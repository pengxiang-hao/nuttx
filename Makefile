############################################################################
# Makefile
#
#   Copyright (C) 2007-2012 Gregory Nutt. All rights reserved.
#   Author: Gregory Nutt <gnutt@nuttx.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name NuttX nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

TOPDIR := ${shell pwd | sed -e 's/ /\\ /g'}
-include ${TOPDIR}/.config
include ${TOPDIR}/tools/Config.mk
-include ${TOPDIR}/Make.defs

# Control build verbosity

ifeq ($(V),1)
export Q :=
else
export Q := @
endif

# Default tools

ifeq ($(DIRLINK),)
DIRLINK = $(TOPDIR)/tools/link.sh
DIRUNLINK = $(TOPDIR)/tools/unlink.sh
endif

# This define is passed as EXTRADEFINES for kernel-mode builds.  It is also passed
# during PASS1 (but not PASS2) context and depend targets.

KDEFINE = ${shell $(TOPDIR)/tools/define.sh "$(CC)" __KERNEL__}

# Process architecture and board-specific directories

ARCH_DIR = arch/$(CONFIG_ARCH)
ARCH_SRC = $(ARCH_DIR)/src
ARCH_INC = $(ARCH_DIR)/include
BOARD_DIR = configs/$(CONFIG_ARCH_BOARD)

# Add-on directories.  These may or may not be in place in the
# NuttX source tree (they must be specifically installed)
#
# CONFIG_APPS_DIR can be over-ridden from the command line or in the .config file.
# The default value of CONFIG_APPS_DIR is ../apps.  Ultimately, the application
# will be built if APPDIR is defined.  APPDIR will be defined if a directory containing
# a Makefile is found at the path provided by CONFIG_APPS_DIR

ifeq ($(CONFIG_APPS_DIR),)
CONFIG_APPS_DIR = ../apps
endif
APPDIR := ${shell if [ -r $(CONFIG_APPS_DIR)/Makefile ]; then echo "$(CONFIG_APPS_DIR)"; fi}

# All add-on directories.
#
# NUTTX_ADDONS is the list of directories built into the NuttX kernel.
# USER_ADDONS is the list of directories that will be built into the user application

NUTTX_ADDONS :=
USER_ADDONS :=

ifeq ($(CONFIG_NUTTX_KERNEL),y)
USER_ADDONS += $(APPDIR)
else
NUTTX_ADDONS += $(APPDIR)
endif

# Lists of build directories.
#
# FSDIRS depend on file descriptor support; NONFSDIRS do not (except for parts
#   of FSDIRS).  We will exclude FSDIRS from the build if file descriptor
#   support is disabled
# CONTEXTDIRS include directories that have special, one-time pre-build
#   requirements.  Normally this includes things like auto-generation of
#   configuration specific files or creation of configurable symbolic links
# USERDIRS - When NuttX is build is a monolithic kernel, this provides the
#   list of directories that must be built
# OTHERDIRS - These are directories that are not built but probably should
#   be cleaned to prevent garbarge from collecting in them when changing
#   configurations.

NONFSDIRS = sched $(ARCH_SRC) $(NUTTX_ADDONS)
FSDIRS = fs drivers binfmt
CONTEXTDIRS = $(APPDIR)
USERDIRS =
OTHERDIRS = lib

ifeq ($(CONFIG_NUTTX_KERNEL),y)

NONFSDIRS += syscall
CONTEXTDIRS += syscall
USERDIRS += syscall libc mm $(USER_ADDONS)
ifeq ($(CONFIG_HAVE_CXX),y)
USERDIRS += libxx
endif

else

NONFSDIRS += libc mm
OTHERDIRS += syscall $(USER_ADDONS)
ifeq ($(CONFIG_HAVE_CXX),y)
NONFSDIRS += libxx
else
OTHERDIRS += libxx
endif

endif

ifeq ($(CONFIG_NX),y)
NONFSDIRS += graphics
CONTEXTDIRS += graphics
else
OTHERDIRS += graphics
endif

# CLEANDIRS are the directories that will clean in.  These are
#   all directories that we know about.
# KERNDEPDIRS are the directories in which we will build target dependencies.
#   If NuttX and applications are built separately (CONFIG_NUTTX_KERNEL),
#   then this holds only the directories containing kernel files.
# USERDEPDIRS. If NuttX and applications are built separately (CONFIG_NUTTX_KERNEL),
#   then this holds only the directories containing user files.

CLEANDIRS = $(NONFSDIRS) $(FSDIRS) $(USERDIRS) $(OTHERDIRS)
KERNDEPDIRS = $(NONFSDIRS)
USERDEPDIRS = $(USERDIRS)

# Add file system directories to KERNDEPDIRS (they are already in CLEANDIRS)

ifeq ($(CONFIG_NFILE_DESCRIPTORS),0)
ifeq ($(CONFIG_NET),y)
ifneq ($(CONFIG_NSOCKET_DESCRIPTORS),0)
KERNDEPDIRS += fs
endif
KERNDEPDIRS += drivers
endif
else
KERNDEPDIRS += $(FSDIRS)
endif

# Add networking directories to KERNDEPDIRS and CLEANDIRS

ifeq ($(CONFIG_NET),y)
KERNDEPDIRS += net
endif
CLEANDIRS += net

#
# Extra objects used in the final link.
#
# Pass 1 1ncremental (relative) link objects should be put into the
# processor-specific source directory (where other link objects will
# be created).  If the pass1 obect is an archive, it could go anywhere.

ifeq ($(CONFIG_BUILD_2PASS),y)
EXTRA_OBJS += $(CONFIG_PASS1_OBJECT)
endif

# NUTTXLIBS is the list of NuttX libraries that is passed to the
#   processor-specific Makefile to build the final NuttX target.
#   Libraries in FSDIRS are excluded if file descriptor support
#   is disabled.
# USERLIBS is the list of libraries used to build the final user-space
#   application

NUTTXLIBS = lib/libsched$(LIBEXT) lib/libarch$(LIBEXT)
USERLIBS =

# Add libraries for syscall support.  The C library will be needed by
# both the kernel- and user-space builds.  For now, the memory manager (mm)
# is placed in user space (only).

ifeq ($(CONFIG_NUTTX_KERNEL),y)
NUTTXLIBS += lib/libstubs$(LIBEXT) lib/libkc$(LIBEXT)
USERLIBS += lib/libproxies$(LIBEXT) lib/libuc$(LIBEXT) lib/libmm$(LIBEXT)
else
NUTTXLIBS += lib/libmm$(LIBEXT) lib/libc$(LIBEXT)
endif

# Add libraries for C++ support.  CXX, CXXFLAGS, and COMPILEXX must
# be defined in Make.defs for this to work!

ifeq ($(CONFIG_HAVE_CXX),y)
ifeq ($(CONFIG_NUTTX_KERNEL),y)
USERLIBS += lib/libcxx$(LIBEXT)
else
NUTTXLIBS += lib/libcxx$(LIBEXT)
endif
endif

# Add library for application support.

ifneq ($(APPDIR),)
ifeq ($(CONFIG_NUTTX_KERNEL),y)
USERLIBS += lib/libapps$(LIBEXT)
else
NUTTXLIBS += lib/libapps$(LIBEXT)
endif
endif

# Add libraries for network support

ifeq ($(CONFIG_NET),y)
NUTTXLIBS += lib/libnet$(LIBEXT)
endif

# Add libraries for file system support

ifeq ($(CONFIG_NFILE_DESCRIPTORS),0)
ifneq ($(CONFIG_NSOCKET_DESCRIPTORS),0)
NUTTXLIBS += lib/libfs$(LIBEXT)
endif
ifeq ($(CONFIG_NET),y)
NUTTXLIBS += lib/libdrivers$(LIBEXT)
endif
else
NUTTXLIBS += lib/libfs$(LIBEXT) lib/libdrivers$(LIBEXT) lib/libbinfmt$(LIBEXT)
endif

# Add libraries for the NX graphics sub-system

ifeq ($(CONFIG_NX),y)
NUTTXLIBS += lib/libgraphics$(LIBEXT)
endif

# LINKLIBS derives from NUTTXLIBS and is simply the same list with the subdirectory removed

LINKLIBS = $(patsubst lib/%,%,$(NUTTXLIBS))

# This is the name of the final target (relative to the top level directorty)

BIN = nuttx$(EXEEXT)

all: $(BIN)
.PHONY: context clean_context check_context export subdir_clean clean subdir_distclean distclean apps_clean apps_distclean

# Target used to copy include/nuttx/math.h.  If CONFIG_ARCH_MATH_H is
# defined, then there is an architecture specific math.h header file
# that will be included indirectly from include/math.h.  But first, we
# have to copy math.h from include/nuttx/. to include/.  Logic within
# include/nuttx/math.h will hand the redirection to the architecture-
# specific math.h header file.
#
# If the CONFIG_LIBM is defined, the Rhombus libm will be built at libc/math.
# Definitions and prototypes for the Rhombus libm are also contained in
# include/nuttx/math.h and so the file must also be copied in that case.
#
# If neither CONFIG_ARCH_MATH_H nor CONFIG_LIBM is defined, then no math.h
# header file will be provided.  You would want that behavior if (1) you
# don't use libm, or (2) you want to use the math.h and libm provided
# within your toolchain.

ifeq ($(CONFIG_ARCH_MATH_H),y)
NEED_MATH_H = y
else
ifeq ($(CONFIG_LIBM),y)
NEED_MATH_H = y
endif
endif

ifeq ($(NEED_MATH_H),y)
include/math.h: include/nuttx/math.h
	$(Q) cp -f include/nuttx/math.h include/math.h
else
include/math.h:
endif

# The float.h header file defines the properties of your floating point
# implementation.  It would always be best to use your toolchain's float.h
# header file but if none is avaiable, a default float.h header file will
# provided if this option is selected.  However there is no assurance that
# the settings in this float.h are actually correct for your platform!

ifeq ($(CONFIG_ARCH_FLOAT_H),y)
include/float.h: include/nuttx/float.h
	$(Q) cp -f include/nuttx/float.h include/float.h
else
include/float.h:
endif

# Target used to copy include/nuttx/stdarg.h.  If CONFIG_ARCH_STDARG_H is
# defined, then there is an architecture specific stdarg.h header file
# that will be included indirectly from include/stdarg.h.  But first, we
# have to copy stdarg.h from include/nuttx/. to include/.

ifeq ($(CONFIG_ARCH_STDARG_H),y)
include/stdarg.h: include/nuttx/stdarg.h
	$(Q) cp -f include/nuttx/stdarg.h include/stdarg.h
else
include/stdarg.h:
endif

# Targets used to build include/nuttx/version.h.  Creation of version.h is
# part of the overall NuttX configuration sequence. Notice that the
# tools/mkversion tool is built and used to create include/nuttx/version.h

tools/mkversion$(HOSTEXEEXT):
	$(Q) $(MAKE) -C tools -f Makefile.host TOPDIR="$(TOPDIR)"  mkversion$(HOSTEXEEXT)

$(TOPDIR)/.version:
	$(Q) if [ ! -f .version ]; then \
		echo "No .version file found, creating one"; \
		tools/version.sh -v 0.0 -b 0 .version; \
		chmod 755 .version; \
	fi

include/nuttx/version.h: $(TOPDIR)/.version tools/mkversion$(HOSTEXEEXT)
	$(Q) tools/mkversion $(TOPDIR) > include/nuttx/version.h

# Targets used to build include/nuttx/config.h.  Creation of config.h is
# part of the overall NuttX configuration sequence. Notice that the
# tools/mkconfig tool is built and used to create include/nuttx/config.h

tools/mkconfig$(HOSTEXEEXT):
	$(Q) $(MAKE) -C tools -f Makefile.host TOPDIR="$(TOPDIR)"  mkconfig$(HOSTEXEEXT)

include/nuttx/config.h: $(TOPDIR)/.config tools/mkconfig$(HOSTEXEEXT)
	$(Q) tools/mkconfig $(TOPDIR) > include/nuttx/config.h

# Targets used to create dependencies

tools/mkdeps$(HOSTEXEEXT):
	$(Q) $(MAKE) -C tools -f Makefile.host TOPDIR="$(TOPDIR)"  mkdeps$(HOSTEXEEXT)

# dirlinks, and helpers
#
# Directories links.  Most of establishing the NuttX configuration involves
# setting up symbolic links with 'generic' directory names to specific,
# configured directories.
#
# Link the apps/include directory to include/apps

include/apps: Make.defs
ifneq ($(APPDIR),)
	@echo "LN: include/apps -> $(APPDIR)/include"
	$(Q) if [ -d $(TOPDIR)/$(APPDIR)/include ]; then \
		$(DIRLINK) $(TOPDIR)/$(APPDIR)/include include/apps; \
	fi
endif

# Link the arch/<arch-name>/include directory to include/arch

include/arch: Make.defs
	@echo "LN: include/arch -> $(TOPDIR)/$(ARCH_DIR)/include"
	$(Q) $(DIRLINK) $(TOPDIR)/$(ARCH_DIR)/include include/arch

# Link the configs/<board-name>/include directory to include/arch/board

include/arch/board: include/arch Make.defs include/arch
	@echo "LN: include/arch/board -> $(TOPDIR)/$(BOARD_DIR)/include"
	$(Q) $(DIRLINK) $(TOPDIR)/$(BOARD_DIR)/include include/arch/board

# Link the configs/<board-name>/src dir to arch/<arch-name>/src/board

$(ARCH_SRC)/board: Make.defs
	@echo "LN: $(ARCH_SRC)/board -> $(TOPDIR)/$(BOARD_DIR)/src"
	$(Q) $(DIRLINK) $(TOPDIR)/$(BOARD_DIR)/src $(ARCH_SRC)/board

# Link arch/<arch-name>/include/<chip-name> to arch/<arch-name>/include/chip

$(ARCH_SRC)/chip: Make.defs
ifneq ($(CONFIG_ARCH_CHIP),)
	@echo "LN: $(ARCH_SRC)/chip -> $(TOPDIR)\$(ARCH_SRC)/$(CONFIG_ARCH_CHIP)"
	$(Q) $(DIRLINK) $(TOPDIR)/$(ARCH_SRC)/$(CONFIG_ARCH_CHIP) $(ARCH_SRC)/chip
endif

# Link arch/<arch-name>/src/<chip-name> to arch/<arch-name>/src/chip

include/arch/chip: include/arch Make.defs
ifneq ($(CONFIG_ARCH_CHIP),)
	@echo "LN: include/arch/chip -> $(TOPDIR)/$(ARCH_INC)/$(CONFIG_ARCH_CHIP)"
	$(Q) $(DIRLINK) $(TOPDIR)/$(ARCH_INC)/$(CONFIG_ARCH_CHIP) include/arch/chip
endif

dirlinks: include/arch include/arch/board include/arch/chip $(ARCH_SRC)/board $(ARCH_SRC)/chip include/apps

# context
#
# The context target is invoked on each target build to assure that NuttX is
# properly configured.  The basic configuration steps include creation of the
# the config.h and version.h header files in the include/nuttx directory and
# the establishment of symbolic links to configured directories.

context: check_context include/nuttx/config.h include/nuttx/version.h include/math.h include/float.h include/stdarg.h dirlinks
	$(Q) for dir in $(CONTEXTDIRS) ; do \
		$(MAKE) -C $$dir TOPDIR="$(TOPDIR)" context; \
	done

# clean_context
#
# This is part of the distclean target.  It removes all of the header files
# and symbolic links created by the context target.

clean_context:
	$(Q) rm -f include/nuttx/config.h
	$(Q) rm -f include/nuttx/version.h
	$(Q) rm -f include/math.h
	$(Q) rm -f include/stdarg.h
	$(Q) $(DIRUNLINK) include/arch/board
	$(Q) $(DIRUNLINK) include/arch/chip
	$(Q) $(DIRUNLINK) include/arch
	$(Q) $(DIRUNLINK) $(ARCH_SRC)/board
	$(Q) $(DIRUNLINK) $(ARCH_SRC)/chip
	$(Q) $(DIRUNLINK) include/apps

# check_context
#
# This target checks if NuttX has been configured.  NuttX is configured using
# the script tools/configure.sh.  That script will install certain files in
# the top-level NuttX build directory.  This target verifies that those
# configuration files have been installed and that NuttX is ready to be built.

check_context:
	$(Q) if [ ! -e ${TOPDIR}/.config -o ! -e ${TOPDIR}/Make.defs ]; then \
		echo "" ; echo "Nuttx has not been configured:" ; \
		echo "  cd tools; ./configure.sh <target>" ; echo "" ; \
		exit 1 ; \
	fi

# Archive targets.  The target build sequency will first create a series of
# libraries, one per configured source file directory.  The final NuttX
# execution will then be built from those libraries.  The following targets
# built those libraries.
#
# Possible kernel-mode builds

libc/libkc$(LIBEXT): context
	$(Q) $(MAKE) -C libc TOPDIR="$(TOPDIR)" libkc$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libkc$(LIBEXT): libc/libkc$(LIBEXT)
	$(Q) install libc/libkc$(LIBEXT) lib/libkc$(LIBEXT)

sched/libsched$(LIBEXT): context
	$(Q) $(MAKE) -C sched TOPDIR="$(TOPDIR)" libsched$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libsched$(LIBEXT): sched/libsched$(LIBEXT)
	$(Q) install sched/libsched$(LIBEXT) lib/libsched$(LIBEXT)

$(ARCH_SRC)/libarch$(LIBEXT): context
	$(Q) $(MAKE) -C $(ARCH_SRC) TOPDIR="$(TOPDIR)" libarch$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libarch$(LIBEXT): $(ARCH_SRC)/libarch$(LIBEXT)
	$(Q) install $(ARCH_SRC)/libarch$(LIBEXT) lib/libarch$(LIBEXT)

net/libnet$(LIBEXT): context
	$(Q) $(MAKE) -C net TOPDIR="$(TOPDIR)" libnet$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libnet$(LIBEXT): net/libnet$(LIBEXT)
	$(Q) install net/libnet$(LIBEXT) lib/libnet$(LIBEXT)

fs/libfs$(LIBEXT): context
	$(Q) $(MAKE) -C fs TOPDIR="$(TOPDIR)" libfs$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libfs$(LIBEXT): fs/libfs$(LIBEXT)
	$(Q) install fs/libfs$(LIBEXT) lib/libfs$(LIBEXT)

drivers/libdrivers$(LIBEXT): context
	$(Q) $(MAKE) -C drivers TOPDIR="$(TOPDIR)" libdrivers$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libdrivers$(LIBEXT): drivers/libdrivers$(LIBEXT)
	$(Q) install drivers/libdrivers$(LIBEXT) lib/libdrivers$(LIBEXT)

binfmt/libbinfmt$(LIBEXT): context
	$(Q) $(MAKE) -C binfmt TOPDIR="$(TOPDIR)" libbinfmt$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libbinfmt$(LIBEXT): binfmt/libbinfmt$(LIBEXT)
	$(Q) install binfmt/libbinfmt$(LIBEXT) lib/libbinfmt$(LIBEXT)

graphics/libgraphics$(LIBEXT): context
	$(Q) $(MAKE) -C graphics TOPDIR="$(TOPDIR)" libgraphics$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libgraphics$(LIBEXT): graphics/libgraphics$(LIBEXT)
	$(Q) install graphics/libgraphics$(LIBEXT) lib/libgraphics$(LIBEXT)

syscall/libstubs$(LIBEXT): context
	$(Q) $(MAKE) -C syscall TOPDIR="$(TOPDIR)" libstubs$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libstubs$(LIBEXT): syscall/libstubs$(LIBEXT)
	$(Q) install syscall/libstubs$(LIBEXT) lib/libstubs$(LIBEXT)

# Possible user-mode builds

libc/libuc$(LIBEXT): context
	$(Q) $(MAKE) -C libc TOPDIR="$(TOPDIR)" libuc$(LIBEXT)

lib/libuc$(LIBEXT): libc/libuc$(LIBEXT)
	$(Q) install libc/libuc$(LIBEXT) lib/libuc$(LIBEXT)

libxx/libcxx$(LIBEXT): context
	$(Q) $(MAKE) -C libxx TOPDIR="$(TOPDIR)" libcxx$(LIBEXT)

lib/libcxx$(LIBEXT): libxx/libcxx$(LIBEXT)
	$(Q) install libxx/libcxx$(LIBEXT) lib/libcxx$(LIBEXT)

mm/libmm$(LIBEXT): context
	$(Q) $(MAKE) -C mm TOPDIR="$(TOPDIR)" libmm$(LIBEXT) EXTRADEFINES=$(KDEFINE)

lib/libmm$(LIBEXT): mm/libmm$(LIBEXT)
	$(Q) install mm/libmm$(LIBEXT) lib/libmm$(LIBEXT)

$(APPDIR)/libapps$(LIBEXT): context
	$(Q) $(MAKE) -C $(APPDIR) TOPDIR="$(TOPDIR)" libapps$(LIBEXT)

lib/libapps$(LIBEXT): $(APPDIR)/libapps$(LIBEXT)
	$(Q) install $(APPDIR)/libapps$(LIBEXT) lib/libapps$(LIBEXT)

syscall/libproxies$(LIBEXT): context
	$(Q) $(MAKE) -C syscall TOPDIR="$(TOPDIR)" libproxies$(LIBEXT)

lib/libproxies$(LIBEXT): syscall/libproxies$(LIBEXT)
	$(Q) install syscall/libproxies$(LIBEXT) lib/libproxies$(LIBEXT)

# Possible non-kernel builds

libc/libc$(LIBEXT): context
	$(Q) $(MAKE) -C libc TOPDIR="$(TOPDIR)" libc$(LIBEXT)

lib/libc$(LIBEXT): libc/libc$(LIBEXT)
	$(Q) install libc/libc$(LIBEXT) lib/libc$(LIBEXT)

# pass1 and pass2
#
# If the 2 pass build option is selected, then this pass1 target is
# configured to built before the pass2 target.  This pass1 target may, as an
# example, build an extra link object (CONFIG_PASS1_OBJECT) which may be an
# incremental (relative) link object, but could be a static library (archive);
# some modification to this Makefile would be required if CONFIG_PASS1_OBJECT
# is an archive.  Exactly what is performed during pass1 or what it generates
# is unknown to this makefule unless CONFIG_PASS1_OBJECT is defined.

pass1deps: pass1dep $(USERLIBS)

pass1: pass1deps
ifeq ($(CONFIG_BUILD_2PASS),y)
	$(Q) if [ -z "$(CONFIG_PASS1_BUILDIR)" ]; then \
		echo "ERROR: CONFIG_PASS1_BUILDIR not defined"; \
		exit 1; \
	fi
	$(Q) if [ ! -d "$(CONFIG_PASS1_BUILDIR)" ]; then \
		echo "ERROR: CONFIG_PASS1_BUILDIR does not exist"; \
		exit 1; \
	fi
	$(Q) if [ ! -f "$(CONFIG_PASS1_BUILDIR)/Makefile" ]; then \
		echo "ERROR: No Makefile in CONFIG_PASS1_BUILDIR"; \
		exit 1; \
	fi
	$(Q) $(MAKE) -C $(CONFIG_PASS1_BUILDIR) TOPDIR="$(TOPDIR)" LINKLIBS="$(LINKLIBS)" USERLIBS="$(USERLIBS)" "$(CONFIG_PASS1_TARGET)"
endif

pass2deps: pass2dep $(NUTTXLIBS)

pass2: pass2deps
	$(Q) $(MAKE) -C $(ARCH_SRC) TOPDIR="$(TOPDIR)" EXTRA_OBJS="$(EXTRA_OBJS)" LINKLIBS="$(LINKLIBS)" EXTRADEFINES=$(KDEFINE) $(BIN)
	$(Q) if [ -w /tftpboot ] ; then \
		cp -f $(BIN) /tftpboot/$(BIN).${CONFIG_ARCH}; \
	fi
ifeq ($(CONFIG_RRLOAD_BINARY),y)
	@echo "MK: $(BIN).rr"
	$(Q) $(TOPDIR)/tools/mkimage.sh --Prefix $(CROSSDEV) $(BIN) $(BIN).rr
	$(Q) if [ -w /tftpboot ] ; then \
		cp -f $(BIN).rr /tftpboot/$\(BIN).rr.$(CONFIG_ARCH); \
	fi
endif
ifeq ($(CONFIG_INTELHEX_BINARY),y)
	@echo "CP: $(BIN).hex"
	$(Q) $(OBJCOPY) $(OBJCOPYARGS) -O ihex $(BIN) $(BIN).hex
endif
ifeq ($(CONFIG_MOTOROLA_SREC),y)
	@echo "CP: $(BIN).srec"
	$(Q) $(OBJCOPY) $(OBJCOPYARGS) -O srec $(BIN) $(BIN).srec
endif
ifeq ($(CONFIG_RAW_BINARY),y)
	@echo "CP: $(BIN).bin"
	$(Q) $(OBJCOPY) $(OBJCOPYARGS) -O binary $(BIN) $(BIN).bin
endif

# $(BIN)
#
# Create the final NuttX executable in a two pass build process.  In the
# normal case, all pass1 and pass2 dependencies are created then pass1
# and pass2 targets are built.  However, in some cases, you may need to build
# pass1 depenencies and pass1 first, then build pass2 dependencies and pass2.
# in that case, execute 'make pass1 pass2' from the command line.

$(BIN): pass1deps pass2deps pass1 pass2

# download
#
# This is a helper target that will rebuild NuttX and download it to the target
# system in one step.  The operation of this target depends completely upon
# implementation of the DOWNLOAD command in the user Make.defs file.  It will
# generate an error an error if the DOWNLOAD command is not defined.

download: $(BIN)
	$(call DOWNLOAD, $<)

# pass1dep: Create pass1 build dependencies
# pass2dep: Create pass2 build dependencies

pass1dep: context tools/mkdeps$(HOSTEXEEXT) 
	$(Q) for dir in $(USERDEPDIRS) ; do \
		$(MAKE) -C $$dir TOPDIR="$(TOPDIR)" depend ; \
	done

pass2dep: context tools/mkdeps$(HOSTEXEEXT) 
	$(Q) for dir in $(KERNDEPDIRS) ; do \
		$(MAKE) -C $$dir TOPDIR="$(TOPDIR)" EXTRADEFINES=$(KDEFINE) depend; \
	done

# Configuration targets
#
# These targets depend on the kconfig-frontends packages.  To use these, you
# must first download and install the kconfig-frontends package from this
# location: http://ymorin.is-a-geek.org/projects/kconfig-frontends.  See
# misc/tools/README.txt for additional information.

config:
	$(Q) APPSDIR=${CONFIG_APPS_DIR} conf Kconfig

oldconfig:
	$(Q) APPSDIR=${CONFIG_APPS_DIR} conf --oldconfig Kconfig

menuconfig:
	$(Q) APPSDIR=${CONFIG_APPS_DIR} mconf Kconfig

# export
#
# The export target will package the NuttX libraries and header files into
# an exportable package.  Caveats: (1) These needs some extension for the KERNEL
# build; it needs to receive USERLIBS and create a libuser.a). (2) The logic
# in tools/mkexport.sh only supports GCC and, for example, explicitly assumes
# that the archiver is 'ar'

export: pass2deps
	$(Q) tools/mkexport.sh -w$(WINTOOL) -t "$(TOPDIR)" -l "$(NUTTXLIBS)"

# General housekeeping targets:  dependencies, cleaning, etc.
#
# depend:    Create both PASS1 and PASS2 dependencies
# clean:     Removes derived object files, archives, executables, and
#            temporary files, but retains the configuration and context
#            files and directories.
# distclean: Does 'clean' then also removes all configuration and context
#            files.  This essentially restores the directory structure
#            to its original, unconfigured stated.

depend: pass1dep pass2dep

subdir_clean:
	$(Q) for dir in $(CLEANDIRS) ; do \
		if [ -e $$dir/Makefile ]; then \
			$(MAKE) -C $$dir TOPDIR="$(TOPDIR)" clean ; \
		fi \
	done
	$(Q) $(MAKE) -C tools -f Makefile.host TOPDIR="$(TOPDIR)" clean
	$(Q) $(MAKE) -C mm -f Makefile.test TOPDIR="$(TOPDIR)" clean
ifeq ($(CONFIG_BUILD_2PASS),y)
	$(Q) $(MAKE) -C $(CONFIG_PASS1_BUILDIR) TOPDIR="$(TOPDIR)" clean
endif

clean: subdir_clean
	$(Q) rm -f $(BIN) nuttx.* mm_test *.map _SAVED_APPS_config *~
	$(Q) rm -f nuttx-export*

subdir_distclean:
	$(Q) for dir in $(CLEANDIRS) ; do \
		if [ -e $$dir/Makefile ]; then \
			$(MAKE) -C $$dir TOPDIR="$(TOPDIR)" distclean ; \
		fi \
	done

distclean: clean subdir_distclean clean_context
ifeq ($(CONFIG_BUILD_2PASS),y)
	$(Q) $(MAKE) -C $(CONFIG_PASS1_BUILDIR) TOPDIR="$(TOPDIR)" distclean
endif
	$(Q) rm -f Make.defs setenv.sh setenv.bat .config .config.old

# Application housekeeping targets.  The APPDIR variable refers to the user
# application directory.  A sample apps/ directory is included with NuttX,
# however, this is not treated as part of NuttX and may be replaced with a
# different application directory.  For the most part, the application
# directory is treated like any other build directory in this script.  However,
# as a convenience, the following targets are included to support housekeeping
# functions in the user application directory from the NuttX build directory.
#
# apps_clean:     Perform the clean operation only in the user application
#                 directory
# apps_distclean: Perform the distclean operation only in the user application
#                 directory.  Note that the apps/.config file (inf any) is
#                 preserved so that this is not a "full" distclean but more of a
#                 configuration "reset." (There willnot be an apps/.config
#                 file if the configuration was generated via make menuconfig).

apps_clean:
ifneq ($(APPDIR),)
	$(Q) $(MAKE) -C "$(TOPDIR)/$(APPDIR)" TOPDIR="$(TOPDIR)" clean
endif

apps_distclean:
ifneq ($(APPDIR),)
	$(Q) if [ -r "$(TOPDIR)/$(APPDIR)/.config" ]; then \
		cp "$(TOPDIR)/$(APPDIR)/.config" _SAVED_APPS_config || \
			{ echo "Copy of $(APPDIR)/.config failed" ; exit 1 ; } \
	else \
		rm -f _SAVED_APPS_config; \
	fi
	$(Q) $(MAKE) -C "$(TOPDIR)/$(APPDIR)" TOPDIR="$(TOPDIR)" distclean
	$(Q) if [ -r _SAVED_APPS_config ]; then \
		mv _SAVED_APPS_config "$(TOPDIR)/$(APPDIR)/.config" || \
			{ echo "Copy of _SAVED_APPS_config failed" ; exit 1 ; } \
	fi
endif


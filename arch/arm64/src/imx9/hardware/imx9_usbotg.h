/****************************************************************************
 * arch/arm64/src/imx9/hardware/imx9_usbotg.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM64_SRC_IMX9_HARDWARE_IMX9_USBOTG_H
#define __ARCH_ARM64_SRC_IMX9_HARDWARE_IMX9_USBOTG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define IMX9_EHCI_NRHPORT                 1

#define IMX9_USBOTG_ID_OFFSET             0x000 /* Identification */
#define IMX9_USBHOST_HWGENERAL_OFFSET     0x004 /* Hardware General */
#define IMX9_USBHOST_HWHOST_OFFSET        0x008 /* Host Hardware Parameters */
#define IMX9_USBHOST_HWDEVICE_OFFSET      0x00c /* Device Hardware Parameters */
#define IMX9_USBHOST_HWTXBUF_OFFSET       0x010 /* TX Buffer Hardware Parameters */
#define IMX9_USBHOST_HWRXBUF_OFFSET       0x014 /* RX Buffer Hardware Parameters */
#define IMX9_USBHOST_GPTIMER0LD_OFFSET    0x080 /* General Purpose Timer #0 Load */
#define IMX9_USBHOST_GPTIMER0CTRL_OFFSET  0x084 /* General Purpose Timer #0 Controller */
#define IMX9_USBHOST_GPTIMER1LD_OFFSET    0x088 /* General Purpose Timer #1 Load */
#define IMX9_USBHOST_GPTIMER1CTRL_OFFSET  0x08c /* General Purpose Timer #1 Controller */
#define IMX9_USBHOST_SBUSCFG_OFFSET       0x090 /* System Bus Config */

/* Device/host capability registers */

#define IMX9_USBOTG_CAPLENGTH_OFFSET      0x100 /* Capability register length (8-bit) */
#define IMX9_USBHOST_HCIVERSION_OFFSET    0x102 /* Host interface version number (16-bit) */
#define IMX9_USBHOST_HCSPARAMS_OFFSET     0x104 /* Host controller structural parameters */
#define IMX9_USBHOST_HCCPARAMS_OFFSET     0x108 /* Host controller capability parameters */
#define IMX9_USBDEV_DCIVERSION_OFFSET     0x120 /* Device interface version number */
#define IMX9_USBDEV_DCCPARAMS_OFFSET      0x124 /* Device controller capability parameters */

/* Device/host/OTG operational registers */

#define IMX9_USBOTG_USBCMD_OFFSET         0x140 /* USB command (both) */
#define IMX9_USBOTG_USBSTS_OFFSET         0x144 /* USB status (both) */
#define IMX9_USBOTG_USBINTR_OFFSET        0x148 /* USB interrupt enable (both) */
#define IMX9_USBOTG_FRINDEX_OFFSET        0x14c /* USB frame index (both) */
#define IMX9_USBOTG_DEVICEADDR_OFFSET     0x154 /* USB device address (device) */
#define IMX9_USBOTG_ASYNCLISTADDR_OFFSET  0x158 /* Next asynchronous list address (host) */
#define IMX9_USBOTG_ENDPOINTLIST_OFFSET   0x158 /* Address of endpoint list in memory (device) */
#define IMX9_USBOTG_BURSTSIZE_OFFSET      0x160 /* Programmable burst size (both) */
#define IMX9_USBOTG_TXFILLTUNING_OFFSET   0x164 /* Host transmit pre-buffer packet tuning (host) */
#define IMX9_USBOTG_ENDPTNAK_OFFSET       0x178 /* Endpoint NAK (device) */
#define IMX9_USBOTG_ENDPTNAKEN_OFFSET     0x17c /* Endpoint NAK Enable (device) */
#define IMX9_USBOTG_CONFIGFLAG_OFFSET     0x180 /* Configured flag register (not used in lpc313x) */
#define IMX9_USBOTG_PORTSC1_OFFSET        0x184 /* Port status/control 1 (both) */
#define IMX9_USBOTG_OTGSC_OFFSET          0x1a4 /* OTG status and control (otg) */
#define IMX9_USBOTG_USBMODE_OFFSET        0x1a8 /* USB device mode (both) */

#define IMX9_USBDEV_USBCMD_OFFSET         0x140 /* USB command (both) */
#define IMX9_USBDEV_USBSTS_OFFSET         0x144 /* USB status (both) */
#define IMX9_USBDEV_USBINTR_OFFSET        0x148 /* USB interrupt enable (both) */
#define IMX9_USBDEV_FRINDEX_OFFSET        0x14c /* USB frame index (both) */
#define IMX9_USBDEV_DEVICEADDR_OFFSET     0x154 /* USB device address (device) */
#define IMX9_USBDEV_ENDPOINTLIST_OFFSET   0x158 /* Address of endpoint list in memory (device) */
#define IMX9_USBDEV_BURSTSIZE_OFFSET      0x160 /* Programmable burst size (both) */
#define IMX9_USBDEV_ENDPTNAK_OFFSET       0x178 /* Endpoint NAK (device) */
#define IMX9_USBDEV_ENDPTNAKEN_OFFSET     0x17c /* Endpoint NAK Enable (device) */
#define IMX9_USBDEV_PORTSC1_OFFSET        0x184 /* Port status/control 1 (both) */
#define IMX9_USBDEV_USBMODE_OFFSET        0x1a8 /* USB device mode (both) */

#define IMX9_USBHOST_USBCMD_OFFSET        0x140 /* USB command (both) */
#define IMX9_USBHOST_USBSTS_OFFSET        0x144 /* USB status (both) */
#define IMX9_USBHOST_USBINTR_OFFSET       0x148 /* USB interrupt enable (both) */
#define IMX9_USBHOST_FRINDEX_OFFSET       0x14c /* USB frame index (both) */
#define IMX9_USBHOST_PERIODICLIST_OFFSET  0x154 /* Frame list base address (host) */
#define IMX9_USBHOST_ASYNCLISTADDR_OFFSET 0x158 /* Next asynchronous list address (host) */
#define IMX9_USBHOST_TTCTRL_OFFSET        0x15c /* Asynchronous buffer status for embedded TT (host) */
#define IMX9_USBHOST_BURSTSIZE_OFFSET     0x160 /* Programmable burst size (both) */
#define IMX9_USBHOST_TXFILLTUNING_OFFSET  0x164 /* Host transmit pre-buffer packet tuning (host) */
#define IMX9_USBHOST_PORTSC1_OFFSET       0x184 /* Port status/control 1 (both) */
#define IMX9_USBHOST_USBMODE_OFFSET       0x1a8 /* USB device mode (both) */

/* Device endpoint registers */

#define IMX9_USBDEV_ENDPTSETUPSTAT_OFFSET 0x1ac /* Endpoint setup status */
#define IMX9_USBDEV_ENDPTPRIME_OFFSET     0x1b0 /* Endpoint initialization */
#define IMX9_USBDEV_ENDPTFLUSH_OFFSET     0x1b4 /* Endpoint de-initialization */
#define IMX9_USBDEV_ENDPTSTATUS_OFFSET    0x1b8 /* Endpoint status */
#define IMX9_USBDEV_ENDPTCOMPLETE_OFFSET  0x1bc /* Endpoint complete */

#define IMX9_USBDEV_ENDPTCTRL_OFFSET(n)   (IMX9_USBDEV_ENDPTCTRL0_OFFSET + ((n) * 4))
#define IMX9_USBDEV_ENDPTCTRL0_OFFSET     0x1c0 /* Endpoint control 0 */
#define IMX9_USBDEV_ENDPTCTRL1_OFFSET     0x1c4 /* Endpoint control 1 */
#define IMX9_USBDEV_ENDPTCTRL2_OFFSET     0x1c8 /* Endpoint control 2 */
#define IMX9_USBDEV_ENDPTCTRL3_OFFSET     0x1cc /* Endpoint control 3 */
#define IMX9_USBDEV_ENDPTCTRL4_OFFSET     0x1d0 /* Endpoint control 4 */
#define IMX9_USBDEV_ENDPTCTRL5_OFFSET     0x1d4 /* Endpoint control 5 */
#define IMX9_USBDEV_ENDPTCTRL6_OFFSET     0x1d8 /* Endpoint control 6 */
#define IMX9_USBDEV_ENDPTCTRL7_OFFSET     0x1dc /* Endpoint control 7 */

/* USB Non-core memory map & register definition */

#define IMX9_USBNC_CTRL1_OFFSET           0x0200 /* USB OTG Control Register 1 */
#define IMX9_USBNC_CTRL2_OFFSET           0x0204 /* USB OTG Control Register 2 */
#define IMX9_USBNC_UTMIPHY_CFG1_OFFSET    0x0230 /* PHY Configure 1 */

/* USBOTG register bit definitions ******************************************/

/* Device/host capability registers */

/* CAPLENGTH */

#define USBOTG_CAPLENGTH_SHIFT               (0)       /* Bits 0-7: Offset from register base to operational regs */
#define USBOTG_CAPLENGTH_MASK                (0xff << USBOTG_CAPLENGTH_SHIFT)

/* HCIVERSION */

#define USBHOST_HCIVERSION_SHIFT             (0)       /* Bits 0-15: BCD encoding of the EHCI revision number */
#define USBHOST_HCIVERSION_MASK              (0xffff << USBHOST_HCIVERSION_SHIFT)

/* HCSPARAMS */

#define USBHOST_HCSPARAMS_NTT_SHIFT          (24)      /* Bits 24-27: Number of Transaction Translators */
#define USBHOST_HCSPARAMS_NTT_MASK           (0xf << USBHOST_HCSPARAMS_NTT_SHIFT)
#define USBHOST_HCSPARAMS_NPTT_SHIFT         (20)      /* Bits 20-23: Number of Ports per Transaction Translator */
#define USBHOST_HCSPARAMS_NPTT_MASK          (15 << USBHOST_HCSPARAMS_NPTT_SHIFT)
#define USBHOST_HCSPARAMS_PI                 (1 << 16) /* Bit 16: Port indicators */
#define USBHOST_HCSPARAMS_NCC_SHIFT          (12)      /* Bits 12-15: Number of Companion Controller */
#define USBHOST_HCSPARAMS_NCC_MASK           (0xf << USBHOST_HCSPARAMS_NCC_SHIFT)
#define USBHOST_HCSPARAMS_NPCC_SHIFT         (8)       /* Bits 8-11: Number of Ports per Companion Controller */
#define USBHOST_HCSPARAMS_NPCC_MASK          (0xf << USBHOST_HCSPARAMS_NPCC_SHIFT)
#define USBHOST_HCSPARAMS_PPC                (1 << 4)  /* Bit 4:  Port Power Control */
#define USBHOST_HCSPARAMS_NPORTS_SHIF        (0)       /* Bits 0-3: Number of downstream ports */
#define USBHOST_HCSPARAMS_NPORTS_MASK        (0xf << USBHOST_HCSPARAMS_NPORTS_SHIFT)

/* HCCPARAMS */

#define USBHOST_HCCPARAMS_EECP_SHIFT         (8)       /* Bits 8-15: EHCI Extended Capabilities Pointer */
#define USBHOST_HCCPARAMS_EECP_MASK          (0xff << USBHOST_HCCPARAMS_EECP_SHIFT)
#define USBHOST_HCCPARAMS_IST_SHIFT          (4)       /* Bits 4-7: Isochronous Scheduling Threshold */
#define USBHOST_HCCPARAMS_IST_MASK           (0xf << USBHOST_HCCPARAMS_IST_SHIFT)
#define USBHOST_HCCPARAMS_ASP                (1 << 2)  /* Bit 2:  Asynchronous Schedule Park Capability */
#define USBHOST_HCCPARAMS_PFL                (1 << 1)  /* Bit 1:  Programmable Frame List Flag */
#define USBHOST_HCCPARAMS_ADC                (1 << 0)  /* Bit 0:  64-bit Addressing Capability */

/* DCIVERSION */

#define USBDEV_DCIVERSION_SHIFT              (0)       /* Bits 0-15: BCD encoding of the device interface */
#define USBDEV_DCIVERSION_MASK               (0xffff << USBDEV_DCIVERSION_SHIFT)

/* DCCPARAMS */

#define USBDEV_DCCPARAMS_HC                  (1 << 8)  /* Bit 8:  Host Capable */
#define USBDEV_DCCPARAMS_DC                  (1 << 7)  /* Bit 7:  Device Capable */
#define USBDEV_DCCPARAMS_DEN_SHIFT           (0)       /* Bits 0-4: DEN Device Endpoint Number */
#define USBDEV_DCCPARAMS_DEN_MASK            (0x1f << USBDEV_DCCPARAMS_DEN_SHIFT)

/* Device/host operational registers */

/* USB Command register USBCMD -- Device Mode */

#define USBDEV_USBCMD_ITC_SHIFT              (16)      /* Bits 16-23: Interrupt threshold control */
#define USBDEV_USBCMD_ITC_MASK               (0xff << USBDEV_USBCMD_ITC_SHIFT)
#  define USBDEV_USBCMD_ITCIMME              (0  << USBDEV_USBCMD_ITC_SHIFT) /* Immediate (no threshold) */
#  define USBDEV_USBCMD_ITC1UF               (1  << USBDEV_USBCMD_ITC_SHIFT) /* 1 micro frame */
#  define USBDEV_USBCMD_ITC2UF               (2  << USBDEV_USBCMD_ITC_SHIFT) /* 2 micro frames */
#  define USBDEV_USBCMD_ITC4UF               (4  << USBDEV_USBCMD_ITC_SHIFT) /* 4 micro frames */
#  define USBDEV_USBCMD_ITC8UF               (8  << USBDEV_USBCMD_ITC_SHIFT) /* 8 micro frames */
#  define USBDEV_USBCMD_ITC16UF              (16 << USBDEV_USBCMD_ITC_SHIFT) /* 16 micro frames */
#  define USBDEV_USBCMD_ITC32UF              (32 << USBDEV_USBCMD_ITC_SHIFT) /* 32 micro frames */
#  define USBDEV_USBCMD_ITC64UF              (64 << USBDEV_USBCMD_ITC_SHIFT) /* 64 micro frames */

#define USBDEV_USBCMD_ATDTW                  (1 << 14)  /* Bit 14: Add dTD trip wire */
#define USBDEV_USBCMD_SUTW                   (1 << 13)  /* Bit 13: Setup trip wire */
#define USBDEV_USBCMD_RST                    (1 << 1)   /* Bit 1:  1 Controller reset */
#define USBDEV_USBCMD_RS                     (1 << 0)   /* Bit 0:  0 Run/Stop */

/* USB Command register USBCMD -- Host Mode */

#define USBHOST_USBCMD_ITC_SHIFT             (16)      /* Bits 16-13: Interrupt threshold control */
#define USBHOST_USBCMD_ITC_MASK              (0xff << USBHOST_USBCMD_ITC_SHIFT)
#  define USBHOST_USBCMD_ITCIMMED            (0  << USBHOST_USBCMD_ITC_SHIFT) /* Immediate (no threshold) */
#  define USBHOST_USBCMD_ITC1UF              (1  << USBHOST_USBCMD_ITC_SHIFT) /* 1 micro frame */
#  define USBHOST_USBCMD_ITC2UF              (2  << USBHOST_USBCMD_ITC_SHIFT) /* 2 micro frames */
#  define USBHOST_USBCMD_ITC4UF              (4  << USBHOST_USBCMD_ITC_SHIFT) /* 4 micro frames */
#  define USBHOST_USBCMD_ITC8UF              (8  << USBHOST_USBCMD_ITC_SHIFT) /* 8 micro frames */
#  define USBHOST_USBCMD_ITC16UF             (16 << USBHOST_USBCMD_ITC_SHIFT) /* 16 micro frames */
#  define USBHOST_USBCMD_ITC32UF             (32 << USBHOST_USBCMD_ITC_SHIFT) /* 32 micro frames */
#  define USBHOST_USBCMD_ITC64UF             (64 << USBHOST_USBCMD_ITC_SHIFT) /* 64 micro frames */

#define USBHOST_USBCMD_FS2                   (1 << 15) /* Bit 15: Bit 2 of the Frame List Size bits */
#define USBHOST_USBCMD_ASPE                  (1 << 11) /* Bit 11: Asynchronous Schedule Park Mode Enable */
#define USBHOST_USBCMD_ASP_SHIFT             (8)       /* Bits 8-9: Asynchronous schedule park mode */
#define USBHOST_USBCMD_ASP_MASK              (0x3 << USBHOST_USBCMD_ASP_SHIFT)
#define USBHOST_USBCMD_IAA                   (1 << 6)  /* Bit 6:  Interrupt next asynchronous schedule */
#define USBHOST_USBCMD_ASE                   (1 << 5)  /* Bit 5:  Skips processing asynchronous schedule */
#define USBHOST_USBCMD_PSE                   (1 << 4)  /* Bit 4:  Skips processing periodic schedule */
#define USBHOST_USBCMD_FS1                   (1 << 3)  /* Bit 3:  Bit 1 of the Frame List Size bits */
#define USBHOST_USBCMD_FS0                   (1 << 2)  /* Bit 2:  Bit 0 of the Frame List Size bits */
#define USBHOST_USBCMD_RST                   (1 << 1)  /* Bit 1:  Controller reset */
#define USBHOST_USBCMD_RS                    (1 << 0)  /* Bit 0:  Run/Stop */

/* USB Status register USBSTS -- Device Mode */

#define USBDEV_USBSTS_NAKI                   (1 << 16) /* Bit 16: NAK interrupt bit */
#define USBDEV_USBSTS_SLI                    (1 << 8)  /* Bit 8:  DCSuspend */
#define USBDEV_USBSTS_SRI                    (1 << 7)  /* Bit 7:  SOF received */
#define USBDEV_USBSTS_URI                    (1 << 6)  /* Bit 6:  USB reset received */
#define USBDEV_USBSTS_PCI                    (1 << 2)  /* Bit 2:  Port change detect */
#define USBDEV_USBSTS_UEI                    (1 << 1)  /* Bit 1:  USB error interrupt */
#define USBDEV_USBSTS_UI                     (1 << 0)  /* Bit 0:  USB interrupt */

/* USB Status register USBSTS -- Host Mode */

#define USBHOST_USBSTS_UPI                   (1 << 19) /* Bit 19: USB host periodic interrupt */
#define USBHOST_USBSTS_UAI                   (1 << 18) /* Bit 18: USB host asynchronous interrupt */
#define USBHOST_USBSTS_AS                    (1 << 15) /* Bit 15: Asynchronous schedule status */
#define USBHOST_USBSTS_PS                    (1 << 14) /* Bit 14: Periodic schedule status */
#define USBHOST_USBSTS_RCL                   (1 << 13) /* Bit 13: Reclamation */
#define USBHOST_USBSTS_HCH                   (1 << 12) /* Bit 12: HCHalted */
#define USBHOST_USBSTS_SRI                   (1 << 7)  /* Bit 7:  SOF received */
#define USBHOST_USBSTS_AAI                   (1 << 5)  /* Bit 5:  Interrupt on async advance */
#define USBHOST_USBSTS_FRI                   (1 << 3)  /* Bit 3:  Frame list roll-over */
#define USBHOST_USBSTS_PCI                   (1 << 2)  /* Bit 2:  Port change detect */
#define USBHOST_USBSTS_UEI                   (1 << 1)  /* Bit 1:  USB error interrupt */
#define USBHOST_USBSTS_UI                    (1 << 0)  /* Bit 0:  USB interrupt */

/* USB interrupt register USBINTR -- Device Mode */

#define USBDEV_USBINTR_NAKE                  (1 << 16) /* Bit 16: NAK interrupt enable */
#define USBDEV_USBINTR_SLE                   (1 << 8)  /* Bit 8:  Sleep enable */
#define USBDEV_USBINTR_SRE                   (1 << 7)  /* Bit 7:  SOF received enable */
#define USBDEV_USBINTR_URE                   (1 << 6)  /* Bit 6:  USB reset enable */
#define USBDEV_USBINTR_PCE                   (1 << 2)  /* Bit 2:  Port change detect enable */
#define USBDEV_USBINTR_UEE                   (1 << 1)  /* Bit 1:  USB error interrupt enable */
#define USBDEV_USBINTR_UE                    (1 << 0)  /* Bit 0:  USB interrupt enable */

/* USB interrupt register USBINTR (address 0x19000148) -- Host Mode */

#define USBHOST_USBINTR_UPIE                 (1 << 19) /* Bit 19: USB host periodic interrupt enable */
#define USBHOST_USBINTR_UAIE                 (1 << 18) /* Bit 18: USB host asynchronous interrupt enable */
#define USBHOST_USBINTR_SRE                  (1 << 7)  /* Bit 7:  SOF timer interrupt enable */
#define USBHOST_USBINTR_AAE                  (1 << 5)  /* Bit 5:  Interrupt on asynchronous advance enable */
#define USBHOST_USBINTR_FRE                  (1 << 3)  /* Bit 3:  Frame list rollover enable */
#define USBHOST_USBINTR_PCE                  (1 << 2)  /* Bit 2:  Port change detect enable */
#define USBHOST_USBINTR_UEE                  (1 << 1)  /* Bit 1:  USB error interrupt enable */
#define USBHOST_USBINTR_UE                   (1 << 0)  /* Bit 0:  USB interrupt enable */

/* Frame index register FRINDEX -- Device Mode */

#define USBDEV_FRINDEX_LFN_SHIFT             (3)       /* Bits 3-13: Frame number of last frame transmitted */
#define USBDEV_FRINDEX_LFN_MASK              (0x7ff << USBDEV_FRINDEX_LFN_SHIFT)
#define USBDEV_FRINDEX_CUFN_SHIFT            (0)       /* Bits 0-2: Current micro frame number */
#define USBDEV_FRINDEX_CUFN_MASK             (7 << USBDEV_FRINDEX_CUFN_SHIFT)

/* Frame index register FRINDEX -- Host Mode */

#define USBHOST_FRINDEX_FLI_SHIFT            (3)       /* Bits 3-13: Frame list current index */
#define USBHOST_FRINDEX_FLI_MASK(n)          (0x7ff << ((n) + USBHOST_FRINDEX_FLI_SHIFT - 1)
#define USBHOST_FRINDEX_CUFN_SHIFT           (0)       /* Bits 0-2: Current micro frame number */
#define USBHOST_FRINDEX_CUFN_MASK            (0x7 << USBHOST_FRINDEX_CUFN_SHIFT)

/* USB Device Address register DEVICEADDR -- Device Mode */

#define USBDEV_DEVICEADDR_SHIFT              (25)      /* Bits 25-31: USBADR USB device address */
#define USBDEV_DEVICEADDR_MASK               (0x7f << USBDEV_DEVICEADDR_SHIFT)
#define USBDEV_DEVICEADDR_USBADRA            (1 << 24) /* Bit 24: Device address advance */

/* USB Periodic List Base register PERIODICLIST -- Host Mode */

#define USBHOST_PERIODICLIST_BASEADR_SHIFT   (12)      /* Bits 12-31: Base Address (Low) */
#define USBHOST_PERIODICLIST_BASEADR_MASK    (0xfffff << USBHOST_PERIODICLIST_PERBASE_SHIFT)

/* USB Asynchronous List Address register ASYNCLISTADDR -- Host Mode */

#define USBHOST_ASYNCLISTADDR_ASYBASE_SHIFT  (5)       /* Bits 5-31: Link pointer (Low) LPL */
#define USBHOST_ASYNCLISTADDR_ASYBASE_MASK   (0x07ffffff << USBHOST_ASYNCLISTADDR_ASYBASE_SHIFT)

/* USB Endpoint List Address register ENDPOINTLISTADDR -- Device Mode */

#define USBDEV_ENDPOINTLIST_EPBASE_SHIFT     (11)      /* Bits 11-31: Endpoint list pointer (low) */
#define USBDEV_ENDPOINTLIST_EPBASE_MASK      (0x1fffff << USBDEV_ENDPOINTLIST_EPBASE_SHIFT)

/* USB burst size register BURSTSIZE -- Device/Host Mode */

#define USBDEV_BURSTSIZE_TXPBURST_SHIFT      (8)       /* Bits 8-15: Programmable TX burst length */
#define USBDEV_BURSTSIZE_TXPBURST_MASK       (0xff << USBDEV_BURSTSIZE_TXPBURST_SHIFT)
#define USBDEV_BURSTSIZE_RXPBURST_SHIFT      (0)       /* Bits 0-7: RXPBURST Programmable RX burst length */
#define USBDEV_BURSTSIZE_RXPBURST_MASK       (0xff << USBDEV_BURSTSIZE_RXPBURST_SHIFT)

#define USBHOST_BURSTSIZE_TXPBURST_SHIFT     (8)       /* Bits 8-15: Programmable TX burst length */
#define USBHOST_BURSTSIZE_TXPBURST_MASK      (0xff << USBHOST_BURSTSIZE_TXPBURST_SHIFT)
#define USBHOST_BURSTSIZE_RXPBURST_SHIFT     (0)       /* Bits 0-7: RXPBURST Programmable RX burst length */
#define USBHOST_BURSTSIZE_RXPBURST_MASK      (0xff << USBHOST_BURSTSIZE_RXPBURST_SHIFT)

/* USB Transfer buffer Fill Tuning register TXFIFOFILLTUNING -- Host Mode */

#define USBHOST_TXFILLTUNING_FIFOTHRES_SHIFT (16)      /* Bits 16-21: Scheduler overhead */
#define USBHOST_TXFILLTUNING_FIFOTHRES_MASK  (0x3f << USBHOST_TXFILLTUNING_FIFOTHRES_SHIFT)
#define USBHOST_TXFILLTUNING_SCHEATLTH_SHIFT (8)       /* Bits 8-12: Scheduler health counter */
#define USBHOST_TXFILLTUNING_SCHEATLTH_MASK  (0x1f << USBHOST_TXFILLTUNING_SCHEATLTH_SHIFT)
#define USBHOST_TXFILLTUNING_SCHOH_SHIFT     (0)       /* Bits 0-7: FIFO burst threshold */
#define USBHOST_TXFILLTUNING_SCHOH_MASK      (0x7f << USBHOST_TXFILLTUNING_SCHOH_SHIFT)

/* USB endpoint NAK register ENDPTNAK -- Device Mode */

#define USBDEV_ENDPTNAK_EPTN_SHIFT           (16)      /* Bits 16-23: Tx endpoint NAK */
#define USBDEV_ENDPTNAK_EPTN_MASK            (0xff << USBDEV_ENDPTNAK_EPTN_SHIFT)
#define USBDEV_ENDPTNAK_EPRN_SHIFT           (0)       /* Bits 0-7: Rx endpoint NAK */
#define USBDEV_ENDPTNAK_EPRN_MASK            (0xff << USBDEV_ENDPTNAK_EPRN_SHIFT)

/* USB Endpoint NAK Enable register ENDPTNAKEN -- Device Mode */

#define USBDEV_ENDPTNAK_EPTNE_SHIFT          (16)      /* Bits 16-23: Tx endpoint NAK enable */
#define USBDEV_ENDPTNAK_EPTNE_MASK           (0xff << USBDEV_ENDPTNAK_EPTNE_SHIFT)
#define USBDEV_ENDPTNAK_EPRNE_SHIFT          (0)       /* Bits 0-7: Rx endpoint NAK enable */
#define USBDEV_ENDPTNAK_EPRNE_MASK           (0xff << USBDEV_ENDPTNAK_EPRNE_SHIFT)

/* Configure Flag register CONFIGFLAG -- Not used, returns 1 */

#define USBDEV_CONFIGFLAG_CF                 (1)

/* Port Status and Control register PRTSC1 -- Device Mode */

#define USBDEV_PRTSC1_PSPD_SHIFT             (26)      /* Bits 26-27: Port speed */
#define USBDEV_PRTSC1_PSPD_MASK              (0x3 << USBDEV_PRTSC1_PSPD_SHIFT)
#  define USBDEV_PRTSC1_PSPD_FS              (0 << USBDEV_PRTSC1_PSPD_SHIFT) /* Full-speed */
#  define USBDEV_PRTSC1_PSPD_LS              (1 << USBDEV_PRTSC1_PSPD_SHIFT) /* Low-speed */
#  define USBDEV_PRTSC1_PSPD_HS              (2 << USBDEV_PRTSC1_PSPD_SHIFT) /* High-speed */

#define USBDEV_PRTSC1_PFSC                   (1 << 24) /* Bit 24: Port force full speed connect */
#define USBDEV_PRTSC1_PHCD                   (1 << 23) /* Bit 23: PHY low power suspend - clock disable (PLPSCD) */
#define USBDEV_PRTSC1_PTC_SHIFT              (16)      /* Bits 16-19: 19: Port test control */
#define USBDEV_PRTSC1_PTC_MASK               (0xf << USBDEV_PRTSC1_PTC_SHIFT)
#  define USBDEV_PRTSC1_PTC_DISABLE          (0 << USBDEV_PRTSC1_PTC_SHIFT) /* TEST_MODE_DISABLE */
#  define USBDEV_PRTSC1_PTC_JSTATE           (1 << USBDEV_PRTSC1_PTC_SHIFT) /* J_STATE */
#  define USBDEV_PRTSC1_PTC_KSTATE           (2 << USBDEV_PRTSC1_PTC_SHIFT) /* K_STATE */
#  define USBDEV_PRTSC1_PTC_SE0              (3 << USBDEV_PRTSC1_PTC_SHIFT) /* SE0 (host)/NAK (device) */
#  define USBDEV_PRTSC1_PTC_PACKET           (4 << USBDEV_PRTSC1_PTC_SHIFT) /* Packet */
#  define USBDEV_PRTSC1_PTC_HS               (5 << USBDEV_PRTSC1_PTC_SHIFT) /* FORCE_ENABLE_HS */
#  define USBDEV_PRTSC1_PTC_FS               (6 << USBDEV_PRTSC1_PTC_SHIFT) /* FORCE_ENABLE_FS */

#define USBDEV_PRTSC1_PIC_SHIFT              (14)      /* Bits 14-15: Port indicator control */
#define USBDEV_PRTSC1_PIC_MASK               (0x3 << USBDEV_PRTSC1_PIC_SHIFT)
#  define USBDEV_PRTSC1_PIC_OFF              (0 << USBDEV_PRTSC1_PIC_SHIFT) /* 00 Port indicators are off */
#  define USBDEV_PRTSC1_PIC_AMBER            (1 << USBDEV_PRTSC1_PIC_SHIFT) /* 01 amber */
#  define USBDEV_PRTSC1_PIC_GREEN            (2 << USBDEV_PRTSC1_PIC_SHIFT) /* 10 green */

#define USBDEV_PRTSC1_HSP                    (1 << 9)  /* Bit 9:  High-speed status */
#define USBDEV_PRTSC1_PR                     (1 << 8)  /* Bit 8:  Port reset */
#define USBDEV_PRTSC1_SUSP                   (1 << 7)  /* Bit 7:  Suspend */
#define USBDEV_PRTSC1_FPR                    (1 << 6)  /* Bit 6:  Force port resume */
#define USBDEV_PRTSC1_PEC                    (1 << 3)  /* Bit 3:  Port enable/disable change */
#define USBDEV_PRTSC1_PE                     (1 << 2)  /* Bit 2:  Port enable */
#define USBDEV_PRTSC1_CCS                    (1 << 0)  /* Bit 0:  Current connect status */

/* Port Status and Control register PRTSC1 -- Host Mode */

#define USBHOST_PRTSC1_PSPD_SHIFT            (26)      /* Bits 26-27: Port speed */
#define USBHOST_PRTSC1_PSPD_MASK             (0x3 << USBHOST_PRTSC1_PSPD_SHIFT)
#  define USBHOST_PRTSC1_PSPD_FS             (0 << USBHOST_PRTSC1_PSPD_SHIFT) /* Full-speed */
#  define USBHOST_PRTSC1_PSPD_LS             (1 << USBHOST_PRTSC1_PSPD_SHIFT) /* Low-speed */
#  define USBHOST_PRTSC1_PSPD_HS             (2 << USBHOST_PRTSC1_PSPD_SHIFT) /* High-speed */

#define USBHOST_PRTSC1_PFSC                  (1 << 24) /* Bit 24: Port force full speed connect */
#define USBHOST_PRTSC1_PHCD                  (1 << 23) /* Bit 23: PHY low power suspend - clock disable (PLPSCD) */
#define USBHOST_PRTSC1_WKOC                  (1 << 22) /* Bit 22: Wake on over-current enable (WKOC_E) */
#define USBHOST_PRTSC1_WKDC                  (1 << 21) /* Bit 21: Wake on disconnect enable (WKDSCNNT_E) */
#define USBHOST_PRTSC1_WKCN                  (1 << 20) /* Bit 20: Wake on connect enable (WKCNNT_E) */
#define USBHOST_PRTSC1_PTC_SHIFT             (16)      /* Bits 16-19: Port test control */
#define USBHOST_PRTSC1_PTC_MASK              (0xf << USBHOST_PRTSC1_PTC_SHIFT)
#  define USBHOST_PRTSC1_PTC_DISABLE         (0 << USBHOST_PRTSC1_PTC_SHIFT) /* 0000 TEST_MODE_DISABLE */
#  define USBHOST_PRTSC1_PTC_JSTATE          (1 << USBHOST_PRTSC1_PTC_SHIFT) /* 0001 J_STATE */
#  define USBHOST_PRTSC1_PTC_KSTATE          (2 << USBHOST_PRTSC1_PTC_SHIFT) /* 0010 K_STATE */
#  define USBHOST_PRTSC1_PTC_SE0             (3 << USBHOST_PRTSC1_PTC_SHIFT) /* 0011 SE0 (host)/NAK (device) */
#  define USBHOST_PRTSC1_PTC_PACKET          (4 << USBHOST_PRTSC1_PTC_SHIFT) /* 0100 Packet */
#  define USBHOST_PRTSC1_PTC_HS              (5 << USBHOST_PRTSC1_PTC_SHIFT) /* 0101 FORCE_ENABLE_HS */
#  define USBHOST_PRTSC1_PTC_FS              (6 << USBHOST_PRTSC1_PTC_SHIFT) /* 0110 FORCE_ENABLE_FS */
#  define USBHOST_PRTSC1_PTC_LS              (7 << USBHOST_PRTSC1_PTC_SHIFT) /* 0111 FORCE_ENABLE_LS */

#define USBHOST_PRTSC1_PIC_SHIFT             (14)      /* Bits 14-15: Port indicator control */
#define USBHOST_PRTSC1_PIC_MASK              (0x3 << USBHOST_PRTSC1_PIC_SHIFT)
#  define USBHOST_PRTSC1_PIC_OFF             (0 << USBHOST_PRTSC1_PIC_SHIFT) /* 00 Port indicators are off */
#  define USBHOST_PRTSC1_PIC_AMBER           (1 << USBHOST_PRTSC1_PIC_SHIFT) /* 01 Amber */
#  define USBHOST_PRTSC1_PIC_GREEN           (2 << USBHOST_PRTSC1_PIC_SHIFT) /* 10 Green */

#define USBHOST_PRTSC1_PP                    (1 << 12) /* Bit 12: Port power control */
#define USBHOST_PRTSC1_LS_SHIFT              (10)      /* Bits 10-11: Line status */
#define USBHOST_PRTSC1_LS_MASK               (0x3 << USBHOST_PRTSC1_LS_SHIFT)
#  define USBHOST_PRTSC1_LS_SE0              (0 << USBHOST_PRTSC1_LS_SHIFT) /* SE0 (USB_DP and USB_DM LOW) */
#  define USBHOST_PRTSC1_LS_JSTATE           (2 << USBHOST_PRTSC1_LS_SHIFT) /* J-state (USB_DP HIGH and USB_DM LOW) */
#  define USBHOST_PRTSC1_LS_KSTATE           (1 << USBHOST_PRTSC1_LS_SHIFT) /* K-state (USB_DP LOW and USB_DM HIGH) */

#define USBHOST_PRTSC1_HSP                   (1 << 9)  /* Bit 9:  High-speed status */
#define USBHOST_PRTSC1_PR                    (1 << 8)  /* Bit 8:  Port reset */
#define USBHOST_PRTSC1_SUSP                  (1 << 7)  /* Bit 7:  Suspend */
#define USBHOST_PRTSC1_FPR                   (1 << 6)  /* Bit 6:  Force port resume */
#define USBHOST_PRTSC1_OCC                   (1 << 5)  /* Bit 5:  Over-current change */
#define USBHOST_PRTSC1_OCA                   (1 << 4)  /* Bit 4:  Over-current active */
#define USBHOST_PRTSC1_PEC                   (1 << 3)  /* Bit 3:  Port disable/enable change */
#define USBHOST_PRTSC1_PE                    (1 << 2)  /* Bit 2:  Port enable */
#define USBHOST_PRTSC1_CSC                   (1 << 1)  /* Bit 1:  Connect status change */
#define USBHOST_PRTSC1_CCS                   (1 << 0)  /* Bit 0:  Current connect status */

/* OTG Status and Control register (OTGSC) */

/* OTG interrupt enable */

#define USBOTG_OTGSC_DPIE                    (1 << 30) /* Bit 30: Data pulse interrupt enable */
#define USBOTG_OTGSC_1MSE                    (1 << 29) /* Bit 29: 1 millisecond timer interrupt enable */
#define USBOTG_OTGSC_BSEIE                   (1 << 28) /* Bit 28: B-session end interrupt enable */
#define USBOTG_OTGSC_BSVIE                   (1 << 27) /* Bit 27: B-session valid interrupt enable */
#define USBOTG_OTGSC_ASVIE                   (1 << 26) /* Bit 26: A-session valid interrupt enable */
#define USBOTG_OTGSC_AVVIE                   (1 << 25) /* Bit 25: A-VBUS valid interrupt enable */
#define USBOTG_OTGSC_IDIE                    (1 << 24) /* Bit 24: USB ID interrupt enable */

/* OTG interrupt status */

#define USBOTG_OTGSC_DPIS                    (1 << 22) /* Bit 22: Data pulse interrupt status */
#define USBOTG_OTGSC_1MSS                    (1 << 21) /* Bit 21: 1 millisecond timer interrupt status */
#define USBOTG_OTGSC_BSEIS                   (1 << 20) /* Bit 20: B-Session end interrupt status */
#define USBOTG_OTGSC_BSVIS                   (1 << 19) /* Bit 19: B-Session valid interrupt status */
#define USBOTG_OTGSC_ASVIS                   (1 << 18) /* Bit 18: A-Session valid interrupt status */
#define USBOTG_OTGSC_AVVIS                   (1 << 17) /* Bit 17: A-VBUS valid interrupt status */
#define USBOTG_OTGSC_IDIS                    (1 << 16) /* Bit 16: USB ID interrupt status */

/* OTG status inputs */

#define USBOTG_OTGSC_DPS                     (1 << 14) /* Bit 14: Data bus pulsing status */
#define USBOTG_OTGSC_1MST                    (1 << 13) /* Bit 13: 1 millisecond timer toggle */
#define USBOTG_OTGSC_BSE                     (1 << 12) /* Bit 12: B-session end */
#define USBOTG_OTGSC_BSV                     (1 << 11) /* Bit 11: B-session valid */
#define USBOTG_OTGSC_ASV                     (1 << 10) /* Bit 10: A-session valid */
#define USBOTG_OTGSC_AVV                     (1 << 9)  /* Bit 9:  A-VBUS valid */
#define USBOTG_OTGSC_ID                      (1 << 8)  /* Bit 8:  USB ID */

/* OTG controls */

#define USBOTG_OTGSC_IDPU                    (1 << 5)  /* Bit 5:  ID pull-up */
#define USBOTG_OTGSC_DP                      (1 << 4)  /* Bit 4:  Data pulsing */
#define USBOTG_OTGSC_OT                      (1 << 3)  /* Bit 3:  OTG termination */
#define USBOTG_OTGSC_VC                      (1 << 1)  /* Bit 1:  VBUS_Charge */
#define USBOTG_OTGSC_VD                      (1 << 0)  /* Bit 0:  VBUS_Discharge */

/* USB Mode register USBMODE -- Device Mode */

#define USBDEV_USBMODE_SDIS                  (1 << 4)  /* Bit 4:  Stream disable mode */
#define USBDEV_USBMODE_SLOM                  (1 << 3)  /* Bit 3:  Setup Lockout mode */
#define USBDEV_USBMODE_ES                    (1 << 2)  /* Bit 2:  Endian select */
#define USBDEV_USBMODE_CM_SHIFT              (0)       /* Bits 0-1: Controller mode */
#define USBDEV_USBMODE_CM_MASK               (0x3 << USBDEV_USBMODE_CM_SHIFT)
#  define USBDEV_USBMODE_CM_IDLE             (0 << USBDEV_USBMODE_CM_SHIFT) /* Idle */
#  define USBDEV_USBMODE_CM_DEVICE           (2 << USBDEV_USBMODE_CM_SHIFT) /* Device controller */
#  define USBDEV_USBMODE_CM_HOST             (3 << USBDEV_USBMODE_CM_SHIFT) /* Host controller */

/* USB Mode register USBMODE -- Host Mode */

#define USBHOST_USBMODE_SDIS                 (1 << 4)  /* Bit 4:  Stream disable mode */
#define USBHOST_USBMODE_ES                   (1 << 2)  /* Bit 2:  Endian select */
#define USBHOST_USBMODE_CM_SHIFT             (0)       /* Bits 0-1: Controller mode */
#define USBHOST_USBMODE_CM_MASK              (0x3 << USBHOST_USBMODE_CM_SHIFT)
#  define USBHOST_USBMODE_CM_IDLE            (0 << USBHOST_USBMODE_CM_SHIFT) /* Idle */
#  define USBHOST_USBMODE_CM_DEVICE          (2 << USBHOST_USBMODE_CM_SHIFT) /* Device controller */
#  define USBHOST_USBMODE_CM_HOST            (3 << USBHOST_USBMODE_CM_SHIFT) /* Host controller */

/* Device endpoint registers */

/* USB Endpoint Setup Status register ENDPTSETUPSTAT */

#define USBDEV_ENDPTSETSTAT_STAT15           (1 << 15) /* Bit 15: Setup EP status for logical EP 15 */
#define USBDEV_ENDPTSETSTAT_STAT14           (1 << 14) /* Bit 14: Setup EP status for logical EP 14 */
#define USBDEV_ENDPTSETSTAT_STAT13           (1 << 13) /* Bit 13: Setup EP status for logical EP 13 */
#define USBDEV_ENDPTSETSTAT_STAT12           (1 << 12) /* Bit 12: Setup EP status for logical EP 12 */
#define USBDEV_ENDPTSETSTAT_STAT11           (1 << 11) /* Bit 11: Setup EP status for logical EP 11 */
#define USBDEV_ENDPTSETSTAT_STAT10           (1 << 10) /* Bit 10: Setup EP status for logical EP 10 */
#define USBDEV_ENDPTSETSTAT_STAT9            (1 << 9)  /* Bit 9:  Setup EP status for logical EP 9 */
#define USBDEV_ENDPTSETSTAT_STAT8            (1 << 8)  /* Bit 8:  Setup EP status for logical EP 8 */
#define USBDEV_ENDPTSETSTAT_STAT7            (1 << 7)  /* Bit 7:  Setup EP status for logical EP 7 */
#define USBDEV_ENDPTSETSTAT_STAT6            (1 << 6)  /* Bit 6:  Setup EP status for logical EP 6 */
#define USBDEV_ENDPTSETSTAT_STAT5            (1 << 5)  /* Bit 5:  Setup EP status for logical EP 5 */
#define USBDEV_ENDPTSETSTAT_STAT4            (1 << 4)  /* Bit 4:  Setup EP status for logical EP 4 */
#define USBDEV_ENDPTSETSTAT_STAT3            (1 << 3)  /* Bit 3:  Setup EP status for logical EP 3 */
#define USBDEV_ENDPTSETSTAT_STAT2            (1 << 2)  /* Bit 2:  Setup EP status for logical EP 2 */
#define USBDEV_ENDPTSETSTAT_STAT1            (1 << 1)  /* Bit 1:  Setup EP status for logical EP 1 */
#define USBDEV_ENDPTSETSTAT_STAT0            (1 << 0)  /* Bit 0:  Setup EP status for logical EP 0 */

/* USB Endpoint Prime register ENDPTPRIME */

#define USBDEV_ENDPTPRIM_PETB7               (1 << 23) /* Bit 23: Prime EP xmt buffer for physical IN EP 7 */
#define USBDEV_ENDPTPRIM_PETB6               (1 << 22) /* Bit 22: Prime EP xmt buffer for physical IN EP 6 */
#define USBDEV_ENDPTPRIM_PETB5               (1 << 21) /* Bit 21: Prime EP xmt buffer for physical IN EP 5 */
#define USBDEV_ENDPTPRIM_PETB4               (1 << 20) /* Bit 20: Prime EP xmt buffer for physical IN EP 4 */
#define USBDEV_ENDPTPRIM_PETB3               (1 << 19) /* Bit 19: Prime EP xmt buffer for physical IN EP 3 */
#define USBDEV_ENDPTPRIM_PETB2               (1 << 18) /* Bit 18: Prime EP xmt buffer for physical IN EP 2 */
#define USBDEV_ENDPTPRIM_PETB1               (1 << 17) /* Bit 17: Prime EP xmt buffer for physical IN EP 1 */
#define USBDEV_ENDPTPRIM_PETB0               (1 << 16) /* Bit 16: Prime EP xmt buffer for physical IN EP 0 */
#define USBDEV_ENDPTPRIM_PERB7               (1 << 7)  /* Bit 7:  Prime EP recv buffer for physical OUT EP 7 */
#define USBDEV_ENDPTPRIM_PERB6               (1 << 6)  /* Bit 6:  Prime EP recv buffer for physical OUT EP 6 */
#define USBDEV_ENDPTPRIM_PERB5               (1 << 5)  /* Bit 5:  Prime EP recv buffer for physical OUT EP 5 */
#define USBDEV_ENDPTPRIM_PERB4               (1 << 4)  /* Bit 4:  Prime EP recv buffer for physical OUT EP 4 */
#define USBDEV_ENDPTPRIM_PERB3               (1 << 3)  /* Bit 3:  Prime EP recv buffer for physical OUT EP 3 */
#define USBDEV_ENDPTPRIM_PERB2               (1 << 2)  /* Bit 2:  Prime EP recv buffer for physical OUT EP 2 */
#define USBDEV_ENDPTPRIM_PERB1               (1 << 1)  /* Bit 1:  Prime EP recv buffer for physical OUT EP 1 */
#define USBDEV_ENDPTPRIM_PERB0               (1 << 0)  /* Bit 0:  Prime EP recv buffer for physical OUT EP 0 */

/* USB Endpoint Flush register ENDPTFLUSH */

#define USBDEV_ENDPTFLUSH_FETB7              (1 << 23) /* Bit 23: Flush EP xmt buffer for physical IN EP 7 */
#define USBDEV_ENDPTFLUSH_FETB6              (1 << 22) /* Bit 22: Flush EP xmt buffer for physical IN EP 6 */
#define USBDEV_ENDPTFLUSH_FETB5              (1 << 21) /* Bit 21: Flush EP xmt buffer for physical IN EP 5 */
#define USBDEV_ENDPTFLUSH_FETB4              (1 << 20) /* Bit 20: Flush EP xmt buffer for physical IN EP 4 */
#define USBDEV_ENDPTFLUSH_FETB3              (1 << 19) /* Bit 19: Flush EP xmt buffer for physical IN EP 3 */
#define USBDEV_ENDPTFLUSH_FETB2              (1 << 18) /* Bit 18: Flush EP xmt buffer for physical IN EP 2 */
#define USBDEV_ENDPTFLUSH_FETB1              (1 << 17) /* Bit 17: Flush EP xmt buffer for physical IN EP 1 */
#define USBDEV_ENDPTFLUSH_FETB0              (1 << 16) /* Bit 16: Flush EP xmt buffer for physical IN EP 0 */
#define USBDEV_ENDPTFLUSH_FERB7              (1 << 7)  /* Bit 7:  Flush EP recv buffer for physical OUT EP 7 */
#define USBDEV_ENDPTFLUSH_FERB6              (1 << 6)  /* Bit 6:  Flush EP recv buffer for physical OUT EP 6 */
#define USBDEV_ENDPTFLUSH_FERB5              (1 << 5)  /* Bit 5:  Flush EP recv buffer for physical OUT EP 5 */
#define USBDEV_ENDPTFLUSH_FERB4              (1 << 4)  /* Bit 4:  Flush EP recv buffer for physical OUT EP 4 */
#define USBDEV_ENDPTFLUSH_FERB3              (1 << 3)  /* Bit 3:  Flush EP recv buffer for physical OUT EP 3 */
#define USBDEV_ENDPTFLUSH_FERB2              (1 << 2)  /* Bit 2:  Flush EP recv buffer for physical OUT EP 2 */
#define USBDEV_ENDPTFLUSH_FERB1              (1 << 1)  /* Bit 1:  Flush EP recv buffer for physical OUT EP 1 */
#define USBDEV_ENDPTFLUSH_FERB0              (1 << 0)  /* Bit 0:  Flush EP recv buffer for physical OUT EP 0 */

/* USB Endpoint Status register ENDPTSTATUS */

#define USBDEV_ENDPTSTATUS_ETBR7             (1 << 23) /* Bit 23: EP xmt buffer ready for physical IN EP 7 */
#define USBDEV_ENDPTSTATUS_ETBR6             (1 << 22) /* Bit 22: EP xmt buffer ready for physical IN EP 6 */
#define USBDEV_ENDPTSTATUS_ETBR5             (1 << 21) /* Bit 21: EP xmt buffer ready for physical IN EP 5 */
#define USBDEV_ENDPTSTATUS_ETBR4             (1 << 20) /* Bit 20: EP xmt buffer ready for physical IN EP 4 */
#define USBDEV_ENDPTSTATUS_ETBR3             (1 << 19) /* Bit 19: EP xmt buffer ready for physical IN EP 3 */
#define USBDEV_ENDPTSTATUS_ETBR2             (1 << 18) /* Bit 18: EP xmt buffer ready for physical IN EP 2 */
#define USBDEV_ENDPTSTATUS_ETBR1             (1 << 17) /* Bit 17: EP xmt buffer ready for physical IN EP 1 */
#define USBDEV_ENDPTSTATUS_ETBR0             (1 << 16) /* Bit 16: EP xmt buffer ready for physical IN EP 0 */
#define USBDEV_ENDPTSTATUS_ERBR7             (1 << 7)  /* Bit 7:  EP recv buffer ready for physical OUT EP 7 */
#define USBDEV_ENDPTSTATUS_ERBR6             (1 << 6)  /* Bit 6:  EP recv buffer ready for physical OUT EP 6 */
#define USBDEV_ENDPTSTATUS_ERBR5             (1 << 5)  /* Bit 5:  EP recv buffer ready for physical OUT EP 5 */
#define USBDEV_ENDPTSTATUS_ERBR4             (1 << 4)  /* Bit 4:  EP recv buffer ready for physical OUT EP 4 */
#define USBDEV_ENDPTSTATUS_ERBR3             (1 << 3)  /* Bit 3:  EP recv buffer ready for physical OUT EP 3 */
#define USBDEV_ENDPTSTATUS_ERBR2             (1 << 2)  /* Bit 2:  EP recv buffer ready for physical OUT EP 2 */
#define USBDEV_ENDPTSTATUS_ERBR1             (1 << 1)  /* Bit 1:  EP recv buffer ready for physical OUT EP 1 */
#define USBDEV_ENDPTSTATUS_ERBR0             (1 << 0)  /* Bit 0:  EP recv buffer ready for physical OUT EP 0 */

/* USB Endpoint Complete register ENDPTCOMPLETE */

#define USBDEV_ENDPTCOMPLETE_ETCE7           (1 << 23) /* Bit 23: EP xmt complete event for physical IN EP 7 */
#define USBDEV_ENDPTCOMPLETE_ETCE6           (1 << 22) /* Bit 22: EP xmt complete event for physical IN EP 6 */
#define USBDEV_ENDPTCOMPLETE_ETCE5           (1 << 21) /* Bit 21: EP xmt complete event for physical IN EP 5 */
#define USBDEV_ENDPTCOMPLETE_ETCE4           (1 << 20) /* Bit 20: EP xmt complete event for physical IN EP 4 */
#define USBDEV_ENDPTCOMPLETE_ETCE3           (1 << 19) /* Bit 19: EP xmt complete event for physical IN EP 3 */
#define USBDEV_ENDPTCOMPLETE_ETCE2           (1 << 18) /* Bit 18: EP xmt complete event for physical IN EP 2 */
#define USBDEV_ENDPTCOMPLETE_ETCE1           (1 << 17) /* Bit 17: EP xmt complete event for physical IN EP 1 */
#define USBDEV_ENDPTCOMPLETE_ETCE0           (1 << 16) /* Bit 16: EP xmt complete event for physical IN EP 0 */
#define USBDEV_ENDPTCOMPLETE_ERCE7           (1 << 7)  /* Bit 7:  EP recv complete event for physical OUT EP 7 */
#define USBDEV_ENDPTCOMPLETE_ERCE6           (1 << 6)  /* Bit 6:  EP recv complete event for physical OUT EP 6 */
#define USBDEV_ENDPTCOMPLETE_ERCE5           (1 << 5)  /* Bit 5:  EP recv complete event for physical OUT EP 5 */
#define USBDEV_ENDPTCOMPLETE_ERCE4           (1 << 4)  /* Bit 4:  EP recv complete event for physical OUT EP 4 */
#define USBDEV_ENDPTCOMPLETE_ERCE3           (1 << 3)  /* Bit 3:  EP recv complete event for physical OUT EP 3 */
#define USBDEV_ENDPTCOMPLETE_ERCE2           (1 << 2)  /* Bit 2:  EP recv complete event for physical OUT EP 2 */
#define USBDEV_ENDPTCOMPLETE_ERCE1           (1 << 1)  /* Bit 1:  EP recv complete event for physical OUT EP 1 */
#define USBDEV_ENDPTCOMPLETE_ERCE0           (1 << 0)  /* Bit 0:  EP recv complete event for physical OUT EP 0 */

/* USB Endpoint 0 Control register ENDPTCTRL0 */

#define USBDEV_ENDPTCTRL0_TXE                (1 << 23) /* Bit 23: Tx endpoint enable */
#define USBDEV_ENDPTCTRL0_TXT_SHIFT          (18)      /* Bits 18-19: Tx endpoint type */
#define USBDEV_ENDPTCTRL0_TXT_MASK           (0x3 << USBDEV_ENDPTCTRL0_TXT_SHIFT)
#  define USBDEV_ENDPTCTRL0_TXT_CTRL         (0 << USBDEV_ENDPTCTRL0_TXT_SHIFT) /* Control */

#define USBDEV_ENDPTCTRL0_TXS                (1 << 16) /* Bit 16: Tx endpoint stall */
#define USBDEV_ENDPTCTRL0_RXE                (1 << 7)  /* Bit 7:  Rx endpoint enable */
#define USBDEV_ENDPTCTRL0_RXT_SHIFT          (2)       /* Bits 2-3: Endpoint type */
#define USBDEV_ENDPTCTR0L_RXT_MASK           (0x3 << USBDEV_ENDPTCTRL0_RXT_SHIFT)
#  define USBDEV_ENDPTCTRL0_RXT_CTRL         (0 << USBDEV_ENDPTCTRL0_RXT_SHIFT) /* Control */

#define USBDEV_ENDPTCTRL0_RXS                (1 << 0)  /* Bit 0:  Rx endpoint stall */

/* USB Endpoint 1-7 control registers ENDPTCTRL1-ENDPPTCTRL7 */

#define USBDEV_ENDPTCTRL_TXE                 (1 << 23) /* Bit 23: Tx endpoint enable */
#define USBDEV_ENDPTCTRL_TXR                 (1 << 22) /* Bit 22: Tx data toggle reset */
#define USBDEV_ENDPTCTRL_TXI                 (1 << 21) /* Bit 21: Tx data toggle inhibit */
#define USBDEV_ENDPTCTRL_TXT_SHIFT           (18)      /* Bits 18-19: Tx endpoint type */
#define USBDEV_ENDPTCTRL_TXT_MASK            (0x3 << USBDEV_ENDPTCTRL_TXT_SHIFT)
#  define USBDEV_ENDPTCTRL_TXT_CTRL          (0 << USBDEV_ENDPTCTRL_TXT_SHIFT) /* Control */
#  define USBDEV_ENDPTCTRL_TXT_ISOC          (1 << USBDEV_ENDPTCTRL_TXT_SHIFT) /* Isochronous */
#  define USBDEV_ENDPTCTRL_TXT_BULK          (2 << USBDEV_ENDPTCTRL_TXT_SHIFT) /* Bulk */
#  define USBDEV_ENDPTCTRL_TXT_INTR          (3 << USBDEV_ENDPTCTRL_TXT_SHIFT) /* Interrupt */

#define USBDEV_ENDPTCTRL_TXS                 (1 << 16) /* Bit 16: Tx endpoint stall */
#define USBDEV_ENDPTCTRL_RXE                 (1 << 7)  /* Bit 7:  Rx endpoint enable */
#define USBDEV_ENDPTCTRL_RXR                 (1 << 6)  /* Bit 6:  Rx data toggle reset */
#define USBDEV_ENDPTCTRL_RXI                 (1 << 5)  /* Bit 5:  Rx data toggle inhibit */
#define USBDEV_ENDPTCTRL_RXT_SHIFT           (2)       /* Bits 2-3: Endpoint type */
#define USBDEV_ENDPTCTRL_RXT_MASK            (0x3 << USBDEV_ENDPTCTRL_RXT_SHIFT)
#  define USBDEV_ENDPTCTRL_RXT_CTRL          (0 << USBDEV_ENDPTCTRL_RXT_SHIFT) /* Control */
#  define USBDEV_ENDPTCTRL_RXT_ISOC          (1 << USBDEV_ENDPTCTRL_RXT_SHIFT) /* Isochronous */
#  define USBDEV_ENDPTCTRL_RXT_BULK          (2 << USBDEV_ENDPTCTRL_RXT_SHIFT) /* Bulk */
#  define USBDEV_ENDPTCTRL_RXT_INTR          (3 << USBDEV_ENDPTCTRL_RXT_SHIFT) /* Interrupt */

#define USBDEV_ENDPTCTRL_RXS                 (1 << 0)  /* Bit 0:  Rx endpoint stall */

/* Device non-core registers */

/* USB OTG Control register 1 */

#define USBNC_CTRL1_WIR                      (1 << 31) /* Bit 31: Wake-up Interrupt Request */
#define USBNC_CTRL1_WKUP_DPDM_EN             (1 << 29) /* Bit 29: Wake-up on DP/DM change enable */
#define USBNC_CTRL1_WKUP_VBUS_EN             (1 << 17) /* Bit 17: Wake-up on VBUS change enable */
#define USBNC_CTRL1_WKUP_ID_EN               (1 << 16) /* Bit 16: Wake-up on ID change enable */
#define USBNC_CTRL1_WKUP_SW                  (1 << 15) /* Bit 15: Software Wake-up */
#define USBNC_CTRL1_WKUP_SW_EN               (1 << 14) /* Bit 14: Software Wake-up Enable */
#define USBNC_CTRL1_WIE                      (1 << 10) /* Bit 10: Wake-up Interrupt Enable */
#define USBNC_CTRL1_PWR_POL                  (1 << 9)  /* Bit 9: Power Polarity */
#define USBNC_CTRL1_OVER_CUR_POL             (1 << 8)  /* Bit 8: Polarity of Overcurrent */
#define USBNC_CTRL1_OVER_CUR_DIS             (1 << 7)  /* Bit 7: Disable Overcurrent Detection */

/* USB OTG Control register 2 */

#define USBNC_CTRL2_UTMI_CLK_VLD             (1 << 31) /* Bit 31: UTMI clock to the USB PHY is valid */
#define USBNC_CTRL2_SHORT_PKT_EN             (1 << 23) /* Bit 23: Short Packet Interrupt enable */
#define USBNC_CTRL2_LOWSPEED_EN              (1 << 3)  /* Bit 3: Low speed enable */
#define USBNC_CTRL2_AUTURESUME_EN            (1 << 2)  /* Bit 2: Auto Resume Enable */
#define USBNC_CTRL2_VBUS_SOURCE_SEL_MASK     (0x3)     /* Bits 0-1: VBUS source select at VBUS wakeup event */

/* PHY Configure 1 -- internal control register bits of the PHY clock */

#define USBNC_UTMIPHY_CFG1_TXPREEMPPULSETUNE0     (1 << 30) /* Bit 30: HS Transmitter Pre-Emphasis Duration Control */
#define USBNC_UTMIPHY_CFG1_TXPREEMPAMPTUNE0_SHIFT (28)      /* Bits 28-29: HS Transmitter Pre-Emphasis Current Control */
#define USBNC_UTMIPHY_CFG1_TXPREEMPAMPTUNE0_MASK  (0x3 << 28)
#define USBNC_UTMIPHY_CFG1_TXRESTUNE0_SHIFT       (26)      /* Bits 26-27: USB Source Impedance Adjustment */
#define USBNC_UTMIPHY_CFG1_TXRESTUNE0_MASK        (0x3 << 26)
#define USBNC_UTMIPHY_CFG1_TXRISETUNE0_SHIFT      (24)      /* Bits 24-25: HS Transmitter Rise/Fall Time Adjustment */
#define USBNC_UTMIPHY_CFG1_TXRISETUNE0_MASK       (0x3 << 24)
#define USBNC_UTMIPHY_CFG1_TXVREFTUNE0_SHIFT      (20)      /* Bits 20-23: HS DC Voltage Level Adjustment */
#define USBNC_UTMIPHY_CFG1_TXVREFTUNE0_MASK       (0xf << 20)
#define USBNC_UTMIPHY_CFG1_TXFSLSTUNE0_SHIFT      (16)      /* Bits 16-19: FS/LS Source Impedance Adjustment */
#define USBNC_UTMIPHY_CFG1_TXFSLSTUNE0_MASK       (0xf << 16)
#define USBNC_UTMIPHY_CFG1_PHY_POR_SW             (1 << 15) /* Bit 15 : PHY software POR */
#define USBNC_UTMIPHY_CFG1_TXHSXVTUNE_SHIFT       (13)      /* Bits 13-14: Transmitter High-Speed Crossover Adjustment */
#define USBNC_UTMIPHY_CFG1_TXHSXVTUNE_MASK        (0x3 << 13)
#define USBNC_UTMIPHY_CFG1_OTGTUNE0_SHIFT         (10)      /* Bits 10-12: VBUS Valid Threshold Adjustment */
#define USBNC_UTMIPHY_CFG1_OTGTUNE0_MASK          (0x7 << 10)
#define USBNC_UTMIPHY_CFG1_SQRXTUNE0_SHIFT        (7)       /* Bits 7-9: Squelch Threshold Adjustment */
#define USBNC_UTMIPHY_CFG1_SQRXTUNE0_MASK         (0x7 << 7)
#define USBNC_UTMIPHY_CFG1_COMPDISTUNE0_SHIFT     (4)       /* Bits 4-6: Disconnect Threshold Adjustment */
#define USBNC_UTMIPHY_CFG1_COMPDISTUNE0_MASK      (0x7 << 4)

#endif /* __ARCH_ARM64_SRC_IMX9_HARDWARE_IMX9_USBOTG_H */

/****************************************************************************
 * arch/arm/src/max326xx/max326_periphclks.h
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

#ifndef __ARCH_ARM_SRC_MAX326XX_MAX326_PERIPHCLKS_H
#define __ARCH_ARM_SRC_MAX326XX_MAX326_PERIPHCLKS_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#if defined(CONFIG_ARCH_FAMILY_MAX32620) || defined(CONFIG_ARCH_FAMILY_MAX32630)
#  include "max32620_30/max32620_30_periphclks.h"
#elif defined(CONFIG_ARCH_FAMILY_MAX32660)
#  include "max32660/max32660_periphclks.h"
#else
#  error "Unsupported MAX326XX family"
#endif

#endif /* __ARCH_ARM_SRC_MAX326XX_MAX326_PERIPHCLKS_H */

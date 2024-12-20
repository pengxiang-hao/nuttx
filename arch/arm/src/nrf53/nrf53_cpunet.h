/****************************************************************************
 * arch/arm/src/nrf53/nrf53_cpunet.h
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

#ifndef __ARCH_ARM_SRC_NRF53_NRF53_CPUNET_H
#define __ARCH_ARM_SRC_NRF53_NRF53_CPUNET_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifndef CONFIG_NRF53_NET_GPIO_ALLOW_ALL
/****************************************************************************
 * Name: nrf53_board_gpio_cpunet_allow
 *
 * Description:
 *   Board logic may implement own set of GPIOs available for the Net core.
 *
 ****************************************************************************/

void nrf53_board_gpio_cpunet_allow(void);
#endif

/****************************************************************************
 * Name: nrf53_cpunet_power
 ****************************************************************************/

void nrf53_cpunet_power(bool enable);

/****************************************************************************
 * Name: nrf53_cpunet_boot
 ****************************************************************************/

void nrf53_cpunet_boot(void);

#endif /* __ARCH_ARM_SRC_NRF53_NRF53_CPUNET_H */

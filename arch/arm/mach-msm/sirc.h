/* arch/arm/mach-msm/pm.h
 *
 * Copyright (C) 2009 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _ARCH_ARM_MACH_MSM_SIRC_H
#define _ARCH_ARM_MACH_MSM_SIRC_H

#ifdef CONFIG_ARCH_QSD8X50
void sirc_fiq_select(int irq, bool enable);
void __init msm_init_sirc(void);

struct sirc_regs_t {
	void    *int_enable;
	void    *int_enable_clear;
	void    *int_enable_set;
	void    *int_type;
	void    *int_polarity;
	void    *int_clear;
};

struct sirc_cascade_regs {
	void    *int_status;
	unsigned int    cascade_irq;
	unsigned int    cascade_fiq;
};

#define SIRC_MASK                     0x007FFFFF

#define SPSS_SIRC_INT_SELECT          (MSM_SIRC_BASE + 0x00)
#define SPSS_SIRC_INT_ENABLE          (MSM_SIRC_BASE + 0x04)
#define SPSS_SIRC_INT_ENABLE_CLEAR    (MSM_SIRC_BASE + 0x08)
#define SPSS_SIRC_INT_ENABLE_SET      (MSM_SIRC_BASE + 0x0C)
#define SPSS_SIRC_INT_TYPE            (MSM_SIRC_BASE + 0x10)
#define SPSS_SIRC_INT_POLARITY        (MSM_SIRC_BASE + 0x14)
#define SPSS_SIRC_SECURITY            (MSM_SIRC_BASE + 0x18)
#define SPSS_SIRC_IRQ_STATUS          (MSM_SIRC_BASE + 0x1C)
#define SPSS_SIRC_IRQ1_STATUS         (MSM_SIRC_BASE + 0x20)
#define SPSS_SIRC_RAW_STATUS          (MSM_SIRC_BASE + 0x24)
#define SPSS_SIRC_INT_CLEAR           (MSM_SIRC_BASE + 0x28)
#define SPSS_SIRC_SOFT_INT            (MSM_SIRC_BASE + 0x2C)

#else
static inline void sirc_fiq_select(int irq, bool enable) {}
static inline void __init msm_init_sirc(void) {}
#endif

#endif

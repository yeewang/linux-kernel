/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _ASM_RISCV_PGTABLE_BITS_H
#define _ASM_RISCV_PGTABLE_BITS_H

/*
 * PTE format:
 * | XLEN-1  10 | 9             8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0
 *       PFN      reserved for SW   D   A   G   U   X   W   R   V
 */

#define _PAGE_ACCESSED_OFFSET 6

#define _PAGE_PRESENT   (1 << 0)
#define _PAGE_READ      (1 << 1)    /* Readable */
#define _PAGE_WRITE     (1 << 2)    /* Writable */
#define _PAGE_EXEC      (1 << 3)    /* Executable */
#define _PAGE_USER      (1 << 4)    /* User */
#define _PAGE_GLOBAL    (1 << 5)    /* Global */
#define _PAGE_ACCESSED  (1 << 6)    /* Set by hardware on any access */
#define _PAGE_DIRTY     (1 << 7)    /* Set by hardware on any write */
#define _PAGE_SOFT      (1 << 8)    /* Reserved for software */

/* T-HEAD C9xx extend */
#ifdef CONFIG_STD_SVPBMT
#define _PAGE_SEC	(0UL << 00)   /* Security */
#define _PAGE_SHARE	(0UL << 00)   /* Shareable */
#define _PAGE_BUF	(0UL << 00)   /* Bufferable */
#define _PAGE_CACHE	(0UL << 00)   /* Cacheable */
#define _PAGE_SO	(1UL << 62)   /* Strong Order */
#else
#define _PAGE_SEC	(1UL << 59)   /* Security */
#define _PAGE_SHARE	(1UL << 60)   /* Shareable */
#define _PAGE_BUF	(1UL << 61)   /* Bufferable */
#define _PAGE_CACHE	(1UL << 62)   /* Cacheable */
#define _PAGE_SO	(1UL << 63)   /* Strong Order */
#endif

#define _PAGE_SPECIAL   _PAGE_SOFT
#define _PAGE_TABLE     _PAGE_PRESENT

/*
 * _PAGE_PROT_NONE is set on not-present pages (and ignored by the hardware) to
 * distinguish them from swapped out pages
 */
#define _PAGE_PROT_NONE _PAGE_READ

#define _PAGE_PFN_SHIFT 10

/* Set of bits to preserve across pte_modify() */
#define _PAGE_CHG_MASK  (~(unsigned long)(_PAGE_PRESENT | _PAGE_READ |	\
					  _PAGE_WRITE | _PAGE_EXEC |	\
					  _PAGE_USER | _PAGE_GLOBAL |	\
					  _PAGE_SEC | _PAGE_SHARE |	\
					  _PAGE_BUF | _PAGE_CACHE |	\
					  _PAGE_SO ))

#endif /* _ASM_RISCV_PGTABLE_BITS_H */

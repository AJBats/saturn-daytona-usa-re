/* fpmul.s -- Math utilities & DMA transfer
 * Translation unit: 0x06027552 - 0x060276CC
 *
 * Function catalog:
 *   fpmul            — 16.16 fixed-point multiply (r4 * r5 >> 16)
 *   fpdiv_setup      — 16.16 fixed-point divide via SH-2 hardware divider
 *   memmove_byte     — overlap-safe byte-granularity memmove
 *   memmove_word     — overlap-safe 16-bit word memmove
 *   memmove_long     — overlap-safe 32-bit longword memmove
 *   memcpy_byte_idx  — forward-only byte memcpy (indexed)
 *   memcpy_word_idx  — forward-only word memcpy (indexed)
 *   memcpy_long_idx  — forward-only long memcpy (indexed)
 *   memcpy_block32   — high-performance 32-byte block copy
 *   dma_transfer     — SCU DMA level 0 transfer (busy-wait)
 *   viewport_project — 3D viewport projection (screen coords)
 */

    .section .text.FUN_06027552


/* fpmul(r4=a, r5=b) -> r0 = (a * b) >> 16
 * 16.16 fixed-point multiply using 32x32->64 hardware multiplier.
 * dmuls.l gives 64-bit result in MACH:MACL; xtrct extracts middle 32 bits.
 * Called hundreds of times per frame — this is THE core fixed-point multiply.
 */
    .global fpmul
    .type fpmul, @function
fpmul:
    dmuls.l r4, r5              /* signed 32x32->64: MACH:MACL = a * b */
    sts mach, r4                /* r4 = high 32 bits */
    sts macl, r0                /* r0 = low 32 bits */
    rts
    xtrct r4, r0                /* r0 = (r4<<16)|(r0>>16) = middle 32 = (a*b)>>16 */

/* fpdiv_setup(r4=dividend, r5=divisor) -> r0 = r4/r5 in 16.16
 * Uses SH-2 hardware division unit at 0xFFFFFF00:
 *   +0x00 DVSR   — divisor (written first)
 *   +0x10 DVDNTH — dividend high (sign-extended integer part)
 *   +0x14 DVDNTL — dividend low  (fractional part, triggers division)
 *   +0x1C result — quotient (ready in 39 cycles)
 *
 * By placing dividend in the 64-bit pair (high:low = integer:fraction<<16),
 * the hardware computes (dividend << 16) / divisor, yielding 16.16 result.
 * NOTE: Not interrupt-safe — no DIVU lock.
 */
    .global fpdiv_setup
fpdiv_setup:
    mov.w   .L_divu_base, r2    /* r2 = 0xFFFFFF00 (SH-2 division unit) */
    mov r4, r3
    mov.l r5, @(0, r2)         /* DVSR = divisor */
    shlr16 r3                   /* r3 = dividend >> 16 (integer part) */
    exts.w r3, r3               /* sign-extend to 32 bits */
    mov.l r3, @(16, r2)        /* DVDNTH = sign-extended integer part */
    shll16 r4                   /* r4 = dividend << 16 (fractional alignment) */
    mov.l r4, @(20, r2)        /* DVDNTL = fraction (triggers division) */
    rts
    mov.l @(28, r2), r0        /* r0 = quotient from +0x1C */
.L_divu_base:
    .2byte  0xFF00              /* sign-extends to 0xFFFFFF00 */
    .2byte  0x0000              /* padding */

/* memmove_byte(r4=dst, r5=src, r6=count)
 * Overlap-safe byte copy. Detects direction:
 *   dst > src: copy backward (prevents corruption on overlap)
 *   dst <= src: copy forward
 *   dst == src or count == 0: return immediately
 */
    .global memmove_byte
memmove_byte:
    cmp/eq r4, r5               /* dst == src? */
    bt      .L_06027592         /* yes: nothing to do */
    mov #0x0, r7
    cmp/eq r7, r6               /* count == 0? */
    bt      .L_06027592         /* yes: nothing to do */
    cmp/hi r4, r5               /* src > dst (unsigned)? */
    bt      .L_06027596         /* yes: copy forward */
    add r6, r5                  /* backward: start from end */
    add r6, r4
    add #-0x1, r5
.L_06027588:
    mov.b @r5, r7               /* load byte from src */
    dt r6                       /* count-- */
    mov.b r7, @-r4              /* store to dst (pre-decrement) */
    bf/s    .L_06027588
    add #-0x1, r5               /* src-- */
.L_06027592:
    rts
    nop
.L_06027596:                    /* forward copy */
    mov.b @r5+, r7              /* load byte, src++ */
    dt r6                       /* count-- */
    mov.b r7, @r4               /* store to dst */
    bf/s    .L_06027596
    add #0x1, r4                /* dst++ */
    rts
    nop

/* memmove_word(r4=dst, r5=src, r6=byte_count)
 * Overlap-safe 16-bit word copy. Count is in bytes, halved internally.
 */
    .global memmove_word
memmove_word:
    cmp/eq r4, r5
    bt      .L_060275C6
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .L_060275C6
    mov r6, r7                  /* save original byte count */
    cmp/hi r4, r5
    bt/s    .L_060275CA         /* forward if src > dst */
    shlr r6                     /* r6 = count / 2 (word count) */
    add r7, r5                  /* backward: start from end */
    add r7, r4
    add #-0x4, r5               /* back up past last word (accounts for @r5 read) */
.L_060275BC:
    mov.w @r5, r7
    dt r6
    mov.w r7, @-r4
    bf/s    .L_060275BC
    add #-0x2, r5
.L_060275C6:
    rts
    nop
.L_060275CA:                    /* forward copy */
    mov.w @r5+, r7
    dt r6
    mov.w r7, @r4
    bf/s    .L_060275CA
    add #0x2, r4
    rts
    nop

/* memmove_long(r4=dst, r5=src, r6=byte_count)
 * Overlap-safe 32-bit longword copy. Count is in bytes, quartered internally.
 */
    .global memmove_long
memmove_long:
    cmp/eq r4, r5
    bt      .L_060275FA
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .L_060275FA
    mov r6, r7                  /* save original byte count */
    cmp/hi r4, r5
    bt/s    .L_060275FE         /* forward if src > dst */
    shlr2 r6                    /* r6 = count / 4 (long count) */
    add r7, r5                  /* backward: start from end */
    add r7, r4
    add #-0x4, r5
.L_060275F0:
    mov.l @r5, r7
    dt r6
    mov.l r7, @-r4
    bf/s    .L_060275F0
    add #-0x4, r5
.L_060275FA:
    rts
    nop
.L_060275FE:                    /* forward copy */
    mov.l @r5+, r7
    dt r6
    mov.l r7, @r4
    bf/s    .L_060275FE
    add #0x4, r4
    rts
    nop

/* memcpy_byte_idx(r4=dst, r5=src, r6=byte_count)
 * Forward-only byte copy using R0-indexed addressing.
 * More compact than memmove but no overlap handling.
 */
    .global memcpy_byte_idx
memcpy_byte_idx:
    mov #0x0, r0                /* r0 = index = 0 */
    add #-0x1, r6               /* r6 = count - 1 (for cmp/gt) */
.L_06027610:
    mov.b @(r0, r5), r1         /* r1 = src[index] */
    cmp/gt r0, r6               /* more bytes? */
    mov.b r1, @(r0, r4)         /* dst[index] = r1 */
    bt/s    .L_06027610
    add #0x1, r0                /* index++ */
    rts
    add #0x1, r6                /* restore r6 (count) */

/* memcpy_word_idx(r4=dst, r5=src, r6=byte_count)
 * Forward-only 16-bit word copy using R0-indexed addressing.
 */
    .global memcpy_word_idx
memcpy_word_idx:
    mov #0x0, r0
    add #-0x2, r6
.L_06027622:
    mov.w @(r0, r5), r1
    cmp/gt r0, r6
    mov.w r1, @(r0, r4)
    bt/s    .L_06027622
    add #0x2, r0
    rts
    add #0x2, r6

/* memcpy_long_idx(r4=dst, r5=src, r6=byte_count)
 * Forward-only 32-bit longword copy using R0-indexed addressing.
 */
    .global memcpy_long_idx
memcpy_long_idx:
    mov #0x0, r0
    add #-0x4, r6
.L_06027634:
    mov.l @(r0, r5), r1
    cmp/gt r0, r6
    mov.l r1, @(r0, r4)
    bt/s    .L_06027634
    add #0x4, r0
    rts
    add #0x4, r6

/* memcpy_block32(r4=dst, r5=src, r6=block_count)
 * High-performance block copy: 32 bytes per iteration.
 * Loads 8 longwords into r0-r3 (4+4), stores to dst, advances by 32.
 * Used for large structure copies (matrix data, model geometry).
 */
    .global memcpy_block32
memcpy_block32:
    mov.l @r5+, r0              /* load first 16 bytes */
    mov.l @r5+, r1
    mov.l @r5+, r2
    mov.l @r5+, r3
    mov.l r0, @(0, r4)          /* store first 16 bytes */
    mov.l r1, @(4, r4)
    mov.l r2, @(8, r4)
    mov.l r3, @(12, r4)
    mov.l @r5+, r0              /* load next 16 bytes */
    mov.l @r5+, r1
    mov.l @r5+, r2
    mov.l @r5+, r3
    mov.l r0, @(16, r4)         /* store next 16 bytes */
    mov.l r1, @(20, r4)
    mov.l r2, @(24, r4)
    mov.l r3, @(28, r4)
    dt r6                       /* block_count-- */
    bf/s    memcpy_block32
    add #0x20, r4               /* dst += 32 */
    rts
    nop

/* dma_transfer(r4=src, r5=dst, r6=size)
 * Initiates SCU DMA level 0 transfer. Busy-waits until DMA is idle,
 * then programs source/dest/size/mode and starts transfer.
 *
 * SCU DMA Level 0 registers at 0x25FE0000:
 *   +0x00 D0R  — read (source) address
 *   +0x04 D0W  — write (dest) address
 *   +0x08 D0C  — transfer byte count
 *   +0x0C D0AD — address add (0x0101 = src+4, dst+4)
 *   +0x10 D0EN — enable (0x0101 = enable + start)
 *   +0x14 D0MD — mode (7 = direct, immediate start)
 *
 * NOTE: r4=source written to +0x04, r5=dest written to +0x00.
 * The SCU swaps read/write compared to typical memcpy convention.
 */
    .global dma_transfer
dma_transfer:
    .byte   0xD0, 0x07    /* mov.l .L_scu_dsta, r0 */
    mov.l @r0, r0               /* r0 = DMA status register value */
    .byte   0xD1, 0x07    /* mov.l .L_dma_busy_mask, r1 */
    tst r1, r0                  /* any DMA channels busy? */
    bf      dma_transfer         /* yes: spin until idle */
    .byte   0xD1, 0x07    /* mov.l .L_scu_d0r, r1 */
    mov.w   .L_dma_mode, r2     /* r2 = 0x0101 (src+4, dst+4) */
    mov.l r4, @(4, r1)         /* D0W (+0x04) = source */
    mov.l r5, @(0, r1)         /* D0R (+0x00) = dest */
    mov.l r6, @(8, r1)         /* D0C (+0x08) = byte count */
    mov.l r2, @(12, r1)        /* D0AD (+0x0C) = 0x0101 (addr increment) */
    mov #0x7, r0                /* direct mode, immediate start */
    mov.l r0, @(20, r1)        /* D0MD (+0x14) = 7 */
    rts
    mov.l r2, @(16, r1)        /* D0EN (+0x10) = 0x0101 (enable + go) */
.L_dma_mode:
    .2byte  0x0101              /* DMA addr mode: src+4, dst+4 */
.L_scu_dsta:
    .4byte  0x25FE007C                  /* SCU DSTA — DMA status */
.L_dma_busy_mask:
    .4byte  0x0000272E          /* DMA busy bits (all 3 levels operating/standby) */
.L_scu_d0r:
    .4byte  0x25FE0000                  /* SCU D0R — DMA level 0 read addr */
    .4byte  0x00090000          /* unused padding (next TU boundary) */

/* viewport_project(r4=coords_3d, r5=screen_out)
 * Projects 3D coordinates to 2D screen space.
 * Reads XYZ from r4 struct, multiplies by projection factor,
 * writes 16-bit screen X/Y to r5.
 *
 * Uses hardware division unit at 0xFFFFFF00 for perspective divide:
 *   +0x00 DVSR — set to Z coordinate
 *   +0x10 DVDNTH — projection constant
 *   +0x14 DVDNTL — triggers division
 *   +0x1C result — 1/Z projection factor
 *
 * Then: screen_x = X * factor (dmuls.l, take MACH = high 16 bits)
 *        screen_y = -Y * factor (Y is negated for screen coords)
 */
    .global viewport_project
viewport_project:
    mov.w   .L_divu_base_b, r1  /* r1 = 0xFFFFFF00 (division unit) */
    mov.w   .L_proj_scale, r0   /* r0 = 0x00A0 = 160 (half-screen width) */
    mov.l @(8, r4), r2         /* r2 = Z coordinate */
    mov.l r0, @(16, r1)        /* DVDNTH = 160 (projection numerator) */
    mov.l r2, @(0, r1)         /* DVSR = Z (triggers perspective divide) */
    mov #0x0, r0
    mov.l r0, @(20, r1)        /* DVDNTL = 0 (low dividend) */
    mov.l @(4, r4), r0         /* r0 = Y coordinate */
    mov.l @r4, r2              /* r2 = X coordinate */
    neg r0, r0                  /* negate Y (screen Y is inverted) */
    mov.l @(28, r1), r4        /* r4 = projection factor (160/Z) */
    dmuls.l r2, r4              /* MACH:MACL = X * factor */
    sts mach, r2                /* r2 = high 32 bits = screen X */
    dmuls.l r0, r4              /* MACH:MACL = (-Y) * factor */
    mov.w r2, @r5              /* store screen X (16-bit) */
    sts mach, r0                /* r0 = high 32 bits = screen Y */
    rts
    mov.w r0, @(2, r5)         /* store screen Y (16-bit) */
.L_divu_base_b:
    .2byte  0xFF00              /* sign-extends to 0xFFFFFF00 */
    .2byte  0x0009              /* padding (not referenced) */
    .4byte  0x00010000          /* 16.16 constant 1.0 (not referenced by this fn) */
    .2byte  0xFF00              /* padding (not referenced) */
.L_proj_scale:
    .2byte  0x00A0              /* 160 = half of 320px screen width */

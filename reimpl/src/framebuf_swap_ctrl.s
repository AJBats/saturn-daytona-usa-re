/* framebuf_swap_ctrl.s -- SH-2 FRT compare-match A interrupt handler
 * Translation unit: 0x060072E6 - 0x0600736C
 *
 * Function catalog:
 *   framebuf_swap_ctrl — FRT Output Compare A (OCRA) interrupt handler.
 *                        Provides frame timing tick for buffer swap control.
 *
 * This is an interrupt handler (returns via RTE, saves all registers).
 * The SH-2 Free-Running Timer (FRT) generates an interrupt when FRC
 * matches OCRA. This handler:
 *   1. Clears SCU interrupt mask bit 0x83 (enables nested interrupts)
 *   2. Increments frame tick counter (sym_06059F40)
 *   3. Clears FRT compare-match flags in FTCSR (AND #0x87 clears OCFA/OCFB/OVF)
 *   4. Clears SCU interrupt request (bit 0xFF7C)
 *
 * SH-2 FRT registers used:
 *   FTCSR (0xFFFFFE11) — Free-running Timer Control/Status Register
 *     bit6=OCFA (compare match A flag), bit5=OCFB, bit4=OVF (overflow)
 *     AND #0x87 clears bits 6:4 (all status flags), keeps control bits
 */

    .section .text.FUN_060072E6


    .global framebuf_swap_ctrl
    .type framebuf_swap_ctrl, @function
framebuf_swap_ctrl:
    /* Full register save — interrupt context */
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l r7, @-r15
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l r4, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l r1, @-r15
    mov.l r0, @-r15
    sts.l pr, @-r15
    sts.l mach, @-r15
    sts.l macl, @-r15

    /* Clear SCU interrupt bits to allow nested interrupts */
    .byte   0xD3, 0x16    /* mov.l .L_fn_scu_int_ctrl, r3 */
    mov.w   .L_scu_clear_mask, r5     /* r5 = 0x0083 (interrupt clear bits) */
    mov.l @r3, r3
    jsr @r3
    mov #-0x1, r4                      /* r4 = -1 (all bits) */

    /* Increment frame tick counter */
    .byte   0xD2, 0x14    /* mov.l .L_frame_tick_ctr, r2 */
    .byte   0xD3, 0x14    /* mov.l .L_frame_tick_ctr, r3 */
    mov.l @r2, r2
    add #0x1, r2
    mov.l r2, @r3                      /* counter++ */

    /* Clear FRT compare-match flags in FTCSR */
    mov.w   .L_frt_ftcsr, r5          /* r5 = 0xFE11 → 0xFFFFFE11 (FTCSR) */
    mov.b @r5, r4                      /* read current FTCSR */
    extu.b r4, r0
    and #0x87, r0                      /* clear OCFA/OCFB/OVF flags (bits 6:4) */
    mov.b r0, @r5                      /* write back */

    /* Clear SCU interrupt request */
    .byte   0xD3, 0x0E    /* mov.l .L_fn_scu_int_ctrl, r3 */
    mov.w   .L_scu_req_clear, r4      /* r4 = 0xFF7C (sign-ext → interrupt clear) */
    mov.l @r3, r3
    jsr @r3
    mov #0x0, r5                       /* r5 = 0 (clear mode) */

    /* Full register restore + return from interrupt */
    lds.l @r15+, macl
    lds.l @r15+, mach
    lds.l @r15+, pr
    mov.l @r15+, r0
    mov.l @r15+, r1
    mov.l @r15+, r2
    mov.l @r15+, r3
    mov.l @r15+, r4
    mov.l @r15+, r5
    mov.l @r15+, r6
    mov.l @r15+, r7
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    mov.l @r15+, r15
    rte
    nop

/* Word pool */
.L_scu_clear_mask:
    .2byte  0x0083                     /* SCU interrupt clear bits */
.L_frt_ftcsr:
    .2byte  0xFE11                     /* SH-2 FRT FTCSR (0xFFFFFE11) */
.L_scu_req_clear:
    .2byte  0xFF7C                     /* SCU interrupt request clear */
    .2byte  0xFFFF

/* Long pool */
.L_fn_scu_int_ctrl:
    .4byte  sym_06000344               /* SCU interrupt control function */
.L_frame_tick_ctr:
    .4byte  sym_06059F40               /* frame tick counter (incremented per OCRA match) */

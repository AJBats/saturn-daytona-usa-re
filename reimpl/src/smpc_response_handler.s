/* smpc_response_handler.s -- Interrupt-safe SMPC peripheral query wrapper
 * Translation unit: 0x06035D22 - 0x06035D5A
 *
 * Function catalog:
 *   smpc_response_handler — Disables interrupts, calls smpc_peripheral_query,
 *                           restores interrupt level. Ensures atomic SMPC access.
 */

    .section .text.FUN_06035D22

/* smpc_response_handler() -> r0 = peripheral query result
 * Wrapper that raises SH-2 interrupt mask to level 15 (all blocked) before
 * calling smpc_peripheral_query, then restores the original interrupt level.
 * This prevents SMPC INTBACK response reads from being interrupted mid-read
 * (which would corrupt the packed OREG data).
 *
 * SR register layout: bits [7:4] = interrupt mask level (I3-I0)
 * Level 15 = all interrupts blocked; level 0 = all enabled.
 */
    .global smpc_response_handler
    .type smpc_response_handler, @function
smpc_response_handler:
    mov.l r14, @-r15            /* save r14 */
    sts.l pr, @-r15             /* save return address */
    stc sr, r0                  /* r0 = current SR */
    shlr2 r0                    /* shift interrupt level to bits [5:2] */
    shlr2 r0                    /* shift to bits [3:0] */
    and #0xF, r0                /* r0 = original interrupt level (0-15) */
    mov r0, r14                 /* r14 = saved interrupt level */
    stc sr, r0                  /* r0 = current SR again */
    .byte   0x93, 0x29    /* mov.w .L_wpool_06035D88, r3 */
    and r3, r0                  /* clear interrupt mask bits (keep T,S,M,Q) */
    or #0xF0, r0                /* set interrupt level to 15 (block all) */
    ldc r0, sr                  /* apply: interrupts now disabled */
    .byte   0xB0, 0x0E    /* bsr 0x06035D5A (smpc_peripheral_query) */
    nop
    mov r0, r4                  /* r4 = query result (saved across SR restore) */
    mov r14, r0                 /* r0 = original interrupt level */
    and #0xF, r0                /* mask to 4 bits */
    shll2 r0                    /* shift back to SR position [5:2] */
    shll2 r0                    /* shift to bits [7:4] */
    stc sr, r2                  /* r2 = current SR */
    .byte   0x93, 0x1D    /* mov.w .L_wpool_06035D88, r3 */
    and r3, r2                  /* clear interrupt mask bits */
    or r2, r0                   /* combine: original level + other SR bits */
    ldc r0, sr                  /* restore original interrupt level */
    mov r4, r0                  /* r0 = query result */
    lds.l @r15+, pr             /* restore return address */
    rts
    mov.l @r15+, r14            /* restore r14 */

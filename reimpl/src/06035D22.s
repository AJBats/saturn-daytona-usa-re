
    .section .text.FUN_06035D22

    .global smpc_response_handler
    .type smpc_response_handler, @function
smpc_response_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    stc sr, r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov r0, r14
    stc sr, r0
    .byte   0x93, 0x29    /* mov.w .L_wpool_06035D88, r3 */
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    .byte   0xB0, 0x0E    /* bsr 0x06035D5A (smpc_peripheral_query) */
    nop
    mov r0, r4
    mov r14, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r2
    .byte   0x93, 0x1D    /* mov.w .L_wpool_06035D88, r3 */
    and r3, r2
    or r2, r0
    ldc r0, sr
    mov r4, r0
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

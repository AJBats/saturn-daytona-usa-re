
    .section .text.FUN_06009DD0


    .global state_postrace_wait_init
    .type state_postrace_wait_init, @function
state_postrace_wait_init:
    sts.l pr, @-r15
    .byte   0xD3, 0x19    /* mov.l .L_pool_06009E38, r3 */
    jsr @r3
    nop
    mov #0x1B, r2
    .byte   0xD3, 0x18    /* mov.l .L_pool_06009E3C, r3 */
    mov.l r2, @r3
    .byte   0x92, 0x29    /* mov.w .L_wpool_06009E34, r2 */
    .byte   0xD3, 0x17    /* mov.l .L_pool_06009E40, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x17    /* mov.l .L_pool_06009E44, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x17    /* mov.l .L_pool_06009E48, r3 */
    jsr @r3
    nop
    mov #0x3, r2
    .byte   0xD3, 0x16    /* mov.l .L_pool_06009E4C, r3 */
    mov.w r2, @r3
    mov #0x0, r6
    mov #0x13, r5
    mov r5, r4
    .byte   0xD3, 0x14    /* mov.l .L_pool_06009E50, r3 */
    jmp @r3
    lds.l @r15+, pr

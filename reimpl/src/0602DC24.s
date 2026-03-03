
    .section .text.FUN_0602DC24


    .global vdp1_cmd_init
    .type vdp1_cmd_init, @function
vdp1_cmd_init:
    mov.l r14, @-r15
    .byte   0xD0, 0x05    /* mov.l .L_pool_0602DC3C, r0 */
    mov.l @r0, r0
    shll2 r0
    .byte   0xD1, 0x04    /* mov.l .L_pool_0602DC40, r1 */
    mov.l @(r0, r1), r0

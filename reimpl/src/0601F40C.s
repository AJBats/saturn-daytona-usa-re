
    .section .text.FUN_0601F40C


    .global geom_output_handler
    .type geom_output_handler, @function
geom_output_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x20    /* mov.l .L_pool_0601F494, r14 */
    .byte   0xD2, 0x21    /* mov.l .L_pool_0601F498, r2 */
    mov.b @r14, r3
    extu.b r3, r3
    add r2, r3
    mov.b @r3, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601F45E
    .byte   0xBD, 0xCF    /* bsr 0x0601EFC4 (external) */
    nop
    .byte   0xD6, 0x1D    /* mov.l .L_pool_0601F49C, r6 */
    mov.b @r14, r5
    .byte   0xD2, 0x1D    /* mov.l .L_pool_0601F4A0, r2 */
    mov.b @r14, r4
    mov.l @r6, r6
    extu.b r5, r5
    extu.b r4, r4
    mov r5, r3
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    add r2, r5
    .byte   0xD3, 0x18    /* mov.l .L_pool_0601F4A4, r3 */
    add r3, r4
    mov.b @r4, r4
    .byte   0xB9, 0xE3    /* bsr 0x0601E810 (external) */
    extu.b r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0601F45E
    mov #0xC, r3
    .byte   0xD2, 0x15    /* mov.l .L_pool_0601F4A8, r2 */
    mov.b r3, @r2
    lds.l @r15+, pr
    .byte   0xD3, 0x14    /* mov.l .L_pool_0601F4AC, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_0601F45E:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

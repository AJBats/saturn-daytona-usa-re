
    .section .text.FUN_06035E90


    .global FUN_06035E90
    .type FUN_06035E90, @function
FUN_06035E90:
    sts.l pr, @-r15
    mov r4, r1
    .byte   0xD2, 0x13    /* mov.l .L_pool_06035EE4, r2 */
    .byte   0xD3, 0x14    /* mov.l .L_pool_06035EE8, r3 */
    jsr @r3
    mov #0x8, r0
    lds.l @r15+, pr
    rts
    nop


    .global FUN_06035EA2
    .type FUN_06035EA2, @function
FUN_06035EA2:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xD3, 0x11    /* mov.l .L_pool_06035EEC, r3 */
    jsr @r3
    mov r6, r14
    mov r0, r4
    tst r4, r4
    bt      .L_06035EBA
    mov r4, r0
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06035EBA:
    .byte   0xD3, 0x0D    /* mov.l .L_pool_06035EF0, r3 */
    mov.b @r14, r2
    mov.b r2, @r3
    mov r4, r0
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

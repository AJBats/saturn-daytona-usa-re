
    .section .text.FUN_06012084


    .global FUN_06012084
    .type FUN_06012084, @function
FUN_06012084:
    sts.l pr, @-r15
    .byte   0xDE, 0x0F    /* mov.l .L_pool_060120C4, r14 */
    jsr @r14
    mov #0x8, r4
    .byte   0x94, 0x19    /* mov.w .L_wpool_060120C2, r4 */
    jsr @r14
    mov #0x5, r5
    mov #0x4, r5
    jsr @r14
    mov #0x10, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sym_0601209E
sym_0601209E:
    mov #0x7, r5


    .global FUN_060120A0
    .type FUN_060120A0, @function
FUN_060120A0:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_060120C4, r14
    jsr @r14
    mov #0x20, r4
    mov #0x6, r5
    jsr @r14
    mov #0x8, r4
    mov.w   .L_wpool_060120C2, r4
    jsr @r14
    mov #0x5, r5
    mov #0x4, r5
    jsr @r14
    mov #0x10, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_060120C2:
    .2byte  0x0100
.L_pool_060120C4:
    .4byte  FUN_06038BD4

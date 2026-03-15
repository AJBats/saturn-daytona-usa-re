
    .section .text.FUN_0602DE4C


    .global FUN_0602DE4C
    .type FUN_0602DE4C, @function
FUN_0602DE4C:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x14    /* mov.l .L_pool_0602DEA8, r0 */
    cmp/ge r0, r1
    bt      .L_0602DE5C
    neg r1, r1
.L_0602DE5C:
    .byte   0xD0, 0x1E    /* mov.l .L_pool_0602DED8, r0 */
    mov.l r1, @r0

    .global FUN_0602DE60
FUN_0602DE60:
    .byte   0xDD, 0x1E    /* mov.l .L_pool_0602DEDC, r13 */

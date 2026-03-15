
    .section .text.FUN_0602E714


    .global FUN_0602E714
    .type FUN_0602E714, @function
FUN_0602E714:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov r0, r7
    mov.l @r15+, r4
    sub r6, r4
    mov r4, r5
    .byte   0xDD, 0x0D    /* mov.l .L_pool_0602E75C, r13 */

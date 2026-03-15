
    .section .text.FUN_06040964


    .global FUN_06040964
    .type FUN_06040964, @function
FUN_06040964:
    sts.l pr, @-r15
    .byte   0xD3, 0x12    /* mov.l .L_pool_060409B0, r3 */
    jsr @r3
    nop
    mov r0, r4
    cmp/pz r4
    bt      .L_06040974
    mov #0x0, r4
.L_06040974:
    lds.l @r15+, pr
    rts
    mov r4, r0
    .2byte  0x6263

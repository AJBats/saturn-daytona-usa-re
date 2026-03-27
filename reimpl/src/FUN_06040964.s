
    .section .text.FUN_06040964


    .global FUN_06040964
    .type FUN_06040964, @function
FUN_06040964:
    sts.l pr, @-r15
    mov.l   .L_pool_060409B0, r3
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


    .global FUN_0604097C
    .type FUN_0604097C, @function
FUN_0604097C:
    mov.l r14, @-r15
    mov r4, r14

    .global FUN_06040980
    .type FUN_06040980, @function
FUN_06040980:
    sts.l pr, @-r15
    mov r14, r1
    mov.l r5, @(32, r14)
    add #0x18, r1
    mov.l   .L_pool_060409B4, r3
    jsr @r3
    mov #0x6, r0
    mov #0x0, r2
    mov.l r2, @-r15
    mov r2, r7
    mov.l   .L_pool_060409B8, r3
    jsr @r3
    mov.l @(20, r14), r4
    mov r0, r4
    tst r4, r4
    bt/s    .L_060409A8
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060409A8:
    lds.l @r15+, pr
    mov.l   .L_pool_060409BC, r3
    jmp @r3
    mov.l @r15+, r14
.L_pool_060409B0:
    .4byte  FUN_06041648
.L_pool_060409B4:
    .4byte  sym_06035228
.L_pool_060409B8:
    .4byte  FUN_06041034
.L_pool_060409BC:
    .4byte  FUN_0604188C
    .4byte  0x4F26000B
    .4byte  0x6EF6E500

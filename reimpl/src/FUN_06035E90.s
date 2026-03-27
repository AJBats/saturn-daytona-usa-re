
    .section .text.FUN_06035E90


    .global FUN_06035E90
    .type FUN_06035E90, @function
FUN_06035E90:
    sts.l pr, @-r15
    mov r4, r1
    mov.l   .L_pool_06035EE4, r2
    mov.l   .L_pool_06035EE8, r3
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
    mov.l   .L_06035EEC, r3
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
    mov.l   .L_pool_06035EF0, r3
    mov.b @r14, r2
    mov.b r2, @r3
    mov r4, r0
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_06035EC8
    .type FUN_06035EC8, @function
FUN_06035EC8:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06035EEC, r3
    jsr @r3
    mov r15, r6
    mov r0, r14
    tst r14, r14
    bt      .L_06035EF4
    mov r14, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_06035EE4:
    .4byte  sym_06059CB0
.L_pool_06035EE8:
    .4byte  sym_06035168
.L_06035EEC:
    .4byte  FUN_06035D22
.L_pool_06035EF0:
    .4byte  sym_06063594
.L_06035EF4:
    mov.l   .L_06035F38, r5
    bsr     FUN_06035F16
    mov r15, r4
    mov r14, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global FUN_06035F04
    .type FUN_06035F04, @function
FUN_06035F04:
    sts.l pr, @-r15
    mov r4, r1
    mov.l   .L_06035F38, r2
    mov.l   .L_06035F3C, r3
    jsr @r3
    mov #0xC, r0
    lds.l @r15+, pr
    rts
    nop
    .global FUN_06035F16
FUN_06035F16:

    .global sym_06035F16
sym_06035F16:
    mov.b @r4, r3
    mov.b r3, @r5
    mov.b @(1, r4), r0
    mov r0, r2
    mov.b r0, @(4, r5)
    mov.b @(2, r4), r0
    mov.b r0, @(5, r5)
    mov.b @(3, r4), r0
    mov.b r0, @(6, r5)
    mov.b @(4, r4), r0
    mov.b r0, @(7, r5)
    mov.l @(4, r4), r3
    mov.l   .L_06035F40, r2
    and r2, r3
    rts
    mov.l r3, @(8, r5)
    .2byte  0xFFFF
.L_06035F38:
    .4byte  sym_06063594
.L_06035F3C:
    .4byte  sym_06035168
.L_06035F40:
    .4byte  0x00FFFFFF

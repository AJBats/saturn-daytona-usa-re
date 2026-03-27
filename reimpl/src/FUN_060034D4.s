
    .section .text.FUN_060034D4


    .global FUN_060034D4
    .type FUN_060034D4, @function
FUN_060034D4:
    mov.l r14, @-r15
    sts.l pr, @-r15

    mov.w   .L_pool_0600353C, r6
    mov.l   .L_pool_06003544, r5
    mov.l   .L_06003548, r4
    mov.l   .L_0600354C, r3
    jsr @r3
    nop

    mov.l   .L_06003550, r14
    mov.l   .L_06003554, r5
    mov.l   .L_pool_06003558, r4
    jsr @r14
    nop

    mov.l   .L_0600355C, r5
    mov.l   .L_pool_06003560, r4
    jsr @r14
    mov.l @r5, r5

    mov.l   .L_0600355C, r5
    mov.w   .L_0600353E, r2
    mov.l   .L_pool_06003564, r4
    mov.l @r5, r5
    jsr @r14
    add r2, r5

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_06003508
    .type FUN_06003508, @function
FUN_06003508:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.w   .L_06003540, r6
    mov.l   .L_06003568, r5
    mov.l   .L_06003548, r4
    mov.l   .L_0600354C, r3
    jsr @r3
    nop
    mov.l   .L_06003550, r14
    mov.l   .L_06003554, r5
    mov.l   .L_0600356C, r4
    jsr @r14
    nop
    mov.l   .L_0600355C, r5
    mov.l   .L_06003570, r4
    jsr @r14
    mov.l @r5, r5
    mov.l   .L_0600355C, r5
    mov.w   .L_0600353E, r2
    mov.l   .L_06003574, r4
    mov.l @r5, r5
    jsr @r14
    add r2, r5
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_0600353C:
    .2byte  0x00E0
.L_0600353E:
    .2byte  0x2000
.L_06003540:
    .2byte  0x0100
    .2byte  0xFFFF
.L_pool_06003544:
    .4byte  0x25F00860
.L_06003548:
    .4byte  0x25F00200
.L_0600354C:
    .4byte  FUN_0602761E
.L_06003550:
    .4byte  FUN_06028654
.L_06003554:
    .4byte  0x25E34000
.L_pool_06003558:
    .4byte  0x25E497E4
.L_0600355C:
    .4byte  sym_060612AC
.L_pool_06003560:
    .4byte  0x25E4108C
.L_pool_06003564:
    .4byte  0x25E41A24
.L_06003568:
    .4byte  0x25F00940
.L_0600356C:
    .4byte  0x25E4EFEC
.L_06003570:
    .4byte  0x25E42300
.L_06003574:
    .4byte  0x25E42C78

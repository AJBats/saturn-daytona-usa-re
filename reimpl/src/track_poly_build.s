
    .section .text.FUN_0602F550


    .global track_poly_build
    .type track_poly_build, @function
track_poly_build:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r11
    exts.w r11, r11
    mov.l @r15+, r0
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r1
    mov.l @(40, r0), r12
    sub r12, r11
    mov.l   .L_pool_0602F580, r10
    tst r10, r11
    bt      .L_0602F588
    mov.l   .L_pool_0602F584, r10
    bra     .L_0602F58C
    or r10, r11
    .2byte  0x0000
    .4byte  0x001E0000
    .4byte  atan2
.L_pool_0602F580:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) / bit 15 mask */
.L_pool_0602F584:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) / sign extend */
.L_0602F588:
    mov.l   .L_pool_0602F5A0, r10
    and r10, r11
.L_0602F58C:
    cmp/pz r11
    bt      .L_0602F592
    neg r11, r11
.L_0602F592:
    mov.l   .L_pool_0602F5A4, r10
    cmp/ge r10, r11
    bt      .L_0602F5A8
    mov #0x14, r12
    bra     .L_0602F5B0
    mov.w r12, @(r0, r1)
    .2byte  0x0000
.L_pool_0602F5A0:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_pool_0602F5A4:
    .4byte  0x0000071C                  /* angle threshold ~10 degrees (16-bit angle) */
.L_0602F5A8:
    mov.w   DAT_0602f5b4, r11
    add r11, r6
    dt r5
    .byte   0x8B, 0x99    /* bf 0x0602F4E4 (external) */
.L_0602F5B0:
    rts
    nop

    .global DAT_0602f5b4
DAT_0602f5b4:
    .2byte  0x0268

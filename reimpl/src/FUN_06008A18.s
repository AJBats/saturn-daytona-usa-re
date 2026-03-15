
    .section .text.FUN_06008A18


    .global FUN_06008A18
    .type FUN_06008A18, @function
FUN_06008A18:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_06008AC4, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov.l   .L_06008AC8, r3
    jsr @r3
    nop
    mov.l   .L_06008ACC, r4
    mov.l @r14, r2
    cmp/pz r2
    bf      .L_06008A40
    mov.l   .L_06008AD0, r2
    mov.w @r2, r3
    mov.w   .L_06008AC0, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_06008A72
.L_06008A40:
    mov.l @r14, r3
    cmp/pz r3
    bf      .L_06008A50
    mov.l   .L_06008AD4, r3
    jsr @r3
    nop
    bra     .L_06008A60
    nop
.L_06008A50:
    mov.l @r4, r2
    mov #0x3, r3
    add #0x1, r2
    mov.l r2, @r4
    cmp/hs r3, r2
    bf      .L_06008A60
    mov #0x0, r3
    mov.l r3, @r4
.L_06008A60:
    mov #0x4, r2
    mov.l   .L_06008AD8, r3
    mov.l r2, @r3
    mov #0x3, r2
    mov.l   .L_06008ADC, r3
    mov.w r2, @r3
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06008A72:
    mov.l @r4, r0
    cmp/eq #0x2, r0
    bf      .L_06008A7E
    mov.l   .L_06008AE0, r3
    jsr @r3
    nop
.L_06008A7E:
    mov.l   .L_06008AE4, r3
    jsr @r3
    nop
    mov.l   .L_06008AE8, r3
    jsr @r3
    nop
    mov.l   .L_06008AEC, r3
    jsr @r3
    nop
    mov.l   .L_06008AF0, r3
    jsr @r3
    nop
    mov #0x15, r5
    mov.l   .L_06008AF4, r3
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_06008AF8, r3
    jsr @r3
    nop
    mov.l @r14, r2
    mov.w   .L_06008AC2, r3
    cmp/gt r3, r2
    bt      .L_06008AB2
    mov.l   .L_06008AFC, r3
    jsr @r3
    nop
.L_06008AB2:
    lds.l @r15+, pr
    mov.l   .L_06008B00, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0x4F26                              /* dead code: unreachable lds.l @r15+, pr */
    .4byte  0x000B6EF6                          /* dead code: unreachable rts + mov.l @r15+, r14 */
.L_06008AC0:
    .2byte  0x0800
.L_06008AC2:
    .2byte  0x0244
.L_06008AC4:
    .4byte  sym_0607EBCC
.L_06008AC8:
    .4byte  sym_0600A1F6
.L_06008ACC:
    .4byte  sym_0607EAD8
.L_06008AD0:
    .4byte  sym_06063D9A
.L_06008AD4:
    .4byte  FUN_06018E70
.L_06008AD8:
    .4byte  FUN_0605ACC4
.L_06008ADC:
    .4byte  sym_06087804
.L_06008AE0:
    .4byte  FUN_06033BC8
.L_06008AE4:
    .4byte  FUN_0601FD74
.L_06008AE8:
    .4byte  FUN_0600DE40
.L_06008AEC:
    .4byte  FUN_0600A914
.L_06008AF0:
    .4byte  FUN_060055BC
.L_06008AF4:
    .4byte  sym_0600338C
.L_06008AF8:
    .4byte  FUN_0600BFFC
.L_06008AFC:
    .4byte  sym_0601AEB6
.L_06008B00:
    .4byte  FUN_060078DC                    /* FUN_060078DC — finalize and commit frame */

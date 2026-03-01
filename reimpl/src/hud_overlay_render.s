
    .section .text.FUN_0601E2B4


    .global hud_overlay_render
    .type hud_overlay_render, @function
hud_overlay_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r12
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601E354, r9
    mov.l   .L_0601E358, r10
    mov.l   .L_0601E35C, r11
    mov.l   .L_0601E360, r13
    mov.l   .L_0601E364, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf/s    .L_0601E2F2
    mov #0x1, r14
    bra     .L_0601E2E6
    mov r12, r4
.L_0601E2DC:
    mov.l @r11, r2
    add r4, r2
    extu.b r12, r3
    mov.b r3, @r2
    add #0x1, r4
.L_0601E2E6:
    mov.b @r9, r0
    extu.b r0, r0
    shll2 r0
    mov.l @(r0, r10), r3
    cmp/hs r3, r4
    bf      .L_0601E2DC
.L_0601E2F2:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E2F2
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x1A, r3
    mov.l   .L_0601E368, r2
    mov.b r3, @r2
.L_0601E306:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E306
    mov.l   .L_0601E36C, r3
    mov.l   .L_0601E370, r6
    mov.l   .L_0601E374, r5
    mov.l   .L_0601E378, r4
    mov.l @r3, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xB0, 0x2C    /* bsr 0x0601E37C (external) */
    nop
.L_0601E324:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E324
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.l   .L_0601E368, r2
    mov.b r3, @r2
.L_0601E338:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E338
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0601E354:
    .4byte  sym_060877D8
.L_0601E358:
    .4byte  sym_0604A5C0
.L_0601E35C:
    .4byte  sym_0605E068
.L_0601E360:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_0601E364:
    .4byte  sym_06087080
.L_0601E368:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_0601E36C:
    .4byte  sym_06000358
.L_0601E370:
    .4byte  sym_06087086
.L_0601E374:
    .4byte  sym_0605E064
.L_0601E378:
    .4byte  sym_0605E060

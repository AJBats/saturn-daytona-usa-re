
    .section .text.FUN_06042418


    .global fixpt_div_helper
    .type fixpt_div_helper, @function
fixpt_div_helper:
    mov.l r14, @-r15
    sts.l pr, @-r15
    cmp/pz r4
    bt/s    .L_06042426
    mov #0x0, r14
    mov #0x1, r14
    neg r4, r4
.L_06042426:
    mov.l   .L_0604244C, r2
    cmp/ge r2, r4
    bf      .L_06042430
    bra     .L_0604243A
    mov #0x0, r4
.L_06042430:
    mov.l   .L_06042450, r3
    cmp/gt r3, r4
    bf      .L_0604243A
    sub r4, r2
    mov r2, r4
.L_0604243A:
    mov.l   .L_06042454, r3
    jsr @r3
    nop
    tst r14, r14
    bt      .L_06042446
    neg r0, r0
.L_06042446:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0604244C:
    .4byte  0x00B40000          /* 180.0 in 16.16 fixed-point (180 << 16) */
.L_06042450:
    .4byte  0x005A0000          /* 90.0 in 16.16 fixed-point (90 << 16) */
.L_06042454:
    .4byte  sym_060424A2        /* core sine table lookup function */

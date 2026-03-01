
    .section .text.FUN_06042418


    .global fixpt_div_helper
    .type fixpt_div_helper, @function
fixpt_div_helper:
    mov.l r14, @-r15
    sts.l pr, @-r15
    cmp/pz r4
    bt/s    .L_sign_done
    mov #0x0, r14
    mov #0x1, r14
    neg r4, r4
.L_sign_done:
    mov.l   .L_fp_180, r2
    cmp/ge r2, r4
    bf      .L_range_ok
    bra     .L_call_sine
    mov #0x0, r4
.L_range_ok:
    mov.l   .L_fp_90, r3
    cmp/gt r3, r4
    bf      .L_call_sine
    sub r4, r2
    mov r2, r4
.L_call_sine:
    mov.l   .L_fn_sine_core, r3
    jsr @r3
    nop
    tst r14, r14
    bt      .L_return
    neg r0, r0
.L_return:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_fp_180:
    .4byte  0x00B40000          /* 180.0 in 16.16 fixed-point (180 << 16) */
.L_fp_90:
    .4byte  0x005A0000          /* 90.0 in 16.16 fixed-point (90 << 16) */
.L_fn_sine_core:
    .4byte  sym_060424A2        /* core sine table lookup function */

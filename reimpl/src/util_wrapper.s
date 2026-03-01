
    .section .text.FUN_06014A42


    .global util_wrapper
    .type util_wrapper, @function
util_wrapper:
    sts.l pr, @-r15
    .byte   0xB2, 0x76    /* bsr 0x06014F34 (external) */
    nop
    .byte   0xD3, 0x09    /* mov.l .L_pool_fn_vdp2_util_loop, r3 */
    jmp @r3
    lds.l @r15+, pr
    .2byte  0x0260
    .4byte  0x25C00000
    .4byte  sym_06044B64
    .4byte  sym_06059FFC
    .4byte  memcpy_word_idx
    .4byte  vdp2_loop_ctrl
    .4byte  sym_0607EBF4
    .4byte  sym_06085F90
    .4byte  sym_06085F94
.L_pool_fn_vdp2_util_loop:
    .4byte  vdp2_util_loop                /* [HIGH] tail-call target (per hud_ui.s annotation) */

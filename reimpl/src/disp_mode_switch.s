
    .section .text.FUN_06033020


    .global disp_mode_switch
    .type disp_mode_switch, @function
disp_mode_switch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l   .L_pool_disp_flags, r0
    mov.b @r0, r1
    mov.l   .L_pool_scroll_enable_mask, r0
    tst r0, r1
    bt      .L_scroll_disabled
    mov.l   .L_pool_scroll_target, r5
    bra     .L_interpolate
    nop
    .2byte  0x0000
.L_pool_disp_flags:
    .4byte  sym_06082A25
.L_pool_scroll_enable_mask:
    .4byte  0x00000001
.L_pool_scroll_target:
    .4byte  0x00003333
.L_scroll_disabled:
    xor r5, r5
.L_interpolate:
    mov.l   .L_pool_scroll_pos, r0
    mov.l @r0, r1
    sub r1, r5
    shar r5
    add r5, r1
    mov.l r1, @r0
    mov.l @r4, r2
    add r1, r2
    mov.l r2, @r4
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
    .2byte  0x0000
.L_pool_scroll_pos:
    .4byte  sym_06082A28
    .4byte  0x000B0009
    .4byte  0xD0076002
    .4byte  0x60024015
    .2byte  0x8907

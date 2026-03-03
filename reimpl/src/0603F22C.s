
    .section .text.FUN_0603F22C


    .global hud_toggle_ctrl
    .type hud_toggle_ctrl, @function
hud_toggle_ctrl:
    mov.l   .L_0603F234, r4
    .byte   0xA0, 0x03    /* bra 0x0603F238 (external) */
    nop
    .2byte  0xFFFF
.L_0603F234:
    .4byte  0x00FFFFFF

	.text
    .global hud_toggle_ctrl
hud_toggle_ctrl:
    mov.l   .L_0603F234, r4
    .byte   0xA0, 0x03    /* bra 0x0603F238 (external) */
    nop
    .short  0xFFFF
.L_0603F234:
    .long  0x00FFFFFF

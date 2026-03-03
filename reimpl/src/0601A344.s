	.text
    .global hud_nop_stub_d
hud_nop_stub_d:
    mov.l r14, @-r15
    mov #0x60, r6

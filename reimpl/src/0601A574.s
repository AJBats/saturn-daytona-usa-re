	.text
    .global hud_nop_stub_e
hud_nop_stub_e:
    mov.l r14, @-r15
    mov #0x0, r14

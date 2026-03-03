	.text
    .global hud_nop_stub_c
hud_nop_stub_c:
    mov.l r14, @-r15
    mov #0x40, r0

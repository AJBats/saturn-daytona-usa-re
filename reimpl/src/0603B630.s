	.text
    .global nop_stub_menu
nop_stub_menu:
    mov.l r14, @-r15
    mov #0x1D, r1

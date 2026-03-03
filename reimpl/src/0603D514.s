	.text
    .global display_nop_stub_b
display_nop_stub_b:
    mov.l r14, @-r15
    mov #0x1, r6

	.text
    .global display_nop_stub_a
display_nop_stub_a:
    mov.l r14, @-r15
    mov #0x1, r6

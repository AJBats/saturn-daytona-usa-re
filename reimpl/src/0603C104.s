	.text
    .global display_init_chain
display_init_chain:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x8, r13

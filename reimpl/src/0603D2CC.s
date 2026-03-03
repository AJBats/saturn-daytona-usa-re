	.text
    .global render_credits_stub
render_credits_stub:
    mov.l r14, @-r15
    mov #0x1, r6

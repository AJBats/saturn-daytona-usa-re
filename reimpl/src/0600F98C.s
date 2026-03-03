	.text
    .global transition_stub
transition_stub:
    mov.l r14, @-r15
    mov #0x0, r6

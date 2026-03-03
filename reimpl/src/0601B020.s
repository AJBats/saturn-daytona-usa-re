	.text
    .global disc_ready_stub
disc_ready_stub:
    mov.l r14, @-r15
    mov #0x0, r7

	.text
    .global replay_end_stub
replay_end_stub:
    mov.l r14, @-r15
    mov #0x0, r7
    mov #0x30, r6

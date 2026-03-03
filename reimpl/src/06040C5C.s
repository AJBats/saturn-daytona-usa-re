	.text
    .global nop_stub_evt
nop_stub_evt:
    mov.l r14, @-r15
    mov r6, r14

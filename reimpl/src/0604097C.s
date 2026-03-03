	.text
    .global nop_stub_sys
nop_stub_sys:
    mov.l r14, @-r15
    mov r4, r14

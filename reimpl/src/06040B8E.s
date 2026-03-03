	.text
    .global reg_push_fragment
reg_push_fragment:
    mov.l r14, @-r15

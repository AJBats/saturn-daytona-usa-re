	.text
    .global track_post_nop_stub
track_post_nop_stub:
    mov.l r14, @-r15
    mov r4, r14

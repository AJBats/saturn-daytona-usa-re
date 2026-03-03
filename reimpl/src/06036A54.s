	.text
    .global track_shadow_stub
track_shadow_stub:
    mov.l r14, @-r15
    mov r5, r14
    mov.l r13, @-r15
    mov r4, r13

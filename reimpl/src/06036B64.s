	.text
    .global track_effect_stub
track_effect_stub:
    mov.l r14, @-r15
    mov r6, r14
    mov.l r13, @-r15
    mov r4, r13
    mov.l r12, @-r15
    mov r5, r12

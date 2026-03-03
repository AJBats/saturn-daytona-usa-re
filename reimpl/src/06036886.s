	.text
    .global track_impact_adjust_stub
track_impact_adjust_stub:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r5, r14
    mov.l r12, @-r15
    mov r6, r13

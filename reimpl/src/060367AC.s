	.text
    .global track_impact_stub
track_impact_stub:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov r5, r13

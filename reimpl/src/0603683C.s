	.text
    .global track_impact_response
track_impact_response:
    mov.l r14, @-r15
    mov r5, r14
    mov.l r13, @-r15
    mov r6, r13
    mov.l r12, @-r15
    mov r4, r12

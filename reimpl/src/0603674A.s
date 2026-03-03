	.text
    .global track_collision_stub
track_collision_stub:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r6, r14
    mov.l r12, @-r15
    mov r5, r13

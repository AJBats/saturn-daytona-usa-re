	.text
    .global track_seg_stub
track_seg_stub:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r6, r14
    mov.l r12, @-r15
    mov r5, r13

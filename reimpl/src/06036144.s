	.text
    .global track_seg_boundary
track_seg_boundary:
    mov.l r14, @-r15
    mov r4, r14

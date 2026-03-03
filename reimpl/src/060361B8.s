	.text
    .global track_seg_nop_stub
track_seg_nop_stub:
    mov.l r14, @-r15
    mov r4, r14

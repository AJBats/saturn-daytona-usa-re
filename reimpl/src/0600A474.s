	.text
    .global camera_push_save
camera_push_save:
    mov.l r14, @-r15
    mov r4, r14

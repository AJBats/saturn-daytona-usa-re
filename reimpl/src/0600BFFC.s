	.text
    .global scene_master
scene_master:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x1, r11
    mov.l r9, @-r15
    mov r11, r14
    mov.l r8, @-r15
    add #0x7F, r14

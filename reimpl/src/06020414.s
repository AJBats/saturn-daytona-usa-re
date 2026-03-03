	.text
    .global obj_destroy
obj_destroy:
    mov.l r14, @-r15
    extu.w r6, r6
    mov.l r13, @-r15
    mov #0x0, r14
    shll2 r6
    mov.l r12, @-r15
    extu.b r14, r13
    shll2 r6
    mov.l r11, @-r15
    shll2 r6
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov r5, r8

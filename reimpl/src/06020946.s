	.text
    .global obj_lod_level
obj_lod_level:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x1C, r11

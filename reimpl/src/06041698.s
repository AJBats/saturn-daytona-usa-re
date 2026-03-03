	.text
    .global large_prologue_save
large_prologue_save:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r11
    mov.l r9, @-r15
    mov #0x1E, r10

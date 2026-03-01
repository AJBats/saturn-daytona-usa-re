
    .section .text.FUN_0601FFA8


    .global vram_ptr_get
    .type vram_ptr_get, @function
vram_ptr_get:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov #0x1, r9

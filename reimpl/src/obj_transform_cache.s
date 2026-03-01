
    .section .text.FUN_06004F14


    .global obj_transform_cache
    .type obj_transform_cache, @function
obj_transform_cache:
    mov.l r14, @-r15
    mov #0x4, r3
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov r5, r9
    mov.l r8, @-r15
    and r9, r3

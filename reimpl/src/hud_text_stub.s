
    .section .text.FUN_06016940


    .global hud_text_stub
    .type hud_text_stub, @function
hud_text_stub:
    mov.l r14, @-r15
    mov #0x7, r2
    mov.l r13, @-r15
    mov r4, r14
    mov.l r12, @-r15
    extu.b r14, r3
    mov.l r11, @-r15
    mov #0x0, r11

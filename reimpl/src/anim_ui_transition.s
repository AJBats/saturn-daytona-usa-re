
    .section .text.FUN_060114AC


    .global anim_ui_transition
    .type anim_ui_transition, @function
anim_ui_transition:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov r4, r13
    mov.l r11, @-r15
    extu.w r13, r0


    .section .text.FUN_06012080


    .global sound_init_bonus
    .type sound_init_bonus, @function
sound_init_bonus:
    mov.l r14, @-r15
    mov #0x7, r5

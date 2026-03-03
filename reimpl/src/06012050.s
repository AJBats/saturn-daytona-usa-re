
    .section .text.FUN_06012050


    .global sound_init_race
    .type sound_init_race, @function
sound_init_race:
    mov.l r14, @-r15
    mov #0x7, r5

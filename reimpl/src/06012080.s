	.text
    .global sound_init_bonus
sound_init_bonus:
    mov.l r14, @-r15
    mov #0x7, r5

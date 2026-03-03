	.text
    .global sound_init_race
sound_init_race:
    mov.l r14, @-r15
    mov #0x7, r5

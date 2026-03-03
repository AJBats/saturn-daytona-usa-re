	.text
    .global race_start_init
race_start_init:
    mov.l r14, @-r15
    mov #0x1, r3

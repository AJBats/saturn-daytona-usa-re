	.text
    .global attract_timer_init
attract_timer_init:
    mov.l r14, @-r15
    mov #0x1, r6

	.text
    .global attract_timer_tick
attract_timer_tick:
    mov.l r14, @-r15
    mov #0x35, r0

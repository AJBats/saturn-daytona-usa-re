	.text
    .global attract_timer_tick
attract_timer_tick:
    .byte 0x2F, 0xE6
    .byte 0xE0, 0x35

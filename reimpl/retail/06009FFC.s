	.text
    .global state_timeext_setup
state_timeext_setup:
    .byte 0x2F, 0xE6
    .byte 0xE5, 0x00

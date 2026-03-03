	.text
    .global transition_stub
transition_stub:
    .byte 0x2F, 0xE6
    .byte 0xE6, 0x00

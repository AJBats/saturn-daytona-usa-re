	.text
    .global display_nop_stub_b
display_nop_stub_b:
    .byte 0x2F, 0xE6
    .byte 0xE6, 0x01

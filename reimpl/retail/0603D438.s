	.text
    .global display_nop_stub_a
display_nop_stub_a:
    .byte 0x2F, 0xE6
    .byte 0xE6, 0x01

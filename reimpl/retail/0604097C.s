	.text
    .global nop_stub_sys
nop_stub_sys:
    .byte 0x2F, 0xE6
    .byte 0x6E, 0x43

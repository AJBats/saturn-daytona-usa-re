	.text
    .global disc_ready_stub
disc_ready_stub:
    .byte 0x2F, 0xE6
    .byte 0xE7, 0x00

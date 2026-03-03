	.text
    .global error_code_stub
error_code_stub:
    .byte 0x2F, 0xE6
    .byte 0xE2, 0xFE

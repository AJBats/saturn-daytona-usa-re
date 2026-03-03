	.text
    .global evt_error_code_return
evt_error_code_return:
    .byte 0x2F, 0xE6
    .byte 0xE6, 0x00

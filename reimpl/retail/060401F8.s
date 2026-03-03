    .section .text.FUN_060401F8
    .global evt_error_code_return
    .type evt_error_code_return, @function
evt_error_code_return:
    .byte 0x2F, 0xE6
    .byte 0xE6, 0x00

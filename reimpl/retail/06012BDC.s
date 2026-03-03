    .section .text.FUN_06012BDC
    .global cd_error_recover
    .type cd_error_recover, @function
cd_error_recover:
    .byte 0x2F, 0xE6
    .byte 0x2F, 0xD6
    .byte 0x2F, 0xC6
    .byte 0xED, 0x0F

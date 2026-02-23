    .section .text.FUN_06040F16
    .global evt_reg_save
    .type evt_reg_save, @function
evt_reg_save:
    .byte 0x2F, 0xE6
    .byte 0x2F, 0xD6
    .byte 0x6E, 0x43

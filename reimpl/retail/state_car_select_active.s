    .section .text.FUN_06008B9C
    .global state_car_select_active
    .type state_car_select_active, @function
state_car_select_active:
    .byte 0x4F, 0x22
    .byte 0xD3, 0x0C
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xD3, 0x0B
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xD3, 0x06
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xE2, 0x00
    .byte 0xD3, 0x05
    .byte 0x4F, 0x26
    .byte 0x00, 0x0B
    .byte 0x23, 0x22
    .byte 0xFF, 0xFF
    .4byte g_game_state
    .4byte car_select_setup
    .4byte sym_06026CE0
    .4byte sym_06059F44
    .4byte sym_0605A016
    .4byte FUN_06019A48
    .4byte FUN_06019928

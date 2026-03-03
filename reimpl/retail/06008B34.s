    .section .text.FUN_06008B34
    .global state_course_select_active
    .type state_course_select_active, @function
state_course_select_active:
    .byte 0x4F, 0x22
    .byte 0xD3, 0x0E
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xD3, 0x0D
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xD3, 0x08
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xE2, 0x00
    .byte 0xD3, 0x07
    .byte 0x4F, 0x26
    .byte 0x00, 0x0B
    .byte 0x23, 0x22
    .byte 0xFF, 0xFF
    .4byte handler_init_reset
    .4byte g_game_state
    .4byte track_poly_start
    .4byte obj_render_update
    .4byte sym_06026CE0
    .4byte sym_06059F44
    .4byte sym_0605A016
    .4byte course_select_input
    .4byte course_select_draw

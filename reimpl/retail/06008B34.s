	.text
    .global state_course_select_active
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
    .long handler_init_reset
    .long g_game_state
    .long track_poly_start
    .long obj_render_update
    .long sym_06026CE0
    .long sym_06059F44
    .long sym_0605A016
    .long course_select_input
    .long course_select_draw

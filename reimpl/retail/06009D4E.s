	.text
    .global state_post_race_display
state_post_race_display:
    .byte 0x4F, 0x22
    .byte 0xD3, 0x16
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xD2, 0x16
    .byte 0x62, 0x20
    .byte 0x22, 0x28
    .byte 0x8B, 0x0B
    .byte 0xD3, 0x15
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xD6, 0x14
    .byte 0xD5, 0x15
    .byte 0xD4, 0x15
    .byte 0xD3, 0x16
    .byte 0x43, 0x0B
    .byte 0x66, 0x62
    .byte 0xD3, 0x15
    .byte 0x43, 0x0B
    .byte 0x00, 0x09
    .byte 0xD3, 0x15
    .byte 0x43, 0x2B
    .byte 0x4F, 0x26
    .long sym_0605A016
    .long display_mode_init
    .long race_state_pair_2
    .long g_game_state
    .long sym_06078654
    .long gameover_channel_setup
    .long obj_render_update
    .long sym_0607E944
    .long sym_0605B6D8
    .byte 0x40, 0x00
    .byte 0x00, 0x00
    .long sym_06026CE0
    .long sym_06059F44
    .long ai_waypoint_pathfind
    .long sym_06085F8A
    .long camera_system
    .long sym_06063E24
    .long sym_06063EEC
    .long sym_06063EF8
    .long camera_orient_calc
    .long scene_master
    .long frame_end_commit

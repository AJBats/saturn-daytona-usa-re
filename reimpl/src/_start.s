    .section .text.startup
    .global _start
_start:
    .global sym_06003000
sym_06003000:
    .byte 0xD1, 0x17
    .byte 0xE0, 0x00
    .byte 0xDF, 0x18
    .byte 0x41, 0x0B
    .byte 0x40, 0x0E
    .byte 0xD0, 0x16
    .byte 0x40, 0x0B
    .byte 0x00, 0x09
    .byte 0xC7, 0x1A
    .byte 0xD1, 0x18
    .byte 0xD2, 0x15
    .byte 0x61, 0x12
    .byte 0xD3, 0x15
    .byte 0x22, 0x12
    .byte 0x66, 0x13
    .byte 0xE4, 0x01
    .byte 0xE5, 0x10
    .byte 0x35, 0x67
    .byte 0x8D, 0x02
    .byte 0xE5, 0x08
    .byte 0x44, 0x28
    .byte 0x76, 0xF0
    .byte 0x35, 0x67
    .byte 0x8D, 0x02
    .byte 0xE5, 0x06
    .byte 0x44, 0x18
    .byte 0x76, 0xF8
    .byte 0x35, 0x67
    .byte 0x89, 0x03
    .byte 0x44, 0x08
    .byte 0x44, 0x08
    .byte 0x44, 0x08
    .byte 0x76, 0xFA
    .byte 0x26, 0x68
    .byte 0x89, 0x02
    .byte 0x46, 0x10
    .byte 0x8F, 0xFD
    .byte 0x44, 0x00
    .byte 0xD2, 0x0A
    .byte 0x23, 0x42
    .byte 0x65, 0x22
    .byte 0x41, 0x08
    .byte 0x00, 0x1E
    .byte 0x75, 0x01
    .byte 0x40, 0x0B
    .byte 0x22, 0x52
    .byte 0xAF, 0xD5
    .byte 0x00, 0x09
    .4byte system_init
    .4byte per_frame_update
    .4byte sym_06003000
    .4byte sym_0607EBC0
    .4byte sym_0607EBC4
    .4byte g_game_state
    .4byte sym_0607EBC8
    .4byte state_boot_init
    .4byte loc_0600890A
    .4byte state_attract_setup
    .4byte state_attract_active
    .4byte state_mode_select_entry
    .4byte state_mode_select_active
    .4byte state_course_select_init
    .4byte state_course_select_active
    .4byte state_car_select_init
    .4byte FUN_06008B9C
    .4byte state_loading_init
    .4byte state_loading_check
    .4byte state_race_prepare
    .4byte state_pre_race
    .4byte state_race_setup
    .4byte state_race_main
    .4byte state_post_countdown
    .4byte state_post_lap
    .4byte state_time_extend_setup
    .4byte state_time_extend_active
    .4byte state_race_complete
    .4byte state_post_race_cleanup
    .4byte state_attract_return
    .4byte state_demo_setup
    .4byte state_post_race_init
    .4byte state_post_race_display
    .4byte state_postrace_wait_init
    .4byte state_postrace_countdown
    .4byte state_abort
    .4byte state_results_screen
    .4byte state_resource_load
    .4byte state_memory_route

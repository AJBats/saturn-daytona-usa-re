    	.text
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
    .long system_init
    .long FUN_0600A392
    .long sym_06003000
    .long sym_0607EBC0
    .long sym_0607EBC4
    .long g_game_state
    .long sym_0607EBC8
    .long state_boot_init
    .long loc_0600890A
    .long state_attract_setup
    .long state_attract_active
    .long state_mode_select_entry
    .long state_mode_select_active
    .long state_course_select_init
    .long state_course_select_active
    .long state_car_select_init
    .long FUN_06008B9C
    .long state_loading_init
    .long state_loading_check
    .long state_race_prepare
    .long state_pre_race
    .long state_race_setup
    .long state_race_main
    .long state_post_countdown
    .long state_post_lap
    .long state_time_extend_setup
    .long state_time_extend_active
    .long state_race_complete
    .long state_post_race_cleanup
    .long state_attract_return
    .long state_demo_setup
    .long state_post_race_init
    .long state_post_race_display
    .long state_postrace_wait_init
    .long state_postrace_countdown
    .long state_abort
    .long state_results_screen
    .long state_resource_load
    .long state_memory_route

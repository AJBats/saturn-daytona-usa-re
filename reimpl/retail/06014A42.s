	.text
    .global util_wrapper
util_wrapper:
    .byte 0x4F, 0x22
    .byte 0xB2, 0x76
    .byte 0x00, 0x09
    .byte 0xD3, 0x09
    .byte 0x43, 0x2B
    .byte 0x4F, 0x26
    .byte 0x02, 0x60
    .byte 0x25, 0xC0
    .byte 0x00, 0x00
    .long sym_06044B64
    .long sym_06059FFC
    .long memcpy_word_idx
    .long vdp2_loop_ctrl
    .long sym_0607EBF4
    .long sym_06085F90
    .long sym_06085F94
    .long vdp2_util_loop

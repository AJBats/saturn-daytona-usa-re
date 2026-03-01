
    .section .text.FUN_0603242A


    .global display_cmd_position
    .type display_cmd_position, @function
display_cmd_position:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0x6A    /* bra 0x0603230A (external) */
    nop
    .2byte  0x0000
    .4byte  sound_cmd_dispatch

    .global loc_0603243C
loc_0603243C:
    .byte   0xD2, 0x04    /* mov.l _pool_scroll_enable_bit, r2 */
    .byte   0xD0, 0x05    /* mov.l _pool_disp_flags_a, r0 */
    mov.b @r0, r1
    or r2, r1
    mov.b r1, @r0
    xor r1, r1
    .byte   0xD0, 0x03    /* mov.l _pool_scroll_pos, r0 */
    .byte   0xAF, 0x5E    /* bra 0x0603230A (external) */
    mov.l r1, @r0
    .2byte  0x0000
_pool_scroll_enable_bit:
    .4byte  0x00000001
_pool_disp_flags_a:
    .4byte  sym_06082A25
_pool_scroll_pos:
    .4byte  sym_06082A28

    .global loc_0603245C
loc_0603245C:
    .byte   0xD2, 0x03    /* mov.l _pool_scroll_clear_bit, r2 */
    .byte   0xD0, 0x04    /* mov.l _pool_disp_flags_b, r0 */
    not r2, r2
    mov.b @r0, r1
    and r2, r1
    .byte   0xAF, 0x50    /* bra 0x0603230A (external) */
    mov.b r1, @r0
    .2byte  0x0000
_pool_scroll_clear_bit:
    .4byte  0x00000001
_pool_disp_flags_b:
    .4byte  sym_06082A25

    .global loc_06032474
loc_06032474:
    .byte   0xD2, 0x03    /* mov.l _pool_poslock_clear_bit, r2 */
    .byte   0xD0, 0x04    /* mov.l _pool_disp_flags_c, r0 */
    not r2, r2
    mov.b @r0, r1
    and r2, r1
    .byte   0xAF, 0x44    /* bra 0x0603230A (external) */
    mov.b r1, @r0
    .2byte  0x0000
_pool_poslock_clear_bit:
    .4byte  0x00000002
_pool_disp_flags_c:
    .4byte  sym_06082A25

    .global loc_0603248C
loc_0603248C:
    .byte   0xD2, 0x02    /* mov.l _pool_poslock_set_bit, r2 */
    .byte   0xD0, 0x03    /* mov.l _pool_disp_flags_d, r0 */
    mov.b @r0, r1
    or r2, r1
    .byte   0xAF, 0x39    /* bra 0x0603230A (external) */
    mov.b r1, @r0
_pool_poslock_set_bit:
    .4byte  0x00000002
_pool_disp_flags_d:
    .4byte  sym_06082A25

    .global loc_060324A0
loc_060324A0:
    .byte   0xD0, 0x07    /* mov.l _pool_car_base_ptr, r0 */
    mov.l @r0, r0
    mov.l @r0, r1
    .byte   0xD2, 0x07    /* mov.l _pool_car_flag_mask, r2 */
    and r2, r1
    mov.l r1, @r0
    .byte   0xD0, 0x06    /* mov.l _pool_cmd_state_byte, r0 */
    xor r1, r1
    mov.b r1, @r0
    .byte   0xD0, 0x06    /* mov.l _pool_disp_flags_e, r0 */
    mov.b @r0, r1
    .byte   0xD2, 0x06    /* mov.l _pool_reset_flag_bit, r2 */
    or r2, r1
    .byte   0xAF, 0x26    /* bra 0x0603230A (external) */
    mov.b r1, @r0
    .2byte  0x0000
_pool_car_base_ptr:
    .4byte  sym_0607E944
_pool_car_flag_mask:
    .4byte  0xFFFEFFFF
_pool_cmd_state_byte:
    .4byte  sym_06082A24
_pool_disp_flags_e:
    .4byte  sym_06082A25
_pool_reset_flag_bit:
    .4byte  0x00000004
    .4byte  0xD00401EC
    .4byte  0x21188919
    .4byte  0xE0042108
    .4byte  0x8B04A021
    .4byte  0x00090000
    .4byte  0x000002DC

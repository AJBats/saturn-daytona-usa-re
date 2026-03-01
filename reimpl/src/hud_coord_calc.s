
    .section .text.FUN_06010994


    .global hud_coord_calc
    .type hud_coord_calc, @function
hud_coord_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   _pool_game_state_idx_ptr, r12
    mov.l   _pool_vdp1_cmd_buf_ptr, r13
    mov.l   _pool_memcpy_word_idx, r14
    mov.l   _pool_split_screen_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_single_player_path
    mov #0x20, r6
    mov.l   _pool_disp_elem_data_ptr, r5
    mov.l   _pool_cmd_table_base, r3
    mov.l   _pool_car_index_ptr, r4
    mov.l   _pool_color_table_byte, r2
    mov.l   _pool_buf_offset_word, r1
    mov.l @r12, r0
    mov.l @r5, r5
    mov.l @r4, r4
    mov.w @r1, r1
    shll2 r0
    shll2 r5
    add r2, r4
    extu.w r1, r1
    add r3, r5
    mov.b @r4, r4
    mov.l @r5, r5
    extu.b r4, r4
    add r1, r4
    shll2 r4
    shll2 r4
    shll r4
    shll r0
    add r0, r4
    mov.l @r13, r1
    bra     .L_do_first_copy
    add r1, r4
.L_single_player_path:
    mov.w   DAT_06010a2a, r6

    .global loc_060109E2
loc_060109E2:
    mov.l   _pool_disp_data_base_ptr, r5
    mov.l   _pool_func_table_base, r3
    mov.l @r12, r4
    mov.l @r5, r5
    shll2 r4
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll r4
    mov.l @r13, r2
    add r2, r4
    add #0x40, r4
.L_do_first_copy:
    jsr @r14
    nop
    mov.w   DAT_06010a2a, r6
    mov.l   _pool_elem_type_byte, r5
    mov.l   _pool_func_table_base, r3
    mov.l @r12, r4
    mov.l @r13, r2
    mov r6, r1
    mov.b @r5, r5
    shll2 r4
    add #0x40, r1
    extu.b r5, r5
    shll r4
    shll2 r5
    add r2, r4
    add r3, r5
    mov.l @r5, r5
    jsr @r14
    add r1, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06010a2a
DAT_06010a2a:
    .2byte  0x00C0
_pool_game_state_idx_ptr:
    .4byte  sym_06059FFC
_pool_vdp1_cmd_buf_ptr:
    .4byte  sym_06063F5C
_pool_memcpy_word_idx:
    .4byte  memcpy_word_idx
_pool_split_screen_flag:
    .4byte  sym_06083255
_pool_disp_elem_data_ptr:
    .4byte  sym_0607EAB8
_pool_cmd_table_base:
    .4byte  sym_0605D0AC
_pool_car_index_ptr:
    .4byte  sym_0607EAD8
_pool_color_table_byte:
    .4byte  sym_060448B5
_pool_buf_offset_word:
    .4byte  sym_0607886C
_pool_disp_data_base_ptr:
    .4byte  sym_06078868
_pool_func_table_base:
    .4byte  sym_0605D05C
_pool_elem_type_byte:
    .4byte  sym_0607ED91

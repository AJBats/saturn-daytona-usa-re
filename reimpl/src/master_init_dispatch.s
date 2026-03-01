
    .section .text.FUN_06003A3C


    .global master_init_dispatch
    .type master_init_dispatch, @function
master_init_dispatch:
    sts.l pr, @-r15
    mov #0x0, r3
    mov.l   .L_game_state_flag, r2
    mov.l r3, @r2
    mov.l   .L_heap_base_addr, r3
    mov.l   .L_heap_base_ptr, r2
    mov.l r3, @r2
    mov #0x0, r3
    mov.l   .L_init_mode_flag, r2
    mov.l r3, @r2
    mov.w   .L_const_0080, r3
    mov.l   .L_dispatch_flags, r2
    mov.l r3, @r2
    mov #0x1, r3
    mov.l   .L_init_counter, r2
    mov.l r3, @r2
    mov.w   DAT_06003ade, r7
    mov.l   .L_handler_slot_96, r6
    mov.l   .L_handler_table_a, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0x8, r5
    mov.w   .L_slot_id_a2, r7
    mov.l   .L_handler_slot_a2, r6
    mov.l   .L_handler_table_a, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0x8, r5
    mov #0x3F, r7
    mov.l   .L_handler_slot_3f, r6
    mov.l   .L_handler_table_b, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0x4, r5
    mov #0x61, r7
    mov.l   .L_handler_slot_61, r6
    mov.l   .L_handler_table_a, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0x8, r5
    mov #0x45, r7
    mov.l   .L_handler_slot_45, r6
    mov.l   .L_handler_table_c, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0xC, r5
    mov #0xB, r7
    mov.l   .L_handler_slot_0b, r6
    mov.l   .L_handler_table_d, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0x4, r5
    mov #0x0, r7
    mov.l   .L_handler_table_e, r4
    mov.l   .L_fn_register_handler, r3
    mov r7, r6
    jsr @r3
    mov #0x4, r5
    mov #0x34, r7
    mov.l   .L_handler_slot_34, r6
    mov.l   .L_handler_table_f, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0xC, r5
    mov.w   .L_slot_id_c9, r7
    mov.l   .L_handler_slot_c9, r6
    mov.l   .L_handler_table_g, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0x9, r5
    mov.w   .L_slot_id_2ea, r7
    mov.l   .L_handler_slot_2ea, r6
    mov.l   .L_handler_table_h, r4
    mov.l   .L_fn_register_handler, r3
    jsr @r3
    mov #0x9, r5
    mov #0x0, r7
    mov r7, r6
    bra     .L_register_obj_handlers
    mov #0x8, r5
.L_const_0080:
    .2byte  0x0080

    .global DAT_06003ade
DAT_06003ade:
    .2byte  0x0096
.L_slot_id_a2:
    .2byte  0x00A2
.L_slot_id_c9:
    .2byte  0x00C9
.L_slot_id_2ea:
    .2byte  0x02EA
    .2byte  0xFFFF
.L_game_state_flag:
    .4byte  sym_06063D94
.L_heap_base_addr:
    .4byte  sym_060F0000
.L_heap_base_ptr:
    .4byte  sym_06063D90
.L_init_mode_flag:
    .4byte  sym_06059F10
.L_dispatch_flags:
    .4byte  sym_06059F18
.L_init_counter:
    .4byte  sym_06059F1C
.L_handler_slot_96:
    .4byte  0x002D0868
.L_handler_table_a:
    .4byte  sym_06059EC8
.L_fn_register_handler:
    .4byte  obj_transform_cache
.L_handler_slot_a2:
    .4byte  0x002D0108
.L_handler_slot_3f:
    .4byte  sym_060430CE
.L_handler_table_b:
    .4byte  0x002BE5F0
.L_handler_slot_61:
    .4byte  0x002D11A4
.L_handler_slot_45:
    .4byte  0x002A0000
.L_handler_table_c:
    .4byte  0x002A86F8
.L_handler_slot_0b:
    .4byte  0x002A7D64
.L_handler_table_d:
    .4byte  0x002AC382
.L_handler_table_e:
    .4byte  0x002AC390
.L_handler_slot_34:
    .4byte  0x002A3784
.L_handler_table_f:
    .4byte  0x002AA0B0
.L_handler_slot_c9:
    .4byte  0x002A6BCC
.L_handler_table_g:
    .4byte  sym_060EF650
.L_handler_slot_2ea:
    .4byte  0x002A3910
.L_handler_table_h:
    .4byte  sym_060EE300
.L_register_obj_handlers:
    mov.l   .L_obj_table_init_a, r4
    mov.l   .L_fn_register_handler_2, r3
    jsr @r3
    nop
    mov #0x0, r7
    mov.l   .L_obj_table_slot_0a, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0x8, r5
    mov #0x0, r7
    mov.l   .L_obj_table_slot_0b, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0x8, r5
    mov.w   .L_slot_id_1bb, r7
    mov.l   .L_handler_slot_1bb, r6
    mov.l   .L_obj_table_1bb, r4
    mov.l   .L_fn_register_handler_2, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_01, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_02, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_03, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_04, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_05, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_06, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_07, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_08, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_09, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_10, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x14, r7
    mov.l   .L_handler_slot_14, r6
    mov.l   .L_obj_table_slot_14, r4
    mov.l   .L_fn_register_handler_2, r3
    jsr @r3
    mov #0x4, r5
    mov #0x0, r7
    mov.l   .L_obj_table_null_11, r4
    mov.l   .L_fn_register_handler_2, r3
    mov r7, r6
    jsr @r3
    mov #0x4, r5
    mov.w   .L_slot_id_db, r7
    mov.l   .L_handler_slot_db, r6
    mov.l   .L_handler_table_a_2, r4
    mov.l   .L_fn_register_handler_2, r3
    jsr @r3
    mov #0x9, r5
    mov.w   DAT_06003c1a, r7
    bra     .L_register_scene_handlers
    nop
.L_slot_id_1bb:
    .2byte  0x01BB
.L_slot_id_db:
    .2byte  0x00DB

    .global DAT_06003c1a
DAT_06003c1a:
    .2byte  0x013C
.L_obj_table_init_a:
    .4byte  sym_060EE7D4
.L_fn_register_handler_2:
    .4byte  obj_transform_cache
.L_obj_table_slot_0a:
    .4byte  sym_060EECA8
.L_obj_table_slot_0b:
    .4byte  sym_060EF17C
.L_handler_slot_1bb:
    .4byte  0x002ADA4C
.L_obj_table_1bb:
    .4byte  0x002B4D1C
.L_obj_table_null_01:
    .4byte  0x002B4D50
.L_obj_table_null_02:
    .4byte  0x002B4D84
.L_obj_table_null_03:
    .4byte  0x002B4DE4
.L_obj_table_null_04:
    .4byte  0x002B510A
.L_obj_table_null_05:
    .4byte  0x002B517A
.L_obj_table_null_06:
    .4byte  0x002B4DB8
.L_obj_table_null_07:
    .4byte  0x002B4EAC
.L_obj_table_null_08:
    .4byte  0x002B4FF8
.L_obj_table_null_09:
    .4byte  0x002B5054
.L_obj_table_null_10:
    .4byte  0x002B50B2
.L_handler_slot_14:
    .4byte  0x002B43EC
.L_obj_table_slot_14:
    .4byte  0x002B7082
.L_obj_table_null_11:
    .4byte  0x002B709A
.L_handler_slot_db:
    .4byte  0x002B0910
.L_handler_table_a_2:
    .4byte  sym_06059EC8
.L_register_scene_handlers:
    mov.l   .L_handler_slot_13c, r6
    mov.l   .L_handler_table_a_3, r4
    mov.l   .L_fn_register_handler_3, r3
    jsr @r3
    mov #0x9, r5
    mov #0x19, r7
    mov.l   .L_handler_slot_19, r6
    mov.l   .L_handler_table_a_3, r4
    mov.l   .L_fn_register_handler_3, r3
    jsr @r3
    mov #0x8, r5
    mov.w   DAT_06003d36, r7
    mov.l   .L_handler_slot_106, r6
    mov.l   .L_handler_table_a_3, r4
    mov.l   .L_fn_register_handler_3, r3
    jsr @r3
    mov #0x9, r5
    mov.w   .L_slot_id_16a, r7
    mov.l   .L_handler_slot_16a, r6
    mov.l   .L_scene_table_16a, r4
    mov.l   .L_fn_register_handler_3, r3
    jsr @r3
    mov #0xC, r5
    mov #0x57, r7
    mov.l   .L_handler_slot_57, r6
    mov.l   .L_scene_table_57, r4
    mov.l   .L_fn_register_handler_3, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_01, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_02, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov.w   DAT_06003d3a, r7
    mov.l   .L_handler_slot_116, r6
    mov.l   .L_scene_table_116, r4
    mov.l   .L_fn_register_handler_3, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_03, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_04, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_05, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_06, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_07, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_08, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_scene_table_null_09, r4
    mov.l   .L_fn_register_handler_3, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x52, r7
    mov.l   .L_handler_slot_52, r6
    mov.l   .L_scene_table_52, r4
    mov.l   .L_fn_register_handler_3, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov r7, r6
    bra     .L_register_gfx_handlers
    mov #0xC, r5

    .global DAT_06003d36
DAT_06003d36:
    .2byte  0x0106
.L_slot_id_16a:
    .2byte  0x016A

    .global DAT_06003d3a
DAT_06003d3a:
    .2byte  0x0116
.L_handler_slot_13c:
    .4byte  0x002B121C
.L_handler_table_a_3:
    .4byte  sym_06059EC8
.L_fn_register_handler_3:
    .4byte  obj_transform_cache
.L_handler_slot_19:
    .4byte  0x002B3550
.L_handler_slot_106:
    .4byte  0x002BECFC
.L_handler_slot_16a:
    .4byte  0x002B2300
.L_scene_table_16a:
    .4byte  0x002B625E
.L_handler_slot_57:
    .4byte  0x002B04B4
.L_scene_table_57:
    .4byte  0x002B616E
.L_scene_table_null_01:
    .4byte  0x002B61C2
.L_scene_table_null_02:
    .4byte  0x002B6216
.L_handler_slot_116:
    .4byte  0x002B36B4
.L_scene_table_116:
    .4byte  0x002B6C02
.L_scene_table_null_03:
    .4byte  0x002B6C92
.L_scene_table_null_04:
    .4byte  0x002B6D22
.L_scene_table_null_05:
    .4byte  0x002B6DB2
.L_scene_table_null_06:
    .4byte  0x002B6E42
.L_scene_table_null_07:
    .4byte  0x002B6ED2
.L_scene_table_null_08:
    .4byte  0x002B6F62
.L_scene_table_null_09:
    .4byte  0x002B6FF2
.L_handler_slot_52:
    .4byte  0x002B8EA8
.L_scene_table_52:
    .4byte  0x002BE684
.L_register_gfx_handlers:
    mov.l   .L_gfx_table_init, r4
    mov.l   .L_fn_register_handler_4, r3
    jsr @r3
    nop
    mov #0x0, r7
    mov.l   .L_gfx_table_null_01, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_02, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_03, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov.w   .L_slot_id_220, r7
    mov.l   .L_handler_slot_220, r6
    mov.l   .L_gfx_table_220, r4
    mov.l   .L_fn_register_handler_4, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_04, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_05, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_06, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_07, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_08, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_09, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_10, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_11, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_12, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_13, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_14, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_gfx_table_null_15, r4
    mov.l   .L_fn_register_handler_4, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov r7, r6
    mov.l   .L_gfx_table_null_16, r4
    bra     .L_register_misc_handlers
    mov #0xC, r5
.L_slot_id_220:
    .2byte  0x0220
.L_gfx_table_init:
    .4byte  0x002BE6E8
.L_fn_register_handler_4:
    .4byte  obj_transform_cache
.L_gfx_table_null_01:
    .4byte  0x002BE71C
.L_gfx_table_null_02:
    .4byte  0x002BE780
.L_gfx_table_null_03:
    .4byte  0x002BE7B4
.L_handler_slot_220:
    .4byte  0x002ACB58
.L_gfx_table_220:
    .4byte  0x002B49CC
.L_gfx_table_null_04:
    .4byte  0x002B4A80
.L_gfx_table_null_05:
    .4byte  0x002B4AB4
.L_gfx_table_null_06:
    .4byte  0x002B4AE8
.L_gfx_table_null_07:
    .4byte  0x002B4B1C
.L_gfx_table_null_08:
    .4byte  0x002B4B50
.L_gfx_table_null_09:
    .4byte  0x002B4B84
.L_gfx_table_null_10:
    .4byte  0x002B4BB8
.L_gfx_table_null_11:
    .4byte  0x002B4BEC
.L_gfx_table_null_12:
    .4byte  0x002B4C20
.L_gfx_table_null_13:
    .4byte  0x002B4C54
.L_gfx_table_null_14:
    .4byte  0x002B4C64
.L_gfx_table_null_15:
    .4byte  0x002B4C70
.L_gfx_table_null_16:
    .4byte  0x002B4CAC
.L_register_misc_handlers:
    mov.l   .L_fn_register_handler_5, r3
    jsr @r3
    nop
    mov #0x0, r7
    mov.l   .L_misc_table_null_01, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_misc_table_null_02, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_misc_table_null_03, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_handler_table_a_5, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0x8, r5
    mov.w   .L_memset_size_0a00, r5
    mov.l   .L_memset_target_01, r4
    mov.l   .L_fn_register_memset, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_memset_size_0a00, r5
    mov.l   .L_memset_target_02, r4
    mov.l   .L_fn_register_memset, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_memset_size_0a00, r5
    mov.l   .L_memset_target_03, r4
    mov.l   .L_fn_register_memset, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_memset_size_0a00, r5
    mov.l   .L_memset_target_04, r4
    mov.l   .L_fn_register_memset, r3
    jsr @r3
    mov #0x4, r6
    mov #0x49, r7
    mov.l   .L_handler_slot_49, r6
    mov.l   .L_misc_table_49, r4
    mov.l   .L_fn_register_handler_5, r3
    jsr @r3
    mov #0xD, r5
    mov #0x14, r7
    mov.l   .L_handler_slot_14_2, r6
    mov.l   .L_misc_table_14, r4
    mov.l   .L_fn_register_handler_5, r3
    jsr @r3
    mov #0x5, r5
    mov #0x0, r7
    mov.l   .L_misc_table_null_04, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0x4, r5
    mov #0x10, r7
    mov.l   .L_handler_slot_10, r6
    mov.l   .L_misc_table_10, r4
    mov.l   .L_fn_register_handler_5, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_misc_table_null_05, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_misc_table_null_06, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_misc_table_null_07, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_misc_table_null_07, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_handler_table_a_5, r4
    mov.l   .L_fn_register_handler_5, r3
    mov r7, r6
    jsr @r3
    mov r7, r5
    mov #0x7, r7
    bra     .L_register_phys_handlers
    nop
.L_memset_size_0a00:
    .2byte  0x0A00
    .2byte  0xFFFF
.L_fn_register_handler_5:
    .4byte  obj_transform_cache
.L_misc_table_null_01:
    .4byte  0x002B4CC8
.L_misc_table_null_02:
    .4byte  0x002B4CE4
.L_misc_table_null_03:
    .4byte  0x002B4D00
.L_handler_table_a_5:
    .4byte  sym_06059EC8
.L_memset_target_01:
    .4byte  0x002A8964
.L_fn_register_memset:
    .4byte  sym_0600508A
.L_memset_target_02:
    .4byte  0x002A8AB8
.L_memset_target_03:
    .4byte  0x002A8C74
.L_memset_target_04:
    .4byte  0x002A8DC8
.L_handler_slot_49:
    .4byte  0x002AC63C
.L_misc_table_49:
    .4byte  0x002B4918
.L_handler_slot_14_2:
    .4byte  0x002B43EC
.L_misc_table_14:
    .4byte  0x002B7082
.L_misc_table_null_04:
    .4byte  0x002B709A
.L_handler_slot_10:
    .4byte  0x002B9194
.L_misc_table_10:
    .4byte  0x002BE7DC
.L_misc_table_null_05:
    .4byte  0x002BE7EC
.L_misc_table_null_06:
    .4byte  0x002BE7FC
.L_misc_table_null_07:
    .4byte  0x002BE80C
.L_register_phys_handlers:
    mov.l   .L_handler_slot_07, r6
    mov.l   .L_phys_table_07, r4
    mov.l   .L_fn_register_handler_6, r3
    jsr @r3
    mov #0x4, r5
    mov #0x26, r7
    mov.l   .L_handler_slot_26, r6
    mov.l   .L_phys_table_26, r4
    mov.l   .L_fn_register_handler_6, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_phys_table_null_01, r4
    mov.l   .L_fn_register_handler_6, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_phys_table_null_02, r4
    mov.l   .L_fn_register_handler_6, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_phys_table_null_03, r4
    mov.l   .L_fn_register_handler_6, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_phys_table_null_04, r4
    mov.l   .L_fn_register_handler_6, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_phys_table_null_05, r4
    mov.l   .L_fn_register_handler_6, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x1B, r7
    mov.l   .L_handler_slot_1b, r6
    mov.l   .L_phys_table_1b, r4
    mov.l   .L_fn_register_handler_6, r3
    jsr @r3
    mov #0x4, r5
    mov #0x0, r7
    mov.l   .L_phys_table_null_06, r4
    mov.l   .L_fn_register_handler_6, r3
    mov r7, r6
    jsr @r3
    mov #0x4, r5
    mov #0x17, r7
    mov.l   .L_handler_slot_17, r6
    mov.l   .L_phys_table_17, r4
    mov.l   .L_fn_register_handler_6, r3
    jsr @r3
    mov #0xC, r5
    mov.w   .L_memset_size_0bb8, r5
    mov.l   .L_memset_target_05, r4
    mov.l   .L_fn_register_memset_2, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_memset_size_0bb8, r5
    mov.l   .L_memset_target_06, r4
    mov.l   .L_fn_register_memset_2, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_memset_size_0bb8, r5
    mov.l   .L_memset_target_07, r4
    mov.l   .L_fn_register_memset_2, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_memset_size_0bb8, r5
    mov.l   .L_memset_target_08, r4
    mov.l   .L_fn_register_memset_2, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_memset_size_0bb8, r5
    mov.l   .L_memset_target_09, r4
    mov.l   .L_fn_register_memset_2, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_memset_size_0bb8, r5
    mov.l   .L_memset_target_10, r4
    mov.l   .L_fn_register_memset_2, r3
    jsr @r3
    mov #0x4, r6
    mov.w   DAT_060040a0, r5
    mov.l   .L_memset_target_11, r4
    mov.l   .L_fn_register_memset_2, r3
    jsr @r3
    mov #0x4, r6
    mov.w   DAT_060040a2, r5
    bra     .L_register_final_batch
    mov #0x4, r6
.L_memset_size_0bb8:
    .2byte  0x0BB8

    .global DAT_060040a0
DAT_060040a0:
    .2byte  0x0C4F

    .global DAT_060040a2
DAT_060040a2:
    .2byte  0x0D7D
.L_handler_slot_07:
    .4byte  0x002B8DC8
.L_phys_table_07:
    .4byte  0x002BE672
.L_fn_register_handler_6:
    .4byte  obj_transform_cache
.L_handler_slot_26:
    .4byte  0x002B9244
.L_phys_table_26:
    .4byte  0x002BE81C
.L_phys_table_null_01:
    .4byte  0x002BE834
.L_phys_table_null_02:
    .4byte  0x002BE84C
.L_phys_table_null_03:
    .4byte  0x002BE864
.L_phys_table_null_04:
    .4byte  0x002BE87C
.L_phys_table_null_05:
    .4byte  0x002BE888
.L_handler_slot_1b:
    .4byte  0x002B943C
.L_phys_table_1b:
    .4byte  0x002BE894
.L_phys_table_null_06:
    .4byte  0x002BE8B4
.L_handler_slot_17:
    .4byte  0x002B979C
.L_phys_table_17:
    .4byte  0x002BE8D2
.L_memset_target_05:
    .4byte  0x002B51EA
.L_fn_register_memset_2:
    .4byte  sym_0600508A
.L_memset_target_06:
    .4byte  0x002B5B8E
.L_memset_target_07:
    .4byte  0x002B5F02
.L_memset_target_08:
    .4byte  0x002BDB00
.L_memset_target_09:
    .4byte  0x002BDBC4
.L_memset_target_10:
    .4byte  0x002BDC04
.L_memset_target_11:
    .4byte  0x002BDC50
.L_register_final_batch:
    mov.l   .L_final_memset_target, r4
    mov.l   .L_fn_register_memset_3, r3
    jsr @r3
    nop
    mov.w   DAT_060041c2, r5
    mov.l   .L_final_memset_batch, r4
    .4byte  0xD32F430B
    .4byte  0xE6049556
    .4byte  0xD42FD32D
    .4byte  0x430BE604
    .4byte  0x9551D42E
    .4byte  0xD32A430B
    .4byte  0xE604954C
    .4byte  0xD42CD328
    .4byte  0x430BE604
    .4byte  0x9547D42B
    .4byte  0xD325430B
    .4byte  0xE6049542
    .4byte  0xD429D323
    .4byte  0x430BE604
    .4byte  0x953DD428
    .4byte  0xD320430B
    .4byte  0xE6049538
    .4byte  0xD426D31E
    .4byte  0x430BE604
    .4byte  0x9533D425
    .4byte  0xD31B430B
    .4byte  0xE604952F
    .4byte  0xD423D319
    .4byte  0x430BE604
    .4byte  0x952AD422
    .4byte  0xD316430B
    .4byte  0xE6049525
    .4byte  0xD420D314
    .4byte  0x430BE604
    .4byte  0x9520D41F
    .4byte  0xD311430B
    .4byte  0xE604E777
    .4byte  0xD61DD41E
    .4byte  0xD31E430B
    .4byte  0xE50CE700
    .4byte  0xD41DD31C
    .4byte  0x6673430B
    .4byte  0xE50CE700
    .4byte  0xD41BD319
    .4byte  0x6673430B
    .4byte  0xE50CE700
    .4byte  0xD419D316
    .4byte  0x6673430B
    .4byte  0xE50CE73C
    .4byte  0xD617A02F
    .2byte  0xE50C

    .global DAT_060041c2
DAT_060041c2:
    .2byte  0x0D7D

    .global DAT_060041c4
DAT_060041c4:
    .4byte  0x0E4CFFFF
.L_final_memset_target:
    .4byte  0x002BE098
.L_fn_register_memset_3:
    .4byte  sym_0600508A
.L_final_memset_batch:
    .4byte  0x002BE10C
    .4byte  0x002BE180
    .4byte  0x002BE1F4
    .4byte  0x002BE268
    .4byte  0x002BE2DC
    .4byte  0x002BE350
    .4byte  0x002BE3C4
    .4byte  0x002BE438
    .4byte  0x002BE4AC
    .4byte  0x002BE520
    .4byte  0x002BE54C
    .4byte  0x002BE588
    .4byte  0x002BE5C4
    .4byte  0x002A7643
    .4byte  0x002AC278
    .4byte  obj_transform_cache
    .4byte  0x002AC2EA
    .4byte  0x002AC2A6
    .4byte  0x002AC326
    .4byte  0x002B98F0
    .4byte  0xD432D333
    .4byte  0x430B0009
    .4byte  0xE700D432
    .4byte  0xD3306673
    .4byte  0x430BE50C
    .4byte  0xE700D430
    .4byte  0xD32D6673
    .4byte  0x430BE50C
    .4byte  0xE700D42E
    .4byte  0xD32A6673
    .4byte  0x430BE50C
    .4byte  0x954BD42C
    .4byte  0xD32C430B
    .4byte  0xE6049547
    .4byte  0xD42BD32A
    .4byte  0x430BE604
    .4byte  0x9542D42A
    .4byte  0xD327430B
    .4byte  0xE604953D
    .4byte  0xD428D325
    .4byte  0x430BE604
    .4byte  0x9538D427
    .4byte  0xD322430B
    .4byte  0xE6049533
    .4byte  0xD425D320
    .4byte  0x430BE604
    .4byte  0x952ED424
    .4byte  0xD31D430B
    .4byte  0xE6049529
    .4byte  0xD422D31B
    .4byte  0x430BE604
    .4byte  0x9524D421
    .4byte  0xD318430B
    .4byte  0xE604951F
    .4byte  0xD41FD316
    .4byte  0x430BE604
    .4byte  0x951AD41E
    .4byte  0xD313430B
    .4byte  0xE6049515
    .4byte  0xD41CD311
    .4byte  0x430BE604
    .4byte  0x9510D41B
    .4byte  0xD30E430B
    .4byte  0xE604950B
    .4byte  0xD419D30C
    .4byte  0x430BE604
    .4byte  0x9506D418
    .4byte  0xD309430B
    .4byte  0xE604A02D
    .4byte  0xE6040A00
    .4byte  0x0BB8FFFF
    .4byte  0x002BE90E
    .4byte  obj_transform_cache
    .4byte  0x002BE944
    .4byte  0x002BE97A
    .4byte  0x002BE9B0
    .4byte  0x002ED748
    .4byte  sym_0600508A
    .4byte  0x002EE0EC
    .4byte  0x002EE1B0
    .4byte  0x002EE2B4
    .4byte  0x002EE3B8
    .4byte  0x002EE454
    .4byte  0x002EE4F0
    .4byte  0x002EE510
    .4byte  0x002EE53C
    .4byte  0x002EE56C
    .4byte  0x002EE594
    .4byte  0x002EE5A8
    .4byte  0x002EE5C4
    .4byte  0x002EE5D8
    .4byte  0x002EE600
    .4byte  0x9560D431
    .4byte  0xD331430B
    .4byte  0x0009955B
    .4byte  0xD430D32F
    .4byte  0x430BE604
    .4byte  0x9556D42F
    .4byte  0xD32C430B
    .4byte  0xE6049551
    .4byte  0xD42DD32A
    .4byte  0x430BE604
    .4byte  0x954CD42C
    .4byte  0xD327430B
    .4byte  0xE6049547
    .4byte  0xD42AD325
    .4byte  0x430BE604
    .4byte  0x9542D429
    .4byte  0xD322430B
    .4byte  0xE604953D
    .4byte  0xD427D320
    .4byte  0x430BE604
    .4byte  0x9538D426
    .4byte  0xD31D430B
    .4byte  0xE6049533
    .4byte  0xD424D31B
    .4byte  0x430BE604
    .4byte  0x952ED423
    .4byte  0xD318430B
    .4byte  0xE6049529
    .4byte  0xD421D316
    .4byte  0x430BE604
    .4byte  0x9524D420
    .4byte  0xD313430B
    .4byte  0xE604951F
    .4byte  0xD41ED311
    .4byte  0x430BE604
    .4byte  0x951AD41D
    .4byte  0xD30E430B
    .4byte  0xE6049515
    .4byte  0xD41BD30C
    .4byte  0x430BE604
    .4byte  0x9510D41A
    .4byte  0xD309430B
    .4byte  0xE604950B
    .4byte  0xD418D307
    .4byte  0x430BE604
    .4byte  0x9506D417
    .4byte  0xD304430B
    .4byte  0xE6049501
    .4byte  0xA02AE604
    .4byte  0x0BB8FFFF
    .4byte  0x002EE620
    .4byte  sym_0600508A
    .4byte  0x002EE648
    .4byte  0x002EE72C
    .4byte  0x002EE738
    .4byte  0x002EE744
    .4byte  0x002EE770
    .4byte  0x002EE79C
    .4byte  0x002EE7C8
    .4byte  0x002EE7F4
    .4byte  0x002EE820
    .4byte  0x002EE84C
    .4byte  0x002EE878
    .4byte  0x002EE8A4
    .4byte  0x002EE8D0
    .4byte  0x002EE8FC
    .4byte  0x002EE928
    .4byte  0x002EE954
    .4byte  0x002EE980
    .4byte  0x002EE9AC
    .4byte  0xD430D331
    .4byte  0x430B0009
    .4byte  0x955BD430
    .4byte  0xD32E430B
    .4byte  0xE6049556
    .4byte  0xD42ED32C
    .4byte  0x430BE604
    .4byte  0x9551D42D
    .4byte  0xD329430B
    .4byte  0xE604954C
    .4byte  0xD42BD327
    .4byte  0x430BE604
    .4byte  0x9547D42A
    .4byte  0xD324430B
    .4byte  0xE6049542
    .4byte  0xD428D322
    .4byte  0x430BE604
    .4byte  0x953DD427
    .4byte  0xD31F430B
    .4byte  0xE6049538
    .4byte  0xD425D31D
    .4byte  0x430BE604
    .4byte  0x9533D424
    .4byte  0xD31A430B
    .4byte  0xE604952E
    .4byte  0xD422D318
    .4byte  0x430BE604
    .4byte  0x9529D421
    .4byte  0xD315430B
    .4byte  0xE6049524
    .4byte  0xD41FD313
    .4byte  0x430BE604
    .4byte  0x951FD41E
    .4byte  0xD310430B
    .4byte  0xE604951A
    .4byte  0xD41CD30E
    .4byte  0x430BE604
    .4byte  0x9515D41B
    .4byte  0xD30B430B
    .4byte  0xE6049510
    .4byte  0xD419D309
    .4byte  0x430BE604
    .4byte  0x950BD418
    .4byte  0xD306430B
    .4byte  0xE6049506
    .4byte  0xD416D304
    .4byte  0x430BE604
    .4byte  0x9501A029
    .4byte  0xE6040BB8
    .4byte  0x002EE9C8
    .4byte  sym_0600508A
    .4byte  0x002EE9DE
    .4byte  0x002EE9F4
    .4byte  0x002EEA10
    .4byte  0x002EEA2C
    .4byte  0x002EEA3C
    .4byte  0x002EEA48
    .4byte  0x002EEA6A
    .4byte  0x002EEA86
    .4byte  0x002EEAB2
    .4byte  0x002EEAC2
    .4byte  0x002EEAD6
    .4byte  0x002EEAFE
    .4byte  0x002EEB0E
    .4byte  0x002EEB22
    .4byte  0x002EEB4A
    .4byte  0x002EEB60
    .4byte  0x002EEB76
    .4byte  0x002EF51A
    .4byte  0xD429D32A
    .4byte  0x430B0009
    .4byte  0x974AD629
    .4byte  0xD429D32A
    .4byte  0x430BE509
    .4byte  0x9745D629
    .4byte  0xD429D327
    .4byte  0x430BE509
    .4byte  0x9540D428
    .4byte  0xD321430B
    .4byte  0xE604953B
    .4byte  0xD426D31F
    .4byte  0x430BE604
    .4byte  0x9536D425
    .4byte  0xD31C430B
    .4byte  0xE604E71F
    .4byte  0xD623D424
    .4byte  0xD31C430B
    .4byte  0xE50CE70A
    .4byte  0xD622D423
    .4byte  0xD319430B
    .4byte  0xE505E703
    .4byte  0xD621D422
    .4byte  0xD316430B
    .4byte  0xE500E700
    .4byte  0xD420D314
    .4byte  0x6673430B
    .4byte  0x6573E712
    .4byte  0xD61ED41F
    .4byte  0xD310430B
    .4byte  0xE5049514
    .4byte  0xD41DD30B
    .4byte  0x430BE604
    .4byte  0x950FD41C
    .4byte  0xD308430B
    .4byte  0xE604E706
    .4byte  0xD61AD41B
    .4byte  0xD308430B
    .4byte  0xE5004F26
    .4byte  0x000B0009
    .4byte  0x00A201C8

    .global DAT_06004610
DAT_06004610:
    .2byte  0x0E95

    .global DAT_06004612
DAT_06004612:
    .2byte  0x0B5E
    .4byte  0x002BE9E6
    .4byte  sym_0600508A
    .4byte  0x002BCF4C
    .4byte  sym_060438CE
    .4byte  obj_transform_cache
    .4byte  0x002BA314
    .4byte  sym_06044272
    .4byte  0x002BEB8E
    .4byte  0x002BEC32
    .4byte  0x002BECEA
    .4byte  0x002B47AC
    .4byte  0x002B70CA
    .4byte  0x002B466C
    .4byte  0x002B70B2
    .4byte  sym_0605E0E8
    .4byte  sym_0605E148
    .4byte  sym_0605E150
    .4byte  0x002ED508
    .4byte  0x002EFEBE
    .4byte  0x002AC3A0
    .4byte  0x002AC4BC
    .4byte  sym_06059E08
    .4byte  sym_06059DF8

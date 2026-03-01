
    .section .text.FUN_0600629C


    .global car_array_init
    .type car_array_init, @function
car_array_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    extu.w r13, r1
    extu.w r13, r0
    extu.w r13, r3
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_car_array_base, r8
    mov.w   .L_car_struct_stride, r9
    mov.l   .L_fn_car_type_init, r10
    mov.l   .L_car_struct_scratch, r12
    mov.l   .L_cur_car_ptr, r14
    mov.l   .L_global_clear_a, r2
    mov.w r13, @r2
    mov.l   .L_global_clear_b, r2
    mov.w r1, @r2
    mov.l   .L_global_clear_c, r2
    mov.w r0, @r2
    mov.l   .L_global_clear_d, r2
    mov.w r3, @r2
    mov.l   .L_display_mode_flag, r1
    mov.b @r1, r1
    extu.b r1, r1
    tst r1, r1
    bt      .L_skip_display_init
    mov r8, r3
    add r9, r3
    mov.l r3, @r14
    mov r3, r2
    mov.l r3, @r12
    mov.l @r14, r3
    jsr @r10
    mov.l r13, @(4, r3)
    mov.l @r12, r2
    mov #0x38, r3
    mov #0x74, r0
    mov.l r3, @(r0, r2)
    mov.l @r12, r3
    mov #0x38, r2
    add #0x1C, r0
    mov.l r2, @(r0, r3)
    mov.l   .L_car_param_table, r4
    add #0xE, r0
    mov.l @r12, r3
    mov.b @r4, r2
    extu.b r2, r2
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    mov.b @(1, r4), r0
    mov r0, r2
    extu.b r2, r2
    mov #0x7C, r0
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    mov.b @(2, r4), r0
    mov r0, r2
    extu.b r2, r2
    mov.w   DAT_06006360, r0
    mov.w r2, @(r0, r3)
    mov.l   .L_attract_cycle_cnt, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_set_attract_default
    mov.l @r14, r3
    mov.w   DAT_06006362, r0
    mov.w r13, @(r0, r3)
    mov.l @r14, r3
    exts.w r13, r2
    add #0x2, r0
    mov.w r2, @(r0, r3)
    bra     .L_init_player_car
    nop
.L_set_attract_default:
    mov.l @r14, r2
    mov #0x3, r3
    mov.w   DAT_06006362, r0
    mov.w r3, @(r0, r2)
    mov.l @r14, r3
    mov #0x3, r2
    add #0x2, r0
    mov.w r2, @(r0, r3)
.L_init_player_car:
    mov r8, r3
    mov.l r8, @r14
    mov r3, r2
    mov.l r3, @r12
    mov.l @r14, r3
    jsr @r10
    mov.l r13, @(4, r3)
    bra     .L_post_loop_setup
    nop
.L_skip_display_init:
    bra     .L_car_init_loop_cond
    mov r13, r11
.L_car_struct_stride:
    .2byte  0x0268                      /* car struct size: 616 bytes */

    .global DAT_06006360
DAT_06006360:
    .2byte  0x009C                      /* car struct offset for param[2] */

    .global DAT_06006362
DAT_06006362:
    .2byte  0x00DC                      /* car struct offset for attract fields */
.L_car_array_base:
    .4byte  sym_06078900               /* car struct array base address */
.L_fn_car_type_init:
    .4byte  car_type_init              /* per-car type initialization function */
.L_car_struct_scratch:
    .4byte  sym_0607E944               /* primary car pointer (stored/persistent, "car ptr stored") */
.L_cur_car_ptr:
    .4byte  sym_0607E940               /* working car pointer (active/current, "car ptr working") */
.L_global_clear_a:
    .4byte  sym_0605DF4E               /* global state word A (zeroed on init) */
.L_global_clear_b:
    .4byte  sym_0605DF50               /* global state word B (zeroed on init) */
.L_global_clear_c:
    .4byte  sym_0605DF52               /* global state word C (zeroed on init) */
.L_global_clear_d:
    .4byte  sym_0605DF54               /* global state word D (zeroed on init) */
.L_display_mode_flag:
    .4byte  sym_06078635               /* display/phase flag (byte: 0=attract/normal, nonzero=special) */
.L_car_param_table:
    .4byte  sym_0607ED90               /* 3 config bytes read into car struct (also ring buffer base in other contexts) */
.L_attract_cycle_cnt:
    .4byte  sym_0607EAD8               /* attract cycle counter (dword) */
.L_car_init_loop_body:
    mul.l r9, r11
    sts macl, r2
    add r8, r2
    mov r2, r3
    mov.l r2, @r14
    jsr @r10
    mov.l r11, @(4, r3)
    add #0x1, r11
.L_car_init_loop_cond:
    mov.l   .L_total_car_count, r2
    mov.l @r2, r2
    cmp/ge r2, r11
    bf      .L_car_init_loop_body
.L_post_loop_setup:
    mov.l @r12, r2
    mov #0x38, r3
    mov #0x74, r0
    mov.l r3, @(r0, r2)
    mov.l @r12, r3
    mov #0x38, r2
    add #0x1C, r0
    mov.l r2, @(r0, r3)
    mov.l @r12, r3
    add #0xC, r0
    mov.l   .L_car_type_param, r2
    mov.l @r2, r2
    exts.w r2, r2
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    add #0x2, r0
    mov.l   .L_hud_elem_index, r2
    mov.w @r2, r2
    mov.w r2, @(r0, r3)
    mov #0x7C, r0
    mov.l @r12, r3
    mov.l   .L_player_car_index, r2
    mov.l @r2, r2
    mov.w r2, @(r0, r3)
    mov.l   .L_fn_car_ptr_list_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_scroll_param_load, r3
    jsr @r3
    nop
    mov.l   .L_prev_game_state, r0
    mov.l @r0, r0
    cmp/eq #0xE, r0
    bf      .L_clear_race_flag
    mov.l   .L_attract_cycle_cnt_b, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_set_race_flag
.L_clear_race_flag:
    mov #0x0, r3
    mov.l   .L_race_state_flag, r2
    mov.l r3, @r2
    bra     .L_init_camera_params
    nop
.L_set_race_flag:
    mov #0x1, r3
    mov.l   .L_race_state_flag, r2
    mov.l r3, @r2
.L_init_camera_params:
    mov.l @r12, r4
    mov.l   .L_camera_yaw_store, r3
    mov.l @(32, r4), r2
    mov.l r2, @r3
    add #0x4, r3
    mov.l r13, @r3
    mov.l   .L_cam_angle_06063F10, r3
    mov.l r13, @r3
    mov.l   .L_cam_chain_a, r3
    mov.l r13, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_cam_chain_b, r3
    mov.l r2, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_cam_chain_c, r3
    mov.l r2, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_cam_chain_d, r3
    mov.l r2, @r3
    mov.l   .L_cam_initial_z_offset, r2
    mov.l   .L_cam_chain_e, r3
    mov.l r2, @r3
    mov.l   .L_attract_cycle_cnt_b, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_set_attract_pos_default
    mov.w   .L_attract_field_off, r0
    mov.w r13, @(r0, r4)
    exts.w r13, r3
    add #0x2, r0
    mov.w r3, @(r0, r4)
    bra     .L_final_state_config
    nop
.L_attract_field_off:
    .2byte  0x00DC                      /* car struct offset for attract field A */
    .2byte  0xFFFF                      /* padding / alignment */
.L_total_car_count:
    .4byte  sym_0607EA98               /* total number of cars in race */
.L_car_type_param:
    .4byte  sym_0607EAB8               /* car type parameter (dword) */
.L_hud_elem_index:
    .4byte  sym_06063F42               /* HUD element index (word) */
.L_player_car_index:
    .4byte  sym_06078868               /* player car/sprite index (dword) */
.L_fn_car_ptr_list_init:
    .4byte  sym_0600D280               /* car_ptr_list_init — rebuilds sorted car pointer lists */
.L_fn_scroll_param_load:
    .4byte  sym_0602E5E4               /* scroll_param_load — initializes rotation scroll parameters */
.L_prev_game_state:
    .4byte  sym_0607EBC0               /* previous game state (saved each frame by main loop) */
.L_attract_cycle_cnt_b:
    .4byte  sym_0607EAD8               /* attract cycle counter (dword) */
.L_race_state_flag:
    .4byte  sym_0607EAD0               /* race state flag at sym_0607EAD0 (annotations disagree: "race_end_flag" in race_states.s, set=1 here when attract_cycle==0) */
.L_camera_yaw_store:
    .4byte  sym_06063EF0               /* heading global — car heading copied here (also used by race_update) */
.L_cam_angle_06063F10:
    .4byte  sym_06063F10               /* camera angle register (cleared on init, no external confirmation) */
.L_cam_chain_a:
    .4byte  sym_06063E78               /* camera chain A — zero-propagation chain start */
.L_cam_chain_b:
    .4byte  sym_06063E8C               /* camera chain B — receives from A */
.L_cam_chain_c:
    .4byte  sym_06063E64               /* camera chain C — receives from B */
.L_cam_chain_d:
    .4byte  sym_06063E50               /* camera chain D — receives from C */
.L_cam_initial_z_offset:
    .4byte  0xFEA00000                 /* fixed-point 16.16: -352.0 (initial camera Z offset) */
.L_cam_chain_e:
    .4byte  sym_06063F14               /* camera param chain E (receives initial Z offset) */
.L_set_attract_pos_default:
    mov #0x3, r2
    .byte   0x90, 0x59    /* mov.w .L_wpool_0600654C, r0 */
    mov.w r2, @(r0, r4)
    mov r2, r3
    add #0x2, r0
    mov.w r3, @(r0, r4)
.L_final_state_config:
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006550, r3 */
    mov #0x2, r2
    mov #0x0, r5
    mov.l r13, @r3
    .byte   0xD3, 0x2A    /* mov.l .L_pool_06006554, r3 */
    mov.l r2, @r3
    mov #0x1, r2
    .byte   0xD3, 0x2A    /* mov.l .L_pool_06006558, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x2A    /* mov.l .L_pool_0600655C, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xD2, 0x29    /* mov.l .L_pool_06006560, r2 */
    .byte   0xD3, 0x2A    /* mov.l .L_pool_06006564, r3 */
    mov.l r2, @r3
    .byte   0xD4, 0x2A    /* mov.l .L_pool_06006568, r4 */
    .byte   0xD3, 0x2A    /* mov.l .L_pool_0600656C, r3 */
    mov.l r4, @r3
    .byte   0xD2, 0x2A    /* mov.l .L_pool_06006570, r2 */
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006574, r3 */
    mov.l r2, @r3
    .byte   0xD2, 0x2B    /* mov.l .L_pool_06006578, r2 */
    .byte   0xD3, 0x2B    /* mov.l .L_pool_0600657C, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006580, r3 */
    mov.l r13, @r3
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006584, r3 */
    mov.l r4, @r3
    mov #0x2, r2
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006588, r3 */
    mov.l r2, @r3
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA1, 0x6B    /* bra 0x060067C8 (external) */
    mov.l @r15+, r14

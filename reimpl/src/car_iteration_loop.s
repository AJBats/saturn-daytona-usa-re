
    .section .text.FUN_0600DE70


    .global car_iteration_loop
    .type car_iteration_loop, @function
car_iteration_loop:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x1, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   _pool_frame_marker, r8
    mov.l   _pool_physics_init_flag, r9
    mov.l   _pool_warmup_countdown, r10
    mov.l   _pool_current_car_ptr, r11
    mov.l   _pool_car_base_ptr, r14
    mov.l   _pool_total_car_count_ptr, r0
    mov.l   _pool_fn_calc_divisor, r3
    mov.l @r0, r0
    jsr @r3
    mov #-0x4, r1
    exts.w r0, r0
    mov.l   _pool_half_count_store, r3
    mov.w r0, @r3
    mov.l   _pool_camera_yaw_ptr, r2
    mov.l @r2, r2
    mov.l r2, @(8, r15)
    mov #0x0, r12
    mov.l   _pool_car_array_base, r4
    mov.w   DAT_0600deb2, r3
    add r4, r3
    mov.l r3, @(4, r15)
    bra     .L_loop_test
    mov.l r4, @r15

    .global DAT_0600deb2
DAT_0600deb2:
    .2byte  0x0268
_pool_total_car_count_ptr:
    .4byte  sym_0607EA98
_pool_half_count_store:
    .4byte  sym_060786CA
_pool_car_base_ptr:
    .4byte  sym_0607E944
_pool_current_car_ptr:
    .4byte  sym_0607E940
_pool_frame_marker:
    .4byte  sym_0607ED8C
_pool_physics_init_flag:
    .4byte  sym_0607EAE4
_pool_warmup_countdown:
    .4byte  sym_0607ED88
_pool_fn_calc_divisor:
    .4byte  sym_06035340
_pool_camera_yaw_ptr:
    .4byte  sym_06063EF0
_pool_car_array_base:
    .4byte  sym_06078900
.L_loop_body:
    .byte   0xD0, 0x2D    /* mov.l .L_pool_0600DF94, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_normal_mode
    extu.w r12, r12
    tst r12, r12
    bf      .L_setup_car0
    mov.w r13, @r8
    mov.l @(4, r15), r2
    mov.l r2, @r14
    mov r2, r3
    bra     .L_call_car_update
    mov.l r2, @r11
.L_setup_car0:
    mov #0x0, r2
    mov.w r2, @r8
    mov.l @r10, r3
    add #-0x2, r3
    mov.l r3, @r10
    mov.l @r15, r2
    mov.l r2, @r14
    mov.l @(8, r15), r3
    .byte   0xD2, 0x23    /* mov.l .L_pool_0600DF98, r2 */
    mov.l r3, @r2
    mov.l @r14, r3
    mov.l r3, @r11
    bra     .L_call_car_update
    nop
.L_normal_mode:
    mov.l @r9, r0
    tst r0, r0
    bf      .L_call_car_update
    mov.l r13, @r9
.L_call_car_update:
    .byte   0xB2, 0xE9    /* bsr 0x0600E4F2 (external) */
    nop
    add #0x1, r12
.L_loop_test:
    extu.w r12, r2
    .byte   0xD3, 0x1D    /* mov.l .L_pool_0600DF9C, r3 */
    mov.b @r3, r3
    extu.b r3, r3
    cmp/ge r3, r2
    bf      .L_loop_body
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0600DFA0, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x1B    /* mov.l .L_pool_0600DFA4, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_standard_render
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0600DFA8, r3 */
    jsr @r3
    nop
    bra     .L_frame_finalize
    nop
.L_standard_render:
    .byte   0xD3, 0x19    /* mov.l .L_pool_0600DFAC, r3 */
    jsr @r3
    nop
.L_frame_finalize:
    .byte   0xD3, 0x18    /* mov.l .L_pool_0600DFB0, r3 */
    jsr @r3
    nop
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0xAD    /* bra 0x0600E0C0 (external) */
    mov.l @r15+, r14

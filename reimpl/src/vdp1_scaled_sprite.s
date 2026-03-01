
    .section .text.FUN_0602DC68


    .global vdp1_scaled_sprite
    .type vdp1_scaled_sprite, @function
vdp1_scaled_sprite:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_ptr_render_state_byte, r1
    mov.l   .L_const_scaled_mode, r0
    mov.b r0, @r1
    mov.l   .L_ptr_camera_param_b, r1
    mov.l   .L_cam_param_offset, r2
    add r2, r1
    mov.l @r1, r2
    mov.l   .L_ptr_attract_cycle, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_ptr_cmd_limit_table, r0
    mov.l @(r0, r3), r0
    cmp/gt r2, r0
    bf      .L_store_limit
    mov.l   .L_cmd_limit_step, r3
    add r3, r2
    cmp/gt r2, r0
    bf      .L_store_limit
    mov.l r2, @r1
    bra     .L_check_car_ptr
    nop
    .4byte  sym_06082A2C               /* (unreachable pool) RBG coefficient ptr */
    .4byte  0x00000028                 /* (unreachable pool) offset 0x28 */
    .4byte  disp_init_setup            /* (unreachable pool) fn ptr: disp_init_setup */
.L_ptr_render_state_byte:
    .4byte  sym_06082A26               /* render state byte */
.L_const_scaled_mode:
    .4byte  0x00000001                 /* 1 = scaled sprite mode */
.L_ptr_camera_param_b:
    .4byte  sym_06063EEC               /* camera smoothed heading param base */
.L_cam_param_offset:
    .4byte  0x00000004                 /* byte offset to heading[1] */
.L_ptr_attract_cycle:
    .4byte  sym_0607EAD8               /* attract cycle counter (0/1/2) */
.L_ptr_cmd_limit_table:
    .4byte  sym_0602ECAC               /* VDP1 cmd limit table (per attract cycle) */
.L_cmd_limit_step:
    .4byte  0x00000100                 /* 256: increment per frame */
.L_store_limit:
    mov.l r0, @r1
.L_check_car_ptr:
    mov.l   .L_ptr_car_struct, r0
    mov.l @r0, r0
    mov.l   .L_car_field_offset, r1
    mov.l @(r0, r1), r4
    mov.l   .L_const_null, r1
    cmp/eq r1, r4
    bf      .L_return
    mov.l   .L_ptr_cmd_state_byte, r4
    mov.l   .L_const_neg_one, r1
    mov.b r1, @r4
    mov.l   .L_ptr_render_state_byte_b, r4
    mov.l   .L_const_mode_two, r1
    mov.b r1, @r4
    mov.l   .L_ptr_render_mode, r4
    mov.l   .L_const_mode_one, r1
    mov.l r1, @r4
.L_return:
    rts
    nop
    .2byte  0x0000
.L_ptr_car_struct:
    .4byte  sym_0607E940               /* pointer to current car struct */
.L_car_field_offset:
    .4byte  0x00000008                 /* byte offset to car VDP1 draw pointer */
.L_const_null:
    .4byte  0x00000000                 /* NULL comparison value */
.L_ptr_cmd_state_byte:
    .4byte  sym_06082A24               /* VDP1 cmd state byte */
.L_const_neg_one:
    .4byte  0xFFFFFFFF                  /* -1: clear/reset marker */
.L_ptr_render_state_byte_b:
    .4byte  sym_06082A26               /* render state byte (second ref) */
.L_const_mode_two:
    .4byte  0x00000002                 /* 2 = skip/inactive mode */
.L_ptr_render_mode:
    .4byte  sym_06082A30               /* render mode (32-bit state) */
.L_const_mode_one:
    .4byte  0x00000001                 /* 1 = idle mode */

    .global loc_0602DD10
loc_0602DD10:
    mov.l   .L_ptr_attract_cycle_b, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_ptr_cmd_dispatch_table, r0
    mov.l @(r0, r3), r1
    mov.l   .L_ptr_cmd_slot_counter, r0
    mov.l @r0, r0
    shll2 r0
    shll2 r0
    shll r0
    add r0, r1
    mov.l @r1+, r3
    mov.l   .L_end_of_list_sentinel, r0
    cmp/eq r0, r3
    bf      .L_process_cmd_data
    mov.l   .L_ptr_cmd_slot_counter, r1
    mov.l   .L_const_zero, r0
    mov.l r0, @r1
    mov.l   .L_ptr_render_mode_b, r0
    mov.l   .L_const_state_done, r1
    mov.l r1, @r0
    rts
    nop
    .2byte  0x0000
.L_ptr_attract_cycle_b:
    .4byte  sym_0607EAD8               /* attract cycle counter (0/1/2) */
.L_ptr_cmd_dispatch_table:
    .4byte  sym_0602ECBC               /* cmd list base table (per attract cycle) */
.L_ptr_cmd_slot_counter:
    .4byte  sym_06082A38               /* current cmd slot index */
.L_end_of_list_sentinel:
    .4byte  0xFFFFFFFF                  /* -1: end-of-list sentinel */
.L_const_zero:
    .4byte  0x00000000                 /* 0: reset value */
.L_ptr_render_mode_b:
    .4byte  sym_06082A30               /* render mode (second ref) */
.L_const_state_done:
    .4byte  0x00000003                 /* 3 = rendering done */
.L_process_cmd_data:
    .byte   0xD0, 0x46    /* mov.l .L_xpool_ptr_render_mode, r0 */  ! r0 -> render_mode (sym_06082A30)
    .byte   0xD2, 0x47    /* mov.l .L_xpool_const_0x2, r2 */        ! r2 = 0x2
    mov.l r2, @r0
    .byte   0xD2, 0x47    /* mov.l .L_xpool_ptr_dirty_flags, r2 */  ! r2 -> dirty_flags (sym_06082A3C)
    mov.l r3, @r2
    mov.l @r1+, r4
    .byte   0xD2, 0x46    /* mov.l .L_xpool_ptr_update_timer, r2 */ ! r2 -> update_timer (sym_06082A40)
    mov.l r4, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x46    /* mov.l .L_xpool_ptr_vtx_ax_src, r2 */   ! r2 -> vtx_ax_src (sym_06082A54)
    mov.l r0, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x45    /* mov.l .L_xpool_ptr_vtx_ay_src, r2 */   ! r2 -> vtx_ay_src (sym_06082A58)
    mov.l r0, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x45    /* mov.l .L_xpool_ptr_vtx_bx_src, r2 */   ! r2 -> vtx_bx_src (sym_06082A44)
    mov.l r0, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x44    /* mov.l .L_xpool_ptr_vtx_by_src, r2 */   ! r2 -> vtx_by_src (sym_06082A48)
    mov.l r0, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x44    /* mov.l .L_xpool_ptr_vtx_c_src, r2 */    ! r2 -> vtx_c_src (sym_06082A50)
    mov.l r0, @r2
    mov r3, r0
    .byte   0xD1, 0x43    /* mov.l .L_xpool_const_0x10, r1 */       ! r1 = 0x10 (bit 4 mask)
    tst r1, r0
    .byte   0x89, 0x10    /* bt 0x0602DDB4 (external) */             ! if zero, skip texture offset calc
    .byte   0xD1, 0x3D    /* mov.l .L_xpool_ptr_vtx_ax_src, r1 */   ! r1 -> vtx_ax_src (re-read record[2])
    mov.l @r1, r1
    .byte   0xD0, 0x42    /* mov.l .L_xpool_ptr_vtx_ax_dst, r0 */   ! r0 -> vtx_ax_dst (sym_06082A70)
    mov.l @r0, r0
    sub r0, r1
    mov r4, r0
    .byte   0xDC, 0x41    /* mov.l .L_xpool_fn_ptr_06034FFC, r12 */ ! r12 = continuation handler fn ptr

/* pre_render_transform -- L3 assembly (SH-2 mnemonics)
 *
 * Pre-render coordinate transform for 4 geometry channels.
 *
 * Reads the player car's world position (X/Y/Z) and heading (yaw),
 * builds a Y-axis rotation matrix from the heading, then transforms
 * each of the 4 geometry channel source vectors through that matrix
 * (mat_vec_transform). After transformation, the car's world-space
 * translation (X/Y/Z) is added to each channel's output vector.
 * Finally the render budget is decremented by 0x30 (48 bytes = 4
 * transformed 3x4 matrix slots consumed).
 *
 * Called once per frame during the pre-render phase to position the
 * four geometry sub-objects (car body parts) relative to the camera.
 *
 * Calls: sym_06026DBC (render state init), sym_06026E0C (render
 *        state push), mat_rot_y, mat_vec_transform (x4)
 */

    .section .text.FUN_060061C8


    .global pre_render_transform
    .type pre_render_transform, @function
pre_render_transform:
    mov.l r14, @-r15                    ! save r14 (callee-saved)
    mov.l r13, @-r15                    ! save r13 (callee-saved)
    mov.l r12, @-r15                    ! save r12 (callee-saved)
    mov.l r11, @-r15                    ! save r11 (callee-saved)
    sts.l pr, @-r15                     ! save return address
    mov.l   _pool_car_struct_ptr, r11   ! r11 = &car_struct_ptr
    mov.l   _pool_fn_render_init, r3    ! r3 = render_state_init
    mov.l @r11, r11                     ! r11 = car struct base
    mov.l @(16, r11), r14               ! r14 = car.pos_x (world X)
    mov.l @(20, r11), r13               ! r13 = car.pos_y (world Y)
    jsr @r3                             ! call render_state_init()
    mov.l @(24, r11), r12               ! r12 = car.pos_z (world Z)  [delay slot]
    mov.l   _pool_fn_render_push, r3    ! r3 = render_state_push
    jsr @r3                             ! call render_state_push()
    nop                                 ! (delay slot)
    mov.l   _pool_fn_mat_rot_y, r3      ! r3 = mat_rot_y
    jsr @r3                             ! build Y rotation matrix from heading
    mov.l @(48, r11), r4                ! r4 = car.heading (yaw angle)  [delay slot]
    mov.l   _pool_fn_mat_vec_xform, r11 ! r11 = mat_vec_transform (reuse r11)
    mov.l   _pool_geom_ch0_out, r5      ! r5 = dest: geom channel 0 output XYZ
    mov.l   _pool_geom_ch0_src, r4      ! r4 = src: geom channel 0 source vector
    jsr @r11                            ! mat_vec_transform(src_ch0, dst_ch0)
    nop                                 ! (delay slot)
    mov.l   _pool_geom_ch1_out, r5      ! r5 = dest: geom channel 1 output XYZ
    mov.l   _pool_geom_ch1_src, r4      ! r4 = src: geom channel 1 source vector
    jsr @r11                            ! mat_vec_transform(src_ch1, dst_ch1)
    nop                                 ! (delay slot)
    mov.l   _pool_geom_ch2_out, r5      ! r5 = dest: geom channel 2 output XYZ
    mov.l   _pool_geom_ch2_src, r4      ! r4 = src: geom channel 2 source vector
    jsr @r11                            ! mat_vec_transform(src_ch2, dst_ch2)
    nop                                 ! (delay slot)
    mov.l   _pool_geom_ch3_out, r5      ! r5 = dest: geom channel 3 output XYZ
    mov.l   _pool_geom_ch3_src, r4      ! r4 = src: geom channel 3 source vector
    jsr @r11                            ! mat_vec_transform(src_ch3, dst_ch3)
    nop                                 ! (delay slot)
    ! --- Apply world translation to channel 0 ---
    mov.l   _pool_geom_ch0_out, r4      ! r4 = &geom_ch0_out[X]
    mov.l @r4, r2                       ! r2 = ch0_out.x
    add r14, r2                         ! r2 += car.pos_x
    mov.l r2, @r4                       ! ch0_out.x = rotated_x + car.pos_x
    mov.l r13, @(4, r4)                 ! ch0_out.y = car.pos_y (replace Y directly)
    mov.l @(8, r4), r3                  ! r3 = ch0_out.z
    add r12, r3                         ! r3 += car.pos_z
    mov.l r3, @(8, r4)                  ! ch0_out.z = rotated_z + car.pos_z
    ! --- Apply world translation to channel 1 ---
    mov.l   _pool_geom_ch1_out, r4      ! r4 = &geom_ch1_out[X]
    mov.l @r4, r2                       ! r2 = ch1_out.x
    add r14, r2                         ! r2 += car.pos_x
    mov.l r2, @r4                       ! ch1_out.x = rotated_x + car.pos_x
    mov.l r13, @(4, r4)                 ! ch1_out.y = car.pos_y
    mov.l @(8, r4), r3                  ! r3 = ch1_out.z
    add r12, r3                         ! r3 += car.pos_z
    mov.l r3, @(8, r4)                  ! ch1_out.z = rotated_z + car.pos_z
    ! --- Apply world translation to channel 2 ---
    mov.l   _pool_geom_ch2_out, r4      ! r4 = &geom_ch2_out[X]
    mov.l @r4, r2                       ! r2 = ch2_out.x
    add r14, r2                         ! r2 += car.pos_x
    mov.l r2, @r4                       ! ch2_out.x = rotated_x + car.pos_x
    mov.l r13, @(4, r4)                 ! ch2_out.y = car.pos_y
    mov.l @(8, r4), r3                  ! r3 = ch2_out.z
    add r12, r3                         ! r3 += car.pos_z
    mov.l r3, @(8, r4)                  ! ch2_out.z = rotated_z + car.pos_z
    ! --- Apply world translation to channel 3 ---
    mov.l   _pool_geom_ch3_out, r4      ! r4 = &geom_ch3_out[X]
    mov.l @r4, r2                       ! r2 = ch3_out.x
    add r14, r2                         ! r2 += car.pos_x
    mov.l r2, @r4                       ! ch3_out.x = rotated_x + car.pos_x
    mov.l r13, @(4, r4)                 ! ch3_out.y = car.pos_y
    mov.l @(8, r4), r3                  ! r3 = ch3_out.z
    add r12, r3                         ! r3 += car.pos_z
    mov.l r3, @(8, r4)                  ! ch3_out.z = rotated_z + car.pos_z
    ! --- Decrement render budget ---
    mov.l   _pool_render_budget, r4     ! r4 = &render_budget
    mov.l @r4, r2                       ! r2 = current budget
    add #-0x30, r2                      ! r2 -= 0x30 (48 bytes consumed)
    mov.l r2, @r4                       ! store updated budget
    ! --- Epilogue ---
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! restore r14  [delay slot]
    .2byte  0xFFFF                      ! padding
_pool_car_struct_ptr:
    .4byte  sym_0607E940                ! -> car struct pointer (indirect)
_pool_fn_render_init:
    .4byte  sym_06026DBC                ! -> render state initialization fn
_pool_fn_render_push:
    .4byte  sym_06026E0C                ! -> render state push/save fn
_pool_fn_mat_rot_y:
    .4byte  mat_rot_y                   ! -> Y-axis rotation matrix builder
_pool_fn_mat_vec_xform:
    .4byte  mat_vec_transform           ! -> matrix-vector transform fn
_pool_geom_ch0_out:
    .4byte  sym_06063E9C                ! -> geom channel 0 output position XYZ
_pool_geom_ch0_src:
    .4byte  sym_0604464C                ! -> geom channel 0 source vector
_pool_geom_ch1_out:
    .4byte  sym_06063EB0                ! -> geom channel 1 output position XYZ
_pool_geom_ch1_src:
    .4byte  sym_06044640                ! -> geom channel 1 source vector
_pool_geom_ch2_out:
    .4byte  sym_06063ED8                ! -> geom channel 2 output position XYZ
_pool_geom_ch2_src:
    .4byte  sym_06044658                ! -> geom channel 2 source vector
_pool_geom_ch3_out:
    .4byte  sym_06063EC4                ! -> geom channel 3 output position XYZ
_pool_geom_ch3_src:
    .4byte  sym_06044664                ! -> geom channel 3 source vector
_pool_render_budget:
    .4byte  sym_06089EDC                ! -> render budget counter (32-bit)

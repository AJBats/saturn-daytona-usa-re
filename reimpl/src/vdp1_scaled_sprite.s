/* vdp1_scaled_sprite -- VDP1 scaled sprite command builder
 * Translation unit: 0x0602DC68 - 0x0602DDA0
 *
 * Two entry points:
 *
 *   vdp1_scaled_sprite (FUN_0602DC68):
 *     Called via the VDP1 command builder pipeline. Invokes disp_init_setup
 *     through r13 to refresh display state, then writes render_state_byte=1
 *     (scaled sprite mode). Reads the camera smoothed heading parameter
 *     (sym_06063EEC+4) and clamps it against a per-attract-cycle limit from
 *     the cmd_limit_table (sym_0602ECAC), stepping by 256 if under the max.
 *     Then checks whether the car struct pointer (sym_0607E940[2]) is null.
 *     If null, marks rendering as inactive: cmd_state_byte=-1,
 *     render_state_byte=2, render_mode=1.
 *
 *   loc_0602DD10 (VDP1 command data reader):
 *     Shared tail used by normal sprite, scaled sprite, and distorted sprite
 *     builders. Looks up the attract cycle counter to select a dispatch table
 *     entry (sym_0602ECBC), then indexes by the cmd_slot_counter
 *     (sym_06082A38 * 32) to read an 8-longword VDP1 command record.
 *     If the first word is -1 (end sentinel), resets the slot counter and
 *     sets render_mode=3 (done). Otherwise sets render_mode=2, then copies
 *     7 record fields into the scene parameter state block (sym_06082A3C
 *     through sym_06082A50). These same addresses are later read by the
 *     distorted sprite interpolator as dirty_flags, update_timer, and
 *     vertex source coordinates. Finally tests bit 4 of the control word;
 *     if set, computes a relative texture offset and loads a continuation
 *     handler into r12 for further processing (external .byte tail).
 */

    .section .text.FUN_0602DC68


    .global vdp1_scaled_sprite
    .type vdp1_scaled_sprite, @function
vdp1_scaled_sprite:
    sts.l pr, @-r15              ! save PR (call to disp_init_setup below)
    jsr @r13                     ! call disp_init_setup (passed in r13 by caller)
    nop
    lds.l @r15+, pr              ! restore PR
    nop
    mov.l   .L_ptr_render_state_byte, r1 ! r1 -> render_state_byte (sym_06082A26)
    mov.l   .L_const_scaled_mode, r0     ! r0 = 0x1 (scaled sprite mode)
    mov.b r0, @r1               ! render_state_byte = 1
    mov.l   .L_ptr_camera_param_b, r1    ! r1 -> camera param B base (sym_06063EEC)
    mov.l   .L_cam_param_offset, r2      ! r2 = 0x4
    add r2, r1                   ! r1 -> camera_param_b[1] (dword at +4)
    mov.l @r1, r2                ! r2 = current camera value
    mov.l   .L_ptr_attract_cycle, r3     ! r3 -> attract cycle counter
    mov.l @r3, r3                ! r3 = attract_cycle (0/1/2)
    shll2 r3                     ! r3 *= 4 (index into longword table)
    mov.l   .L_ptr_cmd_limit_table, r0   ! r0 -> cmd limit table base
    mov.l @(r0, r3), r0          ! r0 = cmd_limit_table[attract_cycle]
    cmp/gt r2, r0                ! limit > camera_value?
    bf      .L_store_limit       ! if not, store limit as-is (clamp to max)
    mov.l   .L_cmd_limit_step, r3        ! r3 = 0x100 (256 step)
    add r3, r2                   ! r2 = camera_value + 256
    cmp/gt r2, r0                ! limit > (camera_value + 256)?
    bf      .L_store_limit       ! if not, store the incremented value
    mov.l r2, @r1                ! camera_param_b[1] = camera_value + 256
    bra     .L_check_car_ptr     ! skip store_limit path
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
    mov.l r0, @r1                ! camera_param_b[1] = limit (clamped)
.L_check_car_ptr:
    mov.l   .L_ptr_car_struct, r0        ! r0 -> car struct pointer
    mov.l @r0, r0                ! r0 = car struct base address
    mov.l   .L_car_field_offset, r1      ! r1 = 0x8
    mov.l @(r0, r1), r4          ! r4 = car_struct[2] (VDP1 draw pointer)
    mov.l   .L_const_null, r1    ! r1 = 0x0
    cmp/eq r1, r4                ! car draw pointer == NULL?
    bf      .L_return            ! if non-null, car is active — return
    ! --- car has no draw data: mark rendering as inactive ---
    mov.l   .L_ptr_cmd_state_byte, r4    ! r4 -> cmd_state_byte (sym_06082A24)
    mov.l   .L_const_neg_one, r1         ! r1 = 0xFF (-1)
    mov.b r1, @r4               ! cmd_state_byte = -1 (inactive)
    mov.l   .L_ptr_render_state_byte_b, r4 ! r4 -> render_state_byte
    mov.l   .L_const_mode_two, r1        ! r1 = 0x2
    mov.b r1, @r4               ! render_state_byte = 2 (skip mode)
    mov.l   .L_ptr_render_mode, r4       ! r4 -> render_mode (sym_06082A30)
    mov.l   .L_const_mode_one, r1        ! r1 = 0x1
    mov.l r1, @r4               ! render_mode = 1 (idle)
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
    mov.l   .L_ptr_attract_cycle_b, r3   ! r3 -> attract cycle counter
    mov.l @r3, r3                ! r3 = attract_cycle (0/1/2)
    shll2 r3                     ! r3 *= 4 (index into longword table)
    mov.l   .L_ptr_cmd_dispatch_table, r0 ! r0 -> cmd dispatch table (sym_0602ECBC)
    mov.l @(r0, r3), r1          ! r1 = dispatch_table[attract_cycle] (cmd list base)
    mov.l   .L_ptr_cmd_slot_counter, r0   ! r0 -> cmd slot counter
    mov.l @r0, r0                ! r0 = slot index
    shll2 r0                     ! r0 *= 4
    shll2 r0                     ! r0 *= 16
    shll r0                      ! r0 *= 32 (each cmd record = 32 bytes / 8 longwords)
    add r0, r1                   ! r1 -> cmd_list_base + slot * 32
    mov.l @r1+, r3               ! r3 = first longword of cmd record; r1 advances
    mov.l   .L_end_of_list_sentinel, r0   ! r0 = 0xFFFFFFFF (end sentinel)
    cmp/eq r0, r3                ! end of command list?
    bf      .L_process_cmd_data  ! if not end, process this record
    ! --- end of list: reset slot counter, signal done ---
    mov.l   .L_ptr_cmd_slot_counter, r1   ! r1 -> cmd slot counter
    mov.l   .L_const_zero, r0    ! r0 = 0
    mov.l r0, @r1               ! cmd_slot_counter = 0 (reset)
    mov.l   .L_ptr_render_mode_b, r0      ! r0 -> render_mode (sym_06082A30)
    mov.l   .L_const_state_done, r1       ! r1 = 3
    mov.l r1, @r0               ! render_mode = 3 (done)
    rts                          ! return — list exhausted
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
    ! --- Store record fields into scene parameter state block ---
    ! r1 points to record[1] (already read record[0] into r3 above)
    ! r3 = record[0] (control word / dirty_flags when read later)
    ! Pool entries below are cross-section refs into vdp1_distorted_sprite's pool
    .byte   0xD0, 0x46    /* mov.l .L_xpool_ptr_render_mode, r0 */  ! r0 -> render_mode (sym_06082A30)
    .byte   0xD2, 0x47    /* mov.l .L_xpool_const_0x2, r2 */        ! r2 = 0x2
    mov.l r2, @r0               ! render_mode = 2 (active)
    .byte   0xD2, 0x47    /* mov.l .L_xpool_ptr_dirty_flags, r2 */  ! r2 -> dirty_flags (sym_06082A3C)
    mov.l r3, @r2               ! dirty_flags = record[0]
    mov.l @r1+, r4              ! r4 = record[1]; r1 -> record[2]
    .byte   0xD2, 0x46    /* mov.l .L_xpool_ptr_update_timer, r2 */ ! r2 -> update_timer (sym_06082A40)
    mov.l r4, @r2               ! update_timer = record[1]
    mov.l @r1+, r0              ! r0 = record[2]
    .byte   0xD2, 0x46    /* mov.l .L_xpool_ptr_vtx_ax_src, r2 */   ! r2 -> vtx_ax_src (sym_06082A54)
    mov.l r0, @r2               ! vtx_ax_src = record[2]
    mov.l @r1+, r0              ! r0 = record[3]
    .byte   0xD2, 0x45    /* mov.l .L_xpool_ptr_vtx_ay_src, r2 */   ! r2 -> vtx_ay_src (sym_06082A58)
    mov.l r0, @r2               ! vtx_ay_src = record[3]
    mov.l @r1+, r0              ! r0 = record[4]
    .byte   0xD2, 0x45    /* mov.l .L_xpool_ptr_vtx_bx_src, r2 */   ! r2 -> vtx_bx_src (sym_06082A44)
    mov.l r0, @r2               ! vtx_bx_src = record[4]
    mov.l @r1+, r0              ! r0 = record[5]
    .byte   0xD2, 0x44    /* mov.l .L_xpool_ptr_vtx_by_src, r2 */   ! r2 -> vtx_by_src (sym_06082A48)
    mov.l r0, @r2               ! vtx_by_src = record[5]
    mov.l @r1+, r0              ! r0 = record[6]
    .byte   0xD2, 0x44    /* mov.l .L_xpool_ptr_vtx_c_src, r2 */    ! r2 -> vtx_c_src (sym_06082A50)
    mov.l r0, @r2               ! vtx_c_src = record[6]
    ! --- Check bit 4 of control word for texture offset processing ---
    mov r3, r0                   ! r0 = record[0] (control word)
    .byte   0xD1, 0x43    /* mov.l .L_xpool_const_0x10, r1 */       ! r1 = 0x10 (bit 4 mask)
    tst r1, r0                  ! control_word & 0x10 == 0?
    .byte   0x89, 0x10    /* bt 0x0602DDB4 (external) */             ! if zero, skip texture offset calc
    .byte   0xD1, 0x3D    /* mov.l .L_xpool_ptr_vtx_ax_src, r1 */   ! r1 -> vtx_ax_src (re-read record[2])
    mov.l @r1, r1               ! r1 = vtx_ax_src value (texture source addr)
    .byte   0xD0, 0x42    /* mov.l .L_xpool_ptr_vtx_ax_dst, r0 */   ! r0 -> vtx_ax_dst (sym_06082A70)
    mov.l @r0, r0               ! r0 = vtx_ax_dst (base address)
    sub r0, r1                  ! r1 = texture_src - base (relative offset)
    mov r4, r0                  ! r0 = record[1] (saved from earlier)
    .byte   0xDC, 0x41    /* mov.l .L_xpool_fn_ptr_06034FFC, r12 */ ! r12 = continuation handler fn ptr

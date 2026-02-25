/* vdp1_distorted_sprite -- VDP1 distorted sprite vertex interpolation
 * Translation unit: 0x0602DE62 - 0x0602E07A
 *
 * Main entry: vdp1_distorted_sprite (FUN_0602DE62, 536B)
 * Tail stub: loc_0602E078 (loads function pointer into r13)
 *
 * Called as part of the VDP1 command builder pipeline. First invokes
 * car_param_lookup via r13 to refresh car/scene parameters, then reads
 * a countdown timer (vertex_update_timer at sym_06082A40). If the timer
 * is zero, the function skips to a "no update needed" path that increments
 * an auxiliary counter and branches back to the command list builder.
 *
 * When updates are needed, the function decrements the timer and examines
 * a 5-bit dirty mask (vertex_dirty_flags at sym_06082A3C). Each bit
 * controls interpolation of one scene parameter channel:
 *
 *   bit 4 (0x10): vertex A X — source sym_06082A54 → dest sym_06082A70
 *   bit 3 (0x08): vertex A Y — source sym_06082A58 → dest sym_06082A78
 *   bit 2 (0x04): vertex B X — source sym_06082A44 → dest sym_06063EEC
 *   bit 1 (0x02): vertex B Y — source sym_06082A48 → dest sym_06063EF0
 *   bit 0 (0x01): vertex C   — source sym_06082A50 → dest sym_06063E24
 *
 * For each active channel, the code performs wrap-aware clamping:
 *   - If source >= dest: clamp so dest doesn't exceed source + wrap_size
 *   - If source <  dest: clamp so dest doesn't drop below source - wrap_size
 * The wrap_size for each channel is stored at a separate address
 * (sym_06082A6C/74/5C/60/68 respectively).
 *
 * This creates smooth interpolation of distorted sprite vertex positions
 * across frames, preventing sudden jumps while respecting wrap boundaries.
 */

    .section .text.FUN_0602DE62


    .global vdp1_distorted_sprite
    .type vdp1_distorted_sprite, @function
vdp1_distorted_sprite:
    sts.l pr, @-r15                          ! save return address on stack
    jsr @r13                                 ! call car_param_lookup (loaded into r13 by caller)
    nop                                      ! (delay slot)
    lds.l @r15+, pr                          ! restore return address from stack
    nop                                      ! (pipeline flush)
    .byte   0xD2, 0x05    /* mov.l .L_ptr_vtx_update_timer, r2 */ ! r2 = &vtx_update_timer (sym_06082A40)
    mov.l @r2, r0                            ! r0 = vtx_update_timer value
    tst r0, r0                               ! test if timer == 0
    bf      .L_update_active                 ! if timer != 0 → process vertex updates
    bra     .L_no_update                     ! timer expired → skip to no-update path
    nop                                      ! (delay slot)
    .4byte  sym_06082A30                     ! pool: &render_state (physics/render state)
    .4byte  0x00000002                       ! pool: constant 0x2 (BY dirty bit mask)
    .4byte  sym_06082A3C                     ! pool: &dirty_flags (vertex dirty bit mask)
.L_ptr_vtx_update_timer:
    .4byte  sym_06082A40                     ! pool: &vtx_update_timer (countdown)
    .4byte  sym_06082A54                     ! pool: &vtx_ax_src (vertex A X source)
    .4byte  sym_06082A58                     ! pool: &vtx_ay_src (vertex A Y source)
    .4byte  sym_06082A44                     ! pool: &vtx_bx_src (vertex B X source)
    .4byte  sym_06082A48                     ! pool: &vtx_by_src (vertex B Y source)
    .4byte  sym_06082A50                     ! pool: &vtx_c_src (vertex C source)
    .4byte  0x00000010                       ! pool: constant 0x10 (AX dirty bit mask)
    .4byte  sym_06082A70                     ! pool: &vtx_ax_dst (vertex A X dest)
    .4byte  sym_06034FFC                     ! pool: function ptr (adjacent TU reference)
    .4byte  0x00000000                       ! pool: constant 0x0 (zero)
    .4byte  sym_06082A6C                     ! pool: &vtx_ax_wrap (vertex A X wrap size)
    .4byte  0x00000008                       ! pool: constant 0x8 (AY dirty bit mask)
    .4byte  sym_06082A78                     ! pool: &vtx_ay_dst (vertex A Y dest)
    .4byte  sym_06082A74                     ! pool: &vtx_ay_wrap (vertex A Y wrap size)
    .4byte  0x00000004                       ! pool: constant 0x4 (BX dirty bit mask)
    .4byte  sym_06063EEC                     ! pool: &camera_pitch (BX dest = camera param B)
    .4byte  sym_06082A5C                     ! pool: &vtx_bx_wrap (vertex B X wrap size)
    .4byte  sym_06063EF0                     ! pool: &camera_yaw_ext (BY dest = camera yaw)
    .4byte  sym_06082A60                     ! pool: &vtx_by_wrap (vertex B Y wrap size)
    .4byte  0x00000001                       ! pool: constant 0x1 (C dirty bit mask)
    .4byte  sym_06063E24                     ! pool: &camera_eye_y (C dest = camera eye Y)
    .4byte  sym_06082A68                     ! pool: &vtx_c_wrap (vertex C wrap size)
    .4byte  car_param_lookup                 ! pool: &car_param_lookup function
.L_update_active:
    add #-0x1, r0                            ! decrement timer
    mov.l r0, @r2                            ! store decremented timer back
    .byte   0xD2, 0x09    /* mov.l .L_ptr_dirty_flags, r2 */ ! r2 = &dirty_flags (sym_06082A3C)
    mov.l @r2, r4                            ! r4 = dirty_flags (saved for all channels)
    mov r4, r0                               ! r0 = dirty_flags (for bit testing)
    .byte   0xD1, 0x09    /* mov.l .L_bit_ax, r1 */ ! r1 = 0x10 (AX channel bit)
    tst r1, r0                               ! test if AX bit is set
    bt      .L_ax_done                       ! if AX bit clear → skip AX interpolation
    .byte   0xD0, 0x08    /* mov.l .L_ptr_ax_src, r0 */ ! r0 = &vtx_ax_src (sym_06082A54)
    mov.l @r0, r3                            ! r3 = vtx_ax_src (source coord)
    .byte   0xD1, 0x08    /* mov.l .L_ptr_ax_dst, r1 */ ! r1 = &vtx_ax_dst (sym_06082A70)
    mov.l @r1, r2                            ! r2 = vtx_ax_dst (current dest coord)
    cmp/ge r2, r3                            ! signed compare: src >= dst?
    bt      .L_ax_src_ge_dst                 ! if src >= dst → upper clamp path
    .byte   0xD0, 0x07    /* mov.l .L_ptr_ax_wrap, r0 */ ! r0 = &vtx_ax_wrap (sym_06082A6C)
    mov.l @r0, r0                            ! r0 = wrap_size
    sub r0, r2                               ! r2 = dst - wrap_size (lower bound)
    cmp/ge r3, r2                            ! lower_bound >= src?
    bt      .L_ax_use_dst                    ! if lower_bound >= src → dst is in range, use it
    bra     .L_ax_use_src                    ! src is below lower bound → snap to src
    nop                                      ! (delay slot)
    .2byte  0x0000                           ! (alignment padding)
.L_ptr_dirty_flags:
    .4byte  sym_06082A3C                     ! pool: &dirty_flags
.L_bit_ax:
    .4byte  0x00000010                       ! pool: 0x10 = AX dirty bit mask
.L_ptr_ax_src:
    .4byte  sym_06082A54                     ! pool: &vtx_ax_src
.L_ptr_ax_dst:
    .4byte  sym_06082A70                     ! pool: &vtx_ax_dst
.L_ptr_ax_wrap:
    .4byte  sym_06082A6C                     ! pool: &vtx_ax_wrap (wrap size)
.L_ax_src_ge_dst:                            ! --- AX: source >= dest path ---
    .byte   0xD0, 0x03    /* mov.l .L_ptr_ax_wrap_2, r0 */ ! r0 = &vtx_ax_wrap
    mov.l @r0, r0                            ! r0 = wrap_size
    add r0, r2                               ! r2 = dst + wrap_size (upper bound)
    cmp/ge r2, r3                            ! src >= upper_bound?
    bt      .L_ax_use_dst                    ! if src >= upper_bound → dst is in range, use it
.L_ax_use_src:                               ! --- AX: snap dest to source ---
    mov.l r3, @r1                            ! *vtx_ax_dst = src (snap)
    bra     .L_ax_done                       ! proceed to AY channel
    nop                                      ! (delay slot)
.L_ptr_ax_wrap_2:
    .4byte  sym_06082A6C                     ! pool: &vtx_ax_wrap (wrap size, duplicate)
.L_ax_use_dst:                               ! --- AX: keep dest as-is ---
    mov.l r2, @r1                            ! *vtx_ax_dst = clamped dst
.L_ax_done:                                  ! === Channel AY (bit 3 = 0x08): vertex A Y ===
    mov r4, r0                               ! r0 = dirty_flags (reload from saved r4)
    .byte   0xD1, 0x07    /* mov.l .L_bit_ay, r1 */ ! r1 = 0x8 (AY channel bit)
    tst r1, r0                               ! test if AY bit is set
    bt      .L_ay_done                       ! if AY bit clear → skip AY interpolation
    .byte   0xD0, 0x07    /* mov.l .L_ptr_ay_src, r0 */ ! r0 = &vtx_ay_src (sym_06082A58)
    mov.l @r0, r3                            ! r3 = vtx_ay_src (source coord)
    .byte   0xD1, 0x07    /* mov.l .L_ptr_ay_dst, r1 */ ! r1 = &vtx_ay_dst (sym_06082A78)
    mov.l @r1, r2                            ! r2 = vtx_ay_dst (current dest coord)
    cmp/ge r2, r3                            ! src >= dst?
    bt      .L_ay_src_ge_dst                 ! if src >= dst → upper clamp path
    .byte   0xD0, 0x06    /* mov.l .L_ptr_ay_wrap, r0 */ ! r0 = &vtx_ay_wrap (sym_06082A74)
    mov.l @r0, r0                            ! r0 = wrap_size
    sub r0, r2                               ! r2 = dst - wrap_size (lower bound)
    cmp/ge r3, r2                            ! lower_bound >= src?
    bt      .L_ay_use_dst                    ! if lower_bound >= src → dst in range, use it
    bra     .L_ay_use_src                    ! src below lower bound → snap to src
    nop                                      ! (delay slot)
.L_bit_ay:
    .4byte  0x00000008                       ! pool: 0x8 = AY dirty bit mask
.L_ptr_ay_src:
    .4byte  sym_06082A58                     ! pool: &vtx_ay_src
.L_ptr_ay_dst:
    .4byte  sym_06082A78                     ! pool: &vtx_ay_dst
.L_ptr_ay_wrap:
    .4byte  sym_06082A74                     ! pool: &vtx_ay_wrap (wrap size)
.L_ay_src_ge_dst:                            ! --- AY: source >= dest path ---
    .byte   0xD0, 0x03    /* mov.l .L_ptr_ay_wrap_2, r0 */ ! r0 = &vtx_ay_wrap
    mov.l @r0, r0                            ! r0 = wrap_size
    add r0, r2                               ! r2 = dst + wrap_size (upper bound)
    cmp/ge r2, r3                            ! src >= upper_bound?
    bt      .L_ay_use_dst                    ! if src >= upper_bound → dst in range, use it
.L_ay_use_src:                               ! --- AY: snap dest to source ---
    mov.l r3, @r1                            ! *vtx_ay_dst = src (snap)
    bra     .L_ay_done                       ! proceed to BX channel
    nop                                      ! (delay slot)
.L_ptr_ay_wrap_2:
    .4byte  sym_06082A74                     ! pool: &vtx_ay_wrap (wrap size, duplicate)
.L_ay_use_dst:                               ! --- AY: keep dest as-is ---
    mov.l r2, @r1                            ! *vtx_ay_dst = clamped dst
.L_ay_done:                                  ! === Channel BX (bit 2 = 0x04): vertex B X ===
    mov r4, r0                               ! r0 = dirty_flags (reload from saved r4)
    .byte   0xD1, 0x07    /* mov.l .L_bit_bx, r1 */ ! r1 = 0x4 (BX channel bit)
    tst r1, r0                               ! test if BX bit is set
    bt      .L_bx_done                       ! if BX bit clear → skip BX interpolation
    .byte   0xD0, 0x07    /* mov.l .L_ptr_bx_src, r0 */ ! r0 = &vtx_bx_src (sym_06082A44)
    mov.l @r0, r3                            ! r3 = vtx_bx_src (source coord)
    .byte   0xD1, 0x07    /* mov.l .L_ptr_bx_dst, r1 */ ! r1 = &camera_pitch (sym_06063EEC)
    mov.l @r1, r2                            ! r2 = camera_pitch (current dest coord)
    cmp/ge r2, r3                            ! src >= dst?
    bt      .L_bx_src_ge_dst                 ! if src >= dst → upper clamp path
    .byte   0xD0, 0x06    /* mov.l .L_ptr_bx_wrap, r0 */ ! r0 = &vtx_bx_wrap (sym_06082A5C)
    mov.l @r0, r0                            ! r0 = wrap_size
    sub r0, r2                               ! r2 = dst - wrap_size (lower bound)
    cmp/ge r3, r2                            ! lower_bound >= src?
    bt      .L_bx_use_dst                    ! if lower_bound >= src → dst in range, use it
    bra     .L_bx_use_src                    ! src below lower bound → snap to src
    nop                                      ! (delay slot)
.L_bit_bx:
    .4byte  0x00000004                       ! pool: 0x4 = BX dirty bit mask
.L_ptr_bx_src:
    .4byte  sym_06082A44                     ! pool: &vtx_bx_src
.L_ptr_bx_dst:
    .4byte  sym_06063EEC                     ! pool: &camera_pitch (BX dest)
.L_ptr_bx_wrap:
    .4byte  sym_06082A5C                     ! pool: &vtx_bx_wrap (wrap size)
.L_bx_src_ge_dst:                            ! --- BX: source >= dest path ---
    .byte   0xD0, 0x03    /* mov.l .L_ptr_bx_wrap_2, r0 */ ! r0 = &vtx_bx_wrap
    mov.l @r0, r0                            ! r0 = wrap_size
    add r0, r2                               ! r2 = dst + wrap_size (upper bound)
    cmp/ge r2, r3                            ! src >= upper_bound?
    bt      .L_bx_use_dst                    ! if src >= upper_bound → dst in range, use it
.L_bx_use_src:                               ! --- BX: snap dest to source ---
    mov.l r3, @r1                            ! *camera_pitch = src (snap)
    bra     .L_bx_done                       ! proceed to BY channel
    nop                                      ! (delay slot)
.L_ptr_bx_wrap_2:
    .4byte  sym_06082A5C                     ! pool: &vtx_bx_wrap (wrap size, duplicate)
.L_bx_use_dst:                               ! --- BX: keep dest as-is ---
    mov.l r2, @r1                            ! *camera_pitch = clamped dst
.L_bx_done:                                  ! === Channel BY (bit 1 = 0x02): vertex B Y ===
    mov r4, r0                               ! r0 = dirty_flags (reload from saved r4)
    .byte   0xD1, 0x07    /* mov.l .L_bit_by, r1 */ ! r1 = 0x2 (BY channel bit)
    tst r1, r0                               ! test if BY bit is set
    bt      .L_by_done                       ! if BY bit clear → skip BY interpolation
    .byte   0xD0, 0x07    /* mov.l .L_ptr_by_src, r0 */ ! r0 = &vtx_by_src (sym_06082A48)
    mov.l @r0, r3                            ! r3 = vtx_by_src (source coord)
    .byte   0xD1, 0x07    /* mov.l .L_ptr_by_dst, r1 */ ! r1 = &camera_yaw_ext (sym_06063EF0)
    mov.l @r1, r2                            ! r2 = camera_yaw_ext (current dest coord)
    cmp/ge r2, r3                            ! src >= dst?
    bt      .L_by_src_ge_dst                 ! if src >= dst → upper clamp path
    .byte   0xD0, 0x06    /* mov.l .L_ptr_by_wrap, r0 */ ! r0 = &vtx_by_wrap (sym_06082A60)
    mov.l @r0, r0                            ! r0 = wrap_size
    sub r0, r2                               ! r2 = dst - wrap_size (lower bound)
    cmp/ge r3, r2                            ! lower_bound >= src?
    bt      .L_by_use_dst                    ! if lower_bound >= src → dst in range, use it
    bra     .L_by_use_src                    ! src below lower bound → snap to src
    nop                                      ! (delay slot)
.L_bit_by:
    .4byte  0x00000002                       ! pool: 0x2 = BY dirty bit mask
.L_ptr_by_src:
    .4byte  sym_06082A48                     ! pool: &vtx_by_src
.L_ptr_by_dst:
    .4byte  sym_06063EF0                     ! pool: &camera_yaw_ext (BY dest)
.L_ptr_by_wrap:
    .4byte  sym_06082A60                     ! pool: &vtx_by_wrap (wrap size)
.L_by_src_ge_dst:                            ! --- BY: source >= dest path ---
    .byte   0xD0, 0x03    /* mov.l .L_ptr_by_wrap_2, r0 */ ! r0 = &vtx_by_wrap
    mov.l @r0, r0                            ! r0 = wrap_size
    add r0, r2                               ! r2 = dst + wrap_size (upper bound)
    cmp/ge r2, r3                            ! src >= upper_bound?
    bt      .L_by_use_dst                    ! if src >= upper_bound → dst in range, use it
.L_by_use_src:                               ! --- BY: snap dest to source ---
    mov.l r3, @r1                            ! *camera_yaw_ext = src (snap)
    bra     .L_by_done                       ! proceed to C channel
    nop                                      ! (delay slot)
.L_ptr_by_wrap_2:
    .4byte  sym_06082A60                     ! pool: &vtx_by_wrap (wrap size, duplicate)
.L_by_use_dst:                               ! --- BY: keep dest as-is ---
    mov.l r2, @r1                            ! *camera_yaw_ext = clamped dst
.L_by_done:                                  ! === Channel C (bit 0 = 0x01): vertex C ===
    mov r4, r0                               ! r0 = dirty_flags (reload from saved r4)
    .byte   0xD1, 0x07    /* mov.l .L_bit_c, r1 */ ! r1 = 0x1 (C channel bit)
    tst r1, r0                               ! test if C bit is set
    bt      .L_all_done                      ! if C bit clear → skip C interpolation
    .byte   0xD0, 0x07    /* mov.l .L_ptr_c_src, r0 */ ! r0 = &vtx_c_src (sym_06082A50)
    mov.l @r0, r3                            ! r3 = vtx_c_src (source coord)
    .byte   0xD1, 0x07    /* mov.l .L_ptr_c_dst, r1 */ ! r1 = &camera_eye_y (sym_06063E24)
    mov.l @r1, r2                            ! r2 = camera_eye_y (current dest coord)
    cmp/ge r2, r3                            ! src >= dst?
    bt      .L_c_src_ge_dst                  ! if src >= dst → upper clamp path
    .byte   0xD0, 0x06    /* mov.l .L_ptr_c_wrap, r0 */ ! r0 = &vtx_c_wrap (sym_06082A68)
    mov.l @r0, r0                            ! r0 = wrap_size
    sub r0, r2                               ! r2 = dst - wrap_size (lower bound)
    cmp/ge r3, r2                            ! lower_bound >= src?
    bt      .L_c_use_dst                     ! if lower_bound >= src → dst in range, use it
    bra     .L_c_use_src                     ! src below lower bound → snap to src
    nop                                      ! (delay slot)
.L_bit_c:
    .4byte  0x00000001                       ! pool: 0x1 = C dirty bit mask
.L_ptr_c_src:
    .4byte  sym_06082A50                     ! pool: &vtx_c_src
.L_ptr_c_dst:
    .4byte  sym_06063E24                     ! pool: &camera_eye_y (C dest)
.L_ptr_c_wrap:
    .4byte  sym_06082A68                     ! pool: &vtx_c_wrap (wrap size)
.L_c_src_ge_dst:                             ! --- C: source >= dest path ---
    .byte   0xD0, 0x03    /* mov.l .L_ptr_c_wrap_2, r0 */ ! r0 = &vtx_c_wrap
    mov.l @r0, r0                            ! r0 = wrap_size
    add r0, r2                               ! r2 = dst + wrap_size (upper bound)
    cmp/ge r2, r3                            ! src >= upper_bound?
    bt      .L_c_use_dst                     ! if src >= upper_bound → dst in range, use it
.L_c_use_src:                                ! --- C: snap dest to source ---
    mov.l r3, @r1                            ! *camera_eye_y = src (snap)
    bra     .L_all_done                      ! done with all channels
    nop                                      ! (delay slot)
.L_ptr_c_wrap_2:
    .4byte  sym_06082A68                     ! pool: &vtx_c_wrap (wrap size, duplicate)
.L_c_use_dst:                                ! --- C: keep dest as-is ---
    mov.l r2, @r1                            ! *camera_eye_y = clamped dst
.L_all_done:                                 ! === All channels processed ===
    rts                                      ! return to caller
    nop                                      ! (delay slot)
.L_no_update:                                ! === Timer expired: no vertex update needed ===
    .byte   0xD1, 0x04    /* mov.l .L_ptr_aux_counter, r1 */ ! r1 = &aux_counter (sym_06082A38)
    mov.l @r1, r0                            ! r0 = aux_counter value
    add #0x1, r0                             ! increment aux counter
    mov.l r0, @r1                            ! store incremented aux counter
    .byte   0xD1, 0x03    /* mov.l .L_ptr_render_state, r1 */ ! r1 = &render_state (sym_06082A30)
    .byte   0xD0, 0x03    /* mov.l .L_const_one, r0 */ ! r0 = 0x1
    mov.l r0, @r1                            ! render_state = 1 (signal ready)
    .byte   0xAE, 0x52    /* bra 0x0602DD10 (external) */ ! branch to VDP1 cmd list builder (loc_0602DD10)
    nop                                      ! (delay slot)
.L_ptr_aux_counter:
    .4byte  sym_06082A38                     ! pool: &aux_counter (auxiliary buffer counter)
.L_ptr_render_state:
    .4byte  sym_06082A30                     ! pool: &render_state (physics/render state flag)
.L_const_one:
    .4byte  0x00000001                       ! pool: constant 0x1 (render ready flag)

    .global loc_0602E078
loc_0602E078:                                ! --- Tail stub: loads next function ptr into r13 ---
    .byte   0xDD, 0x12    /* mov.l .L_pool_0602E0C4, r13 */ ! r13 = next cmd builder fn (from adjacent pool)

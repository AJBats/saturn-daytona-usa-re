/* race_utility_calc -- Secondary SH-2 scene render callback (race mode)
 * Translation unit: 0x0600C170 - 0x0600C218
 *
 * Called by the secondary SH-2 main loop (slave_main_loop) via the
 * callback pointer at sym_06063574. This is the race-mode variant;
 * race_utility_fn is its sibling for alternate modes.
 *
 * Pipeline:
 *   1. Reset VDP1 command list (sym_0603C000 = render finalize)
 *   2. Camera setup — dispatches on race_active_flag (sym_06083255):
 *        != 0: scene_render_coord (car-relative camera)
 *        == 0: camera_track_setup (track-relative camera, attract/replay)
 *   3. Render all scene objects (render_scene_loop)
 *   4. Scene grid dispatch — if grid_param_a + grid_param_b == 8:
 *        scene_path_a (standard grid render)
 *      else:
 *        scene_path_b (extended-range grid render)
 *   5. Snapshot frame tick counter (sym_06059F40 -> sym_06059F4C)
 *   6. Write low-16-bit mask to VDP2 special function register (0x21800000)
 *
 * The embedded data table at +0x18..+0x3F is the secondary SH-2 callback
 * registration vector, written by the race init code that stores this
 * function's address into sym_06063574.
 */

    .section .text.FUN_0600C170


    .global race_utility_calc
    .type race_utility_calc, @function
race_utility_calc:
    sts.l pr, @-r15                              ! save return address
    mov.l   .L_ptr_render_finalize, r3           ! r3 = &sym_0603C000 (VDP1 cmd list reset)
    jsr @r3                                      ! call render finalize — clears VDP1 cmd list
    nop                                          ! (delay slot)
    mov.l   .L_ptr_race_active_flag, r0          ! r0 = &sym_06083255 (race active flag byte)
    mov.b @r0, r0                                ! r0 = race_active_flag
    tst r0, r0                                   ! test if race is active
    bt      .L_track_camera_path                 ! if flag == 0: use track-relative camera
    .byte   0xB8, 0xDE    /* bsr 0x0600B340 (external) */  ! call scene_render_coord (car-relative camera)
    nop                                          ! (delay slot)
    bra     .L_camera_done                       ! skip track camera setup
    nop                                          ! (delay slot)
    /* --- secondary SH-2 callback registration vector (10 entries) --- */
    .4byte  race_utility_calc                    ! [+0x18] self-pointer (this callback)
    .4byte  sym_06063574                         ! [+0x1C] callback slot address
    .4byte  0x0000FFFF                           ! [+0x20] low 16-bit mask constant
    .4byte  0x21000000                           ! [+0x24] VDP2 TVMD register (cache-through)
    .4byte  0x02800008                           ! [+0x28] SCU DMA config word
    .4byte  frame_dispatch                       ! [+0x2C] frame dispatch function
    .4byte  scene_post_render                    ! [+0x30] scene post-render function
    .4byte  0x02000000                           ! [+0x34] SCU base address
    .4byte  replay_playback_engine               ! [+0x38] replay playback engine
    .4byte  sym_0607EA98                         ! [+0x3C] game state data pointer
.L_ptr_render_finalize:
    .4byte  sym_0603C000                         ! VDP1 command list reset function
.L_ptr_race_active_flag:
    .4byte  sym_06083255                         ! race active flag (byte): 0 = attract/replay
.L_track_camera_path:
    mov.l   .L_ptr_camera_track_setup, r3        ! r3 = &camera_track_setup
    jsr @r3                                      ! call camera_track_setup (track-relative camera)
    nop                                          ! (delay slot)
.L_camera_done:
    .byte   0xBB, 0xA9    /* bsr 0x0600B914 (external) */  ! call render_scene_loop (render all scene objects)
    nop                                          ! (delay slot)
    mov.l   .L_ptr_grid_param_a, r0              ! r0 = &grid_param_a (scene grid config word A)
    mov.l   .L_ptr_grid_param_b, r3              ! r3 = &grid_param_b (scene grid config word B)
    mov.l @r0, r0                                ! r0 = grid_param_a
    mov.l @r3, r3                                ! r3 = grid_param_b
    add r3, r0                                   ! r0 = grid_param_a + grid_param_b
    cmp/eq #0x8, r0                              ! test if sum == 8 (standard grid mode)
    bf      .L_use_path_b                        ! if sum != 8: use extended-range path B
    mov.l   .L_ptr_scene_path_a, r3              ! r3 = &scene_path_a
    jsr @r3                                      ! call scene_path_a (standard grid render)
    nop                                          ! (delay slot)
    bra     .L_grid_dispatch_done                ! skip path B
    nop                                          ! (delay slot)
.L_use_path_b:
    mov.l   .L_ptr_scene_path_b, r3              ! r3 = &scene_path_b
    jsr @r3                                      ! call scene_path_b (extended-range grid render)
    nop                                          ! (delay slot)
.L_grid_dispatch_done:
    mov.l   .L_ptr_frame_tick, r2                ! r2 = &frame_tick (FRT interrupt counter)
    mov.l   .L_ptr_frame_tick_snapshot, r3       ! r3 = &frame_tick_snapshot (latched copy)
    mov.l @r2, r2                                ! r2 = current frame tick value
    mov.l r2, @r3                                ! snapshot = frame tick (latch for this frame)
    mov.l   .L_mask_low16, r2                    ! r2 = 0x0000FFFF (low 16-bit mask)
    mov.l   .L_ptr_vdp2_special_fn_reg, r3       ! r3 = 0x21800000 (VDP2 special function reg)
    lds.l @r15+, pr                              ! restore return address
    rts                                          ! return to secondary SH-2 main loop
    mov.w r2, @r3                                ! (delay slot) write 0xFFFF to VDP2 special fn reg
    .2byte  0xFFFF                               ! alignment padding
.L_ptr_camera_track_setup:
    .4byte  camera_track_setup                   ! track-relative camera init (attract/replay/pre-race)
.L_ptr_grid_param_a:
    .4byte  sym_06063E1C                         ! scene grid configuration parameter A
.L_ptr_grid_param_b:
    .4byte  sym_06063E20                         ! scene grid configuration parameter B
.L_ptr_scene_path_a:
    .4byte  scene_path_a                         ! standard scene grid render dispatch
.L_ptr_scene_path_b:
    .4byte  scene_path_b                         ! extended-range scene grid render dispatch
.L_ptr_frame_tick:
    .4byte  sym_06059F40                         ! FRT compare-match frame tick counter
.L_ptr_frame_tick_snapshot:
    .4byte  sym_06059F4C                         ! latched frame tick snapshot for this frame
.L_mask_low16:
    .4byte  0x0000FFFF                           ! low 16-bit mask (written to VDP2 special fn)
.L_ptr_vdp2_special_fn_reg:
    .4byte  0x21800000                           ! VDP2 special function register (cache-through)

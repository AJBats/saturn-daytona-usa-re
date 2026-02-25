/* vdp1_init.s -- VDP1 initialization and framebuffer resolution selection
 * Translation unit: 0x0600A140 - 0x0600A392
 *
 * This TU handles VDP1 hardware setup and framebuffer resolution mode
 * selection for Daytona USA on the Sega Saturn.
 *
 * Function catalog:
 *   vdp1_init            -- Clears VDP1 command table and both framebuffer planes.
 *   sym_0600A1F6         -- Selects framebuffer resolution (mode 3 or 4) based on
 *                           vertical line count vs player-mode-dependent thresholds.
 *   sym_0600A33C         -- Selects framebuffer resolution (mode 5-8) based on
 *                           game mode index (0-3).
 *
 * VDP1 memory layout:
 *   0x25C00000 (512KB) -- VRAM: command tables, character patterns, gouraud tables
 *   0x25C80000 (256KB) -- Framebuffer: double-buffered draw/display planes
 *
 * Initialization sequence (vdp1_init):
 *   1. Write 0x80000000 to VRAM[0] -- VDP1 end-of-list command (bit15 = END flag)
 *   2. Clear framebuffer plane A (256KB = 0x10000 longs, 8 bytes/iteration)
 *   3. Trigger buffer swap via display update function
 *   4. Clear framebuffer plane B (same)
 *   5. Trigger buffer swap again to restore original state
 *   Both planes are zeroed to prevent stale graphics on first frame.
 *
 * Resolution selection (sym_0600A1F6):
 *   Reads current vertical line count from state_countdown (sym_0607EBCC) and
 *   compares against threshold pairs that vary by player mode (sym_0607EAD8):
 *     Mode 0 (single): thresholds 196 / 168
 *     Mode 1:          thresholds 647 / 625
 *     Default:         thresholds 430 / 400
 *   Writes mode 3 (high match) or 4 (low match) to fb_res_mode (sym_0605A016).
 *
 * Resolution selection (sym_0600A33C):
 *   Dispatches on game_mode (sym_06063E1C) values 0-3, writing modes 5-8
 *   respectively to fb_res_mode.
 */

    .section .text.FUN_0600A140


    .global vdp1_init
    .type vdp1_init, @function
vdp1_init:
    mov.l r14, @-r15                       ! save r14 (callee-saved) to stack
    sts.l pr, @-r15                        ! save return address to stack
    mov #0x0, r14                          ! r14 = 0 (clear value for framebuffer fill)

    /* Write end-of-list command to VRAM[0] */
    mov.l   _pool_vdp1_end_cmd, r3        ! r3 = 0x80000000 (END flag in command word)
    mov.l   _pool_vdp1_vram_base, r2      ! r2 = 0x25C00000 (VDP1 VRAM base, cache-through)
    mov.l r3, @r2                          ! VRAM[0] = END command — terminate command list

    /* Clear framebuffer plane A: 256KB = 0x10000 longs, 8 bytes per iteration */
    mov.l   _pool_vdp1_fb_base, r5        ! r5 = 0x25C80000 (framebuffer base, cache-through)
    mov.l   _pool_fb_clear_count, r4      ! r4 = 0x10000 (64K iterations, 2 longs each)
.L_clear_plane_a:
    mov r5, r3                             ! r3 = current write address
    add #-0x2, r4                          ! decrement loop counter by 2 (writing 2 longs)
    add #0x4, r5                           ! advance write pointer by 4 bytes
    mov.l r14, @r3                         ! write 0x00000000 to [addr]
    mov r5, r2                             ! r2 = next write address
    add #0x4, r5                           ! advance write pointer by 4 more bytes
    tst r4, r4                             ! test if counter reached zero
    bf/s    .L_clear_plane_a               ! loop if counter != 0
    mov.l r14, @r2                         ! (delay slot) write 0x00000000 to [addr+4]

    /* Trigger buffer swap so we can clear the other plane */
    mov.l   _pool_fb_swap_flag, r3        ! r3 = &fb_swap_request (sym_0605A00C)
    mov.l r14, @r3                         ! clear swap request flag to 0
    mov.l   _pool_display_update_fn, r3   ! r3 = &display_update (sym_06026CE0)
    jsr @r3                                ! call display update — triggers buffer swap
    nop                                    ! (delay slot)
    mov.l   _pool_vblank_phase, r3        ! r3 = &vblank_phase (sym_06059F44)
    mov.l r14, @r3                         ! reset vblank phase to 0

    /* Clear framebuffer plane B (same procedure as plane A) */
    mov.l   _pool_vdp1_fb_base, r5       ! r5 = 0x25C80000 (framebuffer base again)
    mov.l   _pool_fb_clear_count, r4     ! r4 = 0x10000 (64K iterations)
.L_clear_plane_b:
    mov r5, r2                             ! r2 = current write address
    add #-0x2, r4                          ! decrement loop counter by 2
    add #0x4, r5                           ! advance write pointer by 4 bytes
    mov.l r14, @r2                         ! write 0x00000000 to [addr]
    mov r5, r3                             ! r3 = next write address
    add #0x4, r5                           ! advance write pointer by 4 more bytes
    tst r4, r4                             ! test if counter reached zero
    bf/s    .L_clear_plane_b               ! loop if counter != 0
    mov.l r14, @r3                         ! (delay slot) write 0x00000000 to [addr+4]

    /* Trigger second buffer swap to restore original draw/display state */
    mov.l   _pool_fb_swap_flag, r3        ! r3 = &fb_swap_request (sym_0605A00C)
    mov.l r14, @r3                         ! clear swap request flag to 0
    mov.l   _pool_display_update_fn, r3   ! r3 = &display_update (sym_06026CE0)
    jsr @r3                                ! call display update — triggers buffer swap
    nop                                    ! (delay slot)
    mov.l   _pool_vblank_phase, r3        ! r3 = &vblank_phase (sym_06059F44)
    mov.l r14, @r3                         ! reset vblank phase to 0

    lds.l @r15+, pr                        ! restore return address from stack
    rts                                    ! return to caller
    mov.l @r15+, r14                       ! (delay slot) restore r14 from stack
    .2byte  0xFFFF                         ! alignment padding

/* Constant pool -- vdp1_init */
_pool_vdp1_end_cmd:
    .4byte  0x80000000                     ! VDP1 end-of-list command (bit15 = END flag)
_pool_vdp1_vram_base:
    .4byte  0x25C00000                     ! VDP1 VRAM base (cache-through mirror)
_pool_vdp1_fb_base:
    .4byte  0x25C80000                     ! VDP1 framebuffer base (cache-through mirror)
_pool_fb_clear_count:
    .4byte  0x00010000                     ! 64K iterations x 8 bytes = 256KB total
_pool_fb_swap_flag:
    .4byte  sym_0605A00C                   ! &fb_swap_request flag (32-bit)
_pool_display_update_fn:
    .4byte  sym_06026CE0                   ! display update / camera state finalization fn
_pool_vblank_phase:
    .4byte  sym_06059F44                   ! &vblank_phase flag (32-bit)
    .4byte  0xD01B6000                     ! (byte-encoded function — not decoded)
    .4byte  0x600C2008
    .4byte  0x8B08D01A
    .4byte  0x6001600D
    .4byte  0x20088B12
    .4byte  0xD0186002
    .4byte  0x20088B0E
    .4byte  0xD417D318
    .4byte  0x6331633C
    .4byte  0x2430D217
    .4byte  0x6222622C
    .4byte  0x60238041
    .4byte  0xD3156332
    .4byte  0x633C6033
    .4byte  0x8042000B
    .2byte  0x0009

    .global sym_0600A1F6
sym_0600A1F6:
    mov #0x3, r7                           ! r7 = 3 (hi-res mode value)
    mov.l   _pool_line_count_ptr, r5      ! r5 = &state_countdown / line count (sym_0607EBCC)
    mov.l   _pool_fb_res_mode_a, r4       ! r4 = &fb_res_mode (sym_0605A016, 16-bit)
    mov.l   _pool_player_mode_a, r0       ! r0 = &player_mode (sym_0607EAD8)
    mov.l @r0, r0                          ! r0 = player_mode value
    tst r0, r0                             ! test if player_mode == 0
    bf/s    .L_nonzero_player_mode         ! branch if player_mode != 0
    mov #0x4, r6                           ! (delay slot) r6 = 4 (lo-res mode value)

    /* Player mode 0 (single player): thresholds 196 / 168 */
    mov.l @r5, r3                          ! r3 = current line count
    mov.w   DAT_0600a224, r2              ! r2 = 0x00C4 (196 — hi-res threshold)
    cmp/eq r2, r3                          ! compare line count == 196?
    bf      .L_try_single_lo              ! branch if not equal
    exts.w r7, r7                          ! sign-extend mode 3 to longword
    bra     .L_res_select_done             ! jump to return
    mov.w r7, @r4                          ! (delay slot) fb_res_mode = 3
.L_try_single_lo:
    mov.l @r5, r2                          ! r2 = current line count (reload)
    mov.w   _wpool_single_lo_thresh, r3   ! r3 = 0x00A8 (168 — lo-res threshold)
    cmp/eq r3, r2                          ! compare line count == 168?
    bf      .L_single_no_match            ! branch if not equal
    exts.w r6, r6                          ! sign-extend mode 4 to longword
    mov.w r6, @r4                          ! fb_res_mode = 4
.L_single_no_match:
    bra     .L_res_select_done             ! jump to return (no match — leave unchanged)
    nop                                    ! (delay slot)

    .global DAT_0600a224
DAT_0600a224:
    .2byte  0x00C4                         ! single-player hi-res threshold (196 lines)
_wpool_single_lo_thresh:
    .2byte  0x00A8                         ! single-player lo-res threshold (168 lines)
    .4byte  sym_06078635                   ! demo flag (byte)
    .4byte  sym_0607ED8C                   ! special render enable (16-bit)
    .4byte  sym_0605AD00                   ! render state variable
    .4byte  sym_0607ED90                   ! car parameter table (3 bytes)
    .4byte  sym_06063F44                   ! timing word destination
    .4byte  sym_06078868                   ! frame mirror / player sprite index (dword)
    .4byte  sym_0607EAB8                   ! frame output / game variant flag (dword)
_pool_line_count_ptr:
    .4byte  sym_0607EBCC                   ! &state_countdown / vertical line count (32-bit)
_pool_fb_res_mode_a:
    .4byte  sym_0605A016                   ! &fb_res_mode (16-bit display mode selector)
_pool_player_mode_a:
    .4byte  sym_0607EAD8                   ! &player_mode (0=single, 1=versus, 2+=other)
.L_nonzero_player_mode:
    mov.l   _pool_player_mode_b, r0       ! r0 = &player_mode (sym_0607EAD8, reloaded)
    mov.l @r0, r0                          ! r0 = player_mode value
    cmp/eq #0x1, r0                        ! test if player_mode == 1
    bf      .L_default_thresholds          ! branch if not mode 1

    /* Player mode 1 (versus): thresholds 647 / 625 */
    mov.l @r5, r3                          ! r3 = current line count
    mov.w   DAT_0600a2d8, r2              ! r2 = 0x0287 (647 — mode 1 hi-res threshold)
    cmp/eq r2, r3                          ! compare line count == 647?
    bf      .L_try_mode1_lo               ! branch if not equal
    exts.w r7, r7                          ! sign-extend mode 3 to longword
    bra     .L_res_select_done             ! jump to return
    mov.w r7, @r4                          ! (delay slot) fb_res_mode = 3
.L_try_mode1_lo:
    mov.l @r5, r2                          ! r2 = current line count (reload)
    mov.w   _wpool_mode1_lo_thresh, r3    ! r3 = 0x0271 (625 — mode 1 lo-res threshold)
    cmp/eq r3, r2                          ! compare line count == 625?
    bf      .L_mode1_no_match             ! branch if not equal
    exts.w r6, r6                          ! sign-extend mode 4 to longword
    mov.w r6, @r4                          ! fb_res_mode = 4
.L_mode1_no_match:
    bra     .L_res_select_done             ! jump to return (no match — leave unchanged)
    nop                                    ! (delay slot)

    /* Default thresholds (mode 2+): 430 / 400 */
.L_default_thresholds:
    mov.l @r5, r2                          ! r2 = current line count
    mov.w   DAT_0600a2dc, r3              ! r3 = 0x01AE (430 — default hi-res threshold)
    cmp/eq r3, r2                          ! compare line count == 430?
    bf      .L_try_default_lo             ! branch if not equal
    exts.w r7, r7                          ! sign-extend mode 3 to longword
    bra     .L_res_select_done             ! jump to return
    mov.w r7, @r4                          ! (delay slot) fb_res_mode = 3
.L_try_default_lo:
    mov.l @r5, r2                          ! r2 = current line count (reload)
    mov.w   _wpool_default_lo_thresh, r3  ! r3 = 0x0190 (400 — default lo-res threshold)
    cmp/eq r3, r2                          ! compare line count == 400?
    bf      .L_res_select_done             ! branch if not equal — leave unchanged
    exts.w r6, r6                          ! sign-extend mode 4 to longword
    mov.w r6, @r4                          ! fb_res_mode = 4
.L_res_select_done:
    rts                                    ! return to caller
    nop                                    ! (delay slot)
    .4byte  0xE703D515                     ! (byte-encoded function — not decoded)
    .4byte  0xD415D013
    .4byte  0x60028801
    .4byte  0x8F0FE604
    .4byte  0x6252931B
    .4byte  0x32308B02
    .4byte  0x677FA043
    .4byte  0x24716252
    .4byte  0x93153230
    .4byte  0x8B01666F
    .4byte  0x2461A03B
    .4byte  0x0009D009
    .4byte  0x60028802
    .4byte  0x8B366352
    .4byte  0x920A3320
    .4byte  0x8B10677F
    .4byte  0xA0302471

    .global DAT_0600a2d8
DAT_0600a2d8:
    .2byte  0x0287                         ! mode 1 hi-res threshold (647 lines)
_wpool_mode1_lo_thresh:
    .2byte  0x0271                         ! mode 1 lo-res threshold (625 lines)

    .global DAT_0600a2dc
DAT_0600a2dc:
    .2byte  0x01AE                         ! default hi-res threshold (430 lines)
_wpool_default_lo_thresh:
    .2byte  0x0190                         ! default lo-res threshold (400 lines)
    .4byte  0x03710352                     ! (inline data — resolution table entries)
    .4byte  0x03ABFFFF                     ! (inline data + alignment padding)
_pool_player_mode_b:
    .4byte  sym_0607EAD8                   ! &player_mode (0=single, 1=versus, 2+=other)
    .4byte  sym_0607EBCC                   ! &state_countdown / vertical line count (32-bit)
    .4byte  sym_0605A016                   ! &fb_res_mode (16-bit display mode selector)
    .4byte  0x62529338                     ! (byte-encoded function — not decoded)
    .4byte  0x32308B02
    .4byte  0x666FA01B
    .4byte  0x24616252
    .4byte  0x93323230
    .4byte  0x8B02677F
    .4byte  0xA0142471
    .4byte  0x6252932C
    .4byte  0x32308B02
    .4byte  0x666FA00D
    .4byte  0x24616252
    .4byte  0x93263230
    .4byte  0x8B02677F
    .4byte  0xA0062471
    .4byte  0x62529320
    .4byte  0x32308B01
    .4byte  0x666F2461
    .4byte  0x000B0009

    .global sym_0600A33C
sym_0600A33C:
    mov.l   _pool_fb_res_mode_b, r5       ! r5 = &fb_res_mode (sym_0605A016, 16-bit)
    mov.l   _pool_game_mode, r4           ! r4 = &game_mode (sym_06063E1C, 32-bit)
    mov.l @r4, r0                          ! r0 = game_mode value
    tst r0, r0                             ! test if game_mode == 0
    bf      .L_check_mode_1               ! branch if game_mode != 0
    mov #0x5, r3                           ! r3 = 5 (resolution mode for game_mode 0)
    mov.w r3, @r5                          ! fb_res_mode = 5
    bra     .L_mode_select_done            ! jump to return
    nop                                    ! (delay slot)
.L_check_mode_1:
    mov.l @r4, r0                          ! r0 = game_mode value (reload)
    cmp/eq #0x1, r0                        ! test if game_mode == 1
    bf      .L_check_mode_2               ! branch if game_mode != 1
    mov #0x6, r3                           ! r3 = 6 (resolution mode for game_mode 1)
    mov.w r3, @r5                          ! fb_res_mode = 6
    bra     .L_mode_select_done            ! jump to return
    nop                                    ! (delay slot)
.L_check_mode_2:
    mov.l @r4, r0                          ! r0 = game_mode value (reload)
    cmp/eq #0x2, r0                        ! test if game_mode == 2
    bf      .L_check_mode_3               ! branch if game_mode != 2
    mov #0x7, r3                           ! r3 = 7 (resolution mode for game_mode 2)
    mov.w r3, @r5                          ! fb_res_mode = 7
    bra     .L_mode_select_done            ! jump to return
    nop                                    ! (delay slot)
    .2byte  0x0398                         ! (inline data — resolution table entry)

    .global DAT_0600a36c
DAT_0600a36c:
    .2byte  0x036D                         ! data constant (877)

    .global DAT_0600a36e
DAT_0600a36e:
    .2byte  0x0336                         ! data constant (822)

    .global DAT_0600a370
DAT_0600a370:
    .2byte  0x021A                         ! data constant (538)

    .global DAT_0600a372
DAT_0600a372:
    .2byte  0x01B4                         ! data constant (436)
_pool_fb_res_mode_b:
    .4byte  sym_0605A016                   ! &fb_res_mode (16-bit display mode selector)
_pool_game_mode:
    .4byte  sym_06063E1C                   ! &game_mode (32-bit, 0-3)
.L_check_mode_3:
    mov.l @r4, r0                          ! r0 = game_mode value (reload)
    cmp/eq #0x3, r0                        ! test if game_mode == 3
    bf      .L_mode_select_done            ! branch if game_mode != 3 — leave unchanged
    mov #0x8, r3                           ! r3 = 8 (resolution mode for game_mode 3)
    mov.w r3, @r5                          ! fb_res_mode = 8
.L_mode_select_done:
    rts                                    ! return to caller
    nop                                    ! (delay slot)
    .2byte  0xE300                         ! (byte-encoded tail — not decoded)
    .4byte  0xD213000B
    .2byte  0x2232

/* ranking_pts_calc -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06013B04 - 0x06013C20
 *
 * Post-race ranking points calculator and sound trigger.
 *
 * Part of the results screen state machine (dispatch table at sym_0605B6D8).
 * Called once per frame during the "ranking reveal" animation phase.
 *
 * Each frame:
 *   1. Increment 16-bit frame timer (sym_06084AF6)
 *   2. Render 3D scene: obj_render_loop_3d + race_variant_setup_a
 *   3. Timer - 0x1F → section index (bits 9:5), subsection (bits 4:0)
 *   4. Section 3 (final reveal): if sym_06084FB8 != 0, call handler_init_reset;
 *      then dispatch race_variant_b/c/d based on car count (sym_06084FB4),
 *      look up score from position table (sym_0605B294), play sound
 *   5. Sections 0-2: read variant char from sym_06084B14[section],
 *      convert char - 'A' to score table index (sym_0605B0FC),
 *      play sound via sound_cmd_dispatch
 *   6. Section >= 4 → animation complete, exit
 *
 * loc_06013C10: Phase reset stub — sets phase byte (sym_06084AF2) = 7,
 * clears frame timer, falls through to bonus_multiplier.
 */

    .section .text.FUN_06013B04


    .global ranking_pts_calc
    .type ranking_pts_calc, @function
ranking_pts_calc:
    mov.l r14, @-r15                ! save r14
    mov.l r13, @-r15                ! save r13
    mov.l r12, @-r15                ! save r12
    mov.l r11, @-r15                ! save r11
    sts.l pr, @-r15                 ! save return address
    mov.l   _pool_fn_sound_cmd, r11 ! r11 = &sound_cmd_dispatch (kept across calls)
    mov.l   _pool_car_count_ptr, r12 ! r12 = &car_count (sym_06084FB4)
    mov.l   _pool_frame_timer_ptr, r14 ! r14 = &frame_timer (sym_06084AF6)
    mov.w @r14, r3                  ! r3 = current frame timer
    add #0x1, r3                    ! r3++ (advance timer)
    mov.w r3, @r14                  ! write back incremented timer
    .byte   0xB1, 0x8F    /* bsr obj_render_loop_3d */
    nop                             ! delay slot
    .byte   0xB3, 0x25    /* bsr race_variant_setup_a */
    nop                             ! delay slot
    mov.w @r14, r4                  ! r4 = current frame timer value
    extu.w r4, r4                   ! zero-extend to 32-bit
    add #-0x1F, r4                  ! r4 = timer - 0x1F (subtract initial delay)
    cmp/pz r4                       ! timer >= 0x1F?
    bt      .L_timer_ready          ! yes — use adjusted value
    mov #0x0, r4                    ! no — clamp to 0
.L_timer_ready:
    mov r4, r3                      ! r3 = adjusted timer
    mov #0x4, r2                    ! r2 = 4 (max section count)
    shlr2 r3                        ! r3 >>= 2
    shlr2 r3                        ! r3 >>= 2
    shlr r3                         ! r3 >>= 1  → section index = bits[9:5]
    cmp/hs r2, r3                   ! section >= 4?
    bt      .L_epilogue             ! yes — animation complete, exit
    mov #0x1F, r0                   ! r0 = 0x1F (subsection mask)
    and r4, r0                      ! r0 = subsection = bits[4:0]
    cmp/eq #0x1F, r0                ! subsection == 0x1F? (last tick of section)
    bf      .L_epilogue             ! no — not at section boundary, exit
    mov r4, r0                      ! r0 = adjusted timer
    shlr2 r0                        ! r0 >>= 2
    shlr2 r0                        ! r0 >>= 2
    shlr r0                         ! r0 >>= 1  → section index again
    cmp/eq #0x3, r0                 ! section == 3? (final reveal)
    bf      .L_section_0_2          ! no — handle sections 0-2
    mov.l   _pool_final_reveal_flag, r0 ! r0 = &final_reveal_flag (sym_06084FB8)
    mov.w @r0, r0                   ! r0 = flag value (16-bit)
    extu.w r0, r0                   ! zero-extend
    tst r0, r0                      ! flag == 0?
    bt      .L_section_0_2          ! yes — skip handler, use section 0-2 path
    mov.l   _pool_fn_handler_init_reset, r3 ! r3 = &handler_init_reset
    jsr @r3                         ! call handler_init_reset
    nop                             ! delay slot
    mov.l   _pool_sound_base_id, r13 ! r13 = 0xAE1000FF (ranking sound base)
    mov #0x25, r3                   ! r3 = 37 (car count threshold: low)
    mov.l @r12, r2                  ! r2 = car_count
    cmp/hs r3, r2                   ! car_count >= 37?
    bt      .L_check_68_cars        ! yes — check next threshold
    mov.l   _pool_fn_race_variant_b, r3 ! r3 = &race_variant_b (< 37 cars)
    jsr @r3                         ! call race_variant_b
    nop                             ! delay slot
    bra     .L_lookup_score         ! → look up position score
    mov r13, r14                    ! delay: r14 = sound base ID
.L_check_68_cars:
    mov.l @r12, r2                  ! r2 = car_count
    mov #0x44, r3                   ! r3 = 68 (car count threshold: high)
    cmp/hs r3, r2                   ! car_count >= 68?
    bt      .L_variant_d            ! yes — use variant d
    mov.l   _pool_fn_race_variant_c, r3 ! r3 = &race_variant_c (37..67 cars)
    jsr @r3                         ! call race_variant_c
    nop                             ! delay slot
    bra     .L_set_sound_base       ! → set sound base
    nop                             ! delay slot
.L_variant_d:
    mov.l   _pool_fn_race_variant_d, r3 ! r3 = &race_variant_d (>= 68 cars)
    jsr @r3                         ! call race_variant_d
    nop                             ! delay slot
.L_set_sound_base:
    mov r13, r14                    ! r14 = sound base ID (for score merge)
.L_lookup_score:
    mov.l @r12, r5                  ! r5 = car_count (used as position)
    mov.l   _pool_position_score_tbl, r3 ! r3 = &position_score_table (sym_0605B294)
    add #-0x1, r5                   ! r5 = position - 1 (0-based index)
    shll2 r5                        ! r5 *= 4 (long word stride)
    add r3, r5                      ! r5 = &score_table[position - 1]
    mov.l @r5, r5                   ! r5 = score value from table
    shll8 r5                        ! r5 <<= 8 (shift score into upper bits)
    add r14, r5                     ! r5 = sound_base | (score << 8) → full sound cmd
    jsr @r11                        ! call sound_cmd_dispatch
    mov #0x0, r4                    ! delay: r4 = channel 0
    bra     .L_epilogue             ! → exit
    nop                             ! delay slot
    .2byte  0xFFFF                  ! alignment padding
_pool_fn_sound_cmd:
    .4byte  sound_cmd_dispatch
_pool_car_count_ptr:
    .4byte  sym_06084FB4
_pool_frame_timer_ptr:
    .4byte  sym_06084AF6
_pool_final_reveal_flag:
    .4byte  sym_06084FB8
_pool_fn_handler_init_reset:
    .4byte  handler_init_reset
_pool_sound_base_id:
    .4byte  0xAE1000FF              ! ranking reveal sound base ID
_pool_fn_race_variant_b:
    .4byte  race_variant_b
_pool_fn_race_variant_c:
    .4byte  race_variant_c
_pool_fn_race_variant_d:
    .4byte  race_variant_d
_pool_position_score_tbl:
    .4byte  sym_0605B294
.L_section_0_2:
    mov r4, r2                      ! r2 = adjusted timer
    mov #0x3, r3                    ! r3 = 3 (max section for this path)
    shlr2 r2                        ! r2 >>= 2
    shlr2 r2                        ! r2 >>= 2
    shlr r2                         ! r2 >>= 1  → section index
    cmp/hs r3, r2                   ! section >= 3?
    bt      .L_epilogue             ! yes — out of range for this path, exit
    shlr2 r4                        ! r4 >>= 2 (begin section index calc)
    .byte   0xDE, 0x18    /* mov.l _pool_variant_char_tbl, r14 — sym_06084B14 */
    shlr2 r4                        ! r4 >>= 2
    shlr r4                         ! r4 >>= 1  → section index as byte offset
    add r4, r14                     ! r14 = &variant_char_tbl[section]
    mov.b @r14, r14                 ! r14 = variant char (e.g. 'A', 'B', ...)
    extu.b r14, r14                 ! zero-extend byte to 32-bit
    add #-0x41, r14                 ! r14 -= 'A' → 0-based score table index
    cmp/pz r14                      ! index >= 0? (valid char >= 'A')
    bf      .L_default_sound        ! no — use default sound
    mov r14, r5                     ! r5 = score table index
    shll2 r5                        ! r5 *= 4 (long word stride)
    .byte   0xD3, 0x14    /* mov.l _pool_score_tbl, r3 — sym_0605B0FC */
    add r3, r5                      ! r5 = &score_table[index]
    bra     .L_play_sound           ! → play the looked-up sound
    mov.l @r5, r5                   ! delay: r5 = score/sound value from table
.L_default_sound:
    .byte   0xD5, 0x13    /* mov.l _pool_default_sound_id, r5 — 0xAB1102FF */
.L_play_sound:
    jsr @r11                        ! call sound_cmd_dispatch(channel=0, cmd=r5)
    mov #0x0, r4                    ! delay: r4 = channel 0
.L_epilogue:
    lds.l @r15+, pr                 ! restore return address
    mov.l @r15+, r11                ! restore r11
    mov.l @r15+, r12                ! restore r12
    mov.l @r15+, r13                ! restore r13
    rts                             ! return
    mov.l @r15+, r14                ! delay: restore r14

    .global loc_06013C10
loc_06013C10:
    mov #0x7, r3                    ! r3 = 7 (next phase ID)
    .byte   0xD2, 0x0F    /* mov.l _pool_phase_byte, r2 — &sym_06084AF2 */
    mov.b r3, @r2                   ! phase_byte = 7 (advance to bonus phase)
    mov #0x0, r3                    ! r3 = 0
    .byte   0xD2, 0x0E    /* mov.l _pool_frame_timer, r2 — &sym_06084AF6 */
    mov.w r3, @r2                   ! frame_timer = 0 (reset for next phase)
    .byte   0xA0, 0x00    /* bra bonus_multiplier (falls through) */
    nop                             ! delay slot

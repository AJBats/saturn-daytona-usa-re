/* mode_select_handler — Mode Select menu controller
 * Translation unit: 0x060196B0 - 0x060197F4
 *
 * Runs every frame while the Mode Select screen is active
 * (ARCADE MODE / SATURN MODE / RANKING / OPTIONS).
 *
 * Input → State → Dispatch:
 *   1. Calls scene_dual_finalize()
 *   2. Reads button state at sym_06063D98+2:
 *      - Confirm (0x0100): transition to next screen
 *      - DOWN (0x2000): increment selection index (wraps 4 → 0)
 *      - UP (0x1000): decrement selection index (wraps -1 → 3)
 *   3. Tail-calls per-item renderer via 4-entry dispatch table
 *
 * Callee-saved registers:
 *   r10 = &sym_06085FF1 (flag byte — set on confirm and direction input)
 *   r11 = 0 (inherited from caller, used as zero constant)
 *   r12 = &sym_0605D242 (counter byte, incremented each frame)
 *   r13 = 1 (constant)
 *   r14 = &sym_0605D244 (mode selection index, 0-3)
 */

    .section .text.FUN_060196B0


    .global mode_select_handler
    .type mode_select_handler, @function
mode_select_handler:
    sts.l pr, @-r15                              ! save return address
    add #-0xC, r15                               ! allocate 12-byte stack frame
    mov.l   _pool_flag_byte, r10                 ! r10 -> &sym_06085FF1
    mov.l   _pool_counter_byte, r12              ! r12 -> &sym_0605D242
    mov.l   _pool_mode_select_idx, r14           ! r14 -> &sym_0605D244 (selection index)
    mov.l   _pool_fn_scene_finalize, r3
    jsr @r3                                      ! call scene_dual_finalize()
    mov #0x1, r13                                ! (delay) r13 = 1
    mov.l   _pool_button_state, r4               ! r4 -> button state struct (sym_06063D98)
    mov.w   _wpool_confirm_mask, r3              ! r3 = 0x0100 (confirm button mask)
    mov.w @(2, r4), r0                           ! r0 = button word at +2
    mov r0, r2
    extu.w r2, r2
    and r3, r2                                   ! isolate confirm bit
    tst r2, r2
    bt      .L_no_confirm                        ! not pressed -> check directions
    ! --- Confirm pressed: transition to next screen ---
    mov.b @r14, r7                               ! r7 = selection index (0-3)
    shll r7                                      ! r7 *= 2 (LUT stride)
    mov.l r7, @(8, r15)                          ! save scaled index
    mov.l   _pool_06049AF4, r3                   ! r3 -> lookup table
    mov.l   _pool_06063750, r2                   ! r2 -> object table
    add r3, r7
    mov.w @r7, r7                                ! r7 = LUT entry (16-bit)
    extu.w r7, r7
    shll2 r7
    shll r7                                      ! r7 *= 8 (object table stride)
    add r2, r7                                   ! r7 -> object table entry
    mov.l r7, @(4, r15)
    mov.l @(4, r7), r7                           ! r7 = entry field +4
    mov.w   _wpool_0x2000, r3                    ! r3 = 0x2000
    mov.l @(8, r15), r6
    add r3, r7                                   ! r7 += 0x2000
    mov.l   _pool_06049AEC, r3                   ! r3 -> per-slot param table
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0                           ! byte +1 from param table
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2                                ! byte +0 from param table
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6                                     ! r6 *= 64
    add r2, r6
    shll r6                                      ! r6 *= 2
    mov.l @(4, r15), r5
    mov.l @r5, r5                                ! r5 = entry field +0
    mov.l   _pool_fn_06028400, r3
    jsr @r3                                      ! call sym_06028400(r4=0xC, r5, r6, r7)
    mov #0xC, r4                                 ! (delay) r4 = 0xC
    mov.b @r14, r2                               ! r2 = selection index
    cmp/gt r13, r2                               ! index > 1? (RANKING or OPTIONS)
    bf      .L_skip_idx_reset
    exts.b r11, r2                               ! r2 = 0
    mov.b r2, @r14                               ! reset selection to 0
.L_skip_idx_reset:
    mov.l   _pool_06059F44, r3
    mov.l r11, @r3                               ! clear sym_06059F44 to 0
    extu.b r11, r2
    mov.b r2, @r12                               ! clear counter byte to 0
    mov #0x4, r3
    mov.l   _pool_game_state, r2                 ! r2 -> &sym_0605AD10
    mov.l r3, @r2                                ! game state = 4 (advance)
    exts.b r13, r3                               ! r3 = 1
    mov.b r3, @r10                               ! set flag byte = 1
    mov.l   _pool_06085FF5, r3
    bra     .L_epilog_rts
    mov.b r13, @r3                               ! (delay) set sym_06085FF5 = 1
.L_no_confirm:
    ! --- Check DOWN button (0x2000) ---
    mov.w @(2, r4), r0                           ! re-read button word
    mov.w   _wpool_0x2000, r3                    ! r3 = 0x2000 (DOWN button mask)
    mov r0, r2
    extu.w r2, r2
    and r3, r2                                   ! isolate DOWN bit
    tst r2, r2
    bt/s    .L_check_up                          ! not pressed -> check UP
    mov #0x5, r5                                 ! (delay) r5 = 5
    mov.b r13, @r10                              ! set flag byte = 1
    extu.b r5, r5
    mov.b r5, @r12                               ! counter byte = 5
    mov.b @r14, r2                               ! r2 = selection index
    add #0x1, r2                                 ! r2++ (move cursor down)
    mov.b r2, @r14                               ! write back
    mov.b @r14, r3                               ! r3 = updated index
    mov #0x4, r2
    cmp/ge r2, r3                                ! index >= 4?
    bf      .L_common_exit                       ! no -> exit
    exts.b r11, r2                               ! r2 = 0
    bra     .L_common_exit
    mov.b r2, @r14                               ! (delay) wrap to 0

    .global DAT_06019762
_wpool_confirm_mask:
DAT_06019762:
    .2byte  0x0100
_wpool_0x2000:
    .2byte  0x2000
    .2byte  0xFFFF
_pool_flag_byte:
    .4byte  sym_06085FF1
_pool_counter_byte:
    .4byte  sym_0605D242
_pool_mode_select_idx:
    .4byte  sym_0605D244
_pool_fn_scene_finalize:
    .4byte  scene_dual_finalize
_pool_button_state:
    .4byte  sym_06063D98
_pool_06049AF4:
    .4byte  sym_06049AF4
_pool_06063750:
    .4byte  sym_06063750
_pool_06049AEC:
    .4byte  sym_06049AEC
_pool_fn_06028400:
    .4byte  sym_06028400
_pool_06059F44:
    .4byte  sym_06059F44
_pool_game_state:
    .4byte  sym_0605AD10
_pool_06085FF5:
    .4byte  sym_06085FF5
.L_check_up:
    ! --- Check UP button (0x1000) ---
    mov.w @(2, r4), r0                           ! re-read button word
    .byte   0x93, 0x63    /* mov.w @(disp,PC), r3 — loads 0x1000 (UP button mask) */
    mov r0, r2
    extu.w r2, r2
    and r3, r2                                   ! isolate UP bit
    tst r2, r2
    bt      .L_common_exit                       ! not pressed -> exit
    mov.b r13, @r10                              ! set flag byte = 1
    extu.b r5, r5
    mov.b r5, @r12                               ! counter byte = 5
    mov.b @r14, r2                               ! r2 = selection index
    add #-0x1, r2                                ! r2-- (move cursor up)
    mov.b r2, @r14                               ! write back
    mov.b @r14, r3                               ! r3 = updated index
    cmp/pz r3                                    ! index >= 0?
    bt      .L_common_exit                       ! yes -> exit
    mov #0x3, r3
    mov.b r3, @r14                               ! wrap to 3
.L_common_exit:
    ! --- Every-frame: advance counters, dispatch to per-item renderer ---
    .byte   0xD4, 0x2B    /* mov.l @(disp,PC), r4 — &sym_0605D243 (animation timer) */
    mov.b @r4, r2
    add #0x1, r2                                 ! timer++
    mov.b r2, @r4
    mov.b @r12, r3
    add #0x1, r3                                 ! counter++
    mov.b r3, @r12
    mov.b @r14, r2                               ! r2 = selection index (0-3)
    shll2 r2                                     ! r2 *= 4 (dispatch table stride)
    .byte   0xD3, 0x28    /* mov.l @(disp,PC), r3 — &sym_0605D250 (dispatch table) */
    add r3, r2                                   ! r2 -> &dispatch_table[index]
    mov.l @r2, r2                                ! r2 = function pointer
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    jmp @r2                                      ! tail-call per-item renderer
    mov.l @r15+, r14                             ! (delay)
.L_epilog_rts:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14                             ! (delay)

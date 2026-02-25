/* display_param_set -- VDP1 framebuffer display parameter configuration
 * Translation unit: 0x06038E54 - 0x06038F6C
 *
 * Function catalog:
 *   display_param_set     -- Configure VDP1 framebuffer mode, swap enable,
 *                            and FBCR register bits based on a 16-bit mode word.
 *   display_param_reset   -- Reset all display parameter state variables to
 *                            power-on defaults (called by display_hw_init).
 *
 * Mode word (r4) encoding for display_param_set:
 *   0xFFFF -- "all params on": fb_mode_selector = 2, swap_enable = 0,
 *             FBCR |= 3 (manual change + erase), store mode word
 *   0xFFFE -- "partial on":    fb_mode_selector = 3, swap_enable = 0,
 *             FBCR |= 3 (manual change + erase), store mode word
 *   Other  -- bit 14 (0x4000): if set, swap_enable = 0; if clear, swap_enable = 1
 *             bits [14:0] masked by 0x7FFF: fb_mode value (0/1/2+)
 *             FBCR updated based on fb_mode_selector being zero or nonzero
 *
 * Data symbols referenced:
 *   sym_060635B4  -- VDP framebuffer mode selector (half-word, values 0-3)
 *   sym_060635B8  -- framebuffer swap enable flag (long, 0 or 1)
 *   sym_060635BC  -- current display mode word (long, written from r4)
 *   sym_060635C0  -- per-input frame counter (long)
 *   sym_060635C4  -- game state active flag (long)
 *   sym_060635C8  -- additional display state (long)
 *   sym_060A4C92  -- cached FBCR value / software shadow (half-word)
 *
 * VDP1 FBCR register (0x25D00002):
 *   bit 0 (FCM) -- framebuffer change mode (1 = manual)
 *   bit 1 (FCT) -- framebuffer change trigger
 *   Together 0x3 = manual change + erase trigger
 *
 * Callers:
 *   engine_init_global  -- display_param_set(1)   [startup init]
 *   main_loop_timing    -- display_param_set(0xFFFF) [per-frame enable all]
 */

    .section .text.FUN_06038E54


    .global display_param_set
    .type display_param_set, @function
display_param_set:
    mov.l r14, @-r15                            ! save r14 (callee-saved)
    extu.w r4, r3                               ! r3 = mode word zero-extended to 16 bits
    mov.l r13, @-r15                            ! save r13 (callee-saved)
    mov #0x3, r13                               ! r13 = 0x3 (FBCR mask: FCM + FCT bits)
    mov.l r11, @-r15                            ! save r11 (callee-saved)
    mov.l   .L_ptr_display_mode, r11            ! r11 = &sym_060635BC (current display mode word)
    mov.l   .L_ptr_fbcr_shadow, r14             ! r14 = &sym_060A4C92 (cached FBCR shadow)
    mov.l   .L_vdp1_fbcr, r7                   ! r7 = 0x25D00002 (VDP1 FBCR register)
    mov.l   .L_ptr_fb_mode_sel, r5             ! r5 = &sym_060635B4 (framebuffer mode selector)
    mov.l   .L_ptr_swap_enable, r1             ! r1 = &sym_060635B8 (swap enable flag)
    mov.l   .L_mask_low16, r2                   ! r2 = 0x0000FFFF
    cmp/eq r2, r3                               ! test: mode word == 0xFFFF?
    bf/s    .L_not_all_on                       ! branch if not "all params on" mode
    mov #0x0, r6                                ! r6 = 0 (delay slot: zero constant)

    /* --- Mode 0xFFFF: "all params on" --- */
    mov #0x2, r2                                ! r2 = 2 (fb_mode_selector value for "all on")
    mov.w r2, @r5                               ! fb_mode_selector = 2
    mov.l r6, @r1                               ! swap_enable = 0 (no swap)
    mov.w @r14, r3                              ! r3 = cached FBCR shadow value
    extu.w r3, r3                               ! zero-extend to 32 bits
    or r13, r3                                  ! r3 |= 0x3 (set FCM + FCT bits)
    extu.w r3, r3                               ! keep as 16-bit value
    mov.w r3, @r7                               ! write to VDP1 FBCR register
    extu.w r4, r4                               ! zero-extend mode word
    bra     .L_epilogue                         ! jump to epilogue
    mov.l r4, @r11                              ! delay slot: store mode word to display_mode

.L_not_all_on:
    extu.w r4, r2                               ! r2 = mode word zero-extended
    mov.l   .L_const_fffe, r3                   ! r3 = 0x0000FFFE
    cmp/eq r3, r2                               ! test: mode word == 0xFFFE?
    bf      .L_not_partial_on                   ! branch if not "partial on" mode

    /* --- Mode 0xFFFE: "partial on" --- */
    extu.w r13, r3                              ! r3 = 3 (fb_mode_selector value for "partial")
    mov.w r3, @r5                               ! fb_mode_selector = 3
    mov.l r6, @r1                               ! swap_enable = 0 (no swap)
    mov.w @r14, r2                              ! r2 = cached FBCR shadow value
    extu.w r2, r2                               ! zero-extend to 32 bits
    or r13, r2                                  ! r2 |= 0x3 (set FCM + FCT bits)
    extu.w r2, r2                               ! keep as 16-bit value
    mov.w r2, @r7                               ! write to VDP1 FBCR register
    extu.w r4, r4                               ! zero-extend mode word
    bra     .L_epilogue                         ! jump to epilogue
    mov.l r4, @r11                              ! delay slot: store mode word to display_mode

.L_not_partial_on:
    /* --- Generic mode: decode bit fields --- */
    extu.w r4, r2                               ! r2 = mode word zero-extended
    mov.w   DAT_06038efa, r3                    ! r3 = 0x4000 (bit 14 mask: swap control bit)
    and r3, r2                                  ! r2 = mode_word & 0x4000
    tst r2, r2                                  ! test: is bit 14 clear?
    bt      .L_swap_enable_set                  ! if bit 14 clear, set swap_enable = 1
    bra     .L_swap_done                        ! bit 14 set: skip (swap_enable stays 0)
    mov.l r6, @r1                               ! delay slot: swap_enable = 0

.L_swap_enable_set:
    mov #0x1, r2                                ! r2 = 1
    mov.l r2, @r1                               ! swap_enable = 1 (enable framebuffer swap)

.L_swap_done:
    mov.w   DAT_06038efc, r3                    ! r3 = 0x7FFF (mask: bits [14:0])
    and r3, r4                                  ! r4 = mode_word & 0x7FFF (strip bit 15)
    extu.w r4, r4                               ! zero-extend result
    tst r4, r4                                  ! test: fb_mode value == 0?
    bt      .L_fb_mode_zero                     ! branch if fb_mode is zero

    /* --- fb_mode nonzero: determine fb_mode_selector (1 or 2) --- */
    extu.w r4, r0                               ! r0 = fb_mode value
    cmp/eq #0x1, r0                             ! test: fb_mode == 1?
    bf      .L_fb_mode_not_one                  ! branch if not 1
    bra     .L_write_fb_mode_sel                ! fb_mode == 1: selector = 0
    extu.w r6, r2                               ! delay slot: r2 = 0 (selector for mode 1)

.L_fb_mode_not_one:
    mov #0x1, r2                                ! r2 = 1 (selector for mode >= 2)

.L_write_fb_mode_sel:
    bra     .L_store_mode_and_check             ! jump to store fb_mode_selector
    mov.w r2, @r5                               ! delay slot: fb_mode_selector = r2

.L_fb_mode_zero:
    extu.w r6, r2                               ! r2 = 0
    mov.w r2, @r5                               ! fb_mode_selector = 0

.L_store_mode_and_check:
    extu.w r4, r4                               ! zero-extend fb_mode value
    mov.l r4, @r11                              ! store mode word to display_mode
    mov.w @r5, r3                               ! r3 = fb_mode_selector we just wrote
    extu.w r3, r3                               ! zero-extend
    tst r3, r3                                  ! test: fb_mode_selector == 0?
    bf      .L_fbcr_set_manual                  ! branch if nonzero (need FCM+FCT bits)

    /* --- fb_mode_selector == 0: write FBCR shadow as-is (no manual change) --- */
    mov.w @r14, r3                              ! r3 = cached FBCR shadow value
    mov.w r3, @r7                               ! write FBCR shadow directly to VDP1 FBCR
    bra     .L_epilogue                         ! jump to epilogue
    nop                                         ! (delay slot: no-op)

.L_fbcr_set_manual:
    /* --- fb_mode_selector nonzero: set FCM+FCT bits in FBCR --- */
    mov.w @r14, r2                              ! r2 = cached FBCR shadow value
    extu.w r2, r2                               ! zero-extend
    or r13, r2                                  ! r2 |= 0x3 (set FCM + FCT)
    extu.w r2, r2                               ! keep as 16-bit
    mov.w r2, @r7                               ! write to VDP1 FBCR register

.L_epilogue:
    mov.l @r15+, r11                            ! restore r11
    mov.l @r15+, r13                            ! restore r13
    rts                                         ! return to caller
    mov.l @r15+, r14                            ! delay slot: restore r14

    .global DAT_06038efa
DAT_06038efa:
    .2byte  0x4000

    .global DAT_06038efc
DAT_06038efc:
    .2byte  0x7FFF
    .2byte  0xFFFF
.L_ptr_display_mode:
    .4byte  sym_060635BC
.L_ptr_fbcr_shadow:
    .4byte  sym_060A4C92
.L_vdp1_fbcr:
    .4byte  0x25D00002                  /* VDP1 FBCR — framebuffer control */
.L_ptr_fb_mode_sel:
    .4byte  sym_060635B4
.L_ptr_swap_enable:
    .4byte  sym_060635B8
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_const_fffe:
    .4byte  0x0000FFFE
    .4byte  0xD40DD00E
    .4byte  0x60022008
    .4byte  0x8904E301
    .4byte  0x24326042
    .4byte  0x20088BFC
    .4byte  0x000B0009

/* display_param_reset -- Reset all display parameter state to defaults
 *
 * Called by display_hw_init during system initialization.
 * Zeroes all framebuffer state variables and sets swap_enable = 1.
 *
 * After reset:
 *   fb_mode_selector  = 0   (sym_060635B4)
 *   swap_enable       = 1   (sym_060635B8)
 *   display_mode      = 0   (sym_060635BC)
 *   frame_counter     = 0   (sym_060635C0)
 *   game_state_flag   = 0   (sym_060635C4)
 *   display_state_ext = 0   (sym_060635C8)
 */
    .global sym_06038F34
sym_06038F34:
    mov #0x0, r4                                ! r4 = 0 (clear value)
    mov #0x1, r1                                ! r1 = 1 (swap enable default)
    mov.l   .L_rst_fb_mode_sel, r2              ! r2 = &sym_060635B4 (fb mode selector)
    mov.w r4, @r2                               ! fb_mode_selector = 0
    mov.l   .L_rst_swap_enable, r2              ! r2 = &sym_060635B8 (swap enable flag)
    mov.l r1, @r2                               ! swap_enable = 1 (enabled by default)
    mov.l   .L_rst_display_mode, r2             ! r2 = &sym_060635BC (current display mode)
    mov.l r4, @r2                               ! display_mode = 0
    mov.l   .L_rst_frame_counter, r2            ! r2 = &sym_060635C0 (frame counter)
    mov.l r4, @r2                               ! frame_counter = 0
    mov.l   .L_rst_game_state, r2               ! r2 = &sym_060635C4 (game state flag)
    mov.l r4, @r2                               ! game_state_flag = 0
    mov.l   .L_rst_display_ext, r2              ! r2 = &sym_060635C8 (extended display state)
    rts                                         ! return to caller
    mov.l r4, @r2                               ! delay slot: display_state_ext = 0
    .2byte  0xFFFF
.L_rst_game_state:
    .4byte  sym_060635C4
.L_rst_display_mode:
    .4byte  sym_060635BC
.L_rst_fb_mode_sel:
    .4byte  sym_060635B4
.L_rst_swap_enable:
    .4byte  sym_060635B8
.L_rst_frame_counter:
    .4byte  sym_060635C0
.L_rst_display_ext:
    .4byte  sym_060635C8

/* polygon_param_setup -- VDP1 display parameter initialization
 * Translation unit: 0x06039250 - 0x0603950C
 *
 * Configures VDP1 display registers for each frame:
 *   - TVMR (TV mode), FBCR (framebuffer control), PTMR (plot trigger)
 *   - EWDR/EWLR/EWRR (erase window fill color, position, size)
 *   - Erase window coordinates derived from a resolution table
 *   - Interlace mode flag for half/full vertical resolution
 *
 * Functions:
 *   vdp2_scroll_update    -- Top-level per-frame VDP1 setup (raises IRQ mask,
 *                            calls polygon_param_setup + erase window config,
 *                            writes first VRAM cmd byte, sets frame-ready flag)
 *   polygon_param_setup   -- Selects VDP1 TV mode, resolution entry, and
 *                            interlace/color depth flags
 *   sym_060393FC (vdp1_erase_window_set)
 *                         -- Computes and writes erase window upper-left (EWLR)
 *                            and lower-right (EWRR) from resolution table,
 *                            adjusting for interlace and high-color modes
 *   sym_060394C2 (vdp1_draw_end_wait)
 *                         -- Polls VDP1 EDSR until draw-end bit is set
 *   .L_interlace_flag_set -- Sets or clears the interlace flag word (TU-local)
 *
 * Data symbols referenced:
 *   sym_060635B4..BC  -- VDP framebuffer mode / swap config (3 words)
 *   sym_060635CC      -- frame-ready flag
 *   sym_060635D0..DC  -- erase window working variables (7 half-words)
 *   sym_060635DE      -- high-color mode flag
 *   sym_060635E0      -- resolution table (8 entries x 4 bytes: W,H pairs)
 *   sym_060A4C88      -- cached display width
 *   sym_060A4C8C      -- cached display height
 *   sym_060A4C90      -- cached TVMR value
 *   sym_060A4C92      -- cached FBCR / interlace flag
 *   sym_060A4C94      -- high-color interlace enable
 *   sym_060A4C96      -- (unused/reserved display param)
 */

    .section .text.FUN_06039250


    .global vdp2_scroll_update
    .type vdp2_scroll_update, @function
vdp2_scroll_update:
    mov.l r14, @-r15           ! save r14
    mov.l r13, @-r15           ! save r13
    sts.l pr, @-r15            ! save return address
    mov r4, r14                ! r14 = output pointer (caller-provided)
    stc sr, r0                 ! r0 = current SR
    shlr2 r0                   ! shift IRQ mask bits into low nibble
    shlr2 r0                   ! r0 >>= 4 total
    and #0xF, r0               ! isolate old IRQ mask (bits 7..4 of SR)
    mov r0, r13                ! r13 = saved IRQ mask level
    stc sr, r0                 ! r0 = SR again
    mov.w   DAT_060392e6, r3   ! r3 = 0xFF0F (mask to clear IRQ bits)
    and r3, r0                 ! clear IRQ mask field in SR copy
    or #0xF0, r0               ! set IRQ mask to 0xF (disable all IRQs)
    ldc r0, sr                 ! apply raised IRQ mask
    bsr     .L_interlace_flag_set ! call interlace_flag_set
    mov #0x0, r4               ! arg: interlace = 0 (non-interlace) [delay slot]
    mov #0x0, r6               ! arg: high_color = 0
    mov #0x0, r5               ! arg: res_index = 0
    bsr     polygon_param_setup ! configure VDP1 TV mode & resolution
    mov #0x0, r4               ! arg: tv_mode = 0 [delay slot]
    mov.l   .L_fbcr_cached, r2 ! r2 -> cached FBCR value
    mov #0x0, r6               ! (clear r6, used later as high_color=0)
    mov.l   .L_vdp1_fbcr, r3   ! r3 = VDP1 FBCR register address
    mov.w @r2, r2              ! r2 = cached FBCR value
    mov.w r2, @r3              ! write FBCR to VDP1
    mov #0x2, r2               ! r2 = 0x2 (auto plot trigger)
    mov.l   .L_vdp1_ptmr, r3   ! r3 = VDP1 PTMR register address
    mov.w r2, @r3              ! PTMR = 2 (draw on Vblank-In)
    mov.l   .L_erase_color, r2 ! r2 = 0x8000 (black in RGB555)
    mov.l   .L_vdp1_ewdr, r3   ! r3 = VDP1 EWDR register address
    mov.w r2, @r3              ! set erase fill color
    mov #0x0, r2               ! r2 = 0
    mov.l   .L_vdp1_ewlr, r3   ! r3 = VDP1 EWLR register address
    mov.w r2, @r3              ! erase upper-left = (0,0)
    mov.l   .L_erase_lower_right, r2 ! r2 = 0xFFFF (max coords)
    mov.l   .L_vdp1_ewrr, r3   ! r3 = VDP1 EWRR register address
    mov.w r2, @r3              ! erase lower-right = full screen
    mov.l   .L_display_height, r2 ! r2 -> cached display height
    mov.l @r2, r2              ! r2 = display height
    add #-0x1, r2              ! height - 1 (last visible scanline)
    extu.w r2, r2              ! zero-extend to 16-bit
    mov.l r2, @-r15            ! push (height-1) onto stack as arg
    mov.l   .L_display_width, r7 ! r7 -> cached display width
    mov.l   .L_erase_color, r4 ! r4 = 0x8000 (erase fill color arg)
    mov.l @r7, r7              ! r7 = display width
    add #-0x1, r7              ! width - 1 (last visible pixel)
    extu.w r7, r7              ! zero-extend to 16-bit
    bsr     sym_060393FC           ! compute and write erase window (vdp1_erase_window_set)
    mov #0x0, r5               ! arg: top-left Y = 0 [delay slot]
    add #0x4, r15              ! pop stack arg
    mov.l   .L_vdp1_vram_base, r2 ! r2 = VDP1 VRAM base (0x25C00000)
    mov.l r2, @r14             ! store VRAM base at *output
    mov r2, r3                 ! r3 = VRAM base
    mov.w   .L_cmd_byte_0x80, r2 ! r2 = 0x0080
    mov.b r2, @r3              ! VRAM[0] = 0x80 (first cmd table byte)
    mov.l @r14, r3             ! r3 = VRAM base again
    add #0x1, r3               ! r3 = VRAM base + 1
    mov #0x0, r2               ! r2 = 0
    mov.b r2, @r3              ! VRAM[1] = 0x00 (second cmd table byte)
    mov r13, r0                ! r0 = saved IRQ mask
    and #0xF, r0               ! isolate low nibble
    shll2 r0                   ! shift back to SR IRQ mask position
    shll2 r0                   ! r0 <<= 4 total
    stc sr, r3                 ! r3 = current SR
    mov.w   DAT_060392e6, r2   ! r2 = 0xFF0F (clear mask for IRQ bits)
    and r2, r3                 ! clear IRQ mask field
    or r3, r0                  ! merge restored IRQ mask with other SR bits
    ldc r0, sr                 ! restore original IRQ level
    mov #0x1, r3               ! r3 = 1
    mov.l   .L_frame_ready_flag, r2 ! r2 -> frame-ready flag
    mov.l r3, @r2              ! frame_ready = 1 (signal frame is set up)
    lds.l @r15+, pr            ! restore return address
    mov.l @r15+, r13           ! restore r13
    rts                        ! return
    mov.l @r15+, r14           ! restore r14 [delay slot]

    .global DAT_060392e6
DAT_060392e6:
    .2byte  0xFF0F                      /* SR mask: clear IRQ level bits */
.L_cmd_byte_0x80:
    .2byte  0x0080                      /* VDP1 VRAM cmd byte 0: 0x80 (normal sprite) */
    .2byte  0xFFFF                      /* alignment padding */
.L_fbcr_cached:
    .4byte  sym_060A4C92               /* cached FBCR / interlace value */
.L_vdp1_fbcr:
    .4byte  0x25D00002                  /* VDP1 FBCR -- framebuffer control */
.L_vdp1_ptmr:
    .4byte  0x25D00004                  /* VDP1 PTMR -- plot trigger */
.L_erase_color:
    .4byte  0x00008000                  /* erase fill: 0x8000 (black in RGB555) */
.L_vdp1_ewdr:
    .4byte  0x25D00006                  /* VDP1 EWDR -- erase fill color */
.L_vdp1_ewlr:
    .4byte  0x25D00008                  /* VDP1 EWLR -- erase upper-left */
.L_erase_lower_right:
    .4byte  0x0000FFFF                  /* default lower-right (full screen) */
.L_vdp1_ewrr:
    .4byte  0x25D0000A                  /* VDP1 EWRR -- erase lower-right */
.L_display_height:
    .4byte  sym_060A4C8C               /* cached display height */
.L_display_width:
    .4byte  sym_060A4C88               /* cached display width */
.L_vdp1_vram_base:
    .4byte  0x25C00000                  /* VDP1 VRAM base address */
.L_frame_ready_flag:
    .4byte  sym_060635CC               /* frame-ready flag (1 = setup complete) */

    .global polygon_param_setup
    .type polygon_param_setup, @function
polygon_param_setup:
    mov.l r14, @-r15           ! save r14
    extu.w r4, r1              ! r1 = tv_mode (zero-extended)
    mov #0x7, r3               ! r3 = 0x7 (3-bit mask)
    mov.l   .L_cached_height_b, r14 ! r14 -> cached display height
    mov.l   .L_cached_tvmr, r2 ! r2 -> cached TVMR value
    and r1, r3                 ! r3 = tv_mode & 0x7
    mov.w r3, @r2              ! store masked TV mode to cached TVMR
    mov.l   .L_vdp1_tvmr, r2   ! r2 = VDP1 TVMR register address
    mov.w r3, @r2              ! write TV mode to VDP1 TVMR
    extu.w r5, r3              ! r3 = res_index (zero-extended)
    mov #0x7, r2               ! r2 = 7 (max valid resolution index)
    cmp/gt r2, r3              ! T = (res_index > 7)?
    bf/s    .L_res_index_valid ! branch if index <= 7 (valid)
    mov #0x0, r7               ! r7 = 0 (used as zero constant) [delay slot]
    extu.w r7, r5              ! res_index out of range: clamp to 0
.L_res_index_valid:
    extu.w r5, r4              ! r4 = clamped res_index
    mov.l   .L_res_table, r3   ! r3 -> resolution table base
    shll2 r4                   ! r4 = res_index * 4 (each entry is 4 bytes)
    add r3, r4                 ! r4 -> resolution table[res_index]
    mov.w @r4, r2              ! r2 = table[idx].width
    mov.l   .L_cached_width_b, r3 ! r3 -> cached display width
    mov.l r2, @r3              ! store width to cached display width
    mov.w @(2, r4), r0         ! r0 = table[idx].height
    mov r0, r2                 ! r2 = height (copy)
    mov.l r0, @r14             ! store height to cached display height
    extu.w r6, r0              ! r0 = high_color flag
    cmp/eq #0x1, r0            ! T = (high_color == 1)?
    bf      .L_no_interlace_double ! skip if not high-color mode
    mov.l @r14, r2             ! r2 = display height
    shll r2                    ! r2 = height * 2 (double for interlace)
    mov.l r2, @r14             ! store doubled height
.L_no_interlace_double:
    mov r1, r0                 ! r0 = tv_mode
    cmp/eq #0x1, r0            ! T = (tv_mode == 1)?
    bt      .L_set_hires_flag  ! if mode 1, set high-res flag
    mov r1, r0                 ! r0 = tv_mode
    cmp/eq #0x3, r0            ! T = (tv_mode == 3)?
    bf      .L_clear_hires_flag ! if not mode 1 or 3, clear flag
.L_set_hires_flag:
    mov #0x1, r3               ! r3 = 1
    mov.l   .L_hires_flag, r2  ! r2 -> high-res mode flag
    mov.w r3, @r2              ! hires_flag = 1
    bra     .L_check_highcolor ! skip clear path
    nop                        ! [delay slot]
.L_clear_hires_flag:
    extu.w r7, r2              ! r2 = 0
    mov.l   .L_hires_flag, r3  ! r3 -> high-res mode flag
    mov.w r2, @r3              ! hires_flag = 0
.L_check_highcolor:
    extu.w r6, r6              ! zero-extend high_color arg
    tst r6, r6                 ! T = (high_color == 0)?
    bt      .L_no_highcolor    ! skip if not high-color
    mov #0x8, r3               ! r3 = 8 (high-color interlace enable)
    mov.l   .L_highcolor_flag, r2 ! r2 -> high-color interlace enable
    mov.w r3, @r2              ! highcolor_interlace = 8
    bra     .L_clear_reserved  ! skip clear path
    nop                        ! [delay slot]
.L_no_highcolor:
    extu.w r7, r2              ! r2 = 0
    mov.l   .L_highcolor_flag, r3 ! r3 -> high-color interlace enable
    mov.w r2, @r3              ! highcolor_interlace = 0
.L_clear_reserved:
    extu.w r7, r2              ! r2 = 0
    mov.l   .L_reserved_param, r3 ! r3 -> reserved display param
    mov.w r2, @r3              ! reserved_param = 0
    rts                        ! return
    mov.l @r15+, r14           ! restore r14 [delay slot]
    .2byte  0xFFFF             ! alignment padding
.L_cached_height_b:
    .4byte  sym_060A4C8C               /* cached display height */
.L_cached_tvmr:
    .4byte  sym_060A4C90               /* cached TVMR value */
.L_vdp1_tvmr:
    .4byte  0x25D00000                  /* VDP1 TVMR -- TV mode */
.L_res_table:
    .4byte  sym_060635E0               /* resolution table (8 entries: W,H) */
.L_cached_width_b:
    .4byte  sym_060A4C88               /* cached display width */
.L_hires_flag:
    .4byte  sym_060635DE               /* high-res mode flag */
.L_highcolor_flag:
    .4byte  sym_060A4C94               /* high-color interlace enable */
.L_reserved_param:
    .4byte  sym_060A4C96               /* reserved display parameter */
    .4byte  0xD31C6331
    .4byte  0x2431D21C
    .4byte  0x6222622D
    .4byte  0x60238141
    .4byte  0xD31A6332
    .4byte  0x633D6033
    .4byte  0x8142D319
    .4byte  0x63316033
    .4byte  0x8143D318
    .4byte  0x63316033
    .4byte  0x8144D317
    .4byte  0x63316033
    .4byte  0x8145D316
    .4byte  0x63316033
    .4byte  0x8146D315
    .4byte  0x63316033
    .4byte  0x000B8147

    .global sym_060393FC               /* vdp1_erase_window_set */
sym_060393FC:
    /* Args: r4=erase_color, r5=top_left_Y, r6=top_left_X, r7=bottom_right_X */
    /* Stack: @(2,r15)=bottom_right_Y */
    mov.w @(2, r15), r0        ! r0 = bottom_right_Y (from stack)
    mov.l   .L_ew_color_var, r3 ! r3 -> erase color working var
    mov r0, r1                 ! r1 = bottom_right_Y
    mov.w r4, @r3              ! store erase color
    mov.l   .L_ew_top_y, r3    ! r3 -> top-left Y working var
    mov.w r5, @r3              ! store top-left Y
    mov.l   .L_ew_top_x, r3    ! r3 -> top-left X working var
    mov.w r6, @r3              ! store top-left X
    mov.l   .L_ew_bot_x, r3    ! r3 -> bottom-right X working var
    mov.w r7, @r3              ! store bottom-right X
    mov.l   .L_ew_bot_y, r3    ! r3 -> bottom-right Y working var
    mov.w r1, @r3              ! store bottom-right Y
    mov.l   .L_vdp1_ewdr_b, r3 ! r3 = VDP1 EWDR register address
    mov.w r4, @r3              ! write erase fill color to EWDR
    mov.l   .L_hires_flag_b, r0 ! r0 -> high-res mode flag
    mov.w @r0, r0              ! r0 = hires_flag
    extu.w r0, r0              ! zero-extend
    tst r0, r0                 ! T = (hires_flag == 0)?
    bt      .L_top_y_normal    ! branch if normal res (not hi-res)
    extu.w r5, r5              ! zero-extend top_left_Y
    shlr2 r5                   ! top_left_Y /= 4 (hi-res X scaling)
    bra     .L_check_interlace_top ! continue to interlace check
    shlr2 r5                   ! top_left_Y /= 16 total [delay slot]
    .2byte  0xFFFF             ! alignment padding
    .4byte  sym_060635B4               /* VDP framebuffer mode selector (unreferenced pool) */
    .4byte  sym_060635B8               /* framebuffer swap enable (unreferenced pool) */
    .4byte  sym_060635BC               /* framebuffer swap delay (unreferenced pool) */
.L_ew_color_var:
    .4byte  sym_060635D4               /* erase window color working var */
.L_ew_top_y:
    .4byte  sym_060635D6               /* erase window top-left Y */
.L_ew_top_x:
    .4byte  sym_060635D8               /* erase window top-left X */
.L_ew_bot_x:
    .4byte  sym_060635DA               /* erase window bottom-right X */
.L_ew_bot_y:
    .4byte  sym_060635DC               /* erase window bottom-right Y */
.L_vdp1_ewdr_b:
    .4byte  0x25D00006                  /* VDP1 EWDR -- erase fill color */
.L_hires_flag_b:
    .4byte  sym_060635DE               /* high-res mode flag */
.L_top_y_normal:
    extu.w r5, r5              ! zero-extend top_left_Y
    shlr2 r5                   ! top_left_Y /= 4
    shlr r5                    ! top_left_Y /= 8 total (normal res)
.L_check_interlace_top:
    mov.l   .L_highcolor_interlace, r0 ! r0 -> high-color interlace enable
    mov.w @r0, r0              ! r0 = highcolor_interlace
    extu.w r0, r0              ! zero-extend
    tst r0, r0                 ! T = (interlace == 0)?
    bt      .L_top_x_normal    ! branch if no interlace
    extu.w r6, r6              ! zero-extend top_left_X
    shlr r6                    ! top_left_X /= 2 (interlace halves Y res)
.L_top_x_normal:
    extu.w r5, r5              ! zero-extend scaled Y
    extu.w r6, r6              ! zero-extend scaled X
    mov.l   .L_ewlr_working, r3 ! r3 -> EWLR working var
    shll8 r5                   ! Y <<= 8
    shll r5                    ! Y <<= 9 total (pack into EWLR high bits)
    add r6, r5                 ! combine: EWLR = (Y << 9) | X
    extu.w r5, r5              ! zero-extend combined value
    mov.w r5, @r3              ! store to EWLR working var
    mov.l   .L_ewlr_working, r2 ! r2 -> EWLR working var
    mov.l   .L_vdp1_ewlr_b, r3 ! r3 = VDP1 EWLR register address
    mov.w @r2, r2              ! r2 = packed EWLR value
    mov.w r2, @r3              ! write EWLR to VDP1
    mov.l   .L_hires_flag_c, r0 ! r0 -> high-res mode flag
    mov.w @r0, r0              ! r0 = hires_flag
    extu.w r0, r0              ! zero-extend
    tst r0, r0                 ! T = (hires_flag == 0)?
    bt/s    .L_bot_x_normal    ! branch if normal resolution
    add #0x1, r7               ! bottom_right_X += 1 [delay slot]
    extu.w r7, r7              ! zero-extend bottom_right_X
    shlr2 r7                   ! bot_right_X /= 4 (hi-res scaling)
    bra     .L_check_interlace_bot ! continue
    shlr2 r7                   ! bot_right_X /= 16 total [delay slot]
.L_bot_x_normal:
    extu.w r7, r7              ! zero-extend bottom_right_X
    shlr2 r7                   ! bot_right_X /= 4
    shlr r7                    ! bot_right_X /= 8 total (normal res)
.L_check_interlace_bot:
    mov.l   .L_highcolor_interlace, r0 ! r0 -> high-color interlace enable
    mov.w @r0, r0              ! r0 = highcolor_interlace
    extu.w r0, r0              ! zero-extend
    tst r0, r0                 ! T = (interlace == 0)?
    bt      .L_bot_y_normal    ! branch if no interlace
    extu.w r1, r1              ! zero-extend bottom_right_Y
    shlr r1                    ! bot_right_Y /= 2 (interlace halves Y)
.L_bot_y_normal:
    extu.w r7, r7              ! zero-extend scaled X
    extu.w r1, r1              ! zero-extend scaled Y
    mov.l   .L_ewrr_working, r3 ! r3 -> EWRR working var
    shll8 r7                   ! X <<= 8
    shll r7                    ! X <<= 9 total (pack into EWRR high bits)
    add r1, r7                 ! combine: EWRR = (X << 9) | Y
    extu.w r7, r7              ! zero-extend combined value
    mov.w r7, @r3              ! store to EWRR working var
    mov.l   .L_ewrr_working, r2 ! r2 -> EWRR working var
    mov.l   .L_vdp1_ewrr_b, r3 ! r3 = VDP1 EWRR register address
    mov.w @r2, r2              ! r2 = packed EWRR value
    rts                        ! return
    mov.w r2, @r3              ! write EWRR to VDP1 [delay slot]

    .global sym_060394C2               /* vdp1_draw_end_wait */
sym_060394C2:
    mov.l   .L_vdp1_edsr, r5   ! r5 = VDP1 EDSR register address
    mov #0x2, r4               ! r4 = bit 1 mask (draw-end flag)
.L_poll_edsr:
    mov.w @r5, r2              ! r2 = EDSR value
    extu.w r2, r2              ! zero-extend
    and r4, r2                 ! isolate draw-end bit
    tst r2, r2                 ! T = (draw-end == 0)?
    bt      .L_poll_edsr       ! loop until draw-end is set
    rts                        ! return when draw complete
    nop                        ! [delay slot]
.L_highcolor_interlace:
    .4byte  sym_060A4C94               /* high-color interlace enable */
.L_ewlr_working:
    .4byte  sym_060635D0               /* EWLR packed working value */
.L_vdp1_ewlr_b:
    .4byte  0x25D00008                  /* VDP1 EWLR -- erase upper-left */
.L_hires_flag_c:
    .4byte  sym_060635DE               /* high-res mode flag */
.L_ewrr_working:
    .4byte  sym_060635D2               /* EWRR packed working value */
.L_vdp1_ewrr_b:
    .4byte  0x25D0000A                  /* VDP1 EWRR -- erase lower-right */
.L_vdp1_edsr:
    .4byte  0x25D00010                  /* VDP1 EDSR -- draw end status */
.L_interlace_flag_set:
    tst r4, r4                 ! T = (interlace_arg == 0)?
    bt      .L_clear_interlace ! branch if disabling interlace
    mov #0x10, r3              ! r3 = 0x10 (interlace enable value)
    mov.l   .L_interlace_cached, r2 ! r2 -> cached FBCR/interlace flag
    mov.w r3, @r2              ! set interlace flag = 0x10
    bra     .L_interlace_done  ! done
    nop                        ! [delay slot]
.L_clear_interlace:
    mov #0x0, r2               ! r2 = 0
    mov.l   .L_interlace_cached, r3 ! r3 -> cached FBCR/interlace flag
    mov.w r2, @r3              ! clear interlace flag = 0
.L_interlace_done:
    rts                        ! return
    nop                        ! [delay slot]
.L_interlace_cached:
    .4byte  sym_060A4C92               /* cached FBCR / interlace flag */

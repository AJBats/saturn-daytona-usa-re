/* button_input_read.s -- Main per-frame input/event dispatch
 * Translation unit: 0x06006F3C - 0x06007268
 *
 * Function catalog:
 *   button_input_read -- Per-frame input consumer and event dispatcher.
 *                        Reads processed input state (32-bit button/event word),
 *                        tests individual bit flags, dispatches to handlers.
 *
 * Overall flow:
 *   1. Prologue: save callee-saved registers, load persistent pointers
 *   2. Increment global tick counter, set run_flag = 1
 *   3. If skip_flag is nonzero, jump straight to exit
 *   4. VDP framebuffer mode dispatch (modes 0-3):
 *      - Mode 0: default (call scene_data_dispatch, clear game_state)
 *      - Mode 1: framebuffer swap with delay timing
 *      - Mode 2: manual erase (call scene_data_dispatch if game active)
 *      - Mode 3: VBlank erase (set VBE+FCM+FCT, call scene_data_dispatch)
 *   5. Car struct selection: compute current car pointer from index
 *   6. Button dispatch: test bits in input state word, call handlers:
 *      - Bit 29 (0x20000000): DMA transfer via dma_transfer()
 *      - Bit 2  (0x04): D-pad Right -> DMA transfer
 *      - Bit 4  (0x10): D-pad Left -> display_channel_b(src, dst, 4)
 *      - Bit 5  (0x20): Start -> display_channel_b(src, dst, 8)
 *      - Bit 6  (0x40): A button -> display_channel_b(src, dst, 16)
 *      - Bit 7  (0x80): B button -> display_channel_b(src, dst, 32)
 *   7. Channel A event dispatch (bits 16-19):
 *      - Each calls display_channel_a(src, dst, 4/8/16/32)
 *   8. System event dispatch:
 *      - Bit 31: special handler A
 *      - Bit 30: special handler B
 *      - Bit 20: display_channels_load()
 *      - Bit 26: obj_collision_update()
 *      - Bit 27: physics update
 *   9. Clear input state word (consume all events)
 *  10. Epilogue: set run_flag = 2, restore registers, return
 *
 * Input state word layout (at sym_0605B6D8):
 *   Bits [7:0]   -- Button flags (active-HIGH, set = pressed):
 *     bit 2  (0x04)       -- D-pad Right
 *     bit 4  (0x10)       -- D-pad Left
 *     bit 5  (0x20)       -- Start button
 *     bit 6  (0x40)       -- A button (gas/accelerate)
 *     bit 7  (0x80)       -- B button (brake)
 *   Bits [19:16] -- Display channel A events:
 *     bit 16 (0x00010000) -- Channel A event 0
 *     bit 17 (0x00020000) -- Channel A event 1
 *     bit 18 (0x00040000) -- Channel A event 2
 *     bit 19 (0x00080000) -- Channel A event 3
 *   Bits [31:20] -- System events:
 *     bit 20 (0x00100000) -- Display channels reload
 *     bit 26 (0x04000000) -- Collision update trigger
 *     bit 27 (0x08000000) -- Physics update trigger
 *     bit 29 (0x20000000) -- DMA transfer trigger (special)
 *     bit 30 (0x40000000) -- Special handler B
 *     bit 31 (0x80000000) -- Special handler A
 *
 * Register allocation (callee-saved across entire function):
 *   r8  = display_channel_b (handler for lower button bits)
 *   r9  = display_channel_a (handler for channel events)
 *   r10 = scene_data_dispatch (VDP scene dispatch)
 *   r11 = &sym_060635C4 (game state flag)
 *   r12 = 0 (cleared event accumulator)
 *   r13 = &sym_060635C0 (frame counter)
 *   r14 = &sym_0605B6D8 (input state word pointer)
 */

    .section .text.FUN_06006F3C


    .global button_input_read
    .type button_input_read, @function
button_input_read:
    mov.l r14, @-r15           ! save r14 on stack
    mov #0x1, r2               ! r2 = 1 (used to set run_flag below)
    mov.l r13, @-r15           ! save r13 on stack
    mov.l r12, @-r15           ! save r12 on stack
    mov.l r11, @-r15           ! save r11 on stack
    mov.l r10, @-r15           ! save r10 on stack
    mov.l r9, @-r15            ! save r9 on stack
    mov.l r8, @-r15            ! save r8 on stack
    sts.l pr, @-r15            ! save return address on stack
    mov.l   .L_fn_disp_channel_b, r8  ! r8 = &display_channel_b
    mov.l   .L_fn_disp_channel_a, r9  ! r9 = &display_channel_a
    mov.l   .L_fn_scene_dispatch, r10 ! r10 = &scene_data_dispatch
    mov.l   .L_game_state_flag, r11   ! r11 = &game_state_flag
    mov.l   .L_frame_counter, r13     ! r13 = &frame_counter
    mov.l   .L_input_state_ptr, r14   ! r14 = &input_state_word
    mov.l   .L_tick_counter, r4       ! r4 = &global_tick_counter
    mov.l @r4, r3              ! r3 = tick_counter value
    add #0x1, r3               ! r3 = tick_counter + 1
    mov.l r3, @r4              ! tick_counter++ (write back)
    mov.l   .L_run_flag, r3   ! r3 = &run_flag
    mov.l r2, @r3              ! run_flag = 1 (processing started)
    mov.l   .L_skip_flag, r0  ! r0 = &skip_flag
    mov.w @r0, r0              ! r0 = skip_flag (16-bit read)
    extu.w r0, r0              ! zero-extend to 32 bits
    tst r0, r0                 ! skip_flag == 0?
    bt/s    .L_vdp_mode_entry  ! yes: proceed with input processing
    mov #0x0, r12              ! r12 = 0 (cleared event accumulator, in delay slot)
    bra     .L_exit_epilogue   ! no: skip all processing, jump to exit
    nop                        ! (delay slot)

    /* === VDP framebuffer mode handling === */
.L_vdp_mode_entry:
    mov.l   .L_display_mode, r3  ! r3 = &display_mode
    mov.l r12, @r3             ! display_mode = 0 (reset)
    mov.l   .L_vdp_mode, r4   ! r4 = &vdp_mode_selector
    mov.w @r4, r0              ! r0 = vdp_mode (16-bit)
    extu.w r0, r0              ! zero-extend to 32 bits
    cmp/eq #0x2, r0            ! VDP mode == 2? (manual erase)
    bf      .L_vdp_check_mode3 ! no: check mode 3
    mov.l @r11, r0             ! r0 = game_state_flag
    tst r0, r0                 ! game state active? (nonzero = active)
    bt      .L_button_dispatch ! no (zero): skip to button dispatch
    jsr @r10                   ! scene_data_dispatch() — render scene for manual erase
    nop                        ! (delay slot)
    mov #0x2, r3               ! r3 = 2
    mov.l   .L_display_mode, r2  ! r2 = &display_mode
    mov.l r3, @r2              ! display_mode = 2 (manual erase active)
    bra     .L_button_dispatch ! proceed to button dispatch
    nop                        ! (delay slot)
.L_vdp_check_mode3:
    mov.l   .L_vdp1_fbcr, r6  ! r6 = VDP1 FBCR register address (0x25D00002)
    mov.l   .L_fbcr_state, r5 ! r5 = &cached_fbcr_value
    mov.w @r4, r0              ! r0 = vdp_mode (re-read)
    extu.w r0, r0              ! zero-extend to 32 bits
    cmp/eq #0x3, r0            ! VDP mode == 3? (VBlank erase)
    bf      .L_vdp_check_mode0 ! no: check mode 0/1
    mov.l @r11, r0             ! r0 = game_state_flag
    tst r0, r0                 ! game state active?
    bt      .L_button_dispatch ! no: skip to button dispatch
    mov.l   .L_tvmr_state, r0 ! r0 = &cached_tvmr_value
    mov.l   .L_vdp1_tvmr, r3  ! r3 = VDP1 TVMR register address (0x25D00000)
    mov.w @r0, r0              ! r0 = cached TVMR value (16-bit)
    extu.w r0, r0              ! zero-extend to 32 bits
    or #0x8, r0                ! set bit 3: VBE (VBlank erase enable)
    mov.w r0, @r3              ! write TVMR register with VBE set
    mov.w @r5, r0              ! r0 = cached FBCR value (16-bit)
    extu.w r0, r0              ! zero-extend to 32 bits
    or #0x3, r0                ! set bits 0+1: FCM (manual change) + FCT (change trigger)
    jsr @r10                   ! scene_data_dispatch() — render scene for VBlank erase
    mov.w r0, @r6              ! write VDP1 FBCR register (in delay slot)
    mov #0x3, r3               ! r3 = 3
    mov.l   .L_display_mode, r2  ! r2 = &display_mode
    mov.l r3, @r2              ! display_mode = 3 (VBlank erase active)
    bra     .L_button_dispatch ! proceed to button dispatch
    nop                        ! (delay slot)
.L_vdp_check_mode0:
    mov.w @r4, r2              ! r2 = vdp_mode (re-read, 16-bit)
    extu.w r2, r2              ! zero-extend to 32 bits
    tst r2, r2                 ! VDP mode == 0? (default mode)
    bf      .L_vdp_mode1_fbswap ! no: must be mode 1, handle framebuffer swap
    jsr @r10                   ! scene_data_dispatch() — default mode render
    nop                        ! (delay slot)
    bra     .L_button_dispatch ! proceed to button dispatch
    mov.l r12, @r11            ! game_state_flag = 0 (clear, in delay slot)
    .2byte  0xFFFF             ! padding to align constant pool

    /* === Constant pool: setup pointers === */
.L_fn_disp_channel_b:
    .4byte  display_channel_b  ! function pointer: display_channel_b
.L_fn_disp_channel_a:
    .4byte  display_channel_a  ! function pointer: display_channel_a
.L_fn_scene_dispatch:
    .4byte  scene_data_dispatch ! function pointer: scene_data_dispatch
.L_game_state_flag:
    .4byte  sym_060635C4       ! game state active flag (nonzero = active)
.L_frame_counter:
    .4byte  sym_060635C0       ! per-input frame counter (for fb swap timing)
.L_input_state_ptr:
    .4byte  sym_0605B6D8       ! processed input state (32-bit button/event word)
.L_tick_counter:
    .4byte  sym_0607864C       ! global tick counter (incremented every frame)
.L_run_flag:
    .4byte  sym_06059F54       ! input processing run flag (1=running, 2=done)
.L_skip_flag:
    .4byte  sym_0605A00C       ! input skip flag (nonzero = skip all processing)
.L_display_mode:
    .4byte  sym_06063F58       ! display/VDP mode state output
.L_vdp_mode:
    .4byte  sym_060635B4       ! VDP framebuffer mode selector (0-3)
.L_vdp1_fbcr:
    .4byte  0x25D00002                  ! VDP1 FBCR -- framebuffer change control register
.L_fbcr_state:
    .4byte  sym_060A4C92       ! cached FBCR value (software shadow)
.L_tvmr_state:
    .4byte  sym_060A4C90       ! cached TVMR value (software shadow)
.L_vdp1_tvmr:
    .4byte  0x25D00000                  ! VDP1 TVMR -- TV mode register

    /* === Framebuffer swap timing (VDP mode 1) === */
.L_vdp_mode1_fbswap:
    mov.l @r13, r2             ! r2 = current frame_counter value
    add #0x1, r2               ! r2 = frame_counter + 1
    mov.l r2, @r13             ! frame_counter++ (write back)
    mov.l   .L_fb_swap_enable, r0  ! r0 = &fb_swap_enable
    mov.l @r0, r0              ! r0 = fb_swap_enable flag value
    cmp/eq #0x1, r0            ! fb swap enabled? (== 1)
    bf      .L_fbswap_check_delay  ! no: skip early swap trigger
    mov.l   .L_fb_swap_delay, r2   ! r2 = &fb_swap_delay
    mov.l @r13, r3             ! r3 = frame_counter (re-read)
    mov.l @r2, r2              ! r2 = fb_swap_delay value
    add #-0x1, r2              ! r2 = delay - 1 (early trigger threshold)
    cmp/gt r3, r2              ! frame_counter < (delay - 1)?
    bt      .L_fbswap_check_delay  ! yes: not yet time for early trigger
    mov.w @r5, r0              ! r0 = cached FBCR value (16-bit)
    extu.w r0, r0              ! zero-extend to 32 bits
    or #0x2, r0                ! set bit 1: FCM (manual framebuffer change mode)
    extu.w r0, r0              ! ensure 16-bit clean value
    mov.w r0, @r6              ! write VDP1 FBCR -- trigger early fb swap
.L_fbswap_check_delay:
    mov.l   .L_fb_swap_delay, r3  ! r3 = &fb_swap_delay
    mov.l @r13, r2             ! r2 = frame_counter
    mov.l @r3, r3              ! r3 = fb_swap_delay value
    cmp/gt r2, r3              ! frame_counter < delay?
    bt      .L_button_dispatch ! yes: delay not reached, skip to button dispatch
    mov.l @r11, r0             ! r0 = game_state_flag
    tst r0, r0                 ! game state active?
    bt      .L_fbswap_reset_counter ! no: just reset counter
    jsr @r10                   ! scene_data_dispatch() -- render scene for mode 1
    nop                        ! (delay slot)
    mov #0x1, r3               ! r3 = 1
    mov.l   .L_display_mode_b, r2  ! r2 = &display_mode
    mov.l r3, @r2              ! display_mode = 1 (mode 1 active)
.L_fbswap_reset_counter:
    mov.l r12, @r13            ! frame_counter = 0 (reset for next cycle)

    /* === Button dispatch section === */
    /* Computes pointer to current car struct from car_array_idx and car_select, */
    /* then tests individual bit flags in the input state word @r14 */
    /* and dispatches to corresponding handlers. */
.L_button_dispatch:
    mov.l   .L_car_array_idx, r3  ! r3 = &car_array_idx
    mov.l   .L_car_select, r1    ! r1 = &car_select
    mov.l @r3, r3              ! r3 = car_array_idx value
    mov.l @r1, r1              ! r1 = car_select value
    shlr2 r3                   ! r3 = car_array_idx >> 2
    shlr r1                    ! r1 = car_select >> 1
    mov r3, r2                 ! r2 = r3 (copy shifted index)
    shll2 r3                   ! r3 = (idx >> 2) << 2 = idx & ~3
    shll2 r2                   ! r2 = (idx >> 2) << 2
    shll2 r3                   ! r3 = r3 << 2 (total: idx >> 2 << 4)
    shll2 r2                   ! r2 = r2 << 2 (total: idx >> 2 << 4)
    shll2 r2                   ! r2 = r2 << 2 (total: idx >> 2 << 6)
    add r2, r3                 ! r3 = combined offset (idx>>2<<4 + idx>>2<<6)
    add r1, r3                 ! r3 += car_select >> 1 (sub-index offset)
    mov.l   .L_car_base, r2   ! r2 = car_array_base address
    add r2, r3                 ! r3 = &car[computed_index] (base + offset)
    mov.l   .L_current_car, r2  ! r2 = &current_car_ptr
    mov.l r3, @r2              ! current_car = &car[computed_index]

    /* Bit 29: DMA transfer trigger (0x20000000) */
    mov.l @r14, r1             ! r1 = input_state_word
    mov.l   .L_bit29_dma, r2  ! r2 = 0x20000000 (bit 29 mask)
    and r2, r1                 ! r1 = input_state & bit29_mask
    tst r1, r1                 ! bit 29 set?
    bt      .L_check_dpad_right ! no: skip DMA trigger
    mov.w   .L_dma_size_a, r6 ! r6 = 0x0640 (DMA transfer byte count)
    mov.l   .L_current_car, r5  ! r5 = &current_car_ptr
    mov.l   .L_dma_dst_a, r4  ! r4 = &dma_destination_a
    mov.l   .L_fn_dma_transfer, r3  ! r3 = &dma_transfer function
    mov.l @r5, r5              ! r5 = current_car address (DMA source)
    jsr @r3                    ! dma_transfer(dst, src, size)
    mov.l @r4, r4              ! r4 = DMA destination address (in delay slot)

    /* Bit 2: D-pad Right (0x04) */
.L_check_dpad_right:
    mov.l @r14, r0             ! r0 = input_state_word
    tst #0x4, r0               ! bit 2 set? (D-pad Right)
    bt      .L_check_dpad_left ! no: skip to Left check
    mov.w   .L_dma_size_b, r6 ! r6 = 0x0E00 (DMA transfer byte count)
    mov.l   .L_dma_src_b, r5  ! r5 = &dma_source_b
    mov.l   .L_dma_dst_b, r4  ! r4 = &dma_destination_b
    mov.l   .L_fn_dma_transfer, r3  ! r3 = &dma_transfer function
    mov.l @r5, r5              ! r5 = dma_source_b address
    jsr @r3                    ! dma_transfer(dst, src, size)
    mov.l @r4, r4              ! r4 = dma_destination_b address (in delay slot)

    /* Bit 4: D-pad Left (0x10) */
.L_check_dpad_left:
    mov.l @r14, r0             ! r0 = input_state_word
    tst #0x10, r0              ! bit 4 set? (D-pad Left)
    bt      .L_check_start     ! no: skip to Start check
    mov.l   .L_btn_left_a, r6 ! r6 = &left_data_source_ptr
    mov.l   .L_btn_left_b, r5 ! r5 = &left_data_dest_ptr
    mov.l @r6, r6              ! r6 = left_data_source address
    mov.l @r5, r5              ! r5 = left_data_dest address
    jsr @r8                    ! display_channel_b(src=r6, dst=r5, mode=4)
    mov #0x4, r4               ! r4 = 4 (channel mode, in delay slot)

    /* Bit 5: Start button (0x20) */
.L_check_start:
    mov.l @r14, r0             ! r0 = input_state_word
    tst #0x20, r0              ! bit 5 set? (Start button)
    bt      .L_check_btn_a     ! no: skip to A button check
    mov.l   .L_btn_start_a, r6  ! r6 = &start_data_source_ptr
    mov.l   .L_btn_start_b, r5  ! r5 = &start_data_dest_ptr
    mov.l @r6, r6              ! r6 = start_data_source address
    mov.l @r5, r5              ! r5 = start_data_dest address
    jsr @r8                    ! display_channel_b(src=r6, dst=r5, mode=8)
    mov #0x8, r4               ! r4 = 8 (channel mode, in delay slot)

    /* Bit 6: A button -- gas/accelerate (0x40) */
.L_check_btn_a:
    mov.l @r14, r0             ! r0 = input_state_word
    tst #0x40, r0              ! bit 6 set? (A button)
    bt      .L_check_btn_b     ! no: skip to B button check
    mov.l   .L_btn_a_src, r6  ! r6 = &btn_a_data_source_ptr
    mov.l   .L_btn_a_dst, r5  ! r5 = &btn_a_data_dest_ptr
    mov.l @r6, r6              ! r6 = btn_a_data_source address
    mov.l @r5, r5              ! r5 = btn_a_data_dest address
    jsr @r8                    ! display_channel_b(src=r6, dst=r5, mode=16)
    mov #0x10, r4              ! r4 = 16 (channel mode, in delay slot)

    /* Bit 7: B button -- brake (0x80) */
.L_check_btn_b:
    mov.l @r14, r0             ! r0 = input_state_word
    tst #0x80, r0              ! bit 7 set? (B button)
    bt      .L_check_chan_a0   ! no: skip to channel A event section
    mov.l   .L_btn_b_src, r6  ! r6 = &btn_b_data_source_ptr
    bra     .L_btn_b_handler   ! B button handler is across pool gap
    nop                        ! (delay slot)

    /* === Word pool entries === */
.L_dma_size_a:
    .2byte  0x0640              ! DMA transfer size for bit 29 trigger (1600 bytes)
.L_dma_size_b:
    .2byte  0x0E00              ! DMA transfer size for D-pad Right (3584 bytes)
    .2byte  0xFFFF              ! padding to align constant pool

    /* === Constant pool: framebuffer timing === */
.L_fb_swap_enable:
    .4byte  sym_060635B8       ! framebuffer swap enable flag (1 = enabled)
.L_fb_swap_delay:
    .4byte  sym_060635BC       ! framebuffer swap delay (frame count threshold)
.L_display_mode_b:
    .4byte  sym_06063F58       ! display mode (same address as .L_display_mode)
.L_car_array_idx:
    .4byte  sym_06059F3C       ! car array index (selects which car slot)
.L_car_select:
    .4byte  sym_06059F38       ! car selection value (sub-index within slot)
.L_car_base:
    .4byte  sym_0606B178       ! car array base address (start of car struct array)
.L_current_car:
    .4byte  sym_06059F34       ! pointer to current car struct (computed result)
.L_bit29_dma:
    .4byte  0x20000000         ! bit 29 mask -- DMA trigger event
.L_dma_dst_a:
    .4byte  sym_06063F60       ! DMA destination for bit 29 transfer
.L_fn_dma_transfer:
    .4byte  dma_transfer       ! function pointer: dma_transfer(dst, src, size)
.L_dma_src_b:
    .4byte  sym_0606129C       ! DMA source for D-pad Right transfer
.L_dma_dst_b:
    .4byte  sym_060612B4       ! DMA destination for D-pad Right transfer
.L_btn_left_a:
    .4byte  sym_0605B700       ! D-pad Left: data source ptr
.L_btn_left_b:
    .4byte  sym_0605B6FC       ! D-pad Left: data dest ptr
.L_btn_start_a:
    .4byte  sym_0605B708       ! Start: data source ptr
.L_btn_start_b:
    .4byte  sym_0605B704       ! Start: data dest ptr
.L_btn_a_src:
    .4byte  sym_0605B710       ! A button: data source ptr
.L_btn_a_dst:
    .4byte  sym_0605B70C       ! A button: data dest ptr
.L_btn_b_src:
    .4byte  sym_0605B718       ! B button: data source ptr

    /* B button extended handler (reached via bra from bit 7 test) */
.L_btn_b_handler:
    mov.l @r6, r6              ! r6 = btn_b_data_source address
    mov.l   .L_btn_b_dst, r5  ! r5 = &btn_b_data_dest_ptr
    mov.l @r5, r5              ! r5 = btn_b_data_dest address
    jsr @r8                    ! display_channel_b(src=r6, dst=r5, mode=32)
    mov #0x20, r4              ! r4 = 32 (channel mode, in delay slot)

    /* === Channel A event dispatch section === */
    /* Tests bits 16-19 of input state, dispatches to display_channel_a */

    /* Bit 16: Channel A event 0 (0x00010000) */
.L_check_chan_a0:
    mov.l @r14, r3             ! r3 = input_state_word
    mov.l   .L_evt_bit16, r2  ! r2 = 0x00010000 (bit 16 mask)
    and r2, r3                 ! r3 = input_state & bit16_mask
    tst r3, r3                 ! bit 16 set?
    bt      .L_check_chan_a1   ! no: skip to event 1
    mov.l   .L_chan_a0_src, r6 ! r6 = &chan_a0_source_ptr
    mov.l   .L_chan_a0_dst, r5 ! r5 = &chan_a0_dest_ptr
    mov.l @r6, r6              ! r6 = chan_a0_source address
    mov.l @r5, r5              ! r5 = chan_a0_dest address
    jsr @r9                    ! display_channel_a(src=r6, dst=r5, mode=4)
    mov #0x4, r4               ! r4 = 4 (channel mode, in delay slot)

    /* Bit 17: Channel A event 1 (0x00020000) */
.L_check_chan_a1:
    mov.l @r14, r3             ! r3 = input_state_word
    mov.l   .L_evt_bit17, r2  ! r2 = 0x00020000 (bit 17 mask)
    and r2, r3                 ! r3 = input_state & bit17_mask
    tst r3, r3                 ! bit 17 set?
    bt      .L_check_chan_a2   ! no: skip to event 2
    mov.l   .L_chan_a1_src, r6 ! r6 = &chan_a1_source_ptr
    mov.l   .L_chan_a1_dst, r5 ! r5 = &chan_a1_dest_ptr
    mov.l @r6, r6              ! r6 = chan_a1_source address
    mov.l @r5, r5              ! r5 = chan_a1_dest address
    jsr @r9                    ! display_channel_a(src=r6, dst=r5, mode=8)
    mov #0x8, r4               ! r4 = 8 (channel mode, in delay slot)

    /* Bit 18: Channel A event 2 (0x00040000) */
.L_check_chan_a2:
    mov.l @r14, r3             ! r3 = input_state_word
    mov.l   .L_evt_bit18, r2  ! r2 = 0x00040000 (bit 18 mask)
    and r2, r3                 ! r3 = input_state & bit18_mask
    tst r3, r3                 ! bit 18 set?
    bt      .L_check_chan_a3   ! no: skip to event 3
    mov.l   .L_chan_a2_src, r6 ! r6 = &chan_a2_source_ptr
    mov.l   .L_chan_a2_dst, r5 ! r5 = &chan_a2_dest_ptr
    mov.l @r6, r6              ! r6 = chan_a2_source address
    mov.l @r5, r5              ! r5 = chan_a2_dest address
    jsr @r9                    ! display_channel_a(src=r6, dst=r5, mode=16)
    mov #0x10, r4              ! r4 = 16 (channel mode, in delay slot)

    /* Bit 19: Channel A event 3 (0x00080000) */
.L_check_chan_a3:
    mov.l @r14, r3             ! r3 = input_state_word
    mov.l   .L_evt_bit19, r2  ! r2 = 0x00080000 (bit 19 mask)
    and r2, r3                 ! r3 = input_state & bit19_mask
    tst r3, r3                 ! bit 19 set?
    bt      .L_check_handler_a ! no: skip to system events
    mov.l   .L_chan_a3_src, r6 ! r6 = &chan_a3_source_ptr
    mov.l   .L_chan_a3_dst, r5 ! r5 = &chan_a3_dest_ptr
    mov.l @r6, r6              ! r6 = chan_a3_source address
    mov.l @r5, r5              ! r5 = chan_a3_dest address
    jsr @r9                    ! display_channel_a(src=r6, dst=r5, mode=32)
    mov #0x20, r4              ! r4 = 32 (channel mode, in delay slot)

    /* === System event dispatch section === */

    /* Bit 31: Special handler A (0x80000000) */
.L_check_handler_a:
    mov.l @r14, r3             ! r3 = input_state_word
    mov.l   .L_evt_bit31, r2  ! r2 = 0x80000000 (bit 31 mask)
    and r2, r3                 ! r3 = input_state & bit31_mask
    tst r3, r3                 ! bit 31 set?
    bt      .L_check_handler_b ! no: skip to handler B
    mov.l   .L_fn_handler_a, r3  ! r3 = &special_handler_a function
    jsr @r3                    ! call special_handler_a()
    nop                        ! (delay slot)

    /* Bit 30: Special handler B (0x40000000) */
.L_check_handler_b:
    mov.l @r14, r2             ! r2 = input_state_word
    mov.l   .L_evt_bit30, r3  ! r3 = 0x40000000 (bit 30 mask)
    and r3, r2                 ! r2 = input_state & bit30_mask
    tst r2, r2                 ! bit 30 set?
    bt      .L_check_channels_reload ! no: skip to channels reload
    mov.l   .L_fn_handler_b, r3  ! r3 = &special_handler_b function
    jsr @r3                    ! call special_handler_b()
    nop                        ! (delay slot)

    /* Bit 20: Display channels reload (0x00100000) */
.L_check_channels_reload:
    mov.l @r14, r2             ! r2 = input_state_word
    mov.l   .L_evt_bit20, r3  ! r3 = 0x00100000 (bit 20 mask)
    and r3, r2                 ! r2 = input_state & bit20_mask
    tst r2, r2                 ! bit 20 set?
    bt      .L_check_collision ! no: skip to collision update
    mov.l   .L_fn_channels_load, r3  ! r3 = &display_channels_load function
    jsr @r3                    ! display_channels_load()
    nop                        ! (delay slot)

    /* Bit 26: Collision update (0x04000000) */
.L_check_collision:
    mov.l @r14, r2             ! r2 = input_state_word
    mov.l   .L_evt_bit26, r3  ! r3 = 0x04000000 (bit 26 mask)
    and r3, r2                 ! r2 = input_state & bit26_mask
    tst r2, r2                 ! bit 26 set?
    bt      .L_check_physics   ! no: skip to physics update
    mov.l   .L_fn_collision, r3  ! r3 = &obj_collision_update function
    jsr @r3                    ! obj_collision_update()
    nop                        ! (delay slot)

    /* Bit 27: Physics update (0x08000000) */
.L_check_physics:
    mov.l @r14, r2             ! r2 = input_state_word
    mov.l   .L_evt_bit27, r3  ! r3 = 0x08000000 (bit 27 mask)
    and r3, r2                 ! r2 = input_state & bit27_mask
    tst r2, r2                 ! bit 27 set?
    bt      .L_clear_input     ! no: skip to input clear
    mov.l   .L_fn_physics, r3 ! r3 = &physics_update function
    jsr @r3                    ! call physics_update()
    nop                        ! (delay slot)

    /* Clear input state and exit */
.L_clear_input:
    mov.l r12, @r14            ! input_state_word = 0 (consume all events)
.L_exit_epilogue:
    mov #0x2, r2               ! r2 = 2 (processing complete marker)
    mov.l   .L_run_flag_exit, r3  ! r3 = &run_flag
    mov.l r2, @r3              ! run_flag = 2 (done)
    lds.l @r15+, pr            ! restore return address from stack
    mov.l @r15+, r8            ! restore r8 from stack
    mov.l @r15+, r9            ! restore r9 from stack
    mov.l @r15+, r10           ! restore r10 from stack
    mov.l @r15+, r11           ! restore r11 from stack
    mov.l @r15+, r12           ! restore r12 from stack
    mov.l @r15+, r13           ! restore r13 from stack
    rts                        ! return to caller
    mov.l @r15+, r14           ! restore r14 from stack (in delay slot)

    /* === Constant pool: event dispatch === */
.L_btn_b_dst:
    .4byte  sym_0605B714       ! B button: data dest ptr
.L_evt_bit16:
    .4byte  0x00010000         ! bit 16 mask -- channel A event 0
.L_chan_a0_src:
    .4byte  sym_0605B6E0       ! channel A event 0: source ptr
.L_chan_a0_dst:
    .4byte  sym_0605B6DC       ! channel A event 0: dest ptr
.L_evt_bit17:
    .4byte  0x00020000         ! bit 17 mask -- channel A event 1
.L_chan_a1_src:
    .4byte  sym_0605B6E8       ! channel A event 1: source ptr
.L_chan_a1_dst:
    .4byte  sym_0605B6E4       ! channel A event 1: dest ptr
.L_evt_bit18:
    .4byte  0x00040000         ! bit 18 mask -- channel A event 2
.L_chan_a2_src:
    .4byte  sym_0605B6F0       ! channel A event 2: source ptr
.L_chan_a2_dst:
    .4byte  sym_0605B6EC       ! channel A event 2: dest ptr
.L_evt_bit19:
    .4byte  0x00080000         ! bit 19 mask -- channel A event 3
.L_chan_a3_src:
    .4byte  sym_0605B6F8       ! channel A event 3: source ptr
.L_chan_a3_dst:
    .4byte  sym_0605B6F4       ! channel A event 3: dest ptr
.L_evt_bit31:
    .4byte  0x80000000         ! bit 31 mask -- special handler A
.L_fn_handler_a:
    .4byte  sym_060149E0       ! special handler A function
.L_evt_bit30:
    .4byte  0x40000000         ! bit 30 mask -- special handler B
.L_fn_handler_b:
    .4byte  sym_060149CC       ! special handler B function
.L_evt_bit20:
    .4byte  0x00100000         ! bit 20 mask -- display channels reload
.L_fn_channels_load:
    .4byte  display_channels_load  ! function pointer: display_channels_load
.L_evt_bit26:
    .4byte  0x04000000         ! bit 26 mask -- collision update
.L_fn_collision:
    .4byte  obj_collision_update   ! function pointer: obj_collision_update
.L_evt_bit27:
    .4byte  0x08000000         ! bit 27 mask -- physics update
.L_fn_physics:
    .4byte  sym_06033354       ! physics update function
.L_run_flag_exit:
    .4byte  sym_06059F54       ! run flag (same address as .L_run_flag)

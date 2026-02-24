/* button_input_read.s -- Main per-frame input/event dispatch
 * Translation unit: 0x06006F3C - 0x06007268
 *
 * Function catalog:
 *   button_input_read — Per-frame input consumer and event dispatcher.
 *                       Reads processed input state (32-bit button/event word),
 *                       tests individual bit flags, dispatches to handlers.
 *
 * Input state word layout (at sym_0605B6D8):
 *   Bits [7:0]   — Button flags (active-HIGH, set = pressed):
 *     bit 2  (0x04)       — D-pad Right
 *     bit 4  (0x10)       — D-pad Left
 *     bit 5  (0x20)       — Start button
 *     bit 6  (0x40)       — A button (gas/accelerate)
 *     bit 7  (0x80)       — B button (brake)
 *   Bits [19:16] — Display channel A events:
 *     bit 16 (0x00010000) — Channel A event 0
 *     bit 17 (0x00020000) — Channel A event 1
 *     bit 18 (0x00040000) — Channel A event 2
 *     bit 19 (0x00080000) — Channel A event 3
 *   Bits [31:20] — System events:
 *     bit 20 (0x00100000) — Display channels reload
 *     bit 26 (0x04000000) — Collision update trigger
 *     bit 27 (0x08000000) — Physics update trigger
 *     bit 29 (0x20000000) — DMA transfer trigger (special)
 *     bit 30 (0x40000000) — Special handler B
 *     bit 31 (0x80000000) — Special handler A
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
    mov.l r14, @-r15
    mov #0x1, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_disp_channel_b, r8
    mov.l   .L_fn_disp_channel_a, r9
    mov.l   .L_fn_scene_dispatch, r10
    mov.l   .L_game_state_flag, r11
    mov.l   .L_frame_counter, r13
    mov.l   .L_input_state_ptr, r14
    mov.l   .L_tick_counter, r4
    mov.l @r4, r3
    add #0x1, r3               /* tick_counter++ */
    mov.l r3, @r4
    mov.l   .L_run_flag, r3
    mov.l r2, @r3              /* run_flag = 1 */
    mov.l   .L_skip_flag, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0                 /* skip_flag == 0? */
    bt/s    .L_06006F76        /* yes: proceed with input processing */
    mov #0x0, r12              /* r12 = 0 (cleared events) */
    bra     .L_060071F0        /* no: skip to exit */
    nop

    /* === VDP framebuffer mode handling === */
.L_06006F76:
    mov.l   .L_display_mode, r3
    mov.l r12, @r3             /* display_mode = 0 */
    mov.l   .L_vdp_mode, r4
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x2, r0            /* VDP mode == 2? (manual erase) */
    bf      .L_06006F98
    mov.l @r11, r0
    tst r0, r0                 /* game state active? */
    bt      .L_06007058        /* no: skip to button dispatch */
    jsr @r10                   /* scene_data_dispatch() */
    nop
    mov #0x2, r3
    mov.l   .L_display_mode, r2
    mov.l r3, @r2              /* display_mode = 2 */
    bra     .L_06007058
    nop
.L_06006F98:
    mov.l   .L_vdp1_fbcr, r6
    mov.l   .L_fbcr_state, r5
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x3, r0            /* VDP mode == 3? (VBlank erase) */
    bf      .L_06006FCA
    mov.l @r11, r0
    tst r0, r0
    bt      .L_06007058
    mov.l   .L_tvmr_state, r0
    mov.l   .L_vdp1_tvmr, r3
    mov.w @r0, r0
    extu.w r0, r0
    or #0x8, r0                /* set VBE (vblank erase) bit */
    mov.w r0, @r3              /* write TVMR */
    mov.w @r5, r0
    extu.w r0, r0
    or #0x3, r0                /* set FCM + FCT (manual fb change + trigger) */
    jsr @r10                   /* scene_data_dispatch() */
    mov.w r0, @r6              /* write FBCR */
    mov #0x3, r3
    mov.l   .L_display_mode, r2
    mov.l r3, @r2              /* display_mode = 3 */
    bra     .L_06007058
    nop
.L_06006FCA:
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2                 /* VDP mode == 0? (default) */
    bf      .L_06007018
    jsr @r10                   /* scene_data_dispatch() */
    nop
    bra     .L_06007058
    mov.l r12, @r11            /* game_state = 0 */
    .2byte  0xFFFF             /* padding */

    /* === Constant pool: setup pointers === */
.L_fn_disp_channel_b:
    .4byte  display_channel_b
.L_fn_disp_channel_a:
    .4byte  display_channel_a
.L_fn_scene_dispatch:
    .4byte  scene_data_dispatch
.L_game_state_flag:
    .4byte  sym_060635C4       /* game state active flag */
.L_frame_counter:
    .4byte  sym_060635C0       /* per-input frame counter */
.L_input_state_ptr:
    .4byte  sym_0605B6D8       /* processed input state (32-bit button/event word) */
.L_tick_counter:
    .4byte  sym_0607864C       /* global tick counter */
.L_run_flag:
    .4byte  sym_06059F54       /* input processing run flag */
.L_skip_flag:
    .4byte  sym_0605A00C       /* input skip flag (nonzero = skip) */
.L_display_mode:
    .4byte  sym_06063F58       /* display/VDP mode state */
.L_vdp_mode:
    .4byte  sym_060635B4       /* VDP framebuffer mode selector */
.L_vdp1_fbcr:
    .4byte  0x25D00002                  /* VDP1 FBCR — framebuffer control */
.L_fbcr_state:
    .4byte  sym_060A4C92       /* cached FBCR value */
.L_tvmr_state:
    .4byte  sym_060A4C90       /* cached TVMR value */
.L_vdp1_tvmr:
    .4byte  0x25D00000                  /* VDP1 TVMR — TV mode */

    /* === Framebuffer swap timing (VDP mode 1) === */
.L_06007018:
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13             /* frame_counter++ */
    mov.l   .L_fb_swap_enable, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0            /* fb swap enabled? */
    bf      .L_0600703C
    mov.l   .L_fb_swap_delay, r2
    mov.l @r13, r3
    mov.l @r2, r2
    add #-0x1, r2
    cmp/gt r3, r2              /* frame_counter < delay - 1? */
    bt      .L_0600703C
    mov.w @r5, r0              /* read cached FBCR */
    extu.w r0, r0
    or #0x2, r0                /* set FCM (manual change mode) */
    extu.w r0, r0
    mov.w r0, @r6              /* write VDP1 FBCR */
.L_0600703C:
    mov.l   .L_fb_swap_delay, r3
    mov.l @r13, r2
    mov.l @r3, r3
    cmp/gt r2, r3              /* frame_counter < delay? */
    bt      .L_06007058        /* yes: not ready yet */
    mov.l @r11, r0
    tst r0, r0
    bt      .L_06007056
    jsr @r10                   /* scene_data_dispatch() */
    nop
    mov #0x1, r3
    mov.l   .L_display_mode_b, r2
    mov.l r3, @r2              /* display_mode = 1 */
.L_06007056:
    mov.l r12, @r13            /* reset frame_counter = 0 */

    /* === Button dispatch section === */
    /* Tests individual bit flags in the input state word @r14 */
    /* and dispatches to corresponding handlers */
.L_06007058:
    mov.l   .L_car_array_idx, r3
    mov.l   .L_car_select, r1
    mov.l @r3, r3
    mov.l @r1, r1
    shlr2 r3                   /* compute car struct offset: */
    shlr r1                    /* index * 0x268 (car struct size) */
    mov r3, r2                 /* r2 = index / 4 */
    shll2 r3                   /* r3 = (index/4) * 16 */
    shll2 r2                   /* r2 = (index/4) * 16 * 4 = ... */
    shll2 r3                   /* r3 = r3 * 16 = 0x100 */
    shll2 r2                   /* r2 * 16 = 0x400 */
    shll2 r2                   /* r2 * 4 = 0x1000 (scaled) */
    add r2, r3                 /* r3 = combined offset */
    add r1, r3                 /* add car select half */
    mov.l   .L_car_base, r2
    add r2, r3                 /* r3 = &car[index] (base + offset) */
    mov.l   .L_current_car, r2
    mov.l r3, @r2              /* current_car = &car[index] */

    /* Bit 29: DMA transfer trigger (0x20000000) */
    mov.l @r14, r1             /* r1 = input state */
    mov.l   .L_bit29_dma, r2
    and r2, r1
    tst r1, r1
    bt      .L_06007094        /* not set: skip */
    mov.w   .L_dma_size_a, r6  /* r6 = 0x0640 (DMA transfer size) */
    mov.l   .L_current_car, r5
    mov.l   .L_dma_dst_a, r4
    mov.l   .L_fn_dma_transfer, r3
    mov.l @r5, r5              /* r5 = current car address (source) */
    jsr @r3                    /* dma_transfer(dst, src, size) */
    mov.l @r4, r4              /* r4 = DMA destination */

    /* Bit 2: D-pad Right (0x04) */
.L_06007094:
    mov.l @r14, r0
    tst #0x4, r0
    bt      .L_060070A8        /* not pressed: skip */
    mov.w   .L_dma_size_b, r6  /* r6 = 0x0E00 (DMA transfer size) */
    mov.l   .L_dma_src_b, r5
    mov.l   .L_dma_dst_b, r4
    mov.l   .L_fn_dma_transfer, r3
    mov.l @r5, r5
    jsr @r3                    /* dma_transfer(dst, src, size) */
    mov.l @r4, r4

    /* Bit 4: D-pad Left (0x10) */
.L_060070A8:
    mov.l @r14, r0
    tst #0x10, r0
    bt      .L_060070BA
    mov.l   .L_btn_left_a, r6
    mov.l   .L_btn_left_b, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8                    /* display_channel_b(src, dst, 4) */
    mov #0x4, r4

    /* Bit 5: Start button (0x20) */
.L_060070BA:
    mov.l @r14, r0
    tst #0x20, r0
    bt      .L_060070CC
    mov.l   .L_btn_start_a, r6
    mov.l   .L_btn_start_b, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8                    /* display_channel_b(src, dst, 8) */
    mov #0x8, r4

    /* Bit 6: A button — gas (0x40) */
.L_060070CC:
    mov.l @r14, r0
    tst #0x40, r0
    bt      .L_060070DE
    mov.l   .L_btn_a_src, r6
    mov.l   .L_btn_a_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8                    /* display_channel_b(src, dst, 16) */
    mov #0x10, r4

    /* Bit 7: B button — brake (0x80) */
.L_060070DE:
    mov.l @r14, r0
    tst #0x80, r0
    bt      .L_06007146        /* not pressed: skip to channel A section */
    mov.l   .L_btn_b_src, r6
    bra     .L_0600713C        /* B button has special extended handler */
    nop

    /* === Word pool entries === */
.L_dma_size_a:
    .2byte  0x0640              /* DMA transfer size for bit 29 trigger */
.L_dma_size_b:
    .2byte  0x0E00              /* DMA transfer size for D-pad Right */
    .2byte  0xFFFF              /* padding */

    /* === Constant pool: framebuffer timing === */
.L_fb_swap_enable:
    .4byte  sym_060635B8       /* framebuffer swap enable flag */
.L_fb_swap_delay:
    .4byte  sym_060635BC       /* framebuffer swap delay (frame count) */
.L_display_mode_b:
    .4byte  sym_06063F58       /* display mode (same as .L_display_mode) */
.L_car_array_idx:
    .4byte  sym_06059F3C       /* car array index */
.L_car_select:
    .4byte  sym_06059F38       /* car selection */
.L_car_base:
    .4byte  sym_0606B178       /* car array base address */
.L_current_car:
    .4byte  sym_06059F34       /* pointer to current car struct */
.L_bit29_dma:
    .4byte  0x20000000         /* bit 29 mask — DMA trigger event */
.L_dma_dst_a:
    .4byte  sym_06063F60       /* DMA destination for bit 29 */
.L_fn_dma_transfer:
    .4byte  dma_transfer
.L_dma_src_b:
    .4byte  sym_0606129C       /* DMA source for D-pad Right */
.L_dma_dst_b:
    .4byte  sym_060612B4       /* DMA destination for D-pad Right */
.L_btn_left_a:
    .4byte  sym_0605B700       /* D-pad Left: data source ptr */
.L_btn_left_b:
    .4byte  sym_0605B6FC       /* D-pad Left: data dest ptr */
.L_btn_start_a:
    .4byte  sym_0605B708       /* Start: data source ptr */
.L_btn_start_b:
    .4byte  sym_0605B704       /* Start: data dest ptr */
.L_btn_a_src:
    .4byte  sym_0605B710       /* A button: data source ptr */
.L_btn_a_dst:
    .4byte  sym_0605B70C       /* A button: data dest ptr */
.L_btn_b_src:
    .4byte  sym_0605B718       /* B button: data source ptr */

    /* B button extended handler (falls through from bit 7 test) */
.L_0600713C:
    mov.l @r6, r6
    mov.l   .L_btn_b_dst, r5
    mov.l @r5, r5
    jsr @r8                    /* display_channel_b(src, dst, 32) */
    mov #0x20, r4

    /* === Channel A event dispatch section === */
    /* Tests bits 16-19 of input state, dispatches to display_channel_a */

    /* Bit 16: Channel A event 0 (0x00010000) */
.L_06007146:
    mov.l @r14, r3
    mov.l   .L_evt_bit16, r2
    and r2, r3
    tst r3, r3
    bt      .L_0600715C
    mov.l   .L_chan_a0_src, r6
    mov.l   .L_chan_a0_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9                    /* display_channel_a(src, dst, 4) */
    mov #0x4, r4

    /* Bit 17: Channel A event 1 (0x00020000) */
.L_0600715C:
    mov.l @r14, r3
    mov.l   .L_evt_bit17, r2
    and r2, r3
    tst r3, r3
    bt      .L_06007172
    mov.l   .L_chan_a1_src, r6
    mov.l   .L_chan_a1_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9                    /* display_channel_a(src, dst, 8) */
    mov #0x8, r4

    /* Bit 18: Channel A event 2 (0x00040000) */
.L_06007172:
    mov.l @r14, r3
    mov.l   .L_evt_bit18, r2
    and r2, r3
    tst r3, r3
    bt      .L_06007188
    mov.l   .L_chan_a2_src, r6
    mov.l   .L_chan_a2_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9                    /* display_channel_a(src, dst, 16) */
    mov #0x10, r4

    /* Bit 19: Channel A event 3 (0x00080000) */
.L_06007188:
    mov.l @r14, r3
    mov.l   .L_evt_bit19, r2
    and r2, r3
    tst r3, r3
    bt      .L_0600719E
    mov.l   .L_chan_a3_src, r6
    mov.l   .L_chan_a3_dst, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9                    /* display_channel_a(src, dst, 32) */
    mov #0x20, r4

    /* === System event dispatch section === */

    /* Bit 31: Special handler A (0x80000000) */
.L_0600719E:
    mov.l @r14, r3
    mov.l   .L_evt_bit31, r2
    and r2, r3
    tst r3, r3
    bt      .L_060071AE
    mov.l   .L_fn_handler_a, r3
    jsr @r3
    nop

    /* Bit 30: Special handler B (0x40000000) */
.L_060071AE:
    mov.l @r14, r2
    mov.l   .L_evt_bit30, r3
    and r3, r2
    tst r2, r2
    bt      .L_060071BE
    mov.l   .L_fn_handler_b, r3
    jsr @r3
    nop

    /* Bit 20: Display channels reload (0x00100000) */
.L_060071BE:
    mov.l @r14, r2
    mov.l   .L_evt_bit20, r3
    and r3, r2
    tst r2, r2
    bt      .L_060071CE
    mov.l   .L_fn_channels_load, r3
    jsr @r3                    /* display_channels_load() */
    nop

    /* Bit 26: Collision update (0x04000000) */
.L_060071CE:
    mov.l @r14, r2
    mov.l   .L_evt_bit26, r3
    and r3, r2
    tst r2, r2
    bt      .L_060071DE
    mov.l   .L_fn_collision, r3
    jsr @r3                    /* obj_collision_update() */
    nop

    /* Bit 27: Physics update (0x08000000) */
.L_060071DE:
    mov.l @r14, r2
    mov.l   .L_evt_bit27, r3
    and r3, r2
    tst r2, r2
    bt      .L_060071EE
    mov.l   .L_fn_physics, r3
    jsr @r3
    nop

    /* Clear input state and exit */
.L_060071EE:
    mov.l r12, @r14            /* input_state = 0 (consume all events) */
.L_060071F0:
    mov #0x2, r2
    mov.l   .L_run_flag_exit, r3
    mov.l r2, @r3              /* run_flag = 2 (done) */
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    /* === Constant pool: event dispatch === */
.L_btn_b_dst:
    .4byte  sym_0605B714       /* B button: data dest ptr */
.L_evt_bit16:
    .4byte  0x00010000         /* bit 16 mask — channel A event 0 */
.L_chan_a0_src:
    .4byte  sym_0605B6E0       /* channel A event 0: source ptr */
.L_chan_a0_dst:
    .4byte  sym_0605B6DC       /* channel A event 0: dest ptr */
.L_evt_bit17:
    .4byte  0x00020000         /* bit 17 mask — channel A event 1 */
.L_chan_a1_src:
    .4byte  sym_0605B6E8       /* channel A event 1: source ptr */
.L_chan_a1_dst:
    .4byte  sym_0605B6E4       /* channel A event 1: dest ptr */
.L_evt_bit18:
    .4byte  0x00040000         /* bit 18 mask — channel A event 2 */
.L_chan_a2_src:
    .4byte  sym_0605B6F0       /* channel A event 2: source ptr */
.L_chan_a2_dst:
    .4byte  sym_0605B6EC       /* channel A event 2: dest ptr */
.L_evt_bit19:
    .4byte  0x00080000         /* bit 19 mask — channel A event 3 */
.L_chan_a3_src:
    .4byte  sym_0605B6F8       /* channel A event 3: source ptr */
.L_chan_a3_dst:
    .4byte  sym_0605B6F4       /* channel A event 3: dest ptr */
.L_evt_bit31:
    .4byte  0x80000000         /* bit 31 mask — special handler A */
.L_fn_handler_a:
    .4byte  sym_060149E0       /* special handler A function */
.L_evt_bit30:
    .4byte  0x40000000         /* bit 30 mask — special handler B */
.L_fn_handler_b:
    .4byte  sym_060149CC       /* special handler B function */
.L_evt_bit20:
    .4byte  0x00100000         /* bit 20 mask — display channels reload */
.L_fn_channels_load:
    .4byte  display_channels_load
.L_evt_bit26:
    .4byte  0x04000000         /* bit 26 mask — collision update */
.L_fn_collision:
    .4byte  obj_collision_update
.L_evt_bit27:
    .4byte  0x08000000         /* bit 27 mask — physics update */
.L_fn_physics:
    .4byte  sym_06033354       /* physics update function */
.L_run_flag_exit:
    .4byte  sym_06059F54       /* run flag (same as .L_run_flag) */

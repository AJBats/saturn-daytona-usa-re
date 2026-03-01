
    .section .text.FUN_0600C010


    .global scene_render_body
    .type scene_render_body, @function
scene_render_body:
    sts.l pr, @-r15
    mov.l   .L_pool_0600C094, r8
    mov.w   .L_wpool_0600C090, r10
    mov.l   .L_pool_0600C098, r12
    mov.l   .L_pool_0600C09C, r13
    mov.l   .L_pool_0600C0A0, r0
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_skip_secondary_init
    mov #0x0, r9
    mov.l   .L_pool_0600C0A4, r4
    mov.l   .L_pool_0600C0A8, r3
    jsr @r3
    mov.l @r4, r4
.L_skip_secondary_init:
    mov.l @r8, r2
    mov.l   .L_pool_0600C0AC, r3
    and r3, r2
    tst r2, r2
    bf      .L_past_render_dispatch
    mov.l   .L_pool_0600C0B0, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_render_path_b
    mov.l   .L_pool_0600C0B4, r3
    jsr @r3
    nop
    bra     .L_past_render_dispatch
    nop
.L_render_path_b:
    mov.l   .L_pool_0600C0B8, r3
    jsr @r3
    nop
.L_past_render_dispatch:
    mov.l @r8, r2
    mov.l   .L_pool_0600C0BC, r3
    cmp/eq r3, r2
    bf      .L_past_state17_render
    mov.l   .L_pool_0600C0C0, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_past_state17_render
    mov.l   .L_pool_0600C0C4, r3
    jsr @r3
    nop
.L_past_state17_render:
    mov #0x30, r6
    mov.l @r12, r2
    add #0x30, r2
    mov.l r2, @r12
    mov.l   .L_pool_0600C0C8, r5
    mov.l   .L_pool_0600C0CC, r3
    mov.l @r5, r5
    jsr @r3
    mov r2, r4
    mov.l   .L_pool_0600C0D0, r4
    mov.l   .L_pool_0600C0D4, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_use_lod_config_count
    mov.l   .L_pool_0600C0D8, r3
    mov.l @r3, r3
    shar r3
    exts.w r3, r3
    mov.w r3, @r4
    bra     .L_set_secondary_callback
    nop
.L_wpool_0600C090:
    .2byte  0xFE11                      /* hardware status address mask fragment */
    .2byte  0xFFFF                      /* padding / alignment */
.L_pool_0600C094:
    .4byte  sym_0607EBC4                /* game state bitmask (read by @r8) */
.L_pool_0600C098:
    .4byte  sym_0608A52C                /* render budget counter (frame alloc tracking) */
.L_pool_0600C09C:
    .4byte  sym_0605A1DD                /* LOD config byte (object detail level) */
.L_pool_0600C0A0:
    .4byte  sym_06083255                /* secondary SH-2 processing flag (byte) */
.L_pool_0600C0A4:
    .4byte  sym_0607EB8C                /* argument pointer for secondary dispatch */
.L_pool_0600C0A8:
    .4byte  vblank_handler              /* per-frame update / secondary dispatch */
.L_pool_0600C0AC:
    .4byte  0x02000000                  /* state 25 bitmask (bit 25) */
.L_pool_0600C0B0:
    .4byte  sym_06078635                /* render mode flag (byte: 0=path B, else=path A) */
.L_pool_0600C0B4:
    .4byte  sym_0600D336                /* render path A function */
.L_pool_0600C0B8:
    .4byte  physics_calc_dispatch       /* render path B / physics calc dispatch */
.L_pool_0600C0BC:
    .4byte  0x00020000                  /* state 17 bitmask (0x20000) — 2.0 in 16.16 fixed-point */
.L_pool_0600C0C0:
    .4byte  sym_0607EAE0                /* state 17 guard (long: 0 = allow special render) */
.L_pool_0600C0C4:
    .4byte  sym_0602E610                /* state 17 special rendering function */
.L_pool_0600C0C8:
    .4byte  sym_06089EDC                /* source data for render budget copy */
.L_pool_0600C0CC:
    .4byte  memcpy_long_idx             /* indexed long memory copy function */
.L_pool_0600C0D0:
    .4byte  sym_06078664                /* object iteration count target (halfword) */
.L_pool_0600C0D4:
    .4byte  sym_06059F30                /* object count mode (0=compute, else=use config) */
.L_pool_0600C0D8:
    .4byte  sym_0607EA98                /* total renderable object count */
.L_use_lod_config_count:
    mov.b @r13, r2
    extu.b r2, r2
    mov.w r2, @r4
.L_set_secondary_callback:
    .byte   0xD3, 0x29    /* mov.l .L_pool_secondary_callback_fn, r3 -- r3 = FUN_0600C170 (secondary rendering callback) */
    .byte   0xD2, 0x29    /* mov.l .L_pool_secondary_callback_ptr, r2 -- r2 = &secondary_callback_ptr (sym_06063574) */
    mov.l r3, @r2
    .byte   0xD3, 0x29    /* mov.l .L_pool_minit_value, r3 -- r3 = 0x0000FFFF (MINIT trigger value) */
    .byte   0xD2, 0x2A    /* mov.l .L_pool_minit_register, r2 -- r2 = 0x21000000 (VDP/MINIT hardware register) */
    mov.w r3, @r2
    mov.l @r8, r3
    .byte   0xD2, 0x29    /* mov.l .L_pool_skip_update_mask, r2 -- r2 = 0x02800008 (states 3+19+25 combined mask) */
    and r2, r3
    tst r3, r3
    bf      .L_skip_per_frame_update
    .byte   0xD3, 0x28    /* mov.l .L_pool_fn_per_frame_update, r3 -- r3 = FUN_060058FA (per-frame update) */
    jsr @r3
    nop
.L_skip_per_frame_update:
    .byte   0xD3, 0x28    /* mov.l .L_pool_fn_scene_post_render, r3 -- r3 = scene_post_render (FUN_06006868) */
    jsr @r3
    nop
    .byte   0xBA, 0xCC    /* bsr 0x0600B6A0 (external) -- call CS0 object rendering loop */
    nop
    mov.l @r8, r2
    .byte   0xD3, 0x26    /* mov.l .L_pool_0600C0AC_b, r3 -- r3 = 0x02000000 (state 25) */
    cmp/eq r3, r2
    bt      .L_begin_hw_poll
    .byte   0xD3, 0x25    /* mov.l .L_pool_fn_post_render_dispatch, r3 -- r3 = FUN_0601BDEC (post-render) */
    jsr @r3
    nop
    bra     .L_begin_hw_poll
    nop
.L_set_lod_increment:
    mov r11, r9
.L_begin_hw_poll:
    mov.b @r10, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_set_lod_increment
    mov.b @r10, r0
    and #0xF, r0
    mov.b r0, @r10
    tst r9, r9
    bt      .L_lod_decrement_path
    mov.b @r13, r3
    .byte   0xD2, 0x1E    /* mov.l .L_pool_0600C0D8_b, r2 -- r2 = &total_obj_count (sym_0607EA98) */
    extu.b r3, r3
    mov.l @r2, r2
    cmp/ge r2, r3
    bt      .L_lod_adjustment_done
    mov.b @r13, r2
    add #0x1, r2
    bra     .L_lod_adjustment_done
    mov.b r2, @r13
.L_lod_decrement_path:
    mov.b @r13, r2
    extu.b r2, r2
    cmp/gt r11, r2
    bf      .L_lod_adjustment_done
    mov.b @r13, r2
    add #-0x1, r2
    mov.b r2, @r13
.L_lod_adjustment_done:
    .byte   0xD3, 0x17    /* mov.l .L_pool_fn_render_finalize, r3 -- r3 = sym_0603C000 (render finalize) */
    jsr @r3
    nop
    mov.l @r12, r2
    add #-0x30, r2
    mov.l r2, @r12
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

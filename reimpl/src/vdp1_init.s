
    .section .text.FUN_0600A140


    .global vdp1_init
    .type vdp1_init, @function
vdp1_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r14

    mov.l   _pool_vdp1_end_cmd, r3
    mov.l   _pool_vdp1_vram_base, r2
    mov.l r3, @r2

    mov.l   _pool_vdp1_fb_base, r5
    mov.l   _pool_fb_clear_count, r4
.L_clear_plane_a:
    mov r5, r3
    add #-0x2, r4
    add #0x4, r5
    mov.l r14, @r3
    mov r5, r2
    add #0x4, r5
    tst r4, r4
    bf/s    .L_clear_plane_a
    mov.l r14, @r2

    mov.l   _pool_fb_swap_flag, r3
    mov.l r14, @r3
    mov.l   _pool_display_update_fn, r3
    jsr @r3
    nop
    mov.l   _pool_vblank_phase, r3
    mov.l r14, @r3

    mov.l   _pool_vdp1_fb_base, r5
    mov.l   _pool_fb_clear_count, r4
.L_clear_plane_b:
    mov r5, r2
    add #-0x2, r4
    add #0x4, r5
    mov.l r14, @r2
    mov r5, r3
    add #0x4, r5
    tst r4, r4
    bf/s    .L_clear_plane_b
    mov.l r14, @r3

    mov.l   _pool_fb_swap_flag, r3
    mov.l r14, @r3
    mov.l   _pool_display_update_fn, r3
    jsr @r3
    nop
    mov.l   _pool_vblank_phase, r3
    mov.l r14, @r3

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF

_pool_vdp1_end_cmd:
    .4byte  0x80000000
_pool_vdp1_vram_base:
    .4byte  0x25C00000
_pool_vdp1_fb_base:
    .4byte  0x25C80000
_pool_fb_clear_count:
    .4byte  0x00010000
_pool_fb_swap_flag:
    .4byte  sym_0605A00C
_pool_display_update_fn:
    .4byte  sym_06026CE0
_pool_vblank_phase:
    .4byte  sym_06059F44
    .4byte  0xD01B6000
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
    mov #0x3, r7
    mov.l   _pool_line_count_ptr, r5
    mov.l   _pool_fb_res_mode_a, r4
    mov.l   _pool_player_mode_a, r0
    mov.l @r0, r0
    tst r0, r0
    bf/s    .L_nonzero_player_mode
    mov #0x4, r6

    mov.l @r5, r3
    mov.w   DAT_0600a224, r2
    cmp/eq r2, r3
    bf      .L_try_single_lo
    exts.w r7, r7
    bra     .L_res_select_done
    mov.w r7, @r4
.L_try_single_lo:
    mov.l @r5, r2
    mov.w   _wpool_single_lo_thresh, r3
    cmp/eq r3, r2
    bf      .L_single_no_match
    exts.w r6, r6
    mov.w r6, @r4
.L_single_no_match:
    bra     .L_res_select_done
    nop

    .global DAT_0600a224
DAT_0600a224:
    .2byte  0x00C4
_wpool_single_lo_thresh:
    .2byte  0x00A8
    .4byte  sym_06078635
    .4byte  sym_0607ED8C
    .4byte  sym_0605AD00
    .4byte  sym_0607ED90
    .4byte  sym_06063F44
    .4byte  sym_06078868
    .4byte  sym_0607EAB8
_pool_line_count_ptr:
    .4byte  sym_0607EBCC
_pool_fb_res_mode_a:
    .4byte  sym_0605A016
_pool_player_mode_a:
    .4byte  sym_0607EAD8
.L_nonzero_player_mode:
    mov.l   _pool_player_mode_b, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_default_thresholds

    mov.l @r5, r3
    mov.w   DAT_0600a2d8, r2
    cmp/eq r2, r3
    bf      .L_try_mode1_lo
    exts.w r7, r7
    bra     .L_res_select_done
    mov.w r7, @r4
.L_try_mode1_lo:
    mov.l @r5, r2
    mov.w   _wpool_mode1_lo_thresh, r3
    cmp/eq r3, r2
    bf      .L_mode1_no_match
    exts.w r6, r6
    mov.w r6, @r4
.L_mode1_no_match:
    bra     .L_res_select_done
    nop

.L_default_thresholds:
    mov.l @r5, r2
    mov.w   DAT_0600a2dc, r3
    cmp/eq r3, r2
    bf      .L_try_default_lo
    exts.w r7, r7
    bra     .L_res_select_done
    mov.w r7, @r4
.L_try_default_lo:
    mov.l @r5, r2
    mov.w   _wpool_default_lo_thresh, r3
    cmp/eq r3, r2
    bf      .L_res_select_done
    exts.w r6, r6
    mov.w r6, @r4
.L_res_select_done:
    rts
    nop
    .4byte  0xE703D515
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
    .2byte  0x0287
_wpool_mode1_lo_thresh:
    .2byte  0x0271

    .global DAT_0600a2dc
DAT_0600a2dc:
    .2byte  0x01AE
_wpool_default_lo_thresh:
    .2byte  0x0190
    .4byte  0x03710352
    .4byte  0x03ABFFFF
_pool_player_mode_b:
    .4byte  sym_0607EAD8
    .4byte  sym_0607EBCC
    .4byte  sym_0605A016
    .4byte  0x62529338
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
    mov.l   _pool_fb_res_mode_b, r5
    mov.l   _pool_game_mode, r4
    mov.l @r4, r0
    tst r0, r0
    bf      .L_check_mode_1
    mov #0x5, r3
    mov.w r3, @r5
    bra     .L_mode_select_done
    nop
.L_check_mode_1:
    mov.l @r4, r0
    cmp/eq #0x1, r0
    bf      .L_check_mode_2
    mov #0x6, r3
    mov.w r3, @r5
    bra     .L_mode_select_done
    nop
.L_check_mode_2:
    mov.l @r4, r0
    cmp/eq #0x2, r0
    bf      .L_check_mode_3
    mov #0x7, r3
    mov.w r3, @r5
    bra     .L_mode_select_done
    nop
    .2byte  0x0398

    .global DAT_0600a36c
DAT_0600a36c:
    .2byte  0x036D

    .global DAT_0600a36e
DAT_0600a36e:
    .2byte  0x0336

    .global DAT_0600a370
DAT_0600a370:
    .2byte  0x021A

    .global DAT_0600a372
DAT_0600a372:
    .2byte  0x01B4
_pool_fb_res_mode_b:
    .4byte  sym_0605A016
_pool_game_mode:
    .4byte  sym_06063E1C
.L_check_mode_3:
    mov.l @r4, r0
    cmp/eq #0x3, r0
    bf      .L_mode_select_done
    mov #0x8, r3
    mov.w r3, @r5
.L_mode_select_done:
    rts
    nop
    .2byte  0xE300
    .4byte  0xD213000B
    .2byte  0x2232

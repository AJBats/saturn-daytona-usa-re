
   .section .text.FUN_06014A74


   .global display_mode_init
   .type display_mode_init, @function
display_mode_init:
    mov.l r14, @-r15
    mov #0x19, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x0, r11
    mov.l r10, @-r15
    mov #0x1, r10
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_hud_table_base, r9
    mov.l   .L_fn_channel_config, r12

    mov.w   .L_channel_id_0x100, r4
    jsr @r12
    mov r11, r5
    mov r10, r5
    jsr @r12
    mov #0x4, r4
    mov r10, r5
    jsr @r12
    mov #0x8, r4
    mov #0x2, r5
    jsr @r12
    mov #0x10, r4
    mov #0x7, r5
    jsr @r12
    mov #0x20, r4
    mov r11, r5
    jsr @r12
    mov r10, r4

    mov.l   .L_display_skip_flag, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_compact_commit_path

    mov.l   .L_fn_layer_config, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov.l   .L_fn_display_channel, r3
    mov r6, r5
    jsr @r3
    mov #0x8, r4
    mov #0x6, r5
    jsr @r12
    mov #0x10, r4
    mov.l   .L_fn_render_commit, r3
    jsr @r3
    nop
    mov.l   .L_fn_gameover_setup, r3
    jsr @r3
    nop
    bra     .L_common_init
    nop
.L_channel_id_0x100:
    .2byte  0x0100                            /* channel ID 0x100 */
.L_hud_table_base:
    .4byte  sym_06085640                   /* HUD element table base */
.L_fn_channel_config:
    .4byte  channel_nibble_config          /* channel configuration function */
.L_display_skip_flag:
    .4byte  sym_06085F8A                   /* display skip flag (byte) */
.L_fn_layer_config:
    .4byte  sym_0602853E                   /* display layer configuration */
.L_fn_display_channel:
    .4byte  display_channel_b              /* display channel B enable */
.L_fn_render_commit:
    .4byte  sym_06028560                   /* render state commit */
.L_fn_gameover_setup:
    .4byte  gameover_channel_setup         /* game over channel setup */

.L_compact_commit_path:
    mov.l   .L_fn_obj_compact, r3
    jsr @r3
    nop
    mov.l   .L_fn_frame_commit, r3
    jsr @r3
    nop

.L_common_init:
    mov.w   .L_channel_id_0x100_b, r4
    jsr @r12
    mov #0x4, r5
    mov.l   .L_fn_layer_config_b, r3
    jsr @r3
    mov #0xC, r4

    mov #0x0, r6
    mov.l   .L_fn_display_channel_b, r3
    mov r6, r5
    jsr @r3
    mov #0x10, r4
    mov #0x0, r6
    mov.l   .L_fn_display_channel_b, r3
    mov r6, r5
    jsr @r3
    mov #0x20, r4

    mov.l   .L_fn_memcpy_word, r13
    mov.l   .L_palette_src_0, r5
    mov.l   .L_vdp2_cram_0x660, r4
    jsr @r13
    mov #0x20, r6
    mov.l   .L_palette_src_1, r5
    mov.l   .L_vdp2_cram_0x680, r4
    jsr @r13
    mov #0x20, r6
    mov.l   .L_palette_src_2, r5
    mov.l   .L_vdp2_cram_0x6A0, r4
    jsr @r13
    mov #0x20, r6
    mov.l   .L_palette_src_3, r5
    mov.l   .L_vdp2_cram_0x6C0, r4
    jsr @r13
    mov #0x20, r6

    mov #0x20, r6
    mov.l   .L_sprite_src_0, r5
    mov.l   .L_vdp1_vram_base, r8
    mov.l   .L_tile_index_ptr, r4
    mov.w   .L_sprite_offset_0, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r8, r4
    jsr @r13
    add r3, r4
    mov #0x20, r6
    mov.l   .L_sprite_src_1, r5
    mov.l   .L_tile_index_ptr, r4
    mov.w   .L_sprite_offset_1, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r8, r4
    jsr @r13
    add r3, r4
    mov #0x20, r6
    mov.l   .L_sprite_src_2, r5
    mov.l   .L_tile_index_ptr, r4
    mov.w   .L_sprite_offset_2, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r8, r4
    jsr @r13
    add r3, r4
    mov #0x20, r6
    mov.l   .L_sprite_src_3, r5
    mov.l   .L_tile_index_ptr, r4
    mov.w   .L_sprite_offset_3, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r8, r4
    jsr @r13
    add r3, r4

    mov.l   .L_fn_vram_tile_copy, r13
    mov #0x8, r7
    mov.l   .L_tilemap_src_0, r5
    mov.l   .L_vdp2_vram_0x73B98, r4
    jsr @r13
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_tilemap_src_1, r5
    mov.l   .L_vdp2_vram_0x74158, r4
    jsr @r13
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_tilemap_src_2, r5
    mov.l   .L_vdp2_vram_0x74AFC, r4
    jsr @r13
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_tilemap_src_3, r5
    mov.l   .L_vdp2_vram_0x75730, r4
    jsr @r13
    mov #0x0, r6
    bra     .L_hud_element_check
    extu.b r11, r5
.L_channel_id_0x100_b:
    .2byte  0x0100                            /* channel ID 0x100 (second ref) */
.L_sprite_offset_0:
    .2byte  0x0260                            /* VDP1 sprite offset 0 */
.L_sprite_offset_1:
    .2byte  0x0280                            /* VDP1 sprite offset 1 */
.L_sprite_offset_2:
    .2byte  0x0220                            /* VDP1 sprite offset 2 */
.L_sprite_offset_3:
    .2byte  0x0240                            /* VDP1 sprite offset 3 */
.L_fn_obj_compact:
    .4byte  obj_data_compact               /* object data compaction */
.L_fn_frame_commit:
    .4byte  frame_end_commit               /* frame end commit */
.L_fn_layer_config_b:
    .4byte  sym_0602853E                   /* display layer configuration */
.L_fn_display_channel_b:
    .4byte  display_channel_b              /* display channel B enable */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx                /* word-indexed memory copy */
.L_palette_src_0:
    .4byte  sym_06044A64                   /* color palette source 0 */
.L_vdp2_cram_0x660:
    .4byte  0x25F00660                      /* VDP2 color RAM +0x660 */
.L_palette_src_1:
    .4byte  sym_06044A84                   /* color palette source 1 */
.L_vdp2_cram_0x680:
    .4byte  0x25F00680                      /* VDP2 color RAM +0x680 */
.L_palette_src_2:
    .4byte  sym_06044AA4                   /* color palette source 2 */
.L_vdp2_cram_0x6A0:
    .4byte  0x25F006A0                      /* VDP2 color RAM +0x6A0 */
.L_palette_src_3:
    .4byte  sym_06044AC4                   /* color palette source 3 */
.L_vdp2_cram_0x6C0:
    .4byte  0x25F006C0                      /* VDP2 color RAM +0x6C0 */
.L_vdp1_vram_base:
    .4byte  0x25C00000                      /* VDP1 VRAM base */
.L_sprite_src_0:
    .4byte  sym_06044AE4                   /* sprite pattern source 0 */
.L_tile_index_ptr:
    .4byte  sym_06059FFC                   /* tile index value (ptr, *8 for offset) */
.L_sprite_src_1:
    .4byte  sym_06044B24                   /* sprite pattern source 1 */
.L_sprite_src_2:
    .4byte  sym_06044B04                   /* sprite pattern source 2 */
.L_sprite_src_3:
    .4byte  sym_06044B44                   /* sprite pattern source 3 */
.L_fn_vram_tile_copy:
    .4byte  sym_0600511E                   /* VRAM tile data copy */
.L_tilemap_src_0:
    .4byte  0x00017700                      /* tile map source 0 address */
.L_vdp2_vram_0x73B98:
    .4byte  0x25E73B98                      /* VDP2 VRAM +0x73B98 */
.L_tilemap_src_1:
    .4byte  0x000189E0                      /* tile map source 1 address */
.L_vdp2_vram_0x74158:
    .4byte  0x25E74158                      /* VDP2 VRAM +0x74158 */
.L_tilemap_src_2:
    .4byte  0x0001AFA0                      /* tile map source 2 address */
.L_vdp2_vram_0x74AFC:
    .4byte  0x25E74AFC                      /* VDP2 VRAM +0x74AFC */
.L_tilemap_src_3:
    .4byte  0x0001C980                      /* tile map source 3 address */
.L_vdp2_vram_0x75730:
    .4byte  0x25E75730                      /* VDP2 VRAM +0x75730 */

.L_hud_element_body:
    extu.b r5, r4
    mov #0x36, r3
    muls.w r3, r4
    sts macl, r4
    exts.w r4, r4
    add r9, r4
    extu.w r10, r2
    mov.w r2, @r4
    extu.w r14, r0
    mov.w r0, @(2, r4)
    extu.b r11, r4
    extu.b r5, r6
    muls.w r3, r6
    sts macl, r6
    exts.w r6, r6
    add r9, r6

.L_hud_slot_fill:
    extu.b r4, r2
    mov #0x20, r0
    shll r2
    add #0x1, r4
    add r6, r2
    extu.b r4, r3
    mov.w r0, @(4, r2)
    cmp/ge r14, r3
    bf      .L_hud_slot_fill
    add #0x1, r5

.L_hud_element_check:
    extu.b r5, r3
    mov #0x2C, r2
    cmp/ge r2, r3
    bf      .L_hud_element_body

    mov.l   .L_fn_vdp2_loop, r3
    jsr @r3
    nop
    mov.l   .L_fn_geom_pipeline, r3
    jsr @r3
    nop

    exts.w r10, r0
    mov.l   .L_display_flag_a, r3
    mov.b r11, @r3
    mov.l   .L_display_flag_b, r3
    mov.w r11, @r3
    mov.l   .L_display_flag_c, r3
    mov.w r0, @r3
    mov.l   .L_fn_pre_display, r3
    jsr @r3
    nop

    mov.l   .L_special_render_check, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    .word 0x0029
    mov.l   .L_race_event_flags, r3
    mov.l @r3, r3
    and r3, r0
    and r10, r0
    tst r0, r0
    bt      .L_epilogue

    mov #0x27, r3
    mov.l   .L_display_flag_b, r2
    mov.w r3, @r2
    mov.l   .L_car_state_ptr, r4
    mov.l @r4, r3
    mov.l   .L_demo_src_byte, r2
    mov.b @r2, r2
    mov.w   DAT_06014cf2, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.l   .L_demo_src_word, r2
    mov.l @r2, r2
    mov.w   .L_car_demo_offset_b, r0
    mov.l r2, @(r0, r3)
    mov.l   .L_demo_params, r3
    mov.l @r3, r3
    mov.l   .L_demo_dest, r2
    mov.l r3, @r2

.L_epilogue:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06014cf2
DAT_06014cf2:
    .2byte  0x0224                            /* car struct: demo param A offset */
.L_car_demo_offset_b:
    .2byte  0x0240                            /* car struct: demo param B offset */
    .2byte  0xFFFF                            /* padding */
.L_fn_vdp2_loop:
    .4byte  vdp2_loop_ctrl                 /* VDP2 loop control */
.L_fn_geom_pipeline:
    .4byte  geom_pipeline_coord            /* geometry pipeline coordinates */
.L_display_flag_a:
    .4byte  sym_06085F89                   /* display flag A (byte) */
.L_display_flag_b:
    .4byte  sym_06085F90                   /* display flag B (16-bit) */
.L_display_flag_c:
    .4byte  sym_06085F94                   /* display flag C (16-bit) */
.L_fn_pre_display:
    .4byte  sym_060149CC                   /* pre-display setup */
.L_special_render_check:
    .4byte  sym_0607ED8C                   /* special render enable (16-bit) */
.L_race_event_flags:
    .4byte  sym_0607EBF4                   /* race event bitfield (32-bit) */
.L_car_state_ptr:
    .4byte  sym_0607E944                   /* car state base pointer */
.L_demo_src_byte:
    .4byte  sym_06078637                   /* demo source byte */
.L_demo_src_word:
    .4byte  sym_06078638                   /* demo source word (32-bit) */
.L_demo_params:
    .4byte  sym_0607863C                   /* demo parameters source */
.L_demo_dest:
    .4byte  sym_060786A4                   /* demo parameters destination */


    .section .text.FUN_0601A2BC


    .global start_light_render
    .type start_light_render, @function
start_light_render:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_render_mode_flags, r4
    mov.l   .L_sign_bit, r3
    mov.l @r4, r2
    or r3, r2
    mov.l   .L_fn_camera_finalize, r3
    jsr @r3
    mov.l r2, @r4
    mov.l   .L_fn_camera_finalize, r3
    jsr @r3
    nop
    mov.l   .L_fn_display_channel_cfg, r14
    jsr @r14
    mov #0x4, r4
    jsr @r14
    mov #0x8, r4
    jsr @r14
    mov #0xC, r4
    mov.l   .L_fn_render_state_commit, r3
    jsr @r3
    nop
    mov #0x8, r7
    mov.l   .L_tile_data_size, r5
    mov.l   .L_vdp2_vram_tile_a, r4
    mov.l   .L_fn_vram_tile_copy, r3
    jsr @r3
    mov #0x0, r6
    mov #0x9, r7
    mov.l   .L_tile_data_size, r5
    mov.l   .L_vdp2_vram_tile_b, r4
    mov.l   .L_fn_vram_tile_copy, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_frame_counter, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0x0090
    .4byte  sym_0605D4F0
    .4byte  sym_06049AFC
    .4byte  sym_060284AE
.L_render_mode_flags:
    .4byte  sym_0605B6D8                    /* render mode flags (32-bit) */
.L_sign_bit:
    .4byte  0x80000000                      /* sign bit — triggers display state change */
.L_fn_camera_finalize:
    .4byte  sym_06026CE0                    /* camera state finalization */
.L_fn_display_channel_cfg:
    .4byte  sym_0602853E                    /* display channel configure */
.L_fn_render_state_commit:
    .4byte  sym_06028560                    /* render state commit / flush */
.L_tile_data_size:
    .4byte  0x00017700                      /* tile pattern data size (96000 bytes) */
.L_vdp2_vram_tile_a:
    .4byte  0x25E76EFC                      /* VDP2 VRAM +0x76EFC (tile block A dest) */
.L_fn_vram_tile_copy:
    .4byte  sym_0600511E                    /* VRAM tile/pattern upload function */
.L_vdp2_vram_tile_b:
    .4byte  0x25E77B18                      /* VDP2 VRAM +0x77B18 (tile block B dest) */
.L_frame_counter:
    .4byte  sym_06085FF2                    /* animation frame counter (byte) */

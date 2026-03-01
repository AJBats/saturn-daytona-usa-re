
    .section .text.FUN_060096DC


    .global state_time_extend_setup
    .type state_time_extend_setup, @function
state_time_extend_setup:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xB4, 0x8B    /* bsr state_timeext_setup — frame setup helper */
    nop
    mov #0x13, r2
    mov.l   .L_pool_game_state, r3
    mov #0x0, r14
    mov.l r2, @r3
    mov.l   .L_pool_lap_count, r4
    mov.l   .L_pool_extend_lap_backup, r3
    mov.b @r4, r2
    mov.b r2, @r3
    extu.b r14, r2
    mov.b r2, @r4
    mov.l   .L_pool_extend_timer, r2
    mov.w r14, @r2
    mov.l   .L_pool_extend_gfx_base, r7
    mov.w   .L_wpool_sprite_coord_y, r6
    mov.w   .L_wpool_sprite_param_a, r5
    mov.l   .L_pool_fn_geom_render, r2
    jsr @r2
    mov #0x8, r4
    mov.l   .L_pool_extend_text_data, r3
    mov.l r3, @r15
    mov r3, r7
    mov.l   .L_mask_nibble3, r6
    mov.w   .L_wpool_sprite_param_b, r5
    add #0x2E, r7
    mov.l   .L_pool_fn_geom_dispatch, r3
    jsr @r3
    mov #0x8, r4
    mov.l @r15, r7
    mov.l   .L_mask_nibble3, r6
    mov.w   .L_wpool_sprite_param_c, r5
    mov.l   .L_pool_fn_geom_dispatch, r3
    add #0x2F, r7
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_render_flags, r4
    mov.l   .L_pool_fn_camera_finalize, r3
    mov.l @r4, r0
    or #0x4, r0
    jsr @r3
    mov.l r0, @r4
    mov.l   .L_pool_anim_state, r3
    mov.l r14, @r3
    mov.l   .L_pool_snd_cmd_extend, r5
    mov r14, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_pool_fn_sound_dispatch, r3
    jmp @r3
    mov.l @r15+, r14
.L_wpool_sprite_coord_y:
    .2byte  0x0090                          /* Y screen coordinate for extend sprite */
.L_wpool_sprite_param_a:
    .2byte  0x051C                          /* sprite parameter A (first HUD element) */
.L_wpool_sprite_param_b:
    .2byte  0x061C                          /* sprite parameter B (second text element) */
.L_wpool_sprite_param_c:
    .2byte  0x049C                          /* sprite parameter C (third text element) */
.L_pool_game_state:
    .4byte  g_game_state                    /* game state dispatch value (32-bit) */
.L_pool_lap_count:
    .4byte  sym_06078654                    /* current lap count (byte) */
.L_pool_extend_lap_backup:
    .4byte  sym_06078652                    /* extend-mode lap backup (byte) */
.L_pool_extend_timer:
    .4byte  sym_06078650                    /* time extend countdown timer (16-bit) */
.L_pool_extend_gfx_base:
    .4byte  sym_060446CC                    /* time extend sprite/graphics data base */
.L_pool_fn_geom_render:
    .4byte  sym_060284AE                    /* geom_render — VDP number+text renderer */
.L_pool_extend_text_data:
    .4byte  sym_0605AC9C                    /* time extend text/sprite data base */
.L_mask_nibble3:
    .4byte  0x0000F000                      /* nibble-3 mask for geom dispatch */
.L_pool_fn_geom_dispatch:
    .4byte  sym_060283E0                    /* geom_dispatch — display command writer */
.L_pool_render_flags:
    .4byte  sym_0605B6D8                    /* render mode flags (32-bit bitmask) */
.L_pool_fn_camera_finalize:
    .4byte  sym_06026CE0                    /* camera_finalize — commit camera state */
.L_pool_anim_state:
    .4byte  sym_06059F44                    /* animation state (32-bit, cleared to 0) */
.L_pool_snd_cmd_extend:
    .4byte  0xAE0004FF                      /* sound command: time extend jingle */
.L_pool_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch              /* sound command dispatcher (tail-call target) */

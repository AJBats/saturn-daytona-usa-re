
    .section .text.FUN_0601A348


    .global green_light_anim
    .type green_light_anim, @function
green_light_anim:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_fn_memcpy_word, r14
    mov.l   .L_pal_traffic_light, r3
    mov.l r3, @r15
    mov.l   .L_vdp2_cram_0x020, r4
    jsr @r14
    mov r3, r5
    mov #0x60, r6
    mov.l   .L_vdp2_cram_0x620, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_pal_sprite_start, r5
    mov.l   .L_vdp2_cram_0x400, r4
    jsr @r14
    mov #0x40, r6
    mov.l   .L_fn_race_data, r3
    jsr @r3
    nop
    mov.l   .L_game_timer, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0601A390
    mov #0x0, r6
    mov.l   .L_disp_list_a, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.l   .L_fn_disp_loader, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_0601A3A8
    nop
.L_0601A390:
    mov.l   .L_disp_list_b, r2
    mov #0x0, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_disp_offset, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_fn_disp_loader, r3
    jsr @r3
    mov #0x4, r4
.L_0601A3A8:
    mov.l   .L_fn_post_process, r3
    jsr @r3
    nop
    mov.l   .L_anim_frame_ctr, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_disp_offset:
    .2byte  0x1000                      /* display list offset for alternate frame */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx            /* word-indexed memcpy */
.L_pal_traffic_light:
    .4byte  sym_0605CF9C               /* source: traffic light palette (48 colors) */
.L_vdp2_cram_0x020:
    .4byte  0x25F00020                  /* VDP2 color RAM +0x020 — traffic light low */
.L_vdp2_cram_0x620:
    .4byte  0x25F00620                  /* VDP2 color RAM +0x620 — traffic light high mirror */
.L_pal_sprite_start:
    .4byte  sym_0605D01C               /* source: start sequence sprite palette */
.L_vdp2_cram_0x400:
    .4byte  0x25F00400                  /* VDP2 color RAM +0x400 — sprite bank */
.L_fn_race_data:
    .4byte  race_data_handler          /* race state update */
.L_game_timer:
    .4byte  sym_06063D9E               /* game timer (16-bit) — 0x10 = green light moment */
.L_disp_list_a:
    .4byte  sym_06063C90               /* display list descriptor A (green ON) */
.L_fn_disp_loader:
    .4byte  sym_06028400               /* display list loader */
.L_disp_list_b:
    .4byte  sym_06063C98               /* display list descriptor B (alternate) */
.L_fn_post_process:
    .4byte  sym_06026CE0               /* post-process display commit */
.L_anim_frame_ctr:
    .4byte  sym_06085FF2               /* animation frame counter (byte) */

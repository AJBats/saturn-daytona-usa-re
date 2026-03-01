
    .section .text.FUN_060200A4


    .global race_start_obj_init
    .type race_start_obj_init, @function
race_start_obj_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pal_start_objs, r5
    mov.l   .L_vdp2_cram_0x6C0, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    mov #0x20, r6
    mov.l   .L_pal_grid_overlay, r5
    mov.l   .L_vdp2_cram_0x060, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    mov #0x20, r6
    mov #0x8, r7
    mov.l   .L_rom_pattern_a, r5
    mov.l   .L_fn_pattern_upload, r14
    mov.l   .L_vdp2_vram_0x33AD8, r4
    jsr @r14
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_rom_pattern_b, r5
    mov.l   .L_vdp2_vram_0x33764, r4
    jsr @r14
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_rom_pattern_c, r5
    mov.l   .L_vram_staging, r4
    jsr @r14
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_rom_pattern_d, r5
    mov.l   .L_vdp2_vram_0x3398C, r4
    jsr @r14
    mov #0x0, r6
    mov.l   .L_course_descriptor, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_0602014a, r3
    mov.w   DAT_0602014c, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_fn_disp_loader, r3
    jsr @r3
    mov #0xC, r4
    mov #0x0, r6
    mov.l   .L_fn_disp_chan_b, r3
    mov r6, r5
    jsr @r3
    mov #0x20, r4
    mov #0x0, r6
    mov.l   .L_fn_disp_chan_b, r3
    mov r6, r5
    jsr @r3
    mov #0x8, r4
    .byte   0xB6, 0x5C    /* bsr 0x06020DD0 (external) — race start object setup */
    nop
    mov #0x0, r2
    mov.l   .L_start_timer_a, r3
    mov.w r2, @r3
    mov.l   .L_start_timer_b, r3
    mov.w r2, @r3
    mov.l   .L_start_state, r3
    mov.l r2, @r3
    mov.l   .L_start_phase, r3
    mov.w r2, @r3
    mov.l   .L_snd_start_fanfare, r5
    mov.l   .L_fn_sound_cmd, r3
    jsr @r3
    mov r2, r4
    mov #0x0, r2
    mov.l   .L_anim_state_a, r3
    mov.b r2, @r3
    mov.l   .L_anim_state_b, r3
    mov.b r2, @r3
    mov #0xF, r2
    mov.l   .L_lap_init_counter, r3
    mov.b r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0602014a
DAT_0602014a:
    .2byte  0x6000                      /* display list offset into course descriptor */

    .global DAT_0602014c
DAT_0602014c:
    .2byte  0x0A02                      /* display config flags */
    .2byte  0xFFFF
.L_pal_start_objs:
    .4byte  sym_0604896C               /* source: start objects palette */
.L_vdp2_cram_0x6C0:
    .4byte  0x25F006C0                  /* VDP2 color RAM +0x6C0 — course palette bank */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx            /* word-indexed memcpy */
.L_pal_grid_overlay:
    .4byte  sym_0604BC14               /* source: grid overlay palette */
.L_vdp2_cram_0x060:
    .4byte  0x25F00060                  /* VDP2 color RAM +0x060 — NBG0 ext */
.L_fn_pattern_upload:
    .4byte  sym_0600511E               /* pattern data upload function */
.L_rom_pattern_a:
    .4byte  0x00017700                  /* ROM offset: pattern block A */
.L_vdp2_vram_0x33AD8:
    .4byte  0x25E33AD8                  /* VDP2 VRAM +0x33AD8 — pattern A dest */
.L_rom_pattern_b:
    .4byte  0x00018B40                  /* ROM offset: pattern block B */
.L_vdp2_vram_0x33764:
    .4byte  0x25E33764                  /* VDP2 VRAM +0x33764 — pattern B dest */
.L_rom_pattern_c:
    .4byte  0x0001D2A0                  /* ROM offset: pattern block C */
.L_vram_staging:
    .4byte  sym_0605E164               /* Work RAM staging buffer for pattern C */
.L_rom_pattern_d:
    .4byte  0x00018F20                  /* ROM offset: pattern block D */
.L_vdp2_vram_0x3398C:
    .4byte  0x25E3398C                  /* VDP2 VRAM +0x3398C — pattern D dest */
.L_course_descriptor:
    .4byte  sym_06063CA0               /* course display list descriptor */
.L_fn_disp_loader:
    .4byte  sym_06028400               /* display list loader */
.L_fn_disp_chan_b:
    .4byte  display_channel_b          /* display channel clear/set */
.L_start_timer_a:
    .4byte  sym_0608780A               /* race start timer A (16-bit) */
.L_start_timer_b:
    .4byte  sym_06087808               /* race start timer B (16-bit) */
.L_start_state:
    .4byte  sym_06087814               /* race start state (32-bit) */
.L_start_phase:
    .4byte  sym_06087806               /* race start phase (16-bit) */
.L_snd_start_fanfare:
    .4byte  0xAB1128FF                  /* sound cmd: race start fanfare */
.L_fn_sound_cmd:
    .4byte  sound_cmd_dispatch         /* sound command dispatch */
.L_anim_state_a:
    .4byte  sym_06087826               /* animation state A (byte) */
.L_anim_state_b:
    .4byte  sym_06087824               /* animation state B (byte) */
.L_lap_init_counter:
    .4byte  sym_06087825               /* lap init counter (byte, initial = 0xF) */

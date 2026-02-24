/* palette_frame_effects.s -- Per-frame palette commit to VDP2 Color RAM
 * Translation unit: 0x0601938C - 0x060193F4
 *
 * Function catalog:
 *   palette_frame_effects — Copies 5 palette groups from Work RAM shadow
 *                           buffers to VDP2 Color RAM (CRAM) via word memcpy.
 *
 * VDP2 Color RAM layout (this function's responsibility):
 *   CRAM+0x000  (0x20 bytes) — Base palette (backgrounds)
 *   CRAM+0x540  (0x20 bytes) — Sprite palette group A
 *   CRAM+0x600  (0x20 bytes) — Background effect palette
 *   CRAM+0x620  (0xE0 bytes) — Extended palette range (environmental)
 *   CRAM+0x780  (0x80 bytes) — Dynamic effect palette (fade/flash)
 *
 * Called once per frame during VBlank to commit palette updates.
 * Uses memcpy_word_idx (word-indexed copy: r4=dest, r5=src, r6=byte count).
 */

    .section .text.FUN_0601938C


    .global palette_frame_effects
    .type palette_frame_effects, @function
palette_frame_effects:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_memcpy_word, r14     /* r14 = memcpy_word_idx (held across calls) */

    /* Copy sprite palette A → CRAM+0x540 (32 bytes) */
    mov.l   .L_pal_sprite_a, r5
    mov.l   .L_cram_sprite_a, r4
    jsr @r14
    mov #0x20, r6

    /* Copy base palette → CRAM+0x000 (32 bytes) */
    mov.l   .L_pal_base, r5
    mov.l   .L_cram_base, r4
    jsr @r14
    mov #0x20, r6

    /* Copy background effect palette → CRAM+0x600 (32 bytes) */
    mov.l   .L_pal_bg_effect, r5
    mov.l   .L_cram_bg_effect, r4
    jsr @r14
    mov #0x20, r6

    /* Copy extended palette range → CRAM+0x620 (224 bytes) */
    mov.w   .L_sz_extended, r6         /* 0xE0 = 224 bytes */
    mov.l   .L_pal_extended, r5
    mov.l   .L_cram_extended, r4
    jsr @r14
    nop

    /* Copy dynamic effect palette → CRAM+0x780 (128 bytes) */
    mov.w   .L_sz_dynamic, r6          /* 0x80 = 128 bytes */
    mov.l   .L_pal_dynamic, r5
    mov.l   .L_cram_dynamic, r4
    jsr @r14
    nop

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

/* Word pool — palette sizes */
.L_sz_extended:
    .2byte  0x00E0                     /* 224 bytes (extended range) */
.L_sz_dynamic:
    .2byte  0x0080                     /* 128 bytes (dynamic effects) */

/* Long pool — function pointer + palette sources + CRAM destinations */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx
.L_pal_sprite_a:
    .4byte  sym_0605CE9C               /* shadow buffer: sprite palette A */
.L_cram_sprite_a:
    .4byte  0x25F00540                  /* VDP2 color RAM +0x540 */
.L_pal_base:
    .4byte  sym_0605CD9C               /* shadow buffer: base palette */
.L_cram_base:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 */
.L_pal_bg_effect:
    .4byte  sym_0605CF9C               /* shadow buffer: BG effect palette */
.L_cram_bg_effect:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 */
.L_pal_extended:
    .4byte  sym_0605CEBC               /* shadow buffer: extended palette */
.L_cram_extended:
    .4byte  0x25F00620                  /* VDP2 color RAM +0x620 */
.L_pal_dynamic:
    .4byte  sym_06049DC4               /* shadow buffer: dynamic effects */
.L_cram_dynamic:
    .4byte  0x25F00780                  /* VDP2 color RAM +0x780 */

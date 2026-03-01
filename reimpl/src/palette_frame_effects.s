
    .section .text.FUN_0601938C


    .global palette_frame_effects
    .type palette_frame_effects, @function
palette_frame_effects:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_memcpy_word, r14

    mov.l   .L_pal_sprite_a, r5
    mov.l   .L_cram_sprite_a, r4
    jsr @r14
    mov #0x20, r6

    mov.l   .L_pal_base, r5
    mov.l   .L_cram_base, r4
    jsr @r14
    mov #0x20, r6

    mov.l   .L_pal_bg_effect, r5
    mov.l   .L_cram_bg_effect, r4
    jsr @r14
    mov #0x20, r6

    mov.w   .L_sz_extended, r6
    mov.l   .L_pal_extended, r5
    mov.l   .L_cram_extended, r4
    jsr @r14
    nop

    mov.w   .L_sz_dynamic, r6
    mov.l   .L_pal_dynamic, r5
    mov.l   .L_cram_dynamic, r4
    jsr @r14
    nop

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

.L_sz_extended:
    .2byte  0x00E0                     /* 224 bytes (extended range) */
.L_sz_dynamic:
    .2byte  0x0080                     /* 128 bytes (dynamic effects) */

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


    .section .text.FUN_060038D4


    .global dma_vram_init
    .type dma_vram_init, @function
dma_vram_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_fn_dma_transfer, r14
    mov.l   .L_pal_nbg0_base, r5
    mov.l   .L_vdp2_cram_0x000, r4
    jsr @r14
    mov #0x60, r6
    mov #0x40, r6
    mov.l   .L_pal_nbg0_ext, r3
    mov.l r3, @(8, r15)
    mov.l   .L_vdp2_cram_0x060, r4
    jsr @r14
    mov r3, r5
    mov.l   .L_pal_nbg1, r5
    mov.l   .L_vdp2_cram_0x0A0, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_pal_nbg2, r5
    mov.l   .L_vdp2_cram_0x0E0, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_pal_nbg3, r5
    mov.l   .L_vdp2_cram_0x100, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_pal_rbg0, r5
    mov.l   .L_vdp2_cram_0x120, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_pal_sprite_a, r5
    mov.l   .L_vdp2_cram_0x140, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_pal_sprite_b, r5
    mov.l   .L_vdp2_cram_0x160, r4
    jsr @r14
    mov #0x20, r6
    mov #0x20, r6
    mov.l   .L_pal_course_ui, r3
    mov.l r3, @r15
    mov.l   .L_vdp2_cram_0x1A0, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_pal_hud, r3
    mov.l r3, @(4, r15)
    mov.l   .L_vdp2_cram_0x1C0, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_vdp2_cram_0x600, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l   .L_pal_sprite_c, r5
    mov.l   .L_vdp2_cram_0x660, r4
    jsr @r14
    mov #0x60, r6
    mov #0x20, r6
    mov.l   .L_vdp2_cram_0x7A0, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x40, r6
    mov.l   .L_vdp2_cram_0x7C0, r4
    jsr @r14
    mov.l @(4, r15), r5
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_fn_dma_transfer:
    .4byte  dma_transfer               /* word-indexed memcpy */
.L_pal_nbg0_base:
    .4byte  sym_0604814C               /* source: NBG0 base palette (48 colors) */
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 — bank 0 */
.L_pal_nbg0_ext:
    .4byte  sym_0604848C               /* source: NBG0 extended palette (32 colors) */
.L_vdp2_cram_0x060:
    .4byte  0x25F00060                  /* VDP2 color RAM +0x060 — bank 1 */
.L_pal_nbg1:
    .4byte  sym_060484CC               /* source: NBG1 palette */
.L_vdp2_cram_0x0A0:
    .4byte  0x25F000A0                  /* VDP2 color RAM +0x0A0 — bank 2 */
.L_pal_nbg2:
    .4byte  sym_060485AC               /* source: NBG2 palette */
.L_vdp2_cram_0x0E0:
    .4byte  0x25F000E0                  /* VDP2 color RAM +0x0E0 — bank 3 */
.L_pal_nbg3:
    .4byte  sym_0604892C               /* source: NBG3 palette */
.L_vdp2_cram_0x100:
    .4byte  0x25F00100                  /* VDP2 color RAM +0x100 — bank 4 */
.L_pal_rbg0:
    .4byte  sym_060488EC               /* source: RBG0 palette */
.L_vdp2_cram_0x120:
    .4byte  0x25F00120                  /* VDP2 color RAM +0x120 — bank 5 */
.L_pal_sprite_a:
    .4byte  sym_0604890C               /* source: sprite palette A */
.L_vdp2_cram_0x140:
    .4byte  0x25F00140                  /* VDP2 color RAM +0x140 — bank 6 */
.L_pal_sprite_b:
    .4byte  sym_0605CDBC               /* source: sprite palette B */
.L_vdp2_cram_0x160:
    .4byte  0x25F00160                  /* VDP2 color RAM +0x160 — bank 7 */
.L_pal_course_ui:
    .4byte  sym_060487EC               /* source: course UI palette */
.L_vdp2_cram_0x1A0:
    .4byte  0x25F001A0                  /* VDP2 color RAM +0x1A0 — bank 8 */
.L_pal_hud:
    .4byte  sym_060483EC               /* source: HUD palette */
.L_vdp2_cram_0x1C0:
    .4byte  0x25F001C0                  /* VDP2 color RAM +0x1C0 — bank 9 */
.L_vdp2_cram_0x600:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 — high bank (sprite B mirror) */
.L_pal_sprite_c:
    .4byte  sym_0604888C               /* source: sprite palette C */
.L_vdp2_cram_0x660:
    .4byte  0x25F00660                  /* VDP2 color RAM +0x660 — high bank (sprite C) */
.L_vdp2_cram_0x7A0:
    .4byte  0x25F007A0                  /* VDP2 color RAM +0x7A0 — high bank (course UI mirror) */
.L_vdp2_cram_0x7C0:
    .4byte  0x25F007C0                  /* VDP2 color RAM +0x7C0 — high bank (HUD mirror) */

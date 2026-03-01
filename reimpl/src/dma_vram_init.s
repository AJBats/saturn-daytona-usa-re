
    .section .text.FUN_060038D4


    .global dma_vram_init
    .type dma_vram_init, @function
dma_vram_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_06003960, r14
    mov.l   .L_06003964, r5
    mov.l   .L_06003968, r4
    jsr @r14
    mov #0x60, r6
    mov #0x40, r6
    mov.l   .L_0600396C, r3
    mov.l r3, @(8, r15)
    mov.l   .L_06003970, r4
    jsr @r14
    mov r3, r5
    mov.l   .L_06003974, r5
    mov.l   .L_06003978, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0600397C, r5
    mov.l   .L_06003980, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_06003984, r5
    mov.l   .L_06003988, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0600398C, r5
    mov.l   .L_06003990, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_06003994, r5
    mov.l   .L_06003998, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0600399C, r5
    mov.l   .L_060039A0, r4
    jsr @r14
    mov #0x20, r6
    mov #0x20, r6
    mov.l   .L_060039A4, r3
    mov.l r3, @r15
    mov.l   .L_060039A8, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_060039AC, r3
    mov.l r3, @(4, r15)
    mov.l   .L_060039B0, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_060039B4, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l   .L_060039B8, r5
    mov.l   .L_060039BC, r4
    jsr @r14
    mov #0x60, r6
    mov #0x20, r6
    mov.l   .L_060039C0, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x40, r6
    mov.l   .L_060039C4, r4
    jsr @r14
    mov.l @(4, r15), r5
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06003960:
    .4byte  dma_transfer               /* word-indexed memcpy */
.L_06003964:
    .4byte  sym_0604814C               /* source: NBG0 base palette (48 colors) */
.L_06003968:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 — bank 0 */
.L_0600396C:
    .4byte  sym_0604848C               /* source: NBG0 extended palette (32 colors) */
.L_06003970:
    .4byte  0x25F00060                  /* VDP2 color RAM +0x060 — bank 1 */
.L_06003974:
    .4byte  sym_060484CC               /* source: NBG1 palette */
.L_06003978:
    .4byte  0x25F000A0                  /* VDP2 color RAM +0x0A0 — bank 2 */
.L_0600397C:
    .4byte  sym_060485AC               /* source: NBG2 palette */
.L_06003980:
    .4byte  0x25F000E0                  /* VDP2 color RAM +0x0E0 — bank 3 */
.L_06003984:
    .4byte  sym_0604892C               /* source: NBG3 palette */
.L_06003988:
    .4byte  0x25F00100                  /* VDP2 color RAM +0x100 — bank 4 */
.L_0600398C:
    .4byte  sym_060488EC               /* source: RBG0 palette */
.L_06003990:
    .4byte  0x25F00120                  /* VDP2 color RAM +0x120 — bank 5 */
.L_06003994:
    .4byte  sym_0604890C               /* source: sprite palette A */
.L_06003998:
    .4byte  0x25F00140                  /* VDP2 color RAM +0x140 — bank 6 */
.L_0600399C:
    .4byte  sym_0605CDBC               /* source: sprite palette B */
.L_060039A0:
    .4byte  0x25F00160                  /* VDP2 color RAM +0x160 — bank 7 */
.L_060039A4:
    .4byte  sym_060487EC               /* source: course UI palette */
.L_060039A8:
    .4byte  0x25F001A0                  /* VDP2 color RAM +0x1A0 — bank 8 */
.L_060039AC:
    .4byte  sym_060483EC               /* source: HUD palette */
.L_060039B0:
    .4byte  0x25F001C0                  /* VDP2 color RAM +0x1C0 — bank 9 */
.L_060039B4:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 — high bank (sprite B mirror) */
.L_060039B8:
    .4byte  sym_0604888C               /* source: sprite palette C */
.L_060039BC:
    .4byte  0x25F00660                  /* VDP2 color RAM +0x660 — high bank (sprite C) */
.L_060039C0:
    .4byte  0x25F007A0                  /* VDP2 color RAM +0x7A0 — high bank (course UI mirror) */
.L_060039C4:
    .4byte  0x25F007C0                  /* VDP2 color RAM +0x7C0 — high bank (HUD mirror) */

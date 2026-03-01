
    .section .text.FUN_0600FE38


    .global transition_medium_b
    .type transition_medium_b, @function
transition_medium_b:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0600FE98, r4
    mov.l @r4, r3
    add #-0x1, r3
    mov.l r3, @r4
    mov.w   .L_wpool_0600FE92, r2
    cmp/eq r2, r3
    bf      .L_0600FE74
    mov.l   .L_pool_0600FE9C, r2
    mov.l r2, @r15
    mov.l   .L_pool_0600FEA0, r4
    mov.l   .L_pool_0600FEA4, r3
    jsr @r3
    mov r2, r5
    mov.l   .L_pool_0600FEA8, r7
    mov #0x0, r6
    mov.l @r15, r5
    mov.l   .L_pool_0600FEAC, r3
    mov.l @(4, r7), r7
    add r3, r7
    mov.l   .L_pool_0600FEB0, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r2
    mov.l   .L_pool_0600FEB4, r3
    mov.l r2, @r3
    mov #0x10, r2
    mov.l   .L_pool_0600FEB8, r3
    mov.b r2, @r3
.L_0600FE74:
    mov.l   .L_pool_0600FEBC, r7
    mov.w   .L_wpool_0600FE94, r6
    mov.w   .L_wpool_0600FE96, r5
    mov.l   .L_pool_0600FEC0, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0600FEC4, r4
    mov.l   .L_pool_0600FEC8, r3
    jsr @r3
    nop
    mov.l   .L_0600FECC, r4
    add #0x4, r15
    mov.l   .L_pool_0600FEC8, r3
    jmp @r3
    lds.l @r15+, pr
.L_wpool_0600FE92:
    .2byte  0x00AB                 /* countdown trigger threshold (171 frames) */
.L_wpool_0600FE94:
    .2byte  0x0090                 /* split-screen tile size */
.L_wpool_0600FE96:
    .2byte  0x07A2                 /* split-screen tile data size */
.L_pool_0600FE98:
    .4byte  sym_0607EBCC           /* &state_countdown (32-bit, WRAM High) */
.L_pool_0600FE9C:
    .4byte  sym_06094FA8           /* tilemap source data (WRAM) */
.L_pool_0600FEA0:
    .4byte  sym_060EFB24           /* DMA source: VDP2 tilemap data */
.L_pool_0600FEA4:
    .4byte  dma_memory_transfer    /* DMA memory-to-memory transfer */
.L_pool_0600FEA8:
    .4byte  sym_06063838           /* tile table entry (struct base) */
.L_pool_0600FEAC:
    .4byte  0x00009000             /* tile data offset (+0x9000) */
.L_pool_0600FEB0:
    .4byte  sym_06028400           /* display list loader / tile writer */
.L_pool_0600FEB4:
    .4byte  sym_06078864           /* transition state word (32-bit) */
.L_pool_0600FEB8:
    .4byte  sym_0607887F           /* game_state_byte (8-bit) */
.L_pool_0600FEBC:
    .4byte  sym_0605ACE4           /* split-screen tile data source */
.L_pool_0600FEC0:
    .4byte  sym_060284AE           /* display channel handler / tile writer */
.L_0600FEC4:
    .4byte  0x25F001E0             /* VDP2 color RAM +0x1E0 */
.L_pool_0600FEC8:
    .4byte  sym_06011F1C           /* palette_color_fade (from dual_hud_render) */
.L_0600FECC:
    .4byte  0x25F00520             /* VDP2 color RAM +0x520 */


    .section .text.FUN_0601D2DC


    .global render_coord_transform
    .type render_coord_transform, @function
render_coord_transform:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_fn_vdp2_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_chan_config, r14
    mov.w   .L_chan_id_0x100, r4
    jsr @r14
    mov #0x0, r5
    mov #0x0, r5
    jsr @r14
    mov #0x4, r4
    mov #0x0, r5
    jsr @r14
    mov #0x8, r4
    mov #0x6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x7, r5
    jsr @r14
    mov #0x20, r4
    mov.l   .L_fn_audio_disp, r3
    jsr @r3
    nop
    mov #0x8, r7
    mov.l   .L_rom_pattern_offset, r5
    mov.l   .L_vdp2_vram_0x6F9C4, r4
    mov.l   .L_fn_pattern_upload, r3
    jsr @r3
    mov #0x0, r6
    mov #0x40, r6
    mov.l   .L_pal_base, r2
    mov.l   .L_fn_dma_transfer, r14
    mov.l r2, @r15
    mov.l   .L_vdp2_cram_0x600, r4
    jsr @r14
    mov r2, r5
    mov.l   .L_pal_sprite_c, r5
    mov.l   .L_vdp2_cram_0x660, r4
    jsr @r14
    mov #0x60, r6
    mov #0x60, r6
    mov.l   .L_vdp2_cram_0x000, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_tilemap_a, r5
    mov.l   .L_vdp2_vram_0x759EC, r4
    mov.l   .L_fn_dma_mem, r3
    jsr @r3
    nop
    mov.l   .L_tilemap_b, r2
    mov.l r2, @r15
    mov.l   .L_vdp2_vram_0x75DDC, r4
    mov.l   .L_fn_dma_mem, r3
    jsr @r3
    mov r2, r5
    mov #0x0, r6
    mov.l @r15, r5
    mov.w   DAT_0601d36c, r7
    mov.l   .L_fn_disp_loader, r3
    jsr @r3
    mov #0x8, r4
    mov #0x0, r2
    mov.l   .L_state_flag, r3
    mov.b r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_fn_disp_finalize, r3
    jmp @r3
    mov.l @r15+, r14
.L_chan_id_0x100:
    .2byte  0x0100                      /* display channel ID */

    .global DAT_0601d36c
DAT_0601d36c:
    .2byte  0x1000                      /* display list size */
    .2byte  0xFFFF
.L_fn_vdp2_init:
    .4byte  sym_060149E0               /* VDP2 display system init */
.L_fn_chan_config:
    .4byte  channel_nibble_config      /* display channel priority config */
.L_fn_audio_disp:
    .4byte  audio_display_init         /* audio display init */
.L_rom_pattern_offset:
    .4byte  0x00017700                  /* ROM offset: character pattern data */
.L_vdp2_vram_0x6F9C4:
    .4byte  0x25E6F9C4                  /* VDP2 VRAM +0x6F9C4 — pattern destination */
.L_fn_pattern_upload:
    .4byte  sym_0600511E               /* pattern data upload */
.L_fn_dma_transfer:
    .4byte  dma_transfer               /* word-indexed memcpy */
.L_pal_base:
    .4byte  sym_0604842C               /* source: base palette (64 bytes) */
.L_vdp2_cram_0x600:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 — sprite high bank */
.L_pal_sprite_c:
    .4byte  sym_0604888C               /* source: sprite palette C (96 bytes) */
.L_vdp2_cram_0x660:
    .4byte  0x25F00660                  /* VDP2 color RAM +0x660 — sprite C */
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 — bank 0 */
.L_tilemap_a:
    .4byte  sym_06094FA8               /* source: tilemap A (results screen) */
.L_vdp2_vram_0x759EC:
    .4byte  0x25E759EC                  /* VDP2 VRAM +0x759EC — tilemap A destination */
.L_fn_dma_mem:
    .4byte  dma_memory_transfer        /* DMA memory transfer */
.L_tilemap_b:
    .4byte  sym_06095F48               /* source: tilemap B (results screen) */
.L_vdp2_vram_0x75DDC:
    .4byte  0x25E75DDC                  /* VDP2 VRAM +0x75DDC — tilemap B destination */
.L_fn_disp_loader:
    .4byte  sym_06028400               /* display list loader */
.L_state_flag:
    .4byte  sym_0607887F               /* results screen state flag (byte) */
.L_fn_disp_finalize:
    .4byte  sym_060149CC               /* display system finalize */


    .section .text.FUN_0601D2DC


    .global render_coord_transform
    .type render_coord_transform, @function
render_coord_transform:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601D370, r3
    jsr @r3
    nop
    mov.l   .L_0601D374, r14
    mov.w   .L_0601D36A, r4
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
    mov.l   .L_0601D378, r3
    jsr @r3
    nop
    mov #0x8, r7
    mov.l   .L_0601D37C, r5
    mov.l   .L_0601D380, r4
    mov.l   .L_0601D384, r3
    jsr @r3
    mov #0x0, r6
    mov #0x40, r6
    mov.l   .L_0601D38C, r2
    mov.l   .L_0601D388, r14
    mov.l r2, @r15
    mov.l   .L_0601D390, r4
    jsr @r14
    mov r2, r5
    mov.l   .L_0601D394, r5
    mov.l   .L_0601D398, r4
    jsr @r14
    mov #0x60, r6
    mov #0x60, r6
    mov.l   .L_0601D39C, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_0601D3A0, r5
    mov.l   .L_0601D3A4, r4
    mov.l   .L_0601D3A8, r3
    jsr @r3
    nop
    mov.l   .L_0601D3AC, r2
    mov.l r2, @r15
    mov.l   .L_0601D3B0, r4
    mov.l   .L_0601D3A8, r3
    jsr @r3
    mov r2, r5
    mov #0x0, r6
    mov.l @r15, r5
    mov.w   DAT_0601d36c, r7
    mov.l   .L_0601D3B4, r3
    jsr @r3
    mov #0x8, r4
    mov #0x0, r2
    mov.l   .L_0601D3B8, r3
    mov.b r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_0601D3BC, r3
    jmp @r3
    mov.l @r15+, r14
.L_0601D36A:
    .2byte  0x0100                      /* display channel ID */

    .global DAT_0601d36c
DAT_0601d36c:
    .2byte  0x1000                      /* display list size */
    .2byte  0xFFFF
.L_0601D370:
    .4byte  sym_060149E0               /* VDP2 display system init */
.L_0601D374:
    .4byte  channel_nibble_config      /* display channel priority config */
.L_0601D378:
    .4byte  audio_display_init         /* audio display init */
.L_0601D37C:
    .4byte  0x00017700                  /* ROM offset: character pattern data */
.L_0601D380:
    .4byte  0x25E6F9C4                  /* VDP2 VRAM +0x6F9C4 — pattern destination */
.L_0601D384:
    .4byte  sym_0600511E               /* pattern data upload */
.L_0601D388:
    .4byte  dma_transfer               /* word-indexed memcpy */
.L_0601D38C:
    .4byte  sym_0604842C               /* source: base palette (64 bytes) */
.L_0601D390:
    .4byte  0x25F00600                  /* VDP2 color RAM +0x600 — sprite high bank */
.L_0601D394:
    .4byte  sym_0604888C               /* source: sprite palette C (96 bytes) */
.L_0601D398:
    .4byte  0x25F00660                  /* VDP2 color RAM +0x660 — sprite C */
.L_0601D39C:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 — bank 0 */
.L_0601D3A0:
    .4byte  sym_06094FA8               /* source: tilemap A (results screen) */
.L_0601D3A4:
    .4byte  0x25E759EC                  /* VDP2 VRAM +0x759EC — tilemap A destination */
.L_0601D3A8:
    .4byte  dma_memory_transfer        /* DMA memory transfer */
.L_0601D3AC:
    .4byte  sym_06095F48               /* source: tilemap B (results screen) */
.L_0601D3B0:
    .4byte  0x25E75DDC                  /* VDP2 VRAM +0x75DDC — tilemap B destination */
.L_0601D3B4:
    .4byte  sym_06028400               /* display list loader */
.L_0601D3B8:
    .4byte  sym_0607887F               /* results screen state flag (byte) */
.L_0601D3BC:
    .4byte  sym_060149CC               /* display system finalize */

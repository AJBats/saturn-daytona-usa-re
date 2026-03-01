
    .section .text.FUN_06012E6A


    .global sound_scsp_boot
    .type sound_scsp_boot, @function
sound_scsp_boot:
    sts.l pr, @-r15
    .byte   0xD5, 0x0B    /* mov.l _pool_table_dest, r5 */
    .byte   0xD4, 0x0C    /* mov.l _pool_fn_table_bin, r4 */
    .byte   0xBE, 0xE4    /* bsr cd_dma_setup */
    nop
    .byte   0xD5, 0x0B    /* mov.l _pool_polygon_dest, r5 */
    .byte   0xD4, 0x0C    /* mov.l _pool_fn_polygon_bin, r4 */
    .byte   0xAE, 0xE0    /* bra cd_dma_setup */
    lds.l @r15+, pr

    .global sym_06012E7C
sym_06012E7C:
    .byte   0xD5, 0x0B    /* mov.l _pool_pit_dest, r5 */
    .byte   0xD4, 0x0C    /* mov.l _pool_fn_pit_bin, r4 */
    .byte   0xAE, 0xDC    /* bra cd_dma_setup */
    nop

    .global sym_06012E84
sym_06012E84:
    .byte   0xD5, 0x0B    /* mov.l _pool_sound_ram_base, r5 */
    .byte   0xD4, 0x0C    /* mov.l _pool_fn_sounds_bin, r4 */
    .byte   0xAE, 0xD8    /* bra cd_dma_setup */
    nop
    .4byte  sym_06044978
    .4byte  sym_06044984
    .4byte  0x002A0000
    .4byte  sym_06044990
_pool_table_dest:
    .4byte  0x002F0000
_pool_fn_table_bin:
    .4byte  sym_0604499C
_pool_polygon_dest:
    .4byte  sym_060F8000
_pool_fn_polygon_bin:
    .4byte  sym_060449A8
_pool_pit_dest:
    .4byte  0x002F8000
_pool_fn_pit_bin:
    .4byte  sym_060449B4
_pool_sound_ram_base:
    .4byte  0x25A00000
_pool_fn_sounds_bin:
    .4byte  sym_060449BC

    .global sym_06012EBC
sym_06012EBC:
    .byte   0xD5, 0x09    /* mov.l _pool_snd_ram_3000_a, r5 */
    .byte   0xD4, 0x0A    /* mov.l _pool_fn_gamed_bin, r4 */
    .byte   0xAE, 0xBC    /* bra cd_dma_setup */
    nop

    .global sym_06012EC4
sym_06012EC4:
    .byte   0xD5, 0x09    /* mov.l _pool_wram_low, r5 */
    .byte   0xD4, 0x08    /* mov.l _pool_fn_gamed_bin, r4 */
    .byte   0xAE, 0xB8    /* bra cd_dma_setup */
    nop
    .4byte  0xD508D409
    .4byte  0xAEB40009
    .4byte  0xD506D408
    .4byte  0xAEB00009

    .global sym_06012EDC
sym_06012EDC:
    .byte   0xD5, 0x01    /* mov.l _pool_snd_ram_3000_a, r5 */
    .byte   0xD4, 0x07    /* mov.l _pool_fn_slctd_bin_a, r4 */
    .byte   0xAE, 0xAC    /* bra cd_dma_setup */
    nop
_pool_snd_ram_3000_a:
    .4byte  0x25A03000
_pool_fn_gamed_bin:
    .4byte  sym_060449C8
_pool_wram_low:
    .4byte  0x00200000
    .4byte  0x25A10000
    .4byte  sym_060449D4
    .4byte  sym_060449E0
_pool_fn_slctd_bin_a:
    .4byte  sym_060449EC

    .global sym_06012F00
sym_06012F00:
    .byte   0xD5, 0x09    /* mov.l _pool_slctd_dest, r5 */
    .byte   0xD4, 0x0A    /* mov.l _pool_fn_slctd_bin_b, r4 */
    .byte   0xAE, 0x9A    /* bra cd_dma_setup */
    nop
    .4byte  0xD509D40A
    .4byte  0xAE960009

    .global sym_06012F10
sym_06012F10:
    .byte   0xD5, 0x09    /* mov.l _pool_snd_ram_3000_b, r5 */
    .byte   0xD4, 0x0A    /* mov.l _pool_fn_overd_bin, r4 */
    .byte   0xAE, 0x92    /* bra cd_dma_setup */
    nop
    .4byte  0xD505D409
    .4byte  0xAE8E0009

    .global sym_06012F20
sym_06012F20:
    .byte   0xD5, 0x05    /* mov.l _pool_snd_ram_3000_b, r5 */
    .byte   0xD4, 0x08    /* mov.l _pool_fn_namd_bin, r4 */
    .byte   0xAE, 0x8A    /* bra cd_dma_setup */
    nop
_pool_slctd_dest:
    .4byte  0x0026D000
_pool_fn_slctd_bin_b:
    .4byte  sym_060449EC
    .4byte  0x25A10000
    .4byte  sym_060449F8
_pool_snd_ram_3000_b:
    .4byte  0x25A03000
_pool_fn_overd_bin:
    .4byte  sym_06044A04
    .4byte  sym_06044A10
_pool_fn_namd_bin:
    .4byte  sym_06044A1C
    .4byte  0xD507D408
    .4byte  0xAE760009

    .global sym_06012F50
sym_06012F50:
    .byte   0xD5, 0x07    /* mov.l _pool_snd_ram_3000_c, r5 */
    .byte   0xD4, 0x08    /* mov.l _pool_fn_musicd_bin, r4 */
    .byte   0xAE, 0x72    /* bra cd_dma_setup */
    nop

    .global sym_06012F58
sym_06012F58:
    .byte   0xD5, 0x05    /* mov.l _pool_snd_ram_3000_c, r5 */
    .byte   0xD4, 0x07    /* mov.l _pool_fn_music2d_bin, r4 */
    .byte   0xAE, 0x6E    /* bra cd_dma_setup */
    nop

    .global sym_06012F60
sym_06012F60:
    .byte   0xD5, 0x03    /* mov.l _pool_snd_ram_3000_c, r5 */
    .byte   0xD4, 0x06    /* mov.l _pool_fn_music3d_bin, r4 */
    .byte   0xAE, 0x6A    /* bra cd_dma_setup */
    nop
    .4byte  0x25A10000
    .4byte  sym_06044A28
_pool_snd_ram_3000_c:
    .4byte  0x25A03000
_pool_fn_musicd_bin:
    .4byte  sym_06044A34
_pool_fn_music2d_bin:
    .4byte  sym_06044A40
_pool_fn_music3d_bin:
    .4byte  sym_06044A4C

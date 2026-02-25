/* sound_scsp_boot -- CD file loader thunks
 *
 * A collection of thin wrapper functions that load game assets from CD
 * into various memory destinations via cd_dma_setup(r4=filename, r5=dest).
 *
 * The first function (sound_scsp_boot) is called during system_init to
 * load TABLE.BIN and POLYGON.BIN.  The remaining functions load sound
 * data, overlay binaries, and music sequences into Sound RAM, Work RAM,
 * or dedicated buffer regions.  Several unnamed 8-byte inline code blocks
 * are additional loader thunks whose callers live in other TUs.
 *
 * Translation unit: 0x06012E6A - 0x06012F80
 */

    .section .text.FUN_06012E6A


    .global sound_scsp_boot
    .type sound_scsp_boot, @function
sound_scsp_boot:
    sts.l pr, @-r15                             ! save return address
    .byte   0xD5, 0x0B    /* mov.l _pool_table_dest, r5 */  ! r5 = 0x002F0000 (TABLE.BIN dest)
    .byte   0xD4, 0x0C    /* mov.l _pool_fn_table_bin, r4 */  ! r4 -> "TABLE.BIN" filename
    .byte   0xBE, 0xE4    /* bsr cd_dma_setup */             ! load TABLE.BIN to 0x002F0000
    nop                                         ! (delay slot)
    .byte   0xD5, 0x0B    /* mov.l _pool_polygon_dest, r5 */  ! r5 = sym_060F8000 (POLYGON.BIN dest)
    .byte   0xD4, 0x0C    /* mov.l _pool_fn_polygon_bin, r4 */  ! r4 -> "POLYGON.BIN" filename
    .byte   0xAE, 0xE0    /* bra cd_dma_setup */             ! tail-call: load POLYGON.BIN
    lds.l @r15+, pr                             ! (delay slot) restore return address

    .global sym_06012E7C
sym_06012E7C:                                   ! load_pit_bin — load PIT.BIN to 0x002F8000
    .byte   0xD5, 0x0B    /* mov.l _pool_pit_dest, r5 */  ! r5 = 0x002F8000 (PIT.BIN dest)
    .byte   0xD4, 0x0C    /* mov.l _pool_fn_pit_bin, r4 */  ! r4 -> "PIT.BIN" filename
    .byte   0xAE, 0xDC    /* bra cd_dma_setup */             ! tail-call: load PIT.BIN
    nop                                         ! (delay slot)

    .global sym_06012E84
sym_06012E84:                                   ! load_sounds_bin — load SOUNDS.BIN to Sound RAM
    .byte   0xD5, 0x0B    /* mov.l _pool_sound_ram_base, r5 */  ! r5 = 0x25A00000 (Sound RAM base)
    .byte   0xD4, 0x0C    /* mov.l _pool_fn_sounds_bin, r4 */  ! r4 -> "SOUNDS.BIN" filename
    .byte   0xAE, 0xD8    /* bra cd_dma_setup */             ! tail-call: load SOUNDS.BIN
    nop                                         ! (delay slot)
    .4byte  sym_06044978                        ! -> "TEX_C2.BIN" (pool for adjacent TU)
    .4byte  sym_06044984                        ! -> "TEX_C0.BIN" (pool for adjacent TU)
    .4byte  0x002A0000                          ! dest addr for adjacent TU loader
    .4byte  sym_06044990                        ! -> "SCROLL.BIN" (pool for adjacent TU)
_pool_table_dest:
    .4byte  0x002F0000                          ! TABLE.BIN destination address
_pool_fn_table_bin:
    .4byte  sym_0604499C                        ! -> "TABLE.BIN" filename string
_pool_polygon_dest:
    .4byte  sym_060F8000                        ! POLYGON.BIN destination address
_pool_fn_polygon_bin:
    .4byte  sym_060449A8                        ! -> "POLYGON.BIN" filename string
_pool_pit_dest:
    .4byte  0x002F8000                          ! PIT.BIN destination address
_pool_fn_pit_bin:
    .4byte  sym_060449B4                        ! -> "PIT.BIN" filename string
_pool_sound_ram_base:
    .4byte  0x25A00000                          ! Sound RAM base address
_pool_fn_sounds_bin:
    .4byte  sym_060449BC                        ! -> "SOUNDS.BIN" filename string

    .global sym_06012EBC
sym_06012EBC:                                   ! load_gamed_sndram — load GAMED.BIN to Sound RAM +0x3000
    .byte   0xD5, 0x09    /* mov.l _pool_snd_ram_3000_a, r5 */  ! r5 = 0x25A03000 (Sound RAM +0x3000)
    .byte   0xD4, 0x0A    /* mov.l _pool_fn_gamed_bin, r4 */  ! r4 -> "GAMED.BIN" filename
    .byte   0xAE, 0xBC    /* bra cd_dma_setup */             ! tail-call: load GAMED.BIN to snd RAM
    nop                                         ! (delay slot)

    .global sym_06012EC4
sym_06012EC4:                                   ! load_gamed_wram — load GAMED.BIN to Work RAM Low
    .byte   0xD5, 0x09    /* mov.l _pool_wram_low, r5 */  ! r5 = 0x00200000 (Work RAM Low)
    .byte   0xD4, 0x08    /* mov.l _pool_fn_gamed_bin, r4 */  ! r4 -> "GAMED.BIN" filename
    .byte   0xAE, 0xB8    /* bra cd_dma_setup */             ! tail-call: load GAMED.BIN to WRAM
    nop                                         ! (delay slot)
    .4byte  0xD508D409                          ! inline code: mov.l r5,@(+8*4,PC); mov.l r4,@(+9*4,PC)
    .4byte  0xAEB40009                          ! inline code: bra cd_dma_setup; nop
    .4byte  0xD506D408                          ! inline code: mov.l r5,@(+6*4,PC); mov.l r4,@(+8*4,PC)
    .4byte  0xAEB00009                          ! inline code: bra cd_dma_setup; nop

    .global sym_06012EDC
sym_06012EDC:                                   ! load_slctd_sndram — load SLCTD.BIN to Sound RAM +0x3000
    .byte   0xD5, 0x01    /* mov.l _pool_snd_ram_3000_a, r5 */  ! r5 = 0x25A03000 (Sound RAM +0x3000)
    .byte   0xD4, 0x07    /* mov.l _pool_fn_slctd_bin_a, r4 */  ! r4 -> "SLCTD.BIN" filename
    .byte   0xAE, 0xAC    /* bra cd_dma_setup */             ! tail-call: load SLCTD.BIN to snd RAM
    nop                                         ! (delay slot)
_pool_snd_ram_3000_a:
    .4byte  0x25A03000                          ! Sound RAM +0x3000 (68K driver area)
_pool_fn_gamed_bin:
    .4byte  sym_060449C8                        ! -> "GAMED.BIN" filename string
_pool_wram_low:
    .4byte  0x00200000                          ! Work RAM Low base address
    .4byte  0x25A10000                          ! SCSP register base (pool for inline code)
    .4byte  sym_060449D4                        ! -> "GAME0.BIN" (pool for inline code)
    .4byte  sym_060449E0                        ! -> "GAME1.BIN" (pool for inline code)
_pool_fn_slctd_bin_a:
    .4byte  sym_060449EC                        ! -> "SLCTD.BIN" filename string

    .global sym_06012F00
sym_06012F00:                                   ! load_slctd_wram — load SLCTD.BIN to 0x0026D000
    .byte   0xD5, 0x09    /* mov.l _pool_slctd_dest, r5 */  ! r5 = 0x0026D000 (Work RAM Low buffer)
    .byte   0xD4, 0x0A    /* mov.l _pool_fn_slctd_bin_b, r4 */  ! r4 -> "SLCTD.BIN" filename
    .byte   0xAE, 0x9A    /* bra cd_dma_setup */             ! tail-call: load SLCTD.BIN to WRAM
    nop                                         ! (delay slot)
    .4byte  0xD509D40A                          ! inline code: mov.l r5; mov.l r4 (SLCT0.BIN loader)
    .4byte  0xAE960009                          ! inline code: bra cd_dma_setup; nop

    .global sym_06012F10
sym_06012F10:                                   ! load_overd_sndram — load OVERD.BIN to Sound RAM +0x3000
    .byte   0xD5, 0x09    /* mov.l _pool_snd_ram_3000_b, r5 */  ! r5 = 0x25A03000 (Sound RAM +0x3000)
    .byte   0xD4, 0x0A    /* mov.l _pool_fn_overd_bin, r4 */  ! r4 -> "OVERD.BIN" filename
    .byte   0xAE, 0x92    /* bra cd_dma_setup */             ! tail-call: load OVERD.BIN to snd RAM
    nop                                         ! (delay slot)
    .4byte  0xD505D409                          ! inline code: mov.l r5; mov.l r4 (OVER0.BIN loader)
    .4byte  0xAE8E0009                          ! inline code: bra cd_dma_setup; nop

    .global sym_06012F20
sym_06012F20:                                   ! load_namd_sndram — load NAMD.BIN to Sound RAM +0x3000
    .byte   0xD5, 0x05    /* mov.l _pool_snd_ram_3000_b, r5 */  ! r5 = 0x25A03000 (Sound RAM +0x3000)
    .byte   0xD4, 0x08    /* mov.l _pool_fn_namd_bin, r4 */  ! r4 -> "NAMD.BIN" filename
    .byte   0xAE, 0x8A    /* bra cd_dma_setup */             ! tail-call: load NAMD.BIN to snd RAM
    nop                                         ! (delay slot)
_pool_slctd_dest:
    .4byte  0x0026D000                          ! SLCTD.BIN Work RAM destination
_pool_fn_slctd_bin_b:
    .4byte  sym_060449EC                        ! -> "SLCTD.BIN" filename string
    .4byte  0x25A10000                          ! SCSP register base (pool for inline code)
    .4byte  sym_060449F8                        ! -> "SLCT0.BIN" (pool for inline code)
_pool_snd_ram_3000_b:
    .4byte  0x25A03000                          ! Sound RAM +0x3000 (68K driver area)
_pool_fn_overd_bin:
    .4byte  sym_06044A04                        ! -> "OVERD.BIN" filename string
    .4byte  sym_06044A10                        ! -> "OVER0.BIN" (pool for inline code)
_pool_fn_namd_bin:
    .4byte  sym_06044A1C                        ! -> "NAMD.BIN" filename string
    .4byte  0xD507D408                          ! inline code: mov.l r5; mov.l r4 (NAM0.BIN loader)
    .4byte  0xAE760009                          ! inline code: bra cd_dma_setup; nop

    .global sym_06012F50
sym_06012F50:                                   ! load_musicd_sndram — load MUSICD.BIN to Sound RAM +0x3000
    .byte   0xD5, 0x07    /* mov.l _pool_snd_ram_3000_c, r5 */  ! r5 = 0x25A03000 (Sound RAM +0x3000)
    .byte   0xD4, 0x08    /* mov.l _pool_fn_musicd_bin, r4 */  ! r4 -> "MUSICD.BIN" filename
    .byte   0xAE, 0x72    /* bra cd_dma_setup */             ! tail-call: load MUSICD.BIN to snd RAM
    nop                                         ! (delay slot)

    .global sym_06012F58
sym_06012F58:                                   ! load_music2d_sndram — load MUSIC2D.BIN to Sound RAM +0x3000
    .byte   0xD5, 0x05    /* mov.l _pool_snd_ram_3000_c, r5 */  ! r5 = 0x25A03000 (Sound RAM +0x3000)
    .byte   0xD4, 0x07    /* mov.l _pool_fn_music2d_bin, r4 */  ! r4 -> "MUSIC2D.BIN" filename
    .byte   0xAE, 0x6E    /* bra cd_dma_setup */             ! tail-call: load MUSIC2D.BIN to snd RAM
    nop                                         ! (delay slot)

    .global sym_06012F60
sym_06012F60:                                   ! load_music3d_sndram — load MUSIC3D.BIN to Sound RAM +0x3000
    .byte   0xD5, 0x03    /* mov.l _pool_snd_ram_3000_c, r5 */  ! r5 = 0x25A03000 (Sound RAM +0x3000)
    .byte   0xD4, 0x06    /* mov.l _pool_fn_music3d_bin, r4 */  ! r4 -> "MUSIC3D.BIN" filename
    .byte   0xAE, 0x6A    /* bra cd_dma_setup */             ! tail-call: load MUSIC3D.BIN to snd RAM
    nop                                         ! (delay slot)
    .4byte  0x25A10000                          ! SCSP register base (pool for inline code)
    .4byte  sym_06044A28                        ! -> "NAM0.BIN" (pool for inline code)
_pool_snd_ram_3000_c:
    .4byte  0x25A03000                          ! Sound RAM +0x3000 (68K driver area)
_pool_fn_musicd_bin:
    .4byte  sym_06044A34                        ! -> "MUSICD.BIN" filename string
_pool_fn_music2d_bin:
    .4byte  sym_06044A40                        ! -> "MUSIC2D.BIN" filename string
_pool_fn_music3d_bin:
    .4byte  sym_06044A4C                        ! -> "MUSIC3D.BIN" filename string

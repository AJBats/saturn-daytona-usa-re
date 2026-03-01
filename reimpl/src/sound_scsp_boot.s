
    .section .text.FUN_06012E6A


    .global sound_scsp_boot
    .type sound_scsp_boot, @function
sound_scsp_boot:
    sts.l pr, @-r15
    .byte   0xD5, 0x0B    /* mov.l .L_pool_06012E9C, r5 */
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06012EA0, r4 */
    .byte   0xBE, 0xE4    /* bsr cd_dma_setup */
    nop
    .byte   0xD5, 0x0B    /* mov.l .L_pool_06012EA4, r5 */
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06012EA8, r4 */
    .byte   0xAE, 0xE0    /* bra cd_dma_setup */
    lds.l @r15+, pr

    .global sym_06012E7C
sym_06012E7C:
    .byte   0xD5, 0x0B    /* mov.l .L_pool_06012EAC, r5 */
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06012EB0, r4 */
    .byte   0xAE, 0xDC    /* bra cd_dma_setup */
    nop

    .global sym_06012E84
sym_06012E84:
    .byte   0xD5, 0x0B    /* mov.l .L_pool_06012EB4, r5 */
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06012EB8, r4 */
    .byte   0xAE, 0xD8    /* bra cd_dma_setup */
    nop
    .4byte  sym_06044978
    .4byte  sym_06044984
    .4byte  0x002A0000
    .4byte  sym_06044990
.L_pool_06012E9C:
    .4byte  0x002F0000
.L_pool_06012EA0:
    .4byte  sym_0604499C
.L_pool_06012EA4:
    .4byte  sym_060F8000
.L_pool_06012EA8:
    .4byte  sym_060449A8
.L_pool_06012EAC:
    .4byte  0x002F8000
.L_pool_06012EB0:
    .4byte  sym_060449B4
.L_pool_06012EB4:
    .4byte  0x25A00000
.L_pool_06012EB8:
    .4byte  sym_060449BC

    .global sym_06012EBC
sym_06012EBC:
    .byte   0xD5, 0x09    /* mov.l .L_pool_06012EE4, r5 */
    .byte   0xD4, 0x0A    /* mov.l .L_pool_06012EE8, r4 */
    .byte   0xAE, 0xBC    /* bra cd_dma_setup */
    nop

    .global sym_06012EC4
sym_06012EC4:
    .byte   0xD5, 0x09    /* mov.l .L_pool_06012EEC, r5 */
    .byte   0xD4, 0x08    /* mov.l .L_pool_06012EE8, r4 */
    .byte   0xAE, 0xB8    /* bra cd_dma_setup */
    nop
    .4byte  0xD508D409
    .4byte  0xAEB40009
    .4byte  0xD506D408
    .4byte  0xAEB00009

    .global sym_06012EDC
sym_06012EDC:
    .byte   0xD5, 0x01    /* mov.l .L_pool_06012EE4, r5 */
    .byte   0xD4, 0x07    /* mov.l .L_pool_06012EFC, r4 */
    .byte   0xAE, 0xAC    /* bra cd_dma_setup */
    nop
.L_pool_06012EE4:
    .4byte  0x25A03000
.L_pool_06012EE8:
    .4byte  sym_060449C8
.L_pool_06012EEC:
    .4byte  0x00200000
    .4byte  0x25A10000
    .4byte  sym_060449D4
    .4byte  sym_060449E0
.L_pool_06012EFC:
    .4byte  sym_060449EC

    .global sym_06012F00
sym_06012F00:
    .byte   0xD5, 0x09    /* mov.l .L_pool_06012F28, r5 */
    .byte   0xD4, 0x0A    /* mov.l .L_pool_06012F2C, r4 */
    .byte   0xAE, 0x9A    /* bra cd_dma_setup */
    nop
    .4byte  0xD509D40A
    .4byte  0xAE960009

    .global sym_06012F10
sym_06012F10:
    .byte   0xD5, 0x09    /* mov.l .L_pool_06012F38, r5 */
    .byte   0xD4, 0x0A    /* mov.l .L_pool_06012F3C, r4 */
    .byte   0xAE, 0x92    /* bra cd_dma_setup */
    nop
    .4byte  0xD505D409
    .4byte  0xAE8E0009

    .global sym_06012F20
sym_06012F20:
    .byte   0xD5, 0x05    /* mov.l .L_pool_06012F38, r5 */
    .byte   0xD4, 0x08    /* mov.l .L_pool_06012F44, r4 */
    .byte   0xAE, 0x8A    /* bra cd_dma_setup */
    nop
.L_pool_06012F28:
    .4byte  0x0026D000
.L_pool_06012F2C:
    .4byte  sym_060449EC
    .4byte  0x25A10000
    .4byte  sym_060449F8
.L_pool_06012F38:
    .4byte  0x25A03000
.L_pool_06012F3C:
    .4byte  sym_06044A04
    .4byte  sym_06044A10
.L_pool_06012F44:
    .4byte  sym_06044A1C
    .4byte  0xD507D408
    .4byte  0xAE760009

    .global sym_06012F50
sym_06012F50:
    .byte   0xD5, 0x07    /* mov.l .L_pool_06012F70, r5 */
    .byte   0xD4, 0x08    /* mov.l .L_pool_06012F74, r4 */
    .byte   0xAE, 0x72    /* bra cd_dma_setup */
    nop

    .global sym_06012F58
sym_06012F58:
    .byte   0xD5, 0x05    /* mov.l .L_pool_06012F70, r5 */
    .byte   0xD4, 0x07    /* mov.l .L_pool_06012F78, r4 */
    .byte   0xAE, 0x6E    /* bra cd_dma_setup */
    nop

    .global sym_06012F60
sym_06012F60:
    .byte   0xD5, 0x03    /* mov.l .L_pool_06012F70, r5 */
    .byte   0xD4, 0x06    /* mov.l .L_pool_06012F7C, r4 */
    .byte   0xAE, 0x6A    /* bra cd_dma_setup */
    nop
    .4byte  0x25A10000
    .4byte  sym_06044A28
.L_pool_06012F70:
    .4byte  0x25A03000
.L_pool_06012F74:
    .4byte  sym_06044A34
.L_pool_06012F78:
    .4byte  sym_06044A40
.L_pool_06012F7C:
    .4byte  sym_06044A4C

	.text
    .global sound_scsp_boot
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
    .long  sym_06044978
    .long  sym_06044984
    .long  0x002A0000
    .long  sym_06044990
.L_pool_06012E9C:
    .long  0x002F0000
.L_pool_06012EA0:
    .long  sym_0604499C
.L_pool_06012EA4:
    .long  sym_060F8000
.L_pool_06012EA8:
    .long  sym_060449A8
.L_pool_06012EAC:
    .long  0x002F8000
.L_pool_06012EB0:
    .long  sym_060449B4
.L_pool_06012EB4:
    .long  0x25A00000
.L_pool_06012EB8:
    .long  sym_060449BC

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
    .long  0xD508D409
    .long  0xAEB40009
    .long  0xD506D408
    .long  0xAEB00009

    .global sym_06012EDC
sym_06012EDC:
    .byte   0xD5, 0x01    /* mov.l .L_pool_06012EE4, r5 */
    .byte   0xD4, 0x07    /* mov.l .L_pool_06012EFC, r4 */
    .byte   0xAE, 0xAC    /* bra cd_dma_setup */
    nop
.L_pool_06012EE4:
    .long  0x25A03000
.L_pool_06012EE8:
    .long  sym_060449C8
.L_pool_06012EEC:
    .long  0x00200000
    .long  0x25A10000
    .long  sym_060449D4
    .long  sym_060449E0
.L_pool_06012EFC:
    .long  sym_060449EC

    .global sym_06012F00
sym_06012F00:
    .byte   0xD5, 0x09    /* mov.l .L_pool_06012F28, r5 */
    .byte   0xD4, 0x0A    /* mov.l .L_pool_06012F2C, r4 */
    .byte   0xAE, 0x9A    /* bra cd_dma_setup */
    nop
    .long  0xD509D40A
    .long  0xAE960009

    .global sym_06012F10
sym_06012F10:
    .byte   0xD5, 0x09    /* mov.l .L_pool_06012F38, r5 */
    .byte   0xD4, 0x0A    /* mov.l .L_pool_06012F3C, r4 */
    .byte   0xAE, 0x92    /* bra cd_dma_setup */
    nop
    .long  0xD505D409
    .long  0xAE8E0009

    .global sym_06012F20
sym_06012F20:
    .byte   0xD5, 0x05    /* mov.l .L_pool_06012F38, r5 */
    .byte   0xD4, 0x08    /* mov.l .L_pool_06012F44, r4 */
    .byte   0xAE, 0x8A    /* bra cd_dma_setup */
    nop
.L_pool_06012F28:
    .long  0x0026D000
.L_pool_06012F2C:
    .long  sym_060449EC
    .long  0x25A10000
    .long  sym_060449F8
.L_pool_06012F38:
    .long  0x25A03000
.L_pool_06012F3C:
    .long  sym_06044A04
    .long  sym_06044A10
.L_pool_06012F44:
    .long  sym_06044A1C
    .long  0xD507D408
    .long  0xAE760009

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
    .long  0x25A10000
    .long  sym_06044A28
.L_pool_06012F70:
    .long  0x25A03000
.L_pool_06012F74:
    .long  sym_06044A34
.L_pool_06012F78:
    .long  sym_06044A40
.L_pool_06012F7C:
    .long  sym_06044A4C

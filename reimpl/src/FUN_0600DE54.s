
    .section .text.FUN_0600DE54


    .global FUN_0600DE54
    .type FUN_0600DE54, @function
FUN_0600DE54:
    sts.l pr, @-r15
    .byte   0xD3, 0x17    /* mov.l .L_pool_0600DEB4, r3 */
    .byte   0xD2, 0x17    /* mov.l .L_pool_0600DEB8, r2 */
    mov.l @r3, r3
    shar r3
    mov.w r3, @r2
    .byte   0xD1, 0x16    /* mov.l .L_pool_0600DEBC, r1 */
    .byte   0xD2, 0x17    /* mov.l .L_pool_0600DEC0, r2 */
    mov.l @r1, r1
    mov.l r1, @r2
    .reloc ., R_SH_IND12W, FUN_0600E99C - 4
    .2byte 0xB000    /* bsr FUN_0600E99C (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0600E0C0 - 4
    .2byte 0xA000    /* bra FUN_0600E0C0 (linker-resolved) */
    lds.l @r15+, pr

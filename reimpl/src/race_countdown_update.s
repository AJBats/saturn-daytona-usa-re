
    .section .text.FUN_0600DE40


    .global race_countdown_update
    .type race_countdown_update, @function
race_countdown_update:
    sts.l pr, @-r15
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0600DEB4, r3 */
    .byte   0xD2, 0x1C    /* mov.l .L_pool_0600DEB8, r2 */
    mov.l @r3, r3
    shar r3
    mov.w r3, @r2
    .reloc ., R_SH_IND12W, car_update_simple - 4
    .2byte 0xB000    /* bsr car_update_simple (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, car_update_racing - 4
    .2byte 0xA000    /* bra car_update_racing (linker-resolved) */
    lds.l @r15+, pr

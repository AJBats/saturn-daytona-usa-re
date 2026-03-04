
    .section .text.FUN_0603B324


    .global menu_option_adj
    .type menu_option_adj, @function
menu_option_adj:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r5, @r15
    mov.b @(r0, r14), r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_0603B33E
    mov #-0x10, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603B33E:
    .reloc ., R_SH_IND12W, save_data_validate - 4
    .2byte 0xB000    /* bsr save_data_validate (linker-resolved) */
    mov r14, r4
    mov #0x2, r2
    mov #0x11, r0
    mov #0x1, r3
    mov.b r2, @(r0, r14)
    mov #0x12, r0
    mov.b r3, @(r0, r14)
    mov.l @r14, r3
    mov.l @(16, r3), r8
    .reloc ., R_SH_IND12W, menu_element_dispatch - 4
    .2byte 0xB000    /* bsr menu_element_dispatch (linker-resolved) */
    mov r14, r4
    mov r8, r4
    mov.l @r15, r3
    sub r0, r4
    cmp/ge r4, r3
    bt      .L_0603B364
    bra     .L_0603B366
    mov.l @r15, r5
.L_0603B364:
    mov r4, r5
.L_0603B366:
    .reloc ., R_SH_IND12W, FUN_0603BE7C - 4
    .2byte 0xB000    /* bsr FUN_0603BE7C (linker-resolved) */
    mov.l @r14, r4
    mov #0x0, r5
    .byte   0xD3, 0x10    /* mov.l .L_pool_0603B3B0, r3 */
    jsr @r3
    mov.l @(8, r14), r4
    mov #0x1, r7
    mov #0x0, r6
    .byte   0xD3, 0x0F    /* mov.l .L_pool_0603B3B4, r3 */
    mov r6, r5
    jsr @r3
    mov.l @(4, r14), r4
    mov #-0x1, r5
    .byte   0xD3, 0x0D    /* mov.l .L_pool_0603B3B8, r3 */
    jsr @r3
    mov.l @(8, r14), r4
    mov #0x0, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14

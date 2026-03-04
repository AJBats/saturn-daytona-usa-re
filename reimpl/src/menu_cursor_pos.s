
    .section .text.FUN_0603B130


    .global menu_cursor_pos
    .type menu_cursor_pos, @function
menu_cursor_pos:
    mov.l r14, @-r15
    mov.l @(24, r15), r2
    mov.l r2, @-r15
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov.l @(20, r15), r7
    mov.l @(28, r15), r4
    .reloc ., R_SH_IND12W, save_data_size - 4
    .2byte 0xB000    /* bsr save_data_size (linker-resolved) */
    mov.l @r4, r4
    add #0x10, r15
    mov.l @r15, r0
    tst #0x8, r0
    bt      .L_0603B15C
    bra     .L_0603B14E
    nop
.L_0603B14E:
    mov.l @r15, r0
    tst #0x4, r0
    bt      .L_0603B15C
    bra     .L_0603B158
    nop
.L_0603B158:
    mov.l @(4, r15), r2
    mov.l r14, @r2
.L_0603B15C:
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
    add #0x14, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

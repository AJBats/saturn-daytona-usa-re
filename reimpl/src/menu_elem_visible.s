
    .section .text.FUN_0603B08E


    .global menu_elem_visible
    .type menu_elem_visible, @function
menu_elem_visible:
    sts.l pr, @-r15
    add #-0x8, r15
    .reloc ., R_SH_IND12W, menu_element_dispatch - 4
    .2byte 0xB000    /* bsr menu_element_dispatch (linker-resolved) */
    mov.l r4, @r15
    mov.l r0, @(4, r15)
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r2
    mov.l @r2, r3
    mov.l @(4, r15), r2
    mov.l @(16, r3), r3
    cmp/ge r3, r2
    bf      .L_0603B0B4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov #0x1, r0
    .4byte  sym_060A4D14
.L_0603B0B4:
    mov #0x0, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xE01D

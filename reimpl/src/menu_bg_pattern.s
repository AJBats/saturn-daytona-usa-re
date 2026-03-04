
    .section .text.FUN_0603B5F2


    .global menu_bg_pattern
    .type menu_bg_pattern, @function
menu_bg_pattern:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l @r4, r4
    mov.l @(40, r4), r3
    mov.l r3, @r15
    mov.l r5, @(40, r4)
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop


    .section .text.FUN_0603B3D0


    .global menu_separator
    .type menu_separator, @function
menu_separator:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r3, @(r0, r14)
    .reloc ., R_SH_IND12W, save_field_read - 4
    .2byte 0xB000    /* bsr save_field_read (linker-resolved) */
    mov r14, r4
    mov r14, r13
    .reloc ., R_SH_IND12W, sys_dma_channel_init - 4
    .2byte 0xB000    /* bsr sys_dma_channel_init (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_0603B8F4 - 4
    .2byte 0xB000    /* bsr FUN_0603B8F4 (linker-resolved) */
    mov r13, r4
    .reloc ., R_SH_IND12W, menu_element_dispatch - 4
    .2byte 0xB000    /* bsr menu_element_dispatch (linker-resolved) */
    mov r13, r4
    mov.l r0, @r15
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .global FUN_0603B3FA
FUN_0603B3FA:
    .2byte  0x6343
    .2byte  0xE011

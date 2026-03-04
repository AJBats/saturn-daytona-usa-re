
    .section .text.FUN_0603F500


    .global audio_sync_slave
    .type audio_sync_slave, @function
audio_sync_slave:
    sts.l pr, @-r15
    mov #0x4, r6
    add #-0xC, r15
    mov r15, r5
    mov.l r4, @(4, r15)
    .reloc ., R_SH_IND12W, menu_element_render - 4
    .2byte 0xB000    /* bsr menu_element_render (linker-resolved) */
    add #0x8, r5
    mov #0x4, r6
    mov r15, r5
    .reloc ., R_SH_IND12W, menu_element_render - 4
    .2byte 0xB000    /* bsr menu_element_render (linker-resolved) */
    mov.l @(4, r15), r4
    mov.l @r15, r0
    add #0xC, r15
    lds.l @r15+, pr
    rts
    nop

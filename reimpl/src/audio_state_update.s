
    .section .text.FUN_0603F4CC


    .global audio_state_update
    .type audio_state_update, @function
audio_state_update:
    sts.l pr, @-r15
    mov #0x2, r6
    add #-0x4, r15
    .reloc ., R_SH_IND12W, menu_element_render - 4
    .2byte 0xB000    /* bsr menu_element_render (linker-resolved) */
    mov r15, r5
    mov.w @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop

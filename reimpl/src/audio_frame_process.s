
    .section .text.FUN_0603F4B0


    .global audio_frame_process
    .type audio_frame_process, @function
audio_frame_process:
    sts.l pr, @-r15
    add #-0x4, r15
    .reloc ., R_SH_IND12W, menu_element_render - 4
    .2byte 0xB000    /* bsr menu_element_render (linker-resolved) */
    mov r15, r5
    mov.b @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x0800
    .4byte  cmd_multi_validate
    .4byte  sym_060360FC

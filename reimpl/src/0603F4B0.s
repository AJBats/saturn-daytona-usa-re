	.text
    .global audio_frame_process
audio_frame_process:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xBF, 0x9F    /* bsr 0x0603F3F6 (external) */
    mov r15, r5
    mov.b @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
    .short  0x0800
    .long  cmd_multi_validate
    .long  sym_060360FC


    .section .text.FUN_0603F4CC


    .global audio_state_update
    .type audio_state_update, @function
audio_state_update:
    sts.l pr, @-r15
    mov #0x2, r6
    add #-0x4, r15
    .byte   0xBF, 0x90    /* bsr 0x0603F3F6 (external) */
    mov r15, r5
    mov.w @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop

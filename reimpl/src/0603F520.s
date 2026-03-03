	.text
    .global audio_event_trigger
audio_event_trigger:
    sts.l pr, @-r15
    mov #0x4, r6
    add #-0x4, r15
    .byte   0xBF, 0x66    /* bsr 0x0603F3F6 (external) */
    mov r15, r5
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop

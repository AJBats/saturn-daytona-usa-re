	.text
    .global evt_status_flag_set
evt_status_flag_set:
    sts.l pr, @-r15
    .byte   0xB0, 0x05    /* bsr 0x06040964 (external) */
    nop
    shll8 r0
    lds.l @r15+, pr
    shll2 r0
    rts
    shll r0

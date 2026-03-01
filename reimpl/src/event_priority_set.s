
    .section .text.FUN_06040AF8


    .global event_priority_set
    .type event_priority_set, @function
event_priority_set:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    bsr     .L_get_priority_offset
    mov.l r4, @r15
    mov r0, r14
    tst r14, r14
    bf      .L_offset_valid
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_offset_valid:
    mov.l @r15, r5
    .byte   0xB0, 0x7C    /* bsr 0x06040C10 (external: evt_state_dispatch) */
    mov r14, r4
    mov r0, r4
    tst r4, r4
    bf      .L_dispatch_ok
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_dispatch_ok:
    mov r14, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_get_priority_offset:
    mov #0x10, r0

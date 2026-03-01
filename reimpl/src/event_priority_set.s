
    .section .text.FUN_06040AF8


    .global event_priority_set
    .type event_priority_set, @function
event_priority_set:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    bsr     .L_06040B32
    mov.l r4, @r15
    mov r0, r14
    tst r14, r14
    bf      .L_06040B12
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06040B12:
    mov.l @r15, r5
    .byte   0xB0, 0x7C    /* bsr 0x06040C10 (external: evt_state_dispatch) */
    mov r14, r4
    mov r0, r4
    tst r4, r4
    bf      .L_06040B28
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06040B28:
    mov r14, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06040B32:
    mov #0x10, r0

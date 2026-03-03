	.text
    .global mode_flag_set_a
mode_flag_set_a:
    sts.l pr, @-r15
    mov r4, r0
    add #-0x8, r15
    mov r15, r3
    mov.l r2, @r3
    mov r15, r3
    mov.b r0, @(4, r3)
    mov r15, r3
    mov #0x1, r0
    mov.b r0, @(5, r3)
    .byte   0xD3, 0x04    /* mov.l .L_06018E48, r3 */
    jsr @r3
    mov r15, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
    .long  ai_throttle_modulate
.L_06018E48:
    .long  ai_recovery_handler

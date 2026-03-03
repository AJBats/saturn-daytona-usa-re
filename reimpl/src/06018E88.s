	.text
    .global mode_flag_set_c
mode_flag_set_c:
    sts.l pr, @-r15
    mov #0x0, r2
    add #-0x8, r15
    mov r15, r3
    mov.l r2, @r3
    mov.l   .L_06018EA8, r3
    jsr @r3
    mov r15, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
    .long  0x00FFFFFF
    .long  ai_throttle_modulate
.L_06018EA8:
    .long  ai_recovery_handler

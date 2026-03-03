
    .section .text.FUN_06018E88


    .global mode_flag_set_c
    .type mode_flag_set_c, @function
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
    .4byte  0x00FFFFFF
    .4byte  ai_throttle_modulate
.L_06018EA8:
    .4byte  ai_recovery_handler

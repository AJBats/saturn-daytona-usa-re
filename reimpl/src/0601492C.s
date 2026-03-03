
    .section .text.FUN_0601492C


    .global channel_config_a
    .type channel_config_a, @function
channel_config_a:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_06014960, r14
    mov.w   .L_0601495C, r4
    jsr @r14
    mov #0x4, r5
    mov #0x1, r5
    jsr @r14
    mov #0x4, r4
    mov #0x5, r5
    jsr @r14
    mov #0x8, r4
    mov #0x6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x7, r5
    jsr @r14
    mov #0x20, r4
    mov #0x0, r5
    jsr @r14
    mov #0x1, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601495C:
    .2byte  0x0100
    .2byte  0xFFFF
.L_06014960:
    .4byte  channel_nibble_config

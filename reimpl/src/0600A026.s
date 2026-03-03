	.text
    .global audio_display_init
audio_display_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x13    /* mov.l .L_0600A078, r14 */
    jsr @r14
    mov #0x0, r4
    jsr @r14
    mov #0x4, r4
    jsr @r14
    mov #0x8, r4
    jsr @r14
    mov #0xC, r4
    .byte   0xD3, 0x0F    /* mov.l .L_0600A07C, r3 */
    jsr @r3
    nop
    mov #0x0, r6
    .byte   0xDE, 0x0E    /* mov.l .L_0600A080, r14 */
    mov r6, r5
    jsr @r14
    mov #0x4, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x20, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .short  0xFFFF
    .long  sound_cmd_dispatch
    .long  0xAE0001FF
    .long  0xAE0600FF
.L_0600A078:
    .long  sym_0602853E
.L_0600A07C:
    .long  sym_06028560
.L_0600A080:
    .long  display_channel_b
    .long  0xD523E401
    .long  0x90406352
    .long  0x023E3247
    .long  0x8904E600
    .long  0x6563D320
    .long  0x432BE410
    .long  0x62529035
    .long  0xD31E052E
    .long  0x63324518
    .long  0x24394508
    .long  0x45084508
    .long  0x45002448
    .long  0x8900655B
    .long  0xE600D317
    .long  0x432BE410


    .section .text.FUN_0600A026


    .global audio_display_init
    .type audio_display_init, @function
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
    .2byte  0xFFFF
    .4byte  sound_cmd_dispatch
    .4byte  0xAE0001FF
    .4byte  0xAE0600FF
.L_0600A078:
    .4byte  sym_0602853E
.L_0600A07C:
    .4byte  sym_06028560
.L_0600A080:
    .4byte  display_channel_b
    .4byte  0xD523E401
    .4byte  0x90406352
    .4byte  0x023E3247
    .4byte  0x8904E600
    .4byte  0x6563D320
    .4byte  0x432BE410
    .4byte  0x62529035
    .4byte  0xD31E052E
    .4byte  0x63324518
    .4byte  0x24394508
    .4byte  0x45084508
    .4byte  0x45002448
    .4byte  0x8900655B
    .4byte  0xE600D317
    .4byte  0x432BE410

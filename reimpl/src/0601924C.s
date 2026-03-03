	.text
    .global transition_full_exec
transition_full_exec:
    sts.l pr, @-r15
    mov.l   .L_06019290, r14
    mov.l   .L_06019294, r2
    mov.l r3, @r2
    mov.l   .L_06019298, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_0601929C, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB0, 0x42    /* bsr 0x060192E8 (external) */
    nop
    mov.l   .L_06019294, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601927E
    mov.l   .L_060192A0, r6
    mov.l   .L_060192A4, r5
    mov.l   .L_060192A8, r4
    mov.l   .L_060192AC, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_060192B0, r3
    mov.w r2, @r3
.L_0601927E:
    mov.l   .L_06019298, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .short  0x000B
    .long  0x0009FFFF
.L_06019290:
    .long  sound_cmd_dispatch
.L_06019294:
    .long  sym_06086050
.L_06019298:
    .long  0xAE0001FF
.L_0601929C:
    .long  0xAE0005FF
.L_060192A0:
    .long  0x0006D000
.L_060192A4:
    .long  0x0026D000
.L_060192A8:
    .long  0x25A03000
.L_060192AC:
    .long  memcpy_byte_idx
.L_060192B0:
    .long  0x25A02DBE
    .long  0xE500D611
    .long  0xD4116363
    .long  0x625E7601
    .long  0x44108FFA
    .long  0x2320000B
    .short  0x0009

    .global sym_060192CA
sym_060192CA:
    mov #0x0, r5

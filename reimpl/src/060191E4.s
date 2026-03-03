	.text
    .global transition_multi_step
transition_multi_step:
    sts.l pr, @-r15
    mov.l   .L_06019224, r14
    mov.l   .L_06019228, r2
    mov.l r3, @r2
    mov.l   .L_0601922C, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_06019230, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB0, 0x76    /* bsr 0x060192E8 (external) */
    nop
    mov.l   .L_06019228, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06019216
    mov.l   .L_06019234, r6
    mov.l   .L_06019238, r5
    mov.l   .L_0601923C, r4
    mov.l   .L_06019240, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_06019244, r3
    mov.w r2, @r3
.L_06019216:
    mov.l   .L_0601922C, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .short  0xFFFF
.L_06019224:
    .long  sound_cmd_dispatch
.L_06019228:
    .long  sym_06086050
.L_0601922C:
    .long  0xAE0001FF
.L_06019230:
    .long  0xAE0005FF
.L_06019234:
    .long  0x0006D000
.L_06019238:
    .long  0x00200000
.L_0601923C:
    .long  0x25A03000
.L_06019240:
    .long  memcpy_byte_idx
.L_06019244:
    .long  0x25A02DBE

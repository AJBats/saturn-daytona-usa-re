	.text
    .global palette_frame_effects
palette_frame_effects:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_060193C8, r14

    mov.l   .L_060193CC, r5
    mov.l   .L_060193D0, r4
    jsr @r14
    mov #0x20, r6

    mov.l   .L_060193D4, r5
    mov.l   .L_060193D8, r4
    jsr @r14
    mov #0x20, r6

    mov.l   .L_060193DC, r5
    mov.l   .L_060193E0, r4
    jsr @r14
    mov #0x20, r6

    mov.w   .L_060193C4, r6
    mov.l   .L_060193E4, r5
    mov.l   .L_060193E8, r4
    jsr @r14
    nop

    mov.w   .L_060193C6, r6
    mov.l   .L_060193EC, r5
    mov.l   .L_060193F0, r4
    jsr @r14
    nop

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

.L_060193C4:
    .short  0x00E0
.L_060193C6:
    .short  0x0080

.L_060193C8:
    .long  memcpy_word_idx
.L_060193CC:
    .long  sym_0605CE9C
.L_060193D0:
    .long  0x25F00540
.L_060193D4:
    .long  sym_0605CD9C
.L_060193D8:
    .long  0x25F00000
.L_060193DC:
    .long  sym_0605CF9C
.L_060193E0:
    .long  0x25F00600
.L_060193E4:
    .long  sym_0605CEBC
.L_060193E8:
    .long  0x25F00620
.L_060193EC:
    .long  sym_06049DC4
.L_060193F0:
    .long  0x25F00780

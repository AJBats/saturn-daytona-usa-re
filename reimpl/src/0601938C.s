
    .section .text.FUN_0601938C


    .global palette_frame_effects
    .type palette_frame_effects, @function
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
    .2byte  0x00E0
.L_060193C6:
    .2byte  0x0080

.L_060193C8:
    .4byte  memcpy_word_idx
.L_060193CC:
    .4byte  sym_0605CE9C
.L_060193D0:
    .4byte  0x25F00540
.L_060193D4:
    .4byte  sym_0605CD9C
.L_060193D8:
    .4byte  0x25F00000
.L_060193DC:
    .4byte  sym_0605CF9C
.L_060193E0:
    .4byte  0x25F00600
.L_060193E4:
    .4byte  sym_0605CEBC
.L_060193E8:
    .4byte  0x25F00620
.L_060193EC:
    .4byte  sym_06049DC4
.L_060193F0:
    .4byte  0x25F00780

	.text
    .global obj_render_cleanup
obj_render_cleanup:
    sts.l pr, @-r15
    mov.l   .L_06021158, r3
    jsr @r3
    mov #0x8, r4
    mov #0x1, r2
    mov.l   .L_0602115C, r3
    mov.b r2, @r3
    mov.l   .L_06021160, r4
    mov.l   .L_06021164, r3
    jsr @r3
    nop
    mov.l   .L_06021168, r3
    jsr @r3
    nop
    mov #0x0, r4
    mov.l   .L_0602116C, r3
    mov.b r4, @r3
    mov.l   .L_06021170, r3
    mov.b r4, @r3
    mov.l   .L_06021174, r3
    lds.l @r15+, pr
    rts
    mov.l r4, @r3
    .short  0xFFFF
.L_06021158:
    .long  sym_0603850C
.L_0602115C:
    .long  sym_06087C87
.L_06021160:
    .long  sym_06087C84
.L_06021164:
    .long  scene_buffer_init
.L_06021168:
    .long  sym_06038520
.L_0602116C:
    .long  sym_06089594
.L_06021170:
    .long  sym_06089595
.L_06021174:
    .long  sym_06089598

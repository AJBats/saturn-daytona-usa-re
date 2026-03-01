
    .section .text.FUN_06021128


    .global obj_render_cleanup
    .type obj_render_cleanup, @function
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
    .2byte  0xFFFF                         /* padding to align constant pool */
.L_06021158:
    .4byte  sym_0603850C
.L_0602115C:
    .4byte  sym_06087C87
.L_06021160:
    .4byte  sym_06087C84
.L_06021164:
    .4byte  scene_buffer_init
.L_06021168:
    .4byte  sym_06038520
.L_0602116C:
    .4byte  sym_06089594
.L_06021170:
    .4byte  sym_06089595
.L_06021174:
    .4byte  sym_06089598

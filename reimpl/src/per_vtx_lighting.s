
    .section .text.FUN_0602E768


    .global per_vtx_lighting
    .type per_vtx_lighting, @function
per_vtx_lighting:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov r0, r7
    cmp/pz r7
    bt      .L_abs_done
    neg r7, r7
.L_abs_done:
    mov.l   .L_intensity_threshold, r11
    cmp/ge r11, r7
    bt      .L_high_intensity_exit
    bra     .L_compute_vertex_deltas
    nop
    .2byte  0x0000
    .4byte  isqrt
.L_intensity_threshold:
    .4byte  0x000F0000

.L_high_intensity_exit:
    mov.l   .L_vtx_offset_x, r0
    mov.l @(r0, r9), r3
    mov.l   .L_light_output_x, r1
    mov.l r3, @r1
    mov.l   .L_vtx_offset_y, r0
    mov.l @(r0, r9), r3
    mov.l   .L_light_output_y, r1
    mov.l r3, @r1
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    rts
    nop
    .2byte  0x0000
.L_vtx_offset_x:
    .4byte  0x00000238
.L_light_output_x:
    .4byte  DAT_06083264
.L_vtx_offset_y:
    .4byte  0x0000023C
.L_light_output_y:
    .4byte  DAT_06083268

.L_compute_vertex_deltas:
    mov.l @(16, r9), r6
    mov.l @(24, r9), r7
    mov.l @(16, r10), r11
    mov.l @(24, r10), r12
    mov.l r0, @-r15
    mov r11, r4
    sub r6, r4
    mov r12, r5
    sub r7, r5
    .byte   0xD0, 0x0E    /* mov.l .L_pool_0602E80C, r0 */ ! load cross-TU pool constant (in shadow_intensity)

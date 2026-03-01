
    .section .text.FUN_060156AC


    .global minimap_car_dot
    .type minimap_car_dot, @function
minimap_car_dot:
    sts.l pr, @-r15
    add #-0x4, r15
    mov r15, r1
    mov.l   .L_pool_color_template_src, r2
    mov.l   .L_pool_memcpy_byte, r3
    jsr @r3
    mov #0x4, r0
    extu.b r13, r14
    mov.l   .L_pool_slot_data_base, r2
    extu.b r13, r4
    mov r14, r3
    shll2 r4
    shll2 r14
    shll2 r3
    shll2 r4
    shll2 r3
    shll2 r3
    add r3, r14
    exts.w r14, r14
    mov.l   .L_pool_car_init_template, r3
    add r2, r14
    add r3, r4
    mov.l @r4, r2
    mov.l r2, @(4, r14)
    mov.l @(4, r4), r3
    mov.l r3, @(8, r14)
    mov.l @(8, r4), r2
    mov.l r2, @(12, r14)
    mov.l @(12, r4), r3
    mov.l r3, @(52, r14)
    mov.l   .L_pool_track_vtx_builder, r3
    jsr @r3
    extu.b r13, r4
    extu.b r13, r4
    mov.l   .L_pool_vertex_table, r2
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    extu.b r13, r3
    add r2, r4
    mov r15, r2
    add r2, r3
    mov.b @r3, r3
    extu.b r3, r0
    mov.w r0, @(6, r4)
    mov #0x3C, r3
    mov #0x1, r0
    mov.b r0, @(4, r4)
    mov #0x3A, r0
    mov.b r0, @(5, r4)
    mov #0x41, r0
    mov.b r3, @(r0, r14)
    mov.b @(2, r14), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    mov.b r0, @(2, r14)
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_slot_data_base:
    .4byte  sym_06084FC8
    .4byte  sym_0605B858
.L_pool_color_template_src:
    .4byte  sym_0605B8A0
.L_pool_memcpy_byte:
    .4byte  sym_06035228
.L_pool_car_init_template:
    .4byte  sym_0605B860
.L_pool_track_vtx_builder:
    .4byte  track_vtx_builder
.L_pool_vertex_table:
    .4byte  sym_06085490

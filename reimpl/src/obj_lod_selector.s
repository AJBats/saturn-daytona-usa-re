
    .section .text.FUN_06020950


    .global obj_lod_selector
    .type obj_lod_selector, @function
obj_lod_selector:
    sts.l pr, @-r15
    add #-0x5C, r15
    mov.l   .L_pool_vram_rect_fill, r12
    mov r15, r13
    mov r15, r1
    mov.l   .L_pool_blank_tile_src, r2
    mov.l   .L_pool_memcpy_byte, r3
    jsr @r3
    mov #0x5C, r0
    mov #0x0, r14
.L_lod_loop:
    mov #0x0, r7
    extu.b r14, r6
    mov r13, r5
    shll2 r6
    shll2 r6
    shll2 r6
    shll r6
    jsr @r12
    mov #0x4, r4
    mov #0x0, r7
    extu.b r14, r6
    mov r13, r5
    shll2 r6
    shll2 r6
    shll2 r6
    add #0x2C, r6
    shll r6
    jsr @r12
    mov #0x4, r4
    add #0x1, r14
    extu.b r14, r3
    cmp/ge r11, r3
    bf      .L_lod_loop
    add #0x5C, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_vram_rect_fill:
    .4byte  sym_06028400
.L_pool_blank_tile_src:
    .4byte  sym_0605F52A
.L_pool_memcpy_byte:
    .4byte  sym_06035228

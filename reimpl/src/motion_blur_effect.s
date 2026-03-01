
    .section .text.FUN_060284BA


    .global motion_blur_effect
    .type motion_blur_effect, @function
motion_blur_effect:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xD0, 0x1D    /* mov.l _pool_vram_ptr_table, r0 */ ! r0 = &vram_ptr_table
    mov.l @(r0, r4), r4
    mov.l @r4, r4
    add r4, r5
    mov r7, r0
    .byte   0xD1, 0x1B    /* mov.l _pool_template_base, r1 */ ! r1 = template table base (sym_06063690)
    add r1, r6
    mov.l @r6+, r1
    mov.w @r6+, r2
    mov.b @r6+, r3
    mov.b @r6+, r4
    mov.b @r6+, r11
    mov.b @r6+, r8
    mov r0, r14
    mov #-0x1, r12
.blur_map_strlen:
    mov.b @r0+, r7
    tst r7, r7
    bf/s    .blur_map_strlen
    add #0x1, r12
    mulu.w r12, r3
    mov r12, r10
    sts macl, r12
    add #-0x40, r12
    neg r12, r12
    shll r12
    mov r14, r0
.row_group_loop:
    mov r10, r9
    mov r14, r0
.tile_loop:
    mov.b @r0+, r7
    mov r3, r13
    sub r8, r7
    mulu.w r7, r11
    mov r1, r6
    sts macl, r7
    add r7, r6
.pixel_copy_loop:
    mov.w @r6, r7
    add r2, r7
    mov.w r7, @r5
    add #0x2, r6
    dt r13
    bf/s    .pixel_copy_loop
    add #0x2, r5
    dt r9
    bf      .tile_loop
    add r3, r1
    add r3, r1
    dt r4
    bf/s    .row_group_loop
    add r12, r5
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
    .2byte  0x0000
_pool_vram_ptr_table:
    .4byte  sym_06028614
_pool_template_base:
    .4byte  sym_06063690
    .2byte  0x0009

    .global sym_0602853E
sym_0602853E:
    .byte   0xD0, 0x06    /* mov.l _pool_default_color_table, r0 */ ! r0 = &default_color_table
    mov.l @(r0, r4), r2
    .byte   0xD0, 0x06    /* mov.l _pool_vram_buf_table, r0 */ ! r0 = &vram_buf_ptr_table
    mov.l @(r0, r4), r0
    mov.l @r0, r0
    mov.w   _wpool_fill_count, r1
.vram_fill_loop:
    mov.l r2, @r0
    dt r1
    bf/s    .vram_fill_loop
    add #0x4, r0
    rts
    nop
_wpool_fill_count:
    .2byte  0x0800
_pool_default_color_table:
    .4byte  sym_06028644
_pool_vram_buf_table:
    .4byte  sym_0602862C

    .global sym_06028560
sym_06028560:
    .byte   0xD0, 0x04    /* mov.l _pool_vram_config_addr, r0 */ ! r0 = VRAM config region base (sym_060612C4)
    mov.w   _wpool_config_count, r1
    .byte   0xD2, 0x04    /* mov.l _pool_default_pattern, r2 */ ! r2 = 0x00200020 (default pixel pattern)
.config_fill_loop:
    mov.l r2, @r0
    dt r1
    bf/s    .config_fill_loop
    add #0x4, r0
    rts
    nop
_wpool_config_count:
    .2byte  0x0380
_pool_vram_config_addr:
    .4byte  sym_060612C4
_pool_default_pattern:
    .4byte  0x00200020
    .4byte  0x00002800

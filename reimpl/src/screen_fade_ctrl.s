
    .section .text.FUN_0602843A


    .global screen_fade_ctrl
    .type screen_fade_ctrl, @function
screen_fade_ctrl:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xD0, 0x19    /* mov.l _pool_vram_ptr_table, r0 */ ! r0 = &vram_pointer_table (sym_06028614)
    mov.l @(r0, r4), r4
    mov.l @r4, r4
    add r4, r5
    .byte   0xBF, 0x5E    /* bsr 0x06028306 (external) */ ! call tile_index_map_lookup(r4)
    mov r7, r4
    .byte   0xD1, 0x17    /* mov.l _pool_template_base, r1 */ ! r1 = template table base (sym_06063690)
    add r1, r6
    mov.l @r6+, r1
    mov.w @r6+, r2
    mov.b @r6+, r3
    mov.b @r6+, r4
    mov.b @r6+, r11
    mov.b @r6+, r8
    mov.w @r6+, r12
    mov r8, r13
    add #-0xC, r13
    neg r13, r13
    add r13, r0
    mov r12, r6
    mov r0, r14
.L_row_group:
    mov r8, r12
    mov r14, r0
.L_tile_loop:
    mov r3, r13
    mov r1, r9
    mov.b @r0+, r7
    mulu.w r7, r11
    sts macl, r7
    add r7, r9
.L_pixel_loop:
    mov.w @r9, r7
    add r2, r7
    mov.w r7, @r5
    add #0x2, r9
    dt r13
    bf/s    .L_pixel_loop
    add #0x2, r5
    dt r12
    bf      .L_tile_loop
    add r3, r1
    add r3, r1
    dt r4
    bf/s    .L_row_group
    add r6, r5
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
_pool_vram_ptr_table:
    .4byte  sym_06028614
_pool_template_base:
    .4byte  sym_06063690
    .2byte  0x0009

    .global sym_060284AE
sym_060284AE:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15

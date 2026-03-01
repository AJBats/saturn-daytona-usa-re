
    .section .text.FUN_06018834


    .global course1_bg_load
    .type course1_bg_load, @function
course1_bg_load:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_offset_table_a, r11
    mov.l   .L_offset_table_b, r12
    mov.l   .L_bg_data_base, r14
    mov.l   .L_fn_memcpy_long, r13
    mov.w   .L_palette_size, r6
    mov.l   .L_wram_low, r9
    mov.l   .L_palette_src, r4
    jsr @r13
    mov r9, r5
    mov.w   .L_tile_a_size, r6
    mov.w   .L_palette_size, r5
    mov.l   .L_tile_a_src, r4
    jsr @r13
    add r9, r5
    mov.l   .L_bg_base_size, r6
    mov.l   .L_bg_base_offset, r5
    add r9, r5
    jsr @r13
    mov r14, r4
    mov.l   .L_map_size, r6
    mov.l   .L_vram_dest_base, r9
    mov.l   .L_map_src, r4
    jsr @r13
    mov r9, r5
    mov.w   .L_tile_bd_size, r6
    mov.l   .L_tile_b_offset, r5
    mov.l   .L_tile_b_src, r4
    jsr @r13
    add r9, r5
    mov.w   .L_tile_c_size, r6
    mov.l   .L_tile_c_offset, r5
    mov.l   .L_tile_c_src, r4
    jsr @r13
    add r9, r5
    mov.w   .L_tile_bd_size, r6
    mov.l   .L_data_d_offset, r5
    mov.l   .L_data_d_src, r4
    jsr @r13
    add r9, r5
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
.L_patch_loop:
    mov r4, r2
    mov r4, r3
    add #0x2, r5
    add r11, r2
    add r12, r3
    add #0x4, r4
    mov.l @r2, r1
    mov r4, r6
    add r14, r1
    mov r4, r2
    mov.l r1, @r3
    add r11, r2
    mov r4, r3
    mov.l @r2, r1
    add r12, r3
    add r14, r1
    mov.l r1, @r3
    cmp/ge r10, r5
    bf/s    .L_patch_loop
    add #0x4, r4
    mov.l   .L_race_end_state, r4
    mov.l   .L_fn_sound_init, r3
    jsr @r3
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_projection_mgr, r3
    jmp @r3
    mov.l @r15+, r14
.L_palette_size:
    .2byte  0x0CC8                         /* palette data: 3272 bytes */
.L_tile_a_size:
    .2byte  0x7A00                         /* tile set A: 31232 bytes */
.L_tile_bd_size:
    .2byte  0x3000                         /* tile set B/D: 12288 bytes */
.L_tile_c_size:
    .2byte  0x4000                         /* tile set C: 16384 bytes */
    .2byte  0xFFFF                         /* alignment padding */
.L_offset_table_a:
    .4byte  sym_0605D1FC                   /* BG offset source table (course 1) */
.L_offset_table_b:
    .4byte  sym_06085FD0                   /* BG offset dest table */
.L_bg_data_base:
    .4byte  sym_060D6900                   /* BG data base address */
.L_fn_memcpy_long:
    .4byte  memcpy_long_idx                /* long-indexed memory copy */
.L_wram_low:
    .4byte  0x00200000                     /* Work RAM Low base */
.L_palette_src:
    .4byte  sym_060D5840                   /* palette source data */
.L_tile_a_src:
    .4byte  sym_060C6000                   /* tile set A source */
.L_bg_base_size:
    .4byte  0x0000BD00                     /* base BG data: 48384 bytes */
.L_bg_base_offset:
    .4byte  0x000086C8                     /* WRAM offset for base BG */
.L_map_size:
    .4byte  0x00019000                     /* map data: 100KB */
.L_vram_dest_base:
    .4byte  0x00240000                     /* VDP2 VRAM destination base */
.L_map_src:
    .4byte  sym_060A6000                   /* map data source */
.L_tile_b_offset:
    .4byte  0x0001C0B8                     /* VRAM offset for tile set B */
.L_tile_b_src:
    .4byte  sym_060BF000                   /* tile set B source */
.L_tile_c_offset:
    .4byte  0x000180B8                     /* VRAM offset for tile set C */
.L_tile_c_src:
    .4byte  sym_060C2000                   /* tile set C source */
.L_data_d_offset:
    .4byte  0x0001DFE8                     /* VRAM offset for data block D */
.L_data_d_src:
    .4byte  0x002F8000                     /* data block D source address */
.L_race_end_state:
    .4byte  sym_0607EAD8                   /* pointer to race end state variable */
.L_fn_sound_init:
    .4byte  sound_init_sequence            /* sound initialization for course */
.L_fn_projection_mgr:
    .4byte  projection_mgr                 /* projection manager (tail call) */

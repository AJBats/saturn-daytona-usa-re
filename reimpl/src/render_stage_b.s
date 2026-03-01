
    .section .text.FUN_06023584


    .global render_stage_b
    .type render_stage_b, @function
render_stage_b:
    sts.l pr, @-r15
    mov #0x0, r8
    mov.w   .L_frame_alloc_neg, r0
    add r0, r15
    mov.l   .L_proj_param_source, r10
    mov r15, r1
    mov.l   .L_channel_table_src, r2
    mov.w   .L_memcpy_byte_count, r0
    mov.l   .L_fn_memcpy_long, r3
    jsr @r3
    add #0x8, r1
    mov.l   .L_sprite_index_table, r4
    mov #0x3, r0
    mov.w r0, @(4, r4)
    mov #0x4, r0
    mov.w r0, @(6, r4)
    mov #0x5, r0
    mov.w r0, @(8, r4)
    mov #0x6, r0
    mov.w r0, @(10, r4)
    mov #0x7, r0
    mov.w r0, @(12, r4)
    mov #0x8, r0
    mov.w r0, @(14, r4)
    mov #0x9, r0
    mov.w r0, @(16, r4)
    mov #0xA, r0
    mov.w r0, @(18, r4)
    mov #0xB, r0
    mov.w r0, @(20, r4)
    mov #0xC, r0
    mov.w r0, @(22, r4)
    mov #0xD, r0
    mov.w r0, @(24, r4)
    mov #0xE, r0
    mov.w r0, @(26, r4)
    mov #0xF, r0
    mov.w r0, @(28, r4)
    mov #0x10, r0
    mov.w r0, @(30, r4)
    mov r4, r3
    add #0x20, r3
    mov #0x11, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x22, r3
    mov #0x12, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x24, r3
    mov #0x13, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x26, r3
    mov #0x14, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x28, r3
    mov #0x15, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x2A, r3
    mov #0x16, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x2C, r3
    mov #0x17, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x2E, r3
    mov #0x18, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x30, r3
    mov #0x19, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x32, r3
    mov #0x1A, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x34, r3
    mov #0x1B, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x36, r3
    mov #0x1C, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x38, r3
    mov.w r9, @r3
    mov #0x1E, r5
    mov r4, r3
    add #0x3A, r3
    extu.w r5, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x3C, r3
    mov #0x1F, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x3E, r3
    mov #0x20, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x40, r3
    mov #0x21, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x42, r3
    mov #0x22, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x44, r3
    mov #0x23, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x46, r3
    mov #0x24, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x48, r3
    mov #0x25, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x4A, r3
    mov #0x26, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x4C, r3
    mov #0x27, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x4E, r3
    mov #0x28, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x50, r3
    mov #0x29, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x52, r3
    mov #0x2A, r2
    mov.w r2, @r3
    mov r4, r3
    add #0x54, r3
    bra     .L_finish_index_table
    nop
.L_frame_alloc_neg:
    .2byte  0xFE6C
.L_memcpy_byte_count:
    .2byte  0x018C
.L_proj_param_source:
    .4byte  sym_0606A4EC
.L_channel_table_src:
    .4byte  sym_06060A48
.L_fn_memcpy_long:
    .4byte  sym_06035168
.L_sprite_index_table:
    .4byte  sym_06089E44
.L_finish_index_table:
    mov #0x36, r2
    add #0x56, r4
    extu.w r5, r12
    mov.w r2, @r3
    mov #0x37, r3
    mov.w r3, @r4
    mov.l   .L_vdp1_vram_base, r2
    mov.l r2, @(4, r15)
    mov r2, r5
    mov.w   .L_vdp1_copy_count, r6
    mov.l   .L_game_state_idx_ptr, r4
    mov.l   .L_scroll_base_table, r3
    mov.w   .L_scroll_data_offset, r2
    mov.l @r4, r4
    mov.l @r3, r3
    shll2 r4
    shll r4
    add r3, r4
    add r2, r4
    mov.l   .L_fn_memcpy_word_idx, r2
    jsr @r2
    nop
    bra     .L_channel_loop_test
    extu.w r8, r14
.L_channel_loop_body:
    mov r14, r4
    mov r14, r3
    mov r15, r2
    shll2 r4
    shll2 r3
    add #0x8, r2
    shll r3
    add r3, r4
    exts.w r4, r4
    add r2, r4
    mov.l @r4, r11
    mov.w @(8, r4), r0
    mov r0, r3
    mov.w r3, @r15
    mov.w @r15, r3
    extu.w r3, r3
    cmp/pl r3
    bf/s    .L_primary_done
    extu.w r8, r13
.L_primary_entry_loop:
    tst r11, r11
    bf      .L_primary_data_valid
    bra     .L_primary_done
    nop
.L_primary_data_valid:
    extu.w r14, r0
    cmp/eq #0x1D, r0
    bf      .L_render_primary_entry
    extu.w r13, r0
    cmp/eq #0x17, r0
    bf      .L_check_idx_3a
    mov.l @r10, r2
    mov.l   .L_proj_param_a, r3
    mov.l r2, @r3
    bra     .L_render_primary_entry
    nop
.L_check_idx_3a:
    extu.w r13, r0
    cmp/eq #0x3A, r0
    bf      .L_check_idx_d0
    mov.l @r10, r2
    mov.l   .L_proj_param_b, r3
    mov.l r2, @r3
    bra     .L_render_primary_entry
    nop
.L_vdp1_copy_count:
    .2byte  0x5780
.L_scroll_data_offset:
    .2byte  0x03C0
.L_vdp1_vram_base:
    .4byte  0x002A8000
.L_game_state_idx_ptr:
    .4byte  sym_06059FFC
.L_scroll_base_table:
    .4byte  sym_06063F5C
.L_fn_memcpy_word_idx:
    .4byte  memcpy_word_idx
.L_proj_param_a:
    .4byte  sym_06089E30
.L_proj_param_b:
    .4byte  sym_06089E2C
.L_check_idx_d0:
    extu.w r13, r2
    mov.w   .L_proj_idx_d0, r3
    cmp/eq r3, r2
    bf      .L_render_primary_entry
    mov.l @r10, r3
    mov.l   .L_proj_config_ptr, r2
    mov.l r3, @r2
.L_render_primary_entry:
    extu.w r12, r5
    mov.l   .L_fn_sprite_render, r3
    mov.l @(4, r15), r6
    jsr @r3
    mov r11, r4
    add #0x1, r13
    mov.w @r15, r3
    extu.w r13, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bf/s    .L_primary_entry_loop
    add #0xC, r11
.L_primary_done:
    mov r14, r4
    mov r14, r3
    mov r15, r2
    shll2 r4
    shll2 r3
    add #0x8, r2
    shll r3
    add r3, r4
    exts.w r4, r4
    add r2, r4
    mov.l @(4, r4), r11
    mov.w @(10, r4), r0
    mov r0, r3
    mov.w r3, @r15
    extu.w r14, r3
    cmp/ge r9, r3
    bf      .L_no_channel_offset
    extu.w r14, r3
    add #-0x1D, r3
    shll r3
    mov.l   .L_channel_offset_table, r2
    add r2, r3
    mov.w @r3, r3
    add r3, r12
.L_no_channel_offset:
    mov.w @r15, r2
    extu.w r2, r2
    cmp/pl r2
    bf/s    .L_secondary_done
    extu.w r8, r13
.L_secondary_entry_loop:
    extu.w r12, r5
    mov.l   .L_fn_secondary_render, r3
    jsr @r3
    mov r11, r4
    add #0x1, r13
    mov.w @r15, r3
    extu.w r13, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bf/s    .L_secondary_entry_loop
    add #0x6, r11
.L_secondary_done:
    extu.w r14, r0
    cmp/eq #0x20, r0
    bf      .L_skip_bank_store
    mov.l   .L_sprite_bank_base, r3
    mov.w r12, @r3
.L_skip_bank_store:
    extu.w r14, r0
    cmp/eq #0x1F, r0
    bf      .L_skip_extra_offset
    add #0x2A, r12
.L_skip_extra_offset:
    extu.w r14, r2
    cmp/ge r9, r2
    bt      .L_no_per_channel_bump
    add #0xA, r12
.L_no_per_channel_bump:
    add #0x1, r14
.L_channel_loop_test:
    extu.w r14, r2
    mov #0x21, r3
    cmp/ge r3, r2
    bt      .L_epilogue
    bra     .L_channel_loop_body
    nop
.L_epilogue:
    mov.w   .L_frame_dealloc, r1
    add r1, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_proj_idx_d0:
    .2byte  0x00D0
.L_frame_dealloc:
    .2byte  0x0194
.L_proj_config_ptr:
    .4byte  sym_06089E28
.L_fn_sprite_render:
    .4byte  vdp1_sprite_render_alt
.L_channel_offset_table:
    .4byte  sym_06060A40
.L_fn_secondary_render:
    .4byte  sym_06007590
.L_sprite_bank_base:
    .4byte  sym_0607886C

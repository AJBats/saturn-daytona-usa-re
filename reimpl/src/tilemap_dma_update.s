
    .section .text.FUN_06036E90


    .global tilemap_dma_update
    .type tilemap_dma_update, @function
tilemap_dma_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r5, r13
    add #-0x4, r15
    extu.w r13, r5
    mov.l r6, @r15
    mov r5, r0
    cmp/eq #0x1, r0
    bt      .L_mode_accepted
    mov.l   .L_screen_height_ptr, r2
    mov.w @r2, r2
    extu.w r2, r2
    cmp/eq r2, r5
    bf      .L_epilog
.L_mode_accepted:
    extu.w r13, r6
    mov.l   .L_scene_transform_ptr, r14
    mov.l   .L_vdp2_offset_mask, r2
    shll r6
    and r2, r4
    mov.l r4, @(60, r14)
    mov.l   .L_vdp2_vram_base, r3
    or r3, r4
    mov.l   .L_word_copy_helper, r3
    jsr @r3
    mov.l @r15, r5
    mov.l @(60, r14), r2
    extu.w r13, r0
    shlr r2
    cmp/eq #0x1, r0
    bt/s    .L_check_ready_flag
    mov.l r2, @(60, r14)
    mov.l   .L_sign_bit, r2
    mov.l @(60, r14), r3
    or r2, r3
    mov.l r3, @(60, r14)
.L_check_ready_flag:
    mov.l   .L_scene_ready_flag_ptr, r4
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_epilog
    mov #0x1, r3
    mov.w r3, @r4
.L_epilog:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_screen_height_ptr:
    .4byte  sym_060635B0                /* &screen_height (16-bit, init=224) */
.L_scene_transform_ptr:
    .4byte  sym_060A3DF8                /* &scene_transform_struct (rotation params, 64 bytes) */
.L_vdp2_offset_mask:
    .4byte  0x0007FFFF                  /* 19-bit VDP2 VRAM offset mask */
.L_vdp2_vram_base:
    .4byte  0x25E00000                  /* VDP2 VRAM +0x00000 */
.L_word_copy_helper:
    .4byte  sym_06038A48                /* word_copy_helper (copies r6 bytes as words) */
.L_sign_bit:
    .4byte  0x80000000                  /* sign bit / multi-word transfer flag */
.L_scene_ready_flag_ptr:
    .4byte  sym_060635AC                /* scene-ready flag (0=idle, 1=pending) */

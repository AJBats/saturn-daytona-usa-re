
    .section .text.FUN_060388C0


    .global scene_data_block_copy
    .type scene_data_block_copy, @function
scene_data_block_copy:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   _pool_scene_ctrl, r13
    mov.w @r13, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_check_scene_b
    mov.l   _pool_scene_a_src_ptr, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_check_scene_b
    mov.l   _pool_scene_a_size, r6
    mov.l   _pool_scene_a_dst, r5
    mov.l   _pool_scene_a_src_ptr, r4
    mov.l @r6, r6
    shll r6
    .byte   0xB0, 0xB1    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r4, r4
    mov #0x0, r2
    mov.w r2, @r13
.L_check_scene_b:
    mov.w @(2, r13), r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_check_channel
    mov.l   _pool_scene_b_src_ptr, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_check_channel
    mov.l   _pool_scene_b_size, r6
    mov.l   _pool_scene_b_dst, r5
    mov.l   _pool_scene_b_src_ptr, r4
    mov.l @r6, r6
    shll r6
    .byte   0xB0, 0xA0    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r4, r4
    mov #0x0, r2
    mov r2, r0
    mov.w r0, @(2, r13)
.L_check_channel:
    mov.l   _pool_screen_mode, r0
    mov.w @r0, r0
    bra     .L_channel_dispatch
    extu.w r0, r0
.L_channel_2:
    mov.w   _wpool_chan2_size, r6
    mov.l   _pool_scene_view_dst, r5
    mov.l   _pool_channel_src, r4
    .byte   0xB0, 0x94    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r4, r4
    bra     .L_fixed_copies
    nop
.L_channel_1:
    mov.w   _wpool_chan1_size, r6
    mov.l   _pool_scene_view_dst, r5
    mov.l   _pool_channel_src, r4
    .byte   0xB0, 0x8D    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r4, r4
    bra     .L_fixed_copies
    nop
_wpool_chan2_size:
    .2byte  0x0100
_wpool_chan1_size:
    .2byte  0x0080
    .2byte  0xFFFF
_pool_scene_ctrl:
    .4byte  sym_060A4C40
_pool_scene_a_src_ptr:
    .4byte  sym_060A4C44
_pool_scene_a_size:
    .4byte  sym_060A4C38
_pool_scene_a_dst:
    .4byte  sym_060A3F68
_pool_scene_b_src_ptr:
    .4byte  sym_060A4C48
_pool_scene_b_size:
    .4byte  sym_060A4C3C
_pool_scene_b_dst:
    .4byte  sym_060A45D0
_pool_screen_mode:
    .4byte  sym_060635B2
_pool_scene_view_dst:
    .4byte  sym_060A3E68
_pool_channel_src:
    .4byte  sym_060A4C5C
.L_channel_dispatch:
    cmp/eq #0x1, r0
    bt      .L_channel_1
    cmp/eq #0x2, r0
    bt      .L_channel_2
.L_fixed_copies:
    .byte   0xDE, 0x22    /* mov.l _pool_staging_ptr, r14 */
    mov #0x28, r6
    .byte   0xD5, 0x22    /* mov.l _pool_pipe_buf_0, r5 */
    .byte   0xB0, 0x6B    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r14, r4
    mov #0x48, r6
    .byte   0xD5, 0x21    /* mov.l _pool_pipe_buf_1, r5 */
    mov.l @r14, r4
    .byte   0xB0, 0x66    /* bsr 0x06038A48 (word-copy helper) */
    add #0x28, r4
    mov #0x40, r6
    .byte   0xD5, 0x20    /* mov.l _pool_pipe_buf_2, r5 */
    mov.l @r14, r4
    .byte   0xB0, 0x61    /* bsr 0x06038A48 (word-copy helper) */
    add #0x70, r4
    mov #0x10, r6
    .byte   0xD5, 0x1E    /* mov.l _pool_pipe_buf_3, r5 */
    mov.l @r14, r4
    .byte   0x92, 0x30    /* mov.w _wpool_offset_0xB0, r2 */
    .byte   0xB0, 0x5B    /* bsr 0x06038A48 (word-copy helper) */
    add r2, r4
    mov #0x20, r6
    .byte   0xD5, 0x1C    /* mov.l _pool_pipe_buf_4, r5 */
    mov.l @r14, r4
    .byte   0x92, 0x2B    /* mov.w _wpool_offset_0xC0, r2 */
    .byte   0xB0, 0x55    /* bsr 0x06038A48 (word-copy helper) */
    add r2, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

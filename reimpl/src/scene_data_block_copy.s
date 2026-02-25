/* scene_data_block_copy -- Scene data publish orchestrator
 * Translation unit: 0x060388C0 - 0x060389A6
 *
 * Per-frame "publish" step that snapshots internal scene state into the
 * rendering pipeline's working buffers. Three stages:
 *
 * Stage 1 (scene A): If copy-pending flag (word) at scene_ctrl is set and
 *   scene A source pointer is non-null, copies scene_a_size*2 bytes from
 *   scene A source to scene A destination buffer, then clears the flag.
 *
 * Stage 2 (scene B): Same pattern for scene B — copies scene_b_size*2 bytes
 *   from scene B source to scene B destination, clears the flag.
 *
 * Channel routing: Reads the screen mode channel value, dispatches on
 *   channel 1 (0x80 bytes) or channel 2 (0x100 bytes) to copy channel
 *   data from the channel source buffer into the scene view struct.
 *
 * Final: 6 fixed-size block copies from a staging pointer into pipeline
 *   working buffers (sizes 0x28, 0x48, 0x40, 0x10, 0x20 bytes at various
 *   offsets). All copies go through the word-copy helper sym_06038A48.
 */

    .section .text.FUN_060388C0


    .global scene_data_block_copy
    .type scene_data_block_copy, @function
scene_data_block_copy:
    mov.l r14, @-r15                        ! save r14
    mov.l r13, @-r15                        ! save r13
    sts.l pr, @-r15                         ! save return address
    mov.l   _pool_scene_ctrl, r13           ! r13 = &scene_ctrl (copy-pending flags)
    mov.w @r13, r0                          ! r0 = scene_ctrl[0] (scene A pending flag)
    extu.w r0, r0                           ! zero-extend to 32 bits
    tst r0, r0                              ! test if scene A copy is pending
    bt      .L_check_scene_b               ! skip if flag is zero
    mov.l   _pool_scene_a_src_ptr, r3       ! r3 = &scene_a_src_ptr
    mov.l @r3, r0                           ! r0 = scene_a_src_ptr value
    tst r0, r0                              ! test if source pointer is null
    bt      .L_check_scene_b               ! skip if null — no data to copy
    mov.l   _pool_scene_a_size, r6          ! r6 = &scene_a_size (word count)
    mov.l   _pool_scene_a_dst, r5           ! r5 = &scene_a_dst (destination buffer)
    mov.l   _pool_scene_a_src_ptr, r4       ! r4 = &scene_a_src_ptr
    mov.l @r6, r6                           ! r6 = scene_a_size value
    shll r6                                 ! r6 *= 2 (convert words to byte count)
    .byte   0xB0, 0xB1    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r4, r4                           ! r4 = scene A source address (delay slot)
    mov #0x0, r2                            ! r2 = 0
    mov.w r2, @r13                          ! clear scene A pending flag
.L_check_scene_b:
    mov.w @(2, r13), r0                     ! r0 = scene_ctrl[1] (scene B pending flag)
    extu.w r0, r0                           ! zero-extend to 32 bits
    tst r0, r0                              ! test if scene B copy is pending
    bt      .L_check_channel                ! skip if flag is zero
    mov.l   _pool_scene_b_src_ptr, r3       ! r3 = &scene_b_src_ptr
    mov.l @r3, r0                           ! r0 = scene_b_src_ptr value
    tst r0, r0                              ! test if source pointer is null
    bt      .L_check_channel                ! skip if null — no data to copy
    mov.l   _pool_scene_b_size, r6          ! r6 = &scene_b_size (word count)
    mov.l   _pool_scene_b_dst, r5           ! r5 = &scene_b_dst (destination buffer)
    mov.l   _pool_scene_b_src_ptr, r4       ! r4 = &scene_b_src_ptr
    mov.l @r6, r6                           ! r6 = scene_b_size value
    shll r6                                 ! r6 *= 2 (convert words to byte count)
    .byte   0xB0, 0xA0    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r4, r4                           ! r4 = scene B source address (delay slot)
    mov #0x0, r2                            ! r2 = 0
    mov r2, r0                              ! r0 = 0
    mov.w r0, @(2, r13)                     ! clear scene B pending flag
.L_check_channel:
    mov.l   _pool_screen_mode, r0           ! r0 = &screen_mode channel selector
    mov.w @r0, r0                           ! r0 = screen_mode value
    bra     .L_channel_dispatch             ! jump to channel dispatch switch
    extu.w r0, r0                           ! zero-extend channel value (delay slot)
.L_channel_2:
    mov.w   _wpool_chan2_size, r6           ! r6 = 0x0100 (256 bytes for channel 2)
    mov.l   _pool_scene_view_dst, r5       ! r5 = &scene_view_dst (scene view struct)
    mov.l   _pool_channel_src, r4          ! r4 = &channel_src pointer
    .byte   0xB0, 0x94    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r4, r4                           ! r4 = channel source address (delay slot)
    bra     .L_fixed_copies                 ! proceed to fixed-size copies
    nop                                     ! delay slot
.L_channel_1:
    mov.w   _wpool_chan1_size, r6           ! r6 = 0x0080 (128 bytes for channel 1)
    mov.l   _pool_scene_view_dst, r5       ! r5 = &scene_view_dst (scene view struct)
    mov.l   _pool_channel_src, r4          ! r4 = &channel_src pointer
    .byte   0xB0, 0x8D    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r4, r4                           ! r4 = channel source address (delay slot)
    bra     .L_fixed_copies                 ! proceed to fixed-size copies
    nop                                     ! delay slot
_wpool_chan2_size:
    .2byte  0x0100                          ! channel 2 copy size: 256 bytes
_wpool_chan1_size:
    .2byte  0x0080                          ! channel 1 copy size: 128 bytes
    .2byte  0xFFFF                          ! padding / alignment
_pool_scene_ctrl:
    .4byte  sym_060A4C40                    ! scene copy-pending flags (2 x word)
_pool_scene_a_src_ptr:
    .4byte  sym_060A4C44                    ! scene A source pointer
_pool_scene_a_size:
    .4byte  sym_060A4C38                    ! scene A copy size (in words)
_pool_scene_a_dst:
    .4byte  sym_060A3F68                    ! scene A destination buffer
_pool_scene_b_src_ptr:
    .4byte  sym_060A4C48                    ! scene B source pointer
_pool_scene_b_size:
    .4byte  sym_060A4C3C                    ! scene B copy size (in words)
_pool_scene_b_dst:
    .4byte  sym_060A45D0                    ! scene B destination buffer
_pool_screen_mode:
    .4byte  sym_060635B2                    ! screen mode / channel selector
_pool_scene_view_dst:
    .4byte  sym_060A3E68                    ! scene view struct (destination)
_pool_channel_src:
    .4byte  sym_060A4C5C                    ! channel data source pointer
.L_channel_dispatch:
    cmp/eq #0x1, r0                         ! is channel == 1?
    bt      .L_channel_1                    ! handle channel 1 (0x80 bytes)
    cmp/eq #0x2, r0                         ! is channel == 2?
    bt      .L_channel_2                    ! handle channel 2 (0x100 bytes)
.L_fixed_copies:
    .byte   0xDE, 0x22    /* mov.l _pool_staging_ptr, r14 */    ! r14 = &staging_ptr (sym_060A3D84)
    mov #0x28, r6                           ! r6 = 0x28 (40 bytes)
    .byte   0xD5, 0x22    /* mov.l _pool_pipe_buf_0, r5 */     ! r5 = &pipe_buf_0 (sym_060A3D88)
    .byte   0xB0, 0x6B    /* bsr 0x06038A48 (word-copy helper) */
    mov.l @r14, r4                          ! r4 = staging_ptr base address (delay slot)
    mov #0x48, r6                           ! r6 = 0x48 (72 bytes)
    .byte   0xD5, 0x21    /* mov.l _pool_pipe_buf_1, r5 */     ! r5 = &pipe_buf_1 (sym_060A3DB0)
    mov.l @r14, r4                          ! r4 = staging_ptr base address
    .byte   0xB0, 0x66    /* bsr 0x06038A48 (word-copy helper) */
    add #0x28, r4                           ! r4 += 0x28 — start at offset 40 (delay slot)
    mov #0x40, r6                           ! r6 = 0x40 (64 bytes)
    .byte   0xD5, 0x20    /* mov.l _pool_pipe_buf_2, r5 */     ! r5 = &pipe_buf_2 (sym_060A3DF8)
    mov.l @r14, r4                          ! r4 = staging_ptr base address
    .byte   0xB0, 0x61    /* bsr 0x06038A48 (word-copy helper) */
    add #0x70, r4                           ! r4 += 0x70 — start at offset 112 (delay slot)
    mov #0x10, r6                           ! r6 = 0x10 (16 bytes)
    .byte   0xD5, 0x1E    /* mov.l _pool_pipe_buf_3, r5 */     ! r5 = &pipe_buf_3 (sym_060A3E38)
    mov.l @r14, r4                          ! r4 = staging_ptr base address
    .byte   0x92, 0x30    /* mov.w _wpool_offset_0xB0, r2 */   ! r2 = 0x00B0 (offset 176)
    .byte   0xB0, 0x5B    /* bsr 0x06038A48 (word-copy helper) */
    add r2, r4                              ! r4 += 0xB0 — start at offset 176 (delay slot)
    mov #0x20, r6                           ! r6 = 0x20 (32 bytes)
    .byte   0xD5, 0x1C    /* mov.l _pool_pipe_buf_4, r5 */     ! r5 = &pipe_buf_4 (sym_060A3E48)
    mov.l @r14, r4                          ! r4 = staging_ptr base address
    .byte   0x92, 0x2B    /* mov.w _wpool_offset_0xC0, r2 */   ! r2 = 0x00C0 (offset 192)
    .byte   0xB0, 0x55    /* bsr 0x06038A48 (word-copy helper) */
    add r2, r4                              ! r4 += 0xC0 — start at offset 192 (delay slot)
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14 (delay slot)

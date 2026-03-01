
    .section .text.FUN_0601AE80


    .global course_data_handler
    .type course_data_handler, @function
course_data_handler:
    sts.l pr, @-r15
    mov #0x0, r4
    mov #0x28, r1
    mov.l   _pool_attract_frame_ctr, r2
    extu.b r4, r3
    extu.b r4, r4
    mov.b r3, @r2
    mov.l   _pool_phase_timer, r2
    mov.b r1, @r2
    mov.l   _pool_phase_index, r2
    mov.b r4, @r2
    mov.l   _pool_pal_course_main, r5
    mov.l   _pool_vdp2_cram_0x6C0, r4
    mov.l   _pool_fn_memcpy_word, r2
    jsr @r2
    mov #0x60, r6
    mov.l   _pool_pal_course_ext, r5
    mov.l   _pool_vdp2_cram_0x180, r4
    mov.l   _pool_fn_memcpy_word, r3
    jsr @r3
    mov #0x20, r6
    mov.w   _wpool_cram_full_size, r6
    mov.l   _pool_pal_full_init, r5
    mov.l   _pool_vdp2_cram_0x000, r4
    mov.l   _pool_fn_dma_transfer, r3
    jmp @r3
    lds.l @r15+, pr

    .global sym_0601AEB6
sym_0601AEB6:
    mov.l   _pool_phase_index, r3
    mov.b @r3, r3
    extu.b r3, r3
    shll2 r3
    mov.l   _pool_phase_jump_table, r2
    add r2, r3
    mov.l @r3, r3
    jmp @r3
    nop
_wpool_cram_full_size:
    .2byte  0x0180                           /* 384 bytes — full CRAM init block size */
    .2byte  0xFFFF                           /* padding */
    .4byte  sym_06078868                     /* (unused pool — sprite/frame index) */
    .4byte  sym_06078663                     /* (unused pool — camera direction flip) */
_pool_attract_frame_ctr:
    .4byte  sym_06086010                     /* attract frame counter (byte) */
_pool_phase_timer:
    .4byte  sym_0608600F                     /* phase countdown timer (byte) */
_pool_phase_index:
    .4byte  sym_06086011                     /* current attract phase index (byte) */
_pool_pal_course_main:
    .4byte  sym_0604866C                     /* course main palette data (48 colors) */
_pool_vdp2_cram_0x6C0:
    .4byte  0x25F006C0                       /* VDP2 color RAM +0x6C0 */
_pool_fn_memcpy_word:
    .4byte  memcpy_word_idx                  /* word-indexed memcpy routine */
_pool_pal_course_ext:
    .4byte  sym_060485CC                     /* course extended palette data */
_pool_vdp2_cram_0x180:
    .4byte  0x25F00180                       /* VDP2 color RAM +0x180 */
_pool_pal_full_init:
    .4byte  sym_0604996C                     /* full CRAM init palette data */
_pool_vdp2_cram_0x000:
    .4byte  0x25F00000                       /* VDP2 color RAM +0x000 */
_pool_fn_dma_transfer:
    .4byte  dma_transfer                     /* SCU DMA transfer routine */
_pool_phase_jump_table:
    .4byte  sym_0605DEC8                     /* attract phase jump table base */

    .global loc_0601AF04
loc_0601AF04:
    .byte   0xD4, 0x19    /* mov.l .L_pool_0601AF6C, r4 */
    mov.b @r4, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0601AF16
    .byte   0xD5, 0x18    /* mov.l .L_pool_0601AF70, r5 */
    mov.b @r5, r3
    add #0x1, r3
    mov.b r3, @r5
.L_0601AF16:
    mov.b @r4, r2
    add #-0x1, r2
    rts
    mov.b r2, @r4

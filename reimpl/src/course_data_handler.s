/* course_data_handler — Attract mode palette init + phase dispatch
 * Translation unit: 0x0601AE80 - 0x0601AF1E
 *
 * Three functions:
 *
 *   course_data_handler — Called during attract mode init (attract_init_body).
 *       Resets three phase-control bytes, then copies course palette data
 *       into VDP2 color RAM: two word-indexed memcpy calls for partial banks,
 *       then a tail-call DMA transfer for the full CRAM init block.
 *
 *   attract_phase_dispatch (sym_0601AEB6) — Called during attract active state
 *       (state_attract_active) when the attract timer > 580.  Reads the current
 *       phase index, indexes into the attract phase jump table (sym_0605DEC8),
 *       and jumps to the handler for the current phase.
 *
 *   attract_phase_tick (loc_0601AF04) — The default phase handler, called from
 *       the jump table for most phases.  Decrements the phase countdown timer;
 *       when it reaches zero, advances to the next phase.  Pool entries for
 *       this function live in the next TU (replay_cam_auto_cut).
 *
 * State bytes:
 *   sym_06086010 — attract frame counter (reset to 0)
 *   sym_0608600F — phase countdown timer (reset to 0x28 = 40 frames)
 *   sym_06086011 — current phase index (reset to 0)
 */

    .section .text.FUN_0601AE80


    .global course_data_handler
    .type course_data_handler, @function
course_data_handler:
    sts.l pr, @-r15                          ! save return address
    mov #0x0, r4                             ! r4 = 0 (clear value)
    mov #0x28, r1                            ! r1 = 0x28 (40 — initial phase timer)
    mov.l   _pool_attract_frame_ctr, r2      ! r2 -> attract frame counter
    extu.b r4, r3                            ! r3 = 0 (zero-extended byte)
    extu.b r4, r4                            ! r4 = 0 (zero-extended byte)
    mov.b r3, @r2                            ! attract frame counter = 0
    mov.l   _pool_phase_timer, r2            ! r2 -> phase countdown timer
    mov.b r1, @r2                            ! phase countdown timer = 0x28
    mov.l   _pool_phase_index, r2            ! r2 -> current phase index
    mov.b r4, @r2                            ! phase index = 0
    mov.l   _pool_pal_course_main, r5        ! r5 = source: course main palette
    mov.l   _pool_vdp2_cram_0x6C0, r4       ! r4 = dest: VDP2 CRAM +0x6C0
    mov.l   _pool_fn_memcpy_word, r2         ! r2 = &memcpy_word_idx
    jsr @r2                                  ! memcpy_word_idx(CRAM_0x6C0, main_pal, 0x60)
    mov #0x60, r6                            ! r6 = 0x60 (96 bytes — 48 colors)
    mov.l   _pool_pal_course_ext, r5         ! r5 = source: course extended palette
    mov.l   _pool_vdp2_cram_0x180, r4       ! r4 = dest: VDP2 CRAM +0x180
    mov.l   _pool_fn_memcpy_word, r3        ! r3 = &memcpy_word_idx
    jsr @r3                                  ! memcpy_word_idx(CRAM_0x180, ext_pal, 0x20)
    mov #0x20, r6                            ! r6 = 0x20 (32 bytes — 16 colors)
    mov.w   _wpool_cram_full_size, r6        ! r6 = 0x0180 (384 bytes — full CRAM init)
    mov.l   _pool_pal_full_init, r5          ! r5 = source: full CRAM init palette
    mov.l   _pool_vdp2_cram_0x000, r4       ! r4 = dest: VDP2 CRAM +0x000 (base)
    mov.l   _pool_fn_dma_transfer, r3       ! r3 = &dma_transfer
    jmp @r3                                  ! tail-call dma_transfer(CRAM_0x000, full_pal, 0x180)
    lds.l @r15+, pr                          ! restore PR in delay slot (for tail-call return)

    .global sym_0601AEB6
sym_0601AEB6:
    mov.l   _pool_phase_index, r3            ! r3 -> current phase index byte
    mov.b @r3, r3                            ! r3 = phase index (signed byte)
    extu.b r3, r3                            ! r3 = phase index (unsigned)
    shll2 r3                                 ! r3 = phase index * 4 (table offset)
    mov.l   _pool_phase_jump_table, r2       ! r2 = base of attract phase jump table
    add r2, r3                               ! r3 = &jump_table[phase_index]
    mov.l @r3, r3                            ! r3 = jump_table[phase_index] (handler addr)
    jmp @r3                                  ! jump to phase handler
    nop                                      ! delay slot (unused)
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
    .byte   0xD4, 0x19    /* mov.l .L_pool_0601AF6C, r4 — r4 -> phase timer (pool in next TU) */
    mov.b @r4, r3                            ! r3 = current phase timer value
    extu.b r3, r3                            ! r3 = timer (unsigned)
    tst r3, r3                               ! test if timer == 0
    bf      .L_timer_nonzero                 ! if timer != 0, skip phase advance
    .byte   0xD5, 0x18    /* mov.l .L_pool_0601AF70, r5 — r5 -> phase index (pool in next TU) */
    mov.b @r5, r3                            ! r3 = current phase index
    add #0x1, r3                             ! r3 = next phase index
    mov.b r3, @r5                            ! advance to next phase
.L_timer_nonzero:
    mov.b @r4, r2                            ! r2 = current phase timer
    add #-0x1, r2                            ! r2 = timer - 1
    rts                                      ! return
    mov.b r2, @r4                            ! store decremented timer (delay slot)

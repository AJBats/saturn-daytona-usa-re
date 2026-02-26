/* file_block_read -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06012400 - 0x06012450
 *
 * Reads file data blocks into position vectors B/C/D/E.
 * On first call, plays an initialization sound effect (0xAE110FFF)
 * via sound_cmd_dispatch and sets the read-initialized flag.
 * Then dispatches four calls to file_format_detect, one per
 * position vector block (indices 0-3). The final call is a
 * tail-call via BRA.
 *
 * Args: none (reads global state)
 */

    .section .text.FUN_06012400


    .global file_block_read
    .type file_block_read, @function
file_block_read:
    sts.l pr, @-r15                         ! save return address
    mov.l   _pool_read_init_flag, r3        ! r3 = &file_read_initialized_flag
    mov.b @r3, r3                           ! r3 = flag value (byte)
    extu.b r3, r3                           ! zero-extend byte to longword
    tst r3, r3                              ! test if flag == 0 (not yet initialized)
    bf      .L_skip_init                    ! if nonzero (already initialized), skip sound
    mov.l   _pool_sfx_file_init, r5         ! r5 = 0xAE110FFF (file-init sound effect ID)
    mov.l   _pool_fn_sound_dispatch, r3     ! r3 = &sound_cmd_dispatch
    jsr @r3                                 ! sound_cmd_dispatch(0, 0xAE110FFF)
    mov #0x0, r4                            ! r4 = 0 (channel arg, in delay slot)
    mov #0x1, r2                            ! r2 = 1 (flag = initialized)
    mov.l   _pool_read_init_flag, r3        ! r3 = &file_read_initialized_flag
    mov.b r2, @r3                           ! file_read_initialized_flag = 1
.L_skip_init:
    mov.l   _pool_position_vec_b, r4        ! r4 = &position_vec_b (block 0 destination)
    .byte   0xB0, 0x18    /* bsr 0x06012450 (external) */  ! file_format_detect(vec_b, 0)
    mov #0x0, r5                            ! r5 = 0 (block index 0, in delay slot)
    mov.l   _pool_position_vec_c, r4        ! r4 = &position_vec_c (block 1 destination)
    .byte   0xB0, 0x15    /* bsr 0x06012450 (external) */  ! file_format_detect(vec_c, 1)
    mov #0x1, r5                            ! r5 = 1 (block index 1, in delay slot)
    mov.l   _pool_position_vec_d, r4        ! r4 = &position_vec_d (block 2 destination)
    .byte   0xB0, 0x12    /* bsr 0x06012450 (external) */  ! file_format_detect(vec_d, 2)
    mov #0x2, r5                            ! r5 = 2 (block index 2, in delay slot)
    mov #0x3, r5                            ! r5 = 3 (block index 3)
    mov.l   _pool_position_vec_e, r4        ! r4 = &position_vec_e (block 3 destination)
    .byte   0xA0, 0x0E    /* bra 0x06012450 (external) */  ! tail-call file_format_detect(vec_e, 3)
    lds.l @r15+, pr                         ! restore return address (delay slot)
_pool_read_init_flag:
    .4byte  sym_060788F0                    /* file read initialized flag (byte) */
_pool_sfx_file_init:
    .4byte  0xAE110FFF                      /* SCSP sound command: file-init SFX */
_pool_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch              /* sound command dispatch function */
_pool_position_vec_b:
    .4byte  sym_060788C0                    /* position vector B (XYZ triplet, 12 bytes) */
_pool_position_vec_c:
    .4byte  sym_060788CC                    /* position vector C (XYZ triplet, 12 bytes) */
_pool_position_vec_d:
    .4byte  sym_060788D8                    /* position vector D (XYZ triplet, 12 bytes) */
_pool_position_vec_e:
    .4byte  sym_060788E4                    /* position vector E (XYZ triplet, 12 bytes) */

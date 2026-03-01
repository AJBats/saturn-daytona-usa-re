
    .section .text.FUN_06012400


    .global file_block_read
    .type file_block_read, @function
file_block_read:
    sts.l pr, @-r15
    mov.l   _pool_read_init_flag, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0601241A
    mov.l   _pool_sfx_file_init, r5
    mov.l   _pool_fn_sound_dispatch, r3
    jsr @r3
    mov #0x0, r4
    mov #0x1, r2
    mov.l   _pool_read_init_flag, r3
    mov.b r2, @r3
.L_0601241A:
    mov.l   _pool_position_vec_b, r4
    .byte   0xB0, 0x18    /* bsr 0x06012450 (external) */
    mov #0x0, r5
    mov.l   _pool_position_vec_c, r4
    .byte   0xB0, 0x15    /* bsr 0x06012450 (external) */
    mov #0x1, r5
    mov.l   _pool_position_vec_d, r4
    .byte   0xB0, 0x12    /* bsr 0x06012450 (external) */
    mov #0x2, r5
    mov #0x3, r5
    mov.l   _pool_position_vec_e, r4
    .byte   0xA0, 0x0E    /* bra 0x06012450 (external) */
    lds.l @r15+, pr
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


    .section .text.FUN_06014A04


    .global FUN_06014A04
    .type FUN_06014A04, @function
FUN_06014A04:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x11    /* mov.l .L_vdp1_vram_base, r3 */
    mov.l r3, @r15
    .byte   0xD5, 0x11    /* mov.l .L_cmd_source_table, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_ptr_game_state_index, r4 */
    .byte   0x92, 0x1D    /* mov.w .L_vdp1_cmd_offset_0x260, r2 */
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r3, r4
    add r2, r4
    .byte   0xD2, 0x0F    /* mov.l .L_fn_memcpy_word_idx, r2 */
    jsr @r2
    mov #0x20, r6
    .byte   0xD3, 0x0F    /* mov.l .L_fn_vdp2_loop_ctrl, r3 */
    jsr @r3
    nop
    .byte   0xD5, 0x0E    /* mov.l .L_ptr_race_state_flags, r5 */
    mov #0x1, r4
    mov #0x0, r3
    mov.l @r5, r2
    or r4, r2
    mov.l r2, @r5
    .byte   0xD2, 0x0C    /* mov.l .L_pool_06014A6C, r2 */
    mov.w r3, @r2
    .byte   0xD3, 0x0C    /* mov.l .L_pool_06014A70, r3 */
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.w r4, @r3


    .global FUN_06014A42
    .type FUN_06014A42, @function
FUN_06014A42:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06014F34 - 4
    .2byte 0xB000    /* bsr FUN_06014F34 (linker-resolved) */
    nop
    .byte   0xD3, 0x09    /* mov.l .L_pool_06014A71, r3 */
    jmp @r3
    lds.l @r15+, pr
    .2byte  0x0260
    .4byte  0x25C00000
    .4byte  sym_06044B64
    .4byte  sym_06059FFC
    .4byte  FUN_0602761E
    .4byte  FUN_060172BC
    .4byte  sym_0607EBF4
    .4byte  sym_06085F90
    .4byte  sym_06085F94
.L_pool_06014A71:
    .4byte  FUN_0601712C

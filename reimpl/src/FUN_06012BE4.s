
    .section .text.FUN_06012BE4


    .global FUN_06012BE4
    .type FUN_06012BE4, @function
FUN_06012BE4:
    sts.l pr, @-r15
    .byte   0xDC, 0x20    /* mov.l .L_fn_ptr_cdb_read_status, r12 */
    mov.w   DAT_06012c66, r14
    .byte   0xD7, 0x20    /* mov.l .L_str_set_daytona_disc, r7 */
    .byte   0xD6, 0x20    /* mov.l .L_pool_06012C70, r6 */
    .byte   0xD3, 0x21    /* mov.l .L_fn_ptr_geom_render_dispatch, r3 */
    mov r14, r5
    jsr @r3
    mov #0x8, r4
    mov #0x24, r6
    .byte   0xD5, 0x1F    /* mov.l .L_vram_cfg_src, r5 */
    .byte   0xD4, 0x20    /* mov.l .L_vram_cfg_dst_ptr, r4 */
    .byte   0xD3, 0x20    /* mov.l .L_fn_ptr_memcpy_word_idx, r3 */
    add r14, r5
    mov.l @r4, r4
    jsr @r3
    add r14, r4
    .byte   0xD3, 0x1F    /* mov.l .L_fn_ptr_ai_brake_zone_calc, r3 */
    jsr @r3
    nop
.L_06012C0C:
    jsr @r12
    nop
    and r13, r0
    cmp/eq #0x1, r0
    bf      .L_06012C0C
    .byte   0xD7, 0x1C    /* mov.l .L_str_spaces_clear, r7 */
    mov r14, r5
    .byte   0xD3, 0x16    /* mov.l .L_fn_ptr_geom_render_dispatch, r3 */
    .byte   0xD6, 0x14    /* mov.l .L_pool_06012C78, r6 */
    jsr @r3
    mov #0x8, r4
    mov #0x24, r6
    .byte   0xD5, 0x14    /* mov.l .L_vram_cfg_src, r5 */
    .byte   0xD4, 0x15    /* mov.l .L_vram_cfg_dst_ptr, r4 */
    .byte   0xD3, 0x15    /* mov.l .L_fn_ptr_memcpy_word_idx, r3 */
    add r14, r5
    mov.l @r4, r4
    jsr @r3
    add r14, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_06012B58 - 4
    .2byte 0xA000    /* bra FUN_06012B58 (linker-resolved) */
    mov.l @r15+, r14


    .global FUN_06012C3C
    .type FUN_06012C3C, @function
FUN_06012C3C:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_pool_06012C8C, r8
    mov.l   .L_pool_06012C90, r10
    mov.l   .L_pool_06012C94, r11
    mov #0x5, r13
    mov.l   .L_pool_06012C98, r14
    mov.l r4, @r15
    mov.l r5, @(4, r15)
    mov #-0x1, r4
    mov r4, r12
    mov.l r4, @(8, r15)
    bra     .L_06012CA0
    mov #0x0, r9

    .global DAT_06012c66
DAT_06012c66:
    sts macl, r10
    .4byte  FUN_06018EAC
    .4byte  sym_060448D4
    .4byte  0x0000E000
    .4byte  sym_060283E0
    .4byte  sym_060612C4
    .4byte  sym_060612B4
    .4byte  FUN_0602761E
    .4byte  FUN_06034C48
    .4byte  sym_0605ACCA
.L_pool_06012C8C:
    .4byte  FUN_0603B1B6
.L_pool_06012C90:
    .4byte  sym_06084AEC
.L_pool_06012C94:
    .4byte  FUN_0603AE08
.L_pool_06012C98:
    .4byte  sym_0600026C
.L_06012C9C:
    .reloc ., R_SH_IND12W, FUN_06012BDC - 4
    .2byte 0xB000    /* bsr FUN_06012BDC (linker-resolved) */
    nop
.L_06012CA0:
    mov.b @r10, r0
    tst r0, r0
    bf      .L_06012C9C
.L_06012CA6:
    jsr @r11
    mov.l @r15, r4
    add #0x1, r9
    cmp/ge r13, r9
    bf/s    .L_06012CB8
    mov r0, r12
    mov.l @r14, r2
    jsr @r2
    nop
.L_06012CB8:
    cmp/pz r12
    bf      .L_06012CA6
    mov #0x0, r2
    mov.l r2, @r15
.L_06012CC0:
    mov #-0x1, r7
    mov #0x0, r5
    mov.l @(4, r15), r6
    jsr @r8
    mov r12, r4
    mov r0, r9
    mov.l @r15, r3
    add #0x1, r3
    cmp/ge r13, r3
    bf/s    .L_06012CDC
    mov.l r3, @r15
    mov.l @r14, r3
    jsr @r3
    nop
.L_06012CDC:
    cmp/pz r9
    bf      .L_06012CC0
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

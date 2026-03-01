
    .section .text.FUN_0603F582


    .global vblank_dma_chain
    .type vblank_dma_chain, @function
vblank_dma_chain:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14
    mov.l r12, @-r15
    mov r5, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov #0x0, r10
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x54, r15
    mov.l @r14, r0
    tst r0, r0
    bf/s    .L_has_commands
    mov r10, r8
    bra     .L_epilogue
    mov.b r10, @r13
.L_has_commands:
    .byte   0xBF, 0xC5    /* bsr 0x0603F534 (external) */
    mov r14, r4
    mov.b r0, @r13
    mov.b @r13, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_count_nonzero
    bra     .L_epilogue
    nop
    .4byte  0x0800FFFF
    .4byte  cmd_multi_validate
.L_count_nonzero:
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBF, 0x16    /* bsr 0x0603F3F6 (external) */
    add #0x4C, r5
    .byte   0xBF, 0x99    /* bsr 0x0603F500 (external) */
    mov r14, r4
    mov.w   DAT_0603f682, r2
    add r2, r0
    mov.l r0, @(4, r13)
    .byte   0xBF, 0x94    /* bsr 0x0603F500 (external) */
    mov r14, r4
    mov.l r0, @(8, r13)
    bra     .L_skip_init_test
    mov r10, r12
.L_skip_field_loop:
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBF, 0x07    /* bsr 0x0603F3F6 (external) */
    add #0x48, r5
    add #0x1, r12
.L_skip_init_test:
    mov #0x7, r2
    cmp/ge r2, r12
    bf      .L_skip_field_loop
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0xFE    /* bsr 0x0603F3F6 (external) */
    add #0x28, r5
    mov #0x28, r0
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    mov.b @(r0, r15), r2
    mov #0x2C, r0
    mov.b r2, @(r0, r15)
    .byte   0xBE, 0xF5    /* bsr 0x0603F3F6 (external) */
    add #0x24, r5
    mov #0x24, r0
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    mov.b @(r0, r15), r0
    mov.b r0, @(14, r13)
    .byte   0xBE, 0xED    /* bsr 0x0603F3F6 (external) */
    add #0x20, r5
    mov #0x20, r0
    mov.b @(r0, r15), r0
    mov.b r0, @(15, r13)
    .byte   0xBF, 0x5D    /* bsr 0x0603F4E0 (external) */
    mov r14, r4
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0xE3    /* bsr 0x0603F3F6 (external) */
    add #0x1C, r5
    mov #0x1C, r0
    mov.b @(r0, r15), r9
    extu.b r9, r2
    add #0x21, r2
    mov.l r2, @(4, r15)
    mov r13, r11
    add #0x10, r11
    bra     .L_fname_read_test
    mov r10, r12
.L_fname_read_char:
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0xD5    /* bsr 0x0603F3F6 (external) */
    add #0x18, r5
    mov #0x18, r0
    mov.b @(r0, r15), r2
    mov.b r2, @r15
    mov.b @r15, r0
    extu.b r0, r0
    cmp/eq #0x3B, r0
    bf/s    .L_not_version_sep
    add #0x1, r12
    bra     .L_fname_done
    nop
.L_not_version_sep:
    mov r11, r2
    mov.b @r15, r3
    mov.b r3, @r2
    mov.b @r15, r0
    extu.b r0, r0
    cmp/eq #0x2E, r0
    bf/s    .L_fname_read_test
    add #0x1, r11
    mov #0x50, r0
    bra     .L_fname_done
    mov.l r11, @(r0, r15)
.L_fname_read_test:
    mov #0x8, r4
    extu.b r9, r5
    cmp/gt r4, r5
    bf      .L_use_total_len
    bra     .L_use_max_8
    mov r4, r2

    .global DAT_0603f682
DAT_0603f682:
    .2byte  0x0096
.L_use_total_len:
    mov r5, r2
.L_use_max_8:
    cmp/ge r2, r12
    bf      .L_fname_read_char
.L_fname_done:
    mov.b @r15, r0
    extu.b r0, r0
    cmp/eq #0x3B, r0
    bf      .L_not_semicolon
    bra     .L_skip_version_loop_test
    nop
.L_skip_version_char:
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0xAB    /* bsr 0x0603F3F6 (external) */
    add #0x44, r5
    add #0x1, r12
.L_skip_version_loop_test:
    extu.b r9, r2
    cmp/ge r2, r12
    bf      .L_skip_version_char
    bra     .L_post_ext_parsing
    nop
.L_not_semicolon:
    mov.b @r15, r0
    extu.b r0, r0
    cmp/eq #0x2E, r0
    bt      .L_ext_chars_done
    bra     .L_ext_read_test
    nop
.L_ext_read_char:
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0x9A    /* bsr 0x0603F3F6 (external) */
    add #0x14, r5
    mov #0x14, r0
    mov.b @(r0, r15), r2
    mov.b r2, @r15
    mov.b @r15, r0
    extu.b r0, r0
    cmp/eq #0x2E, r0
    bf/s    .L_ext_not_dot
    add #0x1, r12
    mov r11, r2
    add #0x1, r11
    mov.b @r15, r3
    mov.b r3, @r2
    mov #0x50, r0
    bra     .L_ext_chars_done
    mov.l r11, @(r0, r15)
.L_ext_not_dot:
    mov #0x1, r8
.L_ext_read_test:
    extu.b r9, r2
    cmp/ge r2, r12
    bf      .L_ext_read_char
.L_ext_chars_done:
    bra     .L_post_ext_parsing
    nop
.L_read_remaining_char:
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0x80    /* bsr 0x0603F3F6 (external) */
    add #0x10, r5
    mov #0x10, r0
    mov.b @(r0, r15), r2
    mov.b r2, @r15
    mov.b @r15, r0
    extu.b r0, r0
    cmp/eq #0x3B, r0
    bf/s    .L_remaining_not_semi
    add #0x1, r12
    bra     .L_skip_remaining_test
    nop
.L_skip_remaining_char:
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0x71    /* bsr 0x0603F3F6 (external) */
    add #0x40, r5
    add #0x1, r12
.L_skip_remaining_test:
    extu.b r9, r2
    cmp/ge r2, r12
    bf      .L_skip_remaining_char
    bra     .L_fname_null_terminate
    nop
.L_remaining_not_semi:
    mov #0x50, r0
    mov r11, r3
    mov #0x3, r1
    mov.l @(r0, r15), r2
    sub r2, r3
    cmp/gt r1, r3
    bf      .L_ext_len_ok
    bra     .L_post_ext_parsing
    mov #0x1, r8
.L_ext_len_ok:
    mov r13, r2
    mov r11, r3
    add #0x10, r2
    sub r2, r3
    mov #0xC, r2
    cmp/ge r2, r3
    bt      .L_post_ext_parsing
    mov r11, r2
    add #0x1, r11
    mov.b @r15, r3
    mov.b r3, @r2
.L_post_ext_parsing:
    extu.b r9, r3
    cmp/ge r3, r12
    bf      .L_read_remaining_char
.L_fname_null_terminate:
    mov r13, r3
    mov r11, r2
    add #0x10, r3
    sub r3, r2
    mov #0xC, r3
    cmp/ge r3, r2
    bt      .L_skip_null
    extu.b r10, r3
    mov.b r3, @r11
.L_skip_null:
    extu.b r9, r0
    add #0x1, r0
    tst #0x1, r0
    bt      .L_no_pad_byte
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0x42    /* bsr 0x0603F3F6 (external) */
    add #0x3C, r5
    mov.l @(4, r15), r2
    add #0x1, r2
    mov.l r2, @(4, r15)
.L_no_pad_byte:
    mov r13, r3
    add #0x10, r3
    mov.b @r3, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_fname_nonempty
    mov r13, r0
    .byte   0xD3, 0x20    /* mov.l _pool_strcpy, r3 */
    .byte   0xD1, 0x1E    /* mov.l _pool_str_dot, r1 */
    jsr @r3
    add #0x10, r0
    bra     .L_post_fname_fixup
    nop
.L_fname_nonempty:
    mov r13, r0
    add #0x10, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_post_fname_fixup
    .byte   0xD1, 0x1B    /* mov.l _pool_str_dotdot, r1 */
    mov r13, r0
    .byte   0xD2, 0x19    /* mov.l _pool_strcpy, r2 */
    jsr @r2
    add #0x10, r0
.L_post_fname_fixup:
    mov.b @r13, r3
    mov.l @(4, r15), r2
    extu.b r3, r3
    cmp/ge r3, r2
    bt      .L_all_fields_consumed
    mov r14, r4
    mov #0x4, r6
    mov r15, r5
    .byte   0xBE, 0x1D    /* bsr 0x0603F3F6 (external) */
    add #0x38, r5
    mov r14, r4
    mov #0x2, r6
    mov r15, r5
    .byte   0xBE, 0x18    /* bsr 0x0603F3F6 (external) */
    add #0xC, r5
    mov.w @(12, r15), r0
    mov r14, r4
    mov #0x2, r6
    mov r15, r5
    mov.w r0, @(12, r13)
    .byte   0xBE, 0x11    /* bsr 0x0603F3F6 (external) */
    add #0x34, r5
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0x0C    /* bsr 0x0603F3F6 (external) */
    add #0x8, r5
    mov.b @(8, r15), r0
    mov r0, r4
    mov #0x1D, r0
    mov.b r4, @(r0, r13)
    mov.l @(4, r15), r12
    bra     .L_tail_skip_test
    add #0x9, r12
.L_tail_skip_char:
    mov r14, r4
    mov #0x1, r6
    mov r15, r5
    .byte   0xBE, 0x00    /* bsr 0x0603F3F6 (external) */
    add #0x30, r5
    add #0x1, r12
.L_tail_skip_test:
    mov.b @r13, r2
    extu.b r2, r2
    cmp/ge r2, r12
    bf      .L_tail_skip_char
    bra     .L_check_fixup_flag
    nop
_pool_str_dot:
    .4byte  sym_06059CB8
_pool_strcpy:
    .4byte  sym_06035FEC
_pool_str_dotdot:
    .4byte  sym_06059CBC
.L_all_fields_consumed:
    mov #0x2C, r0
    mov.b @(r0, r15), r0
    extu.b r0, r0
    tst #0x2, r0
    bt      .L_no_half_flag
    .byte   0xD2, 0x26    /* mov.l .L_fp_half, r2 */
    bra     .L_store_xfer_len
    nop
.L_no_half_flag:
    mov #0x0, r2
.L_store_xfer_len:
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(12, r13)
    extu.b r10, r3
    mov #0x1D, r0
    mov.b r3, @(r0, r13)
.L_check_fixup_flag:
    tst r8, r8
    bt      .L_epilogue
    mov.w @(12, r13), r0
    or #0x80, r0
    mov.w r0, @(12, r13)
.L_epilogue:
    add #0x54, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .4byte  0x5351E01D
    .4byte  0x24325252
    .4byte  0x1421005C
    .4byte  0x804A8556
    .4byte  0xD3156603
    .4byte  0x666D2369
    .4byte  0x23388901
    .4byte  0xA001E310
    .4byte  0xE300921D
    .4byte  0x22692228
    .4byte  0x8901A001
    .4byte  0xE108E100
    .4byte  0x92172269
    .4byte  0x22288D02
    .4byte  0x331CA001
    .4byte  0xE104E100
    .4byte  0x92102269
    .4byte  0x22288D02
    .4byte  0x331CA001
    .4byte  0xE102E100
    .4byte  0x331C603C
    .4byte  0x804B845E
    .4byte  0x8048845F
    .4byte  0x000B8049
    .2byte  0x0800

    .global DAT_0603f8ae
DAT_0603f8ae:
    .2byte  0x1000
    .4byte  0x2000FFFF
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */

    .global sym_0603F8B8
sym_0603F8B8:
    mov.l r5, @r4
    mov.l r6, @(4, r4)
    mov.l r7, @(8, r4)
    mov.l @r15, r3
    mov.l r3, @(12, r4)
    mov.l @(4, r15), r3
    mov.l r3, @(16, r4)
    mov.l @(8, r15), r3
    mov.l r3, @(20, r4)
    rts
    mov r4, r0
    .2byte  0x7FFC
    .4byte  0x2F426043
    .4byte  0x50016442
    .4byte  0x402B7F04
    .4byte  0x7FFC2F42
    .4byte  0x60435001
    .4byte  0xE600D505
    .4byte  0x6442402B
    .2byte  0x7F04

    .global sym_0603F8EE
sym_0603F8EE:
    add #-0x4, r15
    mov.l r4, @r15
    mov r4, r0
    mov.l @(8, r0), r0
    mov.l @r4, r4
    jmp @r0
    add #0x4, r15
    .4byte  0x0000FFFF

    .global sym_0603F900
sym_0603F900:
    add #-0x4, r15
    mov.l r4, @r15
    mov r4, r0
    mov.l @(12, r0), r0
    mov.l @r4, r4
    jmp @r0
    add #0x4, r15

    .global sym_0603F90E
sym_0603F90E:
    add #-0x4, r15
    mov.l r4, @r15
    mov r4, r0
    mov.l @(16, r0), r0
    mov.l @r4, r4
    jmp @r0
    add #0x4, r15

    .global sym_0603F91C
sym_0603F91C:
    add #-0x4, r15
    mov.l r4, @r15
    mov r4, r3
    mov.l @(20, r3), r3
    mov.l @r4, r4
    jmp @r3
    add #0x4, r15
    .2byte  0x0000
    .4byte  0x14586362
    .4byte  0x14395261
    .4byte  0x142A5362
    .4byte  0x000B143B

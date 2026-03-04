
    .section .text.FUN_0603BAC6


    .global save_block_copy
    .type save_block_copy, @function
save_block_copy:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov #0x0, r14
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l r4, @r15
    .byte   0xD3, 0x0B    /* mov.l .L_pool_0603BB09, r3 */
    jsr @r3
    mov r14, r12
    tst r0, r0
    bf      .L_0603BB0C
    bra     .L_0603BB76
    mov #0x0, r0

    .global DAT_0603bae6
DAT_0603bae6:
    mov.b r13, @(r0, r0)
    .4byte  sym_0603EF34
    .4byte  sym_0603F070
    .4byte  sym_0603F036
    .4byte  sym_0603EFE6
    .4byte  sym_0603EFD4
    .4byte  attract_init_setup
    .4byte  sym_0603F8B8
    .4byte  attract_replay_loader
.L_pool_0603BB09:
    .4byte  evt_condition_test
.L_0603BB0C:
    mov r15, r3
    add #0x4, r3
    mov r3, r8
    .byte   0xD3, 0x29    /* mov.l .L_pool_0603BBB8, r3 */
    jsr @r3
    nop
    .byte   0x92, 0x4A    /* mov.w .L_wpool_0603BBB0, r2 */
    mov r15, r3
    add r2, r0
    add #0x4, r3
    mov.l r0, @r8
    mov r15, r2
    .byte   0x9B, 0x45    /* mov.w .L_wpool_0603BBB2, r11 */
    add #0x4, r2
    mov.l r11, @(4, r3)
    extu.b r14, r3
    mov r3, r0
    mov r15, r3
    mov.b r0, @(10, r2)
    add #0x4, r3
    extu.b r14, r0
    mov.b r0, @(11, r3)
    mov r15, r3
    extu.b r14, r0
    add #0x4, r3
    mov.b r0, @(8, r3)
    mov r15, r3
    extu.b r14, r0
    add #0x4, r3
    mov.b r0, @(9, r3)
    .reloc ., R_SH_IND12W, FUN_0603B81E - 4
    .2byte 0xB000    /* bsr FUN_0603B81E (linker-resolved) */
    nop
    mov r0, r13
    mov #0x0, r6
    mov r15, r5
    add #0x4, r5
    .reloc ., R_SH_IND12W, save_field_write - 4
    .2byte 0xB000    /* bsr save_field_write (linker-resolved) */
    mov r0, r4
    mov r0, r14
    tst r14, r14
    bt      .L_0603BB6E
    mov r11, r7
    mov #0x1, r5
    mov.l @r15, r6
    .reloc ., R_SH_IND12W, cmd_multi_validate - 4
    .2byte 0xB000    /* bsr cmd_multi_validate (linker-resolved) */
    mov r14, r4
    cmp/eq r11, r0
    bf      .L_0603BB6E
    mov #0x1, r12
.L_0603BB6E:
    mov r14, r5
    .reloc ., R_SH_IND12W, save_commit_write - 4
    .2byte 0xB000    /* bsr save_commit_write (linker-resolved) */
    mov r13, r4
    mov r12, r0
.L_0603BB76:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .section .text.FUN_0603AC1C


    .global cmd_validate_exec
    .type cmd_validate_exec, @function
cmd_validate_exec:
    mov.l r14, @-r15
    mov #0x1, r3
    mov.l r13, @-r15
    sts.l pr, @-r15
    cmp/ge r3, r4
    bf/s    .L_0603AC30
    mov r6, r14
    mov #0x18, r3
    cmp/gt r3, r4
    bf      .L_0603AC34
.L_0603AC30:
    bra     .L_0603ACE2
    mov #-0x5, r0
.L_0603AC34:
    mov #0x3, r3
    and r5, r3
    tst r3, r3
    bt      .L_0603AC40
    bra     .L_0603ACE2
    mov #-0x15, r0
.L_0603AC40:
    tst r14, r14
    bt      .L_0603AC62
    mov.l @r14, r6
    tst r6, r6
    bt      .L_0603AC50
    mov r6, r0
    cmp/eq #0x1, r0
    bf      .L_0603AC5E
.L_0603AC50:
    mov.l @(4, r14), r2
    mov #0x2, r3
    cmp/ge r3, r2
    bf      .L_0603AC5E
    mov.l @(8, r14), r0
    tst r0, r0
    bf      .L_0603AC62
.L_0603AC5E:
    bra     .L_0603ACE2
    mov #-0x4, r0
.L_0603AC62:
    mov.l   .L_pool_0603ACA0, r3
    mov.l r5, @r3
    .reloc ., R_SH_IND12W, sys_boot_table_init - 4
    .2byte 0xB000    /* bsr sys_boot_table_init (linker-resolved) */
    nop
    tst r14, r14
    bf      .L_0603AC72
    bra     .L_0603AC74
    mov #0x1, r4
.L_0603AC72:
    mov #0x0, r4
.L_0603AC74:
    mov.l   .L_pool_0603ACA4, r3
    jsr @r3
    nop
    mov r0, r4
    tst r4, r4
    bt      .L_0603AC88
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603AC88:
    mov.l   .L_pool_0603ACA0, r0
    mov.w   DAT_0603ac9e, r1
    mov.l @r0, r0
    mov.l @(r0, r1), r0
    tst #0x1, r0
    bf      .L_0603ACA8
    mov #-0x2, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14

    .global DAT_0603ac9e
DAT_0603ac9e:
    .2byte  0x00C4
.L_pool_0603ACA0:
    .4byte  sym_060A4D14
.L_pool_0603ACA4:
    .4byte  error_code_stub
.L_0603ACA8:
    tst r14, r14
    bf      .L_0603ACC2
    .byte   0xD3, 0x20    /* mov.l .L_pool_0603AD30, r3 */
    jsr @r3
    nop
    mov r0, r13
    cmp/pz r13
    bt      .L_0603ACD8
    mov #-0x7, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603ACC2:
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0603AD34, r3 */
    jsr @r3
    mov r14, r4
    mov r0, r13
    cmp/pl r13
    bt      .L_0603ACD8
    mov #-0x1, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603ACD8:
    .reloc ., R_SH_IND12W, cmd_dispatch_helper - 4
    .2byte 0xB000    /* bsr cmd_dispatch_helper (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
    mov r13, r0
.L_0603ACE2:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

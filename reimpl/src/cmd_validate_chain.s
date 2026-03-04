
    .section .text.FUN_0603B1B6


    .global cmd_validate_chain
    .type cmd_validate_chain, @function
cmd_validate_chain:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l r5, @r15
    mov.l r6, @(4, r15)
    .reloc ., R_SH_IND12W, cmd_queue_process - 4
    .2byte 0xB000    /* bsr cmd_queue_process (linker-resolved) */
    mov r7, r13
    mov r0, r14
    tst r14, r14
    bf      .L_0603B1DC
    mov #-0x9, r4
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603B1DC:
    mov #0x0, r6
    mov.l @r15, r5
    .reloc ., R_SH_IND12W, cmd_error_return - 4
    .2byte 0xB000    /* bsr cmd_error_return (linker-resolved) */
    mov r14, r4
    mov.l @r14, r5
    mov r13, r0
    mov.l @r15, r3
    mov.l @(16, r5), r5
    cmp/eq #-0x1, r0
    bf/s    .L_0603B1F8
    sub r3, r5
    .byte   0x9D, 0x3D    /* mov.w .L_wpool_0603B270, r13 */
    mul.l r13, r5
    sts macl, r13
.L_0603B1F8:
    mov r13, r7
    mov.l @(4, r15), r6
    .reloc ., R_SH_IND12W, cmd_multi_validate - 4
    .2byte 0xB000    /* bsr cmd_multi_validate (linker-resolved) */
    mov r14, r4
    mov r0, r13
    .reloc ., R_SH_IND12W, cmd_result_store - 4
    .2byte 0xB000    /* bsr cmd_result_store (linker-resolved) */
    mov r14, r4
    cmp/pz r13
    bf      .L_0603B20E
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
.L_0603B20E:
    mov r13, r0
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

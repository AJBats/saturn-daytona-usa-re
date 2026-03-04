
    .section .text.FUN_0603AF94


    .global cmd_result_store
    .type cmd_result_store, @function
cmd_result_store:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603B878 - 4
    .2byte 0xB000    /* bsr FUN_0603B878 (linker-resolved) */
    mov r4, r14
    mov r0, r13
    tst r13, r13
    bf      .L_0603AFB2
    mov #-0xB, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603AFB2:
    mov r14, r12
    .reloc ., R_SH_IND12W, sys_dma_channel_init - 4
    .2byte 0xB000    /* bsr sys_dma_channel_init (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_0603B8F4 - 4
    .2byte 0xB000    /* bsr FUN_0603B8F4 (linker-resolved) */
    mov r12, r4
    mov r12, r5
    .byte   0xD3, 0x1D    /* mov.l .L_pool_0603B034, r3 */
    jsr @r3
    mov r13, r4
    mov #0x0, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14


    .section .text.FUN_0603AE08


    .global cmd_status_check
    .type cmd_status_check, @function
cmd_status_check:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_pool_0603AE6C, r14
    mov.w   .L_0603AE60, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_0603AE26
    mov.l @r14, r0
    mov.w   .L_0603AE62, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bt      .L_0603AE30
.L_0603AE26:
    mov #-0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603AE30:
    mov.l @r14, r6
    mov.w   .L_0603AE64, r0
    mov.l @r15, r5
    mov.l @r14, r4
    mov.l   .L_pool_0603AE70, r3
    mov.l @(r0, r6), r6
    mov.w   .L_0603AE60, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r14
    cmp/pz r14
    bt      .L_0603AE52
    mov #-0x9, r4
    add #0x4, r15
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603AE52:
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
    mov r14, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0603AE60:
    .2byte  0x00A0
.L_0603AE62:
    .2byte  0x0098
.L_0603AE64:
    .2byte  0x009C
    .2byte  0xFFFF
    .4byte  sym_06035168
.L_pool_0603AE6C:
    .4byte  sym_060A4D14                    /* [HIGH] global command state struct pointer */
.L_pool_0603AE70:
    .4byte  slave_sh2_setup

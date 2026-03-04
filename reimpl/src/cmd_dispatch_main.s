
    .section .text.FUN_0603B424


    .global cmd_dispatch_main
    .type cmd_dispatch_main, @function
cmd_dispatch_main:
    mov.l r14, @-r15
    mov #0x12, r0
    mov.l r13, @-r15
    mov r4, r14
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.b @(r0, r14), r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0603B43C
    bra     .L_0603B526
    nop
.L_0603B43C:
    .reloc ., R_SH_IND12W, save_deserialize - 4
    .2byte 0xB000    /* bsr save_deserialize (linker-resolved) */
    mov r14, r4
    bra     .L_0603B4D0
    mov r0, r13
.L_0603B444:
    mov.w   DAT_0603b4c6, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x1, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603B456:
    mov.w   DAT_0603b4c8, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x17, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603B468:
    mov.w   DAT_0603b4ca, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x2, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603B47A:
    mov.w   DAT_0603b4cc, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x14, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603B48C:
    .reloc ., R_SH_IND12W, FUN_0603BF5A - 4
    .2byte 0xB000    /* bsr FUN_0603BF5A (linker-resolved) */
    mov r14, r4
    cmp/eq #0x1, r0
    bf      .L_0603B4E8
    mov.w   DAT_0603b4ce, r3
    mov #0x12, r0
    mov.b r3, @(r0, r14)
    mov #-0x18, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xA000    /* bra save_checksum_calc (linker-resolved) */
    mov.l @r15+, r14
.L_0603B4A6:
    mov #0x11, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_0603B4E8
    mov #0x0, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    .reloc ., R_SH_IND12W, save_field_read - 4
    .2byte 0xB000    /* bsr save_field_read (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
    mov #0x12, r0
    mov.b @(r0, r14), r0
    bra     .L_0603B530
    extu.b r0, r0

    .global DAT_0603b4c6
DAT_0603b4c6:
    .2byte  0x00FF

    .global DAT_0603b4c8
DAT_0603b4c8:
    .2byte  0x00E9

    .global DAT_0603b4ca
DAT_0603b4ca:
    .2byte  0x00FE

    .global DAT_0603b4cc
DAT_0603b4cc:
    .2byte  0x00EC

    .global DAT_0603b4ce
DAT_0603b4ce:
    .2byte  0x00E8
.L_0603B4D0:
    cmp/eq #0x0, r0
    bt      .L_0603B4A6
    cmp/eq #0x1, r0
    bt      .L_0603B48C
    cmp/eq #0x3, r0
    bt      .L_0603B456
    cmp/eq #0x4, r0
    bt      .L_0603B468
    cmp/eq #0x5, r0
    bt      .L_0603B47A
    cmp/eq #0x6, r0
    bt      .L_0603B444
.L_0603B4E8:
    .reloc ., R_SH_IND12W, save_integrity_check - 4
    .2byte 0xB000    /* bsr save_integrity_check (linker-resolved) */
    mov r14, r4
    mov r0, r4
    mov r13, r0
    cmp/eq #0x2, r0
    bf      .L_0603B526
    mov r4, r0
    cmp/eq #0x5, r0
    bf      .L_0603B526
    .byte   0xD3, 0x18    /* mov.l .L_pool_0603B55C, r3 */
    jsr @r3
    mov.l @(8, r14), r4
    mov r0, r8
    .byte   0xD3, 0x17    /* mov.l .L_pool_0603B560, r3 */
    jsr @r3
    mov.l @(8, r14), r4
    mov r8, r5
    mov r14, r4
    sub r0, r5
    .reloc ., R_SH_IND12W, cmd_error_return - 4
    .2byte 0xB000    /* bsr cmd_error_return (linker-resolved) */
    mov #0x1, r6
    mov #0x0, r2
    mov #0x12, r0
    mov r14, r13
    mov.b r2, @(r0, r14)
    .reloc ., R_SH_IND12W, sys_dma_channel_init - 4
    .2byte 0xB000    /* bsr sys_dma_channel_init (linker-resolved) */
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_0603B8F4 - 4
    .2byte 0xB000    /* bsr FUN_0603B8F4 (linker-resolved) */
    mov r13, r4
    .reloc ., R_SH_IND12W, save_field_read - 4
    .2byte 0xB000    /* bsr save_field_read (linker-resolved) */
    mov r13, r4
.L_0603B526:
    .reloc ., R_SH_IND12W, save_checksum_calc - 4
    .2byte 0xB000    /* bsr save_checksum_calc (linker-resolved) */
    mov #0x0, r4
    mov #0x12, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
.L_0603B530:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xE060

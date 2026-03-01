
    .section .text.FUN_06012C3C


    .global cd_dma_setup
    .type cd_dma_setup, @function
cd_dma_setup:
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
    .4byte  cdb_read_status
    .4byte  sym_060448D4
    .4byte  0x0000E000
    .4byte  sym_060283E0
    .4byte  sym_060612C4
    .4byte  sym_060612B4
    .4byte  memcpy_word_idx
    .4byte  ai_brake_zone_calc
    .4byte  sym_0605ACCA
.L_pool_06012C8C:
    .4byte  cmd_validate_chain
.L_pool_06012C90:
    .4byte  sym_06084AEC
.L_pool_06012C94:
    .4byte  cmd_status_check
.L_pool_06012C98:
    .4byte  sym_0600026C
.L_06012C9C:
    .byte   0xBF, 0x9E    /* bsr 0x06012BDC (external) */
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


    .section .text.FUN_0600FD54


    .global FUN_0600FD54
    .type FUN_0600FD54, @function
FUN_0600FD54:
    sts.l pr, @-r15
    mov.l   .L_pool_0600FDD4, r5
    mov.l   .L_pool_0600FDD8, r3
    jsr @r3
    mov #0x0, r4
    mov #0x78, r2
    mov.l   .L_pool_0600FDDC, r3
    mov.w r2, @r3
    mov #0xB, r2
    mov.l   .L_pool_0600FDE0, r3
    mov.b r2, @r3
    .reloc ., R_SH_IND12W, FUN_06010BC4 - 4
    .2byte 0xB000    /* bsr FUN_06010BC4 (linker-resolved) */
    nop
    mov.l   .L_pool_0600FDE4, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600FDE8, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0600FD84
    mov #0x1, r4
    mov.l   .L_pool_0600FDEC, r3
    jmp @r3
    lds.l @r15+, pr
.L_0600FD84:
    lds.l @r15+, pr
    rts
    nop


    .global FUN_0600FD8A
    .type FUN_0600FD8A, @function
FUN_0600FD8A:
    sts.l pr, @-r15
    mov.l   .L_pool_0600FDDC, r4
    mov.w @r4, r3
    add #-0x1, r3
    mov.w r3, @r4
    exts.w r3, r3
    cmp/pz r3
    bt      .L_0600FDB8
    mov #0xC, r3
    mov.l   .L_pool_0600FDE0, r2
    mov r3, r4
    mov.b r3, @r2
    mov.l   .L_pool_0600FDF0, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600FDF0, r3
    jsr @r3
    mov #0x4, r4
    mov #0x14, r2
    mov.l   .L_pool_0600FDF4, r3
    mov.l r2, @r3
    bra     .L_0600FDF8
    nop
.L_0600FDB8:
    .reloc ., R_SH_IND12W, FUN_06010BC4 - 4
    .2byte 0xB000    /* bsr FUN_06010BC4 (linker-resolved) */
    nop
    mov.l   .L_pool_0600FDE4, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600FDE8, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0600FDF8
    mov #0x1, r4
    mov.l   .L_pool_0600FDEC, r3
    jmp @r3
    lds.l @r15+, pr
    .2byte  0xFFFF
.L_pool_0600FDD4:
    .4byte  0xAB1101FF
.L_pool_0600FDD8:
    .4byte  FUN_0601D5F4
.L_pool_0600FDDC:
    .4byte  sym_0607887A
.L_pool_0600FDE0:
    .4byte  sym_0607887F
.L_pool_0600FDE4:
    .4byte  sym_06011EB4
.L_pool_0600FDE8:
    .4byte  sym_06085FF4
.L_pool_0600FDEC:
    .4byte  FUN_060114AC
.L_pool_0600FDF0:
    .4byte  sym_0602853E
.L_pool_0600FDF4:
    .4byte  sym_0607EBCC
.L_0600FDF8:
    lds.l @r15+, pr
    rts
    nop

    .global FUN_0600FDFE
    .type FUN_0600FDFE, @function
FUN_0600FDFE:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0600FE2C, r14
    mov.l @r14, r3
    add #-0x1, r3
    cmp/pz r3
    bt/s    .L_0600FE20
    mov.l r3, @r14
    mov.l   .L_pool_0600FE30, r5
    mov.l   .L_pool_0600FE34, r3
    jsr @r3
    mov #0x0, r4
    mov.w   .L_wpool_0600FE2A, r2
    mov.l r2, @r14
    mov #0xF, r3
    mov.l   .L_pool_0600FE38, r2
    mov.b r3, @r2
.L_0600FE20:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_0600FE2A:
    .2byte  0x00B4
.L_pool_0600FE2C:
    .4byte  sym_0607EBCC
.L_pool_0600FE30:
    .4byte  0xAB110DFF
.L_pool_0600FE34:
    .4byte  FUN_0601D5F4               /* [HIGH] sound command dispatcher function */
.L_pool_0600FE38:
    .4byte  sym_0607887F

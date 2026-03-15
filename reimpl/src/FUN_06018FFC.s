
    .section .text.FUN_06018FFC


    .global FUN_06018FFC
    .type FUN_06018FFC, @function
FUN_06018FFC:
    sts.l pr, @-r15
    mov.l   .L_pool_0601903C, r14
    mov.l   .L_pool_06019040, r2
    mov.l r3, @r2
    mov.l   .L_pool_06019044, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_06019048, r5
    jsr @r14
    mov #0xF, r4
    .reloc ., R_SH_IND12W, FUN_060192E8 - 4
    .2byte 0xB000    /* bsr FUN_060192E8 (linker-resolved) */
    nop
    mov.l   .L_pool_06019040, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06019028
    mov.l   .L_pool_0601904C, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06019050, r3
    mov.w r2, @r3
.L_06019028:
    mov.l   .L_pool_06019054, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_06019044, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_0601903C:
    .4byte  FUN_0601D5F4
.L_pool_06019040:
    .4byte  sym_06086050
.L_pool_06019044:
    .4byte  0xAE0001FF
.L_pool_06019048:
    .4byte  0xAE0005FF
.L_pool_0601904C:
    .4byte  sym_06012EBC
.L_pool_06019050:
    .4byte  0x25A02DBE
.L_pool_06019054:
    .4byte  0xAE0600FF

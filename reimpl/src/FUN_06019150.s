
    .section .text.FUN_06019150


    .global FUN_06019150
    .type FUN_06019150, @function
FUN_06019150:
    sts.l pr, @-r15
    mov.l   .L_pool_060191C4, r14
    mov.l   .L_pool_060191C8, r2
    mov.l r3, @r2
    mov.l   .L_pool_060191CC, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_060191D0, r5
    jsr @r14
    mov #0xF, r4
    .reloc ., R_SH_IND12W, FUN_060192E8 - 4
    .2byte 0xB000    /* bsr FUN_060192E8 (linker-resolved) */
    nop
    mov.l   .L_pool_060191C8, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601917C
    .byte   0xD3, 0x18    /* mov.l .L_pool_060191D4, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_060191D8, r3
    mov.w r2, @r3
.L_0601917C:
    mov.l   .L_pool_060191CC, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_06019188
    .type FUN_06019188, @function
FUN_06019188:
    mov.l r14, @-r15
    mov #0x0, r3

    .global FUN_0601918C
    .type FUN_0601918C, @function
FUN_0601918C:
    sts.l pr, @-r15
    mov.l   .L_pool_060191C4, r14
    mov.l   .L_pool_060191C8, r2
    mov.l r3, @r2
    mov.l   .L_pool_060191CC, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_060191D0, r5
    jsr @r14
    mov #0xF, r4
    .reloc ., R_SH_IND12W, FUN_060192E8 - 4
    .2byte 0xB000    /* bsr FUN_060192E8 (linker-resolved) */
    nop
    mov.l   .L_pool_060191C8, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_060191B8
    mov.l   .L_pool_060191DC, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_060191D8, r3
    mov.w r2, @r3
.L_060191B8:
    mov.l   .L_pool_060191CC, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_060191C4:
    .4byte  FUN_0601D5F4
.L_pool_060191C8:
    .4byte  sym_06086050
.L_pool_060191CC:
    .4byte  0xAE0001FF
.L_pool_060191D0:
    .4byte  0xAE0005FF
    .4byte  sym_06012F58
.L_pool_060191D8:
    .4byte  0x25A02DBE
.L_pool_060191DC:
    .4byte  sym_06012F60

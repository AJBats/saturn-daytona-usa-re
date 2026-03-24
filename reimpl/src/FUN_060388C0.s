
    .section .text.FUN_060388C0


    .global FUN_060388C0
    .type FUN_060388C0, @function
FUN_060388C0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06038938, r13
    mov.w @r13, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_060388EA
    mov.l   .L_pool_0603893C, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_060388EA
    mov.l   .L_pool_06038940, r6
    mov.l   .L_pool_06038944, r5
    mov.l   .L_pool_0603893C, r4
    mov.l @r6, r6
    shll r6
    bsr     FUN_06038A48
    mov.l @r4, r4
    mov #0x0, r2
    mov.w r2, @r13
.L_060388EA:
    mov.w @(2, r13), r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_0603890E
    mov.l   .L_pool_06038948, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603890E
    mov.l   .L_pool_0603894C, r6
    mov.l   .L_pool_06038950, r5
    mov.l   .L_pool_06038948, r4
    mov.l @r6, r6
    shll r6
    bsr     FUN_06038A48
    mov.l @r4, r4
    mov #0x0, r2
    mov r2, r0
    mov.w r0, @(2, r13)
.L_0603890E:
    mov.l   .L_pool_06038954, r0
    mov.w @r0, r0
    bra     .L_06038960
    extu.w r0, r0
.L_06038916:
    mov.w   .L_wpool_06038932, r6
    mov.l   .L_pool_06038958, r5
    mov.l   .L_pool_0603895C, r4
    bsr     FUN_06038A48
    mov.l @r4, r4
    bra     .L_06038968
    nop
.L_06038924:
    mov.w   .L_wpool_06038934, r6
    mov.l   .L_pool_06038958, r5
    mov.l   .L_pool_0603895C, r4
    bsr     FUN_06038A48
    mov.l @r4, r4
    bra     .L_06038968
    nop
.L_wpool_06038932:
    .2byte  0x0100
.L_wpool_06038934:
    .2byte  0x0080
    .2byte  0xFFFF
.L_pool_06038938:
    .4byte  sym_060A4C40
.L_pool_0603893C:
    .4byte  sym_060A4C44
.L_pool_06038940:
    .4byte  sym_060A4C38
.L_pool_06038944:
    .4byte  sym_060A3F68
.L_pool_06038948:
    .4byte  sym_060A4C48
.L_pool_0603894C:
    .4byte  sym_060A4C3C
.L_pool_06038950:
    .4byte  sym_060A45D0
.L_pool_06038954:
    .4byte  sym_060635B2
.L_pool_06038958:
    .4byte  sym_060A3E68
.L_pool_0603895C:
    .4byte  sym_060A4C5C
.L_06038960:
    cmp/eq #0x1, r0
    bt      .L_06038924
    cmp/eq #0x2, r0
    bt      .L_06038916
.L_06038968:
    .byte   0xDE, 0x22    /* mov.l .L_pool_060389F4, r14 */
    mov #0x28, r6
    .byte   0xD5, 0x22    /* mov.l .L_pool_060389F8, r5 */
    bsr     FUN_06038A48
    mov.l @r14, r4
    mov #0x48, r6
    .byte   0xD5, 0x21    /* mov.l .L_pool_060389FC, r5 */
    mov.l @r14, r4
    bsr     FUN_06038A48
    add #0x28, r4
    mov #0x40, r6
    .byte   0xD5, 0x20    /* mov.l .L_pool_06038A00, r5 */
    mov.l @r14, r4
    bsr     FUN_06038A48
    add #0x70, r4
    mov #0x10, r6
    .byte   0xD5, 0x1E    /* mov.l .L_pool_06038A04, r5 */
    mov.l @r14, r4
    .byte   0x92, 0x30    /* mov.w _wpool_offset_0xB0, r2 */
    bsr     FUN_06038A48
    add r2, r4
    mov #0x20, r6
    .byte   0xD5, 0x1C    /* mov.l .L_pool_06038A08, r5 */
    mov.l @r14, r4
    .byte   0x92, 0x2B    /* mov.w _wpool_offset_0xC0, r2 */
    bsr     FUN_06038A48
    add r2, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_060389A6
    .type FUN_060389A6, @function
FUN_060389A6:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x18    /* mov.l .L_pool_06038A0C, r14 */
    mov.w @r14, r0
    bra     .L_06038A28
    extu.w r0, r0
.L_060389B2:
    bsr     FUN_060388C0
    nop
    bra     .L_060389EA
    nop
.L_060389BA:
    .byte   0xD6, 0x15    /* mov.l .L_pool_06038A10, r6 */
    .byte   0xD5, 0x15    /* mov.l .L_pool_06038A14, r5 */
    .byte   0xD4, 0x16    /* mov.l .L_pool_06038A18, r4 */
    mov.w @r6, r6
    mov.l @r5, r5
    extu.w r6, r6
    mov r6, r3
    shll2 r6
    shll2 r3
    shll r3
    add r3, r6
    bsr     sym_06038A48
    mov.l @r4, r4
    .byte   0xD6, 0x11    /* mov.l .L_pool_06038A1C, r6 */
    .byte   0xD5, 0x12    /* mov.l .L_pool_06038A20, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_pool_06038A24, r4 */
    mov.w @r6, r6
    mov.l @r5, r5
    extu.w r6, r6
    shll2 r6
    bsr     sym_06038A48
    mov.l @r4, r4
    bsr     FUN_060388C0
    nop
.L_060389EA:
    mov #0x0, r2
    bra     .L_06038A42
    mov.w r2, @r14
    .4byte  0x00B000C0
    .4byte  sym_060A3D84
    .4byte  sym_060A3D88
    .4byte  sym_060A3DB0
    .4byte  sym_060A3DF8
    .4byte  sym_060A3E38
    .4byte  sym_060A3E48
.L_pool_06038A0C:
    .4byte  sym_060635AC
.L_pool_06038A10:
    .4byte  sym_060635A0
.L_pool_06038A14:
    .4byte  sym_060A3D74
.L_pool_06038A18:
    .4byte  sym_060A3D70
.L_pool_06038A1C:
    .4byte  sym_060635A2
.L_pool_06038A20:
    .4byte  sym_060A3D7C
.L_pool_06038A24:
    .4byte  sym_060A3D78
.L_06038A28:
    cmp/eq #0x1, r0
    bt      .L_060389B2
    cmp/eq #0x2, r0
    bt      .L_060389BA
    cmp/eq #0x3, r0
    bt      .L_06038A42
    cmp/eq #0x4, r0
    bt      .L_06038A42
    cmp/eq #0x5, r0
    bt      .L_06038A42
    cmp/eq #0x6, r0
    bt      .L_06038A42
    cmp/eq #0x7, r0
.L_06038A42:
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_06038AC8 - 4
    .2byte 0xA000    /* bra FUN_06038AC8 (linker-resolved) */
    mov.l @r15+, r14
    .global FUN_06038A48
FUN_06038A48:

    .global sym_06038A48
sym_06038A48:
    shlr r6
    mov #0x0, r7
    mov r7, r3
    cmp/hs r6, r3
    bt      .L_06038A60
.L_06038A52:
    add #0x1, r7
    mov.w @r5, r3
    mov.w r3, @r4
    add #0x2, r4
    cmp/hs r6, r7
    bf/s    .L_06038A52
    add #0x2, r5
.L_06038A60:
    rts
    nop

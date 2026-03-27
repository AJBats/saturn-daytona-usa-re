
    .section .text.FUN_0600F650


    .global FUN_0600F650
    .type FUN_0600F650, @function
FUN_0600F650:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600F6D8, r13
    mov.l   .L_0600F6DC, r3
    jsr @r3
    mov #0x0, r14
    mov.l   .L_0600F6E0, r5
    mov.l   .L_0600F6E4, r3
    jsr @r3
    mov r14, r4
    mov.l   .L_0600F6E8, r3
    jsr @r3
    nop
    mov.l   .L_0600F6EC, r4
    extu.w r14, r0
    mov.w r0, @(6, r4)
    mov.w r0, @(4, r4)
    mov.w r0, @(2, r4)
    mov.w r0, @r4
    mov.w   .L_0600F6D4, r6
    mov.l   .L_0600F6F0, r5
    mov.l   .L_0600F6F4, r4
    mov.l   .L_0600F6F8, r3
    jsr @r3
    nop
    mov.l   .L_0600F6FC, r2
    mov.l r2, @r15
    mov.l   .L_0600F700, r4
    mov.l   .L_0600F704, r3
    jsr @r3
    mov r2, r5
    mov.l   .L_0600F708, r7
    mov r14, r6
    mov.l @r15, r5
    jsr @r13
    mov #0xC, r4
    mov.l   .L_0600F70C, r3
    jsr @r3
    nop
    mov.l   .L_0600F710, r5
    mov.l   .L_0600F6E4, r3
    jsr @r3
    mov r14, r4
    mov.l   .L_0600F714, r3
    jsr @r3
    extu.w r14, r4
    mov.l   .L_0600F718, r3
    jsr @r3
    extu.w r14, r4
    mov.l   .L_0600F71C, r3
    jsr @r3
    nop
    mov.l   .L_0600F720, r2
    mov.w @(6, r2), r0
    mov r0, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_0600F724
    mov #0x24, r10
    bra     .L_0600F728
    mov #0x22, r12
.L_0600F6D4:
    .2byte  0x00C0
    .2byte  0xFFFF
.L_0600F6D8:
    .4byte  sym_06028400
.L_0600F6DC:
    .4byte  FUN_0600A026
.L_0600F6E0:
    .4byte  0xAE0003FF
.L_0600F6E4:
    .4byte  FUN_0601D5F4         /* sound command dispatcher */
.L_0600F6E8:
    .4byte  FUN_06012050
.L_0600F6EC:
    .4byte  sym_06078870
.L_0600F6F0:
    .4byte  sym_060484EC
.L_0600F6F4:
    .4byte  0x25F00460
.L_0600F6F8:
    .4byte  FUN_0602761E
.L_0600F6FC:
    .4byte  sym_06094FA8
.L_0600F700:
    .4byte  0x25E75DDC
.L_0600F704:
    .4byte  FUN_06028654
.L_0600F708:
    .4byte  0x0000E000
.L_0600F70C:
    .4byte  sym_0601143E
.L_0600F710:
    .4byte  0xAB1103FF
.L_0600F714:
    .4byte  sym_06011494
.L_0600F718:
    .4byte  FUN_060114AC
.L_0600F71C:
    .4byte  FUN_06011094
.L_0600F720:
    .4byte  g_pad_state
.L_0600F724:
    mov #0x29, r10
    mov #0x26, r12
.L_0600F728:
    .byte   0xDB, 0x28    /* mov.l .L_tile_table, r11 */
    mov r10, r7
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x26    /* mov.l .L_tile_offset_a, r3 */
    .byte   0x96, 0x43    /* mov.w .L_tile_size_a, r6 */
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x8, r4
    mov r12, r7
    shll2 r7
    shll r7
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x1F    /* mov.l .L_tile_offset_a, r3 */
    .byte   0x96, 0x37    /* mov.w .L_tile_size_b, r6 */
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x8, r4
    .byte   0x97, 0x32    /* mov.w .L_tile_index_c, r7 */
    add r11, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    .byte   0xD3, 0x1B    /* mov.l .L_tile_offset_c, r3 */
    .byte   0x96, 0x2E    /* mov.w .L_tile_size_c, r6 */
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0x8, r4
    .byte   0xD3, 0x18    /* mov.l .L_transition_state, r3 */
    mov.l r14, @r3
    .byte   0x92, 0x27    /* mov.w .L_countdown_value, r2 */
    .byte   0xD3, 0x18    /* mov.l .L_countdown_timer, r3 */
    mov.l r2, @r3
    mov #0x1, r2
    .byte   0xD3, 0x17    /* mov.l .L_transition_active, r3 */
    mov.b r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0600F794
    .type FUN_0600F794, @function
FUN_0600F794:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15

    mov.l   .L_pool_0600F7E4, r3
    mov.l r3, @r15
    mov r3, r14
    add #0x2, r14
    mov.l   .L_pool_0600F7E8, r3
    mov.w @r14, r14
    jsr @r3
    mov #0x0, r4

    mov.l   .L_pool_0600F7EC, r3
    jsr @r3
    nop

    mov.l @r15, r0
    mov.w @(6, r0), r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0600F7F0
    .reloc ., R_SH_IND12W, FUN_06010238 - 4
    .2byte 0xB000    /* bsr FUN_06010238 (linker-resolved) */
    nop
    bra     .L_0600F7F4
    nop

    .2byte  0x0B04
    .4byte  0x0B380170
    .4byte  0x0C2604B0
    .4byte  sym_06063750
    .4byte  0x00009000
    .4byte  0x0000A000
    .4byte  sym_0607EADC
    .4byte  sym_0607EBCC
    .4byte  sym_0607887F
.L_pool_0600F7E4:
    .4byte  g_pad_state
.L_pool_0600F7E8:
    .4byte  FUN_060114AC
.L_pool_0600F7EC:
    .4byte  FUN_06011094

.L_0600F7F0:
    .reloc ., R_SH_IND12W, FUN_060102A8 - 4
    .2byte 0xB000    /* bsr FUN_060102A8 (linker-resolved) */
    mov r14, r4

.L_0600F7F4:
    .reloc ., R_SH_IND12W, FUN_060102EA - 4
    .2byte 0xB000    /* bsr FUN_060102EA (linker-resolved) */
    mov r14, r4

    .byte   0xD0, 0x14    /* mov.l .L_pool_0600F84C, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600F81A
    .byte   0xD4, 0x13    /* mov.l .L_pool_0600F850, r4 */
    .byte   0x92, 0x21    /* mov.w .L_wpool_0600F848, r2 */
    mov.w @r4, r4
    extu.w r4, r4
    and r2, r4
    tst r4, r4
    bt      .L_0600F812
    bra     .L_0600F814
    mov #0x1, r3
.L_0600F812:
    mov #0x0, r3
.L_0600F814:
    exts.b r3, r3
    .byte   0xD2, 0x0F    /* mov.l .L_pool_0600F854, r2 */
    mov.b r3, @r2

.L_0600F81A:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_0600F822
    .type FUN_0600F822, @function
FUN_0600F822:
    sts.l pr, @-r15
    mov.l   .L_pool_0600F85E, r5
    mov.l   .L_pool_0600F862, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_pool_0600F866, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_pool_0600F86A, r3
    jsr @r3
    nop
    mov #0x78, r2
    mov.l   .L_pool_0600F86E, r3
    mov.w r2, @r3
    mov #0x3, r2
    mov.l   .L_pool_0600F872, r3
    lds.l @r15+, pr
    rts
    mov.b r2, @r3
    .4byte  0x0800FFFF
    .4byte  sym_06085FF4
    .4byte  g_pad_state
    .4byte  sym_06078663
.L_pool_0600F85E:
    .4byte  0xAB1101FF
.L_pool_0600F862:
    .4byte  FUN_0601D5F4           /* sound command dispatcher */
.L_pool_0600F866:
    .4byte  FUN_060114AC
.L_pool_0600F86A:
    .4byte  FUN_06011094
.L_pool_0600F86E:
    .4byte  sym_0607887C
.L_pool_0600F872:
    .4byte  sym_0607887F

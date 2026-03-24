
    .section .text.FUN_0601A578


    .global FUN_0601A578
    .type FUN_0601A578, @function
FUN_0601A578:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0601A60C, r3
    mov.l r14, @r3
    mov.l   .L_pool_0601A610, r4
    mov.l   .L_pool_0601A614, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   .L_pool_0601A618, r3
    jsr @r3
    nop
    mov.l   .L_pool_0601A618, r3
    jsr @r3
    nop
    mov #0x9, r7
    mov.l   .L_pool_0601A61C, r5
    mov.l   .L_pool_0601A620, r4
    mov.l   .L_pool_0601A624, r3
    jsr @r3
    mov r14, r6
    mov #0x8, r7
    mov.l   .L_pool_0601A628, r5
    mov.l   .L_pool_0601A62C, r4
    mov.l   .L_pool_0601A624, r3
    jsr @r3
    mov r14, r6
    mov r14, r6
    mov.l   .L_pool_0601A630, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.l   .L_pool_0601A634, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_0601A638, r3
    jsr @r3
    mov #0x4, r4
    mov #0x1, r2
    mov.l   .L_pool_0601A63C, r3
    mov.b r2, @r3
    .reloc ., R_SH_IND12W, FUN_06019928 - 4
    .2byte 0xB000    /* bsr FUN_06019928 (linker-resolved) */
    nop
    bsr     FUN_0601A65E
    nop
    .reloc ., R_SH_IND12W, FUN_0601A80C - 4
    .2byte 0xB000    /* bsr FUN_0601A80C (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601A940 - 4
    .2byte 0xB000    /* bsr FUN_0601A940 (linker-resolved) */
    nop
    mov.l   .L_pool_0601A640, r3
    mov.b r14, @r3
    mov.l   .L_pool_0601A644, r3
    mov.b r14, @r3
    mov.l   .L_pool_0601A648, r3
    mov.b r14, @r3
    mov.l   .L_pool_0601A64C, r3
    jsr @r3
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_pool_0601A650, r3
    jmp @r3
    mov.l @r15+, r14

    .global sym_0601A5F8
sym_0601A5F8:
    mov.l   .L_pool_0601A654, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0601A658
    mov.w   .L_wpool_0601A608, r0
    rts
    nop
.L_wpool_0601A608:
    .2byte  0x00A8
    .2byte  0xFFFF
.L_pool_0601A60C:
    .4byte  sym_06059F44
.L_pool_0601A610:
    .4byte  sym_0605B6D8
.L_pool_0601A614:
    .4byte  0x80000000
.L_pool_0601A618:
    .4byte  sym_06026CE0
.L_pool_0601A61C:
    .4byte  0x00014000
.L_pool_0601A620:
    .4byte  0x25E76174
.L_pool_0601A624:
    .4byte  sym_0600511E
.L_pool_0601A628:
    .4byte  0x00017700
.L_pool_0601A62C:
    .4byte  0x25E761FC
.L_pool_0601A630:
    .4byte  sym_06063AF8
.L_pool_0601A634:
    .4byte  0x0000A000
.L_pool_0601A638:
    .4byte  sym_06028400
.L_pool_0601A63C:
    .4byte  sym_06085FF1
.L_pool_0601A640:
    .4byte  sym_06085FF2
.L_pool_0601A644:
    .4byte  sym_06085FF3
.L_pool_0601A648:
    .4byte  sym_0605D245
.L_pool_0601A64C:
    .4byte  FUN_06019324
.L_pool_0601A650:
    .4byte  FUN_0601938C
.L_pool_0601A654:
    .4byte  sym_06063D9E
.L_0601A658:
    .byte   0x90, 0x40    /* mov.w .L_wpool_0601A6DC, r0 (cross-TU word pool) */
    rts
    nop


    .global FUN_0601A65E
    .type FUN_0601A65E, @function
FUN_0601A65E:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD0, 0x1E    /* mov.l .L_pool_0601A6E4, r0 */
    mov.b @r0, r0
    cmp/eq #0x3, r0
    bf/s    .L_0601A69A
    mov #0x6, r5
    .byte   0xD4, 0x1C    /* mov.l .L_pool_0601A6E8, r4 */
    mov #0x8, r3
    mov.b @r4, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bt/s    .L_0601A686
    mov #0x3, r12
    bra     .L_0601A69E
    extu.b r5, r14
.L_0601A686:
    mov #0x10, r3
    mov.b @r4, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf/s    .L_0601A696
    mov #0x7, r14
    mov #0x0, r3
    mov.b r3, @r4
.L_0601A696:
    bra     .L_0601A69E
    nop
.L_0601A69A:
    extu.b r5, r14
    mov #0x5, r12
.L_0601A69E:
    .byte   0xDB, 0x13    /* mov.l .L_pool_0601A6EC, r11 */
    .byte   0xDD, 0x13    /* mov.l .L_pool_0601A6F0, r13 */
    .byte   0xD2, 0x14    /* mov.l .L_pool_0601A6F4, r2 */
    mov.b @r2, r2
    tst r2, r2
    bf      .L_0601A6F8
    extu.b r14, r7
    mov.w   DAT_0601a6de, r3
    shll8 r7
    add r11, r3
    shll2 r7
    mov.l r3, @r15
    shll2 r7
    mov.l @(4, r3), r3
    mov.w   DAT_0601a6e0, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    extu.b r12, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.w   DAT_0601a6e2, r3
    add r11, r3
    mov.l r3, @r15
    mov.l @(4, r3), r3
    add r3, r7
    bra     .L_0601A726
    nop
    .2byte  0x00A9

    .global DAT_0601a6de
DAT_0601a6de:
    .2byte  0x0418

    .global DAT_0601a6e0
DAT_0601a6e0:
    .2byte  0x0624

    .global DAT_0601a6e2
DAT_0601a6e2:
    .2byte  0x0420
.L_pool_0601A6E4:
    .4byte  sym_06085FF0
.L_pool_0601A6E8:
    .4byte  sym_0605D242
.L_pool_0601A6EC:
    .4byte  sym_06063750
.L_pool_0601A6F0:
    .4byte  sym_06028400
.L_pool_0601A6F4:
    .4byte  sym_0605D241
.L_0601A6F8:
    extu.b r12, r7
    mov.w   DAT_0601a756, r3
    shll8 r7
    add r11, r3
    shll2 r7
    mov.l r3, @r15
    shll2 r7
    mov.l @(4, r3), r3
    mov.w   DAT_0601a758, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    extu.b r14, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.w   DAT_0601a75a, r3
    add r11, r3
    mov.l r3, @r15
    mov.l @(4, r3), r3
    add r3, r7
.L_0601A726:
    mov.w   .L_wpool_0601A75C, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .global FUN_0601A73E
FUN_0601A73E:

    .global sym_0601A73E
sym_0601A73E:
    .byte   0xD3, 0x08    /* mov.l .L_pool_0601A760, r3 */
    mov.b @r3, r3
    tst r3, r3
    bf      .L_0601A74E
    .byte   0xD5, 0x07    /* mov.l .L_pool_0601A764, r5 */
    .byte   0xD3, 0x07    /* mov.l .L_pool_0601A768, r3 */
    jmp @r3
    mov #0xF, r4
.L_0601A74E:
    .byte   0xD5, 0x07    /* mov.l .L_pool_0601A76C, r5 */
    .byte   0xD3, 0x05    /* mov.l .L_pool_0601A768, r3 */
    jmp @r3
    mov #0xF, r4

    .global DAT_0601a756
DAT_0601a756:
    .2byte  0x0418

    .global DAT_0601a758
DAT_0601a758:
    .2byte  0x0624

    .global DAT_0601a75a
DAT_0601a75a:
    .2byte  0x0420
.L_wpool_0601A75C:
    .2byte  0x063C
    .2byte  0xFFFF
.L_pool_0601A760:
    .4byte  sym_0605D241
.L_pool_0601A764:
    .4byte  0xAE0006FF
.L_pool_0601A768:
    .4byte  FUN_0601D5F4
.L_pool_0601A76C:
    .4byte  0xAE0007FF

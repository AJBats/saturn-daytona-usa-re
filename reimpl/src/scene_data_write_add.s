
    .section .text.FUN_06038642


    .global scene_data_write_add
    .type scene_data_write_add, @function
scene_data_write_add:
    mov.l r14, @-r15
    .byte   0xDE, 0x19    /* mov.l .L_pool_060386AF, r14 */
    .byte   0xD7, 0x1A    /* mov.l .L_pool_060386B3, r7 */
    .byte   0xD0, 0x1A    /* mov.l .L_pool_060386B7, r0 */
    bra     .L_0603874C
    mov.l @r0, r0
.L_0603864E:
    mov.l @r7, r2
    add r4, r2
    mov.l r2, @r7
    mov.l @(4, r7), r3
    add r5, r3
    mov.l r3, @(4, r7)
    bra     .L_0603876C
    nop
.L_0603865E:
    mov.l @(16, r7), r2
    add r4, r2
    mov.l r2, @(16, r7)
    mov.l @(20, r7), r3
    add r5, r3
    mov.l r3, @(20, r7)
    bra     .L_0603876C
    nop
.L_0603866E:
    shlr16 r4
    exts.w r4, r4
    mov #0x20, r0
    mov.w @(r0, r7), r2
    add r4, r2
    mov.w r2, @(r0, r7)
    shlr16 r5
    exts.w r5, r5
    mov #0x22, r0
    mov.w @(r0, r7), r3
    add r5, r3
    mov.w r3, @(r0, r7)
    bra     .L_0603876C
    nop
.L_0603868A:
    shlr16 r4
    exts.w r4, r4
    mov #0x24, r0
    mov.w @(r0, r7), r2
    add r4, r2
    mov.w r2, @(r0, r7)
    shlr16 r5
    exts.w r5, r5
    mov #0x26, r0
    mov.w @(r0, r7), r3
    add r5, r3
    mov.w r3, @(r0, r7)
    bra     .L_0603876C
    nop
    .2byte  0xFFFF
    .4byte  scene_color_matrix
.L_pool_060386AF:
    .4byte  sym_060A4C78
.L_pool_060386B3:
    .4byte  sym_060A3DF8
.L_pool_060386B7:
    .4byte  sym_060635A8
.L_060386B8:
    .byte   0xD7, 0x2D    /* mov.l .L_pool_0603877D, r7 */
    mov #0x44, r0
    mov.l @(r0, r7), r2
    add r4, r2
    mov.l r2, @(r0, r7)
    mov #0x48, r0
    mov.l @(r0, r7), r3
    add r5, r3
    mov.l r3, @(r0, r7)
    .byte   0xD3, 0x2A    /* mov.l .L_pool_06038781, r3 */
    mov.l @r3, r0
    tst r0, r0
    bt      .L_060386EC
    .byte   0xD3, 0x29    /* mov.l .L_pool_06038785, r3 */
    mov.l @r3, r0
    tst r0, r0
    bt      .L_060386E2
    .byte   0xD3, 0x28    /* mov.l .L_pool_06038789, r3 */
    mov.l @r3, r0
    tst r0, r0
    bf      .L_060386EC
.L_060386E2:
    mov.l @r14, r3
    add r6, r3
    mov.l r3, @r14
    bra     .L_060386F0
    nop
.L_060386EC:
    mov #0x0, r2
    mov.l r2, @r14
.L_060386F0:
    mov.l @r14, r0
    tst r0, r0
    bt      .L_0603876C
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    .byte   0xD3, 0x20    /* mov.l .L_pool_0603878D, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_06038702:
    mov #0x44, r0
    .byte   0xD7, 0x1F    /* mov.l .L_pool_06038791, r7 */
    mov.l @(r0, r7), r2
    add r4, r2
    mov.l r2, @(r0, r7)
    mov #0x48, r0
    mov.l @(r0, r7), r3
    add r5, r3
    mov.l r3, @(r0, r7)
    .byte   0xD3, 0x1C    /* mov.l .L_pool_06038795, r3 */
    mov.l @r3, r0
    tst r0, r0
    bt      .L_06038736
    .byte   0xD3, 0x1B    /* mov.l .L_pool_06038799, r3 */
    mov.l @r3, r0
    tst r0, r0
    bt      .L_0603872C
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0603879D, r3 */
    mov.l @r3, r0
    tst r0, r0
    bf      .L_06038736
.L_0603872C:
    mov.l @(4, r14), r3
    add r6, r3
    mov.l r3, @(4, r14)
    bra     .L_0603873A
    nop
.L_06038736:
    mov #0x0, r2
    mov.l r2, @(4, r14)
.L_0603873A:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_0603876C
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    .byte   0xD3, 0x0E    /* mov.l .L_pool_0603878D, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_0603874C:
    cmp/eq #0x1, r0
    bt      .L_060386B8
    cmp/eq #0x2, r0
    bt      .L_06038702
    cmp/eq #0x4, r0
    bf      .L_0603875C
    bra     .L_0603864E
    nop
.L_0603875C:
    cmp/eq #0x8, r0
    bf      .L_06038764
    bra     .L_0603865E
    nop
.L_06038764:
    cmp/eq #0x10, r0
    bt      .L_0603866E
    cmp/eq #0x20, r0
    bt      .L_0603868A
.L_0603876C:
    rts
    mov.l @r15+, r14
.L_pool_0603877D:
    .4byte  sym_060A3E68
.L_pool_06038781:
    .4byte  sym_060A4C44
.L_pool_06038785:
    .4byte  sym_060A4C4C
.L_pool_06038789:
    .4byte  sym_060A4C70
.L_pool_0603878D:
    .4byte  scene_color_matrix
.L_pool_06038791:
    .4byte  sym_060A3EE8
.L_pool_06038795:
    .4byte  sym_060A4C48
.L_pool_06038799:
    .4byte  sym_060A4C50
.L_pool_0603879D:
    .4byte  sym_060A4C74

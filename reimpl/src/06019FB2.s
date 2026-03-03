
    .section .text.FUN_06019FB2


    .global course2_physics_init
    .type course2_physics_init, @function
course2_physics_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x6, r11
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15

    .byte   0xD8, 0x08    /* mov.l .L_pool_06019FED, r8 */
    .byte   0xD9, 0x08    /* mov.l .L_pool_06019FF1, r9 */
    .byte   0xDC, 0x09    /* mov.l .L_pool_06019FF5, r12 */
    .byte   0xD0, 0x09    /* mov.l .L_pool_06019FF9, r0 */
    mov.b @r0, r0
    cmp/eq #0x2, r0
    bt/s    .L_0601A050
    mov #0x5, r14

    mov #0x0, r13
.L_06019FD8:
    extu.b r13, r2
    .byte   0xD3, 0x07    /* mov.l .L_pool_06019FFD, r3 */
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_06019FFC
    bra     .L_06019FFE
    extu.b r11, r10
    .2byte  0xFFFF

.L_pool_06019FED:
    .4byte  sym_06049B2C
.L_pool_06019FF1:
    .4byte  sym_06028400
.L_pool_06019FF5:
    .4byte  sym_0605D242
.L_pool_06019FF9:
    .4byte  sym_06085FF0
.L_pool_06019FFD:
    .4byte  sym_0605AD04

.L_06019FFC:
    extu.b r14, r10

.L_06019FFE:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @(8, r15)
    shll2 r7
    mov.w @(r0, r8), r3
    .byte   0xD2, 0x35    /* mov.l .L_pool_0601A0EE, r2 */
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(8, r15), r6
    add r3, r7
    .byte   0xD3, 0x31    /* mov.l .L_pool_0601A0F2, r3 */
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_06019FD8
    bra     .L_0601A0CE
    nop

.L_0601A050:
    mov #0x0, r13
.L_0601A052:
    extu.b r13, r2
    .byte   0xD3, 0x25    /* mov.l .L_pool_0601A0F6, r3 */
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_0601A07E

    mov #0x8, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_0601A06A
    bra     .L_0601A080
    extu.b r11, r10

.L_0601A06A:
    mov #0x10, r3
    mov.b @r12, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf/s    .L_0601A07A
    mov #0x7, r10
    mov #0x0, r3
    mov.b r3, @r12

.L_0601A07A:
    bra     .L_0601A080
    nop

.L_0601A07E:
    mov #0x3, r10

.L_0601A080:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @r15
    shll2 r7
    mov.w @(r0, r8), r3
    .byte   0xD2, 0x14    /* mov.l .L_pool_0601A0EE, r2 */
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(8, r15)
    mov.l @(4, r2), r3
    mov.l @r15, r6
    add r3, r7
    .byte   0xD3, 0x11    /* mov.l .L_pool_0601A0F2, r3 */
    add r3, r6
    mov.l r6, @(4, r15)
    mov.b @(1, r6), r0
    mov.l @(4, r15), r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_0601A052

.L_0601A0CE:
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
    .2byte  0xFFFF

.L_pool_0601A0EE:
    .4byte  sym_06063750
.L_pool_0601A0F2:
    .4byte  sym_06049B22
.L_pool_0601A0F6:
    .4byte  sym_0605AD04

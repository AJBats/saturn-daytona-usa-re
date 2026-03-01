
    .section .text.FUN_060418BE


    .global track_road_validate
    .type track_road_validate, @function
track_road_validate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov #0x3, r8
    mov #0x0, r9
    mov #0x1, r11
    .byte   0xDC, 0x22    /* mov.l .L_06041960, r12 */
    .byte   0xDE, 0x20    /* mov.l .L_0604195C, r14 */
    mov r4, r10
    bra     .L_060419F6
    mov r9, r13
.L_060418E0:
    mov.l @r14, r0
    mov #0x58, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf      .L_0604192E
    mov.l @r14, r5
    mov r13, r3
    add #0x5C, r5
    shll2 r3
    shll2 r3
    add r3, r5
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r4
    .byte   0xD3, 0x19    /* mov.l .L_06041964, r3 */
    mov r0, r5
    jsr @r3
    mov.b @r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0604190E
    bra     .L_06041A04
    nop
.L_0604190E:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r10, r3
    add #0x1, r3
    mov.l r3, @r10
    mov.l @r14, r2
    mov #0x2, r3
    mov #0x58, r0
    mov.l r3, @(r0, r2)
.L_0604192E:
    mov #0x58, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_060419A6
    mov r13, r3
    mov.l @r14, r5
    shll2 r3
    add #0x5C, r5
    shll2 r3
    add r3, r5
    mov.l r5, @r15
    add #0x2, r5
    mov.l @r15, r4
    .byte   0xD3, 0x07    /* mov.l .L_06041968, r3 */
    jsr @r3
    mov.b @r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0604196C
    bra     .L_06041A04
    nop
    .2byte  0xFFFF
.L_0604195C:
    .4byte  sym_060A5400
.L_06041960:
    .4byte  ai_checkpoint_validate
.L_06041964:
    .4byte  track_road_width_main
.L_06041968:
    .4byte  track_bank_calc
.L_0604196C:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov r15, r3
    mov #0x40, r0
    mov.l @r14, r2
    add #0x4, r3
    mov.b @r3, r1
    mov.b r1, @(r0, r2)
    mov.l @r10, r3
    add #0x1, r3
    mov.l r3, @r10
    mov.l @r14, r2
    mov r13, r3
    add #0x5C, r2
    shll2 r3
    shll2 r3
    add r2, r3
    mov.l @(12, r3), r0
    tst r0, r0
    bt      .L_060419A0
    mov.l @r14, r3
    mov #0x58, r0
    mov.l r8, @(r0, r3)
    bra     .L_060419A6
    nop
.L_060419A0:
    mov.l @r14, r2
    mov #0x58, r0
    mov.l r11, @(r0, r2)
.L_060419A6:
    mov #0x58, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    cmp/eq #0x3, r0
    bf      .L_060419F4
    mov r13, r3
    mov.l @r14, r6
    shll2 r3
    add #0x5C, r6
    shll2 r3
    add r3, r6
    mov.l r6, @r15
    mov.l @(12, r6), r6
    mov.l @r15, r5
    mov.l @r15, r4
    .byte   0xD3, 0x27    /* mov.l .L_06041A64, r3 */
    mov.l @(8, r5), r5
    jsr @r3
    mov.b @r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_060419D6
    bra     .L_06041A04
    nop
.L_060419D6:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r10, r3
    add #0x1, r3
    mov.l r3, @r10
    mov.l @r14, r2
    mov #0x58, r0
    mov.l r11, @(r0, r2)
.L_060419F4:
    add #0x1, r13
.L_060419F6:
    mov #0x54, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r2
    cmp/ge r2, r13
    bt      .L_06041A04
    bra     .L_060418E0
    nop
.L_06041A04:
    mov.l @r14, r2
    mov #0x54, r0
    mov.l @(r0, r2), r3
    cmp/ge r3, r13
    bf      .L_06041A16
    mov.l @r14, r2
    mov #0x54, r0
    bra     .L_06041A48
    mov.l r9, @(r0, r2)
.L_06041A16:
    bra     .L_06041A38
    mov r9, r4
.L_06041A1A:
    mov r4, r1
    mov r13, r2
    mov.l @r14, r5
    .byte   0xD3, 0x11    /* mov.l .L_06041A68, r3 */
    shll2 r1
    shll2 r2
    add #0x5C, r5
    shll2 r1
    shll2 r2
    add r5, r1
    add r5, r2
    jsr @r3
    mov #0x10, r0
    add #0x1, r13
    add #0x1, r4
.L_06041A38:
    mov.l @r14, r2
    mov #0x54, r0
    mov.l @(r0, r2), r3
    cmp/ge r3, r13
    bf      .L_06041A1A
    mov.l @r14, r2
    mov #0x54, r0
    mov.l r4, @(r0, r2)
.L_06041A48:
    mov #0x40, r3
    mov.l r3, @r15
    .byte   0xD3, 0x07    /* mov.l .L_06041A6C, r3 */
    jsr @r3
    nop
    mov r0, r5
    mov.l @r15, r3
    exts.w r5, r4
    and r3, r4
    tst r4, r4
    bt      .L_06041A70
    bra     .L_06041A72
    mov #0x1, r4
    .2byte  0xFFFF
.L_06041A64:
    .4byte  track_seg_interpolate
.L_06041A68:
    .4byte  sym_06035168
.L_06041A6C:
    .4byte  sym_06035C4E
.L_06041A70:
    mov #0x0, r4
.L_06041A72:
    tst r4, r4
    bt      .L_06041A86
    mov.l @r14, r3
    mov #0x54, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_06041A86
    mov.l @r14, r3
    mov #0x58, r0
    mov.l r9, @(r0, r3)
.L_06041A86:
    mov #0x54, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .section .text.FUN_06011094


    .global hud_course_render
    .type hud_course_render, @function
hud_course_render:
    mov.l r14, @-r15
    mov #0x3, r4
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_06011134, r5
    mov.l   .L_06011138, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x3, r0
    bf/s    .L_060110C4
    mov r4, r14
    mov.l @r5, r0
    tst #0x1, r0
    bt      .L_060110C0
    bra     .L_060110D4
    mov r14, r12
.L_060110C0:
    bra     .L_060110D4
    mov #0x4, r12
.L_060110C4:
    mov.l @r5, r12
    mov #0x2, r3
    and r4, r12
    cmp/ge r3, r12
    bt      .L_060110D2
    bra     .L_060110D4
    mov r14, r12
.L_060110D2:
    mov #0x4, r12
.L_060110D4:
    mov.l   .L_0601113C, r4
    mov.w   .L_0601112C, r0
    mov.l   .L_06011140, r9
    mov.l @(r0, r4), r11
    add #0x10, r0
    mov.l @(r0, r4), r10
    mov.l @r9, r0
    tst r0, r0
    bt      .L_060110EA
    bra     .L_060110EC
    mov.l r14, @r15
.L_060110EA:
    mov.l r12, @r15
.L_060110EC:
    mov.l   .L_06011144, r13
    mov.l @r15, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.l r7, @(4, r15)
    add r11, r7
    mov.w   .L_0601112E, r6
    mov.l   .L_06011148, r0
    mov.l   .L_0601114C, r3
    mov.l @r0, r0
    shll2 r0
    mov.l r3, @(12, r15)
    mov.l @(r0, r3), r5
    jsr @r13
    mov #0x4, r4
    mov.l   .L_06011150, r8
    mov.l @(4, r15), r7
    mov.w   .L_06011130, r6
    mov.l   .L_06011154, r3
    mov.l @r8, r0
    add r10, r7
    shll2 r0
    mov.l r3, @r15
    mov.l @(r0, r3), r5
    jsr @r13
    mov #0x8, r4
    mov.l @r9, r0
    cmp/eq #0x1, r0
    bt      .L_06011158
    bra     .L_0601115A
    mov.l r14, @(4, r15)

    .global DAT_0601112c
.L_0601112C:
DAT_0601112c:
    .2byte  0x00D4
.L_0601112E:
    .2byte  0x0282
.L_06011130:
    .2byte  0x048C
    .2byte  0xFFFF
.L_06011134:
    .4byte  sym_0607EBC8
.L_06011138:
    .4byte  sym_0607887F
.L_0601113C:
    .4byte  sym_06063750
.L_06011140:
    .4byte  sym_0607EADC
.L_06011144:
    .4byte  sym_06028400
.L_06011148:
    .4byte  sym_06078644
.L_0601114C:
    .4byte  sym_0605AC70
.L_06011150:
    .4byte  sym_0605AD00
.L_06011154:
    .4byte  sym_0605AB98
.L_06011158:
    mov.l r12, @(4, r15)
.L_0601115A:
    mov.l @(4, r15), r7
    add #0x2, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.l r7, @(8, r15)
    add r11, r7
    .byte   0x96, 0x4D    /* mov.w .L_vdp1_cmd_offset_2a, r6 */
    .byte   0xD5, 0x29    /* mov.l .L_pool_06011210, r5 */
    mov.l @(12, r15), r3
    mov.l @r5, r5
    shll2 r5
    add r3, r5
    mov.l @(12, r5), r5
    jsr @r13
    mov #0x4, r4
    mov.l @(8, r15), r7
    .byte   0x96, 0x44    /* mov.w .L_vdp1_cmd_offset_2b, r6 */
    mov.l @r8, r5
    mov.l @r15, r3
    add r10, r7
    shll2 r5
    add r3, r5
    mov.l @(12, r5), r5
    jsr @r13
    mov #0x8, r4
    mov.l @r9, r0
    cmp/eq #0x2, r0
    bt      .L_06011198
    bra     .L_0601119A
    mov.l r14, @(8, r15)
.L_06011198:
    mov.l r12, @(8, r15)
.L_0601119A:
    mov.l @(8, r15), r7
    add #0x4, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.l r7, @(4, r15)
    add r11, r7
    .byte   0x96, 0x2F    /* mov.w .L_vdp1_cmd_offset_3a, r6 */
    .byte   0xD5, 0x19    /* mov.l .L_pool_06011214, r5 */
    mov.l @(12, r15), r3
    mov.l @r5, r5
    shll2 r5
    add r3, r5
    mov.l @(24, r5), r5
    jsr @r13
    mov #0x4, r4
    mov.l @(4, r15), r7
    .byte   0x96, 0x26    /* mov.w .L_vdp1_cmd_offset_3b, r6 */
    mov.l @r8, r5
    mov.l @r15, r3
    add r10, r7
    shll2 r5
    add r3, r5
    mov.l @(24, r5), r5
    jsr @r13
    mov #0x8, r4
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

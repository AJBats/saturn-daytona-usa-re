    .section .text.FUN_06006F3C


    .global FUN_06006F3C
    .type FUN_06006F3C, @function
FUN_06006F3C:
    mov.l r14, @-r15
    mov #0x1, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_06006FDC, r8
    mov.l   .L_06006FE0, r9
    mov.l   .L_06006FE4, r10
    mov.l   .L_06006FE8, r11
    mov.l   .L_06006FEC, r13
    mov.l   .L_06006FF0, r14
    mov.l   .L_06006FF4, r4
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
    mov.l   .L_06006FF8, r3
    mov.l r2, @r3
    mov.l   .L_06006FFC, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt/s    .L_06006F76
    mov #0x0, r12
    bra     .L_060071F0
    nop

.L_06006F76:
    mov.l   .L_06007000, r3
    mov.l r12, @r3
    mov.l   .L_06007004, r4
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_06006F98
    mov.l @r11, r0
    tst r0, r0
    bt      .L_06007058
    jsr @r10
    nop
    mov #0x2, r3
    mov.l   .L_06007000, r2
    mov.l r3, @r2
    bra     .L_06007058
    nop
.L_06006F98:
    mov.l   .L_06007008, r6
    mov.l   .L_0600700C, r5
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x3, r0
    bf      .L_06006FCA
    mov.l @r11, r0
    tst r0, r0
    bt      .L_06007058
    mov.l   .L_06007010, r0
    mov.l   .L_06007014, r3
    mov.w @r0, r0
    extu.w r0, r0
    or #0x8, r0
    mov.w r0, @r3
    mov.w @r5, r0
    extu.w r0, r0
    or #0x3, r0
    jsr @r10
    mov.w r0, @r6
    mov #0x3, r3
    mov.l   .L_06007000, r2
    mov.l r3, @r2
    bra     .L_06007058
    nop
.L_06006FCA:
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_06007018
    jsr @r10
    nop
    bra     .L_06007058
    mov.l r12, @r11
    .2byte  0xFFFF

.L_06006FDC:
    .4byte  display_channel_b
.L_06006FE0:
    .4byte  display_channel_a
.L_06006FE4:
    .4byte  scene_data_dispatch
.L_06006FE8:
    .4byte  sym_060635C4
.L_06006FEC:
    .4byte  sym_060635C0
.L_06006FF0:
    .4byte  sym_0605B6D8
.L_06006FF4:
    .4byte  sym_0607864C
.L_06006FF8:
    .4byte  sym_06059F54
.L_06006FFC:
    .4byte  sym_0605A00C
.L_06007000:
    .4byte  sym_06063F58
.L_06007004:
    .4byte  sym_060635B4
.L_06007008:
    .4byte  0x25D00002
.L_0600700C:
    .4byte  sym_060A4C92
.L_06007010:
    .4byte  sym_060A4C90
.L_06007014:
    .4byte  0x25D00000

.L_06007018:
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    mov.l   .L_060070F0, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0600703C
    mov.l   .L_060070F4, r2
    mov.l @r13, r3
    mov.l @r2, r2
    add #-0x1, r2
    cmp/gt r3, r2
    bt      .L_0600703C
    mov.w @r5, r0
    extu.w r0, r0
    or #0x2, r0
    extu.w r0, r0
    mov.w r0, @r6
.L_0600703C:
    mov.l   .L_060070F4, r3
    mov.l @r13, r2
    mov.l @r3, r3
    cmp/gt r2, r3
    bt      .L_06007058
    mov.l @r11, r0
    tst r0, r0
    bt      .L_06007056
    jsr @r10
    nop
    mov #0x1, r3
    mov.l   .L_060070F8, r2
    mov.l r3, @r2
.L_06007056:
    mov.l r12, @r13

.L_06007058:
    mov.l   .L_060070FC, r3
    mov.l   .L_06007100, r1
    mov.l @r3, r3
    mov.l @r1, r1
    shlr2 r3
    shlr r1
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r3
    shll2 r2
    shll2 r2
    add r2, r3
    add r1, r3
    mov.l   .L_06007104, r2
    add r2, r3
    mov.l   .L_06007108, r2
    mov.l r3, @r2

    mov.l @r14, r1
    mov.l   .L_0600710C, r2
    and r2, r1
    tst r1, r1
    bt      .L_06007094
    mov.w   .L_060070EA, r6
    mov.l   .L_06007108, r5
    mov.l   .L_06007110, r4
    mov.l   .L_06007114, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4

.L_06007094:
    mov.l @r14, r0
    tst #0x4, r0
    bt      .L_060070A8
    mov.w   .L_060070EC, r6
    mov.l   .L_06007118, r5
    mov.l   .L_0600711C, r4
    mov.l   .L_06007114, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4

.L_060070A8:
    mov.l @r14, r0
    tst #0x10, r0
    bt      .L_060070BA
    mov.l   .L_06007120, r6
    mov.l   .L_06007124, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8
    mov #0x4, r4

.L_060070BA:
    mov.l @r14, r0
    tst #0x20, r0
    bt      .L_060070CC
    mov.l   .L_06007128, r6
    mov.l   .L_0600712C, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8
    mov #0x8, r4

.L_060070CC:
    mov.l @r14, r0
    tst #0x40, r0
    bt      .L_060070DE
    mov.l   .L_06007130, r6
    mov.l   .L_06007134, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r8
    mov #0x10, r4

.L_060070DE:
    mov.l @r14, r0
    tst #0x80, r0
    bt      .L_06007146
    mov.l   .L_06007138, r6
    bra     .L_0600713C
    nop

.L_060070EA:
    .2byte  0x0640
.L_060070EC:
    .2byte  0x0E00
    .2byte  0xFFFF

.L_060070F0:
    .4byte  sym_060635B8
.L_060070F4:
    .4byte  sym_060635BC
.L_060070F8:
    .4byte  sym_06063F58
.L_060070FC:
    .4byte  sym_06059F3C
.L_06007100:
    .4byte  sym_06059F38
.L_06007104:
    .4byte  sym_0606B178
.L_06007108:
    .4byte  sym_06059F34
.L_0600710C:
    .4byte  0x20000000
.L_06007110:
    .4byte  sym_06063F60
.L_06007114:
    .4byte  dma_transfer
.L_06007118:
    .4byte  sym_0606129C
.L_0600711C:
    .4byte  sym_060612B4
.L_06007120:
    .4byte  sym_0605B700
.L_06007124:
    .4byte  sym_0605B6FC
.L_06007128:
    .4byte  sym_0605B708
.L_0600712C:
    .4byte  sym_0605B704
.L_06007130:
    .4byte  sym_0605B710
.L_06007134:
    .4byte  sym_0605B70C
.L_06007138:
    .4byte  sym_0605B718

.L_0600713C:
    mov.l @r6, r6
    mov.l   .L_06007208, r5
    mov.l @r5, r5
    jsr @r8
    mov #0x20, r4


.L_06007146:
    mov.l @r14, r3
    mov.l   .L_0600720C, r2
    and r2, r3
    tst r3, r3
    bt      .L_0600715C
    mov.l   .L_06007210, r6
    mov.l   .L_06007214, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9
    mov #0x4, r4

.L_0600715C:
    mov.l @r14, r3
    mov.l   .L_06007218, r2
    and r2, r3
    tst r3, r3
    bt      .L_06007172
    mov.l   .L_0600721C, r6
    mov.l   .L_06007220, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9
    mov #0x8, r4

.L_06007172:
    mov.l @r14, r3
    mov.l   .L_06007224, r2
    and r2, r3
    tst r3, r3
    bt      .L_06007188
    mov.l   .L_06007228, r6
    mov.l   .L_0600722C, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9
    mov #0x10, r4

.L_06007188:
    mov.l @r14, r3
    mov.l   .L_06007230, r2
    and r2, r3
    tst r3, r3
    bt      .L_0600719E
    mov.l   .L_06007234, r6
    mov.l   .L_06007238, r5
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r9
    mov #0x20, r4


.L_0600719E:
    mov.l @r14, r3
    mov.l   .L_0600723C, r2
    and r2, r3
    tst r3, r3
    bt      .L_060071AE
    mov.l   .L_06007240, r3
    jsr @r3
    nop

.L_060071AE:
    mov.l @r14, r2
    mov.l   .L_06007244, r3
    and r3, r2
    tst r2, r2
    bt      .L_060071BE
    mov.l   .L_06007248, r3
    jsr @r3
    nop

.L_060071BE:
    mov.l @r14, r2
    mov.l   .L_0600724C, r3
    and r3, r2
    tst r2, r2
    bt      .L_060071CE
    mov.l   .L_06007250, r3
    jsr @r3
    nop

.L_060071CE:
    mov.l @r14, r2
    mov.l   .L_06007254, r3
    and r3, r2
    tst r2, r2
    bt      .L_060071DE
    mov.l   .L_06007258, r3
    jsr @r3
    nop

.L_060071DE:
    mov.l @r14, r2
    mov.l   .L_0600725C, r3
    and r3, r2
    tst r2, r2
    bt      .L_060071EE
    mov.l   .L_06007260, r3
    jsr @r3
    nop

.L_060071EE:
    mov.l r12, @r14
.L_060071F0:
    mov #0x2, r2
    mov.l   .L_06007264, r3
    mov.l r2, @r3
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_06007208:
    .4byte  sym_0605B714
.L_0600720C:
    .4byte  0x00010000
.L_06007210:
    .4byte  sym_0605B6E0
.L_06007214:
    .4byte  sym_0605B6DC
.L_06007218:
    .4byte  0x00020000
.L_0600721C:
    .4byte  sym_0605B6E8
.L_06007220:
    .4byte  sym_0605B6E4
.L_06007224:
    .4byte  0x00040000
.L_06007228:
    .4byte  sym_0605B6F0
.L_0600722C:
    .4byte  sym_0605B6EC
.L_06007230:
    .4byte  0x00080000
.L_06007234:
    .4byte  sym_0605B6F8
.L_06007238:
    .4byte  sym_0605B6F4
.L_0600723C:
    .4byte  0x80000000
.L_06007240:
    .4byte  sym_060149E0
.L_06007244:
    .4byte  0x40000000
.L_06007248:
    .4byte  sym_060149CC
.L_0600724C:
    .4byte  0x00100000
.L_06007250:
    .4byte  display_channels_load
.L_06007254:
    .4byte  0x04000000
.L_06007258:
    .4byte  obj_collision_update
.L_0600725C:
    .4byte  0x08000000
.L_06007260:
    .4byte  sym_06033354
.L_06007264:
    .4byte  sym_06059F54

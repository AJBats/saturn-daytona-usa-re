
    .section .text.FUN_06024D24


    .global render_finalize_b
    .type render_finalize_b, @function
render_finalize_b:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06024DBC, r10
    mov.w   .L_06024DB8, r11
    mov.l   .L_06024DC0, r13
    mov.l   .L_06024DC4, r14
    mov.b @r13, r3
    extu.b r3, r3
    tst r3, r3
    bf/s    .L_06024E10
    mov #0x0, r12
    mov #0x1, r3
    mov.b r3, @r13
    mov.l   .L_06024DC8, r5
    mov.l   .L_06024DCC, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_06024DD0, r2
    mov.l   .L_06024DD4, r3
    mov.l @r3, r3
    or r2, r3
    mov.l   .L_06024DD4, r2
    mov.l r3, @r2
    mov r2, r1
    mov.l @r1, r1
    or r9, r1
    mov.l r1, @r2
    mov.l   .L_06024DD8, r8
    mov.w   .L_06024DBA, r6
    mov.l   .L_06024DDC, r3
    mov.l r3, @r15
    mov.l   .L_06024DE0, r4
    jsr @r8
    mov r3, r5
    mov #0x20, r6
    mov.l   .L_06024DE4, r3
    mov.l r3, @(4, r15)
    mov.l   .L_06024DE8, r4
    jsr @r8
    mov r3, r5
    mov.w   .L_06024DBA, r6
    mov.l   .L_06024DEC, r4
    jsr @r8
    mov.l @r15, r5
    mov #0x20, r6
    mov.l   .L_06024DF0, r4
    jsr @r8
    mov.l @(4, r15), r5
    mov #0x8, r7
    mov.l   .L_06024DF4, r5
    mov.l   .L_06024DF8, r4
    mov.l   .L_06024DFC, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_06024E00, r3
    jsr @r3
    nop
    mov.w r0, @r10
    mov.l   .L_06024E04, r3
    mov.w r12, @r3
    mov.l   .L_06024E08, r1
    mov.b @r1, r1
    .byte   0xB1, 0x66    /* bsr 0x06025070 (scene_finalize_a */
    mov.l r1, @r14
    .byte   0xB1, 0xD0    /* bsr 0x06025148 (scene_finalize_b */
    nop
    mov.w @r10, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_06024E0C
    .byte   0xB2, 0x38    /* bsr 0x06025224 (scene_process_a */
    mov.l @r14, r4
    bra     .L_06024E10
    nop
.L_06024DB8:
    .2byte  0x00A9
.L_06024DBA:
    .2byte  0x0080
.L_06024DBC:
    .4byte  sym_06089EC4
.L_06024DC0:
    .4byte  sym_06061198
.L_06024DC4:
    .4byte  sym_06089EC8
.L_06024DC8:
    .4byte  0xAE0003FF
.L_06024DCC:
    .4byte  sound_cmd_dispatch
.L_06024DD0:
    .4byte  0x40000000
.L_06024DD4:
    .4byte  sym_0605B6D8
.L_06024DD8:
    .4byte  memcpy_word_idx
.L_06024DDC:
    .4byte  sym_0605CF9C
.L_06024DE0:
    .4byte  0x25F000C0
.L_06024DE4:
    .4byte  sym_0605CD9C
.L_06024DE8:
    .4byte  0x25F00000
.L_06024DEC:
    .4byte  0x25F006C0
.L_06024DF0:
    .4byte  0x25F00600
.L_06024DF4:
    .4byte  0x00017700
.L_06024DF8:
    .4byte  0x25E76EFC
.L_06024DFC:
    .4byte  sym_0600511E
.L_06024E00:
    .4byte  sym_0601A5F8
.L_06024E04:
    .4byte  sym_06089EC6
.L_06024E08:
    .4byte  sym_0605D240
.L_06024E0C:
    .byte   0xB3, 0x34    /* bsr 0x06025478 (scene_process_b */
    mov.l @r14, r4
.L_06024E10:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bt      .L_06024E1C
    bra     .L_06024F1A
    nop
.L_06024E1C:
    mov.l   .L_06024EA8, r4
    mov.l   .L_06024EAC, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_06024EB0, r8
    mov.w @r8, r8
    extu.w r8, r2
    tst r2, r2
    bf      .L_06024E32
    bra     .L_06024F48
    nop
.L_06024E32:
    mov.l r12, @r15
    extu.w r8, r3
    mov.w   .L_06024EA0, r2
    and r2, r3
    mov.l r3, @(4, r15)
.L_06024E3C:
    mov.l @r14, r0
    cmp/eq #0x4, r0
    bf      .L_06024E78
    mov.l @(4, r15), r0
    tst r0, r0
    bt      .L_06024E78
    extu.b r9, r3
    mov #-0x1, r2
    mov.b r3, @r13
    mov.l   .L_06024EB4, r3
    mov.l r2, @r3
    mov.l   .L_06024EB8, r3
    mov.w r12, @r3
    mov.l   .L_06024EBC, r3
    mov.w r12, @r3
    mov.l   .L_06024EAC, r3
    jsr @r3
    extu.w r12, r4
    mov.w @r10, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_06024E70
    .byte   0xB1, 0xDC    /* bsr 0x06025224 (scene_process_a */
    mov.l @r14, r4
    bra     .L_06024F16
    nop
.L_06024E70:
    .byte   0xB3, 0x02    /* bsr 0x06025478 (scene_process_b */
    mov.l @r14, r4
    bra     .L_06024F16
    nop
.L_06024E78:
    extu.w r8, r2
    mov.w   .L_06024EA2, r3
    and r3, r2
    tst r2, r2
    bt      .L_06024E8E
    mov.l @r14, r3
    mov.l   .L_06024EC0, r2
    mov.b r3, @r2
    mov #0x2, r1
    bra     .L_06024F16
    mov.b r1, @r13
.L_06024E8E:
    extu.w r8, r2
    mov.w   .L_06024EA4, r3
    and r3, r2
    tst r2, r2
    bt      .L_06024EC4
    mov #0x2, r3
    mov.b r3, @r13
    bra     .L_06024F16
    nop
.L_06024EA0:
    .2byte  0x0800
.L_06024EA2:
    .2byte  0x0600
.L_06024EA4:
    .2byte  0x0100
    .2byte  0xFFFF
.L_06024EA8:
    .4byte  sym_06089EC6
.L_06024EAC:
    .4byte  mat_multiply_basic
.L_06024EB0:
    .4byte  sym_06063D9A
.L_06024EB4:
    .4byte  sym_06089ECC
.L_06024EB8:
    .4byte  sym_06089ED6
.L_06024EBC:
    .4byte  sym_06089ED4
.L_06024EC0:
    .4byte  sym_0605D240
.L_06024EC4:
    extu.w r8, r2
    mov.l   .L_06024F74, r3
    and r3, r2
    tst r2, r2
    bt      .L_06024EDE
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov r3, r2
    mov #0x5, r3
    cmp/ge r3, r2
    bf      .L_06024EDE
    mov.l r12, @r14
.L_06024EDE:
    extu.w r8, r3
    mov.w   .L_06024F72, r2
    and r2, r3
    tst r3, r3
    bt      .L_06024EF6
    mov.l @r14, r3
    add #-0x1, r3
    mov r3, r2
    mov.l r3, @r14
    cmp/pz r2
    bt      .L_06024EF6
    mov.l r9, @r14
.L_06024EF6:
    mov.w @r10, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_06024F06
    .byte   0xB1, 0x91    /* bsr 0x06025224 (scene_process_a */
    mov.l @r14, r4
    bra     .L_06024F0A
    nop
.L_06024F06:
    .byte   0xB2, 0xB7    /* bsr 0x06025478 (scene_process_b */
    mov.l @r14, r4
.L_06024F0A:
    mov #0x1, r3
    mov.l @r15, r2
    add #0x1, r2
    cmp/ge r3, r2
    bf/s    .L_06024E3C
    mov.l r2, @r15
.L_06024F16:
    bra     .L_06024F48
    nop
.L_06024F1A:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_06024F3A
    mov.w @r10, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_06024F32
    .byte   0xB3, 0xCF    /* bsr 0x060256CC (scene_physics_integrate */
    nop
    bra     .L_06024F48
    nop
.L_06024F32:
    .byte   0xB6, 0x5F    /* bsr 0x06025BF4 (scene_physics_variant */
    nop
    bra     .L_06024F48
    nop
.L_06024F3A:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x5, r0
    bf      .L_06024F48
    mov.l   .L_06024F78, r3
    jsr @r3
    nop
.L_06024F48:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x6, r0
    bf      .L_06024FE2
    mov.l   .L_06024F7C, r2
    mov.w @r2, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_06024F80
    mov.w @r10, r3
    extu.w r3, r3
    cmp/eq r11, r3
    bf      .L_06024F6A
    .byte   0xB0, 0x85    /* bsr 0x06025070 (scene_finalize_a */
    nop
    bra     .L_06024FCA
    nop
.L_06024F6A:
    .byte   0xB0, 0xED    /* bsr 0x06025148 (scene_finalize_b */
    nop
    bra     .L_06024FCA
    nop
.L_06024F72:
    .2byte  0x4000
.L_06024F74:
    .4byte  0x00008000
.L_06024F78:
    .4byte  sprite_anim_update
.L_06024F7C:
    .4byte  sym_06089ED8
.L_06024F80:
    mov.w @r10, r5
    mov.l @r14, r4
    mov.l   .L_06025044, r3
    jsr @r3
    exts.b r4, r4
    mov r12, r5
    mov.l   .L_06025048, r2
    mov.l r2, @r15
    mov r2, r6
    mov.l   .L_0602504C, r7
    mov r2, r4
.L_06024F96:
    mov.w @r10, r3
    extu.w r3, r3
    cmp/eq r11, r3
    bf      .L_06024FB4
    mov r5, r3
    shll2 r3
    shll r3
    mov.l   .L_0602504C, r2
    add r2, r3
    mov.l @r3, r3
    mov.l @(4, r4), r2
    mov.w @r2, r1
    mov.w r1, @r3
    bra     .L_06024FBC
    nop
.L_06024FB4:
    mov.l @(4, r7), r2
    mov.l @(4, r6), r3
    mov.w @r3, r1
    mov.w r1, @r2
.L_06024FBC:
    add #0x1, r5
    add #0xC, r6
    add #0x8, r7
    mov #0xE, r3
    cmp/ge r3, r5
    bf/s    .L_06024F96
    add #0xC, r4
.L_06024FCA:
    mov.w @r10, r3
    extu.w r3, r3
    cmp/eq r11, r3
    bf      .L_06024FDA
    .byte   0xB1, 0x27    /* bsr 0x06025224 (scene_process_a */
    mov.l @r14, r4
    bra     .L_06024FDE
    nop
.L_06024FDA:
    .byte   0xB2, 0x4D    /* bsr 0x06025478 (scene_process_b */
    mov.l @r14, r4
.L_06024FDE:
    mov #0x1, r2
    mov.b r2, @r13
.L_06024FE2:
    mov.b @r13, r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_06025016
    extu.b r12, r2
    mov.b r2, @r13
    mov.l   .L_06025050, r2
    mov.b r12, @r2
    mov.l   .L_06025054, r1
    mov.l   .L_06025054, r2
    mov.l @r1, r1
    or r9, r1
    mov.l r1, @r2
    mov.l   .L_06025058, r2
    jsr @r2
    mov #0x8, r4
    mov.l   .L_06025058, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0602505C, r3
    jsr @r3
    nop
    mov.l   .L_06025060, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
.L_06025016:
    mov.l   .L_06025064, r3
    mov.w @r3, r3
    add #0x1, r3
    mov.l   .L_06025064, r2
    mov.w r3, @r2
    mov.l   .L_06025054, r1
    mov.l @r1, r1
    or r9, r1
    mov.l   .L_06025054, r2
    mov.l r1, @r2
    mov.l   .L_06025068, r2
    mov.l r12, @r2
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_0602506C, r2
    jmp @r2
    mov.l @r15+, r14
.L_06025044:
    .4byte  sprite_pair_render
.L_06025048:
    .4byte  sym_060610BC
.L_0602504C:
    .4byte  sym_06060D7C
.L_06025050:
    .4byte  sym_06061199
.L_06025054:
    .4byte  sym_0605B6D8
.L_06025058:
    .4byte  sym_0602853E
.L_0602505C:
    .4byte  sym_06028560
.L_06025060:
    .4byte  sym_06085FF2
.L_06025064:
    .4byte  sym_06089EC6
.L_06025068:
    .4byte  sym_06059F44
.L_0602506C:
    .4byte  sym_06026CE0

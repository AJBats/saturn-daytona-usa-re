	.text
    .global course_obj_transform
course_obj_transform:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_0600B208, r11
    mov.l @r11, r11
    mov.l   .L_0600B20C, r14
    mov.l @r14, r14
    mov.l   .L_0600B210, r3
    mov.l r14, @r3
    mov.l   .L_0600B214, r0
    bra     .L_0600B230
    mov.l @r0, r0
.L_0600B1BE:
    mov.l   .L_0600B218, r13
    mov.l   .L_0600B21C, r12
    bra     .L_0600B23C
    nop
.L_0600B1C6:
    mov.l   .L_0600B220, r13
    mov.l   .L_0600B224, r12
    bra     .L_0600B23C
    nop
.L_0600B1CE:
    mov.l   .L_0600B228, r13
    mov.l   .L_0600B22C, r12
    bra     .L_0600B23C
    nop
    .short  0xFFFF
    .long  sym_06083258
    .long  sym_060621D8
    .long  sym_0606212C
    .long  sym_06032158
    .long  sym_06062180
    .long  sym_06089E44
    .long  sym_060620D8
    .long  sym_06031DF4
    .long  sym_0607EBC4
    .long  0x20020000
    .long  master_ctrl_dispatch
    .long  sym_0608A52C
.L_0600B208:
    .long  sym_0607EB8C
.L_0600B20C:
    .long  sym_0607E944
.L_0600B210:
    .long  sym_0607E940
.L_0600B214:
    .long  sym_0607EAD8
.L_0600B218:
    .long  sym_06063488
.L_0600B21C:
    .long  sym_06063434
.L_0600B220:
    .long  sym_060634A4
.L_0600B224:
    .long  sym_06063450
.L_0600B228:
    .long  sym_060634C0
.L_0600B22C:
    .long  sym_0606346C
.L_0600B230:
    cmp/eq #0x0, r0
    bt      .L_0600B1BE
    cmp/eq #0x1, r0
    bt      .L_0600B1C6
    cmp/eq #0x2, r0
    bt      .L_0600B1CE
.L_0600B23C:
    mov.l   .L_0600B304, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_0600B308, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l   .L_0600B30C, r3
    jsr @r3
    mov.l @(32, r14), r4
    mov.l   .L_0600B310, r3
    jsr @r3
    mov.l @(36, r14), r4
    mov.l   .L_0600B314, r3
    jsr @r3
    mov.l @(28, r14), r4
    mov.w   .L_0600B2FC, r0
    mov.l   .L_0600B30C, r3
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r2
    jsr @r3
    add r2, r4
    mov.l   .L_0600B318, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600B2E6
    mov.l   .L_0600B31C, r5
    mov.l   .L_0600B320, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(24, r13), r4
    mov.l   .L_0600B324, r6
    mov.l   .L_0600B328, r2
    mov.l @r6, r6
    mov r2, r5
    mov.l r2, @(4, r15)
    mov.w @r5, r5
    mov.l   .L_0600B32C, r3
    jsr @r3
    mov.l @(24, r12), r4
    mov #0x0, r6
    mov.w   .L_0600B2FE, r0
    mov.l   .L_0600B308, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   .L_0600B300, r0
    mov.l   .L_0600B310, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_0600B302, r0
    mov.l   .L_0600B330, r2
    mov.l   .L_0600B314, r3
    mov.l @(r0, r14), r4
    mov.l @r2, r2
    jsr @r3
    add r2, r4
    mov.l @(12, r11), r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0600B334, r3
    mov.l @r15, r4
    mov.l   .L_0600B320, r2
    add r3, r5
    add r13, r4
    mov.l @r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @(12, r11), r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0600B338, r3
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_0600B32C, r2
    add r3, r6
    mov.w @r5, r5
    add r12, r4
    mov.l @r6, r6
    jsr @r2
    mov.l @r4, r4
    .byte   0xB9, 0x97    /* bsr camera_collision_avoid (dual-obj renderer) */
    nop
.L_0600B2E6:
    mov.l   .L_0600B33C, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0600B2FC:
    .short  0x01D8
.L_0600B2FE:
    .short  0x01B4
.L_0600B300:
    .short  0x01D0
.L_0600B302:
    .short  0x01C8
.L_0600B304:
    .long  sym_06026DBC
.L_0600B308:
    .long  sym_06026E2E
.L_0600B30C:
    .long  mat_rot_y
.L_0600B310:
    .long  mat_rot_z
.L_0600B314:
    .long  mat_rot_x
.L_0600B318:
    .long  sym_06059F30
.L_0600B31C:
    .long  sym_06063510
.L_0600B320:
    .long  sym_06031D8C
.L_0600B324:
    .long  sym_060634F4
.L_0600B328:
    .long  sym_06089E98
.L_0600B32C:
    .long  sym_06031A28
.L_0600B330:
    .long  sym_06083258
.L_0600B334:
    .long  sym_060634F8
.L_0600B338:
    .long  sym_060634DC
.L_0600B33C:
    .long  sym_06089EDC

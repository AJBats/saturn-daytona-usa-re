	.text
   .global camera_car_transform
camera_car_transform:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600AE4C, r11
    mov.l   .L_0600AE50, r13
    mov.l   .L_0600AE54, r14
    mov.l   .L_0600AE58, r3
    mov.l @r14, r14
    mov.l r14, @r3
    mov.l   .L_0600AE5C, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_0600AE60, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l @(32, r14), r4
    mov.l   .L_0600AE64, r2
    mov.l   .L_0600AE68, r3
    jsr @r3
    add r2, r4
    mov.l @(36, r14), r4
    mov.l   .L_0600AE6C, r3
    jsr @r3
    neg r4, r4
    mov.l   .L_0600AE70, r2
    mov.l   .L_0600AE74, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0600AE7C
    mov.l @(28, r14), r4
    neg r4, r4
    mov.w @r11, r3
    extu.w r3, r2
    shll2 r2
    mov.l   .L_0600AE78, r3
    add r2, r3
    mov.l @r3, r2
    bra     .L_0600AE94
    add r2, r4
    .long  sym_06027080
    .long  sym_06044670
    .long  sym_060270F2
    .long  mat_rot_xz_b
    .long  sym_060621D8
    .long  sym_06032158
    .long  sym_06062180
    .long  sym_06031DF4
.L_0600AE4C:
    .long  sym_06063F46
.L_0600AE50:
    .long  mat_rot_x
.L_0600AE54:
    .long  sym_0607E944
.L_0600AE58:
    .long  sym_0607E940
.L_0600AE5C:
    .long  sym_06026DBC
.L_0600AE60:
    .long  sym_06026E2E
.L_0600AE64:
    .long  0x00008000
.L_0600AE68:
    .long  mat_rot_y
.L_0600AE6C:
    .long  mat_rot_z
.L_0600AE70:
    .long  sym_0607EBC4
.L_0600AE74:
    .long  0x00800008
.L_0600AE78:
    .long  sym_0605BDCC
.L_0600AE7C:
    mov.l @(28, r14), r4
    neg r4, r4
    mov.l   .L_0600AF1C, r3
    mov.l @r3, r3
    add r3, r4
    mov.w @r11, r2
    extu.w r2, r1
    shll2 r1
    mov.l   .L_0600AF20, r2
    add r1, r2
    mov.l @r2, r1
    add r1, r4
.L_0600AE94:
    jsr @r13
    nop
    mov.w   .L_0600AF12, r0
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r3
    add r3, r4
    mov.l   .L_0600AF24, r3
    jsr @r3
    nop
    mov.l   .L_0600AF28, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600AF8C
    mov.l   .L_0600AF2C, r5
    mov.l   .L_0600AF30, r4
    mov.l   .L_0600AF34, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_0600AF38, r6
    mov.l   .L_0600AF3C, r5
    mov.l   .L_0600AF40, r4
    mov.l   .L_0600AF44, r3
    mov.l @r6, r6
    mov.w @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov #0x0, r6
    mov.w   .L_0600AF14, r0
    mov.l   .L_0600AF48, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   .L_0600AF16, r0
    mov.l   .L_0600AF4C, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_0600AF18, r0
    jsr @r13
    mov.l @(r0, r14), r4
    mov.l   .L_0600AF50, r0
    mov.b @r0, r0
    tst #0x2, r0
    bf      .L_0600AEF4
    mov #0x0, r5
    .byte   0xBD, 0xD2    /* bsr FUN_0600AA98 (external) */
    mov r14, r4
.L_0600AEF4:
    mov r14, r0
    mov.b @(1, r0), r0
    tst #0x1, r0
    bt.s    .L_0600AF5C
    mov #0x0, r12
    mov #0xD, r12
    mov.w @r11, r4
    extu.w r4, r4
    mov.l   .L_0600AF54, r3
    add r3, r4
    mov.b @r4, r4
    mov.l   .L_0600AF58, r2
    mov.l @r2, r2
    bra     .L_0600AF60
    add r2, r4
.L_0600AF12:
    .short  0x01D8
.L_0600AF14:
    .short  0x01B4
.L_0600AF16:
    .short  0x01D0
.L_0600AF18:
    .short  0x01C8
    .short  0xFFFF
.L_0600AF1C:
    .long  sym_06078668
.L_0600AF20:
    .long  sym_0605BDCC
.L_0600AF24:
    .long  mat_rot_y
.L_0600AF28:
    .long  sym_06059F30
.L_0600AF2C:
    .long  sym_060621E8
.L_0600AF30:
    .long  sym_0606213C
.L_0600AF34:
    .long  sym_06031D8C
.L_0600AF38:
    .long  sym_06062190
.L_0600AF3C:
    .long  sym_06089E44
.L_0600AF40:
    .long  sym_060620E8
.L_0600AF44:
    .long  sym_06031A28
.L_0600AF48:
    .long  sym_06026E2E
.L_0600AF4C:
    .long  mat_rot_z
.L_0600AF50:
    .long  sym_06082A25
.L_0600AF54:
    .long  sym_06044740
.L_0600AF58:
    .long  sym_06083258
.L_0600AF5C:
    .byte   0xD4, 0x2B    /* mov.l @(0x0600B00C), r4 */
    mov.l @r4, r4
.L_0600AF60:
    jsr @r13
    nop
    extu.w r12, r14
    .byte   0xD5, 0x2A    /* mov.l @(0x0600B010), r5 */
    .byte   0xD4, 0x2A    /* mov.l @(0x0600B014), r4 */
    .byte   0xD3, 0x2B    /* mov.l @(0x0600B018), r3 */
    shll2 r14
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xD6, 0x28    /* mov.l @(0x0600B01C), r6 */
    .byte   0xD5, 0x29    /* mov.l @(0x0600B020), r5 */
    .byte   0xD4, 0x29    /* mov.l @(0x0600B024), r4 */
    .byte   0xD3, 0x2A    /* mov.l @(0x0600B028), r3 */
    add r14, r6
    mov.w @r5, r5
    add r14, r4
    mov.l @r6, r6
    jsr @r3
    mov.l @r4, r4
.L_0600AF8C:
    .byte   0xD2, 0x27    /* mov.l @(0x0600B02C), r2 */
    .byte   0xD3, 0x28    /* mov.l @(0x0600B030), r3 */
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0600AF9E
    .byte   0xD3, 0x26    /* mov.l @(0x0600B034), r3 */
    jsr @r3
    nop
.L_0600AF9E:
    .byte   0xD4, 0x26    /* mov.l @(0x0600B038), r4 */
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

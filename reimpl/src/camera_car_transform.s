
   .section .text.FUN_0600ADD4


   .global camera_car_transform
   .type camera_car_transform, @function
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
    .4byte  sym_06027080             /* (adj pool FUN_0600AC44: mat_push_B — Stack B push matrix) */
    .4byte  sym_06044670             /* (adj pool FUN_0600AC44: static object position table) */
    .4byte  sym_060270F2             /* (adj pool FUN_0600AC44: mat_xform_trans_B — Stack B transform) */
    .4byte  mat_rot_xz_b            /* (adj pool FUN_0600AC44: XZ rotation) */
    .4byte  sym_060621D8             /* (adj pool FUN_0600AC44: car 3 data struct base) */
    .4byte  sym_06032158             /* (adj pool FUN_0600AC44: distance check / visibility cull B) */
    .4byte  sym_06062180             /* (adj pool FUN_0600AC44: car 2 data struct base) */
    .4byte  sym_06031DF4             /* (adj pool FUN_0600AC44: render submission / VDP1 submit B) */
.L_0600AE4C:
    .4byte  sym_06063F46             /* camera mode index, 16-bit (MEDIUM) */
.L_0600AE50:
    .4byte  mat_rot_x         /* apply accumulated rotation matrix (HIGH) */
.L_0600AE54:
    .4byte  sym_0607E944             /* car array base pointer (HIGH — used across rendering/AI/collision) */
.L_0600AE58:
    .4byte  sym_0607E940             /* current car struct pointer (HIGH — published for other subsystems) */
.L_0600AE5C:
    .4byte  sym_06026DBC             /* mat_push_A — push matrix onto Stack A (HIGH) */
.L_0600AE60:
    .4byte  sym_06026E2E             /* mat_xform_trans_A — vector transform + translate (HIGH) */
.L_0600AE64:
    .4byte  0x00008000               /* 0x8000 = 180 degrees in 16-bit angle space (HIGH) */
.L_0600AE68:
    .4byte  mat_rot_y                /* Y-axis rotation (HIGH) */
.L_0600AE6C:
    .4byte  mat_rot_z                /* Z-axis rotation (HIGH) */
.L_0600AE70:
    .4byte  sym_0607EBC4             /* game mode flags word (HIGH — confirmed across multiple TUs) */
.L_0600AE74:
    .4byte  0x00800008               /* bits: 0x00800000 | 0x00000008 — special camera mode (MEDIUM) */
.L_0600AE78:
    .4byte  sym_0605BDCC             /* per-mode bank angle offset table, 4 bytes/entry (MEDIUM) */
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
    bt/s    .L_0600AF5C
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
    .2byte  0x01D8                   /* car offset: camera yaw */
.L_0600AF14:
    .2byte  0x01B4                   /* car offset: camera roll */
.L_0600AF16:
    .2byte  0x01D0                   /* car offset: camera pitch A */
.L_0600AF18:
    .2byte  0x01C8                   /* car offset: camera pitch B */
    .2byte  0xFFFF                       /* alignment padding */
.L_0600AF1C:
    .4byte  sym_06078668             /* camera height offset value (MEDIUM) */
.L_0600AF20:
    .4byte  sym_0605BDCC             /* bank angle offset table (dup for reach) (MEDIUM) */
.L_0600AF24:
    .4byte  mat_rot_y                /* Y rotation (dup for reach) (HIGH) */
.L_0600AF28:
    .4byte  sym_06059F30             /* camera follow mode flag (MEDIUM — also used in course-specific renderer) */
.L_0600AF2C:
    .4byte  sym_060621E8             /* car 3 data struct + 0x10 (rotation source A) (MEDIUM) */
.L_0600AF30:
    .4byte  sym_0606213C             /* car 1 data struct + 0x10 (rotation dest A) (MEDIUM) */
.L_0600AF34:
    .4byte  sym_06031D8C             /* vec_matrix_xform_A — distance/visibility (Stack A) (MEDIUM) */
.L_0600AF38:
    .4byte  sym_06062190             /* car 2 data struct + 0x10 (rotation source B) (MEDIUM) */
.L_0600AF3C:
    .4byte  sym_06089E44             /* indexed sprite/scale table (16-bit entries) (MEDIUM) */
.L_0600AF40:
    .4byte  sym_060620E8             /* car 0 data struct + 0x10 (rotation dest B) (MEDIUM) */
.L_0600AF44:
    .4byte  sym_06031A28             /* vec_scaled_xform_A — sprite submit / scaled transform (MEDIUM) */
.L_0600AF48:
    .4byte  sym_06026E2E             /* mat_xform_trans_A (dup for reach) (HIGH) */
.L_0600AF4C:
    .4byte  mat_rot_z                /* Z rotation (dup for reach) (HIGH) */
.L_0600AF50:
    .4byte  sym_06082A25             /* camera shake flags byte — bit 1 = shake active (MEDIUM) */
.L_0600AF54:
    .4byte  sym_06044740             /* per-mode LOD lookup table, byte entries indexed by mode (LOW) */
.L_0600AF58:
    .4byte  sym_06083258             /* camera LOD offset base pointer (LOW) */
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

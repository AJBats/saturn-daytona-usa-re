
    .section .text.FUN_0600B4D2


    .global camera_lerp
    .type camera_lerp, @function
camera_lerp:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xDA, 0x0A    /* mov.l .L_pool_0600B516, r10 — camera state ptr */
    mov.l @r10, r10
    .byte   0xDE, 0x0A    /* mov.l .L_pool_0600B51A, r14 — car array base */
    mov.l @r14, r14
    .byte   0xD3, 0x0A    /* mov.l .L_pool_0600B51E, r3 */
    mov.l r14, @r3
    .byte   0xD0, 0x0A    /* mov.l .L_pool_0600B522, r0 */
    bra     .L_end_state_dispatch
    mov.l @r0, r0
.L_camera_mode_a:
    .byte   0xDC, 0x09    /* mov.l .L_pool_0600B526, r12 — rotation source table */
    .byte   0xDB, 0x0A    /* mov.l .L_pool_0600B52A, r11 — rotation dest table */
    bra     .L_position_lerp
    nop
.L_camera_mode_b:
    .byte   0xDC, 0x09    /* mov.l .L_pool_0600B52E, r12 */
    .byte   0xDB, 0x0A    /* mov.l .L_pool_0600B532, r11 */
    bra     .L_position_lerp
    nop
.L_camera_mode_c:
    .byte   0xDC, 0x09    /* mov.l .L_pool_0600B536, r12 */
    .byte   0xDB, 0x0A    /* mov.l .L_pool_0600B53A, r11 */
    bra     .L_position_lerp
    nop
.L_pool_0600B516:
    .4byte  sym_0607EB8C               /* camera lerp state (ptr) */
.L_pool_0600B51A:
    .4byte  sym_0607E944               /* car array base pointer */
.L_pool_0600B51E:
    .4byte  sym_0607E940               /* current car struct pointer */
.L_pool_0600B522:
    .4byte  sym_0607EAD8               /* race end state (0/1/2 dispatch) */
.L_pool_0600B526:
    .4byte  sym_06063488               /* state 0 rotation source params */
.L_pool_0600B52A:
    .4byte  sym_06063434               /* state 0 rotation dest params */
.L_pool_0600B52E:
    .4byte  sym_060634A4               /* state 1 rotation source params */
.L_pool_0600B532:
    .4byte  sym_06063450               /* state 1 rotation dest params */
.L_pool_0600B536:
    .4byte  sym_060634C0               /* state 2 rotation source params */
.L_pool_0600B53A:
    .4byte  sym_0606346C               /* state 2 rotation dest params */
.L_end_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_camera_mode_a
    cmp/eq #0x1, r0
    bt      .L_camera_mode_b
    cmp/eq #0x2, r0
    bt      .L_camera_mode_c
.L_position_lerp:
    .byte   0xD9, 0x3E    /* mov.l .L_pool_0600B65C, r9 — 0x8000 lerp bias */
    mov #0x0, r1
    .byte   0xDD, 0x3E    /* mov.l .L_pool_0600B660, r13 — camera pos XYZ */
    mov.l @(16, r14), r2
    mov.l @r13, r3
    sub r3, r2
    add r9, r2
    cmp/gt r2, r1
    addc r1, r2
    shar r2
    add r2, r3
    mov.l r3, @r13
    mov.l @(20, r14), r2
    mov.l @(4, r13), r3
    sub r3, r2
    cmp/gt r2, r1
    addc r1, r2
    shar r2
    add r2, r3
    mov.l r3, @(4, r13)
    mov.l @(24, r14), r2
    mov.l @(8, r13), r3
    mov.w   DAT_0600b630, r1
    sub r3, r2
    add r1, r2
    mov #0x0, r3
    cmp/gt r2, r3
    addc r3, r2
    shar r2
    mov.l @(8, r13), r1
    add r2, r1
    .byte   0xD3, 0x31    /* mov.l .L_pool_0600B664, r3 */
    jsr @r3
    mov.l r1, @(8, r13)
    mov.l @(8, r13), r6
    mov.l @(4, r13), r5
    .byte   0xD3, 0x2F    /* mov.l .L_pool_0600B668, r3 */
    jsr @r3
    mov.l @r13, r4
    .byte   0xD3, 0x2F    /* mov.l .L_pool_0600B66C, r3 */
    jsr @r3
    mov.l @(32, r14), r4
    .byte   0xD3, 0x2E    /* mov.l .L_pool_0600B670, r3 */
    jsr @r3
    mov.l @(36, r14), r4
    .byte   0xD3, 0x2E    /* mov.l .L_pool_0600B674, r3 */
    jsr @r3
    mov.l @(28, r14), r4
    mov.w   DAT_0600b632, r0
    .byte   0xD3, 0x2A    /* mov.l .L_pool_0600B66C, r3 */
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r2
    jsr @r3
    add r2, r4
    .byte   0xD0, 0x2A    /* mov.l .L_pool_0600B678, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_frame_counter_dec
    mov r9, r6
    mov r9, r5
    .byte   0xD3, 0x28    /* mov.l .L_pool_0600B67C, r3 */
    jsr @r3
    mov r9, r4
    .byte   0xD5, 0x27    /* mov.l .L_pool_0600B680, r5 — scale source (ptr) */
    .byte   0xD3, 0x28    /* mov.l .L_pool_0600B684, r3 */
    mov.l @r5, r5
    jsr @r3
    mov.l @(24, r12), r4
    .byte   0xD6, 0x27    /* mov.l .L_pool_0600B688, r6 — rotation data (ptr) */
    .byte   0xD2, 0x27    /* mov.l .L_pool_0600B68C, r2 — scale table */
    mov.l @r6, r6
    mov r2, r5
    mov.l r2, @(4, r15)
    mov.w @r5, r5
    .byte   0xD3, 0x26    /* mov.l .L_pool_0600B690, r3 */
    extu.w r5, r5
    jsr @r3
    mov.l @(24, r11), r4
    mov #0x0, r6
    mov.w   DAT_0600b634, r0
    .byte   0xD3, 0x19    /* mov.l .L_pool_0600B668, r3 */
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   DAT_0600b636, r0
    .byte   0xD3, 0x18    /* mov.l .L_pool_0600B670, r3 */
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_off_cam_pitch_b, r0
    .byte   0xD2, 0x1F    /* mov.l .L_pool_0600B694, r2 — camera offset */
    .byte   0xD3, 0x17    /* mov.l .L_pool_0600B674, r3 */
    mov.l @(r0, r14), r4
    mov.l @r2, r2
    jsr @r3
    add r2, r4
    mov.l @(12, r10), r5
    shll2 r5
    mov.l r5, @r15
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0600B698, r3 — chain A base */
    mov.l @r15, r4
    .byte   0xD2, 0x16    /* mov.l .L_pool_0600B684, r2 */
    add r3, r5
    add r12, r4
    mov.l @r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @(12, r10), r6
    shll2 r6
    mov.l r6, @r15
    .byte   0xD3, 0x17    /* mov.l .L_pool_0600B69C, r3 — chain B base */
    add r3, r6
    mov.l @r6, r6
    mov.l @(4, r15), r5
    mov.w @r5, r5
    extu.w r5, r5
    mov.l @r15, r4
    add r11, r4
    bra     .L_chain_final_call
    mov.l @r4, r4

    .global DAT_0600b630
DAT_0600b630:
    .2byte  0x8000                        /* Z-axis lerp rounding bias */

    .global DAT_0600b632
DAT_0600b632:
    .2byte  0x01D8                        /* car offset: camera yaw */

    .global DAT_0600b634
DAT_0600b634:
    .2byte  0x01B4                        /* car offset: camera roll */

    .global DAT_0600b636
DAT_0600b636:
    .2byte  0x01D0                        /* car offset: camera pitch A */
.L_off_cam_pitch_b:
    .2byte  0x01C8                        /* car offset: camera pitch B */
    .2byte  0xFFFF
.L_pool_0600B65C:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_0600B660:
    .4byte  sym_06078670               /* camera position XYZ (3×32-bit) */
.L_pool_0600B664:
    .4byte  sym_06027080               /* fixed-point multiply */
.L_pool_0600B668:
    .4byte  sym_060270F2               /* fixed-point divide */
.L_pool_0600B66C:
    .4byte  mat_rot_xy_b               /* XY plane rotation */
.L_pool_0600B670:
    .4byte  mat_rot_yz_b               /* YZ plane rotation */
.L_pool_0600B674:
    .4byte  mat_rot_xz_b               /* XZ plane rotation */
.L_pool_0600B678:
    .4byte  sym_06059F30               /* camera follow mode flag */
.L_pool_0600B67C:
    .4byte  mat_scale_b                /* matrix scale function */
.L_pool_0600B680:
    .4byte  sym_06063510               /* scale source vector (ptr) */
.L_pool_0600B684:
    .4byte  sym_06032158               /* vector matrix transform */
.L_pool_0600B688:
    .4byte  sym_060634F4               /* rotation data source (ptr) */
.L_pool_0600B68C:
    .4byte  sym_06089E98               /* per-mode scale factor (16-bit) */
.L_pool_0600B690:
    .4byte  sym_06031DF4               /* scaled vector transform */
.L_pool_0600B694:
    .4byte  sym_06083258               /* camera LOD offset base */
.L_pool_0600B698:
    .4byte  sym_060634F8               /* rotation chain A params */
.L_pool_0600B69C:
    .4byte  sym_060634DC               /* rotation chain B params */
.L_chain_final_call:
    .byte   0xD2, 0x11    /* mov.l .L_pool_fn_chain_final, r2 — chain finalization */
    jsr @r2
    nop
.L_frame_counter_dec:
    .byte   0xD4, 0x11    /* mov.l .L_pool_frame_counter, r4 — camera frame counter */
    mov.l @r4, r3
    add #-0x30, r3
    mov.l r3, @r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

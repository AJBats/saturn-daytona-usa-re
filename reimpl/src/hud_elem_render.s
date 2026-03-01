
    .section .text.FUN_0601503A


    .global hud_layout_mgr
    .type hud_layout_mgr, @function
hud_layout_mgr:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD3, 0x0B    /* mov.l .L_06015074, r3 */
    mov.b @r3, r3
    tst r3, r3
    .word 0x0029
    .byte   0xD1, 0x0A    /* mov.l .L_06015078, r1 */
    mov.l @r1, r1
    tst r1, r1
    .word 0x0129
    or r1, r0
    .byte   0xD3, 0x09    /* mov.l .L_0601507C, r3 */
    .byte   0xD1, 0x09    /* mov.l .L_06015080, r1 */
    mov.b @r3, r3
    mov.l @r1, r1
    or r3, r0
    tst r1, r1
    .word 0x0129
    or r1, r0
    tst r0, r0
    bt      .L_06015084
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    bra     race_data_dispatch
    mov.l @r15+, r14
.L_06015074:
    .4byte  sym_06085FF4
.L_06015078:
    .4byte  sym_0607EBF4
.L_0601507C:
    .4byte  sym_06078635
.L_06015080:
    .4byte  sym_0607EAE0
.L_06015084:
    .byte   0xD2, 0x23    /* mov.l .L_06015114, r2 */
    mov.w   .L_06015108, r3
    mov.l @r2, r2
    cmp/hs r3, r2
    bt/s    .L_060150F0
    mov #0x0, r13
    .byte   0xD3, 0x21    /* mov.l .L_06015118, r3 */
    jsr @r3
    mov #0xC, r4
    .byte   0xD3, 0x21    /* mov.l .L_0601511C, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x20    /* mov.l .L_06015120, r3 */
    jsr @r3
    nop
    mov #0x60, r6
    mov.w   .L_0601510A, r5
    .byte   0xDE, 0x1F    /* mov.l .L_06015124, r14 */
    .byte   0xD7, 0x1F    /* mov.l .L_06015128, r7 */
    jsr @r14
    mov #0xC, r4
    mov #0x60, r6
    mov.w   .L_0601510C, r5
    .byte   0xD7, 0x1E    /* mov.l .L_0601512C, r7 */
    jsr @r14
    mov #0xC, r4
    .byte   0xD7, 0x1D    /* mov.l .L_06015130, r7 */
    mov #0x60, r6
    mov.w   .L_0601510E, r5
    jsr @r14
    mov #0xC, r4
    .byte   0xD7, 0x1C    /* mov.l .L_06015134, r7 */
    mov.w   .L_06015110, r6
    mov.w   .L_06015112, r5
    jsr @r14
    mov #0xC, r4
    mov.b @r15, r4
    .byte   0xD3, 0x1A    /* mov.l .L_06015138, r3 */
    jsr @r3
    extu.b r4, r4
    extu.b r13, r2
    .byte   0xD3, 0x19    /* mov.l .L_0601513C, r3 */
    mov.b r2, @r3
    mov #0xE, r1
    .byte   0xD3, 0x18    /* mov.l .L_06015140, r3 */
    mov.b r1, @r3
    mov #0xA, r1
    .byte   0xD3, 0x18    /* mov.l .L_06015144, r3 */
    mov.b r1, @r3
    exts.b r13, r13
    .byte   0xD3, 0x17    /* mov.l .L_06015148, r3 */
    mov.b r13, @r3
    bra     .L_060150FE
    nop
.L_060150F0:
    .byte   0xD3, 0x16    /* mov.l .L_0601514C, r3 */
    mov.w r13, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    bra     race_data_dispatch
    mov.l @r15+, r14
.L_060150FE:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06015108:
    .2byte  0x2A94
.L_0601510A:
    .2byte  0x0320
.L_0601510C:
    .2byte  0x051E
.L_0601510E:
    .2byte  0x0532
.L_06015110:
    .2byte  0x0090
.L_06015112:
    .2byte  0x051C
.L_06015114:
    .4byte  sym_0607ED88
.L_06015118:
    .4byte  sym_0602853E
.L_0601511C:
    .4byte  sym_06028560
.L_06015120:
    .4byte  gameover_channel_setup
.L_06015124:
    .4byte  sym_060284AE
.L_06015128:
    .4byte  sym_06044C78
.L_0601512C:
    .4byte  sym_06044C80
.L_06015130:
    .4byte  sym_06044C84
.L_06015134:
    .4byte  sym_06044C88
.L_06015138:
    .4byte  sym_060172E4
.L_0601513C:
    .4byte  sym_06085F8C
.L_06015140:
    .4byte  sym_06085F8D
.L_06015144:
    .4byte  sym_06085F8E
.L_06015148:
    .4byte  sym_06085F8B
.L_0601514C:
    .4byte  sym_0607ED8C

    .global hud_elem_render
    .type hud_elem_render, @function
hud_elem_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x1, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    .byte   0xD9, 0x29    /* mov.l .L_06015208, r9 */
    .byte   0xDC, 0x2A    /* mov.l .L_0601520C, r12 */
    .byte   0xDE, 0x2A    /* mov.l .L_06015210, r14 */
    .byte   0xDB, 0x2B    /* mov.l .L_06015214, r11 */
    .byte   0xD2, 0x2B    /* mov.l .L_06015218, r2 */
    mov.w @(2, r12), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt/s    .L_060151A4
    mov #0x0, r13
    .byte   0xD7, 0x28    /* mov.l .L_0601521C, r7 */
    mov.w   .L_06015202, r6
    mov.b @r9, r5
    mov.b @r11, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    .byte   0xD3, 0x24    /* mov.l .L_06015220, r3 */
    jsr @r3
    mov #0xC, r4
    mov.b r10, @r14
    mov #0x18, r3
    mov.b r3, @r11
    extu.b r13, r2
    .byte   0xD3, 0x21    /* mov.l .L_06015224, r3 */
    mov.b r2, @r3
    bra     .L_060151DC
    nop
.L_060151A4:
    mov.w @(2, r12), r0
    mov.w   .L_06015204, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_060151DC
    .byte   0xD7, 0x1A    /* mov.l .L_0601521C, r7 */
    mov.w   .L_06015202, r6
    mov.b @r9, r5
    mov.b @r11, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    .byte   0xD3, 0x15    /* mov.l .L_06015220, r3 */
    jsr @r3
    mov #0xC, r4
    mov #0xE, r2
    mov.b r2, @r11
    exts.b r13, r3
    mov.b r3, @r14
    extu.b r13, r2
    .byte   0xD3, 0x12    /* mov.l .L_06015224, r3 */
    mov.b r2, @r3
.L_060151DC:
    mov.w @(2, r12), r0
    mov.w   .L_06015206, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601526E
    mov.b @r9, r0
    extu.b r0, r0
    cmp/eq #0xC, r0
    bf      .L_060151F8
    mov.b @r14, r2
    add #0x2, r2
    mov.b r2, @r14
.L_060151F8:
    mov.b @r14, r0
    cmp/eq #0x1, r0
    bf      .L_06015228
    bra     .L_0601527C
    nop
.L_06015202:
    .2byte  0x0090
.L_06015204:
    .2byte  0x4000
.L_06015206:
    .2byte  0x0200
.L_06015208:
    .4byte  sym_06085F8E
.L_0601520C:
    .4byte  g_pad_state
.L_06015210:
    .4byte  sym_06085F8B
.L_06015214:
    .4byte  sym_06085F8D
.L_06015218:
    .4byte  0x00008000
.L_0601521C:
    .4byte  sym_06044C8C
.L_06015220:
    .4byte  sym_060284AE
.L_06015224:
    .4byte  sym_06085F8C
.L_06015228:
    mov.b @r14, r2
    tst r2, r2
    bf      .L_0601524E
    .byte   0xD2, 0x29    /* mov.l .L_060152D4, r2 */
    mov #0x8, r0
    mov.w r10, @r2
    .byte   0xD2, 0x28    /* mov.l .L_060152D8, r2 */
    mov.l r10, @r2
    .byte   0xD2, 0x28    /* mov.l .L_060152DC, r2 */
    mov.w r10, @r2
    .byte   0xD2, 0x28    /* mov.l .L_060152E0, r2 */
    mov.l r0, @r2
    bsr     race_data_dispatch
    nop
    mov #0xE, r3
    .byte   0xD2, 0x27    /* mov.l .L_060152E4, r2 */
    mov.l r3, @r2
    bra     .L_0601526A
    nop
.L_0601524E:
    mov.b @r14, r0
    cmp/eq #0x2, r0
    bf      .L_0601525E
    .byte   0xD3, 0x24    /* mov.l .L_060152E8, r3 */
    jsr @r3
    nop
    bra     .L_0601526A
    nop
.L_0601525E:
    mov.b @r14, r0
    cmp/eq #0x3, r0
    bf      .L_0601526A
    .byte   0xD3, 0x21    /* mov.l .L_060152EC, r3 */
    jsr @r3
    nop
.L_0601526A:
    bra     .L_0601528E
    nop
.L_0601526E:
    mov.w @(2, r12), r0
    mov.w   .L_060152CE, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601528E
.L_0601527C:
    .byte   0xD2, 0x15    /* mov.l .L_060152D4, r2 */
    mov #0x8, r1
    mov.w r13, @r2
    .byte   0xD2, 0x16    /* mov.l .L_060152DC, r2 */
    mov.w r13, @r2
    .byte   0xD2, 0x16    /* mov.l .L_060152E0, r2 */
    mov.l r1, @r2
    bsr     race_data_dispatch
    nop
.L_0601528E:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     .L_0601529E
    mov.l @r15+, r14
.L_0601529E:
    .byte   0xD4, 0x14    /* mov.l .L_060152F0, r4 */
    mov.b @r4, r3
    add #0x40, r3
    mov.b r3, @r4
    mov.b @r4, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_06015304
    .byte   0xD7, 0x11    /* mov.l .L_060152F4, r7 */
    mov.w   .L_060152D0, r6
    .byte   0xD5, 0x11    /* mov.l .L_060152F8, r5 */
    .byte   0xD3, 0x11    /* mov.l .L_060152FC, r3 */
    mov.b @r5, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    .byte   0xD3, 0x0D    /* mov.l .L_06015300, r3 */
    jmp @r3
    mov #0xC, r4
.L_060152CE:
    .2byte  0x0100
.L_060152D0:
    .2byte  0x0090
    .2byte  0xFFFF
.L_060152D4:
    .4byte  sym_0607ED8C
.L_060152D8:
    .4byte  sym_0605AD08
.L_060152DC:
    .4byte  sym_06085F92
.L_060152E0:
    .4byte  sym_0607ED88
.L_060152E4:
    .4byte  g_game_state
.L_060152E8:
    .4byte  geom_render_util
.L_060152EC:
    .4byte  geom_output_finalize
.L_060152F0:
    .4byte  sym_06085F8C
.L_060152F4:
    .4byte  sym_06044C8C
.L_060152F8:
    .4byte  sym_06085F8E
.L_060152FC:
    .4byte  sym_06085F8D
.L_06015300:
    .4byte  sym_060284AE
.L_06015304:
    .byte   0xD7, 0x08    /* mov.l .L_06015328, r7 */
    mov.w   .L_06015324, r6
    .byte   0xD5, 0x08    /* mov.l .L_0601532C, r5 */
    .byte   0xD3, 0x09    /* mov.l .L_06015330, r3 */
    mov.b @r5, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    .byte   0xD3, 0x05    /* mov.l .L_06015334, r3 */
    jmp @r3
    mov #0xC, r4
.L_06015324:
    .2byte  0x0090
    .2byte  0xFFFF
.L_06015328:
    .4byte  sym_06044C88
.L_0601532C:
    .4byte  sym_06085F8E
.L_06015330:
    .4byte  sym_06085F8D
.L_06015334:
    .4byte  sym_060284AE

    .global race_data_dispatch
    .type race_data_dispatch, @function
race_data_dispatch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.w   .L_0601541A, r12
    .byte   0xDE, 0x36    /* mov.l .L_0601541C, r14 */
    .byte   0xD3, 0x36    /* mov.l .L_06015420, r3 */
    jsr @r3
    mov #0x0, r13
    mov r13, r5
    jsr @r14
    mov r12, r4
    .byte   0xD3, 0x34    /* mov.l .L_06015424, r3 */
    mov #0x1E, r1
    mov.b r13, @r3
    .byte   0xD3, 0x34    /* mov.l .L_06015428, r3 */
    mov.l r1, @r3
    .byte   0xD3, 0x34    /* mov.l .L_0601542C, r3 */
    jsr @r3
    nop
    .byte   0xD2, 0x33    /* mov.l .L_06015430, r2 */
    .byte   0xD3, 0x34    /* mov.l .L_06015434, r3 */
    mov.b @r2, r2
    mov.b @r3, r3
    extu.b r2, r2
    extu.b r3, r3
    or r3, r2
    tst r2, r2
    bt      .L_06015388
    .byte   0xD3, 0x31    /* mov.l .L_06015438, r3 */
    mov.w @r3, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_06015382
    .byte   0xD3, 0x2F    /* mov.l .L_0601543C, r3 */
    jsr @r3
    nop
.L_06015382:
    mov #0x1A, r2
    .byte   0xD3, 0x28    /* mov.l .L_06015428, r3 */
    mov.l r2, @r3
.L_06015388:
    .byte   0xD3, 0x2D    /* mov.l .L_06015440, r3 */
    jsr @r3
    nop
    mov #0x0, r5
    jsr @r14
    mov r12, r4
    mov #0x1, r5
    jsr @r14
    mov #0x4, r4
    mov #0x6, r5
    jsr @r14
    mov #0x10, r4
    .byte   0xD3, 0x28    /* mov.l .L_06015444, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x28    /* mov.l .L_06015448, r3 */
    mov.l r13, @r3
    .byte   0xD3, 0x28    /* mov.l .L_0601544C, r3 */
    jsr @r3
    nop
    mov #0x3, r2
    .byte   0xD3, 0x27    /* mov.l .L_06015450, r3 */
    mov.w r2, @r3
    .byte   0xD3, 0x27    /* mov.l .L_06015454, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x26    /* mov.l .L_06015458, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x24    /* mov.l .L_06015454, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x23    /* mov.l .L_06015458, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x23    /* mov.l .L_0601545C, r3 */
    jsr @r3
    mov #0x4, r4
    .byte   0xD3, 0x21    /* mov.l .L_0601545C, r3 */
    jsr @r3
    mov #0xC, r4
    .byte   0xD3, 0x21    /* mov.l .L_06015460, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x20    /* mov.l .L_06015464, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x20    /* mov.l .L_06015468, r4 */
    mov.l @r4, r0
    or #0x4, r0
    mov.l r0, @r4
    .byte   0xD3, 0x16    /* mov.l .L_06015448, r3 */
    mov.l r13, @r3
    .byte   0xD3, 0x16    /* mov.l .L_0601544C, r3 */
    jsr @r3
    nop
    mov #0x4, r5
    jsr @r14
    mov r12, r4
    mov #0x0, r5
    jsr @r14
    mov #0x4, r4
    .byte   0xD2, 0x19    /* mov.l .L_0601546C, r2 */
    mov.l @r2, r2
    shll2 r2
    .byte   0xD3, 0x19    /* mov.l .L_06015470, r3 */
    add r3, r2
    mov.l @r2, r2
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    jmp @r2
    mov.l @r15+, r14
.L_0601541A:
    .2byte  0x0100
.L_0601541C:
    .4byte  channel_nibble_config
.L_06015420:
    .4byte  handler_init_reset
.L_06015424:
    .4byte  sym_06085F8A
.L_06015428:
    .4byte  g_game_state
.L_0601542C:
    .4byte  sym_0601ABC6
.L_06015430:
    .4byte  sym_06085FF8
.L_06015434:
    .4byte  sym_06085FF9
.L_06015438:
    .4byte  sym_06085F92
.L_0601543C:
    .4byte  course_config_render
.L_06015440:
    .4byte  vdp2_loop_ctrl
.L_06015444:
    .4byte  sym_060149E0
.L_06015448:
    .4byte  sym_0605A00C
.L_0601544C:
    .4byte  sym_06026CE0
.L_06015450:
    .4byte  sym_0605A016
.L_06015454:
    .4byte  obj_data_compact
.L_06015458:
    .4byte  frame_end_commit
.L_0601545C:
    .4byte  sym_0602853E
.L_06015460:
    .4byte  sym_06028560
.L_06015464:
    .4byte  gameover_channel_setup
.L_06015468:
    .4byte  sym_0605B6D8
.L_0601546C:
    .4byte  sym_0607EAD8
.L_06015470:
    .4byte  sym_0605B724

    .global loc_06015474
loc_06015474:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r4
    extu.b r4, r4
    .byte   0xD3, 0x1A    /* mov.l .L_fn_thunk_target, r3 */
    jmp @r3
    add #0x4, r15

/* RE_TEST: Inverted menu navigation — DOWN goes up, UP goes down
 * Based on src/mode_select_handler.s (byte-identical to retail)
 *
 * Change: swapped button masks in DOWN/UP handlers.
 *   DOWN handler checks BTN_UP (0x1000) → pressing DOWN triggers UP action
 *   UP handler checks BTN_DOWN (0x2000) → pressing UP triggers DOWN action
 *
 * Also converted 3 cross-TU .byte references to proper mnemonics with
 * local pool entries (btn_down mask, sym_0605D243, sym_0605D250).
 *
 * Split prologue: course_select_input pushes r10-r14 and falls through.
 * This function's epilogue pops them. Do NOT change the epilogue.
 */


    .section .text.FUN_060196B0


    .global mode_select_handler
    .type mode_select_handler, @function
mode_select_handler:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_pool_06019768, r10
    mov.l   .L_pool_0601976C, r12
    mov.l   .L_pool_06019770, r14
    mov.l   .L_pool_06019774, r3
    jsr @r3
    mov #0x1, r13
    mov.l   .L_pool_06019778, r4
    mov.w   .L_wpool_06019762, r3
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_06019738
    /* --- B button handler (unchanged) --- */
    mov.b @r14, r7
    shll r7
    mov.l r7, @(8, r15)
    mov.l   .L_pool_0601977C, r3
    mov.l   .L_pool_06019780, r2
    add r3, r7
    mov.w @r7, r7
    extu.w r7, r7
    shll2 r7
    shll r7
    add r2, r7
    mov.l r7, @(4, r15)
    mov.l @(4, r7), r7
    mov.w   .L_wpool_06019764, r3          /* 0x2000 — pointer offset, NOT button mask */
    mov.l @(8, r15), r6
    add r3, r7
    mov.l   .L_pool_06019784, r3
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
    mov.l   .L_pool_06019788, r3
    jsr @r3
    mov #0xC, r4
    mov.b @r14, r2
    cmp/gt r13, r2
    bf      .L_06019720
    exts.b r11, r2
    mov.b r2, @r14
.L_06019720:
    mov.l   .L_pool_0601978C, r3
    mov.l r11, @r3
    extu.b r11, r2
    mov.b r2, @r12
    mov #0x4, r3
    mov.l   .L_pool_06019790, r2
    mov.l r3, @r2
    exts.b r13, r3
    mov.b r3, @r10
    mov.l   .L_pool_06019794, r3
    bra     .L_060197E4
    mov.b r13, @r3
.L_06019738:
    /* --- DOWN handler — SWAPPED: checks BTN_UP (0x1000) --- */
    mov.w @(2, r4), r0
    mov.w   .L_wpool_btn_up, r3            /* SWAPPED: was 0x2000, now 0x1000 */
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt/s    .L_06019798
    mov #0x5, r5
    mov.b r13, @r10
    extu.b r5, r5
    mov.b r5, @r12
    mov.b @r14, r2
    add #0x1, r2
    mov.b r2, @r14
    mov.b @r14, r3
    mov #0x4, r2
    cmp/ge r2, r3
    bf      .L_060197BC
    exts.b r11, r2
    bra     .L_060197BC
    mov.b r2, @r14

    .global DAT_06019762
.L_wpool_06019762:
DAT_06019762:
    .2byte  0x0100
.L_wpool_06019764:
    .2byte  0x2000
.L_wpool_btn_up:
    .2byte  0x1000                         /* UP mask — used by DOWN handler (swapped) */
.L_pool_06019768:
    .4byte  sym_06085FF1
.L_pool_0601976C:
    .4byte  sym_0605D242
.L_pool_06019770:
    .4byte  sym_0605D244
.L_pool_06019774:
    .4byte  scene_dual_finalize
.L_pool_06019778:
    .4byte  g_pad_state
.L_pool_0601977C:
    .4byte  sym_06049AF4
.L_pool_06019780:
    .4byte  sym_06063750
.L_pool_06019784:
    .4byte  sym_06049AEC
.L_pool_06019788:
    .4byte  sym_06028400
.L_pool_0601978C:
    .4byte  sym_06059F44
.L_pool_06019790:
    .4byte  g_game_state
.L_pool_06019794:
    .4byte  sym_06085FF5
.L_06019798:
    /* --- UP handler — SWAPPED: checks BTN_DOWN (0x2000) --- */
    mov.w @(2, r4), r0
    mov.w   .L_wpool_btn_down, r3          /* SWAPPED: was 0x1000, now 0x2000 */
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_060197BC
    mov.b r13, @r10
    extu.b r5, r5
    mov.b r5, @r12
    mov.b @r14, r2
    add #-0x1, r2
    mov.b r2, @r14
    mov.b @r14, r3
    cmp/pz r3
    bt      .L_060197BC
    mov #0x3, r3
    mov.b r3, @r14
.L_060197BC:
    /* --- Common exit: increment counters, dispatch --- */
    mov.l   .L_pool_sym_0605D243, r4       /* was .byte 0xD4, 0x2B (cross-TU) */
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    mov.b @r12, r3
    add #0x1, r3
    mov.b r3, @r12
    mov.b @r14, r2
    shll2 r2
    mov.l   .L_pool_sym_0605D250, r3       /* was .byte 0xD3, 0x28 (cross-TU) */
    add r3, r2
    mov.l @r2, r2
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    jmp @r2
    mov.l @r15+, r14
.L_060197E4:
    /* --- B-button exit path (epilogue) --- */
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    /* --- New pool entries (forward-reachable from UP handler + common exit) --- */
.L_wpool_btn_down:
    .2byte  0x2000                         /* DOWN mask — used by UP handler (swapped) */
    .balign 4
.L_pool_sym_0605D243:
    .4byte  sym_0605D243
.L_pool_sym_0605D250:
    .4byte  sym_0605D250

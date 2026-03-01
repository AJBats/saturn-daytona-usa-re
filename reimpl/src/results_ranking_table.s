
    .section .text.FUN_060164CE


    .global results_ranking_table
    .type results_ranking_table, @function
results_ranking_table:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r12
    .byte   0xDD, 0x0A    /* mov.l .L_p_entry_table, r13 */  ! r13 = &results_entry_table (sym_06084FC8)
    .byte   0xD0, 0x0D    /* mov.l .L_p_bonus_flag, r0 */    ! r0 = &bonus_mode_flag (sym_06085F89)
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_bonus_active
    mov r4, r14
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l r12, @(44, r4)
    mov #0x3, r2
    mov r2, r0
    bra     .L_epilogue
    mov.b r0, @(2, r4)
    .2byte  0xFFFF
.L_p_entry_table:
    .4byte  sym_06084FC8               /* [HIGH] results entry table base */
    .4byte  0x000B0000                 /* [MEDIUM] 11.0 (16.16 FP) */
    .4byte  0x00040000                 /* [MEDIUM] 4.0 (16.16 FP) */
    .4byte  0x0000C000                 /* [MEDIUM] 0.75 (16.16 FP) */
.L_p_bonus_flag:
    .4byte  sym_06085F89               /* [MEDIUM] bonus mode flag (byte) */
.L_bonus_active:
    .byte   0xD5, 0x44    /* mov.l .L_fp_one, r5 */  ! r5 = 0x00010000 (1.0 in 16.16 fixed-point)
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    mov.l @(12, r2), r2
    cmp/gt r5, r2
    bf      .L_init_fresh_entry
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(16, r4), r2
    mov.l @(4, r4), r3
    add r2, r3
    mov.l r3, @(4, r4)
    extu.b r14, r2
    mov #0x4, r3
    cmp/ge r3, r2
    bt      .L_clamp_gt_check
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(4, r4), r2
    mov.l @(52, r4), r3
    cmp/ge r3, r2
    bf      .L_after_clamp
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    bra     .L_after_clamp
    mov.l r2, @(4, r4)
.L_clamp_gt_check:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(4, r4), r2
    mov.l @(52, r4), r3
    cmp/gt r3, r2
    bt      .L_after_clamp
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    mov.l r2, @(4, r4)
.L_after_clamp:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(24, r4), r2
    mov.l @(12, r4), r3
    sub r2, r3
    mov.l r3, @(12, r4)
    mov.l @(36, r4), r2
    mov.l @(24, r4), r3
    sub r2, r3
    mov r3, r2
    mov.l r3, @(24, r4)
    .byte   0xD3, 0x15    /* mov.l .L_fp_two, r3 */  ! r3 = 0x00020000 (2.0 in 16.16 FP)
    cmp/gt r3, r2
    bt      .L_epilogue
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.w   .L_w_countdown_reset, r2
    mov.l r2, @(24, r4)
    bra     .L_epilogue
    mov.l r12, @(16, r4)
.L_init_fresh_entry:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l r5, @(12, r4)
    mov.l r12, @(36, r4)
    mov r12, r2
    mov.l r12, @(24, r4)
    mov.b @(2, r4), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    mov.b r0, @(2, r4)
.L_epilogue:
    extu.b r14, r4
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA3, 0xDA    /* bra 0x06016DD8 (external) */  ! tail-call digit renderer
    mov.l @r15+, r14
.L_w_countdown_reset:
    .2byte  0x0600                     /* [MEDIUM] countdown reset value */
    .2byte  0xFFFF
.L_fp_one:
    .4byte  0x00010000                 /* [HIGH] 1.0 (16.16 fixed-point) */
.L_fp_two:
    .4byte  0x00020000                 /* [HIGH] 2.0 (16.16 fixed-point) */

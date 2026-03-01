
    .section .text.FUN_060167DC


    .global results_input_handler
    .type results_input_handler, @function
results_input_handler:
    sts.l pr, @-r15
    shll2 r3
    mov.l   .L_pool_06016870, r13
    mov.w   .L_0601686C, r2
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(44, r4), r3
    add r2, r3
    mov.l r3, @(44, r4)
    mov r3, r2
    mov.l @(60, r4), r3
    cmp/ge r3, r2
    bf/s    _no_scroll_wrap
    extu.b r12, r11
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(60, r4), r2
    mov.l r2, @(44, r4)
    mov #0x1, r11
_no_scroll_wrap:
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(48, r3), r0
    tst r0, r0
    bt      _skip_bounce
    extu.b r14, r3
    mov #0x7, r2
    mov.w   .L_0601686E, r4
    cmp/ge r2, r3
    bt      _bounce_subtract
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(48, r5), r2
    add r4, r2
    mov.l r2, @(48, r5)
    mov r2, r3
    cmp/pz r3
    bf      _skip_bounce
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l r12, @(48, r3)
    bra     _skip_bounce
    nop
.L_0601686C:
    .2byte  0x0F00                          /* 0x0F00 = scroll step per frame [HIGH] */
.L_0601686E:
    .2byte  0x1800                          /* 0x1800 = bounce velocity delta per frame [HIGH] */
.L_pool_06016870:
    .4byte  sym_06084FC8                    /* results element array base (0x44-byte structs) [HIGH] */
_bounce_subtract:
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(48, r5), r2
    sub r4, r2
    mov r2, r3
    mov.l r2, @(48, r5)
    cmp/pl r3
    bt      _skip_bounce
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l r12, @(48, r3)
_skip_bounce:
    .byte   0xB2, 0x97    /* bsr 0x06016DD8 (external) */
    extu.b r14, r4
    extu.b r11, r11
    tst r11, r11
    bt      _epilogue
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov #0x4, r2
    mov #0x41, r0
    mov.b r2, @(r0, r4)
    mov #0x3, r3
    mov r3, r0
    mov.b r0, @(2, r4)
_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global loc_060168DA
loc_060168DA:
    extu.b r4, r3
    mov #0x7, r2
    mov.l   .L_pool_0601693C, r5
    cmp/ge r2, r3
    bt      _high_index_target
    extu.b r4, r2
    extu.b r4, r1
    mov r2, r3
    shll8 r1
    shll2 r2
    shll2 r3
    shll2 r1
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    shll r1
    mov.w   .L_06016938, r3
    add r3, r1
    bra     _write_target_y
    add r5, r2
_high_index_target:
    extu.b r4, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r5, r2
    mov.w   .L_0601693A, r1
_write_target_y:
    mov.l r1, @(56, r2)
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r5, r4
    mov.b @(2, r4), r0
    mov r0, r2
    add #0x1, r2
    mov r2, r0
    rts
    mov.b r0, @(2, r4)
.L_06016938:
    .2byte  0xC000                          /* 0xC000 = target Y for high-index elements (idx >= 7) [HIGH] */
.L_0601693A:
    .2byte  0x4000                          /* 0x4000 = target Y for low-index elements (idx < 7) [HIGH] */
.L_pool_0601693C:
    .4byte  sym_06084FC8                    /* results element array base (0x44-byte structs) [HIGH] */

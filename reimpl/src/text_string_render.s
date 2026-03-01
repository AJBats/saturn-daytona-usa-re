
    .section .text.FUN_06016A60


    .global text_string_render
    .type text_string_render, @function
text_string_render:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    extu.b r14, r3
    mov.l   .L_pool_text_obj_array, r13
    mov.l   .L_fp_one, r5
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(12, r3), r3
    cmp/gt r5, r3
    bf      .L_not_yet_scrolling
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
    bt      .L_check_accum_high
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
    bf      .L_apply_accum_clamp
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
    bra     .L_apply_accum_clamp
    mov.l r2, @(4, r4)
    .2byte  0xFFFF
.L_pool_text_obj_array:
    .4byte  sym_06084FC8                /* base address of text object array (68 bytes/entry) */
    .4byte  0x000B0000                  /* 11.0 (16.16 fixed-point) */
    .4byte  0x00040000                  /* 4.0 (16.16 fixed-point) */
    .4byte  0x0000C000                  /* 0.75 (16.16 fixed-point) */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_check_accum_high:
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
    bt      .L_apply_accum_clamp
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
.L_apply_accum_clamp:
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
    mov.l r3, @(24, r4)
    mov r3, r2
    mov.l   .L_fp_two, r3
    cmp/gt r3, r2
    bt      .L_done_update
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.w   .L_wpool_base_scroll_step, r2
    mov.l r2, @(24, r4)
    mov #0x0, r3
    mov.l r3, @(16, r4)
    bra     .L_done_update
    nop
.L_not_yet_scrolling:
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
    mov #0x0, r2
    mov.l r2, @(36, r4)
    mov r2, r3
    mov.l r2, @(24, r4)
    mov #0x2, r2
    mov r2, r0
    mov.b r0, @(2, r4)
.L_done_update:
    extu.b r14, r4
    mov.l @r15+, r13
    .byte   0xA1, 0x25    /* bra 0x06016DD8 (external) */ ! tail-call to external text handler
    mov.l @r15+, r14

    .global loc_06016B8E
loc_06016B8E:
    rts
    nop
.L_wpool_base_scroll_step:
    .2byte  0x0600                      /* [MEDIUM] base scroll step value for text animation reset */
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */

    .global loc_06016B98
loc_06016B98:
    mov.l   .L_pool_text_obj_base, r6
    extu.b r4, r5
    mov #0x41, r0
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r6, r5
    mov.b @(r0, r5), r2
    add #-0x1, r2
    mov.b r2, @(r0, r5)
    mov.b @(r0, r5), r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_active_count_nonzero
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r6, r4
    mov #0x7, r2
    mov r2, r0
    mov.b r0, @(2, r4)
.L_active_count_nonzero:
    rts
    nop

    .global loc_06016BD8
loc_06016BD8:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l   .L_pool_text_obj_base, r1
    add r1, r3
    mov.b @(2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    mov.l   .L_pool_dispatch_table_a, r2
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15

    .global loc_06016C06
loc_06016C06:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l   .L_pool_text_obj_base, r1
    add r1, r3
    mov.b @(2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    mov.l   .L_pool_dispatch_table_b, r2
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15
.L_pool_text_obj_base:
    .4byte  sym_06084FC8                /* text object array base (68 bytes/entry) */
.L_pool_dispatch_table_a:
    .4byte  sym_0605BB1C                /* dispatch table A: state->handler fn ptrs */
.L_pool_dispatch_table_b:
    .4byte  sym_0605BB48                /* dispatch table B: state->handler fn ptrs */

    .global loc_06016C40
loc_06016C40:
    extu.b r4, r5
    mov #0x1, r0
    .byte   0xD2, 0x15    /* mov.l pool@0x06016C9C (external: text_obj_array base), r2 */
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    mov #0x27, r3
    add r2, r5
    mov.b r0, @(1, r5)
    .byte   0xD2, 0x11    /* mov.l pool@0x06016CA0 (external: global entry-counter ptr), r2 */
    mov.b r3, @r2
    mov.b @(2, r5), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    rts
    mov.b r0, @(2, r5)


    .section .text.FUN_06026590


    .global sprite_pair_render
    .type sprite_pair_render, @function
sprite_pair_render:
    mov.l r14, @-r15
    extu.w r5, r5
    mov.l r13, @-r15
    mov #0x0, r14
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x50, r11
    mov.l r9, @-r15
    mov #0x40, r9
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.w   .L_slot_table_size, r8
    mov.l   .L_slot_element_table, r13
    mov r8, r3
    add #0x1, r3
    cmp/eq r3, r5
    bf/s    .L_variant_b_clear
    mov r4, r12
    mov r13, r4
    mov r13, r6
    add r8, r6
.L_clear_loop_a:
    mov r4, r5
    extu.w r14, r1
    mov.l @r4, r3
    mov.l @(4, r5), r2
    add #0xC, r4
    mov.w r14, @r2
    mov r4, r5
    mov.w r14, @r3
    mov.l @r4, r3
    mov.l @(4, r5), r2
    add #0xC, r4
    mov.w r1, @r2
    mov.w r1, @r3
    cmp/hs r6, r4
    bf      .L_clear_loop_a
    exts.b r12, r0
    cmp/eq #0x4, r0
    bf      .L_skip_rotation_a
    .byte   0xBE, 0xBF    /* bsr 0x06026362 (external) */
    nop
.L_skip_rotation_a:
    mov r14, r5
    mov r14, r4
    exts.b r12, r10
    shll2 r10
    mov.l   .L_render_record_ptr_table_a, r3
    bra     .L_merge_check_a
    add r3, r10
.L_merge_loop_a:
    mov.l @r10, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_merge_apply_a
    bra     .L_merge_next_a
    nop
.L_merge_apply_a:
    mov.l @r10, r6
    add r5, r6
    mov.l @r6, r3
    mov.w @(4, r6), r0
    mov r0, r2
    extu.w r2, r2
    mov.w @r3, r1
    or r2, r1
    mov.w r1, @r3
.L_merge_next_a:
    add #0x8, r5
    add #0x8, r4
.L_merge_check_a:
    cmp/hs r11, r4
    bf      .L_merge_loop_a
    bra     .L_post_merge
    nop
.L_variant_b_clear:
    mov r13, r4
    mov r13, r6
    add r8, r6
.L_clear_loop_b:
    mov r4, r5
    extu.w r14, r1
    mov.l @r4, r2
    mov.l @(4, r5), r3
    add #0xC, r4
    mov.w r14, @r3
    mov r4, r5
    mov.w r14, @r2
    mov.l @r4, r3
    mov.l @(4, r5), r2
    add #0xC, r4
    mov.w r1, @r2
    mov.w r1, @r3
    cmp/hs r6, r4
    bf      .L_clear_loop_b
    exts.b r12, r0
    cmp/eq #0x4, r0
    bf      .L_skip_rotation_b
    .byte   0xBF, 0x21    /* bsr 0x0602648E (external) */
    nop
.L_skip_rotation_b:
    mov r14, r5
    mov r14, r4
    exts.b r12, r10
    shll2 r10
    mov.l   .L_render_record_ptr_table_b, r3
    bra     .L_merge_check_b
    add r3, r10
.L_merge_loop_b:
    mov.l @r10, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_merge_apply_b
    bra     .L_merge_next_b
    nop
.L_slot_table_size:
    .2byte  0x00A8                          /* 14 entries * 12 bytes = 168 = 0xA8 */
    .2byte  0xFFFF                          /* padding / unused */
.L_slot_element_table:
    .4byte  sym_060610BC                    /* slot element table (12-byte stride) */
.L_render_record_ptr_table_a:
    .4byte  sym_06061170                    /* render record ptr table A (5 x 4-byte ptrs) */
.L_render_record_ptr_table_b:
    .4byte  sym_06061184                    /* render record ptr table B (5 x 4-byte ptrs) */
.L_merge_apply_b:
    mov.l @r10, r6
    add r5, r6
    mov.l @r6, r3
    mov.w @(4, r6), r0
    mov r0, r2
    extu.w r2, r2
    mov.w @r3, r1
    or r2, r1
    mov.w r1, @r3
.L_merge_next_b:
    add #0x8, r5
    add #0x8, r4
.L_merge_check_b:
    cmp/hs r9, r4
    bf      .L_merge_loop_b
.L_post_merge:
    exts.b r12, r0
    cmp/eq #0x4, r0
    bf      .L_epilogue
    mov r13, r4
    mov r13, r6
    add r8, r6
.L_copyback_loop:
    mov r4, r5
    mov.l @r4, r2
    mov.l @(4, r5), r3
    add #0xC, r4
    mov.w @r3, r1
    mov r4, r5
    mov.w r1, @r2
    mov.l @r4, r3
    mov.l @(4, r5), r2
    add #0xC, r4
    mov.w @r2, r1
    mov.w r1, @r3
    cmp/hs r6, r4
    bf      .L_copyback_loop
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

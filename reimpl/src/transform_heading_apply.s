
    .section .text.FUN_060262C0


    .global transform_heading_apply
    .type transform_heading_apply, @function
transform_heading_apply:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r10, @-r15
    mov.l   .L_pool_06026314, r10
    mov #0xA, r12
    mov.l   .L_pool_06026318, r13
    mov.l   .L_pool_0602631C, r14
    mov #0x1, r7
    mov #0x2, r6
    mov #0x0, r0
    extu.w r0, r3
    mov.w r3, @r13
    extu.w r0, r2
    mov.w r2, @r14
    bra     .L_loop_check
    extu.w r0, r5
.L_loop_body:
    extu.w r5, r2
    cmp/eq r4, r2
    bf      .L_not_skip_slot
    bra     .L_loop_next
    nop
.L_not_skip_slot:
    extu.w r5, r0
    shll2 r0
    shll r0
    add r10, r0
    mov.w @(6, r0), r0
    bra     .L_dispatch_heading
    extu.w r0, r0
    .2byte  0xA001                          /* bra .L_case_23_store_id_b: store then bra loop */
    .4byte  0x627D626D                      /* extu.w r7,r2 / extu.w r6,r2 */
    .4byte  0xA0262D21                      /* bra .L_loop_next / mov.w r2,@r13 [delay] */
    .4byte  0xA001627D                      /* bra .L_case_811_store_id_b: bra / extu.w r7,r2 [delay] */
    .4byte  0x626DA021                      /* extu.w r6,r2 / bra .L_loop_next */
    .2byte  0x2E21                          /* mov.w r2,@r14 [delay: store r2 to course_id_b] */
.L_out_of_range:
    bra     .L_loop_next
    nop
    .2byte  0xFFFF                          /* alignment padding */
.L_pool_06026314:
    .4byte  sym_06060F2C                    /* [MEDIUM] slot_data_table base (8-byte stride, up to 10 slots) */
.L_pool_06026318:
    .4byte  sym_06089ED6                    /* [HIGH] &course_id_a (word) */
.L_pool_0602631C:
    .4byte  sym_06089ED4                    /* [HIGH] &course_id_b (word) */
.L_dispatch_heading:
    mov.w   .L_wpool_06026336, r1
    sub r1, r0
    mov #0xC, r1
    cmp/hs r1, r0
    bt      .L_out_of_range
    shll r0
    mov r0, r1
    .word 0xC702
    mov.w @(r0, r1), r0
    braf r0
    nop
.L_wpool_06026336:
    .2byte  0x008A                          /* [HIGH] heading base value to subtract (0x8A) */
    .4byte  0xFFC4FFC4                      /* jump offsets: index 0 (-60), index 1 (-60) -> course_id_a=1 */
    .4byte  0xFFCEFFCE                      /* jump offsets: index 2 (-50), index 3 (-50) -> course_id_a=slot_idx, course_id_b=1 */
    .4byte  0xFFC8FFC8                      /* jump offsets: index 4 (-56), index 5 (-56) -> course_id_a=2 */
    .4byte  0xFFC8FFC8                      /* jump offsets: index 6 (-56), index 7 (-56) -> course_id_a=2 */
    .4byte  0xFFD2FFD2                      /* jump offsets: index 8 (-46), index 9 (-46) -> course_id_b=2 */
    .4byte  0xFFD2FFD2                      /* jump offsets: index 10 (-46), index 11 (-46) -> course_id_b=2 */
.L_loop_next:
    add #0x1, r5
.L_loop_check:
    extu.w r5, r2
    cmp/ge r12, r2
    bf      .L_loop_body
    mov.l @r15+, r10
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

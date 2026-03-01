
    .section .text.FUN_0600CDD0


    .global race_heading_calc
    .type race_heading_calc, @function
race_heading_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x2D    /* mov.l .L_pool_0600CE90, r14 */
    .byte   0x90, 0x53    /* mov.w .L_wpool_0600CE86, r0 */
    mov.l @r14, r14
    mov.l @(r0, r14), r13
    add #-0x4, r0
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r13
    shll2 r3
    add r3, r13
    mov.l @(r0, r14), r3
    add r3, r13
    mov.w @(22, r13), r0
    mov r0, r3
    extu.w r3, r3
    .byte   0x90, 0x45    /* mov.w .L_wpool_0600CE88, r0 */
    mov.l r3, @(r0, r14)
    add #0x60, r0
    mov.l @(r0, r14), r4
    tst r4, r4
    bt      .L_use_max_segments
    mov r4, r12
    bra     .L_have_next_segment
    add #-0x1, r12
.L_use_max_segments:
    .byte   0xDC, 0x21    /* mov.l .L_pool_0600CE94, r12 */
    mov.l @r12, r12
.L_have_next_segment:
    mov r12, r11
    mov r12, r3
    .byte   0x90, 0x39    /* mov.w .L_wpool_0600CE8A, r0 */
    mov.l @(24, r14), r5
    shll2 r11
    shll2 r3
    mov.l @(r0, r14), r2
    shll r11
    shll2 r3
    add r3, r11
    add r2, r11
    mov.l @(4, r11), r3
    mov.l @r11, r4
    mov.l @(16, r14), r2
    sub r3, r5
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0600CE98, r3 */
    jsr @r3
    sub r2, r4
    exts.w r0, r6
    exts.w r6, r5
    mov.w @(14, r13), r0
    mov r5, r4
    mov r0, r7
    shll2 r7
    sub r7, r4
    cmp/pz r4
    bt      .L_diff_positive
    mov r7, r2
    bra     .L_check_threshold
    sub r5, r2
.L_diff_positive:
    mov r4, r2
.L_check_threshold:
    .byte   0x93, 0x1D    /* mov.w .L_wpool_0600CE8C, r3 */
    cmp/gt r3, r2
    bf      .L_no_advance
    .byte   0x90, 0x17    /* mov.w .L_wpool_0600CE86, r0 */
    mov.l r12, @(r0, r14)
.L_no_advance:
    mov r13, r0
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .section .text.FUN_06025070


    .global scene_finalize_a
    .type scene_finalize_a, @function
scene_finalize_a:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l   .L_pool_06025138, r10
    mov.l   .L_pool_0602513C, r11
    mov.l   .L_pool_06025140, r12
    mov #0xA, r7
    mov #0x0, r4
    extu.w r4, r5
.L_init_slot_loop:
    extu.w r5, r6
    extu.w r4, r0
    extu.b r5, r3
    shll2 r6
    mov r3, r2
    add #0x1, r5
    shll r6
    shll2 r3
    shll2 r2
    add r11, r6
    shll r2
    mov.l r4, @r6
    add r2, r3
    mov.w r0, @(4, r6)
    extu.b r3, r3
    extu.w r4, r2
    mov.w   DAT_06025136, r0
    add r10, r3
    mov.w r0, @(6, r6)
    mov.l @(4, r3), r3
    mov.w r2, @r3
    extu.w r5, r3
    cmp/ge r7, r3
    bf      .L_init_slot_loop
    bra     .L_outer_loop_test
    extu.w r4, r13
.L_outer_loop_body:
    extu.w r4, r5
    extu.w r13, r8
    extu.b r13, r14
    mov.l   .L_pool_06025144, r3
    shll2 r8
    mov r14, r2
    shll r8
    shll2 r14
    shll2 r2
    add r3, r8
    shll r2
    add r2, r14
    extu.b r14, r14
    add r10, r14
.L_inner_slot_loop:
    extu.w r5, r0
    mov.l @r8, r2
    shll r0
    mov.w @r2, r1
    mov.w @(r0, r12), r3
    extu.w r1, r1
    extu.w r3, r3
    and r1, r3
    tst r3, r3
    bt      .L_skip_slot
    extu.w r5, r6
    extu.w r5, r9
    mov.l @(4, r14), r3
    shll2 r6
    shll r6
    add r11, r6
    mov.l r3, @r6
    shll r9
    add r12, r9
    mov.w @r9, r0
    mov.w r0, @(4, r6)
    mov.w @(8, r14), r0
    mov.w r0, @(6, r6)
    mov.l @r6, r3
    mov.w @r9, r2
    extu.w r2, r2
    mov.w @r3, r1
    or r2, r1
    mov.w r1, @r3
.L_skip_slot:
    add #0x1, r5
    extu.w r5, r3
    cmp/ge r7, r3
    bf      .L_inner_slot_loop
    add #0x1, r13
.L_outer_loop_test:
    extu.w r13, r3
    mov #0xE, r2
    cmp/ge r2, r3
    bf      .L_outer_loop_body
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06025136
DAT_06025136:
    .2byte  0x00B4
.L_pool_06025138:
    .4byte  sym_060610BC                /* render channel descriptor table: 14 entries x 12 bytes */
.L_pool_0602513C:
    .4byte  sym_06060F2C                /* scene output table A: 10 slots x 8 bytes */
.L_pool_06025140:
    .4byte  sym_06059094                /* render bitmask array A: 10 x 2-byte slot enable masks */
.L_pool_06025144:
    .4byte  sym_06060D7C                /* scene data table A: 14 entries x 8 bytes (ptr, data_ptr) */

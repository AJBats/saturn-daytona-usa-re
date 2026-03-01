
    .section .text.FUN_06041034


    .global buffer_slot_alloc
    .type buffer_slot_alloc, @function
buffer_slot_alloc:
    mov.l r14, @-r15
    mov #0x54, r0
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0604105C, r14
    mov.l @r14, r1
    mov.l @(r0, r1), r1
    mov.l @r14, r0
    add #0x18, r0
    mov.b @(r0, r4), r0
    cmp/eq #0x1, r0
    bt      .L_slot_active
    bra     .L_epilogue
    mov #-0x7, r0
.L_slot_active:
    mov #0x18, r2
    cmp/ge r2, r1
    bf      .L_capacity_ok
    bra     .L_epilogue
    mov #-0x8, r0
.L_pool_0604105C:
    .4byte  sym_060A5400
.L_capacity_ok:
    mov.l @r14, r2
    mov #0x58, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_dirty_already_set
    mov.l @r14, r3
    mov #0x1, r2
    mov #0x58, r0
    mov.l r2, @(r0, r3)
.L_dirty_already_set:
    mov r1, r13
    exts.b r4, r4
    exts.b r5, r5
    mov.l @r14, r2
    shll2 r13
    mov r5, r0
    add #0x5C, r2
    shll2 r13
    add r13, r2
    mov.b r4, @r2
    mov.l @r14, r2
    add #0x5C, r2
    add r13, r2
    mov.b r0, @(1, r2)
    mov r6, r2
    .byte   0xD3, 0x1A    /* mov.l .L_pool_060410FC, r3 */
    mov.l @r14, r1
    add #0x5C, r1
    add r13, r1
    add #0x2, r1
    jsr @r3
    mov #0x6, r0
    mov #0x54, r0
    mov.l @r14, r3
    add #0x5C, r3
    add r13, r3
    mov.l r7, @(8, r3)
    mov.l @r14, r3
    mov.l @(16, r15), r2
    add #0x5C, r3
    add r3, r13
    mov.l r2, @(12, r13)
    mov.l @r14, r3
    mov.l @(r0, r3), r2
    add #0x1, r2
    mov.l r2, @(r0, r3)
    .byte   0xB4, 0x00    /* bsr 0x060418BE (external) */
    mov r15, r4
    mov #0x0, r0
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .section .text.FUN_06020DD0


    .global obj_anim_advance
    .type obj_anim_advance, @function
obj_anim_advance:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov #0x10, r13
    mov #0x0, r14
.L_slot_loop:
    bsr     .L_clear_slot_anim
    extu.b r14, r4
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r13, r2
    bf      .L_slot_loop
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_clear_slot_anim:
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov.l   .L_pool_06020E38, r2
    add r2, r4
    mov #0x0, r5
    extu.b r5, r0
    mov.b r0, @(2, r4)
    mov.b r0, @(1, r4)
    mov.b r0, @r4
    mov.l r5, @(12, r4)
    mov r5, r3
    mov.l r5, @(8, r4)
    mov r3, r2
    mov.l r3, @(4, r4)
    mov.l r2, @(24, r4)
    mov.l r2, @(20, r4)
    mov.l r2, @(16, r4)
    mov.l r2, @(36, r4)
    mov.l r2, @(32, r4)
    mov.l r2, @(28, r4)
    mov.l r2, @(48, r4)
    mov.l r2, @(44, r4)
    mov.l r2, @(40, r4)
    mov.l r2, @(56, r4)
    mov.l r2, @(52, r4)
    mov #0x41, r0
    mov.b r2, @(r0, r4)
    mov #0x40, r0
    rts
    mov.b r2, @(r0, r4)
    .2byte  0xFFFF
.L_pool_06020E38:
    .4byte  sym_0608782C


    .section .text.FUN_0601712C


    .global vdp2_util_loop
    .type vdp2_util_loop, @function
vdp2_util_loop:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov #0x12, r11
    add #-0x58, r15
    mov r15, r12
    mov.l   .L_pool_060171A0, r13
    mov r15, r1
    mov.l   .L_pool_060171A4, r2
    mov.l   .L_pool_060171A8, r3
    jsr @r3
    mov #0x58, r0
    mov #0x0, r14
.L_slot_loop:
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bt      .L_skip_slot
    extu.b r14, r0
    mov r0, r3
    shll2 r0
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r0
    exts.w r0, r0
    mov.b @(r0, r13), r0
    extu.b r0, r0
    add #-0x1, r0
    shll2 r0
    mov.l @(r0, r12), r3
    jsr @r3
    mov r14, r4
.L_skip_slot:
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r11, r2
    bf      .L_slot_loop
    add #0x58, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .4byte  handler_dispatch
    .4byte  sym_06018E1E
.L_pool_060171A0:
    .4byte  sym_06084FC8
.L_pool_060171A4:
    .4byte  sym_0605BC14
.L_pool_060171A8:
    .4byte  sym_06035168

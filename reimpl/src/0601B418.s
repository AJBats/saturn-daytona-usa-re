	.text
    .global disc_load_complete_check
disc_load_complete_check:
    sts.l pr, @-r15
    mov.l   .L_pool_0601B468, r3
    mov.l   .L_pool_0601B46C, r2
    mov.b @r3, r3
    extu.b r3, r3
    shll2 r3
    add r2, r3
    mov.l @r3, r3
    jsr @r3
    nop
    mov.w   .L_wpool_0601B45A, r2
    mov.l r2, @-r15
    mov.l   .L_pool_0601B470, r3
    mov.l r3, @-r15
    mov.l   .L_pool_0601B474, r2
    mov.l r2, @-r15
    mov.l   .L_pool_0601B478, r7
    mov.l   .L_pool_0601B47C, r5
    mov.l   .L_pool_0601B480, r3
    mov r7, r6
    jsr @r3
    mov r5, r4
    mov.l   .L_pool_0601B484, r3
    jsr @r3
    add #0xC, r15
    mov.l   .L_pool_0601B488, r4
    mov.w @r4, r2
    add #0x1, r2
    mov.w r2, @r4
    mov.l   .L_pool_0601B45C, r0
    lds.l @r15+, pr
    rts
    mov.b @r0, r0
.L_wpool_0601B45A:
    .short  0x0101
.L_pool_0601B45C:
    .long  sym_0608600C
    .long  sym_0608600E
    .long  handler_dispatch
.L_pool_0601B468:
    .long  sym_0608600D
.L_pool_0601B46C:
    .long  sym_0605DEB4
.L_pool_0601B470:
    .long  0x00010000
.L_pool_0601B474:
    .long  0x00008000
.L_pool_0601B478:
    .long  0x00200000
.L_pool_0601B47C:
    .long  0x01000000
.L_pool_0601B480:
    .long  rigid_body_transform
.L_pool_0601B484:
    .long  frame_end_commit
.L_pool_0601B488:
    .long  sym_0605D4F8

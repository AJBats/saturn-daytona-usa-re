
    .section .text.FUN_0600A478


    .global FUN_0600A478
    .type FUN_0600A478, @function
FUN_0600A478:
    sts.l pr, @-r15
    shll2 r14
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_pool_0600A50C, r5
    mov.l   .L_pool_0600A510, r4
    mov.l   .L_0600A514, r3
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_pool_0600A518, r6
    add r14, r6
    mov.l @r6, r6
    mov.l   .L_pool_0600A51C, r5
    mov.w @r5, r5
    mov.l   .L_pool_0600A520, r4
    add r14, r4
    mov.l @r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_0600A524, r3
    jmp @r3
    mov.l @r15+, r14


    .global FUN_0600A4AA
    .type FUN_0600A4AA, @function
FUN_0600A4AA:
    sts.l pr, @-r15
    mov.l   .L_pool_0600A528, r5
    mov.l   .L_pool_0600A52C, r4
    mov.l   .L_0600A514, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_pool_0600A530, r6
    mov.l @r6, r6
    mov.l   .L_0600A534, r5
    mov.w @r5, r5
    mov.l   .L_pool_0600A538, r4
    mov.l @r4, r4
    mov.l   .L_0600A524, r3
    jmp @r3
    lds.l @r15+, pr

    .global FUN_0600A4CA
    .type FUN_0600A4CA, @function
FUN_0600A4CA:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov r4, r13
    mov.l   .L_0600A534, r8
    mov.l   .L_0600A53C, r9
    mov.l   .L_0600A524, r10
    mov.l   .L_0600A540, r11
    mov.l   .L_0600A514, r12
    mov.l   .L_0600A544, r0
    bra     .L_0600A594
    mov.l @r0, r0
.L_0600A4EC:
    mov r13, r14
    mov.l   .L_0600A548, r4
    shll2 r14
    add r14, r11
    add r14, r4
    mov.l @r11, r5
    jsr @r12
    mov.l @r4, r4
    add r14, r9
    mov.l @r9, r6
    mov r8, r5
    add #0x54, r5
    mov.l   .L_0600A54C, r4
    bra     .L_0600A58A
    mov.w @r5, r5
    .2byte  0xFFFF
.L_pool_0600A50C:
    .4byte  sym_060628C8
.L_pool_0600A510:
    .4byte  sym_06062874
.L_0600A514:
    .4byte  sym_06031D8C
.L_pool_0600A518:
    .4byte  sym_0606291C
.L_pool_0600A51C:
    .4byte  sym_06089E9E
.L_pool_0600A520:
    .4byte  sym_06062820
.L_0600A524:
    .4byte  sym_06031A28
.L_pool_0600A528:
    .4byte  sym_060621DC
.L_pool_0600A52C:
    .4byte  sym_06062130
.L_pool_0600A530:
    .4byte  sym_06062184
.L_0600A534:
    .4byte  sym_06089E44
.L_pool_0600A538:
    .4byte  sym_060620DC
.L_0600A53C:
    .4byte  sym_060634DC
.L_0600A540:
    .4byte  sym_060634F8
.L_0600A544:
    .4byte  sym_0607EAD8
.L_0600A548:
    .4byte  sym_06063488
.L_0600A54C:
    .4byte  sym_06063434
.L_0600A550:
    mov r13, r14
    mov.l   .L_pool_0600A5E8, r4
    shll2 r14
    add r14, r11
    add r14, r4
    mov.l @r11, r5
    jsr @r12
    mov.l @r4, r4
    add r14, r9
    mov.l @r9, r6
    mov r8, r5
    add #0x54, r5
    mov.l   .L_pool_0600A5EC, r4
    bra     .L_0600A58A
    mov.w @r5, r5
.L_0600A56E:
    mov r13, r14
    mov.l   .L_pool_0600A5F0, r4
    shll2 r14
    add r14, r11
    add r14, r4
    mov.l @r11, r5
    jsr @r12
    mov.l @r4, r4
    add r14, r9
    mov.l @r9, r6
    mov r8, r5
    add #0x54, r5
    mov.w @r5, r5
    mov.l   .L_pool_0600A5F4, r4
.L_0600A58A:
    add r14, r4
    jsr @r10
    mov.l @r4, r4
    bra     .L_0600A5A0
    nop
.L_0600A594:
    cmp/eq #0x0, r0
    bt      .L_0600A4EC
    cmp/eq #0x1, r0
    bt      .L_0600A550
    cmp/eq #0x2, r0
    bt      .L_0600A56E
.L_0600A5A0:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global FUN_0600A5B2
    .type FUN_0600A5B2, @function
FUN_0600A5B2:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    add #-0x4, r15
    shll2 r14
    mov.l r4, @r15
    mov.l   .L_pool_0600A5FF, r5
    mov.l   .L_pool_0600A603, r4
    mov.l   .L_pool_0600A607, r3
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_pool_0600A60B, r6
    add r14, r6
    mov.l @r6, r6
    mov.l   .L_pool_0600A60F, r5
    mov.w @r5, r5
    mov.l   .L_pool_0600A613, r4
    add r14, r4
    mov.l @r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_pool_0600A617, r3
    jmp @r3
    mov.l @r15+, r14
.L_pool_0600A5E8:
    .4byte  sym_060634A4
.L_pool_0600A5EC:
    .4byte  sym_06063450
.L_pool_0600A5F0:
    .4byte  sym_060634C0
.L_pool_0600A5F4:
    .4byte  sym_0606346C
.L_pool_0600A5FF:
    .4byte  sym_06063538
.L_pool_0600A603:
    .4byte  sym_06063520
.L_pool_0600A607:
    .4byte  sym_06031D8C
.L_pool_0600A60B:
    .4byte  sym_0606352C
.L_pool_0600A60F:
    .4byte  sym_06089E98
.L_pool_0600A613:
    .4byte  sym_06063514
.L_pool_0600A617:
    .4byte  sym_06031A28

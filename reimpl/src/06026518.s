	.text
    .global mat_multiply_basic
mat_multiply_basic:
    sts.l pr, @-r15
    extu.w r4, r0
    add #-0x4, r15
    tst #0x4, r0
    bt      .L_0602653E
    mov.l   .L_pool_0602657C, r7
    mov.w   .L_wpool_06026572, r6
    mov.w   .L_wpool_06026574, r5
    mov.l   .L_pool_06026580, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_0602657C, r7
    mov.w   .L_wpool_06026572, r6
    mov.w   DAT_06026576, r5
    mov #0x8, r4
    add #0x4, r15
    mov.l   .L_pool_06026580, r3
    jmp @r3
    lds.l @r15+, pr
.L_0602653E:
    mov.l   .L_pool_06026584, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_06026578, r3
    mov.w   .L_wpool_06026574, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_06026588, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_0602658C, r2
    mov.l r2, @r15
    mov r2, r7
    mov.l @(4, r7), r7
    mov.w   DAT_06026578, r3
    add r3, r7
    mov.w   DAT_06026576, r6
    mov r2, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    mov.l   .L_pool_06026588, r3
    jmp @r3
    lds.l @r15+, pr
.L_wpool_06026572:
    .short  0x0090
.L_wpool_06026574:
    .short  0x02A0

    .global DAT_06026576
DAT_06026576:
    .short  0x02B4

    .global DAT_06026578
DAT_06026578:
    .short  0x7000
    .short  0xFFFF
.L_pool_0602657C:
    .long  sym_06059128
.L_pool_06026580:
    .long  sym_060284AE
.L_pool_06026584:
    .long  sym_06063B80
.L_pool_06026588:
    .long  sym_06028400
.L_pool_0602658C:
    .long  sym_06063B88

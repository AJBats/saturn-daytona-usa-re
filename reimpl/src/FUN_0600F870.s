    .section .text.FUN_0600F870


    .global FUN_0600F870
    .type FUN_0600F870, @function
FUN_0600F870:
    sts.l pr, @-r15
    .byte   0xD3, 0x19    /* mov.l .L_pool_0600F8D8, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x18    /* mov.l .L_pool_0600F8DC, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x18    /* mov.l .L_pool_0600F8E0, r4 */
    mov.w @r4, r2
    add #-0x1, r2
    mov.w r2, @r4
    exts.w r2, r2
    cmp/pl r2
    bt      .L_0600F892
    mov #0x4, r2
    .byte   0xD3, 0x15    /* mov.l .L_pool_0600F8E4, r3 */
    mov.b r2, @r3
.L_0600F892:
    lds.l @r15+, pr
    rts
    nop


    .global FUN_0600F898
    .type FUN_0600F898, @function
FUN_0600F898:
    sts.l pr, @-r15
    .byte   0xD3, 0x13    /* mov.l .L_pool_0600F8E8, r3 */
    jsr @r3
    nop
    .byte   0x92, 0x18    /* mov.w .L_wpool_0600F8D4, r2 */
    .byte   0xD3, 0x12    /* mov.l .L_pool_0600F8EC, r3 */
    mov.l r2, @r3
    mov #0x14, r2
    mov.l   .L_pool_0600F8E2, r3
    mov.w r2, @r3
    mov #0x0, r2
    .byte   0xD3, 0x10    /* mov.l .L_pool_0600F8F0, r3 */
    mov.w r2, @r3
    .byte   0xD4, 0x0C    /* mov.l .L_pool_0600F8E4, r4 */
    lds.l @r15+, pr
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4


    .global FUN_0600F8BE
    .type FUN_0600F8BE, @function
FUN_0600F8BE:
    sts.l pr, @-r15
    mov.l   .L_pool_0600F8E2, r4
    mov.w @r4, r3
    add #-0x1, r3
    mov.w r3, @r4
    exts.w r3, r3
    cmp/pl r3
    bf      .L_0600F8F8
    mov.l   .L_pool_0600F8F6, r3
    jmp @r3
    lds.l @r15+, pr
    .4byte  0x0708FFFF
    .4byte  FUN_060114AC
    .4byte  FUN_06011094
.L_pool_0600F8E2:
    .4byte  sym_0607887C
    .4byte  sym_0607887F
    .4byte  sym_06028560
    .4byte  sym_0607EBCC
    .4byte  sym_0607886E
.L_pool_0600F8F6:
    .4byte  FUN_060115F0
.L_0600F8F8:
    .byte   0xD3, 0x19    /* mov.l .L_pool_0600F960, r3 */
    jsr @r3
    mov #0x4, r4
    .byte   0xD4, 0x19    /* mov.l .L_pool_0600F964, r4 */
    lds.l @r15+, pr
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4

    .global FUN_0600F90A
FUN_0600F90A:
    .byte   0xD4, 0x16    /* mov.l .L_pool_0600F964, r4 */
    mov.b @r4, r3
    add #0x1, r3
    rts
    mov.b r3, @r4

    .global FUN_0600F914
    .type FUN_0600F914, @function
FUN_0600F914:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0600F968, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600F96C, r3
    jsr @r3
    nop
    mov #0x0, r14
    mov.l   .L_pool_0600F970, r3
    extu.w r14, r2
    mov r14, r6
    mov.w r2, @r3
    mov #0x2, r3
    mov.l   .L_pool_0600F974, r1
    mov.w r3, @r1
    mov.l   .L_pool_0600F978, r2
    mov.l   .L_pool_0600F97C, r3
    mov.l r2, @r3
    mov r3, r5
    mov.l @r5, r5
    mov.l   .L_pool_0600F980, r3
    jsr @r3
    mov #0x10, r4
    mov.l   .L_pool_0600F984, r3
    jsr @r3
    nop
    mov #0x7, r2
    mov.l   .L_pool_0600F964, r3
    mov.b r2, @r3
    mov.l   .L_pool_0600F970, r3
    mov.w r14, @r3
    extu.w r14, r4
    lds.l @r15+, pr
    mov.l   .L_pool_0600F988, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
    .4byte  sym_0602853E
.L_pool_0600F964:
    .4byte  sym_0607887F
.L_pool_0600F968:
    .4byte  FUN_06011678                  /* sprite command table reset */
.L_pool_0600F96C:
    .4byte  FUN_06012080
.L_pool_0600F970:
    .4byte  sym_0607886E
.L_pool_0600F974:
    .4byte  sym_0605AAA2
.L_pool_0600F978:
    .4byte  0xFEA00000
.L_pool_0600F97C:
    .4byte  sym_0607885C
.L_pool_0600F980:
    .4byte  FUN_06014884
.L_pool_0600F984:
    .4byte  sym_06011450
.L_pool_0600F988:
    .4byte  FUN_0601155E

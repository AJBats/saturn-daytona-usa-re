
    .section .text.FUN_060416A8


    .global dma_int_handler
    .type dma_int_handler, @function
dma_int_handler:
    sts.l pr, @-r15
    mov #0x0, r9
    add #-0x14, r15
    mov.l   .L_06041730, r13
    mov.l r9, @r15
    mov.l @r13, r3
    mov.l @(60, r3), r0
    tst r0, r0
    bt/s    .L_060416D0
    mov r9, r12
    mov.l @r13, r3
    mov.l @(60, r3), r2
    add #-0x1, r2
    mov.l r2, @(60, r3)
    cmp/pl r2
    bt      .L_060416D0
    .byte   0xB6, 0x29    /* bsr 0x0604231E (external) */
    nop
    bra     .L_06041796
    mov #0x3, r0
.L_060416D0:
    mov.w   .L_0604172A, r2
    mov.l   .L_06041734, r3
    jsr @r3
    mov.l r2, @(4, r15)
    mov r0, r4
    mov.l @(4, r15), r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_060416E8
    bra     .L_060416EA
    mov #0x1, r5
.L_060416E8:
    mov #0x0, r5
.L_060416EA:
    mov r5, r0
    cmp/eq #0x1, r0
    bf      .L_06041748
    mov.l   .L_06041738, r4
    mov.l   .L_0604173C, r3
    jsr @r3
    nop
    mov r15, r4
    mov.l   .L_06041740, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov.l   .L_06041744, r3
    mov.l @r13, r1
    add #0x8, r2
    add #0x40, r1
    jsr @r3
    mov #0xC, r0
    mov.l @r13, r2
    mov #0x4C, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bt      .L_06041764
    mov.l @r13, r3
    mov #0x4C, r0
    mov r3, r4
    mov.l @(r0, r3), r2
    mov #0x50, r0
    jsr @r2
    mov.l @(r0, r4), r4
    bra     .L_06041764
    nop
.L_0604172A:
    .2byte  0x0400
    .4byte  ai_checkpoint_validate
.L_06041730:
    .4byte  sym_060A5400
.L_06041734:
    .4byte  sym_06035C4E
.L_06041738:
    .4byte  0x0000FBFF
.L_0604173C:
    .4byte  smpc_cmd_helper_b
.L_06041740:
    .4byte  ai_checkpoint_section
.L_06041744:
    .4byte  sym_06035168
.L_06041748:
    mov r15, r4
    mov.l   .L_060417E4, r3
    jsr @r3
    add #0x8, r4
    mov r0, r4
    tst r4, r4
    bf      .L_06041764
    mov.l @r13, r1
    mov r15, r2
    mov.l   .L_060417E8, r3
    add #0x40, r1
    add #0x8, r2
    jsr @r3
    mov #0xC, r0
.L_06041764:
    bra     .L_06041788
    mov r9, r14
.L_06041768:
    bsr     .L_060417A8
    mov r14, r4
    tst r0, r0
    bt      .L_06041774
    bra     .L_06041786
    nop
.L_06041774:
    mov r15, r5
    .byte   0xB0, 0x56    /* bsr 0x06041826 (external) */
    mov r14, r4
    add r0, r12
    mov.l @r15, r2
    cmp/gt r10, r2
    bf      .L_06041786
    bra     .L_06041796
    mov #0x1, r0
.L_06041786:
    add #0x1, r14
.L_06041788:
    cmp/ge r11, r14
    bf      .L_06041768
    cmp/pl r12
    bf      .L_06041794
    bra     .L_06041796
    mov #0x1, r0
.L_06041794:
    mov #0x0, r0
.L_06041796:
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_060417A8:
    mov.l   .L_060417EC, r5
    bra     .L_060417F8
    mov r4, r0
.L_060417AE:
    mov.l @r5, r4
    bra     .L_060417F4
    mov #0x58, r0
.L_060417B4:
    mov.w   DAT_060417d8, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417BA:
    mov.w   DAT_060417da, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417C0:
    mov.w   .L_060417DC, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417C6:
    mov.w   .L_060417DE, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417CC:
    mov.w   .L_060417E0, r0
    bra     .L_060417F4
    mov.l @r5, r4
.L_060417D2:
    mov.w   .L_060417E2, r0
    bra     .L_060417F4
    mov.l @r5, r4

    .global DAT_060417d8
DAT_060417d8:
    .2byte  0x0304

    .global DAT_060417da
DAT_060417da:
    .2byte  0x030C
.L_060417DC:
    .2byte  0x0328
.L_060417DE:
    .2byte  0x0338
.L_060417E0:
    .2byte  0x0348
.L_060417E2:
    .2byte  0x01E0
.L_060417E4:
    .4byte  cd_block_read_safe
.L_060417E8:
    .4byte  sym_06035168
.L_060417EC:
    .4byte  sym_060A5400
.L_060417F0:
    mov.l @r5, r4
    .byte   0x90, 0x34    /* mov.w .L_wpool_0604185E, r0 */
.L_060417F4:
    bra     .L_06041818
    mov.l @(r0, r4), r4
.L_060417F8:
    cmp/eq #0x0, r0
    bt      .L_060417AE
    cmp/eq #0x1, r0
    bt      .L_060417B4
    cmp/eq #0x2, r0
    bt      .L_060417BA
    cmp/eq #0x3, r0
    bt      .L_060417C0
    cmp/eq #0x4, r0
    bt      .L_060417C6
    cmp/eq #0x5, r0
    bt      .L_060417CC
    cmp/eq #0x6, r0
    bt      .L_060417D2
    cmp/eq #0x7, r0
    bt      .L_060417F0
.L_06041818:
    tst r4, r4
    bf      .L_06041820
    bra     .L_06041822
    mov #0x1, r0
.L_06041820:
    mov #0x0, r0
.L_06041822:
    rts
    nop

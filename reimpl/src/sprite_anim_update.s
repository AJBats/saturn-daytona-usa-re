
    .section .text.FUN_060266CC


    .global sprite_anim_update
    .type sprite_anim_update, @function
sprite_anim_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06026730, r10
    mov.l   .L_pool_06026734, r12
    mov.w   .L_wpool_06026728, r13
    mov.l   .L_pool_06026738, r14
    mov.w   DAT_0602672a, r8
    mov.l   .L_pool_0602673C, r7
    mov r13, r6
    mov r8, r5
    jsr @r12
    mov #0x8, r4
    mov r13, r6
    mov.w   DAT_0602672c, r9
    mov.l   .L_pool_06026740, r7
    mov r9, r5
    jsr @r12
    mov #0x8, r4
    mov.l   .L_pool_06026744, r11
    mov.w @r11, r11
    extu.w r11, r3
    tst r3, r3
    bf      .L_0602670C
    bra     .L_06026824
    nop
.L_0602670C:
    mov.l   .L_pool_06026748, r6
    extu.w r11, r3
    mov.w   DAT_0602672e, r2
    mov.l   .L_pool_0602674C, r4
    and r2, r3
    tst r3, r3
    bt/s    .L_06026784
    mov #0x6, r5
    mov.w @r14, r0
    extu.w r0, r0
    cmp/eq #0x12, r0
    bf      .L_06026750
    bra     .L_06026752
    mov #0x1, r3
.L_wpool_06026728:
    .2byte  0x0090                  /* display list size parameter */

    .global DAT_0602672a
DAT_0602672a:
    .2byte  0x0926                  /* OK text display list offset */

    .global DAT_0602672c
DAT_0602672c:
    .2byte  0x0A26                  /* CANCEL text display list offset */

    .global DAT_0602672e
DAT_0602672e:
    .2byte  0x0E00                  /* confirm button mask (A/B/C buttons) */
.L_pool_06026730:
    .4byte  sym_06059128            /* blank text "  " */
.L_pool_06026734:
    .4byte  sym_060284AE            /* geom_dispatch_final function */
.L_pool_06026738:
    .4byte  sym_06089EDA            /* game mode (word) */
.L_pool_0602673C:
    .4byte  sym_0605912C            /* "  OK" text string */
.L_pool_06026740:
    .4byte  sym_06059134            /* "CANCEL" text string */
.L_pool_06026744:
    .4byte  sym_06063D9A            /* button state register (word) */
.L_pool_06026748:
    .4byte  sym_06061198            /* animation state byte */
.L_pool_0602674C:
    .4byte  sym_06089ED8            /* palette copy pending flag (word) */
.L_06026750:
    mov #0x0, r3
.L_06026752:
    mov r10, r7
    mov.w r3, @r4
    mov.b r5, @r6
    mov r13, r6
    mov.w @r14, r5
    extu.w r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x11, r5
    shll r5
    jsr @r12
    mov #0x8, r4
    mov.l   .L_pool_06026850, r7
    mov r13, r6
    mov r8, r5
    jsr @r12
    mov #0x8, r4
    mov r13, r6
    mov r9, r5
    mov.l   .L_pool_06026854, r7
    jsr @r12
    mov #0x8, r4
    bra     .L_06026892
    nop
.L_06026784:
    extu.w r11, r3
    mov.w   .L_wpool_06026848, r2
    cmp/eq r2, r3
    bf      .L_060267C0
    mov #0x0, r2
    mov r10, r7
    mov.w r2, @r4
    mov.b r5, @r6
    mov r13, r6
    mov.w @r14, r5
    extu.w r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x11, r5
    shll r5
    jsr @r12
    mov #0x8, r4
    mov r13, r6
    mov r8, r5
    mov.l   .L_pool_06026850, r7
    jsr @r12
    mov #0x8, r4
    mov.l   .L_pool_06026854, r7
    mov r13, r6
    mov r9, r5
    jsr @r12
    mov #0x8, r4
    bra     .L_06026892
    nop
.L_060267C0:
    extu.w r11, r3
    mov.w   DAT_0602684a, r2
    cmp/eq r2, r3
    bf      .L_060267E4
    mov r10, r7
    mov r13, r6
    mov.w @r14, r5
    extu.w r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x11, r5
    shll r5
    jsr @r12
    mov #0x8, r4
    mov.w @r14, r3
    add #-0x2, r3
    mov.w r3, @r14
.L_060267E4:
    extu.w r11, r11
    mov.w   .L_wpool_0602684C, r2
    cmp/eq r2, r11
    bf      .L_06026808
    mov r10, r7
    mov r13, r6
    mov.w @r14, r5
    extu.w r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x11, r5
    shll r5
    jsr @r12
    mov #0x8, r4
    mov.w @r14, r3
    add #0x2, r3
    mov.w r3, @r14
.L_06026808:
    mov.w @r14, r2
    mov #0x14, r3
    extu.w r2, r2
    cmp/gt r3, r2
    bf      .L_06026816
    mov #0x12, r3
    mov.w r3, @r14
.L_06026816:
    mov #0x12, r3
    mov.w @r14, r2
    extu.w r2, r2
    cmp/ge r3, r2
    bt      .L_06026824
    mov #0x14, r3
    mov.w r3, @r14
.L_06026824:
    mov.l   .L_pool_06026858, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst #0x4, r0
    bt      .L_0602685C
    mov r10, r7
    mov r13, r6
    mov.w @r14, r5
    extu.w r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x11, r5
    shll r5
    jsr @r12
    mov #0x8, r4
    bra     .L_06026892
    nop
.L_wpool_06026848:
    .2byte  0x0100                  /* accept/start button exact match */

    .global DAT_0602684a
DAT_0602684a:
    .2byte  0x1000                  /* scroll-up button mask */
.L_wpool_0602684C:
    .2byte  0x2000                  /* scroll-down button mask */
    .2byte  0xFFFF                  /* pool alignment padding */
.L_pool_06026850:
    .4byte  sym_0605913C            /* blank text "    " (clears OK slot) */
.L_pool_06026854:
    .4byte  sym_06059144            /* blank text "      " (clears CANCEL slot) */
.L_pool_06026858:
    .4byte  sym_06089EC6            /* slot count (word) */
.L_0602685C:
    mov.l   .L_pool_060268A8, r2
    mov.l r2, @r15
    mov r2, r7
    mov.w   DAT_060268a6, r3
    mov.w @r14, r6
    mov.l @(4, r7), r7
    extu.w r6, r6
    add r3, r7
    shll2 r6
    shll2 r6
    shll2 r6
    add #0x11, r6
    shll r6
    mov r2, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_pool_060268AC, r3
    jmp @r3
    mov.l @r15+, r14
.L_06026892:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_060268a6
DAT_060268a6:
    .2byte  0x7000                  /* VRAM base offset for dlist copy */
.L_pool_060268A8:
    .4byte  sym_06063B88            /* display list entry struct */
.L_pool_060268AC:
    .4byte  sym_06028400            /* display_list_loader function */

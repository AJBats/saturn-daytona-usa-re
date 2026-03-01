
    .section .text.FUN_06020814


    .global obj_culling_pass
    .type obj_culling_pass, @function
obj_culling_pass:
    mov.l r14, @-r15
    mov r4, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06020900, r3
    jsr @r3
    mov.b r0, @(4, r15)
    mov.l   .L_06020904, r3
    jsr @r3
    nop
    mov.l   .L_06020908, r5
    mov.l   .L_0602090C, r4
    mov.l   .L_06020910, r3
    jsr @r3
    mov #0x20, r6
    mov.l   .L_06020914, r13
    mov.l   .L_06020918, r14
    mov.w   .L_060208E6, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_060208E8, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r14
    mov #0x0, r4
    mov #0x0, r11
    mov.l   .L_0602091C, r12
    mov.l   .L_06020920, r3
    mov.l @r12, r2
    or r3, r2
    mov.l r2, @r12
    mov #0x1, r3
    mov.l   .L_06020924, r2
    mov.w r3, @r2
    mov.l   .L_06020928, r3
    mov.l r11, @r3
    mov.l   .L_0602092C, r3
    jsr @r3
    nop
    mov.l   .L_06020920, r2
    mov.l @r12, r3
    or r2, r3
    mov.l r3, @r12
    mov #0x3, r2
    mov.l   .L_06020924, r3
    mov.w r2, @r3
    mov.l   .L_06020928, r3
    mov.l r11, @r3
    mov.l   .L_0602092C, r3
    jsr @r3
    nop
    mov.w   .L_060208EA, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_060208EC, r3
    mov.w   .L_060208EE, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x4, r4
    mov.w   .L_060208F0, r7
    mov.w   .L_060208F2, r6
    mov.l   .L_06020930, r5
    jsr @r14
    mov #0x4, r4
    mov.w   .L_060208F4, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_060208F6, r3
    mov.w   .L_060208F8, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x4, r4
    mov.w   .L_060208FA, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_060208FC, r3
    mov.w   .L_060208FE, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x4, r4
    mov.l   .L_06020934, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_06020938, r3
    mov.w r11, @r3
    mov.b @(4, r15), r0
    mov r0, r4
    extu.b r4, r4
    add #0x8, r15
    lds.l @r15+, pr
    bra     .L_0602093C
    nop
.L_060208E6:
    .2byte  0x0560                          /* struct offset: display list B ptr */
.L_060208E8:
    .2byte  0x0294                          /* copy length for list B */
.L_060208EA:
    .2byte  0x0550                          /* struct offset: display list C ptr */
.L_060208EC:
    .2byte  0x6000                          /* size adjustment for list C */
.L_060208EE:
    .2byte  0x0082                          /* copy length for list C */
.L_060208F0:
    .2byte  0x7C5A                          /* fixed display list address */
.L_060208F2:
    .2byte  0x061A                          /* copy length for fixed list */
.L_060208F4:
    .2byte  0x0368                          /* struct offset: display list D ptr */
.L_060208F6:
    .2byte  0x3000                          /* size adjustment for list D */
.L_060208F8:
    .2byte  0x0898                          /* copy length for list D */
.L_060208FA:
    .2byte  0x0378                          /* struct offset: display list E ptr */
.L_060208FC:
    .2byte  0x4000                          /* size adjustment for list E */
.L_060208FE:
    .2byte  0x08B0                          /* copy length for list E */
.L_06020900:
    .4byte  sym_06028560                    /* render state commit / clear */
.L_06020904:
    .4byte  gameover_channel_setup          /* game-over display channel setup */
.L_06020908:
    .4byte  sym_060489CC                    /* palette source for CRAM +0x200 */
.L_0602090C:
    .4byte  0x25F00200                      /* VDP2 color RAM +0x200 */
.L_06020910:
    .4byte  memcpy_word_idx                 /* word-indexed memcpy */
.L_06020914:
    .4byte  sym_06063750                    /* obj/replay struct base ptr */
.L_06020918:
    .4byte  sym_06028400                    /* display list copy function */
.L_0602091C:
    .4byte  sym_0605B6D8                    /* display/event flags (32-bit) */
.L_06020920:
    .4byte  0x04000000                      /* bit 26 mask — collision update trigger */
.L_06020924:
    .4byte  sym_0608780C                    /* display timer (16-bit word) */
.L_06020928:
    .4byte  sym_0605A00C                    /* frame-ready flag (0 = not ready) */
.L_0602092C:
    .4byte  sym_06026CE0                    /* display update / render commit */
.L_06020930:
    .4byte  sym_0604BBCC                    /* fixed display list source data */
.L_06020934:
    .4byte  sym_0602853E                    /* display layer fill config */
.L_06020938:
    .4byte  sym_06087828                    /* obj animation mode (16-bit word) */
.L_0602093C:
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA2, 0x54    /* bra 0x06020DEE (external) */
    mov.l @r15+, r14

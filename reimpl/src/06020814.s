	.text
    .global obj_culling_pass
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
    .short  0x0560
.L_060208E8:
    .short  0x0294
.L_060208EA:
    .short  0x0550
.L_060208EC:
    .short  0x6000
.L_060208EE:
    .short  0x0082
.L_060208F0:
    .short  0x7C5A
.L_060208F2:
    .short  0x061A
.L_060208F4:
    .short  0x0368
.L_060208F6:
    .short  0x3000
.L_060208F8:
    .short  0x0898
.L_060208FA:
    .short  0x0378
.L_060208FC:
    .short  0x4000
.L_060208FE:
    .short  0x08B0
.L_06020900:
    .long  sym_06028560
.L_06020904:
    .long  gameover_channel_setup
.L_06020908:
    .long  sym_060489CC
.L_0602090C:
    .long  0x25F00200
.L_06020910:
    .long  memcpy_word_idx
.L_06020914:
    .long  sym_06063750
.L_06020918:
    .long  sym_06028400
.L_0602091C:
    .long  sym_0605B6D8
.L_06020920:
    .long  0x04000000
.L_06020924:
    .long  sym_0608780C
.L_06020928:
    .long  sym_0605A00C                    /* frame-ready flag (0 = not ready) */
.L_0602092C:
    .long  sym_06026CE0
.L_06020930:
    .long  sym_0604BBCC
.L_06020934:
    .long  sym_0602853E
.L_06020938:
    .long  sym_06087828
.L_0602093C:
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA2, 0x54    /* bra 0x06020DEE (external) */
    mov.l @r15+, r14


    .section .text.FUN_060121A8


    .global race_cleanup_handler
    .type race_cleanup_handler, @function
race_cleanup_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06012224, r14
    mov.l @r14, r3
    add #0x1, r3
    mov r3, r2
    mov.l r3, @r14
    mov #0x14, r3
    cmp/ge r3, r2
    bt      .L_060121DC
    mov.l   .L_pool_06012228, r3
    mov.l r3, @r15
    mov r3, r7
    mov.w   .L_wpool_06012218, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    mov.l   .L_pool_0601222C, r3
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_06012230, r3
    jsr @r3
    mov #0x8, r4
    .byte   0xB1, 0xFA    /* bsr 0x060125D0 (external) */
    nop
.L_060121DC:
    mov.l @r14, r0
    cmp/eq #0x14, r0
    bf      .L_0601224C
    mov.l   .L_pool_06012234, r5
    mov.l   .L_pool_06012238, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_pool_0601223C, r13
    mov.w   .L_wpool_0601221A, r6
    mov.w   .L_wpool_06012218, r5
    mov.l   .L_pool_06012240, r3
    mov r13, r7
    jsr @r3
    mov #0x8, r4
    mov r13, r7
    mov.w   .L_wpool_0601221A, r6
    mov.w   .L_wpool_0601221C, r5
    mov.l   .L_pool_06012240, r3
    jsr @r3
    mov #0x8, r4
    mov r13, r7
    mov.l   .L_06012244, r6
    mov.w   .L_wpool_0601221E, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_pool_06012248, r3
    jmp @r3
    mov.l @r15+, r14
.L_wpool_06012218:
    .2byte  0x0390
.L_wpool_0601221A:
    .2byte  0x0090
.L_wpool_0601221C:
    .2byte  0x0490
.L_wpool_0601221E:
    .2byte  0x0590
    .4byte  sym_0607EAD8
.L_pool_06012224:
    .4byte  sym_060788AC
.L_pool_06012228:
    .4byte  sym_06063AF0
.L_pool_0601222C:
    .4byte  0x0000B000
.L_pool_06012230:
    .4byte  sym_06028400
.L_pool_06012234:
    .4byte  0xAE110EFF
.L_pool_06012238:
    .4byte  sound_cmd_dispatch              /* sound command dispatch function */
.L_pool_0601223C:
    .4byte  sym_0605ACF0
.L_pool_06012240:
    .4byte  sym_060284AE
.L_06012244:
    .4byte  0x0000E000
.L_pool_06012248:
    .4byte  sym_060283E0
.L_0601224C:
    mov.l @r14, r2
    mov #0x28, r3
    cmp/gt r3, r2
    bf      .L_0601226A
    mov #0x0, r3
    .byte   0xD2, 0x1D    /* mov.l .L_pool_060122CC, r2 */
    mov.b r3, @r2
    .byte   0xD5, 0x1D    /* mov.l .L_pool_060122D0, r5 */
    mov r3, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xD3, 0x1B    /* mov.l .L_pool_060122D4, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_0601226A:
    mov #0x14, r3
    mov.l @r14, r2
    cmp/gt r3, r2
    bf      .L_06012280
    .byte   0xB0, 0x67    /* bsr 0x06012344 (external) */
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xA0, 0xC0    /* bra 0x06012400 (external) */
    mov.l @r15+, r14
.L_06012280:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

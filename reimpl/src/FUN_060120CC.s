
    .section .text.FUN_060120CC


    .global FUN_060120CC
    .type FUN_060120CC, @function
FUN_060120CC:
    sts.l pr, @-r15
    mov #0x0, r14
    mov.l   .L_pool_06012150, r2
    mov r14, r6
    mov r14, r5
    mov.b r3, @r2
    mov.l   .L_pool_06012154, r3
    mov.l r14, @r3
    mov.l   .L_pool_06012158, r3
    jsr @r3
    mov #0x20, r4
    mov.l   .L_pool_0601215C, r4
    mov.l r14, @r4
    mov.l   .L_06012160, r2
    mov.l r2, @(4, r4)
    shlr2 r2
    mov.l   .L_pool_06012164, r3
    mov.l r3, @(8, r4)
    mov.l   .L_pool_06012168, r4
    mov.l r14, @r4
    mov.l r2, @(4, r4)
    mov r4, r2
    mov.l   .L_pool_0601216C, r3
    mov.l r3, @(8, r4)
    mov.l   .L_pool_06012170, r1
    mov.l   .L_pool_06012174, r3
    jsr @r3
    mov #0xC, r0
    mov.l   .L_pool_06012178, r1
    mov.l   .L_pool_06012174, r3
    jsr @r3
    mov #0xC, r0
    mov.l   .L_pool_0601217C, r1
    mov.l   .L_pool_06012174, r3
    jsr @r3
    mov #0xC, r0
    mov.w   DAT_0601214e, r2
    extu.b r14, r1
    mov.l   .L_pool_06012180, r3
    mov.w r2, @r3
    exts.w r14, r2
    mov.l   .L_pool_06012184, r3
    mov.w r2, @r3
    mov.l   .L_pool_06012188, r3
    mov.b r1, @r3
    mov.l   .L_pool_0601218C, r5
    mov.l   .L_pool_06012190, r4
    mov.l   .L_pool_06012194, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601213A
    mov #0x3C, r3
    mov.l r3, @r4
    bra     .L_06012148
    mov.l r14, @r5
.L_0601213A:
    mov #0x1, r2
    mov.l r2, @r4
    mov #0x14, r3
    mov.l r3, @r5
    lds.l @r15+, pr
    bra     FUN_0601228A
    mov.l @r15+, r14
.L_06012148:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0601214e
DAT_0601214e:
    .2byte  0x1000
.L_pool_06012150:
    .4byte  sym_06078636
.L_pool_06012154:
    .4byte  sym_060788F8
.L_pool_06012158:
    .4byte  FUN_06014884
.L_pool_0601215C:
    .4byte  sym_060788B4
.L_06012160:
    .4byte  0x00080000
.L_pool_06012164:
    .4byte  0x000F3333
.L_pool_06012168:
    .4byte  sym_060788C0
.L_pool_0601216C:
    .4byte  0x00053333
.L_pool_06012170:
    .4byte  sym_060788CC
.L_pool_06012174:
    .4byte  sym_06035168
.L_pool_06012178:
    .4byte  sym_060788D8
.L_pool_0601217C:
    .4byte  sym_060788E4
.L_pool_06012180:
    .4byte  sym_060788B0
.L_pool_06012184:
    .4byte  sym_060788B2
.L_pool_06012188:
    .4byte  sym_060788F0
.L_pool_0601218C:
    .4byte  sym_060788F4
.L_pool_06012190:
    .4byte  sym_060788AC
.L_pool_06012194:
    .4byte  sym_0607EAD8

    .global sym_06012198
sym_06012198:
    .byte   0xD0, 0x21    /* mov.l .L_pool_06012220, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_060121A4
    bra     FUN_0601228A
    nop
.L_060121A4:
    .reloc ., R_SH_IND12W, FUN_060127E0 - 4
    .2byte 0xA000    /* bra FUN_060127E0 (linker-resolved) */
    nop


    .global FUN_060121A8
    .type FUN_060121A8, @function
FUN_060121A8:
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
    .reloc ., R_SH_IND12W, FUN_060125D0 - 4
    .2byte 0xB000    /* bsr FUN_060125D0 (linker-resolved) */
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
    .4byte  FUN_0601D5F4              /* sound command dispatch function */
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
    .reloc ., R_SH_IND12W, FUN_06012344 - 4
    .2byte 0xB000    /* bsr FUN_06012344 (linker-resolved) */
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_06012400 - 4
    .2byte 0xA000    /* bra FUN_06012400 (linker-resolved) */
    mov.l @r15+, r14
.L_06012280:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0601228A
    .type FUN_0601228A, @function
FUN_0601228A:
    mov #0x6E, r2

    .global FUN_0601228C
    .type FUN_0601228C, @function

FUN_0601228C:
    sts.l pr, @-r15
    mov.l   .L_pool_060122D8, r4
    mov.l @r4, r3
    cmp/ge r2, r3
    bf      .L_060122A2
    bsr     FUN_060122F4
    nop
    .reloc ., R_SH_IND12W, FUN_0601250C - 4
    .2byte 0xB000    /* bsr FUN_0601250C (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_06012710 - 4
    .2byte 0xA000    /* bra FUN_06012710 (linker-resolved) */
    lds.l @r15+, pr
.L_060122A2:
    mov #0x64, r3
    mov.l   .L_pool_060122DC, r6
    mov.l @r4, r2
    cmp/ge r3, r2
    bf/s    .L_060122B8
    mov #0x0, r5
    exts.w r5, r5
    .reloc ., R_SH_IND12W, FUN_0601250C - 4
    .2byte 0xB000    /* bsr FUN_0601250C (linker-resolved) */
    mov.w r5, @r6
    .reloc ., R_SH_IND12W, FUN_06012710 - 4
    .2byte 0xA000    /* bra FUN_06012710 (linker-resolved) */
    lds.l @r15+, pr
.L_060122B8:
    mov.l @r4, r2
    mov #0x28, r3
    cmp/ge r3, r2
    bf      .L_060122E0
    exts.w r5, r5
    .reloc ., R_SH_IND12W, FUN_060125D0 - 4
    .2byte 0xB000    /* bsr FUN_060125D0 (linker-resolved) */
    mov.w r5, @r6
    .reloc ., R_SH_IND12W, FUN_06012710 - 4
    .2byte 0xA000    /* bra FUN_06012710 (linker-resolved) */
    lds.l @r15+, pr
    .2byte  0xFFFF
    .4byte  sym_06078636
    .4byte  0xAE110FFF
    .4byte  FUN_0601D5F4
.L_pool_060122D8:
    .4byte  sym_0607EBCC
.L_pool_060122DC:
    .4byte  sym_060788B2
.L_060122E0:
    mov #0x1, r5
    mov #0x10, r2
    mov.l r5, @r4
    exts.b r5, r5
    .byte   0xD3, 0x10    /* mov.l .L_pool_0601232C, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x10    /* mov.l .L_pool_06012330, r3 */
    lds.l @r15+, pr
    rts
    mov.b r5, @r3

    .global FUN_060122F4
    .type FUN_060122F4, @function

FUN_060122F4:
    mov.l   .L_06012334, r4
    mov.w   .L_06012326, r3
    mov.l @(4, r4), r2
    sub r3, r2
    mov.l r2, @(4, r4)
    mov.w   .L_06012328, r3
    mov.l @(8, r4), r2
    sub r3, r2
    mov.l r2, @(8, r4)
    mov.l   .L_06012338, r5
    mov.l @(4, r4), r3
    cmp/ge r5, r3
    bt      .L_06012310
    mov.l r5, @(4, r4)
.L_06012310:
    mov.l   .L_0601233C, r5
    mov.l @(8, r4), r3
    cmp/ge r5, r3
    bt      .L_0601231A
    mov.l r5, @(8, r4)
.L_0601231A:
    mov.l   .L_06012340, r5
    mov.w   .L_0601232A, r3
    mov.w @r5, r2
    add r3, r2
    rts
    mov.w r2, @r5
.L_06012326:
    .2byte  0x2999
.L_06012328:
    .2byte  0x4000
.L_0601232A:
    .2byte  0x1800
.L_0601232C:
    .4byte  FUN_0605ACC4
.L_06012330:
    .4byte  sym_06078636
.L_06012334:
    .4byte  sym_060788B4
.L_06012338:
    .4byte  0x00020000
.L_0601233C:
    .4byte  0x0004CCCC
.L_06012340:
    .4byte  sym_060788B2

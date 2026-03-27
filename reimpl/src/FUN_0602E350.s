
    .section .text.FUN_0602E350


    .global FUN_0602E350
    .type FUN_0602E350, @function
FUN_0602E350:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E380, r0
    mov.l @r0, r0
    mov.w   .L_wpool_0602E374, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602e376, r1
    mov.l r3, @(r0, r1)
    mov.w   .L_wpool_0602E378, r1
    mov.l @(r0, r1), r3
    mov.l   .L_pool_0602E39C, r4
    cmp/gt r3, r4
    bt      .L_0602E36E
.L_0602E36E:
    bra     .L_0602E3F4
    nop

    .global DAT_0602e372
DAT_0602e372:
    clrmac
.L_wpool_0602E374:
    .2byte  0x0030

    .global DAT_0602e376
DAT_0602e376:
    .2byte  0x0020
.L_wpool_0602E378:
    .2byte  0x0008
    .2byte  0x0000
    .4byte  FUN_0601D5F4
.L_pool_0602E380:
    .4byte  sym_0607E940
    .4byte  sym_0602E450
    .4byte  sym_0602E4BC
    .4byte  FUN_0600CE66
    .4byte  0x00000000
    .4byte  sym_0603053C
    .4byte  FUN_0600D780
.L_pool_0602E39C:
    .4byte  0x00000096
    .global FUN_0602E3A0
FUN_0602E3A0:
    .4byte  0xD10BD30C
    .4byte  0x2132D10C
    .4byte  0x6212D10C
    .4byte  0x2122D10C
    .4byte  0xD20C2122
    .4byte  0xD10C9308
    .4byte  0x2132D30C
    .4byte  0xD10C0136
    .4byte  0x93039103
    .4byte  0x0136AF19
    .4byte  0x00090000
    .4byte  0x01B40000
    .4byte  sym_0605A1D0
    .4byte  0x00010000
    .4byte  sym_06082A34
    .4byte  sym_06063E20
    .4byte  sym_06082A30
    .4byte  0x00000000
    .4byte  sym_0605A1C4
    .4byte  0x00000001
    .4byte  sym_0607EAC8
.L_0602E3F4:
    mov.l   .L_pool_0602E414, r1
    mov.l @r1, r3
    mov.l   .L_pool_0602E418, r4
    cmp/gt r3, r4
    .byte   0x89, 0x1C    /* bt 0x0602E438 (external) */
    mov.l   .L_pool_0602E41C, r2
    mov.b @r2, r2
    mov.l   .L_pool_0602E420, r1
    and r1, r2
    tst r2, r2
    bt      .L_0602E42C
    mov.l   .L_pool_0602E424, r0
    mov.l   .L_pool_0602E428, r1
    mov.b r1, @r0
    bra     FUN_0602E438
    nop
.L_pool_0602E414:
    .4byte  sym_06082A2C
.L_pool_0602E418:
    .4byte  0x00000028
.L_pool_0602E41C:
    .4byte  sym_06082A25
.L_pool_0602E420:
    .4byte  0x00000004
.L_pool_0602E424:
    .4byte  sym_06082A26
.L_pool_0602E428:
    .4byte  0x00000000
.L_0602E42C:
    .byte   0xDD, 0x07    /* mov.l .L_pool_0602E44C, r13 */


    .global FUN_0602E42E
    .type FUN_0602E42E, @function
FUN_0602E42E:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .global FUN_0602E438
FUN_0602E438:
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    rts
    nop
    .2byte  0x0000
    .4byte  FUN_0603226C

    .global sym_0602E450
sym_0602E450:
    mov r0, r14
    mov.w   DAT_0602e460, r1
    mov.w @(r0, r1), r2
    mov #0x0, r1
    cmp/eq r1, r2
    .byte   0x89, 0x02    /* bt 0x0602E462 (external) */
    .reloc ., R_SH_IND12W, FUN_0602D924 - 4
    .2byte 0xA000    /* bra FUN_0602D924 (linker-resolved) */
    nop

    .global DAT_0602e460
DAT_0602e460:
    .2byte  0x0250

    .global FUN_0602E462
    .type FUN_0602E462, @function
FUN_0602E462:
    sts.l pr, @-r15
    neg r4, r4
    mov r4, r7
    mov.l @(12, r0), r3
    mov r3, r9
    mov.l @(16, r0), r5
    mov.l @(24, r0), r6
    mov.l r5, @(56, r0)
    mov.l r6, @(60, r0)
    mov.l   .L_pool_0602E4B0, r0
    jsr @r0
    nop
    mov r0, r8
    mov r7, r4
    mov.l   .L_pool_0602E4B4, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    mov r14, r0
    mov.l   .L_pool_0602E4B8, r10
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    mov.l r3, @(r0, r10)
    add r3, r5
    mov.l r5, @(16, r0)
    dmuls.l r8, r9
    mov.l   .L_pool_0602E4BC, r10
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    mov.l r9, @(r0, r10)
    add r9, r6
    mov.l r6, @(24, r0)
    lds.l @r15+, pr
    rts
    nop
.L_pool_0602E4B0:
    .4byte  FUN_06027344
.L_pool_0602E4B4:
    .4byte  FUN_06027348
.L_pool_0602E4B8:
    .4byte  0x0000018C
.L_pool_0602E4BC:
    .4byte  0x00000190

    .global sym_0602E4BC
sym_0602E4BC:
    .byte   0x91, 0x2D    /* mov.w .L_wpool_0602E51A, r1 */
    mov.l @(r0, r1), r9
    shll2 r9
    .byte   0xD1, 0x19    /* mov.l .L_pool_0602E528, r1 */
    mov.l @r1, r3
    .byte   0xD4, 0x19    /* mov.l .L_pool_0602E52C, r4 */
    shll2 r3
    add r3, r4
    mov.l @r4, r4
    shll2 r9
    add r9, r4
    mov r4, r10
    .byte   0x91, 0x22    /* mov.w .L_wpool_0602E51C, r1 */
    add r10, r1
    mov.l @r1, r5
    .byte   0x91, 0x20    /* mov.w .L_wpool_0602E51E, r1 */
    add r10, r1
    mov.l @r1, r6
    .byte   0x91, 0x1E    /* mov.w .L_wpool_0602E520, r1 */
    mov.l @(r0, r1), r7
    .byte   0x91, 0x1D    /* mov.w .L_wpool_0602E522, r1 */
    mov.l @(r0, r1), r8
    mov.l r0, @-r15
    mov r5, r4
    sub r7, r4
    mov r6, r5
    sub r8, r5
    .byte   0xD0, 0x0F    /* mov.l .L_pool_0602E530, r0 */

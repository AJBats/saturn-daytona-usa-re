
    .section .text.FUN_06015754


    .global FUN_06015754
    .type FUN_06015754, @function
FUN_06015754:
    sts.l pr, @-r15
    mov r4, r3
    mov.l   .L_060157C8, r13
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(16, r4), r2
    mov.l @(4, r4), r3
    add r2, r3
    mov.l r3, @(4, r4)
    mov.l @(20, r4), r2
    mov.l @(8, r4), r3
    add r2, r3
    mov.l r3, @(8, r4)
    mov.l @(24, r4), r2
    mov.l @(12, r4), r3
    add r2, r3
    mov.l r3, @(12, r4)
    extu.b r14, r4
    mov r4, r0
    cmp/eq #0x1, r0
    .word 0x0029
    mov r0, r3
    mov r4, r0
    cmp/eq #0x3, r0
    .word 0x0129
    or r1, r3
    tst r3, r3
    bt      .L_060157CC
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(4, r4), r2
    mov.l @(52, r4), r3
    cmp/ge r3, r2
    bf      .L_060157FC
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    bra     .L_060157FC
    mov.l r2, @(4, r4)
.L_060157C8:
    .4byte  sym_06084FC8
.L_060157CC:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(4, r4), r2
    mov.l @(52, r4), r3
    cmp/gt r3, r2
    bt      .L_060157FC
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    mov.l r2, @(4, r4)
.L_060157FC:
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(8, r3), r3
    cmp/pz r3
    bf      .L_0601582A
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov #0x0, r1
    mov.l r1, @(8, r3)
.L_0601582A:
    extu.b r14, r3
    mov.l   .L_060158A8, r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(12, r3), r3
    cmp/ge r4, r3
    bf      .L_06015858
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l r4, @(12, r3)
.L_06015858:
    mov.l   .L_060158AC, r3
    jsr @r3
    extu.b r14, r4
    extu.b r14, r4
    mov #0x41, r0
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.b @(r0, r4), r2
    add #-0x1, r2
    mov.b r2, @(r0, r4)
    mov.b @(r0, r4), r3
    extu.b r3, r3
    cmp/pl r3
    bt      .L_0601589C
    extu.b r14, r14
    mov r14, r2
    shll2 r14
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r14
    exts.w r14, r14
    add r13, r14
    mov.b @(2, r14), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    mov.b r0, @(2, r14)
.L_0601589C:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global FUN_060158A4
FUN_060158A4:
    rts
    nop
.L_060158A8:
    .4byte  0x00010000
.L_060158AC:
    .4byte  FUN_06016DD8

    .global FUN_060158B0
FUN_060158B0:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l   .L_06015934, r1
    add r1, r3
    mov.b @(2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    .byte   0xD2, 0x19    /* mov.l .L_pool_06015938, r2 */
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15


    .global FUN_060158DE
    .type FUN_060158DE, @function
FUN_060158DE:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    mov.l   .L_0601593C, r0
    mov.l @r0, r0
    tst r0, r0
    bt/s    .L_060158F8
    mov #0x1, r4
    exts.w r4, r4
    mov.l   .L_06015940, r3
    mov.w r4, @r3
    bra     .L_06015926
    nop
.L_060158F8:
    mov.b @r15, r2
    extu.b r4, r0
    mov.l   .L_06015934, r1
    extu.b r2, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r1, r2
    mov.b r0, @(1, r2)
    mov.l   .L_06015944, r5
    mov.w   .L_06015932, r0
    mov.l   .L_06015948, r3
    mov.l   .L_0601594C, r2
    mov.l @(r0, r5), r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    jsr @r2
    mov #0x0, r4
.L_06015926:
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    mov.l   .L_06015950, r3
    jmp @r3
    lds.l @r15+, pr
.L_06015932:
    .2byte  0x0224
.L_06015934:
    .4byte  sym_06084FC8
    .4byte  sym_0605B8A4
.L_0601593C:
    .4byte  sym_0607EAE0
.L_06015940:
    .4byte  sym_06085F94
.L_06015944:
    .4byte  sym_06078900
.L_06015948:
    .4byte  sym_06044BD8
.L_0601594C:
    .4byte  FUN_0601D5F4         /* sound command dispatch */
.L_06015950:
    .4byte  sym_060172E4


    .section .text.FUN_0602F214


    .global FUN_0602F214
    .type FUN_0602F214, @function
FUN_0602F214:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov r0, r1
    shlr16 r1
    mov r14, r0
    mov.l r1, @(r0, r8)
    .global FUN_0602F224
FUN_0602F224:
    mov.w   DAT_0602f24e, r1
    mov.l @(r0, r1), r4
    mov.w   DAT_0602f24c, r1
    mov.l @(r0, r1), r5
    mov.w   .L_wpool_0602F250, r1
    mov.l @(r0, r1), r6
    add r6, r5
    sub r4, r5
    mov.w @(r0, r9), r3
    shll r3
    shll2 r3
    mov.l   .L_pool_0602F25C, r7
    add r3, r7
    mov.l @r7, r1
    mov.l @(0x4, r7), r2
    cmp/gt r1, r5
    bt      .L_0602F260
    mov r1, r5
    bra     .L_0602F266
    nop

    .global DAT_0602f24c
DAT_0602f24c:
    .2byte  0x00E0

    .global DAT_0602f24e
DAT_0602f24e:
    .2byte  0x00E4
.L_wpool_0602F250:
    .2byte  0x00C0
    .2byte  0x0000
    .4byte  sym_060477CC                 /* [MEDIUM] course speed table (shared pool, not referenced in this TU) */
    .4byte  FUN_0602755C
.L_pool_0602F25C:
    .4byte  sym_0602F3CC
.L_0602F260:
    cmp/ge r5, r2
    bt      .L_0602F266
    mov r2, r5
.L_0602F266:
    add r5, r4
    mov.w   .L_wpool_0602F26E, r1
    rts
    mov.l r4, @(r0, r1)
.L_wpool_0602F26E:
    .2byte  0x00E4

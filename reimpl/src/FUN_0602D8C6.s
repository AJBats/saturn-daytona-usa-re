
    .section .text.FUN_0602D8C6


    .global FUN_0602D8C6
    .type FUN_0602D8C6, @function
FUN_0602D8C6:
    sts.l pr, @-r15
    mov.l @(48, r0), r4
    mov.l r4, @(32, r0)
    mov.l @(40, r0), r4
    neg r4, r4
    mov r4, r7
    mov.l @(12, r0), r3
    mov r3, r9
    mov.l @(16, r0), r5
    mov.l @(24, r0), r6
    mov.l r5, @(56, r0)
    mov.l r6, @(60, r0)
    .byte   0xD0, 0x0F    /* mov.l .L_pool_0602D91E, r0 */
    jsr @r0
    nop
    mov r0, r8
    mov r7, r4
    .byte   0xD0, 0x0D    /* mov.l .L_pool_0602D922, r0 */
    jsr @r0
    nop
    dmuls.l r0, r3
    mov r14, r0
    mov.w   DAT_0602d918, r10
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    mov.l r3, @(r0, r10)
    add r3, r5
    mov.l r5, @(16, r0)
    dmuls.l r8, r9
    mov.w   DAT_0602d91a, r10
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    mov.l r9, @(r0, r10)
    add r9, r6
    mov.l r6, @(24, r0)
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x0250

    .global DAT_0602d918
DAT_0602d918:
    .2byte  0x018C

    .global DAT_0602d91a
DAT_0602d91a:
    .2byte  0x0190
.L_pool_0602D91E:
    .4byte  cos_lookup
.L_pool_0602D922:
    .4byte  sin_lookup

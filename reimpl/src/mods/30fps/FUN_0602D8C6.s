
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
    mov.l   .L_pool_0602D91E, r0
    jsr @r0
    nop
    mov r0, r8
    mov r7, r4
    mov.l   .L_pool_0602D922, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    mov r14, r0
    mov.w   DAT_0602d918, r10
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    /* 30fps: scale velocity X by x2/3 before position integration.
       Position adds velocity 30x/sec instead of 20x/sec. Without this,
       car moves 1.5x too far per second. vel = vel - vel/3. */
    mov.l   .L_one_third, r11
    dmuls.l r11, r3
    sts mach, r11
    sub r11, r3
    mov.l r3, @(r0, r10)
    add r3, r5
    mov.l r5, @(16, r0)
    dmuls.l r8, r9
    mov.w   DAT_0602d91a, r10
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    /* 30fps: scale velocity Z by x2/3 */
    mov.l   .L_one_third, r8
    dmuls.l r8, r9
    sts mach, r8
    sub r8, r9
    mov.l r9, @(r0, r10)
    add r9, r6
    mov.l r6, @(24, r0)
    lds.l @r15+, pr
    rts
    nop
    /* Pool region — pad to 4-byte alignment after function growth */
.L_one_third:
    .4byte  0x55555556    /* 1/3 in 0.32 signed fixed-point (for vel x2/3) */
    .2byte  0x0250

    .global DAT_0602d918
DAT_0602d918:
    .2byte  0x018C

    .global DAT_0602d91a
DAT_0602d91a:
    .2byte  0x0190
    .2byte  0x0000        /* alignment pad */
.L_pool_0602D91E:
    .4byte  FUN_06027344
.L_pool_0602D922:
    .4byte  FUN_06027348

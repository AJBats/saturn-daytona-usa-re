/* Vanilla FUN_0602D8C6 — position writer core.
 *
 * Original: car pointer in r0 (set by caller sym_0602D8BC).
 * For unit testing: car arrives in r4 (standard ABI), adapter moves to r0.
 *
 * Must preserve callee-saved registers (r8-r14).
 */

    .section .text.vanilla
    .align 2

    .global FUN_0602D8C6
FUN_0602D8C6:
    /* Adapter: car in r4 -> r0. Save r14 (used internally). */
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r0

    /* Original FUN_0602D8C6 body */
    mov.l @(48, r0), r4       /* r4 = car[+0x30] heading_copy */
    mov.l r4, @(32, r0)       /* car[+0x20] = heading_copy */
    mov.l @(40, r0), r4       /* r4 = car[+0x28] slip_angle */
    neg r4, r4                /* r4 = -slip_angle */
    mov r4, r7                /* r7 = slip (saved) */
    mov.l @(12, r0), r3       /* r3 = car[+0x0C] speed */
    mov r3, r9                /* r9 = speed (callee-saved) */
    mov.l @(16, r0), r5       /* r5 = car[+0x10] world_x */
    mov.l @(24, r0), r6       /* r6 = car[+0x18] world_z */
    mov.l r5, @(56, r0)       /* car[+0x38] = world_x (pre-update) */
    mov.l r6, @(60, r0)       /* car[+0x3C] = world_z (pre-update) */
    mov r0, r14               /* save car ptr in r14 */
    mov.l .Lv_sin, r0
    jsr @r0                   /* sin(slip) -> r0 */
    nop
    mov r0, r8                /* r8 = sin_val */
    mov r7, r4                /* r4 = slip */
    mov.l .Lv_cos, r0
    jsr @r0                   /* cos(slip) -> r0 */
    nop
    /* r0 = cos_val, r3 = speed (may be clobbered — use r9) */
    dmuls.l r0, r3             /* cos * speed (r3 from before calls — risky) */
    mov r14, r0                /* r0 = car */
    mov.w .Lv_off_18C, r10
    sts mach, r11
    sts macl, r3
    xtrct r11, r3              /* vel_x */
    mov.l r3, @(r0, r10)      /* car[+0x18C] = vel_x */
    add r3, r5                 /* world_x += vel_x */
    mov.l r5, @(16, r0)       /* car[+0x10] = new world_x */
    dmuls.l r8, r9             /* sin * speed */
    mov.w .Lv_off_190, r10
    sts mach, r8
    sts macl, r9
    xtrct r8, r9              /* vel_z */
    mov.l r9, @(r0, r10)      /* car[+0x190] = vel_z */
    add r9, r6                 /* world_z += vel_z */
    mov.l r6, @(24, r0)       /* car[+0x18] = new world_z */

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .align 1
.Lv_off_18C:
    .2byte  0x018C
.Lv_off_190:
    .2byte  0x0190
    .align 2
.Lv_sin:
    .4byte  FUN_06027344
.Lv_cos:
    .4byte  FUN_06027348

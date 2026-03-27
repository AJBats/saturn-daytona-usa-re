/* Vanilla sym_0602D814 — extracted from original assembly.
 * Symbol renamed to vanilla_sym_0602D814 to avoid conflict with decomp version.
 *
 * IMPORTANT: The original assembly uses r14 as car pointer (set by caller).
 * For unit testing, we adapt the entry to take car in r4 (standard ABI).
 */

    .section .text.vanilla
    .align 2

    .global sym_0602D814
sym_0602D814:
    /* Adapter: car arrives in r4, original expects r14 */
    mov r4, r14
    /* Fall through to original code */
    mov r14, r0
    mov.l @(12, r0), r4
    mov.w .Lv_d862, r2       /* r2 = 0xFC (accel_delta offset) */
    mov.l @(r0, r2), r3
    add r3, r4
    mov.l r4, @(12, r0)
    cmp/pz r4
    bt .Lv_D82A
    mov #0x0, r3
    mov.l r3, @(12, r0)
    mov.l r3, @(r0, r2)

    /* Original sym_0602D82A */
.Lv_D82A:
    mov.w .Lv_d864, r2       /* r2 = 0xDC (gear offset) */
    mov.l @(12, r0), r3
    mov.w @(r0, r2), r4
    mov.l .Lv_D868, r5       /* gear table */
    shll2 r4
    add r5, r4
    mov.l @r4, r4
    mov.l .Lv_D86C, r5       /* 0x0221AC91 */
    dmuls.l r3, r4
    nop
    nop
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    dmuls.l r4, r5
    mov.w .Lv_d866, r1       /* r1 = 0xE0 */
    mov #0x0, r3
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    shlr16 r5
    mov r5, r6
    mov.l .Lv_D870, r4       /* 0x2134 */
    cmp/gt r3, r5
    bt .Lv_D874
    mov r3, r5
    bra .Lv_D87A
    nop
.Lv_D874:
    cmp/gt r5, r4
    bt .Lv_D87A
    mov r4, r5
.Lv_D87A:
    mov.l r5, @(r0, r1)      /* car[+0xE0] = clamped */
    sub r5, r6
    cmp/pz r6
    bt .Lv_D884
    mov #0x0, r6
.Lv_D884:
    mov.w .Lv_d88c, r1       /* r1 = 0xE8 */
    mov.l r6, @(r0, r1)      /* car[+0xE8] = excess */
    rts
    nop

    .align 1
.Lv_d862:
    .2byte 0x00FC
.Lv_d864:
    .2byte 0x00DC
.Lv_d866:
    .2byte 0x00E0
.Lv_d88c:
    .2byte 0x00E8
    .align 2
.Lv_D868:
    .4byte sym_060477BC
.Lv_D86C:
    .4byte 0x0221AC91
.Lv_D870:
    .4byte 0x00002134

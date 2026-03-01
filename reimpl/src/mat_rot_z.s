
    .section .text.FUN_06026F2A


    .global mat_rot_z
    .type mat_rot_z, @function
mat_rot_z:
    sts.l pr, @-r15
    .byte   0xD6, 0x50    /* mov.l .L_pool_06027070, r6 */
    mov #0x8, r5
    .byte   0xB2, 0x12    /* bsr 0x06027358 */
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(4, r6)
    .byte   0xD0, 0x4A    /* mov.l .L_pool_06027068, r0 */
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
.L_06026F46:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov r4, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(4, r4)
    bf/s    .L_06026F46
    add #0xC, r4
    rts
    nop

    .global sym_06026F72
sym_06026F72:
    .byte   0xD0, 0x3D    /* mov.l .L_pool_06027068, r0 */
    .byte   0xD6, 0x3F    /* mov.l .L_pool_06027074, r6 */
    mov.l @r0, r5
    mov #0x3, r3
.L_06026F7A:
    mov #0x3, r2
.L_06026F7C:
    clrmac
    mac.l @r4+, @r5+
    add #0x8, r4
    mac.l @r4+, @r5+
    add #0x8, r4
    dt r2
    mac.l @r4+, @r5+
    add #-0x18, r4
    add #-0xC, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l r1, @r6
    bf/s    .L_06026F7C
    add #0x4, r6
    add #-0xC, r4
    dt r3
    bf/s    .L_06026F7A
    add #0xC, r5
    mov r5, r7
    add #-0x24, r5
    add #0x24, r4
    mov #0x3, r3
.L_06026FAA:
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    dt r3
    mac.l @r4+, @r5+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l @r7+, r0
    add r0, r1
    mov.l r1, @r6
    bf/s    .L_06026FAA
    add #0x4, r6
    add #-0x30, r6
    add #-0x30, r7
    mov.l @(0, r6), r0
    mov.l @(4, r6), r1
    mov.l @(8, r6), r2
    mov.l @(12, r6), r3
    mov.l @(16, r6), r4
    mov.l @(20, r6), r5
    mov.l r0, @(0, r7)
    mov.l r1, @(4, r7)
    mov.l r2, @(8, r7)
    mov.l r3, @(12, r7)
    mov.l r4, @(16, r7)
    mov.l r5, @(20, r7)
    mov.l @(24, r6), r0
    mov.l @(28, r6), r1
    mov.l @(32, r6), r2
    mov.l @(36, r6), r3
    mov.l @(40, r6), r4
    mov.l @(44, r6), r5
    mov.l r0, @(24, r7)
    mov.l r1, @(28, r7)
    mov.l r2, @(32, r7)
    mov.l r3, @(36, r7)
    mov.l r4, @(40, r7)
    rts
    mov.l r5, @(44, r7)

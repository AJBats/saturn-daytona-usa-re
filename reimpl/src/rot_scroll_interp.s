
    .section .text.FUN_0602E462


    .global rot_scroll_interp
    .type rot_scroll_interp, @function
rot_scroll_interp:
    sts.l pr, @-r15
    neg r4, r4
    mov r4, r7
    mov.l @(12, r0), r3
    mov r3, r9
    mov.l @(16, r0), r5
    mov.l @(24, r0), r6
    mov.l r5, @(56, r0)
    mov.l r6, @(60, r0)
    .byte   0xD0, 0x0D    /* mov.l .L_pool_0602E4B0, r0 */
    jsr @r0
    nop
    mov r0, r8
    mov r7, r4
    .byte   0xD0, 0x0C    /* mov.l .L_pool_0602E4B4, r0 */
    jsr @r0
    nop
    dmuls.l r0, r3
    mov r14, r0
    .byte   0xDA, 0x0A    /* mov.l .L_pool_0602E4B8, r10 */
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    mov.l r3, @(r0, r10)
    add r3, r5
    mov.l r5, @(16, r0)
    dmuls.l r8, r9
    .byte   0xDA, 0x07    /* mov.l .L_pool_0602E4BC, r10 */
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
    .4byte  cos_lookup
.L_pool_0602E4B4:
    .4byte  sin_lookup
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

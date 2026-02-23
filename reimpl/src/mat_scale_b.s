    .section .text.FUN_06027124
    .global mat_scale_b
    .type mat_scale_b, @function
/* mat_scale_b(r4=scale_x, r5=scale_y, r6=scale_z) — scale matrix stack B columns.
 * Multiplies 3x3 rotation matrix elements by scale factors using 16.16 FP.
 * Cross-TU pool ref: first instruction loads mat_stack_ptr_b from adjacent pool.
 */
mat_scale_b:
    .byte 0xD0, 0x81              /* mov.l @(adjacent_pool), r0 -- mat_stack_ptr_b [cross-TU] */
    mov.l @r0, r7                 /* r7 = current top of stack B */
    mov #0x3, r3                  /* r3 = loop counter (3 iterations) */
.L_0602712A:
    mov.l @(0, r7), r0            /* r0 = matrix[col][row] */
    dmuls.l r0, r4                /* MACH:MACL = element * scale_x */
    mov.l @(12, r7), r0           /* r0 = matrix[col+1][row] */
    sts mach, r1
    sts macl, r2
    xtrct r1, r2                  /* r2 = 16.16 FP result */
    dmuls.l r0, r5                /* element * scale_y */
    mov.l r2, @(0, r7)            /* store scaled element */
    mov.l @(24, r7), r0           /* r0 = matrix[col+2][row] */
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    dmuls.l r0, r6                /* element * scale_z */
    mov.l r2, @(12, r7)
    dt r3                         /* r3--; T = (r3 == 0) */
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    mov.l r2, @(24, r7)
    bf/s .L_0602712A              /* loop back if r3 != 0 */
    add #0x4, r7                  /* advance row pointer (delay slot) */
    rts
    nop

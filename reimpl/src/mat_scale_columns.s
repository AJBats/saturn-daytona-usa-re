    .section .text.FUN_06026E60
    .global mat_scale_columns
    .type mat_scale_columns, @function
/* mat_scale_columns(r4=scale_x, r5=scale_y, r6=scale_z) — scale matrix stack A columns.
 * Identical algorithm to mat_scale_b but operates on stack A.
 * Cross-TU pool ref: first instruction loads mat_stack_ptr_a from adjacent pool.
 */
mat_scale_columns:
    .byte 0xD0, 0x81              /* mov.l @(adjacent_pool), r0 -- mat_stack_ptr_a [cross-TU] */
    mov.l @r0, r7                 /* r7 = current top of stack A */
    mov #0x3, r3                  /* r3 = loop counter (3 iterations) */
.L_06026E6A:
    mov.l @(0, r7), r0
    dmuls.l r0, r4                /* element * scale_x */
    mov.l @(12, r7), r0
    sts mach, r1
    sts macl, r2
    xtrct r1, r2                  /* 16.16 FP result */
    dmuls.l r0, r5                /* element * scale_y */
    mov.l r2, @(0, r7)
    mov.l @(24, r7), r0
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    dmuls.l r0, r6                /* element * scale_z */
    mov.l r2, @(12, r7)
    dt r3
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    mov.l r2, @(24, r7)
    bf/s .L_06026E6A
    add #0x4, r7                  /* next row (delay slot) */
    rts
    nop

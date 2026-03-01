
    .section .text.FUN_06026362


    .global transform_rotation_apply
    .type transform_rotation_apply, @function
transform_rotation_apply:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    .byte   0xDC, 0x0C    /* mov.l .L_pool_060263A0, r12 */
    mov #0xA, r13
    .byte   0xDE, 0x0C    /* mov.l .L_pool_060263A4, r14 */
    .byte   0xD7, 0x0D    /* mov.l .L_pool_060263A8, r7 */
    .byte   0xD5, 0x0D    /* mov.l .L_fp_half, r5 */
    mov #0x0, r4
    extu.w r4, r6
.L_loop_body:
    extu.w r6, r0
    shll2 r0
    shll r0
    add r12, r0
    mov.w @(6, r0), r0
    bra     .L_dispatch_rotation
    extu.w r0, r0
    .4byte  0xA001624D                      /* bra +2 / extu.w r4, r2 (case A entry) */
    .4byte  0x625DA027                      /* extu.w r5, r2 / bra loop_next (case C entry) */
    .4byte  0x2E21A001                      /* mov.w r2, @r14 [delay] / bra +2 (case B entry) */
    .4byte  0x624D625D                      /* extu.w r4, r2 [delay] / extu.w r5, r2 (case D entry) */
    .4byte  0xA0222721                      /* bra loop_next / mov.w r2, @r7 [delay] */
.L_out_of_range:
    bra     .L_loop_next
    nop
.L_pool_060263A0:
    .4byte  sym_06060F2C                    /* [MEDIUM] rotation data table base (8-byte stride, 10 slots) */
.L_pool_060263A4:
    .4byte  sym_06060D2A                    /* [MEDIUM] &rotation_out_a (word output) */
.L_pool_060263A8:
    .4byte  sym_06060D34                    /* [MEDIUM] &rotation_out_b (word output) */
.L_fp_half:
    .4byte  0x00008000                      /* [HIGH] 0.5 (16.16 fixed-point) */
.L_dispatch_rotation:
    mov.w   .L_wpool_060263C6, r1
    sub r1, r0
    mov #0xC, r1
    cmp/hs r1, r0
    bt      .L_out_of_range
    shll r0
    mov r0, r1
    .word 0xC702
    mov.w @(r0, r1), r0
    braf r0
    nop
.L_wpool_060263C6:
    .2byte  0x008A                          /* [HIGH] rotation base value to subtract */
    .4byte  0xFFC2FFC2                      /* index 0,1: offset -62 -> case A (rotation_out_a = 0) */
    .4byte  0xFFCCFFCC                      /* index 2,3: offset -52 -> case B (rotation_out_b = 0) */
    .4byte  0xFFC6FFC6                      /* index 4,5: offset -58 -> case C (rotation_out_a = fp_half) */
    .4byte  0xFFC6FFC6                      /* index 6,7: offset -58 -> case C (rotation_out_a = fp_half) */
    .4byte  0xFFD0FFD0                      /* index 8,9: offset -48 -> case D (rotation_out_b = fp_half) */
    .4byte  0xFFD0FFD0                      /* index 10,11: offset -48 -> case D (rotation_out_b = fp_half) */
.L_loop_next:
    add #0x1, r6
    extu.w r6, r2
    cmp/ge r13, r2
    bf      .L_loop_body
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

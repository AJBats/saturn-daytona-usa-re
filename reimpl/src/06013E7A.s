
    .section .text.FUN_06013E7A


    .global end_race_score
    .type end_race_score, @function
end_race_score:
    mov.l r14, @-r15
    mov.w   DAT_06013f48, r5
    mov.w @r13, r4
    extu.w r4, r4
    mul.l r14, r4
    jsr @r11
    sts macl, r4
    mov.w   DAT_06013f4a, r5
    mov #0x0, r4
    .byte   0xD3, 0x38    /* mov.l .L_pool_06013F70, r3 */
    add r0, r5
    jsr @r3
    mov.l @r15+, r6
    mov.w @(24, r12), r0
    jsr @r9
    mov r0, r4
    mov.w @r13, r5
    extu.w r5, r5
    mul.l r14, r5
    sts macl, r5
    jsr @r11
    mov.l @(4, r12), r4
    mov.l r0, @(12, r15)
    mov.w @r13, r5
    extu.w r5, r5
    mul.l r14, r5
    sts macl, r5
    jsr @r11
    mov.l @(8, r12), r4
    mov.l @r12, r3
    sub r0, r3
    mov.l r3, @(8, r15)
    mov.w @r13, r5
    extu.w r5, r5
    mul.l r14, r5
    sts macl, r5
    jsr @r11
    mov.l @(12, r12), r4
    mov r0, r6
    mov.l @(8, r15), r5
    .byte   0xD3, 0x29    /* mov.l .L_pool_06013F70, r3 */
    jsr @r3
    mov.l @(12, r15), r4
    mov.w @(24, r12), r0
    mov r0, r4
    jsr @r9
    neg r4, r4
    mov.w @(26, r12), r0
    mov.w @r13, r3
    mov r0, r4
    extu.w r3, r3
    mul.l r3, r4
    .byte   0xD3, 0x24    /* mov.l .L_pool_06013F74, r3 */
    jsr @r3
    sts macl, r4
    mov.w @(28, r12), r0
    mov.w @r13, r3
    mov r0, r4
    extu.w r3, r3
    mul.l r3, r4
    .byte   0xD3, 0x21    /* mov.l .L_pool_06013F78, r3 */
    jsr @r3
    sts macl, r4
    mov.w @(30, r12), r0
    mov.w @r13, r3
    mov r0, r4
    extu.w r3, r3
    mul.l r3, r4
    jsr @r9
    sts macl, r4
    mov.w @r13, r5
    extu.w r5, r5
    mul.l r14, r5
    sts macl, r5
    jsr @r11
    mov.l @(16, r12), r4
    mov.w   DAT_06013f4c, r12
    .byte   0xD3, 0x19    /* mov.l .L_pool_06013F7C, r3 */
    add r0, r12
    mov r12, r6
    mov r12, r5
    jsr @r3
    mov r12, r4
    mov #0x4, r5
    mov r8, r12
    .byte   0xD4, 0x16    /* mov.l .L_pool_06013F80, r4 */
    .byte   0xD3, 0x17    /* mov.l .L_pool_06013F84, r3 */
    add r8, r4
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l @r15, r5
    .byte   0xD4, 0x15    /* mov.l .L_pool_06013F88, r4 */
    .byte   0xD3, 0x15    /* mov.l .L_pool_06013F8C, r3 */
    mov.w @r5, r5
    add r12, r4
    jsr @r3
    mov.l @r4, r4
    .byte   0xD2, 0x14    /* mov.l .L_pool_06013F90, r2 */
    mov.l @r2, r2
    bra     .L_06013F94
    nop

    .global DAT_06013f46
DAT_06013f46:
    .word 0x03A0

    .global DAT_06013f48
DAT_06013f48:
    .2byte  0x051E

    .global DAT_06013f4a
DAT_06013f4a:
    .2byte  0x8000

    .global DAT_06013f4c
DAT_06013f4c:
    .2byte  0x4CCC
    .2byte  0xFFFF
    .4byte  mat_rot_z
    .4byte  fpmul
    .4byte  sym_06084AF6
    .4byte  0x00010000
    .4byte  sym_06026E0C
    .4byte  sym_0605AD5C
    .4byte  sym_06089E4A
    .4byte  sym_06026DBC
.L_pool_06013F70:
    .4byte  sym_06026E2E
.L_pool_06013F74:
    .4byte  mat_rot_x
.L_pool_06013F78:
    .4byte  mat_rot_y
.L_pool_06013F7C:
    .4byte  mat_scale_columns
.L_pool_06013F80:
    .4byte  sym_06062338
.L_pool_06013F84:
    .4byte  sym_06031D8C
.L_pool_06013F88:
    .4byte  sym_060622C0
.L_pool_06013F8C:
    .4byte  sym_06031A28
.L_pool_06013F90:
    .4byte  sym_06089EDC
.L_06013F94:
    add #-0x30, r2
    add #0x20, r10
    .byte   0xD3, 0x09    /* mov.l .L_pool_06013FC0, r3 */
    mov.l r2, @r3
    mov.l @(4, r15), r1
    cmp/hs r1, r10
    bt/s    .L_06013FA8
    add #0x4, r8
    .byte   0xAF, 0x65    /* bra 0x06013E72 (external) */
    nop
.L_06013FA8:
    add #0x10, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06013FC0:
    .4byte  sym_06089EDC

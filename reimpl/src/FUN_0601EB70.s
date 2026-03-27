
    .section .text.FUN_0601EB70


    .global FUN_0601EB70
    .type FUN_0601EB70, @function
FUN_0601EB70:
    mov.l r14, @-r15
    mov #0x10, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    .byte   0xDB, 0x1E    /* mov.l .L_pool_0601EBF4, r11 */
    .byte   0xDC, 0x1E    /* mov.l .L_pool_0601EBF8, r12 */
    .byte   0xDD, 0x1F    /* mov.l .L_pool_0601EBFC, r13 */
    .byte   0xD7, 0x1F    /* mov.l .L_pool_0601EC00, r7 */
    .byte   0xD6, 0x20    /* mov.l .L_pool_0601EC04, r6 */
    mov.l   .L_0601EC08, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt/s    .L_0601EB94
    mov #0x0, r5
    bra     .L_0601EBD0
    nop
.L_0601EB94:
    bra     .L_0601EBA2
    mov r5, r4
.L_0601EB98:
    mov.l @r13, r2
    add r4, r2
    extu.b r5, r3
    mov.b r3, @r2
    add #0x1, r4
.L_0601EBA2:
    mov.b @r12, r0
    extu.b r0, r0
    shll2 r0
    mov.l @(r0, r11), r3
    cmp/hs r3, r4
    bf      .L_0601EB98
    mov r5, r4
.L_0601EBB0:
    mov.l @r6, r3
    mov r4, r2
    add r4, r3
    add r7, r2
    add #0x1, r4
    mov.b @r2, r1
    mov r4, r2
    mov.b r1, @r3
    add r7, r2
    mov.l @r6, r3
    mov.b @r2, r1
    add r4, r3
    mov.b r1, @r3
    add #0x1, r4
    cmp/ge r14, r4
    bf      .L_0601EBB0
.L_0601EBD0:
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0601EBDA
    .type FUN_0601EBDA, @function
FUN_0601EBDA:
    mov.l r14, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.w   .L_0601EBF0, r5
    mov.l   .L_0601EC08, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601EC0C
    bra     .L_0601EFBC
    nop
.L_0601EBF0:
    .2byte  0x00F0
    .2byte  0xFFFF
    .4byte  sym_0604A5C0
    .4byte  sym_060877D8
    .4byte  sym_0605E098
    .4byte  sym_0604A5AC
    .4byte  sym_0605E09C
.L_0601EC08:
    .4byte  sym_06087080
.L_0601EC0C:
    mov.l   .L_0601EEE4, r4
    mov.l @r4, r4
    add #0x10, r4
    mov.l   .L_0601EEE8, r6
    mov r6, r7
    mov r6, r11
    add #0x48, r11
.L_0601EC1A:
    mov.l @r7, r14
    mov r14, r6
    mov r14, r12
    add r5, r12
.L_0601EC22:
    mov r6, r0
    mov r6, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r0, r14
    add #0x4, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r0, r14
    add #0x8, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    add #0xC, r6
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    cmp/hs r12, r6
    bf/s    .L_0601EC22
    mov.b r2, @r14
    add #0x8, r7
    cmp/hs r11, r7
    bf      .L_0601EC1A
    mov.l   .L_0601EEEC, r6
    mov r6, r7
    add #0x18, r7
.L_0601EC82:
    mov.l @r6, r0
    mov.b @r4+, r1
    mov r0, r14
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r0, r14
    mov.b @r4+, r1
    add #0x4, r14
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    cmp/hs r7, r6
    bf/s    .L_0601EC82
    mov.b r2, @r14
    mov.l   .L_0601EEF0, r6
    mov r6, r7
    add #0x20, r7
.L_0601ECC2:
    mov r6, r14
    mov.b @r4+, r1
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r6, r14
    mov.b @r4+, r1
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    cmp/hs r7, r6
    bf/s    .L_0601ECC2
    mov.b r2, @r14
    mov.l   .L_0601EEF4, r6
    mov r6, r7
    add #0x20, r7
.L_0601ED00:
    mov r6, r14
    mov.b @r4+, r1
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r6, r14
    mov.b @r4+, r1
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    cmp/hs r7, r6
    bf/s    .L_0601ED00
    mov.b r2, @r14
    mov.l   .L_0601EEF8, r6
    mov r6, r7
    mov r6, r14
    add #0x24, r14
.L_0601ED40:
    mov r7, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    add #0xC, r7
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    cmp/hs r14, r7
    bf/s    .L_0601ED40
    mov.b r2, @r6
    mov.l   .L_0601EEFC, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF00, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF04, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.b @r4+, r2
    mov.l   .L_0601EF08, r3
    mov.b r2, @r3
    mov.b @r4+, r3
    mov.l   .L_0601EF0C, r2
    mov.b r3, @r2
    mov.b @r4+, r2
    mov.l   .L_0601EF10, r3
    mov.b r2, @r3
    mov.b @r4+, r3
    mov.l   .L_0601EF14, r2
    mov.b r3, @r2
    mov.l   .L_0601EF18, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF1C, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF20, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF24, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF28, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF2C, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF30, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF34, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF38, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF3C, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF40, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF44, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF48, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF4C, r6
    mov r6, r3
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r3
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF50, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF54, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.l   .L_0601EF58, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    bra     .L_0601EF5C
    nop
.L_0601EEE4:
    .4byte  sym_0605E098
.L_0601EEE8:
    .4byte  sym_0605DD6C
.L_0601EEEC:
    .4byte  sym_0605DE24
.L_0601EEF0:
    .4byte  sym_0605DDB4
.L_0601EEF4:
    .4byte  sym_0605DDD4
.L_0601EEF8:
    .4byte  sym_0605DE40
.L_0601EEFC:
    .4byte  sym_0605AD00
.L_0601EF00:
    .4byte  sym_0605AD04
.L_0601EF04:
    .4byte  sym_0605AD0C
.L_0601EF08:
    .4byte  sym_0605AB16
.L_0601EF0C:
    .4byte  sym_0605AB17
.L_0601EF10:
    .4byte  sym_0605D240
.L_0601EF14:
    .4byte  sym_0605D241
.L_0601EF18:
    .4byte  sym_06060D44
.L_0601EF1C:
    .4byte  sym_06060D46
.L_0601EF20:
    .4byte  sym_06060D40
.L_0601EF24:
    .4byte  sym_06060D42
.L_0601EF28:
    .4byte  sym_06060D48
.L_0601EF2C:
    .4byte  sym_06060D4A
.L_0601EF30:
    .4byte  sym_06060D4C
.L_0601EF34:
    .4byte  sym_06060D4E
.L_0601EF38:
    .4byte  sym_06060D54
.L_0601EF3C:
    .4byte  sym_06060D58
.L_0601EF40:
    .4byte  sym_06060D50
.L_0601EF44:
    .4byte  sym_06060D60
.L_0601EF48:
    .4byte  sym_06060D62
.L_0601EF4C:
    .4byte  sym_06060D5C
.L_0601EF50:
    .4byte  sym_06060D5E
.L_0601EF54:
    .4byte  sym_06060D64
.L_0601EF58:
    .4byte  sym_06060D66
.L_0601EF5C:
    .byte   0xD6, 0x1F    /* mov.l .L_ptr_xform_param_28, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x1D    /* mov.l .L_ptr_xform_param_2A, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x1B    /* mov.l .L_ptr_xform_param_2C, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x16    /* mov.l .L_ptr_xform_param_30, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x11    /* mov.l .L_ptr_xform_param_34, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4, r3
    mov.b r3, @r6
.L_0601EFBC:
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r14


    .global FUN_0601EFC4
    .type FUN_0601EFC4, @function
FUN_0601EFC4:
    mov.l r14, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.w   .L_0601EFDA, r5
    mov.l   .L_0601EFF0, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601EFF4
    bra     .L_0601F3E4
    nop
.L_0601EFDA:
    .2byte  0x00F0
    .4byte  sym_06060D68
    .4byte  sym_06060D6A
    .4byte  sym_06060D70
    .4byte  sym_06060D74
    .4byte  sym_06060D6C
.L_0601EFF0:
    .4byte  sym_06087080
.L_0601EFF4:
    mov.l   .L_0601F2E4, r4
    mov.l @r4, r4
    add #0x10, r4
    mov.l   .L_0601F2E8, r6
    mov r6, r7
    mov r6, r11
    add #0x48, r11
.L_0601F002:
    mov.l @r7, r14
    mov r14, r6
    mov r14, r12
    add r5, r12
.L_0601F00A:
    mov r6, r0
    mov r6, r14
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    add #0x1, r4
    mov r0, r14
    add #0x4, r14
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    add #0x1, r4
    mov r0, r14
    add #0x8, r14
    mov.b @r14+, r1
    add #0xC, r6
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    cmp/hs r12, r6
    bf/s    .L_0601F00A
    add #0x1, r4
    add #0x8, r7
    cmp/hs r11, r7
    bf      .L_0601F002
    mov.l   .L_0601F2EC, r6
    mov r6, r7
    add #0x18, r7
.L_0601F070:
    mov.l @r6, r0
    add #0x4, r6
    mov r0, r14
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov r0, r14
    mov.b r2, @r4
    add #0x4, r14
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    cmp/hs r7, r6
    bf/s    .L_0601F070
    add #0x1, r4
    mov.l   .L_0601F2F0, r6
    mov r6, r7
    add #0x20, r7
.L_0601F0B4:
    mov r6, r14
    add #0x4, r6
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov r6, r14
    mov.b r2, @r4
    add #0x4, r6
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    cmp/hs r7, r6
    bf/s    .L_0601F0B4
    add #0x1, r4
    mov.l   .L_0601F2F4, r6
    mov r6, r7
    add #0x20, r7
.L_0601F0F6:
    mov r6, r14
    mov.b @r14+, r1
    add #0x4, r6
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov r6, r14
    mov.b r2, @r4
    add #0x4, r6
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    cmp/hs r7, r6
    bf/s    .L_0601F0F6
    add #0x1, r4
    mov.l   .L_0601F2F8, r6
    mov r6, r7
    mov r6, r14
    add #0x24, r14
.L_0601F13A:
    mov r7, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    add #0xC, r7
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    cmp/hs r14, r7
    bf/s    .L_0601F13A
    add #0x1, r4
    mov.l   .L_0601F2FC, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F300, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F304, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F308, r2
    mov.b @r2, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F30C, r2
    mov.b @r2, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F310, r2
    mov.b @r2, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F314, r2
    mov.b @r2, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F318, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F31C, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F320, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F324, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F328, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F32C, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F330, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F334, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F338, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F33C, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F340, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov r4, r3
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r3
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F344, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F348, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F34C, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    bra     .L_0601F350
    nop
.L_0601F2E4:
    .4byte  sym_0605E098
.L_0601F2E8:
    .4byte  sym_0605DD6C
.L_0601F2EC:
    .4byte  sym_0605DE24
.L_0601F2F0:
    .4byte  sym_0605DDB4
.L_0601F2F4:
    .4byte  sym_0605DDD4
.L_0601F2F8:
    .4byte  sym_0605DE40
.L_0601F2FC:
    .4byte  sym_0605AD00
.L_0601F300:
    .4byte  sym_0605AD04
.L_0601F304:
    .4byte  sym_0605AD0C
.L_0601F308:
    .4byte  sym_0605AB16
.L_0601F30C:
    .4byte  sym_0605AB17
.L_0601F310:
    .4byte  sym_0605D240
.L_0601F314:
    .4byte  sym_0605D241
.L_0601F318:
    .4byte  sym_06060D44
.L_0601F31C:
    .4byte  sym_06060D46
.L_0601F320:
    .4byte  sym_06060D40
.L_0601F324:
    .4byte  sym_06060D42
.L_0601F328:
    .4byte  sym_06060D48
.L_0601F32C:
    .4byte  sym_06060D4A
.L_0601F330:
    .4byte  sym_06060D4C
.L_0601F334:
    .4byte  sym_06060D4E
.L_0601F338:
    .4byte  sym_06060D54
.L_0601F33C:
    .4byte  sym_06060D58
.L_0601F340:
    .4byte  sym_06060D50
.L_0601F344:
    .4byte  sym_06060D60
.L_0601F348:
    .4byte  sym_06060D62
.L_0601F34C:
    .4byte  sym_06060D5C
.L_0601F350:
    add #0x1, r4
    mov.l   .L_0601F3EC, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F3F0, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F3F4, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F3F8, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F3FC, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F400, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F404, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_0601F408, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r3
    mov.b r3, @r4
.L_0601F3E4:
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r14
.L_0601F3EC:
    .4byte  sym_06060D5E
.L_0601F3F0:
    .4byte  sym_06060D64
.L_0601F3F4:
    .4byte  sym_06060D66
.L_0601F3F8:
    .4byte  sym_06060D68
.L_0601F3FC:
    .4byte  sym_06060D6A
.L_0601F400:
    .4byte  sym_06060D70
.L_0601F404:
    .4byte  sym_06060D74
.L_0601F408:
    .4byte  sym_06060D6C


    .section .text.FUN_0601EBDA


    .global geom_vertex_compute
    .type geom_vertex_compute, @function
geom_vertex_compute:
    mov.l r14, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.w   .L_0601EBF0, r5
    .byte   0xD0, 0x09    /* mov.l .L_0601EC08, r0 */
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
    .byte   0xD4, 0xB5    /* mov.l .L_0601EEE4, r4 */
    mov.l @r4, r4
    add #0x10, r4
    .byte   0xD6, 0xB5    /* mov.l .L_0601EEE8, r6 */
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
    .byte   0xD6, 0x9B    /* mov.l .L_0601EEEC, r6 */
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
    .byte   0xD6, 0x8C    /* mov.l .L_0601EEF0, r6 */
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
    .byte   0xD6, 0x7E    /* mov.l .L_0601EEF4, r6 */
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
    .byte   0xD6, 0x6F    /* mov.l .L_0601EEF8, r6 */
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
    .byte   0xD6, 0x5B    /* mov.l .L_0601EEFC, r6 */
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
    .byte   0xD6, 0x56    /* mov.l .L_0601EF00, r6 */
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
    .byte   0xD6, 0x51    /* mov.l .L_0601EF04, r6 */
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
    .byte   0xD3, 0x4B    /* mov.l .L_0601EF08, r3 */
    mov.b r2, @r3
    mov.b @r4+, r3
    .byte   0xD2, 0x4B    /* mov.l .L_0601EF0C, r2 */
    mov.b r3, @r2
    mov.b @r4+, r2
    .byte   0xD3, 0x4A    /* mov.l .L_0601EF10, r3 */
    mov.b r2, @r3
    mov.b @r4+, r3
    .byte   0xD2, 0x4A    /* mov.l .L_0601EF14, r2 */
    mov.b r3, @r2
    .byte   0xD6, 0x4A    /* mov.l .L_0601EF18, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x48    /* mov.l .L_0601EF1C, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x46    /* mov.l .L_0601EF20, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x44    /* mov.l .L_0601EF24, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x42    /* mov.l .L_0601EF28, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x40    /* mov.l .L_0601EF2C, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x3E    /* mov.l .L_0601EF30, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x3C    /* mov.l .L_0601EF34, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x3A    /* mov.l .L_0601EF38, r6 */
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
    .byte   0xD6, 0x35    /* mov.l .L_0601EF3C, r6 */
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
    .byte   0xD6, 0x30    /* mov.l .L_0601EF40, r6 */
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
    .byte   0xD6, 0x2B    /* mov.l .L_0601EF44, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x29    /* mov.l .L_0601EF48, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x27    /* mov.l .L_0601EF4C, r6 */
    mov r6, r3
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r3
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x24    /* mov.l .L_0601EF50, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x22    /* mov.l .L_0601EF54, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x20    /* mov.l .L_0601EF58, r6 */
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

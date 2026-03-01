
    .section .text.FUN_0602E07A


    .global scene_zsort
    .type scene_zsort, @function
scene_zsort:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xD4, 0x10    /* mov.l .L_0602E0C8, r4 */
    mov.l @r4, r3
    .byte   0xD4, 0x10    /* mov.l .L_0602E0CC, r4 */
    mov.l r3, @r4
    .byte   0xD4, 0x10    /* mov.l .L_0602E0D0, r4 */
    mov.l @r4, r3
    .byte   0xD4, 0x10    /* mov.l .L_0602E0D4, r4 */
    mov.l r3, @r4
    .byte   0xD4, 0x10    /* mov.l .L_0602E0D8, r4 */
    mov.l @r4, r3
    .byte   0xD4, 0x10    /* mov.l .L_0602E0DC, r4 */
    mov.l r3, @r4
    .byte   0xD4, 0x10    /* mov.l .L_0602E0E0, r4 */
    mov.l @r4, r3
    exts.w r3, r3
    .byte   0xD4, 0x10    /* mov.l .L_0602E0E4, r4 */
    mov.l r3, @r4
    .byte   0xD4, 0x10    /* mov.l .L_0602E0E8, r4 */
    mov.l @r4, r3
    .byte   0xD4, 0x10    /* mov.l .L_0602E0EC, r4 */
    mov.l r3, @r4
    .byte   0xD0, 0x10    /* mov.l .L_0602E0F0, r0 */
    .byte   0xD1, 0x10    /* mov.l .L_0602E0F4, r1 */
    mov.l r1, @r0
    .byte   0xD4, 0x10    /* mov.l .L_0602E0F8, r4 */
    .byte   0xD3, 0x11    /* mov.l .L_0602E0FC, r3 */
    mov.l r3, @r4
    .byte   0xD4, 0x11    /* mov.l .L_0602E100, r4 */
    .byte   0xD3, 0x11    /* mov.l .L_0602E104, r3 */
    mov.l r3, @r4
    rts
    nop
    .4byte  course_table_lookup        /* (adjacent pool: caller's function) */
.L_0602E0C8:
    .4byte  sym_06082A54               /* scene parameter source A */
.L_0602E0CC:
    .4byte  sym_06082A70               /* scene parameter dest A */
.L_0602E0D0:
    .4byte  sym_06082A58               /* scene parameter source B */
.L_0602E0D4:
    .4byte  sym_06082A78               /* scene parameter dest B */
.L_0602E0D8:
    .4byte  sym_06082A44               /* scene parameter source C */
.L_0602E0DC:
    .4byte  sym_06063EEC               /* camera pitch (32-bit) */
.L_0602E0E0:
    .4byte  sym_06082A48               /* scene parameter source D (16-bit) */
.L_0602E0E4:
    .4byte  sym_06063EF0               /* camera pitch extended (sign-extended) */
.L_0602E0E8:
    .4byte  sym_06082A50               /* scene parameter source E */
.L_0602E0EC:
    .4byte  sym_06063E24               /* camera yaw (32-bit) */
.L_0602E0F0:
    .4byte  sym_06082A30               /* physics/render state */
.L_0602E0F4:
    .4byte  0x00000004                  /* physics_state initial value */
.L_0602E0F8:
    .4byte  sym_06063E34               /* z-sort near clipping distance */
.L_0602E0FC:
    .4byte  0x0000F300                  /* near clip = 0xF300 */
.L_0602E100:
    .4byte  sym_06063E28               /* z-sort far clipping distance */
.L_0602E104:
    .4byte  0x006E0000                  /* far clip = 0x6E0000 */

    .global loc_0602E108
loc_0602E108:
    .byte   0xD1, 0x0F    /* mov.l .L_0602E148, r1 */
    mov.w   .L_0602E13E, r3
    mov.l r3, @r1
    .byte   0xD1, 0x0F    /* mov.l .L_0602E14C, r1 */
    .byte   0xD3, 0x0F    /* mov.l .L_0602E150, r3 */
    mov.l r3, @r1
    .byte   0xD1, 0x0F    /* mov.l .L_0602E154, r1 */
    mov.l @r1, r2
    .byte   0xD1, 0x0F    /* mov.l .L_0602E158, r1 */
    mov.l r2, @r1
    .byte   0xD1, 0x0F    /* mov.l .L_0602E15C, r1 */
    .byte   0xD2, 0x10    /* mov.l .L_0602E160, r2 */
    mov.l r2, @r1
    mov.w   .L_0602E140, r3
    .byte   0xD1, 0x0F    /* mov.l .L_0602E164, r1 */
    mov.l r3, @r1
    .byte   0xD0, 0x0F    /* mov.l .L_0602E168, r0 */
    mov.l @r0, r0
    mov.w   .L_0602E13E, r3
    mov.w   .L_0602E142, r1
    mov.l r3, @(r0, r1)
    mov.w   .L_0602E144, r1
    mov.w r3, @(r0, r1)
    mov.w   .L_0602E146, r1
    mov.w r3, @(r0, r1)
    rts
    nop
.L_0602E13E:
    .2byte  0x0000                      /* 0 */
.L_0602E140:
    .2byte  0x0001                      /* 1 */
.L_0602E142:
    .2byte  0x01B4                        /* car struct: collision cooldown offset */
.L_0602E144:
    .2byte  0x00DC                        /* car struct: display param A (word) */
.L_0602E146:
    .2byte  0x00DE                        /* car struct: display param B (word) */
.L_0602E148:
    .4byte  sym_0605A1C4               /* race complete flag (32-bit) */
.L_0602E14C:
    .4byte  sym_0605A1D0               /* depth scale factor (16.16) */
.L_0602E150:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_0602E154:
    .4byte  sym_06082A34               /* scene parameter source */
.L_0602E158:
    .4byte  sym_06063E20               /* camera parameter destination */
.L_0602E15C:
    .4byte  sym_06082A30               /* physics/render state */
.L_0602E160:
    .4byte  0x00000000                  /* zero constant */
.L_0602E164:
    .4byte  sym_0607EAC8               /* checkpoint counter (32-bit) */
.L_0602E168:
    .4byte  sym_0607E940               /* car state base pointer */
    .4byte  0xD10E6312                  /* (embedded sub-fn: raw bytes) */
    .4byte  0x23388907                  /* clear scene params */
    .4byte  0x6033D20D
    .4byte  0x4008022E
    .4byte  0xD00C2022
    .4byte  0x73FF2132
    .4byte  0xD00B6002
    .2byte  0xDD0B

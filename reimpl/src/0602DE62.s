	.text
    .global vdp1_distorted_sprite
vdp1_distorted_sprite:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xD2, 0x05    /* mov.l .L_0602DE84, r2 */
    mov.l @r2, r0
    tst r0, r0
    bf      .L_0602DEE0
    bra     .L_0602E05A
    nop
    .long  sym_06082A30
    .long  0x00000002
    .long  sym_06082A3C
.L_0602DE84:
    .long  sym_06082A40
    .long  sym_06082A54
    .long  sym_06082A58
    .long  sym_06082A44
    .long  sym_06082A48
    .long  sym_06082A50
    .long  0x00000010
    .long  sym_06082A70
    .long  sym_06034FFC
    .long  0x00000000
    .long  sym_06082A6C
    .long  0x00000008
    .long  sym_06082A78
    .long  sym_06082A74
    .long  0x00000004
    .long  sym_06063EEC
    .long  sym_06082A5C
    .long  sym_06063EF0
    .long  sym_06082A60
    .long  0x00000001
    .long  sym_06063E24
    .long  sym_06082A68
    .long  car_param_lookup
.L_0602DEE0:
    add #-0x1, r0
    mov.l r0, @r2
    .byte   0xD2, 0x09    /* mov.l .L_0602DF0C, r2 */
    mov.l @r2, r4
    mov r4, r0
    .byte   0xD1, 0x09    /* mov.l .L_0602DF10, r1 */
    tst r1, r0
    bt      .L_0602DF36
    .byte   0xD0, 0x08    /* mov.l .L_0602DF14, r0 */
    mov.l @r0, r3
    .byte   0xD1, 0x08    /* mov.l .L_0602DF18, r1 */
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DF20
    .byte   0xD0, 0x07    /* mov.l .L_0602DF1C, r0 */
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DF34
    bra     .L_0602DF2A
    nop
    .short  0x0000
.L_0602DF0C:
    .long  sym_06082A3C
.L_0602DF10:
    .long  0x00000010
.L_0602DF14:
    .long  sym_06082A54
.L_0602DF18:
    .long  sym_06082A70
.L_0602DF1C:
    .long  sym_06082A6C
.L_0602DF20:
    .byte   0xD0, 0x03    /* mov.l .L_0602DF30, r0 */
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DF34
.L_0602DF2A:
    mov.l r3, @r1
    bra     .L_0602DF36
    nop
.L_0602DF30:
    .long  sym_06082A6C
.L_0602DF34:
    mov.l r2, @r1
.L_0602DF36:
    mov r4, r0
    .byte   0xD1, 0x07    /* mov.l .L_0602DF58, r1 */
    tst r1, r0
    bt      .L_0602DF7E
    .byte   0xD0, 0x07    /* mov.l .L_0602DF5C, r0 */
    mov.l @r0, r3
    .byte   0xD1, 0x07    /* mov.l .L_0602DF60, r1 */
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DF68
    .byte   0xD0, 0x06    /* mov.l .L_0602DF64, r0 */
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DF7C
    bra     .L_0602DF72
    nop
.L_0602DF58:
    .long  0x00000008
.L_0602DF5C:
    .long  sym_06082A58
.L_0602DF60:
    .long  sym_06082A78
.L_0602DF64:
    .long  sym_06082A74
.L_0602DF68:
    .byte   0xD0, 0x03    /* mov.l .L_0602DF78, r0 */
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DF7C
.L_0602DF72:
    mov.l r3, @r1
    bra     .L_0602DF7E
    nop
.L_0602DF78:
    .long  sym_06082A74
.L_0602DF7C:
    mov.l r2, @r1
.L_0602DF7E:
    mov r4, r0
    .byte   0xD1, 0x07    /* mov.l .L_0602DFA0, r1 */
    tst r1, r0
    bt      .L_0602DFC6
    .byte   0xD0, 0x07    /* mov.l .L_0602DFA4, r0 */
    mov.l @r0, r3
    .byte   0xD1, 0x07    /* mov.l .L_0602DFA8, r1 */
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DFB0
    .byte   0xD0, 0x06    /* mov.l .L_0602DFAC, r0 */
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DFC4
    bra     .L_0602DFBA
    nop
.L_0602DFA0:
    .long  0x00000004
.L_0602DFA4:
    .long  sym_06082A44
.L_0602DFA8:
    .long  sym_06063EEC
.L_0602DFAC:
    .long  sym_06082A5C
.L_0602DFB0:
    .byte   0xD0, 0x03    /* mov.l .L_0602DFC0, r0 */
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DFC4
.L_0602DFBA:
    mov.l r3, @r1
    bra     .L_0602DFC6
    nop
.L_0602DFC0:
    .long  sym_06082A5C
.L_0602DFC4:
    mov.l r2, @r1
.L_0602DFC6:
    mov r4, r0
    .byte   0xD1, 0x07    /* mov.l .L_0602DFE8, r1 */
    tst r1, r0
    bt      .L_0602E00E
    .byte   0xD0, 0x07    /* mov.l .L_0602DFEC, r0 */
    mov.l @r0, r3
    .byte   0xD1, 0x07    /* mov.l .L_0602DFF0, r1 */
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DFF8
    .byte   0xD0, 0x06    /* mov.l .L_0602DFF4, r0 */
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602E00C
    bra     .L_0602E002
    nop
.L_0602DFE8:
    .long  0x00000002
.L_0602DFEC:
    .long  sym_06082A48
.L_0602DFF0:
    .long  sym_06063EF0
.L_0602DFF4:
    .long  sym_06082A60
.L_0602DFF8:
    .byte   0xD0, 0x03    /* mov.l .L_0602E008, r0 */
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602E00C
.L_0602E002:
    mov.l r3, @r1
    bra     .L_0602E00E
    nop
.L_0602E008:
    .long  sym_06082A60
.L_0602E00C:
    mov.l r2, @r1
.L_0602E00E:
    mov r4, r0
    .byte   0xD1, 0x07    /* mov.l .L_0602E030, r1 */
    tst r1, r0
    bt      .L_0602E056
    .byte   0xD0, 0x07    /* mov.l .L_0602E034, r0 */
    mov.l @r0, r3
    .byte   0xD1, 0x07    /* mov.l .L_0602E038, r1 */
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602E040
    .byte   0xD0, 0x06    /* mov.l .L_0602E03C, r0 */
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602E054
    bra     .L_0602E04A
    nop
.L_0602E030:
    .long  0x00000001
.L_0602E034:
    .long  sym_06082A50
.L_0602E038:
    .long  sym_06063E24
.L_0602E03C:
    .long  sym_06082A68
.L_0602E040:
    .byte   0xD0, 0x03    /* mov.l .L_0602E050, r0 */
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602E054
.L_0602E04A:
    mov.l r3, @r1
    bra     .L_0602E056
    nop
.L_0602E050:
    .long  sym_06082A68
.L_0602E054:
    mov.l r2, @r1
.L_0602E056:
    rts
    nop
.L_0602E05A:
    .byte   0xD1, 0x04    /* mov.l .L_0602E06C, r1 */
    mov.l @r1, r0
    add #0x1, r0
    mov.l r0, @r1
    .byte   0xD1, 0x03    /* mov.l .L_0602E070, r1 */
    .byte   0xD0, 0x03    /* mov.l .L_0602E074, r0 */
    mov.l r0, @r1
    .byte   0xAE, 0x52    /* bra 0x0602DD10 (external) */
    nop
.L_0602E06C:
    .long  sym_06082A38
.L_0602E070:
    .long  sym_06082A30
.L_0602E074:
    .long  0x00000001

    .global loc_0602E078
loc_0602E078:
    .byte   0xDD, 0x12    /* mov.l .L_pool_0602E0C4, r13 */

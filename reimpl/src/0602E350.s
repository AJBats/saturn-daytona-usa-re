	.text
    .global rbg_rot_matrix_calc
rbg_rot_matrix_calc:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_0602E380, r0
    mov.l @r0, r0
    mov.w   .L_wpool_0602E374, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602e376, r1
    mov.l r3, @(r0, r1)
    mov.w   .L_wpool_0602E378, r1
    mov.l @(r0, r1), r3
    mov.l   .L_pool_0602E39C, r4
    cmp/gt r3, r4
    bt      .L_0602E36E
.L_0602E36E:
    bra     .L_0602E3F4
    nop

    .global DAT_0602e372
DAT_0602e372:
    clrmac
.L_wpool_0602E374:
    .short  0x0030

    .global DAT_0602e376
DAT_0602e376:
    .short  0x0020
.L_wpool_0602E378:
    .short  0x0008
    .short  0x0000
    .long  sound_cmd_dispatch
.L_pool_0602E380:
    .long  sym_0607E940
    .long  sym_0602E450
    .long  sym_0602E4BC
    .long  collision_detect_main
    .long  0x00000000
    .long  sym_0603053C
    .long  checkpoint_detect
.L_pool_0602E39C:
    .long  0x00000096
    .long  0xD10BD30C
    .long  0x2132D10C
    .long  0x6212D10C
    .long  0x2122D10C
    .long  0xD20C2122
    .long  0xD10C9308
    .long  0x2132D30C
    .long  0xD10C0136
    .long  0x93039103
    .long  0x0136AF19
    .long  0x00090000
    .long  0x01B40000
    .long  sym_0605A1D0
    .long  0x00010000
    .long  sym_06082A34
    .long  sym_06063E20
    .long  sym_06082A30
    .long  0x00000000
    .long  sym_0605A1C4
    .long  0x00000001
    .long  sym_0607EAC8
.L_0602E3F4:
    mov.l   .L_pool_0602E414, r1
    mov.l @r1, r3
    mov.l   .L_pool_0602E418, r4
    cmp/gt r3, r4
    .byte   0x89, 0x1C    /* bt 0x0602E438 (external) */
    mov.l   .L_pool_0602E41C, r2
    mov.b @r2, r2
    mov.l   .L_pool_0602E420, r1
    and r1, r2
    tst r2, r2
    bt      .L_0602E42C
    mov.l   .L_pool_0602E424, r0
    mov.l   .L_pool_0602E428, r1
    mov.b r1, @r0
    .byte   0xA0, 0x12    /* bra 0x0602E438 (external) */
    nop
.L_pool_0602E414:
    .long  sym_06082A2C
.L_pool_0602E418:
    .long  0x00000028
.L_pool_0602E41C:
    .long  sym_06082A25
.L_pool_0602E420:
    .long  0x00000004
.L_pool_0602E424:
    .long  sym_06082A26
.L_pool_0602E428:
    .long  0x00000000
.L_0602E42C:
    .byte   0xDD, 0x07    /* mov.l .L_pool_0602E44C, r13 */

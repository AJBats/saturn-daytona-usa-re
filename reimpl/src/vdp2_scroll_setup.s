
    .section .text.FUN_0602E264


    .global vdp2_scroll_setup
    .type vdp2_scroll_setup, @function
vdp2_scroll_setup:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_car_state_ptr, r0
    mov.l @r0, r0
    mov.w   .L_scroll_coeff_offset, r5
    add r0, r5
    mov.w   .L_scroll_clamp_lo, r3
    mov.l @r5, r1
    mov.w   .L_scroll_clamp_hi, r4
    cmp/gt r3, r1
    bt      .L_above_lower_bound
    mov r3, r1
    bra     .L_normalize
    nop

    .global DAT_0602e284
DAT_0602e284:
    mov.b r1, @(r0, r2)
    .word 0x0088

    .global DAT_0602e288
DAT_0602e288:
    mov.b r4, @(r0, r0)

    .global DAT_0602e28a
DAT_0602e28a:
    stc vbr, r0
    .word 0x0011

    .global DAT_0602e28e
DAT_0602e28e:
    .word 0x0208
.L_scroll_coeff_offset:
    .2byte  0x00E4                         /* struct offset +0xE4: scroll coefficient field [HIGH] */
.L_scroll_clamp_lo:
    .2byte  0x0708                         /* scroll coefficient lower clamp bound [HIGH] */
.L_scroll_clamp_hi:
    .2byte  0x2134                         /* scroll coefficient upper clamp bound [HIGH] */
    .2byte  0x0000                         /* padding */
    .4byte  sym_0607EAC8                   /* data table: VDP2 state struct */
    .4byte  0x00000001                     /* data table: constant 1 */
    .4byte  0x00000028                     /* data table: constant 0x28 (40) */
    .4byte  0x00000000                     /* data table: constant 0 */
    .4byte  0x000000C0                     /* data table: constant 0xC0 (192) */
    .4byte  sym_0602F3EC                   /* data table: damage_mac_core */
    .4byte  sym_0602F7BC                   /* data table: per-car timer tick */
    .4byte  sym_06030A06                   /* data table: per-car physics init */
    .4byte  sym_06030EE0                   /* data table: per-car state update */
    .4byte  brake_force_apply              /* data table: brake force application */
    .4byte  accel_response                 /* data table: acceleration response */
.L_car_state_ptr:
    .4byte  sym_0607E940                   /* pool: pointer to car state struct */
    .4byte  sym_0602D82A                   /* pool: display intensity curve fn */
    .4byte  sym_0602F17C                   /* pool: camera state machine fn */
.L_above_lower_bound:
    cmp/gt r1, r4
    bt      .L_normalize
    mov r4, r1
.L_normalize:
    sub r3, r1
    shll8 r1
    .byte   0x90, 0x0D    /* mov.w .L_wpool_0602E2F8, r0 */ ! r0 = divisor (from next TU pool)
    shlr r1
    .byte   0xDC, 0x07    /* mov.l .L_pool_0602E2FC, r12 */ ! r12 = next dispatch fn (from next TU pool)

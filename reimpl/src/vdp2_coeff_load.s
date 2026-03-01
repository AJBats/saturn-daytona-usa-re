
    .section .text.FUN_0602E2E0


    .global vdp2_coeff_load
    .type vdp2_coeff_load, @function
vdp2_coeff_load:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    nop
    mov #0x7F, r4
    mov #0x1, r3
    cmp/gt r3, r0
    bt      .L_check_upper
    mov r3, r0
    bra     .L_clamped
    nop
    .4byte  0x14B40000
    .4byte  sym_0602ECCC
.L_check_upper:
    cmp/gt r0, r4
    bt      .L_clamped
    mov r4, r0
.L_clamped:
    mov r0, r5
    mov #0x1, r4
    .byte   0xDC, 0x1C    /* mov.l .L_pool_0602E37C, r12 */  ! r12 = next fn ptr (cross-TU pool)

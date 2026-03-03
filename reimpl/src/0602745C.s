
    .section .text.FUN_0602745C


    .global atan2_full
    .type atan2_full, @function
atan2_full:
    sts.l pr, @-r15
    cmp/pz r5
    .byte   0xB0, 0x7C    /* bsr 0x0602755C (external: fpdiv_setup) */
    .word 0x0729
    .byte   0xBF, 0x88    /* bsr 0x06027378 (external: atan_piecewise) */
    mov r0, r4
    lds.l @r15+, pr
    tst r7, r7
    bf      .L_06027472
    .byte   0xD2, 0x21    /* mov.l .L_pool_060274F4, r2 ! r2 = 0x8000 (180 degrees) */
    add r2, r0
.L_06027472:
    rts
    exts.w r0, r0

    .global isqrt
isqrt:
    cmp/pl r4
    bf/s    .L_06027494
    mov #0x0, r0
    .byte   0xD2, 0x1D    /* mov.l .L_pool_060274F4, r2 ! r2 = 0x8000 (initial bit = MSB) */
.L_0602747E:
    add r2, r0
    mul.l r0, r0
    sts macl, r3
    cmp/eq r4, r3
    bt      .L_06027494
    cmp/hi r4, r3
    bf      .L_0602748E
    sub r2, r0
.L_0602748E:
    shlr r2
    cmp/pl r2
    bt      .L_0602747E
.L_06027494:
    rts
    shll8 r0

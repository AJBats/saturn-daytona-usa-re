
    .section .text.FUN_0602E726


    .global vdp2_light_intensity
    .type vdp2_light_intensity, @function
vdp2_light_intensity:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    add r0, r7
    cmp/pz r7
    .byte   0x89, 0x17    /* bt 0x0602E764 (external) */
    mov r7, r4
    shlr2 r4
    .byte   0xDD, 0x09    /* mov.l .L_pool_0602E760, r13 */

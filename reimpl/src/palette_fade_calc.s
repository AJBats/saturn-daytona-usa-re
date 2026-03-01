
    .section .text.FUN_0602E61C


    .global palette_fade_calc
    .type palette_fade_calc, @function
palette_fade_calc:
    mov.l r14, @-r15
    mov.l   .L_pool_0602E639, r9
    mov.l @r9, r9
    mov.l   .L_pool_0602E63D, r0
    mov.l @(r0, r9), r7
    mov.l   .L_pool_0602E641, r0
    mov.l @(r0, r9), r10
    mov.l   .L_pool_0602E645, r3
    mov.l @r3, r3
    cmp/eq r10, r3
    bf      .L_check_param_b
    .byte   0xA0, 0xAB    /* bra 0x0602E78C (external) */  ! target matches param A — skip fade, jump to epilogue
    nop
    .2byte  0x0000
.L_pool_0602E639:
    .4byte  sym_0607E944
.L_pool_0602E63D:
    .4byte  0x00000008
.L_pool_0602E641:
    .4byte  0x00000238
.L_pool_0602E645:
    .4byte  DAT_06083264
.L_check_param_b:
    mov.l   .L_pool_0602E655, r3
    mov.l @r3, r3
    cmp/eq r10, r3
    bt      .L_begin_fade_calc
    .byte   0xA0, 0x4A    /* bra 0x0602E6E8 (external) */  ! neither param matches — branch to alternate path
    nop
.L_pool_0602E655:
    .4byte  DAT_06083268
.L_begin_fade_calc:
    .byte   0xD0, 0x14    /* mov.l .L_pool_0602E6AC, r0 */ ! r0 = color component A offset (from next TU pool)
    mov.l @(r0, r10), r8
    sub r7, r8
    cmp/pz r8
    bt      .L_delta_a_positive
    neg r8, r8
.L_delta_a_positive:
    .byte   0xD0, 0x12    /* mov.l .L_pool_0602E6B0, r0 */ ! r0 = color component B offset (from next TU pool)
    mov.l @(r0, r9), r3
    mov.l @(r0, r10), r5
    .byte   0xD0, 0x12    /* mov.l .L_pool_0602E6B4, r0 */ ! r0 = color component C offset (from next TU pool)
    mov.l @(r0, r9), r6
    mov.l @(r0, r10), r4
    mov.l r4, @-r15
    sub r3, r5
    mov r5, r4
    .byte   0xDD, 0x10    /* mov.l .L_pool_0602E6B8, r13 */ ! r13 = fade step function ptr (from next TU pool)

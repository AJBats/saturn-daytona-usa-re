
    .section .text.FUN_0600E060


    .global FUN_0600E060
    .type FUN_0600E060, @function
FUN_0600E060:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x21    /* mov.l .L_pool_0600E0EC, r14 */
    .byte   0xD3, 0x21    /* mov.l .L_pool_0600E0F0, r3 */
    .byte   0xD2, 0x22    /* mov.l .L_pool_0600E0F4, r2 */
    mov.l @r14, r14
    mov.l @r3, r3
    shar r3
    mov.w r3, @r2
    mov.l   .L_0600E0F8, r2
    mov.l r14, @r2
    .byte   0xD1, 0x20    /* mov.l .L_pool_0600E0FC, r1 */
    .byte   0xD2, 0x21    /* mov.l .L_pool_0600E100, r2 */
    mov.l r1, @r2
    .byte   0xD2, 0x21    /* mov.l .L_pool_0600E104, r2 */
    jsr @r2
    nop
    mov.l @(24, r14), r5
    .byte   0xD3, 0x20    /* mov.l .L_pool_0600E108, r3 */
    jsr @r3
    mov.l @(16, r14), r4
    .byte   0xD3, 0x1F    /* mov.l .L_pool_0600E10C, r3 */
    mov.l r0, @r3
    .byte   0xD3, 0x1F    /* mov.l .L_pool_0600E110, r3 */
    jsr @r3
    nop
    mov.l   .L_0600E114, r13
    .byte   0xD4, 0x1F    /* mov.l .L_pool_0600E118, r4 */
    jsr @r13
    mov #0x0, r5
    .byte   0xD4, 0x1F    /* mov.l .L_pool_0600E11C, r4 */
    jsr @r13
    mov #0x1, r5
    .byte   0xD4, 0x1E    /* mov.l .L_pool_0600E120, r4 */
    jsr @r13
    mov #0x2, r5
    .byte   0xD4, 0x1E    /* mov.l .L_pool_0600E124, r4 */
    jsr @r13
    mov #0x3, r5
    mov r14, r4
    .byte   0xD3, 0x1D    /* mov.l .L_pool_0600E128, r3 */
    jsr @r3
    add #0x14, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    bra     FUN_0600E0C0
    mov.l @r15+, r14


    /* THEORY: ai_car_loop — iterates cars i=1..sym_0607EA98, skipping car 0
       (player). Branches on sym_0607EBC4 & 0x8000: if clear, calls
       FUN_0600e71a (car_physics_pipeline); if set, calls FUN_0600E906.
       Car 0 has its own code path at ~0x0602EF00. Ghidra decompilation +
       empirical (watchpoint on car 0 speed shows different writer PC). */
    .global FUN_0600E0C0
    .type FUN_0600E0C0, @function
FUN_0600E0C0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_0600E12C, r8
    mov.l   .L_0600E130, r9
    mov.w   .L_0600E0EA, r10
    mov.l   .L_0600E134, r11
    mov.l   .L_0600E0F8, r12
    mov.l   .L_0600E114, r14
    mov.l   .L_0600E138, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600E19A
    bra     .L_0600E192
    mov #0x1, r13
.L_0600E0EA:
    .2byte  0x0268
    .4byte  sym_0607E944
    .4byte  sym_0607EA98
    .4byte  sym_060786CA
.L_0600E0F8:
    .4byte  sym_0607E940
    .4byte  sym_06078B68
    .4byte  sym_0607E948
    .4byte  sym_0602DC18
    .4byte  sym_06006838
    .4byte  sym_060786B8
    .4byte  FUN_06005ECC
.L_0600E114:
    .4byte  FUN_06027CA4
    .4byte  sym_06063EB0
    .4byte  sym_06063E9C
    .4byte  sym_06063ED8
    .4byte  sym_06063EC4
    .4byte  FUN_06033020
.L_0600E12C:
    .4byte  sym_0607EBC4
.L_0600E130:
    .4byte  sym_06078900
.L_0600E134:
    .4byte  0x00008000
.L_0600E138:
    .4byte  sym_0607EAE0
.L_0600E13C:
    mul.l r10, r13
    mov.l   .L_0600E1B0, r3
    sts macl, r2
    add r9, r2
    jsr @r3
    mov.l r2, @r12
    mov.l   .L_0600E1B4, r3
    jsr @r3
    nop
    mov.l @r8, r2
    and r11, r2
    tst r2, r2
    bt      .L_0600E15E
    .reloc ., R_SH_IND12W, FUN_0600E906 - 4
    .2byte 0xB000    /* bsr FUN_0600E906 (linker-resolved) */
    nop
    bra     .L_0600E190
    nop
.L_0600E15E:
    .reloc ., R_SH_IND12W, FUN_0600E71A - 4
    .2byte 0xB000    /* bsr FUN_0600E71A (linker-resolved) */
    nop
    mov.l @r12, r2
    mov r2, r0
    mov.b @(1, r0), r0
    tst #0x80, r0
    bt      .L_0600E190
    mov.l   .L_0600E1B8, r3
    jsr @r3
    nop
    mov.l   .L_0600E1BC, r4
    jsr @r14
    mov #0x0, r5
    mov.l   .L_0600E1C0, r4
    jsr @r14
    mov #0x1, r5
    mov.l   .L_0600E1C4, r4
    jsr @r14
    mov #0x2, r5
    mov.l   .L_0600E1C8, r4
    jsr @r14
    mov #0x3, r5
    mov.l   .L_0600E1CC, r3
    jsr @r3
    mov #0x1, r4
.L_0600E190:
    add #0x1, r13
.L_0600E192:
    mov.l   .L_0600E1D0, r2
    mov.l @r2, r2
    cmp/hs r2, r13
    bf      .L_0600E13C
.L_0600E19A:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0600E1B0:
    .4byte  sym_06030A06
.L_0600E1B4:
    .4byte  sym_06030EE0
.L_0600E1B8:
    .4byte  FUN_060061C8
.L_0600E1BC:
    .4byte  sym_06063EB0
.L_0600E1C0:
    .4byte  sym_06063E9C
.L_0600E1C4:
    .4byte  sym_06063ED8
.L_0600E1C8:
    .4byte  sym_06063EC4
.L_0600E1CC:
    .4byte  sym_0603053C
.L_0600E1D0:
    .4byte  sym_0607EA98


    .section .text.FUN_0601416C


    .global race_variant_setup_a
    .type race_variant_setup_a, @function
race_variant_setup_a:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   .L_wpool_06014212, r8
    mov.l   .L_pool_06014214, r12
    mov.l   .L_pool_06014218, r14
    mov.l   .L_pool_0601421C, r3
    jsr @r3
    mov #0x3, r9
    mov #0x0, r13
    mov.l   .L_pool_06014220, r2
    mov.l r2, @r15
.L_06014190:
    mov.l   .L_pool_06014224, r3
    mov.l @r3, r3
    cmp/hs r3, r13
    bt      .L_060141F8
    mov.l   .L_pool_06014228, r3
    jsr @r3
    nop
    mov r14, r6
    mov r8, r5
    mov r13, r4
    mov.l   .L_pool_0601422C, r3
    mov.l   .L_pool_06014230, r2
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov r14, r6
    mov r14, r5
    mov.l   .L_pool_06014234, r3
    jsr @r3
    mov r14, r4
    mov.l   .L_pool_06014238, r4
    add r13, r4
    mov.b @r4, r4
    extu.b r4, r4
    mov r4, r0
    cmp/eq #0x2E, r0
    bf      .L_060141CC
    bra     .L_060141D0
    mov #0x1A, r11
.L_060141CC:
    mov r4, r11
    add #-0x41, r11
.L_060141D0:
    extu.b r11, r11
    mov #0x4, r5
    mov.l   .L_pool_0601423C, r4
    mov.l   .L_pool_06014240, r3
    extu.b r11, r10
    shll2 r10
    add r10, r4
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l @r15, r5
    mov.l   .L_pool_06014244, r4
    mov.l   .L_pool_06014248, r3
    mov.w @r5, r5
    add r10, r4
    jsr @r3
    mov.l @r4, r4
    mov.l @r12, r2
    add #-0x30, r2
    mov.l r2, @r12
.L_060141F8:
    add #0x1, r13
    cmp/hs r9, r13
    bf      .L_06014190
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_06014212:
    .2byte  0xCCCD                      /* sign-extended: -0x3333 (Y position offset) */
.L_pool_06014214:
    .4byte  sym_06089EDC                /* render budget counter (decremented by 0x30 per car) */
.L_pool_06014218:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_pool_0601421C:
    .4byte  sym_06026E0C                /* pre-transform initialization function */
.L_pool_06014220:
    .4byte  sym_06089E4A                /* per-mode 16-bit scale factor */
.L_pool_06014224:
    .4byte  sym_06084B18                /* active car count (read as 32-bit) */
.L_pool_06014228:
    .4byte  sym_06026DBC                /* per-object pre-transform setup */
.L_pool_0601422C:
    .4byte  sym_0605AD4C                /* car object position table (array of ptrs) */
.L_pool_06014230:
    .4byte  sym_06026E2E                /* transform dispatch (sets position) */
.L_pool_06014234:
    .4byte  mat_scale_columns           /* uniform column scale function */
.L_pool_06014238:
    .4byte  sym_06084B14                /* car variant character array (byte per car) */
.L_pool_0601423C:
    .4byte  sym_06062338                /* chain A model lookup table (27 entries) */
.L_pool_06014240:
    .4byte  sym_06031D8C                /* transform chain A dispatch */
.L_pool_06014244:
    .4byte  sym_060622C0                /* chain B model lookup table (27 entries) */
.L_pool_06014248:
    .4byte  sym_06031A28                /* transform chain B dispatch (scaled) */

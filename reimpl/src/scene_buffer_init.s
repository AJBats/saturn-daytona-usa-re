
    .section .text.FUN_06038120


    .global scene_buffer_init
    .type scene_buffer_init, @function
scene_buffer_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov #0x40, r9
    mov.l r8, @-r15
    add #-0x4, r15
    mov.w   .L_wpool_0603815A, r10
    mov.l   .L_pool_0603815C, r11
    mov.l   .L_pool_06038160, r12
    mov.l   .L_pool_06038164, r6
    mov.l   .L_pool_06038168, r8
    mov.l @r8, r0
    cmp/eq #0x8, r0
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    cmp/eq #0x4, r0
    .word 0x0029
    xor #0x1, r0
    and r1, r0
    tst r0, r0
    bt/s    .L_mode_accepted
    extu.w r13, r14
    bra     .L_epilogue
    nop
.L_wpool_0603815A:
    .2byte  0x0200                      /* 512 = max entries for scene A loop */
.L_pool_0603815C:
    .4byte  sym_060A3DF8                /* scene transform struct (64 bytes) */
.L_pool_06038160:
    .4byte  sym_060A3C70                /* scene buffer B output (for loop 2) */
.L_pool_06038164:
    .4byte  sym_060A2470                /* scene buffer A output (for loop 1) */
.L_pool_06038168:
    .4byte  sym_060635A8                /* scene mode / command slot selector */
.L_mode_accepted:
    mov.b @(3, r4), r0
    extu.b r0, r0
    and #0x1, r0
    extu.w r0, r5
    mov.b @(2, r4), r0
    extu.b r0, r0
    shll r0
    and #0x2, r0
    or r0, r5
    mov.b @(1, r4), r0
    extu.b r0, r0
    shll2 r0
    and #0x4, r0
    or r0, r5
    mov.b @r4, r0
    extu.b r0, r0
    shll2 r0
    shll r0
    and #0x8, r0
    or r0, r5
    mov.b @(4, r4), r0
    extu.b r0, r0
    shll2 r0
    shll2 r0
    and #0x30, r0
    or r0, r5
    mov r11, r7
    mov r11, r3
    add #0x2C, r3
    mov.l r3, @r15
    mov.l @r8, r0
    cmp/eq #0x8, r0
    bf/s    .L_mode_is_4
    add #0x30, r7
    extu.w r5, r3
    shll8 r3
    mov.l   .L_mask_byte1, r2
    and r2, r3
    extu.w r3, r5
    mov r11, r7
    add #0x34, r7
.L_mode_is_4:
    mov #0x2A, r0
    mov r6, r2
    mov.w r5, @(r0, r11)
    mov r12, r2
    mov.l   .L_pool_060382A4, r5
    mov.l @(8, r4), r3
    mov.l r3, @r5
    mov.l r6, @(4, r5)
    mov.l   .L_pool_060382A8, r5
    mov.l @(12, r4), r3
    mov.l r3, @r5
    mov.l r12, @(4, r5)
    mov.l   .L_pool_060382AC, r5
    mov.l @(8, r4), r3
    shlr r3
    and r5, r3
    mov.l r3, @r7
    mov.l @r15, r2
    mov.l @(12, r4), r3
    shlr r3
    and r5, r3
    mov.l r3, @r2
    mov.b @(4, r4), r0
    mov r0, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_check_mode_1
    mov #0x1, r14
.L_check_mode_1:
    mov.b @(4, r4), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_mode_2
    mov #0x2, r14
.L_check_mode_2:
    mov.b @(4, r4), r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_check_mode_3
    mov #0x4, r14
.L_check_mode_3:
    mov.b @(4, r4), r0
    extu.b r0, r0
    cmp/eq #0x3, r0
    bf      .L_loop1_setup
    mov #0x8, r14
.L_loop1_setup:
    extu.w r13, r7
    extu.w r13, r5
.L_loop1_top:
    mov.b @(2, r4), r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_loop1_skip_y
    extu.w r7, r0
    mov r5, r3
    mov r5, r2
    shll2 r0
    add #0x1, r7
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    exts.w r3, r3
    mov r4, r1
    add #0x10, r1
    add r1, r3
    mov.l @r3, r3
    mov.l r3, @(r0, r6)
.L_loop1_skip_y:
    mov.b @(1, r4), r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_loop1_skip_x
    extu.w r7, r0
    mov r5, r3
    mov r5, r2
    shll2 r0
    add #0x1, r7
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    exts.w r3, r3
    mov r4, r1
    add #0x10, r1
    add r1, r3
    mov.l @(4, r3), r3
    mov.l r3, @(r0, r6)
.L_loop1_skip_x:
    mov.b @r4, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_loop1_skip_z
    extu.w r7, r0
    mov r5, r3
    mov r5, r2
    shll2 r0
    add #0x1, r7
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    exts.w r3, r3
    mov r4, r1
    add #0x10, r1
    add r1, r3
    mov.l @(8, r3), r3
    mov.l r3, @(r0, r6)
.L_loop1_skip_z:
    extu.w r14, r2
    add r2, r5
    extu.w r5, r3
    cmp/ge r10, r3
    bf      .L_loop1_top
    mov.l   .L_pool_060382B0, r3
    mov.w r7, @r3
    extu.w r13, r7
    extu.w r13, r5
.L_loop2_pre:
    bra     .L_loop2_top
    nop
.L_mask_byte1:
    .4byte  0x0000FF00                  /* byte 1 mask (for mode 8 bitmask shift) */
.L_pool_060382A4:
    .4byte  sym_060A3D70                /* scene A config: size + dest pointer pair */
.L_pool_060382A8:
    .4byte  sym_060A3D78                /* scene B config: size + dest pointer pair */
.L_pool_060382AC:
    .4byte  0x0007FFFF                  /* 19-bit mask for half-size viewport dimension */
.L_pool_060382B0:
    .4byte  sym_060635A0                /* scene A entry count (word) */
.L_loop2_top:
    mov.b @(3, r4), r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_loop2_skip
    extu.w r7, r0
    shll2 r0
    add #0x1, r7
    extu.w r5, r3
    shll2 r3
    mov.w   .L_wpool_060382F4, r2
    add r4, r2
    add r2, r3
    mov.l @r3, r3
    mov.l r3, @(r0, r12)
.L_loop2_skip:
    add #0x1, r5
    extu.w r5, r2
    cmp/ge r9, r2
    bf      .L_loop2_pre
    mov.l   .L_pool_060382F8, r3
    mov.w r7, @r3
    mov #0x2, r2
    mov.l   .L_pool_060382FC, r3
    mov.w r2, @r3
.L_epilogue:
    add #0x4, r15
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_060382F4:
    .2byte  0x1810                      /* offset from config base to coord array */
    .2byte  0xFFFF                      /* padding */
.L_pool_060382F8:
    .4byte  sym_060635A2                /* scene B entry count (word) */
.L_pool_060382FC:
    .4byte  sym_060635AC                /* scene ready flag (2 = data ready for dispatch) */

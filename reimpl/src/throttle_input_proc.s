
    .section .text.FUN_06011F92


    .global throttle_input_proc
    .type throttle_input_proc, @function
throttle_input_proc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    add #-0x8, r15
    mov #0x10, r8
    mov.w   .L_wpool_06011FDA, r9
    mov #0x0, r10
    mov #0x1F, r14
    mov r9, r7
    add #-0x20, r7
    mov.w   DAT_06011fd6, r6
    exts.w r10, r11

.L_06011FB2:
    mov.w @r4, r13
    mov.w @r5, r12
    exts.w r13, r3
    mov.w r10, @r4
    exts.w r12, r2
    and r14, r3
    add #0x1, r3
    mov.l r3, @r15
    mov.l r2, @(4, r15)
    cmp/ge r2, r3
    .word 0x0029
    xor #0x1, r0
    and r14, r0
    tst r0, r0
    bt      .L_06011FDC
    bra     .L_06011FE0
    mov.l @r15, r2

    .global DAT_06011fd4
DAT_06011fd4:
    .word 0x03E0

    .global DAT_06011fd6
DAT_06011fd6:
    .2byte  0x7C00                 /* blue channel mask (bits 10-14) — loaded by mov.w */
    .2byte  0xF800                 /* (adjacent data, not used by this function) */
.L_wpool_06011FDA:
    .2byte  0x0400

.L_06011FDC:
    mov.l @(4, r15), r2
    and r14, r2
.L_06011FE0:
    mov.w @r4, r1
    exts.w r12, r3
    or r2, r1
    exts.w r13, r2
    mov.w r1, @r4
    and r7, r2
    add #0x20, r2
    mov.l r2, @r15
    mov.l r3, @(4, r15)
    cmp/ge r3, r2
    .word 0x0029
    xor #0x1, r0
    and r7, r0
    tst r0, r0
    bt      .L_06012002
    bra     .L_06012006
    mov.l @r15, r3
.L_06012002:
    mov.l @(4, r15), r3
    and r7, r3
.L_06012006:
    exts.w r13, r2
    mov.w @r4, r1
    and r6, r2
    or r3, r1
    add r9, r2
    mov.w r1, @r4
    exts.w r12, r3
    mov.l r2, @r15
    mov.l r3, @(4, r15)
    cmp/ge r3, r2
    .word 0x0029
    xor #0x1, r0
    and r6, r0
    tst r0, r0
    bt      .L_06012028
    bra     .L_0601202C
    mov.l @r15, r3
.L_06012028:
    mov.l @(4, r15), r3
    and r6, r3
.L_0601202C:
    mov.w @r4, r1
    add #0x1, r11
    or r3, r1
    exts.w r11, r3
    mov.w r1, @r4
    add #0x2, r4
    cmp/ge r8, r3
    bf/s    .L_06011FB2
    add #0x2, r5

    add #0x8, r15
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

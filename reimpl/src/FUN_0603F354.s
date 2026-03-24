
    .section .text.FUN_0603F354


    .global FUN_0603F354
    .type FUN_0603F354, @function
FUN_0603F354:
    sts.l pr, @-r15
    add #-0x38, r15
    mov.l   .L_pool_0603F380, r10
    mov.l r4, @r15
    mov r15, r4
    bsr     .L_0603F3DA
    add #0x24, r4
    bra     .L_0603F3BC
    mov #0x0, r13
.L_0603F366:
    mov r15, r5
    mov r15, r4
    add #0x4, r5
    .reloc ., R_SH_IND12W, FUN_0603F582 - 4
    .2byte 0xB000    /* bsr FUN_0603F582 (linker-resolved) */
    add #0x24, r4
    mov r15, r2
    add #0x4, r2
    mov.b @r2, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0603F384
    bra     .L_0603F3C0
    nop
.L_pool_0603F380:
    .4byte  FUN_06036DDC
.L_0603F384:
    cmp/gt r12, r13
    bf      .L_0603F3A0
    mov #0xC, r6
    mov r15, r5
    mov r14, r4
    .byte   0xD3, 0x28    /* mov.l .L_pool_0603F430, r3 */
    add #0x4, r5
    add #0x10, r5
    jsr @r3
    add #-0xC, r4
    tst r0, r0
    bf      .L_0603F3A0
    bra     .L_0603F3B6
    nop
.L_0603F3A0:
    mov r15, r5
    add #0x4, r5
    .reloc ., R_SH_IND12W, FUN_0603F84C - 4
    .2byte 0xB000    /* bsr FUN_0603F84C (linker-resolved) */
    mov r14, r4
    mov #0xC, r6
    mov r15, r5
    mov r14, r4
    add #0x4, r5
    add #0x10, r5
    jsr @r10
    add #0xC, r4
.L_0603F3B6:
    add #0x18, r14
    add #0x1, r13
    add #-0x1, r11
.L_0603F3BC:
    cmp/pl r11
    bt      .L_0603F366
.L_0603F3C0:
    add #-0x18, r14
    mov.b @(11, r14), r0
    or #0x80, r0
    mov.b r0, @(11, r14)
    mov r13, r0
    add #0x38, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .global FUN_0603F3DA
FUN_0603F3DA:

.L_0603F3DA:
    mov.l r5, @r4
    .byte   0xD3, 0x15    /* mov.l .L_pool_0603F434, r3 */
    .byte   0x92, 0x24    /* mov.w .L_wpool_0603F42A, r2 */
    mov.l @r3, r3
    add r3, r2
    mov.l r2, @(4, r4)
    mov #-0x1, r3
    mov.l r3, @(8, r4)
    mov.l @r5, r2
    mov.l @(16, r2), r3
    mov #0x0, r2
    mov.l r3, @(16, r4)
    rts
    mov.l r2, @(12, r4)


    .global FUN_0603F3F6
    .type FUN_0603F3F6, @function
FUN_0603F3F6:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov r5, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.w   .L_0603F42C, r11
    mov.l @r14, r0
    tst r0, r0
    bf/s    .L_0603F43C
    mov r6, r13
    mov r13, r6
    mov #0x0, r5
    mov r10, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x04    /* mov.l .L_pool_0603F439, r3 */
    jmp @r3
    mov.l @r15+, r14
    .2byte  0x043C
.L_0603F42C:
    .2byte  0x0800
    .2byte  0xFFFF
    .4byte  sym_06036D94
    .4byte  sym_060A4D14
.L_pool_0603F439:
    .4byte  sym_06036D78
.L_0603F43C:
    mov.l @(8, r14), r4
    mov r4, r0
    cmp/eq #-0x1, r0
    bt      .L_0603F44A
    .byte   0x93, 0x3D    /* mov.w .L_0603F42C_ext, r3 */
    cmp/ge r3, r4
    bf      .L_0603F45A
.L_0603F44A:
    mov r11, r7
    mov.l @(4, r14), r6
    mov #0x1, r5
    .byte   0xD3, 0x1C    /* mov.l .L_fn_cmd_multi_validate, r3 */
    jsr @r3
    mov.l @r14, r4
    mov #0x0, r2
    mov.l r2, @(8, r14)
.L_0603F45A:
    mov.l @(8, r14), r9
    neg r9, r12
    add r11, r12
    cmp/hs r12, r13
    bt      .L_0603F468
    bra     .L_0603F46C
    mov r13, r12
.L_0603F468:
    mov r11, r12
    sub r9, r12
.L_0603F46C:
    mov r12, r6
    mov.l @(4, r14), r5
    .byte   0xD3, 0x15    /* mov.l .L_fn_memmove, r3 */
    add r9, r5
    jsr @r3
    mov r10, r4
    mov.l @(8, r14), r2
    add r12, r2
    cmp/hs r13, r12
    bt/s    .L_0603F49E
    mov.l r2, @(8, r14)
    sub r12, r13
    mov r11, r7
    mov #0x1, r5
    .byte   0xD3, 0x0E    /* mov.l .L_fn_cmd_multi_validate, r3 */
    mov.l @(4, r14), r6
    jsr @r3
    mov.l @r14, r4
    mov r13, r6
    mov r12, r4
    .byte   0xD3, 0x0C    /* mov.l .L_fn_memmove, r3 */
    mov.l @(4, r14), r5
    jsr @r3
    add r10, r4
    mov.l r13, @(8, r14)
.L_0603F49E:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xE601

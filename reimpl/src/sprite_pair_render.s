
    .section .text.FUN_06026590


    .global sprite_pair_render
    .type sprite_pair_render, @function
sprite_pair_render:
    mov.l r14, @-r15
    extu.w r5, r5
    mov.l r13, @-r15
    mov #0x0, r14
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x50, r11
    mov.l r9, @-r15
    mov #0x40, r9
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.w   .L_06026668, r8
    mov.l   .L_0602666C, r13
    mov r8, r3
    add #0x1, r3
    cmp/eq r3, r5
    bf/s    .L_0602661E
    mov r4, r12
    mov r13, r4
    mov r13, r6
    add r8, r6
.L_060265BC:
    mov r4, r5
    extu.w r14, r1
    mov.l @r4, r3
    mov.l @(4, r5), r2
    add #0xC, r4
    mov.w r14, @r2
    mov r4, r5
    mov.w r14, @r3
    mov.l @r4, r3
    mov.l @(4, r5), r2
    add #0xC, r4
    mov.w r1, @r2
    mov.w r1, @r3
    cmp/hs r6, r4
    bf      .L_060265BC
    exts.b r12, r0
    cmp/eq #0x4, r0
    bf      .L_060265E4
    .byte   0xBE, 0xBF    /* bsr 0x06026362 (external) */
    nop
.L_060265E4:
    mov r14, r5
    mov r14, r4
    exts.b r12, r10
    shll2 r10
    mov.l   .L_06026670, r3
    bra     .L_06026616
    add r3, r10
.L_060265F2:
    mov.l @r10, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_06026600
    bra     .L_06026612
    nop
.L_06026600:
    mov.l @r10, r6
    add r5, r6
    mov.l @r6, r3
    mov.w @(4, r6), r0
    mov r0, r2
    extu.w r2, r2
    mov.w @r3, r1
    or r2, r1
    mov.w r1, @r3
.L_06026612:
    add #0x8, r5
    add #0x8, r4
.L_06026616:
    cmp/hs r11, r4
    bf      .L_060265F2
    bra     .L_06026692
    nop
.L_0602661E:
    mov r13, r4
    mov r13, r6
    add r8, r6
.L_06026624:
    mov r4, r5
    extu.w r14, r1
    mov.l @r4, r2
    mov.l @(4, r5), r3
    add #0xC, r4
    mov.w r14, @r3
    mov r4, r5
    mov.w r14, @r2
    mov.l @r4, r3
    mov.l @(4, r5), r2
    add #0xC, r4
    mov.w r1, @r2
    mov.w r1, @r3
    cmp/hs r6, r4
    bf      .L_06026624
    exts.b r12, r0
    cmp/eq #0x4, r0
    bf      .L_0602664C
    .byte   0xBF, 0x21    /* bsr 0x0602648E (external) */
    nop
.L_0602664C:
    mov r14, r5
    mov r14, r4
    exts.b r12, r10
    shll2 r10
    mov.l   .L_06026674, r3
    bra     .L_0602668E
    add r3, r10
.L_0602665A:
    mov.l @r10, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_06026678
    bra     .L_0602668A
    nop
.L_06026668:
    .2byte  0x00A8                          /* 14 entries * 12 bytes = 168 = 0xA8 */
    .2byte  0xFFFF                          /* padding / unused */
.L_0602666C:
    .4byte  sym_060610BC                    /* slot element table (12-byte stride) */
.L_06026670:
    .4byte  sym_06061170                    /* render record ptr table A (5 x 4-byte ptrs) */
.L_06026674:
    .4byte  sym_06061184                    /* render record ptr table B (5 x 4-byte ptrs) */
.L_06026678:
    mov.l @r10, r6
    add r5, r6
    mov.l @r6, r3
    mov.w @(4, r6), r0
    mov r0, r2
    extu.w r2, r2
    mov.w @r3, r1
    or r2, r1
    mov.w r1, @r3
.L_0602668A:
    add #0x8, r5
    add #0x8, r4
.L_0602668E:
    cmp/hs r9, r4
    bf      .L_0602665A
.L_06026692:
    exts.b r12, r0
    cmp/eq #0x4, r0
    bf      .L_060266BA
    mov r13, r4
    mov r13, r6
    add r8, r6
.L_0602669E:
    mov r4, r5
    mov.l @r4, r2
    mov.l @(4, r5), r3
    add #0xC, r4
    mov.w @r3, r1
    mov r4, r5
    mov.w r1, @r2
    mov.l @r4, r3
    mov.l @(4, r5), r2
    add #0xC, r4
    mov.w @r2, r1
    mov.w r1, @r3
    cmp/hs r6, r4
    bf      .L_0602669E
.L_060266BA:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

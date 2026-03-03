	.text
    .global scene_color_intensity
scene_color_intensity:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_0603881C, r9
    mov.l   .L_06038820, r10
    mov.w   DAT_0603881a, r11
    mov.l   .L_06038824, r12
    mov r4, r14
    mov r5, r13
    mov.l   .L_06038828, r0
    bra     .L_060387F2
    mov.l @r0, r0
.L_060387B4:
    cmp/gt r9, r14
    bf      .L_060387BC
    bra     .L_060387CA
    mov r9, r14
.L_060387BC:
    cmp/ge r11, r14
    bt      .L_060387C4
    bra     .L_060387CA
    mov r11, r14
.L_060387C4:
    tst r14, r14
    bf      .L_060387CA
    mov r12, r14
.L_060387CA:
    cmp/gt r9, r13
    bf      .L_060387D2
    bra     .L_060387E0
    mov r9, r13
.L_060387D2:
    cmp/ge r11, r13
    bt      .L_060387DA
    bra     .L_060387E0
    mov r11, r13
.L_060387DA:
    tst r13, r13
    bf      .L_060387E0
    mov r12, r13
.L_060387E0:
    mov r14, r5
    jsr @r10
    mov r12, r4
    mov r0, r14
    mov r13, r5
    jsr @r10
    mov r12, r4
    bra     .L_06038802
    mov r0, r13
.L_060387F2:
    cmp/eq #0x1, r0
    bt      .L_060387E0
    cmp/eq #0x2, r0
    bt      .L_060387E0
    cmp/eq #0x4, r0
    bt      .L_060387B4
    cmp/eq #0x8, r0
    bt      .L_060387B4
.L_06038802:
    mov.l   .L_0603882C, r6
    mov.l   .L_06038830, r5
    mov.l   .L_06038834, r4
    mov.l   .L_06038828, r0
    bra     .L_06038894
    mov.l @r0, r0
.L_0603880E:
    mov.l r14, @(8, r4)
    bra     .L_060388A4
    mov.l r13, @(12, r4)
.L_06038814:
    mov.l r14, @(24, r4)
    bra     .L_060388A4
    mov.l r13, @(28, r4)

    .global DAT_0603881a
DAT_0603881a:
    .short  0x4000
.L_0603881C:
    .long  0x00FF0000
.L_06038820:
    .long  sym_0603C0A0
.L_06038824:
    .long  0x00010000
.L_06038828:
    .long  sym_060635A8
.L_0603882C:
    .long  sym_060A3E38
.L_06038830:
    .long  sym_060A3E68
.L_06038834:
    .long  sym_060A3DF8
.L_06038838:
    mov r5, r4
    mov #0x4C, r0
    mov.l r14, @(r0, r4)
    mov #0x50, r0
    mov.l r13, @(r0, r4)
    mov.w @(4, r6), r0
    extu.w r0, r0
    tst #0xFF, r0
    bt      .L_060388A4
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_060388B8, r3
    jmp @r3
    mov.l @r15+, r14
.L_06038862:
    mov #0x4C, r0
    mov.w   .L_060388B4, r4
    add r5, r4
    mov.l r14, @(r0, r4)
    mov #0x50, r0
    mov.l r13, @(r0, r4)
    mov.w @(4, r6), r0
    mov.l   .L_060388BC, r2
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_060388A4
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_060388B8, r3
    jmp @r3
    mov.l @r15+, r14
.L_06038894:
    cmp/eq #0x1, r0
    bt      .L_06038838
    cmp/eq #0x2, r0
    bt      .L_06038862
    cmp/eq #0x4, r0
    bt      .L_0603880E
    cmp/eq #0x8, r0
    bt      .L_06038814
.L_060388A4:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_060388B4:
    .short  0x0080
    .short  0xFFFF
.L_060388B8:
    .long  scene_color_matrix
.L_060388BC:
    .long  0x0000FF00

	.text
    .global vdp_mode_select
vdp_mode_select:
    mov.l r14, @-r15
    mov #0xA, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l r4, @(8, r15)
    mov.l r5, @(4, r15)
    mov.l r6, @r15
    mov.l r7, @(12, r15)
    mov.l   .L_06010DBC, r3
    mov.l @r3, r3
    cmp/hs r2, r3
    bf      .L_06010DC0
    bra     .L_06010E8A
    nop
.L_06010DBC:
    .long  sym_060788A0
.L_06010DC0:
    mov.l   .L_06010EA0, r14
    mov.l   .L_06010EA4, r3
    mov.l @r14, r2
    add #0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_06010EA8, r8
    mov.l @(12, r15), r6
    mov.l @r15, r5
    jsr @r8
    mov.l @(4, r15), r4
    mov.l   .L_06010EAC, r4
    mov.l   .L_06010EB0, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_06010EB4, r13
    mov.l   .L_06010EB8, r5
    mov.l   .L_06010EBC, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_06010EC0, r9
    mov.l   .L_06010EC4, r11
    mov.l   .L_06010EC8, r12
    mov.l @(8, r15), r10
    mov.l   .L_06010ECC, r3
    mov.l @r12, r6
    shll r10
    add r3, r10
    mov.w @r10, r5
    jsr @r11
    mov.l @r9, r4
    mov.l   .L_06010ED0, r3
    jsr @r3
    nop
    mov.l   .L_06010ED4, r6
    mov.l   .L_06010ED8, r5
    mov.l   .L_06010EDC, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_06010EE0, r5
    mov.l   .L_06010EBC, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(4, r13), r4
    mov.l @(4, r12), r6
    mov.w @r10, r5
    jsr @r11
    mov.l @(4, r9), r4
    mov.l @r14, r2
    mov.l   .L_06010ED0, r3
    add #-0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_06010EE4, r6
    mov.l   .L_06010EE8, r5
    mov.l   .L_06010EEC, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_06010EF0, r5
    mov.l   .L_06010EBC, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(8, r13), r4
    mov.l @(8, r12), r6
    mov.w @r10, r5
    jsr @r11
    mov.l @(8, r9), r4
    mov.l @r14, r2
    mov.l   .L_06010ED0, r3
    add #-0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_06010EF4, r6
    mov.l   .L_06010EF8, r5
    mov.l   .L_06010EFC, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_06010F00, r5
    mov.l   .L_06010EBC, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(12, r13), r4
    mov.l @(12, r12), r6
    mov.w @r10, r5
    jsr @r11
    mov.l @(12, r9), r4
    mov.l @r14, r2
    add #-0x30, r2
    mov r2, r3
    add #-0x30, r3
    mov.l r3, @r14
.L_06010E8A:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .short  0xFFFF
.L_06010EA0:
    .long  sym_06089EDC
.L_06010EA4:
    .long  sym_06026E0C
.L_06010EA8:
    .long  sym_06026E2E
.L_06010EAC:
    .long  sym_06078878
.L_06010EB0:
    .long  mat_rot_y
.L_06010EB4:
    .long  sym_0606212C
.L_06010EB8:
    .long  sym_060621D8
.L_06010EBC:
    .long  sym_06031D8C
.L_06010EC0:
    .long  sym_060620D8
.L_06010EC4:
    .long  sym_06031A28
.L_06010EC8:
    .long  sym_06062180
.L_06010ECC:
    .long  sym_06089E44
.L_06010ED0:
    .long  sym_06026DBC
.L_06010ED4:
    .long  sym_06044648
.L_06010ED8:
    .long  sym_06044644
.L_06010EDC:
    .long  sym_06044640
.L_06010EE0:
    .long  sym_060621DC
.L_06010EE4:
    .long  sym_06044654
.L_06010EE8:
    .long  sym_06044650
.L_06010EEC:
    .long  sym_0604464C
.L_06010EF0:
    .long  sym_060621E0
.L_06010EF4:
    .long  sym_06044678
.L_06010EF8:
    .long  sym_06044674
.L_06010EFC:
    .long  sym_06044670
.L_06010F00:
    .long  sym_060621E4

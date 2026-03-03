
    .section .text.FUN_06018738


    .global course0_bg_load
    .type course0_bg_load, @function
course0_bg_load:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_060187EC, r11
    mov.l   .L_060187F0, r12
    mov.l   .L_060187F4, r14
    mov.l   .L_060187F8, r13
    mov.w   .L_060187DE, r6
    mov.l   .L_060187FC, r9
    mov.l   .L_06018800, r4
    jsr @r13
    mov r9, r5
    mov.w   .L_060187E0, r6
    mov.w   .L_060187DE, r5
    mov.l   .L_06018804, r4
    jsr @r13
    add r9, r5
    mov.w   .L_060187E2, r6
    mov.w   .L_060187E4, r5
    add r9, r5
    jsr @r13
    mov r14, r4
    mov.l   .L_06018808, r6
    mov.l   .L_0601880C, r9
    mov.l   .L_06018810, r4
    jsr @r13
    mov r9, r5
    mov.w   .L_060187E6, r6
    mov.l   .L_06018814, r5
    mov.l   .L_06018818, r4
    jsr @r13
    add r9, r5
    mov.w   .L_060187E8, r6
    mov.w   .L_060187EA, r5
    mov.l   .L_0601881C, r4
    jsr @r13
    add r9, r5
    mov.w   .L_060187E6, r6
    mov.l   .L_06018820, r5
    mov.l   .L_06018824, r4
    jsr @r13
    add r9, r5
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
.L_0601879C:
    mov r4, r2
    mov r4, r3
    add #0x2, r5
    add r11, r2
    add r12, r3
    add #0x4, r4
    mov.l @r2, r1
    mov r4, r6
    add r14, r1
    mov r4, r2
    mov.l r1, @r3
    add r11, r2
    mov r4, r3
    mov.l @r2, r1
    add r12, r3
    add r14, r1
    mov.l r1, @r3
    cmp/ge r10, r5
    bf/s    .L_0601879C
    add #0x4, r4
    mov.l   .L_06018828, r4
    mov.l   .L_0601882C, r3
    jsr @r3
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_06018830, r3
    jmp @r3
    mov.l @r15+, r14
.L_060187DE:
    .2byte  0x07DC
.L_060187E0:
    .2byte  0x3100
.L_060187E2:
    .2byte  0x4F80
.L_060187E4:
    .2byte  0x38DC
.L_060187E6:
    .2byte  0x3000
.L_060187E8:
    .2byte  0x4000
.L_060187EA:
    .2byte  0x6660
.L_060187EC:
    .4byte  sym_0605D1DC
.L_060187F0:
    .4byte  sym_06085FD0
.L_060187F4:
    .4byte  sym_060D6900
.L_060187F8:
    .4byte  memcpy_long_idx
.L_060187FC:
    .4byte  0x00200000
.L_06018800:
    .4byte  sym_060D5840
.L_06018804:
    .4byte  sym_060C6000
.L_06018808:
    .4byte  0x00018000
.L_0601880C:
    .4byte  0x00240000
.L_06018810:
    .4byte  sym_060A6000
.L_06018814:
    .4byte  0x0000A660
.L_06018818:
    .4byte  sym_060BF000
.L_0601881C:
    .4byte  sym_060C2000
.L_06018820:
    .4byte  0x0000B108
.L_06018824:
    .4byte  0x002F8000
.L_06018828:
    .4byte  sym_0607EAD8
.L_0601882C:
    .4byte  sound_init_sequence
.L_06018830:
    .4byte  render_batch_proc

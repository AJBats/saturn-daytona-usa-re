
    .section .text.FUN_06018834


    .global course1_bg_load
    .type course1_bg_load, @function
course1_bg_load:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_060188E4, r11
    mov.l   .L_060188E8, r12
    mov.l   .L_060188EC, r14
    mov.l   .L_060188F0, r13
    mov.w   .L_060188DA, r6
    mov.l   .L_060188F4, r9
    mov.l   .L_060188F8, r4
    jsr @r13
    mov r9, r5
    mov.w   .L_060188DC, r6
    mov.w   .L_060188DA, r5
    mov.l   .L_060188FC, r4
    jsr @r13
    add r9, r5
    mov.l   .L_06018900, r6
    mov.l   .L_06018904, r5
    add r9, r5
    jsr @r13
    mov r14, r4
    mov.l   .L_06018908, r6
    mov.l   .L_0601890C, r9
    mov.l   .L_06018910, r4
    jsr @r13
    mov r9, r5
    mov.w   .L_060188DE, r6
    mov.l   .L_06018914, r5
    mov.l   .L_06018918, r4
    jsr @r13
    add r9, r5
    mov.w   .L_060188E0, r6
    mov.l   .L_0601891C, r5
    mov.l   .L_06018920, r4
    jsr @r13
    add r9, r5
    mov.w   .L_060188DE, r6
    mov.l   .L_06018924, r5
    mov.l   .L_06018928, r4
    jsr @r13
    add r9, r5
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
.L_06018898:
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
    bf/s    .L_06018898
    add #0x4, r4
    mov.l   .L_0601892C, r4
    mov.l   .L_06018930, r3
    jsr @r3
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_06018934, r3
    jmp @r3
    mov.l @r15+, r14
.L_060188DA:
    .2byte  0x0CC8
.L_060188DC:
    .2byte  0x7A00
.L_060188DE:
    .2byte  0x3000
.L_060188E0:
    .2byte  0x4000
    .2byte  0xFFFF
.L_060188E4:
    .4byte  sym_0605D1FC
.L_060188E8:
    .4byte  sym_06085FD0
.L_060188EC:
    .4byte  sym_060D6900
.L_060188F0:
    .4byte  memcpy_long_idx
.L_060188F4:
    .4byte  0x00200000
.L_060188F8:
    .4byte  sym_060D5840
.L_060188FC:
    .4byte  sym_060C6000
.L_06018900:
    .4byte  0x0000BD00
.L_06018904:
    .4byte  0x000086C8
.L_06018908:
    .4byte  0x00019000
.L_0601890C:
    .4byte  0x00240000
.L_06018910:
    .4byte  sym_060A6000
.L_06018914:
    .4byte  0x0001C0B8
.L_06018918:
    .4byte  sym_060BF000
.L_0601891C:
    .4byte  0x000180B8
.L_06018920:
    .4byte  sym_060C2000
.L_06018924:
    .4byte  0x0001DFE8
.L_06018928:
    .4byte  0x002F8000
.L_0601892C:
    .4byte  sym_0607EAD8
.L_06018930:
    .4byte  sound_init_sequence
.L_06018934:
    .4byte  projection_mgr

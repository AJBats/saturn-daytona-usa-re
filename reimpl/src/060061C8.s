
    .section .text.FUN_060061C8


    .global pre_render_transform
    .type pre_render_transform, @function
pre_render_transform:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06006264, r11
    mov.l   .L_pool_06006268, r3
    mov.l @r11, r11
    mov.l @(16, r11), r14
    mov.l @(20, r11), r13
    jsr @r3
    mov.l @(24, r11), r12
    mov.l   .L_pool_0600626C, r3
    jsr @r3
    nop
    mov.l   .L_pool_06006270, r3
    jsr @r3
    mov.l @(48, r11), r4
    mov.l   .L_pool_06006274, r11
    mov.l   .L_pool_06006278, r5
    mov.l   .L_pool_0600627C, r4
    jsr @r11
    nop
    mov.l   .L_pool_06006280, r5
    mov.l   .L_pool_06006284, r4
    jsr @r11
    nop
    mov.l   .L_pool_06006288, r5
    mov.l   .L_pool_0600628C, r4
    jsr @r11
    nop
    mov.l   .L_pool_06006290, r5
    mov.l   .L_pool_06006294, r4
    jsr @r11
    nop
    mov.l   .L_pool_06006278, r4
    mov.l @r4, r2
    add r14, r2
    mov.l r2, @r4
    mov.l r13, @(4, r4)
    mov.l @(8, r4), r3
    add r12, r3
    mov.l r3, @(8, r4)
    mov.l   .L_pool_06006280, r4
    mov.l @r4, r2
    add r14, r2
    mov.l r2, @r4
    mov.l r13, @(4, r4)
    mov.l @(8, r4), r3
    add r12, r3
    mov.l r3, @(8, r4)
    mov.l   .L_pool_06006288, r4
    mov.l @r4, r2
    add r14, r2
    mov.l r2, @r4
    mov.l r13, @(4, r4)
    mov.l @(8, r4), r3
    add r12, r3
    mov.l r3, @(8, r4)
    mov.l   .L_pool_06006290, r4
    mov.l @r4, r2
    add r14, r2
    mov.l r2, @r4
    mov.l r13, @(4, r4)
    mov.l @(8, r4), r3
    add r12, r3
    mov.l r3, @(8, r4)
    mov.l   .L_pool_06006298, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06006264:
    .4byte  sym_0607E940
.L_pool_06006268:
    .4byte  sym_06026DBC
.L_pool_0600626C:
    .4byte  sym_06026E0C
.L_pool_06006270:
    .4byte  mat_rot_y
.L_pool_06006274:
    .4byte  mat_vec_transform
.L_pool_06006278:
    .4byte  sym_06063E9C
.L_pool_0600627C:
    .4byte  sym_0604464C
.L_pool_06006280:
    .4byte  sym_06063EB0
.L_pool_06006284:
    .4byte  sym_06044640
.L_pool_06006288:
    .4byte  sym_06063ED8
.L_pool_0600628C:
    .4byte  sym_06044658
.L_pool_06006290:
    .4byte  sym_06063EC4
.L_pool_06006294:
    .4byte  sym_06044664
.L_pool_06006298:
    .4byte  sym_06089EDC

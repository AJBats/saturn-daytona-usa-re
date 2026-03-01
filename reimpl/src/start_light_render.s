
    .section .text.FUN_0601A2BC


    .global start_light_render
    .type start_light_render, @function
start_light_render:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601A31C, r4
    mov.l   .L_0601A320, r3
    mov.l @r4, r2
    or r3, r2
    mov.l   .L_0601A324, r3
    jsr @r3
    mov.l r2, @r4
    mov.l   .L_0601A324, r3
    jsr @r3
    nop
    mov.l   .L_0601A328, r14
    jsr @r14
    mov #0x4, r4
    jsr @r14
    mov #0x8, r4
    jsr @r14
    mov #0xC, r4
    mov.l   .L_0601A32C, r3
    jsr @r3
    nop
    mov #0x8, r7
    mov.l   .L_0601A330, r5
    mov.l   .L_0601A334, r4
    mov.l   .L_0601A338, r3
    jsr @r3
    mov #0x0, r6
    mov #0x9, r7
    mov.l   .L_0601A330, r5
    mov.l   .L_0601A33C, r4
    mov.l   .L_0601A338, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_0601A340, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0x0090
    .4byte  sym_0605D4F0
    .4byte  sym_06049AFC
    .4byte  sym_060284AE
.L_0601A31C:
    .4byte  sym_0605B6D8
.L_0601A320:
    .4byte  0x80000000
.L_0601A324:
    .4byte  sym_06026CE0
.L_0601A328:
    .4byte  sym_0602853E
.L_0601A32C:
    .4byte  sym_06028560
.L_0601A330:
    .4byte  0x00017700
.L_0601A334:
    .4byte  0x25E76EFC
.L_0601A338:
    .4byte  sym_0600511E
.L_0601A33C:
    .4byte  0x25E77B18
.L_0601A340:
    .4byte  sym_06085FF2

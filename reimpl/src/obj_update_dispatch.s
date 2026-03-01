
    .section .text.FUN_0602070C


    .global obj_update_dispatch
    .type obj_update_dispatch, @function
obj_update_dispatch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_060207D0, r13
    mov.b r4, @r15
    mov.l   .L_060207D4, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_060207D8, r12
    mov.l @r13, r2
    sub r12, r2
    mov.l r2, @r13
    mov.l   .L_060207DC, r14
    mov.l @r14, r3
    sub r12, r3
    mov.l r3, @r14
    mov r3, r5
    mov.l   .L_060207E0, r3
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_060207E4, r14
    mov.l @r14, r2
    sub r12, r2
    mov.l r2, @r14
    mov r2, r3
    mov.l   .L_060207E8, r11
    mov.l   .L_060207EC, r2
    cmp/gt r2, r3
    bf      .L_06020794
    mov.l @r14, r5
    mov.l   .L_060207F0, r2
    mov.l   .L_060207F4, r4
    mov.l   .L_060207F8, r3
    jsr @r3
    add r2, r5
    mov r0, r4
    mov.l   .L_060207FC, r3
    jsr @r3
    mov.l @r14, r5
    mov r0, r12
    mov.l @r14, r5
    mov.l   .L_060207F0, r2
    mov.l   .L_06020800, r4
    mov.l   .L_060207F8, r3
    jsr @r3
    add r2, r5
    mov r0, r4
    mov.l   .L_060207FC, r3
    jsr @r3
    mov.l @r14, r5
    mov r0, r6
    mov r12, r4
    mov.l   .L_06020804, r7
    mov r0, r5
    mov.l @r11, r2
    mov.l @r7, r3
    sub r2, r4
    sub r3, r5
    mov.l r12, @r11
    mov.l r6, @r7
    mov.l   .L_06020808, r3
    jsr @r3
    mov #0x0, r6
    bra     .L_060207A2
    nop
.L_06020794:
    mov #0x0, r6
    mov.l   .L_0602080C, r3
    mov r6, r5
    jsr @r3
    mov #0x8, r4
    mov #0x0, r2
    mov.l r2, @r11
.L_060207A2:
    mov.l   .L_06020810, r3
    jsr @r3
    nop
    mov.l @r13, r2
    mov.l   .L_060207EC, r3
    cmp/gt r3, r2
    bt      .L_060207C2
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA3, 0x16    /* bra 0x06020DEE (external) */
    mov.l @r15+, r14
.L_060207C2:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_060207D0:
    .4byte  sym_06087818
.L_060207D4:
    .4byte  sym_0603850C
.L_060207D8:
    .4byte  0x00008000
.L_060207DC:
    .4byte  sym_0608781C
.L_060207E0:
    .4byte  scene_color_intensity
.L_060207E4:
    .4byte  sym_06087820
.L_060207E8:
    .4byte  sym_06087810
.L_060207EC:
    .4byte  0x00010000
.L_060207F0:
    .4byte  0xFFFF0000
.L_060207F4:
    .4byte  0x00B00000
.L_060207F8:
    .4byte  fpmul
.L_060207FC:
    .4byte  fpdiv_setup
.L_06020800:
    .4byte  0x00700000
.L_06020804:
    .4byte  sym_06087814
.L_06020808:
    .4byte  scene_data_write_add
.L_0602080C:
    .4byte  display_channel_b
.L_06020810:
    .4byte  sym_06038520

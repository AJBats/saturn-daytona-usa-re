
    .section .text.FUN_060030FC


    .global system_init
    .type system_init, @function
system_init:
    mov.l r14, @-r15
    mov #0x1, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x0, r12
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.l   .L_06003150, r10
    mov.l   .L_06003154, r11
    mov.l   .L_06003158, r13
    mov.l   .L_0600315C, r3
    mov.l @r3, r3
    jsr @r3
    mov r14, r4

.L_0600311A:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0600311A
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.l   .L_06003160, r2
    mov.b r3, @r2
.L_0600312E:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0600312E

    mov.l   .L_06003164, r4
    bra     .L_06003142
    mov.l @r4, r4
.L_0600313E:
    mov.l r12, @r4
    add #0x4, r4
.L_06003142:
    mov.l @r11, r2
    cmp/hs r2, r4
    bf      .L_0600313E

    mov.l   .L_06003168, r4
    bra     .L_06003170
    mov.l @r4, r4
    .2byte  0xFFFF

.L_06003150:
    .4byte  sym_06059C58
.L_06003154:
    .4byte  sym_06059C50
.L_06003158:
    .4byte  0x20100063
.L_0600315C:
    .4byte  sym_06000320
.L_06003160:
    .4byte  0x2010001F
.L_06003164:
    .4byte  sym_06059C4C
.L_06003168:
    .4byte  sym_06059C54
.L_0600316C:
    mov.l r12, @r4
    add #0x4, r4
.L_06003170:
    mov.l @r10, r2
    cmp/hs r2, r4
    bf      .L_0600316C

    mov.l   .L_060031E8, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_060031EC, r3
    jsr @r3
    nop
    mov.l   .L_060031F0, r2
    mov.w   .L_060031E2, r5
    mov.l @r2, r2
    jsr @r2
    mov #-0x1, r4
    mov.l   .L_060031F4, r3
    jsr @r3
    nop
    bsr     vdp_init_dispatch
    nop
    mov.l   .L_060031F8, r3
    jsr @r3
    nop
    mov.l   .L_060031FC, r3
    jsr @r3
    nop
    bsr     sound_timer_init
    nop
    mov.l   .L_06003200, r3
    jsr @r3
    nop
    mov.l   .L_060031F0, r2
    mov.w   .L_060031E4, r4
    mov.l @r2, r2
    jsr @r2
    mov #0x0, r5
    mov.l   .L_06003204, r3
    jsr @r3
    nop
    mov.l   .L_06003208, r3
    jsr @r3
    nop
    mov.l   .L_0600320C, r3
    jsr @r3
    nop
    mov.l   .L_06003210, r3
    jsr @r3
    nop
    mov #0x2, r2
    mov.l   .L_06003214, r3
    mov.l r2, @r3
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_060031E2:
    .2byte  0x0083
.L_060031E4:
    .2byte  0xFF7C
    .2byte  0xFFFF

.L_060031E8:
    .4byte  sym_0603BF7C
.L_060031EC:
    .4byte  sym_06034E58
.L_060031F0:
    .4byte  sym_06000344
.L_060031F4:
    .4byte  cd_progress_notify
.L_060031F8:
    .4byte  engine_init_global
.L_060031FC:
    .4byte  sound_scsp_boot
.L_06003200:
    .4byte  race_sound_handler
.L_06003204:
    .4byte  sym_06005174
.L_06003208:
    .4byte  sym_0601F936
.L_0600320C:
    .4byte  channel_config_a
.L_06003210:
    .4byte  sym_060149E0
.L_06003214:
    .4byte  g_game_state

    .global sound_timer_init
    .type sound_timer_init, @function
sound_timer_init:
    sts.l pr, @-r15
    mov.l   .L_060032C0, r3
    mov.l   .L_060032C4, r5
    mov.l @r3, r3
    jsr @r3
    mov #0x65, r4
    mov.w   .L_060032B2, r5
    mov.b @r5, r4
    mov #0xF, r2
    and r2, r4
    extu.b r4, r0
    or #0x8, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov.w   .L_060032B4, r6
    mov.b @r6, r4
    mov #0x1, r5
    extu.b r4, r4
    or r5, r4
    extu.b r4, r4
    mov.b r4, @r6
    mov.w   .L_060032B6, r4
    mov.b @r4, r3
    extu.b r3, r3
    mov #-0x4, r2
    and r2, r3
    mov.b r3, @r4
    add #0x1, r4
    mov.b @r4, r3
    extu.b r3, r3
    mov #-0x11, r2
    and r2, r3
    extu.b r3, r3
    mov.b r3, @r4
    mov.w   .L_060032B8, r3
    mov.b r5, @r3
    mov #0x66, r2
    add #0x1, r3
    mov #0x0, r4
    mov.b r2, @r3
    add #-0x3, r3
    mov.b r4, @r3
    add #0x1, r3
    lds.l @r15+, pr
    rts
    mov.b r4, @r3

    .global vdp_init_dispatch
    .type vdp_init_dispatch, @function
vdp_init_dispatch:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_060032C0, r14

    mov.l   .L_060032C8, r5
    mov.l @r14, r3
    jsr @r3
    mov #0x4, r4
    mov.l @r14, r2
    mov.l   .L_060032CC, r5
    jsr @r2
    mov #0x6, r4
    mov.l @r14, r3
    mov.l   .L_060032D0, r5
    jsr @r3
    mov #0x9, r4

    mov.l @r14, r2
    mov.l   .L_060032C8, r5
    mov.w   .L_060032BA, r4
    jsr @r2
    nop
    mov.l @r14, r3
    mov.l   .L_060032CC, r5
    mov.w   .L_060032BC, r4
    jsr @r3
    nop
    mov.l @r14, r2
    mov.l   .L_060032D0, r5
    mov.w   .L_060032BE, r4
    lds.l @r15+, pr
    jmp @r2
    mov.l @r15+, r14

.L_060032B2:
    .2byte  0xFE10
.L_060032B4:
    .2byte  0xFE11
.L_060032B6:
    .2byte  0xFE16
.L_060032B8:
    .2byte  0xFE14
.L_060032BA:
    .2byte  0x0104
.L_060032BC:
    .2byte  0x0106
.L_060032BE:
    .2byte  0x0109

.L_060032C0:
    .4byte  sym_06000310
.L_060032C4:
    .4byte  sym_060072E4
.L_060032C8:
    .4byte  sym_06028218
.L_060032CC:
    .4byte  sym_06028230
.L_060032D0:
    .4byte  sym_06028248

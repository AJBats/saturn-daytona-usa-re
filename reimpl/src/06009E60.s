	.text
    .global state_attract_return
state_attract_return:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06009EDC, r3
    jsr @r3
    nop
    mov.l   .L_pool_06009EE0, r14
    jsr @r14
    mov #0x4, r4
    jsr @r14
    mov #0x8, r4
    jsr @r14
    mov #0xC, r4
    mov.l   .L_pool_06009EE4, r3
    jsr @r3
    nop
    mov.l   .L_pool_06009EE8, r14
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x20, r4
    mov.l   .L_pool_06009EEC, r3
    jsr @r3
    nop
    mov.w   .L_wpool_06009EDA, r2
    mov.l   .L_pool_06009EF0, r3
    mov.l r2, @r3
    mov #0x17, r2
    mov.l   .L_pool_06009EF4, r3
    mov.l r2, @r3
    mov #0x0, r2
    mov.l   .L_pool_06009EF8, r3
    mov.w r2, @r3
    mov.l   .L_pool_06009EFC, r3
    jsr @r3
    nop
    mov.l   .L_pool_06009F00, r3
    jsr @r3
    nop
    mov #0x4, r2
    mov.l   .L_pool_06009F04, r3
    mov.w r2, @r3
    mov #0x0, r6
    mov.l   .L_pool_06009F08, r5
    mov.b @r5, r5
    add #0xE, r5
    mov.l r5, @r15
    mov r5, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_pool_06009F0C, r3
    jmp @r3
    mov.l @r15+, r14
.L_wpool_06009EDA:
    .short  0x03E8
.L_pool_06009EDC:
    .long  race_state_pair_2
.L_pool_06009EE0:
    .long  sym_0602853E
.L_pool_06009EE4:
    .long  sym_06028560
.L_pool_06009EE8:
    .long  display_channel_b
.L_pool_06009EEC:
    .long  gameover_channel_setup
.L_pool_06009EF0:
    .long  sym_0607EBCC
.L_pool_06009EF4:
    .long  g_game_state
.L_pool_06009EF8:
    .long  sym_06087804
.L_pool_06009EFC:
    .long  race_init_master
.L_pool_06009F00:
    .long  hud_subsystem_init
.L_pool_06009F04:
    .long  sym_0605A016
.L_pool_06009F08:
    .long  sym_06078648
.L_pool_06009F0C:
    .long  handler_dispatch

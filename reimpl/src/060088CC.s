
    .section .text.FUN_060088CC


    .global state_boot_init
    .type state_boot_init, @function
state_boot_init:
    sts.l pr, @-r15
    mov.l   .L_pool_06008910, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008914, r3
    jsr @r3
    nop
    mov #0x0, r6
    mov.l   .L_06008918, r5
    mov.l   .L_pool_0600891C, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov #0x2, r5
    mov.l   .L_pool_06008920, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_pool_06008924, r3
    jsr @r3
    nop
    mov #0x1, r2
    mov.l   .L_pool_06008928, r3
    mov.l r2, @r3
    mov.l   .L_pool_0600892C, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06008930, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3

    .global loc_0600890A
loc_0600890A:
    mov.l   .L_pool_06008934, r3
    jmp @r3
    nop
.L_pool_06008910:
    .4byte  handler_init_reset
.L_pool_06008914:
    .4byte  render_stage_1
.L_06008918:
    .4byte  0xFFFF0000
.L_pool_0600891C:
    .4byte  display_channel_b
.L_pool_06008920:
    .4byte  handler_dispatch
.L_pool_06008924:
    .4byte  obj_render_update
.L_pool_06008928:
    .4byte  g_game_state
.L_pool_0600892C:
    .4byte  sym_06026CE0
.L_pool_06008930:
    .4byte  sym_06059F44
.L_pool_06008934:
    .4byte  render_stage_2

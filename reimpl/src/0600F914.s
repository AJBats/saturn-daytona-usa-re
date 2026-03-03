
    .section .text.FUN_0600F914


    .global transition_handler_c
    .type transition_handler_c, @function
transition_handler_c:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0600F968, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600F96C, r3
    jsr @r3
    nop
    mov #0x0, r14
    mov.l   .L_pool_0600F970, r3
    extu.w r14, r2
    mov r14, r6
    mov.w r2, @r3
    mov #0x2, r3
    mov.l   .L_pool_0600F974, r1
    mov.w r3, @r1
    mov.l   .L_pool_0600F978, r2
    mov.l   .L_pool_0600F97C, r3
    mov.l r2, @r3
    mov r3, r5
    mov.l @r5, r5
    mov.l   .L_pool_0600F980, r3
    jsr @r3
    mov #0x10, r4
    mov.l   .L_pool_0600F984, r3
    jsr @r3
    nop
    mov #0x7, r2
    mov.l   .L_pool_0600F964, r3
    mov.b r2, @r3
    mov.l   .L_pool_0600F970, r3
    mov.w r14, @r3
    extu.w r14, r4
    lds.l @r15+, pr
    mov.l   .L_pool_0600F988, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
    .4byte  sym_0602853E
.L_pool_0600F964:
    .4byte  sym_0607887F
.L_pool_0600F968:
    .4byte  sprite_buffer_init                  /* sprite command table reset */
.L_pool_0600F96C:
    .4byte  sound_init_bonus
.L_pool_0600F970:
    .4byte  sym_0607886E
.L_pool_0600F974:
    .4byte  sym_0605AAA2
.L_pool_0600F978:
    .4byte  0xFEA00000
.L_pool_0600F97C:
    .4byte  sym_0607885C
.L_pool_0600F980:
    .4byte  display_channel_b
.L_pool_0600F984:
    .4byte  sym_06011450
.L_pool_0600F988:
    .4byte  sprite_batch_renderer

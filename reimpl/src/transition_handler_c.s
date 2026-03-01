
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
    .2byte  0xFFFF                              /* alignment padding */
    .4byte  sym_0602853E                        /* display layer configuration (unreferenced pool) */
.L_pool_0600F964:
    .4byte  sym_0607887F                        /* &game_state byte (7 = results) */
.L_pool_0600F968:
    .4byte  sprite_buffer_init                  /* sprite command table reset */
.L_pool_0600F96C:
    .4byte  sound_init_bonus                    /* results/bonus music init */
.L_pool_0600F970:
    .4byte  sym_0607886E                        /* &transition_state_word (16-bit) */
.L_pool_0600F974:
    .4byte  sym_0605AAA2                        /* &display_config_word (16-bit) */
.L_pool_0600F978:
    .4byte  0xFEA00000                          /* fixed-point negative offset */
.L_pool_0600F97C:
    .4byte  sym_0607885C                        /* &display_slot_ptr (32-bit) */
.L_pool_0600F980:
    .4byte  display_channel_b                   /* display channel B enable */
.L_pool_0600F984:
    .4byte  sym_06011450                        /* render_position_elem_16px */
.L_pool_0600F988:
    .4byte  sprite_batch_renderer               /* sprite batch flush/render */

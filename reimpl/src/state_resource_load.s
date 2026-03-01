
    .section .text.FUN_06008C14


    .global state_resource_load
    .type state_resource_load, @function
state_resource_load:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06008C38, r14
    mov.l   .L_pool_06008C50, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_06008C66
    mov.l   .L_pool_06008C54, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_06008C58
    mov #0x4, r3
    mov.l r3, @r14
    bra     .L_06008C5C
    nop
    .2byte  0xFFFF
.L_pool_06008C38:
    .4byte  g_game_state
    .4byte  disc_course_data_load
    .4byte  sym_06026CE0
    .4byte  sym_06059F44
    .4byte  sym_0605A016
    .4byte  disc_load_complete_check
.L_pool_06008C50:
    .4byte  geom_output_ctrl
.L_pool_06008C54:
    .4byte  sym_0605E0A2
.L_06008C58:
    mov #0x7, r2
    mov.l r2, @r14
.L_06008C5C:
    mov #0x0, r3
    .byte   0xD2, 0x15    /* mov.l .L_pool_06008CB4, r2 */
    mov.b r3, @r2
    bra     .L_06008C6A
    nop
.L_06008C66:
    mov #0x1F, r2
    mov.l r2, @r14
.L_06008C6A:
    mov #0x3, r3
    .byte   0xD2, 0x12    /* mov.l .L_pool_06008CB8, r2 */
    mov.w r3, @r2
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

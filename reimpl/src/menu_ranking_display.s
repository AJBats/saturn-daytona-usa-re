
    .section .text.FUN_0603B6A8


    .global menu_ranking_display
    .type menu_ranking_display, @function
menu_ranking_display:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r5, @r15
    mov.l   .L_pool_0603B724, r14
    mov.w   .L_wpool_0603B71C, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_error_return
    cmp/pz r4
    bf      .L_error_return
    mov.l @r14, r2
    mov.w   .L_wpool_0603B71E, r0
    mov.l @(r0, r2), r3
    cmp/ge r3, r4
    bf      .L_check_mode
.L_error_return:
    mov #-0xA, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_check_mode:
    mov.l @r14, r0
    mov.w   .L_wpool_0603B720, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf      .L_narrow_mode
    mov.l @r14, r5
    mov.w   .L_wpool_0603B71C, r0
    mov.l   .L_pool_0603B728, r3
    jsr @r3
    mov.l @(r0, r5), r5
    mov r0, r5
    mov #0xC, r6
    mov.l   .L_pool_0603B72C, r3
    jsr @r3
    mov.l @r15, r4
    bra     .L_tail_call_result
    nop
.L_narrow_mode:
    mov.l @r14, r5
    mov.w   .L_wpool_0603B71C, r0
    mov.l   .L_pool_0603B730, r3
    jsr @r3
    mov.l @(r0, r5), r5
    mov r0, r5
    mov #0xC, r6
    mov.l   .L_pool_0603B72C, r3
    jsr @r3
    mov.l @r15, r4
.L_tail_call_result:
    mov #0x0, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xA1, 0x14    /* bra 0x0603B93C (external) */
    mov.l @r15+, r14
    .4byte  0x7F044F26
    .4byte  0x000B6EF6
.L_wpool_0603B71C:
    .2byte  0x00A0
.L_wpool_0603B71E:
    .2byte  0x00A4
.L_wpool_0603B720:
    .2byte  0x0098
    .2byte  0xFFFF
.L_pool_0603B724:
    .4byte  sym_060A4D14
.L_pool_0603B728:
    .4byte  sym_0603F1F0
.L_pool_0603B72C:
    .4byte  sym_060360FC
.L_pool_0603B730:
    .4byte  sym_0603F1E0
    .4byte  0xD41DD31E
    .4byte  0x64427404
    .4byte  0x2432D21D
    .4byte  0x1421D31D
    .4byte  0x1432D21D
    .4byte  0x000B1423

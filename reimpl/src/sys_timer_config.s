
    .section .text.FUN_0603B7C0


    .global sys_timer_config
    .type sys_timer_config, @function
sys_timer_config:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0603B840, r10
    mov.l   .L_pool_0603B844, r11
    mov.w   DAT_0603b838, r12
    mov r4, r13
    bra     .L_loop_check
    mov #0x0, r14
.L_loop_body:
    mov.l @r13, r0
    tst r0, r0
    bf      .L_use_stride16
    mov.l @(8, r13), r5
    jsr @r11
    mov r14, r4
    bra     .L_check_flag
    nop
.L_use_stride16:
    mov.l @(8, r13), r5
    jsr @r10
    mov r14, r4
.L_check_flag:
    mov r0, r4
    and r12, r4
    tst r4, r4
    bt      .L_flag_clear
    bra     .L_post_loop
    nop
.L_flag_clear:
    add #0x1, r14
.L_loop_check:
    mov.l @(4, r13), r2
    cmp/ge r2, r14
    bf      .L_loop_body
.L_post_loop:
    mov.l @(4, r13), r2
    cmp/gt r2, r14
    bf      .L_found_in_range
    bra     .L_return
    mov #0x0, r0
.L_found_in_range:
    mov r14, r0
    add #0x1, r0
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xE700
    .4byte  0xD6096462
    .4byte  0x9309343C
    .4byte  0xA0136573
    .4byte  0x9006004E
    .4byte  0x20088B0B
    .4byte  0xA0110009

    .global DAT_0603b838
DAT_0603b838:
    .2byte  0x0080

    .global DAT_0603b83a
DAT_0603b83a:
    .2byte  0x0C3C
    .4byte  0x00ECFFFF
.L_pool_0603B840:
    .4byte  sym_0603F216
.L_pool_0603B844:
    .4byte  sprite_batch_emit
    .4byte  sym_060A4D14
    .4byte  0x921E342C
    .4byte  0x75016362
    .4byte  0x62323523
    .4byte  0x8BE86262
    .4byte  0x63223530
    .4byte  0x8B01A003
    .4byte  0x6473E201
    .4byte  0x90110426
    .4byte  0x000B6043
    .4byte  0xE300900C
    .4byte  0x000B0436
    .4byte  0xD7066572
    .4byte  0x9308353C
    .4byte  0xA00DE600
    .4byte  0x35408B07
    .4byte  0xA00D0009

    .global DAT_0603b88c
DAT_0603b88c:
    .2byte  0x00F0

    .global DAT_0603b88e
DAT_0603b88e:
    .2byte  0x00EC
    .4byte  0x0C3CFFFF
    .4byte  sym_060A4D14
    .4byte  0x923F352C
    .4byte  0x76016372
    .4byte  0x62323623
    .4byte  0x8BEE6272
    .4byte  0x63223630
    .4byte  0x8B00E500
    .4byte  0x000B6053

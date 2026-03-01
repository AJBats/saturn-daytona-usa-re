
    .section .text.FUN_060204D0


    .global obj_list_proc
    .type obj_list_proc, @function
obj_list_proc:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    mov.l   .L_pool_0602051C, r14
    mov.l   .L_pool_06020520, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov r3, r6
    mov.l   .L_pool_06020524, r3
    jsr @r3
    mov #0x20, r4
    mov.l @r14, r2
    mov.l   .L_pool_06020528, r3
    cmp/gt r3, r2
    bf      .L_06020508
    mov.b @r15, r4
    .byte   0xB4, 0x7B    /* bsr 0x06020DEE (external) */
    extu.b r4, r4
    mov.l   .L_pool_06020528, r6
    mov #0x0, r5
    mov #0x20, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_pool_06020524, r3
    jmp @r3
    mov.l @r15+, r14
.L_06020508:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global loc_06020510
loc_06020510:
    rts
    nop
    .4byte  sym_06028560
    .4byte  gameover_channel_setup
.L_pool_0602051C:
    .4byte  sym_06087814
.L_pool_06020520:
    .4byte  0x00180000                  /* display offset stride per entry */
.L_pool_06020524:
    .4byte  display_channel_b
.L_pool_06020528:
    .4byte  0x00980000

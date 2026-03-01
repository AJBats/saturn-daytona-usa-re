
    .section .text.FUN_0603B74C


    .global sys_boot_table_init
    .type sys_boot_table_init, @function
sys_boot_table_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0603B7AC, r14
    mov.l @r14, r3
    mov.l r4, @r3
    .byte   0xBF, 0xEC    /* bsr 0x0603B734 (external) */ ! call external setup
    mov #0x0, r13
    mov.l @r14, r2
    mov.w   DAT_0603b7a4, r0
    mov.l r13, @(r0, r2)
    mov.l @r14, r3
    add #0x14, r0
    mov.l r13, @(r0, r3)
    mov.l @r14, r3
    mov r3, r2
    add #0x8, r0
    mov.l r13, @(r0, r2)
    add #-0x4, r0
    mov.l r13, @(r0, r3)
    mov.l @r14, r3
    add #0xC, r0
    mov.l r13, @(r0, r3)
    mov.l @r14, r3
    add #0xC, r0
    mov.l r13, @(r0, r3)
    mov.l @r14, r5
    mov.w   DAT_0603b7a6, r3
    add r3, r5
    bra     .L_loop_test
    mov r13, r4
.L_loop_clear_entry:
    mov.w   DAT_0603b7a8, r0
    mov.l r13, @(r0, r5)
    mov.w   DAT_0603b7aa, r3
    add r3, r5
    add #0x1, r4
.L_loop_test:
    mov.l @r14, r2
    mov.l @r2, r3
    cmp/ge r3, r4
    bf      .L_loop_clear_entry
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0603b7a4
DAT_0603b7a4:
    .2byte  0x0094

    .global DAT_0603b7a6
DAT_0603b7a6:
    .2byte  0x0C3C

    .global DAT_0603b7a8
DAT_0603b7a8:
    .2byte  0x00EC

    .global DAT_0603b7aa
DAT_0603b7aa:
    .2byte  0x00F0
.L_pool_0603B7AC:
    .4byte  sym_060A4D14
    .4byte  sys_boot_sequence
    .4byte  mem_test_verify
    .4byte  sym_060406A6
    .4byte  sym_0604069A

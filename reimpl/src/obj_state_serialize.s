
    .section .text.FUN_06020D50


    .global obj_state_serialize
    .type obj_state_serialize, @function
obj_state_serialize:
    sts.l pr, @-r15
    add #-0x24, r15
    mov r15, r12
    mov r15, r1
    mov.l   .L_pool_handler_table, r2
    mov.l   .L_pool_slot_array_base, r13
    mov.l   .L_pool_memcpy_long, r3
    jsr @r3
    mov #0x24, r0
    mov #0x0, r14
.L_obj_loop:
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bt      .L_skip_dispatch
    extu.b r14, r0
    mov r0, r3
    shll2 r0
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r0
    exts.w r0, r0
    mov.b @(r0, r13), r0
    extu.b r0, r0
    add #-0x1, r0
    shll2 r0
    mov.l @(r0, r12), r3
    jsr @r3
    mov r14, r4
.L_skip_dispatch:
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r11, r2
    bf      .L_obj_loop
    add #0x24, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06020db2
DAT_06020db2:
    mov.b @(r0, r2), r1
    .4byte  sym_06087C6C
    .4byte  sym_060785FC
    .4byte  sym_060280F8
    .4byte  sym_0605A008
.L_pool_slot_array_base:
    .4byte  sym_0608782C                /* object slot array base */
.L_pool_handler_table:
    .4byte  sym_0605F5A8                /* handler function pointer table */
.L_pool_memcpy_long:
    .4byte  sym_06035168                /* memcpy_long utility */

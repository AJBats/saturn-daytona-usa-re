
    .section .text.FUN_0600CE66


    .global collision_detect_main
    .type collision_detect_main, @function
collision_detect_main:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x09    /* mov.l .L_pool_car_state_ptr, r14 */ ! r14 = &car_state_ptr
    mov.w   DAT_0600ce8e, r0
    mov.l @r14, r14
    mov.l @(r0, r14), r3
    add #0x4, r0
    mov.l r3, @(r0, r14)
    mov r14, r0
    mov.b @(3, r0), r0
    tst #0x8, r0
    bf      .L_proximity_set
    .byte   0xBF, 0x5F    /* bsr 0x0600CD40 (external) */ ! call track_pos_query (checkpoint advance)
    nop
    bra     .L_update_from_segment
    nop

    .global DAT_0600ce86
DAT_0600ce86:
    mov.b r14, @(r0, r1)

    .global DAT_0600ce88
DAT_0600ce88:
    mov.b r8, @(r0, r1)

    .global DAT_0600ce8a
DAT_0600ce8a:
    .word 0x01E0

    .global DAT_0600ce8c
DAT_0600ce8c:
    shll r0

    .global DAT_0600ce8e
DAT_0600ce8e:
    .2byte  0x01EC
.L_pool_car_state_ptr:
    .4byte  sym_0607E940
    .4byte  sym_0607EA9C
    .4byte  atan2
.L_proximity_set:
    .byte   0xBF, 0x98    /* bsr 0x0600CDD0 (external) */ ! call race_heading_calc
    nop
.L_update_from_segment:
    .byte   0x90, 0x4B    /* mov.w .L_wpool_0600CF3A, r0 */ ! r0 = 0x0184 (segment index offset, cross-TU pool)
    .byte   0xD3, 0x28    /* mov.l .L_pool_0600CF44, r3 */  ! r3 = &seg_table_ptr (sym_0607EB84, cross-TU pool)
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    shll2 r2
    add #0x68, r0
    add r3, r2
    mov.w @r2, r2
    extu.w r2, r2
    mov.l r2, @(r0, r14)
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

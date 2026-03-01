
    .section .text.FUN_06041382


    .global error_trap_handler
    .type error_trap_handler, @function
error_trap_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xDE, 0x1A    /* mov.l .L_pool_060413F5, r14 */  ! r14 = &sym_060A5400 (state base indirect ptr)
    mov.l @r14, r3
    add #0x18, r3
    mov.l r3, @(4, r15)
    add r4, r3
    mov.b @r3, r3
    tst r3, r3
    bt      .L_slot_inactive
    mov.l @(4, r15), r3
    add r5, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_both_slots_active
.L_slot_inactive:
    mov #-0x7, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_both_slots_active:
    mov.l @r14, r3
    mov.w   .L_evt_channel_flag_offset, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_channel_free
    mov #-0x1, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_channel_free:
    mov.l @r14, r3
    mov #0x1, r2
    mov.w   .L_evt_channel_flag_offset, r0
    mov.l r2, @(r0, r3)
    mov.l @r14, r3
    add #0x4, r0
    mov.l r4, @(r0, r3)
    add #0x4, r0
    mov.l @r14, r3
    mov.l r5, @(r0, r3)
    mov.l @r14, r3
    add #0x4, r0
    mov.l r6, @(r0, r3)
    add #0x4, r0
    mov.l @r14, r3
    mov.l r7, @(r0, r3)
    .byte   0xB5, 0x82    /* bsr 0x06041EE8 (external) */  ! call track_edge_validate
    mov r15, r4
    mov #0x0, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_evt_channel_flag_offset:
    .2byte  0x0348                                         /* [HIGH] offset to event channel active flag in state struct */
    .4byte  ai_recovery_handler
.L_pool_060413F5:
    .4byte  sym_060A5400
    .4byte  0xD3149026
    .4byte  0x6332003E
    .4byte  0x20088901
    .4byte  0x000BE000
    .4byte  0xE001000B
    .2byte  0x0009

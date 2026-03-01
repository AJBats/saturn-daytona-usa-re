
    .section .text.FUN_0604087C


    .global watchdog_timer_reset
    .type watchdog_timer_reset, @function
watchdog_timer_reset:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_pool_evt_reg_save, r3
    jsr @r3
    mov.l @(4, r4), r4
    mov.l @r15, r4
    mov.l @(20, r4), r4
    add #0x4, r15
    mov.l   .L_pool_slot_free_zone, r3
    jmp @r3
    lds.l @r15+, pr

    .global sym_06040894
sym_06040894:
    mov.l @(36, r4), r0
    extu.b r5, r5
    rts
    mov.l r5, @(36, r4)

    .global DAT_0604089c
DAT_0604089c:
    mac.l @r15+, @r0+
    .word 0xFFFF
    .4byte  track_segment_interp
    .4byte  state_field_read
.L_pool_evt_reg_save:
    .4byte  evt_reg_save
.L_pool_slot_free_zone:
    .4byte  sym_06040EBA

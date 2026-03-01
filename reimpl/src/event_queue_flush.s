
    .section .text.FUN_06040C60


    .global event_queue_flush
    .type event_queue_flush, @function
event_queue_flush:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l r5, @(4, r15)
    mov.l r4, @(8, r15)
    mov.l   .L_pool_fn_brake_handler, r3
    jsr @r3
    mov r15, r4
    mov r14, r0
    cmp/eq #-0x1, r0
    bf      .L_dispatch
    mov.l @(4, r15), r14
    mov.l @(12, r14), r14
.L_dispatch:
    mov #0x1, r6
    mov r14, r5
    .byte   0xBE, 0xB3    /* bsr 0x060409E6 (external) */ ! call evt_checkpoint_handler
    mov.l @(8, r15), r4
    mov.l   .L_pool_evt_record_base, r2
    mov #0x0, r3
    mov #0x10, r0
    mov.b r3, @(r0, r2)
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_fn_brake_handler:
    .4byte  ai_brake_handler
.L_pool_evt_record_base:
    .4byte  sym_0606367C

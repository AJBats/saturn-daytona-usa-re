
    .section .text.FUN_0600E410


    .global car_update_simple
    .type car_update_simple, @function
car_update_simple:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_car_array_base, r14
    mov.l   .L_pool_active_car, r3
    mov.l @r14, r14
    mov.l r14, @r3
    mov.l   .L_pool_fn_gas_force, r3
    jsr @r3
    nop
    mov.l   .L_pool_fn_brake_force, r3
    jsr @r3
    nop
    mov.l   .L_pool_fn_car_setup, r3
    jsr @r3
    nop
    mov.l   .L_pool_fn_car_state, r3
    jsr @r3
    nop
    .byte   0xB1, 0x71    /* bsr 0x0600E71A (external physics step) */
    nop
    mov.l   .L_pool_speed_coeff, r5
    mov.l   .L_pool_fn_fpmul, r3
    jsr @r3
    mov.l @(12, r14), r4
    shlr16 r0
    mov.w   DAT_0600e456, r1
    exts.w r0, r0
    add r14, r1
    mov.l r0, @r1
    mov.w   .L_wpool_display_speed_a_offset, r1
    add r14, r1
    mov.l r0, @r1
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600e456
DAT_0600e456:
    .2byte  0x00E4              /* car struct offset: display speed B */
.L_wpool_display_speed_a_offset:
    .2byte  0x00E0              /* [HIGH] car struct offset: display speed A */
    .2byte  0xFFFF              /* padding */
.L_pool_car_array_base:
    .4byte  sym_0607E944        /* car array base pointer */
.L_pool_active_car:
    .4byte  sym_0607E940        /* active car pointer (global) */
.L_pool_fn_gas_force:
    .4byte  gas_force_apply     /* throttle force computation */
.L_pool_fn_brake_force:
    .4byte  brake_force_apply   /* brake force computation */
.L_pool_fn_car_setup:
    .4byte  sym_06030A06        /* car setup/config step */
.L_pool_fn_car_state:
    .4byte  sym_06030EE0        /* car state update step */
.L_pool_speed_coeff:
    .4byte  0x066505B3          /* speed→display conversion coefficient */
.L_pool_fn_fpmul:
    .4byte  fpmul               /* fixed-point multiply */


    .section .text.FUN_06034E24


    .global smpc_cmd_builder
    .type smpc_cmd_builder, @function
smpc_cmd_builder:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   _pool_input_proc_analog, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x12, r3
    extu.b r14, r14
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov.b r0, @(1, r2)
    mov.l   _pool_input_proc_buttons, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
_pool_input_proc_analog:
    .4byte  input_proc_analog
_pool_input_proc_buttons:
    .4byte  input_proc_buttons

    .global sym_06034E58
sym_06034E58:
    add #-0x4, r15
    mov #0x0, r3
    mov.l   _pool_sh2_state_flag, r2
    mov.l r3, @r2
    bra     .L_06034E64
    nop

.L_06034E64:
    mov.l   _pool_sf_ptr, r0
    mov.l @r0, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x1, r0
    cmp/eq #0x1, r0
    bt      .L_06034E64

    mov.l   _pool_sf_ptr, r2
    mov.l @r2, r2
    mov #0x1, r3
    mov.b r3, @r2
    mov.l   _pool_comreg_ptr, r2
    mov.l @r2, r2
    mov.l   _pool_sshon_cmd, r3
    mov.b @r3, r3
    mov.b r3, @r2
    bra     .L_06034E88
    nop

.L_06034E88:
    mov.l   _pool_sf_ptr, r0
    mov.l @r0, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x1, r0
    cmp/eq #0x1, r0
    bt      .L_06034E88

    mov #0x0, r2
    mov r2, r0
    mov.w r0, @(2, r15)
    bra     .L_06034EAA
    nop

.L_06034EA0:
    mov.w @(2, r15), r0
    mov r0, r2
    add #0x1, r2
    mov r2, r0
    mov.w r0, @(2, r15)

.L_06034EAA:
    mov.w @(2, r15), r0
    mov r0, r3
    extu.w r3, r3
    mov.w   _wpool_delay_limit, r2
    cmp/ge r2, r3
    bf      .L_06034EA0

    mov.l   _pool_sh2_callback_ptr, r2
    mov.l @r2, r2
    mov.l   _pool_slave_main_loop, r3
    mov.l r3, @r2

    mov.l   _pool_sf_ptr, r2
    mov.l @r2, r2
    mov #0x1, r3
    mov.b r3, @r2
    mov.l   _pool_comreg_ptr, r2
    mov.l @r2, r2
    mov.l   _pool_intback_cmd, r3
    mov.b @r3, r3
    mov.b r3, @r2
    bra     .L_06034ED4
    nop

.L_06034ED4:
    mov.l   _pool_sf_ptr, r0
    mov.l @r0, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x1, r0
    cmp/eq #0x1, r0
    bt      .L_06034ED4
    add #0x4, r15
    rts
    nop

_wpool_delay_limit:
    .2byte  0x03E8
    .2byte  0xFFFF

_pool_sh2_state_flag:
    .4byte  sym_06063578
_pool_sf_ptr:
    .4byte  sym_0606358C
_pool_comreg_ptr:
    .4byte  sym_06063584
_pool_sshon_cmd:
    .4byte  sym_06059CAD
_pool_sh2_callback_ptr:
    .4byte  sym_06063580
_pool_slave_main_loop:
    .4byte  slave_main_loop
_pool_intback_cmd:
    .4byte  sym_06059CAC

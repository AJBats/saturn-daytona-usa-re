
    .section .text.FUN_06040B90


    .global event_callback_dispatch
    .type event_callback_dispatch, @function
event_callback_dispatch:
    mov.l r14, @-r15
    mov r15, r2
    add #0x10, r2
    mov.l r2, @-r15
    mov r15, r3
    add #0x1C, r3
    mov.l r3, @-r15
    mov r15, r7
    mov.l   .L_pool_06040C04, r3
    add #0x1C, r7
    jsr @r3
    mov.l @r13, r4
    add #0x10, r15
    mov r13, r4
    mov.l @(16, r15), r3
    mov.l @(8, r4), r5
    mov.l @(16, r4), r2
    add r2, r5
    mov.l @r15, r2
    add r2, r5
    cmp/ge r3, r5
    bf      .L_fill_record
    mov.l @(8, r15), r0
    tst r0, r0
    bt      .L_fill_record
    mov.l @r15, r3
    cmp/pl r3
    bf      .L_fill_record
    mov.l @(12, r15), r2
    mov.l @(8, r15), r3
    sub r3, r2
    mov.l @(4, r15), r1
    sub r2, r1
    mov.l r1, @(4, r15)
.L_fill_record:
    mov.l   .L_pool_06040C08, r13
    mov.l   .L_pool_06040C0C, r3
    jsr @r3
    nop
    mov.l r0, @r13
    mov.l r14, @(4, r13)
    mov.l @(4, r15), r2
    mov.l r2, @(8, r13)
    mov.l @r15, r3
    mov.l r3, @(12, r13)
    mov r13, r3
    mov #0x1, r2
    mov #0x10, r0
    mov.b r2, @(r0, r3)
    mov r3, r0
    add #0x18, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .4byte  cmd_enqueue
    .4byte  state_field_read
.L_pool_06040C04:
    .4byte  sym_06040220
.L_pool_06040C08:
    .4byte  sym_0606367C
.L_pool_06040C0C:
    .4byte  sym_06035C48

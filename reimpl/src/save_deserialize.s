
    .section .text.FUN_0603BD1C


    .global save_deserialize
    .type save_deserialize, @function
save_deserialize:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r13
    add #-0x4, r15
    mov.l   .L_pool_0603BD84, r14
    mov.w   .L_wpool_0603BD64, r0
    mov.l @r14, r4
    mov.l @(r0, r4), r4
    tst r4, r4
    bt      .no_conflict
    cmp/eq r13, r4
    bt      .no_conflict
    bra     .return_result
    mov #0x5, r0
.no_conflict:
    mov #0x10, r0
    mov.l @r14, r2
    mov.b @(r0, r13), r3
    add #0x4, r2
    extu.b r3, r3
    shll2 r3
    shll2 r3
    add r2, r3
    mov r3, r2
    mov.l r3, @r15
    mov.l @r2, r3
    jsr @r3
    mov.l @r13, r4
    mov r0, r4
    tst r4, r4
    bf      .check_result_2
    mov.l @r14, r3
    mov.w   .L_wpool_0603BD64, r0
    mov.l r13, @(r0, r3)
    bra     .set_return_code
    nop
.L_wpool_0603BD64:
    .2byte  0x00A8                      /* [HIGH] active block slot offset in cmd state (+0xA8) */
    .2byte  0xFFFF
    .4byte  sym_060401E4
    .4byte  nop_stub_evt
    .4byte  sym_06040C50
    .4byte  event_priority_set
    .4byte  evt_status_flag_set
    .4byte  evt_cmd_enqueue
    .4byte  sym_0603F8B8
.L_pool_0603BD84:
    .4byte  sym_060A4D14
.check_result_2:
    mov r4, r0
    cmp/eq #0x2, r0
    bf      .set_return_code
    mov.l @r14, r3
    .byte   0x90, 0x3D    /* mov.w wpool@0x0603BE0E (external: 0x00A8 active slot offset), r0 */
    mov.l @(r0, r3), r2
    cmp/eq r13, r2
    bf      .set_return_code
    mov.l @r14, r2
    mov #0x0, r3
    .byte   0x90, 0x37    /* mov.w wpool@0x0603BE0E (external: 0x00A8 active slot offset), r0 */
    mov.l r3, @(r0, r2)
.set_return_code:
    mov r4, r0
.return_result:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

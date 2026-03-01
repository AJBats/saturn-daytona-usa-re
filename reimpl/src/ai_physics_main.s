
    .section .text.FUN_0600E906


    .global ai_physics_main
    .type ai_physics_main, @function
ai_physics_main:
    mov.l r14, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    .byte   0xDE, 0x0C    /* mov.l .L_pool_0600E942, r14 */  ! r14 = &car_state_ptr (sym_0607E940)
    .byte   0xD0, 0x0D    /* mov.l .L_pool_0600E946, r0 */  ! r0 = &race_mode_flag (sym_0607EAD8)
    mov.l @r0, r0
    tst r0, r0
    bt/s    .L_physics_pipeline
    mov.l @r14, r14
    mov #0x0, r3
    bra     .L_epilogue
    mov.l r3, @(12, r14)
    .2byte  0x0228

    .global DAT_0600e920
DAT_0600e920:
    .word 0x01F8

    .global DAT_0600e922
DAT_0600e922:
    mov.b r14, @(r0, r0)
    .word 0x00E0
    .word 0xFFFF
    .4byte  track_segment_advance
    .4byte  sym_0607EA9C
    .4byte  sym_0607EBC4
    .4byte  0x00200000
    .4byte  0x066505B3
    .4byte  fpmul
.L_pool_0600E942:
    .4byte  sym_0607E940
.L_pool_0600E946:
    .4byte  sym_0607EAD8
.L_physics_pipeline:
    .byte   0xD3, 0x29    /* mov.l .L_pool_0600E9F0, r3 */  ! r3 = &friction_stub (cross-TU pool)
    jsr @r3
    nop
    .byte   0xD3, 0x29    /* mov.l .L_pool_0600E9F4, r3 */  ! r3 = &ai_orchestrator (cross-TU pool)
    jsr @r3
    nop
    .byte   0xD5, 0x28    /* mov.l .L_pool_0600E9F8, r5 */  ! r5 = 0x00480000 (Y scale constant, cross-TU pool)
    .byte   0xD3, 0x29    /* mov.l .L_pool_0600E9FC, r3 */  ! r3 = &fpmul (cross-TU pool)
    jsr @r3
    mov.l @(12, r14), r4
    shlr16 r0
    exts.w r0, r0
    mov.l r0, @(8, r14)
    mov.l @(32, r14), r2
    .byte   0xD3, 0x26    /* mov.l .L_pool_0600EA00, r3 */  ! r3 = &track_segment_advance (cross-TU pool)
    jsr @r3
    mov.l r2, @(48, r14)
    .byte   0x90, 0x3A    /* mov.w .L_wpool_0600E9E2, r0 */  ! r0 = 0x0228 (forward speed offset)
    .byte   0xD3, 0x25    /* mov.l .L_pool_0600EA04, r3 */  ! r3 = &speed_coefficient (sym_0607EA9C, cross-TU pool)
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    add #-0x3C, r0
    mul.l r3, r2
    mov.l @(r0, r14), r3
    sts macl, r2
    add #0x8, r0
    add r3, r2
    mov.l r2, @(r0, r14)
    add #-0x8, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_epilogue
    mov #0x0, r3
    .byte   0x90, 0x2B    /* mov.w .L_wpool_0600E9E4, r0 */  ! r0 = 0x021C (speed field offset)
    mov.l r3, @(r0, r14)
    .byte   0x93, 0x2A    /* mov.w .L_wpool_0600E9E6, r3 */  ! r3 = 0x0200 (timer reset value)
    add #-0x18, r0
    mov.l r3, @(r0, r14)
.L_epilogue:
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

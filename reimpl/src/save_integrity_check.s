
    .section .text.FUN_0603BDAC


    .global save_integrity_check
    .type save_integrity_check, @function
save_integrity_check:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov r15, r5
    mov.l   .L_pool_0603BE14, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov.l   .L_pool_0603BE18, r12
    cmp/eq #0x5, r0
    bt/s    .invalid_block
    mov r0, r13
    mov.l   .L_pool_0603BE1C, r3
    jsr @r3
    mov.l @(4, r14), r4
    tst r0, r0
    bf      .block_valid
.invalid_block:
    mov #-0x1, r5
    mov.l   .L_pool_0603BE20, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov.l @r12, r2
    mov.w   .L_wpool_0603BE10, r0
    mov.l @(r0, r2), r3
    cmp/eq r14, r3
    bf      .clear_done
    mov.l @r12, r2
    mov #0x0, r3
    mov.w   .L_wpool_0603BE10, r0
    mov.l r3, @(r0, r2)
.clear_done:
    bra     .epilogue
    mov #0x5, r13
.block_valid:
    tst r13, r13
    bt      .epilogue
    mov.l @r12, r3
    mov.w   .L_wpool_0603BE10, r0
    mov.l r14, @(r0, r3)
    mov #0x1, r3
    mov #0x12, r0
    mov.b r3, @(r0, r14)
.epilogue:
    mov r13, r0
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x00A8                      /* alignment padding (unreachable) */
.L_wpool_0603BE10:
    .2byte  0x00B4                      /* [HIGH] offset to active-block slot in global state */
    .2byte  0xFFFF                      /* alignment padding */
.L_pool_0603BE14:
    .4byte  scene_buffer_update         /* process save block scene data */
.L_pool_0603BE18:
    .4byte  sym_060A4D14                /* global game state base pointer */
.L_pool_0603BE1C:
    .4byte  sym_0603EFD4                /* interp_linear_remainder — validate timing */
.L_pool_0603BE20:
    .4byte  race_timer_sync             /* invalidate/sync race timer */
    .4byte  0x2F864F22
    .4byte  0x4F127FF0
    .4byte  0x2F5265F3
    .4byte  0xBC3A7504
    .4byte  0x64F37404
    .4byte  0x84486403
    .4byte  0x644C2448
    .4byte  0x8B0560F3
    .4byte  0x70046002
    .4byte  0x63F2A012
    .4byte  0x303C60F3
    .4byte  0x61F2D310
    .4byte  0x70046802
    .4byte  0x430B6043
    .4byte  0x63F37304
    .4byte  0xE209323C
    .4byte  0x6220622C
    .4byte  0x6343332C
    .4byte  0x0037001A
    .4byte  0x308C7F10
    .4byte  0x4F164F26
    .4byte  0x000B68F6
    .4byte  0xE01D004C
    .4byte  0x600CC860
    .4byte  0x8B02D304
    .4byte  0x432B0009
    .4byte  0x1458E200
    .4byte  0x000B1429
    .4byte  sym_06034FFC
    .4byte  evt_error_code_return

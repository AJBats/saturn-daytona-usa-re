
    .section .text.FUN_06041AA0


    .global track_boundary_check
    .type track_boundary_check, @function
track_boundary_check:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_pool_06041B10, r14
    mov.l r4, @r15
    mov.l @r14, r0
    mov.w   DAT_06041b0a, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf      .L_skip_phase1
    mov.l @r14, r4
    mov.w   .L_wpool_06041B0C, r0
    mov.l   .L_pool_06041B14, r3
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    mov.l @r15, r2
    mov.l @r2, r3
    add #0x1, r3
    tst r4, r4
    bf/s    .L_skip_state_update
    mov.l r3, @r2
    mov.l @r14, r3
    mov #0x2, r2
    mov.w   DAT_06041b0a, r0
    mov.l r2, @(r0, r3)
.L_skip_state_update:
    mov r15, r4
    mov.l   .L_pool_06041B18, r3
    jsr @r3
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
.L_skip_phase1:
    mov.l @r14, r0
    mov.w   DAT_06041b0a, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_return
    mov #0x40, r2
    mov.l   .L_pool_06041B1C, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r5
    mov.l @r15, r3
    exts.w r5, r4
    and r3, r4
    tst r4, r4
    bt      .L_bit_clear
    bra     .L_bit_set_exit
    mov #0x1, r4

    .global DAT_06041b0a
DAT_06041b0a:
    .2byte  0x0304
.L_wpool_06041B0C:
    .2byte  0x0308
    .2byte  0xFFFF
.L_pool_06041B10:
    .4byte  sym_060A5400         /* [HIGH] global AI/game state base pointer (indirect) */
.L_pool_06041B14:
    .4byte  track_seg_boundary   /* [HIGH] compute track segment boundary result */
.L_pool_06041B18:
    .4byte  ai_checkpoint_validate  /* [HIGH] validate AI checkpoint from stack buffer */
.L_pool_06041B1C:
    .4byte  sym_06035C4E         /* [MEDIUM] HIRQ/CD status reader — event_queue.s calls it "state/field validator" */
.L_bit_clear:
    mov #0x0, r4
.L_bit_set_exit:
    tst r4, r4
    bt      .L_return
    mov.l @r14, r3
    mov #0x0, r2
    .byte   0x90, 0x4C    /* mov.w .L_wpool_boundary_phase_offset, r0 */
    mov.l r2, @(r0, r3)
.L_return:
    mov.l @r14, r0
    .byte   0x91, 0x49    /* mov.w .L_wpool_boundary_phase_offset, r1 */
    mov.l @(r0, r1), r0
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

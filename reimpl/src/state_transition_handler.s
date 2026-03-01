
    .section .text.FUN_06041CC8


    .global state_transition_handler
    .type state_transition_handler, @function
state_transition_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_pool_06041D5C, r14
    mov.l r4, @r15
    mov.l @r14, r0
    mov.w   .L_wpool_06041D58, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf      .L_check_phase2
    mov.l @r14, r6
    mov.w   DAT_06041d5a, r0
    mov.l @r14, r5
    mov.l @r14, r4
    mov.l   .L_pool_06041D60, r3
    mov.l @(r0, r6), r6
    add #-0x4, r0
    mov.l @(r0, r5), r5
    add #-0x4, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_impact_clear
    mov #0x1, r0
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_impact_clear:
    mov r15, r4
    mov.l   .L_pool_06041D64, r3
    jsr @r3
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r15, r3
    mov.l @r3, r2
    add #0x1, r2
    mov.l r2, @r3
    mov.l @r14, r3
    mov #0x2, r2
    mov.w   .L_wpool_06041D58, r0
    mov.l r2, @(r0, r3)
.L_check_phase2:
    mov.l @r14, r0
    mov.w   .L_wpool_06041D58, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_return_in_progress
    mov.l   .L_pool_06041D68, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    tst r4, r4
    bf      .L_return_in_progress
    mov #0x0, r4
    mov.l @r14, r3
    mov.w   .L_wpool_06041D58, r0
    mov.l r4, @(r0, r3)
    mov r4, r0
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_return_in_progress:
    mov #0x1, r0
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_06041D58:
    .2byte  0x0328                      /* [HIGH] offset to transition_state in game state struct */

    .global DAT_06041d5a
DAT_06041d5a:
    .2byte  0x0334
.L_pool_06041D5C:
    .4byte  sym_060A5400
.L_pool_06041D60:
    .4byte  track_impact_force
.L_pool_06041D64:
    .4byte  ai_checkpoint_validate
.L_pool_06041D68:
    .4byte  ai_brake_zone_adjust

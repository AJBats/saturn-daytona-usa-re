
    .section .text.FUN_0601BDEC


    .global replay_playback_engine
    .type replay_playback_engine, @function
replay_playback_engine:
    sts.l pr, @-r15
    mov.l   .L_pool_0601BE50, r7
    mov.l   .L_pool_0601BE54, r6
    mov.l   .L_pool_0601BE58, r4
    mov.l   .L_pool_0601BE5C, r5
    mov.l   .L_pool_0601BE60, r3
    mov.l @r5, r5
    mov.l @(8, r5), r1
    jsr @r3
    mov #0x20, r0
    add #0x1, r0
    mov.l @r6, r2
    add r0, r2
    mov.l r2, @r6
    mov.l @r7, r3
    mov.l @(32, r5), r2
    sub r2, r3
    cmp/pl r3
    bf      .L_scroll_behind
    mov.l @r4, r2
    add #0x2, r2
    bra     .L_clamp_frame_counter
    mov.l r2, @r4
.L_scroll_behind:
    mov.l @r7, r2
    mov.l @(32, r5), r3
    sub r3, r2
    cmp/pz r2
    bt      .L_clamp_frame_counter
    mov.l @r4, r3
    add #-0x2, r3
    mov.l r3, @r4
.L_clamp_frame_counter:
    mov #0x50, r3
    mov.l @r6, r2
    cmp/hi r3, r2
    bf      .L_check_subindex_limit
    mov.l @r6, r3
    add #-0x50, r3
    mov.l r3, @r6
.L_check_subindex_limit:
    mov.l @r4, r2
    mov.w   .L_w_subindex_limit, r3
    cmp/hi r3, r2
    bf      .L_store_and_return
    mov #0x0, r3
    mov.l r3, @r4
.L_store_and_return:
    mov.l @(32, r5), r2
    lds.l @r15+, pr
    rts
    mov.l r2, @r7
.L_w_subindex_limit:
    .2byte  0x00A0                         /* [HIGH] sub-index upper limit (160) */
    .2byte  0xFFFF
.L_pool_0601BE50:
    .4byte  sym_06086018               /* [MEDIUM] replay scroll accumulator (dword) */
.L_pool_0601BE54:
    .4byte  sym_06059F3C               /* [MEDIUM] car array index / replay frame counter */
.L_pool_0601BE58:
    .4byte  sym_06059F38               /* [MEDIUM] car selection sub-index / playback offset */
.L_pool_0601BE5C:
    .4byte  sym_0607E944               /* [HIGH] iterated car struct pointer */
.L_pool_0601BE60:
    .4byte  sym_06034FE0               /* [HIGH] geometry_transform fn */

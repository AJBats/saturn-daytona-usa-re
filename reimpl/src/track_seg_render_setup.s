
    .section .text.FUN_0602F214


    .global track_seg_render_setup
    .type track_seg_render_setup, @function
track_seg_render_setup:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov r0, r1
    shlr16 r1
    mov r14, r0
    mov.l r1, @(r0, r8)
    mov.w   DAT_0602f24e, r1
    mov.l @(r0, r1), r4
    mov.w   DAT_0602f24c, r1
    mov.l @(r0, r1), r5
    mov.w   .L_wpool_seg_length_off, r1
    mov.l @(r0, r1), r6
    add r6, r5
    sub r4, r5
    mov.w @(r0, r9), r3
    shll r3
    shll2 r3
    mov.l   .L_pool_clamp_table, r7
    add r3, r7
    mov.l @r7, r1
    mov.l @(0x4, r7), r2
    cmp/gt r1, r5
    bt      .L_check_upper_bound
    mov r1, r5
    bra     .L_apply_clamped_distance
    nop

    .global DAT_0602f24c
DAT_0602f24c:
    .2byte  0x00E0

    .global DAT_0602f24e
DAT_0602f24e:
    .2byte  0x00E4
.L_wpool_seg_length_off:
    .2byte  0x00C0                       /* [HIGH] struct offset 0xC0 = segment length field */
    .2byte  0x0000                       /* alignment padding */
    .4byte  sym_060477CC                 /* [MEDIUM] course speed table (shared pool, not referenced in this TU) */
    .4byte  fpdiv_setup                  /* [MEDIUM] fpdiv_setup fn ptr (shared pool, caller loads r12) */
.L_pool_clamp_table:
    .4byte  sym_0602F3CC                 /* [HIGH] per-segment render distance clamp table (min/max pairs) */
.L_check_upper_bound:
    cmp/ge r5, r2
    bt      .L_apply_clamped_distance
    mov r2, r5
.L_apply_clamped_distance:
    add r5, r4
    mov.w   .L_wpool_seg_end_off, r1
    rts
    mov.l r4, @(r0, r1)
.L_wpool_seg_end_off:
    .2byte  0x00E4                       /* [HIGH] struct offset 0xE4 = seg_end position field */


    .section .text.FUN_0603FC60


    .global vblank_palette_apply
    .type vblank_palette_apply, @function
vblank_palette_apply:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l r5, @r15
    mov.l r6, @(4, r15)
    mov.l @(16, r14), r4
    mov.l @(20, r14), r5
    mov.l @(24, r14), r3
    sub r3, r5
    cmp/ge r5, r4
    bt      .L_use_pending
    bra     .L_batch_ready
    mov r4, r13
.L_use_pending:
    mov r5, r13
.L_batch_ready:
    mov.l @(48, r14), r2
    mov #0x1, r3
    cmp/gt r3, r2
    bf      .L_batch_done
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_query_elem_b
    mov.l @(4, r14), r1
    mov.l @(28, r14), r3
    mov.l   .L_pool_signed_div_32, r2
    mov.l @(8, r1), r1
    sub r3, r1
    jsr @r2
    mov.l @(48, r14), r0
    mov r0, r13
.L_query_elem_b:
    mov.l   .L_pool_dispatch_slot2, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov r0, r1
    mov.l   .L_pool_signed_div_32, r2
    jsr @r2
    mov.l @(48, r14), r0
    mov r0, r4
    cmp/ge r4, r13
    bt      .L_clamp_batch
    bra     .L_batch_done
    nop

    .global DAT_0603fcb6
DAT_0603fcb6:
    .word 0xFF7F
.L_pool_signed_div_32:
    .4byte  sym_06034FFC
.L_pool_dispatch_slot2:
    .4byte  sym_0603F8EE
.L_clamp_batch:
    mov r4, r13
.L_batch_done:
    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_epilogue
    mov r13, r5
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0603FD34, r3 */  ! r3 = &cmd_dispatch_slot3 (cross-TU pool)
    jsr @r3
    mov.l @r15, r4
    mov.l r0, @(4, r14)
    tst r0, r0
    bt      .L_epilogue
    mov #0x0, r3
    mov.l r3, @(28, r14)
.L_epilogue:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

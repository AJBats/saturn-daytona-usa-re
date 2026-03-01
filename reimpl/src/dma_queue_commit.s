
    .section .text.FUN_06007D8E


    .global dma_queue_commit
    .type dma_queue_commit, @function
dma_queue_commit:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x1, r12
    mov.w   .L_wpool_ftcsr_addr, r13
    mov.w   .L_wpool_ovf_bitmask, r14
    bra     .L_ovf_poll
    mov #0x0, r4
.L_wpool_ftcsr_addr:
    .2byte  0xFE11                          /* [HIGH] SH2_FTCSR low 16 bits (0xFFFFFE11) — FRT control/status register */
.L_wpool_ovf_bitmask:
    .2byte  0x0080                          /* [HIGH] OVF bitmask — bit 7 of FTCSR (timer overflow flag) */
    .2byte  0xFFFF
    .4byte  sym_060281B8
    .4byte  sym_0606A4F8
    .4byte  0x00008000
    .4byte  sym_0608AC20
    .4byte  sym_06078624
    .4byte  sym_0603C000
    .4byte  sym_060280F8
    .4byte  sym_06078620
    .4byte  0x0000FFFF
    .4byte  0x21800000
.L_ovf_retry:
    mov r12, r4
.L_ovf_poll:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_ovf_retry
    mov.b @r13, r0
    and #0xF, r0
    mov.b r0, @r13
    .byte   0xD5, 0x08    /* mov.l .L_pool_render_budget, r5 */  ! r5 = &sym_0605A1C0 (render budget counter)
    tst r4, r4
    bt      .L_budget_increase
    mov.w @r5, r3
    add #-0xA, r3
    mov.w r3, @r5
    bra     .L_epilogue
    nop
.L_budget_increase:
    mov.w @r5, r2
    add #0xA, r2
    mov.w r2, @r5
.L_epilogue:
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x02    /* mov.l .L_pool_render_finalize, r3 */  ! r3 = sym_0603C000 (render finalize)
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_render_budget:
    .4byte  sym_0605A1C0
.L_pool_render_finalize:
    .4byte  sym_0603C000

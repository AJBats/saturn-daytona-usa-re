

    .section .text.FUN_0603FE80


    .global scu_dma_transfer
    .type scu_dma_transfer, @function
scu_dma_transfer:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.w   .L_dma_end_bit_mask, r13
    mov.l   .L_scu_ist, r14
    mov.l r5, @r15
    mov.l r6, @(8, r15)
    mov.l r7, @(4, r15)
    mov.l   .L_bios_int_state_ptr, r3
    mov.l @r3, r3
    mov.l r3, @(12, r15)
    mov.l @r15, r0
    tst r0, r0
    bf      .L_dest_valid
    bra     .L_epilogue_no_dma
    nop
.L_dest_valid:
    mov.l   .L_abus_cs1_timing, r3
    mov.l   .L_scu_asr1, r2
    mov.l r3, @r2
    mov.l   .L_bios_int_ctrl_ptr, r3
    mov.l @r3, r3
    jsr @r3
    mov #-0x1, r4
    mov.w   .L_ist_dma_clear, r2
    mov.l r2, @r14
    mov.l @(4, r15), r3
    mov.l   .L_scu_d0r, r2
    mov.l r3, @r2
    add #0x4, r2
    mov.l @r15, r3
    mov.l r3, @r2
    mov.l @(32, r15), r3
    add #0x4, r2
    mov.l r3, @r2
    mov.l @(28, r15), r0
    tst r0, r0
    bf      .L_addr_update_set
    bra     .L_addr_update_done
    mov #0x0, r4
.L_addr_update_set:
    mov.w   .L_src_addr_add, r4
.L_addr_update_done:
    mov.l @(8, r15), r0
    tst r0, r0
    bf      .L_indirect_set
    bra     .L_indirect_done
    mov #0x0, r5
.L_dma_end_bit_mask:
    .2byte  0x0800                      /* SCU IST bit 11: DMA L0 end interrupt */
.L_ist_dma_clear:
    .2byte  0xF7FF                      /* IST write mask: clear DMA L0 end bit */
.L_src_addr_add:
    .2byte  0x0100                      /* D0AD source address add value */
    .2byte  0xFFFF                      /* padding */
.L_scu_ist:
    .4byte  0x25FE00A4                  /* SCU IST — interrupt status */
.L_bios_int_state_ptr:
    .4byte  sym_06000348
.L_abus_cs1_timing:
    .4byte  0x10041004
.L_scu_asr1:
    .4byte  0x25FE00B4                  /* SCU ASR1 — A-bus timing CS1 */
.L_bios_int_ctrl_ptr:
    .4byte  sym_06000340
.L_scu_d0r:
    .4byte  0x25FE0000                  /* SCU D0R — DMA level 0 read addr */
.L_indirect_set:
    mov #0x2, r5
.L_indirect_done:
    or r5, r4
    .byte   0xD3, 0x12    /* mov.l @(0x25FE000C), r3 */
    mov.l r4, @r3
    mov #0x7, r2
    add #0x8, r3
    mov.l r2, @r3
    .byte   0x92, 0x1E    /* mov.w @(0x0101), r2 */
    add #-0x4, r3
    mov.l r2, @r3
.L_poll_dma_end:
    mov.l @r14, r2
    and r13, r2
    tst r2, r2
    bt      .L_poll_dma_end
    .byte   0xD3, 0x0D    /* mov.l @(sym_06000340), r3 */
    mov.l @r3, r3
    mov.l @(12, r15), r4
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    jmp @r3
    mov.l @r15+, r14
.L_epilogue_no_dma:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global loc_0603FF32
loc_0603FF32:
    rts
    mov #0x0, r0

    .global loc_0603FF36
loc_0603FF36:
    rts
    mov #0x1, r0

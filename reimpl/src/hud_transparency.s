
    .section .text.FUN_060115F0


    .global hud_transparency
    .type hud_transparency, @function
hud_transparency:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.w   .L_w_coeff_count, r13
    mov.l   .L_pool_transition_state_word, r14
    mov.l   .L_fp_eight, r12
    bsr     .L_config_vdp2_coeff
    nop
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
    mov.l   .L_vdp2_vram_0x5F800, r5
    mov #0x0, r4
.L_coeff_loop:
    extu.w r4, r0
    extu.w r4, r1
    mov.l   .L_pool_mem_store_helper, r3
    shll2 r0
    mov r0, r8
    add r5, r8
    jsr @r3
    mov #0x2, r0
    tst r0, r0
    bt      .L_use_pos_scale
    bra     .L_store_coeff
    mov r12, r3
.L_use_pos_scale:
    mov.l   .L_pool_neg_scale, r3
.L_store_coeff:
    add #0x1, r4
    mov.w @r14, r1
    extu.w r1, r1
    mul.l r1, r3
    sts macl, r3
    mov.l r3, @r8
    extu.w r4, r3
    cmp/ge r13, r3
    bf      .L_coeff_loop
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_config_vdp2_coeff:
    mov.l   .L_pool_coeff_table_base, r3
    mov.l   .L_vdp2_reg_0x0A4, r2
    mov.l r3, @r2
    mov.w   .L_w_rpmd_mode, r3
    add #-0xA, r2
    rts
    mov.w r3, @r2


.L_w_coeff_count:
    .2byte  0x0100              /* [HIGH] 256 — coefficient table entry count (loop bound) */
.L_w_rpmd_mode:
    .2byte  0x0200              /* [HIGH] VDP2 RPMD rotation scroll mode select value */
.L_pool_transition_state_word:
    .4byte  sym_0607886E        /* &transition_state_word (16-bit frame counter) */
.L_fp_eight:
    .4byte  0x00080000                  /* 8.0 (16.16 fixed-point) */
.L_vdp2_vram_0x5F800:
    .4byte  0x25E5F800                  /* VDP2 VRAM +0x5F800 */
.L_pool_mem_store_helper:
    .4byte  sym_06035C2C        /* &sym_06035C2C (mem_store_helper — returns selector in r0) */
.L_pool_neg_scale:
    .4byte  0xFFF80000          /* negative scale factor (-8.0 in 16.16 fixed-point) */
.L_pool_coeff_table_base:
    .4byte  0x12F2FC00          /* VDP2 coefficient table base address value */
.L_vdp2_reg_0x0A4:
    .4byte  0x25F800A4                  /* VDP2 register +0x0A4 */


    .section .text.FUN_0600C74E


    .global ai_orchestrator
    .type ai_orchestrator, @function
ai_orchestrator:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDE, 0x1D    /* mov.l .L_pool_0600C7D0, r14 */
    .byte   0xDD, 0x1D    /* mov.l .L_pool_0600C7D4, r13 */

    .reloc ., R_SH_IND12W, FUN_0600CD40 - 4
    .2byte 0xB000    /* bsr FUN_0600CD40 (linker-resolved) */
    mov.l @r14, r14

    .reloc ., R_SH_IND12W, FUN_0600CA96 - 4
    .2byte 0xB000    /* bsr FUN_0600CA96 (linker-resolved) */
    mov r13, r4

    mov #0x2D, r3
    mov.w   DAT_0600c7be, r0
    mov.l @(r0, r14), r4
    cmp/gt r3, r4
    bf      .L_0600C77A
    mov #0x3C, r3
    cmp/ge r3, r4
    bt      .L_0600C77A
    mov.w   DAT_0600c7c0, r3
    mov.l r3, @(40, r14)
    bra     .L_0600C780
    nop

.L_0600C77A:
    mov r13, r5
    .reloc ., R_SH_IND12W, FUN_0600C8CC - 4
    .2byte 0xB000    /* bsr FUN_0600C8CC (linker-resolved) */
    mov r14, r4

.L_0600C780:
    mov.l @(40, r14), r2
    mov.l r2, @(32, r14)

    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_0600C78E
    .reloc ., R_SH_IND12W, FUN_0600C970 - 4
    .2byte 0xB000    /* bsr FUN_0600C970 (linker-resolved) */
    mov r14, r4

.L_0600C78E:
    .reloc ., R_SH_IND12W, FUN_0600C928 - 4
    .2byte 0xB000    /* bsr FUN_0600C928 (linker-resolved) */
    mov r14, r4

    mov r13, r5
    .reloc ., R_SH_IND12W, FUN_0600C7D4 - 4
    .2byte 0xB000    /* bsr FUN_0600C7D4 (linker-resolved) */
    mov r14, r4

    mov r15, r6
    mov r14, r5
    mov.l r6, @-r15
    add #0x10, r5
    mov.l r5, @-r15
    mov.l @(24, r14), r5
    .byte   0xD3, 0x07    /* mov.l .L_pool_0600C7C8, r3 */
    jsr @r3
    mov.l @(16, r14), r4

    mov r0, r4
    mov.l @r15+, r5
    .byte   0xD3, 0x06    /* mov.l .L_pool_0600C7CC, r3 */
    jsr @r3
    mov.l @r15+, r6

    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600c7be
DAT_0600c7be:
    .2byte  0x01EC

    .global DAT_0600c7c0
DAT_0600c7c0:
    .2byte  0x4000
    .2byte  0xFFFF
.L_pool_0600C7C8:
    .4byte  sym_06006838
.L_pool_0600C7CC:
    .4byte  scene_render_alt
.L_pool_0600C7D0:
    .4byte  sym_0607E940
.L_pool_0600C7D4:
    .4byte  sym_06078680

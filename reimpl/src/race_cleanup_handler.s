
    .section .text.FUN_060121A8


    .global race_cleanup_handler
    .type race_cleanup_handler, @function
race_cleanup_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06012224, r14
    mov.l @r14, r3
    add #0x1, r3
    mov r3, r2
    mov.l r3, @r14
    mov #0x14, r3
    cmp/ge r3, r2
    bt      .L_check_transition
    mov.l   .L_pool_06012228, r3
    mov.l r3, @r15
    mov r3, r7
    mov.w   .L_wpool_06012218, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    mov.l   .L_pool_0601222C, r3
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_06012230, r3
    jsr @r3
    mov #0x8, r4
    .byte   0xB1, 0xFA    /* bsr 0x060125D0 (external) */  ! call lap_display_update
    nop
.L_check_transition:
    mov.l @r14, r0
    cmp/eq #0x14, r0
    bf      .L_not_transition_frame
    mov.l   .L_pool_06012234, r5
    mov.l   .L_pool_06012238, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_pool_0601223C, r13
    mov.w   .L_wpool_0601221A, r6
    mov.w   .L_wpool_06012218, r5
    mov.l   .L_pool_06012240, r3
    mov r13, r7
    jsr @r3
    mov #0x8, r4
    mov r13, r7
    mov.w   .L_wpool_0601221A, r6
    mov.w   .L_wpool_0601221C, r5
    mov.l   .L_pool_06012240, r3
    jsr @r3
    mov #0x8, r4
    mov r13, r7
    mov.l   .L_mask_0xE000, r6
    mov.w   .L_wpool_0601221E, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_pool_06012248, r3
    jmp @r3
    mov.l @r15+, r14
.L_wpool_06012218:
    .2byte  0x0390                          /* VDP1 sprite cmd list offset (car model) */
.L_wpool_0601221A:
    .2byte  0x0090                          /* VDP text layer A offset */
.L_wpool_0601221C:
    .2byte  0x0490                          /* VDP text layer B offset */
.L_wpool_0601221E:
    .2byte  0x0590                          /* VDP text layer C offset */
    .4byte  sym_0607EAD8                    /* race end state flag (read by adjacent TU) */
.L_pool_06012224:
    .4byte  sym_060788AC                    /* cleanup frame counter (dword) */
.L_pool_06012228:
    .4byte  sym_06063AF0                    /* car model geometry table base */
.L_pool_0601222C:
    .4byte  0x0000B000                      /* offset into model data block */
.L_pool_06012230:
    .4byte  sym_06028400                    /* display list loader / DMA dispatch */
.L_pool_06012234:
    .4byte  0xAE110EFF                      /* sound cmd: race end cleanup SFX */
.L_pool_06012238:
    .4byte  sound_cmd_dispatch              /* sound command dispatch function */
.L_pool_0601223C:
    .4byte  sym_0605ACF0                    /* HUD text string source data */
.L_pool_06012240:
    .4byte  sym_060284AE                    /* VDP number/text renderer */
.L_mask_0xE000:
    .4byte  0x0000E000                      /* priority bits mask (bits 15:13) */
.L_pool_06012248:
    .4byte  sym_060283E0                    /* VDP text dispatch (tail call target) */
.L_not_transition_frame:
    mov.l @r14, r2
    mov #0x28, r3
    cmp/gt r3, r2
    bf      .L_check_phase3
    mov #0x0, r3
    .byte   0xD2, 0x1D    /* mov.l .L_pool_060122CC, r2 */  ! r2 = &control_flag (in next TU pool)
    mov.b r3, @r2
    .byte   0xD5, 0x1D    /* mov.l .L_pool_060122D0, r5 */  ! r5 = sound param (in next TU pool)
    mov r3, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xD3, 0x1B    /* mov.l .L_pool_060122D4, r3 */  ! r3 = &sound_cmd_dispatch (next TU pool)
    jmp @r3
    mov.l @r15+, r14
.L_check_phase3:
    mov #0x14, r3
    mov.l @r14, r2
    cmp/gt r3, r2
    bf      .L_exit
    .byte   0xB0, 0x67    /* bsr 0x06012344 (external) */  ! call file_data_parse
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xA0, 0xC0    /* bra 0x06012400 (external) */  ! tail-branch to file_block_read
    mov.l @r15+, r14
.L_exit:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

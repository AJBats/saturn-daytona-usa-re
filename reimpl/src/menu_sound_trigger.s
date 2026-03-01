
    .section .text.FUN_0603AE74


    .global menu_sound_trigger
    .type menu_sound_trigger, @function
menu_sound_trigger:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0603AEE0, r14
    mov.w   .L_wpool_0603AED8, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_inactive_error
    mov.l @r14, r0
    mov.w   .L_wpool_0603AEDA, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bt      .L_mode_valid
.L_inactive_error:
    .byte   0xB5, 0x54    /* bsr 0x0603B93C (external) */
    mov #-0x8, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_mode_valid:
    cmp/pz r4
    bf      .L_range_error
    mov.l   .L_pool_0603AEE0, r3
    mov.w   .L_wpool_0603AEDC, r0
    mov.l @r3, r3
    mov.l @(r0, r3), r2
    cmp/gt r4, r2
    bt      .L_index_valid
.L_range_error:
    .byte   0xB5, 0x45    /* bsr 0x0603B93C (external) */
    mov #-0x9, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_index_valid:
    mov.l @r14, r5
    mov.w   .L_wpool_0603AED8, r0
    mov.l   .L_pool_0603AEE4, r3
    jsr @r3
    mov.l @(r0, r5), r5
    mov.l r0, @r15
    .byte   0xB5, 0x38    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0xC, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_0603AED8:
    .2byte  0x00A0                          /* [HIGH] struct offset: active entry count */
.L_wpool_0603AEDA:
    .2byte  0x0098                          /* [HIGH] struct offset: queue mode flag (0=narrow, 1=wide) */
.L_wpool_0603AEDC:
    .2byte  0x00A4                          /* [HIGH] struct offset: entry capacity (max index) */
    .2byte  0xFFFF
.L_pool_0603AEE0:
    .4byte  sym_060A4D14                    /* [HIGH] pointer to global command/display state struct */
.L_pool_0603AEE4:
    .4byte  sym_0603F1F0                    /* [HIGH] index_mul24: idx*24 + base */

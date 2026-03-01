
    .section .text.FUN_0603FCE4


    .global hud_palette_select
    .type hud_palette_select, @function
hud_palette_select:
    mov.l r14, @-r15
    mov #0x1, r2
    mov.l r13, @-r15
    mov r4, r14
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l @(48, r14), r3
    cmp/gt r2, r3
    bf/s    .L_multi_phase
    mov r6, r12
    mov.l @(4, r14), r5
    bra     .L_do_palette_lookup
    mov.l @(8, r5), r5
.L_multi_phase:
    mov.l @(4, r14), r13
    mov.l @(28, r14), r3
    mov.l @(8, r13), r13
    sub r3, r13
    mov.l   .L_pool_0603FD38, r3
    jsr @r3
    mov r12, r4
    cmp/ge r0, r13
    bt      .L_clamp_to_available
    bra     .L_do_palette_lookup
    mov r13, r5
.L_clamp_to_available:
    mov.l   .L_pool_0603FD38, r3
    jsr @r3
    mov r12, r4
    mov r0, r5
.L_do_palette_lookup:
    mov.l   .L_pool_0603FD3C, r3
    jsr @r3
    mov r12, r4
    mov.l r0, @(12, r14)
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x000B
    .4byte  0xE001FFFF
    .4byte  sym_0603F900
.L_pool_0603FD38:
    .4byte  sym_0603F8EE
.L_pool_0603FD3C:
    .4byte  sym_0603F90E

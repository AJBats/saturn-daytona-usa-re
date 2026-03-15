
    .section .text.FUN_060190F8


    .global FUN_060190F8
    .type FUN_060190F8, @function
FUN_060190F8:
    sts.l pr, @-r15
    mov.l   .L_pool_06019130, r14
    mov.l   .L_pool_06019134, r2
    mov.l r3, @r2
    mov.l   .L_pool_06019138, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_0601913C, r5
    jsr @r14
    mov #0xF, r4
    .reloc ., R_SH_IND12W, FUN_060192E8 - 4
    .2byte 0xB000    /* bsr FUN_060192E8 (linker-resolved) */
    nop
    mov.l   .L_pool_06019134, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06019124
    mov.l   .L_pool_06019148, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06019144, r3
    mov.w r2, @r3
.L_06019124:
    mov.l   .L_pool_06019138, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_06019130:
    .4byte  FUN_0601D5F4                  /* sound command dispatch function */
.L_pool_06019134:
    .4byte  sym_06086050
.L_pool_06019138:
    .4byte  0xAE0001FF                          /* sound stop command (channel 00, cmd 01) */
.L_pool_0601913C:
    .4byte  0xAE0005FF                          /* system variant command (channel 00, cmd 05) */
    .4byte  sym_06012F20
.L_pool_06019144:
    .4byte  0x25A02DBE
.L_pool_06019148:
    .4byte  sym_06012F50

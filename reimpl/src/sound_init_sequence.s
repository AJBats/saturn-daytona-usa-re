
    .section .text.FUN_06012E08


    .global sound_init_sequence
    .type sound_init_sequence, @function
sound_init_sequence:
    mov.l r14, @-r15
    mov r4, r0
    mov.l   .L_pool_06012E44, r14
    cmp/eq #0x1, r0
    bf      .L_06012E4C
    mov r14, r5
    mov.l   .L_pool_06012E48, r4
    .reloc ., R_SH_IND12W, cd_dma_setup - 4
    .2byte 0xA000    /* bra cd_dma_setup (linker-resolved) */
    mov.l @r15+, r14
    .2byte  0xFFFF
    .4byte  0x00200000
    .4byte  0x00240000
    .4byte  sym_0604490C
    .4byte  sym_0604491C
    .4byte  sym_06044928
    .4byte  sym_06044938
    .4byte  sym_06044944
    .4byte  sym_06044954
    .4byte  0x002A0000
    .4byte  sym_06044960
.L_pool_06012E44:
    .4byte  0x002A8000
.L_pool_06012E48:
    .4byte  sym_0604496C
.L_06012E4C:
    mov r4, r0
    cmp/eq #0x2, r0
    bf      .L_06012E5A
    mov r14, r5
    .byte   0xD4, 0x0D    /* mov.l .L_pool_06012E8C, r4 */
    .reloc ., R_SH_IND12W, cd_dma_setup - 4
    .2byte 0xA000    /* bra cd_dma_setup (linker-resolved) */
    mov.l @r15+, r14
.L_06012E5A:
    mov r14, r5
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06012E90, r4 */
    .reloc ., R_SH_IND12W, cd_dma_setup - 4
    .2byte 0xA000    /* bra cd_dma_setup (linker-resolved) */
    mov.l @r15+, r14

    .global sym_06012E62
sym_06012E62:
    .byte   0xD5, 0x0C    /* mov.l .L_pool_06012E94, r5 */
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06012E98, r4 */
    .reloc ., R_SH_IND12W, cd_dma_setup - 4
    .2byte 0xA000    /* bra cd_dma_setup (linker-resolved) */
    nop

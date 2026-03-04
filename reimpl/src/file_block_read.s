
    .section .text.FUN_06012400


    .global file_block_read
    .type file_block_read, @function
file_block_read:
    sts.l pr, @-r15
    mov.l   .L_pool_06012434, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0601241A
    mov.l   .L_pool_06012438, r5
    mov.l   .L_pool_0601243C, r3
    jsr @r3
    mov #0x0, r4
    mov #0x1, r2
    mov.l   .L_pool_06012434, r3
    mov.b r2, @r3
.L_0601241A:
    mov.l   .L_pool_06012440, r4
    .reloc ., R_SH_IND12W, file_format_detect - 4
    .2byte 0xB000    /* bsr file_format_detect (linker-resolved) */
    mov #0x0, r5
    mov.l   .L_pool_06012444, r4
    .reloc ., R_SH_IND12W, file_format_detect - 4
    .2byte 0xB000    /* bsr file_format_detect (linker-resolved) */
    mov #0x1, r5
    mov.l   .L_pool_06012448, r4
    .reloc ., R_SH_IND12W, file_format_detect - 4
    .2byte 0xB000    /* bsr file_format_detect (linker-resolved) */
    mov #0x2, r5
    mov #0x3, r5
    mov.l   .L_pool_0601244C, r4
    .reloc ., R_SH_IND12W, file_format_detect - 4
    .2byte 0xA000    /* bra file_format_detect (linker-resolved) */
    lds.l @r15+, pr
.L_pool_06012434:
    .4byte  sym_060788F0
.L_pool_06012438:
    .4byte  0xAE110FFF
.L_pool_0601243C:
    .4byte  sound_cmd_dispatch              /* sound command dispatch function */
.L_pool_06012440:
    .4byte  sym_060788C0
.L_pool_06012444:
    .4byte  sym_060788CC
.L_pool_06012448:
    .4byte  sym_060788D8
.L_pool_0601244C:
    .4byte  sym_060788E4

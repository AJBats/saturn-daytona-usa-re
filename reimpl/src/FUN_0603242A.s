
    .section .text.FUN_0603242A


    .global FUN_0603242A
    .type FUN_0603242A, @function
FUN_0603242A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    nop
    .2byte  0x0000
    .4byte  FUN_0601D5F4

    .global FUN_0603243C
FUN_0603243C:
    .byte   0xD2, 0x04    /* mov.l .L_pool_06032450, r2 */
    .byte   0xD0, 0x05    /* mov.l .L_pool_06032454, r0 */
    mov.b @r0, r1
    or r2, r1
    mov.b r1, @r0
    xor r1, r1
    .byte   0xD0, 0x03    /* mov.l .L_pool_06032458, r0 */
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    mov.l r1, @r0
    .2byte  0x0000
.L_pool_06032450:
    .4byte  0x00000001
.L_pool_06032454:
    .4byte  sym_06082A25
.L_pool_06032458:
    .4byte  sym_06082A28

    .global FUN_0603245C
FUN_0603245C:
    .byte   0xD2, 0x03    /* mov.l .L_pool_0603246C, r2 */
    .byte   0xD0, 0x04    /* mov.l .L_pool_06032470, r0 */
    not r2, r2
    mov.b @r0, r1
    and r2, r1
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    mov.b r1, @r0
    .2byte  0x0000
.L_pool_0603246C:
    .4byte  0x00000001
.L_pool_06032470:
    .4byte  sym_06082A25

    .global FUN_06032474
FUN_06032474:
    .byte   0xD2, 0x03    /* mov.l .L_pool_06032484, r2 */
    .byte   0xD0, 0x04    /* mov.l .L_pool_06032488, r0 */
    not r2, r2
    mov.b @r0, r1
    and r2, r1
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    mov.b r1, @r0
    .2byte  0x0000
.L_pool_06032484:
    .4byte  0x00000002
.L_pool_06032488:
    .4byte  sym_06082A25

    .global FUN_0603248C
FUN_0603248C:
    .byte   0xD2, 0x02    /* mov.l .L_pool_06032498, r2 */
    .byte   0xD0, 0x03    /* mov.l .L_pool_0603249C, r0 */
    mov.b @r0, r1
    or r2, r1
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    mov.b r1, @r0
.L_pool_06032498:
    .4byte  0x00000002
.L_pool_0603249C:
    .4byte  sym_06082A25

    .global FUN_060324A0
FUN_060324A0:
    .byte   0xD0, 0x07    /* mov.l .L_pool_060324C0, r0 */
    mov.l @r0, r0
    mov.l @r0, r1
    .byte   0xD2, 0x07    /* mov.l .L_pool_060324C4, r2 */
    and r2, r1
    mov.l r1, @r0
    .byte   0xD0, 0x06    /* mov.l .L_pool_060324C8, r0 */
    xor r1, r1
    mov.b r1, @r0
    .byte   0xD0, 0x06    /* mov.l .L_pool_060324CC, r0 */
    mov.b @r0, r1
    .byte   0xD2, 0x06    /* mov.l .L_pool_060324D0, r2 */
    or r2, r1
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    mov.b r1, @r0
    .2byte  0x0000
.L_pool_060324C0:
    .4byte  sym_0607E944
.L_pool_060324C4:
    .4byte  0xFFFEFFFF
.L_pool_060324C8:
    .4byte  sym_06082A24
.L_pool_060324CC:
    .4byte  sym_06082A25
.L_pool_060324D0:
    .4byte  0x00000004
    .4byte  0xD00401EC
    .4byte  0x21188919
    .4byte  0xE0042108
    .4byte  0x8B04A021
    .4byte  0x00090000
    .4byte  0x000002DC

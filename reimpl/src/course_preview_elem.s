
    .section .text.FUN_0603367A


    .global course_preview_elem
    .type course_preview_elem, @function
course_preview_elem:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_060336C8 - 4
    .2byte 0xB000    /* bsr FUN_060336C8 (linker-resolved) */
    nop
    lds.l @r15+, pr
.L_06033682:
    .byte   0xD5, 0x10    /* mov.l .L_pool_060336C4, r5 */
    add r5, r0
    mov.l @(r0, r2), r3
    cmp/eq r4, r3
    bt      .L_06033692
    add #-0x1, r6
    cmp/pl r6
    bt      .L_06033682
.L_06033692:
    mov #0x6, r2
    .byte   0xD3, 0x7A    /* mov.l .L_pool_06033880, r3 */
    mov.b @r3, r3
    cmp/pl r3
    bt      .L_060336AA
    mov.l r0, @-r15
    mov #0x1, r0
    cmp/ge r4, r0
    mov.l @r15+, r0
    bf      .L_060336AA
    shll2 r4
    add r4, r2
.L_060336AA:
    mov.w r2, @-r1

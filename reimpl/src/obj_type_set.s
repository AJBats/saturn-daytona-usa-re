
    .section .text.FUN_06020330


    .global obj_type_set
    .type obj_type_set, @function
obj_type_set:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD0, 0x22    /* mov.l .L_pool_060203C0, r0 */
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_0602035C
    mov #0x40, r0
    mov.b @r15, r4
    .byte   0xD2, 0x1F    /* mov.l .L_pool_060203C4, r2 */
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r2, r4
    .byte   0xB0, 0x05    /* bsr 0x06020366 (external) */
    mov.b @(r0, r4), r4
.L_0602035C:
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .byte   0xA5, 0x44    /* bra 0x06020DEE (external) */
    lds.l @r15+, pr

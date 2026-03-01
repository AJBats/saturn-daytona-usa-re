
    .section .text.FUN_0602E7D4


    .global shadow_intensity
    .type shadow_intensity, @function
shadow_intensity:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r13
    exts.w r13, r13
    mov.l @r15+, r0
    mov.w   DAT_0602e80a, r4
    mov.l @(40, r9), r1
    extu.w r4, r4
    mov r4, r3
    extu.w r13, r6
    shll r3
    or r3, r6
    sub r6, r1
    cmp/pl r1
    bt      .L_0602E7F8
    neg r1, r1
.L_0602E7F8:
    mov.l   .L_pool_0602E811, r7
    mov.b @r7, r7
    tst r7, r7
    bf      .L_0602E814
    extu.w r1, r1
    cmp/gt r1, r4
    .byte   0x89, 0x2E    /* bt 0x0602E864 (external) */
    bra     .L_0602E81A
    nop

    .global DAT_0602e80a
DAT_0602e80a:
    .2byte  0x8000                      /* half-circle angle constant */
    .4byte  atan2                       /* pool: atan2 function address */
.L_pool_0602E811:
    .4byte  sym_06078663                /* pool: camera direction flip flag address */
.L_0602E814:
    extu.w r1, r1
    cmp/gt r1, r4
    .byte   0x8B, 0x24    /* bf 0x0602E864 (external) */
.L_0602E81A:
    .byte   0xD3, 0x06    /* mov.l .L_pool_0602E834, r3 */
    cmp/ge r3, r8
    .byte   0x89, 0x11    /* bt 0x0602E844 (external) */
    .byte   0xD4, 0x05    /* mov.l .L_pool_0602E838, r4 */
    .byte   0xD5, 0x06    /* mov.l .L_pool_0602E83C, r5 */
    .byte   0xDD, 0x06    /* mov.l .L_pool_0602E840, r13 */

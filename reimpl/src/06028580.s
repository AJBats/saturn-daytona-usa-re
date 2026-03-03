
    .section .text.FUN_06028580


    .global effect_cleanup_stub
    .type effect_cleanup_stub, @function
effect_cleanup_stub:
    mov.l r14, @-r15
    shll8 r5
    shlr2 r5
    add r4, r5
    mov.l r13, @-r15
    shll r5
    .byte   0x94, 0x25    /* mov.w .L_wpool_060285DA, r4 */
    cmp/pz r6
    mov.l r12, @-r15
    .byte   0x8D, 0x01    /* bt/s 0x06028598 (external) */
    .word 0x0C29
    neg r6, r6

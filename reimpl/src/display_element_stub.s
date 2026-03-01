
    .section .text.FUN_0603137A


    .global display_element_stub
    .type display_element_stub, @function
display_element_stub:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r10
    exts.w r10, r10
    mov.l @r15+, r0
    mov.l @(56, r14), r8
    mov.l @(60, r14), r9
    mov.l @(56, r13), r6
    mov.l @(60, r13), r7
    mov.l r0, @-r15
    mov r8, r4
    sub r6, r4
    mov r9, r5
    sub r7, r5
    .byte   0xD0, 0x28    /* mov.l .L_pool_0603143C, r0 */

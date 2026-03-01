
    .section .text.FUN_0603FE62


    .global attract_elem_b
    .type attract_elem_b, @function
attract_elem_b:
    sts.l pr, @-r15
    mov.l @(8, r15), r3
    mov.l r3, @-r15
    mov.l @(8, r15), r3
    mov.l r3, @-r15
    .byte   0xBF, 0x68    /* bsr 0x0603FD40 (external) */
    mov #0x1, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop

    .global loc_0603FE78
loc_0603FE78:
    rts
    mov #0x0, r0

    .global loc_0603FE7C
loc_0603FE7C:
    rts
    mov #0x1, r0

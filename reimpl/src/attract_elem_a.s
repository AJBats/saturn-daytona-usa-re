
    .section .text.FUN_0603FE44


    .global attract_elem_a
    .type attract_elem_a, @function
attract_elem_a:
    sts.l pr, @-r15
    mov.l @(8, r15), r3
    mov.l r3, @-r15
    mov.l @(8, r15), r3
    mov.l r3, @-r15
    .reloc ., R_SH_IND12W, dma_param_chain_init - 4
    .2byte 0xB000    /* bsr dma_param_chain_init (linker-resolved) */
    mov #0x0, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop

    .global loc_0603FE5A
loc_0603FE5A:
    rts
    mov #0x0, r0

    .global loc_0603FE5E
loc_0603FE5E:
    rts
    mov #0x1, r0

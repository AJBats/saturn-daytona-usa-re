	.text
    .global disp_elem_proc_4
disp_elem_proc_4:
    sts.l pr, @-r15
    .byte   0xB0, 0x32    /* bsr 0x06032304 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0F    /* mov.l .L_pool_060322E0, r4 */

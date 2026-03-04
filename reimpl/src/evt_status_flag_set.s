
    .section .text.FUN_06040954


    .global evt_status_flag_set
    .type evt_status_flag_set, @function
evt_status_flag_set:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, evt_condition_return - 4
    .2byte 0xB000    /* bsr evt_condition_return (linker-resolved) */
    nop
    shll8 r0
    lds.l @r15+, pr
    shll2 r0
    rts
    shll r0

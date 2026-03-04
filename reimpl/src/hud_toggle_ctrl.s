
    .section .text.FUN_0603F22C


    .global hud_toggle_ctrl
    .type hud_toggle_ctrl, @function
hud_toggle_ctrl:
    mov.l   .L_0603F234, r4
    .reloc ., R_SH_IND12W, credits_scroll_entry - 4
    .2byte 0xA000    /* bra credits_scroll_entry (linker-resolved) */
    nop
    .2byte  0xFFFF
.L_0603F234:
    .4byte  0x00FFFFFF

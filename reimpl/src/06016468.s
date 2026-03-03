
    .section .text.FUN_06016468


    .global hud_results_stub_b
    .type hud_results_stub_b, @function
hud_results_stub_b:
    mov.l r14, @-r15
    mov #0x40, r0
    mov.l r13, @-r15
    mov r4, r13

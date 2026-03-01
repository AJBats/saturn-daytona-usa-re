
    .section .text.FUN_06016228


    .global hud_results_stub_a
    .type hud_results_stub_a, @function
hud_results_stub_a:
    mov.l r14, @-r15
    extu.b r4, r14
    mov.l r13, @-r15
    mov r14, r3

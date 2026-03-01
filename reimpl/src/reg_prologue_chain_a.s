
    .section .text.FUN_06038F6C


    .global reg_prologue_chain_a
    .type reg_prologue_chain_a, @function
reg_prologue_chain_a:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x0, r10

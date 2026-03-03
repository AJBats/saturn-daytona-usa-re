	.text
    .global reg_prologue_chain_b
reg_prologue_chain_b:
    mov.l r14, @-r15
    mov #0x0, r14

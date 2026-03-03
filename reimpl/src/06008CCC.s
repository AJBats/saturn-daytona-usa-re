	.text
    .global state_mode_select_entry
state_mode_select_entry:
    mov.l r14, @-r15
    mov #0x0, r14

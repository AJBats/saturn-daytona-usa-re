	.text
    .global state_timeext_setup
state_timeext_setup:
    mov.l r14, @-r15
    mov #0x0, r5

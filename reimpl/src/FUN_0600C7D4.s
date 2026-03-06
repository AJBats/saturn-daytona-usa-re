
    .section .text.FUN_0600C7D4


    /* THEORY: fall-through prologue for FUN_0600C7D8.
       2 instructions: push r14, r14=r4 (car pointer). Falls through into
       FUN_0600C7D8 which contains the actual logic. See FUN_0600C7D8 for
       the heading_and_position_update theory.
       Evidence: NOP'd BSR→FUN_0600C7D4 at 0x0600c71e — skips both this
       prologue and the FUN_0600C7D8 body it falls into. */
    .global FUN_0600C7D4
    .type FUN_0600C7D4, @function
FUN_0600C7D4:
    mov.l r14, @-r15
    mov r4, r14

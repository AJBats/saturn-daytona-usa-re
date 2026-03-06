
    .section .text.FUN_0600C8CC


    /* THEORY: fall-through prologue for FUN_0600C8D0.
       2 instructions: push r14, r14=r4 (car pointer). Falls through into
       FUN_0600C8D0 which contains the actual logic. See FUN_0600C8D0 for
       the heading_angle_update theory.
       Evidence: NOP'd BSR→FUN_0600C8CC at 0x0600c6ac — skips both this
       prologue and the FUN_0600C8D0 body it falls into. */
    .global FUN_0600C8CC
    .type FUN_0600C8CC, @function
FUN_0600C8CC:
    mov.l r14, @-r15
    mov r4, r14

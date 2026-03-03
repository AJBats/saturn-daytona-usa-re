
    .section .text.FUN_0603F202


    .global sprite_batch_emit
    .type sprite_batch_emit, @function
sprite_batch_emit:
    mov r4, r0
    mov r4, r3
    shll2 r0
    shll2 r3
    shll r3
    add r3, r0
    add r5, r0
    mov.b @(11, r0), r0
    rts
    extu.b r0, r0

    .global sym_0603F216
sym_0603F216:
    mov r4, r0
    mov r4, r3
    shll2 r0
    shll2 r3
    shll r0
    shll2 r3
    add r3, r0
    add r5, r0
    mov.b @(11, r0), r0
    rts
    extu.b r0, r0

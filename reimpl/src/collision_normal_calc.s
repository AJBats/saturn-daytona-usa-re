
    .section .text.FUN_06036754


    .global collision_normal_calc
    .type collision_normal_calc, @function
collision_normal_calc:
    sts.l pr, @-r15
    mov r4, r12
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_pool_060367A0, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x56, r3
    mov r15, r5
    mov r15, r4
    add #0x8, r2
    mov.b r3, @r2
    .byte   0xBF, 0x6F    /* bsr 0x06036650 (external) */
    add #0x8, r4
    mov r0, r4
    mov r15, r2
    mov.w @(2, r2), r0
    mov r0, r3
    extu.w r3, r3
    mov.l r3, @r13
    mov r15, r3
    mov.b @(4, r3), r0
    mov r15, r3
    mov r0, r2
    extu.b r2, r2
    mov r4, r0
    mov.l r2, @r12
    mov.l @(4, r3), r2
    mov.l   .L_060367A8, r3
    and r3, r2
    mov.l r2, @r14
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_060367A0:
    .4byte  input_proc_analog           /* [HIGH] fn ptr: SMPC analog axis reader */
    .4byte  input_proc_buttons          /* [HIGH] fn ptr: SMPC button state reader */
.L_060367A8:
    .4byte  0x00FFFFFF                  /* low 24-bit mask */

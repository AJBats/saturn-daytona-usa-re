
    .section .text.FUN_06013E14


    .global score_commit_save
    .type score_commit_save, @function
score_commit_save:
    mov.l r14, @-r15
    mov.l   .L_06013E34, r0
    mov.l @r0, r0
    and #0x1F, r0
    exts.w r0, r14
    cmp/gt r2, r14
    bf      .L_06013E30
    shll8 r14
    shll2 r14
    shll2 r14
    exts.w r14, r4
    mov.l   .L_06013E38, r3
    jmp @r3
    mov.l @r15+, r14
.L_06013E30:
    rts
    mov.l @r15+, r14
.L_06013E34:
    .4byte  sym_0607EBC8
.L_06013E38:
    .4byte  mat_rot_y

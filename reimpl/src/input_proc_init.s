
    .section .text.FUN_06035E00


    .global input_proc_init
    .type input_proc_init, @function
input_proc_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r11, @-r15
    mov.l   .L_cd_hirq, r11
    mov.l   .L_hirq_timeout_limit, r13
    mov #0x0, r14
    mov #-0x3, r1
    mov r14, r7
.L_poll_hirq:
    mov.w @r11, r6
    extu.w r4, r2
    extu.w r6, r3
    and r2, r3
    tst r3, r3
    bt      .L_not_yet
    mov r14, r1
    bra     .L_poll_done
    mov.w r6, @r5
    .2byte  0x00FF
.L_cd_hirq:
    .4byte  0x25890008                  /* CD HIRQ — interrupt request register */
.L_hirq_timeout_limit:
    .4byte  0x00240000                  /* [HIGH] timeout limit — 0x240000 iterations */
.L_not_yet:
    add #0x1, r7
    cmp/ge r13, r7
    bf      .L_poll_hirq
.L_poll_done:
    mov r1, r0
    mov.l @r15+, r11
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .4byte  0x6543D210
    .4byte  0x63512231
    .4byte  0x8551D20F
    .4byte  0x63032231
    .4byte  0x8552D20E
    .4byte  0x63032231
    .4byte  0x8553D20D
    .4byte  0x6303000B
    .2byte  0x2231

    .global sym_06035E5E
sym_06035E5E:
    mov.l   .L_cd_cr1, r3
    mov.w @r3, r3
    mov.w r3, @r4
    mov.l   .L_cd_cr2, r2
    mov.w @r2, r2
    mov r2, r0
    mov.w r0, @(2, r4)
    mov.l   .L_cd_cr3, r3
    mov.w @r3, r3
    mov r3, r0
    mov.w r0, @(4, r4)
    mov.l   .L_cd_cr4, r3
    mov.w @r3, r3
    mov r3, r0
    rts
    mov.w r0, @(6, r4)
    .2byte  0xFFFF
.L_cd_cr1:
    .4byte  0x25890018                  /* CD CR1 — command register 1 */
.L_cd_cr2:
    .4byte  0x2589001C                  /* CD CR2 — command register 2 */
.L_cd_cr3:
    .4byte  0x25890020                  /* CD CR3 — command register 3 */
.L_cd_cr4:
    .4byte  0x25890024                  /* CD CR4 — command register 4 */

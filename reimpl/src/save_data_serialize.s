
    .section .text.FUN_0603BEB8


    .global save_data_serialize
    .type save_data_serialize, @function
save_data_serialize:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_ptr_evt_field_extract, r3
    jsr @r3
    mov.l r11, @-r15
    bra     .L_epilogue
    add #0x10, r15
    .4byte  0x25588901                  /* tst r5,r5; bt +1 */
    .4byte  0x63422532                  /* mov.l @r4,r3; mov.l r3,@r5 */
    .4byte  0x26688901                  /* tst r6,r6; bt +1 */
    .4byte  0x53412632                  /* mov.l @(4,r4),r3; mov.l r3,@r6 */
    .4byte  0x2DD88903                  /* tst r13,r13; bt +3 */
    .4byte  0xE01C034C                  /* mov #0x1C,r0; mov.b @(r0,r4),r3 */
    .4byte  0x633C2D32                  /* extu.b r3,r3; mov.l r3,@r13 */
    .4byte  0x27788901                  /* tst r7,r7; bt +1 */
    .4byte  0x53432732                  /* mov.l @(12,r4),r3; mov.l r3,@r7 */
    .4byte  0x2BB88901                  /* tst r11,r11; bt +1 */
    .4byte  0x53442B32                  /* mov.l @(16,r4),r3; mov.l r3,@r11 */
    .4byte  0x2EE88903                  /* tst r14,r14; bt +3 */
    .4byte  0xE01D034C                  /* mov #0x1D,r0; mov.b @(r0,r4),r3 */
    .4byte  0x633C2E32                  /* extu.b r3,r3; mov.l r3,@r14 */
    .4byte  0x2CC88903                  /* tst r12,r12; bt +3 */
    .4byte  0x53435245                  /* mov.l @(12,r4),r3; mov.l @(20,r4),r2 */
    .4byte  0x33282C32                  /* sub r2,r3; mov.l r3,@r12 */
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_ptr_evt_field_extract:
    .4byte  sym_06040220                /* evt_field_extract */
    .4byte  0x504A000B                  /* embedded: mov.l @(0x28,r4),r0; rts */
    .2byte  0x145A                      /* embedded: mov.l r5,@(0x28,r4) [delay slot] */

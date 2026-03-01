
    .section .text.FUN_06036928


    .global obj_lod_select
    .type obj_lod_select, @function
obj_lod_select:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06036974, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x65, r3
    extu.b r14, r14
    extu.w r11, r11
    extu.b r13, r13
    extu.w r12, r12
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.b r0, @(1, r2)
    mov r11, r0
    mov.w r0, @(2, r3)
    mov r15, r3
    mov r13, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r12, r0
    mov.w r0, @(6, r3)
    mov.w   .L_06036972, r4
    mov.l   .L_06036978, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x0080                      /* alignment padding */
.L_06036972:
    .2byte  0x0100                      /* [MEDIUM] command parameter mask — 0x100 (cf. 0x0080 in obj_visibility_check, 0x0200 in ai_master_update) */
.L_06036974:
    .4byte  input_proc_analog           /* [HIGH] fn ptr: SMPC analog axis reader / buffer initializer */
.L_06036978:
    .4byte  input_proc_buttons          /* [HIGH] fn ptr: SMPC digital button reader / command dispatcher */

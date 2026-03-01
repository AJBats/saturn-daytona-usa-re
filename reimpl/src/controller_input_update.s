/* VERIFIED: controller input state updater — reads SMPC peripheral data,
 * NOT-inverts active-LOW encoding, writes processed button state to g_pad_state.
 * Method: watchpoint on g_pad_state at mode select screen
 *   DOWN:  word[+0]=0x2000, word[+2]=0x2000  (SMPC bit 13 = DOWN)
 *   UP:    word[+0]=0x1000, word[+2]=0x1000  (SMPC bit 12 = UP)
 *   LEFT:  word[+0]=0x4000, word[+2]=0x4000  (SMPC bit 14 = LEFT)
 *   RIGHT: word[+0]=0x8000, word[+2]=0x8000  (SMPC bit 15 = RIGHT)
 *   C:     word[+0]=0x0200, word[+2]=0x0200  (SMPC bit 9 = C)
 *   No button: no writes at all.
 *   All writes come from controller_input_update (PC +0x5E and +0x62).
 *   Static analysis confirms data source is SMPC OREGs via smpc_data_manage.
 * Date: 2026-02-28
 */

    .section .text.FUN_06005198


    .global controller_input_update
    .type controller_input_update, @function
controller_input_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06005220, r14
    mov.l   .L_pool_06005224, r3
    jsr @r3
    mov r15, r4
    mov.l @r15, r1
    mov.w @r1, r1
    extu.w r1, r1
    not r1, r1
    extu.w r1, r1
    mov.l @r15, r12
    mov.w @(8, r12), r0
    mov r0, r12
    extu.w r12, r12
    not r12, r12
    extu.w r12, r12
    mov.l @r15, r5
    mov.w @(2, r5), r0
    mov r0, r5
    not r5, r5
    extu.w r5, r5
    mov.l @r15, r4
    add #0x12, r4
    mov.w @r4, r6
    extu.w r6, r6
    not r6, r6
    extu.w r6, r6
    mov.w @(8, r4), r0
    mov r0, r7
    extu.w r7, r7
    not r7, r7
    extu.w r7, r7
    mov.w @(2, r4), r0
    mov r0, r13
    not r13, r13
    mov.l   .L_pool_06005228, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf/s    .L_0600522C
    extu.w r13, r13
    mov r14, r4
    mov.w r1, @r4
    mov r12, r0
    mov.w r0, @(2, r4)
    mov r5, r0
    mov.w r0, @(4, r4)
    mov.l @r15, r3
    mov #0x10, r0
    mov.b @(r0, r3), r3
    extu.b r3, r0
    mov.w r0, @(6, r4)
    add #0x8, r4
    mov.w r6, @r4
    mov r7, r0
    mov.w r0, @(2, r4)
    mov r13, r0
    mov.w r0, @(4, r4)
    mov.l @r15, r3
    add #0x12, r3
    mov #0x10, r0
    mov.b @(r0, r3), r3
    extu.b r3, r0
    bra     .L_06005260
    mov.w r0, @(6, r4)
.L_pool_06005220:
    .4byte  g_pad_state
.L_pool_06005224:
    .4byte  smpc_data_manage
.L_pool_06005228:
    .4byte  sym_06059F44
.L_0600522C:
    mov r14, r4
    extu.w r1, r1
    mov.w @r4, r2
    or r1, r2
    mov.w r2, @r4
    extu.w r12, r12
    mov.w @(2, r4), r0
    mov r0, r3
    or r12, r3
    mov r3, r0
    mov.w r0, @(2, r4)
    mov r5, r0
    mov.w r0, @(4, r4)
    add #0x8, r4
    extu.w r6, r6
    mov.w @r4, r3
    or r6, r3
    mov.w r3, @r4
    extu.w r7, r7
    mov.w @(2, r4), r0
    mov r0, r2
    or r7, r2
    mov r2, r0
    mov.w r0, @(2, r4)
    mov r13, r0
    mov.w r0, @(4, r4)
.L_06005260:
    mov.w @(6, r14), r0
    extu.w r0, r0
    cmp/eq #0x20, r0
    bf      .L_06005288
    mov #0x0, r4
    mov r14, r5
    mov.w r4, @r5
    extu.w r4, r0
    mov.w r0, @(2, r5)
    extu.w r4, r0
    mov.w r0, @(4, r5)
    add #0x8, r5
    extu.w r4, r3
    mov.w r3, @r5
    extu.w r4, r2
    mov r2, r0
    mov.w r0, @(2, r5)
    extu.w r4, r4
    mov r4, r0
    mov.w r0, @(4, r5)
.L_06005288:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

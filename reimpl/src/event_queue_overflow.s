
    .section .text.FUN_06040F1C


    .global event_queue_overflow
    .type event_queue_overflow, @function
event_queue_overflow:
    sts.l pr, @-r15
    mov.l   .L_pool_06040F3C, r13
    cmp/pz r14
    bf      .L_06040F2A
    mov #0x18, r2
    cmp/ge r2, r14
    bf      .L_06040F2E
.L_06040F2A:
    bra     .L_06040F7A
    mov #-0x6, r0
.L_06040F2E:
    mov.l @r13, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x1, r0
    bt      .L_06040F40
    bra     .L_06040F7A
    mov #-0x7, r0
    .2byte  0xFFFF
.L_pool_06040F3C:
    .4byte  sym_060A5400
.L_06040F40:
    .byte   0xD6, 0x19    /* mov.l .L_pool_06040FA8, r6 */
    mov #0x0, r5
    .reloc ., R_SH_IND12W, evt_checkpoint_validate - 4
    .2byte 0xB000    /* bsr evt_checkpoint_validate (linker-resolved) */
    mov r14, r4
    .byte   0xD4, 0x18    /* mov.l .L_pool_06040FAC, r4 */
    mov.l @r13, r2
    mov.l r4, @(60, r2)
.L_06040F4E:
    .reloc ., R_SH_IND12W, large_prologue_save - 4
    .2byte 0xB000    /* bsr large_prologue_save (linker-resolved) */
    nop
    cmp/eq #0x3, r0
    bf/s    .L_06040F5C
    mov r0, r4
    bra     .L_06040F7A
    mov #-0xC, r0
.L_06040F5C:
    .reloc ., R_SH_IND12W, FUN_06041310 - 4
    .2byte 0xB000    /* bsr FUN_06041310 (linker-resolved) */
    mov r14, r4
    cmp/eq #0x1, r0
    bf      .L_06040F68
    bra     .L_06040F6C
    nop
.L_06040F68:
    bra     .L_06040F4E
    nop
.L_06040F6C:
    mov #0x0, r4
    mov r4, r5
    mov.l @r13, r2
    mov.l r4, @(60, r2)
    mov.l @r13, r0
    mov.b r5, @(r0, r14)
    mov r5, r0
.L_06040F7A:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

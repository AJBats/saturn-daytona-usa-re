    .section .text.FUN_060423A0
    .global bulk_struct_init
    .type bulk_struct_init, @function
/* bulk_struct_init(r4=struct_ptr) — initialize struct fields via callback.
 * Calls ai_checkpoint_validate to fill a 12-byte stack buffer,
 * then copies byte from buffer to struct at offset 0x40.
 * Also provides sym_060423BC/sym_060423C4: field setters at offsets 0x4C/0x50.
 * Cross-TU pool refs reach into cdb_wait_scdq's pool.
 */
bulk_struct_init:
    sts.l pr, @-r15
    add #-0xC, r15
    .byte 0xD3, 0x14              /* mov.l @(pool), r3 -- ai_checkpoint_validate [cross-TU] */
    jsr @r3
    mov r15, r4                   /* r4 = stack buffer (delay slot) */
    mov r15, r3
    mov #0x40, r0
    .byte 0xD2, 0x13              /* mov.l @(pool), r2 -- sym_060A5400 [cross-TU] */
    mov.b @r3, r1
    mov.l @r2, r2
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.b r1, @(r0, r2)          /* struct[0x40] = buffer[0] (delay slot) */
    .global sym_060423BC
sym_060423BC:
    .byte 0xD6, 0x0F              /* mov.l @(pool), r6 -- sym_060A5400 [cross-TU] */
    mov #0x4C, r0
    mov.l @r6, r3
    mov.l r4, @(r0, r3)          /* struct[0x4C] = r4 */
    mov.l @r6, r3
    mov #0x50, r0
    rts
    mov.l r5, @(r0, r3)          /* struct[0x50] = r5 (delay slot) */

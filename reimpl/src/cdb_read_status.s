/* cdb_read_status — Read CD block status byte (5-bit masked)
 *
 * Calls FUN_060349C4 to fill a 12-byte buffer, reads first byte,
 * returns it masked to 5 bits (& 0x1F).
 * Caller (FUN_0600A392) uses bottom 4 bits as CD tray status.
 *
 * Original address: 0x06018EAC
 */

/* scsp_set_master_volume — Set SCSP master output volume
 *
 * Writes 0xE0 to SCSP slot 16+17 EFSDL/EFPAN registers.
 * Sets effect send level for main output channels.
 *   Slot 16: 0x25B00217
 *   Slot 17: 0x25B00237
 *
 * Original address: 0x06018EC8
 */

    .section .text.FUN_06018EAC
    .global cdb_read_status
    .type cdb_read_status, @function

cdb_read_status:
    sts.l   pr, @-r15           /* save return address */
    add     #-12, r15           /* allocate 12-byte buffer on stack */
    mov.l   .L_FUN_060349C4, r3 /* r3 = FUN_060349C4 */
    jsr     @r3                 /* call FUN_060349C4(buffer) */
    mov     r15, r4             /* delay: r4 = stack buffer */
    mov     r15, r0             /* r0 = stack buffer */
    mov     #31, r4             /* r4 = 0x1F mask */
    mov.b   @r0, r0             /* r0 = first byte of result */
    add     #12, r15            /* deallocate stack */
    extu.b  r0, r0              /* zero-extend byte */
    lds.l   @r15+, pr           /* restore return address */
    and     r0, r4              /* r4 = r0 & 0x1F */
    rts                         /* return */
    mov     r4, r0              /* delay: r0 = masked status */

    .global scsp_set_master_volume
    .type scsp_set_master_volume, @function

scsp_set_master_volume:
    mov.w   .L_volume, r4       /* r4 = 0x00E0 (volume level) */
    mov.l   .L_slot16, r2       /* r2 = 0x25B00217 (slot 16 EFSDL) */
    extu.b  r4, r3              /* r3 = 0xE0 */
    mov.b   r3, @r2             /* write 0xE0 to slot 16 */
    mov.l   .L_slot17, r3       /* r3 = 0x25B00237 (slot 17 EFSDL) */
    rts                         /* return */
    mov.b   r4, @r3             /* delay: write 0xE0 to slot 17 */

    /* Constant pool */
    .align 1
.L_volume:
    .word   0x00E0

    .align 2
.L_FUN_060349C4:
    .4byte  FUN_060349C4
.L_slot16:
    .4byte  0x25B00217
.L_slot17:
    .4byte  0x25B00237

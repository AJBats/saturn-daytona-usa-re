/* smpc_peripheral_query.s -- SMPC peripheral status query via CD block HIRQ
 * Translation unit: 0x06035D5A - 0x06035E00
 *
 * Function catalog:
 *   smpc_peripheral_query — Queries CD block status using HIRQ register,
 *                           validates peripheral response, returns error code.
 *
 * This function queries peripheral/CD status through the SCU/CD interface.
 * It reads CD HIRQ (interrupt request register) to check command completion,
 * validates the response, and returns a status code.
 *
 * Error codes:
 *   0  = success (peripheral connected and responding)
 *  -1  = HIRQ bits not set (command not completed)
 *  -2  = busy flag set in status
 *  -5  = disconnect marker (0xFF response)
 *  -6  = error flag set (bit 7 of response)
 */

    .section .text.FUN_06035D5A

    .global smpc_peripheral_query
    .type smpc_peripheral_query, @function
smpc_peripheral_query:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r5, r13                /* r13 = param2 */
    mov.l r12, @-r15
    mov r4, r12                /* r12 = param1 (HIRQ bit mask) */
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15             /* allocate 4 bytes on stack */
    .byte   0xDE, 0x09    /* mov.l .L_hirq_status, r14 */
    .byte   0xD3, 0x09    /* mov.l .L_cd_hirq, r3 */
    mov.w @r14, r2             /* r2 = current HIRQ status word */
    mov.w @r3, r3              /* r3 = CD HIRQ register value */
    extu.w r3, r3
    or r3, r2                  /* merge new HIRQ bits into status */
    mov.w r2, @r14             /* store updated status */
    mov.w @r14, r3
    extu.w r3, r3
    and r12, r3                /* test requested HIRQ bits */
    cmp/eq r12, r3             /* all requested bits set? */
    bt/s    .L_06035D98        /* yes: proceed to check response */
    mov r6, r11                /* r11 = param3 (output buffer) */
    bra     .L_06035DF2
    mov #-0x1, r0              /* return -1: HIRQ not ready */
    .4byte  0xFF0FFFFF         /* mask constant (embedded in code stream) */
    .4byte  ai_brake_zone_main /* cross-TU reference (not used by this fn) */
.L_hirq_status:
    .4byte  sym_06063590       /* HIRQ status cache word */
.L_cd_hirq:
    .4byte  0x25890008                  /* CD HIRQ — interrupt request */

    /* HIRQ bits matched — check for busy flag */
.L_06035D98:
    mov.w @r14, r0
    extu.w r0, r0
    tst #0x1, r0               /* busy bit set? */
    bf      .L_06035DA4        /* no (bit clear): continue */
    bra     .L_06035DF2
    mov #-0x2, r0              /* return -2: busy */

    /* Clear busy and requested HIRQ bits, then read response */
.L_06035DA4:
    mov #0x1, r4
    or r12, r4                 /* r4 = busy_bit | requested_bits */
    not r4, r4                 /* invert to create clear mask */
    .byte   0xBF, 0x60    /* bsr 0x06035C6E (smpc_cmd_helper_b) */
    extu.w r4, r4              /* clear unwanted bits from status */
    mov #-0x2, r2
    mov.w @r14, r3
    and r2, r3                 /* clear bit 0 (busy) */
    mov.w r3, @r14             /* update HIRQ status cache */
    .byte   0xB0, 0x41    /* bsr 0x06035E3C (external helper) */
    mov r13, r4                /* pass param2 */
    mov r15, r5                /* pass stack buffer */
    .byte   0xB0, 0x20    /* bsr 0x06035E00 (read response) */
    mov #0x1, r4
    mov r0, r13                /* r13 = response status */
    tst r13, r13
    bt      .L_06035DCA        /* status == 0: check response data */
    bra     .L_06035DF2
    mov r13, r0                /* return error from sub-call */

    /* Validate response data */
.L_06035DCA:
    .byte   0xB0, 0x48    /* bsr 0x06035E5E (read peripheral data) */
    mov r11, r4                /* pass output buffer */
    mov.b @r11, r4             /* r4 = first response byte */
    .byte   0x93, 0x27    /* mov.w .L_wpool_06035E22, r3 */
    extu.b r4, r2
    cmp/eq r3, r2              /* response == 0xFF? (disconnect) */
    bf      .L_06035DDC
    bra     .L_06035DE4
    mov #-0x5, r13             /* return -5: disconnected */

.L_06035DDC:
    extu.b r4, r0
    tst #0x80, r0              /* error bit set? */
    bt      .L_06035DE4
    mov #-0x6, r13             /* return -6: error flag */

    /* On success, clear the requested HIRQ bits from cache */
.L_06035DE4:
    tst r13, r13               /* error code == 0? */
    bf      .L_06035DF0        /* no: skip clearing */
    not r12, r12               /* invert request mask */
    mov.w @r14, r3
    and r12, r3                /* clear requested bits */
    mov.w r3, @r14

    /* Epilogue */
.L_06035DF0:
    mov r13, r0                /* r0 = return value */
.L_06035DF2:
    add #0x4, r15              /* free stack */
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

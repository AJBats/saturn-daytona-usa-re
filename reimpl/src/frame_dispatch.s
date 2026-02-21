/* frame_dispatch — Per-frame subsystem dispatcher
 *
 * Calls 4 subsystems sequentially each frame:
 *   1. FUN_06005C98 (BSR)
 *   2. FUN_06005A22 (BSR)
 *   3. FUN_06005928 (BSR)
 *   4. FUN_06005AE8 (BRA tail-call)
 *
 * Original address: 0x060058FA
 *
 * NOTE: BSR/BRA kept as .byte — sh-elf-as cannot generate 12-bit
 * PC-relative relocations for external symbols. Displacements are
 * correct as long as sections maintain original relative ordering.
 */

    .section .text.FUN_060058FA
    .global frame_dispatch
    .type frame_dispatch, @function

frame_dispatch:
    sts.l   pr, @-r15           /* save return address */
    .byte   0xB1, 0xCC          /* bsr FUN_06005C98 (subsystem 1) */
    nop                         /* delay slot */
    .byte   0xB0, 0x8F          /* bsr FUN_06005A22 (subsystem 2) */
    nop                         /* delay slot */
    .byte   0xB0, 0x10          /* bsr FUN_06005928 (subsystem 3) */
    nop                         /* delay slot */
    .byte   0xA0, 0xEE          /* bra FUN_06005AE8 (tail-call subsystem 4) */
    lds.l   @r15+, pr           /* delay slot: restore PR before tail-call */

    /* Pool / data (referenced by neighboring functions via PC-relative loads) */
    .byte   0x01, 0x10
    .global DAT_0600590e
DAT_0600590e:
    .byte   0x01, 0x4E
    .global DAT_06005910
DAT_06005910:
    .byte   0x10, 0x00
    .byte   0xFF, 0xFF
    .4byte  sym_06028430
    .4byte  sym_0607EAE0
    .4byte  sym_0607EA98
    .4byte  sym_06078644
    .4byte  sym_06028400

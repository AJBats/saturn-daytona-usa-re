/* Test data for sym_0602D814 unit test */

    .section .bss
    .align 4

/* Two car structs for vanilla vs decomp comparison */
    .global vanilla_car
vanilla_car:
    .space 0x268

    .global decomp_car
decomp_car:
    .space 0x268

/* Gear ratio table — copied from original binary at sym_060477BC */
    .section .rodata
    .align 4
    .global sym_060477BC
sym_060477BC:
    .4byte 0x00093756    /* gear 0 */
    .4byte 0x0005A223    /* gear 1 */
    .4byte 0x0003E677    /* gear 2 */
    .4byte 0x0003122B    /* gear 3 */
    .4byte 0x00000000    /* gear 4 (unused, safety) */
    .4byte 0x00000000    /* gear 5 */
    .4byte 0x00000000    /* gear 6 */
    .4byte 0x00000000    /* gear 7 */

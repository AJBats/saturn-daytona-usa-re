
    .section .text.FUN_06042ACA


    .global palette_engine_core
    .type palette_engine_core, @function
palette_engine_core:
    mov r5, r3
    mov.l @r4, r2
    mov #0x1, r6
    shll2 r3
    shll2 r3
    add #-0x80, r3
    mov.l r2, @r3
    mov.l @(36, r4), r3
    and r6, r3
    cmp/eq r6, r3
    bf      .L_06042AEC
    mov r5, r3
    shll2 r3
    shll2 r3
    add #-0x7C, r3
    mov.l @(4, r4), r2
    mov.l r2, @r3
.L_06042AEC:
    mov #0x2, r6
    mov.l @(36, r4), r3
    and r6, r3
    cmp/eq r6, r3
    bf      .L_06042B02
    mov r5, r3
    shll2 r3
    shll2 r3
    add #-0x78, r3
    mov.l @(8, r4), r2
    mov.l r2, @r3
.L_06042B02:
    mov r5, r7
    mov.l @(36, r4), r0
    shll2 r7
    and #0x4, r0
    shll2 r7
    add #-0x74, r7
    cmp/eq #0x4, r0
    bf/s    .L_06042B24
    mov.l @r7, r6
    .byte   0xD2, 0x24    /* mov.l .L_pool_06042BA9, r2 */
    and r2, r6
    mov.l @(12, r4), r3
    shll8 r3
    shll2 r3
    shll2 r3
    shll2 r3
    or r3, r6
.L_06042B24:
    mov.l @(36, r4), r0
    and #0x8, r0
    cmp/eq #0x8, r0
    bf      .L_06042B3A
    mov.w   .L_wpool_06042B9D, r3
    and r3, r6
    mov.l @(16, r4), r2
    shll8 r2
    shll2 r2
    shll2 r2
    or r2, r6
.L_06042B3A:
    mov.l @(36, r4), r0
    and #0x10, r0
    cmp/eq #0x10, r0
    bf      .L_06042B4A
    mov.w   .L_wpool_06042B9F, r2
    and r2, r6
    mov.l @(20, r4), r3
    or r3, r6
.L_06042B4A:
    mov.l @(36, r4), r0
    and #0x20, r0
    cmp/eq #0x20, r0
    bf      .L_06042B5A
    mov.w   .L_wpool_06042BA1, r3
    and r3, r6
    mov.l @(24, r4), r2
    or r2, r6
.L_06042B5A:
    mov #-0x11, r3
    mov #-0x9, r2
    mov.l @(36, r4), r0
    and r3, r6
    and #0x40, r0
    cmp/eq #0x40, r0
    bf/s    .L_06042B72
    and r2, r6
    mov #-0x5, r2
    and r2, r6
    mov.l @(28, r4), r3
    or r3, r6
.L_06042B72:
    mov.l @(36, r4), r2
    mov.w   .L_wpool_06042BA3, r3
    and r3, r2
    mov r3, r1
    cmp/eq r1, r2
    bf      .L_06042B82
    mov #-0x3, r2
    and r2, r6
.L_06042B82:
    mov.l r6, @r7
    mov.w   .L_wpool_06042BA5, r6
    mov.l @(36, r4), r3
    and r6, r3
    cmp/eq r6, r3
    bf      .L_06042B98
    mov.w   DAT_06042ba6, r3
    add r3, r5
    mov.l @(32, r4), r2
    extu.b r2, r2
    mov.b r2, @r5
.L_06042B98:
    rts
    nop
.L_wpool_06042B9D:
    .2byte  0xCFFF              /* ~0x3000: clear palette number bits [13:12] */
.L_wpool_06042B9F:
    .2byte  0xF3FF              /* ~0x0C00: clear color offset bits [11:10] */
.L_wpool_06042BA1:
    .2byte  0xFDFF              /* ~0x0200: clear special priority bit 9 */
.L_wpool_06042BA3:
    .2byte  0x0100              /* flag bit 8: enable/transparency control */
.L_wpool_06042BA5:
    .2byte  0x0080              /* flag bit 7: auxiliary byte write control */

    .global DAT_06042ba6
DAT_06042ba6:
    .2byte  0xFE71              /* sign-extended offset -0x18F for byte write */
.L_pool_06042BA9:
    .4byte  0xFFFF3FFF          /* ~0x0000C000: clear color bank bits [15:14] */

    .global sym_06042BAC
sym_06042BAC:
    mov r4, r5
    mov #0x1, r3
    shll2 r5
    shll2 r5
    add #-0x74, r5
    mov.l @r5, r4
    or r3, r4
    rts
    mov.l r4, @r5

    .global sym_06042BBE
sym_06042BBE:
    mov r4, r5
    mov #-0x2, r3
    shll2 r5
    shll2 r5
    add #-0x74, r5
    mov.l @r5, r4
    and r3, r4
    rts
    mov.l r4, @r5
    .4byte  0xE5B0E3FE          /* additional helper functions (raw bytes) */
    .4byte  0x64522439
    .4byte  0x000B2542
    .4byte  0xE5B0E304
    .4byte  0xE2026552
    .4byte  0x23592529
    .4byte  0x2432000B
    .2byte  0x1451

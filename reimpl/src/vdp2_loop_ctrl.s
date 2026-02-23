    .section .text.FUN_060172BC
    .global vdp2_loop_ctrl
    .type vdp2_loop_ctrl, @function
/* vdp2_loop_ctrl() — iterate over 18 VDP2 entries, calling init + config for each.
 * Calls sym_060172E4 (struct init) and sym_06017330 (config) for indices 0..17.
 */
vdp2_loop_ctrl:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov #0x12, r12                /* r12 = 18 (loop limit) */
    mov #0x0, r14                 /* r14 = index counter */
.L_060172C8:
    extu.b r14, r13
    bsr sym_060172E4              /* call struct init(r4=index) */
    mov r13, r4                   /* r4 = index (delay slot) */
    bsr .L_06017330               /* call config(r4=index) */
    mov r13, r4                   /* r4 = index (delay slot) */
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r12, r2                /* r2 >= 18? */
    bf .L_060172C8                /* loop if not */
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14              /* (delay slot) */

    .global sym_060172E4
/* sym_060172E4(r4=index) — zero-init a 60-byte struct entry.
 * Computes base = table + index * 68, then zeroes all fields.
 * Cross-TU pool ref for table base address.
 */
sym_060172E4:
    extu.b r4, r4
    mov r4, r3
    shll2 r4                      /* r4 = index * 4 */
    shll2 r3                      /* r3 = index * 4 */
    shll2 r3                      /* r3 = index * 16 */
    shll2 r3                      /* r3 = index * 64 */
    add r3, r4                    /* r4 = index * 68 */
    exts.w r4, r4
    .byte 0xD2, 0x0D              /* mov.l @(pool), r2 -- table base [cross-TU] */
    add r2, r4                    /* r4 = struct base */
    mov #0x0, r5
    extu.b r5, r0
    mov.b r0, @(2, r4)            /* clear byte fields */
    mov.b r0, @(1, r4)
    mov.b r0, @r4
    mov.l r5, @(12, r4)           /* clear long fields */
    mov r5, r3
    mov.l r5, @(8, r4)
    mov r3, r2
    mov.l r3, @(4, r4)
    mov.l r2, @(24, r4)
    mov.l r2, @(20, r4)
    mov.l r2, @(16, r4)
    mov.l r2, @(36, r4)
    mov.l r2, @(32, r4)
    mov.l r2, @(28, r4)
    mov.l r2, @(48, r4)
    mov.l r2, @(44, r4)
    mov.l r2, @(40, r4)
    mov.l r2, @(56, r4)
    mov.l r2, @(52, r4)
    mov #0x41, r0
    mov.b r2, @(r0, r4)           /* clear byte at +0x41 */
    mov #0x40, r0
    rts
    mov.b r2, @(r0, r4)           /* clear byte at +0x40 (delay slot) */
    .4byte sym_06084FC8            /* pool: table base address */

/* sym_06017330(r4=index) — configure a struct entry with 8 sub-slots.
 * Computes base = table + index * 68, zeroes control fields and sub-slot array.
 * Cross-TU pool ref for table base address.
 */
.L_0601732C:
    mov #0x8, r7                  /* r7 = 8 (sub-slot count) */
    mov #0x0, r5                  /* r5 = 0 (fill value) */
.L_06017330:
    extu.b r4, r6
    mov r6, r3
    shll2 r6                      /* r6 = index * 4 */
    shll r6                       /* r6 = index * 8 */
    shll2 r3                      /* r3 = index * 4 */
    shll2 r3                      /* r3 = index * 16 */
    add r3, r6                    /* wait... let me recompute */
    exts.w r6, r6
    .byte 0xD2, 0x17              /* mov.l @(pool), r2 -- table base [cross-TU] */
    add r2, r6                    /* r6 = struct base */
    extu.b r5, r3
    mov r3, r0
    mov.b r0, @(4, r6)            /* clear byte at +4 */
    mov.w r0, @(6, r6)            /* clear word at +6 */
    extu.b r3, r3
    mov r3, r0
    mov.b r0, @(5, r6)            /* clear byte at +5 */
.L_06017354:
    extu.b r5, r4
    extu.b r4, r3
    mov r6, r2
    exts.w r5, r1
    shll r3                       /* r3 = slot * 2 */
    add #0x1, r4                  /* r4 = slot + 1 */
    add #0x8, r2                  /* r2 = base + 8 */
    add r2, r3                    /* r3 = base + 8 + slot*2 */
    mov.w r1, @r3                 /* sub-slot[slot] = 0 */
    extu.b r4, r3
    cmp/ge r7, r3                 /* slot >= 8? */
    bf .L_06017354                /* loop if not */
    rts
    nop

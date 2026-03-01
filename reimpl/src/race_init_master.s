
    .section .text.FUN_0600EB14


    .global race_init_master
    .type race_init_master, @function
race_init_master:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r14
    mov.w   DAT_0600ebd8, r6
    mov.l   .L_0600EBDC, r4
    mov r14, r5
.L_0600EB20:
    mov.l r14, @r4
    add #0x1, r5
    cmp/hs r6, r5
    bf/s    .L_0600EB20
    add #0x4, r4
    mov.l   .L_0600EBE0, r3
    jsr @r3
    nop
    mov.l   .L_0600EBE4, r3
    jsr @r3
    nop
    mov.l   .L_0600EBE8, r3
    jsr @r3
    nop
    mov #0x1, r5
    mov.l   .L_0600EBDC, r4
    mov.w   .L_0600EBDA, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    extu.w r14, r3
    mov.l   .L_0600EBEC, r2
    mov.w r3, @r2
    mov.l   .L_0600EBF0, r2
    mov.l r14, @r2
    mov.l   .L_0600EBF4, r2
    mov.l r14, @r2
    mov.l   .L_0600EBF8, r2
    mov.l r14, @r2
    mov.l   .L_0600EBFC, r2
    mov.l r14, @r2
    mov #0x0, r1
    mov.l   .L_0600EC00, r2
    mov.l r1, @r2
    mov #0x5, r1
    mov.l   .L_0600EC04, r2
    mov.b r1, @r2
    mov.l   .L_0600EC08, r2
    mov.l r14, @r2
    mov.l   .L_0600EC0C, r2
    mov.l r14, @r2
    mov.l   .L_0600EC10, r2
    mov.l r14, @r2
    mov.l   .L_0600EC14, r2
    mov.l r14, @r2
    exts.b r14, r1
    mov.l   .L_0600EC18, r2
    mov.b r1, @r2
    exts.b r14, r0
    mov.l   .L_0600EC1C, r2
    mov.b r0, @r2
    mov.l   .L_0600EC20, r3
    mov.l r14, @r3
    mov.l   .L_0600EC24, r3
    mov.l r14, @r3
    mov.l   .L_0600EC28, r3
    mov.b r14, @r3
    mov.l   .L_0600EC2C, r3
    mov.l r14, @r3
    mov.l   .L_0600EC30, r3
    mov.l r14, @r3
    mov #0x0, r1
    mov.l   .L_0600EC34, r3
    mov.l r1, @r3
    extu.w r14, r1
    mov.l   .L_0600EC38, r3
    mov.w r1, @r3
    extu.b r14, r0
    mov.l   .L_0600EC3C, r3
    mov.b r0, @r3
    mov.l   .L_0600EC40, r3
    mov.b r14, @r3
    mov #0x0, r1
    mov.l   .L_0600EC44, r3
    mov.l r1, @r3
    mov.l   .L_0600EC48, r3
    mov.l r14, @r3
    mov.l   .L_0600EC4C, r3
    mov.b r14, @r3
    extu.b r14, r0
    mov.l   .L_0600EC50, r3
    mov.b r0, @r3
    mov.l   .L_0600EC54, r4
    mov.w r14, @r4
    extu.w r14, r0
    mov.w r0, @(2, r4)
    bra     .L_0600EC58
    nop

    .global DAT_0600ebd8
DAT_0600ebd8:
    .2byte  0x1810                        /* dword count = 40 cars × 0x268/4 */
.L_0600EBDA:
    .2byte  0x0120                        /* offset to car slot enable flags */
.L_0600EBDC:
    .4byte  sym_06078900               /* car data array (40 × 0x268 bytes) */
.L_0600EBE0:
    .4byte  sym_06026E02               /* camera state reset */
.L_0600EBE4:
    .4byte  sym_060270C6               /* view matrix reset */
.L_0600EBE8:
    .4byte  car_array_init             /* car array structure initialization */
.L_0600EBEC:
    .4byte  sym_06063F46               /* HUD overlay enable flag (16-bit) */
.L_0600EBF0:
    .4byte  sym_0607EAE4               /* race timer A (32-bit) */
.L_0600EBF4:
    .4byte  sym_0607EAE8               /* race timer B (32-bit) */
.L_0600EBF8:
    .4byte  sym_0607EAEC               /* race timer C (32-bit) */
.L_0600EBFC:
    .4byte  sym_0607EBD0               /* frame counter (32-bit) */
.L_0600EC00:
    .4byte  sym_0607EBF4               /* race event bitfield (32-bit) */
.L_0600EC04:
    .4byte  sym_06078654               /* lap count (byte, default 5) */
.L_0600EC08:
    .4byte  sym_0605A1C4               /* race complete flag (32-bit) */
.L_0600EC0C:
    .4byte  sym_06082A30               /* physics state A (32-bit) */
.L_0600EC10:
    .4byte  sym_0607EABC               /* checkpoint state A (32-bit) */
.L_0600EC14:
    .4byte  sym_0607EAC0               /* checkpoint state B (32-bit) */
.L_0600EC18:
    .4byte  sym_06083260               /* race mode (byte) */
.L_0600EC1C:
    .4byte  sym_06082A26               /* AI state (byte) */
.L_0600EC20:
    .4byte  sym_060788FC               /* collision state (32-bit) */
.L_0600EC24:
    .4byte  sym_06082A38               /* physics state B (32-bit) */
.L_0600EC28:
    .4byte  sym_06083261               /* race phase (byte) */
.L_0600EC2C:
    .4byte  sym_0608325C               /* countdown state (32-bit) */
.L_0600EC30:
    .4byte  sym_06083258               /* render state (32-bit) */
.L_0600EC34:
    .4byte  sym_0605A21C               /* display state (32-bit) */
.L_0600EC38:
    .4byte  sym_06086058               /* score display A (16-bit) */
.L_0600EC3C:
    .4byte  sym_0608605A               /* score display B (byte) */
.L_0600EC40:
    .4byte  sym_0605DE3C               /* transition state (byte) */
.L_0600EC44:
    .4byte  sym_060786A8               /* replay state (32-bit) */
.L_0600EC48:
    .4byte  sym_060786BC               /* replay buffer pointer (32-bit) */
.L_0600EC4C:
    .4byte  sym_06085FCC               /* input state (byte) */
.L_0600EC50:
    .4byte  sym_06087060               /* sound state (byte) */
.L_0600EC54:
    .4byte  sym_0602FD98               /* timing registers (5 × 16-bit) */
.L_0600EC58:
    extu.w r14, r0
    mov.w r0, @(4, r4)
    extu.w r14, r0
    mov.w r0, @(6, r4)
    extu.w r14, r0
    mov.l   .L_0600EC70, r3
    jsr @r3
    mov.w r0, @(8, r4)
    lds.l @r15+, pr
    mov.l   .L_0600EC74, r3
    jmp @r3
    mov.l @r15+, r14
.L_0600EC70:
    .4byte  track_obj_placement        /* track object placement */
.L_0600EC74:
    .4byte  sym_06018634               /* scroll position reset (track_utility_misc) */

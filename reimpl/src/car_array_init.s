
    .section .text.FUN_0600629C


    .global car_array_init
    .type car_array_init, @function
car_array_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    extu.w r13, r1
    extu.w r13, r0
    extu.w r13, r3
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_06006364, r8
    mov.w   .L_0600635E, r9
    mov.l   .L_06006368, r10
    mov.l   .L_0600636C, r12
    mov.l   .L_06006370, r14
    mov.l   .L_06006374, r2
    mov.w r13, @r2
    mov.l   .L_06006378, r2
    mov.w r1, @r2
    mov.l   .L_0600637C, r2
    mov.w r0, @r2
    mov.l   .L_06006380, r2
    mov.w r3, @r2
    mov.l   .L_06006384, r1
    mov.b @r1, r1
    extu.b r1, r1
    tst r1, r1
    bt      .L_0600635A
    mov r8, r3
    add r9, r3
    mov.l r3, @r14
    mov r3, r2
    mov.l r3, @r12
    mov.l @r14, r3
    jsr @r10
    mov.l r13, @(4, r3)
    mov.l @r12, r2
    mov #0x38, r3
    mov #0x74, r0
    mov.l r3, @(r0, r2)
    mov.l @r12, r3
    mov #0x38, r2
    add #0x1C, r0
    mov.l r2, @(r0, r3)
    mov.l   .L_06006388, r4
    add #0xE, r0
    mov.l @r12, r3
    mov.b @r4, r2
    extu.b r2, r2
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    mov.b @(1, r4), r0
    mov r0, r2
    extu.b r2, r2
    mov #0x7C, r0
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    mov.b @(2, r4), r0
    mov r0, r2
    extu.b r2, r2
    mov.w   DAT_06006360, r0
    mov.w r2, @(r0, r3)
    mov.l   .L_0600638C, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06006338
    mov.l @r14, r3
    mov.w   DAT_06006362, r0
    mov.w r13, @(r0, r3)
    mov.l @r14, r3
    exts.w r13, r2
    add #0x2, r0
    mov.w r2, @(r0, r3)
    bra     .L_06006348
    nop
.L_06006338:
    mov.l @r14, r2
    mov #0x3, r3
    mov.w   DAT_06006362, r0
    mov.w r3, @(r0, r2)
    mov.l @r14, r3
    mov #0x3, r2
    add #0x2, r0
    mov.w r2, @(r0, r3)
.L_06006348:
    mov r8, r3
    mov.l r8, @r14
    mov r3, r2
    mov.l r3, @r12
    mov.l @r14, r3
    jsr @r10
    mov.l r13, @(4, r3)
    bra     .L_060063A8
    nop
.L_0600635A:
    bra     .L_060063A0
    mov r13, r11
.L_0600635E:
    .2byte  0x0268                      /* car struct size: 616 bytes */

    .global DAT_06006360
DAT_06006360:
    .2byte  0x009C                      /* car struct offset for param[2] */

    .global DAT_06006362
DAT_06006362:
    .2byte  0x00DC                      /* car struct offset for attract fields */
.L_06006364:
    .4byte  sym_06078900               /* car struct array base address */
.L_06006368:
    .4byte  car_type_init              /* per-car type initialization function */
.L_0600636C:
    .4byte  sym_0607E944               /* primary car pointer (stored/persistent, "car ptr stored") */
.L_06006370:
    .4byte  sym_0607E940               /* working car pointer (active/current, "car ptr working") */
.L_06006374:
    .4byte  sym_0605DF4E               /* global state word A (zeroed on init) */
.L_06006378:
    .4byte  sym_0605DF50               /* global state word B (zeroed on init) */
.L_0600637C:
    .4byte  sym_0605DF52               /* global state word C (zeroed on init) */
.L_06006380:
    .4byte  sym_0605DF54               /* global state word D (zeroed on init) */
.L_06006384:
    .4byte  sym_06078635               /* display/phase flag (byte: 0=attract/normal, nonzero=special) */
.L_06006388:
    .4byte  sym_0607ED90               /* 3 config bytes read into car struct (also ring buffer base in other contexts) */
.L_0600638C:
    .4byte  sym_0607EAD8               /* attract cycle counter (dword) */
.L_06006390:
    mul.l r9, r11
    sts macl, r2
    add r8, r2
    mov r2, r3
    mov.l r2, @r14
    jsr @r10
    mov.l r11, @(4, r3)
    add #0x1, r11
.L_060063A0:
    mov.l   .L_06006450, r2
    mov.l @r2, r2
    cmp/ge r2, r11
    bf      .L_06006390
.L_060063A8:
    mov.l @r12, r2
    mov #0x38, r3
    mov #0x74, r0
    mov.l r3, @(r0, r2)
    mov.l @r12, r3
    mov #0x38, r2
    add #0x1C, r0
    mov.l r2, @(r0, r3)
    mov.l @r12, r3
    add #0xC, r0
    mov.l   .L_06006454, r2
    mov.l @r2, r2
    exts.w r2, r2
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    add #0x2, r0
    mov.l   .L_06006458, r2
    mov.w @r2, r2
    mov.w r2, @(r0, r3)
    mov #0x7C, r0
    mov.l @r12, r3
    mov.l   .L_0600645C, r2
    mov.l @r2, r2
    mov.w r2, @(r0, r3)
    mov.l   .L_06006460, r3
    jsr @r3
    nop
    mov.l   .L_06006464, r3
    jsr @r3
    nop
    mov.l   .L_06006468, r0
    mov.l @r0, r0
    cmp/eq #0xE, r0
    bf      .L_060063F4
    mov.l   .L_0600646C, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_060063FE
.L_060063F4:
    mov #0x0, r3
    mov.l   .L_06006470, r2
    mov.l r3, @r2
    bra     .L_06006404
    nop
.L_060063FE:
    mov #0x1, r3
    mov.l   .L_06006470, r2
    mov.l r3, @r2
.L_06006404:
    mov.l @r12, r4
    mov.l   .L_06006474, r3
    mov.l @(32, r4), r2
    mov.l r2, @r3
    add #0x4, r3
    mov.l r13, @r3
    mov.l   .L_06006478, r3
    mov.l r13, @r3
    mov.l   .L_0600647C, r3
    mov.l r13, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_06006480, r3
    mov.l r2, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_06006484, r3
    mov.l r2, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_06006488, r3
    mov.l r2, @r3
    mov.l   .L_0600648C, r2
    mov.l   .L_06006490, r3
    mov.l r2, @r3
    mov.l   .L_0600646C, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06006494
    mov.w   .L_0600644C, r0
    mov.w r13, @(r0, r4)
    exts.w r13, r3
    add #0x2, r0
    mov.w r3, @(r0, r4)
    bra     .L_060064A0
    nop
.L_0600644C:
    .2byte  0x00DC                      /* car struct offset for attract field A */
    .2byte  0xFFFF                      /* padding / alignment */
.L_06006450:
    .4byte  sym_0607EA98               /* total number of cars in race */
.L_06006454:
    .4byte  sym_0607EAB8               /* car type parameter (dword) */
.L_06006458:
    .4byte  sym_06063F42               /* HUD element index (word) */
.L_0600645C:
    .4byte  sym_06078868               /* player car/sprite index (dword) */
.L_06006460:
    .4byte  sym_0600D280               /* car_ptr_list_init — rebuilds sorted car pointer lists */
.L_06006464:
    .4byte  sym_0602E5E4               /* scroll_param_load — initializes rotation scroll parameters */
.L_06006468:
    .4byte  sym_0607EBC0               /* previous game state (saved each frame by main loop) */
.L_0600646C:
    .4byte  sym_0607EAD8               /* attract cycle counter (dword) */
.L_06006470:
    .4byte  sym_0607EAD0               /* race state flag at sym_0607EAD0 (annotations disagree: "race_end_flag" in race_states.s, set=1 here when attract_cycle==0) */
.L_06006474:
    .4byte  sym_06063EF0               /* heading global — car heading copied here (also used by race_update) */
.L_06006478:
    .4byte  sym_06063F10               /* camera angle register (cleared on init, no external confirmation) */
.L_0600647C:
    .4byte  sym_06063E78               /* camera chain A — zero-propagation chain start */
.L_06006480:
    .4byte  sym_06063E8C               /* camera chain B — receives from A */
.L_06006484:
    .4byte  sym_06063E64               /* camera chain C — receives from B */
.L_06006488:
    .4byte  sym_06063E50               /* camera chain D — receives from C */
.L_0600648C:
    .4byte  0xFEA00000                 /* fixed-point 16.16: -352.0 (initial camera Z offset) */
.L_06006490:
    .4byte  sym_06063F14               /* camera param chain E (receives initial Z offset) */
.L_06006494:
    mov #0x3, r2
    .byte   0x90, 0x59    /* mov.w .L_wpool_0600654C, r0 */
    mov.w r2, @(r0, r4)
    mov r2, r3
    add #0x2, r0
    mov.w r3, @(r0, r4)
.L_060064A0:
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006550, r3 */
    mov #0x2, r2
    mov #0x0, r5
    mov.l r13, @r3
    .byte   0xD3, 0x2A    /* mov.l .L_pool_06006554, r3 */
    mov.l r2, @r3
    mov #0x1, r2
    .byte   0xD3, 0x2A    /* mov.l .L_pool_06006558, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x2A    /* mov.l .L_pool_0600655C, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xD2, 0x29    /* mov.l .L_pool_06006560, r2 */
    .byte   0xD3, 0x2A    /* mov.l .L_pool_06006564, r3 */
    mov.l r2, @r3
    .byte   0xD4, 0x2A    /* mov.l .L_pool_06006568, r4 */
    .byte   0xD3, 0x2A    /* mov.l .L_pool_0600656C, r3 */
    mov.l r4, @r3
    .byte   0xD2, 0x2A    /* mov.l .L_pool_06006570, r2 */
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006574, r3 */
    mov.l r2, @r3
    .byte   0xD2, 0x2B    /* mov.l .L_pool_06006578, r2 */
    .byte   0xD3, 0x2B    /* mov.l .L_pool_0600657C, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006580, r3 */
    mov.l r13, @r3
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006584, r3 */
    mov.l r4, @r3
    mov #0x2, r2
    .byte   0xD3, 0x2B    /* mov.l .L_pool_06006588, r3 */
    mov.l r2, @r3
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA1, 0x6B    /* bra 0x060067C8 (external) */
    mov.l @r15+, r14

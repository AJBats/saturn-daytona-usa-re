/* FUN_0600A000: moved to sound_init.c */
__asm__(
    ".balign 4\n"
    ".global _FUN_0600A478\n"
    ".type _FUN_0600A478, @function\n"
    "_FUN_0600A478:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0xD522\n"  /* mov.l @(0x88,PC),r5  {[0x0600A50C] = 0x060628C8} */
    ".word 0xD423\n"  /* mov.l @(0x8C,PC),r4  {[0x0600A510] = 0x06062874} */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0600A514] = 0x06031D8C} */
    ".word 0x35EC\n"  /* add r14,r5 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD621\n"  /* mov.l @(0x84,PC),r6  {[0x0600A518] = 0x0606291C} */
    ".word 0x36EC\n"  /* add r14,r6 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0xD521\n"  /* mov.l @(0x84,PC),r5  {[0x0600A51C] = 0x06089E9E} */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0xD421\n"  /* mov.l @(0x84,PC),r4  {[0x0600A520] = 0x06062820} */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0600A524] = 0x06031A28} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0600A478, .-_FUN_0600A478\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0600A614\n"
    ".type _FUN_0600A614, @function\n"
    "_FUN_0600A614:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDC37\n"  /* mov.l @(0xDC,PC),r12  {[0x0600A700] = 0x06089EDC} */
    ".word 0xDD38\n"  /* mov.l @(0xE0,PC),r13  {[0x0600A704] = 0x00008000} */
    ".word 0xDE38\n"  /* mov.l @(0xE0,PC),r14  {[0x0600A708] = 0x0607EB8C} */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x84E1\n"  /* mov.b @(0x1,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8932\n"  /* bt 0x0600A696 */
    ".word 0xD336\n"  /* mov.l @(0xD8,PC),r3  {[0x0600A70C] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDB36\n"  /* mov.l @(0xD8,PC),r11  {[0x0600A710] = 0x06044640} */
    ".word 0xD236\n"  /* mov.l @(0xD8,PC),r2  {[0x0600A714] = 0xFFFF0F5D} */
    ".word 0x935E\n"  /* mov.w @(0xBC,PC),r3 */
    ".word 0x56B2\n"  /* mov.l @(0x8,r11),r6 */
    ".word 0x55B1\n"  /* mov.l @(0x4,r11),r5 */
    ".word 0x64B2\n"  /* mov.l @r11,r4 */
    ".word 0x362C\n"  /* add r2,r6 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x9259\n"  /* mov.w @(0xB2,PC),r2 */
    ".word 0xD333\n"  /* mov.l @(0xCC,PC),r3  {[0x0600A718] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0xD332\n"  /* mov.l @(0xC8,PC),r3  {[0x0600A71C] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x65E0\n"  /* mov.b @r14,r5 */
    ".word 0x750E\n"  /* add #14,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x0600A720] = 0x060621D8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD22F\n"  /* mov.l @(0xBC,PC),r2  {[0x0600A724] = 0x0606212C} */
    ".word 0xD130\n"  /* mov.l @(0xC0,PC),r1  {[0x0600A728] = 0x06031D8C} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x66E0\n"  /* mov.b @r14,r6 */
    ".word 0x760E\n"  /* add #14,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x0600A72C] = 0x06062180} */
    ".word 0xD52C\n"  /* mov.l @(0xB0,PC),r5  {[0x0600A730] = 0x06089E9C} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD22C\n"  /* mov.l @(0xB0,PC),r2  {[0x0600A734] = 0x060620D8} */
    ".word 0xD12D\n"  /* mov.l @(0xB4,PC),r1  {[0x0600A738] = 0x06031A28} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x73D0\n"  /* add #-48,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0x84E4\n"  /* mov.b @(0x4,r14),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x895A\n"  /* bt 0x0600A754 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0600A70C] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDB25\n"  /* mov.l @(0x94,PC),r11  {[0x0600A73C] = 0x06044670} */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0600A740] = 0xFFFDB334} */
    ".word 0x9227\n"  /* mov.w @(0x4E,PC),r2 */
    ".word 0x56B2\n"  /* mov.l @(0x8,r11),r6 */
    ".word 0x55B1\n"  /* mov.l @(0x4,r11),r5 */
    ".word 0x666B\n"  /* neg r6,r6 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0600A718] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64B2\n"  /* mov.l @r11,r4 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0600A71C] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x84E3\n"  /* mov.b @(0x3,r14),r0 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x750E\n"  /* add #14,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0600A720] = 0x060621D8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x0600A724] = 0x0606212C} */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x0600A728] = 0x06031D8C} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x84E3\n"  /* mov.b @(0x3,r14),r0 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0x760E\n"  /* add #14,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0600A72C] = 0x06062180} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0xD50F\n"  /* mov.l @(0x3C,PC),r5  {[0x0600A730] = 0x06089E9C} */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xA025\n"  /* bra 0x0600A744 */
    ".word 0x0009\n"  /* nop */
    ".word 0xCCCD\n"  /* .word 0xCCCD */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEB8C\n"  /* mov #-116,r11 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4640\n"  /* .word 0x4640 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0F5D\n"  /* mov.w @(r0,r5),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x21D8\n"  /* tst r13,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x212C\n"  /* .word 0x212C */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D8C\n"  /* mov.l r8,@(0x30,r13) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2180\n"  /* mov.b r8,@r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E9C\n"  /* mov.w @(0x138,PC),r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D8\n"  /* tst r13,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A28\n"  /* mov.l r2,@(0x20,r10) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4670\n"  /* .word 0x4670 */
    ".word 0xFFFD\n"  /* .word 0xFFFD */
    ".word 0xB334\n"  /* bsr 0x0600ADAE */
    ".word 0xD207\n"  /* mov.l @(0x1C,PC),r2  {[0x0600A764] = 0x060620D8} */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x0600A768] = 0x06031A28} */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x73D0\n"  /* add #-48,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D8\n"  /* tst r13,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A28\n"  /* mov.l r2,@(0x20,r10) */
    ".size _FUN_0600A614, .-_FUN_0600A614\n"
);
void camera_car_transform_setup(void) { }
void course_specific_renderer(void) { }
void camera_position_lerping(void) { }
void race_state_machine(void) { }
void race_utility_calc(void) { }
/* FUN_0600C286: moved to per_frame_render.c */
/* FUN_0600C7D8: moved to physics_helpers.c (alias of FUN_0600C7D4) */
/* FUN_0600C8D0: moved to physics_helpers.c (alias of FUN_0600C8CC) */
void vehicle_state_physics(void) { }
void finish_line_display(void) { }

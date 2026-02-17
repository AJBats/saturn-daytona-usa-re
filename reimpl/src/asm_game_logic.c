/* FUN_0600A000: moved to sound_init.c */
__asm__(



    ".balign 2\n"
































    ".section .text.FUN_0600A478, \"ax\"\n"

    ".global _FUN_0600A478\n"



















    ".section .text.FUN_0600a478, \"ax\"\n"

    ".global _FUN_0600a478\n"
    ".type _FUN_0600A478, @function\n"
    "_FUN_0600A478:\n"
    "_FUN_0600a478:\n"
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
);
__asm__(



    ".balign 2\n"
































    ".section .text.FUN_0600A614, \"ax\"\n"

    ".global _FUN_0600A614\n"



















    ".section .text.FUN_0600a614, \"ax\"\n"

    ".global _FUN_0600a614\n"
    ".type _FUN_0600A614, @function\n"
    "_FUN_0600A614:\n"
    "_FUN_0600a614:\n"
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
);
__asm__(



    ".balign 2\n"
    ".global _camera_car_transform_setup\n"
    ".type _camera_car_transform_setup, @function\n"






























    ".section .text.FUN_0600ADD4, \"ax\"\n"

    ".global _FUN_0600ADD4\n"



















    ".section .text.FUN_0600add4, \"ax\"\n"

    ".global _FUN_0600add4\n"
    "_camera_car_transform_setup:\n"
    "_FUN_0600ADD4:\n"
    "_FUN_0600add4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDB1B\n"  /* mov.l @(0x6C,PC),r11  {[0x0600AE4C] = 0x06063F46} */
    ".word 0xDD1B\n"  /* mov.l @(0x6C,PC),r13  {[0x0600AE50] = 0x06026E94} */
    ".word 0xDE1C\n"  /* mov.l @(0x70,PC),r14  {[0x0600AE54] = 0x0607E944} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600AE58] = 0x0607E940} */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600AE5C] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x55E5\n"  /* mov.l @(0x14,r14),r5 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0600AE60] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E4\n"  /* mov.l @(0x10,r14),r4 */
    ".word 0x54E8\n"  /* mov.l @(0x20,r14),r4 */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x0600AE64] = 0x00008000} */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0600AE68] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x54E9\n"  /* mov.l @(0x24,r14),r4 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0600AE6C] = 0x06026F2A} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0600AE70] = 0x0607EBC4} */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0600AE74] = 0x00800008} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8931\n"  /* bt 0x0600AE7C */
    ".word 0x54E7\n"  /* mov.l @(0x1C,r14),r4 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x63B1\n"  /* mov.w @r11,r3 */
    ".word 0x623D\n"  /* extu.w r3,r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0600AE78] = 0x0605BDCC} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0xA034\n"  /* bra 0x0600AE94 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7080\n"  /* add #-128,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4670\n"  /* .word 0x4670 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x70F2\n"  /* add #-14,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06027158 */
    ".word 0x7158\n"  /* add #88,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x21D8\n"  /* tst r13,r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2158\n"  /* tst r5,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2180\n"  /* mov.b r8,@r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1DF4\n"  /* mov.l r15,@(0x10,r13) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F46\n"  /* cmp/hi r4,r15 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026E94 */
    ".word 0x6E94\n"  /* mov.b @r9+,r14 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBC4\n"  /* mov #-60,r11 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBDCC\n"  /* bsr 0x0600AA16 */
    ".word 0x54E7\n"  /* mov.l @(0x1C,r14),r4 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0600AF1C] = 0x06078668} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x62B1\n"  /* mov.w @r11,r2 */
    ".word 0x612D\n"  /* extu.w r2,r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x0600AF20] = 0x0605BDCC} */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x903B\n"  /* mov.w @(0x76,PC),r0 */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x70F4\n"  /* add #-12,r0 */
    ".word 0x03EE\n"  /* mov.l @(r0,r14),r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0600AF24] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x0600AF28] = 0x06059F30} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x896D\n"  /* bt 0x0600AF8C */
    ".word 0xD51E\n"  /* mov.l @(0x78,PC),r5  {[0x0600AF2C] = 0x060621E8} */
    ".word 0xD41F\n"  /* mov.l @(0x7C,PC),r4  {[0x0600AF30] = 0x0606213C} */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0600AF34] = 0x06031D8C} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD61E\n"  /* mov.l @(0x78,PC),r6  {[0x0600AF38] = 0x06062190} */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x0600AF3C] = 0x06089E44} */
    ".word 0xD41F\n"  /* mov.l @(0x7C,PC),r4  {[0x0600AF40] = 0x060620E8} */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0600AF44] = 0x06031A28} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x9021\n"  /* mov.w @(0x42,PC),r0 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0600AF48] = 0x06026E2E} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x901D\n"  /* mov.w @(0x3A,PC),r0 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600AF4C] = 0x06026F2A} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x0600AF50] = 0x06082A25} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0xC802\n"  /* tst #0x02,r0 */
    ".word 0x8B02\n"  /* bf 0x0600AEF4 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xBDD2\n"  /* bsr 0x0600AA98 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x8401\n"  /* mov.b @(0x1,r0),r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8D2F\n"  /* bt/s 0x0600AF5C */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0xEC0D\n"  /* mov #13,r12 */
    ".word 0x64B1\n"  /* mov.w @r11,r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0600AF54] = 0x06044740} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x0600AF58] = 0x06083258} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0xA027\n"  /* bra 0x0600AF60 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x01D8\n"  /* .word 0x01D8 */
    ".word 0x01B4\n"  /* mov.b r11,@(r0,r1) */
    ".word 0x01D0\n"  /* .word 0x01D0 */
    ".word 0x01C8\n"  /* .word 0x01C8 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8668\n"  /* .word 0x8668 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBDCC\n"  /* bsr 0x0600AABE */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F30\n"  /* mov.w @(0x60,PC),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x21E8\n"  /* tst r14,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x213C\n"  /* .word 0x213C */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D8C\n"  /* mov.l r8,@(0x30,r13) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2190\n"  /* mov.b r9,@r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E44\n"  /* mov.w @(0x88,PC),r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20E8\n"  /* tst r14,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A28\n"  /* mov.l r2,@(0x20,r10) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A25\n"  /* mov.w r2,@-r10 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4740\n"  /* .word 0x4740 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0xD42B\n"  /* mov.l @(0xAC,PC),r4  {[0x0600B00C] = 0x06083258} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6ECD\n"  /* extu.w r12,r14 */
    ".word 0xD52A\n"  /* mov.l @(0xA8,PC),r5  {[0x0600B010] = 0x060621D8} */
    ".word 0xD42A\n"  /* mov.l @(0xA8,PC),r4  {[0x0600B014] = 0x0606212C} */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x0600B018] = 0x06031D8C} */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x35EC\n"  /* add r14,r5 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD628\n"  /* mov.l @(0xA0,PC),r6  {[0x0600B01C] = 0x06062180} */
    ".word 0xD529\n"  /* mov.l @(0xA4,PC),r5  {[0x0600B020] = 0x06089E44} */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x0600B024] = 0x060620D8} */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x0600B028] = 0x06031A28} */
    ".word 0x36EC\n"  /* add r14,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD227\n"  /* mov.l @(0x9C,PC),r2  {[0x0600B02C] = 0x0607EBC4} */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0600B030] = 0x20020000} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8902\n"  /* bt 0x0600AF9E */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0600B034] = 0x0601BE64} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x0600B038] = 0x06089EDC} */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _camera_car_transform_setup, .-_camera_car_transform_setup\n"
);
__asm__(



    ".balign 2\n"
    ".global _course_specific_renderer\n"
    ".type _course_specific_renderer, @function\n"






























    ".section .text.FUN_0600B1A0, \"ax\"\n"

    ".global _FUN_0600B1A0\n"



















    ".section .text.FUN_0600b1a0, \"ax\"\n"

    ".global _FUN_0600b1a0\n"
    "_course_specific_renderer:\n"
    "_FUN_0600B1A0:\n"
    "_FUN_0600b1a0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xDB16\n"  /* mov.l @(0x58,PC),r11  {[0x0600B208] = 0x0607EB8C} */
    ".word 0x6BB2\n"  /* mov.l @r11,r11 */
    ".word 0xDE16\n"  /* mov.l @(0x58,PC),r14  {[0x0600B20C] = 0x0607E944} */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0600B210] = 0x0607E940} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x0600B214] = 0x0607EAD8} */
    ".word 0xA039\n"  /* bra 0x0600B230 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xDD16\n"  /* mov.l @(0x58,PC),r13  {[0x0600B218] = 0x06063488} */
    ".word 0xDC16\n"  /* mov.l @(0x58,PC),r12  {[0x0600B21C] = 0x06063434} */
    ".word 0xA03B\n"  /* bra 0x0600B23C */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD16\n"  /* mov.l @(0x58,PC),r13  {[0x0600B220] = 0x060634A4} */
    ".word 0xDC16\n"  /* mov.l @(0x58,PC),r12  {[0x0600B224] = 0x06063450} */
    ".word 0xA037\n"  /* bra 0x0600B23C */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD16\n"  /* mov.l @(0x58,PC),r13  {[0x0600B228] = 0x060634C0} */
    ".word 0xDC16\n"  /* mov.l @(0x58,PC),r12  {[0x0600B22C] = 0x0606346C} */
    ".word 0xA033\n"  /* bra 0x0600B23C */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x21D8\n"  /* tst r13,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x212C\n"  /* .word 0x212C */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2158\n"  /* tst r5,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2180\n"  /* mov.b r8,@r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E44\n"  /* mov.w @(0x88,PC),r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D8\n"  /* tst r13,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1DF4\n"  /* mov.l r15,@(0x10,r13) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBC4\n"  /* mov #-60,r11 */
    ".word 0x2002\n"  /* mov.l r0,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601C3E4 */
    ".word 0xC3E4\n"  /* trapa #0xE4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0600BC62 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEB8C\n"  /* mov #-116,r11 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3488\n"  /* sub r8,r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3434\n"  /* .word 0x3434 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34A4\n"  /* .word 0x34A4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3450\n"  /* cmp/eq r5,r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34C0\n"  /* cmp/eq r12,r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x346C\n"  /* add r6,r4 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89C4\n"  /* bt 0x0600B1BE */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89C6\n"  /* bt 0x0600B1C6 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89C8\n"  /* bt 0x0600B1CE */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x0600B304] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x55E5\n"  /* mov.l @(0x14,r14),r5 */
    ".word 0xD330\n"  /* mov.l @(0xC0,PC),r3  {[0x0600B308] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E4\n"  /* mov.l @(0x10,r14),r4 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x0600B30C] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E8\n"  /* mov.l @(0x20,r14),r4 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x0600B310] = 0x06026F2A} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E9\n"  /* mov.l @(0x24,r14),r4 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x0600B314] = 0x06026E94} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E7\n"  /* mov.l @(0x1C,r14),r4 */
    ".word 0x904D\n"  /* mov.w @(0x9A,PC),r0 */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x0600B30C] = 0x06026EDE} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x70F4\n"  /* add #-12,r0 */
    ".word 0x02EE\n"  /* mov.l @(r0,r14),r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xD02A\n"  /* mov.l @(0xA8,PC),r0  {[0x0600B318] = 0x06059F30} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8938\n"  /* bt 0x0600B2E6 */
    ".word 0xD529\n"  /* mov.l @(0xA4,PC),r5  {[0x0600B31C] = 0x06063510} */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x0600B320] = 0x06031D8C} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54D6\n"  /* mov.l @(0x18,r13),r4 */
    ".word 0xD629\n"  /* mov.l @(0xA4,PC),r6  {[0x0600B324] = 0x060634F4} */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x0600B328] = 0x06089E98} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0600B32C] = 0x06031A28} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54C6\n"  /* mov.l @(0x18,r12),r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x9034\n"  /* mov.w @(0x68,PC),r0 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600B308] = 0x06026E2E} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x9030\n"  /* mov.w @(0x60,PC),r0 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600B310] = 0x06026F2A} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x902D\n"  /* mov.w @(0x5A,PC),r0 */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x0600B330] = 0x06083258} */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0600B314] = 0x06026E94} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x55B3\n"  /* mov.l @(0xC,r11),r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0600B334] = 0x060634F8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0600B320] = 0x06031D8C} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x56B3\n"  /* mov.l @(0xC,r11),r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0600B338] = 0x060634DC} */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x0600B32C] = 0x06031A28} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x34CC\n"  /* add r12,r4 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xB997\n"  /* bsr 0x0600A614 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x0600B33C] = 0x06089EDC} */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x01D8\n"  /* .word 0x01D8 */
    ".word 0x01B4\n"  /* mov.b r11,@(r0,r1) */
    ".word 0x01D0\n"  /* .word 0x01D0 */
    ".word 0x01C8\n"  /* .word 0x01C8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026E94 */
    ".word 0x6E94\n"  /* mov.b @r9+,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F30\n"  /* mov.w @(0x60,PC),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3510\n"  /* cmp/eq r1,r5 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D8C\n"  /* mov.l r8,@(0x30,r13) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34F4\n"  /* .word 0x34F4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E98\n"  /* mov.w @(0x130,PC),r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A28\n"  /* mov.l r2,@(0x20,r10) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34F8\n"  /* sub r15,r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".size _course_specific_renderer, .-_course_specific_renderer\n"
);
__asm__(
    ".balign 4\n"
    ".global _camera_position_lerping\n"
    ".type _camera_position_lerping, @function\n"






























    ".section .text.FUN_0600B4D2, \"ax\"\n"

    ".global _FUN_0600B4D2\n"



















    ".section .text.FUN_0600b4d2, \"ax\"\n"

    ".global _FUN_0600b4d2\n"
    "_camera_position_lerping:\n"
    "_FUN_0600B4D2:\n"
    "_FUN_0600b4d2:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xDA0A\n"  /* mov.l @(0x28,PC),r10  {[0x0600B50C] = 0x0607EB8C} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xDE0A\n"  /* mov.l @(0x28,PC),r14  {[0x0600B510] = 0x0607E944} */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0600B514] = 0x0607E940} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x0600B518] = 0x0607EAD8} */
    ".word 0xA020\n"  /* bra 0x0600B534 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xDC09\n"  /* mov.l @(0x24,PC),r12  {[0x0600B51C] = 0x06063488} */
    ".word 0xDB0A\n"  /* mov.l @(0x28,PC),r11  {[0x0600B520] = 0x06063434} */
    ".word 0xA022\n"  /* bra 0x0600B540 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDC09\n"  /* mov.l @(0x24,PC),r12  {[0x0600B524] = 0x060634A4} */
    ".word 0xDB0A\n"  /* mov.l @(0x28,PC),r11  {[0x0600B528] = 0x06063450} */
    ".word 0xA01E\n"  /* bra 0x0600B540 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDC09\n"  /* mov.l @(0x24,PC),r12  {[0x0600B52C] = 0x060634C0} */
    ".word 0xDB0A\n"  /* mov.l @(0x28,PC),r11  {[0x0600B530] = 0x0606346C} */
    ".word 0xA01A\n"  /* bra 0x0600B540 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEB8C\n"  /* mov #-116,r11 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3488\n"  /* sub r8,r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3434\n"  /* .word 0x3434 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34A4\n"  /* .word 0x34A4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3450\n"  /* cmp/eq r5,r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34C0\n"  /* cmp/eq r12,r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x346C\n"  /* add r6,r4 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89DD\n"  /* bt 0x0600B4F4 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89DF\n"  /* bt 0x0600B4FC */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89E1\n"  /* bt 0x0600B504 */
    ".word 0xD93E\n"  /* mov.l @(0xF8,PC),r9  {[0x0600B63C] = 0x00008000} */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0xDD3E\n"  /* mov.l @(0xF8,PC),r13  {[0x0600B640] = 0x06078670} */
    ".word 0x52E4\n"  /* mov.l @(0x10,r14),r2 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x329C\n"  /* add r9,r2 */
    ".word 0x3127\n"  /* cmp/gt r2,r1 */
    ".word 0x321E\n"  /* .word 0x321E */
    ".word 0x4221\n"  /* shar r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x52E5\n"  /* mov.l @(0x14,r14),r2 */
    ".word 0x53D1\n"  /* mov.l @(0x4,r13),r3 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x3127\n"  /* cmp/gt r2,r1 */
    ".word 0x321E\n"  /* .word 0x321E */
    ".word 0x4221\n"  /* shar r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1D31\n"  /* mov.l r3,@(0x4,r13) */
    ".word 0x52E6\n"  /* mov.l @(0x18,r14),r2 */
    ".word 0x53D2\n"  /* mov.l @(0x8,r13),r3 */
    ".word 0x9160\n"  /* mov.w @(0xC0,PC),r1 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x323E\n"  /* .word 0x323E */
    ".word 0x4221\n"  /* shar r2 */
    ".word 0x51D2\n"  /* mov.l @(0x8,r13),r1 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x0600B644] = 0x06027080} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x1D12\n"  /* mov.l r1,@(0x8,r13) */
    ".word 0x56D2\n"  /* mov.l @(0x8,r13),r6 */
    ".word 0x55D1\n"  /* mov.l @(0x4,r13),r5 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x0600B648] = 0x060270F2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D2\n"  /* mov.l @r13,r4 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x0600B64C] = 0x060271A2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E8\n"  /* mov.l @(0x20,r14),r4 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x0600B650] = 0x060271EE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E9\n"  /* mov.l @(0x24,r14),r4 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x0600B654] = 0x06027158} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E7\n"  /* mov.l @(0x1C,r14),r4 */
    ".word 0x9047\n"  /* mov.w @(0x8E,PC),r0 */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x0600B64C] = 0x060271A2} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x70F4\n"  /* add #-12,r0 */
    ".word 0x02EE\n"  /* mov.l @(r0,r14),r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xD02A\n"  /* mov.l @(0xA8,PC),r0  {[0x0600B658] = 0x06059F30} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8967\n"  /* bt 0x0600B686 */
    ".word 0x6693\n"  /* mov r9,r6 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0600B65C] = 0x06027124} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xD527\n"  /* mov.l @(0x9C,PC),r5  {[0x0600B660] = 0x06063510} */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0600B664] = 0x06032158} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54C6\n"  /* mov.l @(0x18,r12),r4 */
    ".word 0xD627\n"  /* mov.l @(0x9C,PC),r6  {[0x0600B668] = 0x060634F4} */
    ".word 0xD227\n"  /* mov.l @(0x9C,PC),r2  {[0x0600B66C] = 0x06089E98} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0600B670] = 0x06031DF4} */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54B6\n"  /* mov.l @(0x18,r11),r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x9028\n"  /* mov.w @(0x50,PC),r0 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0600B648] = 0x060270F2} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x9024\n"  /* mov.w @(0x48,PC),r0 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0600B650] = 0x060271EE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x9021\n"  /* mov.w @(0x42,PC),r0 */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x0600B674] = 0x06083258} */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0600B654] = 0x06027158} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x55A3\n"  /* mov.l @(0xC,r10),r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600B678] = 0x060634F8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x0600B664] = 0x06032158} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x34CC\n"  /* add r12,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x56A3\n"  /* mov.l @(0xC,r10),r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0600B67C] = 0x060634DC} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x34BC\n"  /* add r11,r4 */
    ".word 0xA028\n"  /* bra 0x0600B680 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x01D8\n"  /* .word 0x01D8 */
    ".word 0x01B4\n"  /* mov.b r11,@(r0,r1) */
    ".word 0x01D0\n"  /* .word 0x01D0 */
    ".word 0x01C8\n"  /* .word 0x01C8 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8670\n"  /* .word 0x8670 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7080\n"  /* add #-128,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x70F2\n"  /* add #-14,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_060271A2 */
    ".word 0x71A2\n"  /* add #-94,r1 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_060271EE */
    ".word 0x71EE\n"  /* add #-18,r1 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06027158 */
    ".word 0x7158\n"  /* add #88,r1 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F30\n"  /* mov.w @(0x60,PC),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7124\n"  /* add #36,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3510\n"  /* cmp/eq r1,r5 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2158\n"  /* tst r5,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34F4\n"  /* .word 0x34F4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E98\n"  /* mov.w @(0x130,PC),r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1DF4\n"  /* mov.l r15,@(0x10,r13) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34F8\n"  /* sub r15,r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x0600B6C8] = 0x06031DF4} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x0600B6CC] = 0x0608A52C} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x73D0\n"  /* add #-48,r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _camera_position_lerping, .-_camera_position_lerping\n"
);
__asm__(



    ".balign 2\n"
    ".global _race_state_machine\n"
    ".type _race_state_machine, @function\n"






























    ".section .text.FUN_0600C010, \"ax\"\n"

    ".global _FUN_0600C010\n"



















    ".section .text.FUN_0600c010, \"ax\"\n"

    ".global _FUN_0600c010\n"
    "_race_state_machine:\n"
    "_FUN_0600C010:\n"
    "_FUN_0600c010:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD820\n"  /* mov.l @(0x80,PC),r8  {[0x0600C094] = 0x0607EBC4} */
    ".word 0x9A3C\n"  /* mov.w @(0x78,PC),r10 */
    ".word 0xDC20\n"  /* mov.l @(0x80,PC),r12  {[0x0600C098] = 0x0608A52C} */
    ".word 0xDD20\n"  /* mov.l @(0x80,PC),r13  {[0x0600C09C] = 0x0605A1DD} */
    ".word 0xD021\n"  /* mov.l @(0x84,PC),r0  {[0x0600C0A0] = 0x06083255} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D04\n"  /* bt/s 0x0600C02C */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0xD41F\n"  /* mov.l @(0x7C,PC),r4  {[0x0600C0A4] = 0x0607EB8C} */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0600C0A8] = 0x06034708} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6282\n"  /* mov.l @r8,r2 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0600C0AC] = 0x02000000} */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B0C\n"  /* bf 0x0600C050 */
    ".word 0xD01E\n"  /* mov.l @(0x78,PC),r0  {[0x0600C0B0] = 0x06078635} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8904\n"  /* bt 0x0600C04A */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600C0B4] = 0x0600D336} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA003\n"  /* bra 0x0600C050 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0600C0B8] = 0x0600D31C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6282\n"  /* mov.l @r8,r2 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0600C0BC] = 0x00020000} */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B06\n"  /* bf 0x0600C066 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x0600C0C0] = 0x0607EAE0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B02\n"  /* bf 0x0600C066 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0600C0C4] = 0x0602E610} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE630\n"  /* mov #48,r6 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x7230\n"  /* add #48,r2 */
    ".word 0x2C22\n"  /* mov.l r2,@r12 */
    ".word 0xD516\n"  /* mov.l @(0x58,PC),r5  {[0x0600C0C8] = 0x06089EDC} */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0600C0CC] = 0x06027630} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x0600C0D0] = 0x06078664} */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x0600C0D4] = 0x06059F30} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B2C\n"  /* bf 0x0600C0DC */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0600C0D8] = 0x0607EA98} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x2431\n"  /* mov.w r3,@r4 */
    ".word 0xA029\n"  /* bra 0x0600C0E2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFE11\n"  /* .word 0xFE11 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBC4\n"  /* mov #-60,r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0600CAF6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1DD\n"  /* bra 0x0600C45C */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3255\n"  /* dmulu.l r5,r2 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEB8C\n"  /* mov #-116,r11 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06034708 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8635\n"  /* .word 0x8635 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0xD336\n"  /* mov.l @(0xD8,PC),r3  {[0x0600C190] = 0x0000FFFF} */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600D31C */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600C12C] = 0x29988909} */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE610\n"  /* mov #16,r6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7630\n"  /* add #48,r6 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8664\n"  /* .word 0x8664 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F30\n"  /* mov.w @(0x60,PC),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEA98\n"  /* mov #-104,r10 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2421\n"  /* mov.w r2,@r4 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0600C188] = 0x0600C170} */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x0600C18C] = 0x06063574} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0600C190] = 0x0000FFFF} */
    ".word 0xD22A\n"  /* mov.l @(0xA8,PC),r2  {[0x0600C194] = 0x21000000} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x0600C198] = 0x02800008} */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B02\n"  /* bf 0x0600C0FE */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0600C19C] = 0x060058FA} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0600C1A0] = 0x06006868} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xBACC\n"  /* bsr 0x0600B6A0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6282\n"  /* mov.l @r8,r2 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0600C1A4] = 0x02000000} */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8905\n"  /* bt 0x0600C11C */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0600C1A8] = 0x0601BDEC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA001\n"  /* bra 0x0600C11C */
    ".word 0x0009\n"  /* nop */
    ".word 0x69B3\n"  /* mov r11,r9 */
    ".word 0x62A0\n"  /* mov.b @r10,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x32E0\n"  /* cmp/eq r14,r2 */
    ".word 0x8BF9\n"  /* bf 0x0600C11A */
    ".word 0x60A0\n"  /* mov.b @r10,r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x2A00\n"  /* mov.b r0,@r10 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x8909\n"  /* bt 0x0600C144 */
    ".word 0x63D0\n"  /* mov.b @r13,r3 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x0600C1AC] = 0x0607EA98} */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x890A\n"  /* bt 0x0600C152 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0xA007\n"  /* bra 0x0600C152 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x32B7\n"  /* cmp/gt r11,r2 */
    ".word 0x8B02\n"  /* bf 0x0600C152 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0600C1B0] = 0x0603C000} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x2C22\n"  /* mov.l r2,@r12 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _race_state_machine, .-_race_state_machine\n"
);
__asm__(



    ".balign 2\n"
    ".global _race_utility_calc\n"
    ".type _race_utility_calc, @function\n"






























    ".section .text.FUN_0600C170, \"ax\"\n"

    ".global _FUN_0600C170\n"



















    ".section .text.FUN_0600c170, \"ax\"\n"

    ".global _FUN_0600c170\n"
    "_race_utility_calc:\n"
    "_FUN_0600C170:\n"
    "_FUN_0600c170:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0600C1B0] = 0x0603C000} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0600C1B4] = 0x06083255} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891B\n"  /* bt 0x0600C1B8 */
    ".word 0xB8DE\n"  /* bsr 0x0600B340 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA01B\n"  /* bra 0x0600C1BE */
    ".word 0x0009\n"  /* nop */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600C170 */
    ".word 0xC170\n"  /* mov.w r0,@(0xE0,GBR) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3574\n"  /* .word 0x3574 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0280\n"  /* .word 0x0280 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060058FA */
    ".word 0x58FA\n"  /* mov.l @(0x28,r15),r8 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06006868 */
    ".word 0x6868\n"  /* swap.b r6,r8 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601BDEC */
    ".word 0xBDEC\n"  /* bsr 0x0600BD86 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEA98\n"  /* mov #-104,r10 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3255\n"  /* dmulu.l r5,r2 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0600C1F4] = 0x0600AFB2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xBBA9\n"  /* bsr 0x0600B914 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0600C1F8] = 0x06063E1C} */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0600C1FC] = 0x06063E20} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x8808\n"  /* cmp/eq #8,r0 */
    ".word 0x8B04\n"  /* bf 0x0600C1DA */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0600C200] = 0x06006A9C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA003\n"  /* bra 0x0600C1E0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0600C204] = 0x06006CDC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0600C208] = 0x06059F40} */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0600C20C] = 0x06059F4C} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0600C210] = 0x0000FFFF} */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0600C214] = 0x21800000} */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600AFB2 */
    ".word 0xAFB2\n"  /* bra 0x0600C15E */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E1C\n"  /* add r1,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E20\n"  /* cmp/eq r2,r14 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06006A9C */
    ".word 0x6A9C\n"  /* extu.b r9,r10 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06006CDC */
    ".word 0x6CDC\n"  /* extu.b r13,r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F40\n"  /* mov.w @(0x80,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F4C\n"  /* mov.w @(0x98,PC),r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x2180\n"  /* mov.b r8,@r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".size _race_utility_calc, .-_race_utility_calc\n"
);
/* FUN_0600C286: moved to per_frame_render.c */
/* FUN_0600C7D8: moved to physics_helpers.c (alias of FUN_0600C7D4) */
/* FUN_0600C8D0: moved to physics_helpers.c (alias of FUN_0600C8CC) */
__asm__(



    ".balign 2\n"
    ".global _vehicle_state_physics\n"
    ".type _vehicle_state_physics, @function\n"






























    ".section .text.FUN_0600D41C, \"ax\"\n"

    ".global _FUN_0600D41C\n"



















    ".section .text.FUN_0600d41c, \"ax\"\n"

    ".global _FUN_0600d41c\n"
    "_vehicle_state_physics:\n"
    "_FUN_0600D41C:\n"
    "_FUN_0600d41c:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xDC21\n"  /* mov.l @(0x84,PC),r12  {[0x0600D4A8] = 0x060786B4} */
    ".word 0xDD21\n"  /* mov.l @(0x84,PC),r13  {[0x0600D4AC] = 0x0607E9EC} */
    ".word 0xEE01\n"  /* mov #1,r14 */
    ".word 0xA001\n"  /* bra 0x0600D42E */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x03DE\n"  /* mov.l @(r0,r13),r3 */
    ".word 0x9036\n"  /* mov.w @(0x6C,PC),r0 */
    ".word 0x033E\n"  /* mov.l @(r0,r3),r3 */
    ".word 0x3236\n"  /* cmp/hi r3,r2 */
    ".word 0x8B02\n"  /* bf 0x0600D444 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x3422\n"  /* cmp/hs r2,r4 */
    ".word 0x8BF3\n"  /* bf 0x0600D42C */
    ".word 0xD71A\n"  /* mov.l @(0x68,PC),r7  {[0x0600D4B0] = 0x0607EA8C} */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x3526\n"  /* cmp/hi r2,r5 */
    ".word 0x8F07\n"  /* bf/s 0x0600D45E */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x6166\n"  /* mov.l @r6+,r1 */
    ".word 0x75FF\n"  /* add #-1,r5 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2712\n"  /* mov.l r1,@r7 */
    ".word 0x3536\n"  /* cmp/hi r3,r5 */
    ".word 0x8DF9\n"  /* bt/s 0x0600D450 */
    ".word 0x7704\n"  /* add #4,r7 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x0600D4B4] = 0x0607EA98} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x3548\n"  /* sub r4,r5 */
    ".word 0x35E6\n"  /* cmp/hi r14,r5 */
    ".word 0x8F07\n"  /* bf/s 0x0600D478 */
    ".word 0x67D3\n"  /* mov r13,r7 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x6166\n"  /* mov.l @r6+,r1 */
    ".word 0x75FF\n"  /* add #-1,r5 */
    ".word 0x7704\n"  /* add #4,r7 */
    ".word 0x35E6\n"  /* cmp/hi r14,r5 */
    ".word 0x8DF9\n"  /* bt/s 0x0600D46A */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x0600D4B0] = 0x0607EA8C} */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x3426\n"  /* cmp/hi r2,r4 */
    ".word 0x8B06\n"  /* bf 0x0600D48E */
    ".word 0x6156\n"  /* mov.l @r5+,r1 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2712\n"  /* mov.l r1,@r7 */
    ".word 0x3436\n"  /* cmp/hi r3,r4 */
    ".word 0x8DF9\n"  /* bt/s 0x0600D480 */
    ".word 0x7704\n"  /* add #4,r7 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA000\n"  /* bra 0x0600D496 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD706\n"  /* mov.l @(0x18,PC),r7  {[0x0600D4B4] = 0x0607EA98} */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x0600D4AC] = 0x0607E9EC} */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0xA015\n"  /* bra 0x0600D4D0 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86B4\n"  /* .word 0x86B4 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE9EC\n"  /* mov #-20,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEA8C\n"  /* mov #-116,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEA98\n"  /* mov #-104,r10 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x73FC\n"  /* add #-4,r3 */
    ".word 0x6132\n"  /* mov.l @r3,r1 */
    ".word 0x9038\n"  /* mov.w @(0x70,PC),r0 */
    ".word 0x0216\n"  /* mov.l r1,@(r0,r2) */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x0326\n"  /* mov.l r2,@(r0,r3) */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x6372\n"  /* mov.l @r7,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x3632\n"  /* cmp/hs r3,r6 */
    ".word 0x8BEF\n"  /* bf 0x0600D4B8 */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x902A\n"  /* mov.w @(0x54,PC),r0 */
    ".word 0x0326\n"  /* mov.l r2,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9027\n"  /* mov.w @(0x4E,PC),r0 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x0316\n"  /* mov.l r1,@(r0,r3) */
    ".word 0x72FC\n"  /* add #-4,r2 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x70FC\n"  /* add #-4,r0 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x0316\n"  /* mov.l r1,@(r0,r3) */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0x0326\n"  /* mov.l r2,@(r0,r3) */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x70B0\n"  /* add #-80,r0 */
    ".word 0xD10D\n"  /* mov.l @(0x34,PC),r1  {[0x0600D538] = 0x060786B4} */
    ".word 0x023E\n"  /* mov.l @(r0,r3),r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".size _vehicle_state_physics, .-_vehicle_state_physics\n"
);
void finish_line_display(void) { }

__asm__(
    ".balign 4\n"
    ".global _FUN_060140C8\n"
    ".type _FUN_060140C8, @function\n"
    "_FUN_060140C8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x06014138] = 0x06084B18} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x3326\n"  /* cmp/hi r2,r3 */
    ".word 0x892C\n"  /* bt 0x0601412E */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601413C] = 0x0605AD4C} */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x06014140] = 0x06026DBC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F12\n"  /* mov.l r1,@r15 */
    ".word 0xDE17\n"  /* mov.l @(0x5C,PC),r14  {[0x06014144] = 0x00010000} */
    ".word 0x9526\n"  /* mov.w @(0x4C,PC),r5 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06014148] = 0x06026E2E} */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0601414C] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xBE8A\n"  /* bsr 0x06013E12 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE504\n"  /* mov #4,r5 */
    ".word 0xD413\n"  /* mov.l @(0x4C,PC),r4  {[0x06014150] = 0x06084B08} */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06014154] = 0x06062338} */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x06014158] = 0x06031D8C} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x0601415C] = 0x06089E4A} */
    ".word 0xD40E\n"  /* mov.l @(0x38,PC),r4  {[0x06014150] = 0x06084B08} */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06014160] = 0x060622C0} */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x06014164] = 0x06031A28} */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x06014168] = 0x06089EDC} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x73D0\n"  /* add #-48,r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xCCCD\n"  /* .word 0xCCCD */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B18\n"  /* shll8 r11 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD4C\n"  /* bra 0x06013BDA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B08\n"  /* shll2 r11 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D8C\n"  /* mov.l r8,@(0x30,r13) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E4A\n"  /* mov.w @(0x94,PC),r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x22C0\n"  /* mov.b r12,@r2 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A28\n"  /* mov.l r2,@(0x20,r10) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".size _FUN_060140C8, .-_FUN_060140C8\n"
);
/* FUN_06014468: moved to sound_channel.c */
__asm__(
    ".balign 4\n"
    ".global _FUN_060146D4\n"
    ".type _FUN_060146D4, @function\n"
    "_FUN_060146D4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x060146F8] = 0x0607EBCC} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x060146FC] = 0x06084FB4} */
    ".word 0xB046\n"  /* bsr 0x0601476C */
    ".word 0x0009\n"  /* nop */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890E\n"  /* bt 0x06014704 */
    ".word 0xE306\n"  /* mov #6,r3 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x06014700] = 0x06084AF2} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xA00D\n"  /* bra 0x0601470A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B18\n"  /* shll8 r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF0\n"  /* .word 0x4AF0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBCC\n"  /* mov #-52,r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FB4\n"  /* .word 0x4FB4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF2\n"  /* .word 0x4AF2 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06014758] = 0x06084AF2} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0601475C] = 0x06084B10} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8B1F\n"  /* bf 0x06014752 */
    ".word 0xD413\n"  /* mov.l @(0x4C,PC),r4  {[0x06014760] = 0x06085FFC} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x890B\n"  /* bt 0x06014732 */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x06014764] = 0x06084B14} */
    ".word 0x6154\n"  /* mov.b @r5+,r1 */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6154\n"  /* mov.b @r5+,r1 */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6154\n"  /* mov.b @r5+,r1 */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6350\n"  /* mov.b @r5,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x06014768] = 0x06086000} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x890B\n"  /* bt 0x06014752 */
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x06014764] = 0x06084B14} */
    ".word 0x6154\n"  /* mov.b @r5+,r1 */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6154\n"  /* mov.b @r5+,r1 */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6154\n"  /* mov.b @r5+,r1 */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6350\n"  /* mov.b @r5,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF2\n"  /* .word 0x4AF2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B10\n"  /* dt r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FFC\n"  /* mov.l @(0x30,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B14\n"  /* .word 0x4B14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".size _FUN_060146D4, .-_FUN_060146D4\n"
);
/* FUN_06014964: moved to render_setup.c */
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601503A\n"
    ".type _FUN_0601503A, @function\n"
    "_FUN_0601503A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06015074] = 0x06085FF4} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xD10A\n"  /* mov.l @(0x28,PC),r1  {[0x06015078] = 0x0607EBF4} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0601507C] = 0x06078635} */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x06015080] = 0x0607EAE0} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x203B\n"  /* or r3,r0 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890C\n"  /* bt 0x06015084 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA162\n"  /* bra 0x06015338 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8635\n"  /* .word 0x8635 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0xD223\n"  /* mov.l @(0x8C,PC),r2  {[0x06015114] = 0x0607ED88} */
    ".word 0x933F\n"  /* mov.w @(0x7E,PC),r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x3232\n"  /* cmp/hs r3,r2 */
    ".word 0x8D30\n"  /* bt/s 0x060150F0 */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x06015118] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601511C] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06015120] = 0x060032D4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x9531\n"  /* mov.w @(0x62,PC),r5 */
    ".word 0xDE1F\n"  /* mov.l @(0x7C,PC),r14  {[0x06015124] = 0x060284AE} */
    ".word 0xD71F\n"  /* mov.l @(0x7C,PC),r7  {[0x06015128] = 0x06044C78} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x952C\n"  /* mov.w @(0x58,PC),r5 */
    ".word 0xD71E\n"  /* mov.l @(0x78,PC),r7  {[0x0601512C] = 0x06044C80} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD71D\n"  /* mov.l @(0x74,PC),r7  {[0x06015130] = 0x06044C84} */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x9527\n"  /* mov.w @(0x4E,PC),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x06015134] = 0x06044C88} */
    ".word 0x9624\n"  /* mov.w @(0x48,PC),r6 */
    ".word 0x9524\n"  /* mov.w @(0x48,PC),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x06015138] = 0x060172E4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601513C] = 0x06085F8C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xE10E\n"  /* mov #14,r1 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06015140] = 0x06085F8D} */
    ".word 0x2310\n"  /* mov.b r1,@r3 */
    ".word 0xE10A\n"  /* mov #10,r1 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06015144] = 0x06085F8E} */
    ".word 0x2310\n"  /* mov.b r1,@r3 */
    ".word 0x6DDE\n"  /* exts.b r13,r13 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06015148] = 0x06085F8B} */
    ".word 0x23D0\n"  /* mov.b r13,@r3 */
    ".word 0xA007\n"  /* bra 0x060150FE */
    ".word 0x0009\n"  /* nop */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0601514C] = 0x0607ED8C} */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA11D\n"  /* bra 0x06015338 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x2A94\n"  /* mov.b r9,@-r10 */
    ".word 0x0320\n"  /* .word 0x0320 */
    ".word 0x051E\n"  /* mov.l @(r0,r1),r5 */
    ".word 0x0532\n"  /* .word 0x0532 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x051C\n"  /* mov.b @(r0,r1),r5 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED88\n"  /* mov #-120,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060032D4 */
    ".word 0x32D4\n"  /* .word 0x32D4 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4C78\n"  /* .word 0x4C78 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4C80\n"  /* .word 0x4C80 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4C84\n"  /* .word 0x4C84 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4C88\n"  /* .word 0x4C88 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8C\n"  /* mov.l @(0x30,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8D\n"  /* mov.l @(0x34,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8E\n"  /* mov.l @(0x38,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8B\n"  /* mov.l @(0x2C,r8),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED8C\n"  /* mov #-116,r13 */
    ".size _FUN_0601503A, .-_FUN_0601503A\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015150\n"
    ".type _FUN_06015150, @function\n"
    "_FUN_06015150:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0xEA01\n"  /* mov #1,r10 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD929\n"  /* mov.l @(0xA4,PC),r9  {[0x06015208] = 0x06085F8E} */
    ".word 0xDC2A\n"  /* mov.l @(0xA8,PC),r12  {[0x0601520C] = 0x06063D98} */
    ".word 0xDE2A\n"  /* mov.l @(0xA8,PC),r14  {[0x06015210] = 0x06085F8B} */
    ".word 0xDB2B\n"  /* mov.l @(0xAC,PC),r11  {[0x06015214] = 0x06085F8D} */
    ".word 0xD22B\n"  /* mov.l @(0xAC,PC),r2  {[0x06015218] = 0x00008000} */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8D16\n"  /* bt/s 0x060151A4 */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0xD728\n"  /* mov.l @(0xA0,PC),r7  {[0x0601521C] = 0x06044C8C} */
    ".word 0x9642\n"  /* mov.w @(0x84,PC),r6 */
    ".word 0x6590\n"  /* mov.b @r9,r5 */
    ".word 0x63B0\n"  /* mov.b @r11,r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x06015220] = 0x060284AE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x2EA0\n"  /* mov.b r10,@r14 */
    ".word 0xE318\n"  /* mov #24,r3 */
    ".word 0x2B30\n"  /* mov.b r3,@r11 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x06015224] = 0x06085F8C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xA01C\n"  /* bra 0x060151DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x932D\n"  /* mov.w @(0x5A,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8914\n"  /* bt 0x060151DC */
    ".word 0xD71A\n"  /* mov.l @(0x68,PC),r7  {[0x0601521C] = 0x06044C8C} */
    ".word 0x9625\n"  /* mov.w @(0x4A,PC),r6 */
    ".word 0x6590\n"  /* mov.b @r9,r5 */
    ".word 0x63B0\n"  /* mov.b @r11,r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06015220] = 0x060284AE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xE20E\n"  /* mov #14,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0x63DE\n"  /* exts.b r13,r3 */
    ".word 0x2E30\n"  /* mov.b r3,@r14 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06015224] = 0x06085F8C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x9312\n"  /* mov.w @(0x24,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8941\n"  /* bt 0x0601526E */
    ".word 0x6090\n"  /* mov.b @r9,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x880C\n"  /* cmp/eq #12,r0 */
    ".word 0x8B02\n"  /* bf 0x060151F8 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0x60E0\n"  /* mov.b @r14,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B14\n"  /* bf 0x06015228 */
    ".word 0xA03D\n"  /* bra 0x0601527C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8E\n"  /* mov.l @(0x38,r8),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8B\n"  /* mov.l @(0x2C,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8D\n"  /* mov.l @(0x34,r8),r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4C8C\n"  /* .word 0x4C8C */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8C\n"  /* mov.l @(0x30,r8),r15 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B0F\n"  /* bf 0x0601524E */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x060152D4] = 0x0607ED8C} */
    ".word 0xE008\n"  /* mov #8,r0 */
    ".word 0x22A1\n"  /* mov.w r10,@r2 */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x060152D8] = 0x0605AD08} */
    ".word 0x22A2\n"  /* mov.l r10,@r2 */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x060152DC] = 0x06085F92} */
    ".word 0x22A1\n"  /* mov.w r10,@r2 */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x060152E0] = 0x0607ED88} */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0xB07A\n"  /* bsr 0x06015338 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE30E\n"  /* mov #14,r3 */
    ".word 0xD227\n"  /* mov.l @(0x9C,PC),r2  {[0x060152E4] = 0x0605AD10} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA00E\n"  /* bra 0x0601526A */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E0\n"  /* mov.b @r14,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B04\n"  /* bf 0x0601525E */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x060152E8] = 0x0601F5E0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA006\n"  /* bra 0x0601526A */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E0\n"  /* mov.b @r14,r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8B02\n"  /* bf 0x0601526A */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x060152EC] = 0x0601F784} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA010\n"  /* bra 0x0601528E */
    ".word 0x0009\n"  /* nop */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x932D\n"  /* mov.w @(0x5A,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8908\n"  /* bt 0x0601528E */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x060152D4] = 0x0607ED8C} */
    ".word 0xE108\n"  /* mov #8,r1 */
    ".word 0x22D1\n"  /* mov.w r13,@r2 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x060152DC] = 0x06085F92} */
    ".word 0x22D1\n"  /* mov.w r13,@r2 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x060152E0] = 0x0607ED88} */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0xB055\n"  /* bsr 0x06015338 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA000\n"  /* bra 0x0601529E */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x060152F0] = 0x06085F8C} */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x7340\n"  /* add #64,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B2A\n"  /* bf 0x06015304 */
    ".word 0xD711\n"  /* mov.l @(0x44,PC),r7  {[0x060152F4] = 0x06044C8C} */
    ".word 0x960E\n"  /* mov.w @(0x1C,PC),r6 */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x060152F8] = 0x06085F8E} */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x060152FC] = 0x06085F8D} */
    ".word 0x6550\n"  /* mov.b @r5,r5 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06015300] = 0x060284AE} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED8C\n"  /* mov #-116,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD08\n"  /* bra 0x06014CEE */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F92\n"  /* mov.l @(0x8,r9),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED88\n"  /* mov #-120,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x06014D0A */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601F5E0 */
    ".word 0xF5E0\n"  /* .word 0xF5E0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601F784 */
    ".word 0xF784\n"  /* .word 0xF784 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8C\n"  /* mov.l @(0x30,r8),r15 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4C8C\n"  /* .word 0x4C8C */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8E\n"  /* mov.l @(0x38,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8D\n"  /* mov.l @(0x34,r8),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0xD708\n"  /* mov.l @(0x20,PC),r7  {[0x06015328] = 0x06044C88} */
    ".word 0x960D\n"  /* mov.w @(0x1A,PC),r6 */
    ".word 0xD508\n"  /* mov.l @(0x20,PC),r5  {[0x0601532C] = 0x06085F8E} */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06015330] = 0x06085F8D} */
    ".word 0x6550\n"  /* mov.b @r5,r5 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x06015334] = 0x060284AE} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4C88\n"  /* .word 0x4C88 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8E\n"  /* mov.l @(0x38,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8D\n"  /* mov.l @(0x34,r8),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".size _FUN_06015150, .-_FUN_06015150\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06015482\n"
    ".type _FUN_06015482, @function\n"
    "_FUN_06015482:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x060154EC] = 0x06085F8A} */
    ".word 0x634E\n"  /* exts.b r4,r3 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x060154F0] = 0x06085F92} */
    ".word 0x2241\n"  /* mov.w r4,@r2 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x060154F4] = 0x0607EBF4} */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0xCB01\n"  /* or #0x01,r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x060154F8] = 0x0607EAE0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B06\n"  /* bf 0x060154B4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x060154FC] = 0x0607E944} */
    ".word 0x901C\n"  /* mov.w @(0x38,PC),r0 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x023E\n"  /* mov.l @(r0,r3),r2 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B06\n"  /* bf 0x060154C2 */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x06015500] = 0x06063DA0} */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x9215\n"  /* mov.w @(0x2A,PC),r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8904\n"  /* bt 0x060154CC */
    ".word 0xE316\n"  /* mov #22,r3 */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x06015504] = 0x0605AD10} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA003\n"  /* bra 0x060154D2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE318\n"  /* mov #24,r3 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x06015504] = 0x0605AD10} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06015508] = 0x0601E0DE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xD302\n"  /* mov.l @(0x8,PC),r3  {[0x060154E8] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0224\n"  /* mov.b r2,@(r0,r2) */
    ".word 0x0400\n"  /* .word 0x0400 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8A\n"  /* mov.l @(0x28,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F92\n"  /* mov.l @(0x8,r9),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3DA0\n"  /* cmp/eq r10,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x06014F2A */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0xE0DE\n"  /* mov #-34,r0 */
    ".size _FUN_06015482, .-_FUN_06015482\n"
);
/* FUN_0601550C: moved to subsystem_setup.c */
__asm__(
    ".balign 4\n"
    ".global _FUN_060155A4\n"
    ".type _FUN_060155A4, @function\n"
    "_FUN_060155A4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD82C\n"  /* mov.l @(0xB0,PC),r8  {[0x06015668] = 0x0000DDB2} */
    ".word 0xE904\n"  /* mov #4,r9 */
    ".word 0xDA2C\n"  /* mov.l @(0xB0,PC),r10  {[0x0601566C] = 0x00008000} */
    ".word 0xDB2D\n"  /* mov.l @(0xB4,PC),r11  {[0x06015670] = 0x06027552} */
    ".word 0xDD2D\n"  /* mov.l @(0xB4,PC),r13  {[0x06015674] = 0x06084FC8} */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8920\n"  /* bt 0x06015614 */
    ".word 0x6CEC\n"  /* extu.b r14,r12 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x63C3\n"  /* mov r12,r3 */
    ".word 0x4C08\n"  /* shll2 r12 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3C3C\n"  /* add r3,r12 */
    ".word 0x6CCF\n"  /* exts.w r12,r12 */
    ".word 0x3CDC\n"  /* add r13,r12 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8D18\n"  /* bt/s 0x0601562A */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5245\n"  /* mov.l @(0x14,r4),r2 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0xA00B\n"  /* bra 0x0601562A */
    ".word 0x1425\n"  /* mov.l r2,@(0x14,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5247\n"  /* mov.l @(0x1C,r4),r2 */
    ".word 0x1424\n"  /* mov.l r2,@(0x10,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5249\n"  /* mov.l @(0x24,r4),r2 */
    ".word 0x5346\n"  /* mov.l @(0x18,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1436\n"  /* mov.l r3,@(0x18,r4) */
    ".word 0x5248\n"  /* mov.l @(0x20,r4),r2 */
    ".word 0x5347\n"  /* mov.l @(0x1C,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1437\n"  /* mov.l r3,@(0x1C,r4) */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x3293\n"  /* cmp/ge r9,r2 */
    ".word 0x8BB5\n"  /* bf 0x060155C0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xDDB2\n"  /* mov.l @(0x2C8,PC),r13  {[0x06015934] = 0x06084FC8} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD128\n"  /* mov.l @(0xA0,PC),r1  {[0x06015730] = 0x06084FC8} */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x8432\n"  /* mov.b @(0x2,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD226\n"  /* mov.l @(0x98,PC),r2  {[0x06015734] = 0x0605B858} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".size _FUN_060155A4, .-_FUN_060155A4\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_060156A6\n"
    ".type _FUN_060156A6, @function\n"
    "_FUN_060156A6:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".size _FUN_060156A6, .-_FUN_060156A6\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060156AC\n"
    ".type _FUN_060156AC, @function\n"
    "_FUN_060156AC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD221\n"  /* mov.l @(0x84,PC),r2  {[0x06015738] = 0x0605B8A0} */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601573C] = 0x06035228} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x6EDC\n"  /* extu.b r13,r14 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x06015730] = 0x06084FC8} */
    ".word 0x64DC\n"  /* extu.b r13,r4 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06015740] = 0x0605B860} */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x1E21\n"  /* mov.l r2,@(0x4,r14) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x1E32\n"  /* mov.l r3,@(0x8,r14) */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1E23\n"  /* mov.l r2,@(0xC,r14) */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x1E3D\n"  /* mov.l r3,@(0x34,r14) */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06015744] = 0x06016DD8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64DC\n"  /* extu.b r13,r4 */
    ".word 0x64DC\n"  /* extu.b r13,r4 */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x06015748] = 0x06085490} */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x63DC\n"  /* extu.b r13,r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x603C\n"  /* extu.b r3,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0xE33C\n"  /* mov #60,r3 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8044\n"  /* mov.b r0,@(0x4,r4) */
    ".word 0xE03A\n"  /* mov #58,r0 */
    ".word 0x8045\n"  /* mov.b r0,@(0x5,r4) */
    ".word 0xE041\n"  /* mov #65,r0 */
    ".word 0x0E34\n"  /* mov.b r3,@(r0,r14) */
    ".word 0x84E2\n"  /* mov.b @(0x2,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB858\n"  /* bsr 0x060147EA */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB8A0\n"  /* bsr 0x0601487E */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5228\n"  /* mov.l @(0x20,r2),r2 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB860\n"  /* bsr 0x06014806 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06016DD8 */
    ".word 0x6DD8\n"  /* swap.b r13,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5490\n"  /* mov.l @(0x0,r9),r4 */
    ".size _FUN_060156AC, .-_FUN_060156AC\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601574C\n"
    ".type _FUN_0601574C, @function\n"
    "_FUN_0601574C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".size _FUN_0601574C, .-_FUN_0601574C\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015754\n"
    ".type _FUN_06015754, @function\n"
    "_FUN_06015754:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0xDD1B\n"  /* mov.l @(0x6C,PC),r13  {[0x060157C8] = 0x06084FC8} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5244\n"  /* mov.l @(0x10,r4),r2 */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1431\n"  /* mov.l r3,@(0x4,r4) */
    ".word 0x5245\n"  /* mov.l @(0x14,r4),r2 */
    ".word 0x5342\n"  /* mov.l @(0x8,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1432\n"  /* mov.l r3,@(0x8,r4) */
    ".word 0x5246\n"  /* mov.l @(0x18,r4),r2 */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1433\n"  /* mov.l r3,@(0xC,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x231B\n"  /* or r1,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x891A\n"  /* bt 0x060157CC */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x534D\n"  /* mov.l @(0x34,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B25\n"  /* bf 0x060157FC */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524D\n"  /* mov.l @(0x34,r4),r2 */
    ".word 0xA01A\n"  /* bra 0x060157FC */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x534D\n"  /* mov.l @(0x34,r4),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890A\n"  /* bt 0x060157FC */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524D\n"  /* mov.l @(0x34,r4),r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x5332\n"  /* mov.l @(0x8,r3),r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8B0A\n"  /* bf 0x0601582A */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0x1312\n"  /* mov.l r1,@(0x8,r3) */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x060158A8] = 0x00010000} */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x5333\n"  /* mov.l @(0xC,r3),r3 */
    ".word 0x3343\n"  /* cmp/ge r4,r3 */
    ".word 0x8B09\n"  /* bf 0x06015858 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x1343\n"  /* mov.l r4,@(0xC,r3) */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x060158AC] = 0x06016DD8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0xE041\n"  /* mov #65,r0 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x0424\n"  /* mov.b r2,@(r0,r4) */
    ".word 0x034C\n"  /* mov.b @(r0,r4),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x890D\n"  /* bt 0x0601589C */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0x3EDC\n"  /* add r13,r14 */
    ".word 0x84E2\n"  /* mov.b @(0x2,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06016DD8 */
    ".word 0x6DD8\n"  /* swap.b r13,r13 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD11B\n"  /* mov.l @(0x6C,PC),r1  {[0x06015934] = 0x06084FC8} */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x8432\n"  /* mov.b @(0x2,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x06015938] = 0x0605B8A4} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".size _FUN_06015754, .-_FUN_06015754\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_060158DE\n"
    ".type _FUN_060158DE, @function\n"
    "_FUN_060158DE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x0601593C] = 0x0607EAE0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D05\n"  /* bt/s 0x060158F8 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06015940] = 0x06085F94} */
    ".word 0x2341\n"  /* mov.w r4,@r3 */
    ".word 0xA017\n"  /* bra 0x06015926 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62F0\n"  /* mov.b @r15,r2 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0xD10D\n"  /* mov.l @(0x34,PC),r1  {[0x06015934] = 0x06084FC8} */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x06015944] = 0x06078900} */
    ".word 0x900D\n"  /* mov.w @(0x1A,PC),r0 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x06015948] = 0x06044BD8} */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x0601594C] = 0x0601D5F4} */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06015950] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0224\n"  /* mov.b r2,@(r0,r2) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB8A4\n"  /* bsr 0x06014A86 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F94\n"  /* mov.l @(0x10,r9),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8900\n"  /* bt 0x0601594A */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4BD8\n"  /* .word 0x4BD8 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06015D20] = 0x000B6EF6} */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".size _FUN_060158DE, .-_FUN_060158DE\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015954\n"
    ".type _FUN_06015954, @function\n"
    "_FUN_06015954:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xE808\n"  /* mov #8,r8 */
    ".word 0xD931\n"  /* mov.l @(0xC4,PC),r9  {[0x06015A30] = 0x00008000} */
    ".word 0x9A5F\n"  /* mov.w @(0xBE,PC),r10 */
    ".word 0xDB31\n"  /* mov.l @(0xC4,PC),r11  {[0x06015A34] = 0x00010000} */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0xDD31\n"  /* mov.l @(0xC4,PC),r13  {[0x06015A38] = 0x06084FC8} */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x80F4\n"  /* mov.b r0,@(0x4,r15) */
    ".word 0x63CC\n"  /* extu.b r12,r3 */
    ".word 0x2F30\n"  /* mov.b r3,@r15 */
    ".word 0x6ECC\n"  /* extu.b r12,r14 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x14CC\n"  /* mov.l r12,@(0x30,r4) */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0x554B\n"  /* mov.l @(0x2C,r4),r5 */
    ".word 0x3593\n"  /* cmp/ge r9,r5 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xCA01\n"  /* xor #0x01,r0 */
    ".word 0x35C7\n"  /* cmp/gt r12,r5 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891A\n"  /* bt 0x060159DE */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524B\n"  /* mov.l @(0x2C,r4),r2 */
    ".word 0x32A8\n"  /* sub r10,r2 */
    ".word 0x142B\n"  /* mov.l r2,@(0x2C,r4) */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8947\n"  /* bt 0x06015A56 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x13CB\n"  /* mov.l r12,@(0x2C,r3) */
    ".word 0xA03C\n"  /* bra 0x06015A56 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0x522B\n"  /* mov.l @(0x2C,r2),r2 */
    ".word 0x3297\n"  /* cmp/gt r9,r2 */
    ".word 0x8B22\n"  /* bf 0x06015A3C */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524B\n"  /* mov.l @(0x2C,r4),r2 */
    ".word 0x32AC\n"  /* add r10,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x142B\n"  /* mov.l r2,@(0x2C,r4) */
    ".word 0x33B7\n"  /* cmp/gt r11,r3 */
    ".word 0x8B20\n"  /* bf 0x06015A56 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x13BB\n"  /* mov.l r11,@(0x2C,r3) */
    ".word 0xA015\n"  /* bra 0x06015A56 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0x12CB\n"  /* mov.l r12,@(0x2C,r2) */
    ".word 0x62F0\n"  /* mov.b @r15,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2F20\n"  /* mov.b r2,@r15 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06015A9C] = 0x06016DD8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x3283\n"  /* cmp/ge r8,r2 */
    ".word 0x8B8B\n"  /* bf 0x0601597C */
    ".word 0x60F0\n"  /* mov.b @r15,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8808\n"  /* cmp/eq #8,r0 */
    ".word 0x8B0D\n"  /* bf 0x06015A88 */
    ".word 0x84F4\n"  /* mov.b @(0x4,r15),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06015AA0] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06016DD8 */
    ".word 0x6DD8\n"  /* swap.b r13,r13 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".size _FUN_06015954, .-_FUN_06015954\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015AA4\n"
    ".type _FUN_06015AA4, @function\n"
    "_FUN_06015AA4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xED08\n"  /* mov #8,r13 */
    ".word 0x9E48\n"  /* mov.w @(0x90,PC),r14 */
    ".word 0xE702\n"  /* mov #2,r7 */
    ".word 0xD524\n"  /* mov.l @(0x90,PC),r5  {[0x06015B44] = 0x06084FC8} */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x335C\n"  /* add r5,r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x8031\n"  /* mov.b r0,@(0x1,r3) */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6C4C\n"  /* extu.b r4,r12 */
    ".word 0x63C3\n"  /* mov r12,r3 */
    ".word 0x4C08\n"  /* shll2 r12 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3C3C\n"  /* add r3,r12 */
    ".word 0x6CCF\n"  /* exts.w r12,r12 */
    ".word 0x3C5C\n"  /* add r5,r12 */
    ".word 0x626C\n"  /* extu.b r6,r2 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x12EC\n"  /* mov.l r14,@(0x30,r2) */
    ".word 0x00CC\n"  /* mov.b @(r0,r12),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B0B\n"  /* bf 0x06015B14 */
    ".word 0x626C\n"  /* extu.b r6,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x617C\n"  /* extu.b r7,r1 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x8022\n"  /* mov.b r0,@(0x2,r2) */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x636C\n"  /* extu.b r6,r3 */
    ".word 0x33D3\n"  /* cmp/ge r13,r3 */
    ".word 0x8BE0\n"  /* bf 0x06015ADE */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x345C\n"  /* add r5,r4 */
    ".word 0x8442\n"  /* mov.b @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".size _FUN_06015AA4, .-_FUN_06015AA4\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015B48\n"
    ".type _FUN_06015B48, @function\n"
    "_FUN_06015B48:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xE808\n"  /* mov #8,r8 */
    ".word 0xE907\n"  /* mov #7,r9 */
    ".word 0x9B60\n"  /* mov.w @(0xC0,PC),r11 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0xDD30\n"  /* mov.l @(0xC0,PC),r13  {[0x06015C24] = 0x06084FC8} */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x6ACC\n"  /* extu.b r12,r10 */
    ".word 0x6ECC\n"  /* extu.b r12,r14 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x3393\n"  /* cmp/ge r9,r3 */
    ".word 0x891A\n"  /* bt 0x06015BA6 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524C\n"  /* mov.l @(0x30,r4),r2 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x142C\n"  /* mov.l r2,@(0x30,r4) */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8B28\n"  /* bf 0x06015BE0 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x13CC\n"  /* mov.l r12,@(0x30,r3) */
    ".word 0xA01D\n"  /* bra 0x06015BE0 */
    ".word 0x7A01\n"  /* add #1,r10 */
    ".word 0x60EC\n"  /* extu.b r14,r0 */
    ".word 0x8807\n"  /* cmp/eq #7,r0 */
    ".word 0x8B19\n"  /* bf 0x06015BE0 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524C\n"  /* mov.l @(0x30,r4),r2 */
    ".word 0x32B8\n"  /* sub r11,r2 */
    ".word 0x142C\n"  /* mov.l r2,@(0x30,r4) */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x890A\n"  /* bt 0x06015BE0 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x13CC\n"  /* mov.l r12,@(0x30,r3) */
    ".word 0x7A01\n"  /* add #1,r10 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06015C28] = 0x06016DD8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x3283\n"  /* cmp/ge r8,r2 */
    ".word 0x8BBD\n"  /* bf 0x06015B6A */
    ".word 0x60AC\n"  /* extu.b r10,r0 */
    ".word 0x8808\n"  /* cmp/eq #8,r0 */
    ".word 0x8B0C\n"  /* bf 0x06015C0E */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06015C2C] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0C00\n"  /* .word 0x0C00 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06016DD8 */
    ".word 0x6DD8\n"  /* swap.b r13,r13 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD116\n"  /* mov.l @(0x58,PC),r1  {[0x06015CA0] = 0x06084FC8} */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x8432\n"  /* mov.b @(0x2,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x06015CA4] = 0x0605B8B0} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".size _FUN_06015B48, .-_FUN_06015B48\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06015C5E\n"
    ".type _FUN_06015C5E, @function\n"
    "_FUN_06015C5E:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDC0E\n"  /* mov.l @(0x38,PC),r12  {[0x06015CA0] = 0x06084FC8} */
    ".word 0x9D18\n"  /* mov.w @(0x30,PC),r13 */
    ".word 0xEE08\n"  /* mov #8,r14 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x13DC\n"  /* mov.l r13,@(0x30,r3) */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x33E3\n"  /* cmp/ge r14,r3 */
    ".word 0x8BF1\n"  /* bf 0x06015C70 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x06015CA8] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB8B0\n"  /* bsr 0x06014E0A */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".size _FUN_06015C5E, .-_FUN_06015C5E\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015CAC\n"
    ".type _FUN_06015CAC, @function\n"
    "_FUN_06015CAC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x9B35\n"  /* mov.w @(0x6A,PC),r11 */
    ".word 0xEC08\n"  /* mov #8,r12 */
    ".word 0xDD1B\n"  /* mov.l @(0x6C,PC),r13  {[0x06015D28] = 0x06084FC8} */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x66EC\n"  /* extu.b r14,r6 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x654C\n"  /* extu.b r4,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x525C\n"  /* mov.l @(0x30,r5),r2 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x152C\n"  /* mov.l r2,@(0x30,r5) */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8B0A\n"  /* bf 0x06015CF8 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x13EC\n"  /* mov.l r14,@(0x30,r3) */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x33C3\n"  /* cmp/ge r12,r3 */
    ".word 0x8BE1\n"  /* bf 0x06015CC4 */
    ".word 0x606C\n"  /* extu.b r6,r0 */
    ".word 0x8808\n"  /* cmp/eq #8,r0 */
    ".word 0x8B08\n"  /* bf 0x06015D18 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06015D2C] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".size _FUN_06015CAC, .-_FUN_06015CAC\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015D30\n"
    ".type _FUN_06015D30, @function\n"
    "_FUN_06015D30:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xEB05\n"  /* mov #5,r11 */
    ".word 0xEC08\n"  /* mov #8,r12 */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0xDE27\n"  /* mov.l @(0x9C,PC),r14  {[0x06015DE0] = 0x06084FC8} */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x64DC\n"  /* extu.b r13,r4 */
    ".word 0x654C\n"  /* extu.b r4,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35EC\n"  /* add r14,r5 */
    ".word 0x15DC\n"  /* mov.l r13,@(0x30,r5) */
    ".word 0x8452\n"  /* mov.b @(0x2,r5),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B0B\n"  /* bf 0x06015D7A */
    ".word 0x624C\n"  /* extu.b r4,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32EC\n"  /* add r14,r2 */
    ".word 0x61BC\n"  /* extu.b r11,r1 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x8022\n"  /* mov.b r0,@(0x2,r2) */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x33C3\n"  /* cmp/ge r12,r3 */
    ".word 0x8BE1\n"  /* bf 0x06015D46 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06015DE4] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06015D30, .-_FUN_06015D30\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015D94\n"
    ".type _FUN_06015D94, @function\n"
    "_FUN_06015D94:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDB10\n"  /* mov.l @(0x40,PC),r11  {[0x06015DE0] = 0x06084FC8} */
    ".word 0xEC08\n"  /* mov #8,r12 */
    ".word 0xED03\n"  /* mov #3,r13 */
    ".word 0xEE09\n"  /* mov #9,r14 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x654C\n"  /* extu.b r4,r5 */
    ".word 0x60EC\n"  /* extu.b r14,r0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x35BC\n"  /* add r11,r5 */
    ".word 0x8052\n"  /* mov.b r0,@(0x2,r5) */
    ".word 0xE041\n"  /* mov #65,r0 */
    ".word 0x33C3\n"  /* cmp/ge r12,r3 */
    ".word 0x8FEF\n"  /* bf/s 0x06015DAA */
    ".word 0x05D4\n"  /* mov.b r13,@(r0,r5) */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD302\n"  /* mov.l @(0x8,PC),r3  {[0x06015DE4] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xD420\n"  /* mov.l @(0x80,PC),r4  {[0x06015E70] = 0x06084FC8} */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x033C\n"  /* mov.b @(r0,r3),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0xE005\n"  /* mov #5,r0 */
    ".word 0x8032\n"  /* mov.b r0,@(0x2,r3) */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06015E74] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".size _FUN_06015D94, .-_FUN_06015D94\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06015E26\n"
    ".type _FUN_06015E26, @function\n"
    "_FUN_06015E26:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDC10\n"  /* mov.l @(0x40,PC),r12  {[0x06015E70] = 0x06084FC8} */
    ".word 0xED08\n"  /* mov #8,r13 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x645C\n"  /* extu.b r5,r4 */
    ".word 0x60DC\n"  /* extu.b r13,r0 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x625C\n"  /* extu.b r5,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34CC\n"  /* add r12,r4 */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0x534D\n"  /* mov.l @(0x34,r4),r3 */
    ".word 0x1431\n"  /* mov.l r3,@(0x4,r4) */
    ".word 0x14EB\n"  /* mov.l r14,@(0x2C,r4) */
    ".word 0x32D3\n"  /* cmp/ge r13,r2 */
    ".word 0x8FED\n"  /* bf/s 0x06015E38 */
    ".word 0x14EC\n"  /* mov.l r14,@(0x30,r4) */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD302\n"  /* mov.l @(0x8,PC),r3  {[0x06015E74] = 0x060172E4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x72E4\n"  /* add #-28,r2 */
    ".size _FUN_06015E26, .-_FUN_06015E26\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015E78\n"
    ".type _FUN_06015E78, @function\n"
    "_FUN_06015E78:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE041\n"  /* mov #65,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x06015EB4] = 0x06084FC8} */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x0324\n"  /* mov.b r2,@(r0,r3) */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0xB00B\n"  /* bsr 0x06015EB8 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x8422\n"  /* mov.b @(0x2,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8022\n"  /* mov.b r0,@(0x2,r2) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".size _FUN_06015E78, .-_FUN_06015E78\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06015FB0\n"
    ".type _FUN_06015FB0, @function\n"
    "_FUN_06015FB0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".size _FUN_06015FB0, .-_FUN_06015FB0\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06015FC2\n"
    ".type _FUN_06015FC2, @function\n"
    "_FUN_06015FC2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xDD3D\n"  /* mov.l @(0xF4,PC),r13  {[0x060160BC] = 0x06084FC8} */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524C\n"  /* mov.l @(0x30,r4),r2 */
    ".word 0x534E\n"  /* mov.l @(0x38,r4),r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8D42\n"  /* bt/s 0x0601605E */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5246\n"  /* mov.l @(0x18,r4),r2 */
    ".word 0x534C\n"  /* mov.l @(0x30,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x143C\n"  /* mov.l r3,@(0x30,r4) */
    ".word 0x5246\n"  /* mov.l @(0x18,r4),r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xCA01\n"  /* xor #0x01,r0 */
    ".word 0x524E\n"  /* mov.l @(0x38,r4),r2 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890A\n"  /* bt 0x06016022 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524E\n"  /* mov.l @(0x38,r4),r2 */
    ".word 0x142C\n"  /* mov.l r2,@(0x30,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5246\n"  /* mov.l @(0x18,r4),r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x534C\n"  /* mov.l @(0x30,r4),r3 */
    ".word 0x524E\n"  /* mov.l @(0x38,r4),r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890A\n"  /* bt 0x0601605E */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524E\n"  /* mov.l @(0x38,r4),r2 */
    ".word 0x142C\n"  /* mov.l r2,@(0x30,r4) */
    ".word 0x6BEC\n"  /* extu.b r14,r11 */
    ".word 0x63B3\n"  /* mov r11,r3 */
    ".word 0x4B08\n"  /* shll2 r11 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3B3C\n"  /* add r3,r11 */
    ".word 0x6BBF\n"  /* exts.w r11,r11 */
    ".word 0x3BDC\n"  /* add r13,r11 */
    ".word 0x52B4\n"  /* mov.l @(0x10,r11),r2 */
    ".word 0x53B1\n"  /* mov.l @(0x4,r11),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x1B31\n"  /* mov.l r3,@(0x4,r11) */
    ".word 0x52BD\n"  /* mov.l @(0x34,r11),r2 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x060160C0] = 0x06035438} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x060160C4] = 0x000F0000} */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x8952\n"  /* bt 0x0601612E */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0x5224\n"  /* mov.l @(0x10,r2),r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8915\n"  /* bt 0x060160CC */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x060160C8] = 0xFFFC0000} */
    ".word 0x9401\n"  /* mov.w @(0x2,PC),r4 */
    ".word 0xA015\n"  /* bra 0x060160E4 */
    ".word 0x1214\n"  /* mov.l r1,@(0x10,r2) */
    ".word 0xF800\n"  /* .word 0xF800 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5438\n"  /* mov.l @(0x20,r3),r4 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFC\n"  /* .word 0xFFFC */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0xD147\n"  /* mov.l @(0x11C,PC),r1  {[0x060161FC] = 0x00040000} */
    ".word 0x1214\n"  /* mov.l r1,@(0x10,r2) */
    ".word 0x9489\n"  /* mov.w @(0x112,PC),r4 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x5037\n"  /* mov.l @(0x1C,r3),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890C\n"  /* bt 0x06016116 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x5254\n"  /* mov.l @(0x10,r5),r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1524\n"  /* mov.l r2,@(0x10,r5) */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x5134\n"  /* mov.l @(0x10,r3),r1 */
    ".word 0x3148\n"  /* sub r4,r1 */
    ".word 0x1314\n"  /* mov.l r1,@(0x10,r3) */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x5254\n"  /* mov.l @(0x10,r5),r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xCA01\n"  /* xor #0x01,r0 */
    ".word 0x5351\n"  /* mov.l @(0x4,r5),r3 */
    ".word 0x525D\n"  /* mov.l @(0x34,r5),r2 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D0D\n"  /* bt/s 0x06016176 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x525D\n"  /* mov.l @(0x34,r5),r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xA01F\n"  /* bra 0x060161B4 */
    ".word 0x6C4C\n"  /* extu.b r4,r12 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x5254\n"  /* mov.l @(0x10,r5),r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x5351\n"  /* mov.l @(0x4,r5),r3 */
    ".word 0x525D\n"  /* mov.l @(0x34,r5),r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890B\n"  /* bt 0x060161B4 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x525D\n"  /* mov.l @(0x34,r5),r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6C4C\n"  /* extu.b r4,r12 */
    ".word 0xB610\n"  /* bsr 0x06016DD8 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x2CC8\n"  /* tst r12,r12 */
    ".word 0x892E\n"  /* bt 0x0601621C */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0xE041\n"  /* mov #65,r0 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x0424\n"  /* mov.b r2,@(r0,r4) */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x034C\n"  /* mov.b @(r0,r4),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B0E\n"  /* bf 0x06016200 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0x3EDC\n"  /* add r13,r14 */
    ".word 0xA011\n"  /* bra 0x0601621A */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0x3EDC\n"  /* add r13,r14 */
    ".word 0x84E2\n"  /* mov.b @(0x2,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06015FC2, .-_FUN_06015FC2\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016228\n"
    ".type _FUN_06016228, @function\n"
    "_FUN_06016228:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E4C\n"  /* extu.b r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".size _FUN_06016228, .-_FUN_06016228\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016230\n"
    ".type _FUN_06016230, @function\n"
    "_FUN_06016230:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6D4C\n"  /* extu.b r4,r13 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x4D08\n"  /* shll2 r13 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x0601628C] = 0x06084FC8} */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x1E3B\n"  /* mov.l r3,@(0x2C,r14) */
    ".word 0x4D00\n"  /* shll r13 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06016290] = 0x0605BAB8} */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x4228\n"  /* shll16 r2 */
    ".word 0x1E2D\n"  /* mov.l r2,@(0x34,r14) */
    ".word 0x63D3\n"  /* mov r13,r3 */
    ".word 0x7302\n"  /* add #2,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x4228\n"  /* shll16 r2 */
    ".word 0x1E24\n"  /* mov.l r2,@(0x10,r14) */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06016294] = 0x06035438} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6441\n"  /* mov.w @r4,r4 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0x1E09\n"  /* mov.l r0,@(0x24,r14) */
    ".word 0x85D3\n"  /* mov.w @(0x6,r13),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x4228\n"  /* shll16 r2 */
    ".word 0x1E28\n"  /* mov.l r2,@(0x20,r14) */
    ".word 0x84E2\n"  /* mov.b @(0x2,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBAB8\n"  /* bsr 0x06015806 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5438\n"  /* mov.l @(0x20,r3),r4 */
    ".size _FUN_06016230, .-_FUN_06016230\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016298\n"
    ".type _FUN_06016298, @function\n"
    "_FUN_06016298:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x6CEC\n"  /* extu.b r14,r12 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0xEB00\n"  /* mov #0,r11 */
    ".word 0x63C3\n"  /* mov r12,r3 */
    ".word 0xEA01\n"  /* mov #1,r10 */
    ".size _FUN_06016298, .-_FUN_06016298\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060162AC\n"
    ".type _FUN_060162AC, @function\n"
    "_FUN_060162AC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C08\n"  /* shll2 r12 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xDD28\n"  /* mov.l @(0xA0,PC),r13  {[0x06016354] = 0x06084FC8} */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3C3C\n"  /* add r3,r12 */
    ".word 0x6CCF\n"  /* exts.w r12,r12 */
    ".word 0x3CDC\n"  /* add r13,r12 */
    ".word 0x52C4\n"  /* mov.l @(0x10,r12),r2 */
    ".word 0x53C1\n"  /* mov.l @(0x4,r12),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1C31\n"  /* mov.l r3,@(0x4,r12) */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x52CD\n"  /* mov.l @(0x34,r12),r2 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06016358] = 0x06035438} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x52C9\n"  /* mov.l @(0x24,r12),r2 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xCA01\n"  /* xor #0x01,r0 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0601635C] = 0x0605BAF8} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8911\n"  /* bt 0x0601630C */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0601635C] = 0x0605BAF8} */
    ".word 0x22A0\n"  /* mov.b r10,@r2 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5348\n"  /* mov.l @(0x20,r4),r3 */
    ".word 0x1431\n"  /* mov.l r3,@(0x4,r4) */
    ".word 0x5144\n"  /* mov.l @(0x10,r4),r1 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x06016360] = 0x06034FE0} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0xE00A\n"  /* mov #10,r0 */
    ".word 0x1404\n"  /* mov.l r0,@(0x10,r4) */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x3343\n"  /* cmp/ge r4,r3 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xCA01\n"  /* xor #0x01,r0 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0x535D\n"  /* mov.l @(0x34,r5),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8914\n"  /* bt 0x06016364 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524D\n"  /* mov.l @(0x34,r4),r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0xA027\n"  /* bra 0x060163A2 */
    ".word 0x6BAC\n"  /* extu.b r10,r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5438\n"  /* mov.l @(0x20,r3),r4 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBAF8\n"  /* bsr 0x06015952 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4FE0\n"  /* .word 0x4FE0 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x3243\n"  /* cmp/ge r4,r2 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0x535D\n"  /* mov.l @(0x34,r5),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890B\n"  /* bt 0x060163A2 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524D\n"  /* mov.l @(0x34,r4),r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x6BAC\n"  /* extu.b r10,r11 */
    ".word 0xD02E\n"  /* mov.l @(0xB8,PC),r0  {[0x0601645C] = 0x06085F89} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891A\n"  /* bt 0x060163E0 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x9255\n"  /* mov.w @(0xAA,PC),r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x534C\n"  /* mov.l @(0x30,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x143C\n"  /* mov.l r3,@(0x30,r4) */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8B0A\n"  /* bf 0x060163E0 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0x121C\n"  /* mov.l r1,@(0x30,r2) */
    ".word 0xB4FA\n"  /* bsr 0x06016DD8 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6BBC\n"  /* extu.b r11,r11 */
    ".word 0x2BB8\n"  /* tst r11,r11 */
    ".word 0x890B\n"  /* bt 0x06016402 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0x3EDC\n"  /* add r13,r14 */
    ".word 0xE207\n"  /* mov #7,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_060162AC, .-_FUN_060162AC\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016410\n"
    ".type _FUN_06016410, @function\n"
    "_FUN_06016410:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0601645C] = 0x06085F89} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D24\n"  /* bt/s 0x06016464 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0xD510\n"  /* mov.l @(0x40,PC),r5  {[0x06016460] = 0x06084FC8} */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x921B\n"  /* mov.w @(0x36,PC),r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x345C\n"  /* add r5,r4 */
    ".word 0x534C\n"  /* mov.l @(0x30,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x143C\n"  /* mov.l r3,@(0x30,r4) */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8B0A\n"  /* bf 0x06016454 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0x121C\n"  /* mov.l r1,@(0x30,r2) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0xA4BF\n"  /* bra 0x06016DD8 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F89\n"  /* mov.l @(0x24,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06016410, .-_FUN_06016410\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016468\n"
    ".type _FUN_06016468, @function\n"
    "_FUN_06016468:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".size _FUN_06016468, .-_FUN_06016468\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016470\n"
    ".type _FUN_06016470, @function\n"
    "_FUN_06016470:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6EDC\n"  /* extu.b r13,r14 */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x06016500] = 0x06084FC8} */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x05EC\n"  /* mov.b @(r0,r14),r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0xB427\n"  /* bsr 0x06016CDC */
    ".word 0x64DC\n"  /* extu.b r13,r4 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x06016504] = 0x000B0000} */
    ".word 0x1E23\n"  /* mov.l r2,@(0xC,r14) */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x06016508] = 0x00040000} */
    ".word 0x1E36\n"  /* mov.l r3,@(0x18,r14) */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0601650C] = 0x0000C000} */
    ".word 0x1E29\n"  /* mov.l r2,@(0x24,r14) */
    ".word 0x84E2\n"  /* mov.b @(0x2,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x06016510] = 0x06085F89} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890C\n"  /* bt 0x060164C6 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x63D3\n"  /* mov r13,r3 */
    ".word 0x4D08\n"  /* shll2 r13 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x6DDF\n"  /* exts.w r13,r13 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x06016500] = 0x06084FC8} */
    ".word 0x3D2C\n"  /* add r2,r13 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x80D2\n"  /* mov.b r0,@(0x2,r13) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06016470, .-_FUN_06016470\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_060164CE\n"
    ".type _FUN_060164CE, @function\n"
    "_FUN_060164CE:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0xDD0A\n"  /* mov.l @(0x28,PC),r13  {[0x06016500] = 0x06084FC8} */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06016510] = 0x06085F89} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D19\n"  /* bt/s 0x06016514 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x14CB\n"  /* mov.l r12,@(0x2C,r4) */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0xA08E\n"  /* bra 0x0601661A */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F89\n"  /* mov.l @(0x24,r8),r15 */
    ".word 0xD544\n"  /* mov.l @(0x110,PC),r5  {[0x06016628] = 0x00010000} */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0x5223\n"  /* mov.l @(0xC,r2),r2 */
    ".word 0x3257\n"  /* cmp/gt r5,r2 */
    ".word 0x8B63\n"  /* bf 0x060165F6 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5244\n"  /* mov.l @(0x10,r4),r2 */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1431\n"  /* mov.l r3,@(0x4,r4) */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0xE304\n"  /* mov #4,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8918\n"  /* bt 0x06016582 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x534D\n"  /* mov.l @(0x34,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B23\n"  /* bf 0x060165B2 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524D\n"  /* mov.l @(0x34,r4),r2 */
    ".word 0xA018\n"  /* bra 0x060165B2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x534D\n"  /* mov.l @(0x34,r4),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890A\n"  /* bt 0x060165B2 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524D\n"  /* mov.l @(0x34,r4),r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5246\n"  /* mov.l @(0x18,r4),r2 */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x1433\n"  /* mov.l r3,@(0xC,r4) */
    ".word 0x5249\n"  /* mov.l @(0x24,r4),r2 */
    ".word 0x5346\n"  /* mov.l @(0x18,r4),r3 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x1436\n"  /* mov.l r3,@(0x18,r4) */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0601662C] = 0x00020000} */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x891E\n"  /* bt 0x0601661A */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x9219\n"  /* mov.w @(0x32,PC),r2 */
    ".word 0x1426\n"  /* mov.l r2,@(0x18,r4) */
    ".word 0xA012\n"  /* bra 0x0601661A */
    ".word 0x14C4\n"  /* mov.l r12,@(0x10,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x1453\n"  /* mov.l r5,@(0xC,r4) */
    ".word 0x14C9\n"  /* mov.l r12,@(0x24,r4) */
    ".word 0x62C3\n"  /* mov r12,r2 */
    ".word 0x14C6\n"  /* mov.l r12,@(0x18,r4) */
    ".word 0x8442\n"  /* mov.b @(0x2,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA3DA\n"  /* bra 0x06016DD8 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".size _FUN_060164CE, .-_FUN_060164CE\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016630\n"
    ".type _FUN_06016630, @function\n"
    "_FUN_06016630:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".size _FUN_06016630, .-_FUN_06016630\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016634\n"
    ".type _FUN_06016634, @function\n"
    "_FUN_06016634:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD225\n"  /* mov.l @(0x94,PC),r2  {[0x060166D4] = 0x0605BAFA} */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x060166D8] = 0x06035228} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0xD025\n"  /* mov.l @(0x94,PC),r0  {[0x060166DC] = 0x06085F89} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8912\n"  /* bt 0x06016672 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x060166E0] = 0x06084FC8} */
    ".word 0x60EC\n"  /* extu.b r14,r0 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x143B\n"  /* mov.l r3,@(0x2C,r4) */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x4328\n"  /* shll16 r3 */
    ".word 0x1431\n"  /* mov.l r3,@(0x4,r4) */
    ".word 0xB3B3\n"  /* bsr 0x06016DD8 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06016634, .-_FUN_06016634\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601667A\n"
    ".type _FUN_0601667A, @function\n"
    "_FUN_0601667A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xEC06\n"  /* mov #6,r12 */
    ".word 0xDD16\n"  /* mov.l @(0x58,PC),r13  {[0x060166E0] = 0x06084FC8} */
    ".word 0xEE08\n"  /* mov #8,r14 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x61CC\n"  /* extu.b r12,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x8032\n"  /* mov.b r0,@(0x2,r3) */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x33E3\n"  /* cmp/ge r14,r3 */
    ".word 0x8BEF\n"  /* bf 0x0601668C */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8031\n"  /* mov.b r0,@(0x1,r3) */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA609\n"  /* bra 0x060172E4 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBAFA\n"  /* bsr 0x06015CCE */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5228\n"  /* mov.l @(0x20,r2),r2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F89\n"  /* mov.l @(0x24,r8),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xD518\n"  /* mov.l @(0x60,PC),r5  {[0x0601674C] = 0x06084FC8} */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x345C\n"  /* add r5,r4 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x8022\n"  /* mov.b r0,@(0x2,r2) */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8041\n"  /* mov.b r0,@(0x1,r4) */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xA5E0\n"  /* bra 0x060172E4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x654C\n"  /* extu.b r4,r5 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x0601674C] = 0x06084FC8} */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x156E\n"  /* mov.l r6,@(0x38,r5) */
    ".word 0x0564\n"  /* mov.b r6,@(r0,r5) */
    ".word 0x8452\n"  /* mov.b @(0x2,r5),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8052\n"  /* mov.b r0,@(0x2,r5) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".size _FUN_0601667A, .-_FUN_0601667A\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016750\n"
    ".type _FUN_06016750, @function\n"
    "_FUN_06016750:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x060167BC] = 0x0605BB0C} */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x060167C0] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0xD718\n"  /* mov.l @(0x60,PC),r7  {[0x060167C4] = 0x06084FC8} */
    ".word 0x654C\n"  /* extu.b r4,r5 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x357C\n"  /* add r7,r5 */
    ".word 0x005C\n"  /* mov.b @(r0,r5),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x036E\n"  /* mov.l @(r0,r6),r3 */
    ".word 0x153F\n"  /* mov.l r3,@(0x3C,r5) */
    ".word 0x8452\n"  /* mov.b @(0x2,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8052\n"  /* mov.b r0,@(0x2,r5) */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x035C\n"  /* mov.b @(r0,r5),r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x0534\n"  /* mov.b r3,@(r0,r5) */
    ".word 0x035C\n"  /* mov.b @(r0,r5),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B0B\n"  /* bf 0x060167B4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x347C\n"  /* add r7,r4 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBB0C\n"  /* bsr 0x06015DDA */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".size _FUN_06016750, .-_FUN_06016750\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060167C8\n"
    ".type _FUN_060167C8, @function\n"
    "_FUN_060167C8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".size _FUN_060167C8, .-_FUN_060167C8\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060167DC\n"
    ".type _FUN_060167DC, @function\n"
    "_FUN_060167DC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xDD23\n"  /* mov.l @(0x8C,PC),r13  {[0x06016870] = 0x06084FC8} */
    ".word 0x9243\n"  /* mov.w @(0x86,PC),r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x534B\n"  /* mov.l @(0x2C,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x143B\n"  /* mov.l r3,@(0x2C,r4) */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x534F\n"  /* mov.l @(0x3C,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8F0C\n"  /* bf/s 0x06016814 */
    ".word 0x6BCC\n"  /* extu.b r12,r11 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524F\n"  /* mov.l @(0x3C,r4),r2 */
    ".word 0x142B\n"  /* mov.l r2,@(0x2C,r4) */
    ".word 0xEB01\n"  /* mov #1,r11 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x503C\n"  /* mov.l @(0x30,r3),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893C\n"  /* bt 0x060168A6 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0xE207\n"  /* mov #7,r2 */
    ".word 0x941D\n"  /* mov.w @(0x3A,PC),r4 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x891E\n"  /* bt 0x06016874 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x525C\n"  /* mov.l @(0x30,r5),r2 */
    ".word 0x324C\n"  /* add r4,r2 */
    ".word 0x152C\n"  /* mov.l r2,@(0x30,r5) */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8B28\n"  /* bf 0x060168A6 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x13CC\n"  /* mov.l r12,@(0x30,r3) */
    ".word 0xA01D\n"  /* bra 0x060168A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0F00\n"  /* .word 0x0F00 */
    ".word 0x1800\n"  /* mov.l r0,@(0x0,r8) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35DC\n"  /* add r13,r5 */
    ".word 0x525C\n"  /* mov.l @(0x30,r5),r2 */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x152C\n"  /* mov.l r2,@(0x30,r5) */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8909\n"  /* bt 0x060168A6 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x13CC\n"  /* mov.l r12,@(0x30,r3) */
    ".word 0xB297\n"  /* bsr 0x06016DD8 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6BBC\n"  /* extu.b r11,r11 */
    ".word 0x2BB8\n"  /* tst r11,r11 */
    ".word 0x890E\n"  /* bt 0x060168CE */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0xE041\n"  /* mov #65,r0 */
    ".word 0x0424\n"  /* mov.b r2,@(r0,r4) */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0xE207\n"  /* mov #7,r2 */
    ".word 0xD517\n"  /* mov.l @(0x5C,PC),r5  {[0x0601693C] = 0x06084FC8} */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x890F\n"  /* bt 0x06016904 */
    ".word 0x624C\n"  /* extu.b r4,r2 */
    ".word 0x614C\n"  /* extu.b r4,r1 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0xA00A\n"  /* bra 0x06016918 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x624C\n"  /* extu.b r4,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x9110\n"  /* mov.w @(0x20,PC),r1 */
    ".word 0x121E\n"  /* mov.l r1,@(0x38,r2) */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x345C\n"  /* add r5,r4 */
    ".word 0x8442\n"  /* mov.b @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".size _FUN_060167DC, .-_FUN_060167DC\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016940\n"
    ".type _FUN_06016940, @function\n"
    "_FUN_06016940:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE207\n"  /* mov #7,r2 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0xEB00\n"  /* mov #0,r11 */
    ".size _FUN_06016940, .-_FUN_06016940\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016950\n"
    ".type _FUN_06016950, @function\n"
    "_FUN_06016950:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDD2F\n"  /* mov.l @(0xBC,PC),r13  {[0x06016A10] = 0x06084FC8} */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8D21\n"  /* bt/s 0x0601699C */
    ".word 0xE504\n"  /* mov #4,r5 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0xD22D\n"  /* mov.l @(0xB4,PC),r2  {[0x06016A14] = 0x06034FE0} */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x514E\n"  /* mov.l @(0x38,r4),r1 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x534C\n"  /* mov.l @(0x30,r4),r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x143C\n"  /* mov.l r3,@(0x30,r4) */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x534E\n"  /* mov.l @(0x38,r4),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x892E\n"  /* bt 0x060169E0 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524E\n"  /* mov.l @(0x38,r4),r2 */
    ".word 0x142C\n"  /* mov.l r2,@(0x30,r4) */
    ".word 0xA022\n"  /* bra 0x060169E0 */
    ".word 0xEB01\n"  /* mov #1,r11 */
    ".word 0x6CEC\n"  /* extu.b r14,r12 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x06016A14] = 0x06034FE0} */
    ".word 0x63C3\n"  /* mov r12,r3 */
    ".word 0x4C08\n"  /* shll2 r12 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3C3C\n"  /* add r3,r12 */
    ".word 0x6CCF\n"  /* exts.w r12,r12 */
    ".word 0x3CDC\n"  /* add r13,r12 */
    ".word 0x51CE\n"  /* mov.l @(0x38,r12),r1 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x53CC\n"  /* mov.l @(0x30,r12),r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x1C3C\n"  /* mov.l r3,@(0x30,r12) */
    ".word 0xB20C\n"  /* bsr 0x06016DD8 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x52CC\n"  /* mov.l @(0x30,r12),r2 */
    ".word 0x53CE\n"  /* mov.l @(0x38,r12),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B0B\n"  /* bf 0x060169E0 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524E\n"  /* mov.l @(0x38,r4),r2 */
    ".word 0x142C\n"  /* mov.l r2,@(0x30,r4) */
    ".word 0xEB01\n"  /* mov #1,r11 */
    ".word 0xB1FA\n"  /* bsr 0x06016DD8 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6BBC\n"  /* extu.b r11,r11 */
    ".word 0x2BB8\n"  /* tst r11,r11 */
    ".word 0x890B\n"  /* bt 0x06016A02 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0x3EDC\n"  /* add r13,r14 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4FE0\n"  /* .word 0x4FE0 */
    ".size _FUN_06016950, .-_FUN_06016950\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016A18\n"
    ".type _FUN_06016A18, @function\n"
    "_FUN_06016A18:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".size _FUN_06016A18, .-_FUN_06016A18\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016A1C\n"
    ".type _FUN_06016A1C, @function\n"
    "_FUN_06016A1C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x6EF0\n"  /* mov.b @r15,r14 */
    ".word 0xD22C\n"  /* mov.l @(0xB0,PC),r2  {[0x06016AD8] = 0x06084FC8} */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6EEF\n"  /* exts.w r14,r14 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x05EC\n"  /* mov.b @(r0,r14),r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0xB14D\n"  /* bsr 0x06016CDC */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xD226\n"  /* mov.l @(0x98,PC),r2  {[0x06016ADC] = 0x000B0000} */
    ".word 0x1E23\n"  /* mov.l r2,@(0xC,r14) */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x06016AE0] = 0x00040000} */
    ".word 0x1E36\n"  /* mov.l r3,@(0x18,r14) */
    ".word 0xD226\n"  /* mov.l @(0x98,PC),r2  {[0x06016AE4] = 0x0000C000} */
    ".word 0x1E29\n"  /* mov.l r2,@(0x24,r14) */
    ".word 0x84E2\n"  /* mov.b @(0x2,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06016A1C, .-_FUN_06016A1C\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06016A60\n"
    ".type _FUN_06016A60, @function\n"
    "_FUN_06016A60:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0xDD1B\n"  /* mov.l @(0x6C,PC),r13  {[0x06016AD8] = 0x06084FC8} */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x06016AE8] = 0x00010000} */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x5333\n"  /* mov.l @(0xC,r3),r3 */
    ".word 0x3357\n"  /* cmp/gt r5,r3 */
    ".word 0x8B70\n"  /* bf 0x06016B64 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5244\n"  /* mov.l @(0x10,r4),r2 */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x1431\n"  /* mov.l r3,@(0x4,r4) */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0xE304\n"  /* mov #4,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8923\n"  /* bt 0x06016AEC */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x534D\n"  /* mov.l @(0x34,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B2E\n"  /* bf 0x06016B1C */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524D\n"  /* mov.l @(0x34,r4),r2 */
    ".word 0xA023\n"  /* bra 0x06016B1C */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x534D\n"  /* mov.l @(0x34,r4),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890A\n"  /* bt 0x06016B1C */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x524D\n"  /* mov.l @(0x34,r4),r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x5246\n"  /* mov.l @(0x18,r4),r2 */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x1433\n"  /* mov.l r3,@(0xC,r4) */
    ".word 0x5249\n"  /* mov.l @(0x24,r4),r2 */
    ".word 0x5346\n"  /* mov.l @(0x18,r4),r3 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x1436\n"  /* mov.l r3,@(0x18,r4) */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06016B94] = 0x00020000} */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x891F\n"  /* bt 0x06016B86 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x921B\n"  /* mov.w @(0x36,PC),r2 */
    ".word 0x1426\n"  /* mov.l r2,@(0x18,r4) */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x1434\n"  /* mov.l r3,@(0x10,r4) */
    ".word 0xA011\n"  /* bra 0x06016B86 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x1453\n"  /* mov.l r5,@(0xC,r4) */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x1429\n"  /* mov.l r2,@(0x24,r4) */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x1426\n"  /* mov.l r2,@(0x18,r4) */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA125\n"  /* bra 0x06016DD8 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD626\n"  /* mov.l @(0x98,PC),r6  {[0x06016C34] = 0x06084FC8} */
    ".word 0x654C\n"  /* extu.b r4,r5 */
    ".word 0xE041\n"  /* mov #65,r0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x356C\n"  /* add r6,r5 */
    ".word 0x025C\n"  /* mov.b @(r0,r5),r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x0524\n"  /* mov.b r2,@(r0,r5) */
    ".word 0x035C\n"  /* mov.b @(r0,r5),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B0B\n"  /* bf 0x06016BD4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x346C\n"  /* add r6,r4 */
    ".word 0xE207\n"  /* mov #7,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8042\n"  /* mov.b r0,@(0x2,r4) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD111\n"  /* mov.l @(0x44,PC),r1  {[0x06016C34] = 0x06084FC8} */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x8432\n"  /* mov.b @(0x2,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x06016C38] = 0x0605BB1C} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x06016C34] = 0x06084FC8} */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x8432\n"  /* mov.b @(0x2,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06016C3C] = 0x0605BB48} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBB1C\n"  /* bsr 0x06016276 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBB48\n"  /* bsr 0x060162D2 */
    ".word 0x654C\n"  /* extu.b r4,r5 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x06016C9C] = 0x06084FC8} */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0xE327\n"  /* mov #39,r3 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x8051\n"  /* mov.b r0,@(0x1,r5) */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x06016CA0] = 0x06085F88} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x8452\n"  /* mov.b @(0x2,r5),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8052\n"  /* mov.b r0,@(0x2,r5) */
    ".size _FUN_06016A60, .-_FUN_06016A60\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06016C6A\n"
    ".type _FUN_06016C6A, @function\n"
    "_FUN_06016C6A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xDE0B\n"  /* mov.l @(0x2C,PC),r14  {[0x06016CA0] = 0x06085F88} */
    ".word 0xB55B\n"  /* bsr 0x0601772E */
    ".word 0x64E0\n"  /* mov.b @r14,r4 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x72FA\n"  /* add #-6,r2 */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0x63E0\n"  /* mov.b @r14,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8907\n"  /* bt 0x06016C94 */
    ".word 0xB553\n"  /* bsr 0x0601772E */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA328\n"  /* bra 0x060172E4 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F88\n"  /* mov.l @(0x20,r8),r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x06016CD4] = 0x06084FC8} */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x8432\n"  /* mov.b @(0x2,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06016CD8] = 0x0605BB6C} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBB6C\n"  /* bsr 0x060163B6 */
    ".size _FUN_06016C6A, .-_FUN_06016C6A\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06016CE6\n"
    ".type _FUN_06016CE6, @function\n"
    "_FUN_06016CE6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x614C\n"  /* extu.b r4,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0xDD32\n"  /* mov.l @(0xC8,PC),r13  {[0x06016DC0] = 0x06084FC8} */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x2F50\n"  /* mov.b r5,@r15 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x8031\n"  /* mov.b r0,@(0x1,r3) */
    ".word 0xD02F\n"  /* mov.l @(0xBC,PC),r0  {[0x06016DC4] = 0x06085F89} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x06016DC8] = 0x0607EBF4} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8D0C\n"  /* bt/s 0x06016D30 */
    ".word 0x674C\n"  /* extu.b r4,r7 */
    ".word 0xE728\n"  /* mov #40,r7 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0xD127\n"  /* mov.l @(0x9C,PC),r1  {[0x06016DCC] = 0x00008000} */
    ".word 0x131B\n"  /* mov.l r1,@(0x2C,r3) */
    ".word 0xD527\n"  /* mov.l @(0x9C,PC),r5  {[0x06016DD0] = 0x0605BB74} */
    ".word 0x66EC\n"  /* extu.b r14,r6 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x627C\n"  /* extu.b r7,r2 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x666F\n"  /* exts.w r6,r6 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x36DC\n"  /* add r13,r6 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4328\n"  /* shll16 r3 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x1631\n"  /* mov.l r3,@(0x4,r6) */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4328\n"  /* shll16 r3 */
    ".word 0x7002\n"  /* add #2,r0 */
    ".word 0x1632\n"  /* mov.l r3,@(0x8,r6) */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4328\n"  /* shll16 r3 */
    ".word 0x7003\n"  /* add #3,r0 */
    ".word 0x1633\n"  /* mov.l r3,@(0xC,r6) */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4328\n"  /* shll16 r3 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x1634\n"  /* mov.l r3,@(0x10,r6) */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x4328\n"  /* shll16 r3 */
    ".word 0x163D\n"  /* mov.l r3,@(0x34,r6) */
    ".word 0xB024\n"  /* bsr 0x06016DD8 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x06016DD4] = 0x06085490} */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x7317\n"  /* add #23,r3 */
    ".word 0x603D\n"  /* extu.w r3,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8044\n"  /* mov.b r0,@(0x4,r4) */
    ".word 0xE03A\n"  /* mov #58,r0 */
    ".word 0x8045\n"  /* mov.b r0,@(0x5,r4) */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FC8\n"  /* .word 0x4FC8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F89\n"  /* mov.l @(0x24,r8),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBB74\n"  /* bsr 0x060164BE */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5490\n"  /* mov.l @(0x0,r9),r4 */
    ".size _FUN_06016CE6, .-_FUN_06016CE6\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060170FC\n"
    ".type _FUN_060170FC, @function\n"
    "_FUN_060170FC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xE512\n"  /* mov #18,r5 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x06017198] = 0x06018DDC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xA0E7\n"  /* bra 0x060172E4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".size _FUN_060170FC, .-_FUN_060170FC\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06017116\n"
    ".type _FUN_06017116, @function\n"
    "_FUN_06017116:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0601719C] = 0x06018E1E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE412\n"  /* mov #18,r4 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xA0DC\n"  /* bra 0x060172E4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".size _FUN_06017116, .-_FUN_06017116\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06017740\n"
    ".type _FUN_06017740, @function\n"
    "_FUN_06017740:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x63CC\n"  /* extu.b r12,r3 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0xDA18\n"  /* mov.l @(0x60,PC),r10  {[0x060177A8] = 0x06028400} */
    ".word 0xDB18\n"  /* mov.l @(0x60,PC),r11  {[0x060177AC] = 0x06085640} */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8F12\n"  /* bf/s 0x06017774 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x65EC\n"  /* extu.b r14,r5 */
    ".word 0xE336\n"  /* mov #54,r3 */
    ".word 0x7640\n"  /* add #64,r6 */
    ".word 0x253F\n"  /* muls.w r3,r5 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x35BC\n"  /* add r11,r5 */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x63CC\n"  /* extu.b r12,r3 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8FEE\n"  /* bf/s 0x06017750 */
    ".word 0x7D01\n"  /* add #1,r13 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06017740, .-_FUN_06017740\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06018738\n"
    ".type _FUN_06018738, @function\n"
    "_FUN_06018738:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0xEA08\n"  /* mov #8,r10 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDB28\n"  /* mov.l @(0xA0,PC),r11  {[0x060187EC] = 0x0605D1DC} */
    ".word 0xDC29\n"  /* mov.l @(0xA4,PC),r12  {[0x060187F0] = 0x06085FD0} */
    ".word 0xDE29\n"  /* mov.l @(0xA4,PC),r14  {[0x060187F4] = 0x060D6900} */
    ".word 0xDD2A\n"  /* mov.l @(0xA8,PC),r13  {[0x060187F8] = 0x06027630} */
    ".word 0x9645\n"  /* mov.w @(0x8A,PC),r6 */
    ".word 0xD92A\n"  /* mov.l @(0xA8,PC),r9  {[0x060187FC] = 0x00200000} */
    ".word 0xD42A\n"  /* mov.l @(0xA8,PC),r4  {[0x06018800] = 0x060D5840} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x9641\n"  /* mov.w @(0x82,PC),r6 */
    ".word 0x953F\n"  /* mov.w @(0x7E,PC),r5 */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x06018804] = 0x060C6000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x963D\n"  /* mov.w @(0x7A,PC),r6 */
    ".word 0x953D\n"  /* mov.w @(0x7A,PC),r5 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xD626\n"  /* mov.l @(0x98,PC),r6  {[0x06018808] = 0x00018000} */
    ".word 0xD926\n"  /* mov.l @(0x98,PC),r9  {[0x0601880C] = 0x00240000} */
    ".word 0xD427\n"  /* mov.l @(0x9C,PC),r4  {[0x06018810] = 0x060A6000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x9635\n"  /* mov.w @(0x6A,PC),r6 */
    ".word 0xD526\n"  /* mov.l @(0x98,PC),r5  {[0x06018814] = 0x0000A660} */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x06018818] = 0x060BF000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x9631\n"  /* mov.w @(0x62,PC),r6 */
    ".word 0x9531\n"  /* mov.w @(0x62,PC),r5 */
    ".word 0xD425\n"  /* mov.l @(0x94,PC),r4  {[0x0601881C] = 0x060C2000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x962B\n"  /* mov.w @(0x56,PC),r6 */
    ".word 0xD524\n"  /* mov.l @(0x90,PC),r5  {[0x06018820] = 0x0000B108} */
    ".word 0xD424\n"  /* mov.l @(0x90,PC),r4  {[0x06018824] = 0x002F8000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x35A3\n"  /* cmp/ge r10,r5 */
    ".word 0x8FEC\n"  /* bf/s 0x0601879C */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0xD418\n"  /* mov.l @(0x60,PC),r4  {[0x06018828] = 0x0607EAD8} */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601882C] = 0x06012E08} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06018830] = 0x0602304C} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x07DC\n"  /* mov.b @(r0,r13),r7 */
    ".word 0x3100\n"  /* cmp/eq r0,r1 */
    ".word 0x4F80\n"  /* .word 0x4F80 */
    ".word 0x38DC\n"  /* add r13,r8 */
    ".word 0x3000\n"  /* cmp/eq r0,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x6660\n"  /* mov.b @r6,r6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD1DC\n"  /* mov.l @(0x370,PC),r1  {[0x06018B60] = 0xE2636023} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FD0\n"  /* mov.l @(0x0,r13),r15 */
    ".word 0x060D\n"  /* mov.w @(r0,r0),r6 */
    ".word 0x6900\n"  /* mov.b @r0,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7630\n"  /* add #48,r6 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060D\n"  /* mov.w @(r0,r0),r6 */
    ".word 0x5840\n"  /* mov.l @(0x0,r4),r8 */
    ".word 0x060C\n"  /* mov.b @(r0,r0),r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xA660\n"  /* bra 0x060194DA */
    ".word 0x060B\n"  /* .word 0x060B */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x060C\n"  /* mov.b @(r0,r0),r6 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xB108\n"  /* bsr 0x06018A36 */
    ".word 0x002F\n"  /* mac.l @r2+,@r0+ */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06012E08 */
    ".word 0x2E08\n"  /* tst r0,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602304C */
    ".word 0x304C\n"  /* add r4,r0 */
    ".size _FUN_06018738, .-_FUN_06018738\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06018834\n"
    ".type _FUN_06018834, @function\n"
    "_FUN_06018834:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0xEA08\n"  /* mov #8,r10 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDB27\n"  /* mov.l @(0x9C,PC),r11  {[0x060188E4] = 0x0605D1FC} */
    ".word 0xDC28\n"  /* mov.l @(0xA0,PC),r12  {[0x060188E8] = 0x06085FD0} */
    ".word 0xDE28\n"  /* mov.l @(0xA0,PC),r14  {[0x060188EC] = 0x060D6900} */
    ".word 0xDD29\n"  /* mov.l @(0xA4,PC),r13  {[0x060188F0] = 0x06027630} */
    ".word 0x9645\n"  /* mov.w @(0x8A,PC),r6 */
    ".word 0xD929\n"  /* mov.l @(0xA4,PC),r9  {[0x060188F4] = 0x00200000} */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x060188F8] = 0x060D5840} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x9641\n"  /* mov.w @(0x82,PC),r6 */
    ".word 0x953F\n"  /* mov.w @(0x7E,PC),r5 */
    ".word 0xD428\n"  /* mov.l @(0xA0,PC),r4  {[0x060188FC] = 0x060C6000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0xD627\n"  /* mov.l @(0x9C,PC),r6  {[0x06018900] = 0x0000BD00} */
    ".word 0xD528\n"  /* mov.l @(0xA0,PC),r5  {[0x06018904] = 0x000086C8} */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xD627\n"  /* mov.l @(0x9C,PC),r6  {[0x06018908] = 0x00019000} */
    ".word 0xD927\n"  /* mov.l @(0x9C,PC),r9  {[0x0601890C] = 0x00240000} */
    ".word 0xD428\n"  /* mov.l @(0xA0,PC),r4  {[0x06018910] = 0x060A6000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x9633\n"  /* mov.w @(0x66,PC),r6 */
    ".word 0xD527\n"  /* mov.l @(0x9C,PC),r5  {[0x06018914] = 0x0001C0B8} */
    ".word 0xD427\n"  /* mov.l @(0x9C,PC),r4  {[0x06018918] = 0x060BF000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x962F\n"  /* mov.w @(0x5E,PC),r6 */
    ".word 0xD526\n"  /* mov.l @(0x98,PC),r5  {[0x0601891C] = 0x000180B8} */
    ".word 0xD427\n"  /* mov.l @(0x9C,PC),r4  {[0x06018920] = 0x060C2000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x9629\n"  /* mov.w @(0x52,PC),r6 */
    ".word 0xD526\n"  /* mov.l @(0x98,PC),r5  {[0x06018924] = 0x0001DFE8} */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x06018928] = 0x002F8000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x35A3\n"  /* cmp/ge r10,r5 */
    ".word 0x8FEC\n"  /* bf/s 0x06018898 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x0601892C] = 0x0607EAD8} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06018930] = 0x06012E08} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06018934] = 0x06023290} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0CC8\n"  /* .word 0x0CC8 */
    ".word 0x7A00\n"  /* add #0,r10 */
    ".word 0x3000\n"  /* cmp/eq r0,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD1FC\n"  /* mov.l @(0x3F0,PC),r1  {[0x06018CD8] = 0x0607EB84} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FD0\n"  /* mov.l @(0x0,r13),r15 */
    ".word 0x060D\n"  /* mov.w @(r0,r0),r6 */
    ".word 0x6900\n"  /* mov.b @r0,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7630\n"  /* add #48,r6 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060D\n"  /* mov.w @(r0,r0),r6 */
    ".word 0x5840\n"  /* mov.l @(0x0,r4),r8 */
    ".word 0x060C\n"  /* mov.b @(r0,r0),r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xBD00\n"  /* bsr 0x06018306 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x86C8\n"  /* .word 0x86C8 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x9000\n"  /* mov.w @(0x0,PC),r0 */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xC0B8\n"  /* mov.b r0,@(0xB8,GBR) */
    ".word 0x060B\n"  /* .word 0x060B */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x80B8\n"  /* mov.b r0,@(0x8,r11) */
    ".word 0x060C\n"  /* mov.b @(r0,r0),r6 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xDFE8\n"  /* mov.l @(0x3A0,PC),r15  {[0x06018CC8] = 0x0607EBE4} */
    ".word 0x002F\n"  /* mac.l @r2+,@r0+ */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06012E08 */
    ".word 0x2E08\n"  /* tst r0,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06023290 */
    ".word 0x3290\n"  /* cmp/eq r9,r2 */
    ".size _FUN_06018834, .-_FUN_06018834\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06018938\n"
    ".type _FUN_06018938, @function\n"
    "_FUN_06018938:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0xEA08\n"  /* mov #8,r10 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDB26\n"  /* mov.l @(0x98,PC),r11  {[0x060189E4] = 0x0605D21C} */
    ".word 0xDC27\n"  /* mov.l @(0x9C,PC),r12  {[0x060189E8] = 0x06085FD0} */
    ".word 0xDE27\n"  /* mov.l @(0x9C,PC),r14  {[0x060189EC] = 0x060D6900} */
    ".word 0xDD28\n"  /* mov.l @(0xA0,PC),r13  {[0x060189F0] = 0x06027630} */
    ".word 0x9645\n"  /* mov.w @(0x8A,PC),r6 */
    ".word 0xD928\n"  /* mov.l @(0xA0,PC),r9  {[0x060189F4] = 0x00200000} */
    ".word 0xD428\n"  /* mov.l @(0xA0,PC),r4  {[0x060189F8] = 0x060D5840} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0xD628\n"  /* mov.l @(0xA0,PC),r6  {[0x060189FC] = 0x0000F800} */
    ".word 0x953F\n"  /* mov.w @(0x7E,PC),r5 */
    ".word 0xD428\n"  /* mov.l @(0xA0,PC),r4  {[0x06018A00] = 0x060C6000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0xD627\n"  /* mov.l @(0x9C,PC),r6  {[0x06018A04] = 0x00017A00} */
    ".word 0xD528\n"  /* mov.l @(0xA0,PC),r5  {[0x06018A08] = 0x000108A0} */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xD627\n"  /* mov.l @(0x9C,PC),r6  {[0x06018A0C] = 0x00019000} */
    ".word 0xD927\n"  /* mov.l @(0x9C,PC),r9  {[0x06018A10] = 0x00240000} */
    ".word 0xD428\n"  /* mov.l @(0xA0,PC),r4  {[0x06018A14] = 0x060A6000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x9632\n"  /* mov.w @(0x64,PC),r6 */
    ".word 0xD527\n"  /* mov.l @(0x9C,PC),r5  {[0x06018A18] = 0x0001C598} */
    ".word 0xD427\n"  /* mov.l @(0x9C,PC),r4  {[0x06018A1C] = 0x060BF000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x962E\n"  /* mov.w @(0x5C,PC),r6 */
    ".word 0xD526\n"  /* mov.l @(0x98,PC),r5  {[0x06018A20] = 0x00018598} */
    ".word 0xD427\n"  /* mov.l @(0x9C,PC),r4  {[0x06018A24] = 0x060C2000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x9628\n"  /* mov.w @(0x50,PC),r6 */
    ".word 0xD526\n"  /* mov.l @(0x98,PC),r5  {[0x06018A28] = 0x0001EEA0} */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x06018A2C] = 0x002F8000} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x35A3\n"  /* cmp/ge r10,r5 */
    ".word 0x8FEC\n"  /* bf/s 0x0601899C */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x06018A30] = 0x0607EAD8} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06018A34] = 0x06012E08} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06018A38] = 0x06023574} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x10A0\n"  /* mov.l r10,@(0x0,r0) */
    ".word 0x3000\n"  /* cmp/eq r0,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x06018A58] = 0x33238F0D} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FD0\n"  /* mov.l @(0x0,r13),r15 */
    ".word 0x060D\n"  /* mov.w @(r0,r0),r6 */
    ".word 0x6900\n"  /* mov.b @r0,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7630\n"  /* add #48,r6 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060D\n"  /* mov.w @(r0,r0),r6 */
    ".word 0x5840\n"  /* mov.l @(0x0,r4),r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF800\n"  /* .word 0xF800 */
    ".word 0x060C\n"  /* mov.b @(r0,r0),r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x7A00\n"  /* add #0,r10 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x08A0\n"  /* .word 0x08A0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x9000\n"  /* mov.w @(0x0,PC),r0 */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xC598\n"  /* mov.w @(0x130,GBR),r0 */
    ".word 0x060B\n"  /* .word 0x060B */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x8598\n"  /* mov.w @(0x10,r9),r0 */
    ".word 0x060C\n"  /* mov.b @(r0,r0),r6 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xEEA0\n"  /* mov #-96,r14 */
    ".word 0x002F\n"  /* mac.l @r2+,@r0+ */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06012E08 */
    ".word 0x2E08\n"  /* tst r0,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06023574 */
    ".word 0x3574\n"  /* .word 0x3574 */
    ".size _FUN_06018938, .-_FUN_06018938\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06018E22\n"
    ".type _FUN_06018E22, @function\n"
    "_FUN_06018E22:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8035\n"  /* mov.b r0,@(0x5,r3) */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x06018E48] = 0x06034DEA} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06034D1C */
    ".word 0x4D1C\n"  /* .word 0x4D1C */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06034DEA */
    ".word 0x4DEA\n"  /* .word 0x4DEA */
    ".size _FUN_06018E22, .-_FUN_06018E22\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06018E4C\n"
    ".type _FUN_06018E4C, @function\n"
    "_FUN_06018E4C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE403\n"  /* mov #3,r4 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x7FEC\n"  /* add #-20,r15 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x1242\n"  /* mov.l r4,@(0x8,r2) */
    ".word 0x921F\n"  /* mov.w @(0x3E,PC),r2 */
    ".word 0x0324\n"  /* mov.b r2,@(r0,r3) */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06018EA4] = 0x06034D1C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".size _FUN_06018E4C, .-_FUN_06018E4C\n"
);
/* FUN_06018E88: moved to cd_command.c */
__asm__(
    ".balign 4\n"
    ".global _FUN_06018FA8\n"
    ".type _FUN_06018FA8, @function\n"
    "_FUN_06018FA8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE0D\n"  /* mov.l @(0x34,PC),r14  {[0x06018FE0] = 0x0601D5F4} */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x06018FE4] = 0x06086050} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x06018FE8] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x06018FEC] = 0xAE0005FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xB194\n"  /* bsr 0x060192E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06018FE4] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B05\n"  /* bf 0x06018FD4 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06018FF0] = 0x06012EDC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06018FF4] = 0x25A02DBE} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x06018FE8] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x060193B4] = 0x9607D50D} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0xAE00\n"  /* bra 0x06018BEC */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0xAE00\n"  /* bra 0x06018BF0 */
    ".word 0x05FF\n"  /* mac.l @r15+,@r5+ */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2EDC\n"  /* .word 0x2EDC */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2DBE\n"  /* mulu.w r11,r13 */
    ".size _FUN_06018FA8, .-_FUN_06018FA8\n"
);
/* FUN_06018FFC: moved to sound_init.c */
__asm__(
    ".balign 4\n"
    ".global _FUN_0601905C\n"
    ".type _FUN_0601905C, @function\n"
    "_FUN_0601905C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE0F\n"  /* mov.l @(0x3C,PC),r14  {[0x0601909C] = 0x0601D5F4} */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x060190A0] = 0x06086050} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD50F\n"  /* mov.l @(0x3C,PC),r5  {[0x060190A4] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD50F\n"  /* mov.l @(0x3C,PC),r5  {[0x060190A8] = 0xAE0005FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xB13A\n"  /* bsr 0x060192E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x060190A0] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B05\n"  /* bf 0x06019088 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x060190AC] = 0x06012F10} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x060190B0] = 0x25A02DBE} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD506\n"  /* mov.l @(0x18,PC),r5  {[0x060190A4] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD509\n"  /* mov.l @(0x24,PC),r5  {[0x060190B4] = 0xAE0600FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06019470] = 0xE6006563} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0xAE00\n"  /* bra 0x06018CA8 */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0xAE00\n"  /* bra 0x06018CAC */
    ".word 0x05FF\n"  /* mac.l @r15+,@r5+ */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2F10\n"  /* mov.b r1,@r15 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2DBE\n"  /* mulu.w r11,r13 */
    ".word 0xAE06\n"  /* bra 0x06018CC4 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".size _FUN_0601905C, .-_FUN_0601905C\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060190BC\n"
    ".type _FUN_060190BC, @function\n"
    "_FUN_060190BC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE1C\n"  /* mov.l @(0x70,PC),r14  {[0x06019130] = 0x0601D5F4} */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x06019134] = 0x06086050} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x06019138] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x0601913C] = 0xAE0005FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xB10A\n"  /* bsr 0x060192E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x06019134] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B05\n"  /* bf 0x060190E8 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06019140] = 0x06012F20} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06019144] = 0x25A02DBE} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD513\n"  /* mov.l @(0x4C,PC),r5  {[0x06019138] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_060190BC, .-_FUN_060190BC\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060190F8\n"
    ".type _FUN_060190F8, @function\n"
    "_FUN_060190F8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE0D\n"  /* mov.l @(0x34,PC),r14  {[0x06019130] = 0x0601D5F4} */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x06019134] = 0x06086050} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x06019138] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x0601913C] = 0xAE0005FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xB0EC\n"  /* bsr 0x060192E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06019134] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B05\n"  /* bf 0x06019124 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06019148] = 0x06012F50} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06019144] = 0x25A02DBE} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x06019138] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06019504] = 0x0000A000} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0xAE00\n"  /* bra 0x06018D3C */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0xAE00\n"  /* bra 0x06018D40 */
    ".word 0x05FF\n"  /* mac.l @r15+,@r5+ */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2F20\n"  /* mov.b r2,@r15 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2DBE\n"  /* mulu.w r11,r13 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2F50\n"  /* mov.b r5,@r15 */
    ".size _FUN_060190F8, .-_FUN_060190F8\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06019150\n"
    ".type _FUN_06019150, @function\n"
    "_FUN_06019150:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE1C\n"  /* mov.l @(0x70,PC),r14  {[0x060191C4] = 0x0601D5F4} */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x060191C8] = 0x06086050} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x060191CC] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x060191D0] = 0xAE0005FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xB0C0\n"  /* bsr 0x060192E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x060191C8] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B05\n"  /* bf 0x0601917C */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x060191D4] = 0x06012F58} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x060191D8] = 0x25A02DBE} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD513\n"  /* mov.l @(0x4C,PC),r5  {[0x060191CC] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06019150, .-_FUN_06019150\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601918C\n"
    ".type _FUN_0601918C, @function\n"
    "_FUN_0601918C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE0D\n"  /* mov.l @(0x34,PC),r14  {[0x060191C4] = 0x0601D5F4} */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x060191C8] = 0x06086050} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x060191CC] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x060191D0] = 0xAE0005FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xB0A2\n"  /* bsr 0x060192E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x060191C8] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B05\n"  /* bf 0x060191B8 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x060191DC] = 0x06012F60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x060191D8] = 0x25A02DBE} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x060191CC] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06019598] = 0xE2043123} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0xAE00\n"  /* bra 0x06018DD0 */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0xAE00\n"  /* bra 0x06018DD4 */
    ".word 0x05FF\n"  /* mac.l @r15+,@r5+ */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2F58\n"  /* tst r5,r15 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2DBE\n"  /* mulu.w r11,r13 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2F60\n"  /* mov.b r6,@r15 */
    ".size _FUN_0601918C, .-_FUN_0601918C\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060191E4\n"
    ".type _FUN_060191E4, @function\n"
    "_FUN_060191E4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE0F\n"  /* mov.l @(0x3C,PC),r14  {[0x06019224] = 0x0601D5F4} */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x06019228] = 0x06086050} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD50F\n"  /* mov.l @(0x3C,PC),r5  {[0x0601922C] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD50F\n"  /* mov.l @(0x3C,PC),r5  {[0x06019230] = 0xAE0005FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xB076\n"  /* bsr 0x060192E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x06019228] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B08\n"  /* bf 0x06019216 */
    ".word 0xD60B\n"  /* mov.l @(0x2C,PC),r6  {[0x06019234] = 0x0006D000} */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x06019238] = 0x00200000} */
    ".word 0xD40C\n"  /* mov.l @(0x30,PC),r4  {[0x0601923C] = 0x25A03000} */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06019240] = 0x0602760C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x06019244] = 0x25A02DBE} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x0601922C] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x060195F8] = 0x1F628461} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0xAE00\n"  /* bra 0x06018E30 */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0xAE00\n"  /* bra 0x06018E34 */
    ".word 0x05FF\n"  /* mac.l @r15+,@r5+ */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x06019238] = 0x00200000} */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x3000\n"  /* cmp/eq r0,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x760C\n"  /* add #12,r6 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2DBE\n"  /* mulu.w r11,r13 */
    ".size _FUN_060191E4, .-_FUN_060191E4\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601924C\n"
    ".type _FUN_0601924C, @function\n"
    "_FUN_0601924C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE10\n"  /* mov.l @(0x40,PC),r14  {[0x06019290] = 0x0601D5F4} */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x06019294] = 0x06086050} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD510\n"  /* mov.l @(0x40,PC),r5  {[0x06019298] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD510\n"  /* mov.l @(0x40,PC),r5  {[0x0601929C] = 0xAE0005FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xB042\n"  /* bsr 0x060192E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06019294] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B08\n"  /* bf 0x0601927E */
    ".word 0xD60C\n"  /* mov.l @(0x30,PC),r6  {[0x060192A0] = 0x0006D000} */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x060192A4] = 0x0026D000} */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x060192A8] = 0x25A03000} */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x060192AC] = 0x0602760C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x060192B0] = 0x25A02DBE} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD506\n"  /* mov.l @(0x18,PC),r5  {[0x06019298] = 0xAE0001FF} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06019664] = 0x45084508} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0xAE00\n"  /* bra 0x06018E9C */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0xAE00\n"  /* bra 0x06018EA0 */
    ".word 0x05FF\n"  /* mac.l @r15+,@r5+ */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x060192A4] = 0x0026D000} */
    ".word 0x0026\n"  /* mov.l r2,@(r0,r0) */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x060192A8] = 0x25A03000} */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x3000\n"  /* cmp/eq r0,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x760C\n"  /* add #12,r6 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2DBE\n"  /* mulu.w r11,r13 */
    ".global _FUN_060192b4\n"
    "_FUN_060192b4:\n"
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xD611\n"  /* mov.l @(0x44,PC),r6  {[0x060192FC] = 0x25A00000} */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x06019300] = 0x0007FFFF} */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x625E\n"  /* exts.b r5,r2 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8FFA\n"  /* bf/s 0x060192BA */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".size _FUN_0601924C, .-_FUN_0601924C\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060192CC\n"
    ".type _FUN_060192CC, @function\n"
    "_FUN_060192CC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE0C\n"  /* mov.l @(0x30,PC),r14  {[0x06019304] = 0x0601D5F4} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE403\n"  /* mov #3,r4 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".global _FUN_060192e8\n"
    "_FUN_060192e8:\n"
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x06019308] = 0x06086050} */
    ".word 0xD708\n"  /* mov.l @(0x20,PC),r7  {[0x0601930C] = 0x25A02DBE} */
    ".word 0xD608\n"  /* mov.l @(0x20,PC),r6  {[0x06019310] = 0x0000FFFF} */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x06019314] = 0x000186A0} */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8B10\n"  /* bf 0x06019318 */
    ".word 0xA013\n"  /* bra 0x06019320 */
    ".word 0x2152\n"  /* mov.l r5,@r1 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x060196D8] = 0xD229373C} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2DBE\n"  /* mulu.w r11,r13 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x86A0\n"  /* .word 0x86A0 */
    ".word 0x6271\n"  /* mov.w @r7,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3260\n"  /* cmp/eq r6,r2 */
    ".word 0x8BE8\n"  /* bf 0x060192F2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".size _FUN_060192CC, .-_FUN_060192CC\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601935E\n"
    ".type _FUN_0601935E, @function\n"
    "_FUN_0601935E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD406\n"  /* mov.l @(0x18,PC),r4  {[0x0601937C] = 0x0605B6D8} */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06019384] = 0x80000000} */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06019388] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06019388] = 0x06026CE0} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038BD4 */
    ".word 0x8BD4\n"  /* bf 0x06019326 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0601A132 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".size _FUN_0601935E, .-_FUN_0601935E\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_060193FE\n"
    ".type _FUN_060193FE, @function\n"
    "_FUN_060193FE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD22B\n"  /* mov.l @(0xAC,PC),r2  {[0x060194B0] = 0x06085FF0} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0xD22A\n"  /* mov.l @(0xA8,PC),r2  {[0x060194B4] = 0x0605D245} */
    ".word 0x2240\n"  /* mov.b r4,@r2 */
    ".word 0xD22A\n"  /* mov.l @(0xA8,PC),r2  {[0x060194B8] = 0x06085FF1} */
    ".word 0x2200\n"  /* mov.b r0,@r2 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0xD22A\n"  /* mov.l @(0xA8,PC),r2  {[0x060194BC] = 0x06085FF2} */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x2200\n"  /* mov.b r0,@r2 */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x060194C0] = 0x06085FF3} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x060194C4] = 0x06085FF5} */
    ".word 0x2240\n"  /* mov.b r4,@r2 */
    ".word 0xD529\n"  /* mov.l @(0xA4,PC),r5  {[0x060194C8] = 0xAE0003FF} */
    ".word 0xD22A\n"  /* mov.l @(0xA8,PC),r2  {[0x060194CC] = 0x0601D5F4} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xDE29\n"  /* mov.l @(0xA4,PC),r14  {[0x060194D0] = 0x0605B6D8} */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x060194D4] = 0x80000000} */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x060194D8] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x060194D8] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xBFA6\n"  /* bsr 0x0601938C */
    ".word 0x0009\n"  /* nop */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x060194DC] = 0x0601A73E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE709\n"  /* mov #9,r7 */
    ".word 0xD525\n"  /* mov.l @(0x94,PC),r5  {[0x060194E0] = 0x00014000} */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x060194E4] = 0x25E76174} */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x060194E8] = 0x0600511E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xE708\n"  /* mov #8,r7 */
    ".word 0xD525\n"  /* mov.l @(0x94,PC),r5  {[0x060194EC] = 0x00017700} */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x060194F0] = 0x25E761FC} */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x060194E8] = 0x0600511E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xDD24\n"  /* mov.l @(0x90,PC),r13  {[0x060194F4] = 0x06014884} */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE410\n"  /* mov #16,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x060194F8] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x060194F8] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x060194FC] = 0x06028560} */
    ".word 0xCB04\n"  /* or #0x04,r0 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2E02\n"  /* mov.l r0,@r14 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x06019500] = 0x06063AF8} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x06019504] = 0x0000A000} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06019508] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xAF3A\n"  /* bra 0x06019324 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF0\n"  /* mov.l @(0x0,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD245\n"  /* mov.l @(0x114,PC),r2  {[0x060195CC] = 0x06085FF5} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF1\n"  /* mov.l @(0x4,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF2\n"  /* mov.l @(0x8,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF3\n"  /* mov.l @(0xC,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF5\n"  /* mov.l @(0x14,r15),r15 */
    ".word 0xAE00\n"  /* bra 0x060190CC */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x060198A0] = 0x000B0009} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0601A286 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0xA73E\n"  /* bra 0x0601A35E */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x6174\n"  /* mov.b @r7+,r1 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x511E\n"  /* mov.l @(0x38,r1),r1 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x61FC\n"  /* extu.b r15,r1 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014884 */
    ".word 0x4884\n"  /* .word 0x4884 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3AF8\n"  /* sub r15,r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xA000\n"  /* bra 0x0601950A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".size _FUN_060193FE, .-_FUN_060193FE\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060196B0\n"
    ".type _FUN_060196B0, @function\n"
    "_FUN_060196B0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xDA2C\n"  /* mov.l @(0xB0,PC),r10  {[0x06019768] = 0x06085FF1} */
    ".word 0xDC2D\n"  /* mov.l @(0xB4,PC),r12  {[0x0601976C] = 0x0605D242} */
    ".word 0xDE2D\n"  /* mov.l @(0xB4,PC),r14  {[0x06019770] = 0x0605D244} */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x06019774] = 0x06026110} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xED01\n"  /* mov #1,r13 */
    ".word 0xD42D\n"  /* mov.l @(0xB4,PC),r4  {[0x06019778] = 0x06063D98} */
    ".word 0x934E\n"  /* mov.w @(0x9C,PC),r3 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8933\n"  /* bt 0x06019738 */
    ".word 0x67E0\n"  /* mov.b @r14,r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x1F72\n"  /* mov.l r7,@(0x8,r15) */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0601977C] = 0x06049AF4} */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x06019780] = 0x06063750} */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6771\n"  /* mov.w @r7,r7 */
    ".word 0x677D\n"  /* extu.w r7,r7 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x372C\n"  /* add r2,r7 */
    ".word 0x1F71\n"  /* mov.l r7,@(0x4,r15) */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x933B\n"  /* mov.w @(0x76,PC),r3 */
    ".word 0x56F2\n"  /* mov.l @(0x8,r15),r6 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x06019784] = 0x06049AEC} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0x8461\n"  /* mov.b @(0x1,r6),r0 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x362C\n"  /* add r2,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x06019788] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x32D7\n"  /* cmp/gt r13,r2 */
    ".word 0x8B01\n"  /* bf 0x06019720 */
    ".word 0x62BE\n"  /* exts.b r11,r2 */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0601978C] = 0x06059F44} */
    ".word 0x23B2\n"  /* mov.l r11,@r3 */
    ".word 0x62BC\n"  /* extu.b r11,r2 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0xE304\n"  /* mov #4,r3 */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x06019790] = 0x0605AD10} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x63DE\n"  /* exts.b r13,r3 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06019794] = 0x06085FF5} */
    ".word 0xA056\n"  /* bra 0x060197E4 */
    ".word 0x23D0\n"  /* mov.b r13,@r3 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x9313\n"  /* mov.w @(0x26,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8D28\n"  /* bt/s 0x06019798 */
    ".word 0xE505\n"  /* mov #5,r5 */
    ".word 0x2AD0\n"  /* mov.b r13,@r10 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x2C50\n"  /* mov.b r5,@r12 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0x63E0\n"  /* mov.b @r14,r3 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B2F\n"  /* bf 0x060197BC */
    ".word 0x62BE\n"  /* exts.b r11,r2 */
    ".word 0xA02D\n"  /* bra 0x060197BC */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF1\n"  /* mov.l @(0x4,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD242\n"  /* mov.l @(0x108,PC),r2  {[0x06019878] = 0x06059F44} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD244\n"  /* mov.l @(0x110,PC),r2  {[0x06019884] = 0x0605D244} */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026110 */
    ".word 0x6110\n"  /* mov.b @r1,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x9AF4\n"  /* mov.w @(0x1E8,PC),r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x9AEC\n"  /* mov.w @(0x1D8,PC),r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x060191B6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF5\n"  /* mov.l @(0x14,r15),r15 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x9363\n"  /* mov.w @(0xC6,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x890A\n"  /* bt 0x060197BC */
    ".word 0x2AD0\n"  /* mov.b r13,@r10 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x2C50\n"  /* mov.b r5,@r12 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0x63E0\n"  /* mov.b @r14,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8901\n"  /* bt 0x060197BC */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x2E30\n"  /* mov.b r3,@r14 */
    ".word 0xD42B\n"  /* mov.l @(0xAC,PC),r4  {[0x0601986C] = 0x0605D243} */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x63C0\n"  /* mov.b @r12,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2C30\n"  /* mov.b r3,@r12 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x06019870] = 0x0605D250} */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x422B\n"  /* jmp @r2 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_060196B0, .-_FUN_060196B0\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_060197F4\n"
    ".type _FUN_060197F4, @function\n"
    "_FUN_060197F4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06019874] = 0x06063D9A} */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x9333\n"  /* mov.w @(0x66,PC),r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x894A\n"  /* bt 0x0601989C */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06019878] = 0x06059F44} */
    ".word 0x2352\n"  /* mov.l r5,@r3 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0601987C] = 0x0605D242} */
    ".word 0x2350\n"  /* mov.b r5,@r3 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06019880] = 0x0605AD10} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xD71B\n"  /* mov.l @(0x6C,PC),r7  {[0x06019884] = 0x0605D244} */
    ".word 0x6770\n"  /* mov.b @r7,r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x1F72\n"  /* mov.l r7,@(0x8,r15) */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x06019888] = 0x06049AF4} */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6771\n"  /* mov.w @r7,r7 */
    ".word 0x677D\n"  /* extu.w r7,r7 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0601988C] = 0x06063750} */
    ".word 0x372C\n"  /* add r2,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x931A\n"  /* mov.w @(0x34,PC),r3 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x56F2\n"  /* mov.l @(0x8,r15),r6 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06019890] = 0x06049AEC} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x1F61\n"  /* mov.l r6,@(0x4,r15) */
    ".word 0x8461\n"  /* mov.b @(0x1,r6),r0 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06019894] = 0x06028400} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x362C\n"  /* add r2,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06019898] = 0x06026CE0} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD243\n"  /* mov.l @(0x10C,PC),r2  {[0x0601997C] = 0x7E0162EC} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD250\n"  /* mov.l @(0x140,PC),r2  {[0x060199B4] = 0xD7224500} */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD242\n"  /* mov.l @(0x108,PC),r2  {[0x06019988] = 0x60E065E0} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x060192A6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD244\n"  /* mov.l @(0x110,PC),r2  {[0x06019998] = 0x63F26503} */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x9AF4\n"  /* mov.w @(0x1E8,PC),r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x9AEC\n"  /* mov.w @(0x1D8,PC),r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x060198D4] = 0x06078663} */
    ".word 0x2240\n"  /* mov.b r4,@r2 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x060198D8] = 0x0605AA98} */
    ".word 0x2242\n"  /* mov.l r4,@r2 */
    ".word 0x644E\n"  /* exts.b r4,r4 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x060198DC] = 0x06085FF4} */
    ".word 0x2240\n"  /* mov.b r4,@r2 */
    ".word 0xAF9E\n"  /* bra 0x060197F4 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD206\n"  /* mov.l @(0x18,PC),r2  {[0x060198D4] = 0x06078663} */
    ".word 0x2240\n"  /* mov.b r4,@r2 */
    ".word 0xD206\n"  /* mov.l @(0x18,PC),r2  {[0x060198D8] = 0x0605AA98} */
    ".word 0x2242\n"  /* mov.l r4,@r2 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x060198DC] = 0x06085FF4} */
    ".word 0x2210\n"  /* mov.b r1,@r2 */
    ".word 0xAF94\n"  /* bra 0x060197F4 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xAF92\n"  /* bra 0x060197F4 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xAF90\n"  /* bra 0x060197F4 */
    ".word 0xE40A\n"  /* mov #10,r4 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8663\n"  /* .word 0x8663 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAA98\n"  /* bra 0x06018E0E */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".size _FUN_060197F4, .-_FUN_060197F4\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06019D14\n"
    ".type _FUN_06019D14, @function\n"
    "_FUN_06019D14:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0xDE23\n"  /* mov.l @(0x8C,PC),r14  {[0x06019DA8] = 0x0605AD00} */
    ".word 0xD624\n"  /* mov.l @(0x90,PC),r6  {[0x06019DAC] = 0x00008000} */
    ".word 0xD524\n"  /* mov.l @(0x90,PC),r5  {[0x06019DB0] = 0x06063D98} */
    ".word 0xD425\n"  /* mov.l @(0x94,PC),r4  {[0x06019DB4] = 0x0605D243} */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2369\n"  /* and r6,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8D06\n"  /* bt/s 0x06019D3A */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62DE\n"  /* exts.b r13,r2 */
    ".word 0xA029\n"  /* bra 0x06019D8C */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x9734\n"  /* mov.w @(0x68,PC),r7 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8905\n"  /* bt 0x06019D54 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62DE\n"  /* exts.b r13,r2 */
    ".word 0xA01C\n"  /* bra 0x06019D8C */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x6251\n"  /* mov.w @r5,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8909\n"  /* bt 0x06019D72 */
    ".word 0x6040\n"  /* mov.b @r4,r0 */
    ".word 0x8819\n"  /* cmp/eq #25,r0 */
    ".word 0x8B13\n"  /* bf 0x06019D8C */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x63DE\n"  /* exts.b r13,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0xA00D\n"  /* bra 0x06019D8C */
    ".word 0x0009\n"  /* nop */
    ".word 0x6251\n"  /* mov.w @r5,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8907\n"  /* bt 0x06019D8C */
    ".word 0x6040\n"  /* mov.b @r4,r0 */
    ".word 0x8819\n"  /* cmp/eq #25,r0 */
    ".word 0x8B04\n"  /* bf 0x06019D8C */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x63DE\n"  /* exts.b r13,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B00\n"  /* bf 0x06019D96 */
    ".word 0x2ED2\n"  /* mov.l r13,@r14 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8901\n"  /* bt 0x06019DA0 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xAF11\n"  /* bra 0x06019BC8 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD00\n"  /* bra 0x060197AE */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD243\n"  /* mov.l @(0x10C,PC),r2  {[0x06019EC4] = 0x46084608} */
    ".size _FUN_06019D14, .-_FUN_06019D14\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06019EF0\n"
    ".type _FUN_06019EF0, @function\n"
    "_FUN_06019EF0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xDD15\n"  /* mov.l @(0x54,PC),r13  {[0x06019F4C] = 0x06063D98} */
    ".word 0xDE15\n"  /* mov.l @(0x54,PC),r14  {[0x06019F50] = 0x0605AD0C} */
    ".word 0x60D1\n"  /* mov.w @r13,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8D02\n"  /* bt/s 0x06019F08 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0xA001\n"  /* bra 0x06019F0A */
    ".word 0xE506\n"  /* mov #6,r5 */
    ".word 0xE519\n"  /* mov #25,r5 */
    ".word 0xD712\n"  /* mov.l @(0x48,PC),r7  {[0x06019F54] = 0x00008000} */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x06019F58] = 0x0605D243} */
    ".word 0x85D1\n"  /* mov.w @(0x2,r13),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8905\n"  /* bt 0x06019F26 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62CE\n"  /* exts.b r12,r2 */
    ".word 0xA038\n"  /* bra 0x06019F96 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x960B\n"  /* mov.w @(0x16,PC),r6 */
    ".word 0x85D1\n"  /* mov.w @(0x2,r13),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8913\n"  /* bt 0x06019F5C */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62CE\n"  /* exts.b r12,r2 */
    ".word 0xA02B\n"  /* bra 0x06019F96 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x9B18\n"  /* mov.w @(0x30,PC),r11 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD0C\n"  /* bra 0x0601996E */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD243\n"  /* mov.l @(0x10C,PC),r2  {[0x0601A068] = 0x6ABCE310} */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8909\n"  /* bt 0x06019F7A */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x8B13\n"  /* bf 0x06019F96 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62CE\n"  /* exts.b r12,r2 */
    ".word 0xA00E\n"  /* bra 0x06019F96 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8908\n"  /* bt 0x06019F96 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x8B04\n"  /* bf 0x06019F96 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62CE\n"  /* exts.b r12,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0xE205\n"  /* mov #5,r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B01\n"  /* bf 0x06019FA2 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8900\n"  /* bt 0x06019FAA */
    ".word 0x2EC2\n"  /* mov.l r12,@r14 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xAF03\n"  /* bra 0x06019DB8 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06019EF0, .-_FUN_06019EF0\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601A0F0\n"
    ".type _FUN_0601A0F0, @function\n"
    "_FUN_0601A0F0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xDD28\n"  /* mov.l @(0xA0,PC),r13  {[0x0601A198] = 0x06063D98} */
    ".word 0xDE28\n"  /* mov.l @(0xA0,PC),r14  {[0x0601A19C] = 0x0605AD04} */
    ".word 0x60D1\n"  /* mov.w @r13,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8D02\n"  /* bt/s 0x0601A108 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0xA001\n"  /* bra 0x0601A10A */
    ".word 0xE506\n"  /* mov #6,r5 */
    ".word 0xE519\n"  /* mov #25,r5 */
    ".word 0xD725\n"  /* mov.l @(0x94,PC),r7  {[0x0601A1A0] = 0x00008000} */
    ".word 0xD425\n"  /* mov.l @(0x94,PC),r4  {[0x0601A1A4] = 0x0605D243} */
    ".word 0x85D1\n"  /* mov.w @(0x2,r13),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8905\n"  /* bt 0x0601A126 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62CE\n"  /* exts.b r12,r2 */
    ".word 0xA02A\n"  /* bra 0x0601A17A */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x9636\n"  /* mov.w @(0x6C,PC),r6 */
    ".word 0x85D1\n"  /* mov.w @(0x2,r13),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8905\n"  /* bt 0x0601A140 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62CE\n"  /* exts.b r12,r2 */
    ".word 0xA01D\n"  /* bra 0x0601A17A */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8909\n"  /* bt 0x0601A15E */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x8B13\n"  /* bf 0x0601A17A */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62CE\n"  /* exts.b r12,r2 */
    ".word 0xA00E\n"  /* bra 0x0601A17A */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8908\n"  /* bt 0x0601A17A */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x8B04\n"  /* bf 0x0601A17A */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62CE\n"  /* exts.b r12,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0xE205\n"  /* mov #5,r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0601A186 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8900\n"  /* bt 0x0601A18E */
    ".word 0x2EC2\n"  /* mov.l r12,@r14 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xAF0E\n"  /* bra 0x06019FB2 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD04\n"  /* bra 0x06019BAA */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD243\n"  /* mov.l @(0x10C,PC),r2  {[0x0601A2B4] = 0x4F266DF6} */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0601A240] = 0x06085FF2} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x0601A244] = 0x0605D280} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x0009\n"  /* nop */
    ".size _FUN_0601A0F0, .-_FUN_0601A0F0\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601A1BA\n"
    ".type _FUN_0601A1BA, @function\n"
    "_FUN_0601A1BA:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601A248] = 0x06063D9A} */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x9337\n"  /* mov.w @(0x6E,PC),r3 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8D16\n"  /* bt/s 0x0601A1FE */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x0601A240] = 0x06085FF2} */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x0601A24C] = 0x06085FF3} */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x0601A250] = 0x0605D245} */
    ".word 0x22E0\n"  /* mov.b r14,@r2 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x0601A254] = 0x06059F44} */
    ".word 0x22E2\n"  /* mov.l r14,@r2 */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x0601A258] = 0x0605B6D8} */
    ".word 0xD11B\n"  /* mov.l @(0x6C,PC),r1  {[0x0601A25C] = 0x80000000} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601A260] = 0x06026CE0} */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x221B\n"  /* or r1,r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0601A264] = 0x06085FF1} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0xDD19\n"  /* mov.l @(0x64,PC),r13  {[0x0601A268] = 0x0605D242} */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8936\n"  /* bt 0x0601A278 */
    ".word 0xD718\n"  /* mov.l @(0x60,PC),r7  {[0x0601A26C] = 0x06049E48} */
    ".word 0x9616\n"  /* mov.w @(0x2C,PC),r6 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601A270] = 0x06049AFC} */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6533\n"  /* mov r3,r5 */
    ".word 0x750D\n"  /* add #13,r5 */
    ".word 0x730C\n"  /* add #12,r3 */
    ".word 0x6550\n"  /* mov.b @r5,r5 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x750D\n"  /* add #13,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0601A274] = 0x060284AE} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF2\n"  /* mov.l @(0x8,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD280\n"  /* mov.l @(0x200,PC),r2  {[0x0601A448] = 0x89EFAFF0} */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF3\n"  /* mov.l @(0xC,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD245\n"  /* mov.l @(0x114,PC),r2  {[0x0601A368] = 0xD31B430B} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0601B00E */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF1\n"  /* mov.l @(0x4,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD242\n"  /* mov.l @(0x108,PC),r2  {[0x0601A374] = 0x88108B0B} */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x9E48\n"  /* mov.w @(0x90,PC),r14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x9AFC\n"  /* mov.w @(0x1F8,PC),r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0xD725\n"  /* mov.l @(0x94,PC),r7  {[0x0601A310] = 0x0605D4F0} */
    ".word 0x9648\n"  /* mov.w @(0x90,PC),r6 */
    ".word 0xD225\n"  /* mov.l @(0x94,PC),r2  {[0x0601A314] = 0x06049AFC} */
    ".word 0x6772\n"  /* mov.l @r7,r7 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x750D\n"  /* add #13,r5 */
    ".word 0x730C\n"  /* add #12,r3 */
    ".word 0x6550\n"  /* mov.b @r5,r5 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x750D\n"  /* add #13,r5 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0601A318] = 0x060284AE} */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0xE310\n"  /* mov #16,r3 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B01\n"  /* bf 0x0601A2B2 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x2D30\n"  /* mov.b r3,@r13 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601A1BA, .-_FUN_0601A1BA\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601A2BC\n"
    ".type _FUN_0601A2BC, @function\n"
    "_FUN_0601A2BC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD416\n"  /* mov.l @(0x58,PC),r4  {[0x0601A31C] = 0x0605B6D8} */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0601A320] = 0x80000000} */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0601A324] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0601A324] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDE14\n"  /* mov.l @(0x50,PC),r14  {[0x0601A328] = 0x0602853E} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0601A32C] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE708\n"  /* mov #8,r7 */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x0601A330] = 0x00017700} */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x0601A334] = 0x25E76EFC} */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0601A338] = 0x0600511E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xE709\n"  /* mov #9,r7 */
    ".word 0xD50E\n"  /* mov.l @(0x38,PC),r5  {[0x0601A330] = 0x00017700} */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0601A33C] = 0x25E77B18} */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0601A338] = 0x0600511E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD40F\n"  /* mov.l @(0x3C,PC),r4  {[0x0601A340] = 0x06085FF2} */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD4F0\n"  /* mov.l @(0x3C0,PC),r4  {[0x0601A6D4] = 0x5331373C} */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x9AFC\n"  /* mov.w @(0x1F8,PC),r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0601B0D2 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x6EFC\n"  /* extu.b r15,r14 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x511E\n"  /* mov.l @(0x38,r1),r1 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x7B18\n"  /* add #24,r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF2\n"  /* mov.l @(0x8,r15),r15 */
    ".size _FUN_0601A2BC, .-_FUN_0601A2BC\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601A344\n"
    ".type _FUN_0601A344, @function\n"
    "_FUN_0601A344:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".size _FUN_0601A344, .-_FUN_0601A344\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601A348\n"
    ".type _FUN_0601A348, @function\n"
    "_FUN_0601A348:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDE1C\n"  /* mov.l @(0x70,PC),r14  {[0x0601A3C0] = 0x0602761E} */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601A3C4] = 0x0605CF9C} */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x0601A3C8] = 0x25F00020} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6533\n"  /* mov r3,r5 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x0601A3CC] = 0x25F00620} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0601A3D0] = 0x0605D01C} */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x0601A3D4] = 0x25F00400} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE640\n"  /* mov #64,r6 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0601A3D8] = 0x06019324} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x0601A3DC] = 0x06063D9E} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8810\n"  /* cmp/eq #16,r0 */
    ".word 0x8B0B\n"  /* bf 0x0601A390 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x0601A3E0] = 0x06063C90} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601A3E4] = 0x06028400} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xA00C\n"  /* bra 0x0601A3A8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x0601A3E8] = 0x06063C98} */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0x9310\n"  /* mov.w @(0x20,PC),r3 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0601A3E4] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0601A3EC] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0601A3F0] = 0x06085FF2} */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xCF9C\n"  /* .word 0xCF9C */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0620\n"  /* .word 0x0620 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x0601A444] = 0x89F18804} */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0400\n"  /* .word 0x0400 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06019324 */
    ".word 0x9324\n"  /* mov.w @(0x48,PC),r3 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9E\n"  /* .word 0x3D9E */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3C90\n"  /* cmp/eq r9,r12 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3C98\n"  /* sub r9,r12 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF2\n"  /* mov.l @(0x8,r15),r15 */
    ".size _FUN_0601A348, .-_FUN_0601A348\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601A574\n"
    ".type _FUN_0601A574, @function\n"
    "_FUN_0601A574:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".size _FUN_0601A574, .-_FUN_0601A574\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601A578\n"
    ".type _FUN_0601A578, @function\n"
    "_FUN_0601A578:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0601A60C] = 0x06059F44} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD423\n"  /* mov.l @(0x8C,PC),r4  {[0x0601A610] = 0x0605B6D8} */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x0601A614] = 0x80000000} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0601A618] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601A618] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE709\n"  /* mov #9,r7 */
    ".word 0xD520\n"  /* mov.l @(0x80,PC),r5  {[0x0601A61C] = 0x00014000} */
    ".word 0xD421\n"  /* mov.l @(0x84,PC),r4  {[0x0601A620] = 0x25E76174} */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601A624] = 0x0600511E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0xE708\n"  /* mov #8,r7 */
    ".word 0xD520\n"  /* mov.l @(0x80,PC),r5  {[0x0601A628] = 0x00017700} */
    ".word 0xD421\n"  /* mov.l @(0x84,PC),r4  {[0x0601A62C] = 0x25E761FC} */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0601A624] = 0x0600511E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x0601A630] = 0x06063AF8} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0601A634] = 0x0000A000} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601A638] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601A63C] = 0x06085FF1} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xB9AC\n"  /* bsr 0x06019928 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB045\n"  /* bsr 0x0601A65E */
    ".word 0x0009\n"  /* nop */
    ".word 0xB11A\n"  /* bsr 0x0601A80C */
    ".word 0x0009\n"  /* nop */
    ".word 0xB1B2\n"  /* bsr 0x0601A940 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601A640] = 0x06085FF2} */
    ".word 0x23E0\n"  /* mov.b r14,@r3 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601A644] = 0x06085FF3} */
    ".word 0x23E0\n"  /* mov.b r14,@r3 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601A648] = 0x0605D245} */
    ".word 0x23E0\n"  /* mov.b r14,@r3 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601A64C] = 0x06019324} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0601A650] = 0x0601938C} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".global _FUN_0601a5f8\n"
    "_FUN_0601a5f8:\n"
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x0601A654] = 0x06063D9E} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8810\n"  /* cmp/eq #16,r0 */
    ".word 0x8B2A\n"  /* bf 0x0601A658 */
    ".word 0x9001\n"  /* mov.w @(0x2,PC),r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0601B3C6 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x6174\n"  /* mov.b @r7+,r1 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x511E\n"  /* mov.l @(0x38,r1),r1 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x61FC\n"  /* extu.b r15,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3AF8\n"  /* sub r15,r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xA000\n"  /* bra 0x0601A63A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF1\n"  /* mov.l @(0x4,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF2\n"  /* mov.l @(0x8,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF3\n"  /* mov.l @(0xC,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD245\n"  /* mov.l @(0x114,PC),r2  {[0x0601A760] = 0x0605D241} */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06019324 */
    ".word 0x9324\n"  /* mov.w @(0x48,PC),r3 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601938C */
    ".word 0x938C\n"  /* mov.w @(0x118,PC),r3 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9E\n"  /* .word 0x3D9E */
    ".word 0x9040\n"  /* mov.w @(0x80,PC),r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".size _FUN_0601A578, .-_FUN_0601A578\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601A770\n"
    ".type _FUN_0601A770, @function\n"
    "_FUN_0601A770:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x0601A7E4] = 0x06085FF6} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8908\n"  /* bt 0x0601A78E */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0601A7E8] = 0x06012EC4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0601A7EC] = 0x06012F00} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0601A7E4] = 0x06085FF6} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0601A7F0] = 0x06085FF7} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8905\n"  /* bt 0x0601A7A2 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0601A7F4] = 0x060191E0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0601A7F0] = 0x06085FF7} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x0601A7F8] = 0xAE0001FF} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0601A7FC] = 0x0601D5F4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".size _FUN_0601A770, .-_FUN_0601A770\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601A7AC\n"
    ".type _FUN_0601A7AC, @function\n"
    "_FUN_0601A7AC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD514\n"  /* mov.l @(0x50,PC),r5  {[0x0601A800] = 0x0605D241} */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x0601A804] = 0x06063D98} */
    ".word 0x9216\n"  /* mov.w @(0x2C,PC),r2 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8903\n"  /* bt 0x0601A7C8 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2530\n"  /* mov.b r3,@r5 */
    ".word 0xA009\n"  /* bra 0x0601A7DA */
    ".word 0x0009\n"  /* nop */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0601A808] = 0x00008000} */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8901\n"  /* bt 0x0601A7DA */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2530\n"  /* mov.b r3,@r5 */
    ".word 0xBF40\n"  /* bsr 0x0601A65E */
    ".word 0x0009\n"  /* nop */
    ".word 0xAFAE\n"  /* bra 0x0601A73E */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF6\n"  /* mov.l @(0x18,r15),r15 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2EC4\n"  /* mov.b r12,@-r14 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2F00\n"  /* mov.b r0,@r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF7\n"  /* mov.l @(0x1C,r15),r15 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_060191E0 */
    ".word 0x91E0\n"  /* mov.w @(0x1C0,PC),r1 */
    ".word 0xAE00\n"  /* bra 0x0601A3FC */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0601ABD0] = 0xD2182240} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD241\n"  /* mov.l @(0x104,PC),r2  {[0x0601A908] = 0x950F4700} */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".size _FUN_0601A7AC, .-_FUN_0601A7AC\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601AAE8\n"
    ".type _FUN_0601AAE8, @function\n"
    "_FUN_0601AAE8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601AB50] = 0x06063D9A} */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x932D\n"  /* mov.w @(0x5A,PC),r3 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8927\n"  /* bt 0x0601AB48 */
    ".word 0xE31E\n"  /* mov #30,r3 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x0601AB54] = 0x0605AD10} */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x604E\n"  /* exts.b r4,r0 */
    ".word 0x635C\n"  /* extu.b r5,r3 */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x0601AB58] = 0x0605E0A2} */
    ".word 0x655E\n"  /* exts.b r5,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x0601AB5C] = 0x06085FF0} */
    ".word 0x2240\n"  /* mov.b r4,@r2 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x0601AB60] = 0x0605D245} */
    ".word 0x2200\n"  /* mov.b r0,@r2 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601AB64] = 0x06085FF1} */
    ".word 0x2350\n"  /* mov.b r5,@r3 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601AB68] = 0x06085FF2} */
    ".word 0x2340\n"  /* mov.b r4,@r3 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601AB6C] = 0x06085FF3} */
    ".word 0x2340\n"  /* mov.b r4,@r3 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601AB70] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x0601AB74] = 0x0605B6D8} */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601AB78] = 0x06028560} */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0xCB04\n"  /* or #0x04,r0 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601AB7C] = 0x0601950C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x0601AB80] = 0xAE0001FF} */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601AB84] = 0x0601D5F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40F\n"  /* mov #15,r4 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601AB88] = 0x06018E70} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0700\n"  /* .word 0x0700 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x0601A57A */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xE0A2\n"  /* mov #-94,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF0\n"  /* mov.l @(0x0,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD245\n"  /* mov.l @(0x114,PC),r2  {[0x0601AC78] = 0x000B0009} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF1\n"  /* mov.l @(0x4,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF2\n"  /* mov.l @(0x8,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF3\n"  /* mov.l @(0xC,r15),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0601B92A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601950C */
    ".word 0x950C\n"  /* mov.w @(0x18,PC),r5 */
    ".word 0xAE00\n"  /* bra 0x0601A784 */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0601AF58] = 0x2230D405} */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06018E70 */
    ".word 0x8E70\n"  /* .word 0x8E70 */
    ".global _FUN_0601ab8c\n"
    "_FUN_0601ab8c:\n"
    ".word 0xD421\n"  /* mov.l @(0x84,PC),r4  {[0x0601AC14] = 0x0607EAD8} */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x0601AC18] = 0x0605DE40} */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0601AC1C] = 0x0605AD00} */
    ".word 0x302C\n"  /* add r2,r0 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x013E\n"  /* mov.l @(r0,r3),r1 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601AC20] = 0x06086004} */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601AC24] = 0x0607EAE0} */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0601AC28] = 0x0605DE24} */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0x5141\n"  /* mov.l @(0x4,r4),r1 */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x0601AC2C] = 0x06086008} */
    ".word 0x000B\n"  /* rts */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".global _FUN_0601abc6\n"
    "_FUN_0601abc6:\n"
    ".word 0xE400\n"  /* mov #0,r4 */
    ".size _FUN_0601AAE8, .-_FUN_0601AAE8\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601ABC8\n"
    ".type _FUN_0601ABC8, @function\n"
    "_FUN_0601ABC8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0601AC30] = 0x06085FF8} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0601AC34] = 0x06085FF9} */
    ".word 0x2240\n"  /* mov.b r4,@r2 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0601AC38] = 0x06085FFC} */
    ".word 0x2242\n"  /* mov.l r4,@r2 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0601AC3C] = 0x06086000} */
    ".word 0x2242\n"  /* mov.l r4,@r2 */
    ".word 0xB0E8\n"  /* bsr 0x0601ADB0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD40C\n"  /* mov.l @(0x30,PC),r4  {[0x0601AC14] = 0x0607EAD8} */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601AC28] = 0x0605DE24} */
    ".word 0xD516\n"  /* mov.l @(0x58,PC),r5  {[0x0601AC40] = 0x06078638} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8905\n"  /* bt 0x0601AC04 */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B02\n"  /* bf 0x0601AC04 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x0601AC34] = 0x06085FF9} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0601AC44] = 0x0607EBF4} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B1D\n"  /* bf 0x0601AC48 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDE40\n"  /* mov.l @(0x100,PC),r14  {[0x0601AD1C] = 0x4300323C} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD00\n"  /* bra 0x0601A622 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6004\n"  /* mov.b @r0+,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDE24\n"  /* mov.l @(0x90,PC),r14  {[0x0601ACBC] = 0x8D53EE13} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6008\n"  /* swap.b r0,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF8\n"  /* mov.l @(0x20,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF9\n"  /* mov.l @(0x24,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FFC\n"  /* mov.l @(0x30,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8638\n"  /* .word 0x8638 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0xD427\n"  /* mov.l @(0x9C,PC),r4  {[0x0601ACE8] = 0x0607EAD8} */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x0601ACEC] = 0x0605AD00} */
    ".word 0x904A\n"  /* mov.w @(0x94,PC),r0 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x0601ACF0] = 0x0605DD6C} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x0601ACF4] = 0x060786A4} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x034E\n"  /* mov.l @(r0,r4),r3 */
    ".word 0x3232\n"  /* cmp/hs r3,r2 */
    ".word 0x8902\n"  /* bt 0x0601AC76 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601ACF8] = 0x06085FF8} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".size _FUN_0601ABC8, .-_FUN_0601ABC8\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601AC88\n"
    ".type _FUN_0601AC88, @function\n"
    "_FUN_0601AC88:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDD1A\n"  /* mov.l @(0x68,PC),r13  {[0x0601ACF4] = 0x060786A4} */
    ".word 0xD516\n"  /* mov.l @(0x58,PC),r5  {[0x0601ACE8] = 0x0607EAD8} */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x0601ACEC] = 0x0605AD00} */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x6B52\n"  /* mov.l @r5,r11 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601ACF0] = 0x0605DD6C} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4B00\n"  /* shll r11 */
    ".word 0x4B08\n"  /* shll2 r11 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x0601ACFC] = 0x0605DE24} */
    ".word 0x3B2C\n"  /* add r2,r11 */
    ".word 0x6BB2\n"  /* mov.l @r11,r11 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x9015\n"  /* mov.w @(0x2A,PC),r0 */
    ".word 0x024E\n"  /* mov.l @(r0,r4),r2 */
    ".word 0x3322\n"  /* cmp/hs r2,r3 */
    ".word 0x8D53\n"  /* bt/s 0x0601AD66 */
    ".word 0xEE13\n"  /* mov #19,r14 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0601AD00] = 0x0607EBF4} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x894E\n"  /* bt 0x0601AD66 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x61D2\n"  /* mov.l @r13,r1 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x5331\n"  /* mov.l @(0x4,r3),r3 */
    ".word 0x3132\n"  /* cmp/hs r3,r1 */
    ".word 0x8B11\n"  /* bf 0x0601AD04 */
    ".word 0xA026\n"  /* bra 0x0601AD30 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00E8\n"  /* .word 0x00E8 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD00\n"  /* bra 0x0601A6F2 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDD6C\n"  /* mov.l @(0x1B0,PC),r13  {[0x0601AEA4] = 0xD310430B} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86A4\n"  /* .word 0x86A4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF8\n"  /* mov.l @(0x20,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDE24\n"  /* mov.l @(0x90,PC),r14  {[0x0601AD90] = 0x000B6EF6} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0x61EC\n"  /* extu.b r14,r1 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6313\n"  /* mov r1,r3 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x324C\n"  /* add r4,r2 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601AD94] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x7EFF\n"  /* add #-1,r14 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x89CB\n"  /* bt 0x0601ACC8 */
    ".word 0x6CEC\n"  /* extu.b r14,r12 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x63C3\n"  /* mov r12,r3 */
    ".word 0x4C08\n"  /* shll2 r12 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x3C3C\n"  /* add r3,r12 */
    ".word 0x3C4C\n"  /* add r4,r12 */
    ".word 0xB074\n"  /* bsr 0x0601AE2C */
    ".word 0x1C21\n"  /* mov.l r2,@(0x4,r12) */
    ".word 0x80C8\n"  /* mov.b r0,@(0x8,r12) */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x0601AD98] = 0x0605DE3C} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x80C9\n"  /* mov.b r0,@(0x9,r12) */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601AD9C] = 0x0607EAE0} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x603C\n"  /* extu.b r3,r0 */
    ".word 0x80CA\n"  /* mov.b r0,@(0xA,r12) */
    ".word 0x63AC\n"  /* extu.b r10,r3 */
    ".word 0x2C30\n"  /* mov.b r3,@r12 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601ADA0] = 0x06085FFC} */
    ".word 0x23C2\n"  /* mov.l r12,@r3 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601ADA4] = 0x06086012} */
    ".word 0x23E0\n"  /* mov.b r14,@r3 */
    ".word 0xA002\n"  /* bra 0x0601AD6A */
    ".word 0x0009\n"  /* nop */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0601ADA0] = 0x06085FFC} */
    ".word 0x23A2\n"  /* mov.l r10,@r3 */
    ".word 0xD50F\n"  /* mov.l @(0x3C,PC),r5  {[0x0601ADA8] = 0x06086000} */
    ".word 0xD40F\n"  /* mov.l @(0x3C,PC),r4  {[0x0601ADAC] = 0x06078638} */
    ".word 0x53B1\n"  /* mov.l @(0x4,r11),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8906\n"  /* bt 0x0601AD84 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B03\n"  /* bf 0x0601AD84 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x1B31\n"  /* mov.l r3,@(0x4,r11) */
    ".word 0xA001\n"  /* bra 0x0601AD86 */
    ".word 0x25B2\n"  /* mov.l r11,@r5 */
    ".word 0x25A2\n"  /* mov.l r10,@r5 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDE3C\n"  /* mov.l @(0xF0,PC),r14  {[0x0601AE8C] = 0x2230D212} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FFC\n"  /* mov.l @(0x30,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6012\n"  /* mov.l @r1,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8638\n"  /* .word 0x8638 */
    ".word 0xD523\n"  /* mov.l @(0x8C,PC),r5  {[0x0601AE40] = 0x0607EAD8} */
    ".word 0xD624\n"  /* mov.l @(0x90,PC),r6  {[0x0601AE44] = 0x0607EAE0} */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x0601AE48] = 0x0605DE24} */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D2F\n"  /* bt/s 0x0601AE28 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD620\n"  /* mov.l @(0x80,PC),r6  {[0x0601AE4C] = 0x06078638} */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8906\n"  /* bt 0x0601ADE2 */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8B03\n"  /* bf 0x0601ADE2 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0601AE50] = 0x06078900} */
    ".word 0x902F\n"  /* mov.w @(0x5E,PC),r0 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x1431\n"  /* mov.l r3,@(0x4,r4) */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x0601AE54] = 0x060786A4} */
    ".word 0xD61C\n"  /* mov.l @(0x70,PC),r6  {[0x0601AE58] = 0x0605AD00} */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x0601AE5C] = 0x0605DE40} */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x304C\n"  /* add r4,r0 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x6272\n"  /* mov.l @r7,r2 */
    ".word 0x3232\n"  /* cmp/hs r3,r2 */
    ".word 0x8910\n"  /* bt 0x0601AE28 */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x0601AE60] = 0x0607EBF4} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890C\n"  /* bt 0x0601AE28 */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x304C\n"  /* add r4,r0 */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x6372\n"  /* mov.l @r7,r3 */
    ".word 0x0236\n"  /* mov.l r3,@(r0,r2) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_0601ae2c\n"
    "_FUN_0601ae2c:\n"
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0601AE64] = 0x06083255} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891B\n"  /* bt 0x0601AE6C */
    ".word 0xD40C\n"  /* mov.l @(0x30,PC),r4  {[0x0601AE68] = 0x0607EAB8} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xA019\n"  /* bra 0x0601AE70 */
    ".word 0x740A\n"  /* add #10,r4 */
    ".word 0x0240\n"  /* .word 0x0240 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDE24\n"  /* mov.l @(0x90,PC),r14  {[0x0601AEDC] = 0x06086011} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8638\n"  /* .word 0x8638 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8900\n"  /* bt 0x0601AE56 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86A4\n"  /* .word 0x86A4 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD00\n"  /* bra 0x0601A85E */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDE40\n"  /* mov.l @(0x100,PC),r14  {[0x0601AF60] = 0x24307F04} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3255\n"  /* dmulu.l r5,r2 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAB8\n"  /* mov #-72,r10 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0601AECC] = 0x06078868} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0601AED0] = 0x06078663} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D01\n"  /* bt/s 0x0601AE7C */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".size _FUN_0601AC88, .-_FUN_0601AC88\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601AF1E\n"
    ".type _FUN_0601AF1E, @function\n"
    "_FUN_0601AF1E:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601AF74] = 0x060638C8} */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6733\n"  /* mov r3,r7 */
    ".word 0x961E\n"  /* mov.w @(0x3C,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601AF78] = 0x0000C000} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601AF7C] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xDE10\n"  /* mov.l @(0x40,PC),r14  {[0x0601AF80] = 0x06086010} */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x0601AF84] = 0x0605AD00} */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x0601AF88] = 0x0607EAD8} */
    ".word 0x66E0\n"  /* mov.b @r14,r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x655E\n"  /* exts.b r5,r5 */
    ".word 0xB0A6\n"  /* bsr 0x0601B09A */
    ".word 0x644E\n"  /* exts.b r4,r4 */
    ".word 0xE30A\n"  /* mov #10,r3 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x7205\n"  /* add #5,r2 */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x0601AF6C] = 0x0608600F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD405\n"  /* mov.l @(0x14,PC),r4  {[0x0601AF70] = 0x06086011} */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0096\n"  /* mov.l r9,@(r0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6011\n"  /* mov.w @r1,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x38C8\n"  /* sub r12,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6010\n"  /* mov.b @r1,r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD00\n"  /* bra 0x0601A98A */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".size _FUN_0601AF1E, .-_FUN_0601AF1E\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601AF8C\n"
    ".type _FUN_0601AF8C, @function\n"
    "_FUN_0601AF8C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0A3\n"  /* bsr 0x0601B0D8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0601AFC8] = 0x0608600F} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD40C\n"  /* mov.l @(0x30,PC),r4  {[0x0601AFCC] = 0x06086011} */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".size _FUN_0601AF8C, .-_FUN_0601AF8C\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601AFA4\n"
    ".type _FUN_0601AFA4, @function\n"
    "_FUN_0601AFA4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB097\n"  /* bsr 0x0601B0D8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0601AFD4] = 0x060284AE} */
    ".word 0xD708\n"  /* mov.l @(0x20,PC),r7  {[0x0601AFD0] = 0x0604A480} */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x7536\n"  /* add #54,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD705\n"  /* mov.l @(0x14,PC),r7  {[0x0601AFD0] = 0x0604A480} */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x9503\n"  /* mov.w @(0x6,PC),r5 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0601AFD4] = 0x060284AE} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0196\n"  /* mov.l r9,@(r0,r1) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6011\n"  /* mov.w @r1,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0xA480\n"  /* bra 0x0601B8D6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".size _FUN_0601AFA4, .-_FUN_0601AFA4\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601AFD8\n"
    ".type _FUN_0601AFD8, @function\n"
    "_FUN_0601AFD8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xE630\n"  /* mov #48,r6 */
    ".size _FUN_0601AFD8, .-_FUN_0601AFD8\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601AFDE\n"
    ".type _FUN_0601AFDE, @function\n"
    "_FUN_0601AFDE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0xDE20\n"  /* mov.l @(0x80,PC),r14  {[0x0601B064] = 0x06086014} */
    ".word 0x933B\n"  /* mov.w @(0x76,PC),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x923A\n"  /* mov.w @(0x74,PC),r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601B068] = 0x06039100} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x922B\n"  /* mov.w @(0x56,PC),r2 */
    ".word 0x3322\n"  /* cmp/hs r2,r3 */
    ".word 0x8F07\n"  /* bf/s 0x0601B01A */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0601B06C] = 0x06086011} */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0xE328\n"  /* mov #40,r3 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x0601B070] = 0x0608600F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601AFDE, .-_FUN_0601AFDE\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601B020\n"
    ".type _FUN_0601B020, @function\n"
    "_FUN_0601B020:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".size _FUN_0601B020, .-_FUN_0601B020\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601B024\n"
    ".type _FUN_0601B024, @function\n"
    "_FUN_0601B024:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xEE30\n"  /* mov #48,r14 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0601B064] = 0x06086014} */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x9215\n"  /* mov.w @(0x2A,PC),r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x9314\n"  /* mov.w @(0x28,PC),r3 */
    ".word 0x62ED\n"  /* extu.w r14,r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0601B068] = 0x06039100} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0xB047\n"  /* bsr 0x0601B0D8 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0601B070] = 0x0608600F} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD406\n"  /* mov.l @(0x18,PC),r4  {[0x0601B06C] = 0x06086011} */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00A7\n"  /* mul.l r10,r0 */
    ".word 0x0160\n"  /* .word 0x0160 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6014\n"  /* mov.b @r1+,r0 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06039100 */
    ".word 0x9100\n"  /* mov.w @(0x0,PC),r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6011\n"  /* mov.w @r1,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".size _FUN_0601B024, .-_FUN_0601B024\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601B170\n"
    ".type _FUN_0601B170, @function\n"
    "_FUN_0601B170:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xD33C\n"  /* mov.l @(0xF0,PC),r3  {[0x0601B268] = 0x0606A4F4} */
    ".word 0x2382\n"  /* mov.l r8,@r3 */
    ".word 0x9265\n"  /* mov.w @(0xCA,PC),r2 */
    ".word 0xD33C\n"  /* mov.l @(0xF0,PC),r3  {[0x0601B26C] = 0x0606A4EC} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD43C\n"  /* mov.l @(0xF0,PC),r4  {[0x0601B270] = 0x06063F5C} */
    ".word 0xD33C\n"  /* mov.l @(0xF0,PC),r3  {[0x0601B274] = 0x06039250} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x925D\n"  /* mov.w @(0xBA,PC),r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x975C\n"  /* mov.w @(0xB8,PC),r7 */
    ".word 0xD339\n"  /* mov.l @(0xE4,PC),r3  {[0x0601B278] = 0x060393FC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xD339\n"  /* mov.l @(0xE4,PC),r3  {[0x0601B27C] = 0x0605A008} */
    ".word 0x2382\n"  /* mov.l r8,@r3 */
    ".word 0xD235\n"  /* mov.l @(0xD4,PC),r2  {[0x0601B270] = 0x06063F5C} */
    ".word 0xD338\n"  /* mov.l @(0xE0,PC),r3  {[0x0601B280] = 0x00008000} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xD338\n"  /* mov.l @(0xE0,PC),r3  {[0x0601B284] = 0x06012E00} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9650\n"  /* mov.w @(0xA0,PC),r6 */
    ".word 0xDE37\n"  /* mov.l @(0xDC,PC),r14  {[0x0601B288] = 0x002A0000} */
    ".word 0xD437\n"  /* mov.l @(0xDC,PC),r4  {[0x0601B28C] = 0x06059FFC} */
    ".word 0xD330\n"  /* mov.l @(0xC0,PC),r3  {[0x0601B270] = 0x06063F5C} */
    ".word 0xD237\n"  /* mov.l @(0xDC,PC),r2  {[0x0601B290] = 0x0602761E} */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x9A45\n"  /* mov.w @(0x8A,PC),r10 */
    ".word 0xE678\n"  /* mov #120,r6 */
    ".word 0xDC33\n"  /* mov.l @(0xCC,PC),r12  {[0x0601B294] = 0x06007658} */
    ".word 0x9D43\n"  /* mov.w @(0x86,PC),r13 */
    ".word 0x9743\n"  /* mov.w @(0x86,PC),r7 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x37EC\n"  /* add r14,r7 */
    ".word 0x1F73\n"  /* mov.l r7,@(0xC,r15) */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x9B3E\n"  /* mov.w @(0x7C,PC),r11 */
    ".word 0xE67C\n"  /* mov #124,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x973C\n"  /* mov.w @(0x78,PC),r7 */
    ".word 0x37EC\n"  /* add r14,r7 */
    ".word 0x1F71\n"  /* mov.l r7,@(0x4,r15) */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x9938\n"  /* mov.w @(0x70,PC),r9 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x9737\n"  /* mov.w @(0x6E,PC),r7 */
    ".word 0x37EC\n"  /* add r14,r7 */
    ".word 0x1F72\n"  /* mov.l r7,@(0x8,r15) */
    ".word 0x9635\n"  /* mov.w @(0x6A,PC),r6 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xDE28\n"  /* mov.l @(0xA0,PC),r14  {[0x0601B298] = 0x06007540} */
    ".word 0x9632\n"  /* mov.w @(0x64,PC),r6 */
    ".word 0x9432\n"  /* mov.w @(0x64,PC),r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x962F\n"  /* mov.w @(0x5E,PC),r6 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x747D\n"  /* add #125,r4 */
    ".word 0x962C\n"  /* mov.w @(0x58,PC),r6 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x747A\n"  /* add #122,r4 */
    ".word 0xE678\n"  /* mov #120,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x57F3\n"  /* mov.l @(0xC,r15),r7 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x57F1\n"  /* mov.l @(0x4,r15),r7 */
    ".word 0xE67C\n"  /* mov #124,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x57F2\n"  /* mov.l @(0x8,r15),r7 */
    ".word 0x9617\n"  /* mov.w @(0x2E,PC),r6 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x9615\n"  /* mov.w @(0x2A,PC),r6 */
    ".word 0x9415\n"  /* mov.w @(0x2A,PC),r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x9613\n"  /* mov.w @(0x26,PC),r6 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x747D\n"  /* add #125,r4 */
    ".word 0xA02B\n"  /* bra 0x0601B29C */
    ".word 0x0009\n"  /* nop */
    ".word 0x20D8\n"  /* tst r13,r0 */
    ".word 0x00DF\n"  /* mac.l @r13+,@r0+ */
    ".word 0x015F\n"  /* mac.l @r5+,@r1+ */
    ".word 0x0640\n"  /* .word 0x0640 */
    ".word 0x0101\n"  /* .word 0x0101 */
    ".word 0x0B40\n"  /* .word 0x0B40 */
    ".word 0x4B46\n"  /* .word 0x4B46 */
    ".word 0x0102\n"  /* stc sr,r1 */
    ".word 0x5313\n"  /* mov.l @(0xC,r1),r3 */
    ".word 0x0103\n"  /* .word 0x0103 */
    ".word 0x5B86\n"  /* mov.l @(0x18,r8),r11 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0084\n"  /* mov.b r8,@(r0,r0) */
    ".word 0x0104\n"  /* mov.b r0,@(r0,r1) */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F4\n"  /* bra 0x0601BC56 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4EC\n"  /* bra 0x0601BC4A */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F5C\n"  /* add r5,r15 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06039250 */
    ".word 0x9250\n"  /* mov.w @(0xA0,PC),r2 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x93FC\n"  /* mov.w @(0x1F8,PC),r3 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA008\n"  /* bra 0x0601B292 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2E00\n"  /* mov.b r0,@r14 */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9FFC\n"  /* mov.w @(0x1F8,PC),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06007658 */
    ".word 0x7658\n"  /* add #88,r6 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x7540\n"  /* add #64,r5 */
    ".word 0x9675\n"  /* mov.w @(0xEA,PC),r6 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x747A\n"  /* add #122,r4 */
    ".word 0xE678\n"  /* mov #120,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x57F3\n"  /* mov.l @(0xC,r15),r7 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x57F1\n"  /* mov.l @(0x4,r15),r7 */
    ".word 0xE67C\n"  /* mov #124,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x57F2\n"  /* mov.l @(0x8,r15),r7 */
    ".word 0x9665\n"  /* mov.w @(0xCA,PC),r6 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x9663\n"  /* mov.w @(0xC6,PC),r6 */
    ".word 0x9463\n"  /* mov.w @(0xC6,PC),r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x9661\n"  /* mov.w @(0xC2,PC),r6 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x747D\n"  /* add #125,r4 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x9657\n"  /* mov.w @(0xAE,PC),r6 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x747A\n"  /* add #122,r4 */
    ".word 0x6383\n"  /* mov r8,r3 */
    ".word 0xD22D\n"  /* mov.l @(0xB4,PC),r2  {[0x0601B398] = 0x0605AAA0} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xDD2D\n"  /* mov.l @(0xB4,PC),r13  {[0x0601B39C] = 0x0605B6D8} */
    ".word 0xD32D\n"  /* mov.l @(0xB4,PC),r3  {[0x0601B3A0] = 0x80000000} */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0xD32D\n"  /* mov.l @(0xB4,PC),r3  {[0x0601B3A4] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2D22\n"  /* mov.l r2,@r13 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x0601B3A4] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD52B\n"  /* mov.l @(0xAC,PC),r5  {[0x0601B3A8] = 0x0604842C} */
    ".word 0xD42B\n"  /* mov.l @(0xAC,PC),r4  {[0x0601B3AC] = 0x25F00540} */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x0601B3B0] = 0x0602766C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE640\n"  /* mov #64,r6 */
    ".word 0xD52B\n"  /* mov.l @(0xAC,PC),r5  {[0x0601B3B4] = 0x060487EC} */
    ".word 0xD42C\n"  /* mov.l @(0xB0,PC),r4  {[0x0601B3B8] = 0x25F001A0} */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0601B3B0] = 0x0602766C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xE709\n"  /* mov #9,r7 */
    ".word 0xD52A\n"  /* mov.l @(0xA8,PC),r5  {[0x0601B3BC] = 0x00017700} */
    ".word 0xD42B\n"  /* mov.l @(0xAC,PC),r4  {[0x0601B3C0] = 0x25E6F9C4} */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x0601B3C4] = 0x0600511E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0xD52B\n"  /* mov.l @(0xAC,PC),r5  {[0x0601B3C8] = 0x06094FA8} */
    ".word 0xD42B\n"  /* mov.l @(0xAC,PC),r4  {[0x0601B3CC] = 0x25E75DDC} */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x0601B3D0] = 0x06028654} */
    ".word 0x358C\n"  /* add r8,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x1F51\n"  /* mov.l r5,@(0x4,r15) */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0xD72A\n"  /* mov.l @(0xA8,PC),r7  {[0x0601B3D4] = 0x0000B000} */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x0601B3D8] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0601B3DC] = 0x06014884} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE410\n"  /* mov #16,r4 */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0601B3DC] = 0x06014884} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0xDE26\n"  /* mov.l @(0x98,PC),r14  {[0x0601B3E0] = 0x06038BD4} */
    ".word 0x9424\n"  /* mov.w @(0x48,PC),r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE507\n"  /* mov #7,r5 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE506\n"  /* mov #6,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE410\n"  /* mov #16,r4 */
    ".word 0xE505\n"  /* mov #5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601B3E4] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601B3E8] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0601B3EC] = 0x40000000} */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x6283\n"  /* mov r8,r2 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0601B3F0] = 0x0608600D} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xA035\n"  /* bra 0x0601B3F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0084\n"  /* mov.b r8,@(r0,r0) */
    ".word 0x0104\n"  /* mov.b r0,@(r0,r1) */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAAA0\n"  /* bra 0x0601A8DE */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0601C152 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x842C\n"  /* mov.b @(0xC,r2),r0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0540\n"  /* .word 0x0540 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x766C\n"  /* add #108,r6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x87EC\n"  /* .word 0x87EC */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x01A0\n"  /* .word 0x01A0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x25E6\n"  /* mov.l r14,@-r5 */
    ".word 0xF9C4\n"  /* .word 0xF9C4 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x511E\n"  /* mov.l @(0x38,r1),r1 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x5DDC\n"  /* mov.l @(0x30,r13),r13 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xB000\n"  /* bsr 0x0601B3DA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014884 */
    ".word 0x4884\n"  /* .word 0x4884 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038BD4 */
    ".word 0x8BD4\n"  /* bf 0x0601B38E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601B45C] = 0x0608600C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601B460] = 0x0608600E} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xE60F\n"  /* mov #15,r6 */
    ".word 0xE504\n"  /* mov #4,r5 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0601B464] = 0x06018DDC} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601B170, .-_FUN_0601B170\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601B48C\n"
    ".type _FUN_0601B48C, @function\n"
    "_FUN_0601B48C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x962F\n"  /* mov.w @(0x5E,PC),r6 */
    ".word 0xD519\n"  /* mov.l @(0x64,PC),r5  {[0x0601B4F8] = 0x060485EC} */
    ".word 0xD419\n"  /* mov.l @(0x64,PC),r4  {[0x0601B4FC] = 0x25F00020} */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0601B500] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD519\n"  /* mov.l @(0x64,PC),r5  {[0x0601B504] = 0x060485CC} */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x0601B508] = 0x25F00180} */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0601B500] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601B50C] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601B510] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xE616\n"  /* mov #22,r6 */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x0601B514] = 0x060638C8} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0601B518] = 0x0000C000} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0601B51C] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0601B520] = 0x0608600D} */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".size _FUN_0601B48C, .-_FUN_0601B48C\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601B4D6\n"
    ".type _FUN_0601B4D6, @function\n"
    "_FUN_0601B4D6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0601B524] = 0x06063D9A} */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x930A\n"  /* mov.w @(0x14,PC),r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8924\n"  /* bt 0x0601B530 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x0601B528] = 0x0608600C} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0601B52C] = 0x06018E70} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x85EC\n"  /* mov.w @(0x18,r14),r0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x85CC\n"  /* mov.w @(0x18,r12),r0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0180\n"  /* .word 0x0180 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x38C8\n"  /* sub r12,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06018E70 */
    ".word 0x8E70\n"  /* .word 0x8E70 */
    ".word 0xB160\n"  /* bsr 0x0601B7F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB0D2\n"  /* bsr 0x0601B6DC */
    ".word 0x0009\n"  /* nop */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0601B570] = 0x06063D9A} */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x9217\n"  /* mov.w @(0x2E,PC),r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890C\n"  /* bt 0x0601B560 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x0601B574] = 0x0608600E} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B05\n"  /* bf 0x0601B55A */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0601B578] = 0x0608600C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0601B57C] = 0x06018E70} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0601B580] = 0x0608600D} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x0601B580] = 0x0608600D} */
    ".word 0x000B\n"  /* rts */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x0E00\n"  /* .word 0x0E00 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06018E70 */
    ".word 0x8E70\n"  /* .word 0x8E70 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".size _FUN_0601B4D6, .-_FUN_0601B4D6\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601B584\n"
    ".type _FUN_0601B584, @function\n"
    "_FUN_0601B584:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDE1B\n"  /* mov.l @(0x6C,PC),r14  {[0x0601B5F8] = 0x0602761E} */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0601B5FC] = 0x0604866C} */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x0601B600] = 0x25F006C0} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0601B604] = 0x0604862C} */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x0601B608] = 0x25F00720} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0601B60C] = 0x060485EC} */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x0601B610] = 0x25F00740} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0x9626\n"  /* mov.w @(0x4C,PC),r6 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0601B614] = 0x0604996C} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x0601B618] = 0x25F00000} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601B61C] = 0x0602766C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0601B620] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0601B624] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x0601B628] = 0x060638C8} */
    ".word 0xE616\n"  /* mov #22,r6 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601B62C] = 0x0000C000} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601B630] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD517\n"  /* mov.l @(0x5C,PC),r5  {[0x0601B634] = 0x0605D4F5} */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0601B638] = 0x0605D4F4} */
    ".word 0x6550\n"  /* mov.b @r5,r5 */
    ".word 0xB238\n"  /* bsr 0x0601BA50 */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0601B63C] = 0x0605D4FA} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0601B640] = 0x0608600D} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0180\n"  /* .word 0x0180 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x866C\n"  /* .word 0x866C */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x06C0\n"  /* .word 0x06C0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x862C\n"  /* .word 0x862C */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0720\n"  /* .word 0x0720 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x85EC\n"  /* mov.w @(0x18,r14),r0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0740\n"  /* .word 0x0740 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x996C\n"  /* mov.w @(0xD8,PC),r9 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x766C\n"  /* add #108,r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x38C8\n"  /* sub r12,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD4F5\n"  /* mov.l @(0x3D4,PC),r4  {[0x0601BA0C] = 0x63F26330} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD4F4\n"  /* mov.l @(0x3D0,PC),r4  {[0x0601BA0C] = 0x63F26330} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD4FA\n"  /* mov.l @(0x3E8,PC),r4  {[0x0601BA28] = 0x8BC97F24} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".size _FUN_0601B584, .-_FUN_0601B584\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601B644\n"
    ".type _FUN_0601B644, @function\n"
    "_FUN_0601B644:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0xDD20\n"  /* mov.l @(0x80,PC),r13  {[0x0601B6CC] = 0x0605D4F4} */
    ".word 0xDE21\n"  /* mov.l @(0x84,PC),r14  {[0x0601B6D0] = 0x0605D4FA} */
    ".word 0xD421\n"  /* mov.l @(0x84,PC),r4  {[0x0601B6D4] = 0x06063D98} */
    ".word 0x9239\n"  /* mov.w @(0x72,PC),r2 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8D03\n"  /* bt/s 0x0601B664 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0601B6D8] = 0x0608600D} */
    ".word 0xA02D\n"  /* bra 0x0601B6BE */
    ".word 0x2350\n"  /* mov.b r5,@r3 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x932E\n"  /* mov.w @(0x5C,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x890F\n"  /* bt 0x0601B692 */
    ".word 0x63E0\n"  /* mov.b @r14,r3 */
    ".word 0x7305\n"  /* add #5,r3 */
    ".word 0x2E30\n"  /* mov.b r3,@r14 */
    ".word 0xE314\n"  /* mov #20,r3 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B01\n"  /* bf 0x0601B684 */
    ".word 0x655E\n"  /* exts.b r5,r5 */
    ".word 0x2E50\n"  /* mov.b r5,@r14 */
    ".word 0x66E0\n"  /* mov.b @r14,r6 */
    ".word 0x84D1\n"  /* mov.b @(0x1,r13),r0 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x64D0\n"  /* mov.b @r13,r4 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA1DF\n"  /* bra 0x0601BA50 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x9318\n"  /* mov.w @(0x30,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x890E\n"  /* bt 0x0601B6BE */
    ".word 0x63E0\n"  /* mov.b @r14,r3 */
    ".word 0x73FB\n"  /* add #-5,r3 */
    ".word 0x2E30\n"  /* mov.b r3,@r14 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8901\n"  /* bt 0x0601B6B0 */
    ".word 0xE20F\n"  /* mov #15,r2 */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0x66E0\n"  /* mov.b @r14,r6 */
    ".word 0x84D1\n"  /* mov.b @(0x1,r13),r0 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x64D0\n"  /* mov.b @r13,r4 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA1C9\n"  /* bra 0x0601BA50 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0F00\n"  /* .word 0x0F00 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD4F4\n"  /* mov.l @(0x3D0,PC),r4  {[0x0601BAA0] = 0x373C6552} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD4FA\n"  /* mov.l @(0x3E8,PC),r4  {[0x0601BABC] = 0x373C6552} */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".size _FUN_0601B644, .-_FUN_0601B644\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601B6F0\n"
    ".type _FUN_0601B6F0, @function\n"
    "_FUN_0601B6F0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xDC1E\n"  /* mov.l @(0x78,PC),r12  {[0x0601B770] = 0x0608600E} */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x0601B774] = 0x0605DF20} */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0601B778] = 0x06035228} */
    ".word 0x7108\n"  /* add #8,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0601B77C] = 0x0605DF23} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601B778] = 0x06035228} */
    ".word 0x7104\n"  /* add #4,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x0601B780] = 0x06063D98} */
    ".word 0x932C\n"  /* mov.w @(0x58,PC),r3 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8909\n"  /* bt 0x0601B732 */
    ".word 0x63C0\n"  /* mov.b @r12,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2C30\n"  /* mov.b r3,@r12 */
    ".word 0x633E\n"  /* exts.b r3,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8912\n"  /* bt 0x0601B750 */
    ".word 0x63DE\n"  /* exts.b r13,r3 */
    ".word 0x2C30\n"  /* mov.b r3,@r12 */
    ".word 0xA00F\n"  /* bra 0x0601B750 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x931B\n"  /* mov.w @(0x36,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8907\n"  /* bt 0x0601B750 */
    ".word 0x63C0\n"  /* mov.b @r12,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2C30\n"  /* mov.b r3,@r12 */
    ".word 0x633E\n"  /* exts.b r3,r3 */
    ".word 0x33A3\n"  /* cmp/ge r10,r3 */
    ".word 0x8B01\n"  /* bf 0x0601B750 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2C30\n"  /* mov.b r3,@r12 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x62C0\n"  /* mov.b @r12,r2 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B16\n"  /* bf 0x0601B788 */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x0601B784] = 0x0605D4F8} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xC804\n"  /* tst #0x04,r0 */
    ".word 0x8901\n"  /* bt 0x0601B768 */
    ".word 0xA011\n"  /* bra 0x0601B78A */
    ".word 0x6B8C\n"  /* extu.b r8,r11 */
    ".word 0xA00F\n"  /* bra 0x0601B78A */
    ".word 0x6BDC\n"  /* extu.b r13,r11 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF20\n"  /* mov.l @(0x80,PC),r15  {[0x0601B7F8] = 0x2FD6ED03} */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5228\n"  /* mov.l @(0x20,r2),r2 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF23\n"  /* mov.l @(0x8C,PC),r15  {[0x0601B80C] = 0xD81C6AF3} */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD4F8\n"  /* mov.l @(0x3E0,PC),r4  {[0x0601BB68] = 0x00009000} */
    ".word 0x6BDC\n"  /* extu.b r13,r11 */
    ".word 0x67BC\n"  /* extu.b r11,r7 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x69EC\n"  /* extu.b r14,r9 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x4718\n"  /* shll8 r7 */
    ".word 0x7236\n"  /* add #54,r2 */
    ".word 0x7604\n"  /* add #4,r6 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x0601B7EC] = 0x06063750} */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x5321\n"  /* mov.l @(0x4,r2),r3 */
    ".word 0x6660\n"  /* mov.b @r6,r6 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x339C\n"  /* add r9,r3 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x6230\n"  /* mov.b @r3,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x362C\n"  /* add r2,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0601B7F0] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x32A3\n"  /* cmp/ge r10,r2 */
    ".word 0x8BBC\n"  /* bf 0x0601B752 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".size _FUN_0601B6F0, .-_FUN_0601B6F0\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601BBDC\n"
    ".type _FUN_0601BBDC, @function\n"
    "_FUN_0601BBDC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FDC\n"  /* add #-36,r15 */
    ".word 0x986B\n"  /* mov.w @(0xD6,PC),r8 */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD237\n"  /* mov.l @(0xDC,PC),r2  {[0x0601BCC4] = 0x0605DF3E} */
    ".word 0xDB35\n"  /* mov.l @(0xD4,PC),r11  {[0x0601BCBC] = 0x06028400} */
    ".word 0xDC35\n"  /* mov.l @(0xD4,PC),r12  {[0x0601BCC0] = 0x060284AE} */
    ".word 0xD337\n"  /* mov.l @(0xDC,PC),r3  {[0x0601BCC8] = 0x06035228} */
    ".word 0x7120\n"  /* add #32,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x6D5E\n"  /* exts.b r5,r13 */
    ".word 0x655E\n"  /* exts.b r5,r5 */
    ".word 0x7505\n"  /* add #5,r5 */
    ".word 0x1F54\n"  /* mov.l r5,@(0x10,r15) */
    ".word 0xD334\n"  /* mov.l @(0xD0,PC),r3  {[0x0601BCCC] = 0x06063918} */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0xD334\n"  /* mov.l @(0xD0,PC),r3  {[0x0601BCD0] = 0x06063D08} */
    ".word 0x1F32\n"  /* mov.l r3,@(0x8,r15) */
    ".word 0xD334\n"  /* mov.l @(0xD0,PC),r3  {[0x0601BCD4] = 0x06063920} */
    ".word 0x1F33\n"  /* mov.l r3,@(0xC,r15) */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8F02\n"  /* bf/s 0x0601BC14 */
    ".word 0x6E63\n"  /* mov r6,r14 */
    ".word 0xA0DF\n"  /* bra 0x0601BDD2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x67DD\n"  /* extu.w r13,r7 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x65ED\n"  /* extu.w r14,r5 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x0601BCD8] = 0x0605DE64} */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x6772\n"  /* mov.l @r7,r7 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x6ADD\n"  /* extu.w r13,r10 */
    ".word 0x67F3\n"  /* mov r15,r7 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x7720\n"  /* add #32,r7 */
    ".word 0x7509\n"  /* add #9,r5 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x3A9C\n"  /* add r9,r10 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x63A0\n"  /* mov.b @r10,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8909\n"  /* bt 0x0601BC6C */
    ".word 0x67A3\n"  /* mov r10,r7 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x65ED\n"  /* extu.w r14,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x7509\n"  /* add #9,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x6ADD\n"  /* extu.w r13,r10 */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x3A9C\n"  /* add r9,r10 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601BCDC] = 0x06005DD4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54A1\n"  /* mov.l @(0x4,r10),r4 */
    ".word 0x6703\n"  /* mov r0,r7 */
    ".word 0xE678\n"  /* mov #120,r6 */
    ".word 0x65ED\n"  /* extu.w r14,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x7510\n"  /* add #16,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x84A8\n"  /* mov.b @(0x8,r10),r0 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xE20C\n"  /* mov #12,r2 */
    ".word 0x6A03\n"  /* mov r0,r10 */
    ".word 0x2F30\n"  /* mov.b r3,@r15 */
    ".word 0xE01C\n"  /* mov #28,r0 */
    ".word 0x0F34\n"  /* mov.b r3,@(r0,r15) */
    ".word 0x63AC\n"  /* extu.b r10,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B03\n"  /* bf 0x0601BCB0 */
    ".word 0x7AF4\n"  /* add #-12,r10 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xE01C\n"  /* mov #28,r0 */
    ".word 0x0F24\n"  /* mov.b r2,@(r0,r15) */
    ".word 0x63AC\n"  /* extu.b r10,r3 */
    ".word 0xE20A\n"  /* mov #10,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0xA013\n"  /* bra 0x0601BCE0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF3E\n"  /* mov.l @(0xF8,PC),r15  {[0x0601BDC0] = 0xE40C7D01} */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5228\n"  /* mov.l @(0x20,r2),r2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3918\n"  /* sub r1,r9 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D08\n"  /* sub r0,r13 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3920\n"  /* cmp/eq r2,r9 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDE64\n"  /* mov.l @(0x190,PC),r14  {[0x0601BE6C] = 0x2FB62FA6} */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06005DD4 */
    ".word 0x5DD4\n"  /* mov.l @(0x10,r13),r13 */
    ".word 0x8B01\n"  /* bf 0x0601BCE6 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0x2F20\n"  /* mov.b r2,@r15 */
    ".word 0x67AC\n"  /* extu.b r10,r7 */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0xE01C\n"  /* mov #28,r0 */
    ".word 0x66ED\n"  /* extu.w r14,r6 */
    ".word 0x4718\n"  /* shll8 r7 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x02FC\n"  /* mov.b @(r0,r15),r2 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x723C\n"  /* add #60,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x0601BD68] = 0x06063750} */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x1F25\n"  /* mov.l r2,@(0x14,r15) */
    ".word 0x5321\n"  /* mov.l @(0x4,r2),r3 */
    ".word 0x1F66\n"  /* mov.l r6,@(0x18,r15) */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x7621\n"  /* add #33,r6 */
    ".word 0x55F5\n"  /* mov.l @(0x14,r15),r5 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD711\n"  /* mov.l @(0x44,PC),r7  {[0x0601BD6C] = 0x0604A4B8} */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x55F6\n"  /* mov.l @(0x18,r15),r5 */
    ".word 0x7525\n"  /* add #37,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x339C\n"  /* add r9,r3 */
    ".word 0x843A\n"  /* mov.b @(0xA,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8921\n"  /* bt 0x0601BD8E */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x0601BD70] = 0x06078644} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B10\n"  /* bf 0x0601BD74 */
    ".word 0x66ED\n"  /* extu.w r14,r6 */
    ".word 0x57F1\n"  /* mov.l @(0x4,r15),r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x378C\n"  /* add r8,r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x7625\n"  /* add #37,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0xA010\n"  /* bra 0x0601BD88 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0xA4B8\n"  /* bra 0x0601C6E2 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8644\n"  /* .word 0x8644 */
    ".word 0x57F2\n"  /* mov.l @(0x8,r15),r7 */
    ".word 0x66ED\n"  /* extu.w r14,r6 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x378C\n"  /* add r8,r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x7625\n"  /* add #37,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x339C\n"  /* add r9,r3 */
    ".word 0x8439\n"  /* mov.b @(0x9,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890D\n"  /* bt 0x0601BDC2 */
    ".word 0x57F3\n"  /* mov.l @(0xC,r15),r7 */
    ".word 0x66ED\n"  /* extu.w r14,r6 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0601BDE8] = 0x00008000} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x7628\n"  /* add #40,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x7D01\n"  /* add #1,r13 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8D02\n"  /* bt/s 0x0601BDD2 */
    ".word 0x7E03\n"  /* add #3,r14 */
    ".word 0xAF21\n"  /* bra 0x0601BC14 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F24\n"  /* add #36,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".size _FUN_0601BBDC, .-_FUN_0601BBDC\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601BE64\n"
    ".type _FUN_0601BE64, @function\n"
    "_FUN_0601BE64:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD813\n"  /* mov.l @(0x4C,PC),r8  {[0x0601BEC8] = 0x00008000} */
    ".word 0xD914\n"  /* mov.l @(0x50,PC),r9  {[0x0601BECC] = 0x06089EDC} */
    ".word 0xDB14\n"  /* mov.l @(0x50,PC),r11  {[0x0601BED0] = 0x0605DF57} */
    ".word 0xDC15\n"  /* mov.l @(0x54,PC),r12  {[0x0601BED4] = 0x0605DF56} */
    ".word 0xDE15\n"  /* mov.l @(0x54,PC),r14  {[0x0601BED8] = 0x0607E944} */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x0601BEDC] = 0x06063E1C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D04\n"  /* bt/s 0x0601BE94 */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0601BEE0] = 0x06063E20} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B29\n"  /* bf 0x0601BEE8 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x9113\n"  /* mov.w @(0x26,PC),r1 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0601BEE4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x910F\n"  /* mov.w @(0x1E,PC),r1 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0601BEE4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x910B\n"  /* mov.w @(0x16,PC),r1 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0601BEE4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x9107\n"  /* mov.w @(0xE,PC),r1 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0601BEE4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0xA269\n"  /* bra 0x0601C392 */
    ".word 0x0009\n"  /* nop */
    ".word 0x1901\n"  /* mov.l r0,@(0x4,r9) */
    ".word 0x1801\n"  /* mov.l r0,@(0x4,r8) */
    ".word 0x1701\n"  /* mov.l r0,@(0x4,r7) */
    ".word 0x1601\n"  /* mov.l r0,@(0x4,r6) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF57\n"  /* mov.l @(0x15C,PC),r15  {[0x0601C030] = 0x0009D31B} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF56\n"  /* mov.l @(0x158,PC),r15  {[0x0601C030] = 0x0009D31B} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E1C\n"  /* add r1,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E20\n"  /* cmp/eq r2,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4F78\n"  /* .word 0x4F78 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x8403\n"  /* mov.b @(0x3,r0),r0 */
    ".word 0xC840\n"  /* tst #0x40,r0 */
    ".word 0x8907\n"  /* bt 0x0601BF00 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0xD226\n"  /* mov.l @(0x98,PC),r2  {[0x0601BF8C] = 0x0605DF4E} */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x9143\n"  /* mov.w @(0x86,PC),r1 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0601BF90] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x8403\n"  /* mov.b @(0x3,r0),r0 */
    ".word 0xC880\n"  /* tst #0x80,r0 */
    ".word 0x8907\n"  /* bt 0x0601BF18 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x0601BF94] = 0x0605DF50} */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x9138\n"  /* mov.w @(0x70,PC),r1 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0601BF90] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x8402\n"  /* mov.b @(0x2,r0),r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8907\n"  /* bt 0x0601BF30 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0601BF98] = 0x0605DF52} */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x912D\n"  /* mov.w @(0x5A,PC),r1 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601BF90] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x8402\n"  /* mov.b @(0x2,r0),r0 */
    ".word 0xC802\n"  /* tst #0x02,r0 */
    ".word 0x8907\n"  /* bt 0x0601BF48 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0601BF9C] = 0x0605DF54} */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x9122\n"  /* mov.w @(0x44,PC),r1 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601BF90] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x9A1F\n"  /* mov.w @(0x3E,PC),r10 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x0601BF8C] = 0x0605DF4E} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8B6E\n"  /* bf 0x0601C032 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0601BFA0] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0601BFA4] = 0x06063E1C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B2C\n"  /* bf 0x0601BFBC */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x0601BFA8] = 0x06063E20} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B28\n"  /* bf 0x0601BFBC */
    ".word 0xD610\n"  /* mov.l @(0x40,PC),r6  {[0x0601BFAC] = 0xFFFE4000} */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0601BFB0] = 0x00014872} */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601BFB4] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x66A3\n"  /* mov r10,r6 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0601BFB8] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0xA022\n"  /* bra 0x0601BFC6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x1901\n"  /* mov.l r0,@(0x4,r9) */
    ".word 0x1801\n"  /* mov.l r0,@(0x4,r8) */
    ".word 0x1701\n"  /* mov.l r0,@(0x4,r7) */
    ".word 0x1601\n"  /* mov.l r0,@(0x4,r6) */
    ".word 0x6666\n"  /* mov.l @r6+,r6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF4E\n"  /* mov.l @(0x138,PC),r15  {[0x0601C0C8] = 0xD31D430B} */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4F78\n"  /* .word 0x4F78 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF50\n"  /* mov.l @(0x140,PC),r15  {[0x0601C0D8] = 0xD31A64F2} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF52\n"  /* mov.l @(0x148,PC),r15  {[0x0601C0E4] = 0x6552410B} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF54\n"  /* mov.l @(0x150,PC),r15  {[0x0601C0F0] = 0x46082F62} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E1C\n"  /* add r1,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E20\n"  /* cmp/eq r2,r14 */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x4872\n"  /* .word 0x4872 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0x9657\n"  /* mov.w @(0xAE,PC),r6 */
    ".word 0xD42D\n"  /* mov.l @(0xB4,PC),r4  {[0x0601C074] = 0x00014872} */
    ".word 0xD32D\n"  /* mov.l @(0xB4,PC),r3  {[0x0601C078] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x9453\n"  /* mov.w @(0xA6,PC),r4 */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x0601C07C] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65C0\n"  /* mov.b @r12,r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x7512\n"  /* add #18,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0601C080] = 0x060621D8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x0601C084] = 0x0606212C} */
    ".word 0xD12A\n"  /* mov.l @(0xA8,PC),r1  {[0x0601C088] = 0x06031D8C} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x66C0\n"  /* mov.b @r12,r6 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0x7612\n"  /* add #18,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0601C08C] = 0x06062180} */
    ".word 0xD526\n"  /* mov.l @(0x98,PC),r5  {[0x0601C090] = 0x06089E9C} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD226\n"  /* mov.l @(0x98,PC),r2  {[0x0601C094] = 0x060620D8} */
    ".word 0xD126\n"  /* mov.l @(0x98,PC),r1  {[0x0601C098] = 0x06031A28} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6392\n"  /* mov.l @r9,r3 */
    ".word 0x73D0\n"  /* add #-48,r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0x62C0\n"  /* mov.b @r12,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x63C0\n"  /* mov.b @r12,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0601C024 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601C09C] = 0x0605DF4E} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0601C09C] = 0x0605DF4E} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA13F\n"  /* bra 0x0601C2B0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0601C0A0] = 0x0605DF50} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8901\n"  /* bt 0x0601C040 */
    ".word 0xA092\n"  /* bra 0x0601C164 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601C0A4] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x0601C0A8] = 0x06063E1C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B36\n"  /* bf 0x0601C0BC */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0601C0AC] = 0x06063E20} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B32\n"  /* bf 0x0601C0BC */
    ".word 0xD616\n"  /* mov.l @(0x58,PC),r6  {[0x0601C0B0] = 0xFFFE4000} */
    ".word 0xD416\n"  /* mov.l @(0x58,PC),r4  {[0x0601C0B4] = 0xFFFEB78E} */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0601C078] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x66A3\n"  /* mov r10,r6 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0601C0B8] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0xA02C\n"  /* bra 0x0601C0C6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x228F\n"  /* muls.w r8,r2 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x4872\n"  /* .word 0x4872 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
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
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF4E\n"  /* mov.l @(0x138,PC),r15  {[0x0601C1D8] = 0x33238B01} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF50\n"  /* mov.l @(0x140,PC),r15  {[0x0601C1E4] = 0x73FFD203} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E1C\n"  /* add r1,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E20\n"  /* cmp/eq r2,r14 */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0xB78E\n"  /* bsr 0x0601CFD6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0x9639\n"  /* mov.w @(0x72,PC),r6 */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x0601C138] = 0xFFFEB78E} */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0601C13C] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x9435\n"  /* mov.w @(0x6A,PC),r4 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601C140] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65B0\n"  /* mov.b @r11,r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x7512\n"  /* add #18,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0601C144] = 0x060621D8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x0601C148] = 0x0606212C} */
    ".word 0xD11B\n"  /* mov.l @(0x6C,PC),r1  {[0x0601C14C] = 0x06031D8C} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x66B0\n"  /* mov.b @r11,r6 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0x7612\n"  /* add #18,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0601C150] = 0x06062180} */
    ".word 0xD517\n"  /* mov.l @(0x5C,PC),r5  {[0x0601C154] = 0x06089E9C} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x0601C158] = 0x060620D8} */
    ".word 0xD117\n"  /* mov.l @(0x5C,PC),r1  {[0x0601C15C] = 0x06031A28} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6392\n"  /* mov.l @r9,r3 */
    ".word 0x73D0\n"  /* add #-48,r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0x62B0\n"  /* mov.b @r11,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x63B0\n"  /* mov.b @r11,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0601C124 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0601C160] = 0x0605DF50} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0601C160] = 0x0605DF50} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA0BF\n"  /* bra 0x0601C2B0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x228F\n"  /* muls.w r8,r2 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0xB78E\n"  /* bsr 0x0601D05A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
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
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF50\n"  /* mov.l @(0x140,PC),r15  {[0x0601C2A4] = 0x2B20D306} */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0601C1F4] = 0x0605DF52} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B5A\n"  /* bf 0x0601C224 */
    ".word 0x66A3\n"  /* mov r10,r6 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601C1F8] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x9639\n"  /* mov.w @(0x72,PC),r6 */
    ".word 0xD420\n"  /* mov.l @(0x80,PC),r4  {[0x0601C1FC] = 0x00014872} */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0601C200] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x9435\n"  /* mov.w @(0x6A,PC),r4 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0601C204] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65C0\n"  /* mov.b @r12,r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x7512\n"  /* add #18,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601C208] = 0x060621D8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0601C20C] = 0x0606212C} */
    ".word 0xD11D\n"  /* mov.l @(0x74,PC),r1  {[0x0601C210] = 0x06031D8C} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x66C0\n"  /* mov.b @r12,r6 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0x7612\n"  /* add #18,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601C214] = 0x06062180} */
    ".word 0xD519\n"  /* mov.l @(0x64,PC),r5  {[0x0601C218] = 0x06089E9C} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x0601C21C] = 0x060620D8} */
    ".word 0xD119\n"  /* mov.l @(0x64,PC),r1  {[0x0601C220] = 0x06031A28} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6392\n"  /* mov.l @r9,r3 */
    ".word 0x73D0\n"  /* add #-48,r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0x62C0\n"  /* mov.b @r12,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0x63C0\n"  /* mov.b @r12,r3 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0601C1E0 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0601C1F4] = 0x0605DF52} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0601C1F4] = 0x0605DF52} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA061\n"  /* bra 0x0601C2B0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD71\n"  /* mov.l @(0x1C4,PC),r13  {[0x0601C3B4] = 0x06044670} */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF52\n"  /* mov.l @(0x148,PC),r15  {[0x0601C340] = 0x9031D320} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x4872\n"  /* .word 0x4872 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
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
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0601C2C0] = 0x0605DF54} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B40\n"  /* bf 0x0601C2B0 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0601C2C4] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x66A3\n"  /* mov r10,r6 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0601C2C8] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x963D\n"  /* mov.w @(0x7A,PC),r6 */
    ".word 0xD422\n"  /* mov.l @(0x88,PC),r4  {[0x0601C2CC] = 0xFFFEB78E} */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0601C2D0] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x9439\n"  /* mov.w @(0x72,PC),r4 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0601C2D4] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65B0\n"  /* mov.b @r11,r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x7512\n"  /* add #18,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0601C2D8] = 0x060621D8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x0601C2DC] = 0x0606212C} */
    ".word 0xD11F\n"  /* mov.l @(0x7C,PC),r1  {[0x0601C2E0] = 0x06031D8C} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x66B0\n"  /* mov.b @r11,r6 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0x7612\n"  /* add #18,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0601C2E4] = 0x06062180} */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0601C2E8] = 0x06089E9C} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x0601C2EC] = 0x060620D8} */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x0601C2F0] = 0x06031A28} */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6392\n"  /* mov.l @r9,r3 */
    ".word 0x73D0\n"  /* add #-48,r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0x62B0\n"  /* mov.b @r11,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x63B0\n"  /* mov.b @r11,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0601C2A6 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0601C2C0] = 0x0605DF54} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x0601C2C0] = 0x0605DF54} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x0601C2F4] = 0x06059F30} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B1F\n"  /* bf 0x0601C2F8 */
    ".word 0xA06B\n"  /* bra 0x0601C392 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD71\n"  /* mov.l @(0x1C4,PC),r13  {[0x0601C484] = 0x430B62E3} */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF54\n"  /* mov.l @(0x150,PC),r15  {[0x0601C414] = 0x8B2C60D3} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0xB78E\n"  /* bsr 0x0601D1EE */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
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
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F30\n"  /* mov.w @(0x60,PC),r15 */
    ".word 0x9055\n"  /* mov.w @(0xAA,PC),r0 */
    ".word 0x03ED\n"  /* mov.w @(r0,r14),r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B06\n"  /* bf 0x0601C30E */
    ".word 0x9052\n"  /* mov.w @(0xA4,PC),r0 */
    ".word 0x03ED\n"  /* mov.w @(r0,r14),r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B02\n"  /* bf 0x0601C30E */
    ".word 0x63DF\n"  /* exts.w r13,r3 */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x0601C3AC] = 0x0605DF44} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x904A\n"  /* mov.w @(0x94,PC),r0 */
    ".word 0x00ED\n"  /* mov.w @(r0,r14),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B03\n"  /* bf 0x0601C31E */
    ".word 0x9047\n"  /* mov.w @(0x8E,PC),r0 */
    ".word 0x00ED\n"  /* mov.w @(r0,r14),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8939\n"  /* bt 0x0601C392 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x0601C3B0] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDA23\n"  /* mov.l @(0x8C,PC),r10  {[0x0601C3B4] = 0x06044670} */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x0601C3B8] = 0xFFFF6000} */
    ".word 0x923F\n"  /* mov.w @(0x7E,PC),r2 */
    ".word 0x56A2\n"  /* mov.l @(0x8,r10),r6 */
    ".word 0x55A1\n"  /* mov.l @(0x4,r10),r5 */
    ".word 0x666B\n"  /* neg r6,r6 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601C3BC] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A2\n"  /* mov.l @r10,r4 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601C3C0] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x9031\n"  /* mov.w @(0x62,PC),r0 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0601C3C4] = 0x0605DF46} */
    ".word 0x05ED\n"  /* mov.w @(r0,r14),r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x750E\n"  /* add #14,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0601C3C8] = 0x060621D8} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD11D\n"  /* mov.l @(0x74,PC),r1  {[0x0601C3CC] = 0x0606212C} */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601C3D0] = 0x06031D8C} */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x901F\n"  /* mov.w @(0x3E,PC),r0 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0601C3C4] = 0x0605DF46} */
    ".word 0x06ED\n"  /* mov.w @(r0,r14),r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6661\n"  /* mov.w @r6,r6 */
    ".word 0x760E\n"  /* add #14,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x0601C3D4] = 0x06062180} */
    ".word 0xD517\n"  /* mov.l @(0x5C,PC),r5  {[0x0601C3D8] = 0x06089E9C} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD117\n"  /* mov.l @(0x5C,PC),r1  {[0x0601C3DC] = 0x060620D8} */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601C3E0] = 0x06031A28} */
    ".word 0x362C\n"  /* add r2,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x2922\n"  /* mov.l r2,@r9 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0166\n"  /* mov.l r6,@(r0,r1) */
    ".word 0x0152\n"  /* .word 0x0152 */
    ".word 0xCCCD\n"  /* .word 0xCCCD */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF44\n"  /* mov.l @(0x110,PC),r15  {[0x0601C4C0] = 0xE308D218} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4670\n"  /* .word 0x4670 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF46\n"  /* mov.l @(0x118,PC),r15  {[0x0601C4E0] = 0xD0126002} */
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
    ".size _FUN_0601BE64, .-_FUN_0601BE64\n"
);
/* FUN_0601D478: moved to display_fade.c */
/* FUN_0601D4A8: moved to display_fade.c */
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _sound_direct_write\n"
    ".type _sound_direct_write, @function\n"
    ".global _FUN_0601D6B2\n"
    "_sound_direct_write:\n"
    "_FUN_0601D6B2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xB265\n"  /* bsr 0x0601DB84 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x0601D6CC] = 0x25A02C20} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x0601D6D0] = 0x0608604C} */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".size _sound_direct_write, .-_sound_direct_write\n"
);
__asm__(
    ".balign 4\n"
    ".global _sound_chan_a_handler\n"
    ".type _sound_chan_a_handler, @function\n"
    ".global _FUN_0601D6D4\n"
    "_sound_chan_a_handler:\n"
    "_FUN_0601D6D4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".size _sound_chan_a_handler, .-_sound_chan_a_handler\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601D6D8\n"
    ".type _FUN_0601D6D8, @function\n"
    "_FUN_0601D6D8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0601D71C] = 0x0605DF94} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x33E0\n"  /* cmp/eq r14,r3 */
    ".word 0x8907\n"  /* bt 0x0601D6F2 */
    ".word 0xB24F\n"  /* bsr 0x0601DB84 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0601D71C] = 0x0605DF94} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0601D720] = 0x0608604C} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0601D724] = 0x25A02C20} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601D6D8, .-_FUN_0601D6D8\n"
);
__asm__(
    ".balign 4\n"
    ".global _sound_chan_b_handler\n"
    ".type _sound_chan_b_handler, @function\n"
    ".global _FUN_0601D6F8\n"
    "_sound_chan_b_handler:\n"
    "_FUN_0601D6F8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".size _sound_chan_b_handler, .-_sound_chan_b_handler\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601D6FC\n"
    ".type _FUN_0601D6FC, @function\n"
    "_FUN_0601D6FC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0601D728] = 0x0605DF98} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x33E0\n"  /* cmp/eq r14,r3 */
    ".word 0x8907\n"  /* bt 0x0601D716 */
    ".word 0xB23D\n"  /* bsr 0x0601DB84 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0601D728] = 0x0605DF98} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0601D720] = 0x0608604C} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0601D724] = 0x25A02C20} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF94\n"  /* mov.l @(0x250,PC),r15  {[0x0601D970] = 0xA0150009} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF98\n"  /* mov.l @(0x260,PC),r15  {[0x0601D98C] = 0xAE1121FF} */
    ".size _FUN_0601D6FC, .-_FUN_0601D6FC\n"
);
__asm__(
    ".balign 4\n"
    ".global _sound_chan_c_handler\n"
    ".type _sound_chan_c_handler, @function\n"
    ".global _FUN_0601D72C\n"
    "_sound_chan_c_handler:\n"
    "_FUN_0601D72C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".size _sound_chan_c_handler, .-_sound_chan_c_handler\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601D730\n"
    ".type _FUN_0601D730, @function\n"
    "_FUN_0601D730:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0601D76C] = 0x0605DF9C} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x33E0\n"  /* cmp/eq r14,r3 */
    ".word 0x8907\n"  /* bt 0x0601D74A */
    ".word 0xB223\n"  /* bsr 0x0601DB84 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0601D76C] = 0x0605DF9C} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0601D770] = 0x0608604C} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0601D774] = 0x25A02C20} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601D730, .-_FUN_0601D730\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601D750\n"
    ".type _FUN_0601D750, @function\n"
    "_FUN_0601D750:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xB216\n"  /* bsr 0x0601DB84 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0601D774] = 0x25A02C20} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x0601D770] = 0x0608604C} */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDF9C\n"  /* mov.l @(0x270,PC),r15  {[0x0601D9E0] = 0x88018B01} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".size _FUN_0601D750, .-_FUN_0601D750\n"
);
__asm__(
    ".balign 4\n"
    ".global _sound_direct_pass\n"
    ".type _sound_direct_pass, @function\n"
    ".global _FUN_0601D778\n"
    "_sound_direct_pass:\n"
    "_FUN_0601D778:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".size _sound_direct_pass, .-_sound_direct_pass\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601D77C\n"
    ".type _FUN_0601D77C, @function\n"
    "_FUN_0601D77C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0601D7C0] = 0x0605DFA4} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x33E0\n"  /* cmp/eq r14,r3 */
    ".word 0x8907\n"  /* bt 0x0601D796 */
    ".word 0xB1FD\n"  /* bsr 0x0601DB84 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0601D7C0] = 0x0605DFA4} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0601D7C4] = 0x0608604C} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0601D7C8] = 0x25A02C20} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601D77C, .-_FUN_0601D77C\n"
);
__asm__(
    ".balign 4\n"
    ".global _sound_chan_d_handler\n"
    ".type _sound_chan_d_handler, @function\n"
    ".global _FUN_0601D79C\n"
    "_sound_chan_d_handler:\n"
    "_FUN_0601D79C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".size _sound_chan_d_handler, .-_sound_chan_d_handler\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601D7A0\n"
    ".type _FUN_0601D7A0, @function\n"
    "_FUN_0601D7A0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0601D7CC] = 0x0605DFA8} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x33E0\n"  /* cmp/eq r14,r3 */
    ".word 0x8907\n"  /* bt 0x0601D7BA */
    ".word 0xB1EB\n"  /* bsr 0x0601DB84 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0601D7CC] = 0x0605DFA8} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0601D7C4] = 0x0608604C} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0601D7C8] = 0x25A02C20} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDFA4\n"  /* mov.l @(0x290,PC),r15  {[0x0601DA54] = 0x0607EAD8} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDFA8\n"  /* mov.l @(0x2A0,PC),r15  {[0x0601DA70] = 0xE400A00D} */
    ".size _FUN_0601D7A0, .-_FUN_0601D7A0\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601E48C\n"
    ".type _FUN_0601E48C, @function\n"
    "_FUN_0601E48C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F41\n"  /* mov.w r4,@r15 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0601E51C] = 0x06000354} */
    ".word 0x6EF1\n"  /* mov.w @r15,r14 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x6EED\n"  /* extu.w r14,r14 */
    ".word 0x5231\n"  /* mov.l @(0x4,r3),r2 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0601E520] = 0x06087094} */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4E00\n"  /* shll r14 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x85EE\n"  /* mov.w @(0x1C,r14),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x0601E51C] = 0x06000354} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x5003\n"  /* mov.l @(0xC,r0),r0 */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0601E524] = 0x060877D8} */
    ".word 0x6550\n"  /* mov.b @r5,r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0601E528] = 0x0604A5C0} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xE41C\n"  /* mov #28,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6441\n"  /* mov.w @r4,r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601E48C, .-_FUN_0601E48C\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601E636\n"
    ".type _FUN_0601E636, @function\n"
    "_FUN_0601E636:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDD15\n"  /* mov.l @(0x54,PC),r13  {[0x0601E694] = 0x20100063} */
    ".word 0xEE01\n"  /* mov #1,r14 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x32E0\n"  /* cmp/eq r14,r2 */
    ".word 0x89FA\n"  /* bt 0x0601E640 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0xE31A\n"  /* mov #26,r3 */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x0601E698] = 0x2010001F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8BFA\n"  /* bf 0x0601E654 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0601E69C] = 0x06000354} */
    ".word 0xD70F\n"  /* mov.l @(0x3C,PC),r7  {[0x0601E6A0] = 0x060870F4} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x5237\n"  /* mov.l @(0x1C,r3),r2 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0xE610\n"  /* mov #16,r6 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x32E0\n"  /* cmp/eq r14,r2 */
    ".word 0x89FA\n"  /* bt 0x0601E66C */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0xE319\n"  /* mov #25,r3 */
    ".word 0xD206\n"  /* mov.l @(0x18,PC),r2  {[0x0601E698] = 0x2010001F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8BFA\n"  /* bf 0x0601E680 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0063\n"  /* .word 0x0063 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0354\n"  /* mov.b r5,@(r0,r3) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x70F4\n"  /* add #-12,r0 */
    ".size _FUN_0601E636, .-_FUN_0601E636\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601E6E0\n"
    ".type _FUN_0601E6E0, @function\n"
    "_FUN_0601E6E0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDD1A\n"  /* mov.l @(0x68,PC),r13  {[0x0601E754] = 0x20100063} */
    ".word 0xEE01\n"  /* mov #1,r14 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x32E0\n"  /* cmp/eq r14,r2 */
    ".word 0x89FA\n"  /* bt 0x0601E6EE */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0xE31A\n"  /* mov #26,r3 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x0601E758] = 0x2010001F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8BFA\n"  /* bf 0x0601E702 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0601E75C] = 0x06000354} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x5236\n"  /* mov.l @(0x18,r3),r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0601E760] = 0x06087094} */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x854E\n"  /* mov.w @(0x1C,r4),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x32E0\n"  /* cmp/eq r14,r2 */
    ".word 0x89FA\n"  /* bt 0x0601E728 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0xE319\n"  /* mov #25,r3 */
    ".word 0xD207\n"  /* mov.l @(0x1C,PC),r2  {[0x0601E758] = 0x2010001F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8BFA\n"  /* bf 0x0601E73C */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0063\n"  /* .word 0x0063 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0354\n"  /* mov.b r5,@(r0,r3) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7094\n"  /* add #-108,r0 */
    ".size _FUN_0601E6E0, .-_FUN_0601E6E0\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601E770\n"
    ".type _FUN_0601E770, @function\n"
    "_FUN_0601E770:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xDD21\n"  /* mov.l @(0x84,PC),r13  {[0x0601E7FC] = 0x20100063} */
    ".word 0x81F2\n"  /* mov.w r0,@(0x4,r15) */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601E800] = 0x06035C1C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0xE20B\n"  /* mov #11,r2 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x8B02\n"  /* bf 0x0601E78C */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x80CB\n"  /* mov.b r0,@(0xB,r12) */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x32E0\n"  /* cmp/eq r14,r2 */
    ".word 0x89FA\n"  /* bt 0x0601E78C */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0xE31A\n"  /* mov #26,r3 */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x0601E804] = 0x2010001F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8BFA\n"  /* bf 0x0601E7A0 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0601E808] = 0x06000354} */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0x66F2\n"  /* mov.l @r15,r6 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x5235\n"  /* mov.l @(0x14,r3),r2 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0601E80C] = 0x06087094} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x854E\n"  /* mov.w @(0x1C,r4),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x32E0\n"  /* cmp/eq r14,r2 */
    ".word 0x89FA\n"  /* bt 0x0601E7CE */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0xE319\n"  /* mov #25,r3 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0601E804] = 0x2010001F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8BFA\n"  /* bf 0x0601E7E2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0063\n"  /* .word 0x0063 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C1C\n"  /* mov.l @(0x30,r1),r12 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0354\n"  /* mov.b r5,@(r0,r3) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7094\n"  /* add #-108,r0 */
    ".size _FUN_0601E770, .-_FUN_0601E770\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601F464\n"
    ".type _FUN_0601F464, @function\n"
    "_FUN_0601F464:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD50B\n"  /* mov.l @(0x2C,PC),r5  {[0x0601F494] = 0x060877D8} */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0601F4A0] = 0x0604A57C} */
    ".word 0xD40A\n"  /* mov.l @(0x28,PC),r4  {[0x0601F494] = 0x060877D8} */
    ".word 0x6550\n"  /* mov.b @r5,r5 */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0601F4A4] = 0x060877D9} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0xB92B\n"  /* bsr 0x0601E6E0 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xBB71\n"  /* bsr 0x0601EB70 */
    ".word 0x0009\n"  /* nop */
    ".word 0xAFBD\n"  /* bra 0x0601F40C */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x77D8\n"  /* add #-40,r7 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x77DD\n"  /* add #-35,r7 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xE098\n"  /* mov #-104,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0xA57C\n"  /* bra 0x0601FF9E */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x77D9\n"  /* add #-39,r7 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xE05C\n"  /* mov #92,r0 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0xF8BC\n"  /* .word 0xF8BC */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".size _FUN_0601F464, .-_FUN_0601F464\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601F5D0\n"
    ".type _FUN_0601F5D0, @function\n"
    "_FUN_0601F5D0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB152\n"  /* bsr 0x0601F87A */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD301\n"  /* mov.l @(0x4,PC),r3  {[0x0601F5DC] = 0x0601E958} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601E958 */
    ".word 0xE958\n"  /* mov #88,r9 */
    ".size _FUN_0601F5D0, .-_FUN_0601F5D0\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601F938\n"
    ".type _FUN_0601F938, @function\n"
    "_FUN_0601F938:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x9D0E\n"  /* mov.w @(0x1C,PC),r13 */
    ".word 0xDE0B\n"  /* mov.l @(0x2C,PC),r14  {[0x0601F974] = 0x0605B6D8} */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x0601F978] = 0x0605E05C} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xBF96\n"  /* bsr 0x0601F87A */
    ".word 0x0009\n"  /* nop */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0601F97C] = 0x0601E958} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x0601F978] = 0x0605E05C} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B10\n"  /* bf 0x0601F980 */
    ".word 0xA030\n"  /* bra 0x0601F9C2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x4210\n"  /* dt r2 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06036E90 */
    ".word 0x6E90\n"  /* mov.b @r9,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0602072A */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xE05C\n"  /* mov #92,r0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601E958 */
    ".word 0xE958\n"  /* mov #88,r9 */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x0601FA2C] = 0x80000000} */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x0601FA30] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0601FA30] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB01B\n"  /* bsr 0x0601F9CC */
    ".word 0x0009\n"  /* nop */
    ".word 0xD227\n"  /* mov.l @(0x9C,PC),r2  {[0x0601FA34] = 0x40000000} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0xDC26\n"  /* mov.l @(0x98,PC),r12  {[0x0601FA38] = 0x06063D9A} */
    ".word 0xB1BE\n"  /* bsr 0x0601FD20 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22D9\n"  /* and r13,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8901\n"  /* bt 0x0601F9B2 */
    ".word 0xA002\n"  /* bra 0x0601F9B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xAFF5\n"  /* bra 0x0601F9A0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB1B3\n"  /* bsr 0x0601FD20 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0601FA2C] = 0x80000000} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601F938, .-_FUN_0601F938\n"
);
/* FUN_0601FD9C: moved to mode_dispatch.c */
__asm__(
    ".balign 4\n"
    ".global _FUN_0601FFA8\n"
    ".type _FUN_0601FFA8, @function\n"
    "_FUN_0601FFA8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0xE901\n"  /* mov #1,r9 */
    ".size _FUN_0601FFA8, .-_FUN_0601FFA8\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601FFB8\n"
    ".type _FUN_0601FFB8, @function\n"
    "_FUN_0601FFB8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x9852\n"  /* mov.w @(0xA4,PC),r8 */
    ".word 0xDB2B\n"  /* mov.l @(0xAC,PC),r11  {[0x0602006C] = 0x06087802} */
    ".word 0xDC2B\n"  /* mov.l @(0xAC,PC),r12  {[0x06020070] = 0x06087800} */
    ".word 0x6A83\n"  /* mov r8,r10 */
    ".word 0x6EC1\n"  /* mov.w @r12,r14 */
    ".word 0x7A98\n"  /* add #-104,r10 */
    ".word 0x6EED\n"  /* extu.w r14,r14 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4E00\n"  /* shll r14 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x06020074] = 0x060877FC} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0xA02E\n"  /* bra 0x06020032 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x85E1\n"  /* mov.w @(0x2,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x890E\n"  /* bt 0x0601FFFC */
    ".word 0x85E2\n"  /* mov.w @(0x4,r14),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x06020078] = 0x060877F8} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0xD023\n"  /* mov.l @(0x8C,PC),r0  {[0x0602007C] = 0x060877F4} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x629D\n"  /* extu.w r9,r2 */
    ".word 0xD122\n"  /* mov.l @(0x88,PC),r1  {[0x06020080] = 0x06087804} */
    ".word 0x2121\n"  /* mov.w r2,@r1 */
    ".word 0xA021\n"  /* bra 0x0602003E */
    ".word 0x0009\n"  /* nop */
    ".word 0x85E1\n"  /* mov.w @(0x2,r14),r0 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x06020084] = 0x06078900} */
    ".word 0x9431\n"  /* mov.w @(0x62,PC),r4 */
    ".word 0x6D03\n"  /* mov r0,r13 */
    ".word 0x0D87\n"  /* mul.l r8,r13 */
    ".word 0x85E2\n"  /* mov.w @(0x4,r14),r0 */
    ".word 0x0D1A\n"  /* sts macl,r13 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x06020088] = 0x06027552} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x4528\n"  /* shll16 r5 */
    ".word 0x9127\n"  /* mov.w @(0x4E,PC),r1 */
    ".word 0x31DC\n"  /* add r13,r1 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x85E3\n"  /* mov.w @(0x6,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x9022\n"  /* mov.w @(0x44,PC),r0 */
    ".word 0x0D36\n"  /* mov.l r3,@(r0,r13) */
    ".word 0x700C\n"  /* add #12,r0 */
    ".word 0x0DA6\n"  /* mov.l r10,@(r0,r13) */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2C31\n"  /* mov.w r3,@r12 */
    ".word 0x7E08\n"  /* add #8,r14 */
    ".word 0x62B1\n"  /* mov.w @r11,r2 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x89CB\n"  /* bt 0x0601FFD6 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x0602008C] = 0x0605AD10} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8817\n"  /* cmp/eq #23,r0 */
    ".word 0x8B01\n"  /* bf 0x0602004A */
    ".word 0xB0B7\n"  /* bsr 0x060201B8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62B1\n"  /* mov.w @r11,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2B21\n"  /* mov.w r2,@r11 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0268\n"  /* .word 0x0268 */
    ".word 0x035A\n"  /* .word 0x035A */
    ".word 0x0194\n"  /* mov.b r9,@(r0,r1) */
    ".word 0x01F8\n"  /* .word 0x01F8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7802\n"  /* add #2,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7800\n"  /* add #0,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x77FC\n"  /* add #-4,r7 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x77F8\n"  /* add #-8,r7 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x77F4\n"  /* add #-12,r7 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7804\n"  /* add #4,r8 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8900\n"  /* bt 0x0602008A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x0601FAB2 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x060200A0] = 0x0605AD10} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8817\n"  /* cmp/eq #23,r0 */
    ".word 0x8B01\n"  /* bf 0x0602009C */
    ".word 0xA08E\n"  /* bra 0x060201B8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x0601FAC6 */
    ".size _FUN_0601FFB8, .-_FUN_0601FFB8\n"
);

__asm__(



    ".balign 2\n"











    ".section .text.FUN_0600F650, \"ax\"\n"

    ".global _FUN_0600F650\n"
    ".type _FUN_0600F650, @function\n"
    "_FUN_0600F650:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDD1E\n"  /* mov.l @(0x78,PC),r13  {[0x0600F6D8] = 0x06028400} */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0600F6DC] = 0x0600A026} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xD51E\n"  /* mov.l @(0x78,PC),r5  {[0x0600F6E0] = 0xAE0003FF} */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0600F6E4] = 0x0601D5F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0600F6E8] = 0x06012050} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x0600F6EC] = 0x06078870} */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x8141\n"  /* mov.w r0,@(0x2,r4) */
    ".word 0x2401\n"  /* mov.w r0,@r4 */
    ".word 0x9628\n"  /* mov.w @(0x50,PC),r6 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0600F6F0] = 0x060484EC} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x0600F6F4] = 0x25F00460} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600F6F8] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x0600F6FC] = 0x06094FA8} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x0600F700] = 0x25E75DDC} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0600F704] = 0x06028654} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xD71B\n"  /* mov.l @(0x6C,PC),r7  {[0x0600F708] = 0x0000E000} */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0600F70C] = 0x0601143E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD519\n"  /* mov.l @(0x64,PC),r5  {[0x0600F710] = 0xAB1103FF} */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0600F6E4] = 0x0601D5F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0600F714] = 0x06011494} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64ED\n"  /* extu.w r14,r4 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0600F718] = 0x060114AC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64ED\n"  /* extu.w r14,r4 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0600F71C] = 0x06011094} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x0600F720] = 0x06063D98} */
    ".word 0x8523\n"  /* mov.w @(0x6,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B2A\n"  /* bf 0x0600F724 */
    ".word 0xEA24\n"  /* mov #36,r10 */
    ".word 0xA02A\n"  /* bra 0x0600F728 */
    ".word 0xEC22\n"  /* mov #34,r12 */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A026 */
    ".word 0xA026\n"  /* bra 0x0600F72E */
    ".word 0xAE00\n"  /* bra 0x0600F2E4 */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0600FAB8] = 0x2322D023} */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06012050 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8870\n"  /* cmp/eq #112,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x84EC\n"  /* mov.b @(0xC,r14),r0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0460\n"  /* .word 0x0460 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x5DDC\n"  /* mov.l @(0x30,r13),r13 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x143E\n"  /* mov.l r3,@(0x38,r4) */
    ".word 0xAB11\n"  /* bra 0x0600ED36 */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_060114AC */
    ".word 0x14AC\n"  /* mov.l r10,@(0x30,r4) */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06011094 */
    ".word 0x1094\n"  /* mov.l r9,@(0x10,r0) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0xEA29\n"  /* mov #41,r10 */
    ".word 0xEC26\n"  /* mov #38,r12 */
    ".word 0xDB28\n"  /* mov.l @(0xA0,PC),r11  {[0x0600F7CC] = 0x06063750} */
    ".word 0x67A3\n"  /* mov r10,r7 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0600F7D0] = 0x00009000} */
    ".word 0x9643\n"  /* mov.w @(0x86,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x67C3\n"  /* mov r12,r7 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0600F7D0] = 0x00009000} */
    ".word 0x9637\n"  /* mov.w @(0x6E,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x9732\n"  /* mov.w @(0x64,PC),r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0600F7D4] = 0x0000A000} */
    ".word 0x962E\n"  /* mov.w @(0x5C,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0600F7D8] = 0x0607EADC} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x9227\n"  /* mov.w @(0x4E,PC),r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0600F7DC] = 0x0607EBCC} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0600F7E0] = 0x0607887F} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
/* FUN_0600F794: moved to subsystem_counter.c */
/* FUN_0600F822: moved to subsystem_counter.c */
/* FUN_0600F898: moved to subsystem_counter.c */
/* FUN_0600F8BE: moved to subsystem_counter.c */
/* FUN_0600F914: moved to subsystem_counter.c */
/* FUN_0600F98C: moved to subsystem_counter.c */
/* FUN_0600F990: moved to subsystem_counter.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0600F9C6, \"ax\"\n"

    ".global _FUN_0600F9C6\n"
    ".type _FUN_0600F9C6, @function\n"
    "_FUN_0600F9C6:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD513\n"  /* mov.l @(0x4C,PC),r5  {[0x0600FA20] = 0xAE0003FF} */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0600FA24] = 0x0601D5F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0600FA28] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x9610\n"  /* mov.w @(0x20,PC),r6 */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x0600FA2C] = 0x0605CA9C} */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x0600FA30] = 0x25F00460} */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0600FA34] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0600FA38] = 0x0601209E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x0600FA3C] = 0x06063D98} */
    ".word 0x8523\n"  /* mov.w @(0x6,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B20\n"  /* bf 0x0600FA40 */
    ".word 0xEE25\n"  /* mov #37,r14 */
    ".word 0xA020\n"  /* bra 0x0600FA44 */
    ".word 0xED23\n"  /* mov #35,r13 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x885C\n"  /* cmp/eq #92,r0 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014884 */
    ".word 0x4884\n"  /* .word 0x4884 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x886E\n"  /* cmp/eq #110,r0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601155E */
    ".word 0x155E\n"  /* mov.l r5,@(0x38,r5) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x887F\n"  /* cmp/eq #127,r0 */
    ".word 0xAE00\n"  /* bra 0x0600F624 */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0600FDF8] = 0x4F26000B} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xCA9C\n"  /* xor #0x9C,r0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0460\n"  /* .word 0x0460 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x209E\n"  /* mulu.w r9,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0xEE28\n"  /* mov #40,r14 */
    ".word 0xED27\n"  /* mov #39,r13 */
    ".word 0xDB35\n"  /* mov.l @(0xD4,PC),r11  {[0x0600FB1C] = 0x06063750} */
    ".word 0x67E3\n"  /* mov r14,r7 */
    ".word 0xDC35\n"  /* mov.l @(0xD4,PC),r12  {[0x0600FB20] = 0x06028400} */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0xD333\n"  /* mov.l @(0xCC,PC),r3  {[0x0600FB24] = 0x00009000} */
    ".word 0x9659\n"  /* mov.w @(0xB2,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x67D3\n"  /* mov r13,r7 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0xD32D\n"  /* mov.l @(0xB4,PC),r3  {[0x0600FB24] = 0x00009000} */
    ".word 0x964D\n"  /* mov.w @(0x9A,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x9748\n"  /* mov.w @(0x90,PC),r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x9345\n"  /* mov.w @(0x8A,PC),r3 */
    ".word 0x9645\n"  /* mov.w @(0x8A,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD525\n"  /* mov.l @(0x94,PC),r5  {[0x0600FB28] = 0xAB1104FF} */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0600FB2C] = 0x0601D5F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE209\n"  /* mov #9,r2 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x0600FB30] = 0x0607887F} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0600FB34] = 0x0607EADC} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0600FB38] = 0x0607EAB8} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0600FB3C] = 0x06078868} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0600FB40] = 0x060788A0} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0600FB44] = 0x060788A4} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD023\n"  /* mov.l @(0x8C,PC),r0  {[0x0600FB48] = 0x06085FF4} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890F\n"  /* bt 0x0600FAE2 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0600FB4C] = 0x06078894} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x0600FB50] = 0x000C0000} */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0600FB54] = 0x06078898} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0600FB58] = 0x0607889C} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0600FB5C] = 0x060788A8} */
    ".word 0x2340\n"  /* mov.b r4,@r3 */
    ".word 0xD722\n"  /* mov.l @(0x88,PC),r7  {[0x0600FB60] = 0x0605ACE4} */
    ".word 0x961D\n"  /* mov.w @(0x3A,PC),r6 */
    ".word 0x951D\n"  /* mov.w @(0x3A,PC),r5 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0600FB64] = 0x060284AE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x0600FB48] = 0x06085FF4} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B05\n"  /* bf 0x0600FAF6 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0600FB68] = 0x06011494} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0600FB6C] = 0x060114AC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0600FB70] = 0x06010BC4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0600FB74] = 0x06011EB4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0B04\n"  /* mov.b r0,@(r0,r11) */
    ".word 0x0B38\n"  /* .word 0x0B38 */
    ".word 0x0170\n"  /* .word 0x0170 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0C26\n"  /* mov.l r2,@(r0,r12) */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x07A2\n"  /* .word 0x07A2 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x9000\n"  /* mov.w @(0x0,PC),r0 */
    ".word 0xAB11\n"  /* bra 0x0600F14E */
    ".word 0x04FF\n"  /* mac.l @r15+,@r4+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0600FF00] = 0x8B58D81A} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x887F\n"  /* cmp/eq #127,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEADC\n"  /* mov #-36,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAB8\n"  /* mov #-72,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8868\n"  /* cmp/eq #104,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88A0\n"  /* cmp/eq #-96,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88A4\n"  /* cmp/eq #-92,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8894\n"  /* cmp/eq #-108,r0 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8898\n"  /* cmp/eq #-104,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x889C\n"  /* cmp/eq #-100,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88A8\n"  /* cmp/eq #-88,r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xACE4\n"  /* bra 0x0600F52E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_060114AC */
    ".word 0x14AC\n"  /* mov.l r10,@(0x30,r4) */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06010BC4 */
    ".word 0x0BC4\n"  /* mov.b r12,@(r0,r11) */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x1EB4\n"  /* mov.l r11,@(0x10,r14) */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0600FB78, \"ax\"\n"

    ".global _FUN_0600FB78\n"
    ".type _FUN_0600FB78, @function\n"
    "_FUN_0600FB78:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xDB2C\n"  /* mov.l @(0xB0,PC),r11  {[0x0600FC3C] = 0x06063D98} */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x0600FC40] = 0x06010BC4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x0600FC44] = 0x06011EB4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD02B\n"  /* mov.l @(0xAC,PC),r0  {[0x0600FC48] = 0x06085FF4} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x0600FBA4 */
    ".word 0xA099\n"  /* bra 0x0600FCD6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9A42\n"  /* mov.w @(0x84,PC),r10 */
    ".word 0x9C42\n"  /* mov.w @(0x84,PC),r12 */
    ".word 0xDD28\n"  /* mov.l @(0xA0,PC),r13  {[0x0600FC4C] = 0x060284AE} */
    ".word 0xDE29\n"  /* mov.l @(0xA4,PC),r14  {[0x0600FC50] = 0x060283E0} */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x0600FC54] = 0x0607889C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x0600FBB8 */
    ".word 0xA07C\n"  /* bra 0x0600FCB0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x983A\n"  /* mov.w @(0x74,PC),r8 */
    ".word 0xD727\n"  /* mov.l @(0x9C,PC),r7  {[0x0600FC58] = 0x06044750} */
    ".word 0x9539\n"  /* mov.w @(0x72,PC),r5 */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD925\n"  /* mov.l @(0x94,PC),r9  {[0x0600FC5C] = 0x06078868} */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x9534\n"  /* mov.w @(0x68,PC),r5 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0600FC60] = 0x0605AB28} */
    ".word 0x6792\n"  /* mov.l @r9,r7 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6772\n"  /* mov.l @r7,r7 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD722\n"  /* mov.l @(0x88,PC),r7  {[0x0600FC64] = 0x0604475D} */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x952B\n"  /* mov.w @(0x56,PC),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x9528\n"  /* mov.w @(0x50,PC),r5 */
    ".word 0x6792\n"  /* mov.l @r9,r7 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0600FC68] = 0x0605AB60} */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6772\n"  /* mov.l @r7,r7 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0xE309\n"  /* mov #9,r3 */
    ".word 0x3236\n"  /* cmp/hi r3,r2 */
    ".word 0x8B44\n"  /* bf 0x0600FC86 */
    ".word 0xE20B\n"  /* mov #11,r2 */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x0600FC6C] = 0x06078644} */
    ".word 0x6392\n"  /* mov.l @r9,r3 */
    ".word 0x3326\n"  /* cmp/hi r2,r3 */
    ".word 0x8B0C\n"  /* bf 0x0600FC20 */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B02\n"  /* bf 0x0600FC12 */
    ".word 0xD718\n"  /* mov.l @(0x60,PC),r7  {[0x0600FC70] = 0x06044878} */
    ".word 0xA001\n"  /* bra 0x0600FC14 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD718\n"  /* mov.l @(0x60,PC),r7  {[0x0600FC74] = 0x06044888} */
    ".word 0x66A3\n"  /* mov r10,r6 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xA033\n"  /* bra 0x0600FC86 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B2A\n"  /* bf 0x0600FC7C */
    ".word 0xD714\n"  /* mov.l @(0x50,PC),r7  {[0x0600FC78] = 0x06044898} */
    ".word 0xA029\n"  /* bra 0x0600FC7E */
    ".word 0x0009\n"  /* nop */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x07A2\n"  /* .word 0x07A2 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0686\n"  /* mov.l r8,@(r0,r6) */
    ".word 0x06A0\n"  /* .word 0x06A0 */
    ".word 0x0706\n"  /* mov.l r0,@(r0,r7) */
    ".word 0x0720\n"  /* .word 0x0720 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06010BC4 */
    ".word 0x0BC4\n"  /* mov.b r12,@(r0,r11) */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x1EB4\n"  /* mov.l r11,@(0x10,r14) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x83E0\n"  /* .word 0x83E0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x889C\n"  /* cmp/eq #-100,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4750\n"  /* .word 0x4750 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8868\n"  /* cmp/eq #104,r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAB28\n"  /* bra 0x0600F2B6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x475D\n"  /* .word 0x475D */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAB60\n"  /* bra 0x0600F32E */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8644\n"  /* .word 0x8644 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4878\n"  /* .word 0x4878 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4888\n"  /* .word 0x4888 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4898\n"  /* .word 0x4898 */
    ".word 0xD72F\n"  /* mov.l @(0xBC,PC),r7  {[0x0600FD3C] = 0x060448A8} */
    ".word 0x66A3\n"  /* mov r10,r6 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x85B3\n"  /* mov.w @(0x6,r11),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8810\n"  /* cmp/eq #16,r0 */
    ".word 0x8B0B\n"  /* bf 0x0600FCA6 */
    ".word 0xD42C\n"  /* mov.l @(0xB0,PC),r4  {[0x0600FD40] = 0x0605AA9C} */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B03\n"  /* bf 0x0600FC9E */
    ".word 0xB563\n"  /* bsr 0x06010760 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA02A\n"  /* bra 0x0600FCF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0xA026\n"  /* bra 0x0600FCF2 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0x85B1\n"  /* mov.w @(0x2,r11),r0 */
    ".word 0xB41A\n"  /* bsr 0x060104E0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xA021\n"  /* bra 0x0600FCF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x0600FD44] = 0x0605ACE1} */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x953D\n"  /* mov.w @(0x7A,PC),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x953A\n"  /* mov.w @(0x74,PC),r5 */
    ".word 0x67F2\n"  /* mov.l @r15,r7 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD71F\n"  /* mov.l @(0x7C,PC),r7  {[0x0600FD48] = 0x0605ACE3} */
    ".word 0x66A3\n"  /* mov r10,r6 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xA00E\n"  /* bra 0x0600FCF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0600FD4C] = 0x060114AC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x85B3\n"  /* mov.w @(0x6,r11),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8810\n"  /* cmp/eq #16,r0 */
    ".word 0x8B03\n"  /* bf 0x0600FCEC */
    ".word 0xB3C4\n"  /* bsr 0x06010470 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA003\n"  /* bra 0x0600FCF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x85B1\n"  /* mov.w @(0x2,r11),r0 */
    ".word 0xB363\n"  /* bsr 0x060103B8 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62B3\n"  /* mov r11,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x81F2\n"  /* mov.w r0,@(0x4,r15) */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0x921B\n"  /* mov.w @(0x36,PC),r2 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8904\n"  /* bt 0x0600FD16 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x0600FD50] = 0x0607EAE0} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA003\n"  /* bra 0x0600FD1C */
    ".word 0x0009\n"  /* nop */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0600FD50] = 0x0607EAE0} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x7402\n"  /* add #2,r4 */
    ".word 0x6441\n"  /* mov.w @r4,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA6B7\n"  /* bra 0x06010AA4 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0686\n"  /* mov.l r8,@(r0,r6) */
    ".word 0x0706\n"  /* mov.l r0,@(r0,r7) */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x48A8\n"  /* .word 0x48A8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAA9C\n"  /* bra 0x0600F27E */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xACE1\n"  /* bra 0x0600F70C */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xACE3\n"  /* bra 0x0600F714 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_060114AC */
    ".word 0x14AC\n"  /* mov.l r10,@(0x30,r4) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
);
/* FUN_0600FD54: moved to subsystem_timer_b.c */
/* FUN_0600FD8A: moved to subsystem_timer_b.c */
/* FUN_0600FDFE: moved to subsystem_timer_b.c */
/* FUN_0600FE38: moved to subsystem_counter.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0600FED0, \"ax\"\n"

    ".global _FUN_0600FED0\n"
    ".type _FUN_0600FED0, @function\n"
    "_FUN_0600FED0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE1F\n"  /* mov.l @(0x7C,PC),r14  {[0x0600FF60] = 0x0607EBCC} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x9337\n"  /* mov.w @(0x6E,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B04\n"  /* bf 0x0600FEFA */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x0600FF64] = 0x25F00540} */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0600FF68] = 0x06011F92} */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x74E0\n"  /* add #-32,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x932E\n"  /* mov.w @(0x5C,PC),r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B58\n"  /* bf 0x0600FFB4 */
    ".word 0xD81A\n"  /* mov.l @(0x68,PC),r8  {[0x0600FF6C] = 0x25F004A0} */
    ".word 0xD91A\n"  /* mov.l @(0x68,PC),r9  {[0x0600FF70] = 0x06028400} */
    ".word 0xDA1B\n"  /* mov.l @(0x6C,PC),r10  {[0x0600FF74] = 0x06028654} */
    ".word 0xDB1B\n"  /* mov.l @(0x6C,PC),r11  {[0x0600FF78] = 0x0602761E} */
    ".word 0xDC1C\n"  /* mov.l @(0x70,PC),r12  {[0x0600FF7C] = 0x25E34000} */
    ".word 0x9D27\n"  /* mov.w @(0x4E,PC),r13 */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x0600FF80] = 0x0607EAD8} */
    ".word 0xA04A\n"  /* bra 0x0600FFA8 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0600FF84] = 0x0604872C} */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x0600FF88] = 0x25E61CEC} */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x67D3\n"  /* mov r13,r7 */
    ".word 0xD519\n"  /* mov.l @(0x64,PC),r5  {[0x0600FF8C] = 0x25E60000} */
    ".word 0xA015\n"  /* bra 0x0600FF54 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD518\n"  /* mov.l @(0x60,PC),r5  {[0x0600FF90] = 0x0604874C} */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xD418\n"  /* mov.l @(0x60,PC),r4  {[0x0600FF94] = 0x25E665D4} */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x67D3\n"  /* mov r13,r7 */
    ".word 0xD517\n"  /* mov.l @(0x5C,PC),r5  {[0x0600FF98] = 0x25E609A4} */
    ".word 0xA00A\n"  /* bra 0x0600FF54 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD516\n"  /* mov.l @(0x58,PC),r5  {[0x0600FF9C] = 0x0604876C} */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x0600FFA0] = 0x25E6A9CC} */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x67D3\n"  /* mov r13,r7 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD514\n"  /* mov.l @(0x50,PC),r5  {[0x0600FFA4] = 0x25E61348} */
    ".word 0x490B\n"  /* jsr @r9 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xA02C\n"  /* bra 0x0600FFB4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0099\n"  /* .word 0x0099 */
    ".word 0x5A00\n"  /* mov.l @(0x0,r0),r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBCC\n"  /* mov #-52,r11 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0540\n"  /* .word 0x0540 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06011F92 */
    ".word 0x1F92\n"  /* mov.l r9,@(0x8,r15) */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x04A0\n"  /* .word 0x04A0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x25E3\n"  /* .word 0x25E3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x872C\n"  /* .word 0x872C */
    ".word 0x25E6\n"  /* mov.l r14,@-r5 */
    ".word 0x1CEC\n"  /* mov.l r14,@(0x30,r12) */
    ".word 0x25E6\n"  /* mov.l r14,@-r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x874C\n"  /* .word 0x874C */
    ".word 0x25E6\n"  /* mov.l r14,@-r5 */
    ".word 0x65D4\n"  /* mov.b @r13+,r5 */
    ".word 0x25E6\n"  /* mov.l r14,@-r5 */
    ".word 0x09A4\n"  /* mov.b r10,@(r0,r9) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x876C\n"  /* .word 0x876C */
    ".word 0x25E6\n"  /* mov.l r14,@-r5 */
    ".word 0xA9CC\n"  /* bra 0x0600F33E */
    ".word 0x25E6\n"  /* mov.l r14,@-r5 */
    ".word 0x1348\n"  /* mov.l r4,@(0x20,r3) */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89B3\n"  /* bt 0x0600FF14 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89BC\n"  /* bt 0x0600FF2A */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89C5\n"  /* bt 0x0600FF40 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x8878\n"  /* cmp/eq #120,r0 */
    ".word 0x8B01\n"  /* bf 0x0600FFBE */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060102EC, \"ax\"\n"

    ".global _FUN_060102EC\n"
    ".type _FUN_060102EC, @function\n"
    "_FUN_060102EC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE0B\n"  /* mov.l @(0x2C,PC),r14  {[0x06010320] = 0x0607EBCC} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x9308\n"  /* mov.w @(0x10,PC),r3 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8913\n"  /* bt 0x06010328 */
    ".word 0xE306\n"  /* mov #6,r3 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x06010324] = 0x0605AD10} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA03E\n"  /* bra 0x06010386 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEADC\n"  /* mov #-36,r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x887E\n"  /* cmp/eq #126,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBCC\n"  /* mov #-52,r11 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x0600FD4A */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8B04\n"  /* bf 0x06010338 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x922C\n"  /* mov.w @(0x58,PC),r2 */
    ".word 0x2429\n"  /* and r2,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8926\n"  /* bt 0x06010386 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x06010390] = 0x0607EADC} */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06010394] = 0x0604481C} */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x06010398] = 0x0601D5F4} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x2E52\n"  /* mov.l r5,@r14 */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x0601039C] = 0x0607887F} */
    ".word 0x655E\n"  /* exts.b r5,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x060103A0] = 0x0607EAD8} */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x060103A4] = 0x06078648} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x633E\n"  /* exts.b r3,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x060103A8] = 0x0605AB18} */
    ".word 0x2450\n"  /* mov.b r5,@r4 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060103AC] = 0x06085FF4} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B0C\n"  /* bf 0x06010386 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060103B0] = 0x0605AD00} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B08\n"  /* bf 0x06010386 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x060103B4] = 0x06063D98} */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x9309\n"  /* mov.w @(0x12,PC),r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8901\n"  /* bt 0x06010386 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEADC\n"  /* mov #-36,r10 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x481C\n"  /* .word 0x481C */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0601076C] = 0x2F864F22} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x887F\n"  /* cmp/eq #127,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8648\n"  /* .word 0x8648 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAB18\n"  /* bra 0x0600F9DE */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD00\n"  /* bra 0x0600FDB6 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06010AA4, \"ax\"\n"

    ".global _FUN_06010AA4\n"
    ".type _FUN_06010AA4, @function\n"
    "_FUN_06010AA4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x624D\n"  /* extu.w r4,r2 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE0D\n"  /* mov.l @(0x34,PC),r14  {[0x06010AE4] = 0x0607EBCC} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x930A\n"  /* mov.w @(0x14,PC),r3 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8D17\n"  /* bt/s 0x06010AEC */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x63DC\n"  /* extu.b r13,r3 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x06010AE8] = 0x0607887F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xA042\n"  /* bra 0x06010B4C */
    ".word 0x0009\n"  /* nop */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD05C\n"  /* mov.l @(0x170,PC),r0  {[0x06010C44] = 0x89242A42} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9FFC\n"  /* mov.w @(0x1F8,PC),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F5C\n"  /* add r5,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBCC\n"  /* mov #-52,r11 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x887F\n"  /* cmp/eq #127,r0 */
    ".word 0x9540\n"  /* mov.w @(0x80,PC),r5 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x3357\n"  /* cmp/gt r5,r3 */
    ".word 0x892B\n"  /* bt 0x06010B4C */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B04\n"  /* bf 0x06010B04 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x9339\n"  /* mov.w @(0x72,PC),r3 */
    ".word 0x2439\n"  /* and r3,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8923\n"  /* bt 0x06010B4C */
    ".word 0xD51D\n"  /* mov.l @(0x74,PC),r5  {[0x06010B7C] = 0x06063F42} */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06010B80] = 0x06063D9E} */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x2521\n"  /* mov.w r2,@r5 */
    ".word 0x6451\n"  /* mov.w @r5,r4 */
    ".word 0x9331\n"  /* mov.w @(0x62,PC),r3 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8905\n"  /* bt 0x06010B22 */
    ".word 0x932E\n"  /* mov.w @(0x5C,PC),r3 */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8902\n"  /* bt 0x06010B22 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B01\n"  /* bf 0x06010B26 */
    ".word 0x62DD\n"  /* extu.w r13,r2 */
    ".word 0x2521\n"  /* mov.w r2,@r5 */
    ".word 0xB015\n"  /* bsr 0x06010B54 */
    ".word 0x2ED2\n"  /* mov.l r13,@r14 */
    ".word 0xE40A\n"  /* mov #10,r4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06010B84] = 0x0607887F} */
    ".word 0x624C\n"  /* extu.b r4,r2 */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD115\n"  /* mov.l @(0x54,PC),r1  {[0x06010B88] = 0x06078868} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x3142\n"  /* cmp/hs r4,r1 */
    ".word 0x8908\n"  /* bt 0x06010B4C */
    ".word 0xD714\n"  /* mov.l @(0x50,PC),r7  {[0x06010B8C] = 0x0605ACE3} */
    ".word 0x961C\n"  /* mov.w @(0x38,PC),r6 */
    ".word 0x951C\n"  /* mov.w @(0x38,PC),r5 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06010B90] = 0x060284AE} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06010F04, \"ax\"\n"

    ".global _FUN_06010F04\n"
    ".type _FUN_06010F04, @function\n"
    "_FUN_06010F04:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06010F30] = 0x0607884C} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x06010F34] = 0x0603C000} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE30A\n"  /* mov #10,r3 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06010F38] = 0x060788A4} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x3232\n"  /* cmp/hs r3,r2 */
    ".word 0x8B07\n"  /* bf 0x06010F3C */
    ".word 0xA069\n"  /* bra 0x06011002 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x884C\n"  /* cmp/eq #76,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88A4\n"  /* cmp/eq #-92,r0 */
    ".word 0xDC37\n"  /* mov.l @(0xDC,PC),r12  {[0x0601101C] = 0x060270F2} */
    ".word 0xD638\n"  /* mov.l @(0xE0,PC),r6  {[0x06011020] = 0x06078858} */
    ".word 0xD538\n"  /* mov.l @(0xE0,PC),r5  {[0x06011024] = 0x06078854} */
    ".word 0xD439\n"  /* mov.l @(0xE4,PC),r4  {[0x06011028] = 0x06078850} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD437\n"  /* mov.l @(0xDC,PC),r4  {[0x0601102C] = 0x06078878} */
    ".word 0xD338\n"  /* mov.l @(0xE0,PC),r3  {[0x06011030] = 0x060271A2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6441\n"  /* mov.w @r4,r4 */
    ".word 0xD937\n"  /* mov.l @(0xDC,PC),r9  {[0x06011034] = 0x0606212C} */
    ".word 0xDA38\n"  /* mov.l @(0xE0,PC),r10  {[0x06011038] = 0x060621D8} */
    ".word 0xDB38\n"  /* mov.l @(0xE0,PC),r11  {[0x0601103C] = 0x06032158} */
    ".word 0x65A2\n"  /* mov.l @r10,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x6492\n"  /* mov.l @r9,r4 */
    ".word 0xD837\n"  /* mov.l @(0xDC,PC),r8  {[0x06011040] = 0x06031DF4} */
    ".word 0xD638\n"  /* mov.l @(0xE0,PC),r6  {[0x06011044] = 0x06062180} */
    ".word 0x6DF2\n"  /* mov.l @r15,r13 */
    ".word 0xD338\n"  /* mov.l @(0xE0,PC),r3  {[0x06011048] = 0x06089E44} */
    ".word 0xD438\n"  /* mov.l @(0xE0,PC),r4  {[0x0601104C] = 0x060620D8} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x4D00\n"  /* shll r13 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x65D1\n"  /* mov.w @r13,r5 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD335\n"  /* mov.l @(0xD4,PC),r3  {[0x06011050] = 0x06027080} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDE35\n"  /* mov.l @(0xD4,PC),r14  {[0x06011054] = 0x06044640} */
    ".word 0x56E2\n"  /* mov.l @(0x8,r14),r6 */
    ".word 0x55E1\n"  /* mov.l @(0x4,r14),r5 */
    ".word 0x666B\n"  /* neg r6,r6 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x55A1\n"  /* mov.l @(0x4,r10),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x5491\n"  /* mov.l @(0x4,r9),r4 */
    ".word 0xD631\n"  /* mov.l @(0xC4,PC),r6  {[0x06011058] = 0x06062184} */
    ".word 0x65D1\n"  /* mov.w @r13,r5 */
    ".word 0xD431\n"  /* mov.l @(0xC4,PC),r4  {[0x0601105C] = 0x060620DC} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xDE30\n"  /* mov.l @(0xC0,PC),r14  {[0x06011060] = 0x0608A52C} */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06011050] = 0x06027080} */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD62E\n"  /* mov.l @(0xB8,PC),r6  {[0x06011064] = 0x06044654} */
    ".word 0xD52E\n"  /* mov.l @(0xB8,PC),r5  {[0x06011068] = 0x06044650} */
    ".word 0xD42F\n"  /* mov.l @(0xBC,PC),r4  {[0x0601106C] = 0x0604464C} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x666B\n"  /* neg r6,r6 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x55A2\n"  /* mov.l @(0x8,r10),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x5492\n"  /* mov.l @(0x8,r9),r4 */
    ".word 0xD62B\n"  /* mov.l @(0xAC,PC),r6  {[0x06011070] = 0x06062188} */
    ".word 0x65D1\n"  /* mov.w @r13,r5 */
    ".word 0xD42B\n"  /* mov.l @(0xAC,PC),r4  {[0x06011074] = 0x060620E0} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06011050] = 0x06027080} */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD627\n"  /* mov.l @(0x9C,PC),r6  {[0x06011078] = 0x06044678} */
    ".word 0xD528\n"  /* mov.l @(0xA0,PC),r5  {[0x0601107C] = 0x06044674} */
    ".word 0xD428\n"  /* mov.l @(0xA0,PC),r4  {[0x06011080] = 0x06044670} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x666B\n"  /* neg r6,r6 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x55A3\n"  /* mov.l @(0xC,r10),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x5493\n"  /* mov.l @(0xC,r9),r4 */
    ".word 0xD625\n"  /* mov.l @(0x94,PC),r6  {[0x06011084] = 0x0606218C} */
    ".word 0x65D1\n"  /* mov.w @r13,r5 */
    ".word 0xD425\n"  /* mov.l @(0x94,PC),r4  {[0x06011088] = 0x060620E4} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0601108C] = 0x0000FFFF} */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x06011090] = 0x21800000} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
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
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x70F2\n"  /* add #-14,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8858\n"  /* cmp/eq #88,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8854\n"  /* cmp/eq #84,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8850\n"  /* cmp/eq #80,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8878\n"  /* cmp/eq #120,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_060271A2 */
    ".word 0x71A2\n"  /* add #-94,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x212C\n"  /* .word 0x212C */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x21D8\n"  /* tst r13,r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2158\n"  /* tst r5,r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1DF4\n"  /* mov.l r15,@(0x10,r13) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2180\n"  /* mov.b r8,@r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E44\n"  /* mov.w @(0x88,PC),r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D8\n"  /* tst r13,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7080\n"  /* add #-128,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4640\n"  /* .word 0x4640 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2184\n"  /* mov.b r8,@-r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20DC\n"  /* .word 0x20DC */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x06011ABE */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4654\n"  /* .word 0x4654 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4650\n"  /* .word 0x4650 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x464C\n"  /* .word 0x464C */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2188\n"  /* tst r8,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20E0\n"  /* mov.b r14,@r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4678\n"  /* .word 0x4678 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4674\n"  /* .word 0x4674 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4670\n"  /* .word 0x4670 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x218C\n"  /* .word 0x218C */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20E4\n"  /* mov.b r14,@-r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x2180\n"  /* mov.b r8,@r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060114B8, \"ax\"\n"

    ".global _FUN_060114B8\n"
    ".type _FUN_060114B8, @function\n"
    "_FUN_060114B8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xDE11\n"  /* mov.l @(0x44,PC),r14  {[0x06011504] = 0x06078860} */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x060114FC] = 0x060447A8} */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x06011500] = 0x0607EADC} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x012E\n"  /* mov.l @(r0,r2),r1 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x310E\n"  /* .word 0x310E */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD40A\n"  /* mov.l @(0x28,PC),r4  {[0x06011508] = 0x0607887F} */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8902\n"  /* bt 0x060114EE */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x880B\n"  /* cmp/eq #11,r0 */
    ".word 0x8B10\n"  /* bf 0x06011510 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0601150C] = 0x0607EBC8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x890C\n"  /* bt 0x06011510 */
    ".word 0xA02C\n"  /* bra 0x06011552 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x47A8\n"  /* .word 0x47A8 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEADC\n"  /* mov #-36,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8860\n"  /* cmp/eq #96,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x887F\n"  /* cmp/eq #127,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBC8\n"  /* mov #-56,r11 */
    ".word 0x6CDD\n"  /* extu.w r13,r12 */
    ".word 0x6BDD\n"  /* extu.w r13,r11 */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x060115C8] = 0x060447A4} */
    ".word 0x4C00\n"  /* shll r12 */
    ".word 0x4B08\n"  /* shll2 r11 */
    ".word 0x3C3C\n"  /* add r3,r12 */
    ".word 0x4B08\n"  /* shll2 r11 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD72A\n"  /* mov.l @(0xA8,PC),r7  {[0x060115CC] = 0x00010000} */
    ".word 0x964F\n"  /* mov.w @(0x9E,PC),r6 */
    ".word 0xD22A\n"  /* mov.l @(0xA8,PC),r2  {[0x060115D0] = 0x060447A8} */
    ".word 0x3B2C\n"  /* add r2,r11 */
    ".word 0x7B0C\n"  /* add #12,r11 */
    ".word 0x65B2\n"  /* mov.l @r11,r5 */
    ".word 0xB0BB\n"  /* bsr 0x060116A8 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x67C1\n"  /* mov.w @r12,r7 */
    ".word 0x66B2\n"  /* mov.l @r11,r6 */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x060115D4] = 0x06044764} */
    ".word 0xB21D\n"  /* bsr 0x06011978 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x67C1\n"  /* mov.w @r12,r7 */
    ".word 0x66B2\n"  /* mov.l @r11,r6 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0xD424\n"  /* mov.l @(0x90,PC),r4  {[0x060115D8] = 0x06044784} */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA213\n"  /* bra 0x06011978 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060115F0, \"ax\"\n"

    ".global _FUN_060115F0\n"
    ".type _FUN_060115F0, @function\n"
    "_FUN_060115F0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x9D2C\n"  /* mov.w @(0x58,PC),r13 */
    ".word 0xDE17\n"  /* mov.l @(0x5C,PC),r14  {[0x0601165C] = 0x0607886E} */
    ".word 0xDC17\n"  /* mov.l @(0x5C,PC),r12  {[0x06011660] = 0x00080000} */
    ".word 0xB022\n"  /* bsr 0x0601164A */
    ".word 0x0009\n"  /* nop */
    ".word 0x62E1\n"  /* mov.w @r14,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2E21\n"  /* mov.w r2,@r14 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x06011664] = 0x25E5F800} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x614D\n"  /* extu.w r4,r1 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06011668] = 0x06035C2C} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x385C\n"  /* add r5,r8 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x06011628 */
    ".word 0xA001\n"  /* bra 0x0601162A */
    ".word 0x63C3\n"  /* mov r12,r3 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0601166C] = 0xFFF80000} */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x61E1\n"  /* mov.w @r14,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x0317\n"  /* mul.l r1,r3 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x2832\n"  /* mov.l r3,@r8 */
    ".word 0x634D\n"  /* extu.w r4,r3 */
    ".word 0x33D3\n"  /* cmp/ge r13,r3 */
    ".word 0x8BE9\n"  /* bf 0x06011610 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06011670] = 0x12F2FC00} */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x06011674] = 0x25F800A4} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x9303\n"  /* mov.w @(0x6,PC),r3 */
    ".word 0x72F6\n"  /* add #-10,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x886E\n"  /* cmp/eq #110,r0 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x25E5\n"  /* mov.w r14,@-r5 */
    ".word 0xF800\n"  /* .word 0xF800 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C2C\n"  /* mov.l @(0x30,r2),r12 */
    ".word 0xFFF8\n"  /* .word 0xFFF8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x12F2\n"  /* mov.l r15,@(0x8,r2) */
    ".word 0xFC00\n"  /* .word 0xFC00 */
    ".word 0x25F8\n"  /* tst r15,r5 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060116BC, \"ax\"\n"

    ".global _FUN_060116BC\n"
    ".type _FUN_060116BC, @function\n"
    "_FUN_060116BC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x81F4\n"  /* mov.w r0,@(0x8,r15) */
    ".word 0x7604\n"  /* add #4,r6 */
    ".word 0x85F4\n"  /* mov.w @(0x8,r15),r0 */
    ".word 0xD343\n"  /* mov.l @(0x10C,PC),r3  {[0x060117DC] = 0x06027358} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xDB43\n"  /* mov.l @(0x10C,PC),r11  {[0x060117E0] = 0x060786CC} */
    ".word 0xDC43\n"  /* mov.l @(0x10C,PC),r12  {[0x060117E4] = 0x0605AAA0} */
    ".word 0xDD44\n"  /* mov.l @(0x110,PC),r13  {[0x060117E8] = 0x0602754C} */
    ".word 0xDE44\n"  /* mov.l @(0x110,PC),r14  {[0x060117EC] = 0x06027552} */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD43F\n"  /* mov.l @(0xFC,PC),r4  {[0x060117F0] = 0xFFC80000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD43E\n"  /* mov.l @(0xF8,PC),r4  {[0x060117F4] = 0x001E0000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE20A\n"  /* mov #10,r2 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD42E\n"  /* mov.l @(0xB8,PC),r4  {[0x060117F0] = 0xFFC80000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD42D\n"  /* mov.l @(0xB4,PC),r4  {[0x060117F4] = 0x001E0000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD420\n"  /* mov.l @(0x80,PC),r4  {[0x060117F8] = 0x00380000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x060117F4] = 0x001E0000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE20E\n"  /* mov #14,r2 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD40F\n"  /* mov.l @(0x3C,PC),r4  {[0x060117F8] = 0x00380000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD40C\n"  /* mov.l @(0x30,PC),r4  {[0x060117F4] = 0x001E0000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xA010\n"  /* bra 0x060117FC */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7358\n"  /* add #88,r3 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86CC\n"  /* .word 0x86CC */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAAA0\n"  /* bra 0x06010D2A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x754C\n"  /* add #76,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0xFFC8\n"  /* .word 0xFFC8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0038\n"  /* ldtlb */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE310\n"  /* mov #16,r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD453\n"  /* mov.l @(0x14C,PC),r4  {[0x0601196C] = 0x00380000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD452\n"  /* mov.l @(0x148,PC),r4  {[0x06011970] = 0xFFE20000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE212\n"  /* mov #18,r2 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD442\n"  /* mov.l @(0x108,PC),r4  {[0x0601196C] = 0x00380000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD441\n"  /* mov.l @(0x104,PC),r4  {[0x06011970] = 0xFFE20000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE314\n"  /* mov #20,r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD434\n"  /* mov.l @(0xD0,PC),r4  {[0x06011974] = 0xFFC80000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD431\n"  /* mov.l @(0xC4,PC),r4  {[0x06011970] = 0xFFE20000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE216\n"  /* mov #22,r2 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD423\n"  /* mov.l @(0x8C,PC),r4  {[0x06011974] = 0xFFC80000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD420\n"  /* mov.l @(0x80,PC),r4  {[0x06011970] = 0xFFE20000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0xE02E\n"  /* mov #46,r0 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x00FD\n"  /* mov.w @(r0,r15),r0 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x8123\n"  /* mov.w r0,@(0x6,r2) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x8035\n"  /* mov.b r0,@(0x5,r3) */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2C31\n"  /* mov.w r3,@r12 */
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
    ".word 0x0038\n"  /* ldtlb */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFE2\n"  /* .word 0xFFE2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFC8\n"  /* .word 0xFFC8 */
    ".word 0x0000\n"  /* .word 0x0000 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0601198C, \"ax\"\n"

    ".global _FUN_0601198C\n"
    ".type _FUN_0601198C, @function\n"
    "_FUN_0601198C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F71\n"  /* mov.w r7,@r15 */
    ".word 0xDC55\n"  /* mov.l @(0x154,PC),r12  {[0x06011AE8] = 0x0602754C} */
    ".word 0xDD55\n"  /* mov.l @(0x154,PC),r13  {[0x06011AEC] = 0x060786CC} */
    ".word 0xDE56\n"  /* mov.l @(0x158,PC),r14  {[0x06011AF0] = 0x0605AAA0} */
    ".word 0x64B2\n"  /* mov.l @r11,r4 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x7808\n"  /* add #8,r8 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x34AC\n"  /* add r10,r4 */
    ".word 0x2801\n"  /* mov.w r0,@r8 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x54B1\n"  /* mov.l @(0x4,r11),r4 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x780A\n"  /* add #10,r8 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x349C\n"  /* add r9,r4 */
    ".word 0x2801\n"  /* mov.w r0,@r8 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x54B2\n"  /* mov.l @(0x8,r11),r4 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x780C\n"  /* add #12,r8 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x34AC\n"  /* add r10,r4 */
    ".word 0x2801\n"  /* mov.w r0,@r8 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x54B3\n"  /* mov.l @(0xC,r11),r4 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x780E\n"  /* add #14,r8 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x349C\n"  /* add r9,r4 */
    ".word 0x2801\n"  /* mov.w r0,@r8 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x54B4\n"  /* mov.l @(0x10,r11),r4 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x7810\n"  /* add #16,r8 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x34AC\n"  /* add r10,r4 */
    ".word 0x2801\n"  /* mov.w r0,@r8 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x54B5\n"  /* mov.l @(0x14,r11),r4 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x7812\n"  /* add #18,r8 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x349C\n"  /* add r9,r4 */
    ".word 0x2801\n"  /* mov.w r0,@r8 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x54B6\n"  /* mov.l @(0x18,r11),r4 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x7814\n"  /* add #20,r8 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x34AC\n"  /* add r10,r4 */
    ".word 0x2801\n"  /* mov.w r0,@r8 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x54B7\n"  /* mov.l @(0x1C,r11),r4 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x7816\n"  /* add #22,r8 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x349C\n"  /* add r9,r4 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2801\n"  /* mov.w r0,@r8 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x60F1\n"  /* mov.w @r15,r0 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8035\n"  /* mov.b r0,@(0x5,r3) */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E31\n"  /* mov.w r3,@r14 */
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
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x754C\n"  /* add #76,r5 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86CC\n"  /* .word 0x86CC */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAAA0\n"  /* bra 0x06011036 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06011B08, \"ax\"\n"

    ".global _FUN_06011B08\n"
    ".type _FUN_06011B08, @function\n"
    "_FUN_06011B08:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FE8\n"  /* add #-24,r15 */
    ".word 0x1F43\n"  /* mov.l r4,@(0xC,r15) */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x1F52\n"  /* mov.l r5,@(0x8,r15) */
    ".word 0x7604\n"  /* add #4,r6 */
    ".word 0x5AFF\n"  /* mov.l @(0x3C,r15),r10 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0xD33F\n"  /* mov.l @(0xFC,PC),r3  {[0x06011C18] = 0x06027358} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x04FD\n"  /* mov.w @(r0,r15),r4 */
    ".word 0x648B\n"  /* neg r8,r4 */
    ".word 0xDB3E\n"  /* mov.l @(0xF8,PC),r11  {[0x06011C1C] = 0x060786CC} */
    ".word 0xDC3F\n"  /* mov.l @(0xFC,PC),r12  {[0x06011C20] = 0x0605AAA0} */
    ".word 0xDD3F\n"  /* mov.l @(0xFC,PC),r13  {[0x06011C24] = 0x0602754C} */
    ".word 0xDE40\n"  /* mov.l @(0x100,PC),r14  {[0x06011C28] = 0x06027552} */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x1F46\n"  /* mov.l r4,@(0x18,r15) */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x54F5\n"  /* mov.l @(0x14,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE20A\n"  /* mov #10,r2 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x54F4\n"  /* mov.l @(0x10,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x54F5\n"  /* mov.l @(0x14,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE20E\n"  /* mov #14,r2 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xA00B\n"  /* bra 0x06011C2C */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7358\n"  /* add #88,r3 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86CC\n"  /* .word 0x86CC */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAAA0\n"  /* bra 0x06011166 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x754C\n"  /* add #76,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x54F4\n"  /* mov.l @(0x10,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE310\n"  /* mov #16,r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x649B\n"  /* neg r9,r4 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x1F46\n"  /* mov.l r4,@(0x18,r15) */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x54F5\n"  /* mov.l @(0x14,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE212\n"  /* mov #18,r2 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x54F4\n"  /* mov.l @(0x10,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE314\n"  /* mov #20,r3 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x54F5\n"  /* mov.l @(0x14,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xE216\n"  /* mov #22,r2 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x54F4\n"  /* mov.l @(0x10,r15),r4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0xE042\n"  /* mov #66,r0 */
    ".word 0x62C1\n"  /* mov.w @r12,r2 */
    ".word 0x00FD\n"  /* mov.w @(r0,r15),r0 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x8123\n"  /* mov.w r0,@(0x6,r2) */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0xA000\n"  /* bra 0x06011D86 */
    ".word 0x0009\n"  /* nop */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x33BC\n"  /* add r11,r3 */
    ".word 0x8035\n"  /* mov.b r0,@(0x5,r3) */
    ".word 0x63C1\n"  /* mov.w @r12,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2C31\n"  /* mov.w r3,@r12 */
    ".word 0x7F18\n"  /* add #24,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
/* FUN_06012054: moved to vdp_attr_config.c */
/* FUN_06012084: moved to vdp_attr_config.c */
/* FUN_060120A0: moved to vdp_attr_config.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060120CC, \"ax\"\n"

    ".global _FUN_060120CC\n"
    ".type _FUN_060120CC, @function\n"
    "_FUN_060120CC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x06012150] = 0x06078636} */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06012154] = 0x060788F8} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06012158] = 0x06014884} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x0601215C] = 0x060788B4} */
    ".word 0x24E2\n"  /* mov.l r14,@r4 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x06012160] = 0x00080000} */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x4209\n"  /* shlr2 r2 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x06012164] = 0x000F3333} */
    ".word 0x1432\n"  /* mov.l r3,@(0x8,r4) */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x06012168] = 0x060788C0} */
    ".word 0x24E2\n"  /* mov.l r14,@r4 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601216C] = 0x00053333} */
    ".word 0x1432\n"  /* mov.l r3,@(0x8,r4) */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x06012170] = 0x060788CC} */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x06012174] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x06012178] = 0x060788D8} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06012174] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0xD11B\n"  /* mov.l @(0x6C,PC),r1  {[0x0601217C] = 0x060788E4} */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06012174] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x921B\n"  /* mov.w @(0x36,PC),r2 */
    ".word 0x61EC\n"  /* extu.b r14,r1 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06012180] = 0x060788B0} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x62EF\n"  /* exts.w r14,r2 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06012184] = 0x060788B2} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06012188] = 0x060788F0} */
    ".word 0x2310\n"  /* mov.b r1,@r3 */
    ".word 0xD519\n"  /* mov.l @(0x64,PC),r5  {[0x0601218C] = 0x060788F4} */
    ".word 0xD419\n"  /* mov.l @(0x64,PC),r4  {[0x06012190] = 0x060788AC} */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x06012194] = 0x0607EAD8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B03\n"  /* bf 0x0601213A */
    ".word 0xE33C\n"  /* mov #60,r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xA007\n"  /* bra 0x06012148 */
    ".word 0x25E2\n"  /* mov.l r14,@r5 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0xE314\n"  /* mov #20,r3 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA0A1\n"  /* bra 0x0601228A */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8636\n"  /* .word 0x8636 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88F8\n"  /* cmp/eq #-8,r0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014884 */
    ".word 0x4884\n"  /* .word 0x4884 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88B4\n"  /* cmp/eq #-76,r0 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0x3333\n"  /* cmp/ge r3,r3 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88C0\n"  /* cmp/eq #-64,r0 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x3333\n"  /* cmp/ge r3,r3 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88CC\n"  /* cmp/eq #-52,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88D8\n"  /* cmp/eq #-40,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88E4\n"  /* cmp/eq #-28,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88B0\n"  /* cmp/eq #-80,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88B2\n"  /* cmp/eq #-78,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88F0\n"  /* cmp/eq #-16,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88F4\n"  /* cmp/eq #-12,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88AC\n"  /* cmp/eq #-84,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0xD021\n"  /* mov.l @(0x84,PC),r0  {[0x06012220] = 0x0607EAD8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x060121A4 */
    ".word 0xA073\n"  /* bra 0x0601228A */
    ".word 0x0009\n"  /* nop */
    ".word 0xA31C\n"  /* bra 0x060127E0 */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0601228C, \"ax\"\n"

    ".global _FUN_0601228C\n"
    ".type _FUN_0601228C, @function\n"
    "_FUN_0601228C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x060122D8] = 0x0607EBCC} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B05\n"  /* bf 0x060122A2 */
    ".word 0xB02D\n"  /* bsr 0x060122F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB137\n"  /* bsr 0x0601250C */
    ".word 0x0009\n"  /* nop */
    ".word 0xA237\n"  /* bra 0x06012710 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE364\n"  /* mov #100,r3 */
    ".word 0xD60D\n"  /* mov.l @(0x34,PC),r6  {[0x060122DC] = 0x060788B2} */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8F05\n"  /* bf/s 0x060122B8 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0xB12C\n"  /* bsr 0x0601250C */
    ".word 0x2651\n"  /* mov.w r5,@r6 */
    ".word 0xA22C\n"  /* bra 0x06012710 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0xE328\n"  /* mov #40,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B0F\n"  /* bf 0x060122E0 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0xB185\n"  /* bsr 0x060125D0 */
    ".word 0x2651\n"  /* mov.w r5,@r6 */
    ".word 0xA223\n"  /* bra 0x06012710 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8636\n"  /* .word 0x8636 */
    ".word 0xAE11\n"  /* bra 0x06011EF6 */
    ".word 0x0FFF\n"  /* mac.l @r15+,@r15+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x060126A8] = 0x060788B0} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBCC\n"  /* mov #-52,r11 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88B2\n"  /* cmp/eq #-78,r0 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xE210\n"  /* mov #16,r2 */
    ".word 0x2452\n"  /* mov.l r5,@r4 */
    ".word 0x655E\n"  /* exts.b r5,r5 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0601232C] = 0x0605AD10} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06012330] = 0x06078636} */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x2350\n"  /* mov.b r5,@r3 */
    ".word 0xD40F\n"  /* mov.l @(0x3C,PC),r4  {[0x06012334] = 0x060788B4} */
    ".word 0x9316\n"  /* mov.w @(0x2C,PC),r3 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x9313\n"  /* mov.w @(0x26,PC),r3 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x06012338] = 0x00020000} */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x3353\n"  /* cmp/ge r5,r3 */
    ".word 0x8900\n"  /* bt 0x06012310 */
    ".word 0x1451\n"  /* mov.l r5,@(0x4,r4) */
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x0601233C] = 0x0004CCCC} */
    ".word 0x5342\n"  /* mov.l @(0x8,r4),r3 */
    ".word 0x3353\n"  /* cmp/ge r5,r3 */
    ".word 0x8900\n"  /* bt 0x0601231A */
    ".word 0x1452\n"  /* mov.l r5,@(0x8,r4) */
    ".word 0xD509\n"  /* mov.l @(0x24,PC),r5  {[0x06012340] = 0x060788B2} */
    ".word 0x9305\n"  /* mov.w @(0xA,PC),r3 */
    ".word 0x6251\n"  /* mov.w @r5,r2 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2521\n"  /* mov.w r2,@r5 */
    ".word 0x2999\n"  /* and r9,r9 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x1800\n"  /* mov.l r0,@(0x0,r8) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x06011D52 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8636\n"  /* .word 0x8636 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88B4\n"  /* cmp/eq #-76,r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0xCCCC\n"  /* .word 0xCCCC */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88B2\n"  /* cmp/eq #-78,r0 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06012454, \"ax\"\n"

    ".global _FUN_06012454\n"
    ".type _FUN_06012454, @function\n"
    "_FUN_06012454:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x060124D4] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F50\n"  /* mov.b r5,@r15 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x060124D8] = 0x06026E0C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x56E2\n"  /* mov.l @(0x8,r14),r6 */
    ".word 0x55E1\n"  /* mov.l @(0x4,r14),r5 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x060124DC] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x61F0\n"  /* mov.b @r15,r1 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x060124E0] = 0x06035C2C} */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x9229\n"  /* mov.w @(0x52,PC),r2 */
    ".word 0x4418\n"  /* shll8 r4 */
    ".word 0x4318\n"  /* shll8 r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x060124E4] = 0x06026E94} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xD513\n"  /* mov.l @(0x4C,PC),r5  {[0x060124E8] = 0x06063570} */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x060124EC] = 0x0607EAD8} */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x060124F0] = 0x06063564} */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x060124F4] = 0x06031D8C} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD612\n"  /* mov.l @(0x48,PC),r6  {[0x060124F8] = 0x0606356C} */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x060124FC] = 0x06089EA0} */
    ".word 0xD40E\n"  /* mov.l @(0x38,PC),r4  {[0x060124EC] = 0x0607EAD8} */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06012500] = 0x0606355C} */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x06012504] = 0x06031A28} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06012508] = 0x06026DF8} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E0C\n"  /* extu.b r0,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C2C\n"  /* mov.l @(0x30,r2),r12 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026E94 */
    ".word 0x6E94\n"  /* mov.b @r9+,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3570\n"  /* cmp/eq r7,r5 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3564\n"  /* .word 0x3564 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D8C\n"  /* mov.l r8,@(0x30,r13) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x356C\n"  /* add r6,r5 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EA0\n"  /* mov.w @(0x140,PC),r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x355C\n"  /* add r5,r5 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A28\n"  /* mov.l r2,@(0x20,r10) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
);
/* FUN_06012AC4: moved to subsystem_render.c */
/* FUN_06012AFA: moved to subsystem_render.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06012BE4, \"ax\"\n"

    ".global _FUN_06012BE4\n"
    ".type _FUN_06012BE4, @function\n"
    "_FUN_06012BE4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDC20\n"  /* mov.l @(0x80,PC),r12  {[0x06012C68] = 0x06018EAC} */
    ".word 0x9E3D\n"  /* mov.w @(0x7A,PC),r14 */
    ".word 0xD720\n"  /* mov.l @(0x80,PC),r7  {[0x06012C6C] = 0x060448D4} */
    ".word 0xD620\n"  /* mov.l @(0x80,PC),r6  {[0x06012C70] = 0x0000E000} */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x06012C74] = 0x060283E0} */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE624\n"  /* mov #36,r6 */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x06012C78] = 0x060612C4} */
    ".word 0xD420\n"  /* mov.l @(0x80,PC),r4  {[0x06012C7C] = 0x060612B4} */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06012C80] = 0x0602761E} */
    ".word 0x35EC\n"  /* add r14,r5 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06012C84] = 0x06034C48} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x20D9\n"  /* and r13,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8BFA\n"  /* bf 0x06012C0C */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x06012C88] = 0x0605ACCA} */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06012C74] = 0x060283E0} */
    ".word 0xD614\n"  /* mov.l @(0x50,PC),r6  {[0x06012C70] = 0x0000E000} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE624\n"  /* mov #36,r6 */
    ".word 0xD514\n"  /* mov.l @(0x50,PC),r5  {[0x06012C78] = 0x060612C4} */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x06012C7C] = 0x060612B4} */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06012C80] = 0x0602761E} */
    ".word 0x35EC\n"  /* add r14,r5 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xAF8E\n"  /* bra 0x06012B58 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060138BE, \"ax\"\n"

    ".global _FUN_060138BE\n"
    ".type _FUN_060138BE, @function\n"
    "_FUN_060138BE:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06013920] = 0x00008000} */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD517\n"  /* mov.l @(0x5C,PC),r5  {[0x06013924] = 0x00960000} */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06013928] = 0x06011AF4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0601392C] = 0x060078DC} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x04B0\n"  /* .word 0x04B0 */
    ".word 0x05DC\n"  /* mov.b @(r0,r13),r5 */
    ".word 0x020C\n"  /* mov.b @(r0,r0),r2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B0C\n"  /* .word 0x4B0C */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B18\n"  /* shll8 r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B20\n"  /* shal r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF0\n"  /* .word 0x4AF0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBCC\n"  /* mov #-52,r11 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF2\n"  /* .word 0x4AF2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4B14\n"  /* .word 0x4B14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD5C\n"  /* bra 0x060133B6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF8\n"  /* .word 0x4AF8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AFC\n"  /* .word 0x4AFC */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAAA0\n"  /* bra 0x06012E4A */
    ".word 0xAB11\n"  /* bra 0x06012F2E */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06013CE0] = 0x06078900} */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x49CC\n"  /* .word 0x49CC */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6B8\n"  /* bsr 0x0601468E */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0096\n"  /* mov.l r9,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06011AF4 */
    ".word 0x1AF4\n"  /* mov.l r15,@(0x10,r10) */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060078DC */
    ".word 0x78DC\n"  /* add #-36,r8 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06013940] = 0x06084AF2} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xE320\n"  /* mov #32,r3 */
    ".word 0xD202\n"  /* mov.l @(0x8,PC),r2  {[0x06013944] = 0x06084AF4} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA004\n"  /* bra 0x06013948 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF2\n"  /* .word 0x4AF2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF4\n"  /* .word 0x4AF4 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06013948, \"ax\"\n"

    ".global _FUN_06013948\n"
    ".type _FUN_06013948, @function\n"
    "_FUN_06013948:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD834\n"  /* mov.l @(0xD0,PC),r8  {[0x06013A30] = 0x06026E2E} */
    ".word 0xDB35\n"  /* mov.l @(0xD4,PC),r11  {[0x06013A34] = 0x06084AF4} */
    ".word 0xDC35\n"  /* mov.l @(0xD4,PC),r12  {[0x06013A38] = 0x00010000} */
    ".word 0x9E61\n"  /* mov.w @(0xC2,PC),r14 */
    ".word 0x63B1\n"  /* mov.w @r11,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2B31\n"  /* mov.w r3,@r11 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B02\n"  /* bf 0x06013976 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0xD232\n"  /* mov.l @(0xC8,PC),r2  {[0x06013A3C] = 0x06084AF2} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD332\n"  /* mov.l @(0xC8,PC),r3  {[0x06013A40] = 0x06026E0C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6943\n"  /* mov r4,r9 */
    ".word 0xD530\n"  /* mov.l @(0xC0,PC),r5  {[0x06013A44] = 0x0605AD5C} */
    ".word 0x6D53\n"  /* mov r5,r13 */
    ".word 0x3D4C\n"  /* add r4,r13 */
    ".word 0x9250\n"  /* mov.w @(0xA0,PC),r2 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x1F51\n"  /* mov.l r5,@(0x4,r15) */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x06013A48] = 0x06089E4A} */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x06013A4C] = 0x06026DBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6AD3\n"  /* mov r13,r10 */
    ".word 0x66C3\n"  /* mov r12,r6 */
    ".word 0x9548\n"  /* mov.w @(0x90,PC),r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x85AC\n"  /* mov.w @(0x18,r10),r0 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06013A50] = 0x06026F2A} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x9542\n"  /* mov.w @(0x84,PC),r5 */
    ".word 0x64B1\n"  /* mov.w @r11,r4 */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x06013A54] = 0x06027552} */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x04C7\n"  /* mul.l r12,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x65A2\n"  /* mov.l @r10,r5 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0x85AC\n"  /* mov.w @(0x18,r10),r0 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06013A50] = 0x06026F2A} */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x64B1\n"  /* mov.w @r11,r4 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06013A58] = 0x06026EDE} */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x4418\n"  /* shll8 r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06013A5C] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE504\n"  /* mov #4,r5 */
    ".word 0x6A93\n"  /* mov r9,r10 */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x06013A60] = 0x06062338} */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06013A64] = 0x06031D8C} */
    ".word 0x349C\n"  /* add r9,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x06013A68] = 0x060622C0} */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x06013A6C] = 0x06031A28} */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x34AC\n"  /* add r10,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x7D20\n"  /* add #32,r13 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x06013A70] = 0x06089EDC} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06013A70] = 0x06089EDC} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x3D12\n"  /* cmp/hs r1,r13 */
    ".word 0x8FBF\n"  /* bf/s 0x06013990 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x7F08\n"  /* add #8,r15 */
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
    ".word 0x4CCC\n"  /* .word 0x4CCC */
    ".word 0x03A0\n"  /* .word 0x03A0 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x07AE\n"  /* mov.l @(r0,r10),r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF4\n"  /* .word 0x4AF4 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF2\n"  /* .word 0x4AF2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E0C\n"  /* extu.b r0,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD5C\n"  /* bra 0x06013502 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E4A\n"  /* mov.w @(0x94,PC),r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D8C\n"  /* mov.l r8,@(0x30,r13) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x22C0\n"  /* mov.b r12,@r2 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A28\n"  /* mov.l r2,@(0x20,r10) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
);
/* FUN_06013A74: moved to subsystem_counter.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06013B04, \"ax\"\n"

    ".global _FUN_06013B04\n"
    ".type _FUN_06013B04, @function\n"
    "_FUN_06013B04:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDB26\n"  /* mov.l @(0x98,PC),r11  {[0x06013BA8] = 0x0601D5F4} */
    ".word 0xDC26\n"  /* mov.l @(0x98,PC),r12  {[0x06013BAC] = 0x06084FB4} */
    ".word 0xDE27\n"  /* mov.l @(0x9C,PC),r14  {[0x06013BB0] = 0x06084AF6} */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E31\n"  /* mov.w r3,@r14 */
    ".word 0xB18F\n"  /* bsr 0x06013E3C */
    ".word 0x0009\n"  /* nop */
    ".word 0xB325\n"  /* bsr 0x0601416C */
    ".word 0x0009\n"  /* nop */
    ".word 0x64E1\n"  /* mov.w @r14,r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x74E1\n"  /* add #-31,r4 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8900\n"  /* bt 0x06013B2E */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0x3322\n"  /* cmp/hs r2,r3 */
    ".word 0x8963\n"  /* bt 0x06013C04 */
    ".word 0xE01F\n"  /* mov #31,r0 */
    ".word 0x2049\n"  /* and r4,r0 */
    ".word 0x881F\n"  /* cmp/eq #31,r0 */
    ".word 0x8B5F\n"  /* bf 0x06013C04 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4001\n"  /* shlr r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8B3F\n"  /* bf 0x06013BD0 */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x06013BB4] = 0x06084FB8} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893A\n"  /* bt 0x06013BD0 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06013BB8] = 0x06018E70} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD16\n"  /* mov.l @(0x58,PC),r13  {[0x06013BBC] = 0xAE1000FF} */
    ".word 0xE325\n"  /* mov #37,r3 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x3232\n"  /* cmp/hs r3,r2 */
    ".word 0x8904\n"  /* bt 0x06013B74 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06013BC0] = 0x060190F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA00D\n"  /* bra 0x06013B8E */
    ".word 0x6ED3\n"  /* mov r13,r14 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0xE344\n"  /* mov #68,r3 */
    ".word 0x3232\n"  /* cmp/hs r3,r2 */
    ".word 0x8904\n"  /* bt 0x06013B86 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06013BC4] = 0x0601914C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA003\n"  /* bra 0x06013B8C */
    ".word 0x0009\n"  /* nop */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06013BC8] = 0x06019188} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6ED3\n"  /* mov r13,r14 */
    ".word 0x65C2\n"  /* mov.l @r12,r5 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06013BCC] = 0x0605B294} */
    ".word 0x75FF\n"  /* add #-1,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4518\n"  /* shll8 r5 */
    ".word 0x35EC\n"  /* add r14,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA02F\n"  /* bra 0x06013C04 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06013F7C] = 0x06026E60} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FB4\n"  /* .word 0x4FB4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF6\n"  /* .word 0x4AF6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4FB8\n"  /* .word 0x4FB8 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06018E70 */
    ".word 0x8E70\n"  /* .word 0x8E70 */
    ".word 0xAE10\n"  /* bra 0x060137E0 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_060190F4 */
    ".word 0x90F4\n"  /* mov.w @(0x1E8,PC),r0 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601914C */
    ".word 0x914C\n"  /* mov.w @(0x98,PC),r1 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06019188 */
    ".word 0x9188\n"  /* mov.w @(0x110,PC),r1 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB294\n"  /* bsr 0x060140FA */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x4209\n"  /* shlr2 r2 */
    ".word 0x4209\n"  /* shlr2 r2 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x3232\n"  /* cmp/hs r3,r2 */
    ".word 0x8912\n"  /* bt 0x06013C04 */
    ".word 0x4409\n"  /* shlr2 r4 */
    ".word 0xDE18\n"  /* mov.l @(0x60,PC),r14  {[0x06013C44] = 0x06084B14} */
    ".word 0x4409\n"  /* shlr2 r4 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x3E4C\n"  /* add r4,r14 */
    ".word 0x6EE0\n"  /* mov.b @r14,r14 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x7EBF\n"  /* add #-65,r14 */
    ".word 0x4E11\n"  /* cmp/pz r14 */
    ".word 0x8B05\n"  /* bf 0x06013BFE */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06013C48] = 0x0605B0FC} */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0xA001\n"  /* bra 0x06013C00 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD513\n"  /* mov.l @(0x4C,PC),r5  {[0x06013C4C] = 0xAB1102FF} */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE307\n"  /* mov #7,r3 */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x06013C50] = 0x06084AF2} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x06013C54] = 0x06084AF6} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA000\n"  /* bra 0x06013C20 */
    ".word 0x0009\n"  /* nop */
);
/* FUN_06013C20: moved to subsystem_counter.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06013E14, \"ax\"\n"

    ".global _FUN_06013E14\n"
    ".type _FUN_06013E14, @function\n"
    "_FUN_06013E14:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06013E34] = 0x0607EBC8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xC91F\n"  /* and #0x1F,r0 */
    ".word 0x6E0F\n"  /* exts.w r0,r14 */
    ".word 0x3E27\n"  /* cmp/gt r2,r14 */
    ".word 0x8B06\n"  /* bf 0x06013E30 */
    ".word 0x4E18\n"  /* shll8 r14 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x64EF\n"  /* exts.w r14,r4 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x06013E38] = 0x06026EDE} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBC8\n"  /* mov #-56,r11 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06013E7A, \"ax\"\n"

    ".global _FUN_06013E7A\n"
    ".type _FUN_06013E7A, @function\n"
    "_FUN_06013E7A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x9564\n"  /* mov.w @(0xC8,PC),r5 */
    ".word 0x64D1\n"  /* mov.w @r13,r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x04E7\n"  /* mul.l r14,r4 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x955F\n"  /* mov.w @(0xBE,PC),r5 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD338\n"  /* mov.l @(0xE0,PC),r3  {[0x06013F70] = 0x06026E2E} */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x85CC\n"  /* mov.w @(0x18,r12),r0 */
    ".word 0x490B\n"  /* jsr @r9 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x65D1\n"  /* mov.w @r13,r5 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x05E7\n"  /* mul.l r14,r5 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54C1\n"  /* mov.l @(0x4,r12),r4 */
    ".word 0x1F03\n"  /* mov.l r0,@(0xC,r15) */
    ".word 0x65D1\n"  /* mov.w @r13,r5 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x05E7\n"  /* mul.l r14,r5 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54C2\n"  /* mov.l @(0x8,r12),r4 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x3308\n"  /* sub r0,r3 */
    ".word 0x1F32\n"  /* mov.l r3,@(0x8,r15) */
    ".word 0x65D1\n"  /* mov.w @r13,r5 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x05E7\n"  /* mul.l r14,r5 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54C3\n"  /* mov.l @(0xC,r12),r4 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x06013F70] = 0x06026E2E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54F3\n"  /* mov.l @(0xC,r15),r4 */
    ".word 0x85CC\n"  /* mov.w @(0x18,r12),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x490B\n"  /* jsr @r9 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x85CD\n"  /* mov.w @(0x1A,r12),r0 */
    ".word 0x63D1\n"  /* mov.w @r13,r3 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x0437\n"  /* mul.l r3,r4 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x06013F74] = 0x06026E94} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x85CE\n"  /* mov.w @(0x1C,r12),r0 */
    ".word 0x63D1\n"  /* mov.w @r13,r3 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x0437\n"  /* mul.l r3,r4 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x06013F78] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x85CF\n"  /* mov.w @(0x1E,r12),r0 */
    ".word 0x63D1\n"  /* mov.w @r13,r3 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x0437\n"  /* mul.l r3,r4 */
    ".word 0x490B\n"  /* jsr @r9 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x65D1\n"  /* mov.w @r13,r5 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x05E7\n"  /* mul.l r14,r5 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54C4\n"  /* mov.l @(0x10,r12),r4 */
    ".word 0x9C1B\n"  /* mov.w @(0x36,PC),r12 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06013F7C] = 0x06026E60} */
    ".word 0x3C0C\n"  /* add r0,r12 */
    ".word 0x66C3\n"  /* mov r12,r6 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0xE504\n"  /* mov #4,r5 */
    ".word 0x6C83\n"  /* mov r8,r12 */
    ".word 0xD416\n"  /* mov.l @(0x58,PC),r4  {[0x06013F80] = 0x06062338} */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06013F84] = 0x06031D8C} */
    ".word 0x348C\n"  /* add r8,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x06013F88] = 0x060622C0} */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06013F8C] = 0x06031A28} */
    ".word 0x6551\n"  /* mov.w @r5,r5 */
    ".word 0x34CC\n"  /* add r12,r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x06013F90] = 0x06089EDC} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0xA027\n"  /* bra 0x06013F94 */
    ".word 0x0009\n"  /* nop */
    ".word 0x03A0\n"  /* .word 0x03A0 */
    ".word 0x051E\n"  /* mov.l @(r0,r1),r5 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x4CCC\n"  /* .word 0x4CCC */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AF6\n"  /* .word 0x4AF6 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E0C\n"  /* extu.b r0,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD5C\n"  /* bra 0x06013A22 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E4A\n"  /* mov.w @(0x94,PC),r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026E94 */
    ".word 0x6E94\n"  /* mov.b @r9+,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D8C\n"  /* mov.l r8,@(0x30,r13) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x22C0\n"  /* mov.b r12,@r2 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A28\n"  /* mov.l r2,@(0x20,r10) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x72D0\n"  /* add #-48,r2 */
    ".word 0x7A20\n"  /* add #32,r10 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06013FC0] = 0x06089EDC} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x3A12\n"  /* cmp/hs r1,r10 */
    ".word 0x8D02\n"  /* bt/s 0x06013FA8 */
    ".word 0x7804\n"  /* add #4,r8 */
    ".word 0xAF65\n"  /* bra 0x06013E72 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F10\n"  /* add #16,r15 */
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
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
);

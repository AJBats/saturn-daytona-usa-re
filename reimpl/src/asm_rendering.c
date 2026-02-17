__asm__(



    ".balign 2\n"











    ".section .text.FUN_060201B8, \"ax\"\n"

    ".global _FUN_060201B8\n"
    ".type _FUN_060201B8, @function\n"
    "_FUN_060201B8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDD2A\n"  /* mov.l @(0xA8,PC),r13  {[0x0602026C] = 0x06087808} */
    ".word 0xDE2B\n"  /* mov.l @(0xAC,PC),r14  {[0x06020270] = 0x06087806} */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06020274] = 0x06063D9A} */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x934F\n"  /* mov.w @(0x9E,PC),r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8902\n"  /* bt 0x060201D8 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x06020278] = 0x0608780A} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xDC28\n"  /* mov.l @(0xA0,PC),r12  {[0x0602027C] = 0x0605F4A8} */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8939\n"  /* bt 0x06020258 */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B35\n"  /* bf 0x06020258 */
    ".word 0xB626\n"  /* bsr 0x06020E3C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x880F\n"  /* cmp/eq #15,r0 */
    ".word 0x892F\n"  /* bt 0x06020258 */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0xD220\n"  /* mov.l @(0x80,PC),r2  {[0x06020280] = 0x0608782C} */
    ".word 0x60E1\n"  /* mov.w @r14,r0 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x02CD\n"  /* mov.w @(r0,r12),r2 */
    ".word 0x2520\n"  /* mov.b r2,@r5 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x8532\n"  /* mov.w @(0x4,r3),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x0534\n"  /* mov.b r3,@(r0,r5) */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x8531\n"  /* mov.w @(0x2,r3),r0 */
    ".word 0x6103\n"  /* mov r0,r1 */
    ".word 0x2D11\n"  /* mov.w r1,@r13 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E31\n"  /* mov.w r3,@r14 */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B01\n"  /* bf 0x06020258 */
    ".word 0xAFCA\n"  /* bra 0x060201EC */
    ".word 0x0009\n"  /* nop */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0xB573\n"  /* bsr 0x06020D46 */
    ".word 0x2D21\n"  /* mov.w r2,@r13 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA00D\n"  /* bra 0x06020284 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7808\n"  /* add #8,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7806\n"  /* add #6,r8 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x780A\n"  /* add #10,r8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xF4A8\n"  /* .word 0xF4A8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x782C\n"  /* add #44,r8 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06020284, \"ax\"\n"

    ".global _FUN_06020284\n"
    ".type _FUN_06020284, @function\n"
    "_FUN_06020284:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x67F3\n"  /* mov r15,r7 */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x06020320] = 0x0605F526} */
    ".word 0xD621\n"  /* mov.l @(0x84,PC),r6  {[0x06020314] = 0x06063D98} */
    ".word 0xD521\n"  /* mov.l @(0x84,PC),r5  {[0x06020318] = 0x06087826} */
    ".word 0xD422\n"  /* mov.l @(0x88,PC),r4  {[0x0602031C] = 0x06087825} */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06020324] = 0x06035228} */
    ".word 0x7704\n"  /* add #4,r7 */
    ".word 0x7104\n"  /* add #4,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x8561\n"  /* mov.w @(0x2,r6),r0 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x06020328] = 0x00008000} */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8908\n"  /* bt 0x060202BE */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0xE319\n"  /* mov #25,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B01\n"  /* bf 0x060202BE */
    ".word 0xE319\n"  /* mov #25,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0x8561\n"  /* mov.w @(0x2,r6),r0 */
    ".word 0x9326\n"  /* mov.w @(0x4C,PC),r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8907\n"  /* bt 0x060202DC */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8901\n"  /* bt 0x060202DC */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x8561\n"  /* mov.w @(0x2,r6),r0 */
    ".word 0x9218\n"  /* mov.w @(0x30,PC),r2 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8908\n"  /* bt 0x060202FC */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0x027C\n"  /* mov.b @(r0,r7),r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x3320\n"  /* cmp/eq r2,r3 */
    ".word 0x8B02\n"  /* bf 0x060202FC */
    ".word 0x6250\n"  /* mov.b @r5,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2520\n"  /* mov.b r2,@r5 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B02\n"  /* bf 0x06020308 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0602032C] = 0x06087824} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7826\n"  /* add #38,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7825\n"  /* add #37,r8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xF526\n"  /* .word 0xF526 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5228\n"  /* mov.l @(0x20,r2),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7824\n"  /* add #36,r8 */
);
/* FUN_06020330: moved to slot_clear.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06020430, \"ax\"\n"

    ".global _FUN_06020430\n"
    ".type _FUN_06020430, @function\n"
    "_FUN_06020430:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0x9A38\n"  /* mov.w @(0x70,PC),r10 */
    ".word 0xDC1D\n"  /* mov.l @(0x74,PC),r12  {[0x060204AC] = 0x0605F44E} */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0x6BC3\n"  /* mov r12,r11 */
    ".word 0x69C3\n"  /* mov r12,r9 */
    ".word 0x1F71\n"  /* mov.l r7,@(0x4,r15) */
    ".word 0x7B04\n"  /* add #4,r11 */
    ".word 0x1F62\n"  /* mov.l r6,@(0x8,r15) */
    ".word 0x63F0\n"  /* mov.b @r15,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8F24\n"  /* bf/s 0x06020494 */
    ".word 0x7906\n"  /* add #6,r9 */
    ".word 0x60DC\n"  /* extu.b r13,r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0x8820\n"  /* cmp/eq #32,r0 */
    ".word 0x8B04\n"  /* bf 0x06020466 */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0x2B31\n"  /* mov.w r3,@r11 */
    ".word 0x62ED\n"  /* extu.w r14,r2 */
    ".word 0xA008\n"  /* bra 0x06020476 */
    ".word 0x2921\n"  /* mov.w r2,@r9 */
    ".word 0x654C\n"  /* extu.b r4,r5 */
    ".word 0x75C0\n"  /* add #-64,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x635D\n"  /* extu.w r5,r3 */
    ".word 0x2B31\n"  /* mov.w r3,@r11 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x2951\n"  /* mov.w r5,@r9 */
    ".word 0x67A3\n"  /* mov r10,r7 */
    ".word 0x668D\n"  /* extu.w r8,r6 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x060204B0] = 0x06028400} */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x7D01\n"  /* add #1,r13 */
    ".word 0x62F0\n"  /* mov.b @r15,r2 */
    ".word 0x63DC\n"  /* extu.b r13,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8FDC\n"  /* bf/s 0x0602044C */
    ".word 0x7801\n"  /* add #1,r8 */
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
    ".word 0x3C79\n"  /* .word 0x3C79 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xF44E\n"  /* .word 0xF44E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
);
__asm__(



    ".balign 2\n"
    ".global _object_list_iterator\n"
    ".type _object_list_iterator, @function\n"









    ".section .text.FUN_060204B4, \"ax\"\n"

    ".global _FUN_060204B4\n"
    "_object_list_iterator:\n"
    "_FUN_060204B4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06020514] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06020518] = 0x060032D4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xA490\n"  /* bra 0x06020DEE */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".size _object_list_iterator, .-_object_list_iterator\n"
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060204D0, \"ax\"\n"

    ".global _FUN_060204D0\n"
    ".type _FUN_060204D0, @function\n"
    "_FUN_060204D0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xDE10\n"  /* mov.l @(0x40,PC),r14  {[0x0602051C] = 0x06087814} */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x06020520] = 0x00180000} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x6633\n"  /* mov r3,r6 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06020524] = 0x06014884} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06020528] = 0x00980000} */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B0A\n"  /* bf 0x06020508 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0xB47B\n"  /* bsr 0x06020DEE */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xD60B\n"  /* mov.l @(0x2C,PC),r6  {[0x06020528] = 0x00980000} */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06020524] = 0x06014884} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060032D4 */
    ".word 0x32D4\n"  /* .word 0x32D4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7814\n"  /* add #20,r8 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014884 */
    ".word 0x4884\n"  /* .word 0x4884 */
    ".word 0x0098\n"  /* .word 0x0098 */
    ".word 0x0000\n"  /* .word 0x0000 */
);
__asm__(



    ".balign 2\n"
    ".global _object_visibility_test\n"
    ".type _object_visibility_test, @function\n"









    ".section .text.FUN_0602052C, \"ax\"\n"

    ".global _FUN_0602052C\n"
    "_object_visibility_test:\n"
    "_FUN_0602052C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x80F4\n"  /* mov.b r0,@(0x4,r15) */
    ".word 0xD231\n"  /* mov.l @(0xC4,PC),r2  {[0x06020600] = 0x06087804} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x06020604] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD330\n"  /* mov.l @(0xC0,PC),r3  {[0x06020608] = 0x060032D4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD330\n"  /* mov.l @(0xC0,PC),r3  {[0x0602060C] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x0602060C] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xDE2E\n"  /* mov.l @(0xB8,PC),r14  {[0x06020610] = 0x0602761E} */
    ".word 0xD52E\n"  /* mov.l @(0xB8,PC),r5  {[0x06020614] = 0x0604898C} */
    ".word 0xD42F\n"  /* mov.l @(0xBC,PC),r4  {[0x06020618] = 0x25F006E0} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD52E\n"  /* mov.l @(0xB8,PC),r5  {[0x0602061C] = 0x060489AC} */
    ".word 0xD42F\n"  /* mov.l @(0xBC,PC),r4  {[0x06020620] = 0x25F00300} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD22E\n"  /* mov.l @(0xB8,PC),r2  {[0x06020624] = 0x060489CC} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0xD42E\n"  /* mov.l @(0xB8,PC),r4  {[0x06020628] = 0x25F00400} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD42D\n"  /* mov.l @(0xB4,PC),r4  {[0x0602062C] = 0x25F00060} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xDD2C\n"  /* mov.l @(0xB0,PC),r13  {[0x06020630] = 0x06063750} */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xDE2C\n"  /* mov.l @(0xB0,PC),r14  {[0x06020634] = 0x06028400} */
    ".word 0x9736\n"  /* mov.w @(0x6C,PC),r7 */
    ".word 0x37DC\n"  /* add r13,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06020638] = 0x00008000} */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x972D\n"  /* mov.w @(0x5A,PC),r7 */
    ".word 0x37DC\n"  /* add r13,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x962A\n"  /* mov.w @(0x54,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x9726\n"  /* mov.w @(0x4C,PC),r7 */
    ".word 0x37DC\n"  /* add r13,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x9323\n"  /* mov.w @(0x46,PC),r3 */
    ".word 0x9623\n"  /* mov.w @(0x46,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xDE1E\n"  /* mov.l @(0x78,PC),r14  {[0x0602063C] = 0x06014884} */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xDE19\n"  /* mov.l @(0x64,PC),r14  {[0x06020640] = 0x06038BD4} */
    ".word 0x9410\n"  /* mov.w @(0x20,PC),r4 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xE504\n"  /* mov #4,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0xE505\n"  /* mov #5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE506\n"  /* mov #6,r5 */
    ".word 0xA029\n"  /* bra 0x06020644 */
    ".word 0xE410\n"  /* mov #16,r4 */
    ".word 0x0558\n"  /* .word 0x0558 */
    ".word 0x0560\n"  /* .word 0x0560 */
    ".word 0x0294\n"  /* mov.b r9,@(r0,r2) */
    ".word 0x0550\n"  /* .word 0x0550 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0082\n"  /* .word 0x0082 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7804\n"  /* add #4,r8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060032D4 */
    ".word 0x32D4\n"  /* .word 0x32D4 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x898C\n"  /* bt 0x06020532 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x06E0\n"  /* .word 0x06E0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x89AC\n"  /* bt 0x0602057A */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0300\n"  /* .word 0x0300 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x89CC\n"  /* bt 0x060205C2 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0400\n"  /* .word 0x0400 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014884 */
    ".word 0x4884\n"  /* .word 0x4884 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038BD4 */
    ".word 0x8BD4\n"  /* bf 0x060205EE */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE507\n"  /* mov #7,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x060206C8] = 0x06059F6F} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x84F4\n"  /* mov.b @(0x4,r15),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xB3C9\n"  /* bsr 0x06020DEE */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0xDE1B\n"  /* mov.l @(0x6C,PC),r14  {[0x060206CC] = 0x06087820} */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x060206D0] = 0x00040000} */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x060206D4] = 0x06087818} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x060206D8] = 0x0608781C} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x060206DC] = 0x00030000} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x060206E0] = 0x00B00000} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x060206E4] = 0x06027552} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x060206E8] = 0x0602755C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x060206EC] = 0x06087810} */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x060206F0] = 0xFFFF0000} */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x060206F4] = 0x00700000} */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x060206E4] = 0x06027552} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x060206E8] = 0x0602755C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x060206F8] = 0x06087814} */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x060206FC] = 0x0603850C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x060206D8] = 0x0608781C} */
    ".word 0xD40B\n"  /* mov.l @(0x2C,PC),r4  {[0x060206D4] = 0x06087818} */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06020700] = 0x06038794} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x060206F8] = 0x06087814} */
    ".word 0xD40E\n"  /* mov.l @(0x38,PC),r4  {[0x060206EC] = 0x06087810} */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06020704] = 0x06038642} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06020708] = 0x06038520} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F6F\n"  /* mov.w @(0xDE,PC),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7820\n"  /* add #32,r8 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7818\n"  /* add #24,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x781C\n"  /* add #28,r8 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7810\n"  /* add #16,r8 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0070\n"  /* .word 0x0070 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7814\n"  /* add #20,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x850C\n"  /* mov.w @(0x18,r0),r0 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038794 */
    ".word 0x8794\n"  /* .word 0x8794 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038642 */
    ".word 0x8642\n"  /* .word 0x8642 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x8520\n"  /* mov.w @(0x0,r2),r0 */
    ".size _object_visibility_test, .-_object_visibility_test\n"
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602070C, \"ax\"\n"

    ".global _FUN_0602070C\n"
    ".type _FUN_0602070C, @function\n"
    "_FUN_0602070C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDD2D\n"  /* mov.l @(0xB4,PC),r13  {[0x060207D0] = 0x06087818} */
    ".word 0x2F40\n"  /* mov.b r4,@r15 */
    ".word 0xD32D\n"  /* mov.l @(0xB4,PC),r3  {[0x060207D4] = 0x0603850C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xDC2D\n"  /* mov.l @(0xB4,PC),r12  {[0x060207D8] = 0x00008000} */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x32C8\n"  /* sub r12,r2 */
    ".word 0x2D22\n"  /* mov.l r2,@r13 */
    ".word 0xDE2C\n"  /* mov.l @(0xB0,PC),r14  {[0x060207DC] = 0x0608781C} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x33C8\n"  /* sub r12,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x6533\n"  /* mov r3,r5 */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x060207E0] = 0x06038794} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D2\n"  /* mov.l @r13,r4 */
    ".word 0xDE2A\n"  /* mov.l @(0xA8,PC),r14  {[0x060207E4] = 0x06087820} */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x32C8\n"  /* sub r12,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0xDB28\n"  /* mov.l @(0xA0,PC),r11  {[0x060207E8] = 0x06087810} */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x060207EC] = 0x00010000} */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B23\n"  /* bf 0x06020794 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x060207F0] = 0xFFFF0000} */
    ".word 0xD428\n"  /* mov.l @(0xA0,PC),r4  {[0x060207F4] = 0x00B00000} */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x060207F8] = 0x06027552} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x060207FC] = 0x0602755C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x6C03\n"  /* mov r0,r12 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x060207F0] = 0xFFFF0000} */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x06020800] = 0x00700000} */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x060207F8] = 0x06027552} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x060207FC] = 0x0602755C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0xD722\n"  /* mov.l @(0x88,PC),r7  {[0x06020804] = 0x06087814} */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x6372\n"  /* mov.l @r7,r3 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x3538\n"  /* sub r3,r5 */
    ".word 0x2BC2\n"  /* mov.l r12,@r11 */
    ".word 0x2762\n"  /* mov.l r6,@r7 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06020808] = 0x06038642} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xA007\n"  /* bra 0x060207A2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0602080C] = 0x06014884} */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2B22\n"  /* mov.l r2,@r11 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06020810] = 0x06038520} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x060207EC] = 0x00010000} */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8908\n"  /* bt 0x060207C2 */
    ".word 0x64F0\n"  /* mov.b @r15,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA316\n"  /* bra 0x06020DEE */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7818\n"  /* add #24,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x850C\n"  /* mov.w @(0x18,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x781C\n"  /* add #28,r8 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038794 */
    ".word 0x8794\n"  /* .word 0x8794 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7820\n"  /* add #32,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7810\n"  /* add #16,r8 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x0070\n"  /* .word 0x0070 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7814\n"  /* add #20,r8 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038642 */
    ".word 0x8642\n"  /* .word 0x8642 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014884 */
    ".word 0x4884\n"  /* .word 0x4884 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x8520\n"  /* mov.w @(0x0,r2),r0 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06020814, \"ax\"\n"

    ".global _FUN_06020814\n"
    ".type _FUN_06020814, @function\n"
    "_FUN_06020814:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD337\n"  /* mov.l @(0xDC,PC),r3  {[0x06020900] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x80F4\n"  /* mov.b r0,@(0x4,r15) */
    ".word 0xD336\n"  /* mov.l @(0xD8,PC),r3  {[0x06020904] = 0x060032D4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD536\n"  /* mov.l @(0xD8,PC),r5  {[0x06020908] = 0x060489CC} */
    ".word 0xD436\n"  /* mov.l @(0xD8,PC),r4  {[0x0602090C] = 0x25F00200} */
    ".word 0xD337\n"  /* mov.l @(0xDC,PC),r3  {[0x06020910] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xDD36\n"  /* mov.l @(0xD8,PC),r13  {[0x06020914] = 0x06063750} */
    ".word 0xDE37\n"  /* mov.l @(0xDC,PC),r14  {[0x06020918] = 0x06028400} */
    ".word 0x9753\n"  /* mov.w @(0xA6,PC),r7 */
    ".word 0x37DC\n"  /* add r13,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x9650\n"  /* mov.w @(0xA0,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xEB00\n"  /* mov #0,r11 */
    ".word 0xDC32\n"  /* mov.l @(0xC8,PC),r12  {[0x0602091C] = 0x0605B6D8} */
    ".word 0xD333\n"  /* mov.l @(0xCC,PC),r3  {[0x06020920] = 0x04000000} */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0x2C22\n"  /* mov.l r2,@r12 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0xD231\n"  /* mov.l @(0xC4,PC),r2  {[0x06020924] = 0x0608780C} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x06020928] = 0x0605A00C} */
    ".word 0x23B2\n"  /* mov.l r11,@r3 */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x0602092C] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD22D\n"  /* mov.l @(0xB4,PC),r2  {[0x06020920] = 0x04000000} */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06020924] = 0x0608780C} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06020928] = 0x0605A00C} */
    ".word 0x23B2\n"  /* mov.l r11,@r3 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x0602092C] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9732\n"  /* mov.w @(0x64,PC),r7 */
    ".word 0x37DC\n"  /* add r13,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x932F\n"  /* mov.w @(0x5E,PC),r3 */
    ".word 0x962F\n"  /* mov.w @(0x5E,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x972A\n"  /* mov.w @(0x54,PC),r7 */
    ".word 0x962A\n"  /* mov.w @(0x54,PC),r6 */
    ".word 0xD524\n"  /* mov.l @(0x90,PC),r5  {[0x06020930] = 0x0604BBCC} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x9727\n"  /* mov.w @(0x4E,PC),r7 */
    ".word 0x37DC\n"  /* add r13,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x9324\n"  /* mov.w @(0x48,PC),r3 */
    ".word 0x9624\n"  /* mov.w @(0x48,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x971F\n"  /* mov.w @(0x3E,PC),r7 */
    ".word 0x37DC\n"  /* add r13,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x961C\n"  /* mov.w @(0x38,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06020934] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06020938] = 0x06087828} */
    ".word 0x23B1\n"  /* mov.w r11,@r3 */
    ".word 0x84F4\n"  /* mov.b @(0x4,r15),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA02B\n"  /* bra 0x0602093C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0560\n"  /* .word 0x0560 */
    ".word 0x0294\n"  /* mov.b r9,@(r0,r2) */
    ".word 0x0550\n"  /* .word 0x0550 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0082\n"  /* .word 0x0082 */
    ".word 0x7C5A\n"  /* add #90,r12 */
    ".word 0x061A\n"  /* sts macl,r6 */
    ".word 0x0368\n"  /* .word 0x0368 */
    ".word 0x3000\n"  /* cmp/eq r0,r0 */
    ".word 0x0898\n"  /* .word 0x0898 */
    ".word 0x0378\n"  /* .word 0x0378 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x08B0\n"  /* .word 0x08B0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060032D4 */
    ".word 0x32D4\n"  /* .word 0x32D4 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x89CC\n"  /* bt 0x060208A6 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x060216D2 */
    ".word 0x0400\n"  /* .word 0x0400 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x780C\n"  /* add #12,r8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA00C\n"  /* bra 0x06020946 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0xBBCC\n"  /* bsr 0x060200CE */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7828\n"  /* add #40,r8 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA254\n"  /* bra 0x06020DEE */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06020950, \"ax\"\n"

    ".global _FUN_06020950\n"
    ".type _FUN_06020950, @function\n"
    "_FUN_06020950:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FA4\n"  /* add #-92,r15 */
    ".word 0xDC12\n"  /* mov.l @(0x48,PC),r12  {[0x060209A0] = 0x06028400} */
    ".word 0x6DF3\n"  /* mov r15,r13 */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x060209A4] = 0x0605F52A} */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x060209A8] = 0x06035228} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE05C\n"  /* mov #92,r0 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x66EC\n"  /* extu.b r14,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x66EC\n"  /* extu.b r14,r6 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x762C\n"  /* add #44,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x33B3\n"  /* cmp/ge r11,r3 */
    ".word 0x8BE8\n"  /* bf 0x06020964 */
    ".word 0x7F5C\n"  /* add #92,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xF52A\n"  /* .word 0xF52A */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5228\n"  /* mov.l @(0x20,r2),r2 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060209AC, \"ax\"\n"

    ".global _FUN_060209AC\n"
    ".type _FUN_060209AC, @function\n"
    "_FUN_060209AC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD914\n"  /* mov.l @(0x50,PC),r9  {[0x06020A14] = 0x0605F586} */
    ".word 0x9D23\n"  /* mov.w @(0x46,PC),r13 */
    ".word 0xDE14\n"  /* mov.l @(0x50,PC),r14  {[0x06020A18] = 0x06087828} */
    ".word 0x80F4\n"  /* mov.b r0,@(0x4,r15) */
    ".word 0xDC14\n"  /* mov.l @(0x50,PC),r12  {[0x06020A1C] = 0x00200000} */
    ".word 0x6390\n"  /* mov.b @r9,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B05\n"  /* bf 0x060209E0 */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x06020A20] = 0xAB1129FF} */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06020A24] = 0x0601D5F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x2920\n"  /* mov.b r2,@r9 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06020A28] = 0x12F2FC00} */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x06020A2C] = 0x25F800A4} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x9313\n"  /* mov.w @(0x26,PC),r3 */
    ".word 0x72F6\n"  /* add #-10,r2 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E31\n"  /* mov.w r3,@r14 */
    ".word 0xD50F\n"  /* mov.l @(0x3C,PC),r5  {[0x06020A30] = 0x25E5F800} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x614D\n"  /* extu.w r4,r1 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06020A34] = 0x06035C2C} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x385C\n"  /* add r5,r8 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8916\n"  /* bt 0x06020A38 */
    ".word 0xA016\n"  /* bra 0x06020A3A */
    ".word 0x63C3\n"  /* mov r12,r3 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xF586\n"  /* .word 0xF586 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7828\n"  /* add #40,r8 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAB11\n"  /* bra 0x06020046 */
    ".word 0x29FF\n"  /* muls.w r15,r9 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06020DF8] = 0x4308343C} */
    ".word 0x12F2\n"  /* mov.l r15,@(0x8,r2) */
    ".word 0xFC00\n"  /* .word 0xFC00 */
    ".word 0x25F8\n"  /* tst r15,r5 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0x25E5\n"  /* mov.w r14,@-r5 */
    ".word 0xF800\n"  /* .word 0xF800 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C2C\n"  /* mov.l @(0x30,r2),r12 */
    ".word 0xD332\n"  /* mov.l @(0xC8,PC),r3  {[0x06020B04] = 0xFFE00000} */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x61E1\n"  /* mov.w @r14,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x0317\n"  /* mul.l r1,r3 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x2832\n"  /* mov.l r3,@r8 */
    ".word 0x634D\n"  /* extu.w r4,r3 */
    ".word 0x33D3\n"  /* cmp/ge r13,r3 */
    ".word 0x8BD4\n"  /* bf 0x060209F6 */
    ".word 0xE20A\n"  /* mov #10,r2 */
    ".word 0x63E1\n"  /* mov.w @r14,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B43\n"  /* bf 0x06020ADE */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x06020B08] = 0x0605AD04} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06020B0C] = 0x06078637} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0x2019\n"  /* and r1,r0 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x06020B10] = 0x06087824} */
    ".word 0xD22A\n"  /* mov.l @(0xA8,PC),r2  {[0x06020B14] = 0x06085FF4} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0x2029\n"  /* and r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8920\n"  /* bt 0x06020ABA */
    ".word 0x9A3C\n"  /* mov.w @(0x78,PC),r10 */
    ".word 0xDB27\n"  /* mov.l @(0x9C,PC),r11  {[0x06020B18] = 0x06063750} */
    ".word 0xDC27\n"  /* mov.l @(0x9C,PC),r12  {[0x06020B1C] = 0x06028400} */
    ".word 0x973A\n"  /* mov.w @(0x74,PC),r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x9637\n"  /* mov.w @(0x6E,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x37AC\n"  /* add r10,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x9732\n"  /* mov.w @(0x64,PC),r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x962F\n"  /* mov.w @(0x5E,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x37AC\n"  /* add r10,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x972A\n"  /* mov.w @(0x54,PC),r7 */
    ".word 0x37BC\n"  /* add r11,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x9627\n"  /* mov.w @(0x4E,PC),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x37AC\n"  /* add r10,r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xBF44\n"  /* bsr 0x06020946 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2920\n"  /* mov.b r2,@r9 */
    ".word 0x84F4\n"  /* mov.b @(0x4,r15),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA188\n"  /* bra 0x06020DEE */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
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
    ".word 0x3000\n"  /* cmp/eq r0,r0 */
    ".word 0x0568\n"  /* .word 0x0568 */
    ".word 0x0498\n"  /* .word 0x0498 */
    ".word 0x0570\n"  /* .word 0x0570 */
    ".word 0x069C\n"  /* mov.b @(r0,r9),r6 */
    ".word 0x0578\n"  /* .word 0x0578 */
    ".word 0x0B1E\n"  /* mov.l @(r0,r1),r11 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFE0\n"  /* .word 0xFFE0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD04\n"  /* bra 0x06020516 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8637\n"  /* .word 0x8637 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7824\n"  /* add #36,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".global _FUN_06020b20\n"
    "_FUN_06020b20:\n"
    ".word 0x9611\n"  /* mov.w @(0x22,PC),r6 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xD709\n"  /* mov.l @(0x24,PC),r7  {[0x06020B4C] = 0x25E5F800} */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x06020B50] = 0x12F2FC00} */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x06020B54] = 0x25F800A4} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x930C\n"  /* mov.w @(0x18,PC),r3 */
    ".word 0x72F6\n"  /* add #-10,r2 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x645D\n"  /* extu.w r5,r4 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x634D\n"  /* extu.w r4,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8FF9\n"  /* bf/s 0x06020B34 */
    ".word 0x0756\n"  /* mov.l r5,@(r0,r7) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x25E5\n"  /* mov.w r14,@-r5 */
    ".word 0xF800\n"  /* .word 0xF800 */
    ".word 0x12F2\n"  /* mov.l r15,@(0x8,r2) */
    ".word 0xFC00\n"  /* .word 0xFC00 */
    ".word 0x25F8\n"  /* tst r15,r5 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06020B58, \"ax\"\n"

    ".global _FUN_06020B58\n"
    ".type _FUN_06020B58, @function\n"
    "_FUN_06020B58:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD427\n"  /* mov.l @(0x9C,PC),r4  {[0x06020C00] = 0x0607EBF4} */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0xCB01\n"  /* or #0x01,r0 */
    ".word 0xBFDA\n"  /* bsr 0x06020B20 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x06020C04] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xDB24\n"  /* mov.l @(0x90,PC),r11  {[0x06020C08] = 0x0605B6D8} */
    ".word 0xD225\n"  /* mov.l @(0x94,PC),r2  {[0x06020C0C] = 0x04000000} */
    ".word 0x63B2\n"  /* mov.l @r11,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06020C10] = 0x0608780C} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xDD23\n"  /* mov.l @(0x8C,PC),r13  {[0x06020C14] = 0x0605A00C} */
    ".word 0xDC24\n"  /* mov.l @(0x90,PC),r12  {[0x06020C18] = 0x06026CE0} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x2DE2\n"  /* mov.l r14,@r13 */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x06020C0C] = 0x04000000} */
    ".word 0x63B2\n"  /* mov.l @r11,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06020C10] = 0x0608780C} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x2DE2\n"  /* mov.l r14,@r13 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x06020C1C] = 0x06059F6F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06020C20] = 0x06085F8A} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06020C24] = 0x0607EBCC} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xB10F\n"  /* bsr 0x06020DD0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x06020C28] = 0x06063F5C} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x7210\n"  /* add #16,r2 */
    ".word 0x22E0\n"  /* mov.b r14,@r2 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x2DE2\n"  /* mov.l r14,@r13 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x2DE2\n"  /* mov.l r14,@r13 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06020D50, \"ax\"\n"

    ".global _FUN_06020D50\n"
    ".type _FUN_06020D50, @function\n"
    "_FUN_06020D50:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FDC\n"  /* add #-36,r15 */
    ".word 0x6CF3\n"  /* mov r15,r12 */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x06020DC8] = 0x0605F5A8} */
    ".word 0xDD1A\n"  /* mov.l @(0x68,PC),r13  {[0x06020DC4] = 0x0608782C} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06020DCC] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE024\n"  /* mov #36,r0 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x890E\n"  /* bt 0x06020D9C */
    ".word 0x60EC\n"  /* extu.b r14,r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x00DC\n"  /* mov.b @(r0,r13),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x03CE\n"  /* mov.l @(r0,r12),r3 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x32B3\n"  /* cmp/ge r11,r2 */
    ".word 0x8BDF\n"  /* bf 0x06020D64 */
    ".word 0x7F24\n"  /* add #36,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7C6C\n"  /* add #108,r12 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x85FC\n"  /* mov.w @(0x18,r15),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x80F8\n"  /* mov.b r0,@(0x8,r15) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA008\n"  /* bra 0x06020DD6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x782C\n"  /* add #44,r8 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xF5A8\n"  /* .word 0xF5A8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06020E84, \"ax\"\n"

    ".global _FUN_06020E84\n"
    ".type _FUN_06020E84, @function\n"
    "_FUN_06020E84:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDA2A\n"  /* mov.l @(0xA8,PC),r10  {[0x06020F34] = 0x06089594} */
    ".word 0xDB2B\n"  /* mov.l @(0xAC,PC),r11  {[0x06020F38] = 0x06078663} */
    ".word 0xDE2B\n"  /* mov.l @(0xAC,PC),r14  {[0x06020F3C] = 0x06087C84} */
    ".word 0xD42C\n"  /* mov.l @(0xB0,PC),r4  {[0x06020F40] = 0x06089595} */
    ".word 0x6040\n"  /* mov.b @r4,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D04\n"  /* bt/s 0x06020EA2 */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0xE30A\n"  /* mov #10,r3 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x60A0\n"  /* mov.b @r10,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8902\n"  /* bt 0x06020EB0 */
    ".word 0x63A0\n"  /* mov.b @r10,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x06020F44] = 0x0607E944} */
    ".word 0x903C\n"  /* mov.w @(0x78,PC),r0 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0xD223\n"  /* mov.l @(0x8C,PC),r2  {[0x06020F48] = 0x06089598} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x3320\n"  /* cmp/eq r2,r3 */
    ".word 0x8976\n"  /* bt 0x06020FAE */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x06020F4C] = 0x06083255} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B72\n"  /* bf 0x06020FAE */
    ".word 0x9932\n"  /* mov.w @(0x64,PC),r9 */
    ".word 0xDC21\n"  /* mov.l @(0x84,PC),r12  {[0x06020F50] = 0x06063750} */
    ".word 0xD01D\n"  /* mov.l @(0x74,PC),r0  {[0x06020F44] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x912D\n"  /* mov.w @(0x5A,PC),r1 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0xA061\n"  /* bra 0x06020F9A */
    ".word 0xC9CC\n"  /* and #0xCC,r0 */
    ".word 0x67C3\n"  /* mov r12,r7 */
    ".word 0x6693\n"  /* mov r9,r6 */
    ".word 0x7760\n"  /* add #96,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06020F54] = 0x06028400} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xA05F\n"  /* bra 0x06020FAE */
    ".word 0x0009\n"  /* nop */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x06020EFA */
    ".word 0xA001\n"  /* bra 0x06020EFC */
    ".word 0xE70B\n"  /* mov #11,r7 */
    ".word 0xE70A\n"  /* mov #10,r7 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x37CC\n"  /* add r12,r7 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8F02\n"  /* bf/s 0x06020F10 */
    ".word 0x6693\n"  /* mov r9,r6 */
    ".word 0xA001\n"  /* bra 0x06020F12 */
    ".word 0xE50B\n"  /* mov #11,r5 */
    ".word 0xE50A\n"  /* mov #10,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06020F54] = 0x06028400} */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x35CC\n"  /* add r12,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xA045\n"  /* bra 0x06020FAE */
    ".word 0x0009\n"  /* nop */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B16\n"  /* bf 0x06020F58 */
    ".word 0xA016\n"  /* bra 0x06020F5A */
    ".word 0xE70A\n"  /* mov #10,r7 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x0900\n"  /* .word 0x0900 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9594\n"  /* mov.w @(0x128,PC),r5 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8663\n"  /* .word 0x8663 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7C84\n"  /* add #-124,r12 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9595\n"  /* mov.w @(0x12A,PC),r5 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9598\n"  /* mov.w @(0x130,PC),r5 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3255\n"  /* dmulu.l r5,r2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0xE70B\n"  /* mov #11,r7 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x37CC\n"  /* add r12,r7 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8F02\n"  /* bf/s 0x06020F6E */
    ".word 0x6693\n"  /* mov r9,r6 */
    ".word 0xA001\n"  /* bra 0x06020F70 */
    ".word 0xE50A\n"  /* mov #10,r5 */
    ".word 0xE50B\n"  /* mov #11,r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06020FCC] = 0x06028400} */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x35CC\n"  /* add r12,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xA016\n"  /* bra 0x06020FAE */
    ".word 0x0009\n"  /* nop */
    ".word 0x67C3\n"  /* mov r12,r7 */
    ".word 0x6693\n"  /* mov r9,r6 */
    ".word 0x7748\n"  /* add #72,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06020FCC] = 0x06028400} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xA00A\n"  /* bra 0x06020FAE */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89F1\n"  /* bt 0x06020F82 */
    ".word 0x8844\n"  /* cmp/eq #68,r0 */
    ".word 0x89C0\n"  /* bt 0x06020F24 */
    ".word 0x9110\n"  /* mov.w @(0x20,PC),r1 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x89A3\n"  /* bt 0x06020EF0 */
    ".word 0x910E\n"  /* mov.w @(0x1C,PC),r1 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x8994\n"  /* bt 0x06020ED8 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x06020FD0] = 0x0607E944} */
    ".word 0x900B\n"  /* mov.w @(0x16,PC),r0 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x06020FD4] = 0x06089598} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06020FD8] = 0x06063E20} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x890C\n"  /* bt 0x06020FDC */
    ".word 0xA05F\n"  /* bra 0x06021084 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x00CC\n"  /* mov.b @(r0,r12),r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9598\n"  /* mov.w @(0x130,PC),r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E20\n"  /* cmp/eq r2,r14 */
    ".word 0x6CD3\n"  /* mov r13,r12 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x67A0\n"  /* mov.b @r10,r7 */
    ".word 0xE060\n"  /* mov #96,r0 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x060210A0] = 0x0604D3E0} */
    ".word 0xD42F\n"  /* mov.l @(0xBC,PC),r4  {[0x060210A4] = 0x0607E944} */
    ".word 0x677C\n"  /* extu.b r7,r7 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D01\n"  /* bt/s 0x06021018 */
    ".word 0x6772\n"  /* mov.l @r7,r7 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x933E\n"  /* mov.w @(0x7C,PC),r3 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8903\n"  /* bt 0x06021026 */
    ".word 0x933C\n"  /* mov.w @(0x78,PC),r3 */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x06021026 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x9039\n"  /* mov.w @(0x72,PC),r0 */
    ".word 0x0ED6\n"  /* mov.l r13,@(r0,r14) */
    ".word 0x65DC\n"  /* extu.b r13,r5 */
    ".word 0x3C4C\n"  /* add r4,r12 */
    ".word 0x635C\n"  /* extu.b r5,r3 */
    ".word 0x6283\n"  /* mov r8,r2 */
    ".word 0x3648\n"  /* sub r4,r6 */
    ".word 0x61C3\n"  /* mov r12,r1 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x317C\n"  /* add r7,r1 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x932F\n"  /* mov.w @(0x5E,PC),r3 */
    ".word 0x33EC\n"  /* add r14,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x635C\n"  /* extu.b r5,r3 */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x9227\n"  /* mov.w @(0x4E,PC),r2 */
    ".word 0x317C\n"  /* add r7,r1 */
    ".word 0x32EC\n"  /* add r14,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x7358\n"  /* add #88,r3 */
    ".word 0xE216\n"  /* mov #22,r2 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x635C\n"  /* extu.b r5,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8BE5\n"  /* bf 0x0602102C */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x060210A8] = 0x0603850C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x060210AC] = 0x06087C84} */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x060210B0] = 0x06038120} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x060210B4] = 0x06038520} */
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
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x1868\n"  /* mov.l r6,@(0x20,r8) */
    ".word 0x1810\n"  /* mov.l r1,@(0x0,r8) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0xD3E0\n"  /* mov.l @(0x380,PC),r3  {[0x06021424] = 0x0607EAD8} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x850C\n"  /* mov.w @(0x18,r0),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7C84\n"  /* add #-124,r12 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038120 */
    ".word 0x8120\n"  /* mov.w r0,@(0x0,r2) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x8520\n"  /* mov.w @(0x0,r2),r0 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060210B8, \"ax\"\n"

    ".global _FUN_060210B8\n"
    ".type _FUN_060210B8, @function\n"
    "_FUN_060210B8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0xED2C\n"  /* mov #44,r13 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDC13\n"  /* mov.l @(0x4C,PC),r12  {[0x06021114] = 0x06087C84} */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06021118] = 0x0603850C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x624C\n"  /* extu.b r4,r2 */
    ".word 0x931F\n"  /* mov.w @(0x3E,PC),r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x33CC\n"  /* add r12,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x22E2\n"  /* mov.l r14,@r2 */
    ".word 0x624C\n"  /* extu.b r4,r2 */
    ".word 0x32D3\n"  /* cmp/ge r13,r2 */
    ".word 0x8BF5\n"  /* bf 0x060210CE */
    ".word 0xD40C\n"  /* mov.l @(0x30,PC),r4  {[0x06021114] = 0x06087C84} */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0602111C] = 0x06038120} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06021120] = 0x06038520} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"
    ".global _object_render_list_builder\n"
    ".type _object_render_list_builder, @function\n"









    ".section .text.FUN_06022820, \"ax\"\n"

    ".global _FUN_06022820\n"
    "_object_render_list_builder:\n"
    "_FUN_06022820:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x7FD4\n"  /* add #-44,r15 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x964E\n"  /* mov.w @(0x9C,PC),r6 */
    ".word 0x6EF3\n"  /* mov r15,r14 */
    ".word 0x7E24\n"  /* add #36,r14 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x1F37\n"  /* mov.l r3,@(0x1C,r15) */
    ".word 0x6251\n"  /* mov.w @r5,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x7302\n"  /* add #2,r3 */
    ".word 0x1F33\n"  /* mov.l r3,@(0xC,r15) */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0x1F25\n"  /* mov.l r2,@(0x14,r15) */
    ".word 0x6121\n"  /* mov.w @r2,r1 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x1F36\n"  /* mov.l r3,@(0x18,r15) */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x1F22\n"  /* mov.l r2,@(0x8,r15) */
    ".word 0x6121\n"  /* mov.w @r2,r1 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0x7E06\n"  /* add #6,r14 */
    ".word 0x1FE8\n"  /* mov.l r14,@(0x20,r15) */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x7306\n"  /* add #6,r3 */
    ".word 0x1F34\n"  /* mov.l r3,@(0x10,r15) */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x2E21\n"  /* mov.w r2,@r14 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x7C04\n"  /* add #4,r12 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x720C\n"  /* add #12,r2 */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x7A18\n"  /* add #24,r10 */
    ".word 0x6B43\n"  /* mov r4,r11 */
    ".word 0x7B1C\n"  /* add #28,r11 */
    ".word 0x6D23\n"  /* mov r2,r13 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x7810\n"  /* add #16,r8 */
    ".word 0x6943\n"  /* mov r4,r9 */
    ".word 0x7914\n"  /* add #20,r9 */
    ".word 0x1FD1\n"  /* mov.l r13,@(0x4,r15) */
    ".word 0x6051\n"  /* mov.w @r5,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893C\n"  /* bt 0x06022910 */
    ".word 0x53F7\n"  /* mov.l @(0x1C,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8938\n"  /* bt 0x06022910 */
    ".word 0x6E42\n"  /* mov.l @r4,r14 */
    ".word 0x6DC2\n"  /* mov.l @r12,r13 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x62D3\n"  /* mov r13,r2 */
    ".word 0x4E00\n"  /* shll r14 */
    ".word 0x4D00\n"  /* shll r13 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8F0E\n"  /* bf/s 0x060228D4 */
    ".word 0x3D2C\n"  /* add r2,r13 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x24E2\n"  /* mov.l r14,@r4 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0xA010\n"  /* bra 0x060228F2 */
    ".word 0x2CD2\n"  /* mov.l r13,@r12 */
    ".word 0xFE6B\n"  /* .word 0xFE6B */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B09\n"  /* bf 0x060228F2 */
    ".word 0x63A2\n"  /* mov.l @r10,r3 */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x3D2C\n"  /* add r2,r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x24E2\n"  /* mov.l r14,@r4 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x2CD2\n"  /* mov.l r13,@r12 */
    ".word 0x6E42\n"  /* mov.l @r4,r14 */
    ".word 0x3E63\n"  /* cmp/ge r6,r14 */
    ".word 0x8B0B\n"  /* bf 0x06022910 */
    ".word 0x9230\n"  /* mov.w @(0x60,PC),r2 */
    ".word 0x3E27\n"  /* cmp/gt r2,r14 */
    ".word 0x8908\n"  /* bt 0x06022910 */
    ".word 0x6EC2\n"  /* mov.l @r12,r14 */
    ".word 0x3E63\n"  /* cmp/ge r6,r14 */
    ".word 0x8B05\n"  /* bf 0x06022910 */
    ".word 0x932B\n"  /* mov.w @(0x56,PC),r3 */
    ".word 0x3E37\n"  /* cmp/gt r3,r14 */
    ".word 0x8902\n"  /* bt 0x06022910 */
    ".word 0x53F7\n"  /* mov.l @(0x1C,r15),r3 */
    ".word 0x627F\n"  /* exts.w r7,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8943\n"  /* bt 0x060229A2 */
    ".word 0x53F3\n"  /* mov.l @(0xC,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893F\n"  /* bt 0x060229A2 */
    ".word 0x6EF2\n"  /* mov.l @r15,r14 */
    ".word 0x5DF1\n"  /* mov.l @(0x4,r15),r13 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x4E00\n"  /* shll r14 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x63D3\n"  /* mov r13,r3 */
    ".word 0x4D00\n"  /* shll r13 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022960 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x3D2C\n"  /* add r2,r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x23D2\n"  /* mov.l r13,@r3 */
    ".word 0xA012\n"  /* bra 0x06022980 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x6251\n"  /* mov.w @r5,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B0B\n"  /* bf 0x06022980 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x3D2C\n"  /* add r2,r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x23D2\n"  /* mov.l r13,@r3 */
    ".word 0x6EF2\n"  /* mov.l @r15,r14 */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x3E63\n"  /* cmp/ge r6,r14 */
    ".word 0x8B0C\n"  /* bf 0x060229A2 */
    ".word 0x922C\n"  /* mov.w @(0x58,PC),r2 */
    ".word 0x3E27\n"  /* cmp/gt r2,r14 */
    ".word 0x8909\n"  /* bt 0x060229A2 */
    ".word 0x5EF1\n"  /* mov.l @(0x4,r15),r14 */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x3E63\n"  /* cmp/ge r6,r14 */
    ".word 0x8B05\n"  /* bf 0x060229A2 */
    ".word 0x9226\n"  /* mov.w @(0x4C,PC),r2 */
    ".word 0x3E27\n"  /* cmp/gt r2,r14 */
    ".word 0x8902\n"  /* bt 0x060229A2 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893D\n"  /* bt 0x06022A28 */
    ".word 0x53F6\n"  /* mov.l @(0x18,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8939\n"  /* bt 0x06022A28 */
    ".word 0x6E82\n"  /* mov.l @r8,r14 */
    ".word 0x6D92\n"  /* mov.l @r9,r13 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x62D3\n"  /* mov r13,r2 */
    ".word 0x4E00\n"  /* shll r14 */
    ".word 0x4D00\n"  /* shll r13 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x53F4\n"  /* mov.l @(0x10,r15),r3 */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8F0D\n"  /* bf/s 0x060229E8 */
    ".word 0x3D2C\n"  /* add r2,r13 */
    ".word 0x63A2\n"  /* mov.l @r10,r3 */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x3D2C\n"  /* add r2,r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x28E2\n"  /* mov.l r14,@r8 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0xA013\n"  /* bra 0x06022A0A */
    ".word 0x29D2\n"  /* mov.l r13,@r9 */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x52F5\n"  /* mov.l @(0x14,r15),r2 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B0B\n"  /* bf 0x06022A0A */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x28E2\n"  /* mov.l r14,@r8 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x29D2\n"  /* mov.l r13,@r9 */
    ".word 0x6E82\n"  /* mov.l @r8,r14 */
    ".word 0x3E63\n"  /* cmp/ge r6,r14 */
    ".word 0x8B0B\n"  /* bf 0x06022A28 */
    ".word 0x932A\n"  /* mov.w @(0x54,PC),r3 */
    ".word 0x3E37\n"  /* cmp/gt r3,r14 */
    ".word 0x8908\n"  /* bt 0x06022A28 */
    ".word 0x6E92\n"  /* mov.l @r9,r14 */
    ".word 0x3E63\n"  /* cmp/ge r6,r14 */
    ".word 0x8B05\n"  /* bf 0x06022A28 */
    ".word 0x9225\n"  /* mov.w @(0x4A,PC),r2 */
    ".word 0x3E27\n"  /* cmp/gt r2,r14 */
    ".word 0x8902\n"  /* bt 0x06022A28 */
    ".word 0x52F6\n"  /* mov.l @(0x18,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893A\n"  /* bt 0x06022AA8 */
    ".word 0x53F8\n"  /* mov.l @(0x20,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8936\n"  /* bt 0x06022AA8 */
    ".word 0x6DA2\n"  /* mov.l @r10,r13 */
    ".word 0x6EB2\n"  /* mov.l @r11,r14 */
    ".word 0x63D3\n"  /* mov r13,r3 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x4D00\n"  /* shll r13 */
    ".word 0x4E00\n"  /* shll r14 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x6351\n"  /* mov.w @r5,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8F0D\n"  /* bf/s 0x06022A6C */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x2AD2\n"  /* mov.l r13,@r10 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0xA011\n"  /* bra 0x06022A8A */
    ".word 0x2BE2\n"  /* mov.l r14,@r11 */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B09\n"  /* bf 0x06022A8A */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x2AD2\n"  /* mov.l r13,@r10 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x2BE2\n"  /* mov.l r14,@r11 */
    ".word 0x6EA2\n"  /* mov.l @r10,r14 */
    ".word 0x3E63\n"  /* cmp/ge r6,r14 */
    ".word 0x8B0B\n"  /* bf 0x06022AA8 */
    ".word 0x9224\n"  /* mov.w @(0x48,PC),r2 */
    ".word 0x3E27\n"  /* cmp/gt r2,r14 */
    ".word 0x8908\n"  /* bt 0x06022AA8 */
    ".word 0x6EB2\n"  /* mov.l @r11,r14 */
    ".word 0x3E63\n"  /* cmp/ge r6,r14 */
    ".word 0x8B05\n"  /* bf 0x06022AA8 */
    ".word 0x931F\n"  /* mov.w @(0x3E,PC),r3 */
    ".word 0x3E37\n"  /* cmp/gt r3,r14 */
    ".word 0x8902\n"  /* bt 0x06022AA8 */
    ".word 0x53F8\n"  /* mov.l @(0x20,r15),r3 */
    ".word 0x627F\n"  /* exts.w r7,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x53F7\n"  /* mov.l @(0x1C,r15),r3 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x51F6\n"  /* mov.l @(0x18,r15),r1 */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x6211\n"  /* mov.w @r1,r2 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x51F8\n"  /* mov.l @(0x20,r15),r1 */
    ".word 0x6211\n"  /* mov.w @r1,r2 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B01\n"  /* bf 0x06022AC6 */
    ".word 0xA002\n"  /* bra 0x06022ACA */
    ".word 0x0009\n"  /* nop */
    ".word 0xAEE2\n"  /* bra 0x0602288E */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F2C\n"  /* add #44,r15 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".size _object_render_list_builder, .-_object_render_list_builder\n"
);
__asm__(



    ".balign 2\n"
    ".global _object_render_processor\n"
    ".type _object_render_processor, @function\n"









    ".section .text.FUN_06022AE0, \"ax\"\n"

    ".global _FUN_06022AE0\n"
    "_object_render_processor:\n"
    "_FUN_06022AE0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x7FD4\n"  /* add #-44,r15 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x9662\n"  /* mov.w @(0xC4,PC),r6 */
    ".word 0x6EF3\n"  /* mov r15,r14 */
    ".word 0x7E24\n"  /* add #36,r14 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x1F35\n"  /* mov.l r3,@(0x14,r15) */
    ".word 0x6251\n"  /* mov.w @r5,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x7302\n"  /* add #2,r3 */
    ".word 0x1F33\n"  /* mov.l r3,@(0xC,r15) */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0x1F27\n"  /* mov.l r2,@(0x1C,r15) */
    ".word 0x6121\n"  /* mov.w @r2,r1 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x1F32\n"  /* mov.l r3,@(0x8,r15) */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x1F26\n"  /* mov.l r2,@(0x18,r15) */
    ".word 0x6121\n"  /* mov.w @r2,r1 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0x7E06\n"  /* add #6,r14 */
    ".word 0x1FE4\n"  /* mov.l r14,@(0x10,r15) */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x7306\n"  /* add #6,r3 */
    ".word 0x1F38\n"  /* mov.l r3,@(0x20,r15) */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x2E21\n"  /* mov.w r2,@r14 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x7E08\n"  /* add #8,r14 */
    ".word 0x6943\n"  /* mov r4,r9 */
    ".word 0x790C\n"  /* add #12,r9 */
    ".word 0x6B43\n"  /* mov r4,r11 */
    ".word 0x7B04\n"  /* add #4,r11 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x7810\n"  /* add #16,r8 */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x7A14\n"  /* add #20,r10 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x7C18\n"  /* add #24,r12 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".word 0x7D1C\n"  /* add #28,r13 */
    ".word 0x6251\n"  /* mov.w @r5,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8901\n"  /* bt 0x06022B54 */
    ".word 0xA095\n"  /* bra 0x06022C7E */
    ".word 0x0009\n"  /* nop */
    ".word 0x53F3\n"  /* mov.l @(0xC,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8929\n"  /* bt 0x06022BB0 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6142\n"  /* mov.l @r4,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x61F2\n"  /* mov.l @r15,r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2E12\n"  /* mov.l r1,@r14 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022BB0 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9313\n"  /* mov.w @(0x26,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022BB0 */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022BB0 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x930B\n"  /* mov.w @(0x16,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022BB0 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0xA003\n"  /* bra 0x06022BC0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFE6B\n"  /* .word 0xFE6B */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x8929\n"  /* bt 0x06022C16 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x6142\n"  /* mov.l @r4,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x61F2\n"  /* mov.l @r15,r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2812\n"  /* mov.l r1,@r8 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2A32\n"  /* mov.l r3,@r10 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022C16 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x933F\n"  /* mov.w @(0x7E,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022C16 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022C16 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9337\n"  /* mov.w @(0x6E,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022C16 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x06022C22 */
    ".word 0xA1F9\n"  /* bra 0x06023014 */
    ".word 0x0009\n"  /* nop */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x6142\n"  /* mov.l @r4,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x61F2\n"  /* mov.l @r15,r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2C12\n"  /* mov.l r1,@r12 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022C76 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x930F\n"  /* mov.w @(0x1E,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022C76 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022C76 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022C76 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA1CD\n"  /* bra 0x06023014 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x52F7\n"  /* mov.l @(0x1C,r15),r2 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8901\n"  /* bt 0x06022C8C */
    ".word 0xA094\n"  /* bra 0x06022DB4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8929\n"  /* bt 0x06022CE8 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x6092\n"  /* mov.l @r9,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022CE8 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9340\n"  /* mov.w @(0x80,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022CE8 */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022CE8 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9338\n"  /* mov.w @(0x70,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022CE8 */
    ".word 0x52F5\n"  /* mov.l @(0x14,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8929\n"  /* bt 0x06022D44 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x6092\n"  /* mov.l @r9,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2812\n"  /* mov.l r1,@r8 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2A32\n"  /* mov.l r3,@r10 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022D44 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9312\n"  /* mov.w @(0x24,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022D44 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022D44 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x930A\n"  /* mov.w @(0x14,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022D44 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0xA002\n"  /* bra 0x06022D52 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x8B01\n"  /* bf 0x06022D58 */
    ".word 0xA15E\n"  /* bra 0x06023014 */
    ".word 0x0009\n"  /* nop */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x6092\n"  /* mov.l @r9,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2C12\n"  /* mov.l r1,@r12 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022DAC */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x930F\n"  /* mov.w @(0x1E,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022DAC */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022DAC */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022DAC */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA132\n"  /* bra 0x06023014 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x52F6\n"  /* mov.l @(0x18,r15),r2 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8901\n"  /* bt 0x06022DC2 */
    ".word 0xA094\n"  /* bra 0x06022EEA */
    ".word 0x0009\n"  /* nop */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8929\n"  /* bt 0x06022E1E */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x6182\n"  /* mov.l @r8,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x60A2\n"  /* mov.l @r10,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022E1E */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9340\n"  /* mov.w @(0x80,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022E1E */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022E1E */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9338\n"  /* mov.w @(0x70,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022E1E */
    ".word 0x52F5\n"  /* mov.l @(0x14,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8929\n"  /* bt 0x06022E7A */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6182\n"  /* mov.l @r8,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x60A2\n"  /* mov.l @r10,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2E12\n"  /* mov.l r1,@r14 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022E7A */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9312\n"  /* mov.w @(0x24,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022E7A */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022E7A */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x930A\n"  /* mov.w @(0x14,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022E7A */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0xA002\n"  /* bra 0x06022E88 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x8B01\n"  /* bf 0x06022E8E */
    ".word 0xA0C3\n"  /* bra 0x06023014 */
    ".word 0x0009\n"  /* nop */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x6182\n"  /* mov.l @r8,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x60A2\n"  /* mov.l @r10,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x61F2\n"  /* mov.l @r15,r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2C12\n"  /* mov.l r1,@r12 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022EE2 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x930F\n"  /* mov.w @(0x1E,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022EE2 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022EE2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022EE2 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA097\n"  /* bra 0x06023014 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x52F8\n"  /* mov.l @(0x20,r15),r2 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8901\n"  /* bt 0x06022EF8 */
    ".word 0xA08E\n"  /* bra 0x06023014 */
    ".word 0x0009\n"  /* nop */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8929\n"  /* bt 0x06022F54 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x61C2\n"  /* mov.l @r12,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x61F2\n"  /* mov.l @r15,r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022F54 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9340\n"  /* mov.w @(0x80,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022F54 */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022F54 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9338\n"  /* mov.w @(0x70,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022F54 */
    ".word 0x52F5\n"  /* mov.l @(0x14,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8929\n"  /* bt 0x06022FB0 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x61C2\n"  /* mov.l @r12,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x61F2\n"  /* mov.l @r15,r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2E12\n"  /* mov.l r1,@r14 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06022FB0 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9312\n"  /* mov.w @(0x24,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06022FB0 */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06022FB0 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x930A\n"  /* mov.w @(0x14,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06022FB0 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0xA002\n"  /* bra 0x06022FBE */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x8929\n"  /* bt 0x06023014 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x61C2\n"  /* mov.l @r12,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x2812\n"  /* mov.l r1,@r8 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2A32\n"  /* mov.l r3,@r10 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8B0F\n"  /* bf 0x06023014 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9327\n"  /* mov.w @(0x4E,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890B\n"  /* bt 0x06023014 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8F07\n"  /* bf/s 0x06023014 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x931F\n"  /* mov.w @(0x3E,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8902\n"  /* bt 0x06023014 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x637F\n"  /* exts.w r7,r3 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x52F5\n"  /* mov.l @(0x14,r15),r2 */
    ".word 0x51F2\n"  /* mov.l @(0x8,r15),r1 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x6211\n"  /* mov.w @r1,r2 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x51F4\n"  /* mov.l @(0x10,r15),r1 */
    ".word 0x6211\n"  /* mov.w @r1,r2 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B01\n"  /* bf 0x06023032 */
    ".word 0xA002\n"  /* bra 0x06023036 */
    ".word 0x0009\n"  /* nop */
    ".word 0xAD89\n"  /* bra 0x06022B48 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F2C\n"  /* add #44,r15 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".size _object_render_processor, .-_object_render_processor\n"
);
__asm__(



    ".balign 2\n"
    ".global _render_batch_processor\n"
    ".type _render_batch_processor, @function\n"









    ".section .text.FUN_0602304C, \"ax\"\n"

    ".global _FUN_0602304C\n"
    "_render_batch_processor:\n"
    "_FUN_0602304C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0xD44A\n"  /* mov.l @(0x128,PC),r4  {[0x06023188] = 0x06089E44} */
    ".word 0xE003\n"  /* mov #3,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0xE005\n"  /* mov #5,r0 */
    ".word 0x8144\n"  /* mov.w r0,@(0x8,r4) */
    ".word 0xE006\n"  /* mov #6,r0 */
    ".word 0x8145\n"  /* mov.w r0,@(0xA,r4) */
    ".word 0xE007\n"  /* mov #7,r0 */
    ".word 0x8146\n"  /* mov.w r0,@(0xC,r4) */
    ".word 0xE008\n"  /* mov #8,r0 */
    ".word 0x8147\n"  /* mov.w r0,@(0xE,r4) */
    ".word 0xE009\n"  /* mov #9,r0 */
    ".word 0x8148\n"  /* mov.w r0,@(0x10,r4) */
    ".word 0xE00A\n"  /* mov #10,r0 */
    ".word 0x8149\n"  /* mov.w r0,@(0x12,r4) */
    ".word 0xE00B\n"  /* mov #11,r0 */
    ".word 0x814A\n"  /* mov.w r0,@(0x14,r4) */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x814B\n"  /* mov.w r0,@(0x16,r4) */
    ".word 0xE00D\n"  /* mov #13,r0 */
    ".word 0x814C\n"  /* mov.w r0,@(0x18,r4) */
    ".word 0xE00E\n"  /* mov #14,r0 */
    ".word 0x814D\n"  /* mov.w r0,@(0x1A,r4) */
    ".word 0xE00F\n"  /* mov #15,r0 */
    ".word 0x814E\n"  /* mov.w r0,@(0x1C,r4) */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x814F\n"  /* mov.w r0,@(0x1E,r4) */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7320\n"  /* add #32,r3 */
    ".word 0xE211\n"  /* mov #17,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7322\n"  /* add #34,r3 */
    ".word 0xE212\n"  /* mov #18,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7324\n"  /* add #36,r3 */
    ".word 0xE213\n"  /* mov #19,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7326\n"  /* add #38,r3 */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7328\n"  /* add #40,r3 */
    ".word 0xE215\n"  /* mov #21,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732A\n"  /* add #42,r3 */
    ".word 0xE216\n"  /* mov #22,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732C\n"  /* add #44,r3 */
    ".word 0xE217\n"  /* mov #23,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732E\n"  /* add #46,r3 */
    ".word 0xE218\n"  /* mov #24,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7330\n"  /* add #48,r3 */
    ".word 0xE219\n"  /* mov #25,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7332\n"  /* add #50,r3 */
    ".word 0xE21A\n"  /* mov #26,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7334\n"  /* add #52,r3 */
    ".word 0xE21B\n"  /* mov #27,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7336\n"  /* add #54,r3 */
    ".word 0xE21C\n"  /* mov #28,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7338\n"  /* add #56,r3 */
    ".word 0xE21D\n"  /* mov #29,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xE51E\n"  /* mov #30,r5 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733A\n"  /* add #58,r3 */
    ".word 0x625D\n"  /* extu.w r5,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733C\n"  /* add #60,r3 */
    ".word 0xE21F\n"  /* mov #31,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733E\n"  /* add #62,r3 */
    ".word 0xE220\n"  /* mov #32,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7340\n"  /* add #64,r3 */
    ".word 0xE221\n"  /* mov #33,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7342\n"  /* add #66,r3 */
    ".word 0xE222\n"  /* mov #34,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0xE223\n"  /* mov #35,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7346\n"  /* add #70,r3 */
    ".word 0xE224\n"  /* mov #36,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0xE225\n"  /* mov #37,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734A\n"  /* add #74,r3 */
    ".word 0xE226\n"  /* mov #38,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734C\n"  /* add #76,r3 */
    ".word 0xE227\n"  /* mov #39,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734E\n"  /* add #78,r3 */
    ".word 0xE228\n"  /* mov #40,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7350\n"  /* add #80,r3 */
    ".word 0xE229\n"  /* mov #41,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7352\n"  /* add #82,r3 */
    ".word 0xE22A\n"  /* mov #42,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7354\n"  /* add #84,r3 */
    ".word 0xE236\n"  /* mov #54,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x7456\n"  /* add #86,r4 */
    ".word 0xE337\n"  /* mov #55,r3 */
    ".word 0x2431\n"  /* mov.w r3,@r4 */
    ".word 0x6E5D\n"  /* extu.w r5,r14 */
    ".word 0xDB04\n"  /* mov.l @(0x10,PC),r11  {[0x0602318C] = 0x002A8000} */
    ".word 0x9602\n"  /* mov.w @(0x4,PC),r6 */
    ".word 0xD404\n"  /* mov.l @(0x10,PC),r4  {[0x06023190] = 0x06059FFC} */
    ".word 0xA008\n"  /* bra 0x06023194 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x3AC0\n"  /* cmp/eq r12,r10 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E44\n"  /* mov.w @(0x88,PC),r14 */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9FFC\n"  /* mov.w @(0x1F8,PC),r15 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD337\n"  /* mov.l @(0xDC,PC),r3  {[0x06023274] = 0x06063F5C} */
    ".word 0x926B\n"  /* mov.w @(0xD6,PC),r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xD234\n"  /* mov.l @(0xD0,PC),r2  {[0x06023278] = 0x0602761E} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA03F\n"  /* bra 0x0602322C */
    ".word 0x6DCD\n"  /* extu.w r12,r13 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x63D3\n"  /* mov r13,r3 */
    ".word 0xD232\n"  /* mov.l @(0xC8,PC),r2  {[0x0602327C] = 0x06054380} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6A42\n"  /* mov.l @r4,r10 */
    ".word 0x8544\n"  /* mov.w @(0x8,r4),r0 */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x638D\n"  /* extu.w r8,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8F0B\n"  /* bf/s 0x060231E4 */
    ".word 0x69CD\n"  /* extu.w r12,r9 */
    ".word 0x66B3\n"  /* mov r11,r6 */
    ".word 0x65ED\n"  /* extu.w r14,r5 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06023280] = 0x06007790} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x7901\n"  /* add #1,r9 */
    ".word 0x638D\n"  /* extu.w r8,r3 */
    ".word 0x629D\n"  /* extu.w r9,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8FF5\n"  /* bf/s 0x060231CE */
    ".word 0x7A0C\n"  /* add #12,r10 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x63D3\n"  /* mov r13,r3 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x0602327C] = 0x06054380} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x8545\n"  /* mov.w @(0xA,r4),r0 */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x60DD\n"  /* extu.w r13,r0 */
    ".word 0x8827\n"  /* cmp/eq #39,r0 */
    ".word 0x8F01\n"  /* bf/s 0x06023204 */
    ".word 0x5A41\n"  /* mov.l @(0x4,r4),r10 */
    ".word 0x7E2F\n"  /* add #47,r14 */
    ".word 0x628D\n"  /* extu.w r8,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8F0A\n"  /* bf/s 0x06023220 */
    ".word 0x69CD\n"  /* extu.w r12,r9 */
    ".word 0x65ED\n"  /* extu.w r14,r5 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x06023284] = 0x06007590} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x7901\n"  /* add #1,r9 */
    ".word 0x638D\n"  /* extu.w r8,r3 */
    ".word 0x629D\n"  /* extu.w r9,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8FF6\n"  /* bf/s 0x0602320C */
    ".word 0x7A06\n"  /* add #6,r10 */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0xE227\n"  /* mov #39,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8900\n"  /* bt 0x0602322A */
    ".word 0x7E0A\n"  /* add #10,r14 */
    ".word 0x7D01\n"  /* add #1,r13 */
    ".word 0x62DD\n"  /* extu.w r13,r2 */
    ".word 0xE328\n"  /* mov #40,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8BBC\n"  /* bf 0x060231AE */
    ".word 0x7E15\n"  /* add #21,r14 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0602328C] = 0x0607886C} */
    ".word 0xD413\n"  /* mov.l @(0x4C,PC),r4  {[0x06023288] = 0x06054560} */
    ".word 0x6D42\n"  /* mov.l @r4,r13 */
    ".word 0x8544\n"  /* mov.w @(0x8,r4),r0 */
    ".word 0x23E1\n"  /* mov.w r14,@r3 */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0x629D\n"  /* extu.w r9,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8F0B\n"  /* bf/s 0x06023260 */
    ".word 0x6ACD\n"  /* extu.w r12,r10 */
    ".word 0x66B3\n"  /* mov r11,r6 */
    ".word 0x65ED\n"  /* extu.w r14,r5 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x06023280] = 0x06007790} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x7A01\n"  /* add #1,r10 */
    ".word 0x639D\n"  /* extu.w r9,r3 */
    ".word 0x62AD\n"  /* extu.w r10,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8FF5\n"  /* bf/s 0x0602324A */
    ".word 0x7D0C\n"  /* add #12,r13 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x03C0\n"  /* .word 0x03C0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F5C\n"  /* add r5,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x4380\n"  /* .word 0x4380 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06007790 */
    ".word 0x7790\n"  /* add #-112,r7 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x7590\n"  /* add #-112,r5 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x4560\n"  /* .word 0x4560 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x886C\n"  /* cmp/eq #108,r0 */
    ".size _render_batch_processor, .-_render_batch_processor\n"
);
__asm__(



    ".balign 2\n"
    ".global _projection_manager\n"
    ".type _projection_manager, @function\n"









    ".section .text.FUN_06023290, \"ax\"\n"

    ".global _FUN_06023290\n"
    "_projection_manager:\n"
    "_FUN_06023290:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD949\n"  /* mov.l @(0x124,PC),r9  {[0x060233C8] = 0x06056940} */
    ".word 0xDD4A\n"  /* mov.l @(0x128,PC),r13  {[0x060233CC] = 0x0606A4EC} */
    ".word 0xD44A\n"  /* mov.l @(0x128,PC),r4  {[0x060233D0] = 0x06089E44} */
    ".word 0xE003\n"  /* mov #3,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0xE005\n"  /* mov #5,r0 */
    ".word 0x8144\n"  /* mov.w r0,@(0x8,r4) */
    ".word 0xE006\n"  /* mov #6,r0 */
    ".word 0x8145\n"  /* mov.w r0,@(0xA,r4) */
    ".word 0xE007\n"  /* mov #7,r0 */
    ".word 0x8146\n"  /* mov.w r0,@(0xC,r4) */
    ".word 0xE008\n"  /* mov #8,r0 */
    ".word 0x8147\n"  /* mov.w r0,@(0xE,r4) */
    ".word 0xE009\n"  /* mov #9,r0 */
    ".word 0x8148\n"  /* mov.w r0,@(0x10,r4) */
    ".word 0xE00A\n"  /* mov #10,r0 */
    ".word 0x8149\n"  /* mov.w r0,@(0x12,r4) */
    ".word 0xE00B\n"  /* mov #11,r0 */
    ".word 0x814A\n"  /* mov.w r0,@(0x14,r4) */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x814B\n"  /* mov.w r0,@(0x16,r4) */
    ".word 0xE00D\n"  /* mov #13,r0 */
    ".word 0x814C\n"  /* mov.w r0,@(0x18,r4) */
    ".word 0xE00E\n"  /* mov #14,r0 */
    ".word 0x814D\n"  /* mov.w r0,@(0x1A,r4) */
    ".word 0xE00F\n"  /* mov #15,r0 */
    ".word 0x814E\n"  /* mov.w r0,@(0x1C,r4) */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x814F\n"  /* mov.w r0,@(0x1E,r4) */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7320\n"  /* add #32,r3 */
    ".word 0xE211\n"  /* mov #17,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7322\n"  /* add #34,r3 */
    ".word 0xE212\n"  /* mov #18,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7324\n"  /* add #36,r3 */
    ".word 0xE213\n"  /* mov #19,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7326\n"  /* add #38,r3 */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7328\n"  /* add #40,r3 */
    ".word 0xE215\n"  /* mov #21,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732A\n"  /* add #42,r3 */
    ".word 0xE216\n"  /* mov #22,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732C\n"  /* add #44,r3 */
    ".word 0xE217\n"  /* mov #23,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732E\n"  /* add #46,r3 */
    ".word 0xE218\n"  /* mov #24,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7330\n"  /* add #48,r3 */
    ".word 0xE219\n"  /* mov #25,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7332\n"  /* add #50,r3 */
    ".word 0xE21A\n"  /* mov #26,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7334\n"  /* add #52,r3 */
    ".word 0xE21B\n"  /* mov #27,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7336\n"  /* add #54,r3 */
    ".word 0xE21C\n"  /* mov #28,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7338\n"  /* add #56,r3 */
    ".word 0xE21D\n"  /* mov #29,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xE51E\n"  /* mov #30,r5 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733A\n"  /* add #58,r3 */
    ".word 0x625D\n"  /* extu.w r5,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733C\n"  /* add #60,r3 */
    ".word 0xE21F\n"  /* mov #31,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733E\n"  /* add #62,r3 */
    ".word 0xE220\n"  /* mov #32,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7340\n"  /* add #64,r3 */
    ".word 0xE221\n"  /* mov #33,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7342\n"  /* add #66,r3 */
    ".word 0xE222\n"  /* mov #34,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0xE223\n"  /* mov #35,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7346\n"  /* add #70,r3 */
    ".word 0xE224\n"  /* mov #36,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0xE225\n"  /* mov #37,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734A\n"  /* add #74,r3 */
    ".word 0xE226\n"  /* mov #38,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734C\n"  /* add #76,r3 */
    ".word 0xE227\n"  /* mov #39,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734E\n"  /* add #78,r3 */
    ".word 0xE228\n"  /* mov #40,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7350\n"  /* add #80,r3 */
    ".word 0xE229\n"  /* mov #41,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7352\n"  /* add #82,r3 */
    ".word 0xE22A\n"  /* mov #42,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7354\n"  /* add #84,r3 */
    ".word 0xE236\n"  /* mov #54,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x7456\n"  /* add #86,r4 */
    ".word 0xE337\n"  /* mov #55,r3 */
    ".word 0x2431\n"  /* mov.w r3,@r4 */
    ".word 0x6B5D\n"  /* extu.w r5,r11 */
    ".word 0x9601\n"  /* mov.w @(0x2,PC),r6 */
    ".word 0xA007\n"  /* bra 0x060233D4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4240\n"  /* .word 0x4240 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x6940\n"  /* mov.b @r4,r9 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4EC\n"  /* bra 0x06023DAA */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E44\n"  /* mov.w @(0x88,PC),r14 */
    ".word 0xD52D\n"  /* mov.l @(0xB4,PC),r5  {[0x0602348C] = 0x002A8000} */
    ".word 0xD42E\n"  /* mov.l @(0xB8,PC),r4  {[0x06023490] = 0x06059FFC} */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x06023494] = 0x06063F5C} */
    ".word 0x9253\n"  /* mov.w @(0xA6,PC),r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xD22B\n"  /* mov.l @(0xAC,PC),r2  {[0x06023498] = 0x0602761E} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA0A7\n"  /* bra 0x06023540 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0x64CC\n"  /* extu.b r12,r4 */
    ".word 0xE213\n"  /* mov #19,r2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x63CD\n"  /* extu.w r12,r3 */
    ".word 0x349C\n"  /* add r9,r4 */
    ".word 0x6A42\n"  /* mov.l @r4,r10 */
    ".word 0x8544\n"  /* mov.w @(0x8,r4),r0 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8F01\n"  /* bf/s 0x06023412 */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x7B36\n"  /* add #54,r11 */
    ".word 0x628D\n"  /* extu.w r8,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8F5F\n"  /* bf/s 0x060234D8 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x60CD\n"  /* extu.w r12,r0 */
    ".word 0x8813\n"  /* cmp/eq #19,r0 */
    ".word 0x8B50\n"  /* bf 0x060234C2 */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0x8815\n"  /* cmp/eq #21,r0 */
    ".word 0x8B04\n"  /* bf 0x06023430 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0602349C] = 0x06089E30} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xA049\n"  /* bra 0x060234C2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0x8827\n"  /* cmp/eq #39,r0 */
    ".word 0x8B04\n"  /* bf 0x06023440 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x060234A0] = 0x06089E2C} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xA041\n"  /* bra 0x060234C2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0x8840\n"  /* cmp/eq #64,r0 */
    ".word 0x8B04\n"  /* bf 0x06023450 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x060234A4] = 0x06089E34} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xA039\n"  /* bra 0x060234C2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0x8844\n"  /* cmp/eq #68,r0 */
    ".word 0x8B04\n"  /* bf 0x06023460 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x060234A8] = 0x06089E38} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xA031\n"  /* bra 0x060234C2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62ED\n"  /* extu.w r14,r2 */
    ".word 0x9310\n"  /* mov.w @(0x20,PC),r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B04\n"  /* bf 0x06023472 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x060234AC] = 0x06089E28} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA028\n"  /* bra 0x060234C2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62ED\n"  /* extu.w r14,r2 */
    ".word 0x9308\n"  /* mov.w @(0x10,PC),r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B1C\n"  /* bf 0x060234B4 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x060234B0] = 0x06089E3C} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA01F\n"  /* bra 0x060234C2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x03C0\n"  /* .word 0x03C0 */
    ".word 0x0082\n"  /* .word 0x0082 */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9FFC\n"  /* mov.w @(0x1F8,PC),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F5C\n"  /* add r5,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E30\n"  /* mov.w @(0x60,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E2C\n"  /* mov.w @(0x58,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E34\n"  /* mov.w @(0x68,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E38\n"  /* mov.w @(0x70,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E28\n"  /* mov.w @(0x50,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E3C\n"  /* mov.w @(0x78,PC),r14 */
    ".word 0x62ED\n"  /* extu.w r14,r2 */
    ".word 0x9352\n"  /* mov.w @(0xA4,PC),r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B02\n"  /* bf 0x060234C2 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x06023560] = 0x06089E40} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x65BD\n"  /* extu.w r11,r5 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x06023568] = 0x06007790} */
    ".word 0xD627\n"  /* mov.l @(0x9C,PC),r6  {[0x06023564] = 0x002A8000} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x638D\n"  /* extu.w r8,r3 */
    ".word 0x62ED\n"  /* extu.w r14,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8FA1\n"  /* bf/s 0x0602341A */
    ".word 0x7A0C\n"  /* add #12,r10 */
    ".word 0x6ECC\n"  /* extu.b r12,r14 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x3E9C\n"  /* add r9,r14 */
    ".word 0x5EE1\n"  /* mov.l @(0x4,r14),r14 */
    ".word 0x2EE8\n"  /* tst r14,r14 */
    ".word 0x8B01\n"  /* bf 0x060234F2 */
    ".word 0xA02D\n"  /* bra 0x0602354C */
    ".word 0x0009\n"  /* nop */
    ".word 0x68CC\n"  /* extu.b r12,r8 */
    ".word 0x6383\n"  /* mov r8,r3 */
    ".word 0x4808\n"  /* shll2 r8 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x383C\n"  /* add r3,r8 */
    ".word 0x688C\n"  /* extu.b r8,r8 */
    ".word 0x389C\n"  /* add r9,r8 */
    ".word 0x8585\n"  /* mov.w @(0xA,r8),r0 */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x60CD\n"  /* extu.w r12,r0 */
    ".word 0x8813\n"  /* cmp/eq #19,r0 */
    ".word 0x8B00\n"  /* bf 0x0602350E */
    ".word 0x7B53\n"  /* add #83,r11 */
    ".word 0x628D\n"  /* extu.w r8,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8F0A\n"  /* bf/s 0x0602352A */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0x65BD\n"  /* extu.w r11,r5 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0602356C] = 0x06007590} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7A01\n"  /* add #1,r10 */
    ".word 0x638D\n"  /* extu.w r8,r3 */
    ".word 0x62AD\n"  /* extu.w r10,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8FF6\n"  /* bf/s 0x06023516 */
    ".word 0x7E06\n"  /* add #6,r14 */
    ".word 0x60CD\n"  /* extu.w r12,r0 */
    ".word 0x8814\n"  /* cmp/eq #20,r0 */
    ".word 0x8B01\n"  /* bf 0x06023534 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06023570] = 0x0607886C} */
    ".word 0x23B1\n"  /* mov.w r11,@r3 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0xE313\n"  /* mov #19,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8900\n"  /* bt 0x0602353E */
    ".word 0x7B0A\n"  /* add #10,r11 */
    ".word 0x7C01\n"  /* add #1,r12 */
    ".word 0x63CD\n"  /* extu.w r12,r3 */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8901\n"  /* bt 0x0602354C */
    ".word 0xAF53\n"  /* bra 0x060233F2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00A9\n"  /* .word 0x00A9 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E40\n"  /* mov.w @(0x80,PC),r14 */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06007790 */
    ".word 0x7790\n"  /* add #-112,r7 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x7590\n"  /* add #-112,r5 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x886C\n"  /* cmp/eq #108,r0 */
    ".size _projection_manager, .-_projection_manager\n"
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06023574, \"ax\"\n"

    ".global _FUN_06023574\n"
    ".type _FUN_06023574, @function\n"
    "_FUN_06023574:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0xE91D\n"  /* mov #29,r9 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06023584, \"ax\"\n"

    ".global _FUN_06023584\n"
    ".type _FUN_06023584, @function\n"
    "_FUN_06023584:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x9090\n"  /* mov.w @(0x120,PC),r0 */
    ".word 0x3F0C\n"  /* add r0,r15 */
    ".word 0xDA48\n"  /* mov.l @(0x120,PC),r10  {[0x060236B0] = 0x0606A4EC} */
    ".word 0x61F3\n"  /* mov r15,r1 */
    ".word 0xD248\n"  /* mov.l @(0x120,PC),r2  {[0x060236B4] = 0x06060A48} */
    ".word 0x908C\n"  /* mov.w @(0x118,PC),r0 */
    ".word 0xD348\n"  /* mov.l @(0x120,PC),r3  {[0x060236B8] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7108\n"  /* add #8,r1 */
    ".word 0xD448\n"  /* mov.l @(0x120,PC),r4  {[0x060236BC] = 0x06089E44} */
    ".word 0xE003\n"  /* mov #3,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0xE005\n"  /* mov #5,r0 */
    ".word 0x8144\n"  /* mov.w r0,@(0x8,r4) */
    ".word 0xE006\n"  /* mov #6,r0 */
    ".word 0x8145\n"  /* mov.w r0,@(0xA,r4) */
    ".word 0xE007\n"  /* mov #7,r0 */
    ".word 0x8146\n"  /* mov.w r0,@(0xC,r4) */
    ".word 0xE008\n"  /* mov #8,r0 */
    ".word 0x8147\n"  /* mov.w r0,@(0xE,r4) */
    ".word 0xE009\n"  /* mov #9,r0 */
    ".word 0x8148\n"  /* mov.w r0,@(0x10,r4) */
    ".word 0xE00A\n"  /* mov #10,r0 */
    ".word 0x8149\n"  /* mov.w r0,@(0x12,r4) */
    ".word 0xE00B\n"  /* mov #11,r0 */
    ".word 0x814A\n"  /* mov.w r0,@(0x14,r4) */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x814B\n"  /* mov.w r0,@(0x16,r4) */
    ".word 0xE00D\n"  /* mov #13,r0 */
    ".word 0x814C\n"  /* mov.w r0,@(0x18,r4) */
    ".word 0xE00E\n"  /* mov #14,r0 */
    ".word 0x814D\n"  /* mov.w r0,@(0x1A,r4) */
    ".word 0xE00F\n"  /* mov #15,r0 */
    ".word 0x814E\n"  /* mov.w r0,@(0x1C,r4) */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x814F\n"  /* mov.w r0,@(0x1E,r4) */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7320\n"  /* add #32,r3 */
    ".word 0xE211\n"  /* mov #17,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7322\n"  /* add #34,r3 */
    ".word 0xE212\n"  /* mov #18,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7324\n"  /* add #36,r3 */
    ".word 0xE213\n"  /* mov #19,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7326\n"  /* add #38,r3 */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7328\n"  /* add #40,r3 */
    ".word 0xE215\n"  /* mov #21,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732A\n"  /* add #42,r3 */
    ".word 0xE216\n"  /* mov #22,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732C\n"  /* add #44,r3 */
    ".word 0xE217\n"  /* mov #23,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x732E\n"  /* add #46,r3 */
    ".word 0xE218\n"  /* mov #24,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7330\n"  /* add #48,r3 */
    ".word 0xE219\n"  /* mov #25,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7332\n"  /* add #50,r3 */
    ".word 0xE21A\n"  /* mov #26,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7334\n"  /* add #52,r3 */
    ".word 0xE21B\n"  /* mov #27,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7336\n"  /* add #54,r3 */
    ".word 0xE21C\n"  /* mov #28,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7338\n"  /* add #56,r3 */
    ".word 0x2391\n"  /* mov.w r9,@r3 */
    ".word 0xE51E\n"  /* mov #30,r5 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733A\n"  /* add #58,r3 */
    ".word 0x625D\n"  /* extu.w r5,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733C\n"  /* add #60,r3 */
    ".word 0xE21F\n"  /* mov #31,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x733E\n"  /* add #62,r3 */
    ".word 0xE220\n"  /* mov #32,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7340\n"  /* add #64,r3 */
    ".word 0xE221\n"  /* mov #33,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7342\n"  /* add #66,r3 */
    ".word 0xE222\n"  /* mov #34,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0xE223\n"  /* mov #35,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7346\n"  /* add #70,r3 */
    ".word 0xE224\n"  /* mov #36,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0xE225\n"  /* mov #37,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734A\n"  /* add #74,r3 */
    ".word 0xE226\n"  /* mov #38,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734C\n"  /* add #76,r3 */
    ".word 0xE227\n"  /* mov #39,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x734E\n"  /* add #78,r3 */
    ".word 0xE228\n"  /* mov #40,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7350\n"  /* add #80,r3 */
    ".word 0xE229\n"  /* mov #41,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7352\n"  /* add #82,r3 */
    ".word 0xE22A\n"  /* mov #42,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7354\n"  /* add #84,r3 */
    ".word 0xA00A\n"  /* bra 0x060236C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFE6C\n"  /* .word 0xFE6C */
    ".word 0x018C\n"  /* mov.b @(r0,r8),r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4EC\n"  /* bra 0x0602408E */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x0A48\n"  /* .word 0x0A48 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E44\n"  /* mov.w @(0x88,PC),r14 */
    ".word 0xE236\n"  /* mov #54,r2 */
    ".word 0x7456\n"  /* add #86,r4 */
    ".word 0x6C5D\n"  /* extu.w r5,r12 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xE337\n"  /* mov #55,r3 */
    ".word 0x2431\n"  /* mov.w r3,@r4 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x06023748] = 0x002A8000} */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0x9637\n"  /* mov.w @(0x6E,PC),r6 */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x0602374C] = 0x06059FFC} */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06023750] = 0x06063F5C} */
    ".word 0x9235\n"  /* mov.w @(0x6A,PC),r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x06023754] = 0x0602761E} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA081\n"  /* bra 0x060237F2 */
    ".word 0x6E8D\n"  /* extu.w r8,r14 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x6B42\n"  /* mov.l @r4,r11 */
    ".word 0x8544\n"  /* mov.w @(0x8,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x2F31\n"  /* mov.w r3,@r15 */
    ".word 0x63F1\n"  /* mov.w @r15,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8F38\n"  /* bf/s 0x06023786 */
    ".word 0x6D8D\n"  /* extu.w r8,r13 */
    ".word 0x2BB8\n"  /* tst r11,r11 */
    ".word 0x8B01\n"  /* bf 0x0602371E */
    ".word 0xA034\n"  /* bra 0x06023786 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0x881D\n"  /* cmp/eq #29,r0 */
    ".word 0x8B24\n"  /* bf 0x0602376E */
    ".word 0x60DD\n"  /* extu.w r13,r0 */
    ".word 0x8817\n"  /* cmp/eq #23,r0 */
    ".word 0x8B04\n"  /* bf 0x06023734 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x06023758] = 0x06089E30} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xA01D\n"  /* bra 0x0602376E */
    ".word 0x0009\n"  /* nop */
    ".word 0x60DD\n"  /* extu.w r13,r0 */
    ".word 0x883A\n"  /* cmp/eq #58,r0 */
    ".word 0x8B12\n"  /* bf 0x06023760 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0602375C] = 0x06089E2C} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xA015\n"  /* bra 0x0602376E */
    ".word 0x0009\n"  /* nop */
    ".word 0x5780\n"  /* mov.l @(0x0,r8),r7 */
    ".word 0x03C0\n"  /* .word 0x03C0 */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9FFC\n"  /* mov.w @(0x1F8,PC),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F5C\n"  /* add r5,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E30\n"  /* mov.w @(0x60,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E2C\n"  /* mov.w @(0x58,PC),r14 */
    ".word 0x62DD\n"  /* extu.w r13,r2 */
    ".word 0x9357\n"  /* mov.w @(0xAE,PC),r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B02\n"  /* bf 0x0602376E */
    ".word 0x63A2\n"  /* mov.l @r10,r3 */
    ".word 0xD22B\n"  /* mov.l @(0xAC,PC),r2  {[0x06023818] = 0x06089E28} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x65CD\n"  /* extu.w r12,r5 */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x0602381C] = 0x06007790} */
    ".word 0x56F1\n"  /* mov.l @(0x4,r15),r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x7D01\n"  /* add #1,r13 */
    ".word 0x63F1\n"  /* mov.w @r15,r3 */
    ".word 0x62DD\n"  /* extu.w r13,r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8FC8\n"  /* bf/s 0x06023716 */
    ".word 0x7B0C\n"  /* add #12,r11 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x5B41\n"  /* mov.l @(0x4,r4),r11 */
    ".word 0x8545\n"  /* mov.w @(0xA,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x2F31\n"  /* mov.w r3,@r15 */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0x3393\n"  /* cmp/ge r9,r3 */
    ".word 0x8B06\n"  /* bf 0x060237B6 */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0x73E3\n"  /* add #-29,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x06023820] = 0x06060A40} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x3C3C\n"  /* add r3,r12 */
    ".word 0x62F1\n"  /* mov.w @r15,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8F0B\n"  /* bf/s 0x060237D6 */
    ".word 0x6D8D\n"  /* extu.w r8,r13 */
    ".word 0x65CD\n"  /* extu.w r12,r5 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06023824] = 0x06007590} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x7D01\n"  /* add #1,r13 */
    ".word 0x63F1\n"  /* mov.w @r15,r3 */
    ".word 0x62DD\n"  /* extu.w r13,r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8FF5\n"  /* bf/s 0x060237C0 */
    ".word 0x7B06\n"  /* add #6,r11 */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0x8820\n"  /* cmp/eq #32,r0 */
    ".word 0x8B01\n"  /* bf 0x060237E0 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06023828] = 0x0607886C} */
    ".word 0x23C1\n"  /* mov.w r12,@r3 */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0x881F\n"  /* cmp/eq #31,r0 */
    ".word 0x8B00\n"  /* bf 0x060237E8 */
    ".word 0x7C2A\n"  /* add #42,r12 */
    ".word 0x62ED\n"  /* extu.w r14,r2 */
    ".word 0x3293\n"  /* cmp/ge r9,r2 */
    ".word 0x8900\n"  /* bt 0x060237F0 */
    ".word 0x7C0A\n"  /* add #10,r12 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x62ED\n"  /* extu.w r14,r2 */
    ".word 0xE321\n"  /* mov #33,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8901\n"  /* bt 0x060237FE */
    ".word 0xAF79\n"  /* bra 0x060236F0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x910A\n"  /* mov.w @(0x14,PC),r1 */
    ".word 0x3F1C\n"  /* add r1,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x0194\n"  /* mov.b r9,@(r0,r1) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9E28\n"  /* mov.w @(0x50,PC),r14 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06007790 */
    ".word 0x7790\n"  /* add #-112,r7 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x0A40\n"  /* .word 0x0A40 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x7590\n"  /* add #-112,r5 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x886C\n"  /* cmp/eq #108,r0 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06024D14, \"ax\"\n"

    ".global _FUN_06024D14\n"
    ".type _FUN_06024D14, @function\n"
    "_FUN_06024D14:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0xE904\n"  /* mov #4,r9 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06024D24, \"ax\"\n"

    ".global _FUN_06024D24\n"
    ".type _FUN_06024D24, @function\n"
    "_FUN_06024D24:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xDA24\n"  /* mov.l @(0x90,PC),r10  {[0x06024DBC] = 0x06089EC4} */
    ".word 0x9B45\n"  /* mov.w @(0x8A,PC),r11 */
    ".word 0xDD24\n"  /* mov.l @(0x90,PC),r13  {[0x06024DC0] = 0x06061198} */
    ".word 0xDE25\n"  /* mov.l @(0x94,PC),r14  {[0x06024DC4] = 0x06089EC8} */
    ".word 0x63D0\n"  /* mov.b @r13,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8F6B\n"  /* bf/s 0x06024E10 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2D30\n"  /* mov.b r3,@r13 */
    ".word 0xD522\n"  /* mov.l @(0x88,PC),r5  {[0x06024DC8] = 0xAE0003FF} */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x06024DCC] = 0x0601D5F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD222\n"  /* mov.l @(0x88,PC),r2  {[0x06024DD0] = 0x40000000} */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x06024DD4] = 0x0605B6D8} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0xD221\n"  /* mov.l @(0x84,PC),r2  {[0x06024DD4] = 0x0605B6D8} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x219B\n"  /* or r9,r1 */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0xD81F\n"  /* mov.l @(0x7C,PC),r8  {[0x06024DD8] = 0x0602761E} */
    ".word 0x962D\n"  /* mov.w @(0x5A,PC),r6 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06024DDC] = 0x0605CF9C} */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0xD41F\n"  /* mov.l @(0x7C,PC),r4  {[0x06024DE0] = 0x25F000C0} */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x6533\n"  /* mov r3,r5 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06024DE4] = 0x0605CD9C} */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x06024DE8] = 0x25F00000} */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x6533\n"  /* mov r3,r5 */
    ".word 0x9621\n"  /* mov.w @(0x42,PC),r6 */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x06024DEC] = 0x25F006C0} */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x06024DF0] = 0x25F00600} */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0xE708\n"  /* mov #8,r7 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x06024DF4] = 0x00017700} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x06024DF8] = 0x25E76EFC} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x06024DFC] = 0x0600511E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06024E00] = 0x0601A5F8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2A01\n"  /* mov.w r0,@r10 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x06024E04] = 0x06089EC6} */
    ".word 0x23C1\n"  /* mov.w r12,@r3 */
    ".word 0xD11A\n"  /* mov.l @(0x68,PC),r1  {[0x06024E08] = 0x0605D240} */
    ".word 0x6110\n"  /* mov.b @r1,r1 */
    ".word 0xB166\n"  /* bsr 0x06025070 */
    ".word 0x2E12\n"  /* mov.l r1,@r14 */
    ".word 0xB1D0\n"  /* bsr 0x06025148 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62A1\n"  /* mov.w @r10,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x32B0\n"  /* cmp/eq r11,r2 */
    ".word 0x8B2D\n"  /* bf 0x06024E0C */
    ".word 0xB238\n"  /* bsr 0x06025224 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xA02C\n"  /* bra 0x06024E10 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A9\n"  /* .word 0x00A9 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EC4\n"  /* mov.w @(0x188,PC),r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x1198\n"  /* mov.l r9,@(0x20,r1) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EC8\n"  /* mov.w @(0x190,PC),r14 */
    ".word 0xAE00\n"  /* bra 0x060249CC */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x060251A0] = 0x62E34800} */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x06025B8A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xCF9C\n"  /* .word 0xCF9C */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xCD9C\n"  /* .word 0xCD9C */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x06C0\n"  /* .word 0x06C0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x25E7\n"  /* .word 0x25E7 */
    ".word 0x6EFC\n"  /* extu.b r15,r14 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x511E\n"  /* mov.l @(0x38,r1),r1 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0xA5F8\n"  /* bra 0x060259F6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EC6\n"  /* mov.w @(0x18C,PC),r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD240\n"  /* mov.l @(0x100,PC),r2  {[0x06024F0C] = 0x62F27201} */
    ".word 0xB334\n"  /* bsr 0x06025478 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8901\n"  /* bt 0x06024E1C */
    ".word 0xA07F\n"  /* bra 0x06024F1A */
    ".word 0x0009\n"  /* nop */
    ".word 0xD422\n"  /* mov.l @(0x88,PC),r4  {[0x06024EA8] = 0x06089EC6} */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06024EAC] = 0x06026518} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6441\n"  /* mov.w @r4,r4 */
    ".word 0xD822\n"  /* mov.l @(0x88,PC),r8  {[0x06024EB0] = 0x06063D9A} */
    ".word 0x6881\n"  /* mov.w @r8,r8 */
    ".word 0x628D\n"  /* extu.w r8,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B01\n"  /* bf 0x06024E32 */
    ".word 0xA08B\n"  /* bra 0x06024F48 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2FC2\n"  /* mov.l r12,@r15 */
    ".word 0x638D\n"  /* extu.w r8,r3 */
    ".word 0x9233\n"  /* mov.w @(0x66,PC),r2 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B1A\n"  /* bf 0x06024E78 */
    ".word 0x50F1\n"  /* mov.l @(0x4,r15),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8917\n"  /* bt 0x06024E78 */
    ".word 0x639C\n"  /* extu.b r9,r3 */
    ".word 0xE2FF\n"  /* mov #-1,r2 */
    ".word 0x2D30\n"  /* mov.b r3,@r13 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06024EB4] = 0x06089ECC} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06024EB8] = 0x06089ED6} */
    ".word 0x23C1\n"  /* mov.w r12,@r3 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06024EBC] = 0x06089ED4} */
    ".word 0x23C1\n"  /* mov.w r12,@r3 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06024EAC] = 0x06026518} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64CD\n"  /* extu.w r12,r4 */
    ".word 0x62A1\n"  /* mov.w @r10,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x32B0\n"  /* cmp/eq r11,r2 */
    ".word 0x8B03\n"  /* bf 0x06024E70 */
    ".word 0xB1DC\n"  /* bsr 0x06025224 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xA053\n"  /* bra 0x06024F16 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB302\n"  /* bsr 0x06025478 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xA04F\n"  /* bra 0x06024F16 */
    ".word 0x0009\n"  /* nop */
    ".word 0x628D\n"  /* extu.w r8,r2 */
    ".word 0x9312\n"  /* mov.w @(0x24,PC),r3 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8905\n"  /* bt 0x06024E8E */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x06024EC0] = 0x0605D240} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xE102\n"  /* mov #2,r1 */
    ".word 0xA044\n"  /* bra 0x06024F16 */
    ".word 0x2D10\n"  /* mov.b r1,@r13 */
    ".word 0x628D\n"  /* extu.w r8,r2 */
    ".word 0x9308\n"  /* mov.w @(0x10,PC),r3 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8915\n"  /* bt 0x06024EC4 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x2D30\n"  /* mov.b r3,@r13 */
    ".word 0xA03B\n"  /* bra 0x06024F16 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EC6\n"  /* mov.w @(0x18C,PC),r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026518 */
    ".word 0x6518\n"  /* swap.b r1,r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9ECC\n"  /* mov.w @(0x198,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9ED6\n"  /* mov.w @(0x1AC,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9ED4\n"  /* mov.w @(0x1A8,PC),r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD240\n"  /* mov.l @(0x100,PC),r2  {[0x06024FC4] = 0x35338FE6} */
    ".word 0x628D\n"  /* extu.w r8,r2 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06024F74] = 0x00008000} */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8907\n"  /* bt 0x06024EDE */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0xE305\n"  /* mov #5,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B00\n"  /* bf 0x06024EDE */
    ".word 0x2EC2\n"  /* mov.l r12,@r14 */
    ".word 0x638D\n"  /* extu.w r8,r3 */
    ".word 0x9247\n"  /* mov.w @(0x8E,PC),r2 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8906\n"  /* bt 0x06024EF6 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8900\n"  /* bt 0x06024EF6 */
    ".word 0x2E92\n"  /* mov.l r9,@r14 */
    ".word 0x62A1\n"  /* mov.w @r10,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x32B0\n"  /* cmp/eq r11,r2 */
    ".word 0x8B03\n"  /* bf 0x06024F06 */
    ".word 0xB191\n"  /* bsr 0x06025224 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xA002\n"  /* bra 0x06024F0A */
    ".word 0x0009\n"  /* nop */
    ".word 0xB2B7\n"  /* bsr 0x06025478 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8F93\n"  /* bf/s 0x06024E3C */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0xA017\n"  /* bra 0x06024F48 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B0B\n"  /* bf 0x06024F3A */
    ".word 0x62A1\n"  /* mov.w @r10,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x32B0\n"  /* cmp/eq r11,r2 */
    ".word 0x8B03\n"  /* bf 0x06024F32 */
    ".word 0xB3CF\n"  /* bsr 0x060256CC */
    ".word 0x0009\n"  /* nop */
    ".word 0xA00B\n"  /* bra 0x06024F48 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB65F\n"  /* bsr 0x06025BF4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA007\n"  /* bra 0x06024F48 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8805\n"  /* cmp/eq #5,r0 */
    ".word 0x8B02\n"  /* bf 0x06024F48 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06024F78] = 0x060266CC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8806\n"  /* cmp/eq #6,r0 */
    ".word 0x8B48\n"  /* bf 0x06024FE2 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x06024F7C] = 0x06089ED8} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B12\n"  /* bf 0x06024F80 */
    ".word 0x63A1\n"  /* mov.w @r10,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x33B0\n"  /* cmp/eq r11,r3 */
    ".word 0x8B03\n"  /* bf 0x06024F6A */
    ".word 0xB085\n"  /* bsr 0x06025070 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA030\n"  /* bra 0x06024FCA */
    ".word 0x0009\n"  /* nop */
    ".word 0xB0ED\n"  /* bsr 0x06025148 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA02C\n"  /* bra 0x06024FCA */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_060266CC */
    ".word 0x66CC\n"  /* extu.b r12,r6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9ED8\n"  /* mov.w @(0x1B0,PC),r14 */
    ".word 0x65A1\n"  /* mov.w @r10,r5 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x06025044] = 0x06026590} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x644E\n"  /* exts.b r4,r4 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0xD22E\n"  /* mov.l @(0xB8,PC),r2  {[0x06025048] = 0x060610BC} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6623\n"  /* mov r2,r6 */
    ".word 0xD72E\n"  /* mov.l @(0xB8,PC),r7  {[0x0602504C] = 0x06060D7C} */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x63A1\n"  /* mov.w @r10,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x33B0\n"  /* cmp/eq r11,r3 */
    ".word 0x8B0A\n"  /* bf 0x06024FB4 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x0602504C] = 0x06060D7C} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x6121\n"  /* mov.w @r2,r1 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0xA004\n"  /* bra 0x06024FBC */
    ".word 0x0009\n"  /* nop */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x5361\n"  /* mov.l @(0x4,r6),r3 */
    ".word 0x6131\n"  /* mov.w @r3,r1 */
    ".word 0x2211\n"  /* mov.w r1,@r2 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x760C\n"  /* add #12,r6 */
    ".word 0x7708\n"  /* add #8,r7 */
    ".word 0xE30E\n"  /* mov #14,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8FE6\n"  /* bf/s 0x06024F96 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x63A1\n"  /* mov.w @r10,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x33B0\n"  /* cmp/eq r11,r3 */
    ".word 0x8B03\n"  /* bf 0x06024FDA */
    ".word 0xB127\n"  /* bsr 0x06025224 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xA002\n"  /* bra 0x06024FDE */
    ".word 0x0009\n"  /* nop */
    ".word 0xB24D\n"  /* bsr 0x06025478 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B15\n"  /* bf 0x06025016 */
    ".word 0x62CC\n"  /* extu.b r12,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x06025050] = 0x06061199} */
    ".word 0x22C0\n"  /* mov.b r12,@r2 */
    ".word 0xD118\n"  /* mov.l @(0x60,PC),r1  {[0x06025054] = 0x0605B6D8} */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x06025054] = 0x0605B6D8} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x219B\n"  /* or r9,r1 */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x06025058] = 0x0602853E} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06025058] = 0x0602853E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE40C\n"  /* mov #12,r4 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0602505C] = 0x06028560} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x06025060] = 0x06085FF2} */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06025064] = 0x06089EC6} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x06025064] = 0x06089EC6} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x06025054] = 0x0605B6D8} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x219B\n"  /* or r9,r1 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x06025054] = 0x0605B6D8} */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x06025068] = 0x06059F44} */
    ".word 0x22C2\n"  /* mov.l r12,@r2 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x0602506C] = 0x06026CE0} */
    ".word 0x422B\n"  /* jmp @r2 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026590 */
    ".word 0x6590\n"  /* mov.b @r9,r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x10BC\n"  /* mov.l r11,@(0x30,r0) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x0D7C\n"  /* mov.b @(r0,r7),r13 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x1199\n"  /* mov.l r9,@(0x24,r1) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x06025E0A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x853E\n"  /* mov.w @(0x1C,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8560\n"  /* mov.w @(0x0,r6),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF2\n"  /* mov.l @(0x8,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EC6\n"  /* mov.w @(0x18C,PC),r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060272C0, \"ax\"\n"

    ".global _FUN_060272C0\n"
    ".type _FUN_060272C0, @function\n"
    "_FUN_060272C0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x0602732C] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0xDE1C\n"  /* mov.l @(0x70,PC),r14  {[0x0602733C] = 0x0608A6F0} */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x4310\n"  /* dt r3 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x2E12\n"  /* mov.l r1,@r14 */
    ".word 0x8FF2\n"  /* bf/s 0x060272CE */
    ".word 0x7E04\n"  /* add #4,r14 */
    ".word 0x7EF4\n"  /* add #-12,r14 */
    ".word 0x60E6\n"  /* mov.l @r14+,r0 */
    ".word 0x61E6\n"  /* mov.l @r14+,r1 */
    ".word 0x62E6\n"  /* mov.l @r14+,r2 */
    ".word 0x2502\n"  /* mov.l r0,@r5 */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x1522\n"  /* mov.l r2,@(0x8,r5) */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x0602732C] = 0x0608A52C} */
    ".word 0xD60F\n"  /* mov.l @(0x3C,PC),r6  {[0x0602733C] = 0x0608A6F0} */
    ".word 0x6202\n"  /* mov.l @r0,r2 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x4310\n"  /* dt r3 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x2612\n"  /* mov.l r1,@r6 */
    ".word 0x8FF4\n"  /* bf/s 0x06027304 */
    ".word 0x7604\n"  /* add #4,r6 */
    ".word 0x76F4\n"  /* add #-12,r6 */
    ".word 0x6062\n"  /* mov.l @r6,r0 */
    ".word 0x5161\n"  /* mov.l @(0x4,r6),r1 */
    ".word 0x5262\n"  /* mov.l @(0x8,r6),r2 */
    ".word 0x2502\n"  /* mov.l r0,@r5 */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x000B\n"  /* rts */
    ".word 0x1522\n"  /* mov.l r2,@(0x8,r5) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x06027D8A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA530\n"  /* bra 0x06027D96 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA6B0\n"  /* bra 0x0602809A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA6C0\n"  /* bra 0x060280BE */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA6F0\n"  /* bra 0x06028122 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x90DA\n"  /* mov.w @(0x1B4,PC),r0 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x90D9\n"  /* mov.w @(0x1B2,PC),r0 */
    ".word 0x4409\n"  /* shlr2 r4 */
    ".word 0x7402\n"  /* add #2,r4 */
    ".word 0x2409\n"  /* and r0,r4 */
    ".word 0xD066\n"  /* mov.l @(0x198,PC),r0  {[0x060274EC] = 0x002F2F20} */
    ".word 0x000B\n"  /* rts */
    ".word 0x004E\n"  /* mov.l @(r0,r4),r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x93D0\n"  /* mov.w @(0x1A0,PC),r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x91CF\n"  /* mov.w @(0x19E,PC),r1 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0xD062\n"  /* mov.l @(0x188,PC),r0  {[0x060274EC] = 0x002F2F20} */
    ".word 0x4409\n"  /* shlr2 r4 */
    ".word 0x2419\n"  /* and r1,r4 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x024E\n"  /* mov.l @(r0,r4),r2 */
    ".word 0x2319\n"  /* and r1,r3 */
    ".word 0x2522\n"  /* mov.l r2,@r5 */
    ".word 0x0009\n"  /* nop */
    ".word 0x013E\n"  /* mov.l @(r0,r3),r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2612\n"  /* mov.l r1,@r6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8D01\n"  /* bt/s 0x06027380 */
    ".word 0x0629\n"  /* .word 0x0629 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0x7440\n"  /* add #64,r4 */
    ".word 0x7440\n"  /* add #64,r4 */
    ".word 0x3046\n"  /* cmp/hi r4,r0 */
    ".word 0x8B07\n"  /* bf 0x0602739C */
    ".word 0xD058\n"  /* mov.l @(0x160,PC),r0  {[0x060274F0] = 0x002F0000} */
    ".word 0x4419\n"  /* shlr8 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x004D\n"  /* mov.w @(r0,r4),r0 */
    ".word 0x8B52\n"  /* bf 0x0602743E */
    ".word 0x000B\n"  /* rts */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x90BB\n"  /* mov.w @(0x176,PC),r0 */
    ".word 0x6549\n"  /* swap.w r4,r5 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x8B4D\n"  /* bf 0x06027442 */
    ".word 0x90BB\n"  /* mov.w @(0x176,PC),r0 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x891C\n"  /* bt 0x060273E6 */
    ".word 0x90BA\n"  /* mov.w @(0x174,PC),r0 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x890C\n"  /* bt 0x060273CC */
    ".word 0x90B8\n"  /* mov.w @(0x170,PC),r0 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x8904\n"  /* bt 0x060273C2 */
    ".word 0x93B5\n"  /* mov.w @(0x16A,PC),r3 */
    ".word 0xD15B\n"  /* mov.l @(0x16C,PC),r1  {[0x06027528] = 0x00000AC0} */
    ".word 0x92A2\n"  /* mov.w @(0x144,PC),r2 */
    ".word 0xA036\n"  /* bra 0x0602742E */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0x93AF\n"  /* mov.w @(0x15E,PC),r3 */
    ".word 0xD159\n"  /* mov.l @(0x164,PC),r1  {[0x0602752C] = 0x00001581} */
    ".word 0x929E\n"  /* mov.w @(0x13C,PC),r2 */
    ".word 0xA031\n"  /* bra 0x0602742E */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0x90A9\n"  /* mov.w @(0x152,PC),r0 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x8904\n"  /* bt 0x060273DC */
    ".word 0x93A6\n"  /* mov.w @(0x14C,PC),r3 */
    ".word 0xD156\n"  /* mov.l @(0x158,PC),r1  {[0x06027530] = 0x000047AE} */
    ".word 0x9297\n"  /* mov.w @(0x12E,PC),r2 */
    ".word 0xA029\n"  /* bra 0x0602742E */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0xD155\n"  /* mov.l @(0x154,PC),r1  {[0x06027534] = 0x0000B333} */
    ".word 0x9294\n"  /* mov.w @(0x128,PC),r2 */
    ".word 0xE364\n"  /* mov #100,r3 */
    ".word 0xA024\n"  /* bra 0x0602742E */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0x9099\n"  /* mov.w @(0x132,PC),r0 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x890C\n"  /* bt 0x06027406 */
    ".word 0x9097\n"  /* mov.w @(0x12E,PC),r0 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x8904\n"  /* bt 0x060273FC */
    ".word 0xD151\n"  /* mov.l @(0x144,PC),r1  {[0x06027538] = 0x00018000} */
    ".word 0x928A\n"  /* mov.w @(0x114,PC),r2 */
    ".word 0xE346\n"  /* mov #70,r3 */
    ".word 0xA019\n"  /* bra 0x0602742E */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0xD14F\n"  /* mov.l @(0x13C,PC),r1  {[0x0602753C] = 0x0002F333} */
    ".word 0x9286\n"  /* mov.w @(0x10C,PC),r2 */
    ".word 0xE332\n"  /* mov #50,r3 */
    ".word 0xA014\n"  /* bra 0x0602742E */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0x9087\n"  /* mov.w @(0x10E,PC),r0 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x890C\n"  /* bt 0x06027426 */
    ".word 0x9085\n"  /* mov.w @(0x10A,PC),r0 */
    ".word 0x3056\n"  /* cmp/hi r5,r0 */
    ".word 0x8904\n"  /* bt 0x0602741C */
    ".word 0xD14B\n"  /* mov.l @(0x12C,PC),r1  {[0x06027540] = 0x00053333} */
    ".word 0x927C\n"  /* mov.w @(0xF8,PC),r2 */
    ".word 0xE328\n"  /* mov #40,r3 */
    ".word 0xA009\n"  /* bra 0x0602742E */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0xD149\n"  /* mov.l @(0x124,PC),r1  {[0x06027544] = 0x0008B333} */
    ".word 0x9278\n"  /* mov.w @(0xF0,PC),r2 */
    ".word 0xE31E\n"  /* mov #30,r3 */
    ".word 0xA004\n"  /* bra 0x0602742E */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0xD148\n"  /* mov.l @(0x120,PC),r1  {[0x06027548] = 0x0015B6DB} */
    ".word 0x9274\n"  /* mov.w @(0xE8,PC),r2 */
    ".word 0xE310\n"  /* mov #16,r3 */
    ".word 0x6339\n"  /* swap.w r3,r3 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x314D\n"  /* dmuls.l r4,r1 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8F01\n"  /* bf/s 0x0602743E */
    ".word 0x302C\n"  /* add r2,r0 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x905B\n"  /* mov.w @(0xB6,PC),r0 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8BFA\n"  /* bf 0x0602743E */
    ".word 0x000B\n"  /* rts */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B05\n"  /* bf 0x0602745C */
    ".word 0x9054\n"  /* mov.w @(0xA8,PC),r0 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8900\n"  /* bt 0x06027458 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
/* FUN_0602745C: moved to atan.c */
/* FUN_06027498: moved to vec3_math.c */
__asm__(



    ".balign 2\n"
    ".global _spring_damper_physics\n"
    ".type _spring_damper_physics, @function\n"









    ".section .text.FUN_060276CC, \"ax\"\n"

    ".global _FUN_060276CC\n"
    "_spring_damper_physics:\n"
    "_FUN_060276CC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD119\n"  /* mov.l @(0x64,PC),r1  {[0x0602773C] = 0x0000E666} */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x06027740] = 0x00001999} */
    ".word 0x6055\n"  /* mov.w @r5+,r0 */
    ".word 0xDE1A\n"  /* mov.l @(0x68,PC),r14  {[0x06027744] = 0x06063F04} */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B5B\n"  /* bf 0x0602779A */
    ".word 0x5645\n"  /* mov.l @(0x14,r4),r6 */
    ".word 0x574B\n"  /* mov.l @(0x2C,r4),r7 */
    ".word 0x3673\n"  /* cmp/ge r7,r6 */
    ".word 0x8B2E\n"  /* bf 0x06027748 */
    ".word 0x6742\n"  /* mov.l @r4,r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5643\n"  /* mov.l @(0xC,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5741\n"  /* mov.l @(0x4,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x2492\n"  /* mov.l r9,@r4 */
    ".word 0x5644\n"  /* mov.l @(0x10,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5742\n"  /* mov.l @(0x8,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1491\n"  /* mov.l r9,@(0x4,r4) */
    ".word 0x5645\n"  /* mov.l @(0x14,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1492\n"  /* mov.l r9,@(0x8,r4) */
    ".word 0x39E3\n"  /* cmp/ge r14,r9 */
    ".word 0x8BD8\n"  /* bf 0x060276EA */
    ".word 0xA135\n"  /* bra 0x060279A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE666\n"  /* mov #102,r6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1999\n"  /* mov.l r9,@(0x24,r9) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F04\n"  /* .word 0x3F04 */
    ".word 0x6742\n"  /* mov.l @r4,r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5649\n"  /* mov.l @(0x24,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5741\n"  /* mov.l @(0x4,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x2492\n"  /* mov.l r9,@r4 */
    ".word 0x564A\n"  /* mov.l @(0x28,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5742\n"  /* mov.l @(0x8,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1491\n"  /* mov.l r9,@(0x4,r4) */
    ".word 0x564B\n"  /* mov.l @(0x2C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1492\n"  /* mov.l r9,@(0x8,r4) */
    ".word 0x39E3\n"  /* cmp/ge r14,r9 */
    ".word 0x8BD8\n"  /* bf 0x06027748 */
    ".word 0xA106\n"  /* bra 0x060279A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6055\n"  /* mov.w @r5+,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B55\n"  /* bf 0x0602784C */
    ".word 0x5648\n"  /* mov.l @(0x20,r4),r6 */
    ".word 0x5742\n"  /* mov.l @(0x8,r4),r7 */
    ".word 0x3673\n"  /* cmp/ge r7,r6 */
    ".word 0x8B28\n"  /* bf 0x060277FA */
    ".word 0x5743\n"  /* mov.l @(0xC,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5646\n"  /* mov.l @(0x18,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5744\n"  /* mov.l @(0x10,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1493\n"  /* mov.l r9,@(0xC,r4) */
    ".word 0x5647\n"  /* mov.l @(0x1C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5745\n"  /* mov.l @(0x14,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x5648\n"  /* mov.l @(0x20,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1495\n"  /* mov.l r9,@(0x14,r4) */
    ".word 0x39E3\n"  /* cmp/ge r14,r9 */
    ".word 0x8BD8\n"  /* bf 0x060277A8 */
    ".word 0xA0D6\n"  /* bra 0x060279A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x5743\n"  /* mov.l @(0xC,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5744\n"  /* mov.l @(0x10,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1493\n"  /* mov.l r9,@(0xC,r4) */
    ".word 0x5641\n"  /* mov.l @(0x4,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5745\n"  /* mov.l @(0x14,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x5642\n"  /* mov.l @(0x8,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1495\n"  /* mov.l r9,@(0x14,r4) */
    ".word 0x39E3\n"  /* cmp/ge r14,r9 */
    ".word 0x8BD8\n"  /* bf 0x060277FA */
    ".word 0xA0AD\n"  /* bra 0x060279A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6055\n"  /* mov.w @r5+,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B55\n"  /* bf 0x060278FE */
    ".word 0x564B\n"  /* mov.l @(0x2C,r4),r6 */
    ".word 0x5745\n"  /* mov.l @(0x14,r4),r7 */
    ".word 0x3673\n"  /* cmp/ge r7,r6 */
    ".word 0x8B28\n"  /* bf 0x060278AC */
    ".word 0x5746\n"  /* mov.l @(0x18,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5649\n"  /* mov.l @(0x24,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5747\n"  /* mov.l @(0x1C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1496\n"  /* mov.l r9,@(0x18,r4) */
    ".word 0x564A\n"  /* mov.l @(0x28,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5748\n"  /* mov.l @(0x20,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1497\n"  /* mov.l r9,@(0x1C,r4) */
    ".word 0x564B\n"  /* mov.l @(0x2C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1498\n"  /* mov.l r9,@(0x20,r4) */
    ".word 0x39E3\n"  /* cmp/ge r14,r9 */
    ".word 0x8BD8\n"  /* bf 0x0602785A */
    ".word 0xA07D\n"  /* bra 0x060279A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x5746\n"  /* mov.l @(0x18,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5643\n"  /* mov.l @(0xC,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5747\n"  /* mov.l @(0x1C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1496\n"  /* mov.l r9,@(0x18,r4) */
    ".word 0x5644\n"  /* mov.l @(0x10,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5748\n"  /* mov.l @(0x20,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1497\n"  /* mov.l r9,@(0x1C,r4) */
    ".word 0x5645\n"  /* mov.l @(0x14,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1498\n"  /* mov.l r9,@(0x20,r4) */
    ".word 0x39E3\n"  /* cmp/ge r14,r9 */
    ".word 0x8BD8\n"  /* bf 0x060278AC */
    ".word 0xA054\n"  /* bra 0x060279A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x5642\n"  /* mov.l @(0x8,r4),r6 */
    ".word 0x5748\n"  /* mov.l @(0x20,r4),r7 */
    ".word 0x3673\n"  /* cmp/ge r7,r6 */
    ".word 0x8B28\n"  /* bf 0x06027958 */
    ".word 0x5749\n"  /* mov.l @(0x24,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574A\n"  /* mov.l @(0x28,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1499\n"  /* mov.l r9,@(0x24,r4) */
    ".word 0x5641\n"  /* mov.l @(0x4,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574B\n"  /* mov.l @(0x2C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x149A\n"  /* mov.l r9,@(0x28,r4) */
    ".word 0x5642\n"  /* mov.l @(0x8,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x149B\n"  /* mov.l r9,@(0x2C,r4) */
    ".word 0x39E3\n"  /* cmp/ge r14,r9 */
    ".word 0x8BD8\n"  /* bf 0x06027906 */
    ".word 0xA027\n"  /* bra 0x060279A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x5749\n"  /* mov.l @(0x24,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5646\n"  /* mov.l @(0x18,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574A\n"  /* mov.l @(0x28,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1499\n"  /* mov.l r9,@(0x24,r4) */
    ".word 0x5647\n"  /* mov.l @(0x1C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574B\n"  /* mov.l @(0x2C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x149A\n"  /* mov.l r9,@(0x28,r4) */
    ".word 0x5648\n"  /* mov.l @(0x20,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x149B\n"  /* mov.l r9,@(0x2C,r4) */
    ".word 0x39E3\n"  /* cmp/ge r14,r9 */
    ".word 0x8BD8\n"  /* bf 0x06027958 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _spring_damper_physics, .-_spring_damper_physics\n"
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060279B0, \"ax\"\n"

    ".global _FUN_060279B0\n"
    ".type _FUN_060279B0, @function\n"
    "_FUN_060279B0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD11B\n"  /* mov.l @(0x6C,PC),r1  {[0x06027A2C] = 0x0000E666} */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x06027A30] = 0x00001999} */
    ".word 0xDE1C\n"  /* mov.l @(0x70,PC),r14  {[0x06027A34] = 0x06063F08} */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x6C53\n"  /* mov r5,r12 */
    ".word 0x60C1\n"  /* mov.w @r12,r0 */
    ".word 0x2F01\n"  /* mov.w r0,@r15 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x81F1\n"  /* mov.w r0,@(0x2,r15) */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x81F2\n"  /* mov.w r0,@(0x4,r15) */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x81F3\n"  /* mov.w r0,@(0x6,r15) */
    ".word 0x60F1\n"  /* mov.w @r15,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B55\n"  /* bf 0x06027A8A */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B29\n"  /* bf 0x06027A38 */
    ".word 0x6742\n"  /* mov.l @r4,r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5643\n"  /* mov.l @(0xC,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5741\n"  /* mov.l @(0x4,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x2492\n"  /* mov.l r9,@r4 */
    ".word 0x5644\n"  /* mov.l @(0x10,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5742\n"  /* mov.l @(0x8,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1491\n"  /* mov.l r9,@(0x4,r4) */
    ".word 0x5645\n"  /* mov.l @(0x14,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0xA029\n"  /* bra 0x06027A7E */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE666\n"  /* mov #102,r6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1999\n"  /* mov.l r9,@(0x24,r9) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x6742\n"  /* mov.l @r4,r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5649\n"  /* mov.l @(0x24,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5741\n"  /* mov.l @(0x4,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x2492\n"  /* mov.l r9,@r4 */
    ".word 0x564A\n"  /* mov.l @(0x28,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5742\n"  /* mov.l @(0x8,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1491\n"  /* mov.l r9,@(0x4,r4) */
    ".word 0x564B\n"  /* mov.l @(0x2C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1492\n"  /* mov.l r9,@(0x8,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B01\n"  /* bf 0x06027A8A */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x2F01\n"  /* mov.w r0,@r15 */
    ".word 0x85F1\n"  /* mov.w @(0x2,r15),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B4F\n"  /* bf 0x06027B30 */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B23\n"  /* bf 0x06027ADE */
    ".word 0x5743\n"  /* mov.l @(0xC,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5646\n"  /* mov.l @(0x18,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5744\n"  /* mov.l @(0x10,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1493\n"  /* mov.l r9,@(0xC,r4) */
    ".word 0x5647\n"  /* mov.l @(0x1C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5745\n"  /* mov.l @(0x14,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x5648\n"  /* mov.l @(0x20,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0xA023\n"  /* bra 0x06027B24 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x5743\n"  /* mov.l @(0xC,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5744\n"  /* mov.l @(0x10,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1493\n"  /* mov.l r9,@(0xC,r4) */
    ".word 0x5641\n"  /* mov.l @(0x4,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5745\n"  /* mov.l @(0x14,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x5642\n"  /* mov.l @(0x8,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1495\n"  /* mov.l r9,@(0x14,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B01\n"  /* bf 0x06027B30 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81F1\n"  /* mov.w r0,@(0x2,r15) */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B4F\n"  /* bf 0x06027BD6 */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B23\n"  /* bf 0x06027B84 */
    ".word 0x5746\n"  /* mov.l @(0x18,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5649\n"  /* mov.l @(0x24,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5747\n"  /* mov.l @(0x1C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1496\n"  /* mov.l r9,@(0x18,r4) */
    ".word 0x564A\n"  /* mov.l @(0x28,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5748\n"  /* mov.l @(0x20,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1497\n"  /* mov.l r9,@(0x1C,r4) */
    ".word 0x564B\n"  /* mov.l @(0x2C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0xA023\n"  /* bra 0x06027BCA */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x5746\n"  /* mov.l @(0x18,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5643\n"  /* mov.l @(0xC,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5747\n"  /* mov.l @(0x1C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1496\n"  /* mov.l r9,@(0x18,r4) */
    ".word 0x5644\n"  /* mov.l @(0x10,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5748\n"  /* mov.l @(0x20,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1497\n"  /* mov.l r9,@(0x1C,r4) */
    ".word 0x5645\n"  /* mov.l @(0x14,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1498\n"  /* mov.l r9,@(0x20,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B01\n"  /* bf 0x06027BD6 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81F2\n"  /* mov.w r0,@(0x4,r15) */
    ".word 0x85F3\n"  /* mov.w @(0x6,r15),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B4F\n"  /* bf 0x06027C7C */
    ".word 0x60C1\n"  /* mov.w @r12,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B23\n"  /* bf 0x06027C2A */
    ".word 0x5749\n"  /* mov.l @(0x24,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574A\n"  /* mov.l @(0x28,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1499\n"  /* mov.l r9,@(0x24,r4) */
    ".word 0x5641\n"  /* mov.l @(0x4,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574B\n"  /* mov.l @(0x2C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x149A\n"  /* mov.l r9,@(0x28,r4) */
    ".word 0x5642\n"  /* mov.l @(0x8,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0xA023\n"  /* bra 0x06027C70 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x5749\n"  /* mov.l @(0x24,r4),r7 */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x5646\n"  /* mov.l @(0x18,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574A\n"  /* mov.l @(0x28,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1499\n"  /* mov.l r9,@(0x24,r4) */
    ".word 0x5647\n"  /* mov.l @(0x1C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574B\n"  /* mov.l @(0x2C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x317D\n"  /* dmuls.l r7,r1 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x149A\n"  /* mov.l r9,@(0x28,r4) */
    ".word 0x5648\n"  /* mov.l @(0x20,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x326D\n"  /* dmuls.l r6,r2 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x149B\n"  /* mov.l r9,@(0x2C,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B01\n"  /* bf 0x06027C7C */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81F3\n"  /* mov.w r0,@(0x6,r15) */
    ".word 0x67F1\n"  /* mov.w @r15,r7 */
    ".word 0x85F1\n"  /* mov.w @(0x2,r15),r0 */
    ".word 0x370C\n"  /* add r0,r7 */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0x370C\n"  /* add r0,r7 */
    ".word 0x85F3\n"  /* mov.w @(0x6,r15),r0 */
    ".word 0x307C\n"  /* add r7,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8901\n"  /* bt 0x06027C92 */
    ".word 0xAEA3\n"  /* bra 0x060279D8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06028368, \"ax\"\n"

    ".global _FUN_06028368\n"
    ".type _FUN_06028368, @function\n"
    "_FUN_06028368:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06028380] = 0x06028614} */
    ".word 0x024E\n"  /* mov.l @(r0,r4),r2 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0xBFA5\n"  /* bsr 0x060282C0 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0x6103\n"  /* mov r0,r1 */
    ".word 0xE70C\n"  /* mov #12,r7 */
    ".word 0x7105\n"  /* add #5,r1 */
    ".word 0xA00C\n"  /* bra 0x06028398 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8614\n"  /* .word 0x8614 */
);
/* FUN_06028384: moved to vdp1_cmd.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602843A, \"ax\"\n"

    ".global _FUN_0602843A\n"
    ".type _FUN_0602843A, @function\n"
    "_FUN_0602843A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x060284A4] = 0x06028614} */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0xBF5E\n"  /* bsr 0x06028306 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0xD117\n"  /* mov.l @(0x5C,PC),r1  {[0x060284A8] = 0x06063690} */
    ".word 0x361C\n"  /* add r1,r6 */
    ".word 0x6166\n"  /* mov.l @r6+,r1 */
    ".word 0x6265\n"  /* mov.w @r6+,r2 */
    ".word 0x6364\n"  /* mov.b @r6+,r3 */
    ".word 0x6464\n"  /* mov.b @r6+,r4 */
    ".word 0x6B64\n"  /* mov.b @r6+,r11 */
    ".word 0x6864\n"  /* mov.b @r6+,r8 */
    ".word 0x6C65\n"  /* mov.w @r6+,r12 */
    ".word 0x6D83\n"  /* mov r8,r13 */
    ".word 0x7DF4\n"  /* add #-12,r13 */
    ".word 0x6DDB\n"  /* neg r13,r13 */
    ".word 0x30DC\n"  /* add r13,r0 */
    ".word 0x66C3\n"  /* mov r12,r6 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x6C83\n"  /* mov r8,r12 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x6D33\n"  /* mov r3,r13 */
    ".word 0x6913\n"  /* mov r1,r9 */
    ".word 0x6704\n"  /* mov.b @r0+,r7 */
    ".word 0x2B7E\n"  /* mulu.w r7,r11 */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x397C\n"  /* add r7,r9 */
    ".word 0x6791\n"  /* mov.w @r9,r7 */
    ".word 0x372C\n"  /* add r2,r7 */
    ".word 0x2571\n"  /* mov.w r7,@r5 */
    ".word 0x7902\n"  /* add #2,r9 */
    ".word 0x4D10\n"  /* dt r13 */
    ".word 0x8FF9\n"  /* bf/s 0x06028478 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0x4C10\n"  /* dt r12 */
    ".word 0x8BF0\n"  /* bf 0x0602846C */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8FEA\n"  /* bf/s 0x06028468 */
    ".word 0x356C\n"  /* add r6,r5 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8614\n"  /* .word 0x8614 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3690\n"  /* cmp/eq r9,r6 */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_060284ae\n"
    "_FUN_060284ae:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_060284BA, \"ax\"\n"

    ".global _FUN_060284BA\n"
    ".type _FUN_060284BA, @function\n"
    "_FUN_060284BA:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD01D\n"  /* mov.l @(0x74,PC),r0  {[0x06028534] = 0x06028614} */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x6073\n"  /* mov r7,r0 */
    ".word 0xD11B\n"  /* mov.l @(0x6C,PC),r1  {[0x06028538] = 0x06063690} */
    ".word 0x361C\n"  /* add r1,r6 */
    ".word 0x6166\n"  /* mov.l @r6+,r1 */
    ".word 0x6265\n"  /* mov.w @r6+,r2 */
    ".word 0x6364\n"  /* mov.b @r6+,r3 */
    ".word 0x6464\n"  /* mov.b @r6+,r4 */
    ".word 0x6B64\n"  /* mov.b @r6+,r11 */
    ".word 0x6864\n"  /* mov.b @r6+,r8 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0xECFF\n"  /* mov #-1,r12 */
    ".word 0x6704\n"  /* mov.b @r0+,r7 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8FFC\n"  /* bf/s 0x060284DC */
    ".word 0x7C01\n"  /* add #1,r12 */
    ".word 0x23CE\n"  /* mulu.w r12,r3 */
    ".word 0x6AC3\n"  /* mov r12,r10 */
    ".word 0x0C1A\n"  /* sts macl,r12 */
    ".word 0x7CC0\n"  /* add #-64,r12 */
    ".word 0x6CCB\n"  /* neg r12,r12 */
    ".word 0x4C00\n"  /* shll r12 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x69A3\n"  /* mov r10,r9 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x6704\n"  /* mov.b @r0+,r7 */
    ".word 0x6D33\n"  /* mov r3,r13 */
    ".word 0x3788\n"  /* sub r8,r7 */
    ".word 0x2B7E\n"  /* mulu.w r7,r11 */
    ".word 0x6613\n"  /* mov r1,r6 */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x367C\n"  /* add r7,r6 */
    ".word 0x6761\n"  /* mov.w @r6,r7 */
    ".word 0x372C\n"  /* add r2,r7 */
    ".word 0x2571\n"  /* mov.w r7,@r5 */
    ".word 0x7602\n"  /* add #2,r6 */
    ".word 0x4D10\n"  /* dt r13 */
    ".word 0x8FF9\n"  /* bf/s 0x06028504 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0x4910\n"  /* dt r9 */
    ".word 0x8BEF\n"  /* bf 0x060284F6 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8FE9\n"  /* bf/s 0x060284F2 */
    ".word 0x35CC\n"  /* add r12,r5 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8614\n"  /* .word 0x8614 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3690\n"  /* cmp/eq r9,r6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06028558] = 0x06028644} */
    ".word 0x024E\n"  /* mov.l @(r0,r4),r2 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602855C] = 0x0602862C} */
    ".word 0x004E\n"  /* mov.l @(r0,r4),r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x9105\n"  /* mov.w @(0xA,PC),r1 */
    ".word 0x2022\n"  /* mov.l r2,@r0 */
    ".word 0x4110\n"  /* dt r1 */
    ".word 0x8FFC\n"  /* bf/s 0x0602854A */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8644\n"  /* .word 0x8644 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x862C\n"  /* .word 0x862C */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06028574] = 0x060612C4} */
    ".word 0x9106\n"  /* mov.w @(0xC,PC),r1 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06028578] = 0x00200020} */
    ".word 0x2022\n"  /* mov.l r2,@r0 */
    ".word 0x4110\n"  /* dt r1 */
    ".word 0x8FFC\n"  /* bf/s 0x06028566 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0380\n"  /* .word 0x0380 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12C4\n"  /* mov.l r12,@(0x10,r2) */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2800\n"  /* mov.b r0,@r8 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06028580, \"ax\"\n"

    ".global _FUN_06028580\n"
    ".type _FUN_06028580, @function\n"
    "_FUN_06028580:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4518\n"  /* shll8 r5 */
    ".word 0x4509\n"  /* shlr2 r5 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x9425\n"  /* mov.w @(0x4A,PC),r4 */
    ".word 0x4611\n"  /* cmp/pz r6 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x8D01\n"  /* bt/s 0x06028598 */
    ".word 0x0C29\n"  /* .word 0x0C29 */
    ".word 0x666B\n"  /* neg r6,r6 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06028598, \"ax\"\n"

    ".global _FUN_06028598\n"
    ".type _FUN_06028598, @function\n"
    "_FUN_06028598:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6E63\n"  /* mov r6,r14 */
    ".word 0x246E\n"  /* mulu.w r6,r4 */
    ".word 0x6D53\n"  /* mov r5,r13 */
    ".word 0x9636\n"  /* mov.w @(0x6C,PC),r6 */
    ".word 0x750A\n"  /* add #10,r5 */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x4729\n"  /* shlr16 r7 */
    ".word 0x374C\n"  /* add r4,r7 */
    ".word 0xBEDD\n"  /* bsr 0x06028368 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x4E29\n"  /* shlr16 r14 */
    ".word 0x67EF\n"  /* exts.w r14,r7 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0xBED8\n"  /* bsr 0x06028368 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD508\n"  /* mov.l @(0x20,PC),r5  {[0x060285DC] = 0x06028614} */
    ".word 0xE02E\n"  /* mov #46,r0 */
    ".word 0x5252\n"  /* mov.l @(0x8,r5),r2 */
    ".word 0x206B\n"  /* or r6,r0 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x2CC8\n"  /* tst r12,r12 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x32DC\n"  /* add r13,r2 */
    ".word 0x8127\n"  /* mov.w r0,@(0xE,r2) */
    ".word 0x8F03\n"  /* bf/s 0x060285D4 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0xE12D\n"  /* mov #45,r1 */
    ".word 0x216B\n"  /* or r6,r1 */
    ".word 0x2211\n"  /* mov.w r1,@r2 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x2710\n"  /* mov.b r1,@r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8614\n"  /* .word 0x8614 */
    ".word 0x4518\n"  /* shll8 r5 */
    ".word 0x6763\n"  /* mov r6,r7 */
    ".word 0x9614\n"  /* mov.w @(0x28,PC),r6 */
    ".word 0x4509\n"  /* shlr2 r5 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xAEE4\n"  /* bra 0x060283B8 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x4518\n"  /* shll8 r5 */
    ".word 0x6763\n"  /* mov r6,r7 */
    ".word 0x960C\n"  /* mov.w @(0x18,PC),r6 */
    ".word 0x4509\n"  /* shlr2 r5 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xAEC2\n"  /* bra 0x06028384 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x4518\n"  /* shll8 r5 */
    ".word 0x6763\n"  /* mov r6,r7 */
    ".word 0x9604\n"  /* mov.w @(0x8,PC),r6 */
    ".word 0x4509\n"  /* shlr2 r5 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xAEE8\n"  /* bra 0x060283E0 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x1294\n"  /* mov.l r9,@(0x10,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x1298\n"  /* mov.l r9,@(0x20,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x129C\n"  /* mov.l r9,@(0x30,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12A0\n"  /* mov.l r10,@(0x0,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12A4\n"  /* mov.l r10,@(0x10,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12A8\n"  /* mov.l r10,@(0x20,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12AC\n"  /* mov.l r10,@(0x30,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12B0\n"  /* mov.l r11,@(0x0,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12B4\n"  /* mov.l r11,@(0x10,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12B8\n"  /* mov.l r11,@(0x20,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12BC\n"  /* mov.l r11,@(0x30,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12C0\n"  /* mov.l r12,@(0x0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0020\n"  /* .word 0x0020 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_06029740, \"ax\"\n"

    ".global _FUN_06029740\n"
    ".type _FUN_06029740, @function\n"
    "_FUN_06029740:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x06029770] = 0x0000E666} */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x06029774] = 0x00001999} */
    ".word 0xDE09\n"  /* mov.l @(0x24,PC),r14  {[0x06029778] = 0x06063F08} */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x6C53\n"  /* mov r5,r12 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x81F1\n"  /* mov.w r0,@(0x2,r15) */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x81F2\n"  /* mov.w r0,@(0x4,r15) */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x81F3\n"  /* mov.w r0,@(0x6,r15) */
    ".word 0x60C1\n"  /* mov.w @r12,r0 */
    ".word 0x2F01\n"  /* mov.w r0,@r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8907\n"  /* bt 0x0602977C */
    ".word 0xA090\n"  /* bra 0x06029890 */
    ".word 0x85F1\n"  /* mov.w @(0x2,r15),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE666\n"  /* mov #102,r6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1999\n"  /* mov.l r9,@(0x24,r9) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x060297D4 */
    ".word 0x5740\n"  /* mov.l @(0x0,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5643\n"  /* mov.l @(0xC,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5741\n"  /* mov.l @(0x4,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1493\n"  /* mov.l r9,@(0xC,r4) */
    ".word 0x5644\n"  /* mov.l @(0x10,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5742\n"  /* mov.l @(0x8,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x5645\n"  /* mov.l @(0x14,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1495\n"  /* mov.l r9,@(0x14,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x060297D4 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x0602982C */
    ".word 0x5740\n"  /* mov.l @(0x0,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5646\n"  /* mov.l @(0x18,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5741\n"  /* mov.l @(0x4,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1496\n"  /* mov.l r9,@(0x18,r4) */
    ".word 0x5647\n"  /* mov.l @(0x1C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5742\n"  /* mov.l @(0x8,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1497\n"  /* mov.l r9,@(0x1C,r4) */
    ".word 0x5648\n"  /* mov.l @(0x20,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1498\n"  /* mov.l r9,@(0x20,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x0602982C */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B01\n"  /* bf 0x06029836 */
    ".word 0xA1CC\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0x5740\n"  /* mov.l @(0x0,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5649\n"  /* mov.l @(0x24,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5741\n"  /* mov.l @(0x4,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1499\n"  /* mov.l r9,@(0x24,r4) */
    ".word 0x564A\n"  /* mov.l @(0x28,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5742\n"  /* mov.l @(0x8,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x149A\n"  /* mov.l r9,@(0x28,r4) */
    ".word 0x564B\n"  /* mov.l @(0x2C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x149B\n"  /* mov.l r9,@(0x2C,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8901\n"  /* bt 0x06029888 */
    ".word 0xA1A3\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xA19F\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8901\n"  /* bt 0x06029898 */
    ".word 0xA08A\n"  /* bra 0x060299AC */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0x85C0\n"  /* mov.w @(0x0,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x060298F0 */
    ".word 0x5743\n"  /* mov.l @(0xC,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5640\n"  /* mov.l @(0x0,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5744\n"  /* mov.l @(0x10,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1490\n"  /* mov.l r9,@(0x0,r4) */
    ".word 0x5641\n"  /* mov.l @(0x4,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5745\n"  /* mov.l @(0x14,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1491\n"  /* mov.l r9,@(0x4,r4) */
    ".word 0x5642\n"  /* mov.l @(0x8,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1492\n"  /* mov.l r9,@(0x8,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x060298F0 */
    ".word 0x81C0\n"  /* mov.w r0,@(0x0,r12) */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x06029948 */
    ".word 0x5743\n"  /* mov.l @(0xC,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5646\n"  /* mov.l @(0x18,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5744\n"  /* mov.l @(0x10,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1496\n"  /* mov.l r9,@(0x18,r4) */
    ".word 0x5647\n"  /* mov.l @(0x1C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5745\n"  /* mov.l @(0x14,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1497\n"  /* mov.l r9,@(0x1C,r4) */
    ".word 0x5648\n"  /* mov.l @(0x20,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1498\n"  /* mov.l r9,@(0x20,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x06029948 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B01\n"  /* bf 0x06029952 */
    ".word 0xA13E\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0x5743\n"  /* mov.l @(0xC,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5649\n"  /* mov.l @(0x24,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5744\n"  /* mov.l @(0x10,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1499\n"  /* mov.l r9,@(0x24,r4) */
    ".word 0x564A\n"  /* mov.l @(0x28,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5745\n"  /* mov.l @(0x14,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x149A\n"  /* mov.l r9,@(0x28,r4) */
    ".word 0x564B\n"  /* mov.l @(0x2C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x149B\n"  /* mov.l r9,@(0x2C,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8901\n"  /* bt 0x060299A4 */
    ".word 0xA115\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xA111\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8901\n"  /* bt 0x060299B4 */
    ".word 0xA08A\n"  /* bra 0x06029AC8 */
    ".word 0x85C0\n"  /* mov.w @(0x0,r12),r0 */
    ".word 0x85C0\n"  /* mov.w @(0x0,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x06029A0C */
    ".word 0x5746\n"  /* mov.l @(0x18,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5640\n"  /* mov.l @(0x0,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5747\n"  /* mov.l @(0x1C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1490\n"  /* mov.l r9,@(0x0,r4) */
    ".word 0x5641\n"  /* mov.l @(0x4,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5748\n"  /* mov.l @(0x20,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1491\n"  /* mov.l r9,@(0x4,r4) */
    ".word 0x5642\n"  /* mov.l @(0x8,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1492\n"  /* mov.l r9,@(0x8,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x06029A0C */
    ".word 0x81C0\n"  /* mov.w r0,@(0x0,r12) */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x06029A64 */
    ".word 0x5746\n"  /* mov.l @(0x18,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5643\n"  /* mov.l @(0xC,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5747\n"  /* mov.l @(0x1C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1493\n"  /* mov.l r9,@(0xC,r4) */
    ".word 0x5644\n"  /* mov.l @(0x10,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5748\n"  /* mov.l @(0x20,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x5645\n"  /* mov.l @(0x14,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1495\n"  /* mov.l r9,@(0x14,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x06029A64 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B01\n"  /* bf 0x06029A6E */
    ".word 0xA0B0\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0x5746\n"  /* mov.l @(0x18,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5649\n"  /* mov.l @(0x24,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5747\n"  /* mov.l @(0x1C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1499\n"  /* mov.l r9,@(0x24,r4) */
    ".word 0x564A\n"  /* mov.l @(0x28,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x5748\n"  /* mov.l @(0x20,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x149A\n"  /* mov.l r9,@(0x28,r4) */
    ".word 0x564B\n"  /* mov.l @(0x2C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x149B\n"  /* mov.l r9,@(0x2C,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8901\n"  /* bt 0x06029AC0 */
    ".word 0xA087\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xA083\n"  /* bra 0x06029BCE */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x06029B1E */
    ".word 0x5749\n"  /* mov.l @(0x24,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5640\n"  /* mov.l @(0x0,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574A\n"  /* mov.l @(0x28,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1490\n"  /* mov.l r9,@(0x0,r4) */
    ".word 0x5641\n"  /* mov.l @(0x4,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574B\n"  /* mov.l @(0x2C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1491\n"  /* mov.l r9,@(0x4,r4) */
    ".word 0x5642\n"  /* mov.l @(0x8,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1492\n"  /* mov.l r9,@(0x8,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x06029B1E */
    ".word 0x81C0\n"  /* mov.w r0,@(0x0,r12) */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x06029B76 */
    ".word 0x5749\n"  /* mov.l @(0x24,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5643\n"  /* mov.l @(0xC,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574A\n"  /* mov.l @(0x28,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1493\n"  /* mov.l r9,@(0xC,r4) */
    ".word 0x5644\n"  /* mov.l @(0x10,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574B\n"  /* mov.l @(0x2C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1494\n"  /* mov.l r9,@(0x10,r4) */
    ".word 0x5645\n"  /* mov.l @(0x14,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1495\n"  /* mov.l r9,@(0x14,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x06029B76 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x06029BCE */
    ".word 0x5749\n"  /* mov.l @(0x24,r4),r7 */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x5646\n"  /* mov.l @(0x18,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574A\n"  /* mov.l @(0x28,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1496\n"  /* mov.l r9,@(0x18,r4) */
    ".word 0x5647\n"  /* mov.l @(0x1C,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0x574B\n"  /* mov.l @(0x2C,r4),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x327D\n"  /* dmuls.l r7,r2 */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x1497\n"  /* mov.l r9,@(0x1C,r4) */
    ".word 0x5648\n"  /* mov.l @(0x20,r4),r6 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x081A\n"  /* sts macl,r8 */
    ".word 0x316D\n"  /* dmuls.l r6,r1 */
    ".word 0x287D\n"  /* .word 0x287D */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x296D\n"  /* .word 0x296D */
    ".word 0x398C\n"  /* add r8,r9 */
    ".word 0x7904\n"  /* add #4,r9 */
    ".word 0x1498\n"  /* mov.l r9,@(0x20,r4) */
    ".word 0x39E7\n"  /* cmp/gt r14,r9 */
    ".word 0x8B00\n"  /* bf 0x06029BCE */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x67C1\n"  /* mov.w @r12,r7 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x370C\n"  /* add r0,r7 */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x370C\n"  /* add r0,r7 */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x307C\n"  /* add r7,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8901\n"  /* bt 0x06029BE4 */
    ".word 0xADC2\n"  /* bra 0x06029768 */
    ".word 0x60F1\n"  /* mov.w @r15,r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".global _FUN_06029bf4\n"
    "_FUN_06029bf4:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0xDA0A\n"  /* mov.l @(0x28,PC),r10  {[0x06029C30] = 0x06063F08} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0xDC06\n"  /* mov.l @(0x18,PC),r12  {[0x06029C34] = 0x0605BE36} */
    ".word 0x60C1\n"  /* mov.w @r12,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x890A\n"  /* bt 0x06029C38 */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x9103\n"  /* mov.w @(0x6,PC),r1 */
    ".word 0x3100\n"  /* cmp/eq r0,r1 */
    ".word 0x8B06\n"  /* bf 0x06029C38 */
    ".word 0xA2C4\n"  /* bra 0x0602A1B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0097\n"  /* mul.l r9,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBE36\n"  /* bsr 0x060298A6 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xE10C\n"  /* mov #12,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0xD52C\n"  /* mov.l @(0xB0,PC),r5  {[0x06029CF4] = 0x0608A70C} */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x06029CF8] = 0x06089EDC} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0xDB1A\n"  /* mov.l @(0x68,PC),r11  {[0x06029CFC] = 0x0608A704} */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x2B01\n"  /* mov.w r0,@r11 */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B32\n"  /* bf 0x06029D04 */
    ".word 0xD518\n"  /* mov.l @(0x60,PC),r5  {[0x06029D00] = 0x0608A73C} */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06029CF8] = 0x06089EDC} */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x6202\n"  /* mov.l @r0,r2 */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0xD406\n"  /* mov.l @(0x18,PC),r4  {[0x06029CF4] = 0x0608A70C} */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x201D\n"  /* .word 0x201D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x890A\n"  /* bt 0x06029D04 */
    ".word 0xA262\n"  /* bra 0x0602A1B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA70C\n"  /* bra 0x0602AB12 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA704\n"  /* bra 0x0602AB0A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA73C\n"  /* bra 0x0602AB7E */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xE10C\n"  /* mov #12,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0xD54A\n"  /* mov.l @(0x128,PC),r5  {[0x06029E38] = 0x0608A718} */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD04A\n"  /* mov.l @(0x128,PC),r0  {[0x06029E3C] = 0x06089EDC} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B1\n"  /* mov.w r0,@(0x2,r11) */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xE10C\n"  /* mov #12,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0xD535\n"  /* mov.l @(0xD4,PC),r5  {[0x06029E40] = 0x0608A724} */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD032\n"  /* mov.l @(0xC8,PC),r0  {[0x06029E3C] = 0x06089EDC} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B2\n"  /* mov.w r0,@(0x4,r11) */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xE10C\n"  /* mov #12,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0xD51E\n"  /* mov.l @(0x78,PC),r5  {[0x06029E44] = 0x0608A730} */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06029E3C] = 0x06089EDC} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B3\n"  /* mov.w r0,@(0x6,r11) */
    ".word 0x62B5\n"  /* mov.w @r11+,r2 */
    ".word 0x63B5\n"  /* mov.w @r11+,r3 */
    ".word 0x61B5\n"  /* mov.w @r11+,r1 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8914\n"  /* bt 0x06029E58 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B0A\n"  /* bf 0x06029E48 */
    ".word 0xA1C0\n"  /* bra 0x0602A1B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA718\n"  /* bra 0x0602AC6E */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA724\n"  /* bra 0x0602AC8E */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA730\n"  /* bra 0x0602ACAA */
    ".word 0xD118\n"  /* mov.l @(0x60,PC),r1  {[0x06029EAC] = 0x0602A1E0} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x06029EB0] = 0x0608A70C} */
    ".word 0xD518\n"  /* mov.l @(0x60,PC),r5  {[0x06029EB4] = 0x0608A704} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x06029EB8] = 0x060620D0} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x0107\n"  /* mul.l r0,r1 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x06029EBC] = 0x0608AC20} */
    ".word 0xDB17\n"  /* mov.l @(0x5C,PC),r11  {[0x06029EC0] = 0x0608A76C} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x06029EB0] = 0x0608A70C} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xDC0C\n"  /* mov.l @(0x30,PC),r12  {[0x06029EC4] = 0x0608A6FC} */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x9306\n"  /* mov.w @(0xC,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B14\n"  /* bf 0x06029EC8 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA025\n"  /* bra 0x06029EEE */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA1E0\n"  /* bra 0x0602A272 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA70C\n"  /* bra 0x0602ACCE */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA704\n"  /* bra 0x0602ACC2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x06029702 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA76C\n"  /* bra 0x0602AD9E */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA6FC\n"  /* bra 0x0602ACC2 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x06029ED6 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x06029EEE */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x06029EE4 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x06029EEE */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x06029EEE */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x06029F32 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x06029F58 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x06029F40 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x06029F58 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x06029F4E */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x06029F58 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x06029F58 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7510\n"  /* add #16,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x06029F9C */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x06029FC2 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x06029FAA */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x06029FC2 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x06029FB8 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x06029FC2 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x06029FC2 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7518\n"  /* add #24,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602A006 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602A02C */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602A014 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602A02C */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602A022 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602A02C */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9315\n"  /* mov.w @(0x2A,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602A02C */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x0602A054] = 0xFFFFFF50} */
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x0602A058] = 0x000000B0} */
    ".word 0xD60A\n"  /* mov.l @(0x28,PC),r6  {[0x0602A05C] = 0xFFFFFF81} */
    ".word 0xD70B\n"  /* mov.l @(0x2C,PC),r7  {[0x0602A060] = 0x00000051} */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B14\n"  /* bf 0x0602A064 */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B11\n"  /* bf 0x0602A064 */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B0E\n"  /* bf 0x0602A064 */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B0B\n"  /* bf 0x0602A064 */
    ".word 0xA0B3\n"  /* bra 0x0602A1B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x890A\n"  /* bt 0x0602A080 */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8907\n"  /* bt 0x0602A080 */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8904\n"  /* bt 0x0602A080 */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8901\n"  /* bt 0x0602A080 */
    ".word 0xA09B\n"  /* bra 0x0602A1B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B0A\n"  /* bf 0x0602A09C */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B07\n"  /* bf 0x0602A09C */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B04\n"  /* bf 0x0602A09C */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B01\n"  /* bf 0x0602A09C */
    ".word 0xA08D\n"  /* bra 0x0602A1B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x890A\n"  /* bt 0x0602A0B8 */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8907\n"  /* bt 0x0602A0B8 */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8904\n"  /* bt 0x0602A0B8 */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8901\n"  /* bt 0x0602A0B8 */
    ".word 0xA07F\n"  /* bra 0x0602A1B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x61C1\n"  /* mov.w @r12,r1 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B01\n"  /* bf 0x0602A0CE */
    ".word 0xA074\n"  /* bra 0x0602A1B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8906\n"  /* bt 0x0602A0E0 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x0602A128] = 0x0602A1F0} */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x8194\n"  /* mov.w r0,@(0x8,r9) */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x8195\n"  /* mov.w r0,@(0xA,r9) */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x8196\n"  /* mov.w r0,@(0xC,r9) */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x8197\n"  /* mov.w r0,@(0xE,r9) */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x8198\n"  /* mov.w r0,@(0x10,r9) */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x8199\n"  /* mov.w r0,@(0x12,r9) */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x819A\n"  /* mov.w r0,@(0x14,r9) */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x819B\n"  /* mov.w r0,@(0x16,r9) */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x8193\n"  /* mov.w r0,@(0x6,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x8094\n"  /* mov.b r0,@(0x4,r9) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x0602A12C] = 0x0602A200} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x0602A130] = 0x0608A70C} */
    ".word 0x5312\n"  /* mov.l @(0x8,r1),r3 */
    ".word 0x5415\n"  /* mov.l @(0x14,r1),r4 */
    ".word 0x5518\n"  /* mov.l @(0x20,r1),r5 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x561B\n"  /* mov.l @(0x2C,r1),r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA1F0\n"  /* bra 0x0602A50E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA200\n"  /* bra 0x0602A532 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA70C\n"  /* bra 0x0602AF4E */
    ".global _FUN_0602a134\n"
    "_FUN_0602a134:\n"
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0xA02F\n"  /* bra 0x0602A19E */
    ".word 0x0009\n"  /* nop */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602A146 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602A14C */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x0602A152 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA024\n"  /* bra 0x0602A19E */
    ".word 0x0009\n"  /* nop */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602A15C */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602A162 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602A168 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA019\n"  /* bra 0x0602A19E */
    ".word 0x0009\n"  /* nop */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602A184] = 0x000B8000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602A174 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602A17A */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602A180 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA00D\n"  /* bra 0x0602A19E */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602A1C4] = 0x00010000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602A190 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602A196 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602A19C */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x0602A1C8] = 0x060620D0} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD10A\n"  /* mov.l @(0x28,PC),r1  {[0x0602A1CC] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x8908\n"  /* bt 0x0602A1D0 */
    ".word 0xAD29\n"  /* bra 0x06029C14 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0602ABC2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x76CC\n"  /* add #-52,r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x79B0\n"  /* add #-80,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x9740\n"  /* mov.w @(0x80,PC),r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x7E08\n"  /* add #8,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x2820\n"  /* mov.b r2,@r8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x2AE0\n"  /* mov.b r14,@r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA134\n"  /* bra 0x0602A46E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA140\n"  /* bra 0x0602A48A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA156\n"  /* bra 0x0602A4BA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA188\n"  /* bra 0x0602A522 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA16C\n"  /* bra 0x0602A4EE */
    ".global _FUN_0602a214\n"
    "_FUN_0602a214:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0xDA0A\n"  /* mov.l @(0x28,PC),r10  {[0x0602A250] = 0x06063F08} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0xDC06\n"  /* mov.l @(0x18,PC),r12  {[0x0602A254] = 0x0605BE36} */
    ".word 0x60C1\n"  /* mov.w @r12,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x890A\n"  /* bt 0x0602A258 */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x9103\n"  /* mov.w @(0x6,PC),r1 */
    ".word 0x3100\n"  /* cmp/eq r0,r1 */
    ".word 0x8B06\n"  /* bf 0x0602A258 */
    ".word 0xA2C4\n"  /* bra 0x0602A7D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0097\n"  /* mul.l r9,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBE36\n"  /* bsr 0x06029EC6 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xE10C\n"  /* mov #12,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0xD52C\n"  /* mov.l @(0xB0,PC),r5  {[0x0602A314] = 0x0608A7A0} */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x0602A318] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0xDB1A\n"  /* mov.l @(0x68,PC),r11  {[0x0602A31C] = 0x0608A798} */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x2B01\n"  /* mov.w r0,@r11 */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B32\n"  /* bf 0x0602A324 */
    ".word 0xD518\n"  /* mov.l @(0x60,PC),r5  {[0x0602A320] = 0x0608A7D0} */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x0602A318] = 0x0608A52C} */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x6202\n"  /* mov.l @r0,r2 */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0xD406\n"  /* mov.l @(0x18,PC),r4  {[0x0602A314] = 0x0608A7A0} */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x201D\n"  /* .word 0x201D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x890A\n"  /* bt 0x0602A324 */
    ".word 0xA262\n"  /* bra 0x0602A7D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA7A0\n"  /* bra 0x0602B25A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0602AD76 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA798\n"  /* bra 0x0602B252 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA7D0\n"  /* bra 0x0602B2C6 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xE10C\n"  /* mov #12,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0xD54A\n"  /* mov.l @(0x128,PC),r5  {[0x0602A458] = 0x0608A7AC} */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD04A\n"  /* mov.l @(0x128,PC),r0  {[0x0602A45C] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B1\n"  /* mov.w r0,@(0x2,r11) */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xE10C\n"  /* mov #12,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0xD535\n"  /* mov.l @(0xD4,PC),r5  {[0x0602A460] = 0x0608A7B8} */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD032\n"  /* mov.l @(0xC8,PC),r0  {[0x0602A45C] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B2\n"  /* mov.w r0,@(0x4,r11) */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xE10C\n"  /* mov #12,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0xD51E\n"  /* mov.l @(0x78,PC),r5  {[0x0602A464] = 0x0608A7C4} */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x0602A45C] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B3\n"  /* mov.w r0,@(0x6,r11) */
    ".word 0x62B5\n"  /* mov.w @r11+,r2 */
    ".word 0x63B5\n"  /* mov.w @r11+,r3 */
    ".word 0x61B5\n"  /* mov.w @r11+,r1 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8914\n"  /* bt 0x0602A478 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B0A\n"  /* bf 0x0602A468 */
    ".word 0xA1C0\n"  /* bra 0x0602A7D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA7AC\n"  /* bra 0x0602B3B6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0602AEBA */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA7B8\n"  /* bra 0x0602B3D6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA7C4\n"  /* bra 0x0602B3F2 */
    ".word 0xD118\n"  /* mov.l @(0x60,PC),r1  {[0x0602A4CC] = 0x0602A800} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0602A4D0] = 0x0608A7A0} */
    ".word 0xD518\n"  /* mov.l @(0x60,PC),r5  {[0x0602A4D4] = 0x0608A798} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0602A4D8] = 0x060620D4} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x0107\n"  /* mul.l r0,r1 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x0602A4DC] = 0x0608AC20} */
    ".word 0xDB17\n"  /* mov.l @(0x5C,PC),r11  {[0x0602A4E0] = 0x0608A800} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x0602A4D0] = 0x0608A7A0} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xDC0C\n"  /* mov.l @(0x30,PC),r12  {[0x0602A4E4] = 0x0608A790} */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x9306\n"  /* mov.w @(0xC,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B14\n"  /* bf 0x0602A4E8 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA025\n"  /* bra 0x0602A50E */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA800\n"  /* bra 0x060294D2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA7A0\n"  /* bra 0x0602B416 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA798\n"  /* bra 0x0602B40A */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x06029D22 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA800\n"  /* bra 0x060294E6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA790\n"  /* bra 0x0602B40A */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602A4F6 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602A50E */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602A504 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602A50E */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602A50E */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602A552 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602A578 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602A560 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602A578 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602A56E */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602A578 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602A578 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7510\n"  /* add #16,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602A5BC */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602A5E2 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602A5CA */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602A5E2 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602A5D8 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602A5E2 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602A5E2 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7518\n"  /* add #24,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602A626 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602A64C */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602A634 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602A64C */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602A642 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602A64C */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9315\n"  /* mov.w @(0x2A,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602A64C */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x0602A674] = 0xFFFFFF50} */
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x0602A678] = 0x000000B0} */
    ".word 0xD60A\n"  /* mov.l @(0x28,PC),r6  {[0x0602A67C] = 0xFFFFFF81} */
    ".word 0xD70B\n"  /* mov.l @(0x2C,PC),r7  {[0x0602A680] = 0x00000051} */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B14\n"  /* bf 0x0602A684 */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B11\n"  /* bf 0x0602A684 */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B0E\n"  /* bf 0x0602A684 */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B0B\n"  /* bf 0x0602A684 */
    ".word 0xA0B3\n"  /* bra 0x0602A7D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x890A\n"  /* bt 0x0602A6A0 */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8907\n"  /* bt 0x0602A6A0 */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8904\n"  /* bt 0x0602A6A0 */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8901\n"  /* bt 0x0602A6A0 */
    ".word 0xA09B\n"  /* bra 0x0602A7D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B0A\n"  /* bf 0x0602A6BC */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B07\n"  /* bf 0x0602A6BC */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B04\n"  /* bf 0x0602A6BC */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B01\n"  /* bf 0x0602A6BC */
    ".word 0xA08D\n"  /* bra 0x0602A7D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x890A\n"  /* bt 0x0602A6D8 */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8907\n"  /* bt 0x0602A6D8 */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8904\n"  /* bt 0x0602A6D8 */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8901\n"  /* bt 0x0602A6D8 */
    ".word 0xA07F\n"  /* bra 0x0602A7D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x61C1\n"  /* mov.w @r12,r1 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B01\n"  /* bf 0x0602A6EE */
    ".word 0xA074\n"  /* bra 0x0602A7D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8906\n"  /* bt 0x0602A700 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x0602A748] = 0x0602A810} */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x8194\n"  /* mov.w r0,@(0x8,r9) */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x8195\n"  /* mov.w r0,@(0xA,r9) */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x8196\n"  /* mov.w r0,@(0xC,r9) */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x8197\n"  /* mov.w r0,@(0xE,r9) */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x8198\n"  /* mov.w r0,@(0x10,r9) */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x8199\n"  /* mov.w r0,@(0x12,r9) */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x819A\n"  /* mov.w r0,@(0x14,r9) */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x819B\n"  /* mov.w r0,@(0x16,r9) */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x8193\n"  /* mov.w r0,@(0x6,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x8094\n"  /* mov.b r0,@(0x4,r9) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x0602A74C] = 0x0602A820} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x0602A750] = 0x0608A7A0} */
    ".word 0x5312\n"  /* mov.l @(0x8,r1),r3 */
    ".word 0x5415\n"  /* mov.l @(0x14,r1),r4 */
    ".word 0x5518\n"  /* mov.l @(0x20,r1),r5 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x561B\n"  /* mov.l @(0x2C,r1),r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA810\n"  /* bra 0x0602976E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA820\n"  /* bra 0x06029792 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA7A0\n"  /* bra 0x0602B696 */
    ".global _FUN_0602a754\n"
    "_FUN_0602a754:\n"
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0xA02F\n"  /* bra 0x0602A7BE */
    ".word 0x0009\n"  /* nop */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602A766 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602A76C */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x0602A772 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA024\n"  /* bra 0x0602A7BE */
    ".word 0x0009\n"  /* nop */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602A77C */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602A782 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602A788 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA019\n"  /* bra 0x0602A7BE */
    ".word 0x0009\n"  /* nop */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602A7A4] = 0x000B8000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602A794 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602A79A */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602A7A0 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA00D\n"  /* bra 0x0602A7BE */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602A7E4] = 0x00010000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602A7B0 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602A7B6 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602A7BC */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x0602A7E8] = 0x060620D4} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD10A\n"  /* mov.l @(0x28,PC),r1  {[0x0602A7EC] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x8908\n"  /* bt 0x0602A7F0 */
    ".word 0xAD29\n"  /* bra 0x0602A234 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0602B1E2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x76CC\n"  /* add #-52,r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x79B0\n"  /* add #-80,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x9740\n"  /* mov.w @(0x80,PC),r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x7E08\n"  /* add #8,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x2820\n"  /* mov.b r2,@r8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x2AE0\n"  /* mov.b r14,@r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA754\n"  /* bra 0x0602B6CE */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA760\n"  /* bra 0x0602B6EA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA776\n"  /* bra 0x0602B71A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA7A8\n"  /* bra 0x0602B782 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA78C\n"  /* bra 0x0602B74E */
    ".global _FUN_0602a834\n"
    "_FUN_0602a834:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602A840, \"ax\"\n"

    ".global _FUN_0602A840\n"
    ".type _FUN_0602A840, @function\n"
    "_FUN_0602A840:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0xDC0D\n"  /* mov.l @(0x34,PC),r12  {[0x0602A880] = 0x0608A820} */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8FFC\n"  /* bf/s 0x0602A850 */
    ".word 0x7C10\n"  /* add #16,r12 */
    ".word 0xDA0A\n"  /* mov.l @(0x28,PC),r10  {[0x0602A884] = 0x06063F08} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0xDC07\n"  /* mov.l @(0x1C,PC),r12  {[0x0602A888] = 0x0605BE36} */
    ".word 0x60C1\n"  /* mov.w @r12,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x890D\n"  /* bt 0x0602A88C */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x9103\n"  /* mov.w @(0x6,PC),r1 */
    ".word 0x3100\n"  /* cmp/eq r0,r1 */
    ".word 0x8B09\n"  /* bf 0x0602A88C */
    ".word 0xA0FC\n"  /* bra 0x0602AA74 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0097\n"  /* mul.l r9,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA820\n"  /* bra 0x060298C6 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBE36\n"  /* bsr 0x0602A4FA */
    ".word 0xDB1B\n"  /* mov.l @(0x6C,PC),r11  {[0x0602A8FC] = 0x0602AB68} */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x0602A900] = 0x0602AB88} */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x0602A904] = 0x06089EDC} */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xB102\n"  /* bsr 0x0602AAA0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x1532\n"  /* mov.l r3,@(0x8,r5) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B31\n"  /* bf 0x0602A90C */
    ".word 0xD717\n"  /* mov.l @(0x5C,PC),r7  {[0x0602A908] = 0x0602AB98} */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x2792\n"  /* mov.l r9,@r7 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x1791\n"  /* mov.l r9,@(0x4,r7) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x76DC\n"  /* add #-36,r6 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x1792\n"  /* mov.l r9,@(0x8,r7) */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x75F4\n"  /* add #-12,r5 */
    ".word 0x090A\n"  /* sts mach,r9 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x209D\n"  /* .word 0x209D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x890A\n"  /* bt 0x0602A90C */
    ".word 0xA0BD\n"  /* bra 0x0602AA74 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAB68\n"  /* bra 0x06029FD2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAB88\n"  /* bra 0x0602A016 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAB98\n"  /* bra 0x0602A03E */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x0602A980] = 0x0602A91A} */
    ".word 0xB113\n"  /* bsr 0x0602AB3A */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xB0F3\n"  /* bsr 0x0602AB00 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xD719\n"  /* mov.l @(0x64,PC),r7  {[0x0602A984] = 0x0602A92C} */
    ".word 0xB10C\n"  /* bsr 0x0602AB3A */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xB0BD\n"  /* bsr 0x0602AAA0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xB0EA\n"  /* bsr 0x0602AB00 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xD716\n"  /* mov.l @(0x58,PC),r7  {[0x0602A988] = 0x0602A93E} */
    ".word 0xB103\n"  /* bsr 0x0602AB3A */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xB0B4\n"  /* bsr 0x0602AAA0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xB0E1\n"  /* bsr 0x0602AB00 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xD712\n"  /* mov.l @(0x48,PC),r7  {[0x0602A98C] = 0x0602A950} */
    ".word 0xB0FA\n"  /* bsr 0x0602AB3A */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xB0AB\n"  /* bsr 0x0602AAA0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xB0D8\n"  /* bsr 0x0602AB00 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0602A990] = 0x060620D0} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x210E\n"  /* mulu.w r0,r1 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602A994] = 0x0608AC20} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0x7BE0\n"  /* add #-32,r11 */
    ".word 0x9C0D\n"  /* mov.w @(0x1A,PC),r12 */
    ".word 0x50B0\n"  /* mov.l @(0x0,r11),r0 */
    ".word 0x52B2\n"  /* mov.l @(0x8,r11),r2 */
    ".word 0x54B4\n"  /* mov.l @(0x10,r11),r4 */
    ".word 0x56B6\n"  /* mov.l @(0x18,r11),r6 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8B14\n"  /* bf 0x0602A998 */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8B12\n"  /* bf 0x0602A998 */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8B10\n"  /* bf 0x0602A998 */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8B0E\n"  /* bf 0x0602A998 */
    ".word 0xA07B\n"  /* bra 0x0602AA74 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA91A\n"  /* bra 0x06029BBA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA92C\n"  /* bra 0x06029BE2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA93E\n"  /* bra 0x06029C0A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xA950\n"  /* bra 0x06029C32 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x0602A1DA */
    ".word 0x9C3B\n"  /* mov.w @(0x76,PC),r12 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8905\n"  /* bt 0x0602A9AA */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8903\n"  /* bt 0x0602A9AA */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8901\n"  /* bt 0x0602A9AA */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8964\n"  /* bt 0x0602AA74 */
    ".word 0x9C33\n"  /* mov.w @(0x66,PC),r12 */
    ".word 0x51B1\n"  /* mov.l @(0x4,r11),r1 */
    ".word 0x53B3\n"  /* mov.l @(0xC,r11),r3 */
    ".word 0x55B5\n"  /* mov.l @(0x14,r11),r5 */
    ".word 0x57B7\n"  /* mov.l @(0x1C,r11),r7 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8B05\n"  /* bf 0x0602A9C4 */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8B03\n"  /* bf 0x0602A9C4 */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8B01\n"  /* bf 0x0602A9C4 */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8957\n"  /* bt 0x0602AA74 */
    ".word 0x9C27\n"  /* mov.w @(0x4E,PC),r12 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8905\n"  /* bt 0x0602A9D6 */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8903\n"  /* bt 0x0602A9D6 */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8901\n"  /* bt 0x0602A9D6 */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8B4E\n"  /* bf 0x0602AA74 */
    ".word 0x6C93\n"  /* mov r9,r12 */
    ".word 0x7C18\n"  /* add #24,r12 */
    ".word 0x2C75\n"  /* mov.w r7,@-r12 */
    ".word 0x2C65\n"  /* mov.w r6,@-r12 */
    ".word 0x2C55\n"  /* mov.w r5,@-r12 */
    ".word 0x2C45\n"  /* mov.w r4,@-r12 */
    ".word 0x2C35\n"  /* mov.w r3,@-r12 */
    ".word 0x2C25\n"  /* mov.w r2,@-r12 */
    ".word 0x2C15\n"  /* mov.w r1,@-r12 */
    ".word 0x2C05\n"  /* mov.w r0,@-r12 */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x8193\n"  /* mov.w r0,@(0x6,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x8094\n"  /* mov.b r0,@(0x4,r9) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x0602AA18] = 0x0602ABA4} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x021E\n"  /* mov.l @(r0,r1),r2 */
    ".word 0xC760\n"  /* mova @(0x180,PC),r0  {0x0602AB88} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0x5401\n"  /* mov.l @(0x4,r0),r4 */
    ".word 0x5502\n"  /* mov.l @(0x8,r0),r5 */
    ".word 0x422B\n"  /* jmp @r2 */
    ".word 0x5603\n"  /* mov.l @(0xC,r0),r6 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xABA4\n"  /* bra 0x0602A166 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0xA01B\n"  /* bra 0x0602AA5C */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602AA2C */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602AA32 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x0602AA38 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA010\n"  /* bra 0x0602AA5C */
    ".word 0x0009\n"  /* nop */
    ".word 0xA004\n"  /* bra 0x0602AA48 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA001\n"  /* bra 0x0602AA48 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602AA80] = 0x000B8000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602AA4E */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602AA54 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602AA5A */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0602AA84] = 0x060620D0} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602AA88] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x8908\n"  /* bt 0x0602AA8C */
    ".word 0xAEF3\n"  /* bra 0x0602A864 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0602B47E */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_0602aaa0\n"
    "_FUN_0602aaa0:\n"
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x0907\n"  /* mul.l r0,r9 */
    ".word 0xE718\n"  /* mov #24,r7 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x5272\n"  /* mov.l @(0x8,r7),r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x230D\n"  /* .word 0x230D */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x33A7\n"  /* cmp/gt r10,r3 */
    ".word 0x8BD7\n"  /* bf 0x0602AA74 */
    ".word 0x9219\n"  /* mov.w @(0x32,PC),r2 */
    ".word 0x9019\n"  /* mov.w @(0x32,PC),r0 */
    ".word 0x1204\n"  /* mov.l r0,@(0x10,r2) */
    ".word 0x1230\n"  /* mov.l r3,@(0x0,r2) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1205\n"  /* mov.l r0,@(0x14,r2) */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6776\n"  /* mov.l @r7+,r7 */
    ".word 0x76E8\n"  /* add #-24,r6 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x220D\n"  /* .word 0x220D */
    ".word 0x000B\n"  /* rts */
    ".word 0x327C\n"  /* add r7,r2 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_0602ab00\n"
    "_FUN_0602ab00:\n"
    ".word 0x9019\n"  /* mov.w @(0x32,PC),r0 */
    ".word 0x5407\n"  /* mov.l @(0x1C,r0),r4 */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2B12\n"  /* mov.l r1,@r11 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1B21\n"  /* mov.l r2,@(0x4,r11) */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x9710\n"  /* mov.w @(0x20,PC),r7 */
    ".word 0x3177\n"  /* cmp/gt r7,r1 */
    ".word 0x89AC\n"  /* bt 0x0602AA74 */
    ".word 0x607B\n"  /* neg r7,r0 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x89A9\n"  /* bt 0x0602AA74 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x89A7\n"  /* bt 0x0602AA74 */
    ".word 0x4701\n"  /* shlr r7 */
    ".word 0x3277\n"  /* cmp/gt r7,r2 */
    ".word 0x89A4\n"  /* bt 0x0602AA74 */
    ".word 0x2C92\n"  /* mov.l r9,@r12 */
    ".word 0x1C11\n"  /* mov.l r1,@(0x4,r12) */
    ".word 0x1C22\n"  /* mov.l r2,@(0x8,r12) */
    ".word 0x1C33\n"  /* mov.l r3,@(0xC,r12) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".global _FUN_0602ab3a\n"
    "_FUN_0602ab3a:\n"
    ".word 0xC93F\n"  /* and #0x3F,r0 */
    ".word 0xDC08\n"  /* mov.l @(0x20,PC),r12  {[0x0602AB60] = 0x0608A820} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x3C0C\n"  /* add r0,r12 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8B0C\n"  /* bf 0x0602AB64 */
    ".word 0x3900\n"  /* cmp/eq r0,r9 */
    ".word 0x8B0A\n"  /* bf 0x0602AB64 */
    ".word 0x51C1\n"  /* mov.l @(0x4,r12),r1 */
    ".word 0x52C2\n"  /* mov.l @(0x8,r12),r2 */
    ".word 0x53C3\n"  /* mov.l @(0xC,r12),r3 */
    ".word 0x2B12\n"  /* mov.l r1,@r11 */
    ".word 0x1B21\n"  /* mov.l r2,@(0x4,r11) */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x472B\n"  /* jmp @r7 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA820\n"  /* bra 0x06029BA6 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAA1C\n"  /* bra 0x06029FE2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAA26\n"  /* bra 0x06029FFA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAA3C\n"  /* bra 0x0602A02A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAA40\n"  /* bra 0x0602A036 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAA46\n"  /* bra 0x0602A046 */
    ".global _FUN_0602abb8\n"
    "_FUN_0602abb8:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602ABC4, \"ax\"\n"

    ".global _FUN_0602ABC4\n"
    ".type _FUN_0602ABC4, @function\n"
    "_FUN_0602ABC4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0xDC0D\n"  /* mov.l @(0x34,PC),r12  {[0x0602AC04] = 0x06094220} */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8FFC\n"  /* bf/s 0x0602ABD4 */
    ".word 0x7C10\n"  /* add #16,r12 */
    ".word 0xDA0A\n"  /* mov.l @(0x28,PC),r10  {[0x0602AC08] = 0x06063F08} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0xDC07\n"  /* mov.l @(0x1C,PC),r12  {[0x0602AC0C] = 0x0605BE36} */
    ".word 0x60C1\n"  /* mov.w @r12,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x890D\n"  /* bt 0x0602AC10 */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x9103\n"  /* mov.w @(0x6,PC),r1 */
    ".word 0x3100\n"  /* cmp/eq r0,r1 */
    ".word 0x8B09\n"  /* bf 0x0602AC10 */
    ".word 0xA0FC\n"  /* bra 0x0602ADF8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0097\n"  /* mul.l r9,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4220\n"  /* shal r2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBE36\n"  /* bsr 0x0602A87E */
    ".word 0xDB1B\n"  /* mov.l @(0x6C,PC),r11  {[0x0602AC80] = 0x0602AEEC} */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x0602AC84] = 0x0602AF0C} */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x0602AC88] = 0x0608A52C} */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xB102\n"  /* bsr 0x0602AE24 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x1532\n"  /* mov.l r3,@(0x8,r5) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B31\n"  /* bf 0x0602AC90 */
    ".word 0xD717\n"  /* mov.l @(0x5C,PC),r7  {[0x0602AC8C] = 0x0602AF1C} */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x2792\n"  /* mov.l r9,@r7 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x1791\n"  /* mov.l r9,@(0x4,r7) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x76DC\n"  /* add #-36,r6 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x1792\n"  /* mov.l r9,@(0x8,r7) */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x75F4\n"  /* add #-12,r5 */
    ".word 0x090A\n"  /* sts mach,r9 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x209D\n"  /* .word 0x209D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x890A\n"  /* bt 0x0602AC90 */
    ".word 0xA0BD\n"  /* bra 0x0602ADF8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAEEC\n"  /* bra 0x0602AA5E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAF0C\n"  /* bra 0x0602AAA2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0602B6E6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAF1C\n"  /* bra 0x0602AACA */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x0602AD04] = 0x0602AC9E} */
    ".word 0xB113\n"  /* bsr 0x0602AEBE */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xB0F3\n"  /* bsr 0x0602AE84 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xD719\n"  /* mov.l @(0x64,PC),r7  {[0x0602AD08] = 0x0602ACB0} */
    ".word 0xB10C\n"  /* bsr 0x0602AEBE */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xB0BD\n"  /* bsr 0x0602AE24 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xB0EA\n"  /* bsr 0x0602AE84 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xD716\n"  /* mov.l @(0x58,PC),r7  {[0x0602AD0C] = 0x0602ACC2} */
    ".word 0xB103\n"  /* bsr 0x0602AEBE */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xB0B4\n"  /* bsr 0x0602AE24 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xB0E1\n"  /* bsr 0x0602AE84 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xD712\n"  /* mov.l @(0x48,PC),r7  {[0x0602AD10] = 0x0602ACD4} */
    ".word 0xB0FA\n"  /* bsr 0x0602AEBE */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xB0AB\n"  /* bsr 0x0602AE24 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xB0D8\n"  /* bsr 0x0602AE84 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0602AD14] = 0x060620D4} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x210E\n"  /* mulu.w r0,r1 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602AD18] = 0x0608AC20} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0x7BE0\n"  /* add #-32,r11 */
    ".word 0x9C0D\n"  /* mov.w @(0x1A,PC),r12 */
    ".word 0x50B0\n"  /* mov.l @(0x0,r11),r0 */
    ".word 0x52B2\n"  /* mov.l @(0x8,r11),r2 */
    ".word 0x54B4\n"  /* mov.l @(0x10,r11),r4 */
    ".word 0x56B6\n"  /* mov.l @(0x18,r11),r6 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8B14\n"  /* bf 0x0602AD1C */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8B12\n"  /* bf 0x0602AD1C */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8B10\n"  /* bf 0x0602AD1C */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8B0E\n"  /* bf 0x0602AD1C */
    ".word 0xA07B\n"  /* bra 0x0602ADF8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAC9E\n"  /* bra 0x0602A646 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xACB0\n"  /* bra 0x0602A66E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xACC2\n"  /* bra 0x0602A696 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xACD4\n"  /* bra 0x0602A6BE */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x0602A55E */
    ".word 0x9C3B\n"  /* mov.w @(0x76,PC),r12 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8905\n"  /* bt 0x0602AD2E */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8903\n"  /* bt 0x0602AD2E */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8901\n"  /* bt 0x0602AD2E */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8964\n"  /* bt 0x0602ADF8 */
    ".word 0x9C33\n"  /* mov.w @(0x66,PC),r12 */
    ".word 0x51B1\n"  /* mov.l @(0x4,r11),r1 */
    ".word 0x53B3\n"  /* mov.l @(0xC,r11),r3 */
    ".word 0x55B5\n"  /* mov.l @(0x14,r11),r5 */
    ".word 0x57B7\n"  /* mov.l @(0x1C,r11),r7 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8B05\n"  /* bf 0x0602AD48 */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8B03\n"  /* bf 0x0602AD48 */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8B01\n"  /* bf 0x0602AD48 */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8957\n"  /* bt 0x0602ADF8 */
    ".word 0x9C27\n"  /* mov.w @(0x4E,PC),r12 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8905\n"  /* bt 0x0602AD5A */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8903\n"  /* bt 0x0602AD5A */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8901\n"  /* bt 0x0602AD5A */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8B4E\n"  /* bf 0x0602ADF8 */
    ".word 0x6C93\n"  /* mov r9,r12 */
    ".word 0x7C18\n"  /* add #24,r12 */
    ".word 0x2C75\n"  /* mov.w r7,@-r12 */
    ".word 0x2C65\n"  /* mov.w r6,@-r12 */
    ".word 0x2C55\n"  /* mov.w r5,@-r12 */
    ".word 0x2C45\n"  /* mov.w r4,@-r12 */
    ".word 0x2C35\n"  /* mov.w r3,@-r12 */
    ".word 0x2C25\n"  /* mov.w r2,@-r12 */
    ".word 0x2C15\n"  /* mov.w r1,@-r12 */
    ".word 0x2C05\n"  /* mov.w r0,@-r12 */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x8193\n"  /* mov.w r0,@(0x6,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x8094\n"  /* mov.b r0,@(0x4,r9) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x0602AD9C] = 0x0602AF28} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x021E\n"  /* mov.l @(r0,r1),r2 */
    ".word 0xC760\n"  /* mova @(0x180,PC),r0  {0x0602AF0C} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0x5401\n"  /* mov.l @(0x4,r0),r4 */
    ".word 0x5502\n"  /* mov.l @(0x8,r0),r5 */
    ".word 0x422B\n"  /* jmp @r2 */
    ".word 0x5603\n"  /* mov.l @(0xC,r0),r6 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xAF28\n"  /* bra 0x0602ABF2 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0xA01B\n"  /* bra 0x0602ADE0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602ADB0 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602ADB6 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x0602ADBC */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA010\n"  /* bra 0x0602ADE0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA004\n"  /* bra 0x0602ADCC */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA001\n"  /* bra 0x0602ADCC */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602AE04] = 0x000B8000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602ADD2 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602ADD8 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602ADDE */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0602AE08] = 0x060620D4} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602AE0C] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x8908\n"  /* bt 0x0602AE10 */
    ".word 0xAEF3\n"  /* bra 0x0602ABE8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0602B802 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_0602ae24\n"
    "_FUN_0602ae24:\n"
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x0907\n"  /* mul.l r0,r9 */
    ".word 0xE718\n"  /* mov #24,r7 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x5272\n"  /* mov.l @(0x8,r7),r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x230D\n"  /* .word 0x230D */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x33A7\n"  /* cmp/gt r10,r3 */
    ".word 0x8BD7\n"  /* bf 0x0602ADF8 */
    ".word 0x9219\n"  /* mov.w @(0x32,PC),r2 */
    ".word 0x9019\n"  /* mov.w @(0x32,PC),r0 */
    ".word 0x1204\n"  /* mov.l r0,@(0x10,r2) */
    ".word 0x1230\n"  /* mov.l r3,@(0x0,r2) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1205\n"  /* mov.l r0,@(0x14,r2) */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6776\n"  /* mov.l @r7+,r7 */
    ".word 0x76E8\n"  /* add #-24,r6 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x220D\n"  /* .word 0x220D */
    ".word 0x000B\n"  /* rts */
    ".word 0x327C\n"  /* add r7,r2 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_0602ae84\n"
    "_FUN_0602ae84:\n"
    ".word 0x9019\n"  /* mov.w @(0x32,PC),r0 */
    ".word 0x5407\n"  /* mov.l @(0x1C,r0),r4 */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2B12\n"  /* mov.l r1,@r11 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1B21\n"  /* mov.l r2,@(0x4,r11) */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x9710\n"  /* mov.w @(0x20,PC),r7 */
    ".word 0x3177\n"  /* cmp/gt r7,r1 */
    ".word 0x89AC\n"  /* bt 0x0602ADF8 */
    ".word 0x607B\n"  /* neg r7,r0 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x89A9\n"  /* bt 0x0602ADF8 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x89A7\n"  /* bt 0x0602ADF8 */
    ".word 0x4701\n"  /* shlr r7 */
    ".word 0x3277\n"  /* cmp/gt r7,r2 */
    ".word 0x89A4\n"  /* bt 0x0602ADF8 */
    ".word 0x2C92\n"  /* mov.l r9,@r12 */
    ".word 0x1C11\n"  /* mov.l r1,@(0x4,r12) */
    ".word 0x1C22\n"  /* mov.l r2,@(0x8,r12) */
    ".word 0x1C33\n"  /* mov.l r3,@(0xC,r12) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".global _FUN_0602aebe\n"
    "_FUN_0602aebe:\n"
    ".word 0xC93F\n"  /* and #0x3F,r0 */
    ".word 0xDC08\n"  /* mov.l @(0x20,PC),r12  {[0x0602AEE4] = 0x06094220} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x3C0C\n"  /* add r0,r12 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8B0C\n"  /* bf 0x0602AEE8 */
    ".word 0x3900\n"  /* cmp/eq r0,r9 */
    ".word 0x8B0A\n"  /* bf 0x0602AEE8 */
    ".word 0x51C1\n"  /* mov.l @(0x4,r12),r1 */
    ".word 0x52C2\n"  /* mov.l @(0x8,r12),r2 */
    ".word 0x53C3\n"  /* mov.l @(0xC,r12),r3 */
    ".word 0x2B12\n"  /* mov.l r1,@r11 */
    ".word 0x1B21\n"  /* mov.l r2,@(0x4,r11) */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x472B\n"  /* jmp @r7 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4220\n"  /* shal r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xADA0\n"  /* bra 0x0602AA6E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xADAA\n"  /* bra 0x0602AA86 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xADC0\n"  /* bra 0x0602AAB6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xADC4\n"  /* bra 0x0602AAC2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xADCA\n"  /* bra 0x0602AAD2 */
    ".global _FUN_0602af3c\n"
    "_FUN_0602af3c:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602AF48, \"ax\"\n"

    ".global _FUN_0602AF48\n"
    ".type _FUN_0602AF48, @function\n"
    "_FUN_0602AF48:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0xDC24\n"  /* mov.l @(0x90,PC),r12  {[0x0602AFE4] = 0x06094620} */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8FFC\n"  /* bf/s 0x0602AF58 */
    ".word 0x7C10\n"  /* add #16,r12 */
    ".word 0xDA21\n"  /* mov.l @(0x84,PC),r10  {[0x0602AFE8] = 0x06063F08} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0xDB1E\n"  /* mov.l @(0x78,PC),r11  {[0x0602AFEC] = 0x0602B2C8} */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x0602AFF0] = 0x0602B2E8} */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x0602AFF4] = 0x06089EDC} */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0xB12B\n"  /* bsr 0x0602B1D6 */
    ".word 0xE906\n"  /* mov #6,r9 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x1532\n"  /* mov.l r3,@(0x8,r5) */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x0602AFF8] = 0x0602B310} */
    ".word 0x2722\n"  /* mov.l r2,@r7 */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B37\n"  /* bf 0x0602B000 */
    ".word 0xD71A\n"  /* mov.l @(0x68,PC),r7  {[0x0602AFFC] = 0x0602B2F8} */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x2792\n"  /* mov.l r9,@r7 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x1791\n"  /* mov.l r9,@(0x4,r7) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x76DC\n"  /* add #-36,r6 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x1792\n"  /* mov.l r9,@(0x8,r7) */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x75F4\n"  /* add #-12,r5 */
    ".word 0x090A\n"  /* sts mach,r9 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x209D\n"  /* .word 0x209D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8910\n"  /* bt 0x0602B000 */
    ".word 0xA0DE\n"  /* bra 0x0602B19E */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4620\n"  /* shal r6 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB2C8\n"  /* bsr 0x0602B582 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB2E8\n"  /* bsr 0x0602B5C6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB310\n"  /* bsr 0x0602B61E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB2F8\n"  /* bsr 0x0602B5F2 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xD720\n"  /* mov.l @(0x80,PC),r7  {[0x0602B084] = 0x0602B012} */
    ".word 0xB148\n"  /* bsr 0x0602B298 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xB123\n"  /* bsr 0x0602B258 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x0602B088] = 0x0602B028} */
    ".word 0xB13F\n"  /* bsr 0x0602B298 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xB0DC\n"  /* bsr 0x0602B1D6 */
    ".word 0xE906\n"  /* mov #6,r9 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xB118\n"  /* bsr 0x0602B258 */
    ".word 0x0009\n"  /* nop */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xD718\n"  /* mov.l @(0x60,PC),r7  {[0x0602B08C] = 0x0602B03E} */
    ".word 0xB134\n"  /* bsr 0x0602B298 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xB0D1\n"  /* bsr 0x0602B1D6 */
    ".word 0xE906\n"  /* mov #6,r9 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xB10D\n"  /* bsr 0x0602B258 */
    ".word 0x0009\n"  /* nop */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xD713\n"  /* mov.l @(0x4C,PC),r7  {[0x0602B090] = 0x0602B054} */
    ".word 0xB129\n"  /* bsr 0x0602B298 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xB0C6\n"  /* bsr 0x0602B1D6 */
    ".word 0xE906\n"  /* mov #6,r9 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xB102\n"  /* bsr 0x0602B258 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0602B094] = 0x060620D0} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x210E\n"  /* mulu.w r0,r1 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602B098] = 0x0608AC20} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0x7BE0\n"  /* add #-32,r11 */
    ".word 0x9C0D\n"  /* mov.w @(0x1A,PC),r12 */
    ".word 0x50B0\n"  /* mov.l @(0x0,r11),r0 */
    ".word 0x52B2\n"  /* mov.l @(0x8,r11),r2 */
    ".word 0x54B4\n"  /* mov.l @(0x10,r11),r4 */
    ".word 0x56B6\n"  /* mov.l @(0x18,r11),r6 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8B14\n"  /* bf 0x0602B09C */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8B12\n"  /* bf 0x0602B09C */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8B10\n"  /* bf 0x0602B09C */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8B0E\n"  /* bf 0x0602B09C */
    ".word 0xA08E\n"  /* bra 0x0602B19E */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB012\n"  /* bsr 0x0602B0AE */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB028\n"  /* bsr 0x0602B0DE */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB03E\n"  /* bsr 0x0602B10E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB054\n"  /* bsr 0x0602B13E */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x0602A8DE */
    ".word 0x9C3B\n"  /* mov.w @(0x76,PC),r12 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8905\n"  /* bt 0x0602B0AE */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8903\n"  /* bt 0x0602B0AE */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8901\n"  /* bt 0x0602B0AE */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8977\n"  /* bt 0x0602B19E */
    ".word 0x9C33\n"  /* mov.w @(0x66,PC),r12 */
    ".word 0x51B1\n"  /* mov.l @(0x4,r11),r1 */
    ".word 0x53B3\n"  /* mov.l @(0xC,r11),r3 */
    ".word 0x55B5\n"  /* mov.l @(0x14,r11),r5 */
    ".word 0x57B7\n"  /* mov.l @(0x1C,r11),r7 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8B05\n"  /* bf 0x0602B0C8 */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8B03\n"  /* bf 0x0602B0C8 */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8B01\n"  /* bf 0x0602B0C8 */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x896A\n"  /* bt 0x0602B19E */
    ".word 0x9C27\n"  /* mov.w @(0x4E,PC),r12 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8905\n"  /* bt 0x0602B0DA */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8903\n"  /* bt 0x0602B0DA */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8901\n"  /* bt 0x0602B0DA */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8B61\n"  /* bf 0x0602B19E */
    ".word 0x6C93\n"  /* mov r9,r12 */
    ".word 0x7C18\n"  /* add #24,r12 */
    ".word 0x2C75\n"  /* mov.w r7,@-r12 */
    ".word 0x2C65\n"  /* mov.w r6,@-r12 */
    ".word 0x2C55\n"  /* mov.w r5,@-r12 */
    ".word 0x2C45\n"  /* mov.w r4,@-r12 */
    ".word 0x2C35\n"  /* mov.w r3,@-r12 */
    ".word 0x2C25\n"  /* mov.w r2,@-r12 */
    ".word 0x2C15\n"  /* mov.w r1,@-r12 */
    ".word 0x2C05\n"  /* mov.w r0,@-r12 */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x8193\n"  /* mov.w r0,@(0x6,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x8094\n"  /* mov.b r0,@(0x4,r9) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x0602B11C] = 0x0602B314} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x021E\n"  /* mov.l @(r0,r1),r2 */
    ".word 0xC777\n"  /* mova @(0x1DC,PC),r0  {0x0602B2E8} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0x5401\n"  /* mov.l @(0x4,r0),r4 */
    ".word 0x5502\n"  /* mov.l @(0x8,r0),r5 */
    ".word 0x422B\n"  /* jmp @r2 */
    ".word 0x5603\n"  /* mov.l @(0xC,r0),r6 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB314\n"  /* bsr 0x0602B74A */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0xA024\n"  /* bra 0x0602B172 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602B130 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602B136 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x0602B13C */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA019\n"  /* bra 0x0602B172 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602B146 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602B14C */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602B152 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA00E\n"  /* bra 0x0602B172 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA001\n"  /* bra 0x0602B15E */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0602B1A8] = 0x000B8000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602B164 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602B16A */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602B170 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD10E\n"  /* mov.l @(0x38,PC),r1  {[0x0602B1AC] = 0x0602B310} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602B1B0] = 0x06063F54} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602B1B4] = 0x00020000} */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x8B01\n"  /* bf 0x0602B186 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602B1B8] = 0x000A0000} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602B1BC] = 0x060620D0} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD10D\n"  /* mov.l @(0x34,PC),r1  {[0x0602B1C0] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x890F\n"  /* bt 0x0602B1C4 */
    ".word 0xAEE2\n"  /* bra 0x0602AF6C */
    ".word 0x0009\n"  /* nop */
    ".word 0x000B\n"  /* rts */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB310\n"  /* bsr 0x0602B7D2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F54\n"  /* .word 0x3F54 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0602BBB6 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".global _FUN_0602b1d6\n"
    "_FUN_0602b1d6:\n"
    ".word 0x0497\n"  /* mul.l r9,r4 */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x0602B254] = 0x0602B304} */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6105\n"  /* mov.w @r0+,r1 */
    ".word 0x6205\n"  /* mov.w @r0+,r2 */
    ".word 0x6305\n"  /* mov.w @r0+,r3 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x4318\n"  /* shll8 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x1432\n"  /* mov.l r3,@(0x8,r4) */
    ".word 0xE718\n"  /* mov #24,r7 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x5972\n"  /* mov.l @(0x8,r7),r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x230D\n"  /* .word 0x230D */
    ".word 0x339C\n"  /* add r9,r3 */
    ".word 0x33A7\n"  /* cmp/gt r10,r3 */
    ".word 0x8BC2\n"  /* bf 0x0602B19E */
    ".word 0x9919\n"  /* mov.w @(0x32,PC),r9 */
    ".word 0x9019\n"  /* mov.w @(0x32,PC),r0 */
    ".word 0x1904\n"  /* mov.l r0,@(0x10,r9) */
    ".word 0x1930\n"  /* mov.l r3,@(0x0,r9) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1905\n"  /* mov.l r0,@(0x14,r9) */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x6976\n"  /* mov.l @r7+,r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x319C\n"  /* add r9,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6976\n"  /* mov.l @r7+,r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x220D\n"  /* .word 0x220D */
    ".word 0x329C\n"  /* add r9,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x76E8\n"  /* add #-24,r6 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB304\n"  /* bsr 0x0602B862 */
    ".global _FUN_0602b258\n"
    "_FUN_0602b258:\n"
    ".word 0x991A\n"  /* mov.w @(0x34,PC),r9 */
    ".word 0x5797\n"  /* mov.l @(0x1C,r9),r7 */
    ".word 0x371D\n"  /* dmuls.l r1,r7 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x372D\n"  /* dmuls.l r2,r7 */
    ".word 0x2B12\n"  /* mov.l r1,@r11 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1B21\n"  /* mov.l r2,@(0x4,r11) */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x9711\n"  /* mov.w @(0x22,PC),r7 */
    ".word 0x3177\n"  /* cmp/gt r7,r1 */
    ".word 0x8995\n"  /* bt 0x0602B19E */
    ".word 0x970F\n"  /* mov.w @(0x1E,PC),r7 */
    ".word 0x3717\n"  /* cmp/gt r1,r7 */
    ".word 0x8992\n"  /* bt 0x0602B19E */
    ".word 0x970D\n"  /* mov.w @(0x1A,PC),r7 */
    ".word 0x3277\n"  /* cmp/gt r7,r2 */
    ".word 0x898F\n"  /* bt 0x0602B19E */
    ".word 0x9709\n"  /* mov.w @(0x12,PC),r7 */
    ".word 0x3727\n"  /* cmp/gt r2,r7 */
    ".word 0x898C\n"  /* bt 0x0602B19E */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0x1C11\n"  /* mov.l r1,@(0x4,r12) */
    ".word 0x1C22\n"  /* mov.l r2,@(0x8,r12) */
    ".word 0x1C33\n"  /* mov.l r3,@(0xC,r12) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
    ".global _FUN_0602b298\n"
    "_FUN_0602b298:\n"
    ".word 0xC93F\n"  /* and #0x3F,r0 */
    ".word 0xDC09\n"  /* mov.l @(0x24,PC),r12  {[0x0602B2C0] = 0x06094620} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x3C0C\n"  /* add r0,r12 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8B0D\n"  /* bf 0x0602B2C4 */
    ".word 0x3400\n"  /* cmp/eq r0,r4 */
    ".word 0x8B0B\n"  /* bf 0x0602B2C4 */
    ".word 0x51C1\n"  /* mov.l @(0x4,r12),r1 */
    ".word 0x52C2\n"  /* mov.l @(0x8,r12),r2 */
    ".word 0x53C3\n"  /* mov.l @(0xC,r12),r3 */
    ".word 0x2B12\n"  /* mov.l r1,@r11 */
    ".word 0x1B21\n"  /* mov.l r2,@(0x4,r11) */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x472B\n"  /* jmp @r7 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4620\n"  /* shal r6 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB120\n"  /* bsr 0x0602B55A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB12A\n"  /* bsr 0x0602B572 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB140\n"  /* bsr 0x0602B5A2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB156\n"  /* bsr 0x0602B5D2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB15C\n"  /* bsr 0x0602B5E2 */
    ".global _FUN_0602b328\n"
    "_FUN_0602b328:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602B334, \"ax\"\n"

    ".global _FUN_0602B334\n"
    ".type _FUN_0602B334, @function\n"
    "_FUN_0602B334:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0xDA3C\n"  /* mov.l @(0xF0,PC),r10  {[0x0602B42C] = 0x06063F08} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0x6E33\n"  /* mov r3,r14 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6045\n"  /* mov.w @r4+,r0 */
    ".word 0x6145\n"  /* mov.w @r4+,r1 */
    ".word 0x6245\n"  /* mov.w @r4+,r2 */
    ".word 0xD433\n"  /* mov.l @(0xCC,PC),r4  {[0x0602B430] = 0x06094AB0} */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x1411\n"  /* mov.l r1,@(0x4,r4) */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD52D\n"  /* mov.l @(0xB4,PC),r5  {[0x0602B434] = 0x06094A30} */
    ".word 0xD02E\n"  /* mov.l @(0xB8,PC),r0  {[0x0602B438] = 0x06089EDC} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0xDB1C\n"  /* mov.l @(0x70,PC),r11  {[0x0602B43C] = 0x06094A28} */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x2B01\n"  /* mov.w r0,@r11 */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B36\n"  /* bf 0x0602B444 */
    ".word 0xD51A\n"  /* mov.l @(0x68,PC),r5  {[0x0602B440] = 0x06094A60} */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0602B438] = 0x06089EDC} */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x6202\n"  /* mov.l @r0,r2 */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x0602B434] = 0x06094A30} */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x201D\n"  /* .word 0x201D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x890E\n"  /* bt 0x0602B444 */
    ".word 0xA2A4\n"  /* bra 0x0602B972 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4AB0\n"  /* .word 0x4AB0 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A30\n"  /* .word 0x4A30 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A28\n"  /* shll16 r10 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A60\n"  /* .word 0x4A60 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6045\n"  /* mov.w @r4+,r0 */
    ".word 0x6145\n"  /* mov.w @r4+,r1 */
    ".word 0x6245\n"  /* mov.w @r4+,r2 */
    ".word 0xD462\n"  /* mov.l @(0x188,PC),r4  {[0x0602B5E0] = 0x06094AB0} */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x1411\n"  /* mov.l r1,@(0x4,r4) */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD55C\n"  /* mov.l @(0x170,PC),r5  {[0x0602B5E4] = 0x06094A30} */
    ".word 0x750C\n"  /* add #12,r5 */
    ".word 0xD05C\n"  /* mov.l @(0x170,PC),r0  {[0x0602B5E8] = 0x06089EDC} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B1\n"  /* mov.w r0,@(0x2,r11) */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6045\n"  /* mov.w @r4+,r0 */
    ".word 0x6145\n"  /* mov.w @r4+,r1 */
    ".word 0x6245\n"  /* mov.w @r4+,r2 */
    ".word 0xD442\n"  /* mov.l @(0x108,PC),r4  {[0x0602B5E0] = 0x06094AB0} */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x1411\n"  /* mov.l r1,@(0x4,r4) */
    ".word 0xD540\n"  /* mov.l @(0x100,PC),r5  {[0x0602B5EC] = 0x06094AE0} */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD53B\n"  /* mov.l @(0xEC,PC),r5  {[0x0602B5E4] = 0x06094A30} */
    ".word 0x7518\n"  /* add #24,r5 */
    ".word 0xD03B\n"  /* mov.l @(0xEC,PC),r0  {[0x0602B5E8] = 0x06089EDC} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".global _FUN_0602b546\n"
    "_FUN_0602b546:\n"
    ".word 0x81B2\n"  /* mov.w r0,@(0x4,r11) */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6045\n"  /* mov.w @r4+,r0 */
    ".word 0x6145\n"  /* mov.w @r4+,r1 */
    ".word 0x6245\n"  /* mov.w @r4+,r2 */
    ".global _FUN_0602b55a\n"
    "_FUN_0602b55a:\n"
    ".word 0xD421\n"  /* mov.l @(0x84,PC),r4  {[0x0602B5E0] = 0x06094AB0} */
    ".word 0x4018\n"  /* shll8 r0 */
    ".global _FUN_0602b55e\n"
    "_FUN_0602b55e:\n"
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x1411\n"  /* mov.l r1,@(0x4,r4) */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".global _FUN_0602b572\n"
    "_FUN_0602b572:\n"
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0602B5E4] = 0x06094A30} */
    ".word 0x7524\n"  /* add #36,r5 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x0602B5E8] = 0x06089EDC} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".global _FUN_0602b58e\n"
    "_FUN_0602b58e:\n"
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".global _FUN_0602b5a2\n"
    "_FUN_0602b5a2:\n"
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".global _FUN_0602b5be\n"
    "_FUN_0602b5be:\n"
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B3\n"  /* mov.w r0,@(0x6,r11) */
    ".word 0x62B5\n"  /* mov.w @r11+,r2 */
    ".word 0x63B5\n"  /* mov.w @r11+,r3 */
    ".word 0x61B5\n"  /* mov.w @r11+,r1 */
    ".global _FUN_0602b5ce\n"
    "_FUN_0602b5ce:\n"
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".global _FUN_0602b5d2\n"
    "_FUN_0602b5d2:\n"
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8913\n"  /* bt 0x0602B600 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B09\n"  /* bf 0x0602B5F0 */
    ".word 0xA1C9\n"  /* bra 0x0602B972 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4AB0\n"  /* .word 0x4AB0 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A30\n"  /* .word 0x4A30 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4AE0\n"  /* .word 0x4AE0 */
    ".word 0xD118\n"  /* mov.l @(0x60,PC),r1  {[0x0602B654] = 0x0602B9AC} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0602B658] = 0x06094A30} */
    ".word 0xD518\n"  /* mov.l @(0x60,PC),r5  {[0x0602B65C] = 0x06094A28} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0602B660] = 0x060620D0} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x0107\n"  /* mul.l r0,r1 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x0602B664] = 0x0608AC20} */
    ".word 0xDB17\n"  /* mov.l @(0x5C,PC),r11  {[0x0602B668] = 0x06094A90} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x0602B658] = 0x06094A30} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xDC0C\n"  /* mov.l @(0x30,PC),r12  {[0x0602B66C] = 0x06094A20} */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x9306\n"  /* mov.w @(0xC,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B14\n"  /* bf 0x0602B670 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA025\n"  /* bra 0x0602B696 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB9AC\n"  /* bsr 0x0602A9B2 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A30\n"  /* .word 0x4A30 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A28\n"  /* shll16 r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x0602AEAA */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A90\n"  /* .word 0x4A90 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A20\n"  /* shal r10 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602B67E */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602B696 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602B68C */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602B696 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602B696 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602B6DA */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602B700 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602B6E8 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602B700 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602B6F6 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602B700 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602B700 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7510\n"  /* add #16,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602B744 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602B76A */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602B752 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602B76A */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602B760 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602B76A */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602B76A */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7518\n"  /* add #24,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602B7AE */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602B7D4 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602B7BC */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602B7D4 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602B7CA */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602B7D4 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9315\n"  /* mov.w @(0x2A,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602B7D4 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x0602B7FC] = 0xFFFFFF50} */
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x0602B800] = 0x000000B0} */
    ".word 0xD60A\n"  /* mov.l @(0x28,PC),r6  {[0x0602B804] = 0xFFFFFF81} */
    ".word 0xD70B\n"  /* mov.l @(0x2C,PC),r7  {[0x0602B808] = 0x00000051} */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B14\n"  /* bf 0x0602B80C */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B11\n"  /* bf 0x0602B80C */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B0E\n"  /* bf 0x0602B80C */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B0B\n"  /* bf 0x0602B80C */
    ".word 0xA0BD\n"  /* bra 0x0602B972 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x890A\n"  /* bt 0x0602B828 */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8907\n"  /* bt 0x0602B828 */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8904\n"  /* bt 0x0602B828 */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8901\n"  /* bt 0x0602B828 */
    ".word 0xA0A5\n"  /* bra 0x0602B972 */
    ".word 0x0009\n"  /* nop */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B0A\n"  /* bf 0x0602B844 */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B07\n"  /* bf 0x0602B844 */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B04\n"  /* bf 0x0602B844 */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B01\n"  /* bf 0x0602B844 */
    ".word 0xA097\n"  /* bra 0x0602B972 */
    ".word 0x0009\n"  /* nop */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x890A\n"  /* bt 0x0602B860 */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8907\n"  /* bt 0x0602B860 */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8904\n"  /* bt 0x0602B860 */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8901\n"  /* bt 0x0602B860 */
    ".word 0xA089\n"  /* bra 0x0602B972 */
    ".word 0x0009\n"  /* nop */
    ".word 0x61C1\n"  /* mov.w @r12,r1 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B01\n"  /* bf 0x0602B876 */
    ".word 0xA07E\n"  /* bra 0x0602B972 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8906\n"  /* bt 0x0602B888 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x0602B8D0] = 0x0602B9BC} */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x8194\n"  /* mov.w r0,@(0x8,r9) */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x8195\n"  /* mov.w r0,@(0xA,r9) */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x8196\n"  /* mov.w r0,@(0xC,r9) */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x8197\n"  /* mov.w r0,@(0xE,r9) */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x8198\n"  /* mov.w r0,@(0x10,r9) */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x8199\n"  /* mov.w r0,@(0x12,r9) */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x819A\n"  /* mov.w r0,@(0x14,r9) */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x819B\n"  /* mov.w r0,@(0x16,r9) */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x8193\n"  /* mov.w r0,@(0x6,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x8094\n"  /* mov.b r0,@(0x4,r9) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x0602B8D4] = 0x0602B9CC} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x0602B8D8] = 0x06094A30} */
    ".word 0x5312\n"  /* mov.l @(0x8,r1),r3 */
    ".word 0x5415\n"  /* mov.l @(0x14,r1),r4 */
    ".word 0x5518\n"  /* mov.l @(0x20,r1),r5 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x561B\n"  /* mov.l @(0x2C,r1),r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB9BC\n"  /* bsr 0x0602AC4E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB9CC\n"  /* bsr 0x0602AC72 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4A30\n"  /* .word 0x4A30 */
    ".global _FUN_0602b8dc\n"
    "_FUN_0602b8dc:\n"
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0xA02F\n"  /* bra 0x0602B946 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602B8EE */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602B8F4 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x0602B8FA */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA024\n"  /* bra 0x0602B946 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602B904 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602B90A */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602B910 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA019\n"  /* bra 0x0602B946 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602B92C] = 0x000B8000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602B91C */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602B922 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602B928 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA00D\n"  /* bra 0x0602B946 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0602B97C] = 0x00010000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602B938 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602B93E */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602B944 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD10E\n"  /* mov.l @(0x38,PC),r1  {[0x0602B980] = 0x06094AE0} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602B984] = 0x06063F54} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602B988] = 0x00020000} */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x8B01\n"  /* bf 0x0602B95A */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602B98C] = 0x000A0000} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602B990] = 0x060620D0} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD10D\n"  /* mov.l @(0x34,PC),r1  {[0x0602B994] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x890F\n"  /* bt 0x0602B998 */
    ".word 0xACE8\n"  /* bra 0x0602B34C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4AE0\n"  /* .word 0x4AE0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F54\n"  /* .word 0x3F54 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0602C38A */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x76CC\n"  /* add #-52,r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x79B0\n"  /* add #-80,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x9740\n"  /* mov.w @(0x80,PC),r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x7E08\n"  /* add #8,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x2820\n"  /* mov.b r2,@r8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x2AE0\n"  /* mov.b r14,@r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB8DC\n"  /* bsr 0x0602AB8A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB8E8\n"  /* bsr 0x0602ABA6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB8FE\n"  /* bsr 0x0602ABD6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB930\n"  /* bsr 0x0602AC3E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xB914\n"  /* bsr 0x0602AC0A */
    ".global _FUN_0602b9e0\n"
    "_FUN_0602b9e0:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"
    ".global _scene_graph_walker\n"
    ".type _scene_graph_walker, @function\n"









    ".section .text.FUN_0602B9EC, \"ax\"\n"

    ".global _FUN_0602B9EC\n"
    "_scene_graph_walker:\n"
    "_FUN_0602B9EC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0xDC24\n"  /* mov.l @(0x90,PC),r12  {[0x0602BA88] = 0x06094AE4} */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8FFC\n"  /* bf/s 0x0602B9FC */
    ".word 0x7C10\n"  /* add #16,r12 */
    ".word 0xDA21\n"  /* mov.l @(0x84,PC),r10  {[0x0602BA8C] = 0x06063F08} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0xDB1E\n"  /* mov.l @(0x78,PC),r11  {[0x0602BA90] = 0x0602BD6C} */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x0602BA94] = 0x0602BD8C} */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x0602BA98] = 0x0608A52C} */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0xB12B\n"  /* bsr 0x0602BC7A */
    ".word 0xE906\n"  /* mov #6,r9 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x1532\n"  /* mov.l r3,@(0x8,r5) */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x0602BA9C] = 0x0602BDB4} */
    ".word 0x2722\n"  /* mov.l r2,@r7 */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B37\n"  /* bf 0x0602BAA4 */
    ".word 0xD71A\n"  /* mov.l @(0x68,PC),r7  {[0x0602BAA0] = 0x0602BD9C} */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x2792\n"  /* mov.l r9,@r7 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x1791\n"  /* mov.l r9,@(0x4,r7) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x76DC\n"  /* add #-36,r6 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x290D\n"  /* .word 0x290D */
    ".word 0x1792\n"  /* mov.l r9,@(0x8,r7) */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x075F\n"  /* mac.l @r5+,@r7+ */
    ".word 0x75F4\n"  /* add #-12,r5 */
    ".word 0x090A\n"  /* sts mach,r9 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x209D\n"  /* .word 0x209D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8910\n"  /* bt 0x0602BAA4 */
    ".word 0xA0DE\n"  /* bra 0x0602BC42 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4AE4\n"  /* .word 0x4AE4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBD6C\n"  /* bsr 0x0602B56E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBD8C\n"  /* bsr 0x0602B5B2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0602C4F6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBDB4\n"  /* bsr 0x0602B60A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBD9C\n"  /* bsr 0x0602B5DE */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xD720\n"  /* mov.l @(0x80,PC),r7  {[0x0602BB28] = 0x0602BAB6} */
    ".word 0xB148\n"  /* bsr 0x0602BD3C */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xB123\n"  /* bsr 0x0602BCFC */
    ".word 0x0009\n"  /* nop */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xD71C\n"  /* mov.l @(0x70,PC),r7  {[0x0602BB2C] = 0x0602BACC} */
    ".word 0xB13F\n"  /* bsr 0x0602BD3C */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xB0DC\n"  /* bsr 0x0602BC7A */
    ".word 0xE906\n"  /* mov #6,r9 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xB118\n"  /* bsr 0x0602BCFC */
    ".word 0x0009\n"  /* nop */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xD718\n"  /* mov.l @(0x60,PC),r7  {[0x0602BB30] = 0x0602BAE2} */
    ".word 0xB134\n"  /* bsr 0x0602BD3C */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xB0D1\n"  /* bsr 0x0602BC7A */
    ".word 0xE906\n"  /* mov #6,r9 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xB10D\n"  /* bsr 0x0602BCFC */
    ".word 0x0009\n"  /* nop */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xD713\n"  /* mov.l @(0x4C,PC),r7  {[0x0602BB34] = 0x0602BAF8} */
    ".word 0xB129\n"  /* bsr 0x0602BD3C */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xB0C6\n"  /* bsr 0x0602BC7A */
    ".word 0xE906\n"  /* mov #6,r9 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xB102\n"  /* bsr 0x0602BCFC */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0602BB38] = 0x060620D4} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x210E\n"  /* mulu.w r0,r1 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602BB3C] = 0x0608AC20} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0x7BE0\n"  /* add #-32,r11 */
    ".word 0x9C0D\n"  /* mov.w @(0x1A,PC),r12 */
    ".word 0x50B0\n"  /* mov.l @(0x0,r11),r0 */
    ".word 0x52B2\n"  /* mov.l @(0x8,r11),r2 */
    ".word 0x54B4\n"  /* mov.l @(0x10,r11),r4 */
    ".word 0x56B6\n"  /* mov.l @(0x18,r11),r6 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8B14\n"  /* bf 0x0602BB40 */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8B12\n"  /* bf 0x0602BB40 */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8B10\n"  /* bf 0x0602BB40 */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8B0E\n"  /* bf 0x0602BB40 */
    ".word 0xA08E\n"  /* bra 0x0602BC42 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBAB6\n"  /* bsr 0x0602B09A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBACC\n"  /* bsr 0x0602B0CA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBAE2\n"  /* bsr 0x0602B0FA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBAF8\n"  /* bsr 0x0602B12A */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x0602B382 */
    ".word 0x9C3B\n"  /* mov.w @(0x76,PC),r12 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8905\n"  /* bt 0x0602BB52 */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8903\n"  /* bt 0x0602BB52 */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8901\n"  /* bt 0x0602BB52 */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8977\n"  /* bt 0x0602BC42 */
    ".word 0x9C33\n"  /* mov.w @(0x66,PC),r12 */
    ".word 0x51B1\n"  /* mov.l @(0x4,r11),r1 */
    ".word 0x53B3\n"  /* mov.l @(0xC,r11),r3 */
    ".word 0x55B5\n"  /* mov.l @(0x14,r11),r5 */
    ".word 0x57B7\n"  /* mov.l @(0x1C,r11),r7 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8B05\n"  /* bf 0x0602BB6C */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8B03\n"  /* bf 0x0602BB6C */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8B01\n"  /* bf 0x0602BB6C */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x896A\n"  /* bt 0x0602BC42 */
    ".word 0x9C27\n"  /* mov.w @(0x4E,PC),r12 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8905\n"  /* bt 0x0602BB7E */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8903\n"  /* bt 0x0602BB7E */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8901\n"  /* bt 0x0602BB7E */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8B61\n"  /* bf 0x0602BC42 */
    ".word 0x6C93\n"  /* mov r9,r12 */
    ".word 0x7C18\n"  /* add #24,r12 */
    ".word 0x2C75\n"  /* mov.w r7,@-r12 */
    ".word 0x2C65\n"  /* mov.w r6,@-r12 */
    ".word 0x2C55\n"  /* mov.w r5,@-r12 */
    ".word 0x2C45\n"  /* mov.w r4,@-r12 */
    ".word 0x2C35\n"  /* mov.w r3,@-r12 */
    ".word 0x2C25\n"  /* mov.w r2,@-r12 */
    ".word 0x2C15\n"  /* mov.w r1,@-r12 */
    ".word 0x2C05\n"  /* mov.w r0,@-r12 */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x8193\n"  /* mov.w r0,@(0x6,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x8094\n"  /* mov.b r0,@(0x4,r9) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x0602BBC0] = 0x0602BDB8} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x021E\n"  /* mov.l @(r0,r1),r2 */
    ".word 0xC777\n"  /* mova @(0x1DC,PC),r0  {0x0602BD8C} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0x5401\n"  /* mov.l @(0x4,r0),r4 */
    ".word 0x5502\n"  /* mov.l @(0x8,r0),r5 */
    ".word 0x422B\n"  /* jmp @r2 */
    ".word 0x5603\n"  /* mov.l @(0xC,r0),r6 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBDB8\n"  /* bsr 0x0602B736 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0xA024\n"  /* bra 0x0602BC16 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602BBD4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602BBDA */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x0602BBE0 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA019\n"  /* bra 0x0602BC16 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602BBEA */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602BBF0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602BBF6 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA00E\n"  /* bra 0x0602BC16 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA001\n"  /* bra 0x0602BC02 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0602BC4C] = 0x000B8000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602BC08 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602BC0E */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602BC14 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD10E\n"  /* mov.l @(0x38,PC),r1  {[0x0602BC50] = 0x0602BDB4} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602BC54] = 0x06063F54} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602BC58] = 0x00020000} */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x8B01\n"  /* bf 0x0602BC2A */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602BC5C] = 0x000A0000} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602BC60] = 0x060620D4} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD10D\n"  /* mov.l @(0x34,PC),r1  {[0x0602BC64] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x890F\n"  /* bt 0x0602BC68 */
    ".word 0xAEE2\n"  /* bra 0x0602BA10 */
    ".word 0x0009\n"  /* nop */
    ".word 0x000B\n"  /* rts */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBDB4\n"  /* bsr 0x0602B7BE */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F54\n"  /* .word 0x3F54 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0602C65A */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0497\n"  /* mul.l r9,r4 */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x0602BCF8] = 0x0602BDA8} */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6105\n"  /* mov.w @r0+,r1 */
    ".word 0x6205\n"  /* mov.w @r0+,r2 */
    ".word 0x6305\n"  /* mov.w @r0+,r3 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x4318\n"  /* shll8 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x1432\n"  /* mov.l r3,@(0x8,r4) */
    ".word 0xE718\n"  /* mov #24,r7 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x074F\n"  /* mac.l @r4+,@r7+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x5972\n"  /* mov.l @(0x8,r7),r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x230D\n"  /* .word 0x230D */
    ".word 0x339C\n"  /* add r9,r3 */
    ".word 0x33A7\n"  /* cmp/gt r10,r3 */
    ".word 0x8BC2\n"  /* bf 0x0602BC42 */
    ".word 0x9919\n"  /* mov.w @(0x32,PC),r9 */
    ".word 0x9019\n"  /* mov.w @(0x32,PC),r0 */
    ".word 0x1904\n"  /* mov.l r0,@(0x10,r9) */
    ".word 0x1930\n"  /* mov.l r3,@(0x0,r9) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1905\n"  /* mov.l r0,@(0x14,r9) */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x6976\n"  /* mov.l @r7+,r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x319C\n"  /* add r9,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6976\n"  /* mov.l @r7+,r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x220D\n"  /* .word 0x220D */
    ".word 0x329C\n"  /* add r9,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x76E8\n"  /* add #-24,r6 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBDA8\n"  /* bsr 0x0602B84E */
    ".word 0x991A\n"  /* mov.w @(0x34,PC),r9 */
    ".word 0x5797\n"  /* mov.l @(0x1C,r9),r7 */
    ".word 0x371D\n"  /* dmuls.l r1,r7 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x372D\n"  /* dmuls.l r2,r7 */
    ".word 0x2B12\n"  /* mov.l r1,@r11 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1B21\n"  /* mov.l r2,@(0x4,r11) */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x9711\n"  /* mov.w @(0x22,PC),r7 */
    ".word 0x3177\n"  /* cmp/gt r7,r1 */
    ".word 0x8995\n"  /* bt 0x0602BC42 */
    ".word 0x970F\n"  /* mov.w @(0x1E,PC),r7 */
    ".word 0x3717\n"  /* cmp/gt r1,r7 */
    ".word 0x8992\n"  /* bt 0x0602BC42 */
    ".word 0x970D\n"  /* mov.w @(0x1A,PC),r7 */
    ".word 0x3277\n"  /* cmp/gt r7,r2 */
    ".word 0x898F\n"  /* bt 0x0602BC42 */
    ".word 0x9709\n"  /* mov.w @(0x12,PC),r7 */
    ".word 0x3727\n"  /* cmp/gt r2,r7 */
    ".word 0x898C\n"  /* bt 0x0602BC42 */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0x1C11\n"  /* mov.l r1,@(0x4,r12) */
    ".word 0x1C22\n"  /* mov.l r2,@(0x8,r12) */
    ".word 0x1C33\n"  /* mov.l r3,@(0xC,r12) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
    ".word 0xC93F\n"  /* and #0x3F,r0 */
    ".word 0xDC09\n"  /* mov.l @(0x24,PC),r12  {[0x0602BD64] = 0x06094AE4} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x3C0C\n"  /* add r0,r12 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8B0D\n"  /* bf 0x0602BD68 */
    ".word 0x3400\n"  /* cmp/eq r0,r4 */
    ".word 0x8B0B\n"  /* bf 0x0602BD68 */
    ".word 0x51C1\n"  /* mov.l @(0x4,r12),r1 */
    ".word 0x52C2\n"  /* mov.l @(0x8,r12),r2 */
    ".word 0x53C3\n"  /* mov.l @(0xC,r12),r3 */
    ".word 0x2B12\n"  /* mov.l r1,@r11 */
    ".word 0x1B21\n"  /* mov.l r2,@(0x4,r11) */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x472B\n"  /* jmp @r7 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4AE4\n"  /* .word 0x4AE4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBBC4\n"  /* bsr 0x0602B546 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBBCE\n"  /* bsr 0x0602B55E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBBE4\n"  /* bsr 0x0602B58E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBBFA\n"  /* bsr 0x0602B5BE */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xBC00\n"  /* bsr 0x0602B5CE */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".size _scene_graph_walker, .-_scene_graph_walker\n"
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602BDD8, \"ax\"\n"

    ".global _FUN_0602BDD8\n"
    ".type _FUN_0602BDD8, @function\n"
    "_FUN_0602BDD8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0xDA3C\n"  /* mov.l @(0xF0,PC),r10  {[0x0602BED0] = 0x06063F08} */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0x6E33\n"  /* mov r3,r14 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6045\n"  /* mov.w @r4+,r0 */
    ".word 0x6145\n"  /* mov.w @r4+,r1 */
    ".word 0x6245\n"  /* mov.w @r4+,r2 */
    ".word 0xD433\n"  /* mov.l @(0xCC,PC),r4  {[0x0602BED4] = 0x06094F74} */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x1411\n"  /* mov.l r1,@(0x4,r4) */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD52D\n"  /* mov.l @(0xB4,PC),r5  {[0x0602BED8] = 0x06094EF4} */
    ".word 0xD02E\n"  /* mov.l @(0xB8,PC),r0  {[0x0602BEDC] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0xDB1C\n"  /* mov.l @(0x70,PC),r11  {[0x0602BEE0] = 0x06094EEC} */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x2B01\n"  /* mov.w r0,@r11 */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B36\n"  /* bf 0x0602BEE8 */
    ".word 0xD51A\n"  /* mov.l @(0x68,PC),r5  {[0x0602BEE4] = 0x06094F24} */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0602BEDC] = 0x0608A52C} */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x6202\n"  /* mov.l @r0,r2 */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x024F\n"  /* mac.l @r4+,@r2+ */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x0602BED8] = 0x06094EF4} */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x201D\n"  /* .word 0x201D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x890E\n"  /* bt 0x0602BEE8 */
    ".word 0xA2A4\n"  /* bra 0x0602C416 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4F74\n"  /* .word 0x4F74 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4EF4\n"  /* .word 0x4EF4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0602C93A */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4EEC\n"  /* .word 0x4EEC */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4F24\n"  /* .word 0x4F24 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6045\n"  /* mov.w @r4+,r0 */
    ".word 0x6145\n"  /* mov.w @r4+,r1 */
    ".word 0x6245\n"  /* mov.w @r4+,r2 */
    ".word 0xD462\n"  /* mov.l @(0x188,PC),r4  {[0x0602C084] = 0x06094F74} */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x1411\n"  /* mov.l r1,@(0x4,r4) */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD55C\n"  /* mov.l @(0x170,PC),r5  {[0x0602C088] = 0x06094EF4} */
    ".word 0x750C\n"  /* add #12,r5 */
    ".word 0xD05C\n"  /* mov.l @(0x170,PC),r0  {[0x0602C08C] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B1\n"  /* mov.w r0,@(0x2,r11) */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6045\n"  /* mov.w @r4+,r0 */
    ".word 0x6145\n"  /* mov.w @r4+,r1 */
    ".word 0x6245\n"  /* mov.w @r4+,r2 */
    ".word 0xD442\n"  /* mov.l @(0x108,PC),r4  {[0x0602C084] = 0x06094F74} */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x1411\n"  /* mov.l r1,@(0x4,r4) */
    ".word 0xD540\n"  /* mov.l @(0x100,PC),r5  {[0x0602C090] = 0x06094FA4} */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD53B\n"  /* mov.l @(0xEC,PC),r5  {[0x0602C088] = 0x06094EF4} */
    ".word 0x7518\n"  /* add #24,r5 */
    ".word 0xD03B\n"  /* mov.l @(0xEC,PC),r0  {[0x0602C08C] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B2\n"  /* mov.w r0,@(0x4,r11) */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x640D\n"  /* extu.w r0,r4 */
    ".word 0x0417\n"  /* mul.l r1,r4 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6045\n"  /* mov.w @r4+,r0 */
    ".word 0x6145\n"  /* mov.w @r4+,r1 */
    ".word 0x6245\n"  /* mov.w @r4+,r2 */
    ".word 0xD421\n"  /* mov.l @(0x84,PC),r4  {[0x0602C084] = 0x06094F74} */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x1411\n"  /* mov.l r1,@(0x4,r4) */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0602C088] = 0x06094EF4} */
    ".word 0x7524\n"  /* add #36,r5 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x0602C08C] = 0x0608A52C} */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6276\n"  /* mov.l @r7+,r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x3A03\n"  /* cmp/ge r0,r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x81B3\n"  /* mov.w r0,@(0x6,r11) */
    ".word 0x62B5\n"  /* mov.w @r11+,r2 */
    ".word 0x63B5\n"  /* mov.w @r11+,r3 */
    ".word 0x61B5\n"  /* mov.w @r11+,r1 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8913\n"  /* bt 0x0602C0A4 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B09\n"  /* bf 0x0602C094 */
    ".word 0xA1C9\n"  /* bra 0x0602C416 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4F74\n"  /* .word 0x4F74 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4EF4\n"  /* .word 0x4EF4 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0602CAEA */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA4\n"  /* .word 0x4FA4 */
    ".word 0xD118\n"  /* mov.l @(0x60,PC),r1  {[0x0602C0F8] = 0x0602C450} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0602C0FC] = 0x06094EF4} */
    ".word 0xD518\n"  /* mov.l @(0x60,PC),r5  {[0x0602C100] = 0x06094EEC} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0602C104] = 0x060620D4} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x0107\n"  /* mul.l r0,r1 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x0602C108] = 0x0608AC20} */
    ".word 0xDB17\n"  /* mov.l @(0x5C,PC),r11  {[0x0602C10C] = 0x06094F54} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x0602C0FC] = 0x06094EF4} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xDC0C\n"  /* mov.l @(0x30,PC),r12  {[0x0602C110] = 0x06094EE4} */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x9306\n"  /* mov.w @(0xC,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B14\n"  /* bf 0x0602C114 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA025\n"  /* bra 0x0602C13A */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xC450\n"  /* mov.b @(0x50,GBR),r0 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4EF4\n"  /* .word 0x4EF4 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4EEC\n"  /* .word 0x4EEC */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x0602B94E */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4F54\n"  /* .word 0x4F54 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4EE4\n"  /* .word 0x4EE4 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602C122 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602C13A */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602C130 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602C13A */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602C13A */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602C17E */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602C1A4 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602C18C */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602C1A4 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602C19A */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602C1A4 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602C1A4 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C1\n"  /* mov.w r0,@(0x2,r12) */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7510\n"  /* add #16,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602C1E8 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602C20E */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602C1F6 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602C20E */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602C204 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602C20E */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602C20E */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C2\n"  /* mov.w r0,@(0x4,r12) */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7518\n"  /* add #24,r5 */
    ".word 0x911A\n"  /* mov.w @(0x34,PC),r1 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x5242\n"  /* mov.l @(0x8,r4),r2 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x1120\n"  /* mov.l r2,@(0x0,r1) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x5017\n"  /* mov.l @(0x1C,r1),r0 */
    ".word 0x302D\n"  /* dmuls.l r2,r0 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x303D\n"  /* dmuls.l r3,r0 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x5251\n"  /* mov.l @(0x4,r5),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B06\n"  /* bf 0x0602C252 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA017\n"  /* bra 0x0602C278 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3317\n"  /* cmp/gt r1,r3 */
    ".word 0x8B03\n"  /* bf 0x0602C260 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA00D\n"  /* bra 0x0602C278 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B03\n"  /* bf 0x0602C26E */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA006\n"  /* bra 0x0602C278 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x9315\n"  /* mov.w @(0x2A,PC),r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B01\n"  /* bf 0x0602C278 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x81C3\n"  /* mov.w r0,@(0x6,r12) */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x0602C2A0] = 0xFFFFFF50} */
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x0602C2A4] = 0x000000B0} */
    ".word 0xD60A\n"  /* mov.l @(0x28,PC),r6  {[0x0602C2A8] = 0xFFFFFF81} */
    ".word 0xD70B\n"  /* mov.l @(0x2C,PC),r7  {[0x0602C2AC] = 0x00000051} */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B14\n"  /* bf 0x0602C2B0 */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B11\n"  /* bf 0x0602C2B0 */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B0E\n"  /* bf 0x0602C2B0 */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8B0B\n"  /* bf 0x0602C2B0 */
    ".word 0xA0BD\n"  /* bra 0x0602C416 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x890A\n"  /* bt 0x0602C2CC */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8907\n"  /* bt 0x0602C2CC */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8904\n"  /* bt 0x0602C2CC */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8901\n"  /* bt 0x0602C2CC */
    ".word 0xA0A5\n"  /* bra 0x0602C416 */
    ".word 0x0009\n"  /* nop */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B0A\n"  /* bf 0x0602C2E8 */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B07\n"  /* bf 0x0602C2E8 */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B04\n"  /* bf 0x0602C2E8 */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x3607\n"  /* cmp/gt r0,r6 */
    ".word 0x8B01\n"  /* bf 0x0602C2E8 */
    ".word 0xA097\n"  /* bra 0x0602C416 */
    ".word 0x0009\n"  /* nop */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x890A\n"  /* bt 0x0602C304 */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8907\n"  /* bt 0x0602C304 */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8904\n"  /* bt 0x0602C304 */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8901\n"  /* bt 0x0602C304 */
    ".word 0xA089\n"  /* bra 0x0602C416 */
    ".word 0x0009\n"  /* nop */
    ".word 0x61C1\n"  /* mov.w @r12,r1 */
    ".word 0x85C1\n"  /* mov.w @(0x2,r12),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x85C2\n"  /* mov.w @(0x4,r12),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x85C3\n"  /* mov.w @(0x6,r12),r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B01\n"  /* bf 0x0602C31A */
    ".word 0xA07E\n"  /* bra 0x0602C416 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8906\n"  /* bt 0x0602C32C */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x0602C374] = 0x0602C460} */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x60B2\n"  /* mov.l @r11,r0 */
    ".word 0x8194\n"  /* mov.w r0,@(0x8,r9) */
    ".word 0x50B1\n"  /* mov.l @(0x4,r11),r0 */
    ".word 0x8195\n"  /* mov.w r0,@(0xA,r9) */
    ".word 0x50B2\n"  /* mov.l @(0x8,r11),r0 */
    ".word 0x8196\n"  /* mov.w r0,@(0xC,r9) */
    ".word 0x50B3\n"  /* mov.l @(0xC,r11),r0 */
    ".word 0x8197\n"  /* mov.w r0,@(0xE,r9) */
    ".word 0x50B4\n"  /* mov.l @(0x10,r11),r0 */
    ".word 0x8198\n"  /* mov.w r0,@(0x10,r9) */
    ".word 0x50B5\n"  /* mov.l @(0x14,r11),r0 */
    ".word 0x8199\n"  /* mov.w r0,@(0x12,r9) */
    ".word 0x50B6\n"  /* mov.l @(0x18,r11),r0 */
    ".word 0x819A\n"  /* mov.w r0,@(0x14,r9) */
    ".word 0x50B7\n"  /* mov.l @(0x1C,r11),r0 */
    ".word 0x819B\n"  /* mov.w r0,@(0x16,r9) */
    ".word 0x8587\n"  /* mov.w @(0xE,r8),r0 */
    ".word 0x8193\n"  /* mov.w r0,@(0x6,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x8094\n"  /* mov.b r0,@(0x4,r9) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x0602C378] = 0x0602C470} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x0602C37C] = 0x06094EF4} */
    ".word 0x5312\n"  /* mov.l @(0x8,r1),r3 */
    ".word 0x5415\n"  /* mov.l @(0x14,r1),r4 */
    ".word 0x5518\n"  /* mov.l @(0x20,r1),r5 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x561B\n"  /* mov.l @(0x2C,r1),r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xC460\n"  /* mov.b @(0x60,GBR),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xC470\n"  /* mov.b @(0x70,GBR),r0 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4EF4\n"  /* .word 0x4EF4 */
    ".global _FUN_0602c380\n"
    "_FUN_0602c380:\n"
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0xA02F\n"  /* bra 0x0602C3EA */
    ".word 0x0009\n"  /* nop */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602C392 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602C398 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x0602C39E */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA024\n"  /* bra 0x0602C3EA */
    ".word 0x0009\n"  /* nop */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602C3A8 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602C3AE */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602C3B4 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA019\n"  /* bra 0x0602C3EA */
    ".word 0x0009\n"  /* nop */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602C3D0] = 0x000B8000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602C3C0 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602C3C6 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602C3CC */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA00D\n"  /* bra 0x0602C3EA */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0602C420] = 0x00010000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0602C3DC */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0602C3E2 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x0602C3E8 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD10E\n"  /* mov.l @(0x38,PC),r1  {[0x0602C424] = 0x06094FA4} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602C428] = 0x06063F54} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602C42C] = 0x00020000} */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x8B01\n"  /* bf 0x0602C3FE */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602C430] = 0x000A0000} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602C434] = 0x060620D4} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD10D\n"  /* mov.l @(0x34,PC),r1  {[0x0602C438] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x890F\n"  /* bt 0x0602C43C */
    ".word 0xACE8\n"  /* bra 0x0602BDF0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA4\n"  /* .word 0x4FA4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F54\n"  /* .word 0x3F54 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0602CE2E */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x76CC\n"  /* add #-52,r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x79B0\n"  /* add #-80,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x9740\n"  /* mov.w @(0x80,PC),r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x7E08\n"  /* add #8,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x2820\n"  /* mov.b r2,@r8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x2AE0\n"  /* mov.b r14,@r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xC380\n"  /* trapa #0x80 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xC38C\n"  /* trapa #0x8C */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xC3A2\n"  /* trapa #0xA2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xC3D4\n"  /* trapa #0xD4 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xC3B8\n"  /* trapa #0xB8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x2468\n"  /* tst r6,r4 */
    ".word 0x0640\n"  /* .word 0x0640 */
    ".word 0x0009\n"  /* nop */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x2428\n"  /* tst r2,r4 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x6953\n"  /* mov r5,r9 */
    ".word 0xD177\n"  /* mov.l @(0x1DC,PC),r1  {[0x0602C680] = 0x060A2468} */
    ".word 0xDB77\n"  /* mov.l @(0x1DC,PC),r11  {[0x0602C684] = 0x06094FA8} */
    ".word 0x21B2\n"  /* mov.l r11,@r1 */
    ".word 0xD377\n"  /* mov.l @(0x1DC,PC),r3  {[0x0602C688] = 0x060A17A8} */
    ".word 0x6193\n"  /* mov r9,r1 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x6B15\n"  /* mov.w @r1+,r11 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x3282\n"  /* cmp/hs r8,r2 */
    ".word 0x23B1\n"  /* mov.w r11,@r3 */
    ".word 0x8FFA\n"  /* bf/s 0x0602C4AE */
    ".word 0x7302\n"  /* add #2,r3 */
    ".word 0xD16D\n"  /* mov.l @(0x1B4,PC),r1  {[0x0602C670] = 0x060A2468} */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0xD66A\n"  /* mov.l @(0x1A8,PC),r6  {[0x0602C688] = 0x060A17A8} */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xDA6A\n"  /* mov.l @(0x1A8,PC),r10  {[0x0602C68C] = 0x060A2428} */
    ".word 0x94CA\n"  /* mov.w @(0x194,PC),r4 */
    ".word 0xD567\n"  /* mov.l @(0x19C,PC),r5  {[0x0602C684] = 0x06094FA8} */
    ".word 0x6065\n"  /* mov.w @r6+,r0 */
    ".word 0x62A3\n"  /* mov r10,r2 */
    ".word 0xC91F\n"  /* and #0x1F,r0 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x6121\n"  /* mov.w @r2,r1 */
    ".word 0x0047\n"  /* mul.l r4,r0 */
    ".word 0x601D\n"  /* extu.w r1,r0 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x2211\n"  /* mov.w r1,@r2 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x0575\n"  /* mov.w r7,@(r0,r5) */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0x3782\n"  /* cmp/hs r8,r7 */
    ".word 0x8BEE\n"  /* bf 0x0602C4E8 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0xD359\n"  /* mov.l @(0x164,PC),r3  {[0x0602C674] = 0x060A2428} */
    ".word 0xD659\n"  /* mov.l @(0x164,PC),r6  {[0x0602C678] = 0x06094FA8} */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x90AA\n"  /* mov.w @(0x154,PC),r0 */
    ".word 0xE51F\n"  /* mov #31,r5 */
    ".word 0x6135\n"  /* mov.w @r3+,r1 */
    ".word 0x6263\n"  /* mov r6,r2 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8F06\n"  /* bf/s 0x0602C530 */
    ".word 0x360C\n"  /* add r0,r6 */
    ".word 0x6825\n"  /* mov.w @r2+,r8 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x2481\n"  /* mov.w r8,@r4 */
    ".word 0x8DFA\n"  /* bt/s 0x0602C524 */
    ".word 0x7402\n"  /* add #2,r4 */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0x3757\n"  /* cmp/gt r5,r7 */
    ".word 0x8BF0\n"  /* bf 0x0602C518 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0xD14D\n"  /* mov.l @(0x134,PC),r1  {[0x0602C670] = 0x060A2468} */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6793\n"  /* mov r9,r7 */
    ".word 0x6171\n"  /* mov.w @r7,r1 */
    ".word 0x601D\n"  /* extu.w r1,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xD148\n"  /* mov.l @(0x120,PC),r1  {[0x0602C688] = 0x060A17A8} */
    ".word 0x011D\n"  /* mov.w @(r0,r1),r1 */
    ".word 0x601D\n"  /* extu.w r1,r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4001\n"  /* shlr r0 */
    ".word 0xC91F\n"  /* and #0x1F,r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0xD144\n"  /* mov.l @(0x110,PC),r1  {[0x0602C68C] = 0x060A2428} */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x6133\n"  /* mov r3,r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x2211\n"  /* mov.w r1,@r2 */
    ".word 0x917A\n"  /* mov.w @(0xF4,PC),r1 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x431A\n"  /* .word 0x431A */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0xD13B\n"  /* mov.l @(0xEC,PC),r1  {[0x0602C684] = 0x06094FA8} */
    ".word 0x6B75\n"  /* mov.w @r7+,r11 */
    ".word 0x3682\n"  /* cmp/hs r8,r6 */
    ".word 0x8FE0\n"  /* bf/s 0x0602C560 */
    ".word 0x01B5\n"  /* mov.w r11,@(r0,r1) */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0xD333\n"  /* mov.l @(0xCC,PC),r3  {[0x0602C674] = 0x060A2428} */
    ".word 0xD634\n"  /* mov.l @(0xD0,PC),r6  {[0x0602C678] = 0x06094FA8} */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x905F\n"  /* mov.w @(0xBE,PC),r0 */
    ".word 0xE51F\n"  /* mov #31,r5 */
    ".word 0x6135\n"  /* mov.w @r3+,r1 */
    ".word 0x6263\n"  /* mov r6,r2 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8F06\n"  /* bf/s 0x0602C5C6 */
    ".word 0x360C\n"  /* add r0,r6 */
    ".word 0x6825\n"  /* mov.w @r2+,r8 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x2481\n"  /* mov.w r8,@r4 */
    ".word 0x8DFA\n"  /* bt/s 0x0602C5BA */
    ".word 0x7402\n"  /* add #2,r4 */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0x3757\n"  /* cmp/gt r5,r7 */
    ".word 0x8BF0\n"  /* bf 0x0602C5AE */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0xD128\n"  /* mov.l @(0xA0,PC),r1  {[0x0602C670] = 0x060A2468} */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6793\n"  /* mov r9,r7 */
    ".word 0x6171\n"  /* mov.w @r7,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0xD122\n"  /* mov.l @(0x88,PC),r1  {[0x0602C688] = 0x060A17A8} */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC91F\n"  /* and #0x1F,r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0xD120\n"  /* mov.l @(0x80,PC),r1  {[0x0602C68C] = 0x060A2428} */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x6133\n"  /* mov r3,r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x2211\n"  /* mov.w r1,@r2 */
    ".word 0x9131\n"  /* mov.w @(0x62,PC),r1 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x431A\n"  /* .word 0x431A */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0xD116\n"  /* mov.l @(0x58,PC),r1  {[0x0602C684] = 0x06094FA8} */
    ".word 0x6B75\n"  /* mov.w @r7+,r11 */
    ".word 0x3682\n"  /* cmp/hs r8,r6 */
    ".word 0x8FE2\n"  /* bf/s 0x0602C5F6 */
    ".word 0x01B5\n"  /* mov.w r11,@(r0,r1) */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0602C674] = 0x060A2428} */
    ".word 0xD60F\n"  /* mov.l @(0x3C,PC),r6  {[0x0602C678] = 0x06094FA8} */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x9016\n"  /* mov.w @(0x2C,PC),r0 */
    ".word 0xE51F\n"  /* mov #31,r5 */
    ".word 0x6135\n"  /* mov.w @r3+,r1 */
    ".word 0x6263\n"  /* mov r6,r2 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8F06\n"  /* bf/s 0x0602C658 */
    ".word 0x360C\n"  /* add r0,r6 */
    ".word 0x6825\n"  /* mov.w @r2+,r8 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x2481\n"  /* mov.w r8,@r4 */
    ".word 0x8DFA\n"  /* bt/s 0x0602C64C */
    ".word 0x7402\n"  /* add #2,r4 */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0x3757\n"  /* cmp/gt r5,r7 */
    ".word 0x8BF0\n"  /* bf 0x0602C640 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0640\n"  /* .word 0x0640 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x2468\n"  /* tst r6,r4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x2428\n"  /* tst r2,r4 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x0640\n"  /* .word 0x0640 */
    ".word 0x0009\n"  /* nop */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x2468\n"  /* tst r6,r4 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x17A8\n"  /* mov.l r10,@(0x20,r7) */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x2428\n"  /* tst r2,r4 */
);
__asm__(



    ".balign 2\n"
    ".global _vdp1_texture_setup\n"
    ".type _vdp1_texture_setup, @function\n"









    ".section .text.FUN_0602C884, \"ax\"\n"

    ".global _FUN_0602C884\n"
    "_vdp1_texture_setup:\n"
    "_FUN_0602C884:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6093\n"  /* mov r9,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x6412\n"  /* mov.l @r1,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x00B4\n"  /* mov.b r11,@(r0,r0) */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x00D2\n"  /* .word 0x00D2 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x00F6\n"  /* mov.l r15,@(r0,r0) */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x00FA\n"  /* .word 0x00FA */
    ".word 0x0096\n"  /* mov.l r9,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x5AEC\n"  /* mov.l @(0x30,r14),r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECCC\n"  /* mov #-52,r12 */
    ".word 0x4808\n"  /* shll2 r8 */
    ".word 0x328C\n"  /* add r8,r2 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6422\n"  /* mov.l @r2,r4 */
    ".word 0x4801\n"  /* shlr r8 */
    ".word 0x4808\n"  /* shll2 r8 */
    ".word 0x328C\n"  /* add r8,r2 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6422\n"  /* mov.l @r2,r4 */
    ".word 0x4809\n"  /* shlr2 r8 */
    ".word 0x4808\n"  /* shll2 r8 */
    ".word 0x328C\n"  /* add r8,r2 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6422\n"  /* mov.l @r2,r4 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x000B\n"  /* rts */
    ".word 0x4428\n"  /* shll16 r4 */
    ".size _vdp1_texture_setup, .-_vdp1_texture_setup\n"
);
__asm__(



    ".balign 2\n"
    ".global _vdp1_attribute_setup\n"
    ".type _vdp1_attribute_setup, @function\n"









    ".section .text.FUN_0602CCEC, \"ax\"\n"

    ".global _FUN_0602CCEC\n"
    "_vdp1_attribute_setup:\n"
    "_FUN_0602CCEC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x53E2\n"  /* mov.l @(0x8,r14),r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B51\n"  /* bf 0x0602CD9A */
    ".word 0x955E\n"  /* mov.w @(0xBC,PC),r5 */
    ".word 0x915E\n"  /* mov.w @(0xBC,PC),r1 */
    ".word 0x4528\n"  /* shll16 r5 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0x4328\n"  /* shll16 r3 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x9259\n"  /* mov.w @(0xB2,PC),r2 */
    ".word 0xDD31\n"  /* mov.l @(0xC4,PC),r13  {[0x0602CDCC] = 0x0602755C} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x062E\n"  /* mov.l @(r0,r2),r6 */
    ".word 0x360D\n"  /* dmuls.l r0,r6 */
    ".word 0x9155\n"  /* mov.w @(0xAA,PC),r1 */
    ".word 0x9255\n"  /* mov.w @(0xAA,PC),r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x240D\n"  /* .word 0x240D */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x32EC\n"  /* add r14,r2 */
    ".word 0x6512\n"  /* mov.l @r1,r5 */
    ".word 0x6622\n"  /* mov.l @r2,r6 */
    ".word 0x356D\n"  /* dmuls.l r6,r5 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x256D\n"  /* .word 0x256D */
    ".word 0x914A\n"  /* mov.w @(0x94,PC),r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x6711\n"  /* mov.w @r1,r7 */
    ".word 0x9447\n"  /* mov.w @(0x8E,PC),r4 */
    ".word 0xD127\n"  /* mov.l @(0x9C,PC),r1  {[0x0602CDD0] = 0x0602E938} */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6441\n"  /* mov.w @r4,r4 */
    ".word 0xE50A\n"  /* mov #10,r5 */
    ".word 0x3453\n"  /* cmp/ge r5,r4 */
    ".word 0x8905\n"  /* bt 0x0602CD4A */
    ".word 0xE502\n"  /* mov #2,r5 */
    ".word 0x3450\n"  /* cmp/eq r5,r4 */
    ".word 0x8902\n"  /* bt 0x0602CD4A */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x3450\n"  /* cmp/eq r5,r4 */
    ".word 0x8B02\n"  /* bf 0x0602CD50 */
    ".word 0xE502\n"  /* mov #2,r5 */
    ".word 0x3573\n"  /* cmp/ge r7,r5 */
    ".word 0x8924\n"  /* bt 0x0602CD9A */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x371C\n"  /* add r1,r7 */
    ".word 0x374C\n"  /* add r4,r7 */
    ".word 0x6471\n"  /* mov.w @r7,r4 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x912C\n"  /* mov.w @(0x58,PC),r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3457\n"  /* cmp/gt r5,r4 */
    ".word 0x8911\n"  /* bt 0x0602CD9A */
    ".word 0xB535\n"  /* bsr 0x0602D7E4 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x9124\n"  /* mov.w @(0x48,PC),r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6211\n"  /* mov.w @r1,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x890A\n"  /* bt 0x0602CD9A */
    ".word 0x9118\n"  /* mov.w @(0x30,PC),r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6712\n"  /* mov.l @r1,r7 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x0602CDD4] = 0x23280000} */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4428\n"  /* shll16 r4 */
    ".word 0x9619\n"  /* mov.w @(0x32,PC),r6 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x36EC\n"  /* add r14,r6 */
    ".word 0x2602\n"  /* mov.l r0,@r6 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x910E\n"  /* mov.w @(0x1C,PC),r1 */
    ".word 0x9213\n"  /* mov.w @(0x26,PC),r2 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0x3348\n"  /* sub r4,r3 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x960F\n"  /* mov.w @(0x1E,PC),r6 */
    ".word 0x4528\n"  /* shll16 r5 */
    ".word 0x3367\n"  /* cmp/gt r6,r3 */
    ".word 0x8913\n"  /* bt 0x0602CDD8 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA014\n"  /* bra 0x0602CDDE */
    ".word 0x0009\n"  /* nop */
    ".word 0x2134\n"  /* mov.b r3,@-r1 */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x011C\n"  /* mov.b @(r0,r1),r1 */
    ".word 0x010C\n"  /* mov.b @(r0,r0),r1 */
    ".word 0x0144\n"  /* mov.b r4,@(r0,r1) */
    ".word 0x00DC\n"  /* mov.b @(r0,r13),r0 */
    ".word 0x007C\n"  /* mov.b @(r0,r7),r0 */
    ".word 0x0264\n"  /* mov.b r6,@(r0,r2) */
    ".word 0x016C\n"  /* mov.b @(r0,r6),r1 */
    ".word 0x0110\n"  /* .word 0x0110 */
    ".word 0x2B85\n"  /* mov.w r8,@-r11 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE938\n"  /* mov #56,r9 */
    ".word 0x2328\n"  /* tst r2,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0602CDDE */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8B02\n"  /* bf 0x0602CDE8 */
    ".word 0x9506\n"  /* mov.w @(0xC,PC),r5 */
    ".word 0x3458\n"  /* sub r5,r4 */
    ".word 0x0246\n"  /* mov.l r4,@(r0,r2) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x9203\n"  /* mov.w @(0x6,PC),r2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0276\n"  /* mov.l r7,@(r0,r2) */
    ".word 0x05C2\n"  /* .word 0x05C2 */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".size _vdp1_attribute_setup, .-_vdp1_attribute_setup\n"
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602D89A, \"ax\"\n"

    ".global _FUN_0602D89A\n"
    ".type _FUN_0602D89A, @function\n"
    "_FUN_0602D89A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602D8B8] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xB00B\n"  /* bsr 0x0602D8BC */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".global _FUN_0602d8bc\n"
    "_FUN_0602d8bc:\n"
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x912A\n"  /* mov.w @(0x54,PC),r1 */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0x3240\n"  /* cmp/eq r4,r2 */
    ".word 0x8B2E\n"  /* bf 0x0602D924 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602D8C6, \"ax\"\n"

    ".global _FUN_0602D8C6\n"
    ".type _FUN_0602D8C6, @function\n"
    "_FUN_0602D8C6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x540C\n"  /* mov.l @(0x30,r0),r4 */
    ".word 0x1048\n"  /* mov.l r4,@(0x20,r0) */
    ".word 0x540A\n"  /* mov.l @(0x28,r0),r4 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x6743\n"  /* mov r4,r7 */
    ".word 0x5303\n"  /* mov.l @(0xC,r0),r3 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x5504\n"  /* mov.l @(0x10,r0),r5 */
    ".word 0x5606\n"  /* mov.l @(0x18,r0),r6 */
    ".word 0x105E\n"  /* mov.l r5,@(0x38,r0) */
    ".word 0x106F\n"  /* mov.l r6,@(0x3C,r0) */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0602D91C] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0602D920] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x9A11\n"  /* mov.w @(0x22,PC),r10 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x0A36\n"  /* mov.l r3,@(r0,r10) */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1054\n"  /* mov.l r5,@(0x10,r0) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x9A0A\n"  /* mov.w @(0x14,PC),r10 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x0A96\n"  /* mov.l r9,@(r0,r10) */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1066\n"  /* mov.l r6,@(0x18,r0) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0250\n"  /* .word 0x0250 */
    ".word 0x018C\n"  /* mov.b @(r0,r8),r1 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602D934, \"ax\"\n"

    ".global _FUN_0602D934\n"
    ".type _FUN_0602D934, @function\n"
    "_FUN_0602D934:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x5A00\n"  /* mov.l @(0x0,r0),r10 */
    ".word 0xDB05\n"  /* mov.l @(0x14,PC),r11  {[0x0602D958] = 0x00000300} */
    ".word 0x2BA8\n"  /* tst r10,r11 */
    ".word 0x8909\n"  /* bt 0x0602D95C */
    ".word 0x351C\n"  /* add r1,r5 */
    ".word 0xA008\n"  /* bra 0x0602D95E */
    ".word 0x0009\n"  /* nop */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECCC\n"  /* mov #-52,r12 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0300\n"  /* .word 0x0300 */
    ".word 0x3518\n"  /* sub r1,r5 */
    ".word 0x105C\n"  /* mov.l r5,@(0x30,r0) */
    ".word 0x1058\n"  /* mov.l r5,@(0x20,r0) */
    ".word 0x9135\n"  /* mov.w @(0x6A,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x104A\n"  /* mov.l r4,@(0x28,r0) */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x9132\n"  /* mov.w @(0x64,PC),r1 */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0602D9D4] = 0x0602E8B8} */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6532\n"  /* mov.l @r3,r5 */
    ".word 0x5203\n"  /* mov.l @(0xC,r0),r2 */
    ".word 0x352D\n"  /* dmuls.l r2,r5 */
    ".word 0x5702\n"  /* mov.l @(0x8,r0),r7 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x252D\n"  /* .word 0x252D */
    ".word 0x1053\n"  /* mov.l r5,@(0xC,r0) */
    ".word 0xE228\n"  /* mov #40,r2 */
    ".word 0x3727\n"  /* cmp/gt r2,r7 */
    ".word 0x8900\n"  /* bt 0x0602D98C */
    ".word 0xD513\n"  /* mov.l @(0x4C,PC),r5  {[0x0602D9D8] = 0x00006AAA} */
    ".word 0x5604\n"  /* mov.l @(0x10,r0),r6 */
    ".word 0x5706\n"  /* mov.l @(0x18,r0),r7 */
    ".word 0x106E\n"  /* mov.l r6,@(0x38,r0) */
    ".word 0x107F\n"  /* mov.l r7,@(0x3C,r0) */
    ".word 0x6943\n"  /* mov r4,r9 */
    ".word 0x6153\n"  /* mov r5,r1 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x0602D9DC] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0602D9E0] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x350D\n"  /* dmuls.l r0,r5 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xDA0D\n"  /* mov.l @(0x34,PC),r10  {[0x0602D9E4] = 0x0000018C} */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x25BD\n"  /* .word 0x25BD */
    ".word 0x0A56\n"  /* mov.l r5,@(r0,r10) */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x1064\n"  /* mov.l r6,@(0x10,r0) */
    ".word 0x318D\n"  /* dmuls.l r8,r1 */
    ".word 0xDA0A\n"  /* mov.l @(0x28,PC),r10  {[0x0602D9E8] = 0x00000190} */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x218D\n"  /* .word 0x218D */
    ".word 0x0A16\n"  /* mov.l r1,@(r0,r10) */
    ".word 0x371C\n"  /* add r1,r7 */
    ".word 0x1076\n"  /* mov.l r7,@(0x18,r0) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0248\n"  /* .word 0x0248 */
    ".word 0x0250\n"  /* .word 0x0250 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE8B8\n"  /* mov #-72,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x6AAA\n"  /* .word 0x6AAA */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x018C\n"  /* mov.b @(r0,r8),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xD02F\n"  /* mov.l @(0xBC,PC),r0  {[0x0602DAB0] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x0602DAB4] = 0x06063F28} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0xD42F\n"  /* mov.l @(0xBC,PC),r4  {[0x0602DAB8] = 0x00000228} */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8945\n"  /* bt 0x0602DA8E */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x0602DABC] = 0x0607EAD8} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0xD42E\n"  /* mov.l @(0xB8,PC),r4  {[0x0602DAC0] = 0x00000001} */
    ".word 0x3340\n"  /* cmp/eq r4,r3 */
    ".word 0x8B04\n"  /* bf 0x0602DA16 */
    ".word 0xD12D\n"  /* mov.l @(0xB4,PC),r1  {[0x0602DAC4] = 0x00000018} */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0xD42D\n"  /* mov.l @(0xB4,PC),r4  {[0x0602DAC8] = 0xFF000000} */
    ".word 0x3343\n"  /* cmp/ge r4,r3 */
    ".word 0x893B\n"  /* bt 0x0602DA8E */
    ".word 0xD12D\n"  /* mov.l @(0xB4,PC),r1  {[0x0602DACC] = 0x000001BC} */
    ".word 0x011E\n"  /* mov.l @(r0,r1),r1 */
    ".word 0xD32D\n"  /* mov.l @(0xB4,PC),r3  {[0x0602DAD0] = 0x00000000} */
    ".word 0x3130\n"  /* cmp/eq r3,r1 */
    ".word 0x8B36\n"  /* bf 0x0602DA8E */
    ".word 0x913A\n"  /* mov.w @(0x74,PC),r1 */
    ".word 0x031D\n"  /* mov.w @(r0,r1),r3 */
    ".word 0x9139\n"  /* mov.w @(0x72,PC),r1 */
    ".word 0x041D\n"  /* mov.w @(r0,r1),r4 */
    ".word 0x9138\n"  /* mov.w @(0x70,PC),r1 */
    ".word 0x051E\n"  /* mov.l @(r0,r1),r5 */
    ".word 0x243B\n"  /* or r3,r4 */
    ".word 0x254B\n"  /* or r4,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B2C\n"  /* bf 0x0602DA8E */
    ".word 0x9133\n"  /* mov.w @(0x66,PC),r1 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x5210\n"  /* mov.l @(0x0,r1),r2 */
    ".word 0x5311\n"  /* mov.l @(0x4,r1),r3 */
    ".word 0x5412\n"  /* mov.l @(0x8,r1),r4 */
    ".word 0x5513\n"  /* mov.l @(0xC,r1),r5 */
    ".word 0x962E\n"  /* mov.w @(0x5C,PC),r6 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2549\n"  /* and r4,r5 */
    ".word 0x2539\n"  /* and r3,r5 */
    ".word 0x3650\n"  /* cmp/eq r5,r6 */
    ".word 0x8B20\n"  /* bf 0x0602DA8E */
    ".word 0xD021\n"  /* mov.l @(0x84,PC),r0  {[0x0602DAD4] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x9127\n"  /* mov.w @(0x4E,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x530A\n"  /* mov.l @(0x28,r0),r3 */
    ".word 0x3348\n"  /* sub r4,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x9523\n"  /* mov.w @(0x46,PC),r5 */
    ".word 0x335C\n"  /* add r5,r3 */
    ".word 0x9522\n"  /* mov.w @(0x44,PC),r5 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8914\n"  /* bt 0x0602DA8E */
    ".word 0x9520\n"  /* mov.w @(0x40,PC),r5 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8B11\n"  /* bf 0x0602DA8E */
    ".word 0x5200\n"  /* mov.l @(0x0,r0),r2 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0602DAD8] = 0x00000008} */
    ".word 0x2238\n"  /* tst r3,r2 */
    ".word 0x8B3C\n"  /* bf 0x0602DAEC */
    ".word 0xD11A\n"  /* mov.l @(0x68,PC),r1  {[0x0602DADC] = 0x06083260} */
    ".word 0x6110\n"  /* mov.b @r1,r1 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x8B38\n"  /* bf 0x0602DAEC */
    ".word 0x5200\n"  /* mov.l @(0x0,r0),r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0602DAE0] = 0x00020000} */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0xD118\n"  /* mov.l @(0x60,PC),r1  {[0x0602DAE4] = 0x0607EAC8} */
    ".word 0x9211\n"  /* mov.w @(0x22,PC),r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD117\n"  /* mov.l @(0x5C,PC),r1  {[0x0602DAE8] = 0x0605A1C4} */
    ".word 0x920F\n"  /* mov.w @(0x1E,PC),r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD113\n"  /* mov.l @(0x4C,PC),r1  {[0x0602DADC] = 0x06083260} */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x0602DAD0] = 0x00000000} */
    ".word 0x2120\n"  /* mov.b r2,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0150\n"  /* .word 0x0150 */
    ".word 0x0250\n"  /* .word 0x0250 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0120\n"  /* .word 0x0120 */
    ".word 0x0041\n"  /* .word 0x0041 */
    ".word 0x025C\n"  /* mov.b @(r0,r5),r2 */
    ".word 0x3FFF\n"  /* .word 0x3FFF */
    ".word 0x2800\n"  /* mov.b r0,@r8 */
    ".word 0x47FF\n"  /* mac.w @r15+,@r7+ */
    ".word 0x003C\n"  /* mov.b @(r0,r3),r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F28\n"  /* sub r2,r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0228\n"  /* .word 0x0228 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01BC\n"  /* mov.b @(r0,r11),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3260\n"  /* cmp/eq r6,r2 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAC8\n"  /* mov #-56,r10 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1C4\n"  /* bra 0x0602DE76 */
    ".word 0xD102\n"  /* mov.l @(0x8,PC),r1  {[0x0602DAF8] = 0x06083260} */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0602DAFC] = 0xFFFFFFFF} */
    ".word 0x2120\n"  /* mov.b r2,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3260\n"  /* cmp/eq r6,r2 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DB0C, \"ax\"\n"

    ".global _FUN_0602DB0C\n"
    ".type _FUN_0602DB0C, @function\n"
    "_FUN_0602DB0C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xD42D\n"  /* mov.l @(0xB4,PC),r4  {[0x0602DBC4] = 0x00000002} */
    ".word 0xD52D\n"  /* mov.l @(0xB4,PC),r5  {[0x0602DBC8] = 0x00000000} */
    ".word 0xDD2E\n"  /* mov.l @(0xB8,PC),r13  {[0x0602DBCC] = 0x0601D5F4} */
);
#if 0 /* FUN_0602DB14 -- duplicated in batch_render_pipe_2a.c */
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DB14, \"ax\"\n"

    ".global _FUN_0602DB14\n"
    ".type _FUN_0602DB14, @function\n"
    "_FUN_0602DB14:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD42C\n"  /* mov.l @(0xB0,PC),r4  {[0x0602DBD0] = 0x00000003} */
    ".word 0xD52A\n"  /* mov.l @(0xA8,PC),r5  {[0x0602DBC8] = 0x00000000} */
    ".word 0xDD2A\n"  /* mov.l @(0xA8,PC),r13  {[0x0602DBCC] = 0x0601D5F4} */
);
#endif
__asm__(
    ".balign 4\n"
    ".global _per_frame_command_reset\n"
    ".type _per_frame_command_reset, @function\n"









    ".section .text.FUN_0602DB22, \"ax\"\n"

    ".global _FUN_0602DB22\n"
    "_per_frame_command_reset:\n"
    "_FUN_0602DB22:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD42A\n"  /* mov.l @(0xA8,PC),r4  {[0x0602DBD4] = 0x06082A30} */
    ".word 0xD126\n"  /* mov.l @(0x98,PC),r1  {[0x0602DBC8] = 0x00000000} */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x0602DBD8] = 0x06082A26} */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x0602DBDC] = 0x060788FC} */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x0602DBE0] = 0x06082A38} */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x0602DBE4] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0602DBE8] = 0x000000C8} */
    ".word 0xD12A\n"  /* mov.l @(0xA8,PC),r1  {[0x0602DBEC] = 0x0607EAC8} */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0602DBC8] = 0x00000000} */
    ".word 0x9130\n"  /* mov.w @(0x60,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x912F\n"  /* mov.w @(0x5E,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x912E\n"  /* mov.w @(0x5C,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x912D\n"  /* mov.w @(0x5A,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xD125\n"  /* mov.l @(0x94,PC),r1  {[0x0602DBF0] = 0x06082A2C} */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0x912A\n"  /* mov.w @(0x54,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x9129\n"  /* mov.w @(0x52,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x9128\n"  /* mov.w @(0x50,PC),r1 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0x9127\n"  /* mov.w @(0x4E,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x9126\n"  /* mov.w @(0x4C,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0602DBC8] = 0x00000000} */
    ".word 0x9124\n"  /* mov.w @(0x48,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x0602DBF4] = 0x00FA0000} */
    ".word 0xD61F\n"  /* mov.l @(0x7C,PC),r6  {[0x0602DBF8] = 0x0000038E} */
    ".word 0x365D\n"  /* dmuls.l r5,r6 */
    ".word 0x050A\n"  /* sts mach,r5 */
    ".word 0x061A\n"  /* sts macl,r6 */
    ".word 0x265D\n"  /* .word 0x265D */
    ".word 0x911D\n"  /* mov.w @(0x3A,PC),r1 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x0602DBFC] = 0x000000FA} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8901\n"  /* bt 0x0602DB90 */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x0602DC00] = 0x0000000C} */
    ".word 0x0166\n"  /* mov.l r6,@(r0,r1) */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x0602DC04] = 0x00000194} */
    ".word 0x0166\n"  /* mov.l r6,@(r0,r1) */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x0602DC08] = 0x0605A1C4} */
    ".word 0x9214\n"  /* mov.w @(0x28,PC),r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x0602DC0C] = 0x06063E1C} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x0602DC10] = 0x06082A34} */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x0602DC14] = 0x06063E20} */
    ".word 0x920D\n"  /* mov.w @(0x1A,PC),r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xA03D\n"  /* bra 0x0602DC26 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0114\n"  /* mov.b r1,@(r0,r1) */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0244\n"  /* mov.b r4,@(r0,r2) */
    ".word 0x0058\n"  /* sets */
    ".word 0x005C\n"  /* mov.b @(r0,r5),r0 */
    ".word 0x025C\n"  /* mov.b @(r0,r5),r2 */
    ".word 0x0030\n"  /* .word 0x0030 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0148\n"  /* .word 0x0148 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0602DFA0] = 0x00000004} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A26\n"  /* mov.l r2,@-r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x88FC\n"  /* cmp/eq #-4,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A38\n"  /* tst r3,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAC8\n"  /* mov #-56,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A2C\n"  /* .word 0x2A2C */
    ".word 0x00FA\n"  /* .word 0x00FA */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x038E\n"  /* mov.l @(r0,r8),r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00FA\n"  /* .word 0x00FA */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0194\n"  /* mov.b r9,@(r0,r1) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1C4\n"  /* bra 0x0602DF96 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E1C\n"  /* add r1,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A34\n"  /* mov.b r3,@-r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E20\n"  /* cmp/eq r2,r14 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".size _per_frame_command_reset, .-_per_frame_command_reset\n"
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DC24, \"ax\"\n"

    ".global _FUN_0602DC24\n"
    ".type _FUN_0602DC24, @function\n"
    "_FUN_0602DC24:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602DC3C] = 0x06082A30} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x0602DC40] = 0x0602DC44} */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DC30, \"ax\"\n"

    ".global _FUN_0602DC30\n"
    ".type _FUN_0602DC30, @function\n"
    "_FUN_0602DC30:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA298\n"  /* bra 0x0602E16C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xDC44\n"  /* mov.l @(0x110,PC),r12  {[0x0602DD54] = 0x06082A30} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xDC58\n"  /* mov.l @(0x160,PC),r12  {[0x0602DDA8] = 0xD03F3103} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xDD10\n"  /* mov.l @(0x40,PC),r13  {[0x0602DC8C] = 0x8B1AD30C} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xDE60\n"  /* mov.l @(0x180,PC),r14  {[0x0602DDD0] = 0x4F26D035} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE078\n"  /* mov #120,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE108\n"  /* mov #8,r1 */
    ".word 0xD110\n"  /* mov.l @(0x40,PC),r1  {[0x0602DC9C] = 0x06082A2C} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD40F\n"  /* mov.l @(0x3C,PC),r4  {[0x0602DCA0] = 0x00000028} */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8B08\n"  /* bf 0x0602DC78 */
    ".word 0xDD0F\n"  /* mov.l @(0x3C,PC),r13  {[0x0602DCA4] = 0x060321C0} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DC68, \"ax\"\n"

    ".global _FUN_0602DC68\n"
    ".type _FUN_0602DC68, @function\n"
    "_FUN_0602DC68:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xD10D\n"  /* mov.l @(0x34,PC),r1  {[0x0602DCA8] = 0x06082A26} */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0602DCAC] = 0x00000001} */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0xD10D\n"  /* mov.l @(0x34,PC),r1  {[0x0602DCB0] = 0x06063EEC} */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0602DCB4] = 0x00000004} */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0602DCB8] = 0x0607EAD8} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0602DCBC] = 0x0602ECAC} */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x8B1A\n"  /* bf 0x0602DCC4 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0602DCC0] = 0x00000100} */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x8B16\n"  /* bf 0x0602DCC4 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xA015\n"  /* bra 0x0602DCC6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A2C\n"  /* .word 0x2A2C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_060321C0 */
    ".word 0x21C0\n"  /* mov.b r12,@r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A26\n"  /* mov.l r2,@-r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECAC\n"  /* mov #-84,r12 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x0602DCEC] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602DCF0] = 0x00000008} */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602DCF4] = 0x00000000} */
    ".word 0x3410\n"  /* cmp/eq r1,r4 */
    ".word 0x8B08\n"  /* bf 0x0602DCE6 */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x0602DCF8] = 0x06082A24} */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602DCFC] = 0xFFFFFFFF} */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x0602DD00] = 0x06082A26} */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602DD04] = 0x00000002} */
    ".word 0x2410\n"  /* mov.b r1,@r4 */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x0602DD08] = 0x06082A30} */
    ".word 0xD10A\n"  /* mov.l @(0x28,PC),r1  {[0x0602DD0C] = 0x00000001} */
    ".word 0x2412\n"  /* mov.l r1,@r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A24\n"  /* mov.b r2,@-r10 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A26\n"  /* mov.l r2,@-r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0602DD40] = 0x0607EAD8} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x0602DD44] = 0x0602ECBC} */
    ".word 0x013E\n"  /* mov.l @(r0,r3),r1 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x0602DD48] = 0x06082A38} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x6316\n"  /* mov.l @r1+,r3 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x0602DD4C] = 0xFFFFFFFF} */
    ".word 0x3300\n"  /* cmp/eq r0,r3 */
    ".word 0x8B16\n"  /* bf 0x0602DD5C */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x0602DD48] = 0x06082A38} */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602DD50] = 0x00000000} */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602DD54] = 0x06082A30} */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x0602DD58] = 0x00000003} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECBC\n"  /* mov #-68,r12 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A38\n"  /* tst r3,r10 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0xD046\n"  /* mov.l @(0x118,PC),r0  {[0x0602DE78] = 0x06082A30} */
    ".word 0xD247\n"  /* mov.l @(0x11C,PC),r2  {[0x0602DE7C] = 0x00000002} */
    ".word 0x2022\n"  /* mov.l r2,@r0 */
    ".word 0xD247\n"  /* mov.l @(0x11C,PC),r2  {[0x0602DE80] = 0x06082A3C} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x6416\n"  /* mov.l @r1+,r4 */
    ".word 0xD246\n"  /* mov.l @(0x118,PC),r2  {[0x0602DE84] = 0x06082A40} */
    ".word 0x2242\n"  /* mov.l r4,@r2 */
    ".word 0x6016\n"  /* mov.l @r1+,r0 */
    ".word 0xD246\n"  /* mov.l @(0x118,PC),r2  {[0x0602DE88] = 0x06082A54} */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x6016\n"  /* mov.l @r1+,r0 */
    ".word 0xD245\n"  /* mov.l @(0x114,PC),r2  {[0x0602DE8C] = 0x06082A58} */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x6016\n"  /* mov.l @r1+,r0 */
    ".word 0xD245\n"  /* mov.l @(0x114,PC),r2  {[0x0602DE90] = 0x06082A44} */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x6016\n"  /* mov.l @r1+,r0 */
    ".word 0xD244\n"  /* mov.l @(0x110,PC),r2  {[0x0602DE94] = 0x06082A48} */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x6016\n"  /* mov.l @r1+,r0 */
    ".word 0xD244\n"  /* mov.l @(0x110,PC),r2  {[0x0602DE98] = 0x06082A50} */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xD143\n"  /* mov.l @(0x10C,PC),r1  {[0x0602DE9C] = 0x00000010} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x8910\n"  /* bt 0x0602DDB4 */
    ".word 0xD13D\n"  /* mov.l @(0xF4,PC),r1  {[0x0602DE88] = 0x06082A54} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD042\n"  /* mov.l @(0x108,PC),r0  {[0x0602DEA0] = 0x06082A70} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3108\n"  /* sub r0,r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xDC41\n"  /* mov.l @(0x104,PC),r12  {[0x0602DEA4] = 0x06034FFC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DDA0, \"ax\"\n"

    ".global _FUN_0602DDA0\n"
    ".type _FUN_0602DDA0, @function\n"
    "_FUN_0602DDA0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD03F\n"  /* mov.l @(0xFC,PC),r0  {[0x0602DEA8] = 0x00000000} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8900\n"  /* bt 0x0602DDB0 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0xD03E\n"  /* mov.l @(0xF8,PC),r0  {[0x0602DEAC] = 0x06082A6C} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xD13E\n"  /* mov.l @(0xF8,PC),r1  {[0x0602DEB0] = 0x00000008} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x8910\n"  /* bt 0x0602DDDE */
    ".word 0xD133\n"  /* mov.l @(0xCC,PC),r1  {[0x0602DE8C] = 0x06082A58} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD03C\n"  /* mov.l @(0xF0,PC),r0  {[0x0602DEB4] = 0x06082A78} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3108\n"  /* sub r0,r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xDC36\n"  /* mov.l @(0xD8,PC),r12  {[0x0602DEA4] = 0x06034FFC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DDCA, \"ax\"\n"

    ".global _FUN_0602DDCA\n"
    ".type _FUN_0602DDCA, @function\n"
    "_FUN_0602DDCA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD035\n"  /* mov.l @(0xD4,PC),r0  {[0x0602DEA8] = 0x00000000} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8900\n"  /* bt 0x0602DDDA */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0xD037\n"  /* mov.l @(0xDC,PC),r0  {[0x0602DEB8] = 0x06082A74} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xD136\n"  /* mov.l @(0xD8,PC),r1  {[0x0602DEBC] = 0x00000004} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x8912\n"  /* bt 0x0602DE0C */
    ".word 0xD12A\n"  /* mov.l @(0xA8,PC),r1  {[0x0602DE90] = 0x06082A44} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD235\n"  /* mov.l @(0xD4,PC),r2  {[0x0602DEC0] = 0x06063EEC} */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x3108\n"  /* sub r0,r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xDC2B\n"  /* mov.l @(0xAC,PC),r12  {[0x0602DEA4] = 0x06034FFC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DDF8, \"ax\"\n"

    ".global _FUN_0602DDF8\n"
    ".type _FUN_0602DDF8, @function\n"
    "_FUN_0602DDF8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x0602DEA8] = 0x00000000} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8900\n"  /* bt 0x0602DE08 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0xD02E\n"  /* mov.l @(0xB8,PC),r0  {[0x0602DEC4] = 0x06082A5C} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xD11B\n"  /* mov.l @(0x6C,PC),r1  {[0x0602DE7C] = 0x00000002} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x8910\n"  /* bt 0x0602DE36 */
    ".word 0xD11F\n"  /* mov.l @(0x7C,PC),r1  {[0x0602DE94] = 0x06082A48} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD02B\n"  /* mov.l @(0xAC,PC),r0  {[0x0602DEC8] = 0x06063EF0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3108\n"  /* sub r0,r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xDC20\n"  /* mov.l @(0x80,PC),r12  {[0x0602DEA4] = 0x06034FFC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DE22, \"ax\"\n"

    ".global _FUN_0602DE22\n"
    ".type _FUN_0602DE22, @function\n"
    "_FUN_0602DE22:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x0602DEA8] = 0x00000000} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8900\n"  /* bt 0x0602DE32 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x0602DECC] = 0x06082A60} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xD125\n"  /* mov.l @(0x94,PC),r1  {[0x0602DED0] = 0x00000001} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x8910\n"  /* bt 0x0602DE60 */
    ".word 0xD116\n"  /* mov.l @(0x58,PC),r1  {[0x0602DE98] = 0x06082A50} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD024\n"  /* mov.l @(0x90,PC),r0  {[0x0602DED4] = 0x06063E24} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3108\n"  /* sub r0,r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xDC16\n"  /* mov.l @(0x58,PC),r12  {[0x0602DEA4] = 0x06034FFC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DE4C, \"ax\"\n"

    ".global _FUN_0602DE4C\n"
    ".type _FUN_0602DE4C, @function\n"
    "_FUN_0602DE4C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0602DEA8] = 0x00000000} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8900\n"  /* bt 0x0602DE5C */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0xD01E\n"  /* mov.l @(0x78,PC),r0  {[0x0602DED8] = 0x06082A68} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0xDD1E\n"  /* mov.l @(0x78,PC),r13  {[0x0602DEDC] = 0x06012AFA} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602DE62, \"ax\"\n"

    ".global _FUN_0602DE62\n"
    ".type _FUN_0602DE62, @function\n"
    "_FUN_0602DE62:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x0602DE84] = 0x06082A40} */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B35\n"  /* bf 0x0602DEE0 */
    ".word 0xA0F1\n"  /* bra 0x0602E05A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A3C\n"  /* .word 0x2A3C */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A40\n"  /* mov.b r4,@r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A54\n"  /* mov.b r5,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A58\n"  /* tst r5,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A44\n"  /* mov.b r4,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A48\n"  /* tst r4,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A50\n"  /* mov.b r5,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A70\n"  /* mov.b r7,@r10 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4FFC\n"  /* .word 0x4FFC */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A6C\n"  /* .word 0x2A6C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A78\n"  /* tst r7,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A74\n"  /* mov.b r7,@-r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A5C\n"  /* .word 0x2A5C */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EF0\n"  /* cmp/eq r15,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A60\n"  /* mov.b r6,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E24\n"  /* .word 0x3E24 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A68\n"  /* tst r6,r10 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06012AFA */
    ".word 0x2AFA\n"  /* xor r15,r10 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0602DF0C] = 0x06082A3C} */
    ".word 0x6422\n"  /* mov.l @r2,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602DF10] = 0x00000010} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x8922\n"  /* bt 0x0602DF36 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x0602DF14] = 0x06082A54} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x0602DF18] = 0x06082A70} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8911\n"  /* bt 0x0602DF20 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602DF1C] = 0x06082A6C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8916\n"  /* bt 0x0602DF34 */
    ".word 0xA010\n"  /* bra 0x0602DF2A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A3C\n"  /* .word 0x2A3C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A54\n"  /* mov.b r5,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A70\n"  /* mov.b r7,@r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A6C\n"  /* .word 0x2A6C */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0602DF30] = 0x06082A6C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8904\n"  /* bt 0x0602DF34 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xA003\n"  /* bra 0x0602DF36 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A6C\n"  /* .word 0x2A6C */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602DF58] = 0x00000008} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x891F\n"  /* bt 0x0602DF7E */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602DF5C] = 0x06082A58} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602DF60] = 0x06082A78} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x890E\n"  /* bt 0x0602DF68 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602DF64] = 0x06082A74} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8913\n"  /* bt 0x0602DF7C */
    ".word 0xA00D\n"  /* bra 0x0602DF72 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A58\n"  /* tst r5,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A78\n"  /* tst r7,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A74\n"  /* mov.b r7,@-r10 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0602DF78] = 0x06082A74} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8904\n"  /* bt 0x0602DF7C */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xA003\n"  /* bra 0x0602DF7E */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A74\n"  /* mov.b r7,@-r10 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602DFA0] = 0x00000004} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x891F\n"  /* bt 0x0602DFC6 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602DFA4] = 0x06082A44} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602DFA8] = 0x06063EEC} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x890E\n"  /* bt 0x0602DFB0 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602DFAC] = 0x06082A5C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8913\n"  /* bt 0x0602DFC4 */
    ".word 0xA00D\n"  /* bra 0x0602DFBA */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A44\n"  /* mov.b r4,@-r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A5C\n"  /* .word 0x2A5C */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0602DFC0] = 0x06082A5C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8904\n"  /* bt 0x0602DFC4 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xA003\n"  /* bra 0x0602DFC6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A5C\n"  /* .word 0x2A5C */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602DFE8] = 0x00000002} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x891F\n"  /* bt 0x0602E00E */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602DFEC] = 0x06082A48} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602DFF0] = 0x06063EF0} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x890E\n"  /* bt 0x0602DFF8 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602DFF4] = 0x06082A60} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8913\n"  /* bt 0x0602E00C */
    ".word 0xA00D\n"  /* bra 0x0602E002 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A48\n"  /* tst r4,r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EF0\n"  /* cmp/eq r15,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A60\n"  /* mov.b r6,@r10 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0602E008] = 0x06082A60} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8904\n"  /* bt 0x0602E00C */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xA003\n"  /* bra 0x0602E00E */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A60\n"  /* mov.b r6,@r10 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602E030] = 0x00000001} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x891F\n"  /* bt 0x0602E056 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602E034] = 0x06082A50} */
    ".word 0x6302\n"  /* mov.l @r0,r3 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602E038] = 0x06063E24} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x890E\n"  /* bt 0x0602E040 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602E03C] = 0x06082A68} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8913\n"  /* bt 0x0602E054 */
    ".word 0xA00D\n"  /* bra 0x0602E04A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A50\n"  /* mov.b r5,@r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E24\n"  /* .word 0x3E24 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A68\n"  /* tst r6,r10 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0602E050] = 0x06082A68} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8904\n"  /* bt 0x0602E054 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xA003\n"  /* bra 0x0602E056 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A68\n"  /* tst r6,r10 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x0602E06C] = 0x06082A38} */
    ".word 0x6012\n"  /* mov.l @r1,r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x0602E070] = 0x06082A30} */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0602E074] = 0x00000001} */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0xAE52\n"  /* bra 0x0602DD10 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A38\n"  /* tst r3,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xDD12\n"  /* mov.l @(0x48,PC),r13  {[0x0602E0C4] = 0x06012AC4} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E07A, \"ax\"\n"

    ".global _FUN_0602E07A\n"
    ".type _FUN_0602E07A, @function\n"
    "_FUN_0602E07A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0C8] = 0x06082A54} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0CC] = 0x06082A70} */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0D0] = 0x06082A58} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0D4] = 0x06082A78} */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0D8] = 0x06082A44} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0DC] = 0x06063EEC} */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0E0] = 0x06082A48} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0E4] = 0x06063EF0} */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0E8] = 0x06082A50} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0EC] = 0x06063E24} */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x0602E0F0] = 0x06082A30} */
    ".word 0xD110\n"  /* mov.l @(0x40,PC),r1  {[0x0602E0F4] = 0x00000004} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E0F8] = 0x06063E34} */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0602E0FC] = 0x0000F300} */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x0602E100] = 0x06063E28} */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0602E104] = 0x006E0000} */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06012AC4 */
    ".word 0x2AC4\n"  /* mov.b r12,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A54\n"  /* mov.b r5,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A70\n"  /* mov.b r7,@r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A58\n"  /* tst r5,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A78\n"  /* tst r7,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A44\n"  /* mov.b r4,@-r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A48\n"  /* tst r4,r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EF0\n"  /* cmp/eq r15,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A50\n"  /* mov.b r5,@r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E24\n"  /* .word 0x3E24 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E34\n"  /* .word 0x3E34 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF300\n"  /* .word 0xF300 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E28\n"  /* sub r2,r14 */
    ".word 0x006E\n"  /* mov.l @(r0,r6),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD10F\n"  /* mov.l @(0x3C,PC),r1  {[0x0602E148] = 0x0605A1C4} */
    ".word 0x9318\n"  /* mov.w @(0x30,PC),r3 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD10F\n"  /* mov.l @(0x3C,PC),r1  {[0x0602E14C] = 0x0605A1D0} */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0602E150] = 0x00010000} */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD10F\n"  /* mov.l @(0x3C,PC),r1  {[0x0602E154] = 0x06082A34} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0xD10F\n"  /* mov.l @(0x3C,PC),r1  {[0x0602E158] = 0x06063E20} */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD10F\n"  /* mov.l @(0x3C,PC),r1  {[0x0602E15C] = 0x06082A30} */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x0602E160] = 0x00000000} */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x930D\n"  /* mov.w @(0x1A,PC),r3 */
    ".word 0xD10F\n"  /* mov.l @(0x3C,PC),r1  {[0x0602E164] = 0x0607EAC8} */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0602E168] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x9108\n"  /* mov.w @(0x10,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x9107\n"  /* mov.w @(0xE,PC),r1 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x9106\n"  /* mov.w @(0xC,PC),r1 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x01B4\n"  /* mov.b r11,@(r0,r1) */
    ".word 0x00DC\n"  /* mov.b @(r0,r13),r0 */
    ".word 0x00DE\n"  /* mov.l @(r0,r13),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1C4\n"  /* bra 0x0602E4D6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1D0\n"  /* bra 0x0602E4F2 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A34\n"  /* mov.b r3,@-r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E20\n"  /* cmp/eq r2,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAC8\n"  /* mov #-56,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0xD10E\n"  /* mov.l @(0x38,PC),r1  {[0x0602E1A8] = 0x0608325C} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8907\n"  /* bt 0x0602E184 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602E1AC] = 0x0602EC54} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x022E\n"  /* mov.l @(r0,r2),r2 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x0602E1B0] = 0x06083258} */
    ".word 0x2022\n"  /* mov.l r2,@r0 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x0602E1B4] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xDD0B\n"  /* mov.l @(0x2C,PC),r13  {[0x0602E1B8] = 0x0600DB64} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E18A, \"ax\"\n"

    ".global _FUN_0602E18A\n"
    ".type _FUN_0602E18A, @function\n"
    "_FUN_0602E18A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602E1B4] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x0602E1BC] = 0x00000244} */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x0602E1C0] = 0x00000007} */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8B10\n"  /* bf 0x0602E1C4 */
    ".word 0xA0FD\n"  /* bra 0x0602E3A0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEC54\n"  /* mov #84,r12 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0xDB64\n"  /* mov.l @(0x190,PC),r11  {[0x0602E34C] = 0xD410DD12} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0244\n"  /* mov.b r4,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0xD334\n"  /* mov.l @(0xD0,PC),r3  {[0x0602E298] = 0x0607EAC8} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0xD134\n"  /* mov.l @(0xD0,PC),r1  {[0x0602E29C] = 0x00000001} */
    ".word 0x3318\n"  /* sub r1,r3 */
    ".word 0xD434\n"  /* mov.l @(0xD0,PC),r4  {[0x0602E2A0] = 0x00000028} */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8B12\n"  /* bf 0x0602E1F8 */
    ".word 0x9157\n"  /* mov.w @(0xAE,PC),r1 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0x9256\n"  /* mov.w @(0xAC,PC),r2 */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x9254\n"  /* mov.w @(0xA8,PC),r2 */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x9252\n"  /* mov.w @(0xA4,PC),r2 */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x9250\n"  /* mov.w @(0xA0,PC),r2 */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xD129\n"  /* mov.l @(0xA4,PC),r1  {[0x0602E298] = 0x0607EAC8} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x0602E29C] = 0x00000001} */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0xD127\n"  /* mov.l @(0x9C,PC),r1  {[0x0602E298] = 0x0607EAC8} */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0x9147\n"  /* mov.w @(0x8E,PC),r1 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0xD228\n"  /* mov.l @(0xA0,PC),r2  {[0x0602E2A4] = 0x00000000} */
    ".word 0x3320\n"  /* cmp/eq r2,r3 */
    ".word 0x8902\n"  /* bt 0x0602E20C */
    ".word 0xD225\n"  /* mov.l @(0x94,PC),r2  {[0x0602E29C] = 0x00000001} */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0602E2A4] = 0x00000000} */
    ".word 0xD126\n"  /* mov.l @(0x98,PC),r1  {[0x0602E2A8] = 0x000000C0} */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xDD26\n"  /* mov.l @(0x98,PC),r13  {[0x0602E2AC] = 0x0602F3EC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E214, \"ax\"\n"

    ".global _FUN_0602E214\n"
    ".type _FUN_0602E214, @function\n"
    "_FUN_0602E214:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD24\n"  /* mov.l @(0x90,PC),r13  {[0x0602E2B0] = 0x0602F7BC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E220, \"ax\"\n"

    ".global _FUN_0602E220\n"
    ".type _FUN_0602E220, @function\n"
    "_FUN_0602E220:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD22\n"  /* mov.l @(0x88,PC),r13  {[0x0602E2B4] = 0x06030A06} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E22C, \"ax\"\n"

    ".global _FUN_0602E22C\n"
    ".type _FUN_0602E22C, @function\n"
    "_FUN_0602E22C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD20\n"  /* mov.l @(0x80,PC),r13  {[0x0602E2B8] = 0x06030EE0} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E236, \"ax\"\n"

    ".global _FUN_0602E236\n"
    ".type _FUN_0602E236, @function\n"
    "_FUN_0602E236:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD1F\n"  /* mov.l @(0x7C,PC),r13  {[0x0602E2BC] = 0x060085B8} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E240, \"ax\"\n"

    ".global _FUN_0602E240\n"
    ".type _FUN_0602E240, @function\n"
    "_FUN_0602E240:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD1D\n"  /* mov.l @(0x74,PC),r13  {[0x0602E2C0] = 0x0600C4F8} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E24A, \"ax\"\n"

    ".global _FUN_0602E24A\n"
    ".type _FUN_0602E24A, @function\n"
    "_FUN_0602E24A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x0602E2C4] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xDD1B\n"  /* mov.l @(0x6C,PC),r13  {[0x0602E2C8] = 0x0602D82A} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E25A, \"ax\"\n"

    ".global _FUN_0602E25A\n"
    ".type _FUN_0602E25A, @function\n"
    "_FUN_0602E25A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD1A\n"  /* mov.l @(0x68,PC),r13  {[0x0602E2CC] = 0x0602F17C} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E264, \"ax\"\n"

    ".global _FUN_0602E264\n"
    ".type _FUN_0602E264, @function\n"
    "_FUN_0602E264:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x0602E2C4] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x950E\n"  /* mov.w @(0x1C,PC),r5 */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0x930D\n"  /* mov.w @(0x1A,PC),r3 */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x940C\n"  /* mov.w @(0x18,PC),r4 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8928\n"  /* bt 0x0602E2D0 */
    ".word 0x6133\n"  /* mov r3,r1 */
    ".word 0xA029\n"  /* bra 0x0602E2D6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0044\n"  /* mov.b r4,@(r0,r0) */
    ".word 0x0022\n"  /* stc vbr,r0 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x0208\n"  /* .word 0x0208 */
    ".word 0x00E4\n"  /* mov.b r14,@(r0,r0) */
    ".word 0x0708\n"  /* .word 0x0708 */
    ".word 0x2134\n"  /* mov.b r3,@-r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAC8\n"  /* mov #-56,r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF3EC\n"  /* .word 0xF3EC */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF7BC\n"  /* .word 0xF7BC */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0A06\n"  /* mov.l r0,@(r0,r10) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0EE0\n"  /* .word 0x0EE0 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060085B8 */
    ".word 0x85B8\n"  /* mov.w @(0x10,r11),r0 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600C4F8 */
    ".word 0xC4F8\n"  /* mov.b @(0xF8,GBR),r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xD82A\n"  /* mov.l @(0xA8,PC),r8  {[0x0602E374] = 0x00300020} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF17C\n"  /* .word 0xF17C */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8900\n"  /* bt 0x0602E2D6 */
    ".word 0x6143\n"  /* mov r4,r1 */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x900D\n"  /* mov.w @(0x1A,PC),r0 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0xDC07\n"  /* mov.l @(0x1C,PC),r12  {[0x0602E2FC] = 0x0602ECCC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E2E0, \"ax\"\n"

    ".global _FUN_0602E2E0\n"
    ".type _FUN_0602E2E0, @function\n"
    "_FUN_0602E2E0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xE47F\n"  /* mov #127,r4 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x3037\n"  /* cmp/gt r3,r0 */
    ".word 0x8906\n"  /* bt 0x0602E300 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xA007\n"  /* bra 0x0602E306 */
    ".word 0x0009\n"  /* nop */
    ".word 0x14B4\n"  /* mov.l r11,@(0x10,r4) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECCC\n"  /* mov #-52,r12 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8900\n"  /* bt 0x0602E306 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xDC1C\n"  /* mov.l @(0x70,PC),r12  {[0x0602E37C] = 0x0601D5F4} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E30C, \"ax\"\n"

    ".global _FUN_0602E30C\n"
    ".type _FUN_0602E30C, @function\n"
    "_FUN_0602E30C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x0602E380] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x912A\n"  /* mov.w @(0x54,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0xDD19\n"  /* mov.l @(0x64,PC),r13  {[0x0602E384] = 0x0602E450} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E320, \"ax\"\n"

    ".global _FUN_0602E320\n"
    ".type _FUN_0602E320, @function\n"
    "_FUN_0602E320:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD17\n"  /* mov.l @(0x5C,PC),r13  {[0x0602E388] = 0x0602E4BC} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E32C, \"ax\"\n"

    ".global _FUN_0602E32C\n"
    ".type _FUN_0602E32C, @function\n"
    "_FUN_0602E32C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD15\n"  /* mov.l @(0x54,PC),r13  {[0x0602E38C] = 0x0600CE66} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E338, \"ax\"\n"

    ".global _FUN_0602E338\n"
    ".type _FUN_0602E338, @function\n"
    "_FUN_0602E338:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD413\n"  /* mov.l @(0x4C,PC),r4  {[0x0602E390] = 0x00000000} */
    ".word 0xDD14\n"  /* mov.l @(0x50,PC),r13  {[0x0602E394] = 0x0603053C} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E344, \"ax\"\n"

    ".global _FUN_0602E344\n"
    ".type _FUN_0602E344, @function\n"
    "_FUN_0602E344:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602E390] = 0x00000000} */
    ".word 0xDD12\n"  /* mov.l @(0x48,PC),r13  {[0x0602E398] = 0x0600D780} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E350, \"ax\"\n"

    ".global _FUN_0602E350\n"
    ".type _FUN_0602E350, @function\n"
    "_FUN_0602E350:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x0602E380] = 0x0607E940} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x910A\n"  /* mov.w @(0x14,PC),r1 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0x9109\n"  /* mov.w @(0x12,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x9108\n"  /* mov.w @(0x10,PC),r1 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0xD40C\n"  /* mov.l @(0x30,PC),r4  {[0x0602E39C] = 0x00000096} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x89FF\n"  /* bt 0x0602E36E */
    ".word 0xA041\n"  /* bra 0x0602E3F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0030\n"  /* .word 0x0030 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0602E750] = 0x00000008} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE450\n"  /* mov #80,r4 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE4BC\n"  /* mov #-68,r4 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600CE66 */
    ".word 0xCE66\n"  /* .word 0xCE66 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x053C\n"  /* mov.b @(r0,r3),r5 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600D780 */
    ".word 0xD780\n"  /* mov.l @(0x200,PC),r7  {[0x0602E59C] = 0x891A000B} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0096\n"  /* mov.l r9,@(r0,r0) */
    ".word 0xD10B\n"  /* mov.l @(0x2C,PC),r1  {[0x0602E3D0] = 0x0605A1D0} */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0602E3D4] = 0x00010000} */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x0602E3D8] = 0x06082A34} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x0602E3DC] = 0x06063E20} */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x0602E3E0] = 0x06082A30} */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x0602E3E4] = 0x00000000} */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x0602E3E8] = 0x0605A1C4} */
    ".word 0x9308\n"  /* mov.w @(0x10,PC),r3 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0602E3EC] = 0x00000001} */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x0602E3F0] = 0x0607EAC8} */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x9303\n"  /* mov.w @(0x6,PC),r3 */
    ".word 0x9103\n"  /* mov.w @(0x6,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xAF19\n"  /* bra 0x0602E1FC */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01B4\n"  /* mov.b r11,@(r0,r1) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1D0\n"  /* bra 0x0602E776 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A34\n"  /* mov.b r3,@-r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E20\n"  /* cmp/eq r2,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A30\n"  /* mov.b r3,@r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1C4\n"  /* bra 0x0602E776 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAC8\n"  /* mov #-56,r10 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602E414] = 0x06082A2C} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0xD407\n"  /* mov.l @(0x1C,PC),r4  {[0x0602E418] = 0x00000028} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x891C\n"  /* bt 0x0602E438 */
    ".word 0xD207\n"  /* mov.l @(0x1C,PC),r2  {[0x0602E41C] = 0x06082A25} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0602E420] = 0x00000004} */
    ".word 0x2219\n"  /* and r1,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8910\n"  /* bt 0x0602E42C */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602E424] = 0x06082A26} */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x0602E428] = 0x00000000} */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0xA012\n"  /* bra 0x0602E438 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A2C\n"  /* .word 0x2A2C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A25\n"  /* mov.w r2,@-r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A26\n"  /* mov.l r2,@-r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xDD07\n"  /* mov.l @(0x1C,PC),r13  {[0x0602E44C] = 0x0603226C} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E42E, \"ax\"\n"

    ".global _FUN_0602E42E\n"
    ".type _FUN_0602E42E, @function\n"
    "_FUN_0602E42E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603226C */
    ".word 0x226C\n"  /* .word 0x226C */
    ".global _FUN_0602e450\n"
    "_FUN_0602e450:\n"
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x9105\n"  /* mov.w @(0xA,PC),r1 */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0x3210\n"  /* cmp/eq r1,r2 */
    ".word 0x8902\n"  /* bt 0x0602E462 */
    ".word 0xAA62\n"  /* bra 0x0602D924 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0250\n"  /* .word 0x0250 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E462, \"ax\"\n"

    ".global _FUN_0602E462\n"
    ".type _FUN_0602E462, @function\n"
    "_FUN_0602E462:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x6743\n"  /* mov r4,r7 */
    ".word 0x5303\n"  /* mov.l @(0xC,r0),r3 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x5504\n"  /* mov.l @(0x10,r0),r5 */
    ".word 0x5606\n"  /* mov.l @(0x18,r0),r6 */
    ".word 0x105E\n"  /* mov.l r5,@(0x38,r0) */
    ".word 0x106F\n"  /* mov.l r6,@(0x3C,r0) */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0602E4AC] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x0602E4B0] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xDA0A\n"  /* mov.l @(0x28,PC),r10  {[0x0602E4B4] = 0x0000018C} */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x0A36\n"  /* mov.l r3,@(r0,r10) */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1054\n"  /* mov.l r5,@(0x10,r0) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0xDA07\n"  /* mov.l @(0x1C,PC),r10  {[0x0602E4B8] = 0x00000190} */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x0A96\n"  /* mov.l r9,@(r0,r10) */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1066\n"  /* mov.l r6,@(0x18,r0) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x018C\n"  /* mov.b @(r0,r8),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".global _FUN_0602e4bc\n"
    "_FUN_0602e4bc:\n"
    ".word 0x912D\n"  /* mov.w @(0x5A,PC),r1 */
    ".word 0x091E\n"  /* mov.l @(r0,r1),r9 */
    ".word 0x4908\n"  /* shll2 r9 */
    ".word 0xD119\n"  /* mov.l @(0x64,PC),r1  {[0x0602E528] = 0x0607EAD8} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0xD419\n"  /* mov.l @(0x64,PC),r4  {[0x0602E52C] = 0x0602E8AC} */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4908\n"  /* shll2 r9 */
    ".word 0x349C\n"  /* add r9,r4 */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x9122\n"  /* mov.w @(0x44,PC),r1 */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0x6512\n"  /* mov.l @r1,r5 */
    ".word 0x9120\n"  /* mov.w @(0x40,PC),r1 */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0x6612\n"  /* mov.l @r1,r6 */
    ".word 0x911E\n"  /* mov.w @(0x3C,PC),r1 */
    ".word 0x071E\n"  /* mov.l @(r0,r1),r7 */
    ".word 0x911D\n"  /* mov.w @(0x3A,PC),r1 */
    ".word 0x081E\n"  /* mov.l @(r0,r1),r8 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x3478\n"  /* sub r7,r4 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x3588\n"  /* sub r8,r5 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0602E530] = 0x0602744C} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E4F4, \"ax\"\n"

    ".global _FUN_0602E4F4\n"
    ".type _FUN_0602E4F4, @function\n"
    "_FUN_0602E4F4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x650B\n"  /* neg r0,r5 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x655F\n"  /* exts.w r5,r5 */
    ".word 0x910E\n"  /* mov.w @(0x1C,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x6653\n"  /* mov r5,r6 */
    ".word 0x3648\n"  /* sub r4,r6 */
    ".word 0x666F\n"  /* exts.w r6,r6 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x0602E534] = 0xFFFFFF00} */
    ".word 0x3617\n"  /* cmp/gt r1,r6 */
    ".word 0x8910\n"  /* bt 0x0602E538 */
    ".word 0xA012\n"  /* bra 0x0602E53E */
    ".word 0x0009\n"  /* nop */
    ".word 0x0244\n"  /* mov.b r4,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE8AC\n"  /* mov #-84,r8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x744C\n"  /* add #76,r4 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x0602E5AC] = 0x00000100} */
    ".word 0x3617\n"  /* cmp/gt r1,r6 */
    ".word 0x8B00\n"  /* bf 0x0602E540 */
    ".word 0x6613\n"  /* mov r1,r6 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD11A\n"  /* mov.l @(0x68,PC),r1  {[0x0602E5B0] = 0x00000030} */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xD11A\n"  /* mov.l @(0x68,PC),r1  {[0x0602E5B4] = 0x00000028} */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0xD11A\n"  /* mov.l @(0x68,PC),r1  {[0x0602E5B8] = 0x00000008} */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0xD619\n"  /* mov.l @(0x64,PC),r6  {[0x0602E5BC] = 0x0000038E} */
    ".word 0x336D\n"  /* dmuls.l r6,r3 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x236D\n"  /* .word 0x236D */
    ".word 0x9120\n"  /* mov.w @(0x40,PC),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x911F\n"  /* mov.w @(0x3E,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B0B\n"  /* bf 0x0602E582 */
    ".word 0xD115\n"  /* mov.l @(0x54,PC),r1  {[0x0602E5C0] = 0x0608325C} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B07\n"  /* bf 0x0602E582 */
    ".word 0x9318\n"  /* mov.w @(0x30,PC),r3 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xDD13\n"  /* mov.l @(0x4C,PC),r13  {[0x0602E5C4] = 0x0602CCD0} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E578, \"ax\"\n"

    ".global _FUN_0602E578\n"
    ".type _FUN_0602E578, @function\n"
    "_FUN_0602E578:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0009\n"  /* nop */
    ".word 0x9111\n"  /* mov.w @(0x22,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3348\n"  /* sub r4,r3 */
    ".word 0xD60E\n"  /* mov.l @(0x38,PC),r6  {[0x0602E5C8] = 0x00003FFF} */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0xD10E\n"  /* mov.l @(0x38,PC),r1  {[0x0602E5CC] = 0x00000000} */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8B1D\n"  /* bf 0x0602E5D4 */
    ".word 0xD60D\n"  /* mov.l @(0x34,PC),r6  {[0x0602E5D0] = 0x00007FFF} */
    ".word 0x3367\n"  /* cmp/gt r6,r3 */
    ".word 0x891A\n"  /* bt 0x0602E5D4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0194\n"  /* mov.b r9,@(r0,r1) */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x025C\n"  /* mov.b @(r0,r5),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0030\n"  /* .word 0x0030 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x038E\n"  /* mov.l @(r0,r8),r3 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xCCD0\n"  /* .word 0xCCD0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x3FFF\n"  /* .word 0x3FFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0xD102\n"  /* mov.l @(0x8,PC),r1  {[0x0602E5E0] = 0x00000244} */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0244\n"  /* mov.b r4,@(r0,r2) */
    ".global _FUN_0602e5e4\n"
    "_FUN_0602e5e4:\n"
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x0602E5FC] = 0x0607E944} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602E600] = 0x00000238} */
    ".word 0x012E\n"  /* mov.l @(r0,r2),r1 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602E604] = 0x06083264} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602E608] = 0x0000023C} */
    ".word 0x012E\n"  /* mov.l @(r0,r2),r1 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0602E60C] = 0x06083268} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0238\n"  /* .word 0x0238 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3264\n"  /* .word 0x3264 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x023C\n"  /* mov.b @(r0,r3),r2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3268\n"  /* sub r6,r2 */
    ".global _FUN_0602e610\n"
    "_FUN_0602e610:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E61C, \"ax\"\n"

    ".global _FUN_0602E61C\n"
    ".type _FUN_0602E61C, @function\n"
    "_FUN_0602E61C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xD906\n"  /* mov.l @(0x18,PC),r9  {[0x0602E638] = 0x0607E944} */
    ".word 0x6992\n"  /* mov.l @r9,r9 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602E63C] = 0x00000008} */
    ".word 0x079E\n"  /* mov.l @(r0,r9),r7 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0602E640] = 0x00000238} */
    ".word 0x0A9E\n"  /* mov.l @(r0,r9),r10 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0602E644] = 0x06083264} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x33A0\n"  /* cmp/eq r10,r3 */
    ".word 0x8B0A\n"  /* bf 0x0602E648 */
    ".word 0xA0AB\n"  /* bra 0x0602E78C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0238\n"  /* .word 0x0238 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3264\n"  /* .word 0x3264 */
    ".word 0xD302\n"  /* mov.l @(0x8,PC),r3  {[0x0602E654] = 0x06083268} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x33A0\n"  /* cmp/eq r10,r3 */
    ".word 0x8903\n"  /* bt 0x0602E658 */
    ".word 0xA04A\n"  /* bra 0x0602E6E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3268\n"  /* sub r6,r2 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0602E6AC] = 0x00000008} */
    ".word 0x08AE\n"  /* mov.l @(r0,r10),r8 */
    ".word 0x3878\n"  /* sub r7,r8 */
    ".word 0x4811\n"  /* cmp/pz r8 */
    ".word 0x8900\n"  /* bt 0x0602E664 */
    ".word 0x688B\n"  /* neg r8,r8 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0602E6B0] = 0x00000010} */
    ".word 0x039E\n"  /* mov.l @(r0,r9),r3 */
    ".word 0x05AE\n"  /* mov.l @(r0,r10),r5 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0602E6B4] = 0x00000018} */
    ".word 0x069E\n"  /* mov.l @(r0,r9),r6 */
    ".word 0x04AE\n"  /* mov.l @(r0,r10),r4 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x3538\n"  /* sub r3,r5 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0xDD10\n"  /* mov.l @(0x40,PC),r13  {[0x0602E6B8] = 0x06027552} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E678, \"ax\"\n"

    ".global _FUN_0602E678\n"
    ".type _FUN_0602E678, @function\n"
    "_FUN_0602E678:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6703\n"  /* mov r0,r7 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0xDD0B\n"  /* mov.l @(0x2C,PC),r13  {[0x0602E6B8] = 0x06027552} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E68A, \"ax\"\n"

    ".global _FUN_0602E68A\n"
    ".type _FUN_0602E68A, @function\n"
    "_FUN_0602E68A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x370C\n"  /* add r0,r7 */
    ".word 0x4711\n"  /* cmp/pz r7 */
    ".word 0x8913\n"  /* bt 0x0602E6C0 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0x4409\n"  /* shlr2 r4 */
    ".word 0xDD07\n"  /* mov.l @(0x1C,PC),r13  {[0x0602E6BC] = 0x06027476} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E69E, \"ax\"\n"

    ".global _FUN_0602E69E\n"
    ".type _FUN_0602E69E, @function\n"
    "_FUN_0602E69E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA011\n"  /* bra 0x0602E6CC */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7476\n"  /* add #118,r4 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0xDD07\n"  /* mov.l @(0x1C,PC),r13  {[0x0602E6E0] = 0x06027476} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E6C4, \"ax\"\n"

    ".global _FUN_0602E6C4\n"
    ".type _FUN_0602E6C4, @function\n"
    "_FUN_0602E6C4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6703\n"  /* mov r0,r7 */
    ".word 0x4711\n"  /* cmp/pz r7 */
    ".word 0x8900\n"  /* bt 0x0602E6D4 */
    ".word 0x677B\n"  /* neg r7,r7 */
    ".word 0xDB03\n"  /* mov.l @(0xC,PC),r11  {[0x0602E6E4] = 0x000F0000} */
    ".word 0x37B3\n"  /* cmp/ge r11,r7 */
    ".word 0x8958\n"  /* bt 0x0602E78C */
    ".word 0xA071\n"  /* bra 0x0602E7C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7476\n"  /* add #118,r4 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0602E748] = 0x06083264} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0602E74C] = 0x0000023C} */
    ".word 0x0A9E\n"  /* mov.l @(r0,r9),r10 */
    ".word 0x3A30\n"  /* cmp/eq r3,r10 */
    ".word 0x8B4B\n"  /* bf 0x0602E78C */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x0602E750] = 0x00000008} */
    ".word 0x08AE\n"  /* mov.l @(r0,r10),r8 */
    ".word 0x3878\n"  /* sub r7,r8 */
    ".word 0x4811\n"  /* cmp/pz r8 */
    ".word 0x8900\n"  /* bt 0x0602E700 */
    ".word 0x688B\n"  /* neg r8,r8 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0602E754] = 0x00000010} */
    ".word 0x039E\n"  /* mov.l @(r0,r9),r3 */
    ".word 0x05AE\n"  /* mov.l @(r0,r10),r5 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0602E758] = 0x00000018} */
    ".word 0x069E\n"  /* mov.l @(r0,r9),r6 */
    ".word 0x04AE\n"  /* mov.l @(r0,r10),r4 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x3538\n"  /* sub r3,r5 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0xDD12\n"  /* mov.l @(0x48,PC),r13  {[0x0602E75C] = 0x06027552} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E714, \"ax\"\n"

    ".global _FUN_0602E714\n"
    ".type _FUN_0602E714, @function\n"
    "_FUN_0602E714:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6703\n"  /* mov r0,r7 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0xDD0D\n"  /* mov.l @(0x34,PC),r13  {[0x0602E75C] = 0x06027552} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E726, \"ax\"\n"

    ".global _FUN_0602E726\n"
    ".type _FUN_0602E726, @function\n"
    "_FUN_0602E726:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x370C\n"  /* add r0,r7 */
    ".word 0x4711\n"  /* cmp/pz r7 */
    ".word 0x8917\n"  /* bt 0x0602E764 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0x4409\n"  /* shlr2 r4 */
    ".word 0xDD09\n"  /* mov.l @(0x24,PC),r13  {[0x0602E760] = 0x06027476} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E73A, \"ax\"\n"

    ".global _FUN_0602E73A\n"
    ".type _FUN_0602E73A, @function\n"
    "_FUN_0602E73A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA015\n"  /* bra 0x0602E770 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3264\n"  /* .word 0x3264 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x023C\n"  /* mov.b @(r0,r3),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7476\n"  /* add #118,r4 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0xDD07\n"  /* mov.l @(0x1C,PC),r13  {[0x0602E784] = 0x06027476} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E768, \"ax\"\n"

    ".global _FUN_0602E768\n"
    ".type _FUN_0602E768, @function\n"
    "_FUN_0602E768:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6703\n"  /* mov r0,r7 */
    ".word 0x4711\n"  /* cmp/pz r7 */
    ".word 0x8900\n"  /* bt 0x0602E778 */
    ".word 0x677B\n"  /* neg r7,r7 */
    ".word 0xDB03\n"  /* mov.l @(0xC,PC),r11  {[0x0602E788] = 0x000F0000} */
    ".word 0x37B3\n"  /* cmp/ge r11,r7 */
    ".word 0x8906\n"  /* bt 0x0602E78C */
    ".word 0xA01F\n"  /* bra 0x0602E7C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7476\n"  /* add #118,r4 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x0602E7B0] = 0x00000238} */
    ".word 0x039E\n"  /* mov.l @(r0,r9),r3 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x0602E7B4] = 0x06083264} */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x0602E7B8] = 0x0000023C} */
    ".word 0x039E\n"  /* mov.l @(r0,r9),r3 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x0602E7BC] = 0x06083268} */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0238\n"  /* .word 0x0238 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3264\n"  /* .word 0x3264 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x023C\n"  /* mov.b @(r0,r3),r2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3268\n"  /* sub r6,r2 */
    ".word 0x5694\n"  /* mov.l @(0x10,r9),r6 */
    ".word 0x5796\n"  /* mov.l @(0x18,r9),r7 */
    ".word 0x5BA4\n"  /* mov.l @(0x10,r10),r11 */
    ".word 0x5CA6\n"  /* mov.l @(0x18,r10),r12 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x3578\n"  /* sub r7,r5 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0602E80C] = 0x0602744C} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E7D4, \"ax\"\n"

    ".global _FUN_0602E7D4\n"
    ".type _FUN_0602E7D4, @function\n"
    "_FUN_0602E7D4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6D0B\n"  /* neg r0,r13 */
    ".word 0x6DDF\n"  /* exts.w r13,r13 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x9412\n"  /* mov.w @(0x24,PC),r4 */
    ".word 0x519A\n"  /* mov.l @(0x28,r9),r1 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x66DD\n"  /* extu.w r13,r6 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x263B\n"  /* or r3,r6 */
    ".word 0x3168\n"  /* sub r6,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8900\n"  /* bt 0x0602E7F8 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0xD705\n"  /* mov.l @(0x14,PC),r7  {[0x0602E810] = 0x06078663} */
    ".word 0x6770\n"  /* mov.b @r7,r7 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B09\n"  /* bf 0x0602E814 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x892E\n"  /* bt 0x0602E864 */
    ".word 0xA008\n"  /* bra 0x0602E81A */
    ".word 0x0009\n"  /* nop */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x744C\n"  /* add #76,r4 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8663\n"  /* .word 0x8663 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8B24\n"  /* bf 0x0602E864 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0602E834] = 0x00000050} */
    ".word 0x3833\n"  /* cmp/ge r3,r8 */
    ".word 0x8911\n"  /* bt 0x0602E844 */
    ".word 0xD405\n"  /* mov.l @(0x14,PC),r4  {[0x0602E838] = 0x00000000} */
    ".word 0xD506\n"  /* mov.l @(0x18,PC),r5  {[0x0602E83C] = 0xAE1106FF} */
    ".word 0xDD06\n"  /* mov.l @(0x18,PC),r13  {[0x0602E840] = 0x0601D5F4} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E826, \"ax\"\n"

    ".global _FUN_0602E826\n"
    ".type _FUN_0602E826, @function\n"
    "_FUN_0602E826:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xAFAD\n"  /* bra 0x0602E78C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0050\n"  /* .word 0x0050 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x0602E462 */
    ".word 0x06FF\n"  /* mac.l @r15+,@r6+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0602EC14] = 0x00000010} */
    ".word 0xD404\n"  /* mov.l @(0x10,PC),r4  {[0x0602E858] = 0x00000000} */
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x0602E85C] = 0xAE110AFF} */
    ".word 0xDD05\n"  /* mov.l @(0x14,PC),r13  {[0x0602E860] = 0x0601D5F4} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E84A, \"ax\"\n"

    ".global _FUN_0602E84A\n"
    ".type _FUN_0602E84A, @function\n"
    "_FUN_0602E84A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xAF9B\n"  /* bra 0x0602E78C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x0602E482 */
    ".word 0x0AFF\n"  /* mac.l @r15+,@r10+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0602EC34] = 0x00000010} */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x0602E87C] = 0x00000050} */
    ".word 0x3833\n"  /* cmp/ge r3,r8 */
    ".word 0x8910\n"  /* bt 0x0602E88C */
    ".word 0xD405\n"  /* mov.l @(0x14,PC),r4  {[0x0602E880] = 0x00000000} */
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x0602E884] = 0xAE1105FF} */
    ".word 0xDD06\n"  /* mov.l @(0x18,PC),r13  {[0x0602E888] = 0x0601D5F4} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E870, \"ax\"\n"

    ".global _FUN_0602E870\n"
    ".type _FUN_0602E870, @function\n"
    "_FUN_0602E870:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xAF88\n"  /* bra 0x0602E78C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0050\n"  /* .word 0x0050 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x0602E4AA */
    ".word 0x05FF\n"  /* mac.l @r15+,@r5+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0602EC5C] = 0x00000000} */
    ".word 0xD404\n"  /* mov.l @(0x10,PC),r4  {[0x0602E8A0] = 0x00000000} */
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x0602E8A4] = 0xAE1109FF} */
    ".word 0xDD05\n"  /* mov.l @(0x14,PC),r13  {[0x0602E8A8] = 0x0601D5F4} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602E892, \"ax\"\n"

    ".global _FUN_0602E892\n"
    ".type _FUN_0602E892, @function\n"
    "_FUN_0602E892:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xAF77\n"  /* bra 0x0602E78C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x0602E4CA */
    ".word 0x09FF\n"  /* mac.l @r15+,@r9+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0602EC7C] = 0x000000D0} */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x0BD4\n"  /* mov.b r13,@(r0,r11) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x0C44\n"  /* mov.b r4,@(r0,r12) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x0CB4\n"  /* mov.b r11,@(r0,r12) */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE666\n"  /* mov #102,r6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xCCCC\n"  /* .word 0xCCCC */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xB333\n"  /* bsr 0x0602EF48 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8D4F\n"  /* bt/s 0x0602E9DA */
    ".word 0x68F5\n"  /* mov.w @r15+,r8 */
    ".word 0x5000\n"  /* mov.l @(0x0,r0),r0 */
    ".word 0x527A\n"  /* mov.l @(0x28,r7),r2 */
    ".word 0x8D4F\n"  /* bt/s 0x0602E9E2 */
    ".word 0x68F5\n"  /* mov.w @r15+,r8 */
    ".word 0x5000\n"  /* mov.l @(0x0,r0),r0 */
    ".word 0x527A\n"  /* mov.l @(0x28,r7),r2 */
    ".word 0xFD4F\n"  /* .word 0xFD4F */
    ".word 0xC8F5\n"  /* tst #0xF5,r0 */
    ".word 0x81EB\n"  /* mov.w r0,@(0x16,r14) */
    ".word 0x8500\n"  /* mov.w @(0x0,r0),r0 */
    ".word 0xFD4F\n"  /* .word 0xFD4F */
    ".word 0xC8F5\n"  /* tst #0xF5,r0 */
    ".word 0x81EB\n"  /* mov.w r0,@(0x16,r14) */
    ".word 0x8500\n"  /* mov.w @(0x0,r0),r0 */
    ".word 0xED4F\n"  /* mov #79,r13 */
    ".word 0xD8F5\n"  /* mov.l @(0x3D4,PC),r8  {[0x0602ED30] = 0xE3000236} */
    ".word 0x9000\n"  /* mov.w @(0x0,PC),r0 */
    ".word 0x717A\n"  /* add #122,r1 */
    ".word 0xED4F\n"  /* mov #79,r13 */
    ".word 0xD8F5\n"  /* mov.l @(0x3D4,PC),r8  {[0x0602ED38] = 0x923C4328} */
    ".word 0x9000\n"  /* mov.w @(0x0,PC),r0 */
    ".word 0x717A\n"  /* add #122,r1 */
    ".word 0xCD4F\n"  /* .word 0xCD4F */
    ".word 0x98F5\n"  /* mov.w @(0x1EA,PC),r8 */
    ".word 0x81EB\n"  /* mov.w r0,@(0x16,r14) */
    ".word 0x847A\n"  /* mov.b @(0xA,r7),r0 */
    ".word 0xCD4F\n"  /* .word 0xCD4F */
    ".word 0x98F5\n"  /* mov.w @(0x1EA,PC),r8 */
    ".word 0x81EB\n"  /* mov.w r0,@(0x16,r14) */
    ".word 0x847A\n"  /* mov.b @(0xA,r7),r0 */
    ".word 0x8D4F\n"  /* bt/s 0x0602EA1A */
    ".word 0x68F5\n"  /* mov.w @r15+,r8 */
    ".word 0x51EB\n"  /* mov.l @(0x2C,r14),r1 */
    ".word 0x547A\n"  /* mov.l @(0x28,r7),r4 */
    ".word 0x8D4F\n"  /* bt/s 0x0602EA22 */
    ".word 0x68F5\n"  /* mov.w @r15+,r8 */
    ".word 0x51EB\n"  /* mov.l @(0x2C,r14),r1 */
    ".word 0x547A\n"  /* mov.l @(0x28,r7),r4 */
    ".word 0xCD4F\n"  /* .word 0xCD4F */
    ".word 0xC8F5\n"  /* tst #0xF5,r0 */
    ".word 0xA1EB\n"  /* bra 0x0602ED66 */
    ".word 0x847A\n"  /* mov.b @(0xA,r7),r0 */
    ".word 0xCD4F\n"  /* .word 0xCD4F */
    ".word 0xC8F5\n"  /* tst #0xF5,r0 */
    ".word 0xA1EB\n"  /* bra 0x0602ED6E */
    ".word 0x847A\n"  /* mov.b @(0xA,r7),r0 */
    ".word 0x8D4F\n"  /* bt/s 0x0602EA3A */
    ".word 0x68F5\n"  /* mov.w @r15+,r8 */
    ".word 0x5000\n"  /* mov.l @(0x0,r0),r0 */
    ".word 0x517A\n"  /* mov.l @(0x28,r7),r1 */
    ".word 0x8D4F\n"  /* bt/s 0x0602EA42 */
    ".word 0x68F5\n"  /* mov.w @r15+,r8 */
    ".word 0x5000\n"  /* mov.l @(0x0,r0),r0 */
    ".word 0x517A\n"  /* mov.l @(0x28,r7),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x0602E9DC] = 0x00003C00} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x3C00\n"  /* cmp/eq r0,r12 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0016\n"  /* mov.l r1,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2800\n"  /* mov.b r0,@r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x9800\n"  /* mov.w @(0x0,PC),r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD200\n"  /* mov.l @(0x0,PC),r2  {[0x0602EA3C] = 0x00006800} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x6800\n"  /* mov.b @r0,r8 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x0602EA5C] = 0x0000B000} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xB000\n"  /* bsr 0x0602EA62 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x1800\n"  /* mov.l r0,@(0x0,r8) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF300\n"  /* .word 0xF300 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x0602EAC0] = 0x00007C00} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7C00\n"  /* add #0,r12 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xA000\n"  /* bra 0x0602EAE6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xB000\n"  /* bsr 0x0602EB06 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x6800\n"  /* mov.b @r0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2800\n"  /* mov.b r0,@r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD200\n"  /* mov.l @(0x0,PC),r2  {[0x0602EB20] = 0x0000A800} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xA800\n"  /* bra 0x0602DB26 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x0602EB40] = 0x0000F000} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x1800\n"  /* mov.l r0,@(0x0,r8) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF300\n"  /* .word 0xF300 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x0602EBA4] = 0x0000AF33} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAF33\n"  /* bra 0x0602EA10 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0016\n"  /* mov.l r1,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD333\n"  /* mov.l @(0xCC,PC),r3  {[0x0602EC94] = 0x00000040} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE333\n"  /* mov #51,r3 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xD800\n"  /* mov.l @(0x0,PC),r8  {[0x0602EBFC] = 0xFFFF3800} */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x3800\n"  /* cmp/eq r0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD200\n"  /* mov.l @(0x0,PC),r2  {[0x0602EC04] = 0x0000DB33} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xDB33\n"  /* mov.l @(0xCC,PC),r11  {[0x0602ECD4] = 0x430ED305} */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xF800\n"  /* .word 0xF800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD000\n"  /* mov.l @(0x0,PC),r0  {[0x0602EC24] = 0x00012333} */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x2333\n"  /* .word 0x2333 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x3800\n"  /* cmp/eq r0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF300\n"  /* .word 0xF300 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x3333\n"  /* cmp/ge r3,r3 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0050\n"  /* .word 0x0050 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xF800\n"  /* .word 0xF800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x3800\n"  /* cmp/eq r0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7800\n"  /* add #0,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xE9A8\n"  /* mov #-88,r9 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEA8C\n"  /* mov #-116,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEB70\n"  /* mov #112,r11 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEA8C\n"  /* mov #-116,r10 */
    ".global _FUN_0602eccc\n"
    "_FUN_0602eccc:\n"
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xE3F0\n"  /* mov #-16,r3 */
    ".word 0x4F03\n"  /* .word 0x4F03 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x430E\n"  /* ldc r3,sr */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x0602ECEC] = 0xFFFFFF00} */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x1311\n"  /* mov.l r1,@(0x4,r3) */
    ".word 0x0009\n"  /* nop */
    ".word 0x5035\n"  /* mov.l @(0x14,r3),r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F07\n"  /* .word 0x4F07 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6103\n"  /* mov r0,r1 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".global _FUN_0602ecf2\n"
    "_FUN_0602ecf2:\n"
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x0602ED04] = 0x0607EAE4} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0602ED08] = 0x0602ED0C} */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE4\n"  /* mov #-28,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xED0C\n"  /* mov #12,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xED18\n"  /* mov #24,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xED18\n"  /* mov #24,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEEAC\n"  /* mov #-84,r14 */
    ".word 0xD02A\n"  /* mov.l @(0xA8,PC),r0  {[0x0602EDC4] = 0x0602FDA1} */
    ".word 0xE150\n"  /* mov #80,r1 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0xD02A\n"  /* mov.l @(0xA8,PC),r0  {[0x0602EDC8] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD12A\n"  /* mov.l @(0xA8,PC),r1  {[0x0602EDCC] = 0x0607EAE4} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x5202\n"  /* mov.l @(0x8,r0),r2 */
    ".word 0x4228\n"  /* shll16 r2 */
    ".word 0x923F\n"  /* mov.w @(0x7E,PC),r2 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x0236\n"  /* mov.l r3,@(r0,r2) */
    ".word 0x913D\n"  /* mov.w @(0x7A,PC),r1 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x923C\n"  /* mov.w @(0x78,PC),r2 */
    ".word 0x4328\n"  /* shll16 r3 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0236\n"  /* mov.l r3,@(r0,r2) */
    ".word 0x9139\n"  /* mov.w @(0x72,PC),r1 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0x1131\n"  /* mov.l r3,@(0x4,r1) */
    ".word 0x1132\n"  /* mov.l r3,@(0x8,r1) */
    ".word 0x1133\n"  /* mov.l r3,@(0xC,r1) */
    ".word 0x9133\n"  /* mov.w @(0x66,PC),r1 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0602EDD0] = 0xFFFF0000} */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x2132\n"  /* mov.l r3,@r1 */
    ".word 0x9230\n"  /* mov.w @(0x60,PC),r2 */
    ".word 0xD11E\n"  /* mov.l @(0x78,PC),r1  {[0x0602EDD4] = 0x0602EE90} */
    ".word 0x022D\n"  /* mov.w @(r0,r2),r2 */
    ".word 0x932E\n"  /* mov.w @(0x5C,PC),r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x6414\n"  /* mov.b @r1+,r4 */
    ".word 0x2340\n"  /* mov.b r4,@r3 */
    ".word 0x6410\n"  /* mov.b @r1,r4 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2340\n"  /* mov.b r4,@r3 */
    ".word 0xD11A\n"  /* mov.l @(0x68,PC),r1  {[0x0602EDD8] = 0x0602EDE8} */
    ".word 0x9325\n"  /* mov.w @(0x4A,PC),r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x0316\n"  /* mov.l r1,@(r0,r3) */
    ".word 0x9121\n"  /* mov.w @(0x42,PC),r1 */
    ".word 0x041D\n"  /* mov.w @(r0,r1),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0xD116\n"  /* mov.l @(0x58,PC),r1  {[0x0602EDDC] = 0x0602EE20} */
    ".word 0x8900\n"  /* bt 0x0602ED86 */
    ".word 0xD116\n"  /* mov.l @(0x58,PC),r1  {[0x0602EDE0] = 0x0602EE58} */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x6215\n"  /* mov.w @r1+,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x6211\n"  /* mov.w @r1,r2 */
    ".word 0x7302\n"  /* add #2,r3 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602EDA2, \"ax\"\n"

    ".global _FUN_0602EDA2\n"
    ".type _FUN_0602EDA2, @function\n"
    "_FUN_0602EDA2:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDD0F\n"  /* mov.l @(0x3C,PC),r13  {[0x0602EDE4] = 0x060302C6} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA089\n"  /* bra 0x0602EEC2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x005C\n"  /* mov.b @(r0,r5),r0 */
    ".word 0x0108\n"  /* .word 0x0108 */
    ".word 0x010C\n"  /* mov.b @(r0,r0),r1 */
    ".word 0x0120\n"  /* .word 0x0120 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x007C\n"  /* mov.b @(r0,r7),r0 */
    ".word 0x007E\n"  /* mov.l @(r0,r7),r0 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
    ".word 0x009E\n"  /* mov.l @(r0,r9),r0 */
    ".word 0x00CC\n"  /* mov.b @(r0,r12),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFDA1\n"  /* .word 0xFDA1 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE4\n"  /* mov #-28,r10 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEE90\n"  /* mov #-112,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEDE8\n"  /* mov #-24,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEE20\n"  /* mov #32,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEE58\n"  /* mov #88,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x02C6\n"  /* mov.l r12,@(r0,r2) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x605C\n"  /* extu.b r5,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x5EEC\n"  /* mov.l @(0x30,r14),r14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x61CC\n"  /* extu.b r12,r1 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x661C\n"  /* extu.b r1,r6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x64AC\n"  /* extu.b r10,r4 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x605C\n"  /* extu.b r5,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x5EEC\n"  /* mov.l @(0x30,r14),r14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x661C\n"  /* extu.b r1,r6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x64AC\n"  /* extu.b r10,r4 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x61CC\n"  /* extu.b r12,r1 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x661C\n"  /* extu.b r1,r6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x64AC\n"  /* extu.b r10,r4 */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x1380\n"  /* mov.l r8,@(0x0,r3) */
    ".word 0x1D00\n"  /* mov.l r0,@(0x0,r13) */
    ".word 0x1380\n"  /* mov.l r8,@(0x0,r3) */
    ".word 0x1D00\n"  /* mov.l r0,@(0x0,r13) */
    ".word 0x0F00\n"  /* .word 0x0F00 */
    ".word 0x1200\n"  /* mov.l r0,@(0x0,r2) */
    ".word 0x0F00\n"  /* .word 0x0F00 */
    ".word 0x1200\n"  /* mov.l r0,@(0x0,r2) */
    ".word 0x1600\n"  /* mov.l r0,@(0x0,r6) */
    ".word 0x1700\n"  /* mov.l r0,@(0x0,r7) */
    ".word 0x1600\n"  /* mov.l r0,@(0x0,r6) */
    ".word 0x1700\n"  /* mov.l r0,@(0x0,r7) */
    ".word 0x1700\n"  /* mov.l r0,@(0x0,r7) */
    ".word 0x1540\n"  /* mov.l r4,@(0x0,r5) */
    ".word 0x1700\n"  /* mov.l r0,@(0x0,r7) */
    ".word 0x1540\n"  /* mov.l r4,@(0x0,r5) */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x0F00\n"  /* .word 0x0F00 */
    ".word 0x1200\n"  /* mov.l r0,@(0x0,r2) */
    ".word 0x0F00\n"  /* .word 0x0F00 */
    ".word 0x1200\n"  /* mov.l r0,@(0x0,r2) */
    ".word 0x10C0\n"  /* mov.l r12,@(0x0,r0) */
    ".word 0x0F80\n"  /* .word 0x0F80 */
    ".word 0x10C0\n"  /* mov.l r12,@(0x0,r0) */
    ".word 0x0F80\n"  /* .word 0x0F80 */
    ".word 0x1300\n"  /* mov.l r0,@(0x0,r3) */
    ".word 0x1600\n"  /* mov.l r0,@(0x0,r6) */
    ".word 0x1300\n"  /* mov.l r0,@(0x0,r3) */
    ".word 0x1600\n"  /* mov.l r0,@(0x0,r6) */
    ".word 0x0F20\n"  /* .word 0x0F20 */
    ".word 0x1100\n"  /* mov.l r0,@(0x0,r1) */
    ".word 0x0F20\n"  /* .word 0x0F20 */
    ".word 0x1100\n"  /* mov.l r0,@(0x0,r1) */
    ".word 0x1500\n"  /* mov.l r0,@(0x0,r5) */
    ".word 0x1300\n"  /* mov.l r0,@(0x0,r3) */
    ".word 0x1500\n"  /* mov.l r0,@(0x0,r5) */
    ".word 0x1300\n"  /* mov.l r0,@(0x0,r3) */
    ".word 0x1680\n"  /* mov.l r8,@(0x0,r6) */
    ".word 0x1340\n"  /* mov.l r4,@(0x0,r3) */
    ".word 0x1680\n"  /* mov.l r8,@(0x0,r6) */
    ".word 0x1340\n"  /* mov.l r4,@(0x0,r3) */
    ".word 0x10C0\n"  /* mov.l r12,@(0x0,r0) */
    ".word 0x0F80\n"  /* .word 0x0F80 */
    ".word 0x10C0\n"  /* mov.l r12,@(0x0,r0) */
    ".word 0x0F80\n"  /* .word 0x0F80 */
    ".word 0x0F20\n"  /* .word 0x0F20 */
    ".word 0x1100\n"  /* mov.l r0,@(0x0,r1) */
    ".word 0x0F20\n"  /* .word 0x0F20 */
    ".word 0x1100\n"  /* mov.l r0,@(0x0,r1) */
    ".word 0x0705\n"  /* mov.w r0,@(r0,r7) */
    ".word 0x0705\n"  /* mov.w r0,@(r0,r7) */
    ".word 0x4870\n"  /* .word 0x4870 */
    ".word 0x4870\n"  /* .word 0x4870 */
    ".word 0x0508\n"  /* .word 0x0508 */
    ".word 0x0508\n"  /* .word 0x0508 */
    ".word 0x2830\n"  /* mov.b r3,@r8 */
    ".word 0x2830\n"  /* mov.b r3,@r8 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x4020\n"  /* shal r0 */
    ".word 0x4020\n"  /* shal r0 */
    ".word 0x0502\n"  /* stc sr,r5 */
    ".word 0x0502\n"  /* stc sr,r5 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"
    ".global _per_car_render_pipeline\n"
    ".type _per_car_render_pipeline, @function\n"









    ".section .text.FUN_0602EEB8, \"ax\"\n"

    ".global _FUN_0602EEB8\n"
    "_per_car_render_pipeline:\n"
    "_FUN_0602EEB8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDD10\n"  /* mov.l @(0x40,PC),r13  {[0x0602EF00] = 0x0602FDA4} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD10\n"  /* mov.l @(0x40,PC),r13  {[0x0602EF04] = 0x0602EFF0} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD10F\n"  /* mov.l @(0x3C,PC),r1  {[0x0602EF08] = 0x0607EAC8} */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x9114\n"  /* mov.w @(0x28,PC),r1 */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0x7102\n"  /* add #2,r1 */
    ".word 0x0125\n"  /* mov.w r2,@(r0,r1) */
    ".word 0xDD0D\n"  /* mov.l @(0x34,PC),r13  {[0x0602EF0C] = 0x0602F3EC} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD0C\n"  /* mov.l @(0x30,PC),r13  {[0x0602EF10] = 0x0602F7BC} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD0C\n"  /* mov.l @(0x30,PC),r13  {[0x0602EF14] = 0x0602F0E8} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9108\n"  /* mov.w @(0x10,PC),r1 */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8915\n"  /* bt 0x0602EF1C */
    ".word 0xDD09\n"  /* mov.l @(0x24,PC),r13  {[0x0602EF18] = 0x0602F270} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA014\n"  /* bra 0x0602EF22 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0250\n"  /* .word 0x0250 */
    ".word 0x009C\n"  /* mov.b @(r0,r9),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFDA4\n"  /* .word 0xFDA4 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602EFF0 */
    ".word 0xEFF0\n"  /* mov #-16,r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAC8\n"  /* mov #-56,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF3EC\n"  /* .word 0xF3EC */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF7BC\n"  /* .word 0xF7BC */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF0E8\n"  /* .word 0xF0E8 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602F270 */
    ".word 0xF270\n"  /* .word 0xF270 */
    ".word 0xDD11\n"  /* mov.l @(0x44,PC),r13  {[0x0602EF64] = 0x0602F17C} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD11\n"  /* mov.l @(0x44,PC),r13  {[0x0602EF68] = 0x0602F474} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD10\n"  /* mov.l @(0x40,PC),r13  {[0x0602EF6C] = 0x0602F4B4} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD10\n"  /* mov.l @(0x40,PC),r13  {[0x0602EF70] = 0x0602F5B6} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD0F\n"  /* mov.l @(0x3C,PC),r13  {[0x0602EF74] = 0x0602EFCC} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD0F\n"  /* mov.l @(0x3C,PC),r13  {[0x0602EF78] = 0x0602C690} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD0E\n"  /* mov.l @(0x38,PC),r13  {[0x0602EF7C] = 0x0602C8E2} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD0E\n"  /* mov.l @(0x38,PC),r13  {[0x0602EF80] = 0x0602CA84} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9108\n"  /* mov.w @(0x10,PC),r1 */
    ".word 0xDC0D\n"  /* mov.l @(0x34,PC),r12  {[0x0602EF84] = 0x0602D08A} */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0xDD0D\n"  /* mov.l @(0x34,PC),r13  {[0x0602EF88] = 0x0602D43C} */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8919\n"  /* bt 0x0602EF8C */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA018\n"  /* bra 0x0602EF90 */
    ".word 0x0009\n"  /* nop */
    ".word 0x009E\n"  /* mov.l @(r0,r9),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF17C\n"  /* .word 0xF17C */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF474\n"  /* .word 0xF474 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF4B4\n"  /* .word 0xF4B4 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602F5B6 */
    ".word 0xF5B6\n"  /* .word 0xF5B6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xEFCC\n"  /* mov #-52,r15 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602C690 */
    ".word 0xC690\n"  /* mov.l @(0x240,GBR),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602C8E2 */
    ".word 0xC8E2\n"  /* tst #0xE2,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602CA84 */
    ".word 0xCA84\n"  /* xor #0x84,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602D08A */
    ".word 0xD08A\n"  /* mov.l @(0x228,PC),r0  {[0x0602F1B0] = 0x66623643} */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602D43C */
    ".word 0xD43C\n"  /* mov.l @(0xF0,PC),r4  {[0x0602F07C] = 0x9310213E} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD0A\n"  /* mov.l @(0x28,PC),r13  {[0x0602EFBC] = 0x0602CDF6} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD0A\n"  /* mov.l @(0x28,PC),r13  {[0x0602EFC0] = 0x0602D814} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDD09\n"  /* mov.l @(0x24,PC),r13  {[0x0602EFC4] = 0x0602D8BC} */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x5200\n"  /* mov.l @(0x0,r0),r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0602EFC8] = 0xFFFFFC3F} */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602CDF6 */
    ".word 0xCDF6\n"  /* .word 0xCDF6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xD814\n"  /* mov.l @(0x50,PC),r8  {[0x0602F014] = 0x31284111} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xD8BC\n"  /* mov.l @(0x2F0,PC),r8  {[0x0602F2B8] = 0x32308947} */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFC3F\n"  /* .word 0xFC3F */
    ".word 0x5409\n"  /* mov.l @(0x24,r0),r4 */
    ".word 0x950A\n"  /* mov.w @(0x14,PC),r5 */
    ".word 0x960A\n"  /* mov.w @(0x14,PC),r6 */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0x360C\n"  /* add r0,r6 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0xDC04\n"  /* mov.l @(0x10,PC),r12  {[0x0602EFEC] = 0x06027358} */
    ".size _per_car_render_pipeline, .-_per_car_render_pipeline\n"
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602EFDA, \"ax\"\n"

    ".global _FUN_0602EFDA\n"
    ".type _FUN_0602EFDA, @function\n"
    "_FUN_0602EFDA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0104\n"  /* mov.b r0,@(r0,r1) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7358\n"  /* add #88,r3 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602F214, \"ax\"\n"

    ".global _FUN_0602F214\n"
    ".type _FUN_0602F214, @function\n"
    "_FUN_0602F214:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6103\n"  /* mov r0,r1 */
    ".word 0x4129\n"  /* shlr16 r1 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x0816\n"  /* mov.l r1,@(r0,r8) */
    ".word 0x9113\n"  /* mov.w @(0x26,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x9110\n"  /* mov.w @(0x20,PC),r1 */
    ".word 0x051E\n"  /* mov.l @(r0,r1),r5 */
    ".word 0x9110\n"  /* mov.w @(0x20,PC),r1 */
    ".word 0x061E\n"  /* mov.l @(r0,r1),r6 */
    ".word 0x356C\n"  /* add r6,r5 */
    ".word 0x3548\n"  /* sub r4,r5 */
    ".word 0x039D\n"  /* mov.w @(r0,r9),r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0xD708\n"  /* mov.l @(0x20,PC),r7  {[0x0602F25C] = 0x0602F3CC} */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x3517\n"  /* cmp/gt r1,r5 */
    ".word 0x890C\n"  /* bt 0x0602F260 */
    ".word 0x6513\n"  /* mov r1,r5 */
    ".word 0xA00D\n"  /* bra 0x0602F266 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x00E4\n"  /* mov.b r14,@(r0,r0) */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x77CC\n"  /* add #-52,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF3CC\n"  /* .word 0xF3CC */
    ".word 0x3253\n"  /* cmp/ge r5,r2 */
    ".word 0x8900\n"  /* bt 0x0602F266 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0x345C\n"  /* add r5,r4 */
    ".word 0x9101\n"  /* mov.w @(0x2,PC),r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0146\n"  /* mov.l r4,@(r0,r1) */
    ".word 0x00E4\n"  /* mov.b r14,@(r0,r0) */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602F270, \"ax\"\n"

    ".global _FUN_0602F270\n"
    ".type _FUN_0602F270, @function\n"
    "_FUN_0602F270:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x9107\n"  /* mov.w @(0xE,PC),r1 */
    ".word 0x031E\n"  /* mov.l @(r0,r1),r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890E\n"  /* bt 0x0602F298 */
    ".word 0x4311\n"  /* cmp/pz r3 */
    ".word 0x8B03\n"  /* bf 0x0602F286 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0xA00A\n"  /* bra 0x0602F298 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x00D8\n"  /* .word 0x00D8 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x920F\n"  /* mov.w @(0x1E,PC),r2 */
    ".word 0x910F\n"  /* mov.w @(0x1E,PC),r1 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x940D\n"  /* mov.w @(0x1A,PC),r4 */
    ".word 0x3348\n"  /* sub r4,r3 */
    ".word 0x0236\n"  /* mov.l r3,@(r0,r2) */
    ".word 0x910B\n"  /* mov.w @(0x16,PC),r1 */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0x950A\n"  /* mov.w @(0x14,PC),r5 */
    ".word 0x065D\n"  /* mov.w @(r0,r5),r6 */
    ".word 0x3620\n"  /* cmp/eq r2,r6 */
    ".word 0x8953\n"  /* bt 0x0602F34C */
    ".word 0x3627\n"  /* cmp/gt r2,r6 */
    ".word 0x8906\n"  /* bt 0x0602F2B6 */
    ".word 0xA02C\n"  /* bra 0x0602F304 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00C4\n"  /* mov.b r12,@(r0,r0) */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x00FA\n"  /* .word 0x00FA */
    ".word 0x00DC\n"  /* mov.b @(r0,r13),r0 */
    ".word 0x00DE\n"  /* mov.l @(r0,r13),r0 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8947\n"  /* bt 0x0602F34C */
    ".word 0x0165\n"  /* mov.w r6,@(r0,r1) */
    ".word 0x931B\n"  /* mov.w @(0x36,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x4428\n"  /* shll16 r4 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xD80D\n"  /* mov.l @(0x34,PC),r8  {[0x0602F2FC] = 0x060477BC} */
    ".word 0x6983\n"  /* mov r8,r9 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x385C\n"  /* add r5,r8 */
    ".word 0x6782\n"  /* mov.l @r8,r7 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x347D\n"  /* dmuls.l r7,r4 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x395C\n"  /* add r5,r9 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x6592\n"  /* mov.l @r9,r5 */
    ".word 0x247D\n"  /* .word 0x247D */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0602F300] = 0x0602755C} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x4029\n"  /* shlr16 r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xE505\n"  /* mov #5,r5 */
    ".word 0x9102\n"  /* mov.w @(0x4,PC),r1 */
    ".word 0xA02A\n"  /* bra 0x0602F34C */
    ".word 0x0156\n"  /* mov.l r5,@(r0,r1) */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x00D8\n"  /* .word 0x00D8 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x77BC\n"  /* add #-68,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8921\n"  /* bt 0x0602F34C */
    ".word 0x0165\n"  /* mov.w r6,@(r0,r1) */
    ".word 0x933D\n"  /* mov.w @(0x7A,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x4428\n"  /* shll16 r4 */
    ".word 0x6523\n"  /* mov r2,r5 */
    ".word 0xD822\n"  /* mov.l @(0x88,PC),r8  {[0x0602F39C] = 0x060477BC} */
    ".word 0x6983\n"  /* mov r8,r9 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x385C\n"  /* add r5,r8 */
    ".word 0x6782\n"  /* mov.l @r8,r7 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x347D\n"  /* dmuls.l r7,r4 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x395C\n"  /* add r5,r9 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x6592\n"  /* mov.l @r9,r5 */
    ".word 0x247D\n"  /* .word 0x247D */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x0602F3A0] = 0x0602755C} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9329\n"  /* mov.w @(0x52,PC),r3 */
    ".word 0x4029\n"  /* shlr16 r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x9525\n"  /* mov.w @(0x4A,PC),r5 */
    ".word 0x9125\n"  /* mov.w @(0x4A,PC),r1 */
    ".word 0x345C\n"  /* add r5,r4 */
    ".word 0x0146\n"  /* mov.l r4,@(r0,r1) */
    ".word 0xE405\n"  /* mov #5,r4 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x9321\n"  /* mov.w @(0x42,PC),r3 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x9320\n"  /* mov.w @(0x40,PC),r3 */
    ".word 0x911B\n"  /* mov.w @(0x36,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x3347\n"  /* cmp/gt r4,r3 */
    ".word 0x8904\n"  /* bt 0x0602F360 */
    ".word 0xE4FF\n"  /* mov #-1,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x951A\n"  /* mov.w @(0x34,PC),r5 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0546\n"  /* mov.l r4,@(r0,r5) */
    ".word 0x9618\n"  /* mov.w @(0x30,PC),r6 */
    ".word 0x9218\n"  /* mov.w @(0x30,PC),r2 */
    ".word 0x036E\n"  /* mov.l @(r0,r6),r3 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x052E\n"  /* mov.l @(r0,r2),r5 */
    ".word 0x345C\n"  /* add r5,r4 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x9113\n"  /* mov.w @(0x26,PC),r1 */
    ".word 0xD70C\n"  /* mov.l @(0x30,PC),r7  {[0x0602F3A4] = 0x0602F3CC} */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x372C\n"  /* add r2,r7 */
    ".word 0x6872\n"  /* mov.l @r7,r8 */
    ".word 0x5971\n"  /* mov.l @(0x4,r7),r9 */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8912\n"  /* bt 0x0602F3A8 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xA013\n"  /* bra 0x0602F3AE */
    ".word 0x0009\n"  /* nop */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x04E2\n"  /* .word 0x04E2 */
    ".word 0x00C4\n"  /* mov.b r12,@(r0,r0) */
    ".word 0x00D8\n"  /* .word 0x00D8 */
    ".word 0x2134\n"  /* mov.b r3,@-r1 */
    ".word 0x0084\n"  /* mov.b r8,@(r0,r0) */
    ".word 0x00E4\n"  /* mov.b r14,@(r0,r0) */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0x00DC\n"  /* mov.b @(r0,r13),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x77BC\n"  /* add #-68,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xF3CC\n"  /* .word 0xF3CC */
    ".word 0x3943\n"  /* cmp/ge r4,r9 */
    ".word 0x8900\n"  /* bt 0x0602F3AE */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x9904\n"  /* mov.w @(0x8,PC),r9 */
    ".word 0x3387\n"  /* cmp/gt r8,r3 */
    ".word 0x8903\n"  /* bt 0x0602F3C0 */
    ".word 0x6383\n"  /* mov r8,r3 */
    ".word 0xA004\n"  /* bra 0x0602F3C6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2134\n"  /* mov.b r3,@-r1 */
    ".word 0x3933\n"  /* cmp/ge r3,r9 */
    ".word 0x8900\n"  /* bt 0x0602F3C6 */
    ".word 0x6393\n"  /* mov r9,r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0636\n"  /* mov.l r3,@(r0,r6) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFB50\n"  /* .word 0xFB50 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x04B0\n"  /* .word 0x04B0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFDA8\n"  /* .word 0xFDA8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0258\n"  /* .word 0x0258 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFED4\n"  /* .word 0xFED4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFED4\n"  /* .word 0xFED4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".global _FUN_0602f3ec\n"
    "_FUN_0602f3ec:\n"
    ".word 0x5203\n"  /* mov.l @(0xC,r0),r2 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0602F40C] = 0x00480000} */
    ".word 0x332D\n"  /* dmuls.l r2,r3 */
    ".word 0xD407\n"  /* mov.l @(0x1C,PC),r4  {[0x0602F410] = 0x00000158} */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x223D\n"  /* .word 0x223D */
    ".word 0x4229\n"  /* shlr16 r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8907\n"  /* bt 0x0602F414 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0xA008\n"  /* bra 0x0602F41A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0048\n"  /* clrs */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0158\n"  /* .word 0x0158 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8900\n"  /* bt 0x0602F41A */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4209\n"  /* shlr2 r2 */
    ".word 0xD402\n"  /* mov.l @(0x8,PC),r4  {[0x0602F42C] = 0x00000000} */
    ".word 0x3243\n"  /* cmp/ge r4,r2 */
    ".word 0x8904\n"  /* bt 0x0602F430 */
    ".word 0xA00F\n"  /* bra 0x0602F448 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD402\n"  /* mov.l @(0x8,PC),r4  {[0x0602F43C] = 0x00002AAA} */
    ".word 0x3423\n"  /* cmp/ge r2,r4 */
    ".word 0x8904\n"  /* bt 0x0602F440 */
    ".word 0xA007\n"  /* bra 0x0602F448 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2AAA\n"  /* xor r10,r10 */
    ".word 0xD40A\n"  /* mov.l @(0x28,PC),r4  {[0x0602F46C] = 0x00000AAA} */
    ".word 0x3423\n"  /* cmp/ge r2,r4 */
    ".word 0x8900\n"  /* bt 0x0602F448 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x930C\n"  /* mov.w @(0x18,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x9309\n"  /* mov.w @(0x12,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8900\n"  /* bt 0x0602F45A */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x0602F470] = 0x00002AAA} */
    ".word 0x9105\n"  /* mov.w @(0xA,PC),r1 */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0146\n"  /* mov.l r4,@(r0,r1) */
    ".word 0x0048\n"  /* clrs */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0x0050\n"  /* .word 0x0050 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0AAA\n"  /* .word 0x0AAA */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2AAA\n"  /* xor r10,r10 */
    ".global _FUN_0602f474\n"
    "_FUN_0602f474:\n"
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x9117\n"  /* mov.w @(0x2E,PC),r1 */
    ".word 0x031D\n"  /* mov.w @(r0,r1),r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890D\n"  /* bt 0x0602F49C */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0x3368\n"  /* sub r6,r3 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x8907\n"  /* bt 0x0602F49A */
    ".word 0x3360\n"  /* cmp/eq r6,r3 */
    ".word 0x8904\n"  /* bt 0x0602F498 */
    ".word 0xE702\n"  /* mov #2,r7 */
    ".word 0x3370\n"  /* cmp/eq r7,r3 */
    ".word 0x8900\n"  /* bt 0x0602F496 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0xD604\n"  /* mov.l @(0x10,PC),r6  {[0x0602F4B0] = 0x060477D8} */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x9102\n"  /* mov.w @(0x4,PC),r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x00D4\n"  /* mov.b r13,@(r0,r0) */
    ".word 0x0114\n"  /* mov.b r1,@(r0,r1) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x77D8\n"  /* add #-40,r7 */
    ".global _FUN_0602f4b4\n"
    "_FUN_0602f4b4:\n"
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x0602F4C4] = 0x0607EAE0} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8904\n"  /* bt 0x0602F4C8 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x9127\n"  /* mov.w @(0x4E,PC),r1 */
    ".word 0x031D\n"  /* mov.w @(r0,r1),r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B01\n"  /* bf 0x0602F4D4 */
    ".word 0x3368\n"  /* sub r6,r3 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x0602F520] = 0x0607EA98} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0602F524] = 0x0607E948} */
    ".word 0x6632\n"  /* mov.l @r3,r6 */
    ".word 0x921E\n"  /* mov.w @(0x3C,PC),r2 */
    ".word 0x941E\n"  /* mov.w @(0x3C,PC),r4 */
    ".word 0x072E\n"  /* mov.l @(r0,r2),r7 */
    ".word 0x084E\n"  /* mov.l @(r0,r4),r8 */
    ".word 0x921A\n"  /* mov.w @(0x34,PC),r2 */
    ".word 0x941A\n"  /* mov.w @(0x34,PC),r4 */
    ".word 0x6923\n"  /* mov r2,r9 */
    ".word 0x396C\n"  /* add r6,r9 */
    ".word 0x6992\n"  /* mov.l @r9,r9 */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x3A6C\n"  /* add r6,r10 */
    ".word 0x6AA2\n"  /* mov.l @r10,r10 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x6173\n"  /* mov r7,r1 */
    ".word 0x3198\n"  /* sub r9,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8900\n"  /* bt 0x0602F506 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x34A8\n"  /* sub r10,r4 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8900\n"  /* bt 0x0602F510 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x3143\n"  /* cmp/ge r4,r1 */
    ".word 0x8909\n"  /* bt 0x0602F528 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0xA009\n"  /* bra 0x0602F52C */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x00D6\n"  /* mov.l r13,@(r0,r0) */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEA98\n"  /* mov #-104,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE948\n"  /* mov #72,r9 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0xDC10\n"  /* mov.l @(0x40,PC),r12  {[0x0602F578] = 0x001E0000} */
    ".word 0x32C3\n"  /* cmp/ge r12,r2 */
    ".word 0x8935\n"  /* bt 0x0602F5A8 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x3478\n"  /* sub r7,r4 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0x3588\n"  /* sub r8,r5 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x0602F57C] = 0x0602744C} */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602F550, \"ax\"\n"

    ".global _FUN_0602F550\n"
    ".type _FUN_0602F550, @function\n"
    "_FUN_0602F550:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6B0B\n"  /* neg r0,r11 */
    ".word 0x6BBF\n"  /* exts.w r11,r11 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x5C0A\n"  /* mov.l @(0x28,r0),r12 */
    ".word 0x3BC8\n"  /* sub r12,r11 */
    ".word 0xDA05\n"  /* mov.l @(0x14,PC),r10  {[0x0602F580] = 0x00008000} */
    ".word 0x2BA8\n"  /* tst r10,r11 */
    ".word 0x890B\n"  /* bt 0x0602F588 */
    ".word 0xDA04\n"  /* mov.l @(0x10,PC),r10  {[0x0602F584] = 0xFFFF0000} */
    ".word 0xA00B\n"  /* bra 0x0602F58C */
    ".word 0x2BAB\n"  /* or r10,r11 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x744C\n"  /* add #76,r4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xDA05\n"  /* mov.l @(0x14,PC),r10  {[0x0602F5A0] = 0x0000FFFF} */
    ".word 0x2BA9\n"  /* and r10,r11 */
    ".word 0x4B11\n"  /* cmp/pz r11 */
    ".word 0x8900\n"  /* bt 0x0602F592 */
    ".word 0x6BBB\n"  /* neg r11,r11 */
    ".word 0xDA04\n"  /* mov.l @(0x10,PC),r10  {[0x0602F5A4] = 0x0000071C} */
    ".word 0x3BA3\n"  /* cmp/ge r10,r11 */
    ".word 0x8907\n"  /* bt 0x0602F5A8 */
    ".word 0xEC14\n"  /* mov #20,r12 */
    ".word 0xA009\n"  /* bra 0x0602F5B0 */
    ".word 0x01C5\n"  /* mov.w r12,@(r0,r1) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x071C\n"  /* mov.b @(r0,r1),r7 */
    ".word 0x9B04\n"  /* mov.w @(0x8,PC),r11 */
    ".word 0x36BC\n"  /* add r11,r6 */
    ".word 0x4510\n"  /* dt r5 */
    ".word 0x8B99\n"  /* bf 0x0602F4E4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0268\n"  /* .word 0x0268 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602F7F2, \"ax\"\n"

    ".global _FUN_0602F7F2\n"
    ".type _FUN_0602F7F2, @function\n"
    "_FUN_0602F7F2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0xDC15\n"  /* mov.l @(0x54,PC),r12  {[0x0602F84C] = 0x0601D5F4} */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x0602F850] = 0x0607EAD8} */
    ".word 0x9421\n"  /* mov.w @(0x42,PC),r4 */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x0602F854] = 0x0602FD3C} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x6511\n"  /* mov.w @r1,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8935\n"  /* bt 0x0602F87C */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0602F858] = 0x0602FD48} */
    ".word 0x8511\n"  /* mov.w @(0x2,r1),r0 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x6131\n"  /* mov.w @r3,r1 */
    ".word 0x3147\n"  /* cmp/gt r4,r1 */
    ".word 0x8921\n"  /* bt 0x0602F860 */
    ".word 0x8531\n"  /* mov.w @(0x2,r3),r0 */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x891E\n"  /* bt 0x0602F860 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x51E5\n"  /* mov.l @(0x14,r14),r1 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0x3013\n"  /* cmp/ge r1,r0 */
    ".word 0x8927\n"  /* bt 0x0602F87C */
    ".word 0x51E0\n"  /* mov.l @(0x0,r14),r1 */
    ".word 0x9309\n"  /* mov.w @(0x12,PC),r3 */
    ".word 0x2138\n"  /* tst r3,r1 */
    ".word 0x8B23\n"  /* bf 0x0602F87C */
    ".word 0x213B\n"  /* or r3,r1 */
    ".word 0x1E10\n"  /* mov.l r1,@(0x0,r14) */
    ".word 0xD508\n"  /* mov.l @(0x20,PC),r5  {[0x0602F85C] = 0xAE0601FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xA01D\n"  /* bra 0x0602F87C */
    ".word 0x0009\n"  /* nop */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0602FC20] = 0x0602FD60} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD3C\n"  /* .word 0xFD3C */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD48\n"  /* .word 0xFD48 */
    ".word 0xAE06\n"  /* bra 0x0602F46C */
    ".word 0x01FF\n"  /* mac.l @r15+,@r1+ */
    ".word 0x75FF\n"  /* add #-1,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x8BD6\n"  /* bf 0x0602F816 */
    ".word 0x51E0\n"  /* mov.l @(0x0,r14),r1 */
    ".word 0x9311\n"  /* mov.w @(0x22,PC),r3 */
    ".word 0x2138\n"  /* tst r3,r1 */
    ".word 0x8905\n"  /* bt 0x0602F87C */
    ".word 0x6337\n"  /* not r3,r3 */
    ".word 0x2139\n"  /* and r3,r1 */
    ".word 0x1E10\n"  /* mov.l r1,@(0x0,r14) */
    ".word 0xD508\n"  /* mov.l @(0x20,PC),r5  {[0x0602F898] = 0xAE0600FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0x9509\n"  /* mov.w @(0x12,PC),r5 */
    ".word 0x35EC\n"  /* add r14,r5 */
    ".word 0x9308\n"  /* mov.w @(0x10,PC),r3 */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x9407\n"  /* mov.w @(0xE,PC),r4 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8908\n"  /* bt 0x0602F89C */
    ".word 0x6133\n"  /* mov r3,r1 */
    ".word 0xA009\n"  /* bra 0x0602F8A2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x00E4\n"  /* mov.b r14,@(r0,r0) */
    ".word 0x0708\n"  /* .word 0x0708 */
    ".word 0x2134\n"  /* mov.b r3,@-r1 */
    ".word 0xAE06\n"  /* bra 0x0602F4A8 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8900\n"  /* bt 0x0602F8A2 */
    ".word 0x6143\n"  /* mov r4,r1 */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x4118\n"  /* shll8 r1 */
    ".word 0x9008\n"  /* mov.w @(0x10,PC),r0 */
    ".word 0xBA10\n"  /* bsr 0x0602ECCC */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0xE47F\n"  /* mov #127,r4 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x3037\n"  /* cmp/gt r3,r0 */
    ".word 0x8903\n"  /* bt 0x0602F8BC */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xA004\n"  /* bra 0x0602F8C2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x14B4\n"  /* mov.l r11,@(0x10,r4) */
    ".word 0x3407\n"  /* cmp/gt r0,r4 */
    ".word 0x8900\n"  /* bt 0x0602F8C2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xD40A\n"  /* mov.l @(0x28,PC),r4  {[0x0602F8F4] = 0x0605D241} */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0x9110\n"  /* mov.w @(0x20,PC),r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6012\n"  /* mov.l @r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B1C\n"  /* bf 0x0602F910 */
    ".word 0x910C\n"  /* mov.w @(0x18,PC),r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6011\n"  /* mov.w @r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8917\n"  /* bt 0x0602F910 */
    ".word 0x880A\n"  /* cmp/eq #10,r0 */
    ".word 0x8B0D\n"  /* bf 0x0602F900 */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x0602F8F8] = 0xAE111EFF} */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8910\n"  /* bt 0x0602F90C */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x0602F8FC] = 0xAE1142FF} */
    ".word 0xA00E\n"  /* bra 0x0602F90C */
    ".word 0x0009\n"  /* nop */
    ".word 0x01BC\n"  /* mov.b @(r0,r11),r1 */
    ".word 0x0166\n"  /* mov.l r6,@(r0,r1) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD241\n"  /* mov.l @(0x104,PC),r2  {[0x0602F9FC] = 0x2D008800} */
    ".word 0xAE11\n"  /* bra 0x0602F51E */
    ".word 0x1EFF\n"  /* mov.l r15,@(0x3C,r14) */
    ".word 0xAE11\n"  /* bra 0x0602F522 */
    ".word 0x42FF\n"  /* mac.w @r15+,@r2+ */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0xD520\n"  /* mov.l @(0x80,PC),r5  {[0x0602F984] = 0xAE111CFF} */
    ".word 0x8B04\n"  /* bf 0x0602F910 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8900\n"  /* bt 0x0602F90C */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x0602F988] = 0xAE1140FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x0602F98C] = 0x0605D241} */
    ".word 0x6140\n"  /* mov.b @r4,r1 */
    ".word 0x9333\n"  /* mov.w @(0x66,PC),r3 */
    ".word 0x33EC\n"  /* add r14,r3 */
    ".word 0xE52C\n"  /* mov #44,r5 */
    ".word 0x6432\n"  /* mov.l @r3,r4 */
    ".word 0x3540\n"  /* cmp/eq r4,r5 */
    ".word 0x8B05\n"  /* bf 0x0602F92C */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0602F990] = 0xAE111BFF} */
    ".word 0x8900\n"  /* bt 0x0602F928 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0602F994] = 0xAE113FFF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0602F998] = 0x0602FD9F} */
    ".word 0x6030\n"  /* mov.b @r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8904\n"  /* bt 0x0602F93E */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x8D0C\n"  /* bt/s 0x0602F956 */
    ".word 0x2300\n"  /* mov.b r0,@r3 */
    ".word 0x50E3\n"  /* mov.l @(0xC,r14),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890A\n"  /* bt 0x0602F95A */
    ".word 0x901C\n"  /* mov.w @(0x38,PC),r0 */
    ".word 0xE4C8\n"  /* mov #-56,r4 */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x3453\n"  /* cmp/ge r5,r4 */
    ".word 0x8904\n"  /* bt 0x0602F95A */
    ".word 0xE40A\n"  /* mov #10,r4 */
    ".word 0x2340\n"  /* mov.b r4,@r3 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE403\n"  /* mov #3,r4 */
    ".word 0x9012\n"  /* mov.w @(0x24,PC),r0 */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0x4511\n"  /* cmp/pz r5 */
    ".word 0x8900\n"  /* bt 0x0602F964 */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0x4519\n"  /* shlr8 r5 */
    ".word 0xE307\n"  /* mov #7,r3 */
    ".word 0x4509\n"  /* shlr2 r5 */
    ".word 0x3353\n"  /* cmp/ge r5,r3 */
    ".word 0x8900\n"  /* bt 0x0602F970 */
    ".word 0xE507\n"  /* mov #7,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0084\n"  /* mov.b r8,@(r0,r0) */
    ".word 0x005C\n"  /* mov.b @(r0,r5),r0 */
    ".word 0xAE11\n"  /* bra 0x0602F5AA */
    ".word 0x1CFF\n"  /* mov.l r15,@(0x3C,r12) */
    ".word 0xAE11\n"  /* bra 0x0602F5AE */
    ".word 0x40FF\n"  /* mac.w @r15+,@r0+ */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD241\n"  /* mov.l @(0x104,PC),r2  {[0x0602FA94] = 0xD5082448} */
    ".word 0xAE11\n"  /* bra 0x0602F5B6 */
    ".word 0x1BFF\n"  /* mov.l r15,@(0x3C,r11) */
    ".word 0xAE11\n"  /* bra 0x0602F5BA */
    ".word 0x3FFF\n"  /* .word 0x3FFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD9F\n"  /* .word 0xFD9F */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602F9A6, \"ax\"\n"

    ".global _FUN_0602F9A6\n"
    ".type _FUN_0602F9A6, @function\n"
    "_FUN_0602F9A6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0xDC18\n"  /* mov.l @(0x60,PC),r12  {[0x0602FA0C] = 0x0601D5F4} */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xDD18\n"  /* mov.l @(0x60,PC),r13  {[0x0602FA10] = 0x0602FD98} */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8906\n"  /* bt 0x0602F9C4 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8F03\n"  /* bf/s 0x0602F9C4 */
    ".word 0x2D00\n"  /* mov.b r0,@r13 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x0602FA14] = 0xAE1103FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x84D1\n"  /* mov.b @(0x1,r13),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8906\n"  /* bt 0x0602F9D8 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8F03\n"  /* bf/s 0x0602F9D8 */
    ".word 0x80D1\n"  /* mov.b r0,@(0x1,r13) */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x0602FA18] = 0xAE1104FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x84D2\n"  /* mov.b @(0x2,r13),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8906\n"  /* bt 0x0602F9EC */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8F03\n"  /* bf/s 0x0602F9EC */
    ".word 0x80D2\n"  /* mov.b r0,@(0x2,r13) */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x0602FA18] = 0xAE1104FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xDD0B\n"  /* mov.l @(0x2C,PC),r13  {[0x0602FA1C] = 0x0602FD9B} */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8919\n"  /* bt 0x0602FA28 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0xD509\n"  /* mov.l @(0x24,PC),r5  {[0x0602FA20] = 0xAE1110FF} */
    ".word 0x8D20\n"  /* bt/s 0x0602FA3E */
    ".word 0x2D00\n"  /* mov.b r0,@r13 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0xD508\n"  /* mov.l @(0x20,PC),r5  {[0x0602FA24] = 0xAE1111FF} */
    ".word 0x891C\n"  /* bt 0x0602FA3E */
    ".word 0xA01D\n"  /* bra 0x0602FA42 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0602FDE0] = 0x93088B1B} */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD98\n"  /* .word 0xFD98 */
    ".word 0xAE11\n"  /* bra 0x0602F63A */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".word 0xAE11\n"  /* bra 0x0602F63E */
    ".word 0x04FF\n"  /* mac.l @r15+,@r4+ */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD9B\n"  /* .word 0xFD9B */
    ".word 0xAE11\n"  /* bra 0x0602F646 */
    ".word 0x10FF\n"  /* mov.l r15,@(0x3C,r0) */
    ".word 0xAE11\n"  /* bra 0x0602F64A */
    ".word 0x11FF\n"  /* mov.l r15,@(0x3C,r1) */
    ".word 0x84D1\n"  /* mov.b @(0x1,r13),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8909\n"  /* bt 0x0602FA42 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x0602FA64] = 0xAE1112FF} */
    ".word 0x8D03\n"  /* bt/s 0x0602FA3E */
    ".word 0x80D1\n"  /* mov.b r0,@(0x1,r13) */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0xD50B\n"  /* mov.l @(0x2C,PC),r5  {[0x0602FA68] = 0xAE1113FF} */
    ".word 0x8B01\n"  /* bf 0x0602FA42 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x0602FA6C] = 0x0607EAD8} */
    ".word 0x940C\n"  /* mov.w @(0x18,PC),r4 */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x8B2A\n"  /* bf 0x0602FAA6 */
    ".word 0xDD07\n"  /* mov.l @(0x1C,PC),r13  {[0x0602FA70] = 0x0602FD9D} */
    ".word 0xE51E\n"  /* mov #30,r5 */
    ".word 0x61D0\n"  /* mov.b @r13,r1 */
    ".word 0x84D1\n"  /* mov.b @(0x1,r13),r0 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8B0B\n"  /* bf 0x0602FA74 */
    ".word 0xA021\n"  /* bra 0x0602FAA2 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x0602F68A */
    ".word 0x12FF\n"  /* mov.l r15,@(0x3C,r2) */
    ".word 0xAE11\n"  /* bra 0x0602F68E */
    ".word 0x13FF\n"  /* mov.l r15,@(0x3C,r3) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD9D\n"  /* .word 0xFD9D */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8909\n"  /* bt 0x0602FA8C */
    ".word 0x3543\n"  /* cmp/ge r4,r5 */
    ".word 0x8B07\n"  /* bf 0x0602FA8C */
    ".word 0xD502\n"  /* mov.l @(0x8,PC),r5  {[0x0602FA88] = 0xAE1119FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE014\n"  /* mov #20,r0 */
    ".word 0xA00D\n"  /* bra 0x0602FAA2 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0xAE11\n"  /* bra 0x0602F6AE */
    ".word 0x19FF\n"  /* mov.l r15,@(0x3C,r9) */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x8908\n"  /* bt 0x0602FAA2 */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x0602FAB4] = 0x0605D241} */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0xD508\n"  /* mov.l @(0x20,PC),r5  {[0x0602FAB8] = 0xAE111AFF} */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8900\n"  /* bt 0x0602FA9C */
    ".word 0xD508\n"  /* mov.l @(0x20,PC),r5  {[0x0602FABC] = 0xAE113EFF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0x2D10\n"  /* mov.b r1,@r13 */
    ".word 0x80D1\n"  /* mov.b r0,@(0x1,r13) */
    ".word 0xDD06\n"  /* mov.l @(0x18,PC),r13  {[0x0602FAC0] = 0x06086054} */
    ".word 0x61D1\n"  /* mov.w @r13,r1 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x890A\n"  /* bt 0x0602FAC4 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0xA138\n"  /* bra 0x0602FD24 */
    ".word 0x2D11\n"  /* mov.w r1,@r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD241\n"  /* mov.l @(0x104,PC),r2  {[0x0602FBBC] = 0x8B08D503} */
    ".word 0xAE11\n"  /* bra 0x0602F6DE */
    ".word 0x1AFF\n"  /* mov.l r15,@(0x3C,r10) */
    ".word 0xAE11\n"  /* bra 0x0602F6E2 */
    ".word 0x3EFF\n"  /* .word 0x3EFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6054\n"  /* mov.b @r5+,r0 */
    ".word 0x50E0\n"  /* mov.l @(0x0,r14),r0 */
    ".word 0xE108\n"  /* mov #8,r1 */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x8901\n"  /* bt 0x0602FAD0 */
    ".word 0xA12A\n"  /* bra 0x0602FD24 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD110\n"  /* mov.l @(0x40,PC),r1  {[0x0602FB14] = 0x0607EAE0} */
    ".word 0x6412\n"  /* mov.l @r1,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B6D\n"  /* bf 0x0602FBB4 */
    ".word 0xD10F\n"  /* mov.l @(0x3C,PC),r1  {[0x0602FB18] = 0x0607EA98} */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x0602FB1C] = 0x0607E948} */
    ".word 0x6512\n"  /* mov.l @r1,r5 */
    ".word 0x75FF\n"  /* add #-1,r5 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0602FB20] = 0x01800000} */
    ".word 0x5140\n"  /* mov.l @(0x0,r4),r1 */
    ".word 0x2139\n"  /* and r3,r1 */
    ".word 0x3310\n"  /* cmp/eq r1,r3 */
    ".word 0x891D\n"  /* bt 0x0602FB2C */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0602FB24] = 0x01400000} */
    ".word 0x5140\n"  /* mov.l @(0x0,r4),r1 */
    ".word 0x2139\n"  /* and r3,r1 */
    ".word 0x3310\n"  /* cmp/eq r1,r3 */
    ".word 0x8918\n"  /* bt 0x0602FB2C */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0602FB28] = 0x02C00000} */
    ".word 0x5140\n"  /* mov.l @(0x0,r4),r1 */
    ".word 0x2139\n"  /* and r3,r1 */
    ".word 0x3310\n"  /* cmp/eq r1,r3 */
    ".word 0x8B00\n"  /* bf 0x0602FB06 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x4510\n"  /* dt r5 */
    ".word 0x9302\n"  /* mov.w @(0x4,PC),r3 */
    ".word 0x892F\n"  /* bt 0x0602FB6C */
    ".word 0xAFEB\n"  /* bra 0x0602FAE6 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x0268\n"  /* .word 0x0268 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEA98\n"  /* mov #-104,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE948\n"  /* mov #72,r9 */
    ".word 0x0180\n"  /* .word 0x0180 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02C0\n"  /* .word 0x02C0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8905\n"  /* bt 0x0602FB3E */
    ".word 0x4510\n"  /* dt r5 */
    ".word 0x9302\n"  /* mov.w @(0x4,PC),r3 */
    ".word 0x8919\n"  /* bt 0x0602FB6C */
    ".word 0xAFD5\n"  /* bra 0x0602FAE6 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x0268\n"  /* .word 0x0268 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x0602FB4C] = 0x0602FDA1} */
    ".word 0x6530\n"  /* mov.b @r3,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8904\n"  /* bt 0x0602FB50 */
    ".word 0x75FF\n"  /* add #-1,r5 */
    ".word 0xA034\n"  /* bra 0x0602FBB4 */
    ".word 0x2350\n"  /* mov.b r5,@r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFDA1\n"  /* .word 0xFDA1 */
    ".word 0x5543\n"  /* mov.l @(0xC,r4),r5 */
    ".word 0x50E3\n"  /* mov.l @(0xC,r14),r0 */
    ".word 0x3053\n"  /* cmp/ge r5,r0 */
    ".word 0x8B2D\n"  /* bf 0x0602FBB4 */
    ".word 0xE50A\n"  /* mov #10,r5 */
    ".word 0x2350\n"  /* mov.b r5,@r3 */
    ".word 0xD502\n"  /* mov.l @(0x8,PC),r5  {[0x0602FB68] = 0xAE1135FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA0DE\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0xAE11\n"  /* bra 0x0602F78E */
    ".word 0x35FF\n"  /* .word 0x35FF */
    ".word 0x4615\n"  /* cmp/pl r6 */
    ".word 0x8B21\n"  /* bf 0x0602FBB4 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x0602FB80] = 0x0602FDA0} */
    ".word 0x6530\n"  /* mov.b @r3,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8905\n"  /* bt 0x0602FB84 */
    ".word 0x75FF\n"  /* add #-1,r5 */
    ".word 0xA01B\n"  /* bra 0x0602FBB4 */
    ".word 0x2350\n"  /* mov.b r5,@r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFDA0\n"  /* .word 0xFDA0 */
    ".word 0x5043\n"  /* mov.l @(0xC,r4),r0 */
    ".word 0x55E3\n"  /* mov.l @(0xC,r14),r5 */
    ".word 0x3058\n"  /* sub r5,r0 */
    ".word 0x950D\n"  /* mov.w @(0x1A,PC),r5 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0x8B10\n"  /* bf 0x0602FBB4 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x0602FBAC] = 0xAE113AFF} */
    ".word 0x8900\n"  /* bt 0x0602FB9A */
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x0602FBB0] = 0xAE1130FF} */
    ".word 0xE003\n"  /* mov #3,r0 */
    ".word 0x2300\n"  /* mov.b r0,@r3 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA0BE\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0x8E38\n"  /* .word 0x8E38 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x0602F7D2 */
    ".word 0x3AFF\n"  /* .word 0x3AFF */
    ".word 0xAE11\n"  /* bra 0x0602F7D6 */
    ".word 0x30FF\n"  /* .word 0x30FF */
    ".word 0x9009\n"  /* mov.w @(0x12,PC),r0 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0x3310\n"  /* cmp/eq r1,r3 */
    ".word 0x8B08\n"  /* bf 0x0602FBD0 */
    ".word 0xD503\n"  /* mov.l @(0xC,PC),r5  {[0x0602FBCC] = 0xAE1132FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA0AD\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0x01BC\n"  /* mov.b @(r0,r11),r1 */
    ".word 0xAE11\n"  /* bra 0x0602F7F2 */
    ".word 0x32FF\n"  /* .word 0x32FF */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x0602FBE8] = 0x0602FD9B} */
    ".word 0x6034\n"  /* mov.b @r3+,r0 */
    ".word 0x6530\n"  /* mov.b @r3,r5 */
    ".word 0x305C\n"  /* add r5,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B09\n"  /* bf 0x0602FBF0 */
    ".word 0xD503\n"  /* mov.l @(0xC,PC),r5  {[0x0602FBEC] = 0xAE1137FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA09E\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD9B\n"  /* .word 0xFD9B */
    ".word 0xAE11\n"  /* bra 0x0602F812 */
    ".word 0x37FF\n"  /* .word 0x37FF */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602FC18] = 0x0607EAD8} */
    ".word 0xD40A\n"  /* mov.l @(0x28,PC),r4  {[0x0602FC1C] = 0x0602FD54} */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x900B\n"  /* mov.w @(0x16,PC),r0 */
    ".word 0x6341\n"  /* mov.w @r4,r3 */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0xD607\n"  /* mov.l @(0x1C,PC),r6  {[0x0602FC20] = 0x0602FD60} */
    ".word 0x360C\n"  /* add r0,r6 */
    ".word 0x6765\n"  /* mov.w @r6+,r7 */
    ".word 0x3570\n"  /* cmp/eq r7,r5 */
    ".word 0x890B\n"  /* bt 0x0602FC24 */
    ".word 0x4310\n"  /* dt r3 */
    ".word 0x8957\n"  /* bt 0x0602FCC0 */
    ".word 0xAFF9\n"  /* bra 0x0602FC06 */
    ".word 0x7602\n"  /* add #2,r6 */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD54\n"  /* .word 0xFD54 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD60\n"  /* .word 0xFD60 */
    ".word 0x6061\n"  /* mov.w @r6,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8928\n"  /* bt 0x0602FC7C */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x893A\n"  /* bt 0x0602FCA4 */
    ".word 0x911E\n"  /* mov.w @(0x3C,PC),r1 */
    ".word 0x921E\n"  /* mov.w @(0x3C,PC),r2 */
    ".word 0x931E\n"  /* mov.w @(0x3C,PC),r3 */
    ".word 0x941E\n"  /* mov.w @(0x3C,PC),r4 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x32EC\n"  /* add r14,r2 */
    ".word 0x33EC\n"  /* add r14,r3 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x6111\n"  /* mov.w @r1,r1 */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B37\n"  /* bf 0x0602FCC0 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x0602FC78] = 0x0602FD30} */
    ".word 0x9B10\n"  /* mov.w @(0x20,PC),r11 */
    ".word 0x3BEC\n"  /* add r14,r11 */
    ".word 0x6BB2\n"  /* mov.l @r11,r11 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x25B8\n"  /* tst r11,r5 */
    ".word 0x8930\n"  /* bt 0x0602FCC0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x6512\n"  /* mov.l @r1,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA05B\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0x0250\n"  /* .word 0x0250 */
    ".word 0x0150\n"  /* .word 0x0150 */
    ".word 0x01BC\n"  /* mov.b @(r0,r11),r1 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0228\n"  /* .word 0x0228 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD30\n"  /* .word 0xFD30 */
    ".word 0x920E\n"  /* mov.w @(0x1C,PC),r2 */
    ".word 0x53E2\n"  /* mov.l @(0x8,r14),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x891D\n"  /* bt 0x0602FCC0 */
    ".word 0x900B\n"  /* mov.w @(0x16,PC),r0 */
    ".word 0xE518\n"  /* mov #24,r5 */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0x4518\n"  /* shll8 r5 */
    ".word 0x3517\n"  /* cmp/gt r1,r5 */
    ".word 0x8917\n"  /* bt 0x0602FCC0 */
    ".word 0xD503\n"  /* mov.l @(0xC,PC),r5  {[0x0602FCA0] = 0xAE1136FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA044\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
    ".word 0x005C\n"  /* mov.b @(r0,r5),r0 */
    ".word 0xAE11\n"  /* bra 0x0602F8C6 */
    ".word 0x36FF\n"  /* .word 0x36FF */
    ".word 0x9208\n"  /* mov.w @(0x10,PC),r2 */
    ".word 0x53E2\n"  /* mov.l @(0x8,r14),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8909\n"  /* bt 0x0602FCC0 */
    ".word 0xD503\n"  /* mov.l @(0xC,PC),r5  {[0x0602FCBC] = 0xAE112CFF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA036\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0x00F0\n"  /* .word 0x00F0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x0602F8E2 */
    ".word 0x2CFF\n"  /* muls.w r15,r12 */
    ".word 0x900C\n"  /* mov.w @(0x18,PC),r0 */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B0F\n"  /* bf 0x0602FCE8 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x0602FCE0] = 0x00028000} */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x890B\n"  /* bt 0x0602FCE8 */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x0602FCE4] = 0xAE1131FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA024\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xAE11\n"  /* bra 0x0602F90A */
    ".word 0x31FF\n"  /* .word 0x31FF */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x0602FD1C] = 0x0607EAD8} */
    ".word 0x9416\n"  /* mov.w @(0x2C,PC),r4 */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B17\n"  /* bf 0x0602FD24 */
    ".word 0xE1E0\n"  /* mov #-32,r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x3410\n"  /* cmp/eq r1,r4 */
    ".word 0x8902\n"  /* bt 0x0602FD04 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x3410\n"  /* cmp/eq r1,r4 */
    ".word 0x8B0F\n"  /* bf 0x0602FD24 */
    ".word 0xE10A\n"  /* mov #10,r1 */
    ".word 0x50E5\n"  /* mov.l @(0x14,r14),r0 */
    ".word 0x4128\n"  /* shll16 r1 */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x890A\n"  /* bt 0x0602FD24 */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x0602FD20] = 0xAE112EFF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE43C\n"  /* mov #60,r4 */
    ".word 0xA005\n"  /* bra 0x0602FD24 */
    ".word 0x2D41\n"  /* mov.w r4,@r13 */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0xAE11\n"  /* bra 0x0602F946 */
    ".word 0x2EFF\n"  /* muls.w r15,r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xAE11\n"  /* bra 0x0602F956 */
    ".word 0x31FF\n"  /* .word 0x31FF */
    ".word 0xAE11\n"  /* bra 0x0602F95A */
    ".word 0x2FFF\n"  /* muls.w r15,r15 */
    ".word 0xAE11\n"  /* bra 0x0602F95E */
    ".word 0x36FF\n"  /* .word 0x36FF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0058\n"  /* sets */
    ".word 0x0075\n"  /* mov.w r7,@(r0,r0) */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x00E1\n"  /* .word 0x00E1 */
    ".word 0x0066\n"  /* mov.l r6,@(r0,r0) */
    ".word 0x006D\n"  /* mov.w @(r0,r6),r0 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x001B\n"  /* sleep */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x003A\n"  /* .word 0x003A */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x004D\n"  /* mov.w @(r0,r4),r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0052\n"  /* .word 0x0052 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x006A\n"  /* .word 0x006A */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0082\n"  /* .word 0x0082 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x009D\n"  /* mov.w @(r0,r9),r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x00B4\n"  /* mov.b r11,@(r0,r0) */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x00DC\n"  /* mov.b @(r0,r13),r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0078\n"  /* .word 0x0078 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x009D\n"  /* mov.w @(r0,r9),r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x00D4\n"  /* mov.b r13,@(r0,r0) */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x01CE\n"  /* mov.l @(r0,r12),r1 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"











    ".section .text.FUN_0602FDB0, \"ax\"\n"

    ".global _FUN_0602FDB0\n"
    ".type _FUN_0602FDB0, @function\n"
    "_FUN_0602FDB0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0602FDCC] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x0602FDD0] = 0x0607ED8C} */
    ".word 0x6211\n"  /* mov.w @r1,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8905\n"  /* bt 0x0602FDD4 */
    ".word 0xA172\n"  /* bra 0x060300B0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED8C\n"  /* mov #-116,r13 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x0602FDF8] = 0x06063D9A} */
    ".word 0x6121\n"  /* mov.w @r2,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x0602FDFC] = 0x0608188A} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x9308\n"  /* mov.w @(0x10,PC),r3 */
    ".word 0x8B1B\n"  /* bf 0x0602FE1C */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x890B\n"  /* bt 0x0602FE00 */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8900\n"  /* bt 0x0602FDF0 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0xA038\n"  /* bra 0x0602FE64 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x00DE\n"  /* mov.l @(r0,r13),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x188A\n"  /* mov.l r8,@(0x28,r8) */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x0602FE18] = 0x06081888} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x892D\n"  /* bt 0x0602FE64 */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x3240\n"  /* cmp/eq r4,r2 */
    ".word 0x8900\n"  /* bt 0x0602FE12 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0xA027\n"  /* bra 0x0602FE64 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1888\n"  /* mov.l r8,@(0x20,r8) */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0602FE2C] = 0x06081896} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8905\n"  /* bt 0x0602FE30 */
    ".word 0xE403\n"  /* mov #3,r4 */
    ".word 0xA01D\n"  /* bra 0x0602FE64 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1896\n"  /* mov.l r9,@(0x18,r8) */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0602FE40] = 0x06081894} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8905\n"  /* bt 0x0602FE44 */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0xA013\n"  /* bra 0x0602FE64 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1894\n"  /* mov.l r9,@(0x10,r8) */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0602FE54] = 0x06081892} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8905\n"  /* bt 0x0602FE58 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xA009\n"  /* bra 0x0602FE64 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1892\n"  /* mov.l r9,@(0x8,r8) */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x0602FEA0] = 0x06081890} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8901\n"  /* bt 0x0602FE64 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0x6943\n"  /* mov r4,r9 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0602FEA4] = 0x06063D98} */
    ".word 0x6131\n"  /* mov.w @r3,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0602FEA8] = 0x0608188C} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8919\n"  /* bt 0x0602FEAC */
    ".word 0xE880\n"  /* mov #-128,r8 */
    ".word 0x688C\n"  /* extu.b r8,r8 */
    ".word 0x298B\n"  /* or r8,r9 */
    ".word 0x920C\n"  /* mov.w @(0x18,PC),r2 */
    ".word 0x0256\n"  /* mov.l r5,@(r0,r2) */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0x9809\n"  /* mov.w @(0x12,PC),r8 */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8904\n"  /* bt 0x0602FE96 */
    ".word 0x740A\n"  /* add #10,r4 */
    ".word 0x9306\n"  /* mov.w @(0xC,PC),r3 */
    ".word 0x3347\n"  /* cmp/gt r4,r3 */
    ".word 0x8900\n"  /* bt 0x0602FE96 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xA01E\n"  /* bra 0x0602FED6 */
    ".word 0x0246\n"  /* mov.l r4,@(r0,r2) */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1890\n"  /* mov.l r9,@(0x0,r8) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x188C\n"  /* mov.l r8,@(0x30,r8) */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0xE2B0\n"  /* mov #-80,r2 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0x3247\n"  /* cmp/gt r4,r2 */
    ".word 0x8902\n"  /* bt 0x0602FEC0 */
    ".word 0xA008\n"  /* bra 0x0602FECE */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x0074\n"  /* mov.b r7,@(r0,r0) */
    ".word 0x4609\n"  /* shlr2 r6 */
    ".word 0x4609\n"  /* shlr2 r6 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0xE66F\n"  /* mov #111,r6 */
    ".word 0x3463\n"  /* cmp/ge r6,r4 */
    ".word 0x8900\n"  /* bt 0x0602FECE */
    ".word 0xE438\n"  /* mov #56,r4 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x0602FF00] = 0x0000006C} */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x0276\n"  /* mov.l r7,@(r0,r2) */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x0602FF04] = 0x0608188E} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8916\n"  /* bt 0x0602FF0C */
    ".word 0xE840\n"  /* mov #64,r8 */
    ".word 0x298B\n"  /* or r8,r9 */
    ".word 0x930A\n"  /* mov.w @(0x14,PC),r3 */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0x9309\n"  /* mov.w @(0x12,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x9608\n"  /* mov.w @(0x10,PC),r6 */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0xD806\n"  /* mov.l @(0x18,PC),r8  {[0x0602FF08] = 0x000000B8} */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8900\n"  /* bt 0x0602FEF6 */
    ".word 0x7428\n"  /* add #40,r4 */
    ".word 0xA018\n"  /* bra 0x0602FF2A */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x188E\n"  /* mov.l r8,@(0x38,r8) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0602FF3C] = 0x00000090} */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0xD60B\n"  /* mov.l @(0x2C,PC),r6  {[0x0602FF40] = 0x0000008C} */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0xE338\n"  /* mov #56,r3 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0602FF22 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0602FF3C] = 0x00000090} */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0602FF44] = 0x00000088} */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0x9404\n"  /* mov.w @(0x8,PC),r4 */
    ".word 0x034D\n"  /* mov.w @(r0,r4),r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8909\n"  /* bt 0x0602FF48 */
    ".word 0xA08A\n"  /* bra 0x0603004C */
    ".word 0xEA01\n"  /* mov #1,r10 */
    ".word 0x009E\n"  /* mov.l @(r0,r9),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x0602FFA0] = 0x06063F48} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x892B\n"  /* bt 0x0602FFA8 */
    ".word 0xE820\n"  /* mov #32,r8 */
    ".word 0x298B\n"  /* or r8,r9 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x931D\n"  /* mov.w @(0x3A,PC),r3 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0x931B\n"  /* mov.w @(0x36,PC),r3 */
    ".word 0x083E\n"  /* mov.l @(r0,r3),r8 */
    ".word 0x961A\n"  /* mov.w @(0x34,PC),r6 */
    ".word 0x046E\n"  /* mov.l @(r0,r6),r4 */
    ".word 0x4815\n"  /* cmp/pl r8 */
    ".word 0x8B04\n"  /* bf 0x0602FF76 */
    ".word 0xE7CE\n"  /* mov #-50,r7 */
    ".word 0x4821\n"  /* shar r8 */
    ".word 0x3787\n"  /* cmp/gt r8,r7 */
    ".word 0x890E\n"  /* bt 0x0602FF92 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0xE790\n"  /* mov #-112,r7 */
    ".word 0x3788\n"  /* sub r8,r7 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0602FFA4] = 0x0602ECCC} */
    ".word 0x6173\n"  /* mov r7,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE007\n"  /* mov #7,r0 */
    ".word 0x381C\n"  /* add r1,r8 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xA069\n"  /* bra 0x06030068 */
    ".word 0x0386\n"  /* mov.l r8,@(r0,r3) */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F48\n"  /* sub r4,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECCC\n"  /* mov #-52,r12 */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x06030000] = 0x06063F4A} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x892A\n"  /* bt 0x06030008 */
    ".word 0xE810\n"  /* mov #16,r8 */
    ".word 0x298B\n"  /* or r8,r9 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x931D\n"  /* mov.w @(0x3A,PC),r3 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0x931B\n"  /* mov.w @(0x36,PC),r3 */
    ".word 0x083E\n"  /* mov.l @(r0,r3),r8 */
    ".word 0x961A\n"  /* mov.w @(0x34,PC),r6 */
    ".word 0x046E\n"  /* mov.l @(r0,r6),r4 */
    ".word 0x4811\n"  /* cmp/pz r8 */
    ".word 0x8904\n"  /* bt 0x0602FFD8 */
    ".word 0xE732\n"  /* mov #50,r7 */
    ".word 0x4821\n"  /* shar r8 */
    ".word 0x3877\n"  /* cmp/gt r7,r8 */
    ".word 0x890E\n"  /* bt 0x0602FFF4 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0xE770\n"  /* mov #112,r7 */
    ".word 0x3788\n"  /* sub r8,r7 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06030004] = 0x0602ECCC} */
    ".word 0x6173\n"  /* mov r7,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE007\n"  /* mov #7,r0 */
    ".word 0x381C\n"  /* add r1,r8 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xA038\n"  /* bra 0x06030068 */
    ".word 0x0386\n"  /* mov.l r8,@(r0,r3) */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F4A\n"  /* .word 0x3F4A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECCC\n"  /* mov #-52,r12 */
    ".word 0x960F\n"  /* mov.w @(0x1E,PC),r6 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0x930D\n"  /* mov.w @(0x1A,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8928\n"  /* bt 0x06030068 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8D09\n"  /* bt/s 0x0603002E */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0xE898\n"  /* mov #-104,r8 */
    ".word 0xE7F9\n"  /* mov #-7,r7 */
    ".word 0x3683\n"  /* cmp/ge r8,r6 */
    ".word 0x89FF\n"  /* bt 0x06030024 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0xA007\n"  /* bra 0x06030038 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0xE868\n"  /* mov #104,r8 */
    ".word 0xE707\n"  /* mov #7,r7 */
    ".word 0x3863\n"  /* cmp/ge r6,r8 */
    ".word 0x89FF\n"  /* bt 0x06030036 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x9305\n"  /* mov.w @(0xA,PC),r3 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0x9303\n"  /* mov.w @(0x6,PC),r3 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0xA010\n"  /* bra 0x06030068 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x060300A0] = 0x06063D9C} */
    ".word 0x6131\n"  /* mov.w @r3,r1 */
    ".word 0xD714\n"  /* mov.l @(0x50,PC),r7  {[0x060300A4] = 0x06078663} */
    ".word 0x6770\n"  /* mov.b @r7,r7 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B00\n"  /* bf 0x0603005A */
    ".word 0x6117\n"  /* not r1,r1 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x6713\n"  /* mov r1,r7 */
    ".word 0xE580\n"  /* mov #-128,r5 */
    ".word 0x315C\n"  /* add r5,r1 */
    ".word 0x931A\n"  /* mov.w @(0x34,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x0316\n"  /* mov.l r1,@(r0,r3) */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x060300A8] = 0x0607ED90} */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x060300AC] = 0x0607ED88} */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x326C\n"  /* add r6,r2 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x2290\n"  /* mov.b r9,@r2 */
    ".word 0x2AA8\n"  /* tst r10,r10 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x8900\n"  /* bt 0x0603007E */
    ".word 0x2270\n"  /* mov.b r7,@r2 */
    ".word 0x930D\n"  /* mov.w @(0x1A,PC),r3 */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8900\n"  /* bt 0x06030086 */
    ".word 0x76FE\n"  /* add #-2,r6 */
    ".word 0x2462\n"  /* mov.l r6,@r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0x2AF6\n"  /* mov.l r15,@-r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9C\n"  /* add r9,r13 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8663\n"  /* .word 0x8663 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED90\n"  /* mov #-112,r13 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED88\n"  /* mov #-120,r13 */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x060300F8] = 0x0607ED90} */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x060300FC] = 0x0607ED88} */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x326C\n"  /* add r6,r2 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x6120\n"  /* mov.b @r2,r1 */
    ".word 0x9318\n"  /* mov.w @(0x30,PC),r3 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x6513\n"  /* mov r1,r5 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x2529\n"  /* and r2,r5 */
    ".word 0x0355\n"  /* mov.w r5,@(r0,r3) */
    ".word 0x2462\n"  /* mov.l r6,@r4 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xE280\n"  /* mov #-128,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8915\n"  /* bt 0x06030100 */
    ".word 0x920D\n"  /* mov.w @(0x1A,PC),r2 */
    ".word 0x0256\n"  /* mov.l r5,@(r0,r2) */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0x980A\n"  /* mov.w @(0x14,PC),r8 */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8904\n"  /* bt 0x060300EC */
    ".word 0x740A\n"  /* add #10,r4 */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x3347\n"  /* cmp/gt r4,r3 */
    ".word 0x8900\n"  /* bt 0x060300EC */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xA01D\n"  /* bra 0x0603012A */
    ".word 0x0246\n"  /* mov.l r4,@(r0,r2) */
    ".word 0x00DE\n"  /* mov.l @(r0,r13),r0 */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED90\n"  /* mov #-112,r13 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED88\n"  /* mov #-120,r13 */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0xE2B0\n"  /* mov #-80,r2 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0x3247\n"  /* cmp/gt r4,r2 */
    ".word 0x8902\n"  /* bt 0x06030114 */
    ".word 0xA008\n"  /* bra 0x06030122 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x0074\n"  /* mov.b r7,@(r0,r0) */
    ".word 0x4609\n"  /* shlr2 r6 */
    ".word 0x4609\n"  /* shlr2 r6 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0xE66F\n"  /* mov #111,r6 */
    ".word 0x3463\n"  /* cmp/ge r6,r4 */
    ".word 0x8900\n"  /* bt 0x06030122 */
    ".word 0xE438\n"  /* mov #56,r4 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x06030150] = 0x0000006C} */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x0276\n"  /* mov.l r7,@(r0,r2) */
    ".word 0xE240\n"  /* mov #64,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8913\n"  /* bt 0x06030158 */
    ".word 0x930A\n"  /* mov.w @(0x14,PC),r3 */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0x9309\n"  /* mov.w @(0x12,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x9608\n"  /* mov.w @(0x10,PC),r6 */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0xD805\n"  /* mov.l @(0x14,PC),r8  {[0x06030154] = 0x000000B8} */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8900\n"  /* bt 0x06030144 */
    ".word 0x7428\n"  /* add #40,r4 */
    ".word 0xA017\n"  /* bra 0x06030176 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x06030184] = 0x00000090} */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0xD60A\n"  /* mov.l @(0x28,PC),r6  {[0x06030188] = 0x0000008C} */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0xE338\n"  /* mov #56,r3 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0603016E */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x06030184] = 0x00000090} */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0603018C] = 0x00000088} */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0xD405\n"  /* mov.l @(0x14,PC),r4  {[0x06030190] = 0x0607ED90} */
    ".word 0x6340\n"  /* mov.b @r4,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8909\n"  /* bt 0x06030194 */
    ".word 0xA07E\n"  /* bra 0x06030280 */
    ".word 0xEA01\n"  /* mov #1,r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED90\n"  /* mov #-112,r13 */
    ".word 0xE220\n"  /* mov #32,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8926\n"  /* bt 0x060301E8 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x931D\n"  /* mov.w @(0x3A,PC),r3 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0x931B\n"  /* mov.w @(0x36,PC),r3 */
    ".word 0x083E\n"  /* mov.l @(r0,r3),r8 */
    ".word 0x961A\n"  /* mov.w @(0x34,PC),r6 */
    ".word 0x046E\n"  /* mov.l @(r0,r6),r4 */
    ".word 0x4815\n"  /* cmp/pl r8 */
    ".word 0x8B04\n"  /* bf 0x060301BC */
    ".word 0xE7CE\n"  /* mov #-50,r7 */
    ".word 0x4821\n"  /* shar r8 */
    ".word 0x3787\n"  /* cmp/gt r8,r7 */
    ".word 0x890E\n"  /* bt 0x060301D8 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0xE790\n"  /* mov #-112,r7 */
    ".word 0x3788\n"  /* sub r8,r7 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x060301E4] = 0x0602ECCC} */
    ".word 0x6173\n"  /* mov r7,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE007\n"  /* mov #7,r0 */
    ".word 0x381C\n"  /* add r1,r8 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xA05D\n"  /* bra 0x06030296 */
    ".word 0x0386\n"  /* mov.l r8,@(r0,r3) */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECCC\n"  /* mov #-52,r12 */
    ".word 0xE210\n"  /* mov #16,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8926\n"  /* bt 0x0603023C */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x931D\n"  /* mov.w @(0x3A,PC),r3 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0x931B\n"  /* mov.w @(0x36,PC),r3 */
    ".word 0x083E\n"  /* mov.l @(r0,r3),r8 */
    ".word 0x961A\n"  /* mov.w @(0x34,PC),r6 */
    ".word 0x046E\n"  /* mov.l @(r0,r6),r4 */
    ".word 0x4811\n"  /* cmp/pz r8 */
    ".word 0x8904\n"  /* bt 0x06030210 */
    ".word 0xE732\n"  /* mov #50,r7 */
    ".word 0x4821\n"  /* shar r8 */
    ".word 0x3877\n"  /* cmp/gt r7,r8 */
    ".word 0x890E\n"  /* bt 0x0603022C */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0xE770\n"  /* mov #112,r7 */
    ".word 0x3788\n"  /* sub r8,r7 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06030238] = 0x0602ECCC} */
    ".word 0x6173\n"  /* mov r7,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE007\n"  /* mov #7,r0 */
    ".word 0x381C\n"  /* add r1,r8 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xA033\n"  /* bra 0x06030296 */
    ".word 0x0386\n"  /* mov.l r8,@(r0,r3) */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xECCC\n"  /* mov #-52,r12 */
    ".word 0x960F\n"  /* mov.w @(0x1E,PC),r6 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0x930D\n"  /* mov.w @(0x1A,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8925\n"  /* bt 0x06030296 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8D09\n"  /* bt/s 0x06030262 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0xE898\n"  /* mov #-104,r8 */
    ".word 0xE7F9\n"  /* mov #-7,r7 */
    ".word 0x3683\n"  /* cmp/ge r8,r6 */
    ".word 0x89FF\n"  /* bt 0x06030258 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0xA007\n"  /* bra 0x0603026C */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0xE868\n"  /* mov #104,r8 */
    ".word 0xE707\n"  /* mov #7,r7 */
    ".word 0x3863\n"  /* cmp/ge r6,r8 */
    ".word 0x89FF\n"  /* bt 0x0603026A */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x9305\n"  /* mov.w @(0xA,PC),r3 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0x9303\n"  /* mov.w @(0x6,PC),r3 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0xA00D\n"  /* bra 0x06030296 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x060302B4] = 0x0607ED90} */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x060302B8] = 0x0607ED88} */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x326C\n"  /* add r6,r2 */
    ".word 0x6120\n"  /* mov.b @r2,r1 */
    ".word 0xE580\n"  /* mov #-128,r5 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x315C\n"  /* add r5,r1 */
    ".word 0x930E\n"  /* mov.w @(0x1C,PC),r3 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x0316\n"  /* mov.l r1,@(r0,r3) */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x060302B8] = 0x0607ED88} */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x2462\n"  /* mov.l r6,@r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED90\n"  /* mov #-112,r13 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED88\n"  /* mov #-120,r13 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0009\n"  /* nop */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x89FB\n"  /* bt 0x060302BC */
    ".word 0x0009\n"  /* nop */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);

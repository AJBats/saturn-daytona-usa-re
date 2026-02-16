__asm__(



    ".balign 2\n"










    ".section .text.FUN_060302D2, \"ax\"\n"

    ".global _FUN_060302D2\n"
    ".type _FUN_060302D2, @function\n"
    "_FUN_060302D2:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x060302F0] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x060302F4] = 0x0607ED8C} */
    ".word 0x6211\n"  /* mov.w @r1,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8906\n"  /* bt 0x060302F8 */
    ".word 0xA0C3\n"  /* bra 0x06030474 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED8C\n"  /* mov #-116,r13 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x0603031C] = 0x06063D9A} */
    ".word 0x6121\n"  /* mov.w @r2,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x06030320] = 0x0608188A} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x9309\n"  /* mov.w @(0x12,PC),r3 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8B1B\n"  /* bf 0x06030340 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x890B\n"  /* bt 0x06030324 */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8900\n"  /* bt 0x06030314 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0xA038\n"  /* bra 0x06030388 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x00DE\n"  /* mov.l @(r0,r13),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x188A\n"  /* mov.l r8,@(0x28,r8) */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x0603033C] = 0x06081888} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x892D\n"  /* bt 0x06030388 */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x3240\n"  /* cmp/eq r4,r2 */
    ".word 0x8900\n"  /* bt 0x06030336 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0xA027\n"  /* bra 0x06030388 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1888\n"  /* mov.l r8,@(0x20,r8) */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06030350] = 0x06081896} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8905\n"  /* bt 0x06030354 */
    ".word 0xE403\n"  /* mov #3,r4 */
    ".word 0xA01D\n"  /* bra 0x06030388 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1896\n"  /* mov.l r9,@(0x18,r8) */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06030364] = 0x06081894} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8905\n"  /* bt 0x06030368 */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0xA013\n"  /* bra 0x06030388 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1894\n"  /* mov.l r9,@(0x10,r8) */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06030378] = 0x06081892} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8905\n"  /* bt 0x0603037C */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xA009\n"  /* bra 0x06030388 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1892\n"  /* mov.l r9,@(0x8,r8) */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x060303BC] = 0x06081890} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8901\n"  /* bt 0x06030388 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0x6943\n"  /* mov r4,r9 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x060303C0] = 0x06063D98} */
    ".word 0x6131\n"  /* mov.w @r3,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x060303C4] = 0x0608188C} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8915\n"  /* bt 0x060303C8 */
    ".word 0xE880\n"  /* mov #-128,r8 */
    ".word 0x688C\n"  /* extu.b r8,r8 */
    ".word 0x298B\n"  /* or r8,r9 */
    ".word 0x9208\n"  /* mov.w @(0x10,PC),r2 */
    ".word 0x0256\n"  /* mov.l r5,@(r0,r2) */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x9806\n"  /* mov.w @(0xC,PC),r8 */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8900\n"  /* bt 0x060303B2 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0xA014\n"  /* bra 0x060303DE */
    ".word 0x0246\n"  /* mov.l r4,@(r0,r2) */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1890\n"  /* mov.l r9,@(0x0,r8) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x188C\n"  /* mov.l r8,@(0x30,r8) */
    ".word 0x931B\n"  /* mov.w @(0x36,PC),r3 */
    ".word 0xE538\n"  /* mov #56,r5 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x74FE\n"  /* add #-2,r4 */
    ".word 0x3457\n"  /* cmp/gt r5,r4 */
    ".word 0x8900\n"  /* bt 0x060303D6 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x06030408] = 0x0000006C} */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x0276\n"  /* mov.l r7,@(r0,r2) */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x0603040C] = 0x0608188E} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x891A\n"  /* bt 0x0603041C */
    ".word 0xE840\n"  /* mov #64,r8 */
    ".word 0x298B\n"  /* or r8,r9 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06030410] = 0x00000088} */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06030414] = 0x00000090} */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0xD609\n"  /* mov.l @(0x24,PC),r6  {[0x06030418] = 0x0000008C} */
    ".word 0x9806\n"  /* mov.w @(0xC,PC),r8 */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8900\n"  /* bt 0x060303FE */
    ".word 0x7405\n"  /* add #5,r4 */
    ".word 0xA01A\n"  /* bra 0x06030436 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x0074\n"  /* mov.b r7,@(r0,r0) */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x188E\n"  /* mov.l r8,@(0x38,r8) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06030460] = 0x00000090} */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0xD610\n"  /* mov.l @(0x40,PC),r6  {[0x06030464] = 0x0000008C} */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0xE338\n"  /* mov #56,r3 */
    ".word 0x74FB\n"  /* add #-5,r4 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x0603042E */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x06030460] = 0x00000090} */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06030468] = 0x00000088} */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0603046C] = 0x0607ED90} */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x06030470] = 0x0607ED88} */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x326C\n"  /* add r6,r2 */
    ".word 0x7602\n"  /* add #2,r6 */
    ".word 0x2290\n"  /* mov.b r9,@r2 */
    ".word 0x930C\n"  /* mov.w @(0x18,PC),r3 */
    ".word 0x3367\n"  /* cmp/gt r6,r3 */
    ".word 0x8900\n"  /* bt 0x0603044A */
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
    ".word 0x2AF6\n"  /* mov.l r15,@-r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED90\n"  /* mov #-112,r13 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED88\n"  /* mov #-120,r13 */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x060304B4] = 0x0607ED90} */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x060304B8] = 0x0607ED88} */
    ".word 0x6642\n"  /* mov.l @r4,r6 */
    ".word 0x326C\n"  /* add r6,r2 */
    ".word 0x7602\n"  /* add #2,r6 */
    ".word 0x6120\n"  /* mov.b @r2,r1 */
    ".word 0x9314\n"  /* mov.w @(0x28,PC),r3 */
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
    ".word 0x8911\n"  /* bt 0x060304BC */
    ".word 0x9209\n"  /* mov.w @(0x12,PC),r2 */
    ".word 0x0256\n"  /* mov.l r5,@(r0,r2) */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x9807\n"  /* mov.w @(0xE,PC),r8 */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8900\n"  /* bt 0x060304A8 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0xA013\n"  /* bra 0x060304D2 */
    ".word 0x0246\n"  /* mov.l r4,@(r0,r2) */
    ".word 0x00DE\n"  /* mov.l @(r0,r13),r0 */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED90\n"  /* mov #-112,r13 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED88\n"  /* mov #-120,r13 */
    ".word 0x9318\n"  /* mov.w @(0x30,PC),r3 */
    ".word 0xE538\n"  /* mov #56,r5 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0x74FE\n"  /* add #-2,r4 */
    ".word 0x3453\n"  /* cmp/ge r5,r4 */
    ".word 0x8900\n"  /* bt 0x060304CA */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x060304F4] = 0x0000006C} */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x0276\n"  /* mov.l r7,@(r0,r2) */
    ".word 0xE240\n"  /* mov #64,r2 */
    ".word 0x2218\n"  /* tst r1,r2 */
    ".word 0x8915\n"  /* bt 0x06030504 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x060304F8] = 0x00000088} */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x060304FC] = 0x00000090} */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0xD607\n"  /* mov.l @(0x1C,PC),r6  {[0x06030500] = 0x0000008C} */
    ".word 0x9806\n"  /* mov.w @(0xC,PC),r8 */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0x3487\n"  /* cmp/gt r8,r4 */
    ".word 0x8900\n"  /* bt 0x060304EC */
    ".word 0x7405\n"  /* add #5,r4 */
    ".word 0xA017\n"  /* bra 0x0603051E */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x0074\n"  /* mov.b r7,@(r0,r0) */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x06030530] = 0x00000090} */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0xD60A\n"  /* mov.l @(0x28,PC),r6  {[0x06030534] = 0x0000008C} */
    ".word 0x0646\n"  /* mov.l r4,@(r0,r6) */
    ".word 0xE338\n"  /* mov #56,r3 */
    ".word 0x74FB\n"  /* add #-5,r4 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x06030516 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06030530] = 0x00000090} */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06030538] = 0x00000088} */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
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
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x008C\n"  /* mov.b @(r0,r8),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".global _FUN_0603053c\n"
    "_FUN_0603053c:\n"
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06030540, \"ax\"\n"

    ".global _FUN_06030540\n"
    ".type _FUN_06030540, @function\n"
    "_FUN_06030540:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xDE0B\n"  /* mov.l @(0x2C,PC),r14  {[0x06030570] = 0x06030FBE} */
    ".word 0x2E41\n"  /* mov.w r4,@r14 */
    ".word 0xDE0B\n"  /* mov.l @(0x2C,PC),r14  {[0x06030574] = 0x0607E940} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06030548, \"ax\"\n"

    ".global _FUN_06030548\n"
    ".type _FUN_06030548, @function\n"
    "_FUN_06030548:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x910D\n"  /* mov.w @(0x1A,PC),r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0x5411\n"  /* mov.l @(0x4,r1),r4 */
    ".word 0x5512\n"  /* mov.l @(0x8,r1),r5 */
    ".word 0x5613\n"  /* mov.l @(0xC,r1),r6 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x224B\n"  /* or r4,r2 */
    ".word 0x225B\n"  /* or r5,r2 */
    ".word 0x226B\n"  /* or r6,r2 */
    ".word 0x9704\n"  /* mov.w @(0x8,PC),r7 */
    ".word 0x2278\n"  /* tst r7,r2 */
    ".word 0x8B08\n"  /* bf 0x06030578 */
    ".word 0xA0DD\n"  /* bra 0x06030724 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0120\n"  /* .word 0x0120 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBE\n"  /* mov.l @(r0,r11),r15 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x2439\n"  /* and r3,r4 */
    ".word 0x2659\n"  /* and r5,r6 */
    ".word 0x2649\n"  /* and r4,r6 */
    ".word 0x9203\n"  /* mov.w @(0x6,PC),r2 */
    ".word 0x2628\n"  /* tst r2,r6 */
    ".word 0x8902\n"  /* bt 0x0603058A */
    ".word 0xA0CE\n"  /* bra 0x06030724 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x9205\n"  /* mov.w @(0xA,PC),r2 */
    ".word 0x2628\n"  /* tst r2,r6 */
    ".word 0x8907\n"  /* bt 0x060305A0 */
    ".word 0xD702\n"  /* mov.l @(0x8,PC),r7  {[0x0603059C] = 0x06063EC4} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA282\n"  /* bra 0x06030A9C */
    ".word 0x5674\n"  /* mov.l @(0x10,r7),r6 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EC4\n"  /* .word 0x3EC4 */
    ".word 0x9205\n"  /* mov.w @(0xA,PC),r2 */
    ".word 0x2628\n"  /* tst r2,r6 */
    ".word 0x8905\n"  /* bt 0x060305B2 */
    ".word 0x9003\n"  /* mov.w @(0x6,PC),r0 */
    ".word 0xE20F\n"  /* mov #15,r2 */
    ".word 0xA0BB\n"  /* bra 0x06030724 */
    ".word 0x0E25\n"  /* mov.w r2,@(r0,r14) */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x016C\n"  /* mov.b @(r0,r6),r1 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0x9525\n"  /* mov.w @(0x4A,PC),r5 */
    ".word 0x6412\n"  /* mov.l @r1,r4 */
    ".word 0x2458\n"  /* tst r5,r4 */
    ".word 0x8900\n"  /* bt 0x060305BE */
    ".word 0x7C01\n"  /* add #1,r12 */
    ".word 0x5411\n"  /* mov.l @(0x4,r1),r4 */
    ".word 0x2458\n"  /* tst r5,r4 */
    ".word 0x8900\n"  /* bt 0x060305C6 */
    ".word 0x7C02\n"  /* add #2,r12 */
    ".word 0x5412\n"  /* mov.l @(0x8,r1),r4 */
    ".word 0x2458\n"  /* tst r5,r4 */
    ".word 0x8900\n"  /* bt 0x060305CE */
    ".word 0x7C04\n"  /* add #4,r12 */
    ".word 0x5413\n"  /* mov.l @(0xC,r1),r4 */
    ".word 0x2458\n"  /* tst r5,r4 */
    ".word 0x8900\n"  /* bt 0x060305D6 */
    ".word 0x7C08\n"  /* add #8,r12 */
    ".word 0x9715\n"  /* mov.w @(0x2A,PC),r7 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x37EC\n"  /* add r14,r7 */
    ".word 0x2742\n"  /* mov.l r4,@r7 */
    ".word 0xE703\n"  /* mov #3,r7 */
    ".word 0x3C70\n"  /* cmp/eq r7,r12 */
    ".word 0x892F\n"  /* bt 0x06030644 */
    ".word 0xE70C\n"  /* mov #12,r7 */
    ".word 0x3C70\n"  /* cmp/eq r7,r12 */
    ".word 0x890D\n"  /* bt 0x06030606 */
    ".word 0xE705\n"  /* mov #5,r7 */
    ".word 0x6573\n"  /* mov r7,r5 */
    ".word 0x27C9\n"  /* and r12,r7 */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x8971\n"  /* bt 0x060306D8 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8949\n"  /* bt 0x0603068C */
    ".word 0xE50A\n"  /* mov #10,r5 */
    ".word 0x25C8\n"  /* tst r12,r5 */
    ".word 0x896C\n"  /* bt 0x060306D8 */
    ".word 0xA045\n"  /* bra 0x0603068C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0208\n"  /* .word 0x0208 */
    ".word 0xD70D\n"  /* mov.l @(0x34,PC),r7  {[0x0603063C] = 0x06063EC4} */
    ".word 0x9417\n"  /* mov.w @(0x2E,PC),r4 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0x52EC\n"  /* mov.l @(0x30,r14),r2 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0x8900\n"  /* bt 0x0603061A */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8D05\n"  /* bt/s 0x0603062C */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8900\n"  /* bt 0x0603062C */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x9405\n"  /* mov.w @(0xA,PC),r4 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x06030640] = 0x06030FBC} */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x2351\n"  /* mov.w r5,@r3 */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0xA297\n"  /* bra 0x06030B68 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EC4\n"  /* .word 0x3EC4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBC\n"  /* mov.b @(r0,r11),r15 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x52EC\n"  /* mov.l @(0x30,r14),r2 */
    ".word 0x4528\n"  /* shll16 r5 */
    ".word 0x4501\n"  /* shlr r5 */
    ".word 0xD70D\n"  /* mov.l @(0x34,PC),r7  {[0x06030684] = 0x06063E9C} */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x9416\n"  /* mov.w @(0x2C,PC),r4 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0x8900\n"  /* bt 0x06030660 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8D05\n"  /* bt/s 0x06030672 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8900\n"  /* bt 0x06030672 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x9405\n"  /* mov.w @(0xA,PC),r4 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x06030688] = 0x06030FBC} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x2351\n"  /* mov.w r5,@r3 */
    ".word 0xA274\n"  /* bra 0x06030B68 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E9C\n"  /* add r9,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBC\n"  /* mov.b @(r0,r11),r15 */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0x2C48\n"  /* tst r4,r12 */
    ".word 0xD70E\n"  /* mov.l @(0x38,PC),r7  {[0x060306CC] = 0x06063EB0} */
    ".word 0xED01\n"  /* mov #1,r13 */
    ".word 0x8B01\n"  /* bf 0x0603069A */
    ".word 0xD70E\n"  /* mov.l @(0x38,PC),r7  {[0x060306D0] = 0x06063ED8} */
    ".word 0xED03\n"  /* mov #3,r13 */
    ".word 0x9415\n"  /* mov.w @(0x2A,PC),r4 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0x52EC\n"  /* mov.l @(0x30,r14),r2 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8900\n"  /* bt 0x060306A8 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8D05\n"  /* bt/s 0x060306BA */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8900\n"  /* bt 0x060306BA */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x9405\n"  /* mov.w @(0xA,PC),r4 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x060306D4] = 0x06030FBC} */
    ".word 0x2351\n"  /* mov.w r5,@r3 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0xA250\n"  /* bra 0x06030B68 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EB0\n"  /* cmp/eq r11,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3ED8\n"  /* sub r13,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBC\n"  /* mov.b @(r0,r11),r15 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xD70F\n"  /* mov.l @(0x3C,PC),r7  {[0x06030718] = 0x06063E9C} */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x2C48\n"  /* tst r4,r12 */
    ".word 0x8B01\n"  /* bf 0x060306E6 */
    ".word 0xD70E\n"  /* mov.l @(0x38,PC),r7  {[0x0603071C] = 0x06063EC4} */
    ".word 0xED02\n"  /* mov #2,r13 */
    ".word 0x9415\n"  /* mov.w @(0x2A,PC),r4 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0x52EC\n"  /* mov.l @(0x30,r14),r2 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8900\n"  /* bt 0x060306F4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8D05\n"  /* bt/s 0x06030706 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8900\n"  /* bt 0x06030706 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x9406\n"  /* mov.w @(0xC,PC),r4 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x06030720] = 0x06030FBC} */
    ".word 0x2351\n"  /* mov.w r5,@r3 */
    ".word 0x5574\n"  /* mov.l @(0x10,r7),r5 */
    ".word 0xA22A\n"  /* bra 0x06030B68 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E9C\n"  /* add r9,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EC4\n"  /* .word 0x3EC4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBC\n"  /* mov.b @(r0,r11),r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".global _FUN_0603072e\n"
    "_FUN_0603072e:\n"
    ".word 0x9108\n"  /* mov.w @(0x10,PC),r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x3520\n"  /* cmp/eq r2,r5 */
    ".word 0x8B05\n"  /* bf 0x06030744 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x2152\n"  /* mov.l r5,@r1 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0xD202\n"  /* mov.l @(0x8,PC),r2  {[0x06030754] = 0x06030F1C} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x324C\n"  /* add r4,r2 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x412B\n"  /* jmp @r1 */
    ".word 0xEC00\n"  /* mov #0,r12 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0F1C\n"  /* mov.b @(r0,r1),r15 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x06030780] = 0x0607866D} */
    ".word 0xE508\n"  /* mov #8,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x06030784] = 0x06089595} */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0x9509\n"  /* mov.w @(0x12,PC),r5 */
    ".word 0x9009\n"  /* mov.w @(0x12,PC),r0 */
    ".word 0x56E2\n"  /* mov.l @(0x8,r14),r6 */
    ".word 0xE264\n"  /* mov #100,r2 */
    ".word 0x3263\n"  /* cmp/ge r6,r2 */
    ".word 0x02EE\n"  /* mov.l @(r0,r14),r2 */
    ".word 0x8900\n"  /* bt 0x06030774 */
    ".word 0x225B\n"  /* or r5,r2 */
    ".word 0x0E26\n"  /* mov.l r2,@(r0,r14) */
    ".word 0xA047\n"  /* bra 0x06030808 */
    ".word 0x5674\n"  /* mov.l @(0x10,r7),r6 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x866D\n"  /* .word 0x866D */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9595\n"  /* mov.w @(0x12A,PC),r5 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x060307B0] = 0x0607866D} */
    ".word 0xE504\n"  /* mov #4,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x060307B4] = 0x06089595} */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0x9509\n"  /* mov.w @(0x12,PC),r5 */
    ".word 0x9009\n"  /* mov.w @(0x12,PC),r0 */
    ".word 0x56E2\n"  /* mov.l @(0x8,r14),r6 */
    ".word 0xE264\n"  /* mov #100,r2 */
    ".word 0x3263\n"  /* cmp/ge r6,r2 */
    ".word 0x02EE\n"  /* mov.l @(r0,r14),r2 */
    ".word 0x8900\n"  /* bt 0x060307A4 */
    ".word 0x225B\n"  /* or r5,r2 */
    ".word 0x0E26\n"  /* mov.l r2,@(r0,r14) */
    ".word 0xA02F\n"  /* bra 0x06030808 */
    ".word 0x5674\n"  /* mov.l @(0x10,r7),r6 */
    ".word 0x0022\n"  /* stc vbr,r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x866D\n"  /* .word 0x866D */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9595\n"  /* mov.w @(0x12A,PC),r5 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x060307E0] = 0x0607866D} */
    ".word 0xE502\n"  /* mov #2,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x060307E4] = 0x06089595} */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0x9509\n"  /* mov.w @(0x12,PC),r5 */
    ".word 0x9009\n"  /* mov.w @(0x12,PC),r0 */
    ".word 0x56E2\n"  /* mov.l @(0x8,r14),r6 */
    ".word 0xE264\n"  /* mov #100,r2 */
    ".word 0x3263\n"  /* cmp/ge r6,r2 */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x8900\n"  /* bt 0x060307D4 */
    ".word 0x245B\n"  /* or r5,r4 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0xA017\n"  /* bra 0x06030808 */
    ".word 0x5674\n"  /* mov.l @(0x10,r7),r6 */
    ".word 0x0044\n"  /* mov.b r4,@(r0,r0) */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x866D\n"  /* .word 0x866D */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9595\n"  /* mov.w @(0x12A,PC),r5 */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x06030884] = 0x0607866D} */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x06030888] = 0x06089595} */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0x9540\n"  /* mov.w @(0x80,PC),r5 */
    ".word 0x9040\n"  /* mov.w @(0x80,PC),r0 */
    ".word 0x56E2\n"  /* mov.l @(0x8,r14),r6 */
    ".word 0xE264\n"  /* mov #100,r2 */
    ".word 0x3263\n"  /* cmp/ge r6,r2 */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0x8900\n"  /* bt 0x06030804 */
    ".word 0x245B\n"  /* or r5,r4 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0x5674\n"  /* mov.l @(0x10,r7),r6 */
    ".word 0x55EA\n"  /* mov.l @(0x28,r14),r5 */
    ".word 0x8577\n"  /* mov.w @(0xE,r7),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x4128\n"  /* shll16 r1 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8900\n"  /* bt 0x06030822 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x3143\n"  /* cmp/ge r4,r1 */
    ".word 0x8901\n"  /* bt 0x0603082C */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x3418\n"  /* sub r1,r4 */
    ".word 0x6143\n"  /* mov r4,r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x9024\n"  /* mov.w @(0x48,PC),r0 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0x3548\n"  /* sub r4,r5 */
    ".word 0x70FC\n"  /* add #-4,r0 */
    ".word 0x6753\n"  /* mov r5,r7 */
    ".word 0x0E56\n"  /* mov.l r5,@(r0,r14) */
    ".word 0x941D\n"  /* mov.w @(0x3A,PC),r4 */
    ".word 0x7008\n"  /* add #8,r0 */
    ".word 0x0E45\n"  /* mov.w r4,@(r0,r14) */
    ".word 0x901B\n"  /* mov.w @(0x36,PC),r0 */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B39\n"  /* bf 0x060308C4 */
    ".word 0x9017\n"  /* mov.w @(0x2E,PC),r0 */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x0603088C] = 0x06030F74} */
    ".word 0x041D\n"  /* mov.w @(r0,r1),r4 */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x06030890] = 0x06030F98} */
    ".word 0x051D\n"  /* mov.w @(r0,r1),r5 */
    ".word 0x50E2\n"  /* mov.l @(0x8,r14),r0 */
    ".word 0x3043\n"  /* cmp/ge r4,r0 */
    ".word 0x8B1A\n"  /* bf 0x0603089C */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06030894] = 0x06030FBE} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B26\n"  /* bf 0x060308BC */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x06030898] = 0x06008460} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0xA026\n"  /* bra 0x060308C4 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x0088\n"  /* .word 0x0088 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x00BC\n"  /* mov.b @(r0,r11),r0 */
    ".word 0x01D4\n"  /* mov.b r13,@(r0,r1) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x866D\n"  /* .word 0x866D */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9595\n"  /* mov.w @(0x12A,PC),r5 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0F74\n"  /* mov.b r7,@(r0,r15) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0F98\n"  /* .word 0x0F98 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBE\n"  /* mov.l @(r0,r11),r15 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06008460 */
    ".word 0x8460\n"  /* mov.b @(0x0,r6),r0 */
    ".word 0x3503\n"  /* cmp/ge r0,r5 */
    ".word 0x8911\n"  /* bt 0x060308C4 */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x060308B4] = 0x06030FBE} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B09\n"  /* bf 0x060308BC */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x060308B8] = 0x06008418} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0xA009\n"  /* bra 0x060308C4 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBE\n"  /* mov.l @(r0,r11),r15 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06008418 */
    ".word 0x8418\n"  /* mov.b @(0x8,r1),r0 */
    ".word 0x50E0\n"  /* mov.l @(0x0,r14),r0 */
    ".word 0xD419\n"  /* mov.l @(0x64,PC),r4  {[0x06030924] = 0x08000000} */
    ".word 0x204B\n"  /* or r4,r0 */
    ".word 0x1E00\n"  /* mov.l r0,@(0x0,r14) */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0xED01\n"  /* mov #1,r13 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0xD115\n"  /* mov.l @(0x54,PC),r1  {[0x06030928] = 0x060A6000} */
    ".word 0xE234\n"  /* mov #52,r2 */
    ".word 0x232F\n"  /* muls.w r2,r3 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0xED01\n"  /* mov #1,r13 */
    ".word 0x5814\n"  /* mov.l @(0x10,r1),r8 */
    ".word 0x4D28\n"  /* shll16 r13 */
    ".word 0x5A15\n"  /* mov.l @(0x14,r1),r10 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x4D18\n"  /* shll8 r13 */
    ".word 0x358D\n"  /* dmuls.l r8,r5 */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x5010\n"  /* mov.l @(0x0,r1),r0 */
    ".word 0x040A\n"  /* sts mach,r4 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x2D08\n"  /* tst r0,r13 */
    ".word 0x254D\n"  /* .word 0x254D */
    ".word 0x4019\n"  /* shlr8 r0 */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0xC901\n"  /* and #0x01,r0 */
    ".word 0x8F02\n"  /* bf/s 0x06030906 */
    ".word 0x35AC\n"  /* add r10,r5 */
    ".word 0x356C\n"  /* add r6,r5 */
    ".word 0xE901\n"  /* mov #1,r9 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x4515\n"  /* cmp/pl r5 */
    ".word 0x8900\n"  /* bt 0x0603090E */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x3600\n"  /* cmp/eq r0,r6 */
    ".word 0x8900\n"  /* bt 0x06030916 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x6083\n"  /* mov r8,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8F06\n"  /* bf/s 0x0603092C */
    ".word 0x6093\n"  /* mov r9,r0 */
    ".word 0xA008\n"  /* bra 0x06030934 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B15\n"  /* bf 0x0603095C */
    ".word 0xA007\n"  /* bra 0x06030942 */
    ".word 0x0009\n"  /* nop */
    ".word 0x55E6\n"  /* mov.l @(0x18,r14),r5 */
    ".word 0x35AC\n"  /* add r10,r5 */
    ".word 0x4515\n"  /* cmp/pl r5 */
    ".word 0x8900\n"  /* bt 0x0603093E */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0xA25E\n"  /* bra 0x06030DFE */
    ".word 0x0009\n"  /* nop */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06030958] = 0x0602755C} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x3508\n"  /* sub r0,r5 */
    ".word 0x4515\n"  /* cmp/pl r5 */
    ".word 0x8900\n"  /* bt 0x06030954 */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0xA253\n"  /* bra 0x06030DFE */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x52E6\n"  /* mov.l @(0x18,r14),r2 */
    ".word 0x32AC\n"  /* add r10,r2 */
    ".word 0x638B\n"  /* neg r8,r3 */
    ".word 0x332D\n"  /* dmuls.l r2,r3 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x4528\n"  /* shll16 r5 */
    ".word 0x941F\n"  /* mov.w @(0x3E,PC),r4 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8B02\n"  /* bf 0x06030978 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x3247\n"  /* cmp/gt r4,r2 */
    ".word 0x891B\n"  /* bt 0x060309B0 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4329\n"  /* shlr16 r3 */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x54E4\n"  /* mov.l @(0x10,r14),r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x628B\n"  /* neg r8,r2 */
    ".word 0x322D\n"  /* dmuls.l r2,r2 */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x223D\n"  /* .word 0x223D */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x060309AC] = 0x0602755C} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0xA00E\n"  /* bra 0x060309C6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x232D\n"  /* .word 0x232D */
    ".word 0x54E4\n"  /* mov.l @(0x10,r14),r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x628B\n"  /* neg r8,r2 */
    ".word 0x322D\n"  /* dmuls.l r2,r2 */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x223D\n"  /* .word 0x223D */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x060309F8] = 0x0602755C} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x638B\n"  /* neg r8,r3 */
    ".word 0x323D\n"  /* dmuls.l r3,r2 */
    ".word 0x65AB\n"  /* neg r10,r5 */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x223D\n"  /* .word 0x223D */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x52E4\n"  /* mov.l @(0x10,r14),r2 */
    ".word 0x53E6\n"  /* mov.l @(0x18,r14),r3 */
    ".word 0x3028\n"  /* sub r2,r0 */
    ".word 0x3538\n"  /* sub r3,r5 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8900\n"  /* bt 0x060309E4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4515\n"  /* cmp/pl r5 */
    ".word 0x8900\n"  /* bt 0x060309EA */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8906\n"  /* bt 0x060309FC */
    ".word 0x4521\n"  /* shar r5 */
    ".word 0x4521\n"  /* shar r5 */
    ".word 0xA006\n"  /* bra 0x06030A02 */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0xA1FC\n"  /* bra 0x06030DFE */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_06030a06\n"
    "_FUN_06030a06:\n"
    ".word 0xD110\n"  /* mov.l @(0x40,PC),r1  {[0x06030A48] = 0x0607E940} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0x9018\n"  /* mov.w @(0x30,PC),r0 */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8913\n"  /* bt 0x06030A3A */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8F10\n"  /* bf/s 0x06030A3A */
    ".word 0x0345\n"  /* mov.w r4,@(r0,r3) */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x06030A4C] = 0xFFFF0000} */
    ".word 0x9610\n"  /* mov.w @(0x20,PC),r6 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x2652\n"  /* mov.l r5,@r6 */
    ".word 0x043E\n"  /* mov.l @(r0,r3),r4 */
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x06030A50] = 0x00200000} */
    ".word 0x2458\n"  /* tst r5,r4 */
    ".word 0x8906\n"  /* bt 0x06030A3A */
    ".word 0x900A\n"  /* mov.w @(0x14,PC),r0 */
    ".word 0x920A\n"  /* mov.w @(0x14,PC),r2 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6422\n"  /* mov.l @r2,r4 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x553C\n"  /* mov.l @(0x30,r3),r5 */
    ".word 0x135A\n"  /* mov.l r5,@(0x28,r3) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0250\n"  /* .word 0x0250 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0160\n"  /* .word 0x0160 */
    ".word 0x01E4\n"  /* mov.b r14,@(r0,r1) */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x53E3\n"  /* mov.l @(0xC,r14),r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x1E33\n"  /* mov.l r3,@(0xC,r14) */
    ".word 0x52E5\n"  /* mov.l @(0x14,r14),r2 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x06030A84] = 0x06063E4C} */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x06030A88] = 0x06063E60} */
    ".word 0x1121\n"  /* mov.l r2,@(0x4,r1) */
    ".word 0x1321\n"  /* mov.l r2,@(0x4,r3) */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x06030A8C] = 0x06063E74} */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x06030A90] = 0x06063E88} */
    ".word 0x1121\n"  /* mov.l r2,@(0x4,r1) */
    ".word 0x1321\n"  /* mov.l r2,@(0x4,r3) */
    ".word 0x9409\n"  /* mov.w @(0x12,PC),r4 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x06030A94] = 0x0607EAE8} */
    ".word 0x2142\n"  /* mov.l r4,@r1 */
    ".word 0x9406\n"  /* mov.w @(0xC,PC),r4 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x06030A98] = 0x0607EAEC} */
    ".word 0x2142\n"  /* mov.l r4,@r1 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E4C\n"  /* add r4,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E60\n"  /* cmp/eq r6,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E74\n"  /* .word 0x3E74 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E88\n"  /* sub r8,r14 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE8\n"  /* mov #-24,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAEC\n"  /* mov #-20,r10 */
    ".global _FUN_06030a9c\n"
    "_FUN_06030a9c:\n"
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x55EA\n"  /* mov.l @(0x28,r14),r5 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x913B\n"  /* mov.w @(0x76,PC),r1 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8900\n"  /* bt 0x06030AB6 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x3143\n"  /* cmp/ge r4,r1 */
    ".word 0x8901\n"  /* bt 0x06030AC0 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x3418\n"  /* sub r1,r4 */
    ".word 0x6143\n"  /* mov r4,r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x902D\n"  /* mov.w @(0x5A,PC),r0 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0x3548\n"  /* sub r4,r5 */
    ".word 0x70FC\n"  /* add #-4,r0 */
    ".word 0x0E56\n"  /* mov.l r5,@(r0,r14) */
    ".word 0x9429\n"  /* mov.w @(0x52,PC),r4 */
    ".word 0x7008\n"  /* add #8,r0 */
    ".word 0x0E45\n"  /* mov.w r4,@(r0,r14) */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06030B30] = 0x0607866D} */
    ".word 0xE50F\n"  /* mov #15,r5 */
    ".word 0x2050\n"  /* mov.b r5,@r0 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06030B34] = 0x06089595} */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x9021\n"  /* mov.w @(0x42,PC),r0 */
    ".word 0x9121\n"  /* mov.w @(0x42,PC),r1 */
    ".word 0x02EE\n"  /* mov.l @(r0,r14),r2 */
    ".word 0x221B\n"  /* or r1,r2 */
    ".word 0x0E26\n"  /* mov.l r2,@(r0,r14) */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x8577\n"  /* mov.w @(0xE,r7),r0 */
    ".word 0xD110\n"  /* mov.l @(0x40,PC),r1  {[0x06030B38] = 0x060A6000} */
    ".word 0xE234\n"  /* mov #52,r2 */
    ".word 0x202F\n"  /* muls.w r2,r0 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x5814\n"  /* mov.l @(0x10,r1),r8 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x06030B3C] = 0x06030FBE} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06030B40] = 0x06008460} */
    ".word 0x5A15\n"  /* mov.l @(0x14,r1),r10 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x6D12\n"  /* mov.l @r1,r13 */
    ".word 0xD60D\n"  /* mov.l @(0x34,PC),r6  {[0x06030B44] = 0x01000000} */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0x2D68\n"  /* tst r6,r13 */
    ".word 0x8B00\n"  /* bf 0x06030B18 */
    ".word 0xE901\n"  /* mov #1,r9 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B15\n"  /* bf 0x06030B48 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0xA016\n"  /* bra 0x06030B50 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x00CC\n"  /* mov.b @(r0,r12),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x866D\n"  /* .word 0x866D */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9595\n"  /* mov.w @(0x12A,PC),r5 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBE\n"  /* mov.l @(r0,r11),r15 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06008460 */
    ".word 0x8460\n"  /* mov.b @(0x0,r6),r0 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06030B60] = 0x08000000} */
    ".word 0x52E0\n"  /* mov.l @(0x0,r14),r2 */
    ".word 0x220B\n"  /* or r0,r2 */
    ".word 0x1E20\n"  /* mov.l r2,@(0x0,r14) */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06030B64] = 0x06030FBC} */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2051\n"  /* mov.w r5,@r0 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xA0B0\n"  /* bra 0x06030CBE */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBC\n"  /* mov.b @(r0,r11),r15 */
    ".global _FUN_06030b68\n"
    "_FUN_06030b68:\n"
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x50EA\n"  /* mov.l @(0x28,r14),r0 */
    ".word 0x6653\n"  /* mov r5,r6 */
    ".word 0x3608\n"  /* sub r0,r6 */
    ".word 0x666F\n"  /* exts.w r6,r6 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06030B84] = 0x00006FFF} */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x06030B88] = 0x00001000} */
    ".word 0x3363\n"  /* cmp/ge r6,r3 */
    ".word 0x8908\n"  /* bt 0x06030B8C */
    ".word 0x3623\n"  /* cmp/ge r2,r6 */
    ".word 0x8906\n"  /* bt 0x06030B8C */
    ".word 0xADD6\n"  /* bra 0x0603072E */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x6FFF\n"  /* exts.w r15,r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8903\n"  /* bt 0x06030B9C */
    ".word 0x3263\n"  /* cmp/ge r6,r2 */
    ".word 0x8901\n"  /* bt 0x06030B9C */
    ".word 0xADC9\n"  /* bra 0x0603072E */
    ".word 0x0009\n"  /* nop */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06030BC4] = 0x06089595} */
    ".word 0xE901\n"  /* mov #1,r9 */
    ".word 0x2090\n"  /* mov.b r9,@r0 */
    ".word 0x980B\n"  /* mov.w @(0x16,PC),r8 */
    ".word 0xE904\n"  /* mov #4,r9 */
    ".word 0x38EC\n"  /* add r14,r8 */
    ".word 0x2891\n"  /* mov.w r9,@r8 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8908\n"  /* bt 0x06030BC8 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8926\n"  /* bt 0x06030C08 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8914\n"  /* bt 0x06030BE8 */
    ".word 0xA033\n"  /* bra 0x06030C28 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0150\n"  /* .word 0x0150 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9595\n"  /* mov.w @(0x12A,PC),r5 */
    ".word 0x50E0\n"  /* mov.l @(0x0,r14),r0 */
    ".word 0x9409\n"  /* mov.w @(0x12,PC),r4 */
    ".word 0x204B\n"  /* or r4,r0 */
    ".word 0x1E00\n"  /* mov.l r0,@(0x0,r14) */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x9006\n"  /* mov.w @(0xC,PC),r0 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x06030BE4] = 0x06063E9C} */
    ".word 0x8517\n"  /* mov.w @(0xE,r1),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0xA034\n"  /* bra 0x06030C48 */
    ".word 0x5414\n"  /* mov.l @(0x10,r1),r4 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0260\n"  /* .word 0x0260 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E9C\n"  /* add r9,r14 */
    ".word 0x50E0\n"  /* mov.l @(0x0,r14),r0 */
    ".word 0x9409\n"  /* mov.w @(0x12,PC),r4 */
    ".word 0x204B\n"  /* or r4,r0 */
    ".word 0x1E00\n"  /* mov.l r0,@(0x0,r14) */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x9006\n"  /* mov.w @(0xC,PC),r0 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x06030C04] = 0x06063EC4} */
    ".word 0x8517\n"  /* mov.w @(0xE,r1),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0xA024\n"  /* bra 0x06030C48 */
    ".word 0x5414\n"  /* mov.l @(0x10,r1),r4 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0260\n"  /* .word 0x0260 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EC4\n"  /* .word 0x3EC4 */
    ".word 0x50E0\n"  /* mov.l @(0x0,r14),r0 */
    ".word 0x9409\n"  /* mov.w @(0x12,PC),r4 */
    ".word 0x204B\n"  /* or r4,r0 */
    ".word 0x1E00\n"  /* mov.l r0,@(0x0,r14) */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0x9006\n"  /* mov.w @(0xC,PC),r0 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x06030C24] = 0x06063EB0} */
    ".word 0x8517\n"  /* mov.w @(0xE,r1),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0xA05E\n"  /* bra 0x06030CDC */
    ".word 0x5414\n"  /* mov.l @(0x10,r1),r4 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0260\n"  /* .word 0x0260 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EB0\n"  /* cmp/eq r11,r14 */
    ".word 0x50E0\n"  /* mov.l @(0x0,r14),r0 */
    ".word 0x9409\n"  /* mov.w @(0x12,PC),r4 */
    ".word 0x204B\n"  /* or r4,r0 */
    ".word 0x1E00\n"  /* mov.l r0,@(0x0,r14) */
    ".word 0xE403\n"  /* mov #3,r4 */
    ".word 0x9006\n"  /* mov.w @(0xC,PC),r0 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x06030C44] = 0x06063ED8} */
    ".word 0x8517\n"  /* mov.w @(0xE,r1),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0xA04E\n"  /* bra 0x06030CDC */
    ".word 0x5414\n"  /* mov.l @(0x10,r1),r4 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0260\n"  /* .word 0x0260 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3ED8\n"  /* sub r13,r14 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0xD220\n"  /* mov.l @(0x80,PC),r2  {[0x06030CCC] = 0x0602FD9B} */
    ".word 0x6520\n"  /* mov.b @r2,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B01\n"  /* bf 0x06030C56 */
    ".word 0xE605\n"  /* mov #5,r6 */
    ".word 0x2260\n"  /* mov.b r6,@r2 */
    ".word 0x55EA\n"  /* mov.l @(0x28,r14),r5 */
    ".word 0x3548\n"  /* sub r4,r5 */
    ".word 0x4511\n"  /* cmp/pz r5 */
    ".word 0x8900\n"  /* bt 0x06030C60 */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0x9633\n"  /* mov.w @(0x66,PC),r6 */
    ".word 0x3657\n"  /* cmp/gt r5,r6 */
    ".word 0x8905\n"  /* bt 0x06030C72 */
    ".word 0x6263\n"  /* mov r6,r2 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x326C\n"  /* add r6,r2 */
    ".word 0x3527\n"  /* cmp/gt r2,r5 */
    ".word 0x8900\n"  /* bt 0x06030C72 */
    ".word 0x346C\n"  /* add r6,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x1E4C\n"  /* mov.l r4,@(0x30,r14) */
    ".word 0x1E4A\n"  /* mov.l r4,@(0x28,r14) */
    ".word 0xD115\n"  /* mov.l @(0x54,PC),r1  {[0x06030CD0] = 0x060A6000} */
    ".word 0xE234\n"  /* mov #52,r2 */
    ".word 0x232F\n"  /* muls.w r2,r3 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0xED01\n"  /* mov #1,r13 */
    ".word 0x5814\n"  /* mov.l @(0x10,r1),r8 */
    ".word 0x4D28\n"  /* shll16 r13 */
    ".word 0x5A15\n"  /* mov.l @(0x14,r1),r10 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x4D18\n"  /* shll8 r13 */
    ".word 0x358D\n"  /* dmuls.l r8,r5 */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x5010\n"  /* mov.l @(0x0,r1),r0 */
    ".word 0x040A\n"  /* sts mach,r4 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x2D08\n"  /* tst r0,r13 */
    ".word 0x254D\n"  /* .word 0x254D */
    ".word 0x4019\n"  /* shlr8 r0 */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0xC901\n"  /* and #0x01,r0 */
    ".word 0x8F02\n"  /* bf/s 0x06030CAC */
    ".word 0x35AC\n"  /* add r10,r5 */
    ".word 0x356C\n"  /* add r6,r5 */
    ".word 0xE901\n"  /* mov #1,r9 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x4515\n"  /* cmp/pl r5 */
    ".word 0x8900\n"  /* bt 0x06030CB4 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x3600\n"  /* cmp/eq r0,r6 */
    ".word 0x8900\n"  /* bt 0x06030CBC */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x6083\n"  /* mov r8,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8F07\n"  /* bf/s 0x06030CD4 */
    ".word 0x6093\n"  /* mov r9,r0 */
    ".word 0xA031\n"  /* bra 0x06030D2C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD9B\n"  /* .word 0xFD9B */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B3D\n"  /* bf 0x06030D54 */
    ".word 0xA02F\n"  /* bra 0x06030D3A */
    ".word 0x0009\n"  /* nop */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x06030D24] = 0x0602FD9C} */
    ".word 0x6520\n"  /* mov.b @r2,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B01\n"  /* bf 0x06030CEA */
    ".word 0xE605\n"  /* mov #5,r6 */
    ".word 0x2260\n"  /* mov.b r6,@r2 */
    ".word 0x55EA\n"  /* mov.l @(0x28,r14),r5 */
    ".word 0x3548\n"  /* sub r4,r5 */
    ".word 0x4511\n"  /* cmp/pz r5 */
    ".word 0x8900\n"  /* bt 0x06030CF4 */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0x9615\n"  /* mov.w @(0x2A,PC),r6 */
    ".word 0x3657\n"  /* cmp/gt r5,r6 */
    ".word 0x8905\n"  /* bt 0x06030D06 */
    ".word 0x6263\n"  /* mov r6,r2 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x326C\n"  /* add r6,r2 */
    ".word 0x3527\n"  /* cmp/gt r2,r5 */
    ".word 0x8900\n"  /* bt 0x06030D06 */
    ".word 0x346C\n"  /* add r6,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0x1E4C\n"  /* mov.l r4,@(0x30,r14) */
    ".word 0x1E4A\n"  /* mov.l r4,@(0x28,r14) */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x06030D28] = 0x060A6000} */
    ".word 0xE234\n"  /* mov #52,r2 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x232F\n"  /* muls.w r2,r3 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0xED01\n"  /* mov #1,r13 */
    ".word 0x5814\n"  /* mov.l @(0x10,r1),r8 */
    ".word 0x4D28\n"  /* shll16 r13 */
    ".word 0xAFB5\n"  /* bra 0x06030C8C */
    ".word 0x5A15\n"  /* mov.l @(0x14,r1),r10 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD9C\n"  /* .word 0xFD9C */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x55E6\n"  /* mov.l @(0x18,r14),r5 */
    ".word 0x35AC\n"  /* add r10,r5 */
    ".word 0x4515\n"  /* cmp/pl r5 */
    ".word 0x8900\n"  /* bt 0x06030D36 */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0xA062\n"  /* bra 0x06030DFE */
    ".word 0x0009\n"  /* nop */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06030D50] = 0x0602755C} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x3508\n"  /* sub r0,r5 */
    ".word 0x4515\n"  /* cmp/pl r5 */
    ".word 0x8900\n"  /* bt 0x06030D4C */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0xA057\n"  /* bra 0x06030DFE */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x52E6\n"  /* mov.l @(0x18,r14),r2 */
    ".word 0x32AC\n"  /* add r10,r2 */
    ".word 0x638B\n"  /* neg r8,r3 */
    ".word 0x332D\n"  /* dmuls.l r2,r3 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x4528\n"  /* shll16 r5 */
    ".word 0x941F\n"  /* mov.w @(0x3E,PC),r4 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8B02\n"  /* bf 0x06030D70 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x3247\n"  /* cmp/gt r4,r2 */
    ".word 0x891B\n"  /* bt 0x06030DA8 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4329\n"  /* shlr16 r3 */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x54E4\n"  /* mov.l @(0x10,r14),r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x628B\n"  /* neg r8,r2 */
    ".word 0x322D\n"  /* dmuls.l r2,r2 */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x223D\n"  /* .word 0x223D */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x06030DA4] = 0x0602755C} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0xA00E\n"  /* bra 0x06030DBE */
    ".word 0x0009\n"  /* nop */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x232D\n"  /* .word 0x232D */
    ".word 0x54E4\n"  /* mov.l @(0x10,r14),r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x628B\n"  /* neg r8,r2 */
    ".word 0x322D\n"  /* dmuls.l r2,r2 */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x223D\n"  /* .word 0x223D */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06030DF0] = 0x0602755C} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x638B\n"  /* neg r8,r3 */
    ".word 0x323D\n"  /* dmuls.l r3,r2 */
    ".word 0x65AB\n"  /* neg r10,r5 */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x223D\n"  /* .word 0x223D */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x52E4\n"  /* mov.l @(0x10,r14),r2 */
    ".word 0x53E6\n"  /* mov.l @(0x18,r14),r3 */
    ".word 0x3028\n"  /* sub r2,r0 */
    ".word 0x3538\n"  /* sub r3,r5 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8900\n"  /* bt 0x06030DDC */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4515\n"  /* cmp/pl r5 */
    ".word 0x8900\n"  /* bt 0x06030DE2 */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0x3507\n"  /* cmp/gt r0,r5 */
    ".word 0x8906\n"  /* bt 0x06030DF4 */
    ".word 0x4521\n"  /* shar r5 */
    ".word 0x4521\n"  /* shar r5 */
    ".word 0xA006\n"  /* bra 0x06030DFA */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0xA000\n"  /* bra 0x06030DFE */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_06030dfe\n"
    "_FUN_06030dfe:\n"
    ".word 0xD90A\n"  /* mov.l @(0x28,PC),r9  {[0x06030E28] = 0x06030FBC} */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6991\n"  /* mov.w @r9,r9 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2DD8\n"  /* tst r13,r13 */
    ".word 0x8913\n"  /* bt 0x06030E34 */
    ".word 0x54EC\n"  /* mov.l @(0x30,r14),r4 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06030E2C] = 0x06027348} */
    ".word 0xDA07\n"  /* mov.l @(0x1C,PC),r10  {[0x06030E30] = 0x00038000} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8900\n"  /* bt 0x06030E1C */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x3A0D\n"  /* dmuls.l r0,r10 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0xA008\n"  /* bra 0x06030E36 */
    ".word 0x220D\n"  /* .word 0x220D */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0FBC\n"  /* mov.b @(r0,r11),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06030E44] = 0x00013333} */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8D06\n"  /* bt/s 0x06030E48 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0xA008\n"  /* bra 0x06030E52 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x3333\n"  /* cmp/ge r3,r3 */
    ".word 0x3258\n"  /* sub r5,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8901\n"  /* bt 0x06030E52 */
    ".word 0xA03D\n"  /* bra 0x06030ECC */
    ".word 0x0009\n"  /* nop */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x1E5E\n"  /* mov.l r5,@(0x38,r14) */
    ".word 0x1E6F\n"  /* mov.l r6,@(0x3C,r14) */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06030EB0] = 0x06027344} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06030E64, \"ax\"\n"

    ".global _FUN_06030E64\n"
    ".type _FUN_06030E64, @function\n"
    "_FUN_06030E64:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06030EB4] = 0x06027348} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06030E72, \"ax\"\n"

    ".global _FUN_06030E72\n"
    ".type _FUN_06030E72, @function\n"
    "_FUN_06030E72:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x230D\n"  /* .word 0x230D */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1E54\n"  /* mov.l r5,@(0x10,r14) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1E66\n"  /* mov.l r6,@(0x18,r14) */
    ".word 0x53E3\n"  /* mov.l @(0xC,r14),r3 */
    ".word 0x9A0B\n"  /* mov.w @(0x16,PC),r10 */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x06030EB8] = 0x0000DEB8} */
    ".word 0x3AEC\n"  /* add r14,r10 */
    ".word 0x69A1\n"  /* mov.w @r10,r9 */
    ".word 0xE808\n"  /* mov #8,r8 */
    ".word 0x3983\n"  /* cmp/ge r8,r9 */
    ".word 0x890E\n"  /* bt 0x06030EC0 */
    ".word 0x78FE\n"  /* add #-2,r8 */
    ".word 0x3983\n"  /* cmp/ge r8,r9 */
    ".word 0x8B0C\n"  /* bf 0x06030EC2 */
    ".word 0xD404\n"  /* mov.l @(0x10,PC),r4  {[0x06030EBC] = 0x0000FAE1} */
    ".word 0xA00A\n"  /* bra 0x06030EC2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x007C\n"  /* mov.b @(r0,r7),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xDEB8\n"  /* mov.l @(0x2E0,PC),r14  {[0x0603119C] = 0x53EA33A8} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFAE1\n"  /* .word 0xFAE1 */
    ".word 0xD406\n"  /* mov.l @(0x18,PC),r4  {[0x06030EDC] = 0x0000C000} */
    ".word 0x343D\n"  /* dmuls.l r3,r4 */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x243D\n"  /* .word 0x243D */
    ".word 0x1E43\n"  /* mov.l r4,@(0xC,r14) */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x9008\n"  /* mov.w @(0x10,PC),r0 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x06030EF8] = 0x0607E940} */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0x023D\n"  /* mov.w @(r0,r3),r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8B01\n"  /* bf 0x06030EF0 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x0325\n"  /* mov.w r2,@(r0,r3) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0150\n"  /* .word 0x0150 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE940\n"  /* mov #64,r9 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDC04\n"  /* mov.l @(0x10,PC),r12  {[0x06030F14] = 0x0601D5F4} */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x06030F18] = 0xAE1102FF} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x060312E8] = 0x63F6D514} */
    ".word 0xAE11\n"  /* bra 0x06030B3E */
    ".word 0x02FF\n"  /* mac.l @r15+,@r2+ */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x07E8\n"  /* .word 0x07E8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x07B8\n"  /* .word 0x07B8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0788\n"  /* .word 0x0788 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x0758\n"  /* .word 0x0758 */
    ".word 0x0122\n"  /* stc vbr,r1 */
    ".word 0x0122\n"  /* stc vbr,r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0140\n"  /* .word 0x0140 */
    ".word 0x0118\n"  /* .word 0x0118 */
    ".word 0x0118\n"  /* .word 0x0118 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x011D\n"  /* mov.w @(r0,r1),r1 */
    ".word 0x0122\n"  /* stc vbr,r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0136\n"  /* mov.l r3,@(r0,r1) */
    ".word 0x0113\n"  /* .word 0x0113 */
    ".word 0x0118\n"  /* .word 0x0118 */
    ".word 0x0122\n"  /* stc vbr,r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".global _FUN_06030fc0\n"
    "_FUN_06030fc0:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06030FCC, \"ax\"\n"

    ".global _FUN_06030FCC\n"
    ".type _FUN_06030FCC, @function\n"
    "_FUN_06030FCC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x6D53\n"  /* mov r5,r13 */
    ".word 0x6C63\n"  /* mov r6,r12 */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x52D3\n"  /* mov.l @(0xC,r13),r2 */
    ".word 0x3127\n"  /* cmp/gt r2,r1 */
    ".word 0x8904\n"  /* bt 0x06030FE8 */
    ".word 0x58E4\n"  /* mov.l @(0x10,r14),r8 */
    ".word 0x59E6\n"  /* mov.l @(0x18,r14),r9 */
    ".word 0x56D4\n"  /* mov.l @(0x10,r13),r6 */
    ".word 0xA1C3\n"  /* bra 0x0603136E */
    ".word 0x57D6\n"  /* mov.l @(0x18,r13),r7 */
    ".word 0x56E4\n"  /* mov.l @(0x10,r14),r6 */
    ".word 0x57E6\n"  /* mov.l @(0x18,r14),r7 */
    ".word 0x58D4\n"  /* mov.l @(0x10,r13),r8 */
    ".word 0x59D6\n"  /* mov.l @(0x18,r13),r9 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x3578\n"  /* sub r7,r5 */
    ".word 0xD030\n"  /* mov.l @(0xC0,PC),r0  {[0x060310BC] = 0x0602744C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06030FFC, \"ax\"\n"

    ".global _FUN_06030FFC\n"
    ".type _FUN_06030FFC, @function\n"
    "_FUN_06030FFC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6A0B\n"  /* neg r0,r10 */
    ".word 0x6AAF\n"  /* exts.w r10,r10 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x56EE\n"  /* mov.l @(0x38,r14),r6 */
    ".word 0x57EF\n"  /* mov.l @(0x3C,r14),r7 */
    ".word 0x58DE\n"  /* mov.l @(0x38,r13),r8 */
    ".word 0x59DF\n"  /* mov.l @(0x3C,r13),r9 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x3578\n"  /* sub r7,r5 */
    ".word 0xD027\n"  /* mov.l @(0x9C,PC),r0  {[0x060310BC] = 0x0602744C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603101E, \"ax\"\n"

    ".global _FUN_0603101E\n"
    ".type _FUN_0603101E, @function\n"
    "_FUN_0603101E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6B0B\n"  /* neg r0,r11 */
    ".word 0x6BBF\n"  /* exts.w r11,r11 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0x9443\n"  /* mov.w @(0x86,PC),r4 */
    ".word 0x51EC\n"  /* mov.l @(0x30,r14),r1 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0xE701\n"  /* mov #1,r7 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x66BD\n"  /* extu.w r11,r6 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x263B\n"  /* or r3,r6 */
    ".word 0x3168\n"  /* sub r6,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8900\n"  /* bt 0x06031046 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8901\n"  /* bt 0x06031050 */
    ".word 0x3148\n"  /* sub r4,r1 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x51EC\n"  /* mov.l @(0x30,r14),r1 */
    ".word 0xE801\n"  /* mov #1,r8 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x66AD\n"  /* extu.w r10,r6 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x263B\n"  /* or r3,r6 */
    ".word 0x3168\n"  /* sub r6,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8D01\n"  /* bt/s 0x06031066 */
    ".word 0x52DC\n"  /* mov.l @(0x30,r13),r2 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0xB16A\n"  /* bsr 0x06031340 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8901\n"  /* bt 0x06031074 */
    ".word 0x3148\n"  /* sub r4,r1 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x3870\n"  /* cmp/eq r7,r8 */
    ".word 0x8900\n"  /* bt 0x0603107A */
    ".word 0xE901\n"  /* mov #1,r9 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x6413\n"  /* mov r1,r4 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060310C0] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x32A8\n"  /* sub r10,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8D01\n"  /* bt/s 0x06031092 */
    ".word 0x4119\n"  /* shlr8 r1 */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xE30A\n"  /* mov #10,r3 */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8903\n"  /* bt 0x060310A4 */
    ".word 0xE337\n"  /* mov #55,r3 */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x8900\n"  /* bt 0x060310A4 */
    ".word 0xE701\n"  /* mov #1,r7 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4219\n"  /* shlr8 r2 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x890E\n"  /* bt 0x060310CE */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x8907\n"  /* bt 0x060310C4 */
    ".word 0xA007\n"  /* bra 0x060310C6 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x744C\n"  /* add #76,r4 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0xE801\n"  /* mov #1,r8 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8901\n"  /* bt 0x060310CE */
    ".word 0xA00D\n"  /* bra 0x060310E8 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x060310E4] = 0x0605BCC8} */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6412\n"  /* mov.l @r1,r4 */
    ".word 0x34C8\n"  /* sub r12,r4 */
    ".word 0x6C22\n"  /* mov.l @r2,r12 */
    ".word 0x34CC\n"  /* add r12,r4 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8903\n"  /* bt 0x060310E8 */
    ".word 0xA11F\n"  /* bra 0x06031322 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBCC8\n"  /* bsr 0x06030A7A */
    ".word 0x51EA\n"  /* mov.l @(0x28,r14),r1 */
    ".word 0x52DA\n"  /* mov.l @(0x28,r13),r2 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x931D\n"  /* mov.w @(0x3A,PC),r3 */
    ".word 0xEB00\n"  /* mov #0,r11 */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8923\n"  /* bt 0x06031140 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x891E\n"  /* bt 0x06031140 */
    ".word 0xEB01\n"  /* mov #1,r11 */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x53D3\n"  /* mov.l @(0xC,r13),r3 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x06031134] = 0x00042AAA} */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x8972\n"  /* bt 0x060311F6 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x50D0\n"  /* mov.l @(0x0,r13),r0 */
    ".word 0xD408\n"  /* mov.l @(0x20,PC),r4  {[0x06031138] = 0x08000000} */
    ".word 0x204B\n"  /* or r4,r0 */
    ".word 0x1D00\n"  /* mov.l r0,@(0x0,r13) */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0603113C] = 0x06008460} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9005\n"  /* mov.w @(0xA,PC),r0 */
    ".word 0x9405\n"  /* mov.w @(0xA,PC),r4 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0xA064\n"  /* bra 0x060311F6 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x00CC\n"  /* mov.b @(r0,r12),r0 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x2AAA\n"  /* xor r10,r10 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06008460 */
    ".word 0x8460\n"  /* mov.b @(0x0,r6),r0 */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x53D3\n"  /* mov.l @(0xC,r13),r3 */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x0603118C] = 0x00042AAA} */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x890D\n"  /* bt 0x06031168 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x50D0\n"  /* mov.l @(0x0,r13),r0 */
    ".word 0xD40F\n"  /* mov.l @(0x3C,PC),r4  {[0x06031190] = 0x08000000} */
    ".word 0x204B\n"  /* or r4,r0 */
    ".word 0x1D00\n"  /* mov.l r0,@(0x0,r13) */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06031194] = 0x06008460} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9013\n"  /* mov.w @(0x26,PC),r0 */
    ".word 0x9413\n"  /* mov.w @(0x26,PC),r4 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B17\n"  /* bf 0x0603119C */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x53D3\n"  /* mov.l @(0xC,r13),r3 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x3217\n"  /* cmp/gt r1,r2 */
    ".word 0x8911\n"  /* bt 0x0603119C */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x52E0\n"  /* mov.l @(0x0,r14),r2 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06031198] = 0x20000000} */
    ".word 0x8900\n"  /* bt 0x06031182 */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0xA037\n"  /* bra 0x060311F6 */
    ".word 0x1E20\n"  /* mov.l r2,@(0x0,r14) */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x00CC\n"  /* mov.b @(r0,r12),r0 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x2AAA\n"  /* xor r10,r10 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_06008460 */
    ".word 0x8460\n"  /* mov.b @(0x0,r6),r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x53EA\n"  /* mov.l @(0x28,r14),r3 */
    ".word 0x33A8\n"  /* sub r10,r3 */
    ".word 0x9209\n"  /* mov.w @(0x12,PC),r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8907\n"  /* bt 0x060311B8 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8902\n"  /* bt 0x060311B8 */
    ".word 0xA020\n"  /* bra 0x060311F6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8905\n"  /* bt 0x060311CC */
    ".word 0x54EC\n"  /* mov.l @(0x30,r14),r4 */
    ".word 0x1D4C\n"  /* mov.l r4,@(0x30,r13) */
    ".word 0x9120\n"  /* mov.w @(0x40,PC),r1 */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x31DC\n"  /* add r13,r1 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0603120C] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x52D3\n"  /* mov.l @(0xC,r13),r2 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x4109\n"  /* shlr2 r1 */
    ".word 0x310D\n"  /* dmuls.l r0,r1 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x9310\n"  /* mov.w @(0x20,PC),r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x54E3\n"  /* mov.l @(0xC,r14),r4 */
    ".word 0x3418\n"  /* sub r1,r4 */
    ".word 0x1E43\n"  /* mov.l r4,@(0xC,r14) */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B0C\n"  /* bf 0x06031214 */
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x06031210] = 0x0602FD9A} */
    ".word 0x6350\n"  /* mov.b @r5,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B3D\n"  /* bf 0x0603127E */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0xA03B\n"  /* bra 0x0603127E */
    ".word 0x2530\n"  /* mov.b r3,@r5 */
    ".word 0x0208\n"  /* .word 0x0208 */
    ".word 0x0194\n"  /* mov.b r9,@(r0,r1) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD9A\n"  /* .word 0xFD9A */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0xD507\n"  /* mov.l @(0x1C,PC),r5  {[0x06031238] = 0x0602FD98} */
    ".word 0x52E0\n"  /* mov.l @(0x0,r14),r2 */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0xDA07\n"  /* mov.l @(0x1C,PC),r10  {[0x0603123C] = 0x06031A24} */
    ".word 0x8B0E\n"  /* bf 0x06031240 */
    ".word 0x6AA1\n"  /* mov.w @r10,r10 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0xE380\n"  /* mov #-128,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2AA8\n"  /* tst r10,r10 */
    ".word 0x890D\n"  /* bt 0x0603124A */
    ".word 0x9301\n"  /* mov.w @(0x2,PC),r3 */
    ".word 0xA00B\n"  /* bra 0x0603124A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD98\n"  /* .word 0xFD98 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A24\n"  /* mov.l r2,@(0x10,r10) */
    ".word 0x6AA1\n"  /* mov.w @r10,r10 */
    ".word 0xE340\n"  /* mov #64,r3 */
    ".word 0x2AA8\n"  /* tst r10,r10 */
    ".word 0x8900\n"  /* bt 0x0603124A */
    ".word 0x9328\n"  /* mov.w @(0x50,PC),r3 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0x1E20\n"  /* mov.l r2,@(0x0,r14) */
    ".word 0x6450\n"  /* mov.b @r5,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B01\n"  /* bf 0x06031258 */
    ".word 0xE403\n"  /* mov #3,r4 */
    ".word 0x2540\n"  /* mov.b r4,@r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x931F\n"  /* mov.w @(0x3E,PC),r3 */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x5AEC\n"  /* mov.l @(0x30,r14),r10 */
    ".word 0x8F03\n"  /* bf/s 0x0603126C */
    ".word 0x6AAD\n"  /* extu.w r10,r10 */
    ".word 0x6733\n"  /* mov r3,r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x337C\n"  /* add r7,r3 */
    ".word 0x340D\n"  /* dmuls.l r0,r4 */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x240D\n"  /* .word 0x240D */
    ".word 0x8901\n"  /* bt 0x0603127E */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x060312A4] = 0x0000D999} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x930F\n"  /* mov.w @(0x1E,PC),r3 */
    ".word 0x33EC\n"  /* add r14,r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0xE508\n"  /* mov #8,r5 */
    ".word 0x3053\n"  /* cmp/ge r5,r0 */
    ".word 0x8912\n"  /* bt 0x060312B0 */
    ".word 0x75FE\n"  /* add #-2,r5 */
    ".word 0x3053\n"  /* cmp/ge r5,r0 */
    ".word 0x890B\n"  /* bt 0x060312A8 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0xA00C\n"  /* bra 0x060312B4 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x007C\n"  /* mov.b @(r0,r7),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD999\n"  /* mov.l @(0x264,PC),r9  {[0x0603150C] = 0x321C3323} */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA002\n"  /* bra 0x060312B4 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55D4\n"  /* mov.l @(0x10,r13),r5 */
    ".word 0x56D6\n"  /* mov.l @(0x18,r13),r6 */
    ".word 0x1D5E\n"  /* mov.l r5,@(0x38,r13) */
    ".word 0x1D6F\n"  /* mov.l r6,@(0x3C,r13) */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x06031334] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06031338] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1D54\n"  /* mov.l r5,@(0x10,r13) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1D66\n"  /* mov.l r6,@(0x18,r13) */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0xD514\n"  /* mov.l @(0x50,PC),r5  {[0x0603133C] = 0x00008000} */
    ".word 0x3A5C\n"  /* add r5,r10 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x1E5E\n"  /* mov.l r5,@(0x38,r14) */
    ".word 0x1E6F\n"  /* mov.l r6,@(0x3C,r14) */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06031334] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x06031338] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1E54\n"  /* mov.l r5,@(0x10,r14) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1E66\n"  /* mov.l r6,@(0x18,r14) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".global _FUN_06031340\n"
    "_FUN_06031340:\n"
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x940A\n"  /* mov.w @(0x14,PC),r4 */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0x3413\n"  /* cmp/ge r1,r4 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x890A\n"  /* bt 0x06031364 */
    ".word 0x345C\n"  /* add r5,r4 */
    ".word 0x3143\n"  /* cmp/ge r4,r1 */
    ".word 0xD503\n"  /* mov.l @(0xC,PC),r5  {[0x06031360] = 0x06031A24} */
    ".word 0x8906\n"  /* bt 0x06031364 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xA006\n"  /* bra 0x06031368 */
    ".word 0x2541\n"  /* mov.w r4,@r5 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A24\n"  /* mov.l r2,@(0x10,r10) */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x2541\n"  /* mov.w r4,@r5 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x000B\n"  /* rts */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".global _FUN_0603136e\n"
    "_FUN_0603136e:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x3578\n"  /* sub r7,r5 */
    ".word 0xD030\n"  /* mov.l @(0xC0,PC),r0  {[0x0603143C] = 0x0602744C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603137A, \"ax\"\n"

    ".global _FUN_0603137A\n"
    ".type _FUN_0603137A, @function\n"
    "_FUN_0603137A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6A0B\n"  /* neg r0,r10 */
    ".word 0x6AAF\n"  /* exts.w r10,r10 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x58EE\n"  /* mov.l @(0x38,r14),r8 */
    ".word 0x59EF\n"  /* mov.l @(0x3C,r14),r9 */
    ".word 0x56DE\n"  /* mov.l @(0x38,r13),r6 */
    ".word 0x57DF\n"  /* mov.l @(0x3C,r13),r7 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x3578\n"  /* sub r7,r5 */
    ".word 0xD028\n"  /* mov.l @(0xA0,PC),r0  {[0x0603143C] = 0x0602744C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603139C, \"ax\"\n"

    ".global _FUN_0603139C\n"
    ".type _FUN_0603139C, @function\n"
    "_FUN_0603139C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6B0B\n"  /* neg r0,r11 */
    ".word 0x6BBF\n"  /* exts.w r11,r11 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0x9445\n"  /* mov.w @(0x8A,PC),r4 */
    ".word 0x51DC\n"  /* mov.l @(0x30,r13),r1 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x611F\n"  /* exts.w r1,r1 */
    ".word 0xE701\n"  /* mov #1,r7 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x66BD\n"  /* extu.w r11,r6 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x263B\n"  /* or r3,r6 */
    ".word 0x3168\n"  /* sub r6,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8900\n"  /* bt 0x060313C6 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8901\n"  /* bt 0x060313D0 */
    ".word 0x3148\n"  /* sub r4,r1 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x51DC\n"  /* mov.l @(0x30,r13),r1 */
    ".word 0xE801\n"  /* mov #1,r8 */
    ".word 0x611F\n"  /* exts.w r1,r1 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x66AD\n"  /* extu.w r10,r6 */
    ".word 0x263B\n"  /* or r3,r6 */
    ".word 0x3168\n"  /* sub r6,r1 */
    ".word 0x4115\n"  /* cmp/pl r1 */
    ".word 0x8D01\n"  /* bt/s 0x060313E8 */
    ".word 0x52EC\n"  /* mov.l @(0x30,r14),r2 */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0xBFA9\n"  /* bsr 0x06031340 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8901\n"  /* bt 0x060313F6 */
    ".word 0x3148\n"  /* sub r4,r1 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x3870\n"  /* cmp/eq r7,r8 */
    ".word 0x8900\n"  /* bt 0x060313FC */
    ".word 0xE901\n"  /* mov #1,r9 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x6413\n"  /* mov r1,r4 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x06031440] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x32A8\n"  /* sub r10,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8D01\n"  /* bt/s 0x06031414 */
    ".word 0x4119\n"  /* shlr8 r1 */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0xE30A\n"  /* mov #10,r3 */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8903\n"  /* bt 0x06031426 */
    ".word 0xE337\n"  /* mov #55,r3 */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x8900\n"  /* bt 0x06031426 */
    ".word 0xE701\n"  /* mov #1,r7 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4219\n"  /* shlr8 r2 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x890D\n"  /* bt 0x0603144E */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x8906\n"  /* bt 0x06031444 */
    ".word 0xA006\n"  /* bra 0x06031446 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x744C\n"  /* add #76,r4 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0xE801\n"  /* mov #1,r8 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8901\n"  /* bt 0x0603144E */
    ".word 0xA00D\n"  /* bra 0x06031468 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x06031464] = 0x0605BCC8} */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6412\n"  /* mov.l @r1,r4 */
    ".word 0x34C8\n"  /* sub r12,r4 */
    ".word 0x6C22\n"  /* mov.l @r2,r12 */
    ".word 0x34CC\n"  /* add r12,r4 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8903\n"  /* bt 0x06031468 */
    ".word 0xAF5F\n"  /* bra 0x06031322 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBCC8\n"  /* bsr 0x06030DFA */
    ".word 0x51EA\n"  /* mov.l @(0x28,r14),r1 */
    ".word 0x52DA\n"  /* mov.l @(0x28,r13),r2 */
    ".word 0xEB00\n"  /* mov #0,r11 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x9310\n"  /* mov.w @(0x20,PC),r3 */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8919\n"  /* bt 0x060314AC */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x8914\n"  /* bt 0x060314AC */
    ".word 0xEB01\n"  /* mov #1,r11 */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x53D3\n"  /* mov.l @(0xC,r13),r3 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06031498] = 0x00042AAA} */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x8B04\n"  /* bf 0x0603149C */
    ".word 0xA060\n"  /* bra 0x06031556 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x2AAA\n"  /* xor r10,r10 */
    ".word 0x51D0\n"  /* mov.l @(0x0,r13),r1 */
    ".word 0xD302\n"  /* mov.l @(0x8,PC),r3  {[0x060314A8] = 0x08000000} */
    ".word 0x213B\n"  /* or r3,r1 */
    ".word 0x1D10\n"  /* mov.l r1,@(0x0,r13) */
    ".word 0xA057\n"  /* bra 0x06031556 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x51D3\n"  /* mov.l @(0xC,r13),r1 */
    ".word 0x53E3\n"  /* mov.l @(0xC,r14),r3 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x060314C8] = 0x00042AAA} */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x890A\n"  /* bt 0x060314D0 */
    ".word 0x51D0\n"  /* mov.l @(0x0,r13),r1 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x060314CC] = 0x08000000} */
    ".word 0x213B\n"  /* or r3,r1 */
    ".word 0x1D10\n"  /* mov.l r1,@(0x0,r13) */
    ".word 0xA048\n"  /* bra 0x06031556 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x2AAA\n"  /* xor r10,r10 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B13\n"  /* bf 0x060314FC */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0xD207\n"  /* mov.l @(0x1C,PC),r2  {[0x060314F4] = 0x00042AAA} */
    ".word 0x53D3\n"  /* mov.l @(0xC,r13),r3 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x3318\n"  /* sub r1,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890C\n"  /* bt 0x060314FC */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x52D0\n"  /* mov.l @(0x0,r13),r2 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x060314F8] = 0x20000000} */
    ".word 0x8900\n"  /* bt 0x060314EC */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0xA032\n"  /* bra 0x06031556 */
    ".word 0x1D20\n"  /* mov.l r2,@(0x0,r13) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x2AAA\n"  /* xor r10,r10 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x53DA\n"  /* mov.l @(0x28,r13),r3 */
    ".word 0x33A8\n"  /* sub r10,r3 */
    ".word 0x9209\n"  /* mov.w @(0x12,PC),r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8907\n"  /* bt 0x06031518 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8902\n"  /* bt 0x06031518 */
    ".word 0xA020\n"  /* bra 0x06031556 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8905\n"  /* bt 0x0603152C */
    ".word 0x54D8\n"  /* mov.l @(0x20,r13),r4 */
    ".word 0x1E4C\n"  /* mov.l r4,@(0x30,r14) */
    ".word 0x9121\n"  /* mov.w @(0x42,PC),r1 */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x31DC\n"  /* add r13,r1 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06031570] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x51D3\n"  /* mov.l @(0xC,r13),r1 */
    ".word 0x52E3\n"  /* mov.l @(0xC,r14),r2 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x310D\n"  /* dmuls.l r0,r1 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x4121\n"  /* shar r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x1E23\n"  /* mov.l r2,@(0xC,r14) */
    ".word 0x54D3\n"  /* mov.l @(0xC,r13),r4 */
    ".word 0x930F\n"  /* mov.w @(0x1E,PC),r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x3418\n"  /* sub r1,r4 */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B0D\n"  /* bf 0x06031578 */
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x06031574] = 0x0602FD9A} */
    ".word 0x6350\n"  /* mov.b @r5,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B53\n"  /* bf 0x0603160C */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0xA051\n"  /* bra 0x0603160C */
    ".word 0x2530\n"  /* mov.b r3,@r5 */
    ".word 0x0208\n"  /* .word 0x0208 */
    ".word 0x0194\n"  /* mov.b r9,@(r0,r1) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD9A\n"  /* .word 0xFD9A */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2BB8\n"  /* tst r11,r11 */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x06031590] = 0x0602FD98} */
    ".word 0xDA04\n"  /* mov.l @(0x10,PC),r10  {[0x06031594] = 0x06031A24} */
    ".word 0x52E0\n"  /* mov.l @(0x0,r14),r2 */
    ".word 0x6AA1\n"  /* mov.w @r10,r10 */
    ".word 0x8907\n"  /* bt 0x06031598 */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x8909\n"  /* bt 0x060315A0 */
    ".word 0xA011\n"  /* bra 0x060315B2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0xFD98\n"  /* .word 0xFD98 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1A24\n"  /* mov.l r2,@(0x10,r10) */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x8919\n"  /* bt 0x060315D0 */
    ".word 0xA010\n"  /* bra 0x060315C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x2AA8\n"  /* tst r10,r10 */
    ".word 0xE380\n"  /* mov #-128,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x8916\n"  /* bt 0x060315D8 */
    ".word 0x9301\n"  /* mov.w @(0x2,PC),r3 */
    ".word 0xA014\n"  /* bra 0x060315D8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x2AA8\n"  /* tst r10,r10 */
    ".word 0xE340\n"  /* mov #64,r3 */
    ".word 0x890F\n"  /* bt 0x060315D8 */
    ".word 0x9301\n"  /* mov.w @(0x2,PC),r3 */
    ".word 0xA00D\n"  /* bra 0x060315D8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x2AA8\n"  /* tst r10,r10 */
    ".word 0x9303\n"  /* mov.w @(0x6,PC),r3 */
    ".word 0x8907\n"  /* bt 0x060315D8 */
    ".word 0xE380\n"  /* mov #-128,r3 */
    ".word 0xA005\n"  /* bra 0x060315D8 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x2AA8\n"  /* tst r10,r10 */
    ".word 0x932A\n"  /* mov.w @(0x54,PC),r3 */
    ".word 0x8900\n"  /* bt 0x060315D8 */
    ".word 0xE340\n"  /* mov #64,r3 */
    ".word 0x6450\n"  /* mov.b @r5,r4 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x1E20\n"  /* mov.l r2,@(0x0,r14) */
    ".word 0x8B01\n"  /* bf 0x060315E6 */
    ".word 0xE403\n"  /* mov #3,r4 */
    ".word 0x2540\n"  /* mov.b r4,@r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x931F\n"  /* mov.w @(0x3E,PC),r3 */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x5ADC\n"  /* mov.l @(0x30,r13),r10 */
    ".word 0x8F03\n"  /* bf/s 0x060315FA */
    ".word 0x6AAD\n"  /* extu.w r10,r10 */
    ".word 0x6733\n"  /* mov r3,r7 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x337C\n"  /* add r7,r3 */
    ".word 0x340D\n"  /* dmuls.l r0,r4 */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x240D\n"  /* .word 0x240D */
    ".word 0x8901\n"  /* bt 0x0603160C */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06031630] = 0x0000D999} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x930F\n"  /* mov.w @(0x1E,PC),r3 */
    ".word 0x33EC\n"  /* add r14,r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0xE508\n"  /* mov #8,r5 */
    ".word 0x3053\n"  /* cmp/ge r5,r0 */
    ".word 0x8910\n"  /* bt 0x0603163A */
    ".word 0x75FE\n"  /* add #-2,r5 */
    ".word 0x3053\n"  /* cmp/ge r5,r0 */
    ".word 0x890A\n"  /* bt 0x06031634 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xA00B\n"  /* bra 0x06031640 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x007C\n"  /* mov.b @(r0,r7),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD999\n"  /* mov.l @(0x264,PC),r9  {[0x06031898] = 0x4F22400B} */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xA003\n"  /* bra 0x06031640 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x1E5E\n"  /* mov.l r5,@(0x38,r14) */
    ".word 0x1E6F\n"  /* mov.l r6,@(0x3C,r14) */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x060316B8] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x060316BC] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1E54\n"  /* mov.l r5,@(0x10,r14) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1E66\n"  /* mov.l r6,@(0x18,r14) */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x060316C0] = 0x00008000} */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x3A5C\n"  /* add r5,r10 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55D4\n"  /* mov.l @(0x10,r13),r5 */
    ".word 0x56D6\n"  /* mov.l @(0x18,r13),r6 */
    ".word 0x1D5E\n"  /* mov.l r5,@(0x38,r13) */
    ".word 0x1D6F\n"  /* mov.l r6,@(0x3C,r13) */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x060316B8] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x060316BC] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1D54\n"  /* mov.l r5,@(0x10,r13) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0xAE36\n"  /* bra 0x06031322 */
    ".word 0x1D66\n"  /* mov.l r6,@(0x18,r13) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".global _FUN_060316c4\n"
    "_FUN_060316c4:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
void car_collision_response(void) { }
__asm__(



    ".balign 2\n"
    ".global _collision_helper_first_car\n"
    ".type _collision_helper_first_car, @function\n"








    ".section .text.FUN_06031700, \"ax\"\n"

    ".global _FUN_06031700\n"
    "_collision_helper_first_car:\n"
    "_FUN_06031700:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6A0B\n"  /* neg r0,r10 */
    ".word 0x6AAF\n"  /* exts.w r10,r10 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x51E8\n"  /* mov.l @(0x20,r14),r1 */
    ".word 0x941E\n"  /* mov.w @(0x3C,PC),r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x31A8\n"  /* sub r10,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8D01\n"  /* bt/s 0x06031720 */
    ".word 0x52D8\n"  /* mov.l @(0x20,r13),r2 */
    ".word 0x3148\n"  /* sub r4,r1 */
    ".word 0x9416\n"  /* mov.w @(0x2C,PC),r4 */
    ".word 0x32A8\n"  /* sub r10,r2 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8D01\n"  /* bt/s 0x06031730 */
    ".word 0x4119\n"  /* shlr8 r1 */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4219\n"  /* shlr8 r2 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06031758] = 0x0605BCC8} */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6412\n"  /* mov.l @r1,r4 */
    ".word 0x34C8\n"  /* sub r12,r4 */
    ".word 0x6C22\n"  /* mov.l @r2,r12 */
    ".word 0x34CC\n"  /* add r12,r4 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8907\n"  /* bt 0x0603175C */
    ".word 0xA08E\n"  /* bra 0x0603186C */
    ".word 0x0009\n"  /* nop */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x744C\n"  /* add #76,r4 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBCC8\n"  /* bsr 0x060310EE */
    ".word 0x51EA\n"  /* mov.l @(0x28,r14),r1 */
    ".word 0x52DA\n"  /* mov.l @(0x28,r13),r2 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x9312\n"  /* mov.w @(0x24,PC),r3 */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8916\n"  /* bt 0x06031798 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x8911\n"  /* bt 0x06031798 */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x53D3\n"  /* mov.l @(0xC,r13),r3 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x06031790] = 0x0001638E} */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x893B\n"  /* bt 0x060317F8 */
    ".word 0x50D0\n"  /* mov.l @(0x0,r13),r0 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x06031794] = 0x08000000} */
    ".word 0x203B\n"  /* or r3,r0 */
    ".word 0x1D00\n"  /* mov.l r0,@(0x0,r13) */
    ".word 0xA036\n"  /* bra 0x060317F8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x638E\n"  /* exts.b r8,r3 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x53D3\n"  /* mov.l @(0xC,r13),r3 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x060317C8] = 0x0001638E} */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x8903\n"  /* bt 0x060317AC */
    ".word 0x50D0\n"  /* mov.l @(0x0,r13),r0 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x060317CC] = 0x08000000} */
    ".word 0x203B\n"  /* or r3,r0 */
    ".word 0x1D00\n"  /* mov.l r0,@(0x0,r13) */
    ".word 0x53EA\n"  /* mov.l @(0x28,r14),r3 */
    ".word 0x33A8\n"  /* sub r10,r3 */
    ".word 0x9209\n"  /* mov.w @(0x12,PC),r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x890B\n"  /* bt 0x060317D0 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8906\n"  /* bt 0x060317D0 */
    ".word 0xA019\n"  /* bra 0x060317F8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x638E\n"  /* exts.b r8,r3 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x54E8\n"  /* mov.l @(0x20,r14),r4 */
    ".word 0x1D48\n"  /* mov.l r4,@(0x20,r13) */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x06031880] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x52D3\n"  /* mov.l @(0xC,r13),r2 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x310D\n"  /* dmuls.l r0,r1 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x1D23\n"  /* mov.l r2,@(0xC,r13) */
    ".word 0x54E3\n"  /* mov.l @(0xC,r14),r4 */
    ".word 0x3418\n"  /* sub r1,r4 */
    ".word 0x1E43\n"  /* mov.l r4,@(0xC,r14) */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55D4\n"  /* mov.l @(0x10,r13),r5 */
    ".word 0x56D6\n"  /* mov.l @(0x18,r13),r6 */
    ".word 0x1D5E\n"  /* mov.l r5,@(0x38,r13) */
    ".word 0x1D6F\n"  /* mov.l r6,@(0x3C,r13) */
    ".word 0xD01D\n"  /* mov.l @(0x74,PC),r0  {[0x06031880] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06031884] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1D54\n"  /* mov.l r5,@(0x10,r13) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1D66\n"  /* mov.l r6,@(0x18,r13) */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0xD514\n"  /* mov.l @(0x50,PC),r5  {[0x06031888] = 0x00008000} */
    ".word 0x3A5C\n"  /* add r5,r10 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x1E5E\n"  /* mov.l r5,@(0x38,r14) */
    ".word 0x1E6F\n"  /* mov.l r6,@(0x3C,r14) */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06031880] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06031884] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1E54\n"  /* mov.l r5,@(0x10,r14) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1E66\n"  /* mov.l r6,@(0x18,r14) */
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
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x3468\n"  /* sub r6,r4 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x3578\n"  /* sub r7,r5 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x060318E8] = 0x0602744C} */
    ".size _collision_helper_first_car, .-_collision_helper_first_car\n"
);
__asm__(



    ".balign 2\n"
    ".global _collision_helper_second_car\n"
    ".type _collision_helper_second_car, @function\n"








    ".section .text.FUN_06031898, \"ax\"\n"

    ".global _FUN_06031898\n"
    "_collision_helper_second_car:\n"
    "_FUN_06031898:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6A0B\n"  /* neg r0,r10 */
    ".word 0x6AAF\n"  /* exts.w r10,r10 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x51E8\n"  /* mov.l @(0x20,r14),r1 */
    ".word 0x941C\n"  /* mov.w @(0x38,PC),r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x31A8\n"  /* sub r10,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3417\n"  /* cmp/gt r1,r4 */
    ".word 0x8D01\n"  /* bt/s 0x060318B8 */
    ".word 0x52D8\n"  /* mov.l @(0x20,r13),r2 */
    ".word 0x3148\n"  /* sub r4,r1 */
    ".word 0x32A8\n"  /* sub r10,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8D01\n"  /* bt/s 0x060318C4 */
    ".word 0x4119\n"  /* shlr8 r1 */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4219\n"  /* shlr8 r2 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x060318EC] = 0x0605BCC8} */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6412\n"  /* mov.l @r1,r4 */
    ".word 0x34C8\n"  /* sub r12,r4 */
    ".word 0x6C22\n"  /* mov.l @r2,r12 */
    ".word 0x34CC\n"  /* add r12,r4 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8907\n"  /* bt 0x060318F0 */
    ".word 0xAFC4\n"  /* bra 0x0603186C */
    ".word 0x0009\n"  /* nop */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x744C\n"  /* add #76,r4 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xBCC8\n"  /* bsr 0x06031282 */
    ".word 0x51EA\n"  /* mov.l @(0x28,r14),r1 */
    ".word 0x52DA\n"  /* mov.l @(0x28,r13),r2 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x930E\n"  /* mov.w @(0x1C,PC),r3 */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x891C\n"  /* bt 0x06031938 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x8917\n"  /* bt 0x06031938 */
    ".word 0x51E3\n"  /* mov.l @(0xC,r14),r1 */
    ".word 0x53D3\n"  /* mov.l @(0xC,r13),r3 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0603191C] = 0x0001638E} */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x8B05\n"  /* bf 0x06031920 */
    ".word 0xA045\n"  /* bra 0x060319A2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x638E\n"  /* exts.b r8,r3 */
    ".word 0x50D0\n"  /* mov.l @(0x0,r13),r0 */
    ".word 0x51E0\n"  /* mov.l @(0x0,r14),r1 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x06031934] = 0x08000000} */
    ".word 0x203B\n"  /* or r3,r0 */
    ".word 0x213B\n"  /* or r3,r1 */
    ".word 0x1D00\n"  /* mov.l r0,@(0x0,r13) */
    ".word 0x1E10\n"  /* mov.l r1,@(0x0,r14) */
    ".word 0xA038\n"  /* bra 0x060319A2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x51D3\n"  /* mov.l @(0xC,r13),r1 */
    ".word 0x53E3\n"  /* mov.l @(0xC,r14),r3 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x06031970] = 0x0001638E} */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x8906\n"  /* bt 0x06031952 */
    ".word 0x50D0\n"  /* mov.l @(0x0,r13),r0 */
    ".word 0x51E0\n"  /* mov.l @(0x0,r14),r1 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x06031974] = 0x08000000} */
    ".word 0x203B\n"  /* or r3,r0 */
    ".word 0x213B\n"  /* or r3,r1 */
    ".word 0x1D00\n"  /* mov.l r0,@(0x0,r13) */
    ".word 0x1E10\n"  /* mov.l r1,@(0x0,r14) */
    ".word 0x53DA\n"  /* mov.l @(0x28,r13),r3 */
    ".word 0x33A8\n"  /* sub r10,r3 */
    ".word 0x9209\n"  /* mov.w @(0x12,PC),r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x890C\n"  /* bt 0x06031978 */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8907\n"  /* bt 0x06031978 */
    ".word 0xA01B\n"  /* bra 0x060319A2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x638E\n"  /* exts.b r8,r3 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x54D8\n"  /* mov.l @(0x20,r13),r4 */
    ".word 0x1E48\n"  /* mov.l r4,@(0x20,r14) */
    ".word 0x1E4A\n"  /* mov.l r4,@(0x28,r14) */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0xD025\n"  /* mov.l @(0x94,PC),r0  {[0x06031A18] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x51D3\n"  /* mov.l @(0xC,r13),r1 */
    ".word 0x52E3\n"  /* mov.l @(0xC,r14),r2 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x310D\n"  /* dmuls.l r0,r1 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x1E23\n"  /* mov.l r2,@(0xC,r14) */
    ".word 0x54D3\n"  /* mov.l @(0xC,r13),r4 */
    ".word 0x3418\n"  /* sub r1,r4 */
    ".word 0x1D43\n"  /* mov.l r4,@(0xC,r13) */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55E4\n"  /* mov.l @(0x10,r14),r5 */
    ".word 0x56E6\n"  /* mov.l @(0x18,r14),r6 */
    ".word 0x1E5E\n"  /* mov.l r5,@(0x38,r14) */
    ".word 0x1E6F\n"  /* mov.l r6,@(0x3C,r14) */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x06031A18] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x06031A1C] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1E54\n"  /* mov.l r5,@(0x10,r14) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0x1E66\n"  /* mov.l r6,@(0x18,r14) */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0xD510\n"  /* mov.l @(0x40,PC),r5  {[0x06031A20] = 0x00008000} */
    ".word 0x3A5C\n"  /* add r5,r10 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0x6933\n"  /* mov r3,r9 */
    ".word 0x55D4\n"  /* mov.l @(0x10,r13),r5 */
    ".word 0x56D6\n"  /* mov.l @(0x18,r13),r6 */
    ".word 0x1D5E\n"  /* mov.l r5,@(0x38,r13) */
    ".word 0x1D6F\n"  /* mov.l r6,@(0x3C,r13) */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x06031A18] = 0x06027344} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x64AB\n"  /* neg r10,r4 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06031A1C] = 0x06027348} */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x330D\n"  /* dmuls.l r0,r3 */
    ".word 0x0B0A\n"  /* sts mach,r11 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x23BD\n"  /* .word 0x23BD */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x1D54\n"  /* mov.l r5,@(0x10,r13) */
    ".word 0x398D\n"  /* dmuls.l r8,r9 */
    ".word 0x080A\n"  /* sts mach,r8 */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x298D\n"  /* .word 0x298D */
    ".word 0x369C\n"  /* add r9,r6 */
    ".word 0xAF2A\n"  /* bra 0x0603186C */
    ".word 0x1D66\n"  /* mov.l r6,@(0x18,r13) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".size _collision_helper_second_car, .-_collision_helper_second_car\n"
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06031A34, \"ax\"\n"

    ".global _FUN_06031A34\n"
    ".type _FUN_06031A34, @function\n"
    "_FUN_06031A34:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0067\n"  /* mul.l r6,r0 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x6A53\n"  /* mov r5,r10 */
    ".word 0x6E63\n"  /* mov r6,r14 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0xDD08\n"  /* mov.l @(0x20,PC),r13  {[0x06031A68] = 0x06031D5C} */
    ".word 0xDB08\n"  /* mov.l @(0x20,PC),r11  {[0x06031A6C] = 0x06031D3C} */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x230E\n"  /* mulu.w r0,r3 */
    ".word 0x9C07\n"  /* mov.w @(0xE,PC),r12 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06031A70] = 0x06094FA8} */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x5372\n"  /* mov.l @(0x8,r7),r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8909\n"  /* bt 0x06031A74 */
    ".word 0xA147\n"  /* bra 0x06031CF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D5C\n"  /* mov.l r5,@(0x30,r13) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D3C\n"  /* mov.l r3,@(0x30,r13) */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x9032\n"  /* mov.w @(0x64,PC),r0 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x1C30\n"  /* mov.l r3,@(0x0,r12) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B2F\n"  /* bf 0x06031AE8 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x06031AE0] = 0x06031D6C} */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x06031AE4] = 0x06089EDC} */
    ".word 0x6902\n"  /* mov.l @r0,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x79DC\n"  /* add #-36,r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x201D\n"  /* .word 0x201D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8907\n"  /* bt 0x06031AE8 */
    ".word 0xA10B\n"  /* bra 0x06031CF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D6C\n"  /* mov.l r6,@(0x30,r13) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x230E\n"  /* mulu.w r0,r3 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06031B24] = 0x06094FA8} */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x5372\n"  /* mov.l @(0x8,r7),r3 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x1C30\n"  /* mov.l r3,@(0x0,r12) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xB100\n"  /* bsr 0x06031D1A */
    ".word 0x0009\n"  /* nop */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8904\n"  /* bt 0x06031B28 */
    ".word 0xA0E8\n"  /* bra 0x06031CF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x1D31\n"  /* mov.l r3,@(0x4,r13) */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x230E\n"  /* mulu.w r0,r3 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06031B68] = 0x06094FA8} */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x5372\n"  /* mov.l @(0x8,r7),r3 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x1C30\n"  /* mov.l r3,@(0x0,r12) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xB0DF\n"  /* bsr 0x06031D1A */
    ".word 0x0009\n"  /* nop */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8905\n"  /* bt 0x06031B6C */
    ".word 0xA0C7\n"  /* bra 0x06031CF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x1D32\n"  /* mov.l r3,@(0x8,r13) */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x230E\n"  /* mulu.w r0,r3 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06031BAC] = 0x06094FA8} */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x5372\n"  /* mov.l @(0x8,r7),r3 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x1C30\n"  /* mov.l r3,@(0x0,r12) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xB0BD\n"  /* bsr 0x06031D1A */
    ".word 0x0009\n"  /* nop */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8905\n"  /* bt 0x06031BB0 */
    ".word 0xA0A5\n"  /* bra 0x06031CF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".word 0x1D33\n"  /* mov.l r3,@(0xC,r13) */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xB0A7\n"  /* bsr 0x06031D1A */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06031BFC] = 0x060620D0} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x0107\n"  /* mul.l r0,r1 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x06031C00] = 0x0608AC20} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0x9C0D\n"  /* mov.w @(0x1A,PC),r12 */
    ".word 0x50B0\n"  /* mov.l @(0x0,r11),r0 */
    ".word 0x52B2\n"  /* mov.l @(0x8,r11),r2 */
    ".word 0x54B4\n"  /* mov.l @(0x10,r11),r4 */
    ".word 0x56B6\n"  /* mov.l @(0x18,r11),r6 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8B0D\n"  /* bf 0x06031C04 */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8B0B\n"  /* bf 0x06031C04 */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8B09\n"  /* bf 0x06031C04 */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8B07\n"  /* bf 0x06031C04 */
    ".word 0xA07D\n"  /* bra 0x06031CF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x06031446 */
    ".word 0x9C3A\n"  /* mov.w @(0x74,PC),r12 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8905\n"  /* bt 0x06031C16 */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8903\n"  /* bt 0x06031C16 */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8901\n"  /* bt 0x06031C16 */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x896D\n"  /* bt 0x06031CF2 */
    ".word 0x9C32\n"  /* mov.w @(0x64,PC),r12 */
    ".word 0x51B1\n"  /* mov.l @(0x4,r11),r1 */
    ".word 0x53B3\n"  /* mov.l @(0xC,r11),r3 */
    ".word 0x55B5\n"  /* mov.l @(0x14,r11),r5 */
    ".word 0x57B7\n"  /* mov.l @(0x1C,r11),r7 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8B05\n"  /* bf 0x06031C30 */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8B03\n"  /* bf 0x06031C30 */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8B01\n"  /* bf 0x06031C30 */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8960\n"  /* bt 0x06031CF2 */
    ".word 0x9C26\n"  /* mov.w @(0x4C,PC),r12 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8905\n"  /* bt 0x06031C42 */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8903\n"  /* bt 0x06031C42 */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8901\n"  /* bt 0x06031C42 */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8B57\n"  /* bf 0x06031CF2 */
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
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x06031C84] = 0x06031D78} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x53D0\n"  /* mov.l @(0x0,r13),r3 */
    ".word 0x54D1\n"  /* mov.l @(0x4,r13),r4 */
    ".word 0x55D2\n"  /* mov.l @(0x8,r13),r5 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x56D3\n"  /* mov.l @(0xC,r13),r6 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1D78\n"  /* mov.l r7,@(0x20,r13) */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0xA024\n"  /* bra 0x06031CDA */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x06031C98 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x06031C9E */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x06031CA4 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA019\n"  /* bra 0x06031CDA */
    ".word 0x0009\n"  /* nop */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x06031CAE */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x06031CB4 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x06031CBA */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA00E\n"  /* bra 0x06031CDA */
    ".word 0x0009\n"  /* nop */
    ".word 0xE020\n"  /* mov #32,r0 */
    ".word 0xA001\n"  /* bra 0x06031CC6 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06031CFC] = 0x00400000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x06031CCC */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x06031CD2 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x06031CD8 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x06031D00] = 0x060620D0} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x06031D04] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x4E10\n"  /* dt r14 */
    ".word 0x8908\n"  /* bt 0x06031D08 */
    ".word 0xAEA8\n"  /* bra 0x06031A4A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D0\n"  /* mov.b r13,@r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x060326FA */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".global _FUN_06031d1a\n"
    "_FUN_06031d1a:\n"
    ".word 0x900C\n"  /* mov.w @(0x18,PC),r0 */
    ".word 0x3107\n"  /* cmp/gt r0,r1 */
    ".word 0x89E8\n"  /* bt 0x06031CF2 */
    ".word 0x900A\n"  /* mov.w @(0x14,PC),r0 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x89E5\n"  /* bt 0x06031CF2 */
    ".word 0x9008\n"  /* mov.w @(0x10,PC),r0 */
    ".word 0x3207\n"  /* cmp/gt r0,r2 */
    ".word 0x89E2\n"  /* bt 0x06031CF2 */
    ".word 0x9004\n"  /* mov.w @(0x8,PC),r0 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x89DF\n"  /* bt 0x06031CF2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
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
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1C88\n"  /* mov.l r8,@(0x20,r12) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1C92\n"  /* mov.l r9,@(0x8,r12) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1CA8\n"  /* mov.l r10,@(0x20,r12) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1CBE\n"  /* mov.l r11,@(0x38,r12) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x1CC4\n"  /* mov.l r12,@(0x10,r12) */
    ".global _FUN_06031d8c\n"
    "_FUN_06031d8c:\n"
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x06031DEC] = 0x06089EDC} */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06031DF0] = 0x06094FA8} */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6272\n"  /* mov.l @r7,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2F12\n"  /* mov.l r1,@r15 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1F11\n"  /* mov.l r1,@(0x4,r15) */
    ".word 0x5272\n"  /* mov.l @(0x8,r7),r2 */
    ".word 0x4510\n"  /* dt r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1312\n"  /* mov.l r1,@(0x8,r3) */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0x1311\n"  /* mov.l r1,@(0x4,r3) */
    ".word 0x76DC\n"  /* add #-36,r6 */
    ".word 0x8FD8\n"  /* bf/s 0x06031D98 */
    ".word 0x730C\n"  /* add #12,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x4FA8\n"  /* .word 0x4FA8 */
    ".global _FUN_06031df4\n"
    "_FUN_06031df4:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06031E00, \"ax\"\n"

    ".global _FUN_06031E00\n"
    ".type _FUN_06031E00, @function\n"
    "_FUN_06031E00:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE018\n"  /* mov #24,r0 */
    ".word 0x0067\n"  /* mul.l r6,r0 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x6A53\n"  /* mov r5,r10 */
    ".word 0x6E63\n"  /* mov r6,r14 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0xDD08\n"  /* mov.l @(0x20,PC),r13  {[0x06031E34] = 0x06032128} */
    ".word 0xDB08\n"  /* mov.l @(0x20,PC),r11  {[0x06031E38] = 0x06032108} */
    ".word 0x78E8\n"  /* add #-24,r8 */
    ".word 0x8588\n"  /* mov.w @(0x10,r8),r0 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x230E\n"  /* mulu.w r0,r3 */
    ".word 0x9C07\n"  /* mov.w @(0xE,PC),r12 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06031E3C] = 0x060961A8} */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x5372\n"  /* mov.l @(0x8,r7),r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8909\n"  /* bt 0x06031E40 */
    ".word 0xA147\n"  /* bra 0x060320BE */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2128\n"  /* tst r2,r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x61A8\n"  /* swap.b r10,r1 */
    ".word 0x9032\n"  /* mov.w @(0x64,PC),r0 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x1C30\n"  /* mov.l r3,@(0x0,r12) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B2F\n"  /* bf 0x06031EB4 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x06031EAC] = 0x06032138} */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x06031EB0] = 0x0608A52C} */
    ".word 0x6902\n"  /* mov.l @r0,r9 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1511\n"  /* mov.l r1,@(0x4,r5) */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x094F\n"  /* mac.l @r4+,@r9+ */
    ".word 0x79DC\n"  /* add #-36,r9 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1512\n"  /* mov.l r1,@(0x8,r5) */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x054F\n"  /* mac.l @r4+,@r5+ */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x201D\n"  /* .word 0x201D */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8907\n"  /* bt 0x06031EB4 */
    ".word 0xA10B\n"  /* bra 0x060320BE */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2138\n"  /* tst r3,r1 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x0603290E */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x8589\n"  /* mov.w @(0x12,r8),r0 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x230E\n"  /* mulu.w r0,r3 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06031EF0] = 0x060961A8} */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x5372\n"  /* mov.l @(0x8,r7),r3 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x1C30\n"  /* mov.l r3,@(0x0,r12) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xB100\n"  /* bsr 0x060320E6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8904\n"  /* bt 0x06031EF4 */
    ".word 0xA0E8\n"  /* bra 0x060320BE */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x61A8\n"  /* swap.b r10,r1 */
    ".word 0x1D31\n"  /* mov.l r3,@(0x4,r13) */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x858A\n"  /* mov.w @(0x14,r8),r0 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x230E\n"  /* mulu.w r0,r3 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06031F34] = 0x060961A8} */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x5372\n"  /* mov.l @(0x8,r7),r3 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x1C30\n"  /* mov.l r3,@(0x0,r12) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xB0DF\n"  /* bsr 0x060320E6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8905\n"  /* bt 0x06031F38 */
    ".word 0xA0C7\n"  /* bra 0x060320BE */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x61A8\n"  /* swap.b r10,r1 */
    ".word 0x1D32\n"  /* mov.l r3,@(0x8,r13) */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x858B\n"  /* mov.w @(0x16,r8),r0 */
    ".word 0xE30C\n"  /* mov #12,r3 */
    ".word 0x230E\n"  /* mulu.w r0,r3 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06031F78] = 0x060961A8} */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x5372\n"  /* mov.l @(0x8,r7),r3 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0x1C04\n"  /* mov.l r0,@(0x10,r12) */
    ".word 0x1C30\n"  /* mov.l r3,@(0x0,r12) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1C05\n"  /* mov.l r0,@(0x14,r12) */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xB0BD\n"  /* bsr 0x060320E6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8905\n"  /* bt 0x06031F7C */
    ".word 0xA0A5\n"  /* bra 0x060320BE */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x61A8\n"  /* swap.b r10,r1 */
    ".word 0x1D33\n"  /* mov.l r3,@(0xC,r13) */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x6172\n"  /* mov.l @r7,r1 */
    ".word 0x54C7\n"  /* mov.l @(0x1C,r12),r4 */
    ".word 0x341D\n"  /* dmuls.l r1,r4 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x010A\n"  /* sts mach,r1 */
    ".word 0x342D\n"  /* dmuls.l r2,r4 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x1521\n"  /* mov.l r2,@(0x4,r5) */
    ".word 0xB0A7\n"  /* bsr 0x060320E6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06031FC8] = 0x060620D4} */
    ".word 0xE118\n"  /* mov #24,r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x0107\n"  /* mul.l r0,r1 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x06031FCC] = 0x0608AC20} */
    ".word 0x091A\n"  /* sts macl,r9 */
    ".word 0x392C\n"  /* add r2,r9 */
    ".word 0x9C0D\n"  /* mov.w @(0x1A,PC),r12 */
    ".word 0x50B0\n"  /* mov.l @(0x0,r11),r0 */
    ".word 0x52B2\n"  /* mov.l @(0x8,r11),r2 */
    ".word 0x54B4\n"  /* mov.l @(0x10,r11),r4 */
    ".word 0x56B6\n"  /* mov.l @(0x18,r11),r6 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8B0D\n"  /* bf 0x06031FD0 */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8B0B\n"  /* bf 0x06031FD0 */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8B09\n"  /* bf 0x06031FD0 */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x8B07\n"  /* bf 0x06031FD0 */
    ".word 0xA07D\n"  /* bra 0x060320BE */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF50\n"  /* .word 0xFF50 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x06031812 */
    ".word 0x9C3A\n"  /* mov.w @(0x74,PC),r12 */
    ".word 0x3C07\n"  /* cmp/gt r0,r12 */
    ".word 0x8905\n"  /* bt 0x06031FE2 */
    ".word 0x3C27\n"  /* cmp/gt r2,r12 */
    ".word 0x8903\n"  /* bt 0x06031FE2 */
    ".word 0x3C47\n"  /* cmp/gt r4,r12 */
    ".word 0x8901\n"  /* bt 0x06031FE2 */
    ".word 0x3C67\n"  /* cmp/gt r6,r12 */
    ".word 0x896D\n"  /* bt 0x060320BE */
    ".word 0x9C32\n"  /* mov.w @(0x64,PC),r12 */
    ".word 0x51B1\n"  /* mov.l @(0x4,r11),r1 */
    ".word 0x53B3\n"  /* mov.l @(0xC,r11),r3 */
    ".word 0x55B5\n"  /* mov.l @(0x14,r11),r5 */
    ".word 0x57B7\n"  /* mov.l @(0x1C,r11),r7 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8B05\n"  /* bf 0x06031FFC */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8B03\n"  /* bf 0x06031FFC */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8B01\n"  /* bf 0x06031FFC */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8960\n"  /* bt 0x060320BE */
    ".word 0x9C26\n"  /* mov.w @(0x4C,PC),r12 */
    ".word 0x3C17\n"  /* cmp/gt r1,r12 */
    ".word 0x8905\n"  /* bt 0x0603200E */
    ".word 0x3C37\n"  /* cmp/gt r3,r12 */
    ".word 0x8903\n"  /* bt 0x0603200E */
    ".word 0x3C57\n"  /* cmp/gt r5,r12 */
    ".word 0x8901\n"  /* bt 0x0603200E */
    ".word 0x3C77\n"  /* cmp/gt r7,r12 */
    ".word 0x8B57\n"  /* bf 0x060320BE */
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
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x8095\n"  /* mov.b r0,@(0x5,r9) */
    ".word 0x8586\n"  /* mov.w @(0xC,r8),r0 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x06032050] = 0x06032144} */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x53D0\n"  /* mov.l @(0x0,r13),r3 */
    ".word 0x54D1\n"  /* mov.l @(0x4,r13),r4 */
    ".word 0x55D2\n"  /* mov.l @(0x8,r13),r5 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x56D3\n"  /* mov.l @(0xC,r13),r6 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFF81\n"  /* .word 0xFF81 */
    ".word 0x0051\n"  /* .word 0x0051 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2144\n"  /* mov.b r4,@-r1 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x365C\n"  /* add r5,r6 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0xA024\n"  /* bra 0x060320A6 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8900\n"  /* bt 0x06032064 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8900\n"  /* bt 0x0603206A */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8900\n"  /* bt 0x06032070 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA019\n"  /* bra 0x060320A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x0603207A */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x06032080 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x06032086 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0xA00E\n"  /* bra 0x060320A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE020\n"  /* mov #32,r0 */
    ".word 0xA001\n"  /* bra 0x06032092 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x060320C8] = 0x00400000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B00\n"  /* bf 0x06032098 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x3537\n"  /* cmp/gt r3,r5 */
    ".word 0x8B00\n"  /* bf 0x0603209E */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3637\n"  /* cmp/gt r3,r6 */
    ".word 0x8B00\n"  /* bf 0x060320A4 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x060320CC] = 0x060620D4} */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x060320D0] = 0x0606A4F8} */
    ".word 0x4319\n"  /* shlr8 r3 */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0135\n"  /* mov.w r3,@(r0,r1) */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x4E10\n"  /* dt r14 */
    ".word 0x8908\n"  /* bt 0x060320D4 */
    ".word 0xAEA8\n"  /* bra 0x06031E16 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x20D4\n"  /* mov.b r13,@-r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x06032AC6 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x000B\n"  /* rts */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".global _FUN_060320e6\n"
    "_FUN_060320e6:\n"
    ".word 0x900C\n"  /* mov.w @(0x18,PC),r0 */
    ".word 0x3107\n"  /* cmp/gt r0,r1 */
    ".word 0x89E8\n"  /* bt 0x060320BE */
    ".word 0x900A\n"  /* mov.w @(0x14,PC),r0 */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x89E5\n"  /* bt 0x060320BE */
    ".word 0x9008\n"  /* mov.w @(0x10,PC),r0 */
    ".word 0x3207\n"  /* cmp/gt r0,r2 */
    ".word 0x89E2\n"  /* bt 0x060320BE */
    ".word 0x9004\n"  /* mov.w @(0x8,PC),r0 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x89DF\n"  /* bt 0x060320BE */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0xFE70\n"  /* .word 0xFE70 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
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
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2054\n"  /* mov.b r5,@-r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x205E\n"  /* mulu.w r5,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2074\n"  /* mov.b r7,@-r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x208A\n"  /* xor r8,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2090\n"  /* mov.b r9,@r0 */
    ".global _FUN_06032158\n"
    "_FUN_06032158:\n"
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x060321B8] = 0x0608A52C} */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x060321BC] = 0x060961A8} */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0xE724\n"  /* mov #36,r7 */
    ".word 0x376C\n"  /* add r6,r7 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x6272\n"  /* mov.l @r7,r2 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x2F12\n"  /* mov.l r1,@r15 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x5271\n"  /* mov.l @(0x4,r7),r2 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x1F11\n"  /* mov.l r1,@(0x4,r15) */
    ".word 0x5272\n"  /* mov.l @(0x8,r7),r2 */
    ".word 0x4510\n"  /* dt r5 */
    ".word 0x064F\n"  /* mac.l @r4+,@r6+ */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x1312\n"  /* mov.l r1,@(0x8,r3) */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0x1311\n"  /* mov.l r1,@(0x4,r3) */
    ".word 0x76DC\n"  /* add #-36,r6 */
    ".word 0x8FD8\n"  /* bf/s 0x06032164 */
    ".word 0x730C\n"  /* add #12,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xA52C\n"  /* bra 0x06032C16 */
    ".word 0x0609\n"  /* .word 0x0609 */
    ".word 0x61A8\n"  /* swap.b r10,r1 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060321DC, \"ax\"\n"

    ".global _FUN_060321DC\n"
    ".type _FUN_060321DC, @function\n"
    "_FUN_060321DC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB5D7\n"  /* bsr 0x06032D90 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD117\n"  /* mov.l @(0x5C,PC),r1  {[0x06032244] = 0x00000004} */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x06032248] = 0x0000000E} */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0603224C] = 0x00000000} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060321EE, \"ax\"\n"

    ".global _FUN_060321EE\n"
    ".type _FUN_060321EE, @function\n"
    "_FUN_060321EE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB612\n"  /* bsr 0x06032E18 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06032250] = 0x06062464} */
    ".word 0x6173\n"  /* mov r7,r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x021E\n"  /* mov.l @(r0,r1),r2 */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x06032254] = 0x000002DE} */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0xD614\n"  /* mov.l @(0x50,PC),r6  {[0x06032258] = 0x0000000D} */
    ".word 0x6724\n"  /* mov.b @r2+,r7 */
    ".word 0x2170\n"  /* mov.b r7,@r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x4610\n"  /* dt r6 */
    ".word 0x8BFA\n"  /* bf 0x06032208 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x0603225C] = 0x00000005} */
    ".word 0x3707\n"  /* cmp/gt r0,r7 */
    ".word 0x8BD9\n"  /* bf 0x060321D0 */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06032260] = 0x06082A20} */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06032264] = 0x06082A24} */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06032268] = 0x06082A25} */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x23B0\n"  /* mov.b r11,@r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02DC\n"  /* mov.b @(r0,r13),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2464\n"  /* mov.b r6,@-r4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02DE\n"  /* mov.l @(r0,r13),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000D\n"  /* mov.w @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A20\n"  /* mov.b r2,@r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A24\n"  /* mov.b r2,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A25\n"  /* mov.w r2,@-r10 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603227C, \"ax\"\n"

    ".global _FUN_0603227C\n"
    ".type _FUN_0603227C, @function\n"
    "_FUN_0603227C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB041\n"  /* bsr 0x06032304 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD413\n"  /* mov.l @(0x4C,PC),r4  {[0x060322D4] = 0x00000001} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032286, \"ax\"\n"

    ".global _FUN_06032286\n"
    ".type _FUN_06032286, @function\n"
    "_FUN_06032286:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB03C\n"  /* bsr 0x06032304 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x060322D8] = 0x00000002} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032290, \"ax\"\n"

    ".global _FUN_06032290\n"
    ".type _FUN_06032290, @function\n"
    "_FUN_06032290:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB037\n"  /* bsr 0x06032304 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x060322DC] = 0x00000003} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603229A, \"ax\"\n"

    ".global _FUN_0603229A\n"
    ".type _FUN_0603229A, @function\n"
    "_FUN_0603229A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB032\n"  /* bsr 0x06032304 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD40F\n"  /* mov.l @(0x3C,PC),r4  {[0x060322E0] = 0x00000004} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060322A4, \"ax\"\n"

    ".global _FUN_060322A4\n"
    ".type _FUN_060322A4, @function\n"
    "_FUN_060322A4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB02D\n"  /* bsr 0x06032304 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x060322E4] = 0x00000005} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060322AE, \"ax\"\n"

    ".global _FUN_060322AE\n"
    ".type _FUN_060322AE, @function\n"
    "_FUN_060322AE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB028\n"  /* bsr 0x06032304 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060322B6, \"ax\"\n"

    ".global _FUN_060322B6\n"
    ".type _FUN_060322B6, @function\n"
    "_FUN_060322B6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB016\n"  /* bsr 0x060322E8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".global _FUN_060322e8\n"
    "_FUN_060322e8:\n"
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x060322FC] = 0x06082A24} */
    ".word 0x6100\n"  /* mov.b @r0,r1 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x8903\n"  /* bt 0x060322F8 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x06032300] = 0x06082A20} */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A24\n"  /* mov.b r2,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A20\n"  /* mov.b r2,@r10 */
    ".global _FUN_06032304\n"
    "_FUN_06032304:\n"
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06032324] = 0x060623B0} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x0E4E\n"  /* mov.l @(r0,r4),r14 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06032328] = 0x000002D8} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0x6516\n"  /* mov.l @r1+,r5 */
    ".word 0x6616\n"  /* mov.l @r1+,r6 */
    ".word 0x6716\n"  /* mov.l @r1+,r7 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0603232C] = 0x06082A20} */
    ".word 0x6202\n"  /* mov.l @r0,r2 */
    ".word 0x3520\n"  /* cmp/eq r2,r5 */
    ".word 0x8B09\n"  /* bf 0x06032330 */
    ".word 0xD002\n"  /* mov.l @(0x8,PC),r0  {[0x06032328] = 0x000002D8} */
    ".word 0xA023\n"  /* bra 0x06032368 */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x23B0\n"  /* mov.b r11,@r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02D8\n"  /* .word 0x02D8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A20\n"  /* mov.b r2,@r10 */
    ".word 0xA0D0\n"  /* bra 0x060324D4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x239C\n"  /* .word 0x239C */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x23CC\n"  /* .word 0x23CC */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x23E4\n"  /* mov.b r14,@-r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x237C\n"  /* .word 0x237C */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x23F0\n"  /* mov.b r15,@r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2404\n"  /* mov.b r0,@-r4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2414\n"  /* mov.b r1,@-r4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2424\n"  /* mov.b r2,@-r4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x243C\n"  /* .word 0x243C */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x245C\n"  /* .word 0x245C */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2474\n"  /* mov.b r7,@-r4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x248C\n"  /* .word 0x248C */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x24A0\n"  /* mov.b r10,@r4 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0xD002\n"  /* mov.l @(0x8,PC),r0  {[0x06032374] = 0x06032334} */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x2334\n"  /* mov.b r3,@-r3 */
    ".word 0xAFC7\n"  /* bra 0x0603230A */
    ".word 0x0009\n"  /* nop */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06032390] = 0x0000000E} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06032394] = 0x00000002} */
    ".word 0x212B\n"  /* or r2,r1 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06032398] = 0x00000001} */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0xA00C\n"  /* bra 0x060323A8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x060323C0] = 0x0000000E} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x060323C4] = 0x00000003} */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x060323C8] = 0x000002D0} */
    ".word 0x02EE\n"  /* mov.l @(r0,r14),r2 */
    ".word 0x3270\n"  /* cmp/eq r7,r2 */
    ".word 0x8904\n"  /* bt 0x060323BA */
    ".word 0x6473\n"  /* mov r7,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060323B2, \"ax\"\n"

    ".global _FUN_060323B2\n"
    ".type _FUN_060323B2, @function\n"
    "_FUN_060323B2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB530\n"  /* bsr 0x06032E18 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xAFA6\n"  /* bra 0x0603230A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02D0\n"  /* .word 0x02D0 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x060323DC] = 0x0000000E} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x060323E0] = 0x00000001} */
    ".word 0x212B\n"  /* or r2,r1 */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0xAF98\n"  /* bra 0x0603230A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060323E4, \"ax\"\n"

    ".global _FUN_060323E4\n"
    ".type _FUN_060323E4, @function\n"
    "_FUN_060323E4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xBEEB\n"  /* bsr 0x060321C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xAF8D\n"  /* bra 0x0603230A */
    ".word 0x0009\n"  /* nop */
    ".word 0x617C\n"  /* extu.b r7,r1 */
    ".word 0x6279\n"  /* swap.w r7,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0xD002\n"  /* mov.l @(0x8,PC),r0  {[0x06032400] = 0x000002DE} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0xAF86\n"  /* bra 0x0603230A */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02DE\n"  /* mov.l @(r0,r13),r2 */
    ".word 0xD002\n"  /* mov.l @(0x8,PC),r0  {[0x06032410] = 0x0000000E} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0x217B\n"  /* or r7,r1 */
    ".word 0xAF7E\n"  /* bra 0x0603230A */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0xD002\n"  /* mov.l @(0x8,PC),r0  {[0x06032420] = 0x0000000E} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0x6277\n"  /* not r7,r2 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0xAF75\n"  /* bra 0x0603230A */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6573\n"  /* mov r7,r5 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x06032438] = 0x0601D5F4} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603242A, \"ax\"\n"

    ".global _FUN_0603242A\n"
    ".type _FUN_0603242A, @function\n"
    "_FUN_0603242A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xAF6A\n"  /* bra 0x0603230A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x0603280C] = 0x30CC6406} */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06032450] = 0x00000001} */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06032454] = 0x06082A25} */
    ".word 0x6100\n"  /* mov.b @r0,r1 */
    ".word 0x212B\n"  /* or r2,r1 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x06032458] = 0x06082A28} */
    ".word 0xAF5E\n"  /* bra 0x0603230A */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A25\n"  /* mov.w r2,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A28\n"  /* tst r2,r10 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0603246C] = 0x00000001} */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06032470] = 0x06082A25} */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x6100\n"  /* mov.b @r0,r1 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0xAF50\n"  /* bra 0x0603230A */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A25\n"  /* mov.w r2,@-r10 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06032484] = 0x00000002} */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06032488] = 0x06082A25} */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x6100\n"  /* mov.b @r0,r1 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0xAF44\n"  /* bra 0x0603230A */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A25\n"  /* mov.w r2,@-r10 */
    ".word 0xD202\n"  /* mov.l @(0x8,PC),r2  {[0x06032498] = 0x00000002} */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0603249C] = 0x06082A25} */
    ".word 0x6100\n"  /* mov.b @r0,r1 */
    ".word 0x212B\n"  /* or r2,r1 */
    ".word 0xAF39\n"  /* bra 0x0603230A */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A25\n"  /* mov.w r2,@-r10 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x060324C0] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0xD207\n"  /* mov.l @(0x1C,PC),r2  {[0x060324C4] = 0xFFFEFFFF} */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x060324C8] = 0x06082A24} */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x060324CC] = 0x06082A25} */
    ".word 0x6100\n"  /* mov.b @r0,r1 */
    ".word 0xD206\n"  /* mov.l @(0x18,PC),r2  {[0x060324D0] = 0x00000004} */
    ".word 0x212B\n"  /* or r2,r1 */
    ".word 0xAF26\n"  /* bra 0x0603230A */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A24\n"  /* mov.b r2,@-r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A25\n"  /* mov.w r2,@-r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x060324E8] = 0x000002DC} */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x8919\n"  /* bt 0x06032510 */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x8B04\n"  /* bf 0x060324EC */
    ".word 0xA021\n"  /* bra 0x06032528 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02DC\n"  /* mov.b @(r0,r13),r2 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060324EC, \"ax\"\n"

    ".global _FUN_060324EC\n"
    ".type _FUN_060324EC, @function\n"
    "_FUN_060324EC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB4BD\n"  /* bsr 0x06032E6C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060324F4, \"ax\"\n"

    ".global _FUN_060324F4\n"
    ".type _FUN_060324F4, @function\n"
    "_FUN_060324F4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB021\n"  /* bsr 0x0603253C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060324FC, \"ax\"\n"

    ".global _FUN_060324FC\n"
    ".type _FUN_060324FC, @function\n"
    "_FUN_060324FC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0C5\n"  /* bsr 0x0603268C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032504, \"ax\"\n"

    ".global _FUN_06032504\n"
    ".type _FUN_06032504, @function\n"
    "_FUN_06032504:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB03D\n"  /* bsr 0x06032584 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA014\n"  /* bra 0x06032538 */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032510, \"ax\"\n"

    ".global _FUN_06032510\n"
    ".type _FUN_06032510, @function\n"
    "_FUN_06032510:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB4AB\n"  /* bsr 0x06032E6C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032518, \"ax\"\n"

    ".global _FUN_06032518\n"
    ".type _FUN_06032518, @function\n"
    "_FUN_06032518:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB00F\n"  /* bsr 0x0603253C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032520, \"ax\"\n"

    ".global _FUN_06032520\n"
    ".type _FUN_06032520, @function\n"
    "_FUN_06032520:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0B3\n"  /* bsr 0x0603268C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032528, \"ax\"\n"

    ".global _FUN_06032528\n"
    ".type _FUN_06032528, @function\n"
    "_FUN_06032528:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB02B\n"  /* bsr 0x06032584 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032530, \"ax\"\n"

    ".global _FUN_06032530\n"
    ".type _FUN_06032530, @function\n"
    "_FUN_06032530:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB4B7\n"  /* bsr 0x06032EA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xD002\n"  /* mov.l @(0x8,PC),r0  {[0x06032548] = 0x06082A24} */
    ".word 0x6100\n"  /* mov.b @r0,r1 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x8B03\n"  /* bf 0x0603254C */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A24\n"  /* mov.b r2,@-r10 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x0603256C] = 0x0000000E} */
    ".word 0x07ED\n"  /* mov.w @(r0,r14),r7 */
    ".word 0xD607\n"  /* mov.l @(0x1C,PC),r6  {[0x06032570] = 0x00000001} */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x06032574] = 0x00000002} */
    ".word 0x2728\n"  /* tst r2,r7 */
    ".word 0x8900\n"  /* bt 0x0603255A */
    ".word 0xD607\n"  /* mov.l @(0x1C,PC),r6  {[0x06032578] = 0xFFFFFFFF} */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x06032570] = 0x00000001} */
    ".word 0x2728\n"  /* tst r2,r7 */
    ".word 0x8900\n"  /* bt 0x06032562 */
    ".word 0xD606\n"  /* mov.l @(0x18,PC),r6  {[0x0603257C] = 0x00000000} */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06032580] = 0x000002C4} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0x316C\n"  /* add r6,r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02C4\n"  /* mov.b r12,@(r0,r2) */
    ".global _FUN_06032584\n"
    "_FUN_06032584:\n"
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060325C8] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032586, \"ax\"\n"

    ".global _FUN_06032586\n"
    ".type _FUN_06032586, @function\n"
    "_FUN_06032586:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD0F\n"  /* mov.l @(0x3C,PC),r13  {[0x060325CC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x060325D0] = 0x00000000} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x060325D4] = 0x00000004} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x060325D8] = 0x00000008} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x060325DC] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060325A0, \"ax\"\n"

    ".global _FUN_060325A0\n"
    ".type _FUN_060325A0, @function\n"
    "_FUN_060325A0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x060325E0] = 0x0000000C} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x060325E4] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060325AE, \"ax\"\n"

    ".global _FUN_060325AE\n"
    ".type _FUN_060325AE, @function\n"
    "_FUN_060325AE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x060325E8] = 0x00000054} */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x060325EC] = 0x000002DC} */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x060325F0] = 0xFFFFFFFC} */
    ".word 0x2028\n"  /* tst r2,r0 */
    ".word 0x8B1A\n"  /* bf 0x060325F8 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x060325F4] = 0x06081898} */
    ".word 0xA019\n"  /* bra 0x060325FA */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0054\n"  /* mov.b r5,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02DC\n"  /* mov.b @(r0,r13),r2 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFC\n"  /* .word 0xFFFC */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x1898\n"  /* mov.l r9,@(0x20,r8) */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06032668] = 0x000002D4} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0xD71B\n"  /* mov.l @(0x6C,PC),r7  {[0x0603266C] = 0x0000000D} */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06032670] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032604, \"ax\"\n"

    ".global _FUN_06032604\n"
    ".type _FUN_06032604, @function\n"
    "_FUN_06032604:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD19\n"  /* mov.l @(0x64,PC),r13  {[0x06032674] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06032668] = 0x000002D4} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x06032678] = 0x06026F72} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032618, \"ax\"\n"

    ".global _FUN_06032618\n"
    ".type _FUN_06032618, @function\n"
    "_FUN_06032618:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0603266C] = 0x0000000D} */
    ".word 0x3078\n"  /* sub r7,r0 */
    ".word 0xD115\n"  /* mov.l @(0x54,PC),r1  {[0x0603267C] = 0x000002DE} */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x041C\n"  /* mov.b @(r0,r1),r4 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06032680] = 0x0600A474} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603262E, \"ax\"\n"

    ".global _FUN_0603262E\n"
    ".type _FUN_0603262E, @function\n"
    "_FUN_0603262E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x06032668] = 0x000002D4} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x06032684] = 0x00000030} */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x06032688] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032642, \"ax\"\n"

    ".global _FUN_06032642\n"
    ".type _FUN_06032642, @function\n"
    "_FUN_06032642:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD0A\n"  /* mov.l @(0x28,PC),r13  {[0x06032674] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x4710\n"  /* dt r7 */
    ".word 0x8BD5\n"  /* bf 0x06032600 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x06032688] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032656, \"ax\"\n"

    ".global _FUN_06032656\n"
    ".type _FUN_06032656, @function\n"
    "_FUN_06032656:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD05\n"  /* mov.l @(0x14,PC),r13  {[0x06032674] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02D4\n"  /* mov.b r13,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000D\n"  /* mov.w @(r0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6F72\n"  /* mov.l @r7,r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02DE\n"  /* mov.l @(r0,r13),r2 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A474 */
    ".word 0xA474\n"  /* bra 0x06032F6E */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0030\n"  /* .word 0x0030 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".global _FUN_0603268c\n"
    "_FUN_0603268c:\n"
    ".word 0xDD47\n"  /* mov.l @(0x11C,PC),r13  {[0x060327AC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xDC47\n"  /* mov.l @(0x11C,PC),r12  {[0x060327B0] = 0x060623C8} */
    ".word 0xD048\n"  /* mov.l @(0x120,PC),r0  {[0x060327B4] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032694, \"ax\"\n"

    ".global _FUN_06032694\n"
    ".type _FUN_06032694, @function\n"
    "_FUN_06032694:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD43\n"  /* mov.l @(0x10C,PC),r13  {[0x060327AC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD045\n"  /* mov.l @(0x114,PC),r0  {[0x060327B8] = 0x06026E0C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060326A2, \"ax\"\n"

    ".global _FUN_060326A2\n"
    ".type _FUN_060326A2, @function\n"
    "_FUN_060326A2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD40\n"  /* mov.l @(0x100,PC),r13  {[0x060327AC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD043\n"  /* mov.l @(0x10C,PC),r0  {[0x060327BC] = 0x00000010} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD043\n"  /* mov.l @(0x10C,PC),r0  {[0x060327C0] = 0x00000014} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD043\n"  /* mov.l @(0x10C,PC),r0  {[0x060327C4] = 0x00000018} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD043\n"  /* mov.l @(0x10C,PC),r0  {[0x060327C8] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060326BC, \"ax\"\n"

    ".global _FUN_060326BC\n"
    ".type _FUN_060326BC, @function\n"
    "_FUN_060326BC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD041\n"  /* mov.l @(0x104,PC),r0  {[0x060327CC] = 0x0000001E} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD041\n"  /* mov.l @(0x104,PC),r0  {[0x060327D0] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060326CA, \"ax\"\n"

    ".global _FUN_060326CA\n"
    ".type _FUN_060326CA, @function\n"
    "_FUN_060326CA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD040\n"  /* mov.l @(0x100,PC),r0  {[0x060327D4] = 0x0000001C} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD040\n"  /* mov.l @(0x100,PC),r0  {[0x060327D8] = 0x06026E94} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060326D8, \"ax\"\n"

    ".global _FUN_060326D8\n"
    ".type _FUN_060326D8, @function\n"
    "_FUN_060326D8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD03E\n"  /* mov.l @(0xF8,PC),r0  {[0x060327DC] = 0x00000020} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD03E\n"  /* mov.l @(0xF8,PC),r0  {[0x060327E0] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060326E6, \"ax\"\n"

    ".global _FUN_060326E6\n"
    ".type _FUN_060326E6, @function\n"
    "_FUN_060326E6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD03C\n"  /* mov.l @(0xF0,PC),r0  {[0x060327E4] = 0x00000054} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD023\n"  /* mov.l @(0x8C,PC),r0  {[0x060327B4] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032726, \"ax\"\n"

    ".global _FUN_06032726\n"
    ".type _FUN_06032726, @function\n"
    "_FUN_06032726:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD1F\n"  /* mov.l @(0x7C,PC),r13  {[0x060327AC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD02D\n"  /* mov.l @(0xB4,PC),r0  {[0x060327E8] = 0x0000000C} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD022\n"  /* mov.l @(0x88,PC),r0  {[0x060327C8] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603273E, \"ax\"\n"

    ".global _FUN_0603273E\n"
    ".type _FUN_0603273E, @function\n"
    "_FUN_0603273E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x060327EC] = 0x00000022} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD023\n"  /* mov.l @(0x8C,PC),r0  {[0x060327D8] = 0x06026E94} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603274C, \"ax\"\n"

    ".global _FUN_0603274C\n"
    ".type _FUN_0603274C, @function\n"
    "_FUN_0603274C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x060327F0] = 0x00000026} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD021\n"  /* mov.l @(0x84,PC),r0  {[0x060327E0] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603275A, \"ax\"\n"

    ".global _FUN_0603275A\n"
    ".type _FUN_0603275A, @function\n"
    "_FUN_0603275A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD024\n"  /* mov.l @(0x90,PC),r0  {[0x060327F4] = 0x00000024} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x060327D0] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032768, \"ax\"\n"

    ".global _FUN_06032768\n"
    ".type _FUN_06032768, @function\n"
    "_FUN_06032768:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD021\n"  /* mov.l @(0x84,PC),r0  {[0x060327F8] = 0x00000084} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xA029\n"  /* bra 0x060327FC */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x23C8\n"  /* tst r12,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E0C\n"  /* extu.b r0,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0014\n"  /* mov.b r1,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026E94 */
    ".word 0x6E94\n"  /* mov.b @r9+,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0054\n"  /* mov.b r5,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0022\n"  /* stc vbr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0026\n"  /* mov.l r2,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0084\n"  /* mov.b r8,@(r0,r0) */
    ".word 0xD09D\n"  /* mov.l @(0x274,PC),r0  {[0x06032A74] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060327FE, \"ax\"\n"

    ".global _FUN_060327FE\n"
    ".type _FUN_060327FE, @function\n"
    "_FUN_060327FE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD9C\n"  /* mov.l @(0x270,PC),r13  {[0x06032A78] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD09C\n"  /* mov.l @(0x270,PC),r0  {[0x06032A7C] = 0x00000018} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD09A\n"  /* mov.l @(0x268,PC),r0  {[0x06032A80] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032816, \"ax\"\n"

    ".global _FUN_06032816\n"
    ".type _FUN_06032816, @function\n"
    "_FUN_06032816:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD099\n"  /* mov.l @(0x264,PC),r0  {[0x06032A84] = 0x00000028} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD099\n"  /* mov.l @(0x264,PC),r0  {[0x06032A88] = 0x06026E94} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032824, \"ax\"\n"

    ".global _FUN_06032824\n"
    ".type _FUN_06032824, @function\n"
    "_FUN_06032824:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD097\n"  /* mov.l @(0x25C,PC),r0  {[0x06032A8C] = 0x0000002C} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD097\n"  /* mov.l @(0x25C,PC),r0  {[0x06032A90] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032832, \"ax\"\n"

    ".global _FUN_06032832\n"
    ".type _FUN_06032832, @function\n"
    "_FUN_06032832:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD096\n"  /* mov.l @(0x258,PC),r0  {[0x06032A94] = 0x0000002A} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD096\n"  /* mov.l @(0x258,PC),r0  {[0x06032A98] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032840, \"ax\"\n"

    ".global _FUN_06032840\n"
    ".type _FUN_06032840, @function\n"
    "_FUN_06032840:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD094\n"  /* mov.l @(0x250,PC),r0  {[0x06032A9C] = 0x000000B4} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD088\n"  /* mov.l @(0x220,PC),r0  {[0x06032AA0] = 0x00000024} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD07D\n"  /* mov.l @(0x1F4,PC),r0  {[0x06032A80] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603288A, \"ax\"\n"

    ".global _FUN_0603288A\n"
    ".type _FUN_0603288A, @function\n"
    "_FUN_0603288A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD084\n"  /* mov.l @(0x210,PC),r0  {[0x06032AA4] = 0x0000002E} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD07E\n"  /* mov.l @(0x1F8,PC),r0  {[0x06032A90] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032898, \"ax\"\n"

    ".global _FUN_06032898\n"
    ".type _FUN_06032898, @function\n"
    "_FUN_06032898:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD081\n"  /* mov.l @(0x204,PC),r0  {[0x06032AA8] = 0x000000E4} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD075\n"  /* mov.l @(0x1D4,PC),r0  {[0x06032AAC] = 0x00000030} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD067\n"  /* mov.l @(0x19C,PC),r0  {[0x06032A80] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060328E2, \"ax\"\n"

    ".global _FUN_060328E2\n"
    ".type _FUN_060328E2, @function\n"
    "_FUN_060328E2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD070\n"  /* mov.l @(0x1C0,PC),r0  {[0x06032AAC] = 0x00000030} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD068\n"  /* mov.l @(0x1A0,PC),r0  {[0x06032A90] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060328F0, \"ax\"\n"

    ".global _FUN_060328F0\n"
    ".type _FUN_060328F0, @function\n"
    "_FUN_060328F0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD06D\n"  /* mov.l @(0x1B4,PC),r0  {[0x06032AB0] = 0x00000114} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD061\n"  /* mov.l @(0x184,PC),r0  {[0x06032AB4] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032930, \"ax\"\n"

    ".global _FUN_06032930\n"
    ".type _FUN_06032930, @function\n"
    "_FUN_06032930:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD4F\n"  /* mov.l @(0x13C,PC),r13  {[0x06032A78] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD05E\n"  /* mov.l @(0x178,PC),r0  {[0x06032AB8] = 0x0000003C} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD04E\n"  /* mov.l @(0x138,PC),r0  {[0x06032A80] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032948, \"ax\"\n"

    ".global _FUN_06032948\n"
    ".type _FUN_06032948, @function\n"
    "_FUN_06032948:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD05A\n"  /* mov.l @(0x168,PC),r0  {[0x06032ABC] = 0x00000032} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD04C\n"  /* mov.l @(0x130,PC),r0  {[0x06032A88] = 0x06026E94} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032956, \"ax\"\n"

    ".global _FUN_06032956\n"
    ".type _FUN_06032956, @function\n"
    "_FUN_06032956:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD058\n"  /* mov.l @(0x160,PC),r0  {[0x06032AC0] = 0x00000036} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD04B\n"  /* mov.l @(0x12C,PC),r0  {[0x06032A90] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032964, \"ax\"\n"

    ".global _FUN_06032964\n"
    ".type _FUN_06032964, @function\n"
    "_FUN_06032964:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD055\n"  /* mov.l @(0x154,PC),r0  {[0x06032AC4] = 0x00000034} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD049\n"  /* mov.l @(0x124,PC),r0  {[0x06032A98] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032972, \"ax\"\n"

    ".global _FUN_06032972\n"
    ".type _FUN_06032972, @function\n"
    "_FUN_06032972:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD052\n"  /* mov.l @(0x148,PC),r0  {[0x06032AC8] = 0x00000144} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD046\n"  /* mov.l @(0x118,PC),r0  {[0x06032ACC] = 0x00000048} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD031\n"  /* mov.l @(0xC4,PC),r0  {[0x06032A80] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060329BC, \"ax\"\n"

    ".global _FUN_060329BC\n"
    ".type _FUN_060329BC, @function\n"
    "_FUN_060329BC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD042\n"  /* mov.l @(0x108,PC),r0  {[0x06032AD0] = 0x00000038} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD031\n"  /* mov.l @(0xC4,PC),r0  {[0x06032A90] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060329CA, \"ax\"\n"

    ".global _FUN_060329CA\n"
    ".type _FUN_060329CA, @function\n"
    "_FUN_060329CA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD03F\n"  /* mov.l @(0xFC,PC),r0  {[0x06032AD4] = 0x00000174} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD033\n"  /* mov.l @(0xCC,PC),r0  {[0x06032AD8] = 0x00000054} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06032A80] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032A14, \"ax\"\n"

    ".global _FUN_06032A14\n"
    ".type _FUN_06032A14, @function\n"
    "_FUN_06032A14:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD02F\n"  /* mov.l @(0xBC,PC),r0  {[0x06032ADC] = 0x0000003A} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06032A90] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032A22, \"ax\"\n"

    ".global _FUN_06032A22\n"
    ".type _FUN_06032A22, @function\n"
    "_FUN_06032A22:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x06032AE0] = 0x000001A4} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06032AB4] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032A62, \"ax\"\n"

    ".global _FUN_06032A62\n"
    ".type _FUN_06032A62, @function\n"
    "_FUN_06032A62:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD03\n"  /* mov.l @(0xC,PC),r13  {[0x06032A78] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xA039\n"  /* bra 0x06032AE4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026E94 */
    ".word 0x6E94\n"  /* mov.b @r9+,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x002C\n"  /* mov.b @(r0,r2),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B4\n"  /* mov.b r11,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x002E\n"  /* mov.l @(r0,r2),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00E4\n"  /* mov.b r14,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0030\n"  /* .word 0x0030 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0114\n"  /* mov.b r1,@(r0,r1) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x003C\n"  /* mov.b @(r0,r3),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0032\n"  /* .word 0x0032 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0036\n"  /* mov.l r3,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0034\n"  /* mov.b r3,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0144\n"  /* mov.b r4,@(r0,r1) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0048\n"  /* clrs */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0038\n"  /* ldtlb */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0174\n"  /* mov.b r7,@(r0,r1) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0054\n"  /* mov.b r5,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x003A\n"  /* .word 0x003A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01A4\n"  /* mov.b r10,@(r0,r1) */
    ".word 0xD08E\n"  /* mov.l @(0x238,PC),r0  {[0x06032D20] = 0x00000060} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD08D\n"  /* mov.l @(0x234,PC),r0  {[0x06032D24] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032AF0, \"ax\"\n"

    ".global _FUN_06032AF0\n"
    ".type _FUN_06032AF0, @function\n"
    "_FUN_06032AF0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD08B\n"  /* mov.l @(0x22C,PC),r0  {[0x06032D28] = 0x0000003C} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD08B\n"  /* mov.l @(0x22C,PC),r0  {[0x06032D2C] = 0x06026E94} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032AFE, \"ax\"\n"

    ".global _FUN_06032AFE\n"
    ".type _FUN_06032AFE, @function\n"
    "_FUN_06032AFE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD08A\n"  /* mov.l @(0x228,PC),r0  {[0x06032D30] = 0x00000040} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD08A\n"  /* mov.l @(0x228,PC),r0  {[0x06032D34] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032B0C, \"ax\"\n"

    ".global _FUN_06032B0C\n"
    ".type _FUN_06032B0C, @function\n"
    "_FUN_06032B0C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD088\n"  /* mov.l @(0x220,PC),r0  {[0x06032D38] = 0x0000003E} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD088\n"  /* mov.l @(0x220,PC),r0  {[0x06032D3C] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032B1A, \"ax\"\n"

    ".global _FUN_06032B1A\n"
    ".type _FUN_06032B1A, @function\n"
    "_FUN_06032B1A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD086\n"  /* mov.l @(0x218,PC),r0  {[0x06032D40] = 0x000001D4} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD07A\n"  /* mov.l @(0x1E8,PC),r0  {[0x06032D44] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032B5A, \"ax\"\n"

    ".global _FUN_06032B5A\n"
    ".type _FUN_06032B5A, @function\n"
    "_FUN_06032B5A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD79\n"  /* mov.l @(0x1E4,PC),r13  {[0x06032D48] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD079\n"  /* mov.l @(0x1E4,PC),r0  {[0x06032D4C] = 0x0000006C} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD06C\n"  /* mov.l @(0x1B0,PC),r0  {[0x06032D24] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032B72, \"ax\"\n"

    ".global _FUN_06032B72\n"
    ".type _FUN_06032B72, @function\n"
    "_FUN_06032B72:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD075\n"  /* mov.l @(0x1D4,PC),r0  {[0x06032D50] = 0x00000042} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD06B\n"  /* mov.l @(0x1AC,PC),r0  {[0x06032D2C] = 0x06026E94} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032B80, \"ax\"\n"

    ".global _FUN_06032B80\n"
    ".type _FUN_06032B80, @function\n"
    "_FUN_06032B80:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD072\n"  /* mov.l @(0x1C8,PC),r0  {[0x06032D54] = 0x00000046} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD069\n"  /* mov.l @(0x1A4,PC),r0  {[0x06032D34] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032B8E, \"ax\"\n"

    ".global _FUN_06032B8E\n"
    ".type _FUN_06032B8E, @function\n"
    "_FUN_06032B8E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD070\n"  /* mov.l @(0x1C0,PC),r0  {[0x06032D58] = 0x00000044} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD068\n"  /* mov.l @(0x1A0,PC),r0  {[0x06032D3C] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032B9C, \"ax\"\n"

    ".global _FUN_06032B9C\n"
    ".type _FUN_06032B9C, @function\n"
    "_FUN_06032B9C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD06D\n"  /* mov.l @(0x1B4,PC),r0  {[0x06032D5C] = 0x00000204} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD061\n"  /* mov.l @(0x184,PC),r0  {[0x06032D60] = 0x00000078} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD04F\n"  /* mov.l @(0x13C,PC),r0  {[0x06032D24] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032BE6, \"ax\"\n"

    ".global _FUN_06032BE6\n"
    ".type _FUN_06032BE6, @function\n"
    "_FUN_06032BE6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD05D\n"  /* mov.l @(0x174,PC),r0  {[0x06032D64] = 0x00000048} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD050\n"  /* mov.l @(0x140,PC),r0  {[0x06032D34] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032BF4, \"ax\"\n"

    ".global _FUN_06032BF4\n"
    ".type _FUN_06032BF4, @function\n"
    "_FUN_06032BF4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD05A\n"  /* mov.l @(0x168,PC),r0  {[0x06032D68] = 0x00000234} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD04E\n"  /* mov.l @(0x138,PC),r0  {[0x06032D6C] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032C34, \"ax\"\n"

    ".global _FUN_06032C34\n"
    ".type _FUN_06032C34, @function\n"
    "_FUN_06032C34:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD42\n"  /* mov.l @(0x108,PC),r13  {[0x06032D48] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD04B\n"  /* mov.l @(0x12C,PC),r0  {[0x06032D70] = 0x00000084} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD036\n"  /* mov.l @(0xD8,PC),r0  {[0x06032D24] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032C4C, \"ax\"\n"

    ".global _FUN_06032C4C\n"
    ".type _FUN_06032C4C, @function\n"
    "_FUN_06032C4C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD047\n"  /* mov.l @(0x11C,PC),r0  {[0x06032D74] = 0x0000004A} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD034\n"  /* mov.l @(0xD0,PC),r0  {[0x06032D2C] = 0x06026E94} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032C5A, \"ax\"\n"

    ".global _FUN_06032C5A\n"
    ".type _FUN_06032C5A, @function\n"
    "_FUN_06032C5A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD045\n"  /* mov.l @(0x114,PC),r0  {[0x06032D78] = 0x0000004E} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD033\n"  /* mov.l @(0xCC,PC),r0  {[0x06032D34] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032C68, \"ax\"\n"

    ".global _FUN_06032C68\n"
    ".type _FUN_06032C68, @function\n"
    "_FUN_06032C68:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD042\n"  /* mov.l @(0x108,PC),r0  {[0x06032D7C] = 0x0000004C} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD031\n"  /* mov.l @(0xC4,PC),r0  {[0x06032D3C] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032C76, \"ax\"\n"

    ".global _FUN_06032C76\n"
    ".type _FUN_06032C76, @function\n"
    "_FUN_06032C76:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD03F\n"  /* mov.l @(0xFC,PC),r0  {[0x06032D80] = 0x00000264} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD033\n"  /* mov.l @(0xCC,PC),r0  {[0x06032D84] = 0x00000090} */
    ".word 0x30CC\n"  /* add r12,r0 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6606\n"  /* mov.l @r0+,r6 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06032D24] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032CC0, \"ax\"\n"

    ".global _FUN_06032CC0\n"
    ".type _FUN_06032CC0, @function\n"
    "_FUN_06032CC0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD02F\n"  /* mov.l @(0xBC,PC),r0  {[0x06032D88] = 0x00000050} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06032D34] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032CCE, \"ax\"\n"

    ".global _FUN_06032CCE\n"
    ".type _FUN_06032CCE, @function\n"
    "_FUN_06032CCE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x61D3\n"  /* mov r13,r1 */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x06032D8C] = 0x00000294} */
    ".word 0x30EC\n"  /* add r14,r0 */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1020\n"  /* mov.l r2,@(0x0,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1021\n"  /* mov.l r2,@(0x4,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1022\n"  /* mov.l r2,@(0x8,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1023\n"  /* mov.l r2,@(0xC,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1025\n"  /* mov.l r2,@(0x14,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1026\n"  /* mov.l r2,@(0x18,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1027\n"  /* mov.l r2,@(0x1C,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1028\n"  /* mov.l r2,@(0x20,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x1029\n"  /* mov.l r2,@(0x24,r0) */
    ".word 0x6216\n"  /* mov.l @r1+,r2 */
    ".word 0x102A\n"  /* mov.l r2,@(0x28,r0) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x102B\n"  /* mov.l r2,@(0x2C,r0) */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x06032D6C] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032D0E, \"ax\"\n"

    ".global _FUN_06032D0E\n"
    ".type _FUN_06032D0E, @function\n"
    "_FUN_06032D0E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD0C\n"  /* mov.l @(0x30,PC),r13  {[0x06032D48] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x003C\n"  /* mov.b @(r0,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026E94 */
    ".word 0x6E94\n"  /* mov.b @r9+,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01D4\n"  /* mov.b r13,@(r0,r1) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x006C\n"  /* mov.b @(r0,r6),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0042\n"  /* .word 0x0042 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0046\n"  /* mov.l r4,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0044\n"  /* mov.b r4,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0204\n"  /* mov.b r0,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0078\n"  /* .word 0x0078 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0048\n"  /* clrs */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0234\n"  /* mov.b r3,@(r0,r2) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0084\n"  /* mov.b r8,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x004A\n"  /* .word 0x004A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x004E\n"  /* mov.l @(r0,r4),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x004C\n"  /* mov.b @(r0,r4),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0264\n"  /* mov.b r6,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0050\n"  /* .word 0x0050 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0294\n"  /* mov.b r9,@(r0,r2) */
    ".global _FUN_06032d90\n"
    "_FUN_06032d90:\n"
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x06032DEC] = 0x0607EAD8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD116\n"  /* mov.l @(0x58,PC),r1  {[0x06032DF0] = 0x0000000C} */
    ".word 0x210E\n"  /* mulu.w r0,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06032DF4] = 0x060624A4} */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06032DEC] = 0x0607EAD8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x06032DF8] = 0x060624F8} */
    ".word 0x021E\n"  /* mov.l @(r0,r1),r2 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06032DFC] = 0x000002DC} */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x6126\n"  /* mov.l @r2+,r1 */
    ".word 0x6436\n"  /* mov.l @r3+,r4 */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x06032E00] = 0x00000000} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x6126\n"  /* mov.l @r2+,r1 */
    ".word 0x6436\n"  /* mov.l @r3+,r4 */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06032E04] = 0x00000004} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x6126\n"  /* mov.l @r2+,r1 */
    ".word 0x6436\n"  /* mov.l @r3+,r4 */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06032E08] = 0x00000008} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x6125\n"  /* mov.w @r2+,r1 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06032DF0] = 0x0000000C} */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0x6124\n"  /* mov.b @r2+,r1 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x06032E0C] = 0x000002DD} */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06032E0C] = 0x000002DD} */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06032E10] = 0x06062624} */
    ".word 0x021E\n"  /* mov.l @(r0,r1),r2 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06032E14] = 0x000002D8} */
    ".word 0x000B\n"  /* rts */
    ".word 0x0E26\n"  /* mov.l r2,@(r0,r14) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x24A4\n"  /* mov.b r10,@-r4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x24F8\n"  /* tst r15,r4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02DC\n"  /* mov.b @(r0,r13),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02DD\n"  /* mov.w @(r0,r13),r2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2624\n"  /* mov.b r2,@-r6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02D8\n"  /* .word 0x02D8 */
    ".global _FUN_06032e18\n"
    "_FUN_06032e18:\n"
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x06032E44] = 0x000002D0} */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x06032E48] = 0x060627F8} */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x6146\n"  /* mov.l @r4+,r1 */
    ".word 0x6246\n"  /* mov.l @r4+,r2 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06032E4C] = 0x000002CC} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06032E50] = 0x000002C8} */
    ".word 0x0E26\n"  /* mov.l r2,@(r0,r14) */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06032E54] = 0x0000000E} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06032E58] = 0x00000002} */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x8910\n"  /* bt 0x06032E5C */
    ".word 0x6123\n"  /* mov r2,r1 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0xA00E\n"  /* bra 0x06032E5E */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02D0\n"  /* .word 0x02D0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x27F8\n"  /* tst r15,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02CC\n"  /* mov.b @(r0,r12),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02C8\n"  /* .word 0x02C8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0xD101\n"  /* mov.l @(0x4,PC),r1  {[0x06032E64] = 0x00000001} */
    ".word 0xD002\n"  /* mov.l @(0x8,PC),r0  {[0x06032E68] = 0x000002C4} */
    ".word 0x000B\n"  /* rts */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02C4\n"  /* mov.b r12,@(r0,r2) */
    ".global _FUN_06032e6c\n"
    "_FUN_06032e6c:\n"
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06032E90] = 0x000002C4} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0xD108\n"  /* mov.l @(0x20,PC),r1  {[0x06032E94] = 0x00000044} */
    ".word 0x210F\n"  /* muls.w r0,r1 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06032E98] = 0x000002CC} */
    ".word 0x02EE\n"  /* mov.l @(r0,r14),r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06032E9C] = 0x00000010} */
    ".word 0x33EC\n"  /* add r14,r3 */
    ".word 0xD607\n"  /* mov.l @(0x1C,PC),r6  {[0x06032EA0] = 0x00000011} */
    ".word 0x6726\n"  /* mov.l @r2+,r7 */
    ".word 0x2372\n"  /* mov.l r7,@r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x4610\n"  /* dt r6 */
    ".word 0x8BFA\n"  /* bf 0x06032E82 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02C4\n"  /* mov.b r12,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0044\n"  /* mov.b r4,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x02CC\n"  /* mov.b @(r0,r12),r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".global _FUN_06032ea4\n"
    "_FUN_06032ea4:\n"
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x06032EB4] = 0x0000000E} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x06032EB8] = 0x0000001C} */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x8B06\n"  /* bf 0x06032EBC */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0xD049\n"  /* mov.l @(0x124,PC),r0  {[0x06032FE4] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032EBE, \"ax\"\n"

    ".global _FUN_06032EBE\n"
    ".type _FUN_06032EBE, @function\n"
    "_FUN_06032EBE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD48\n"  /* mov.l @(0x120,PC),r13  {[0x06032FE8] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD048\n"  /* mov.l @(0x120,PC),r0  {[0x06032FEC] = 0x00000000} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD048\n"  /* mov.l @(0x120,PC),r0  {[0x06032FF0] = 0x00000004} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD048\n"  /* mov.l @(0x120,PC),r0  {[0x06032FF4] = 0x00000008} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD048\n"  /* mov.l @(0x120,PC),r0  {[0x06032FF8] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032ED8, \"ax\"\n"

    ".global _FUN_06032ED8\n"
    ".type _FUN_06032ED8, @function\n"
    "_FUN_06032ED8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD046\n"  /* mov.l @(0x118,PC),r0  {[0x06032FFC] = 0x0000000C} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD046\n"  /* mov.l @(0x118,PC),r0  {[0x06033000] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032EE6, \"ax\"\n"

    ".global _FUN_06032EE6\n"
    ".type _FUN_06032EE6, @function\n"
    "_FUN_06032EE6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD045\n"  /* mov.l @(0x114,PC),r0  {[0x06033004] = 0x0000000E} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0xD03F\n"  /* mov.l @(0xFC,PC),r0  {[0x06032FF0] = 0x00000004} */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x8924\n"  /* bt 0x06032F42 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0xD03A\n"  /* mov.l @(0xE8,PC),r0  {[0x06032FE4] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032EFC, \"ax\"\n"

    ".global _FUN_06032EFC\n"
    ".type _FUN_06032EFC, @function\n"
    "_FUN_06032EFC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD38\n"  /* mov.l @(0xE0,PC),r13  {[0x06032FE8] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD03F\n"  /* mov.l @(0xFC,PC),r0  {[0x06033008] = 0x060624C8} */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x6506\n"  /* mov.l @r0+,r5 */
    ".word 0x6602\n"  /* mov.l @r0,r6 */
    ".word 0xD039\n"  /* mov.l @(0xE4,PC),r0  {[0x06032FF8] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F12, \"ax\"\n"

    ".global _FUN_06032F12\n"
    ".type _FUN_06032F12, @function\n"
    "_FUN_06032F12:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD03B\n"  /* mov.l @(0xEC,PC),r0  {[0x06033008] = 0x060624C8} */
    ".word 0x5403\n"  /* mov.l @(0xC,r0),r4 */
    ".word 0xD03B\n"  /* mov.l @(0xEC,PC),r0  {[0x0603300C] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F20, \"ax\"\n"

    ".global _FUN_06032F20\n"
    ".type _FUN_06032F20, @function\n"
    "_FUN_06032F20:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD039\n"  /* mov.l @(0xE4,PC),r0  {[0x06033010] = 0x0600A4AA} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F2A, \"ax\"\n"

    ".global _FUN_06032F2A\n"
    ".type _FUN_06032F2A, @function\n"
    "_FUN_06032F2A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD038\n"  /* mov.l @(0xE0,PC),r0  {[0x06033014] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F34, \"ax\"\n"

    ".global _FUN_06032F34\n"
    ".type _FUN_06032F34, @function\n"
    "_FUN_06032F34:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD2A\n"  /* mov.l @(0xA8,PC),r13  {[0x06032FE8] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x06032FF4] = 0x00000008} */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x8924\n"  /* bt 0x06032F92 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x06032FE4] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F4C, \"ax\"\n"

    ".global _FUN_06032F4C\n"
    ".type _FUN_06032F4C, @function\n"
    "_FUN_06032F4C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD24\n"  /* mov.l @(0x90,PC),r13  {[0x06032FE8] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD02B\n"  /* mov.l @(0xAC,PC),r0  {[0x06033008] = 0x060624C8} */
    ".word 0x5404\n"  /* mov.l @(0x10,r0),r4 */
    ".word 0x5505\n"  /* mov.l @(0x14,r0),r5 */
    ".word 0x5606\n"  /* mov.l @(0x18,r0),r6 */
    ".word 0xD025\n"  /* mov.l @(0x94,PC),r0  {[0x06032FF8] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F62, \"ax\"\n"

    ".global _FUN_06032F62\n"
    ".type _FUN_06032F62, @function\n"
    "_FUN_06032F62:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD027\n"  /* mov.l @(0x9C,PC),r0  {[0x06033008] = 0x060624C8} */
    ".word 0x5407\n"  /* mov.l @(0x1C,r0),r4 */
    ".word 0xD027\n"  /* mov.l @(0x9C,PC),r0  {[0x0603300C] = 0x06026F2A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F70, \"ax\"\n"

    ".global _FUN_06032F70\n"
    ".type _FUN_06032F70, @function\n"
    "_FUN_06032F70:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD025\n"  /* mov.l @(0x94,PC),r0  {[0x06033010] = 0x0600A4AA} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F7A, \"ax\"\n"

    ".global _FUN_06032F7A\n"
    ".type _FUN_06032F7A, @function\n"
    "_FUN_06032F7A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD024\n"  /* mov.l @(0x90,PC),r0  {[0x06033014] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F84, \"ax\"\n"

    ".global _FUN_06032F84\n"
    ".type _FUN_06032F84, @function\n"
    "_FUN_06032F84:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD16\n"  /* mov.l @(0x58,PC),r13  {[0x06032FE8] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0xD021\n"  /* mov.l @(0x84,PC),r0  {[0x06033018] = 0x00000010} */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x891C\n"  /* bt 0x06032FD2 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06032FE4] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032F9A, \"ax\"\n"

    ".global _FUN_06032F9A\n"
    ".type _FUN_06032F9A, @function\n"
    "_FUN_06032F9A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD11\n"  /* mov.l @(0x44,PC),r13  {[0x06032FE8] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x06033008] = 0x060624C8} */
    ".word 0x5408\n"  /* mov.l @(0x20,r0),r4 */
    ".word 0x5509\n"  /* mov.l @(0x24,r0),r5 */
    ".word 0x560A\n"  /* mov.l @(0x28,r0),r6 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06032FF8] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032FB0, \"ax\"\n"

    ".global _FUN_06032FB0\n"
    ".type _FUN_06032FB0, @function\n"
    "_FUN_06032FB0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD40C\n"  /* mov.l @(0x30,PC),r4  {[0x06032FEC] = 0x00000000} */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x0603301C] = 0x0600A474} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032FBC, \"ax\"\n"

    ".global _FUN_06032FBC\n"
    ".type _FUN_06032FBC, @function\n"
    "_FUN_06032FBC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06033014] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032FC6, \"ax\"\n"

    ".global _FUN_06032FC6\n"
    ".type _FUN_06032FC6, @function\n"
    "_FUN_06032FC6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD06\n"  /* mov.l @(0x18,PC),r13  {[0x06032FE8] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06033014] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06032FD4, \"ax\"\n"

    ".global _FUN_06032FD4\n"
    ".type _FUN_06032FD4, @function\n"
    "_FUN_06032FD4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD02\n"  /* mov.l @(0x8,PC),r13  {[0x06032FE8] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x24C8\n"  /* tst r12,r4 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A4AA */
    ".word 0xA4AA\n"  /* bra 0x0603396A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A474 */
    ".word 0xA474\n"  /* bra 0x0603390A */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033086, \"ax\"\n"

    ".global _FUN_06033086\n"
    ".type _FUN_06033086, @function\n"
    "_FUN_06033086:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB152\n"  /* bsr 0x06033330 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603308E, \"ax\"\n"

    ".global _FUN_0603308E\n"
    ".type _FUN_0603308E, @function\n"
    "_FUN_0603308E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB006\n"  /* bsr 0x060330A0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3864\n"  /* .word 0x3864 */
    ".global _FUN_060330a0\n"
    "_FUN_060330a0:\n"
    ".word 0xD028\n"  /* mov.l @(0xA0,PC),r0  {[0x06033144] = 0x06033870} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060330A4, \"ax\"\n"

    ".global _FUN_060330A4\n"
    ".type _FUN_060330A4, @function\n"
    "_FUN_060330A4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB061\n"  /* bsr 0x0603316C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD826\n"  /* mov.l @(0x98,PC),r8  {[0x06033148] = 0x00000010} */
    ".word 0xD927\n"  /* mov.l @(0x9C,PC),r9  {[0x0603314C] = 0x00000018} */
    ".word 0x0D8E\n"  /* mov.l @(r0,r8),r13 */
    ".word 0x0E9E\n"  /* mov.l @(r0,r9),r14 */
    ".word 0xDA26\n"  /* mov.l @(0x98,PC),r10  {[0x06033150] = 0x00000268} */
    ".word 0x30AC\n"  /* add r10,r0 */
    ".word 0xD726\n"  /* mov.l @(0x98,PC),r7  {[0x06033154] = 0x0603386C} */
    ".word 0x6772\n"  /* mov.l @r7,r7 */
    ".word 0x6772\n"  /* mov.l @r7,r7 */
    ".word 0x77FF\n"  /* add #-1,r7 */
    ".word 0x0B8E\n"  /* mov.l @(r0,r8),r11 */
    ".word 0x0C9E\n"  /* mov.l @(r0,r9),r12 */
    ".word 0x6BBB\n"  /* neg r11,r11 */
    ".word 0x6CCB\n"  /* neg r12,r12 */
    ".word 0x3BDC\n"  /* add r13,r11 */
    ".word 0x3CEC\n"  /* add r14,r12 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x4421\n"  /* shar r4 */
    ".word 0x3B4C\n"  /* add r4,r11 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0x61B3\n"  /* mov r11,r1 */
    ".word 0xD220\n"  /* mov.l @(0x80,PC),r2  {[0x06033158] = 0x00220000} */
    ".word 0x4111\n"  /* cmp/pz r1 */
    ".word 0x8900\n"  /* bt 0x060330DE */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x3127\n"  /* cmp/gt r2,r1 */
    ".word 0x8929\n"  /* bt 0x06033136 */
    ".word 0x61C3\n"  /* mov r12,r1 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0603315C] = 0x001A0000} */
    ".word 0x4111\n"  /* cmp/pz r1 */
    ".word 0x8900\n"  /* bt 0x060330EC */
    ".word 0x611B\n"  /* neg r1,r1 */
    ".word 0x3127\n"  /* cmp/gt r2,r1 */
    ".word 0x8922\n"  /* bt 0x06033136 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB039\n"  /* bsr 0x0603316C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x606B\n"  /* neg r6,r0 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033100, \"ax\"\n"

    ".global _FUN_06033100\n"
    ".type _FUN_06033100, @function\n"
    "_FUN_06033100:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB041\n"  /* bsr 0x06033188 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x306C\n"  /* add r6,r0 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06033160] = 0x06033884} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x06033164] = 0x00000700} */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8900\n"  /* bt 0x0603311A */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x304C\n"  /* add r4,r0 */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x06033168] = 0x0000FFFF} */
    ".word 0x2049\n"  /* and r4,r0 */
    ".word 0x4019\n"  /* shlr8 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8900\n"  /* bt 0x0603312C */
    ".word 0x611B\n"  /* neg r1,r1 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603312C, \"ax\"\n"

    ".global _FUN_0603312C\n"
    ".type _FUN_0603312C, @function\n"
    "_FUN_0603312C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB06D\n"  /* bsr 0x0603320C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x30AC\n"  /* add r10,r0 */
    ".word 0x77FF\n"  /* add #-1,r7 */
    ".word 0x4715\n"  /* cmp/pl r7 */
    ".word 0x89C0\n"  /* bt 0x060330C0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3870\n"  /* cmp/eq r7,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0268\n"  /* .word 0x0268 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x386C\n"  /* add r6,r8 */
    ".word 0x0022\n"  /* stc vbr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3884\n"  /* .word 0x3884 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0700\n"  /* .word 0x0700 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".global _FUN_0603316c\n"
    "_FUN_0603316c:\n"
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06033180] = 0x00000020} */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06033184] = 0x000001D8} */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x664B\n"  /* neg r4,r6 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01D8\n"  /* .word 0x01D8 */
    ".global _FUN_06033188\n"
    "_FUN_06033188:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x060331F8] = 0x0000FFFF} */
    ".word 0x2409\n"  /* and r0,r4 */
    ".word 0xD519\n"  /* mov.l @(0x64,PC),r5  {[0x060331FC] = 0x0606318C} */
    ".word 0xD619\n"  /* mov.l @(0x64,PC),r6  {[0x06033200] = 0x06063190} */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x06033204] = 0x06027358} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603319C, \"ax\"\n"

    ".global _FUN_0603319C\n"
    ".type _FUN_0603319C, @function\n"
    "_FUN_0603319C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x06033208] = 0x06027552} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060331AA, \"ax\"\n"

    ".global _FUN_060331AA\n"
    ".type _FUN_060331AA, @function\n"
    "_FUN_060331AA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06033208] = 0x06027552} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060331BA, \"ax\"\n"

    ".global _FUN_060331BA\n"
    ".type _FUN_060331BA, @function\n"
    "_FUN_060331BA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0x6413\n"  /* mov r1,r4 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x06033208] = 0x06027552} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060331CA, \"ax\"\n"

    ".global _FUN_060331CA\n"
    ".type _FUN_060331CA, @function\n"
    "_FUN_060331CA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x6413\n"  /* mov r1,r4 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06033208] = 0x06027552} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060331DA, \"ax\"\n"

    ".global _FUN_060331DA\n"
    ".type _FUN_060331DA, @function\n"
    "_FUN_060331DA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6703\n"  /* mov r0,r7 */
    ".word 0x616B\n"  /* neg r6,r1 */
    ".word 0x318C\n"  /* add r8,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x327C\n"  /* add r7,r2 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x318C\n"  /* add r8,r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3190\n"  /* cmp/eq r9,r1 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7358\n"  /* add #88,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".global _FUN_0603320c\n"
    "_FUN_0603320c:\n"
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06033268] = 0x00030000} */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0603326C] = 0x0603390C} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x304C\n"  /* add r4,r0 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0xE606\n"  /* mov #6,r6 */
    ".word 0xE704\n"  /* mov #4,r7 */
    ".word 0x6034\n"  /* mov.b @r3+,r0 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x4509\n"  /* shlr2 r5 */
    ".word 0x4509\n"  /* shlr2 r5 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033230, \"ax\"\n"

    ".global _FUN_06033230\n"
    ".type _FUN_06033230, @function\n"
    "_FUN_06033230:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB021\n"  /* bsr 0x06033278 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x06033270] = 0x00010000} */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x6503\n"  /* mov r0,r5 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033240, \"ax\"\n"

    ".global _FUN_06033240\n"
    ".type _FUN_06033240, @function\n"
    "_FUN_06033240:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB019\n"  /* bsr 0x06033278 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x06033270] = 0x00010000} */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0x77FF\n"  /* add #-1,r7 */
    ".word 0x4715\n"  /* cmp/pl r7 */
    ".word 0x89EA\n"  /* bt 0x06033228 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06033274] = 0xFFF80000} */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06033270] = 0x00010000} */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0x76FF\n"  /* add #-1,r6 */
    ".word 0x4615\n"  /* cmp/pl r6 */
    ".word 0x89E2\n"  /* bt 0x06033226 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x390C\n"  /* add r0,r9 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFF8\n"  /* .word 0xFFF8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".global _FUN_06033278\n"
    "_FUN_06033278:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x3500\n"  /* cmp/eq r0,r5 */
    ".word 0x893D\n"  /* bt 0x06033302 */
    ".word 0xD022\n"  /* mov.l @(0x88,PC),r0  {[0x06033310] = 0x00240000} */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x06033314] = 0x001C0000} */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0xD022\n"  /* mov.l @(0x88,PC),r0  {[0x06033318] = 0x00040000} */
    ".word 0x3017\n"  /* cmp/gt r1,r0 */
    ".word 0x8936\n"  /* bt 0x06033302 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x8934\n"  /* bt 0x06033302 */
    ".word 0xD020\n"  /* mov.l @(0x80,PC),r0  {[0x0603331C] = 0x00460000} */
    ".word 0x3107\n"  /* cmp/gt r0,r1 */
    ".word 0x8931\n"  /* bt 0x06033302 */
    ".word 0xD020\n"  /* mov.l @(0x80,PC),r0  {[0x06033320] = 0x00360000} */
    ".word 0x3207\n"  /* cmp/gt r0,r2 */
    ".word 0x892E\n"  /* bt 0x06033302 */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x06033324] = 0x00008000} */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06033328] = 0x00010000} */
    ".word 0x2208\n"  /* tst r0,r2 */
    ".word 0x8900\n"  /* bt 0x060332AE */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2108\n"  /* tst r0,r1 */
    ".word 0x8900\n"  /* bt 0x060332B4 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x4229\n"  /* shlr16 r2 */
    ".word 0x4129\n"  /* shlr16 r1 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x611F\n"  /* exts.w r1,r1 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0xC9F8\n"  /* and #0xF8,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0xC9F8\n"  /* and #0xF8,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4001\n"  /* shlr r0 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x0603332C] = 0x060629AC} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6040\n"  /* mov.b @r4,r0 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0xE2F0\n"  /* mov #-16,r2 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x2148\n"  /* tst r4,r1 */
    ".word 0x8B02\n"  /* bf 0x060332FA */
    ".word 0xE20F\n"  /* mov #15,r2 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x2029\n"  /* and r2,r0 */
    ".word 0x205B\n"  /* or r5,r0 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x2400\n"  /* mov.b r0,@r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0046\n"  /* mov.l r4,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0036\n"  /* mov.l r3,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x29AC\n"  /* .word 0x29AC */
    ".global _FUN_06033330\n"
    "_FUN_06033330:\n"
    ".word 0xD505\n"  /* mov.l @(0x14,PC),r5  {[0x06033348] = 0x060430CE} */
    ".word 0xD406\n"  /* mov.l @(0x18,PC),r4  {[0x0603334C] = 0x060629AC} */
    ".word 0x9606\n"  /* mov.w @(0xC,PC),r6 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06033350] = 0x0602761E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033338, \"ax\"\n"

    ".global _FUN_06033338\n"
    ".type _FUN_06033338, @function\n"
    "_FUN_06033338:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x07E0\n"  /* .word 0x07E0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x30CE\n"  /* .word 0x30CE */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x29AC\n"  /* .word 0x29AC */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".global _FUN_06033354\n"
    "_FUN_06033354:\n"
    ".word 0xD517\n"  /* mov.l @(0x5C,PC),r5  {[0x060333B4] = 0x060338DC} */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x060333B8] = 0x06033868} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8B00\n"  /* bf 0x06033362 */
    ".word 0xD516\n"  /* mov.l @(0x58,PC),r5  {[0x060333BC] = 0x060338E8} */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x060333C0] = 0x06062D95} */
    ".word 0xE106\n"  /* mov #6,r1 */
    ".word 0x6054\n"  /* mov.b @r5+,r0 */
    ".word 0x2400\n"  /* mov.b r0,@r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6054\n"  /* mov.b @r5+,r0 */
    ".word 0x2400\n"  /* mov.b r0,@r4 */
    ".word 0x7403\n"  /* add #3,r4 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x3100\n"  /* cmp/eq r0,r1 */
    ".word 0x8BF5\n"  /* bf 0x06033366 */
    ".word 0xE706\n"  /* mov #6,r7 */
    ".word 0xD811\n"  /* mov.l @(0x44,PC),r8  {[0x060333C4] = 0x060338F4} */
    ".word 0xD912\n"  /* mov.l @(0x48,PC),r9  {[0x060333C8] = 0x060430CE} */
    ".word 0xDA12\n"  /* mov.l @(0x48,PC),r10  {[0x060333CC] = 0x060629AC} */
    ".word 0x6485\n"  /* mov.w @r8+,r4 */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0x34AC\n"  /* add r10,r4 */
    ".word 0x359C\n"  /* add r9,r5 */
    ".word 0x6685\n"  /* mov.w @r8+,r6 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060333D0] = 0x0602761E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603338E, \"ax\"\n"

    ".global _FUN_0603338E\n"
    ".type _FUN_0603338E, @function\n"
    "_FUN_0603338E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x77FF\n"  /* add #-1,r7 */
    ".word 0x4715\n"  /* cmp/pl r7 */
    ".word 0x89F2\n"  /* bt 0x06033382 */
    ".word 0xD50B\n"  /* mov.l @(0x2C,PC),r5  {[0x060333CC] = 0x060629AC} */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x060333D4] = 0x25E03700} */
    ".word 0x9606\n"  /* mov.w @(0xC,PC),r6 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x060333D0] = 0x0602761E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060333A4, \"ax\"\n"

    ".global _FUN_060333A4\n"
    ".type _FUN_060333A4, @function\n"
    "_FUN_060333A4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x07E0\n"  /* .word 0x07E0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x38DC\n"  /* add r13,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3868\n"  /* sub r6,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x38E8\n"  /* sub r14,r8 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2D95\n"  /* mov.w r9,@-r13 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x38F4\n"  /* .word 0x38F4 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x30CE\n"  /* .word 0x30CE */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x29AC\n"  /* .word 0x29AC */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x25E0\n"  /* mov.b r14,@r5 */
    ".word 0x3700\n"  /* cmp/eq r0,r7 */
    ".global _FUN_060333d8\n"
    "_FUN_060333d8:\n"
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060333E4, \"ax\"\n"

    ".global _FUN_060333E4\n"
    ".type _FUN_060333E4, @function\n"
    "_FUN_060333E4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06033454] = 0x06033870} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD11B\n"  /* mov.l @(0x6C,PC),r1  {[0x06033458] = 0x060629AA} */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x2121\n"  /* mov.w r2,@r1 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0x2125\n"  /* mov.w r2,@-r1 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060333F4, \"ax\"\n"

    ".global _FUN_060333F4\n"
    ".type _FUN_060333F4, @function\n"
    "_FUN_060333F4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0AB\n"  /* bsr 0x06033550 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD117\n"  /* mov.l @(0x5C,PC),r1  {[0x0603345C] = 0x0606299A} */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x2121\n"  /* mov.w r2,@r1 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033402, \"ax\"\n"

    ".global _FUN_06033402\n"
    ".type _FUN_06033402, @function\n"
    "_FUN_06033402:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB120\n"  /* bsr 0x06033648 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603340A, \"ax\"\n"

    ".global _FUN_0603340A\n"
    ".type _FUN_0603340A, @function\n"
    "_FUN_0603340A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB030\n"  /* bsr 0x06033470 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06033460] = 0x06033880} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8904\n"  /* bt 0x06033426 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x06033464] = 0x06033864} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8904\n"  /* bt 0x06033430 */
    ".word 0xD610\n"  /* mov.l @(0x40,PC),r6  {[0x06033468] = 0x0606298C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033428, \"ax\"\n"

    ".global _FUN_06033428\n"
    ".type _FUN_06033428, @function\n"
    "_FUN_06033428:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB169\n"  /* bsr 0x06033700 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD60E\n"  /* mov.l @(0x38,PC),r6  {[0x0603346C] = 0x0606299C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033432, \"ax\"\n"

    ".global _FUN_06033432\n"
    ".type _FUN_06033432, @function\n"
    "_FUN_06033432:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB164\n"  /* bsr 0x06033700 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603343A, \"ax\"\n"

    ".global _FUN_0603343A\n"
    ".type _FUN_0603343A, @function\n"
    "_FUN_0603343A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xBE1E\n"  /* bsr 0x0603307C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3870\n"  /* cmp/eq r7,r8 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x29AA\n"  /* xor r10,r9 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x299A\n"  /* xor r9,r9 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3880\n"  /* cmp/eq r8,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3864\n"  /* .word 0x3864 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x298C\n"  /* .word 0x298C */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x299C\n"  /* .word 0x299C */
    ".global _FUN_06033470\n"
    "_FUN_06033470:\n"
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x060334E8] = 0x060338C4} */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0xD01D\n"  /* mov.l @(0x74,PC),r0  {[0x060334EC] = 0x06033874} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x6135\n"  /* mov.w @r3+,r1 */
    ".word 0x6235\n"  /* mov.w @r3+,r2 */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x060334F0] = 0x06062970} */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x1400\n"  /* mov.l r0,@(0x0,r4) */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x8044\n"  /* mov.b r0,@(0x4,r4) */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x060334F4] = 0x0603387C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x8045\n"  /* mov.b r0,@(0x5,r4) */
    ".word 0xE00E\n"  /* mov #14,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x6535\n"  /* mov.w @r3+,r5 */
    ".word 0x351C\n"  /* add r1,r5 */
    ".word 0xD614\n"  /* mov.l @(0x50,PC),r6  {[0x060334F8] = 0x06033884} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6660\n"  /* mov.b @r6,r6 */
    ".word 0x4615\n"  /* cmp/pl r6 */
    ".word 0x8B01\n"  /* bf 0x060334B4 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x6513\n"  /* mov r1,r5 */
    ".word 0x8144\n"  /* mov.w r0,@(0x8,r4) */
    ".word 0x814A\n"  /* mov.w r0,@(0x14,r4) */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x8146\n"  /* mov.w r0,@(0xC,r4) */
    ".word 0x8148\n"  /* mov.w r0,@(0x10,r4) */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8145\n"  /* mov.w r0,@(0xA,r4) */
    ".word 0x8147\n"  /* mov.w r0,@(0xE,r4) */
    ".word 0x6035\n"  /* mov.w @r3+,r0 */
    ".word 0x302C\n"  /* add r2,r0 */
    ".word 0x8149\n"  /* mov.w r0,@(0x12,r4) */
    ".word 0x814B\n"  /* mov.w r0,@(0x16,r4) */
    ".word 0xD50B\n"  /* mov.l @(0x2C,PC),r5  {[0x060334FC] = 0x060785FC} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x06033500] = 0x060280F8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060334D2, \"ax\"\n"

    ".global _FUN_060334D2\n"
    ".type _FUN_060334D2, @function\n"
    "_FUN_060334D2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060334DA, \"ax\"\n"

    ".global _FUN_060334DA\n"
    ".type _FUN_060334DA, @function\n"
    "_FUN_060334DA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB012\n"  /* bsr 0x06033504 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x38C4\n"  /* .word 0x38C4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3874\n"  /* .word 0x3874 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2970\n"  /* mov.b r7,@r9 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x387C\n"  /* add r7,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3884\n"  /* .word 0x3884 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x85FC\n"  /* mov.w @(0x18,r15),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x80F8\n"  /* mov.b r0,@(0x8,r15) */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06033518] = 0x0605A008} */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x2012\n"  /* mov.l r1,@r0 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0603351C] = 0x060785FC} */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x7120\n"  /* add #32,r1 */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA008\n"  /* bra 0x0603352E */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x85FC\n"  /* mov.w @(0x18,r15),r0 */
    ".global _FUN_06033520\n"
    "_FUN_06033520:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x06033548] = 0x06062970} */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x0603354C] = 0x00000000} */
    ".word 0x1400\n"  /* mov.l r0,@(0x0,r4) */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x8044\n"  /* mov.b r0,@(0x4,r4) */
    ".word 0xD0D2\n"  /* mov.l @(0x348,PC),r0  {[0x0603387C] = 0x0605B734} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x8045\n"  /* mov.b r0,@(0x5,r4) */
    ".word 0xE016\n"  /* mov #22,r0 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0xA15B\n"  /* bra 0x060337FC */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2970\n"  /* mov.b r7,@r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".global _FUN_06033550\n"
    "_FUN_06033550:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD0C8\n"  /* mov.l @(0x320,PC),r0  {[0x06033874] = 0x0607EAD8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x060335D8] = 0x06033630} */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x060335DC] = 0x00000020} */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x060335E0] = 0x000001D8} */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x060335E4] = 0x000001CC} */
    ".word 0x042E\n"  /* mov.l @(r0,r2),r4 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x623B\n"  /* neg r3,r2 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x2126\n"  /* mov.l r2,@-r1 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033578, \"ax\"\n"

    ".global _FUN_06033578\n"
    ".type _FUN_06033578, @function\n"
    "_FUN_06033578:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB03B\n"  /* bsr 0x060335F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x060335E8] = 0x00000010} */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x060335EC] = 0x00000018} */
    ".word 0x022E\n"  /* mov.l @(r0,r2),r2 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x060335F0] = 0x06027552} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603358E, \"ax\"\n"

    ".global _FUN_0603358E\n"
    ".type _FUN_0603358E, @function\n"
    "_FUN_0603358E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x6573\n"  /* mov r7,r5 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x060335F0] = 0x06027552} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603359E, \"ax\"\n"

    ".global _FUN_0603359E\n"
    ".type _FUN_0603359E, @function\n"
    "_FUN_0603359E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6D03\n"  /* mov r0,r13 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060335F0] = 0x06027552} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060335AE, \"ax\"\n"

    ".global _FUN_060335AE\n"
    ".type _FUN_060335AE, @function\n"
    "_FUN_060335AE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6C03\n"  /* mov r0,r12 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x6573\n"  /* mov r7,r5 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x060335F0] = 0x06027552} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060335BE, \"ax\"\n"

    ".global _FUN_060335BE\n"
    ".type _FUN_060335BE, @function\n"
    "_FUN_060335BE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6B03\n"  /* mov r0,r11 */
    ".word 0x6BBB\n"  /* neg r11,r11 */
    ".word 0x3EBC\n"  /* add r11,r14 */
    ".word 0x21E6\n"  /* mov.l r14,@-r1 */
    ".word 0x3DCC\n"  /* add r12,r13 */
    ".word 0x21D6\n"  /* mov.l r13,@-r1 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3630\n"  /* cmp/eq r3,r6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01D8\n"  /* .word 0x01D8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01CC\n"  /* mov.b @(r0,r12),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".global _FUN_060335f4\n"
    "_FUN_060335f4:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD09F\n"  /* mov.l @(0x27C,PC),r0  {[0x06033874] = 0x0607EAD8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD409\n"  /* mov.l @(0x24,PC),r4  {[0x06033624] = 0x0603363C} */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06033628] = 0x06027348} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033606, \"ax\"\n"

    ".global _FUN_06033606\n"
    ".type _FUN_06033606, @function\n"
    "_FUN_06033606:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6703\n"  /* mov r0,r7 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0603362C] = 0x06027344} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033614, \"ax\"\n"

    ".global _FUN_06033614\n"
    ".type _FUN_06033614, @function\n"
    "_FUN_06033614:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6803\n"  /* mov r0,r8 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8E00\n"  /* .word 0x8E00 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7600\n"  /* add #0,r6 */
    ".global _FUN_06033648\n"
    "_FUN_06033648:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB051\n"  /* bsr 0x060336F2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x8B02\n"  /* bf 0x0603365A */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0xA009\n"  /* bra 0x0603366C */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0xD082\n"  /* mov.l @(0x208,PC),r0  {[0x06033864] = 0x0607EAE0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8928\n"  /* bt 0x060336B4 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0xD615\n"  /* mov.l @(0x54,PC),r6  {[0x060336BC] = 0x0603386C} */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0x76FF\n"  /* add #-1,r6 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x060336C0] = 0x00000224} */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x3340\n"  /* cmp/eq r4,r3 */
    ".word 0x8B00\n"  /* bf 0x0603367A */
    ".word 0xE401\n"  /* mov #1,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603367A, \"ax\"\n"

    ".global _FUN_0603367A\n"
    ".type _FUN_0603367A, @function\n"
    "_FUN_0603367A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB024\n"  /* bsr 0x060336C8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD510\n"  /* mov.l @(0x40,PC),r5  {[0x060336C4] = 0x00000268} */
    ".word 0x305C\n"  /* add r5,r0 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x3340\n"  /* cmp/eq r4,r3 */
    ".word 0x8902\n"  /* bt 0x06033692 */
    ".word 0x76FF\n"  /* add #-1,r6 */
    ".word 0x4615\n"  /* cmp/pl r6 */
    ".word 0x89F7\n"  /* bt 0x06033682 */
    ".word 0xE206\n"  /* mov #6,r2 */
    ".word 0xD37A\n"  /* mov.l @(0x1E8,PC),r3  {[0x06033880] = 0x06078635} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8906\n"  /* bt 0x060336AA */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x3043\n"  /* cmp/ge r4,r0 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x8B01\n"  /* bf 0x060336AA */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x324C\n"  /* add r4,r2 */
    ".word 0x2125\n"  /* mov.w r2,@-r1 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060336AC, \"ax\"\n"

    ".global _FUN_060336AC\n"
    ".type _FUN_060336AC, @function\n"
    "_FUN_060336AC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xBF4F\n"  /* bsr 0x06033550 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x386C\n"  /* add r6,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0224\n"  /* mov.b r2,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0268\n"  /* .word 0x0268 */
    ".global _FUN_060336c8\n"
    "_FUN_060336c8:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD071\n"  /* mov.l @(0x1C4,PC),r0  {[0x06033890] = 0x06085FF4} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8B0C\n"  /* bf 0x060336EC */
    ".word 0xD06D\n"  /* mov.l @(0x1B4,PC),r0  {[0x06033888] = 0x06063D98} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0xC810\n"  /* tst #0x10,r0 */
    ".word 0x8908\n"  /* bt 0x060336EC */
    ".word 0xD06C\n"  /* mov.l @(0x1B0,PC),r0  {[0x0603388C] = 0x0605D240} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x8904\n"  /* bt 0x060336EC */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B02\n"  /* bf 0x060336EC */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_060336f2\n"
    "_FUN_060336f2:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0xD062\n"  /* mov.l @(0x188,PC),r0  {[0x06033880] = 0x06078635} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x4015\n"  /* cmp/pl r0 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_06033700\n"
    "_FUN_06033700:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x6E66\n"  /* mov.l @r6+,r14 */
    ".word 0x6D66\n"  /* mov.l @r6+,r13 */
    ".word 0x6C66\n"  /* mov.l @r6+,r12 */
    ".word 0x6B65\n"  /* mov.w @r6+,r11 */
    ".word 0x6A65\n"  /* mov.w @r6+,r10 */
    ".word 0xD159\n"  /* mov.l @(0x164,PC),r1  {[0x06033874] = 0x0607EAD8} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0xD030\n"  /* mov.l @(0xC0,PC),r0  {[0x060337D8] = 0x06033894} */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x7008\n"  /* add #8,r0 */
    ".word 0x6806\n"  /* mov.l @r0+,r8 */
    ".word 0x6502\n"  /* mov.l @r0,r5 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xD12D\n"  /* mov.l @(0xB4,PC),r1  {[0x060337DC] = 0x0602755C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033726, \"ax\"\n"

    ".global _FUN_06033726\n"
    ".type _FUN_06033726, @function\n"
    "_FUN_06033726:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6109\n"  /* swap.w r0,r1 */
    ".word 0x6D1F\n"  /* exts.w r1,r13 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x6583\n"  /* mov r8,r5 */
    ".word 0xD129\n"  /* mov.l @(0xA4,PC),r1  {[0x060337DC] = 0x0602755C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033738, \"ax\"\n"

    ".global _FUN_06033738\n"
    ".type _FUN_06033738, @function\n"
    "_FUN_06033738:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x410B\n"  /* jsr @r1 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6109\n"  /* swap.w r0,r1 */
    ".word 0x6E1F\n"  /* exts.w r1,r14 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x060337E0] = 0xFFFFC800} */
    ".word 0xD34E\n"  /* mov.l @(0x138,PC),r3  {[0x06033884] = 0x06078663} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B02\n"  /* bf 0x06033756 */
    ".word 0x6CCB\n"  /* neg r12,r12 */
    ".word 0x6EEB\n"  /* neg r14,r14 */
    ".word 0xD423\n"  /* mov.l @(0x8C,PC),r4  {[0x060337E4] = 0x00004800} */
    ".word 0xD020\n"  /* mov.l @(0x80,PC),r0  {[0x060337D8] = 0x06033894} */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6105\n"  /* mov.w @r0+,r1 */
    ".word 0x6205\n"  /* mov.w @r0+,r2 */
    ".word 0x31E8\n"  /* sub r14,r1 */
    ".word 0x32D8\n"  /* sub r13,r2 */
    ".word 0x6E13\n"  /* mov r1,r14 */
    ".word 0x6D23\n"  /* mov r2,r13 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B03\n"  /* bf 0x06033772 */
    ".word 0x6105\n"  /* mov.w @r0+,r1 */
    ".word 0x6201\n"  /* mov.w @r0,r2 */
    ".word 0x3E1C\n"  /* add r1,r14 */
    ".word 0x3D2C\n"  /* add r2,r13 */
    ".word 0x3C4C\n"  /* add r4,r12 */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x060337E8] = 0x0000FFFF} */
    ".word 0x2C09\n"  /* and r0,r12 */
    ".word 0x4C19\n"  /* shlr8 r12 */
    ".word 0x4C09\n"  /* shlr2 r12 */
    ".word 0x4C09\n"  /* shlr2 r12 */
    ".word 0x4C00\n"  /* shll r12 */
    ".word 0xD11A\n"  /* mov.l @(0x68,PC),r1  {[0x060337EC] = 0x06033A8C} */
    ".word 0x31CC\n"  /* add r12,r1 */
    ".word 0x6214\n"  /* mov.b @r1+,r2 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x6010\n"  /* mov.b @r1,r0 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x67E3\n"  /* mov r14,r7 */
    ".word 0x68D3\n"  /* mov r13,r8 */
    ".word 0x69E3\n"  /* mov r14,r9 */
    ".word 0x6AD3\n"  /* mov r13,r10 */
    ".word 0x6BE3\n"  /* mov r14,r11 */
    ".word 0x6CD3\n"  /* mov r13,r12 */
    ".word 0x374C\n"  /* add r4,r7 */
    ".word 0x394C\n"  /* add r4,r9 */
    ".word 0x3A4C\n"  /* add r4,r10 */
    ".word 0x3C4C\n"  /* add r4,r12 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x354C\n"  /* add r4,r5 */
    ".word 0x3B4C\n"  /* add r4,r11 */
    ".word 0x364C\n"  /* add r4,r6 */
    ".word 0x384C\n"  /* add r4,r8 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060337AE, \"ax\"\n"

    ".global _FUN_060337AE\n"
    ".type _FUN_060337AE, @function\n"
    "_FUN_060337AE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xBEB6\n"  /* bsr 0x06033520 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD40E\n"  /* mov.l @(0x38,PC),r4  {[0x060337F0] = 0x06062970} */
    ".word 0xD50E\n"  /* mov.l @(0x38,PC),r5  {[0x060337F4] = 0x060785FC} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x060337F8] = 0x060280F8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060337BE, \"ax\"\n"

    ".global _FUN_060337BE\n"
    ".type _FUN_060337BE, @function\n"
    "_FUN_060337BE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060337C6, \"ax\"\n"

    ".global _FUN_060337C6\n"
    ".type _FUN_060337C6, @function\n"
    "_FUN_060337C6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xBE9C\n"  /* bsr 0x06033504 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3894\n"  /* .word 0x3894 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xC800\n"  /* tst #0x00,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4800\n"  /* shll r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3A8C\n"  /* add r8,r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x2970\n"  /* mov.b r7,@r9 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x85FC\n"  /* mov.w @(0x18,r15),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x80F8\n"  /* mov.b r0,@(0x8,r15) */
    ".global _FUN_060337fc\n"
    "_FUN_060337fc:\n"
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xD102\n"  /* mov.l @(0x8,PC),r1  {[0x06033808] = 0x0603380C} */
    ".word 0x301C\n"  /* add r1,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x381C\n"  /* add r1,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x382E\n"  /* .word 0x382E */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3840\n"  /* cmp/eq r4,r8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3852\n"  /* cmp/hs r5,r8 */
    ".word 0x24C1\n"  /* mov.w r12,@r4 */
    ".word 0x24B5\n"  /* mov.w r11,@-r4 */
    ".word 0x24A5\n"  /* mov.w r10,@-r4 */
    ".word 0x2495\n"  /* mov.w r9,@-r4 */
    ".word 0x2485\n"  /* mov.w r8,@-r4 */
    ".word 0x2475\n"  /* mov.w r7,@-r4 */
    ".word 0x2465\n"  /* mov.w r6,@-r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2455\n"  /* mov.w r5,@-r4 */
    ".word 0x24A1\n"  /* mov.w r10,@r4 */
    ".word 0x2495\n"  /* mov.w r9,@-r4 */
    ".word 0x2485\n"  /* mov.w r8,@-r4 */
    ".word 0x2475\n"  /* mov.w r7,@-r4 */
    ".word 0x2465\n"  /* mov.w r6,@-r4 */
    ".word 0x2455\n"  /* mov.w r5,@-r4 */
    ".word 0x24C5\n"  /* mov.w r12,@-r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x24B5\n"  /* mov.w r11,@-r4 */
    ".word 0x2481\n"  /* mov.w r8,@r4 */
    ".word 0x2475\n"  /* mov.w r7,@-r4 */
    ".word 0x2465\n"  /* mov.w r6,@-r4 */
    ".word 0x2455\n"  /* mov.w r5,@-r4 */
    ".word 0x24C5\n"  /* mov.w r12,@-r4 */
    ".word 0x24B5\n"  /* mov.w r11,@-r4 */
    ".word 0x24A5\n"  /* mov.w r10,@-r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2495\n"  /* mov.w r9,@-r4 */
    ".word 0x2461\n"  /* mov.w r6,@r4 */
    ".word 0x2455\n"  /* mov.w r5,@-r4 */
    ".word 0x24C5\n"  /* mov.w r12,@-r4 */
    ".word 0x24B5\n"  /* mov.w r11,@-r4 */
    ".word 0x24A5\n"  /* mov.w r10,@-r4 */
    ".word 0x2495\n"  /* mov.w r9,@-r4 */
    ".word 0x2485\n"  /* mov.w r8,@-r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2475\n"  /* mov.w r7,@-r4 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAB8\n"  /* mov #-72,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEA98\n"  /* mov #-104,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8900\n"  /* bt 0x06033876 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB734\n"  /* bsr 0x060346EA */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8635\n"  /* .word 0x8635 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8663\n"  /* .word 0x8663 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xD240\n"  /* mov.l @(0x100,PC),r2  {[0x06033990] = 0x00072770} */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0084\n"  /* mov.b r8,@(r0,r0) */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0084\n"  /* mov.b r8,@(r0,r0) */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0015\n"  /* mov.w r1,@(r0,r0) */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0013\n"  /* .word 0x0013 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0074\n"  /* mov.b r7,@(r0,r0) */
    ".word 0x0012\n"  /* stc gbr,r0 */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0xFFEA\n"  /* .word 0xFFEA */
    ".word 0x0048\n"  /* clrs */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0xFFEC\n"  /* .word 0xFFEC */
    ".word 0x0048\n"  /* clrs */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0048\n"  /* clrs */
    ".word 0xFFF0\n"  /* .word 0xFFF0 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x4444\n"  /* .word 0x4444 */
    ".word 0x4444\n"  /* .word 0x4444 */
    ".word 0x6556\n"  /* mov.l @r5+,r5 */
    ".word 0x6556\n"  /* mov.l @r5+,r5 */
    ".word 0x6556\n"  /* mov.l @r5+,r5 */
    ".word 0x4444\n"  /* .word 0x4444 */
    ".word 0x5555\n"  /* mov.l @(0x14,r5),r5 */
    ".word 0x5555\n"  /* mov.l @(0x14,r5),r5 */
    ".word 0x6226\n"  /* mov.l @r2+,r2 */
    ".word 0x6226\n"  /* mov.l @r2+,r2 */
    ".word 0x6226\n"  /* mov.l @r2+,r2 */
    ".word 0x5555\n"  /* mov.l @(0x14,r5),r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0x0220\n"  /* .word 0x0220 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x05A0\n"  /* .word 0x05A0 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x06A0\n"  /* .word 0x06A0 */
    ".word 0x0060\n"  /* .word 0x0060 */
    ".word 0x07A0\n"  /* .word 0x07A0 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0022\n"  /* stc vbr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0700\n"  /* .word 0x0700 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7770\n"  /* add #112,r7 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x2700\n"  /* mov.b r0,@r7 */
    ".word 0x0027\n"  /* mul.l r2,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0772\n"  /* .word 0x0772 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0070\n"  /* .word 0x0070 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0770\n"  /* .word 0x0770 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x2770\n"  /* mov.b r7,@r7 */
    ".word 0x0727\n"  /* mul.l r2,r7 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0720\n"  /* .word 0x0720 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0727\n"  /* mul.l r2,r7 */
    ".word 0x2770\n"  /* mov.b r7,@r7 */
    ".word 0x0727\n"  /* mul.l r2,r7 */
    ".word 0x2770\n"  /* mov.b r7,@r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0720\n"  /* .word 0x0720 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0727\n"  /* mul.l r2,r7 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x2770\n"  /* mov.b r7,@r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0770\n"  /* .word 0x0770 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0070\n"  /* .word 0x0070 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0772\n"  /* .word 0x0772 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0027\n"  /* mul.l r2,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x2700\n"  /* mov.b r0,@r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7770\n"  /* add #112,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0700\n"  /* .word 0x0700 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0022\n"  /* stc vbr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2200\n"  /* mov.b r0,@r2 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0700\n"  /* .word 0x0700 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2770\n"  /* mov.b r7,@r7 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7200\n"  /* add #0,r2 */
    ".word 0x0072\n"  /* .word 0x0072 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0777\n"  /* mul.l r7,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0070\n"  /* .word 0x0070 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0270\n"  /* .word 0x0270 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x7270\n"  /* add #112,r2 */
    ".word 0x0772\n"  /* .word 0x0772 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0770\n"  /* .word 0x0770 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0772\n"  /* .word 0x0772 */
    ".word 0x7270\n"  /* add #112,r2 */
    ".word 0x0772\n"  /* .word 0x0772 */
    ".word 0x7270\n"  /* add #112,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0770\n"  /* .word 0x0770 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0772\n"  /* .word 0x0772 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x7270\n"  /* add #112,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0270\n"  /* .word 0x0270 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0070\n"  /* .word 0x0070 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0777\n"  /* mul.l r7,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0072\n"  /* .word 0x0072 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7200\n"  /* add #0,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2770\n"  /* mov.b r7,@r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0700\n"  /* .word 0x0700 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0077\n"  /* mul.l r7,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x7000\n"  /* add #0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2200\n"  /* mov.b r0,@r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7700\n"  /* add #0,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0300\n"  /* .word 0x0300 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x0103\n"  /* .word 0x0103 */
    ".word 0x0203\n"  /* .word 0x0203 */
    ".word 0x0303\n"  /* .word 0x0303 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0102\n"  /* stc sr,r1 */
    ".word 0x0202\n"  /* stc sr,r2 */
    ".word 0x0302\n"  /* stc sr,r3 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0101\n"  /* .word 0x0101 */
    ".word 0x0201\n"  /* .word 0x0201 */
    ".word 0x0301\n"  /* .word 0x0301 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C08, \"ax\"\n"

    ".global _FUN_06033C08\n"
    ".type _FUN_06033C08, @function\n"
    "_FUN_06033C08:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06033C2C] = 0x06033F54} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C14, \"ax\"\n"

    ".global _FUN_06033C14\n"
    ".type _FUN_06033C14, @function\n"
    "_FUN_06033C14:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x06033C2C] = 0x06033F54} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C20, \"ax\"\n"

    ".global _FUN_06033C20\n"
    ".type _FUN_06033C20, @function\n"
    "_FUN_06033C20:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA007\n"  /* bra 0x06033C3A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3F54\n"  /* .word 0x3F54 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06033C54] = 0x0603446C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C32, \"ax\"\n"

    ".global _FUN_06033C32\n"
    ".type _FUN_06033C32, @function\n"
    "_FUN_06033C32:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06033C58] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x06033C5C] = 0x000001EC} */
    ".word 0x011E\n"  /* mov.l @(r0,r1),r1 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06033C60] = 0x000000ED} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8B0F\n"  /* bf 0x06033C68 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06033C64] = 0x00000104} */
    ".word 0x3107\n"  /* cmp/gt r0,r1 */
    ".word 0x890C\n"  /* bt 0x06033C68 */
    ".word 0xA00C\n"  /* bra 0x06033C6A */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x446C\n"  /* .word 0x446C */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00ED\n"  /* mov.w @(r0,r14),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0104\n"  /* mov.b r0,@(r0,r1) */
    ".word 0x0008\n"  /* clrt */
    ".word 0x8B63\n"  /* bf 0x06033D34 */
    ".word 0xE405\n"  /* mov #5,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C6E, \"ax\"\n"

    ".global _FUN_06033C6E\n"
    ".type _FUN_06033C6E, @function\n"
    "_FUN_06033C6E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB170\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE406\n"  /* mov #6,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C78, \"ax\"\n"

    ".global _FUN_06033C78\n"
    ".type _FUN_06033C78, @function\n"
    "_FUN_06033C78:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB16B\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE407\n"  /* mov #7,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C82, \"ax\"\n"

    ".global _FUN_06033C82\n"
    ".type _FUN_06033C82, @function\n"
    "_FUN_06033C82:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB166\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE408\n"  /* mov #8,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C8C, \"ax\"\n"

    ".global _FUN_06033C8C\n"
    ".type _FUN_06033C8C, @function\n"
    "_FUN_06033C8C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB161\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE409\n"  /* mov #9,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033C96, \"ax\"\n"

    ".global _FUN_06033C96\n"
    ".type _FUN_06033C96, @function\n"
    "_FUN_06033C96:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB15C\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE40A\n"  /* mov #10,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CA0, \"ax\"\n"

    ".global _FUN_06033CA0\n"
    ".type _FUN_06033CA0, @function\n"
    "_FUN_06033CA0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB157\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE40B\n"  /* mov #11,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CAA, \"ax\"\n"

    ".global _FUN_06033CAA\n"
    ".type _FUN_06033CAA, @function\n"
    "_FUN_06033CAA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB152\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE40C\n"  /* mov #12,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CB4, \"ax\"\n"

    ".global _FUN_06033CB4\n"
    ".type _FUN_06033CB4, @function\n"
    "_FUN_06033CB4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB14D\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE40D\n"  /* mov #13,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CBE, \"ax\"\n"

    ".global _FUN_06033CBE\n"
    ".type _FUN_06033CBE, @function\n"
    "_FUN_06033CBE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB148\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE40E\n"  /* mov #14,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CC8, \"ax\"\n"

    ".global _FUN_06033CC8\n"
    ".type _FUN_06033CC8, @function\n"
    "_FUN_06033CC8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB143\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE40F\n"  /* mov #15,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CD2, \"ax\"\n"

    ".global _FUN_06033CD2\n"
    ".type _FUN_06033CD2, @function\n"
    "_FUN_06033CD2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB13E\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE410\n"  /* mov #16,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CDC, \"ax\"\n"

    ".global _FUN_06033CDC\n"
    ".type _FUN_06033CDC, @function\n"
    "_FUN_06033CDC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB139\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE411\n"  /* mov #17,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CE6, \"ax\"\n"

    ".global _FUN_06033CE6\n"
    ".type _FUN_06033CE6, @function\n"
    "_FUN_06033CE6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB134\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE412\n"  /* mov #18,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CF0, \"ax\"\n"

    ".global _FUN_06033CF0\n"
    ".type _FUN_06033CF0, @function\n"
    "_FUN_06033CF0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB12F\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE413\n"  /* mov #19,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033CFA, \"ax\"\n"

    ".global _FUN_06033CFA\n"
    ".type _FUN_06033CFA, @function\n"
    "_FUN_06033CFA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB12A\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE414\n"  /* mov #20,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D04, \"ax\"\n"

    ".global _FUN_06033D04\n"
    ".type _FUN_06033D04, @function\n"
    "_FUN_06033D04:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB125\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE415\n"  /* mov #21,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D0E, \"ax\"\n"

    ".global _FUN_06033D0E\n"
    ".type _FUN_06033D0E, @function\n"
    "_FUN_06033D0E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB120\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE416\n"  /* mov #22,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D18, \"ax\"\n"

    ".global _FUN_06033D18\n"
    ".type _FUN_06033D18, @function\n"
    "_FUN_06033D18:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB11B\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE417\n"  /* mov #23,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D22, \"ax\"\n"

    ".global _FUN_06033D22\n"
    ".type _FUN_06033D22, @function\n"
    "_FUN_06033D22:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB116\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE418\n"  /* mov #24,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D2C, \"ax\"\n"

    ".global _FUN_06033D2C\n"
    ".type _FUN_06033D2C, @function\n"
    "_FUN_06033D2C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB111\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06033D4C] = 0x0607E944} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x06033D50] = 0x000001EC} */
    ".word 0x011E\n"  /* mov.l @(r0,r1),r1 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06033D54] = 0x000001B8} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8B0C\n"  /* bf 0x06033D5C */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06033D58] = 0x000001E0} */
    ".word 0x3107\n"  /* cmp/gt r0,r1 */
    ".word 0x8909\n"  /* bt 0x06033D5C */
    ".word 0xA009\n"  /* bra 0x06033D5E */
    ".word 0x0018\n"  /* sett */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01B8\n"  /* .word 0x01B8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01E0\n"  /* .word 0x01E0 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x8901\n"  /* bt 0x06033D64 */
    ".word 0xA094\n"  /* bra 0x06033E8C */
    ".word 0x0009\n"  /* nop */
    ".word 0xD002\n"  /* mov.l @(0x8,PC),r0  {[0x06033D70] = 0x0607EAE0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B03\n"  /* bf 0x06033D74 */
    ".word 0xA091\n"  /* bra 0x06033E92 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0xD43B\n"  /* mov.l @(0xEC,PC),r4  {[0x06033E64] = 0x00000019} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D76, \"ax\"\n"

    ".global _FUN_06033D76\n"
    ".type _FUN_06033D76, @function\n"
    "_FUN_06033D76:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0EC\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD03A\n"  /* mov.l @(0xE8,PC),r0  {[0x06033E68] = 0x06083250} */
    ".word 0x6D02\n"  /* mov.l @r0,r13 */
    ".word 0xD03A\n"  /* mov.l @(0xE8,PC),r0  {[0x06033E6C] = 0x0000013B} */
    ".word 0x3D03\n"  /* cmp/ge r0,r13 */
    ".word 0x8B64\n"  /* bf 0x06033E52 */
    ".word 0xD439\n"  /* mov.l @(0xE4,PC),r4  {[0x06033E70] = 0x0000001A} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D8A, \"ax\"\n"

    ".global _FUN_06033D8A\n"
    ".type _FUN_06033D8A, @function\n"
    "_FUN_06033D8A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0E2\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD438\n"  /* mov.l @(0xE0,PC),r4  {[0x06033E74] = 0x0000001B} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D94, \"ax\"\n"

    ".global _FUN_06033D94\n"
    ".type _FUN_06033D94, @function\n"
    "_FUN_06033D94:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0DD\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD436\n"  /* mov.l @(0xD8,PC),r4  {[0x06033E78] = 0x0000001C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033D9E, \"ax\"\n"

    ".global _FUN_06033D9E\n"
    ".type _FUN_06033D9E, @function\n"
    "_FUN_06033D9E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0D8\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD435\n"  /* mov.l @(0xD4,PC),r4  {[0x06033E7C] = 0x0000001D} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033DA8, \"ax\"\n"

    ".global _FUN_06033DA8\n"
    ".type _FUN_06033DA8, @function\n"
    "_FUN_06033DA8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0D3\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD033\n"  /* mov.l @(0xCC,PC),r0  {[0x06033E80] = 0x00000276} */
    ".word 0x3D03\n"  /* cmp/ge r0,r13 */
    ".word 0x8B4D\n"  /* bf 0x06033E52 */
    ".word 0xE41E\n"  /* mov #30,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033DB8, \"ax\"\n"

    ".global _FUN_06033DB8\n"
    ".type _FUN_06033DB8, @function\n"
    "_FUN_06033DB8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0CB\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE41F\n"  /* mov #31,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033DC2, \"ax\"\n"

    ".global _FUN_06033DC2\n"
    ".type _FUN_06033DC2, @function\n"
    "_FUN_06033DC2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0C6\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE420\n"  /* mov #32,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033DCC, \"ax\"\n"

    ".global _FUN_06033DCC\n"
    ".type _FUN_06033DCC, @function\n"
    "_FUN_06033DCC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0C1\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE421\n"  /* mov #33,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033DD6, \"ax\"\n"

    ".global _FUN_06033DD6\n"
    ".type _FUN_06033DD6, @function\n"
    "_FUN_06033DD6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0BC\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE422\n"  /* mov #34,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033DE0, \"ax\"\n"

    ".global _FUN_06033DE0\n"
    ".type _FUN_06033DE0, @function\n"
    "_FUN_06033DE0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0B7\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x06033E84] = 0x000003B1} */
    ".word 0x3D03\n"  /* cmp/ge r0,r13 */
    ".word 0x8B31\n"  /* bf 0x06033E52 */
    ".word 0xE423\n"  /* mov #35,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033DF0, \"ax\"\n"

    ".global _FUN_06033DF0\n"
    ".type _FUN_06033DF0, @function\n"
    "_FUN_06033DF0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0AF\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE424\n"  /* mov #36,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033DFA, \"ax\"\n"

    ".global _FUN_06033DFA\n"
    ".type _FUN_06033DFA, @function\n"
    "_FUN_06033DFA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0AA\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE425\n"  /* mov #37,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033E04, \"ax\"\n"

    ".global _FUN_06033E04\n"
    ".type _FUN_06033E04, @function\n"
    "_FUN_06033E04:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0A5\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE426\n"  /* mov #38,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033E0E, \"ax\"\n"

    ".global _FUN_06033E0E\n"
    ".type _FUN_06033E0E, @function\n"
    "_FUN_06033E0E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0A0\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE427\n"  /* mov #39,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033E18, \"ax\"\n"

    ".global _FUN_06033E18\n"
    ".type _FUN_06033E18, @function\n"
    "_FUN_06033E18:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB09B\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE428\n"  /* mov #40,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033E22, \"ax\"\n"

    ".global _FUN_06033E22\n"
    ".type _FUN_06033E22, @function\n"
    "_FUN_06033E22:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB096\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE429\n"  /* mov #41,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033E2C, \"ax\"\n"

    ".global _FUN_06033E2C\n"
    ".type _FUN_06033E2C, @function\n"
    "_FUN_06033E2C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB091\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE42A\n"  /* mov #42,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033E36, \"ax\"\n"

    ".global _FUN_06033E36\n"
    ".type _FUN_06033E36, @function\n"
    "_FUN_06033E36:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB08C\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE42B\n"  /* mov #43,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033E40, \"ax\"\n"

    ".global _FUN_06033E40\n"
    ".type _FUN_06033E40, @function\n"
    "_FUN_06033E40:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB087\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xE42C\n"  /* mov #44,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033E4A, \"ax\"\n"

    ".global _FUN_06033E4A\n"
    ".type _FUN_06033E4A, @function\n"
    "_FUN_06033E4A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB082\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x06033E68] = 0x06083250} */
    ".word 0x6012\n"  /* mov.l @r1,r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x06033E88] = 0x00000EC4} */
    ".word 0x3023\n"  /* cmp/ge r2,r0 */
    ".word 0x8B00\n"  /* bf 0x06033E60 */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x06033E88] = 0x00000EC4} */
    ".word 0xA017\n"  /* bra 0x06033E92 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0019\n"  /* div0u */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3250\n"  /* cmp/eq r5,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x013B\n"  /* .word 0x013B */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001B\n"  /* sleep */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001D\n"  /* mov.w @(r0,r1),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0276\n"  /* mov.l r7,@(r0,r2) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x03B1\n"  /* .word 0x03B1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0EC4\n"  /* mov.b r12,@(r0,r14) */
    ".word 0x200A\n"  /* xor r0,r0 */
    ".word 0xD105\n"  /* mov.l @(0x14,PC),r1  {[0x06033EA4] = 0x06083250} */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3250\n"  /* cmp/eq r5,r2 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033ED2, \"ax\"\n"

    ".global _FUN_06033ED2\n"
    ".type _FUN_06033ED2, @function\n"
    "_FUN_06033ED2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD419\n"  /* mov.l @(0x64,PC),r4  {[0x06033F40] = 0x00000001} */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x06033F3C] = 0x06033F54} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033EDE, \"ax\"\n"

    ".global _FUN_06033EDE\n"
    ".type _FUN_06033EDE, @function\n"
    "_FUN_06033EDE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x06033F44] = 0x00000002} */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06033F3C] = 0x06033F54} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033EEA, \"ax\"\n"

    ".global _FUN_06033EEA\n"
    ".type _FUN_06033EEA, @function\n"
    "_FUN_06033EEA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x06033F48] = 0x00000004} */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x06033F3C] = 0x06033F54} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033EF6, \"ax\"\n"

    ".global _FUN_06033EF6\n"
    ".type _FUN_06033EF6, @function\n"
    "_FUN_06033EF6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06033F34] = 0x06083254} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B0A\n"  /* bf 0x06033F1C */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x06033F4C] = 0x00000006} */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB022\n"  /* bsr 0x06033F54 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06033F50] = 0x00000019} */
    ".word 0x3403\n"  /* cmp/ge r0,r4 */
    ".word 0x8BF5\n"  /* bf 0x06033F08 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E08\n"  /* sub r0,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3254\n"  /* .word 0x3254 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x3F54\n"  /* .word 0x3F54 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0019\n"  /* div0u */
    ".global _FUN_06033f54\n"
    "_FUN_06033f54:\n"
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0xD111\n"  /* mov.l @(0x44,PC),r1  {[0x06033F9C] = 0x0000002C} */
    ".word 0x214E\n"  /* mulu.w r4,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0xDE10\n"  /* mov.l @(0x40,PC),r14  {[0x06033FA0] = 0x06082A7C} */
    ".word 0x3E0C\n"  /* add r0,r14 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06033FA4] = 0x0607E944} */
    ".word 0x6A02\n"  /* mov.l @r0,r10 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06033FA8] = 0x00000001} */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8909\n"  /* bt 0x06033F80 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8907\n"  /* bt 0x06033F80 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06033FAC] = 0x00000026} */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x891B\n"  /* bt 0x06033FB0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x892B\n"  /* bt 0x06033FD4 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x892D\n"  /* bt 0x06033FDC */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033F80, \"ax\"\n"

    ".global _FUN_06033F80\n"
    ".type _FUN_06033F80, @function\n"
    "_FUN_06033F80:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB03D\n"  /* bsr 0x06034000 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033F88, \"ax\"\n"

    ".global _FUN_06033F88\n"
    ".type _FUN_06033F88, @function\n"
    "_FUN_06033F88:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0ED\n"  /* bsr 0x06034168 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033F90, \"ax\"\n"

    ".global _FUN_06033F90\n"
    ".type _FUN_06033F90, @function\n"
    "_FUN_06033F90:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB395\n"  /* bsr 0x060346C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA030\n"  /* bra 0x06033FFC */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x002C\n"  /* mov.b @(r0,r2),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A7C\n"  /* .word 0x2A7C */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0026\n"  /* mov.l r2,@(r0,r0) */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FB0, \"ax\"\n"

    ".global _FUN_06033FB0\n"
    ".type _FUN_06033FB0, @function\n"
    "_FUN_06033FB0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB273\n"  /* bsr 0x0603449C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FB8, \"ax\"\n"

    ".global _FUN_06033FB8\n"
    ".type _FUN_06033FB8, @function\n"
    "_FUN_06033FB8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB021\n"  /* bsr 0x06034000 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FC0, \"ax\"\n"

    ".global _FUN_06033FC0\n"
    ".type _FUN_06033FC0, @function\n"
    "_FUN_06033FC0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB0D1\n"  /* bsr 0x06034168 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FC8, \"ax\"\n"

    ".global _FUN_06033FC8\n"
    ".type _FUN_06033FC8, @function\n"
    "_FUN_06033FC8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB379\n"  /* bsr 0x060346C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA014\n"  /* bra 0x06033FFC */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FD4, \"ax\"\n"

    ".global _FUN_06033FD4\n"
    ".type _FUN_06033FD4, @function\n"
    "_FUN_06033FD4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB2C3\n"  /* bsr 0x06034560 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FDC, \"ax\"\n"

    ".global _FUN_06033FDC\n"
    ".type _FUN_06033FDC, @function\n"
    "_FUN_06033FDC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB25D\n"  /* bsr 0x0603449C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FE4, \"ax\"\n"

    ".global _FUN_06033FE4\n"
    ".type _FUN_06033FE4, @function\n"
    "_FUN_06033FE4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB2D1\n"  /* bsr 0x0603458C */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FEC, \"ax\"\n"

    ".global _FUN_06033FEC\n"
    ".type _FUN_06033FEC, @function\n"
    "_FUN_06033FEC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB327\n"  /* bsr 0x06034640 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06033FF4, \"ax\"\n"

    ".global _FUN_06033FF4\n"
    ".type _FUN_06033FF4, @function\n"
    "_FUN_06033FF4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB363\n"  /* bsr 0x060346C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".global _FUN_06034000\n"
    "_FUN_06034000:\n"
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06034018] = 0x00000001} */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8B0D\n"  /* bf 0x06034024 */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x0603401C] = 0x00000012} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0x611F\n"  /* exts.w r1,r1 */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06034020] = 0x0000001C} */
    ".word 0x02EE\n"  /* mov.l @(r0,r14),r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0E26\n"  /* mov.l r2,@(r0,r14) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0012\n"  /* stc gbr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x06034088] = 0x00000012} */
    ".word 0x02ED\n"  /* mov.w @(r0,r14),r2 */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x0603408C] = 0x00000002} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0x6D13\n"  /* mov r1,r13 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x06034090] = 0x06027344} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034036, \"ax\"\n"

    ".global _FUN_06034036\n"
    ".type _FUN_06034036, @function\n"
    "_FUN_06034036:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6C03\n"  /* mov r0,r12 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06034094] = 0x00000020} */
    ".word 0x0BEE\n"  /* mov.l @(r0,r14),r11 */
    ".word 0x3BCD\n"  /* dmuls.l r12,r11 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06034098] = 0x00000014} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0603409C] = 0x00000004} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060340A0] = 0x06027348} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603405A, \"ax\"\n"

    ".global _FUN_0603405A\n"
    ".type _FUN_0603405A, @function\n"
    "_FUN_0603405A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x3B0D\n"  /* dmuls.l r0,r11 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x060340A4] = 0x0000001C} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x060340A8] = 0x0000000C} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x060340AC] = 0x00000001} */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8947\n"  /* bt 0x0603410C */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x060340B0] = 0x00000024} */
    ".word 0x01ED\n"  /* mov.w @(r0,r14),r1 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x8B17\n"  /* bf 0x060340B4 */
    ".word 0xA032\n"  /* bra 0x060340EC */
    ".word 0x222A\n"  /* xor r2,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0012\n"  /* stc gbr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0014\n"  /* mov.b r1,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x31CD\n"  /* dmuls.l r12,r1 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x0A1A\n"  /* sts macl,r10 */
    ".word 0x2A0D\n"  /* .word 0x2A0D */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x060340F8] = 0x06027348} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060340C0, \"ax\"\n"

    ".global _FUN_060340C0\n"
    ".type _FUN_060340C0, @function\n"
    "_FUN_060340C0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x060340FC] = 0x06027344} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060340CE, \"ax\"\n"

    ".global _FUN_060340CE\n"
    ".type _FUN_060340CE, @function\n"
    "_FUN_060340CE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x06034100] = 0x0602755C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060340DC, \"ax\"\n"

    ".global _FUN_060340DC\n"
    ".type _FUN_060340DC, @function\n"
    "_FUN_060340DC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x3B0D\n"  /* dmuls.l r0,r11 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x220D\n"  /* .word 0x220D */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06034104] = 0x00000018} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06034108] = 0x00000008} */
    ".word 0xA023\n"  /* bra 0x0603413E */
    ".word 0x0E26\n"  /* mov.l r2,@(r0,r14) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06034144] = 0x00000004} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06034148] = 0x06083238} */
    ".word 0x2042\n"  /* mov.l r4,@r0 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0603414C] = 0x0000000C} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06034150] = 0x06083240} */
    ".word 0x2052\n"  /* mov.l r5,@r0 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06034154] = 0x06006838} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603411E, \"ax\"\n"

    ".global _FUN_0603411E\n"
    ".type _FUN_0603411E, @function\n"
    "_FUN_0603411E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xD507\n"  /* mov.l @(0x1C,PC),r5  {[0x06034148] = 0x06083238} */
    ".word 0xD60B\n"  /* mov.l @(0x2C,PC),r6  {[0x06034158] = 0x06083244} */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x0603415C] = 0x06027EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603412E, \"ax\"\n"

    ".global _FUN_0603412E\n"
    ".type _FUN_0603412E, @function\n"
    "_FUN_0603412E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x06034160] = 0x0608323C} */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x06034164] = 0x00000008} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3240\n"  /* cmp/eq r4,r2 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x6838\n"  /* swap.b r3,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3244\n"  /* .word 0x3244 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06027EDE */
    ".word 0x7EDE\n"  /* add #-34,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".global _FUN_06034168\n"
    "_FUN_06034168:\n"
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x060341C4] = 0x00000001} */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B41\n"  /* bf 0x060341F4 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x060341C8] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034172, \"ax\"\n"

    ".global _FUN_06034172\n"
    ".type _FUN_06034172, @function\n"
    "_FUN_06034172:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD14\n"  /* mov.l @(0x50,PC),r13  {[0x060341CC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x060341D0] = 0x00000004} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x060341D4] = 0x00000008} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x060341D8] = 0x0000000C} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x060341DC] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603418C, \"ax\"\n"

    ".global _FUN_0603418C\n"
    ".type _FUN_0603418C, @function\n"
    "_FUN_0603418C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x060341E0] = 0x00000002} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x060341E4] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603419A, \"ax\"\n"

    ".global _FUN_0603419A\n"
    ".type _FUN_0603419A, @function\n"
    "_FUN_0603419A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060341E8] = 0x00000011} */
    ".word 0x04EC\n"  /* mov.b @(r0,r14),r4 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060341EC] = 0x0600A5B2} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060341A8, \"ax\"\n"

    ".global _FUN_060341A8\n"
    ".type _FUN_060341A8, @function\n"
    "_FUN_060341A8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x060341F0] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060341B2, \"ax\"\n"

    ".global _FUN_060341B2\n"
    ".type _FUN_060341B2, @function\n"
    "_FUN_060341B2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD04\n"  /* mov.l @(0x10,PC),r13  {[0x060341CC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xA153\n"  /* bra 0x06034468 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A5B2 */
    ".word 0xA5B2\n"  /* bra 0x06034D56 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B43\n"  /* bf 0x06034280 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06034250] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060341FA, \"ax\"\n"

    ".global _FUN_060341FA\n"
    ".type _FUN_060341FA, @function\n"
    "_FUN_060341FA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD14\n"  /* mov.l @(0x50,PC),r13  {[0x06034254] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06034258] = 0x00000004} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0603425C] = 0x00000008} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06034260] = 0x0000000C} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06034264] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034214, \"ax\"\n"

    ".global _FUN_06034214\n"
    ".type _FUN_06034214, @function\n"
    "_FUN_06034214:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06034268] = 0x00000002} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0603426C] = 0x00008000} */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x644F\n"  /* exts.w r4,r4 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06034270] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034228, \"ax\"\n"

    ".global _FUN_06034228\n"
    ".type _FUN_06034228, @function\n"
    "_FUN_06034228:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06034274] = 0x00000011} */
    ".word 0x04EC\n"  /* mov.b @(r0,r14),r4 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06034278] = 0x0600A4CA} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034236, \"ax\"\n"

    ".global _FUN_06034236\n"
    ".type _FUN_06034236, @function\n"
    "_FUN_06034236:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0603427C] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034240, \"ax\"\n"

    ".global _FUN_06034240\n"
    ".type _FUN_06034240, @function\n"
    "_FUN_06034240:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD02\n"  /* mov.l @(0x8,PC),r13  {[0x06034254] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xA10C\n"  /* bra 0x06034468 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A4CA */
    ".word 0xA4CA\n"  /* bra 0x06034C12 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8B3F\n"  /* bf 0x06034304 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x060342D8] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034286, \"ax\"\n"

    ".global _FUN_06034286\n"
    ".type _FUN_06034286, @function\n"
    "_FUN_06034286:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD13\n"  /* mov.l @(0x4C,PC),r13  {[0x060342DC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x060342E0] = 0x00000014} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x060342E4] = 0x00000018} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x060342E8] = 0x0000001C} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x060342EC] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060342A0, \"ax\"\n"

    ".global _FUN_060342A0\n"
    ".type _FUN_060342A0, @function\n"
    "_FUN_060342A0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060342F0] = 0x00000002} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060342F4] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060342AE, \"ax\"\n"

    ".global _FUN_060342AE\n"
    ".type _FUN_060342AE, @function\n"
    "_FUN_060342AE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060342F8] = 0x00000011} */
    ".word 0x04EC\n"  /* mov.b @(r0,r14),r4 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060342FC] = 0x0600A4CA} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060342BC, \"ax\"\n"

    ".global _FUN_060342BC\n"
    ".type _FUN_060342BC, @function\n"
    "_FUN_060342BC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06034300] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060342C6, \"ax\"\n"

    ".global _FUN_060342C6\n"
    ".type _FUN_060342C6, @function\n"
    "_FUN_060342C6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD03\n"  /* mov.l @(0xC,PC),r13  {[0x060342DC] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xA0C9\n"  /* bra 0x06034468 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0014\n"  /* mov.b r1,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A4CA */
    ".word 0xA4CA\n"  /* bra 0x06034C96 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8901\n"  /* bt 0x0603430C */
    ".word 0xA0AE\n"  /* bra 0x06034468 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD044\n"  /* mov.l @(0x110,PC),r0  {[0x06034420] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603430E, \"ax\"\n"

    ".global _FUN_0603430E\n"
    ".type _FUN_0603430E, @function\n"
    "_FUN_0603430E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD43\n"  /* mov.l @(0x10C,PC),r13  {[0x06034424] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD043\n"  /* mov.l @(0x10C,PC),r0  {[0x06034428] = 0x00000004} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD043\n"  /* mov.l @(0x10C,PC),r0  {[0x0603442C] = 0x00000008} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD043\n"  /* mov.l @(0x10C,PC),r0  {[0x06034430] = 0x0000000C} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD043\n"  /* mov.l @(0x10C,PC),r0  {[0x06034434] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034328, \"ax\"\n"

    ".global _FUN_06034328\n"
    ".type _FUN_06034328, @function\n"
    "_FUN_06034328:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD041\n"  /* mov.l @(0x104,PC),r0  {[0x06034438] = 0x00000002} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD041\n"  /* mov.l @(0x104,PC),r0  {[0x0603443C] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034336, \"ax\"\n"

    ".global _FUN_06034336\n"
    ".type _FUN_06034336, @function\n"
    "_FUN_06034336:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD040\n"  /* mov.l @(0x100,PC),r0  {[0x06034440] = 0x00000011} */
    ".word 0x04EC\n"  /* mov.b @(r0,r14),r4 */
    ".word 0xD040\n"  /* mov.l @(0x100,PC),r0  {[0x06034444] = 0x0600A5B2} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034344, \"ax\"\n"

    ".global _FUN_06034344\n"
    ".type _FUN_06034344, @function\n"
    "_FUN_06034344:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD03E\n"  /* mov.l @(0xF8,PC),r0  {[0x06034448] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603434E, \"ax\"\n"

    ".global _FUN_0603434E\n"
    ".type _FUN_0603434E, @function\n"
    "_FUN_0603434E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD33\n"  /* mov.l @(0xCC,PC),r13  {[0x06034424] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD03C\n"  /* mov.l @(0xF0,PC),r0  {[0x0603444C] = 0x06083250} */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0xD03C\n"  /* mov.l @(0xF0,PC),r0  {[0x06034450] = 0x000004EC} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8B5B\n"  /* bf 0x0603441C */
    ".word 0xD02E\n"  /* mov.l @(0xB8,PC),r0  {[0x06034420] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034366, \"ax\"\n"

    ".global _FUN_06034366\n"
    ".type _FUN_06034366, @function\n"
    "_FUN_06034366:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD2D\n"  /* mov.l @(0xB4,PC),r13  {[0x06034424] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD02D\n"  /* mov.l @(0xB4,PC),r0  {[0x06034428] = 0x00000004} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD037\n"  /* mov.l @(0xDC,PC),r0  {[0x06034454] = 0x00280000} */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x0603442C] = 0x00000008} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x06034430] = 0x0000000C} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD035\n"  /* mov.l @(0xD4,PC),r0  {[0x06034458] = 0x003E0000} */
    ".word 0x3608\n"  /* sub r0,r6 */
    ".word 0xD02B\n"  /* mov.l @(0xAC,PC),r0  {[0x06034434] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034388, \"ax\"\n"

    ".global _FUN_06034388\n"
    ".type _FUN_06034388, @function\n"
    "_FUN_06034388:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x06034438] = 0x00000002} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x0603443C] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034396, \"ax\"\n"

    ".global _FUN_06034396\n"
    ".type _FUN_06034396, @function\n"
    "_FUN_06034396:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD028\n"  /* mov.l @(0xA0,PC),r0  {[0x06034440] = 0x00000011} */
    ".word 0x04EC\n"  /* mov.b @(r0,r14),r4 */
    ".word 0xD028\n"  /* mov.l @(0xA0,PC),r0  {[0x06034444] = 0x0600A5B2} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060343A4, \"ax\"\n"

    ".global _FUN_060343A4\n"
    ".type _FUN_060343A4, @function\n"
    "_FUN_060343A4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x06034448] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060343AE, \"ax\"\n"

    ".global _FUN_060343AE\n"
    ".type _FUN_060343AE, @function\n"
    "_FUN_060343AE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD1B\n"  /* mov.l @(0x6C,PC),r13  {[0x06034424] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD024\n"  /* mov.l @(0x90,PC),r0  {[0x0603444C] = 0x06083250} */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0xD027\n"  /* mov.l @(0x9C,PC),r0  {[0x0603445C] = 0x00000627} */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8B2B\n"  /* bf 0x0603441C */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x06034420] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060343C6, \"ax\"\n"

    ".global _FUN_060343C6\n"
    ".type _FUN_060343C6, @function\n"
    "_FUN_060343C6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD15\n"  /* mov.l @(0x54,PC),r13  {[0x06034424] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06034428] = 0x00000004} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD022\n"  /* mov.l @(0x88,PC),r0  {[0x06034460] = 0x00190000} */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0603442C] = 0x00000008} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06034430] = 0x0000000C} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD020\n"  /* mov.l @(0x80,PC),r0  {[0x06034464] = 0x001C0000} */
    ".word 0x3608\n"  /* sub r0,r6 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06034434] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060343E8, \"ax\"\n"

    ".global _FUN_060343E8\n"
    ".type _FUN_060343E8, @function\n"
    "_FUN_060343E8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x06034438] = 0x00000002} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x0603443C] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060343F8, \"ax\"\n"

    ".global _FUN_060343F8\n"
    ".type _FUN_060343F8, @function\n"
    "_FUN_060343F8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x06034440] = 0x00000011} */
    ".word 0x04EC\n"  /* mov.b @(r0,r14),r4 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x06034444] = 0x0600A5B2} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034406, \"ax\"\n"

    ".global _FUN_06034406\n"
    ".type _FUN_06034406, @function\n"
    "_FUN_06034406:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x06034448] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034410, \"ax\"\n"

    ".global _FUN_06034410\n"
    ".type _FUN_06034410, @function\n"
    "_FUN_06034410:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD02\n"  /* mov.l @(0x8,PC),r13  {[0x06034424] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xA024\n"  /* bra 0x06034468 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A5B2 */
    ".word 0xA5B2\n"  /* bra 0x06034FAE */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3250\n"  /* cmp/eq r5,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x04EC\n"  /* mov.b @(r0,r14),r4 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0627\n"  /* mul.l r2,r6 */
    ".word 0x0019\n"  /* div0u */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_0603446c\n"
    "_FUN_0603446c:\n"
    ".word 0x277A\n"  /* xor r7,r7 */
    ".word 0xD107\n"  /* mov.l @(0x1C,PC),r1  {[0x0603448C] = 0x0000002C} */
    ".word 0x217E\n"  /* mulu.w r7,r1 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0xDE06\n"  /* mov.l @(0x18,PC),r14  {[0x06034490] = 0x06082A7C} */
    ".word 0x3E0C\n"  /* add r0,r14 */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06034494] = 0x00000026} */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06034498] = 0x00000005} */
    ".word 0x3703\n"  /* cmp/ge r0,r7 */
    ".word 0x8BF3\n"  /* bf 0x0603446E */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x002C\n"  /* mov.b @(r0,r2),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x2A7C\n"  /* .word 0x2A7C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0026\n"  /* mov.l r2,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x06034508] = 0x00000001} */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B52\n"  /* bf 0x0603454A */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x0603450C] = 0x00000004} */
    ".word 0x03EE\n"  /* mov.l @(r0,r14),r3 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06034510] = 0x0000000C} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06034514] = 0x00000010} */
    ".word 0x05AE\n"  /* mov.l @(r0,r10),r5 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06034518] = 0x00000018} */
    ".word 0x06AE\n"  /* mov.l @(r0,r10),r6 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0xDD16\n"  /* mov.l @(0x58,PC),r13  {[0x0603451C] = 0x06083238} */
    ".word 0x1D30\n"  /* mov.l r3,@(0x0,r13) */
    ".word 0x1D41\n"  /* mov.l r4,@(0x4,r13) */
    ".word 0x1D52\n"  /* mov.l r5,@(0x8,r13) */
    ".word 0x1D63\n"  /* mov.l r6,@(0xC,r13) */
    ".word 0x51D0\n"  /* mov.l @(0x0,r13),r1 */
    ".word 0x50D2\n"  /* mov.l @(0x8,r13),r0 */
    ".word 0x3018\n"  /* sub r1,r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x354D\n"  /* dmuls.l r4,r5 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x1D14\n"  /* mov.l r1,@(0x10,r13) */
    ".word 0x51D1\n"  /* mov.l @(0x4,r13),r1 */
    ".word 0x50D3\n"  /* mov.l @(0xC,r13),r0 */
    ".word 0x3018\n"  /* sub r1,r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x354D\n"  /* dmuls.l r4,r5 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x210D\n"  /* .word 0x210D */
    ".word 0x54D4\n"  /* mov.l @(0x10,r13),r4 */
    ".word 0x341C\n"  /* add r1,r4 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8915\n"  /* bt 0x06034524 */
    ".word 0x4409\n"  /* shlr2 r4 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x06034520] = 0x06027476} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060344FC, \"ax\"\n"

    ".global _FUN_060344FC\n"
    ".type _FUN_060344FC, @function\n"
    "_FUN_060344FC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA013\n"  /* bra 0x0603452E */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0018\n"  /* sett */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7476\n"  /* add #118,r4 */
    ".word 0xD00A\n"  /* mov.l @(0x28,PC),r0  {[0x06034550] = 0x06027476} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034526, \"ax\"\n"

    ".global _FUN_06034526\n"
    ".type _FUN_06034526, @function\n"
    "_FUN_06034526:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x6823\n"  /* mov r2,r8 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06034554] = 0x00080000} */
    ".word 0x3203\n"  /* cmp/ge r0,r2 */
    ".word 0x8902\n"  /* bt 0x0603454A */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x06034558] = 0x00000001} */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x0603455C] = 0x00000026} */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7476\n"  /* add #118,r4 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0026\n"  /* mov.l r2,@(r0,r0) */
    ".global _FUN_06034560\n"
    "_FUN_06034560:\n"
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0603457C] = 0x00000028} */
    ".word 0x01AE\n"  /* mov.l @(r0,r10),r1 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06034580] = 0x00000002} */
    ".word 0x0E15\n"  /* mov.w r1,@(r0,r14) */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06034584] = 0x0000000C} */
    ".word 0x04AE\n"  /* mov.l @(r0,r10),r4 */
    ".word 0x4420\n"  /* shal r4 */
    ".word 0xD003\n"  /* mov.l @(0xC,PC),r0  {[0x0603457C] = 0x00000028} */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06034588] = 0x00000026} */
    ".word 0xE102\n"  /* mov #2,r1 */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0026\n"  /* mov.l r2,@(r0,r0) */
    ".global _FUN_0603458c\n"
    "_FUN_0603458c:\n"
    ".word 0xD01E\n"  /* mov.l @(0x78,PC),r0  {[0x06034608] = 0x00000002} */
    ".word 0x09ED\n"  /* mov.w @(r0,r14),r9 */
    ".word 0xD11E\n"  /* mov.l @(0x78,PC),r1  {[0x0603460C] = 0x00004000} */
    ".word 0x391C\n"  /* add r1,r9 */
    ".word 0xD01E\n"  /* mov.l @(0x78,PC),r0  {[0x06034610] = 0x00000028} */
    ".word 0x08EE\n"  /* mov.l @(r0,r14),r8 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xD01E\n"  /* mov.l @(0x78,PC),r0  {[0x06034614] = 0x06027344} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603459C, \"ax\"\n"

    ".global _FUN_0603459C\n"
    ".type _FUN_0603459C, @function\n"
    "_FUN_0603459C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x380D\n"  /* dmuls.l r0,r8 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x230D\n"  /* .word 0x230D */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x06034618] = 0x00000004} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x0603461C] = 0x06027348} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060345B8, \"ax\"\n"

    ".global _FUN_060345B8\n"
    ".type _FUN_060345B8, @function\n"
    "_FUN_060345B8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x380D\n"  /* dmuls.l r0,r8 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x230D\n"  /* .word 0x230D */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06034620] = 0x0000000C} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x06034618] = 0x00000004} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06034624] = 0x06083238} */
    ".word 0x2042\n"  /* mov.l r4,@r0 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x06034620] = 0x0000000C} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06034628] = 0x06083240} */
    ".word 0x2052\n"  /* mov.l r5,@r0 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0603462C] = 0x06006838} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060345E2, \"ax\"\n"

    ".global _FUN_060345E2\n"
    ".type _FUN_060345E2, @function\n"
    "_FUN_060345E2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xD50D\n"  /* mov.l @(0x34,PC),r5  {[0x06034624] = 0x06083238} */
    ".word 0xD610\n"  /* mov.l @(0x40,PC),r6  {[0x06034630] = 0x06083244} */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06034634] = 0x06027EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060345F2, \"ax\"\n"

    ".global _FUN_060345F2\n"
    ".type _FUN_060345F2, @function\n"
    "_FUN_060345F2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x06034638] = 0x0608323C} */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0603463C] = 0x00000008} */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7344\n"  /* add #68,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7348\n"  /* add #72,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3240\n"  /* cmp/eq r4,r2 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x6838\n"  /* swap.b r3,r8 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3244\n"  /* .word 0x3244 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06027EDE */
    ".word 0x7EDE\n"  /* add #-34,r14 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".global _FUN_06034640\n"
    "_FUN_06034640:\n"
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06034694] = 0x06026DBC} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034642, \"ax\"\n"

    ".global _FUN_06034642\n"
    ".type _FUN_06034642, @function\n"
    "_FUN_06034642:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD13\n"  /* mov.l @(0x4C,PC),r13  {[0x06034698] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x0603469C] = 0x00000004} */
    ".word 0x04EE\n"  /* mov.l @(r0,r14),r4 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x060346A0] = 0x00000008} */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x060346A4] = 0x0000000C} */
    ".word 0x06EE\n"  /* mov.l @(r0,r14),r6 */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x060346A8] = 0x06026E2E} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603465C, \"ax\"\n"

    ".global _FUN_0603465C\n"
    ".type _FUN_0603465C, @function\n"
    "_FUN_0603465C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060346AC] = 0x00000002} */
    ".word 0x04ED\n"  /* mov.w @(r0,r14),r4 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060346B0] = 0x06026EDE} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603466A, \"ax\"\n"

    ".global _FUN_0603466A\n"
    ".type _FUN_0603466A, @function\n"
    "_FUN_0603466A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060346B4] = 0x00000011} */
    ".word 0x04EC\n"  /* mov.b @(r0,r14),r4 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x060346B8] = 0x0600A4CA} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034678, \"ax\"\n"

    ".global _FUN_06034678\n"
    ".type _FUN_06034678, @function\n"
    "_FUN_06034678:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x060346BC] = 0x06026DF8} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034682, \"ax\"\n"

    ".global _FUN_06034682\n"
    ".type _FUN_06034682, @function\n"
    "_FUN_06034682:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xDD03\n"  /* mov.l @(0xC,PC),r13  {[0x06034698] = 0x06089EDC} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DBC\n"  /* extu.b r11,r13 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x9EDC\n"  /* mov.w @(0x1B8,PC),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600A4CA */
    ".word 0xA4CA\n"  /* bra 0x06035052 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6DF8\n"  /* swap.b r15,r13 */
    ".global _FUN_060346c0\n"
    "_FUN_060346c0:\n"
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x060346F0] = 0x00000001} */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0xD10B\n"  /* mov.l @(0x2C,PC),r1  {[0x060346F4] = 0x060631B4} */
    ".word 0x021C\n"  /* mov.b @(r0,r1),r2 */
    ".word 0xD10B\n"  /* mov.l @(0x2C,PC),r1  {[0x060346F8] = 0x060631B8} */
    ".word 0x031C\n"  /* mov.b @(r0,r1),r3 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x060346FC] = 0x00000010} */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0x3123\n"  /* cmp/ge r2,r1 */
    ".word 0x8B08\n"  /* bf 0x060346EC */
    ".word 0x222A\n"  /* xor r2,r2 */
    ".word 0x0E24\n"  /* mov.b r2,@(r0,r14) */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06034700] = 0x00000011} */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x8B00\n"  /* bf 0x060346EA */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x06034704] = 0x00000000} */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x31B4\n"  /* .word 0x31B4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x31B8\n"  /* sub r11,r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034720, \"ax\"\n"

    ".global _FUN_06034720\n"
    ".type _FUN_06034720, @function\n"
    "_FUN_06034720:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB017\n"  /* bsr 0x06034754 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034728, \"ax\"\n"

    ".global _FUN_06034728\n"
    ".type _FUN_06034728, @function\n"
    "_FUN_06034728:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB03D\n"  /* bsr 0x060347A8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034730, \"ax\"\n"

    ".global _FUN_06034730\n"
    ".type _FUN_06034730, @function\n"
    "_FUN_06034730:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xB089\n"  /* bsr 0x06034848 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".global _FUN_06034754\n"
    "_FUN_06034754:\n"
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0603478C] = 0x0607E944} */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06034790] = 0x00000008} */
    ".word 0xD50E\n"  /* mov.l @(0x38,PC),r5  {[0x06034794] = 0x012C0000} */
    ".word 0x041E\n"  /* mov.l @(r0,r1),r4 */
    ".word 0x4428\n"  /* shll16 r4 */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x06034798] = 0x0602755C} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034762, \"ax\"\n"

    ".global _FUN_06034762\n"
    ".type _FUN_06034762, @function\n"
    "_FUN_06034762:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0xD008\n"  /* mov.l @(0x20,PC),r0  {[0x06034790] = 0x00000008} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0603479C] = 0x00060000} */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x8B00\n"  /* bf 0x0603477A */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0x0E16\n"  /* mov.l r1,@(r0,r14) */
    ".word 0x6213\n"  /* mov r1,r2 */
    ".word 0x4229\n"  /* shlr16 r2 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x060347A0] = 0x00000007} */
    ".word 0x2209\n"  /* and r0,r2 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x060347A4] = 0x0000000C} */
    ".word 0x0E26\n"  /* mov.l r2,@(r0,r14) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".global _FUN_060347a8\n"
    "_FUN_060347a8:\n"
    ".word 0xD01E\n"  /* mov.l @(0x78,PC),r0  {[0x06034824] = 0x0000000C} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x3130\n"  /* cmp/eq r3,r1 */
    ".word 0x8B0A\n"  /* bf 0x060347C8 */
    ".word 0xD01D\n"  /* mov.l @(0x74,PC),r0  {[0x06034828] = 0x00000010} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x201A\n"  /* xor r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8905\n"  /* bt 0x060347C8 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x0603482C] = 0x00000001} */
    ".word 0xD11C\n"  /* mov.l @(0x70,PC),r1  {[0x06034830] = 0xFFFFFFFF} */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x06034834] = 0x00000002} */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x06034824] = 0x0000000C} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0xE305\n"  /* mov #5,r3 */
    ".word 0x3130\n"  /* cmp/eq r3,r1 */
    ".word 0x8B0A\n"  /* bf 0x060347E8 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x06034828] = 0x00000010} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x201A\n"  /* xor r1,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8905\n"  /* bt 0x060347E8 */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x06034838] = 0x00000004} */
    ".word 0xD114\n"  /* mov.l @(0x50,PC),r1  {[0x06034830] = 0xFFFFFFFF} */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xD016\n"  /* mov.l @(0x58,PC),r0  {[0x0603483C] = 0x00000005} */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06034834] = 0x00000002} */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06034840] = 0x00000000} */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x3120\n"  /* cmp/eq r2,r1 */
    ".word 0x8B02\n"  /* bf 0x06034804 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x0603482C] = 0x00000001} */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xD00D\n"  /* mov.l @(0x34,PC),r0  {[0x0603483C] = 0x00000005} */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0x7101\n"  /* add #1,r1 */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x06034844] = 0x00000003} */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x3120\n"  /* cmp/eq r2,r1 */
    ".word 0x8B02\n"  /* bf 0x06034820 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x06034838] = 0x00000004} */
    ".word 0x211A\n"  /* xor r1,r1 */
    ".word 0x0E14\n"  /* mov.b r1,@(r0,r14) */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".global _FUN_06034848\n"
    "_FUN_06034848:\n"
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06034860] = 0x06083255} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x894E\n"  /* bt 0x060348EE */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x06034864] = 0x0607EBC4} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xD104\n"  /* mov.l @(0x10,PC),r1  {[0x06034868] = 0x00028000} */
    ".word 0x2018\n"  /* tst r1,r0 */
    ".word 0x8B08\n"  /* bf 0x0603486C */
    ".word 0xA048\n"  /* bra 0x060348EE */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3255\n"  /* dmulu.l r5,r2 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBC4\n"  /* mov #-60,r11 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x060348A0] = 0x00000010} */
    ".word 0x01EE\n"  /* mov.l @(r0,r14),r1 */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x060348A4] = 0x0000000C} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x893A\n"  /* bt 0x060348EE */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x060348A8] = 0x0607E944} */
    ".word 0x6102\n"  /* mov.l @r0,r1 */
    ".word 0xD00B\n"  /* mov.l @(0x2C,PC),r0  {[0x060348AC] = 0x00000008} */
    ".word 0x011E\n"  /* mov.l @(r0,r1),r1 */
    ".word 0x900D\n"  /* mov.w @(0x1A,PC),r0 */
    ".word 0x3103\n"  /* cmp/ge r0,r1 */
    ".word 0x8914\n"  /* bt 0x060348B0 */
    ".word 0xD007\n"  /* mov.l @(0x1C,PC),r0  {[0x060348A4] = 0x0000000C} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8928\n"  /* bt 0x060348E0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x891A\n"  /* bt 0x060348C8 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x891E\n"  /* bt 0x060348D4 */
    ".word 0x8805\n"  /* cmp/eq #5,r0 */
    ".word 0x8922\n"  /* bt 0x060348E0 */
    ".word 0xA028\n"  /* bra 0x060348EE */
    ".word 0x0009\n"  /* nop */
    ".word 0x0104\n"  /* mov.b r0,@(r0,r1) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0xD004\n"  /* mov.l @(0x10,PC),r0  {[0x060348C4] = 0x0000000C} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8913\n"  /* bt 0x060348E0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8905\n"  /* bt 0x060348C8 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8909\n"  /* bt 0x060348D4 */
    ".word 0xA015\n"  /* bra 0x060348EE */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0xD501\n"  /* mov.l @(0x4,PC),r5  {[0x060348D0] = 0xAE113BFF} */
    ".word 0xA00A\n"  /* bra 0x060348E2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x060344F6 */
    ".word 0x3BFF\n"  /* .word 0x3BFF */
    ".word 0xD501\n"  /* mov.l @(0x4,PC),r5  {[0x060348DC] = 0xAE113CFF} */
    ".word 0xA004\n"  /* bra 0x060348E2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x06034502 */
    ".word 0x3CFF\n"  /* .word 0x3CFF */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x060348F4] = 0xAE113DFF} */
    ".word 0xD405\n"  /* mov.l @(0x14,PC),r4  {[0x060348F8] = 0x00000000} */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x060348FC] = 0x0601D5F4} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060348E6, \"ax\"\n"

    ".global _FUN_060348E6\n"
    ".type _FUN_060348E6, @function\n"
    "_FUN_060348E6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x0603451A */
    ".word 0x3DFF\n"  /* .word 0x3DFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06034CD0] = 0x64F3D30F} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603493A, \"ax\"\n"

    ".global _FUN_0603493A\n"
    ".type _FUN_0603493A, @function\n"
    "_FUN_0603493A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x9018\n"  /* mov.w @(0x30,PC),r0 */
    ".word 0x05EE\n"  /* mov.l @(r0,r14),r5 */
    ".word 0x4511\n"  /* cmp/pz r5 */
    ".word 0x8900\n"  /* bt 0x0603494C */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0x4519\n"  /* shlr8 r5 */
    ".word 0xE307\n"  /* mov #7,r3 */
    ".word 0x4509\n"  /* shlr2 r5 */
    ".word 0x3353\n"  /* cmp/ge r5,r3 */
    ".word 0x8900\n"  /* bt 0x06034958 */
    ".word 0xE507\n"  /* mov #7,r5 */
    ".word 0xE402\n"  /* mov #2,r4 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x06034980] = 0x0601D5F4} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603495C, \"ax\"\n"

    ".global _FUN_0603495C\n"
    ".type _FUN_0603495C, @function\n"
    "_FUN_0603495C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x400B\n"  /* jsr @r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x005C\n"  /* mov.b @(r0,r5),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xAE11\n"  /* bra 0x060345A2 */
    ".word 0x28FF\n"  /* muls.w r15,r8 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06034D54] = 0x64037F08} */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034A9C, \"ax\"\n"

    ".global _FUN_06034A9C\n"
    ".type _FUN_06034A9C, @function\n"
    "_FUN_06034A9C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034AA0, \"ax\"\n"

    ".global _FUN_06034AA0\n"
    ".type _FUN_06034AA0, @function\n"
    "_FUN_06034AA0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD327\n"  /* mov.l @(0x9C,PC),r3  {[0x06034B44] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06034B48] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8422\n"  /* mov.b @(0x2,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x2E30\n"  /* mov.b r3,@r14 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8433\n"  /* mov.b @(0x3,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x80E1\n"  /* mov.b r0,@(0x1,r14) */
    ".word 0x8435\n"  /* mov.b @(0x5,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x8436\n"  /* mov.b @(0x6,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x80E3\n"  /* mov.b r0,@(0x3,r14) */
    ".word 0x8437\n"  /* mov.b @(0x7,r3),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x80E4\n"  /* mov.b r0,@(0x4,r14) */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034B5C, \"ax\"\n"

    ".global _FUN_06034B5C\n"
    ".type _FUN_06034B5C, @function\n"
    "_FUN_06034B5C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x06034BF8] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06034BFC] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x5321\n"  /* mov.l @(0x4,r2),r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034BA8, \"ax\"\n"

    ".global _FUN_06034BA8\n"
    ".type _FUN_06034BA8, @function\n"
    "_FUN_06034BA8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6B53\n"  /* mov r5,r11 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06034BF8] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE304\n"  /* mov #4,r3 */
    ".word 0x6BBD\n"  /* extu.w r11,r11 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63EC\n"  /* extu.b r14,r3 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60B3\n"  /* mov r11,r0 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x8131\n"  /* mov.w r0,@(0x2,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x8036\n"  /* mov.b r0,@(0x6,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x8037\n"  /* mov.b r0,@(0x7,r3) */
    ".word 0x9005\n"  /* mov.w @(0xA,PC),r0 */
    ".word 0x20E9\n"  /* and r14,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B1E\n"  /* bf 0x06034C2C */
    ".word 0x9202\n"  /* mov.w @(0x4,PC),r2 */
    ".word 0xA008\n"  /* bra 0x06034C04 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0081\n"  /* .word 0x0081 */
    ".word 0x0DAC\n"  /* mov.b @(r0,r10),r13 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x89F9\n"  /* bt 0x06034C00 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06034C7C] = 0x06035C92} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE441\n"  /* mov #65,r4 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x06034C80] = 0x06035EC8} */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x2EE8\n"  /* tst r14,r14 */
    ".word 0x8B0A\n"  /* bf 0x06034C38 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06034C84] = 0x06035C80} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA006\n"  /* bra 0x06034C38 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06034C80] = 0x06035EC8} */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034CCC, \"ax\"\n"

    ".global _FUN_06034CCC\n"
    ".type _FUN_06034CCC, @function\n"
    "_FUN_06034CCC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06034D10] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE306\n"  /* mov #6,r3 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06034D14] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x06034D18] = 0x00FFFFFF} */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0082\n"  /* .word 0x0082 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E00 */
    ".word 0x5E00\n"  /* mov.l @(0x0,r0),r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFD\n"  /* .word 0xFFFD */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C6E\n"  /* mov.l @(0x38,r6),r12 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034D20, \"ax\"\n"

    ".global _FUN_06034D20\n"
    ".type _FUN_06034D20, @function\n"
    "_FUN_06034D20:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x06034DBC] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE310\n"  /* mov #16,r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0xB013\n"  /* bsr 0x06034D5E */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x03EC\n"  /* mov.b @(r0,r14),r3 */
    ".word 0x7505\n"  /* add #5,r5 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xB009\n"  /* bsr 0x06034D5E */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x06034DC0] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034E20, \"ax\"\n"

    ".global _FUN_06034E20\n"
    ".type _FUN_06034E20, @function\n"
    "_FUN_06034E20:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034E24, \"ax\"\n"

    ".global _FUN_06034E24\n"
    ".type _FUN_06034E24, @function\n"
    "_FUN_06034E24:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06034E50] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE312\n"  /* mov #18,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x06034E54] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xD223\n"  /* mov.l @(0x8C,PC),r2  {[0x06034EEC] = 0x06063578} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA000\n"  /* bra 0x06034E64 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD022\n"  /* mov.l @(0x88,PC),r0  {[0x06034EF0] = 0x0606358C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC901\n"  /* and #0x01,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89F8\n"  /* bt 0x06034E64 */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x06034EF0] = 0x0606358C} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x06034EF4] = 0x06063584} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06034EF8] = 0x06059CAD} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xA000\n"  /* bra 0x06034E88 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06034EF0] = 0x0606358C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC901\n"  /* and #0x01,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89F8\n"  /* bt 0x06034E88 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x81F1\n"  /* mov.w r0,@(0x2,r15) */
    ".word 0xA005\n"  /* bra 0x06034EAA */
    ".word 0x0009\n"  /* nop */
    ".word 0x85F1\n"  /* mov.w @(0x2,r15),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x81F1\n"  /* mov.w r0,@(0x2,r15) */
    ".word 0x85F1\n"  /* mov.w @(0x2,r15),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x921A\n"  /* mov.w @(0x34,PC),r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8BF4\n"  /* bf 0x06034EA0 */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x06034EFC] = 0x06063580} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06034F00] = 0x06034F08} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x06034EF0] = 0x0606358C} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x06034EF4] = 0x06063584} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06034F04] = 0x06059CAC} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xA000\n"  /* bra 0x06034ED4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x06034EF0] = 0x0606358C} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC901\n"  /* and #0x01,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89F8\n"  /* bt 0x06034ED4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x03E8\n"  /* .word 0x03E8 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3578\n"  /* sub r7,r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x358C\n"  /* add r8,r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3584\n"  /* .word 0x3584 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9CAD\n"  /* mov.w @(0x15A,PC),r12 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3580\n"  /* cmp/eq r8,r5 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06034F08 */
    ".word 0x4F08\n"  /* shll2 r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9CAC\n"  /* mov.w @(0x158,PC),r12 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06034F08, \"ax\"\n"

    ".global _FUN_06034F08\n"
    ".type _FUN_06034F08, @function\n"
    "_FUN_06034F08:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x9324\n"  /* mov.w @(0x48,PC),r3 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xCBF0\n"  /* or #0xF0,r0 */
    ".word 0x400E\n"  /* ldc r0,sr */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x9320\n"  /* mov.w @(0x40,PC),r3 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x931E\n"  /* mov.w @(0x3C,PC),r3 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xA015\n"  /* bra 0x06034F5E */
    ".word 0x0009\n"  /* nop */
    ".word 0x9019\n"  /* mov.w @(0x32,PC),r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC980\n"  /* and #0x80,r0 */
    ".word 0x9316\n"  /* mov.w @(0x2C,PC),r3 */
    ".word 0x3030\n"  /* cmp/eq r3,r0 */
    ".word 0x8B0D\n"  /* bf 0x06034F5E */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x9211\n"  /* mov.w @(0x22,PC),r2 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x06034F70] = 0x06063574} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8903\n"  /* bt 0x06034F58 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06034F74] = 0x26063574} */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x06034F70] = 0x06063574} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xAFE9\n"  /* bra 0x06034F34 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF0F\n"  /* .word 0xFF0F */
    ".word 0xFEE2\n"  /* .word 0xFEE2 */
    ".word 0xFE60\n"  /* .word 0xFE60 */
    ".word 0xFE10\n"  /* .word 0xFE10 */
    ".word 0xFE11\n"  /* .word 0xFE11 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3574\n"  /* .word 0x3574 */
    ".word 0x2606\n"  /* mov.l r0,@-r6 */
    ".word 0x3574\n"  /* .word 0x3574 */
    ".global _FUN_06034f78\n"
    "_FUN_06034f78:\n"
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x6318\n"  /* swap.b r1,r3 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x6413\n"  /* mov r1,r4 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xE6FF\n"  /* mov #-1,r6 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8B05\n"  /* bf 0x06034FA6 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x89F3\n"  /* bt 0x06034F8E */
    ".word 0x2059\n"  /* and r5,r0 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0x3418\n"  /* sub r1,r4 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x890B\n"  /* bt 0x06034FCC */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8B05\n"  /* bf 0x06034FCC */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x74FF\n"  /* add #-1,r4 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x89F3\n"  /* bt 0x06034FB4 */
    ".word 0x6422\n"  /* mov.l @r2,r4 */
    ".word 0x2649\n"  /* and r4,r6 */
    ".word 0x256B\n"  /* or r6,r5 */
    ".word 0x2252\n"  /* mov.l r5,@r2 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".global _FUN_06034fe0\n"
    "_FUN_06034fe0:\n"
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x9309\n"  /* mov.w @(0x12,PC),r3 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x2316\n"  /* mov.l r1,@-r3 */
    ".word 0x7310\n"  /* add #16,r3 */
    ".word 0x6032\n"  /* mov.l @r3,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".global _FUN_06034ffc\n"
    "_FUN_06034ffc:\n"
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x894B\n"  /* bt 0x0603509A */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2127\n"  /* .word 0x2127 */
    ".word 0x333A\n"  /* .word 0x333A */
    ".word 0x312A\n"  /* .word 0x312A */
    ".word 0x2307\n"  /* .word 0x2307 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x312E\n"  /* .word 0x312E */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x060350A8] = 0x060A246C} */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x060350AC] = 0x0000044E} */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x246C\n"  /* .word 0x246C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".global _FUN_060350b0\n"
    "_FUN_060350b0:\n"
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x894D\n"  /* bt 0x06035150 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x0019\n"  /* div0u */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3344\n"  /* .word 0x3344 */
    ".word 0x8B03\n"  /* bf 0x06035148 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x06035160] = 0x060A246C} */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06035164] = 0x0000044E} */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x246C\n"  /* .word 0x246C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".global _FUN_06035168\n"
    "_FUN_06035168:\n"
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xE340\n"  /* mov #64,r3 */
    ".word 0x3302\n"  /* cmp/hs r0,r3 */
    ".word 0x8B4B\n"  /* bf 0x06035208 */
    ".word 0xD301\n"  /* mov.l @(0x4,PC),r3  {[0x06035178] = 0x060351C4} */
    ".word 0x033E\n"  /* mov.l @(r0,r3),r3 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51C4\n"  /* mov.l @(0x10,r12),r1 */
    ".word 0x0009\n"  /* nop */
    ".word 0x502F\n"  /* mov.l @(0x3C,r2),r0 */
    ".word 0x110F\n"  /* mov.l r0,@(0x3C,r1) */
    ".word 0x502E\n"  /* mov.l @(0x38,r2),r0 */
    ".word 0x110E\n"  /* mov.l r0,@(0x38,r1) */
    ".word 0x502D\n"  /* mov.l @(0x34,r2),r0 */
    ".word 0x110D\n"  /* mov.l r0,@(0x34,r1) */
    ".word 0x502C\n"  /* mov.l @(0x30,r2),r0 */
    ".word 0x110C\n"  /* mov.l r0,@(0x30,r1) */
    ".word 0x502B\n"  /* mov.l @(0x2C,r2),r0 */
    ".word 0x110B\n"  /* mov.l r0,@(0x2C,r1) */
    ".word 0x502A\n"  /* mov.l @(0x28,r2),r0 */
    ".word 0x110A\n"  /* mov.l r0,@(0x28,r1) */
    ".word 0x5029\n"  /* mov.l @(0x24,r2),r0 */
    ".word 0x1109\n"  /* mov.l r0,@(0x24,r1) */
    ".word 0x5028\n"  /* mov.l @(0x20,r2),r0 */
    ".word 0x1108\n"  /* mov.l r0,@(0x20,r1) */
    ".word 0x5027\n"  /* mov.l @(0x1C,r2),r0 */
    ".word 0x1107\n"  /* mov.l r0,@(0x1C,r1) */
    ".word 0x5026\n"  /* mov.l @(0x18,r2),r0 */
    ".word 0x1106\n"  /* mov.l r0,@(0x18,r1) */
    ".word 0x5025\n"  /* mov.l @(0x14,r2),r0 */
    ".word 0x1105\n"  /* mov.l r0,@(0x14,r1) */
    ".word 0x5024\n"  /* mov.l @(0x10,r2),r0 */
    ".word 0x1104\n"  /* mov.l r0,@(0x10,r1) */
    ".word 0x5023\n"  /* mov.l @(0xC,r2),r0 */
    ".word 0x1103\n"  /* mov.l r0,@(0xC,r1) */
    ".word 0x5022\n"  /* mov.l @(0x8,r2),r0 */
    ".word 0x1102\n"  /* mov.l r0,@(0x8,r1) */
    ".word 0x5021\n"  /* mov.l @(0x4,r2),r0 */
    ".word 0x1101\n"  /* mov.l r0,@(0x4,r1) */
    ".word 0x6022\n"  /* mov.l @r2,r0 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51BE\n"  /* mov.l @(0x38,r11),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51BA\n"  /* mov.l @(0x28,r11),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51B6\n"  /* mov.l @(0x18,r11),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51B2\n"  /* mov.l @(0x8,r11),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51AE\n"  /* mov.l @(0x38,r10),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51AA\n"  /* mov.l @(0x28,r10),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51A6\n"  /* mov.l @(0x18,r10),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x51A2\n"  /* mov.l @(0x8,r10),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x519E\n"  /* mov.l @(0x38,r9),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x519A\n"  /* mov.l @(0x28,r9),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5196\n"  /* mov.l @(0x18,r9),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5192\n"  /* mov.l @(0x8,r9),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x518E\n"  /* mov.l @(0x38,r8),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x518A\n"  /* mov.l @(0x28,r8),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5186\n"  /* mov.l @(0x18,r8),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5182\n"  /* mov.l @(0x8,r8),r1 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x517E\n"  /* mov.l @(0x38,r7),r1 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x6026\n"  /* mov.l @r2+,r0 */
    ".word 0x3322\n"  /* cmp/hs r2,r3 */
    ".word 0x8B06\n"  /* bf 0x06035222 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x6026\n"  /* mov.l @r2+,r0 */
    ".word 0x3322\n"  /* cmp/hs r2,r3 */
    ".word 0x8B02\n"  /* bf 0x06035222 */
    ".word 0x1101\n"  /* mov.l r0,@(0x4,r1) */
    ".word 0xAFF6\n"  /* bra 0x0603520E */
    ".word 0x7108\n"  /* add #8,r1 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".global _FUN_06035228\n"
    "_FUN_06035228:\n"
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8912\n"  /* bt 0x06035258 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x6024\n"  /* mov.b @r2+,r0 */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0x3426\n"  /* cmp/hi r2,r4 */
    ".word 0x8B0C\n"  /* bf 0x06035258 */
    ".word 0x6024\n"  /* mov.b @r2+,r0 */
    ".word 0x8011\n"  /* mov.b r0,@(0x1,r1) */
    ".word 0x3426\n"  /* cmp/hi r2,r4 */
    ".word 0x8B08\n"  /* bf 0x06035258 */
    ".word 0x6024\n"  /* mov.b @r2+,r0 */
    ".word 0x8012\n"  /* mov.b r0,@(0x2,r1) */
    ".word 0x3426\n"  /* cmp/hi r2,r4 */
    ".word 0x8B04\n"  /* bf 0x06035258 */
    ".word 0x6024\n"  /* mov.b @r2+,r0 */
    ".word 0x8013\n"  /* mov.b r0,@(0x3,r1) */
    ".word 0x3426\n"  /* cmp/hi r2,r4 */
    ".word 0x7104\n"  /* add #4,r1 */
    ".word 0x89EE\n"  /* bt 0x06035236 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x0E0C\n"  /* mov.b @(r0,r0),r14 */
    ".word 0x0A08\n"  /* .word 0x0A08 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x201E\n"  /* mulu.w r1,r0 */
    ".word 0x1C1A\n"  /* mov.l r1,@(0x28,r12) */
    ".word 0x1816\n"  /* mov.l r1,@(0x18,r8) */
    ".word 0x1412\n"  /* mov.l r1,@(0x8,r4) */
    ".word 0x3432\n"  /* cmp/hs r3,r4 */
    ".word 0x302E\n"  /* .word 0x302E */
    ".word 0x2C2A\n"  /* xor r2,r12 */
    ".word 0x2826\n"  /* mov.l r2,@-r8 */
    ".word 0x403E\n"  /* .word 0x403E */
    ".word 0x3C3A\n"  /* .word 0x3C3A */
    ".word 0x4856\n"  /* .word 0x4856 */
    ".word 0x626C\n"  /* extu.b r6,r2 */
    ".global _FUN_06035280\n"
    "_FUN_06035280:\n"
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x4111\n"  /* cmp/pz r1 */
    ".word 0x8F18\n"  /* bf/s 0x060352B8 */
    ".word 0xE220\n"  /* mov #32,r2 */
    ".word 0x3123\n"  /* cmp/ge r2,r1 */
    ".word 0x890B\n"  /* bt 0x060352A4 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x060352A0] = 0x06035260} */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0xD102\n"  /* mov.l @(0x8,PC),r1  {[0x0603529C] = 0x060352AA} */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x412B\n"  /* jmp @r1 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x52AA\n"  /* mov.l @(0x28,r10),r2 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5260\n"  /* mov.l @(0x0,r6),r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xC907\n"  /* and #0x07,r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xC903\n"  /* and #0x03,r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xC901\n"  /* and #0x01,r0 */
    ".word 0x4005\n"  /* rotr r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFCFA\n"  /* .word 0xFCFA */
    ".word 0xF8F6\n"  /* .word 0xF8F6 */
    ".word 0xF4F2\n"  /* .word 0xF4F2 */
    ".word 0xF0EE\n"  /* .word 0xF0EE */
    ".word 0xECEA\n"  /* mov #-22,r12 */
    ".word 0xE8E6\n"  /* mov #-26,r8 */
    ".word 0xE4E2\n"  /* mov #-30,r4 */
    ".word 0xE0DE\n"  /* mov #-34,r0 */
    ".word 0xDCDA\n"  /* mov.l @(0x368,PC),r12  {[0x0603569C] = 0x48158905} */
    ".word 0xD8D6\n"  /* mov.l @(0x358,PC),r8  {[0x0603568C] = 0x34338D05} */
    ".word 0xD4D2\n"  /* mov.l @(0x348,PC),r4  {[0x06035680] = 0x44243433} */
    ".word 0xD0CE\n"  /* mov.l @(0x338,PC),r0  {[0x06035670] = 0x34338913} */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x2236\n"  /* mov.l r3,@-r2 */
    ".word 0x4858\n"  /* .word 0x4858 */
    ".word 0x6672\n"  /* mov.l @r7,r6 */
    ".global _FUN_06035340\n"
    "_FUN_06035340:\n"
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x4111\n"  /* cmp/pz r1 */
    ".word 0x8F39\n"  /* bf/s 0x060353BA */
    ".word 0xE220\n"  /* mov #32,r2 */
    ".word 0x3123\n"  /* cmp/ge r2,r1 */
    ".word 0x8917\n"  /* bt 0x0603537C */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x4204\n"  /* rotl r2 */
    ".word 0x8B07\n"  /* bf 0x06035362 */
    ".word 0xD207\n"  /* mov.l @(0x1C,PC),r2  {[0x06035370] = 0x06035338} */
    ".word 0x71E8\n"  /* add #-24,r1 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x6210\n"  /* mov.b @r1,r2 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x06035374] = 0x060353BE} */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x412B\n"  /* jmp @r1 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x3127\n"  /* cmp/gt r2,r1 */
    ".word 0x8BF4\n"  /* bf 0x06035352 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06035378] = 0x06036068} */
    ".word 0x422B\n"  /* jmp @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5338\n"  /* mov.l @(0x20,r3),r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x53BE\n"  /* mov.l @(0x38,r11),r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x6068\n"  /* swap.b r6,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x8902\n"  /* bt 0x06035386 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x6109\n"  /* swap.w r0,r1 */
    ".word 0x6018\n"  /* swap.b r1,r0 */
    ".word 0xE180\n"  /* mov #-128,r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0xE1C0\n"  /* mov #-64,r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0xE1E0\n"  /* mov #-32,r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0xE1F0\n"  /* mov #-16,r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0xE1F8\n"  /* mov #-8,r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0xE1FC\n"  /* mov #-4,r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0x4004\n"  /* rotl r0 */
    ".word 0xE1FE\n"  /* mov #-2,r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8B01\n"  /* bf 0x06035440 */
    ".word 0xA001\n"  /* bra 0x06035442 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x604B\n"  /* neg r4,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x55F7\n"  /* mov.l @(0x1C,r15),r5 */
    ".word 0x56F8\n"  /* mov.l @(0x20,r15),r6 */
    ".word 0x57F9\n"  /* mov.l @(0x24,r15),r7 */
    ".word 0xD0B4\n"  /* mov.l @(0x2D0,PC),r0  {[0x0603572C] = 0x80000000} */
    ".word 0xA061\n"  /* bra 0x06035522 */
    ".word 0x260A\n"  /* xor r0,r6 */
    ".global _FUN_06035460\n"
    "_FUN_06035460:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x56F6\n"  /* mov.l @(0x18,r15),r6 */
    ".word 0x57F7\n"  /* mov.l @(0x1C,r15),r7 */
    ".word 0x54F8\n"  /* mov.l @(0x20,r15),r4 */
    ".word 0x55F9\n"  /* mov.l @(0x24,r15),r5 */
    ".word 0xD0AE\n"  /* mov.l @(0x2B8,PC),r0  {[0x0603572C] = 0x80000000} */
    ".word 0xA055\n"  /* bra 0x06035522 */
    ".word 0x260A\n"  /* xor r0,r6 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B07\n"  /* bf 0x0603548C */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B05\n"  /* bf 0x0603548C */
    ".word 0x3930\n"  /* cmp/eq r3,r9 */
    ".word 0x8B07\n"  /* bf 0x06035494 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B01\n"  /* bf 0x0603548C */
    ".word 0x2BA7\n"  /* .word 0x2BA7 */
    ".word 0x8B03\n"  /* bf 0x06035494 */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA11B\n"  /* bra 0x060356CA */
    ".word 0xE508\n"  /* mov #8,r5 */
    ".word 0xA119\n"  /* bra 0x060356CA */
    ".word 0x0009\n"  /* nop */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x8B07\n"  /* bf 0x060354AC */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B0B\n"  /* bf 0x060354B8 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B09\n"  /* bf 0x060354B8 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B0D\n"  /* bf 0x060354C4 */
    ".word 0xA10F\n"  /* bra 0x060356CA */
    ".word 0x2AB9\n"  /* and r11,r10 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8B1E\n"  /* bf 0x060354EE */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B1C\n"  /* bf 0x060354EE */
    ".word 0xA00A\n"  /* bra 0x060354CC */
    ".word 0x0009\n"  /* nop */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8B0E\n"  /* bf 0x060354DA */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B0C\n"  /* bf 0x060354DA */
    ".word 0xA004\n"  /* bra 0x060354CC */
    ".word 0x0009\n"  /* nop */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x6573\n"  /* mov r7,r5 */
    ".word 0x6893\n"  /* mov r9,r8 */
    ".word 0x6AB3\n"  /* mov r11,r10 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0xA0F8\n"  /* bra 0x060356CA */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0xD393\n"  /* mov.l @(0x24C,PC),r3  {[0x06035728] = 0x00100000} */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8904\n"  /* bt 0x060354EE */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8FFB\n"  /* bf/s 0x060354E4 */
    ".word 0x78FF\n"  /* add #-1,r8 */
    ".word 0xD38E\n"  /* mov.l @(0x238,PC),r3  {[0x06035728] = 0x00100000} */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4624\n"  /* .word 0x4624 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8904\n"  /* bt 0x06035502 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4624\n"  /* .word 0x4624 */
    ".word 0x3633\n"  /* cmp/ge r3,r6 */
    ".word 0x8FFB\n"  /* bf/s 0x060354F8 */
    ".word 0x79FF\n"  /* add #-1,r9 */
    ".word 0xA034\n"  /* bra 0x0603556E */
    ".word 0x0009\n"  /* nop */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA0DE\n"  /* bra 0x060356CA */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x55F7\n"  /* mov.l @(0x1C,r15),r5 */
    ".word 0x56F8\n"  /* mov.l @(0x20,r15),r6 */
    ".word 0x57F9\n"  /* mov.l @(0x24,r15),r7 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4404\n"  /* rotl r4 */
    ".word 0x4604\n"  /* rotl r6 */
    ".word 0x3462\n"  /* cmp/hs r6,r4 */
    ".word 0x8905\n"  /* bt 0x06035542 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0x6623\n"  /* mov r2,r6 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x6573\n"  /* mov r7,r5 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x4405\n"  /* rotr r4 */
    ".word 0x4605\n"  /* rotr r6 */
    ".word 0xD373\n"  /* mov.l @(0x1CC,PC),r3  {[0x06035714] = 0x000007FF} */
    ".word 0xD073\n"  /* mov.l @(0x1CC,PC),r0  {[0x06035718] = 0x000FFFFF} */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x6B63\n"  /* mov r6,r11 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x4829\n"  /* shlr16 r8 */
    ".word 0x4809\n"  /* shlr2 r8 */
    ".word 0x4809\n"  /* shlr2 r8 */
    ".word 0x2839\n"  /* and r3,r8 */
    ".word 0x6963\n"  /* mov r6,r9 */
    ".word 0x4929\n"  /* shlr16 r9 */
    ".word 0x4909\n"  /* shlr2 r9 */
    ".word 0x4909\n"  /* shlr2 r9 */
    ".word 0x2939\n"  /* and r3,r9 */
    ".word 0x2409\n"  /* and r0,r4 */
    ".word 0x2609\n"  /* and r0,r6 */
    ".word 0x3830\n"  /* cmp/eq r3,r8 */
    ".word 0x8986\n"  /* bt 0x06035478 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x8994\n"  /* bt 0x06035498 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4624\n"  /* .word 0x4624 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4624\n"  /* .word 0x4624 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4624\n"  /* .word 0x4624 */
    ".word 0xD065\n"  /* mov.l @(0x194,PC),r0  {[0x0603571C] = 0x00800000} */
    ".word 0x240B\n"  /* or r0,r4 */
    ".word 0x260B\n"  /* or r0,r6 */
    ".word 0x6283\n"  /* mov r8,r2 */
    ".word 0x3298\n"  /* sub r9,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8929\n"  /* bt 0x060355E8 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8922\n"  /* bt 0x060355E0 */
    ".word 0xE336\n"  /* mov #54,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x891C\n"  /* bt 0x060355DA */
    ".word 0xE320\n"  /* mov #32,r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8F06\n"  /* bf/s 0x060355B4 */
    ".word 0xE901\n"  /* mov #1,r9 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8900\n"  /* bt 0x060355B0 */
    ".word 0x269B\n"  /* or r9,r6 */
    ".word 0x6763\n"  /* mov r6,r7 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x4F02\n"  /* sts.l mach,@-r15 */
    ".word 0xC75F\n"  /* mova @(0x17C,PC),r0  {0x06035734} */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x302C\n"  /* add r2,r0 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x3705\n"  /* dmulu.l r0,r7 */
    ".word 0x070A\n"  /* sts mach,r7 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x3605\n"  /* dmulu.l r0,r6 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x4F06\n"  /* lds.l @r15+,mach */
    ".word 0x8D09\n"  /* bt/s 0x060355E8 */
    ".word 0x273B\n"  /* or r3,r7 */
    ".word 0xA007\n"  /* bra 0x060355E8 */
    ".word 0x279B\n"  /* or r9,r7 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xA004\n"  /* bra 0x060355E8 */
    ".word 0xE701\n"  /* mov #1,r7 */
    ".word 0x4601\n"  /* shlr r6 */
    ".word 0x4725\n"  /* .word 0x4725 */
    ".word 0x4210\n"  /* dt r2 */
    ".word 0x8BFB\n"  /* bf 0x060355E0 */
    ".word 0x2BA7\n"  /* .word 0x2BA7 */
    ".word 0x890F\n"  /* bt 0x0603560C */
    ".word 0x357E\n"  /* .word 0x357E */
    ".word 0x346E\n"  /* .word 0x346E */
    ".word 0xD34C\n"  /* mov.l @(0x130,PC),r3  {[0x06035724] = 0x01000000} */
    ".word 0x3347\n"  /* cmp/gt r4,r3 */
    ".word 0x8952\n"  /* bt 0x0603569C */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x0229\n"  /* .word 0x0229 */
    ".word 0x252B\n"  /* or r2,r5 */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0xD344\n"  /* mov.l @(0x110,PC),r3  {[0x06035714] = 0x000007FF} */
    ".word 0x3830\n"  /* cmp/eq r3,r8 */
    ".word 0x8B4A\n"  /* bf 0x0603569C */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xA05F\n"  /* bra 0x060356CA */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x3640\n"  /* cmp/eq r4,r6 */
    ".word 0x8B01\n"  /* bf 0x06035614 */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x8979\n"  /* bt 0x06035708 */
    ".word 0x357A\n"  /* .word 0x357A */
    ".word 0x346A\n"  /* .word 0x346A */
    ".word 0x8B03\n"  /* bf 0x06035622 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x655A\n"  /* .word 0x655A */
    ".word 0x644A\n"  /* .word 0x644A */
    ".word 0x6AB3\n"  /* mov r11,r10 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B02\n"  /* bf 0x0603562C */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x78E0\n"  /* add #-32,r8 */
    ".word 0xD340\n"  /* mov.l @(0x100,PC),r3  {[0x06035730] = 0xFFFF0000} */
    ".word 0x2348\n"  /* tst r4,r3 */
    ".word 0x8B04\n"  /* bf 0x0603563C */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x234D\n"  /* .word 0x234D */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x4528\n"  /* shll16 r5 */
    ".word 0x78F0\n"  /* add #-16,r8 */
    ".word 0xD339\n"  /* mov.l @(0xE4,PC),r3  {[0x06035724] = 0x01000000} */
    ".word 0x3346\n"  /* cmp/hi r4,r3 */
    ".word 0x8915\n"  /* bt 0x0603566E */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x3346\n"  /* cmp/hi r4,r3 */
    ".word 0x8D28\n"  /* bt/s 0x0603569C */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x3346\n"  /* cmp/hi r4,r3 */
    ".word 0x8D23\n"  /* bt/s 0x0603569C */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x3346\n"  /* cmp/hi r4,r3 */
    ".word 0x8D1E\n"  /* bt/s 0x0603569C */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x3346\n"  /* cmp/hi r4,r3 */
    ".word 0x8D19\n"  /* bt/s 0x0603569C */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0xAFEA\n"  /* bra 0x06035642 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x0603571C] = 0x00800000} */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8913\n"  /* bt 0x0603569C */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8D0F\n"  /* bt/s 0x0603569C */
    ".word 0x78FF\n"  /* add #-1,r8 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8D0A\n"  /* bt/s 0x0603569C */
    ".word 0x78FF\n"  /* add #-1,r8 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8D05\n"  /* bt/s 0x0603569C */
    ".word 0x78FF\n"  /* add #-1,r8 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8FEC\n"  /* bf/s 0x06035674 */
    ".word 0x78FF\n"  /* add #-1,r8 */
    ".word 0x4815\n"  /* cmp/pl r8 */
    ".word 0x8905\n"  /* bt 0x060356AC */
    ".word 0x688B\n"  /* neg r8,r8 */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x4810\n"  /* dt r8 */
    ".word 0x8BFB\n"  /* bf 0x060356A4 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0xC804\n"  /* tst #0x04,r0 */
    ".word 0x890B\n"  /* bt 0x060356CA */
    ".word 0xC80B\n"  /* tst #0x0B,r0 */
    ".word 0x8909\n"  /* bt 0x060356CA */
    ".word 0xE008\n"  /* mov #8,r0 */
    ".word 0x350E\n"  /* .word 0x350E */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x340E\n"  /* .word 0x340E */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06035724] = 0x01000000} */
    ".word 0x3047\n"  /* cmp/gt r4,r0 */
    ".word 0x8902\n"  /* bt 0x060356CA */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x4525\n"  /* .word 0x4525 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06035718] = 0x000FFFFF} */
    ".word 0x2409\n"  /* and r0,r4 */
    ".word 0x4828\n"  /* shll16 r8 */
    ".word 0x4808\n"  /* shll2 r8 */
    ".word 0x4808\n"  /* shll2 r8 */
    ".word 0x248B\n"  /* or r8,r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4A00\n"  /* shll r10 */
    ".word 0x4425\n"  /* .word 0x4425 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x56F5\n"  /* mov.l @(0x14,r15),r6 */
    ".word 0x2642\n"  /* mov.l r4,@r6 */
    ".word 0x1651\n"  /* mov.l r5,@(0x4,r6) */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0xE800\n"  /* mov #0,r8 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xAFDC\n"  /* bra 0x060356CA */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x07FF\n"  /* mac.l @r15+,@r7+ */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0400\n"  /* .word 0x0400 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0400\n"  /* .word 0x0400 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0040\n"  /* .word 0x0040 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".global _FUN_060357b8\n"
    "_FUN_060357b8:\n"
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x50F5\n"  /* mov.l @(0x14,r15),r0 */
    ".word 0x51F6\n"  /* mov.l @(0x18,r15),r1 */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x06035834] = 0x000007FF} */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x06035838] = 0x000FFFFF} */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x4229\n"  /* shlr16 r2 */
    ".word 0x4209\n"  /* shlr2 r2 */
    ".word 0x4209\n"  /* shlr2 r2 */
    ".word 0x2249\n"  /* and r4,r2 */
    ".word 0x2059\n"  /* and r5,r0 */
    ".word 0xD419\n"  /* mov.l @(0x64,PC),r4  {[0x06035840] = 0x000003FF} */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8B27\n"  /* bf 0x06035830 */
    ".word 0xE453\n"  /* mov #83,r4 */
    ".word 0x3247\n"  /* cmp/gt r4,r2 */
    ".word 0x8924\n"  /* bt 0x06035830 */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x0603583C] = 0x00100000} */
    ".word 0x204B\n"  /* or r4,r0 */
    ".word 0x72EC\n"  /* add #-20,r2 */
    ".word 0x4211\n"  /* cmp/pz r2 */
    ".word 0x8B11\n"  /* bf 0x06035814 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0x3243\n"  /* cmp/ge r4,r2 */
    ".word 0x8905\n"  /* bt 0x06035802 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x4210\n"  /* dt r2 */
    ".word 0x890F\n"  /* bt 0x0603581C */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0xAFFB\n"  /* bra 0x060357F8 */
    ".word 0x4024\n"  /* .word 0x4024 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x72E0\n"  /* add #-32,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8908\n"  /* bt 0x0603581C */
    ".word 0x4210\n"  /* dt r2 */
    ".word 0x8FFD\n"  /* bf/s 0x0603580A */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xA004\n"  /* bra 0x0603581C */
    ".word 0x0009\n"  /* nop */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x4210\n"  /* dt r2 */
    ".word 0x8FFD\n"  /* bf/s 0x06035816 */
    ".word 0x4001\n"  /* shlr r0 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x8B00\n"  /* bf 0x06035822 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0xAFF7\n"  /* bra 0x06035822 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x07FF\n"  /* mac.l @r15+,@r7+ */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".global _FUN_06035844\n"
    "_FUN_06035844:\n"
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x55F7\n"  /* mov.l @(0x1C,r15),r5 */
    ".word 0x56F4\n"  /* mov.l @(0x10,r15),r6 */
    ".word 0x57F5\n"  /* mov.l @(0x14,r15),r7 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0xD021\n"  /* mov.l @(0x84,PC),r0  {[0x060358E4] = 0x7FF00000} */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x6B63\n"  /* mov r6,r11 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x2809\n"  /* and r0,r8 */
    ".word 0x6963\n"  /* mov r6,r9 */
    ".word 0x2909\n"  /* and r0,r9 */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x060358E8] = 0x000FFFFF} */
    ".word 0x2409\n"  /* and r0,r4 */
    ".word 0x2609\n"  /* and r0,r6 */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x060358E4] = 0x7FF00000} */
    ".word 0x3800\n"  /* cmp/eq r0,r8 */
    ".word 0x891C\n"  /* bt 0x060358B0 */
    ".word 0x3900\n"  /* cmp/eq r0,r9 */
    ".word 0x8920\n"  /* bt 0x060358BC */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x8924\n"  /* bt 0x060358C8 */
    ".word 0x2BA7\n"  /* .word 0x2BA7 */
    ".word 0x890A\n"  /* bt 0x06035898 */
    ".word 0x4A11\n"  /* cmp/pz r10 */
    ".word 0x8B04\n"  /* bf 0x06035890 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x375A\n"  /* .word 0x375A */
    ".word 0x3BAA\n"  /* .word 0x3BAA */
    ".word 0xA006\n"  /* bra 0x0603589C */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x357A\n"  /* .word 0x357A */
    ".word 0x3ABA\n"  /* .word 0x3ABA */
    ".word 0xA002\n"  /* bra 0x0603589C */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x4A11\n"  /* cmp/pz r10 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B15\n"  /* bf 0x060358E0 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B13\n"  /* bf 0x060358E0 */
    ".word 0xAFDD\n"  /* bra 0x06035876 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8B0F\n"  /* bf 0x060358E0 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B0D\n"  /* bf 0x060358E0 */
    ".word 0xAFD9\n"  /* bra 0x0603587A */
    ".word 0x0009\n"  /* nop */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x8BD8\n"  /* bf 0x0603587E */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8BD6\n"  /* bf 0x0603587E */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8BD4\n"  /* bf 0x0603587E */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8BD2\n"  /* bf 0x0603587E */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8BD0\n"  /* bf 0x0603587E */
    ".word 0xAFDE\n"  /* bra 0x0603589C */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xAFDC\n"  /* bra 0x0603589C */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".global _FUN_060358ec\n"
    "_FUN_060358ec:\n"
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891E\n"  /* bt 0x06035934 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8901\n"  /* bt 0x06035900 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0xD10E\n"  /* mov.l @(0x38,PC),r1  {[0x0603593C] = 0x0000041F} */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x8FFD\n"  /* bf/s 0x06035902 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x4228\n"  /* shll16 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4019\n"  /* shlr8 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4128\n"  /* shll16 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0x4025\n"  /* .word 0x4025 */
    ".word 0x51F3\n"  /* mov.l @(0xC,r15),r1 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x1121\n"  /* mov.l r2,@(0x4,r1) */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xAFF5\n"  /* bra 0x06035924 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x041F\n"  /* mac.l @r1+,@r4+ */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B4A\n"  /* bf 0x060359DA */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B48\n"  /* bf 0x060359DA */
    ".word 0x3930\n"  /* cmp/eq r3,r9 */
    ".word 0x8907\n"  /* bt 0x0603595C */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x8B40\n"  /* bf 0x060359D2 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8B3E\n"  /* bf 0x060359D2 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B3C\n"  /* bf 0x060359D2 */
    ".word 0xA03F\n"  /* bra 0x060359DA */
    ".word 0x0009\n"  /* nop */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8B3C\n"  /* bf 0x060359DA */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B3A\n"  /* bf 0x060359DA */
    ".word 0xA035\n"  /* bra 0x060359D2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8B36\n"  /* bf 0x060359DA */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B34\n"  /* bf 0x060359DA */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x8B2E\n"  /* bf 0x060359D2 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B2C\n"  /* bf 0x060359D2 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B2A\n"  /* bf 0x060359D2 */
    ".word 0xA02D\n"  /* bra 0x060359DA */
    ".word 0x0009\n"  /* nop */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B03\n"  /* bf 0x0603598C */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8B01\n"  /* bf 0x0603598C */
    ".word 0xA01E\n"  /* bra 0x060359C8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD066\n"  /* mov.l @(0x198,PC),r0  {[0x06035B28] = 0x00100000} */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x3403\n"  /* cmp/ge r0,r4 */
    ".word 0x8904\n"  /* bt 0x060359A0 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x4424\n"  /* .word 0x4424 */
    ".word 0x3403\n"  /* cmp/ge r0,r4 */
    ".word 0x8FFB\n"  /* bf/s 0x06035996 */
    ".word 0x78FF\n"  /* add #-1,r8 */
    ".word 0xA04B\n"  /* bra 0x06035A3A */
    ".word 0x0009\n"  /* nop */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8B03\n"  /* bf 0x060359B0 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8B01\n"  /* bf 0x060359B0 */
    ".word 0xA00C\n"  /* bra 0x060359C8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD05D\n"  /* mov.l @(0x174,PC),r0  {[0x06035B28] = 0x00100000} */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4624\n"  /* .word 0x4624 */
    ".word 0x3603\n"  /* cmp/ge r0,r6 */
    ".word 0x8904\n"  /* bt 0x060359C4 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x4624\n"  /* .word 0x4624 */
    ".word 0x3603\n"  /* cmp/ge r0,r6 */
    ".word 0x8FFB\n"  /* bf/s 0x060359BA */
    ".word 0x79FF\n"  /* add #-1,r9 */
    ".word 0xA03B\n"  /* bra 0x06035A3E */
    ".word 0x0009\n"  /* nop */
    ".word 0x4A00\n"  /* shll r10 */
    ".word 0x0129\n"  /* .word 0x0129 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xA091\n"  /* bra 0x06035AF4 */
    ".word 0x4105\n"  /* rotr r1 */
    ".global _FUN_060359d2\n"
    "_FUN_060359d2:\n"
    ".word 0xD853\n"  /* mov.l @(0x14C,PC),r8  {[0x06035B20] = 0x000007FF} */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0xA07E\n"  /* bra 0x06035AD6 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".global _FUN_060359da\n"
    "_FUN_060359da:\n"
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0xD850\n"  /* mov.l @(0x140,PC),r8  {[0x06035B20] = 0x000007FF} */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0xA079\n"  /* bra 0x06035AD6 */
    ".word 0xE008\n"  /* mov #8,r0 */
    ".global _FUN_060359e4\n"
    "_FUN_060359e4:\n"
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x54F7\n"  /* mov.l @(0x1C,r15),r4 */
    ".word 0x55F8\n"  /* mov.l @(0x20,r15),r5 */
    ".word 0x56F9\n"  /* mov.l @(0x24,r15),r6 */
    ".word 0x57FA\n"  /* mov.l @(0x28,r15),r7 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06035A08, \"ax\"\n"

    ".global _FUN_06035A08\n"
    ".type _FUN_06035A08, @function\n"
    "_FUN_06035A08:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x4F02\n"  /* sts.l mach,@-r15 */
    ".word 0xD344\n"  /* mov.l @(0x110,PC),r3  {[0x06035B20] = 0x000007FF} */
    ".word 0xD044\n"  /* mov.l @(0x110,PC),r0  {[0x06035B24] = 0x000FFFFF} */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x2A6A\n"  /* xor r6,r10 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x4829\n"  /* shlr16 r8 */
    ".word 0x4809\n"  /* shlr2 r8 */
    ".word 0x4809\n"  /* shlr2 r8 */
    ".word 0x2839\n"  /* and r3,r8 */
    ".word 0x6963\n"  /* mov r6,r9 */
    ".word 0x4929\n"  /* shlr16 r9 */
    ".word 0x4909\n"  /* shlr2 r9 */
    ".word 0x4909\n"  /* shlr2 r9 */
    ".word 0x2939\n"  /* and r3,r9 */
    ".word 0x2409\n"  /* and r0,r4 */
    ".word 0x2609\n"  /* and r0,r6 */
    ".word 0x3830\n"  /* cmp/eq r3,r8 */
    ".word 0x8986\n"  /* bt 0x06035940 */
    ".word 0x3930\n"  /* cmp/eq r3,r9 */
    ".word 0x8998\n"  /* bt 0x06035968 */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x89A2\n"  /* bt 0x06035980 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x89B2\n"  /* bt 0x060359A4 */
    ".word 0xD23C\n"  /* mov.l @(0xF0,PC),r2  {[0x06035B30] = 0x000003FF} */
    ".word 0x389C\n"  /* add r9,r8 */
    ".word 0x3828\n"  /* sub r2,r8 */
    ".word 0x3833\n"  /* cmp/ge r3,r8 */
    ".word 0x89C4\n"  /* bt 0x060359D2 */
    ".word 0xE3CB\n"  /* mov #-53,r3 */
    ".word 0x3387\n"  /* cmp/gt r8,r3 */
    ".word 0x89BC\n"  /* bt 0x060359C8 */
    ".word 0xD036\n"  /* mov.l @(0xD8,PC),r0  {[0x06035B28] = 0x00100000} */
    ".word 0x240B\n"  /* or r0,r4 */
    ".word 0x260B\n"  /* or r0,r6 */
    ".word 0x3755\n"  /* dmulu.l r5,r7 */
    ".word 0x020A\n"  /* sts mach,r2 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x3645\n"  /* dmulu.l r4,r6 */
    ".word 0x090A\n"  /* sts mach,r9 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x3745\n"  /* dmulu.l r4,r7 */
    ".word 0x040A\n"  /* sts mach,r4 */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x3655\n"  /* dmulu.l r5,r6 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x372E\n"  /* .word 0x372E */
    ".word 0x364E\n"  /* .word 0x364E */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x307E\n"  /* .word 0x307E */
    ".word 0x316E\n"  /* .word 0x316E */
    ".word 0x392E\n"  /* .word 0x392E */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8900\n"  /* bt 0x06035A80 */
    ".word 0xCB01\n"  /* or #0x01,r0 */
    ".word 0x230D\n"  /* .word 0x230D */
    ".word 0x201D\n"  /* .word 0x201D */
    ".word 0x219D\n"  /* .word 0x219D */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4025\n"  /* .word 0x4025 */
    ".word 0x4325\n"  /* .word 0x4325 */
    ".word 0xD527\n"  /* mov.l @(0x9C,PC),r5  {[0x06035B2C] = 0x01000000} */
    ".word 0x2518\n"  /* tst r1,r5 */
    ".word 0x8908\n"  /* bt 0x06035AA4 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4025\n"  /* .word 0x4025 */
    ".word 0x4325\n"  /* .word 0x4325 */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0xD421\n"  /* mov.l @(0x84,PC),r4  {[0x06035B20] = 0x000007FF} */
    ".word 0x3840\n"  /* cmp/eq r4,r8 */
    ".word 0x8B01\n"  /* bf 0x06035AA4 */
    ".word 0xAF97\n"  /* bra 0x060359D2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8900\n"  /* bt 0x06035AAA */
    ".word 0xCB01\n"  /* or #0x01,r0 */
    ".word 0x4815\n"  /* cmp/pl r8 */
    ".word 0x8907\n"  /* bt 0x06035ABE */
    ".word 0x688B\n"  /* neg r8,r8 */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4025\n"  /* .word 0x4025 */
    ".word 0x0329\n"  /* .word 0x0329 */
    ".word 0x4810\n"  /* dt r8 */
    ".word 0x8FFA\n"  /* bf/s 0x06035AB2 */
    ".word 0x203B\n"  /* or r3,r0 */
    ".word 0xC804\n"  /* tst #0x04,r0 */
    ".word 0x8909\n"  /* bt 0x06035AD6 */
    ".word 0xC80B\n"  /* tst #0x0B,r0 */
    ".word 0x8907\n"  /* bt 0x06035AD6 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x304E\n"  /* .word 0x304E */
    ".word 0x312E\n"  /* .word 0x312E */
    ".word 0x3517\n"  /* cmp/gt r1,r5 */
    ".word 0x8902\n"  /* bt 0x06035AD6 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4025\n"  /* .word 0x4025 */
    ".word 0x7801\n"  /* add #1,r8 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4025\n"  /* .word 0x4025 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4025\n"  /* .word 0x4025 */
    ".word 0x4101\n"  /* shlr r1 */
    ".word 0x4025\n"  /* .word 0x4025 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x06035B24] = 0x000FFFFF} */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0x4828\n"  /* shll16 r8 */
    ".word 0x4808\n"  /* shll2 r8 */
    ".word 0x4808\n"  /* shll2 r8 */
    ".word 0x218B\n"  /* or r8,r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x4A00\n"  /* shll r10 */
    ".word 0x4125\n"  /* .word 0x4125 */
    ".word 0x4F06\n"  /* lds.l @r15+,mach */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x56F6\n"  /* mov.l @(0x18,r15),r6 */
    ".word 0x2612\n"  /* mov.l r1,@r6 */
    ".word 0x1601\n"  /* mov.l r0,@(0x4,r6) */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x07FF\n"  /* mac.l @r15+,@r7+ */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".global _FUN_06035b34\n"
    "_FUN_06035b34:\n"
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x55F7\n"  /* mov.l @(0x1C,r15),r5 */
    ".word 0x56F4\n"  /* mov.l @(0x10,r15),r6 */
    ".word 0x57F5\n"  /* mov.l @(0x14,r15),r7 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x06035BC0] = 0x7FF00000} */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x6B63\n"  /* mov r6,r11 */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x2809\n"  /* and r0,r8 */
    ".word 0x6963\n"  /* mov r6,r9 */
    ".word 0x2909\n"  /* and r0,r9 */
    ".word 0xD01A\n"  /* mov.l @(0x68,PC),r0  {[0x06035BC4] = 0x000FFFFF} */
    ".word 0x2409\n"  /* and r0,r4 */
    ".word 0x2609\n"  /* and r0,r6 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x06035BC0] = 0x7FF00000} */
    ".word 0x3800\n"  /* cmp/eq r0,r8 */
    ".word 0x8914\n"  /* bt 0x06035B90 */
    ".word 0x3900\n"  /* cmp/eq r0,r9 */
    ".word 0x8918\n"  /* bt 0x06035B9C */
    ".word 0x2888\n"  /* tst r8,r8 */
    ".word 0x891C\n"  /* bt 0x06035BA8 */
    ".word 0x3BA0\n"  /* cmp/eq r10,r11 */
    ".word 0x8B03\n"  /* bf 0x06035B7A */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x8B01\n"  /* bf 0x06035B7A */
    ".word 0xA001\n"  /* bra 0x06035B7C */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8BF2\n"  /* bf 0x06035B7A */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8BF0\n"  /* bf 0x06035B7A */
    ".word 0xAFE5\n"  /* bra 0x06035B66 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8BEC\n"  /* bf 0x06035B7A */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8BEA\n"  /* bf 0x06035B7A */
    ".word 0xAFE1\n"  /* bra 0x06035B6A */
    ".word 0x0009\n"  /* nop */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x8BE6\n"  /* bf 0x06035B7A */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8BDE\n"  /* bf 0x06035B6E */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8BDC\n"  /* bf 0x06035B6E */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8BE0\n"  /* bf 0x06035B7A */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8BDE\n"  /* bf 0x06035B7A */
    ".word 0xAFDE\n"  /* bra 0x06035B7C */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".global _FUN_06035bc8\n"
    "_FUN_06035bc8:\n"
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8915\n"  /* bt 0x06035BFC */
    ".word 0xD10C\n"  /* mov.l @(0x30,PC),r1  {[0x06035C04] = 0x0000041F} */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x8FFD\n"  /* bf/s 0x06035BD2 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x4228\n"  /* shll16 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4019\n"  /* shlr8 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4128\n"  /* shll16 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x51F2\n"  /* mov.l @(0x8,r15),r1 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x1121\n"  /* mov.l r2,@(0x4,r1) */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xAFF6\n"  /* bra 0x06035BEE */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x041F\n"  /* mac.l @r1+,@r4+ */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036148, \"ax\"\n"

    ".global _FUN_06036148\n"
    ".type _FUN_06036148, @function\n"
    "_FUN_06036148:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x060361AC] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE330\n"  /* mov #48,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x060361B0] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036172, \"ax\"\n"

    ".global _FUN_06036172\n"
    ".type _FUN_06036172, @function\n"
    "_FUN_06036172:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x060361AC] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE331\n"  /* mov #49,r3 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x060361B4] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8424\n"  /* mov.b @(0x4,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060361B8, \"ax\"\n"

    ".global _FUN_060361B8\n"
    ".type _FUN_060361B8, @function\n"
    "_FUN_060361B8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060361BC, \"ax\"\n"

    ".global _FUN_060361BC\n"
    ".type _FUN_060361BC, @function\n"
    "_FUN_060361BC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x060361F4] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE332\n"  /* mov #50,r3 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x060361F8] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8424\n"  /* mov.b @(0x4,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036208, \"ax\"\n"

    ".global _FUN_06036208\n"
    ".type _FUN_06036208, @function\n"
    "_FUN_06036208:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x06036298] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x22E2\n"  /* mov.l r14,@r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0xE240\n"  /* mov #64,r2 */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x13C1\n"  /* mov.l r12,@(0x4,r3) */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0603629C] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603623E, \"ax\"\n"

    ".global _FUN_0603623E\n"
    ".type _FUN_0603623E, @function\n"
    "_FUN_0603623E:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6E63\n"  /* mov r6,r14 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6D53\n"  /* mov r5,r13 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036248, \"ax\"\n"

    ".global _FUN_06036248\n"
    ".type _FUN_06036248, @function\n"
    "_FUN_06036248:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06036298] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE341\n"  /* mov #65,r3 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x060362A0] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x060362A4] = 0x00FFFFFF} */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x5321\n"  /* mov.l @(0x4,r2),r3 */
    ".word 0xD207\n"  /* mov.l @(0x1C,PC),r2  {[0x060362A4] = 0x00FFFFFF} */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060362B0, \"ax\"\n"

    ".global _FUN_060362B0\n"
    ".type _FUN_060362B0, @function\n"
    "_FUN_060362B0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x06036374] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE342\n"  /* mov #66,r3 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x84E1\n"  /* mov.b @(0x1,r14),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x84E2\n"  /* mov.b @(0x2,r14),r0 */
    ".word 0x8032\n"  /* mov.b r0,@(0x2,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x84E4\n"  /* mov.b @(0x4,r14),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x8033\n"  /* mov.b r0,@(0x3,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8035\n"  /* mov.b r0,@(0x5,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x84E3\n"  /* mov.b @(0x3,r14),r0 */
    ".word 0x8036\n"  /* mov.b r0,@(0x6,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x84E5\n"  /* mov.b @(0x5,r14),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x8037\n"  /* mov.b r0,@(0x7,r3) */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06036378] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036308, \"ax\"\n"

    ".global _FUN_06036308\n"
    ".type _FUN_06036308, @function\n"
    "_FUN_06036308:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D43\n"  /* mov r4,r13 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036310, \"ax\"\n"

    ".global _FUN_06036310\n"
    ".type _FUN_06036310, @function\n"
    "_FUN_06036310:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06036374] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE343\n"  /* mov #67,r3 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0603637C] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8421\n"  /* mov.b @(0x1,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x80E1\n"  /* mov.b r0,@(0x1,r14) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8432\n"  /* mov.b @(0x2,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x80E2\n"  /* mov.b r0,@(0x2,r14) */
    ".word 0x8433\n"  /* mov.b @(0x3,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x80E4\n"  /* mov.b r0,@(0x4,r14) */
    ".word 0x8435\n"  /* mov.b @(0x5,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0x8436\n"  /* mov.b @(0x6,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x80E3\n"  /* mov.b r0,@(0x3,r14) */
    ".word 0x8437\n"  /* mov.b @(0x7,r3),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x80E5\n"  /* mov.b r0,@(0x5,r14) */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036388, \"ax\"\n"

    ".global _FUN_06036388\n"
    ".type _FUN_06036388, @function\n"
    "_FUN_06036388:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06036408] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE344\n"  /* mov #68,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0603640C] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060363C4, \"ax\"\n"

    ".global _FUN_060363C4\n"
    ".type _FUN_060363C4, @function\n"
    "_FUN_060363C4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06036408] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE345\n"  /* mov #69,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06036410] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8421\n"  /* mov.b @(0x1,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036424, \"ax\"\n"

    ".global _FUN_06036424\n"
    ".type _FUN_06036424, @function\n"
    "_FUN_06036424:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD327\n"  /* mov.l @(0x9C,PC),r3  {[0x060364C8] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE346\n"  /* mov #70,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x6BBC\n"  /* extu.b r11,r11 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0x60B3\n"  /* mov r11,r0 */
    ".word 0x8032\n"  /* mov.b r0,@(0x2,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8033\n"  /* mov.b r0,@(0x3,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x060364CC] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603646C, \"ax\"\n"

    ".global _FUN_0603646C\n"
    ".type _FUN_0603646C, @function\n"
    "_FUN_0603646C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6C53\n"  /* mov r5,r12 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036478, \"ax\"\n"

    ".global _FUN_06036478\n"
    ".type _FUN_06036478, @function\n"
    "_FUN_06036478:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x060364C8] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE347\n"  /* mov #71,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x060364D0] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8422\n"  /* mov.b @(0x2,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8433\n"  /* mov.b @(0x3,r3),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2D22\n"  /* mov.l r2,@r13 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060364DC, \"ax\"\n"

    ".global _FUN_060364DC\n"
    ".type _FUN_060364DC, @function\n"
    "_FUN_060364DC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06036510] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE348\n"  /* mov #72,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x06036514] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036524, \"ax\"\n"

    ".global _FUN_06036524\n"
    ".type _FUN_06036524, @function\n"
    "_FUN_06036524:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x060365BC] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE350\n"  /* mov #80,r3 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x060365C0] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8521\n"  /* mov.w @(0x2,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8434\n"  /* mov.b @(0x4,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2C22\n"  /* mov.l r2,@r12 */
    ".word 0x8533\n"  /* mov.w @(0x6,r3),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2D22\n"  /* mov.l r2,@r13 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036578, \"ax\"\n"

    ".global _FUN_06036578\n"
    ".type _FUN_06036578, @function\n"
    "_FUN_06036578:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6D53\n"  /* mov r5,r13 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x060365BC] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE351\n"  /* mov #81,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x060365C0] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8523\n"  /* mov.w @(0x6,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060365D0, \"ax\"\n"

    ".global _FUN_060365D0\n"
    ".type _FUN_060365D0, @function\n"
    "_FUN_060365D0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06036644] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE352\n"  /* mov #82,r3 */
    ".word 0x6EED\n"  /* extu.w r14,r14 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x6DDD\n"  /* extu.w r13,r13 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8121\n"  /* mov.w r0,@(0x2,r2) */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06036648] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603667E, \"ax\"\n"

    ".global _FUN_0603667E\n"
    ".type _FUN_0603667E, @function\n"
    "_FUN_0603667E:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6E63\n"  /* mov r6,r14 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6D53\n"  /* mov r5,r13 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036688, \"ax\"\n"

    ".global _FUN_06036688\n"
    ".type _FUN_06036688, @function\n"
    "_FUN_06036688:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x060366FC] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE354\n"  /* mov #84,r3 */
    ".word 0x6DDD\n"  /* extu.w r13,r13 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x8121\n"  /* mov.w r0,@(0x2,r2) */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x060366F8] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x06036700] = 0x00FFFFFF} */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8424\n"  /* mov.b @(0x4,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x80E4\n"  /* mov.b r0,@(0x4,r14) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8435\n"  /* mov.b @(0x5,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x80E5\n"  /* mov.b r0,@(0x5,r14) */
    ".word 0x8436\n"  /* mov.b @(0x6,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x80E6\n"  /* mov.b r0,@(0x6,r14) */
    ".word 0x8437\n"  /* mov.b @(0x7,r3),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x80E7\n"  /* mov.b r0,@(0x7,r14) */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C4E\n"  /* mov.l @(0x38,r4),r12 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036704, \"ax\"\n"

    ".global _FUN_06036704\n"
    ".type _FUN_06036704, @function\n"
    "_FUN_06036704:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6C63\n"  /* mov r6,r12 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036710, \"ax\"\n"

    ".global _FUN_06036710\n"
    ".type _FUN_06036710, @function\n"
    "_FUN_06036710:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x060367A0] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE355\n"  /* mov #85,r3 */
    ".word 0x6EED\n"  /* extu.w r14,r14 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8121\n"  /* mov.w r0,@(0x2,r2) */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x13C1\n"  /* mov.l r12,@(0x4,r3) */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x060367A4] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603674A, \"ax\"\n"

    ".global _FUN_0603674A\n"
    ".type _FUN_0603674A, @function\n"
    "_FUN_0603674A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6E63\n"  /* mov r6,r14 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6D53\n"  /* mov r5,r13 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036754, \"ax\"\n"

    ".global _FUN_06036754\n"
    ".type _FUN_06036754, @function\n"
    "_FUN_06036754:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x060367A0] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE356\n"  /* mov #86,r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xBF6F\n"  /* bsr 0x06036650 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8521\n"  /* mov.w @(0x2,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8434\n"  /* mov.b @(0x4,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2C22\n"  /* mov.l r2,@r12 */
    ".word 0x5231\n"  /* mov.l @(0x4,r3),r2 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x060367A8] = 0x00FFFFFF} */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060367AC, \"ax\"\n"

    ".global _FUN_060367AC\n"
    ".type _FUN_060367AC, @function\n"
    "_FUN_060367AC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D53\n"  /* mov r5,r13 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060367B4, \"ax\"\n"

    ".global _FUN_060367B4\n"
    ".type _FUN_060367B4, @function\n"
    "_FUN_060367B4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06036834] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE360\n"  /* mov #96,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8032\n"  /* mov.b r0,@(0x2,r3) */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06036838] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE440\n"  /* mov #64,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060367F4, \"ax\"\n"

    ".global _FUN_060367F4\n"
    ".type _FUN_060367F4, @function\n"
    "_FUN_060367F4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06036834] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE361\n"  /* mov #97,r3 */
    ".word 0x6EED\n"  /* extu.w r14,r14 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x6DDD\n"  /* extu.w r13,r13 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8121\n"  /* mov.w r0,@(0x2,r2) */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x9409\n"  /* mov.w @(0x12,PC),r4 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06036838] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036848, \"ax\"\n"

    ".global _FUN_06036848\n"
    ".type _FUN_06036848, @function\n"
    "_FUN_06036848:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x060368D4] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE362\n"  /* mov #98,r3 */
    ".word 0x6EED\n"  /* extu.w r14,r14 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x6DDD\n"  /* extu.w r13,r13 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8121\n"  /* mov.w r0,@(0x2,r2) */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x942E\n"  /* mov.w @(0x5C,PC),r4 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x060368D8] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036886, \"ax\"\n"

    ".global _FUN_06036886\n"
    ".type _FUN_06036886, @function\n"
    "_FUN_06036886:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6D63\n"  /* mov r6,r13 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036890, \"ax\"\n"

    ".global _FUN_06036890\n"
    ".type _FUN_06036890, @function\n"
    "_FUN_06036890:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x060368D4] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE363\n"  /* mov #99,r3 */
    ".word 0x6EED\n"  /* extu.w r14,r14 */
    ".word 0x6CCC\n"  /* extu.b r12,r12 */
    ".word 0x6DDD\n"  /* extu.w r13,r13 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8121\n"  /* mov.w r0,@(0x2,r2) */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x9409\n"  /* mov.w @(0x12,PC),r4 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x060368D8] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060368DC, \"ax\"\n"

    ".global _FUN_060368DC\n"
    ".type _FUN_060368DC, @function\n"
    "_FUN_060368DC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D53\n"  /* mov r5,r13 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060368E4, \"ax\"\n"

    ".global _FUN_060368E4\n"
    ".type _FUN_060368E4, @function\n"
    "_FUN_060368E4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x06036974] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE364\n"  /* mov #100,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x6DDD\n"  /* extu.w r13,r13 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x9434\n"  /* mov.w @(0x68,PC),r4 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x06036978] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036918, \"ax\"\n"

    ".global _FUN_06036918\n"
    ".type _FUN_06036918, @function\n"
    "_FUN_06036918:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E73\n"  /* mov r7,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6C63\n"  /* mov r6,r12 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x6B53\n"  /* mov r5,r11 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036928, \"ax\"\n"

    ".global _FUN_06036928\n"
    ".type _FUN_06036928, @function\n"
    "_FUN_06036928:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06036974] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE365\n"  /* mov #101,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x6BBD\n"  /* extu.w r11,r11 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x6CCD\n"  /* extu.w r12,r12 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0x60B3\n"  /* mov r11,r0 */
    ".word 0x8131\n"  /* mov.w r0,@(0x2,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x940B\n"  /* mov.w @(0x16,PC),r4 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06036978] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603698C, \"ax\"\n"

    ".global _FUN_0603698C\n"
    ".type _FUN_0603698C, @function\n"
    "_FUN_0603698C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06036A10] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE366\n"  /* mov #102,r3 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0x6BBD\n"  /* extu.w r11,r11 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x6CCD\n"  /* extu.w r12,r12 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0x60B3\n"  /* mov r11,r0 */
    ".word 0x8131\n"  /* mov.w r0,@(0x2,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x9427\n"  /* mov.w @(0x4E,PC),r4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06036A14] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060369D4, \"ax\"\n"

    ".global _FUN_060369D4\n"
    ".type _FUN_060369D4, @function\n"
    "_FUN_060369D4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_060369D8, \"ax\"\n"

    ".global _FUN_060369D8\n"
    ".type _FUN_060369D8, @function\n"
    "_FUN_060369D8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x06036A10] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE367\n"  /* mov #103,r3 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06036A18] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8421\n"  /* mov.b @(0x1,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036A24, \"ax\"\n"

    ".global _FUN_06036A24\n"
    ".type _FUN_06036A24, @function\n"
    "_FUN_06036A24:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06036A90] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE370\n"  /* mov #112,r3 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x12E1\n"  /* mov.l r14,@(0x4,r2) */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x9424\n"  /* mov.w @(0x48,PC),r4 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06036A94] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036A54, \"ax\"\n"

    ".global _FUN_06036A54\n"
    ".type _FUN_06036A54, @function\n"
    "_FUN_06036A54:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D43\n"  /* mov r4,r13 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036A5C, \"ax\"\n"

    ".global _FUN_06036A5C\n"
    ".type _FUN_06036A5C, @function\n"
    "_FUN_06036A5C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06036A90] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE371\n"  /* mov #113,r3 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x12E1\n"  /* mov.l r14,@(0x4,r2) */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0x9408\n"  /* mov.w @(0x10,PC),r4 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06036A94] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036AA4, \"ax\"\n"

    ".global _FUN_06036AA4\n"
    ".type _FUN_06036AA4, @function\n"
    "_FUN_06036AA4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06036B38] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE372\n"  /* mov #114,r3 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06036B3C] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x8521\n"  /* mov.w @(0x2,r2),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x8434\n"  /* mov.b @(0x4,r3),r0 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x2C22\n"  /* mov.l r2,@r12 */
    ".word 0x5231\n"  /* mov.l @(0x4,r3),r2 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06036B40] = 0x00FFFFFF} */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036AF8, \"ax\"\n"

    ".global _FUN_06036AF8\n"
    ".type _FUN_06036AF8, @function\n"
    "_FUN_06036AF8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6D53\n"  /* mov r5,r13 */
    ".word 0x7FEC\n"  /* add #-20,r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06036B38] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE373\n"  /* mov #115,r3 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x720C\n"  /* add #12,r2 */
    ".word 0x7604\n"  /* add #4,r6 */
    ".word 0x750C\n"  /* add #12,r5 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x720C\n"  /* add #12,r2 */
    ".word 0x730C\n"  /* add #12,r3 */
    ".word 0x12E1\n"  /* mov.l r14,@(0x4,r2) */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8034\n"  /* mov.b r0,@(0x4,r3) */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x06036B3C] = 0x06035EA2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8908\n"  /* bt 0x06036B44 */
    ".word 0xA012\n"  /* bra 0x06036B5A */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EA2 */
    ".word 0x5EA2\n"  /* mov.l @(0x8,r10),r14 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06036BD0] = 0x00FFFFFF} */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06036BD4] = 0x06035CBC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036B64, \"ax\"\n"

    ".global _FUN_06036B64\n"
    ".type _FUN_06036B64, @function\n"
    "_FUN_06036B64:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E63\n"  /* mov r6,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6C53\n"  /* mov r5,r12 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036B70, \"ax\"\n"

    ".global _FUN_06036B70\n"
    ".type _FUN_06036B70, @function\n"
    "_FUN_06036B70:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06036BD8] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x22E2\n"  /* mov.l r14,@r2 */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0xE274\n"  /* mov #116,r2 */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x13C1\n"  /* mov.l r12,@(0x4,r3) */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0x941D\n"  /* mov.w @(0x3A,PC),r4 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06036BDC] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06036BA6, \"ax\"\n"

    ".global _FUN_06036BA6\n"
    ".type _FUN_06036BA6, @function\n"
    "_FUN_06036BA6:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06036BD8] = 0x06035E90} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xE375\n"  /* mov #117,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x940A\n"  /* mov.w @(0x14,PC),r4 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06036BE0] = 0x06035C92} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9406\n"  /* mov.w @(0xC,PC),r4 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06036BDC] = 0x06035EC8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035CBC */
    ".word 0x5CBC\n"  /* mov.l @(0x30,r11),r12 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035E90 */
    ".word 0x5E90\n"  /* mov.l @(0x0,r9),r14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035EC8 */
    ".word 0x5EC8\n"  /* mov.l @(0x20,r12),r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C92\n"  /* mov.l @(0x8,r9),r12 */
    ".global _FUN_06036be4\n"
    "_FUN_06036be4:\n"
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x8955\n"  /* bt 0x06036C96 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2127\n"  /* .word 0x2127 */
    ".word 0x0429\n"  /* .word 0x0429 */
    ".word 0x333A\n"  /* .word 0x333A */
    ".word 0x312A\n"  /* .word 0x312A */
    ".word 0x2307\n"  /* .word 0x2307 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x4124\n"  /* .word 0x4124 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x2327\n"  /* .word 0x2327 */
    ".word 0x0229\n"  /* .word 0x0229 */
    ".word 0x224A\n"  /* xor r4,r2 */
    ".word 0x4225\n"  /* .word 0x4225 */
    ".word 0x8B02\n"  /* bf 0x06036C8A */
    ".word 0x2307\n"  /* .word 0x2307 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x3304\n"  /* .word 0x3304 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xD103\n"  /* mov.l @(0xC,PC),r1  {[0x06036CA4] = 0x060A246C} */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x06036CA8] = 0x0000044E} */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x246C\n"  /* .word 0x246C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".global _FUN_06036cb0\n"
    "_FUN_06036cb0:\n"
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x6416\n"  /* mov.l @r1+,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x264C\n"  /* .word 0x264C */
    ".word 0x6516\n"  /* mov.l @r1+,r5 */
    ".word 0x8913\n"  /* bt 0x06036CE8 */
    ".word 0x2042\n"  /* mov.l r4,@r0 */
    ".word 0x265C\n"  /* .word 0x265C */
    ".word 0x6416\n"  /* mov.l @r1+,r4 */
    ".word 0x890A\n"  /* bt 0x06036CDE */
    ".word 0x1051\n"  /* mov.l r5,@(0x4,r0) */
    ".word 0x264C\n"  /* .word 0x264C */
    ".word 0x6516\n"  /* mov.l @r1+,r5 */
    ".word 0x8908\n"  /* bt 0x06036CE2 */
    ".word 0x1042\n"  /* mov.l r4,@(0x8,r0) */
    ".word 0x265C\n"  /* .word 0x265C */
    ".word 0x6416\n"  /* mov.l @r1+,r4 */
    ".word 0x8906\n"  /* bt 0x06036CE6 */
    ".word 0x1053\n"  /* mov.l r5,@(0xC,r0) */
    ".word 0xAFEE\n"  /* bra 0x06036CBA */
    ".word 0x7010\n"  /* add #16,r0 */
    ".word 0xA003\n"  /* bra 0x06036CE8 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0xA001\n"  /* bra 0x06036CE8 */
    ".word 0x7008\n"  /* add #8,r0 */
    ".word 0x700C\n"  /* add #12,r0 */
    ".word 0x71F8\n"  /* add #-8,r1 */
    ".word 0x6603\n"  /* mov r0,r6 */
    ".word 0x6014\n"  /* mov.b @r1+,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x2600\n"  /* mov.b r0,@r6 */
    ".word 0x8909\n"  /* bt 0x06036D08 */
    ".word 0x6014\n"  /* mov.b @r1+,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8061\n"  /* mov.b r0,@(0x1,r6) */
    ".word 0x8905\n"  /* bt 0x06036D08 */
    ".word 0x6014\n"  /* mov.b @r1+,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8062\n"  /* mov.b r0,@(0x2,r6) */
    ".word 0x8901\n"  /* bt 0x06036D08 */
    ".word 0x6014\n"  /* mov.b @r1+,r0 */
    ".word 0x8063\n"  /* mov.b r0,@(0x3,r6) */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".global _FUN_06036d14\n"
    "_FUN_06036d14:\n"
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2439\n"  /* and r3,r4 */
    ".word 0x2319\n"  /* and r1,r3 */
    ".word 0x234B\n"  /* or r4,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8922\n"  /* bt 0x06036D6C */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x6304\n"  /* mov.b @r0+,r3 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x6414\n"  /* mov.b @r1+,r4 */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x8916\n"  /* bt 0x06036D60 */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8B14\n"  /* bf 0x06036D60 */
    ".word 0x6304\n"  /* mov.b @r0+,r3 */
    ".word 0x6414\n"  /* mov.b @r1+,r4 */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x8910\n"  /* bt 0x06036D60 */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8B0E\n"  /* bf 0x06036D60 */
    ".word 0x6304\n"  /* mov.b @r0+,r3 */
    ".word 0x6414\n"  /* mov.b @r1+,r4 */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x890A\n"  /* bt 0x06036D60 */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8B08\n"  /* bf 0x06036D60 */
    ".word 0x6304\n"  /* mov.b @r0+,r3 */
    ".word 0x6414\n"  /* mov.b @r1+,r4 */
    ".word 0x3350\n"  /* cmp/eq r5,r3 */
    ".word 0x8904\n"  /* bt 0x06036D60 */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8B02\n"  /* bf 0x06036D60 */
    ".word 0x6304\n"  /* mov.b @r0+,r3 */
    ".word 0xAFE7\n"  /* bra 0x06036D2E */
    ".word 0x6414\n"  /* mov.b @r1+,r4 */
    ".word 0x3348\n"  /* sub r4,r3 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0xD301\n"  /* mov.l @(0x4,PC),r3  {[0x06036D74] = 0x06036E1C} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x6E1C\n"  /* extu.b r1,r14 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x6373\n"  /* mov r7,r3 */
    ".word 0x3362\n"  /* cmp/hs r6,r3 */
    ".word 0x8D06\n"  /* bt/s 0x06036D8E */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x625C\n"  /* extu.b r5,r2 */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0x2020\n"  /* mov.b r2,@r0 */
    ".word 0x3762\n"  /* cmp/hs r6,r7 */
    ".word 0x8FFA\n"  /* bf/s 0x06036D82 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".global _FUN_06036d94\n"
    "_FUN_06036d94:\n"
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8F02\n"  /* bf/s 0x06036D9E */
    ".word 0x6753\n"  /* mov r5,r7 */
    ".word 0x000B\n"  /* rts */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x3362\n"  /* cmp/hs r6,r3 */
    ".word 0x8910\n"  /* bt 0x06036DC8 */
    ".word 0x6244\n"  /* mov.b @r4+,r2 */
    ".word 0x6174\n"  /* mov.b @r7+,r1 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x3210\n"  /* cmp/eq r1,r2 */
    ".word 0x8B0A\n"  /* bf 0x06036DC8 */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x6320\n"  /* mov.b @r2,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B01\n"  /* bf 0x06036DC2 */
    ".word 0xA003\n"  /* bra 0x06036DC8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7501\n"  /* add #1,r5 */
    ".word 0x3562\n"  /* cmp/hs r6,r5 */
    ".word 0x8BEE\n"  /* bf 0x06036DA6 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x77FF\n"  /* add #-1,r7 */
    ".word 0x6370\n"  /* mov.b @r7,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3038\n"  /* sub r3,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"
    ".global _vdp2_secondary_config\n"
    ".type _vdp2_secondary_config, @function\n"








    ".section .text.FUN_0603836C, \"ax\"\n"

    ".global _FUN_0603836C\n"
    "_vdp2_secondary_config:\n"
    "_FUN_0603836C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xDC46\n"  /* mov.l @(0x118,PC),r12  {[0x0603848C] = 0x0000FFFF} */
    ".word 0xED10\n"  /* mov #16,r13 */
    ".word 0xEE08\n"  /* mov #8,r14 */
    ".word 0xD745\n"  /* mov.l @(0x114,PC),r7  {[0x06038490] = 0x060A3D88} */
    ".word 0xD546\n"  /* mov.l @(0x118,PC),r5  {[0x06038494] = 0x060A3DB0} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD346\n"  /* mov.l @(0x118,PC),r3  {[0x06038498] = 0x25F80000} */
    ".word 0xD246\n"  /* mov.l @(0x118,PC),r2  {[0x0603849C] = 0x060A3D84} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD346\n"  /* mov.l @(0x118,PC),r3  {[0x060384A0] = 0x00008000} */
    ".word 0x2731\n"  /* mov.w r3,@r7 */
    ".word 0x624D\n"  /* extu.w r4,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8171\n"  /* mov.w r0,@(0x2,r7) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8173\n"  /* mov.w r0,@(0x6,r7) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8176\n"  /* mov.w r0,@(0xC,r7) */
    ".word 0x4309\n"  /* shlr2 r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8177\n"  /* mov.w r0,@(0xE,r7) */
    ".word 0x664D\n"  /* extu.w r4,r6 */
    ".word 0x636D\n"  /* extu.w r6,r3 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x61CD\n"  /* extu.w r12,r1 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x7210\n"  /* add #16,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0x636D\n"  /* extu.w r6,r3 */
    ".word 0x33E3\n"  /* cmp/ge r14,r3 */
    ".word 0x8BF4\n"  /* bf 0x0603839E */
    ".word 0xE020\n"  /* mov #32,r0 */
    ".word 0x0745\n"  /* mov.w r4,@(r0,r7) */
    ".word 0xE022\n"  /* mov #34,r0 */
    ".word 0x0745\n"  /* mov.w r4,@(r0,r7) */
    ".word 0xE024\n"  /* mov #36,r0 */
    ".word 0x0745\n"  /* mov.w r4,@(r0,r7) */
    ".word 0xE026\n"  /* mov #38,r0 */
    ".word 0x0745\n"  /* mov.w r4,@(r0,r7) */
    ".word 0x2541\n"  /* mov.w r4,@r5 */
    ".word 0x624D\n"  /* extu.w r4,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8152\n"  /* mov.w r0,@(0x4,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8153\n"  /* mov.w r0,@(0x6,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8154\n"  /* mov.w r0,@(0x8,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8155\n"  /* mov.w r0,@(0xA,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8156\n"  /* mov.w r0,@(0xC,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8157\n"  /* mov.w r0,@(0xE,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8158\n"  /* mov.w r0,@(0x10,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8159\n"  /* mov.w r0,@(0x12,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x815A\n"  /* mov.w r0,@(0x14,r5) */
    ".word 0x634D\n"  /* extu.w r4,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x815B\n"  /* mov.w r0,@(0x16,r5) */
    ".word 0x664D\n"  /* extu.w r4,r6 */
    ".word 0x636D\n"  /* extu.w r6,r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x614D\n"  /* extu.w r4,r1 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x7218\n"  /* add #24,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0x636D\n"  /* extu.w r6,r3 */
    ".word 0x33E3\n"  /* cmp/ge r14,r3 */
    ".word 0x8BF4\n"  /* bf 0x060383F8 */
    ".word 0x664D\n"  /* extu.w r4,r6 */
    ".word 0x636D\n"  /* extu.w r6,r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x614D\n"  /* extu.w r4,r1 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x7228\n"  /* add #40,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0x636D\n"  /* extu.w r6,r3 */
    ".word 0x33D3\n"  /* cmp/ge r13,r3 */
    ".word 0x8BF4\n"  /* bf 0x06038410 */
    ".word 0xD61F\n"  /* mov.l @(0x7C,PC),r6  {[0x060384A4] = 0x060A3DF8} */
    ".word 0x2642\n"  /* mov.l r4,@r6 */
    ".word 0x1641\n"  /* mov.l r4,@(0x4,r6) */
    ".word 0xD01E\n"  /* mov.l @(0x78,PC),r0  {[0x060384A8] = 0x00010000} */
    ".word 0x1602\n"  /* mov.l r0,@(0x8,r6) */
    ".word 0x1603\n"  /* mov.l r0,@(0xC,r6) */
    ".word 0x1644\n"  /* mov.l r4,@(0x10,r6) */
    ".word 0x1645\n"  /* mov.l r4,@(0x14,r6) */
    ".word 0x1606\n"  /* mov.l r0,@(0x18,r6) */
    ".word 0x1607\n"  /* mov.l r0,@(0x1C,r6) */
    ".word 0xE020\n"  /* mov #32,r0 */
    ".word 0x0645\n"  /* mov.w r4,@(r0,r6) */
    ".word 0xE022\n"  /* mov #34,r0 */
    ".word 0x0645\n"  /* mov.w r4,@(r0,r6) */
    ".word 0xE024\n"  /* mov #36,r0 */
    ".word 0x0645\n"  /* mov.w r4,@(r0,r6) */
    ".word 0xE026\n"  /* mov #38,r0 */
    ".word 0x0645\n"  /* mov.w r4,@(r0,r6) */
    ".word 0xE028\n"  /* mov #40,r0 */
    ".word 0x0645\n"  /* mov.w r4,@(r0,r6) */
    ".word 0xE02A\n"  /* mov #42,r0 */
    ".word 0x0645\n"  /* mov.w r4,@(r0,r6) */
    ".word 0x164B\n"  /* mov.l r4,@(0x2C,r6) */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x7330\n"  /* add #48,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0x164D\n"  /* mov.l r4,@(0x34,r6) */
    ".word 0x164E\n"  /* mov.l r4,@(0x38,r6) */
    ".word 0x164F\n"  /* mov.l r4,@(0x3C,r6) */
    ".word 0xD612\n"  /* mov.l @(0x48,PC),r6  {[0x060384AC] = 0x060A3E38} */
    ".word 0x2641\n"  /* mov.w r4,@r6 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8161\n"  /* mov.w r0,@(0x2,r6) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8162\n"  /* mov.w r0,@(0x4,r6) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8163\n"  /* mov.w r0,@(0x6,r6) */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x2341\n"  /* mov.w r4,@r3 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8165\n"  /* mov.w r0,@(0xA,r6) */
    ".word 0x1643\n"  /* mov.l r4,@(0xC,r6) */
    ".word 0xD60B\n"  /* mov.l @(0x2C,PC),r6  {[0x060384B0] = 0x060A3E48} */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x2341\n"  /* mov.w r4,@r3 */
    ".word 0xA014\n"  /* bra 0x060384B4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D88\n"  /* sub r8,r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3DB0\n"  /* cmp/eq r11,r13 */
    ".word 0x25F8\n"  /* tst r15,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D84\n"  /* .word 0x3D84 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3DF8\n"  /* sub r15,r13 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E38\n"  /* sub r3,r14 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E48\n"  /* sub r4,r14 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8161\n"  /* mov.w r0,@(0x2,r6) */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x2341\n"  /* mov.w r4,@r3 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8163\n"  /* mov.w r0,@(0x6,r6) */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x2341\n"  /* mov.w r4,@r3 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8165\n"  /* mov.w r0,@(0xA,r6) */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x730C\n"  /* add #12,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x2341\n"  /* mov.w r4,@r3 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8167\n"  /* mov.w r0,@(0xE,r6) */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x7310\n"  /* add #16,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x624D\n"  /* extu.w r4,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8169\n"  /* mov.w r0,@(0x12,r6) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x816A\n"  /* mov.w r0,@(0x14,r6) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x816B\n"  /* mov.w r0,@(0x16,r6) */
    ".word 0x1646\n"  /* mov.l r4,@(0x18,r6) */
    ".word 0x1647\n"  /* mov.l r4,@(0x1C,r6) */
    ".word 0xD60F\n"  /* mov.l @(0x3C,PC),r6  {[0x06038534] = 0x060635AC} */
    ".word 0x6361\n"  /* mov.w @r6,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B01\n"  /* bf 0x06038504 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2631\n"  /* mov.w r3,@r6 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xD509\n"  /* mov.l @(0x24,PC),r5  {[0x06038534] = 0x060635AC} */
    ".word 0x6051\n"  /* mov.w @r5,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B01\n"  /* bf 0x0603851A */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2521\n"  /* mov.w r2,@r5 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06038538] = 0x060635A8} */
    ".word 0x000B\n"  /* rts */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xD404\n"  /* mov.l @(0x10,PC),r4  {[0x06038534] = 0x060635AC} */
    ".word 0x6341\n"  /* mov.w @r4,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B01\n"  /* bf 0x0603852E */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2431\n"  /* mov.w r3,@r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35AC\n"  /* add r10,r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35A8\n"  /* sub r10,r5 */
    ".size _vdp2_secondary_config, .-_vdp2_secondary_config\n"
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_06038F6C, \"ax\"\n"

    ".global _FUN_06038F6C\n"
    ".type _FUN_06038F6C, @function\n"
    "_FUN_06038F6C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0xEA00\n"  /* mov #0,r10 */
);
__asm__(



    ".balign 2\n"
    ".global _vdp1_display_list_cmd\n"
    ".type _vdp1_display_list_cmd, @function\n"








    ".section .text.FUN_06038F78, \"ax\"\n"

    ".global _FUN_06038F78\n"
    "_vdp1_display_list_cmd:\n"
    "_FUN_06038F78:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDB19\n"  /* mov.l @(0x64,PC),r11  {[0x06038FE0] = 0x060389A6} */
    ".word 0xDC19\n"  /* mov.l @(0x64,PC),r12  {[0x06038FE4] = 0x060A4C84} */
    ".word 0xDD1A\n"  /* mov.l @(0x68,PC),r13  {[0x06038FE8] = 0x060635C4} */
    ".word 0xDE1A\n"  /* mov.l @(0x68,PC),r14  {[0x06038FEC] = 0x060635C0} */
    ".word 0x2CA2\n"  /* mov.l r10,@r12 */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x06038FF0] = 0x060635B4} */
    ".word 0x6041\n"  /* mov.w @r4,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B08\n"  /* bf 0x06038FA0 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8956\n"  /* bt 0x06039042 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0xA051\n"  /* bra 0x06039042 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD614\n"  /* mov.l @(0x50,PC),r6  {[0x06038FF4] = 0x060A4C92} */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x06038FF8] = 0x25D00002} */
    ".word 0x6041\n"  /* mov.w @r4,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8B11\n"  /* bf 0x06038FD0 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8947\n"  /* bt 0x06039042 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06038FFC] = 0x060A4C90} */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06039000] = 0x25D00000} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xCB08\n"  /* or #0x08,r0 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x6061\n"  /* mov.w @r6,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xCB03\n"  /* or #0x03,r0 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x2501\n"  /* mov.w r0,@r5 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0xA039\n"  /* bra 0x06039042 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B15\n"  /* bf 0x06039004 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA031\n"  /* bra 0x06039042 */
    ".word 0x2DA2\n"  /* mov.l r10,@r13 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_060389A6 */
    ".word 0x89A6\n"  /* bt 0x06038F32 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C84\n"  /* .word 0x4C84 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35C4\n"  /* .word 0x35C4 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35C0\n"  /* cmp/eq r12,r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35B4\n"  /* .word 0x35B4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C92\n"  /* .word 0x4C92 */
    ".word 0x25D0\n"  /* mov.b r13,@r5 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C90\n"  /* .word 0x4C90 */
    ".word 0x25D0\n"  /* mov.b r13,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x06039088] = 0x060635B8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B0A\n"  /* bf 0x06039028 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x0603908C] = 0x060635BC} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8904\n"  /* bt 0x06039028 */
    ".word 0x6061\n"  /* mov.w @r6,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xCB02\n"  /* or #0x02,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2501\n"  /* mov.w r0,@r5 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0603908C] = 0x060635BC} */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8907\n"  /* bt 0x06039042 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8903\n"  /* bt 0x06039040 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0x2EA2\n"  /* mov.l r10,@r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _vdp1_display_list_cmd, .-_vdp1_display_list_cmd\n"
);
__asm__(



    ".balign 2\n"
    ".global _vdp1_vblank_cmd\n"
    ".type _vdp1_vblank_cmd, @function\n"








    ".section .text.FUN_06039050, \"ax\"\n"

    ".global _FUN_06039050\n"
    "_vdp1_vblank_cmd:\n"
    "_FUN_06039050:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDC0D\n"  /* mov.l @(0x34,PC),r12  {[0x06039090] = 0x25D00002} */
    ".word 0xDD0E\n"  /* mov.l @(0x38,PC),r13  {[0x06039094] = 0x060A4C92} */
    ".word 0xDE0E\n"  /* mov.l @(0x38,PC),r14  {[0x06039098] = 0x060A4C84} */
    ".word 0xD00F\n"  /* mov.l @(0x3C,PC),r0  {[0x0603909C] = 0x060A4C94} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891D\n"  /* bt 0x060390A4 */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x060390A0] = 0x25F80004} */
    ".word 0x6441\n"  /* mov.w @r4,r4 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0xC802\n"  /* tst #0x02,r0 */
    ".word 0x8903\n"  /* bt 0x0603907A */
    ".word 0x60D1\n"  /* mov.w @r13,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xA003\n"  /* bra 0x06039080 */
    ".word 0xCB0C\n"  /* or #0x0C,r0 */
    ".word 0x60D1\n"  /* mov.w @r13,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xCB08\n"  /* or #0x08,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xA02E\n"  /* bra 0x060390E2 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35B8\n"  /* sub r11,r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35BC\n"  /* add r11,r5 */
    ".word 0x25D0\n"  /* mov.b r13,@r5 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C92\n"  /* .word 0x4C92 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C84\n"  /* .word 0x4C84 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C94\n"  /* .word 0x4C94 */
    ".word 0x25F8\n"  /* tst r15,r5 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891B\n"  /* bt 0x060390E2 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B06\n"  /* bf 0x060390BE */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x060390EC] = 0x060635CC} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8902\n"  /* bt 0x060390BE */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x060390F0] = 0x060394C2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8B05\n"  /* bf 0x060390D0 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x060390F4] = 0x060A4C90} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x060390F8] = 0x25D00000} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xA005\n"  /* bra 0x060390DA */
    ".word 0x0009\n"  /* nop */
    ".word 0x60D1\n"  /* mov.w @r13,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xCB03\n"  /* or #0x03,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2C01\n"  /* mov.w r0,@r12 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x060390FC] = 0x060635C4} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0x2E42\n"  /* mov.l r4,@r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35CC\n"  /* add r12,r5 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x94C2\n"  /* mov.w @(0x184,PC),r4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C90\n"  /* .word 0x4C90 */
    ".word 0x25D0\n"  /* mov.b r13,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35C4\n"  /* .word 0x35C4 */
    ".size _vdp1_vblank_cmd, .-_vdp1_vblank_cmd\n"
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603990E, \"ax\"\n"

    ".global _FUN_0603990E\n"
    ".type _FUN_0603990E, @function\n"
    "_FUN_0603990E:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x9813\n"  /* mov.w @(0x26,PC),r8 */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0xDA0F\n"  /* mov.l @(0x3C,PC),r10  {[0x06039964] = 0x20100061} */
    ".word 0xDB10\n"  /* mov.l @(0x40,PC),r11  {[0x06039968] = 0x060A4CF4} */
    ".word 0xDC10\n"  /* mov.l @(0x40,PC),r12  {[0x0603996C] = 0x060A4D04} */
    ".word 0xED01\n"  /* mov #1,r13 */
    ".word 0xDE10\n"  /* mov.l @(0x40,PC),r14  {[0x06039970] = 0x060A4CEC} */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xCBF0\n"  /* or #0xF0,r0 */
    ".word 0x400E\n"  /* ldc r0,sr */
    ".word 0xD00C\n"  /* mov.l @(0x30,PC),r0  {[0x06039974] = 0x060A4CAA} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0xA2EE\n"  /* bra 0x06039F26 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x00F0\n"  /* .word 0x00F0 */
    ".word 0xFF0F\n"  /* .word 0xFF0F */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CE8\n"  /* .word 0x4CE8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CC4\n"  /* .word 0x4CC4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C98\n"  /* .word 0x4C98 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CC0\n"  /* .word 0x4CC0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CBC\n"  /* .word 0x4CBC */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0061\n"  /* .word 0x0061 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CF4\n"  /* .word 0x4CF4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D04\n"  /* rotl r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CEC\n"  /* .word 0x4CEC */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAA\n"  /* .word 0x4CAA */
    ".word 0xD238\n"  /* mov.l @(0xE0,PC),r2  {[0x06039A5C] = 0x060A4C9C} */
    ".word 0xD339\n"  /* mov.l @(0xE4,PC),r3  {[0x06039A60] = 0x20100031} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD338\n"  /* mov.l @(0xE0,PC),r3  {[0x06039A64] = 0x20100033} */
    ".word 0x6030\n"  /* mov.b @r3,r0 */
    ".word 0x8021\n"  /* mov.b r0,@(0x1,r2) */
    ".word 0xD335\n"  /* mov.l @(0xD4,PC),r3  {[0x06039A5C] = 0x060A4C9C} */
    ".word 0xD237\n"  /* mov.l @(0xDC,PC),r2  {[0x06039A68] = 0x20100035} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0xD136\n"  /* mov.l @(0xD8,PC),r1  {[0x06039A6C] = 0x20100037} */
    ".word 0x6110\n"  /* mov.b @r1,r1 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x221B\n"  /* or r1,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8131\n"  /* mov.w r0,@(0x2,r3) */
    ".word 0xD234\n"  /* mov.l @(0xD0,PC),r2  {[0x06039A70] = 0x20100039} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x4228\n"  /* shll16 r2 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0xD133\n"  /* mov.l @(0xCC,PC),r1  {[0x06039A74] = 0x2010003B} */
    ".word 0x6110\n"  /* mov.b @r1,r1 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x4128\n"  /* shll16 r1 */
    ".word 0x221B\n"  /* or r1,r2 */
    ".word 0xD031\n"  /* mov.l @(0xC4,PC),r0  {[0x06039A78] = 0x2010003D} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x4018\n"  /* shll8 r0 */
    ".word 0x220B\n"  /* or r0,r2 */
    ".word 0xD130\n"  /* mov.l @(0xC0,PC),r1  {[0x06039A7C] = 0x2010003F} */
    ".word 0x6110\n"  /* mov.b @r1,r1 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x221B\n"  /* or r1,r2 */
    ".word 0x1321\n"  /* mov.l r2,@(0x4,r3) */
    ".word 0xD22E\n"  /* mov.l @(0xB8,PC),r2  {[0x06039A80] = 0x20100021} */
    ".word 0x6020\n"  /* mov.b @r2,r0 */
    ".word 0x8038\n"  /* mov.b r0,@(0x8,r3) */
    ".word 0xD22E\n"  /* mov.l @(0xB8,PC),r2  {[0x06039A84] = 0x060A4CA8} */
    ".word 0x22D0\n"  /* mov.b r13,@r2 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x0102\n"  /* stc sr,r1 */
    ".word 0x923E\n"  /* mov.w @(0x7C,PC),r2 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0x201B\n"  /* or r1,r0 */
    ".word 0x400E\n"  /* ldc r0,sr */
    ".word 0xA2DB\n"  /* bra 0x06039F9A */
    ".word 0x0009\n"  /* nop */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x06039A88] = 0x060A4CD8} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B12\n"  /* bf 0x06039A14 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x06039A8C] = 0x060A4CE8} */
    ".word 0xE207\n"  /* mov #7,r2 */
    ".word 0xD022\n"  /* mov.l @(0x88,PC),r0  {[0x06039A80] = 0x20100021} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x2310\n"  /* mov.b r1,@r3 */
    ".word 0xE307\n"  /* mov #7,r3 */
    ".word 0x3432\n"  /* cmp/hs r3,r4 */
    ".word 0x8BF2\n"  /* bf 0x060399F0 */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x06039A88] = 0x060A4CD8} */
    ".word 0x22D0\n"  /* mov.b r13,@r2 */
    ".word 0xE102\n"  /* mov #2,r1 */
    ".word 0xA295\n"  /* bra 0x06039F3E */
    ".word 0x2B10\n"  /* mov.b r1,@r11 */
    ".word 0x629C\n"  /* extu.b r9,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06039A80] = 0x20100021} */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0xA27A\n"  /* bra 0x06039F14 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x06039A90] = 0x060A4CF8} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8B01\n"  /* bf 0x06039A2C */
    ".word 0xA263\n"  /* bra 0x06039EF2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06039A90] = 0x060A4CF8} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8F4B\n"  /* bf/s 0x06039AD2 */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6230\n"  /* mov.b @r3,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2289\n"  /* and r8,r2 */
    ".word 0x3280\n"  /* cmp/eq r8,r2 */
    ".word 0x8B27\n"  /* bf 0x06039A98 */
    ".word 0x9407\n"  /* mov.w @(0xE,PC),r4 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06039A94] = 0x0603AB46} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB6AE\n"  /* bsr 0x0603A7B0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA023\n"  /* bra 0x06039A9E */
    ".word 0x0009\n"  /* nop */
    ".word 0xFF0F\n"  /* .word 0xFF0F */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C9C\n"  /* .word 0x4C9C */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0031\n"  /* .word 0x0031 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0033\n"  /* .word 0x0033 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0035\n"  /* mov.w r3,@(r0,r0) */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0037\n"  /* mul.l r3,r0 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0039\n"  /* .word 0x0039 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x003B\n"  /* .word 0x003B */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x003D\n"  /* mov.w @(r0,r3),r0 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x003F\n"  /* mac.l @r3+,@r0+ */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0021\n"  /* .word 0x0021 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CA8\n"  /* .word 0x4CA8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CD8\n"  /* .word 0x4CD8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CE8\n"  /* .word 0x4CE8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CF8\n"  /* .word 0x4CF8 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xAB46\n"  /* bra 0x06039126 */
    ".word 0xD332\n"  /* mov.l @(0xC8,PC),r3  {[0x06039B64] = 0x0603AB46} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x648C\n"  /* extu.b r8,r4 */
    ".word 0xD232\n"  /* mov.l @(0xC8,PC),r2  {[0x06039B68] = 0x060A4CB4} */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x06039B68] = 0x060A4CB4} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD130\n"  /* mov.l @(0xC0,PC),r1  {[0x06039B6C] = 0x060A4CAC} */
    ".word 0x6111\n"  /* mov.w @r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x8B01\n"  /* bf 0x06039AB6 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B01\n"  /* bf 0x06039AC2 */
    ".word 0xA23E\n"  /* bra 0x06039F3E */
    ".word 0x0009\n"  /* nop */
    ".word 0xB291\n"  /* bsr 0x06039FE8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B04\n"  /* bf 0x06039AD8 */
    ".word 0xA236\n"  /* bra 0x06039F3E */
    ".word 0x0009\n"  /* nop */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x06039B70] = 0x060A4D0C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0xA209\n"  /* bra 0x06039EF2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD023\n"  /* mov.l @(0x8C,PC),r0  {[0x06039B70] = 0x060A4D0C} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8901\n"  /* bt 0x06039AEE */
    ".word 0xA0AF\n"  /* bra 0x06039C4C */
    ".word 0x0009\n"  /* nop */
    ".word 0x629C\n"  /* extu.b r9,r2 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06039B70] = 0x060A4D0C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x9134\n"  /* mov.w @(0x68,PC),r1 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06039B74] = 0x060A4CFC} */
    ".word 0x2310\n"  /* mov.b r1,@r3 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x6310\n"  /* mov.b @r1,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2389\n"  /* and r8,r3 */
    ".word 0x3380\n"  /* cmp/eq r8,r3 */
    ".word 0x8B3A\n"  /* bf 0x06039B7C */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x880F\n"  /* cmp/eq #15,r0 */
    ".word 0x8B05\n"  /* bf 0x06039B1E */
    ".word 0x9425\n"  /* mov.w @(0x4A,PC),r4 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06039B64] = 0x0603AB46} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA003\n"  /* bra 0x06039B24 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06039B64] = 0x0603AB46} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x648C\n"  /* extu.b r8,r4 */
    ".word 0xB644\n"  /* bsr 0x0603A7B0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x06039B68] = 0x060A4CB4} */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06039B68] = 0x060A4CB4} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD10E\n"  /* mov.l @(0x38,PC),r1  {[0x06039B6C] = 0x060A4CAC} */
    ".word 0x6111\n"  /* mov.w @r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x8B01\n"  /* bf 0x06039B40 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B01\n"  /* bf 0x06039B4C */
    ".word 0xA1D9\n"  /* bra 0x06039EFE */
    ".word 0x0009\n"  /* nop */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x06039B70] = 0x060A4D0C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD109\n"  /* mov.l @(0x24,PC),r1  {[0x06039B78] = 0x060A4CF8} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06039B78] = 0x060A4CF8} */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0xA05F\n"  /* bra 0x06039C1E */
    ".word 0x0009\n"  /* nop */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xAB46\n"  /* bra 0x060391F6 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CB4\n"  /* .word 0x4CB4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAC\n"  /* .word 0x4CAC */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D0C\n"  /* .word 0x4D0C */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CFC\n"  /* .word 0x4CFC */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CF8\n"  /* .word 0x4CF8 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x6320\n"  /* mov.b @r2,r3 */
    ".word 0x9257\n"  /* mov.w @(0xAE,PC),r2 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2389\n"  /* and r8,r3 */
    ".word 0x3320\n"  /* cmp/eq r2,r3 */
    ".word 0x8B11\n"  /* bf 0x06039BAE */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x6320\n"  /* mov.b @r2,r3 */
    ".word 0x9251\n"  /* mov.w @(0xA2,PC),r2 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3320\n"  /* cmp/eq r2,r3 */
    ".word 0x8B06\n"  /* bf 0x06039BA4 */
    ".word 0xB7D6\n"  /* bsr 0x0603AB46 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0xE220\n"  /* mov #32,r2 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x06039C38] = 0x060A4CFC} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xA012\n"  /* bra 0x06039BC8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xB7CE\n"  /* bsr 0x0603AB46 */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0xA00D\n"  /* bra 0x06039BC8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x2489\n"  /* and r8,r4 */
    ".word 0xB7C6\n"  /* bsr 0x0603AB46 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x6320\n"  /* mov.b @r2,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2389\n"  /* and r8,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x06039C38] = 0x060A4CFC} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC80F\n"  /* tst #0x0F,r0 */
    ".word 0x8B04\n"  /* bf 0x06039BDC */
    ".word 0x63DC\n"  /* extu.b r13,r3 */
    ".word 0xD219\n"  /* mov.l @(0x64,PC),r2  {[0x06039C3C] = 0x060A4D0D} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xA005\n"  /* bra 0x06039BE6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06039C38] = 0x060A4CFC} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8820\n"  /* cmp/eq #32,r0 */
    ".word 0x8B13\n"  /* bf 0x06039C18 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x06039C40] = 0x060A4CAE} */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06039C44] = 0x060A4D02} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xE305\n"  /* mov #5,r3 */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x06039C40] = 0x060A4CAE} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8904\n"  /* bt 0x06039C0E */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x06039C40] = 0x060A4CAE} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xA005\n"  /* bra 0x06039C18 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x06039C40] = 0x060A4CAE} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x72FE\n"  /* add #-2,r2 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x06039C40] = 0x060A4CAE} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06039C48] = 0x060A4D0E} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0xB1E1\n"  /* bsr 0x06039FE8 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B0E\n"  /* bf 0x06039C4C */
    ".word 0xA166\n"  /* bra 0x06039EFE */
    ".word 0x0009\n"  /* nop */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x00E3\n"  /* .word 0x00E3 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CFC\n"  /* .word 0x4CFC */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D0D\n"  /* .word 0x4D0D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAE\n"  /* .word 0x4CAE */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D02\n"  /* sts.l mach,@-r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D0E\n"  /* ldc r13,sr */
    ".word 0xD078\n"  /* mov.l @(0x1E0,PC),r0  {[0x06039E30] = 0x060A4D0D} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B0F\n"  /* bf 0x06039C76 */
    ".word 0xD376\n"  /* mov.l @(0x1D8,PC),r3  {[0x06039E30] = 0x060A4D0D} */
    ".word 0x2390\n"  /* mov.b r9,@r3 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x6310\n"  /* mov.b @r1,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0xB1BF\n"  /* bsr 0x06039FE8 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B01\n"  /* bf 0x06039C76 */
    ".word 0xA144\n"  /* bra 0x06039EFE */
    ".word 0x0009\n"  /* nop */
    ".word 0xD06F\n"  /* mov.l @(0x1BC,PC),r0  {[0x06039E34] = 0x060A4D0E} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8901\n"  /* bt 0x06039C84 */
    ".word 0xA086\n"  /* bra 0x06039D90 */
    ".word 0x0009\n"  /* nop */
    ".word 0x629C\n"  /* extu.b r9,r2 */
    ".word 0xD36B\n"  /* mov.l @(0x1AC,PC),r3  {[0x06039E34] = 0x060A4D0E} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD16B\n"  /* mov.l @(0x1AC,PC),r1  {[0x06039E38] = 0x060A4CAE} */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x6110\n"  /* mov.b @r1,r1 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8B5C\n"  /* bf 0x06039D50 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x33A6\n"  /* cmp/hi r10,r3 */
    ".word 0x8B37\n"  /* bf 0x06039D12 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD365\n"  /* mov.l @(0x194,PC),r3  {[0x06039E3C] = 0x060A4D11} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD163\n"  /* mov.l @(0x18C,PC),r1  {[0x06039E38] = 0x060A4CAE} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6110\n"  /* mov.b @r1,r1 */
    ".word 0x611C\n"  /* extu.b r1,r1 */
    ".word 0x4100\n"  /* shll r1 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x31A6\n"  /* cmp/hi r10,r1 */
    ".word 0x8B15\n"  /* bf 0x06039CE4 */
    ".word 0xD261\n"  /* mov.l @(0x184,PC),r2  {[0x06039E40] = 0x060A4D0F} */
    ".word 0x22D0\n"  /* mov.b r13,@r2 */
    ".word 0xD45E\n"  /* mov.l @(0x178,PC),r4  {[0x06039E38] = 0x060A4CAE} */
    ".word 0x61C2\n"  /* mov.l @r12,r1 */
    ".word 0xD260\n"  /* mov.l @(0x180,PC),r2  {[0x06039E44] = 0x060A4D08} */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x3148\n"  /* sub r4,r1 */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x62A3\n"  /* mov r10,r2 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x3027\n"  /* cmp/gt r2,r0 */
    ".word 0x320E\n"  /* .word 0x320E */
    ".word 0x4221\n"  /* shar r2 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x2C42\n"  /* mov.l r4,@r12 */
    ".word 0xB19E\n"  /* bsr 0x0603A01C */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0xA04A\n"  /* bra 0x06039D78 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD358\n"  /* mov.l @(0x160,PC),r3  {[0x06039E48] = 0x060A4D10} */
    ".word 0x23D0\n"  /* mov.b r13,@r3 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x3318\n"  /* sub r1,r3 */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x331E\n"  /* .word 0x331E */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x3038\n"  /* sub r3,r0 */
    ".word 0xD352\n"  /* mov.l @(0x148,PC),r3  {[0x06039E44] = 0x060A4D08} */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0xD44E\n"  /* mov.l @(0x138,PC),r4  {[0x06039E38] = 0x060A4CAE} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xB187\n"  /* bsr 0x0603A01C */
    ".word 0x0009\n"  /* nop */
    ".word 0xA03F\n"  /* bra 0x06039D90 */
    ".word 0x2EA2\n"  /* mov.l r10,@r14 */
    ".word 0xD04E\n"  /* mov.l @(0x138,PC),r0  {[0x06039E4C] = 0x060A4CFC} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8820\n"  /* cmp/eq #32,r0 */
    ".word 0x8B09\n"  /* bf 0x06039D30 */
    ".word 0xD446\n"  /* mov.l @(0x118,PC),r4  {[0x06039E38] = 0x060A4CAE} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6440\n"  /* mov.b @r4,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xB178\n"  /* bsr 0x0603A01C */
    ".word 0x0009\n"  /* nop */
    ".word 0xA00B\n"  /* bra 0x06039D46 */
    ".word 0x2C92\n"  /* mov.l r9,@r12 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0xD347\n"  /* mov.l @(0x11C,PC),r3  {[0x06039E50] = 0x060A4CCC} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0xD346\n"  /* mov.l @(0x118,PC),r3  {[0x06039E54] = 0x060A4CD0} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD33F\n"  /* mov.l @(0xFC,PC),r3  {[0x06039E48] = 0x060A4D10} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xA020\n"  /* bra 0x06039D90 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x32A6\n"  /* cmp/hi r10,r2 */
    ".word 0x8B10\n"  /* bf 0x06039D7E */
    ".word 0xD238\n"  /* mov.l @(0xE0,PC),r2  {[0x06039E40] = 0x060A4D0F} */
    ".word 0x22D0\n"  /* mov.b r13,@r2 */
    ".word 0x62A3\n"  /* mov r10,r2 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x3218\n"  /* sub r1,r2 */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0x3127\n"  /* cmp/gt r2,r1 */
    ".word 0x321E\n"  /* .word 0x321E */
    ".word 0x4221\n"  /* shar r2 */
    ".word 0x3028\n"  /* sub r2,r0 */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0xB152\n"  /* bsr 0x0603A01C */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0xA0C0\n"  /* bra 0x06039EFE */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0xD332\n"  /* mov.l @(0xC8,PC),r3  {[0x06039E48] = 0x060A4D10} */
    ".word 0x23D0\n"  /* mov.b r13,@r3 */
    ".word 0x64C2\n"  /* mov.l @r12,r4 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xB147\n"  /* bsr 0x0603A01C */
    ".word 0x0009\n"  /* nop */
    ".word 0x2C92\n"  /* mov.l r9,@r12 */
    ".word 0xD02B\n"  /* mov.l @(0xAC,PC),r0  {[0x06039E40] = 0x060A4D0F} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B2E\n"  /* bf 0x06039DF8 */
    ".word 0x629C\n"  /* extu.b r9,r2 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x06039E40] = 0x060A4D0F} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xE320\n"  /* mov #32,r3 */
    ".word 0x61C2\n"  /* mov.l @r12,r1 */
    ".word 0x3133\n"  /* cmp/ge r3,r1 */
    ".word 0x8B06\n"  /* bf 0x06039DB6 */
    ".word 0xD225\n"  /* mov.l @(0x94,PC),r2  {[0x06039E40] = 0x060A4D0F} */
    ".word 0x22D0\n"  /* mov.b r13,@r2 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x61C2\n"  /* mov.l @r12,r1 */
    ".word 0x71E0\n"  /* add #-32,r1 */
    ".word 0xA016\n"  /* bra 0x06039DE2 */
    ".word 0x2C12\n"  /* mov.l r1,@r12 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06039E48] = 0x060A4D10} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x64C2\n"  /* mov.l @r12,r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x06039E58] = 0x20100021} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xA00D\n"  /* bra 0x06039DE2 */
    ".word 0x2C92\n"  /* mov.l r9,@r12 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x06039E5C] = 0x060A4CD4} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6130\n"  /* mov.b @r3,r1 */
    ".word 0x2210\n"  /* mov.b r1,@r2 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x06039E5C] = 0x060A4CD4} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0xD220\n"  /* mov.l @(0x80,PC),r2  {[0x06039E5C] = 0x060A4CD4} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x7102\n"  /* add #2,r1 */
    ".word 0x2E12\n"  /* mov.l r1,@r14 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x3342\n"  /* cmp/hs r4,r3 */
    ".word 0x8BEF\n"  /* bf 0x06039DC8 */
    ".word 0xB0FE\n"  /* bsr 0x06039FE8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B01\n"  /* bf 0x06039DF8 */
    ".word 0xA083\n"  /* bra 0x06039EFE */
    ".word 0x0009\n"  /* nop */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06039E48] = 0x060A4D10} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B47\n"  /* bf 0x06039E92 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06039E48] = 0x060A4D10} */
    ".word 0x2390\n"  /* mov.b r9,@r3 */
    ".word 0xB153\n"  /* bsr 0x0603A0B0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x06039E60] = 0x060A4CB4} */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06039E60] = 0x060A4CB4} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD113\n"  /* mov.l @(0x4C,PC),r1  {[0x06039E64] = 0x060A4CAC} */
    ".word 0x6111\n"  /* mov.w @r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x3213\n"  /* cmp/ge r1,r2 */
    ".word 0x8B01\n"  /* bf 0x06039E22 */
    ".word 0x62DC\n"  /* extu.b r13,r2 */
    ".word 0x2B20\n"  /* mov.b r2,@r11 */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B1E\n"  /* bf 0x06039E68 */
    ".word 0xA068\n"  /* bra 0x06039EFE */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D0D\n"  /* .word 0x4D0D */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D0E\n"  /* ldc r13,sr */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAE\n"  /* .word 0x4CAE */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D11\n"  /* cmp/pz r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D0F\n"  /* mac.w @r0+,@r13+ */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D08\n"  /* shll2 r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D10\n"  /* dt r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CFC\n"  /* .word 0x4CFC */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CCC\n"  /* .word 0x4CCC */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CD0\n"  /* .word 0x4CD0 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0021\n"  /* .word 0x0021 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CD4\n"  /* .word 0x4CD4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CB4\n"  /* .word 0x4CB4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAC\n"  /* .word 0x4CAC */
    ".word 0xD251\n"  /* mov.l @(0x144,PC),r2  {[0x06039FB0] = 0x060A4D11} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B07\n"  /* bf 0x06039E82 */
    ".word 0xD350\n"  /* mov.l @(0x140,PC),r3  {[0x06039FB4] = 0x060A4CF8} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0xD24E\n"  /* mov.l @(0x138,PC),r2  {[0x06039FB4] = 0x060A4CF8} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x61DC\n"  /* extu.b r13,r1 */
    ".word 0xD24E\n"  /* mov.l @(0x138,PC),r2  {[0x06039FB8] = 0x060A4D0C} */
    ".word 0x2210\n"  /* mov.b r1,@r2 */
    ".word 0xB0B1\n"  /* bsr 0x06039FE8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B01\n"  /* bf 0x06039E92 */
    ".word 0xA036\n"  /* bra 0x06039EFE */
    ".word 0x0009\n"  /* nop */
    ".word 0xD047\n"  /* mov.l @(0x11C,PC),r0  {[0x06039FB0] = 0x060A4D11} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B2A\n"  /* bf 0x06039EF2 */
    ".word 0x629C\n"  /* extu.b r9,r2 */
    ".word 0xD344\n"  /* mov.l @(0x110,PC),r3  {[0x06039FB0] = 0x060A4D11} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD146\n"  /* mov.l @(0x118,PC),r1  {[0x06039FBC] = 0x060A4D08} */
    ".word 0xE320\n"  /* mov #32,r3 */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x3137\n"  /* cmp/gt r3,r1 */
    ".word 0x8B0A\n"  /* bf 0x06039EC2 */
    ".word 0x63DC\n"  /* extu.b r13,r3 */
    ".word 0xD244\n"  /* mov.l @(0x110,PC),r2  {[0x06039FC0] = 0x060A4D0F} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x2EA2\n"  /* mov.l r10,@r14 */
    ".word 0xD341\n"  /* mov.l @(0x104,PC),r3  {[0x06039FBC] = 0x060A4D08} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x73E0\n"  /* add #-32,r3 */
    ".word 0xD240\n"  /* mov.l @(0x100,PC),r2  {[0x06039FBC] = 0x060A4D08} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA010\n"  /* bra 0x06039EE2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD33E\n"  /* mov.l @(0xF8,PC),r3  {[0x06039FBC] = 0x060A4D08} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x63DC\n"  /* extu.b r13,r3 */
    ".word 0xD239\n"  /* mov.l @(0xE4,PC),r2  {[0x06039FB8] = 0x060A4D0C} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD137\n"  /* mov.l @(0xDC,PC),r1  {[0x06039FB4] = 0x060A4CF8} */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0xD236\n"  /* mov.l @(0xD8,PC),r2  {[0x06039FB4] = 0x060A4CF8} */
    ".word 0x2212\n"  /* mov.l r1,@r2 */
    ".word 0xD237\n"  /* mov.l @(0xDC,PC),r2  {[0x06039FBC] = 0x060A4D08} */
    ".word 0x2292\n"  /* mov.l r9,@r2 */
    ".word 0xB081\n"  /* bsr 0x06039FE8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B01\n"  /* bf 0x06039EF2 */
    ".word 0xA006\n"  /* bra 0x06039EFE */
    ".word 0x0009\n"  /* nop */
    ".word 0xD230\n"  /* mov.l @(0xC0,PC),r2  {[0x06039FB4] = 0x060A4CF8} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8B01\n"  /* bf 0x06039EFE */
    ".word 0xADF1\n"  /* bra 0x06039AE0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62B0\n"  /* mov.b @r11,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8901\n"  /* bt 0x06039F0A */
    ".word 0xA01A\n"  /* bra 0x06039F3E */
    ".word 0x0009\n"  /* nop */
    ".word 0xD22E\n"  /* mov.l @(0xB8,PC),r2  {[0x06039FC4] = 0x060A4CF0} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x06039FC4] = 0x060A4CF0} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD22B\n"  /* mov.l @(0xAC,PC),r2  {[0x06039FC4] = 0x060A4CF0} */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8901\n"  /* bt 0x06039F22 */
    ".word 0xAD7F\n"  /* bra 0x06039A20 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA00C\n"  /* bra 0x06039F3E */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B01\n"  /* bf 0x06039F2E */
    ".word 0xAD25\n"  /* bra 0x06039978 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B01\n"  /* bf 0x06039F36 */
    ".word 0xAD6F\n"  /* bra 0x06039A14 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B01\n"  /* bf 0x06039F3E */
    ".word 0xAD53\n"  /* bra 0x060399E4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60B0\n"  /* mov.b @r11,r0 */
    ".word 0xA01C\n"  /* bra 0x06039F7C */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xB40F\n"  /* bsr 0x0603A766 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x06039FC8] = 0x060A4CA9} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC980\n"  /* and #0x80,r0 */
    ".word 0xCB40\n"  /* or #0x40,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x06039FCC] = 0x20100001} */
    ".word 0x2300\n"  /* mov.b r0,@r3 */
    ".word 0xA016\n"  /* bra 0x06039F88 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x06039FC8] = 0x060A4CA9} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x6227\n"  /* not r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06039FC8] = 0x060A4CA9} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC980\n"  /* and #0x80,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06039FCC] = 0x20100001} */
    ".word 0x2300\n"  /* mov.b r0,@r3 */
    ".word 0xA006\n"  /* bra 0x06039F88 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89E1\n"  /* bt 0x06039F44 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89E1\n"  /* bt 0x06039F48 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89E9\n"  /* bt 0x06039F5C */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x0202\n"  /* stc sr,r2 */
    ".word 0x930C\n"  /* mov.w @(0x18,PC),r3 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x202B\n"  /* or r2,r0 */
    ".word 0x400E\n"  /* ldc r0,sr */
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
    ".word 0xFF0F\n"  /* .word 0xFF0F */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D11\n"  /* cmp/pz r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CF8\n"  /* .word 0x4CF8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D0C\n"  /* .word 0x4D0C */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D08\n"  /* shll2 r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D0F\n"  /* mac.w @r0+,@r13+ */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CF0\n"  /* .word 0x4CF0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CA9\n"  /* .word 0x4CA9 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0603A008] = 0x060A4CAC} */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0603A00C] = 0x060A4CB4} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B02\n"  /* bf 0x06039FE4 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0603A010] = 0x060A4CF4} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_06039fe8\n"
    "_FUN_06039fe8:\n"
    ".word 0xD50A\n"  /* mov.l @(0x28,PC),r5  {[0x0603A014] = 0x20100061} */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0603A018] = 0x060A4CEC} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3352\n"  /* cmp/hs r5,r3 */
    ".word 0x8B08\n"  /* bf 0x0603A004 */
    ".word 0xE420\n"  /* mov #32,r4 */
    ".word 0x6350\n"  /* mov.b @r5,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2349\n"  /* and r4,r3 */
    ".word 0x3340\n"  /* cmp/eq r4,r3 */
    ".word 0x8B02\n"  /* bf 0x0603A004 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0xD203\n"  /* mov.l @(0xC,PC),r2  {[0x0603A010] = 0x060A4CF4} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAC\n"  /* .word 0x4CAC */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CB4\n"  /* .word 0x4CB4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CF4\n"  /* .word 0x4CF4 */
    ".word 0x2010\n"  /* mov.b r1,@r0 */
    ".word 0x0061\n"  /* .word 0x0061 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CEC\n"  /* .word 0x4CEC */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603AA82, \"ax\"\n"

    ".global _FUN_0603AA82\n"
    ".type _FUN_0603AA82, @function\n"
    "_FUN_0603AA82:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xDE23\n"  /* mov.l @(0x8C,PC),r14  {[0x0603AB14] = 0x060A4CAE} */
    ".word 0x9544\n"  /* mov.w @(0x88,PC),r5 */
    ".word 0xD423\n"  /* mov.l @(0x8C,PC),r4  {[0x0603AB18] = 0x060A4CC8} */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD023\n"  /* mov.l @(0x8C,PC),r0  {[0x0603AB1C] = 0x060A4CAF} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0xA046\n"  /* bra 0x0603AB20 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xA005\n"  /* bra 0x0603AAA2 */
    ".word 0x6763\n"  /* mov r6,r7 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x327C\n"  /* add r7,r2 */
    ".word 0x635C\n"  /* extu.b r5,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x3722\n"  /* cmp/hs r2,r7 */
    ".word 0x8BF6\n"  /* bf 0x0603AA98 */
    ".word 0xA04A\n"  /* bra 0x0603AB42 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA02A\n"  /* bra 0x0603AB06 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x2250\n"  /* mov.b r5,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2250\n"  /* mov.b r5,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0x636C\n"  /* extu.b r6,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7203\n"  /* add #3,r2 */
    ".word 0x636C\n"  /* extu.b r6,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0xA015\n"  /* bra 0x0603AAFC */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x636C\n"  /* extu.b r6,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x636C\n"  /* extu.b r6,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0xA00B\n"  /* bra 0x0603AAFC */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x2250\n"  /* mov.b r5,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2250\n"  /* mov.b r5,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7202\n"  /* add #2,r2 */
    ".word 0x636C\n"  /* extu.b r6,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7203\n"  /* add #3,r2 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0xA020\n"  /* bra 0x0603AB42 */
    ".word 0x2260\n"  /* mov.b r6,@r2 */
    ".word 0xA004\n"  /* bra 0x0603AB0E */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x2250\n"  /* mov.b r5,@r2 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0xA018\n"  /* bra 0x0603AB42 */
    ".word 0x2250\n"  /* mov.b r5,@r2 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAE\n"  /* .word 0x4CAE */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CC8\n"  /* .word 0x4CC8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAF\n"  /* mac.w @r10+,@r12+ */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89C4\n"  /* bt 0x0603AAAE */
    ".word 0x8810\n"  /* cmp/eq #16,r0 */
    ".word 0x89C4\n"  /* bt 0x0603AAB2 */
    ".word 0x8820\n"  /* cmp/eq #32,r0 */
    ".word 0x89D2\n"  /* bt 0x0603AAD2 */
    ".word 0x8830\n"  /* cmp/eq #48,r0 */
    ".word 0x89DA\n"  /* bt 0x0603AAE6 */
    ".word 0x9149\n"  /* mov.w @(0x92,PC),r1 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x89E5\n"  /* bt 0x0603AB02 */
    ".word 0x9147\n"  /* mov.w @(0x8E,PC),r1 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x89E4\n"  /* bt 0x0603AB06 */
    ".word 0x9145\n"  /* mov.w @(0x8A,PC),r1 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x89A8\n"  /* bt 0x0603AA94 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".global _FUN_0603ab46\n"
    "_FUN_0603ab46:\n"
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0xD620\n"  /* mov.l @(0x80,PC),r6  {[0x0603ABCC] = 0x060A4CB4} */
    ".word 0xD521\n"  /* mov.l @(0x84,PC),r5  {[0x0603ABD0] = 0x060A4CC0} */
    ".word 0xD021\n"  /* mov.l @(0x84,PC),r0  {[0x0603ABD4] = 0x060A4CAF} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0xA04E\n"  /* bra 0x0603ABF0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xD020\n"  /* mov.l @(0x80,PC),r0  {[0x0603ABD8] = 0x060A4CAE} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x0037\n"  /* mul.l r3,r0 */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0x302C\n"  /* add r2,r0 */
    ".word 0xA054\n"  /* bra 0x0603AC12 */
    ".word 0x2040\n"  /* mov.b r4,@r0 */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0xA037\n"  /* bra 0x0603ABE6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0xA006\n"  /* bra 0x0603AB94 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0xA03A\n"  /* bra 0x0603AC12 */
    ".word 0x0244\n"  /* mov.b r4,@(r0,r2) */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xA02F\n"  /* bra 0x0603AC12 */
    ".word 0x8028\n"  /* mov.b r0,@(0x8,r2) */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xA026\n"  /* bra 0x0603AC12 */
    ".word 0x8022\n"  /* mov.b r0,@(0x2,r2) */
    ".word 0x00E1\n"  /* .word 0x00E1 */
    ".word 0x00E2\n"  /* .word 0x00E2 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CB4\n"  /* .word 0x4CB4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CC0\n"  /* .word 0x4CC0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAF\n"  /* mac.w @r10+,@r12+ */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4CAE\n"  /* .word 0x4CAE */
    ".word 0x6262\n"  /* mov.l @r6,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xA011\n"  /* bra 0x0603AC12 */
    ".word 0x8024\n"  /* mov.b r0,@(0x4,r2) */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89BA\n"  /* bt 0x0603AB6A */
    ".word 0x8810\n"  /* cmp/eq #16,r0 */
    ".word 0x89BF\n"  /* bt 0x0603AB78 */
    ".word 0x8820\n"  /* cmp/eq #32,r0 */
    ".word 0x89C5\n"  /* bt 0x0603AB88 */
    ".word 0x8830\n"  /* cmp/eq #48,r0 */
    ".word 0x89CE\n"  /* bt 0x0603AB9E */
    ".word 0x9109\n"  /* mov.w @(0x12,PC),r1 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x89D6\n"  /* bt 0x0603ABB4 */
    ".word 0x9107\n"  /* mov.w @(0xE,PC),r1 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x89E7\n"  /* bt 0x0603ABDC */
    ".word 0x9105\n"  /* mov.w @(0xA,PC),r1 */
    ".word 0x3010\n"  /* cmp/eq r1,r0 */
    ".word 0x89A0\n"  /* bt 0x0603AB54 */
    ".word 0x000B\n"  /* rts */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x00E1\n"  /* .word 0x00E1 */
    ".word 0x00E2\n"  /* .word 0x00E2 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603ACEA, \"ax\"\n"

    ".global _FUN_0603ACEA\n"
    ".type _FUN_0603ACEA, @function\n"
    "_FUN_0603ACEA:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x901B\n"  /* mov.w @(0x36,PC),r0 */
    ".word 0x3F0C\n"  /* add r0,r15 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xDD0F\n"  /* mov.l @(0x3C,PC),r13  {[0x0603AD38] = 0x060A4D14} */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8F1F\n"  /* bf/s 0x0603AD40 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x9013\n"  /* mov.w @(0x26,PC),r0 */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8903\n"  /* bt 0x0603AD14 */
    ".word 0xB616\n"  /* bsr 0x0603B93C */
    ".word 0xE4F9\n"  /* mov #-7,r4 */
    ".word 0xA045\n"  /* bra 0x0603AD9E */
    ".word 0x0009\n"  /* nop */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0603AD3C] = 0x0603F238} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8903\n"  /* bt 0x0603AD28 */
    ".word 0xB60C\n"  /* bsr 0x0603B93C */
    ".word 0xE4FF\n"  /* mov #-1,r4 */
    ".word 0xA03B\n"  /* bra 0x0603AD9E */
    ".word 0x0009\n"  /* nop */
    ".word 0xA039\n"  /* bra 0x0603AD9E */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xFF0C\n"  /* .word 0xFF0C */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF22C\n"  /* .word 0xF22C */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603BC12 */
    ".word 0xBC12\n"  /* bsr 0x0603A55E */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603F238 */
    ".word 0xF238\n"  /* .word 0xF238 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x904A\n"  /* mov.w @(0x94,PC),r0 */
    ".word 0x002E\n"  /* mov.l @(r0,r2),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B07\n"  /* bf 0x0603AD5A */
    ".word 0x65D2\n"  /* mov.l @r13,r5 */
    ".word 0x9046\n"  /* mov.w @(0x8C,PC),r0 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x0603ADE0] = 0x0603F1E0} */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0xA006\n"  /* bra 0x0603AD66 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65D2\n"  /* mov.l @r13,r5 */
    ".word 0x903E\n"  /* mov.w @(0x7C,PC),r0 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0603ADE4] = 0x0603F1F0} */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x84EB\n"  /* mov.b @(0xB,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC810\n"  /* tst #0x10,r0 */
    ".word 0x8901\n"  /* bt 0x0603AD74 */
    ".word 0xA004\n"  /* bra 0x0603AD7C */
    ".word 0x0009\n"  /* nop */
    ".word 0xB5E2\n"  /* bsr 0x0603B93C */
    ".word 0xE4FA\n"  /* mov #-6,r4 */
    ".word 0xA011\n"  /* bra 0x0603AD9E */
    ".word 0x0009\n"  /* nop */
    ".word 0x66C3\n"  /* mov r12,r6 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xB653\n"  /* bsr 0x0603BA2C */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x6D03\n"  /* mov r0,r13 */
    ".word 0x56E1\n"  /* mov.l @(0x4,r14),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0603ADE8] = 0x0603F0FC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0xB61F\n"  /* bsr 0x0603B9D6 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xB5D0\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x911E\n"  /* mov.w @(0x3C,PC),r1 */
    ".word 0x3F1C\n"  /* add r1,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603AE74, \"ax\"\n"

    ".global _FUN_0603AE74\n"
    ".type _FUN_0603AE74, @function\n"
    "_FUN_0603AE74:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDE19\n"  /* mov.l @(0x64,PC),r14  {[0x0603AEE0] = 0x060A4D14} */
    ".word 0x902C\n"  /* mov.w @(0x58,PC),r0 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8904\n"  /* bt 0x0603AE90 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x9127\n"  /* mov.w @(0x4E,PC),r1 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8906\n"  /* bt 0x0603AE9E */
    ".word 0xB554\n"  /* bsr 0x0603B93C */
    ".word 0xE4F8\n"  /* mov #-8,r4 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8B05\n"  /* bf 0x0603AEAE */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0603AEE0] = 0x060A4D14} */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x023E\n"  /* mov.l @(r0,r3),r2 */
    ".word 0x3247\n"  /* cmp/gt r4,r2 */
    ".word 0x8906\n"  /* bt 0x0603AEBC */
    ".word 0xB545\n"  /* bsr 0x0603B93C */
    ".word 0xE4F7\n"  /* mov #-9,r4 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x900B\n"  /* mov.w @(0x16,PC),r0 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0603AEE4] = 0x0603F1F0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0xB538\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x700C\n"  /* add #12,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0098\n"  /* .word 0x0098 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF1F0\n"  /* .word 0xF1F0 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603AFDC, \"ax\"\n"

    ".global _FUN_0603AFDC\n"
    ".type _FUN_0603AFDC, @function\n"
    "_FUN_0603AFDC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDC15\n"  /* mov.l @(0x54,PC),r12  {[0x0603B038] = 0x060A4D14} */
    ".word 0x03DC\n"  /* mov.b @(r0,r13),r3 */
    ".word 0x6CC2\n"  /* mov.l @r12,r12 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x7C04\n"  /* add #4,r12 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8F05\n"  /* bf/s 0x0603B000 */
    ".word 0x3C3C\n"  /* add r3,r12 */
    ".word 0x53C3\n"  /* mov.l @(0xC,r12),r3 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D2\n"  /* mov.l @r13,r4 */
    ".word 0xA010\n"  /* bra 0x0603B020 */
    ".word 0x3E0C\n"  /* add r0,r14 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B03\n"  /* bf 0x0603B00E */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x5234\n"  /* mov.l @(0x10,r3),r2 */
    ".word 0xA009\n"  /* bra 0x0603B020 */
    ".word 0x3E2C\n"  /* add r2,r14 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8906\n"  /* bt 0x0603B020 */
    ".word 0xE4F3\n"  /* mov #-13,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA48E\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4E11\n"  /* cmp/pz r14 */
    ".word 0x890B\n"  /* bt 0x0603B03C */
    ".word 0xE4F1\n"  /* mov #-15,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA485\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603BF22 */
    ".word 0xBF22\n"  /* bsr 0x0603AE7E */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x52C2\n"  /* mov.l @(0x8,r12),r2 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x64D2\n"  /* mov.l @r13,r4 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0xB479\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B08E, \"ax\"\n"

    ".global _FUN_0603B08E\n"
    ".type _FUN_0603B08E, @function\n"
    "_FUN_0603B08E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xBFE1\n"  /* bsr 0x0603B058 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x1F01\n"  /* mov.l r0,@(0x4,r15) */
    ".word 0xB450\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x5334\n"  /* mov.l @(0x10,r3),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B05\n"  /* bf 0x0603B0B4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xE01D\n"  /* mov #29,r0 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B0C0, \"ax\"\n"

    ".global _FUN_0603B0C0\n"
    ".type _FUN_0603B0C0, @function\n"
    "_FUN_0603B0C0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x1F51\n"  /* mov.l r5,@(0x4,r15) */
    ".word 0x6EF2\n"  /* mov.l @r15,r14 */
    ".word 0x6EE2\n"  /* mov.l @r14,r14 */
    ".word 0x0EEC\n"  /* mov.b @(r0,r14),r14 */
    ".word 0x6EEC\n"  /* extu.b r14,r14 */
    ".word 0xB433\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x890C\n"  /* bt 0x0603B0F8 */
    ".word 0xA000\n"  /* bra 0x0603B0E2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8906\n"  /* bt 0x0603B0F8 */
    ".word 0xA000\n"  /* bra 0x0603B0EE */
    ".word 0x0009\n"  /* nop */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x0603B114] = 0x06035F44} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5F44\n"  /* mov.l @(0x10,r4),r15 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B118, \"ax\"\n"

    ".global _FUN_0603B118\n"
    ".type _FUN_0603B118, @function\n"
    "_FUN_0603B118:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xEE00\n"  /* mov #0,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B11C, \"ax\"\n"

    ".global _FUN_0603B11C\n"
    ".type _FUN_0603B11C, @function\n"
    "_FUN_0603B11C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FEC\n"  /* add #-20,r15 */
    ".word 0x1F43\n"  /* mov.l r4,@(0xC,r15) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x1F51\n"  /* mov.l r5,@(0x4,r15) */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x1F62\n"  /* mov.l r6,@(0x8,r15) */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x1F74\n"  /* mov.l r7,@(0x10,r15) */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B130, \"ax\"\n"

    ".global _FUN_0603B130\n"
    ".type _FUN_0603B130, @function\n"
    "_FUN_0603B130:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x52F6\n"  /* mov.l @(0x18,r15),r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x57F5\n"  /* mov.l @(0x14,r15),r7 */
    ".word 0x54F7\n"  /* mov.l @(0x1C,r15),r4 */
    ".word 0xB6AD\n"  /* bsr 0x0603BE9C */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8908\n"  /* bt 0x0603B15C */
    ".word 0xA000\n"  /* bra 0x0603B14E */
    ".word 0x0009\n"  /* nop */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0xC804\n"  /* tst #0x04,r0 */
    ".word 0x8903\n"  /* bt 0x0603B15C */
    ".word 0xA000\n"  /* bra 0x0603B158 */
    ".word 0x0009\n"  /* nop */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x22E2\n"  /* mov.l r14,@r2 */
    ".word 0xB3EE\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B168, \"ax\"\n"

    ".global _FUN_0603B168\n"
    ".type _FUN_0603B168, @function\n"
    "_FUN_0603B168:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FEC\n"  /* add #-20,r15 */
    ".word 0x1F43\n"  /* mov.l r4,@(0xC,r15) */
    ".word 0x1F64\n"  /* mov.l r6,@(0x10,r15) */
    ".word 0x1F72\n"  /* mov.l r7,@(0x8,r15) */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x53F6\n"  /* mov.l @(0x18,r15),r3 */
    ".word 0x6673\n"  /* mov r7,r6 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x730C\n"  /* add #12,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x720C\n"  /* add #12,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x54F7\n"  /* mov.l @(0x1C,r15),r4 */
    ".word 0xB686\n"  /* bsr 0x0603BE9C */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x53FA\n"  /* mov.l @(0x28,r15),r3 */
    ".word 0x6032\n"  /* mov.l @r3,r0 */
    ".word 0xC99F\n"  /* and #0x9F,r0 */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0x53F6\n"  /* mov.l @(0x18,r15),r3 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x51F5\n"  /* mov.l @(0x14,r15),r1 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x4218\n"  /* shll8 r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x321C\n"  /* add r1,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xB3C7\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x7F24\n"  /* add #36,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B290, \"ax\"\n"

    ".global _FUN_0603B290\n"
    ".type _FUN_0603B290, @function\n"
    "_FUN_0603B290:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0x1F61\n"  /* mov.l r6,@(0x4,r15) */
    ".word 0x1F72\n"  /* mov.l r7,@(0x8,r15) */
    ".word 0x03EC\n"  /* mov.b @(r0,r14),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8906\n"  /* bt 0x0603B2B8 */
    ".word 0xE4F0\n"  /* mov #-16,r4 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA342\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xB374\n"  /* bsr 0x0603B9A4 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xE011\n"  /* mov #17,r0 */
    ".word 0x0E44\n"  /* mov.b r4,@(r0,r14) */
    ".word 0xE012\n"  /* mov #18,r0 */
    ".word 0x0E44\n"  /* mov.b r4,@(r0,r14) */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x5834\n"  /* mov.l @(0x10,r3),r8 */
    ".word 0xBEC5\n"  /* bsr 0x0603B058 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x3343\n"  /* cmp/ge r4,r3 */
    ".word 0x8901\n"  /* bt 0x0603B2DC */
    ".word 0xA001\n"  /* bra 0x0603B2DE */
    ".word 0x6DF2\n"  /* mov.l @r15,r13 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0xB5CC\n"  /* bsr 0x0603BE7C */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0603B310] = 0x0603F9DA} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E2\n"  /* mov.l @(0x8,r14),r4 */
    ".word 0xE701\n"  /* mov #1,r7 */
    ".word 0x56F2\n"  /* mov.l @(0x8,r15),r6 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0603B314] = 0x0603EF54} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E1\n"  /* mov.l @(0x4,r14),r4 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0603B318] = 0x0603FA00} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E2\n"  /* mov.l @(0x8,r14),r4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA318\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_060423CC */
    ".word 0x23CC\n"  /* .word 0x23CC */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF9DA\n"  /* .word 0xF9DA */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xEF54\n"  /* mov #84,r15 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xFA00\n"  /* .word 0xFA00 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B324, \"ax\"\n"

    ".global _FUN_0603B324\n"
    ".type _FUN_0603B324, @function\n"
    "_FUN_0603B324:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0x03EC\n"  /* mov.b @(r0,r14),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8905\n"  /* bt 0x0603B33E */
    ".word 0xE4F0\n"  /* mov #-16,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0xA2FF\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xB331\n"  /* bsr 0x0603B9A4 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0xE011\n"  /* mov #17,r0 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x0E24\n"  /* mov.b r2,@(r0,r14) */
    ".word 0xE012\n"  /* mov #18,r0 */
    ".word 0x0E34\n"  /* mov.b r3,@(r0,r14) */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x5834\n"  /* mov.l @(0x10,r3),r8 */
    ".word 0xBE81\n"  /* bsr 0x0603B058 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x3408\n"  /* sub r0,r4 */
    ".word 0x3343\n"  /* cmp/ge r4,r3 */
    ".word 0x8901\n"  /* bt 0x0603B364 */
    ".word 0xA001\n"  /* bra 0x0603B366 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0xB589\n"  /* bsr 0x0603BE7C */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0603B3B0] = 0x0603F9DA} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E2\n"  /* mov.l @(0x8,r14),r4 */
    ".word 0xE701\n"  /* mov #1,r7 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0603B3B4] = 0x0603EF54} */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E1\n"  /* mov.l @(0x4,r14),r4 */
    ".word 0xE5FF\n"  /* mov #-1,r5 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0603B3B8] = 0x0603FA1A} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E2\n"  /* mov.l @(0x8,r14),r4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0xA2D5\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B392, \"ax\"\n"

    ".global _FUN_0603B392\n"
    ".type _FUN_0603B392, @function\n"
    "_FUN_0603B392:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0xB2D0\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0xE012\n"  /* mov #18,r0 */
    ".word 0x032C\n"  /* mov.b @(r0,r2),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B09\n"  /* bf 0x0603B3BC */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF9DA\n"  /* .word 0xF9DA */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xEF54\n"  /* mov #84,r15 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603FA1A */
    ".word 0xFA1A\n"  /* .word 0xFA1A */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xE012\n"  /* mov #18,r0 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B3CA, \"ax\"\n"

    ".global _FUN_0603B3CA\n"
    ".type _FUN_0603B3CA, @function\n"
    "_FUN_0603B3CA:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B3D0, \"ax\"\n"

    ".global _FUN_0603B3D0\n"
    ".type _FUN_0603B3D0, @function\n"
    "_FUN_0603B3D0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x0E34\n"  /* mov.b r3,@(r0,r14) */
    ".word 0xB2FE\n"  /* bsr 0x0603B9D6 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x6DE3\n"  /* mov r14,r13 */
    ".word 0xB26A\n"  /* bsr 0x0603B8B4 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xB288\n"  /* bsr 0x0603B8F4 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xBE38\n"  /* bsr 0x0603B058 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0xB2A7\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".global _FUN_0603b3fa\n"
    "_FUN_0603b3fa:\n"
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0xE011\n"  /* mov #17,r0 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B3FE, \"ax\"\n"

    ".global _FUN_0603B3FE\n"
    ".type _FUN_0603B3FE, @function\n"
    "_FUN_0603B3FE:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x033C\n"  /* mov.b @(r0,r3),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xD504\n"  /* mov.l @(0x10,PC),r5  {[0x0603B41C] = 0x7FFFFFFF} */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0603B420] = 0x0603EF64} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x5441\n"  /* mov.l @(0x4,r4),r4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xA290\n"  /* bra 0x0603B93C */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603EF64 */
    ".word 0xEF64\n"  /* mov #100,r15 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B53C, \"ax\"\n"

    ".global _FUN_0603B53C\n"
    ".type _FUN_0603B53C, @function\n"
    "_FUN_0603B53C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDD06\n"  /* mov.l @(0x18,PC),r13  {[0x0603B564] = 0x060A4D14} */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x7D34\n"  /* add #52,r13 */
    ".word 0x00DE\n"  /* mov.l @(r0,r13),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8F09\n"  /* bf/s 0x0603B568 */
    ".word 0xEB00\n"  /* mov #0,r11 */
    ".word 0x2CB2\n"  /* mov.l r11,@r12 */
    ".word 0xA015\n"  /* bra 0x0603B586 */
    ".word 0x6EB3\n"  /* mov r11,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF9F2\n"  /* .word 0xF9F2 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF9F6\n"  /* .word 0xF9F6 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x2C22\n"  /* mov.l r2,@r12 */
    ".word 0xBF5A\n"  /* bsr 0x0603B424 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x2EE8\n"  /* tst r14,r14 */
    ".word 0x8B07\n"  /* bf 0x0603B586 */
    ".word 0xE060\n"  /* mov #96,r0 */
    ".word 0x00DE\n"  /* mov.l @(r0,r13),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B02\n"  /* bf 0x0603B584 */
    ".word 0x2CB2\n"  /* mov.l r11,@r12 */
    ".word 0xA001\n"  /* bra 0x0603B586 */
    ".word 0x6EB3\n"  /* mov r11,r14 */
    ".word 0xEE01\n"  /* mov #1,r14 */
    ".word 0xB1D9\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B598, \"ax\"\n"

    ".global _FUN_0603B598\n"
    ".type _FUN_0603B598, @function\n"
    "_FUN_0603B598:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE11D\n"  /* mov #29,r1 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC860\n"  /* tst #0x60,r0 */
    ".word 0x8B08\n"  /* bf 0x0603B5BC */
    ".word 0xA000\n"  /* bra 0x0603B5AE */
    ".word 0x0009\n"  /* nop */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0603B5CC] = 0x06040894} */
    ".word 0x5426\n"  /* mov.l @(0x18,r2),r4 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x1F01\n"  /* mov.l r0,@(0x4,r15) */
    ".word 0xB1BE\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x50F1\n"  /* mov.l @(0x4,r15),r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0894\n"  /* mov.b r9,@(r0,r8) */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B5D0, \"ax\"\n"

    ".global _FUN_0603B5D0\n"
    ".type _FUN_0603B5D0, @function\n"
    "_FUN_0603B5D0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x1353\n"  /* mov.l r5,@(0xC,r3) */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0603B628] = 0x0603F970} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x5442\n"  /* mov.l @(0x8,r4),r4 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0xB1AA\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B5F2, \"ax\"\n"

    ".global _FUN_0603B5F2\n"
    ".type _FUN_0603B5F2, @function\n"
    "_FUN_0603B5F2:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x534A\n"  /* mov.l @(0x28,r4),r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x145A\n"  /* mov.l r5,@(0x28,r4) */
    ".word 0xB19D\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B60C, \"ax\"\n"

    ".global _FUN_0603B60C\n"
    ".type _FUN_0603B60C, @function\n"
    "_FUN_0603B60C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0603B62C] = 0x0603F9FA} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x5442\n"  /* mov.l @(0x8,r4),r4 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0xB18F\n"  /* bsr 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603F970 */
    ".word 0xF970\n"  /* .word 0xF970 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF9FA\n"  /* .word 0xF9FA */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B630, \"ax\"\n"

    ".global _FUN_0603B630\n"
    ".type _FUN_0603B630, @function\n"
    "_FUN_0603B630:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE11D\n"  /* mov #29,r1 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B634, \"ax\"\n"

    ".global _FUN_0603B634\n"
    ".type _FUN_0603B634, @function\n"
    "_FUN_0603B634:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC860\n"  /* tst #0x60,r0 */
    ".word 0x8B11\n"  /* bf 0x0603B666 */
    ".word 0xA000\n"  /* bra 0x0603B646 */
    ".word 0x0009\n"  /* nop */
    ".word 0xBD07\n"  /* bsr 0x0603B058 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0603B69C] = 0x060406B4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B03\n"  /* bf 0x0603B65E */
    ".word 0xE4EC\n"  /* mov #-20,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA16F\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x0603B6A0] = 0x060A4D14} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x9019\n"  /* mov.w @(0x32,PC),r0 */
    ".word 0x02E6\n"  /* mov.l r14,@(r0,r2) */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA167\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xD60C\n"  /* mov.l @(0x30,PC),r6  {[0x0603B6A0] = 0x060A4D14} */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x9012\n"  /* mov.w @(0x24,PC),r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0xA15E\n"  /* bra 0x0603B93C */
    ".word 0xE400\n"  /* mov #0,r4 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B680, \"ax\"\n"

    ".global _FUN_0603B680\n"
    ".type _FUN_0603B680, @function\n"
    "_FUN_0603B680:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6143\n"  /* mov r4,r1 */
    ".word 0xD206\n"  /* mov.l @(0x18,PC),r2  {[0x0603B6A0] = 0x060A4D14} */
    ".word 0x9308\n"  /* mov.w @(0x10,PC),r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x0603B6A4] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_060406B4 */
    ".word 0x06B4\n"  /* mov.b r11,@(r0,r6) */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B6A8, \"ax\"\n"

    ".global _FUN_0603B6A8\n"
    ".type _FUN_0603B6A8, @function\n"
    "_FUN_0603B6A8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xDE1C\n"  /* mov.l @(0x70,PC),r14  {[0x0603B724] = 0x060A4D14} */
    ".word 0x9033\n"  /* mov.w @(0x66,PC),r0 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8906\n"  /* bt 0x0603B6CA */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8B04\n"  /* bf 0x0603B6CA */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x902C\n"  /* mov.w @(0x58,PC),r0 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x3433\n"  /* cmp/ge r3,r4 */
    ".word 0x8B04\n"  /* bf 0x0603B6D4 */
    ".word 0xE0F6\n"  /* mov #-10,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x9123\n"  /* mov.w @(0x46,PC),r1 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B0B\n"  /* bf 0x0603B6F6 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x901C\n"  /* mov.w @(0x38,PC),r0 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0603B728] = 0x0603F1F0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0xE60C\n"  /* mov #12,r6 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0603B72C] = 0x060360FC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xA00A\n"  /* bra 0x0603B70A */
    ".word 0x0009\n"  /* nop */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0603B730] = 0x0603F1E0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0xE60C\n"  /* mov #12,r6 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0603B72C] = 0x060360FC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA114\n"  /* bra 0x0603B93C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0x0098\n"  /* .word 0x0098 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF1F0\n"  /* .word 0xF1F0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x60FC\n"  /* extu.b r15,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF1E0\n"  /* .word 0xF1E0 */
    ".global _FUN_0603b734\n"
    "_FUN_0603b734:\n"
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x0603B7AC] = 0x060A4D14} */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0603B7B0] = 0x060402BC} */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0603B7B4] = 0x0604053A} */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0603B7B8] = 0x060406A6} */
    ".word 0x1432\n"  /* mov.l r3,@(0x8,r4) */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0603B7BC] = 0x0604069A} */
    ".word 0x000B\n"  /* rts */
    ".word 0x1423\n"  /* mov.l r2,@(0xC,r4) */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603B92C, \"ax\"\n"

    ".global _FUN_0603B92C\n"
    ".type _FUN_0603B92C, @function\n"
    "_FUN_0603B92C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xBFC0\n"  /* bsr 0x0603B8B4 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xAFDC\n"  /* bra 0x0603B8F4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603BE9C, \"ax\"\n"

    ".global _FUN_0603BE9C\n"
    ".type _FUN_0603BE9C, @function\n"
    "_FUN_0603BE9C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE01D\n"  /* mov #29,r0 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x5BF5\n"  /* mov.l @(0x14,r15),r11 */
    ".word 0x5CF6\n"  /* mov.l @(0x18,r15),r12 */
    ".word 0x5DF7\n"  /* mov.l @(0x1C,r15),r13 */
    ".word 0x5EF8\n"  /* mov.l @(0x20,r15),r14 */
    ".word 0x004C\n"  /* mov.b @(r0,r4),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC860\n"  /* tst #0x60,r0 */
    ".word 0x8B07\n"  /* bf 0x0603BEC8 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603BEB8, \"ax\"\n"

    ".global _FUN_0603BEB8\n"
    ".type _FUN_0603BEB8, @function\n"
    "_FUN_0603BEB8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0603BF18] = 0x06040220} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0xA022\n"  /* bra 0x0603BF0C */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8901\n"  /* bt 0x0603BED0 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8901\n"  /* bt 0x0603BED8 */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x2632\n"  /* mov.l r3,@r6 */
    ".word 0x2DD8\n"  /* tst r13,r13 */
    ".word 0x8903\n"  /* bt 0x0603BEE4 */
    ".word 0xE01C\n"  /* mov #28,r0 */
    ".word 0x034C\n"  /* mov.b @(r0,r4),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8901\n"  /* bt 0x0603BEEC */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x2732\n"  /* mov.l r3,@r7 */
    ".word 0x2BB8\n"  /* tst r11,r11 */
    ".word 0x8901\n"  /* bt 0x0603BEF4 */
    ".word 0x5344\n"  /* mov.l @(0x10,r4),r3 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0x2EE8\n"  /* tst r14,r14 */
    ".word 0x8903\n"  /* bt 0x0603BF00 */
    ".word 0xE01D\n"  /* mov #29,r0 */
    ".word 0x034C\n"  /* mov.b @(r0,r4),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x2CC8\n"  /* tst r12,r12 */
    ".word 0x8903\n"  /* bt 0x0603BF0C */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x5245\n"  /* mov.l @(0x14,r4),r2 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0220\n"  /* .word 0x0220 */
    ".word 0x504A\n"  /* mov.l @(0x28,r4),r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x145A\n"  /* mov.l r5,@(0x28,r4) */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603C10C, \"ax\"\n"

    ".global _FUN_0603C10C\n"
    ".type _FUN_0603C10C, @function\n"
    "_FUN_0603C10C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDC1B\n"  /* mov.l @(0x6C,PC),r12  {[0x0603C17C] = 0x060A4D60} */
    ".word 0xB624\n"  /* bsr 0x0603CD5C */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0603C180] = 0x0603D2CC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0603C184] = 0x0603D3A8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0603C188] = 0x0603D438} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0603C18C] = 0x0603D514} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0603C190] = 0x0603D5D0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64EC\n"  /* extu.b r14,r4 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x634C\n"  /* extu.b r4,r3 */
    ".word 0x33D3\n"  /* cmp/ge r13,r3 */
    ".word 0x8FF9\n"  /* bf/s 0x0603C134 */
    ".word 0x0CE6\n"  /* mov.l r14,@(r0,r12) */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0603C194] = 0x060A4D80} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x0603C198] = 0x060A4DA6} */
    ".word 0x22E0\n"  /* mov.b r14,@r2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x0603C19C] = 0x060A3D96} */
    ".word 0x930F\n"  /* mov.w @(0x1E,PC),r3 */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x3000\n"  /* cmp/eq r0,r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D60\n"  /* .word 0x4D60 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603D2CC */
    ".word 0xD2CC\n"  /* mov.l @(0x330,PC),r2  {[0x0603C4B4] = 0x22C9622D} */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603D3A8 */
    ".word 0xD3A8\n"  /* mov.l @(0x2A0,PC),r3  {[0x0603C428] = 0x85D2600D} */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603D438 */
    ".word 0xD438\n"  /* mov.l @(0xE0,PC),r4  {[0x0603C26C] = 0xD344430B} */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603D514 */
    ".word 0xD514\n"  /* mov.l @(0x50,PC),r5  {[0x0603C1E0] = 0x816662E3} */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603D5D0 */
    ".word 0xD5D0\n"  /* mov.l @(0x340,PC),r5  {[0x0603C4D4] = 0x85666203} */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D80\n"  /* .word 0x4D80 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4DA6\n"  /* .word 0x4DA6 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D96\n"  /* cmp/hi r9,r13 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xD227\n"  /* mov.l @(0x9C,PC),r2  {[0x0603C240] = 0x060A4DA6} */
    ".word 0x000B\n"  /* rts */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603D2D0, \"ax\"\n"

    ".global _FUN_0603D2D0\n"
    ".type _FUN_0603D2D0, @function\n"
    "_FUN_0603D2D0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD72F\n"  /* mov.l @(0xBC,PC),r7  {[0x0603D394] = 0x0000FFF0} */
    ".word 0xD530\n"  /* mov.l @(0xC0,PC),r5  {[0x0603D398] = 0x060A4D58} */
    ".word 0xD430\n"  /* mov.l @(0xC0,PC),r4  {[0x0603D39C] = 0x060A4D28} */
    ".word 0x915A\n"  /* mov.w @(0xB4,PC),r1 */
    ".word 0xD330\n"  /* mov.l @(0xC0,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2421\n"  /* mov.w r2,@r4 */
    ".word 0xDE2D\n"  /* mov.l @(0xB4,PC),r14  {[0x0603D3A4] = 0x0000F0FF} */
    ".word 0x9150\n"  /* mov.w @(0xA0,PC),r1 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2421\n"  /* mov.w r2,@r4 */
    ".word 0x9147\n"  /* mov.w @(0x8E,PC),r1 */
    ".word 0xD327\n"  /* mov.l @(0x9C,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8141\n"  /* mov.w r0,@(0x2,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x913C\n"  /* mov.w @(0x78,PC),r1 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8141\n"  /* mov.w r0,@(0x2,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9131\n"  /* mov.w @(0x62,PC),r1 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9126\n"  /* mov.w @(0x4C,PC),r1 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x911B\n"  /* mov.w @(0x36,PC),r1 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8543\n"  /* mov.w @(0x6,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9110\n"  /* mov.w @(0x20,PC),r1 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8543\n"  /* mov.w @(0x6,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9105\n"  /* mov.w @(0xA,PC),r1 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0603D3A0] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0101\n"  /* .word 0x0101 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFF0\n"  /* .word 0xFFF0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D58\n"  /* .word 0x4D58 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D28\n"  /* shll16 r13 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4F78\n"  /* .word 0x4F78 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF0FF\n"  /* .word 0xF0FF */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603D43C, \"ax\"\n"

    ".global _FUN_0603D43C\n"
    ".type _FUN_0603D43C, @function\n"
    "_FUN_0603D43C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD730\n"  /* mov.l @(0xC0,PC),r7  {[0x0603D504] = 0x0000FF00} */
    ".word 0xD531\n"  /* mov.l @(0xC4,PC),r5  {[0x0603D508] = 0x060A4D58} */
    ".word 0xD431\n"  /* mov.l @(0xC4,PC),r4  {[0x0603D50C] = 0x060A4D36} */
    ".word 0x915A\n"  /* mov.w @(0xB4,PC),r1 */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2421\n"  /* mov.w r2,@r4 */
    ".word 0x9E52\n"  /* mov.w @(0xA4,PC),r14 */
    ".word 0x9150\n"  /* mov.w @(0xA0,PC),r1 */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2421\n"  /* mov.w r2,@r4 */
    ".word 0x9147\n"  /* mov.w @(0x8E,PC),r1 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8141\n"  /* mov.w r0,@(0x2,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x913C\n"  /* mov.w @(0x78,PC),r1 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8141\n"  /* mov.w r0,@(0x2,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9131\n"  /* mov.w @(0x62,PC),r1 */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9126\n"  /* mov.w @(0x4C,PC),r1 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x911B\n"  /* mov.w @(0x36,PC),r1 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8543\n"  /* mov.w @(0x6,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9110\n"  /* mov.w @(0x20,PC),r1 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9105\n"  /* mov.w @(0xA,PC),r1 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0603D510] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0301\n"  /* .word 0x0301 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D58\n"  /* .word 0x4D58 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D36\n"  /* .word 0x4D36 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4F78\n"  /* .word 0x4F78 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603D518, \"ax\"\n"

    ".global _FUN_0603D518\n"
    ".type _FUN_0603D518, @function\n"
    "_FUN_0603D518:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD728\n"  /* mov.l @(0xA0,PC),r7  {[0x0603D5C0] = 0x0000FF00} */
    ".word 0xD529\n"  /* mov.l @(0xA4,PC),r5  {[0x0603D5C4] = 0x060A4D58} */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x0603D5C8] = 0x060A4D3E} */
    ".word 0x914B\n"  /* mov.w @(0x96,PC),r1 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0603D5CC] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x2421\n"  /* mov.w r2,@r4 */
    ".word 0x9E43\n"  /* mov.w @(0x86,PC),r14 */
    ".word 0x9141\n"  /* mov.w @(0x82,PC),r1 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x0603D5CC] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x2421\n"  /* mov.w r2,@r4 */
    ".word 0x9138\n"  /* mov.w @(0x70,PC),r1 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0603D5CC] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8141\n"  /* mov.w r0,@(0x2,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x912D\n"  /* mov.w @(0x5A,PC),r1 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0603D5CC] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8141\n"  /* mov.w r0,@(0x2,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9122\n"  /* mov.w @(0x44,PC),r1 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0603D5CC] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x911B\n"  /* mov.w @(0x36,PC),r1 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0603D5CC] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8543\n"  /* mov.w @(0x6,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2279\n"  /* and r7,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9110\n"  /* mov.w @(0x20,PC),r1 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0603D5CC] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x8543\n"  /* mov.w @(0x6,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8143\n"  /* mov.w r0,@(0x6,r4) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x9105\n"  /* mov.w @(0xA,PC),r1 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0603D5CC] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0401\n"  /* .word 0x0401 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D58\n"  /* .word 0x4D58 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D3E\n"  /* .word 0x4D3E */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4F78\n"  /* .word 0x4F78 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603D7B0, \"ax\"\n"

    ".global _FUN_0603D7B0\n"
    ".type _FUN_0603D7B0, @function\n"
    "_FUN_0603D7B0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0xEE02\n"  /* mov #2,r14 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDC42\n"  /* mov.l @(0x108,PC),r12  {[0x0603D8C8] = 0x0000FFFE} */
    ".word 0xD742\n"  /* mov.l @(0x108,PC),r7  {[0x0603D8CC] = 0x060A4D58} */
    ".word 0xD543\n"  /* mov.l @(0x10C,PC),r5  {[0x0603D8D0] = 0x060A4D18} */
    ".word 0xD343\n"  /* mov.l @(0x10C,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x6DC3\n"  /* mov r12,r13 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x7DFF\n"  /* add #-1,r13 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0xD341\n"  /* mov.l @(0x104,PC),r3  {[0x0603D8D8] = 0x0000FEFF} */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD33C\n"  /* mov.l @(0xF0,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22C9\n"  /* and r12,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD336\n"  /* mov.l @(0xD8,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22D9\n"  /* and r13,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x0603D8DC] = 0x0000FFFB} */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x0603D8E0] = 0x0000FFF7} */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0xD327\n"  /* mov.l @(0x9C,PC),r3  {[0x0603D8E4] = 0x0000FFEF} */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x602D\n"  /* extu.w r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0603D8E8] = 0x0000FFDF} */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B01\n"  /* bf 0x0603D874 */
    ".word 0xA0A9\n"  /* bra 0x0603D9C6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0603D8D8] = 0x0000FEFF} */
    ".word 0x911F\n"  /* mov.w @(0x3E,PC),r1 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x221B\n"  /* or r1,r2 */
    ".word 0xE304\n"  /* mov #4,r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2349\n"  /* and r4,r3 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890C\n"  /* bt 0x0603D8B4 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0603D8D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22C9\n"  /* and r12,r2 */
    ".word 0x226B\n"  /* or r6,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x23E9\n"  /* and r14,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8922\n"  /* bt 0x0603D902 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xA014\n"  /* bra 0x0603D8EC */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFE\n"  /* .word 0xFFFE */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D58\n"  /* .word 0x4D58 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D18\n"  /* shll8 r13 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4F78\n"  /* .word 0x4F78 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFEFF\n"  /* .word 0xFEFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFB\n"  /* .word 0xFFFB */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFF7\n"  /* .word 0xFFF7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFEF\n"  /* .word 0xFFEF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFDF\n"  /* .word 0xFFDF */
    ".word 0xD339\n"  /* mov.l @(0xE4,PC),r3  {[0x0603D9D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22C9\n"  /* and r12,r2 */
    ".word 0x226B\n"  /* or r6,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0x2349\n"  /* and r4,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890C\n"  /* bt 0x0603D924 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xD331\n"  /* mov.l @(0xC4,PC),r3  {[0x0603D9D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22D9\n"  /* and r13,r2 */
    ".word 0x22EB\n"  /* or r14,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x9354\n"  /* mov.w @(0xA8,PC),r3 */
    ".word 0x2349\n"  /* and r4,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890C\n"  /* bt 0x0603D946 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0603D9D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x22D9\n"  /* and r13,r2 */
    ".word 0x22EB\n"  /* or r14,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0xE310\n"  /* mov #16,r3 */
    ".word 0x2349\n"  /* and r4,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890B\n"  /* bt 0x0603D966 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0603D9D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0603D9D8] = 0x0000FFFB} */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xCB04\n"  /* or #0x04,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0xE220\n"  /* mov #32,r2 */
    ".word 0x2249\n"  /* and r4,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x890B\n"  /* bt 0x0603D986 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0603D9D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0603D9DC] = 0x0000FFF7} */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xCB08\n"  /* or #0x08,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x6243\n"  /* mov r4,r2 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x890B\n"  /* bt 0x0603D9A6 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0603D9D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0603D9E0] = 0x0000FFEF} */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xCB10\n"  /* or #0x10,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0xD20F\n"  /* mov.l @(0x3C,PC),r2  {[0x0603D9E4] = 0x00080000} */
    ".word 0x2429\n"  /* and r2,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x890B\n"  /* bt 0x0603D9C6 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0603D9D4] = 0x06034F78} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE101\n"  /* mov #1,r1 */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0603D9E8] = 0x0000FFDF} */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xCB20\n"  /* or #0x20,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4F78\n"  /* .word 0x4F78 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFB\n"  /* .word 0xFFFB */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFF7\n"  /* .word 0xFFF7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFEF\n"  /* .word 0xFFEF */
    ".word 0x0008\n"  /* clrt */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFDF\n"  /* .word 0xFFDF */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603DB28, \"ax\"\n"

    ".global _FUN_0603DB28\n"
    ".type _FUN_0603DB28, @function\n"
    "_FUN_0603DB28:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xDA18\n"  /* mov.l @(0x60,PC),r10  {[0x0603DBA0] = 0x060A4C80} */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x81F2\n"  /* mov.w r0,@(0x4,r15) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8D0A\n"  /* bt/s 0x0603DB5E */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8907\n"  /* bt 0x0603DB5E */
    ".word 0x9326\n"  /* mov.w @(0x4C,PC),r3 */
    ".word 0x3630\n"  /* cmp/eq r3,r6 */
    ".word 0x8B02\n"  /* bf 0x0603DB5A */
    ".word 0x6073\n"  /* mov r7,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8901\n"  /* bt 0x0603DB5E */
    ".word 0xA13C\n"  /* bra 0x0603DDD6 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0x6073\n"  /* mov r7,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8906\n"  /* bt 0x0603DB72 */
    ".word 0x6073\n"  /* mov r7,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8903\n"  /* bt 0x0603DB72 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8901\n"  /* bt 0x0603DB72 */
    ".word 0xA132\n"  /* bra 0x0603DDD6 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0x636C\n"  /* extu.b r6,r3 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x0603DBA4] = 0x060A4C58} */
    ".word 0x617C\n"  /* extu.b r7,r1 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x0603DBA8] = 0x060A4C59} */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8F06\n"  /* bf/s 0x0603DB90 */
    ".word 0x2210\n"  /* mov.b r1,@r2 */
    ".word 0x6073\n"  /* mov r7,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B02\n"  /* bf 0x0603DB90 */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0xA010\n"  /* bra 0x0603DBB0 */
    ".word 0x2A21\n"  /* mov.w r2,@r10 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8B0B\n"  /* bf 0x0603DBAC */
    ".word 0x6073\n"  /* mov r7,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B08\n"  /* bf 0x0603DBAC */
    ".word 0xA008\n"  /* bra 0x0603DBAE */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C80\n"  /* .word 0x4C80 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C58\n"  /* .word 0x4C58 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C59\n"  /* .word 0x4C59 */
    ".word 0x62DD\n"  /* extu.w r13,r2 */
    ".word 0x2A21\n"  /* mov.w r2,@r10 */
    ".word 0x63A1\n"  /* mov.w @r10,r3 */
    ".word 0xD242\n"  /* mov.l @(0x108,PC),r2  {[0x0603DCBC] = 0x060A3E38} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xD442\n"  /* mov.l @(0x108,PC),r4  {[0x0603DCC0] = 0x060A4C70} */
    ".word 0x24D2\n"  /* mov.l r13,@r4 */
    ".word 0x14D1\n"  /* mov.l r13,@(0x4,r4) */
    ".word 0xD541\n"  /* mov.l @(0x104,PC),r5  {[0x0603DCC4] = 0x060A4C60} */
    ".word 0x25D2\n"  /* mov.l r13,@r5 */
    ".word 0xD441\n"  /* mov.l @(0x104,PC),r4  {[0x0603DCC8] = 0x060A4C68} */
    ".word 0x24D2\n"  /* mov.l r13,@r4 */
    ".word 0x15D1\n"  /* mov.l r13,@(0x4,r5) */
    ".word 0x14D1\n"  /* mov.l r13,@(0x4,r4) */
    ".word 0xD440\n"  /* mov.l @(0x100,PC),r4  {[0x0603DCCC] = 0x060A53A8} */
    ".word 0xD041\n"  /* mov.l @(0x104,PC),r0  {[0x0603DCD0] = 0x060635AE} */
    ".word 0x6B43\n"  /* mov r4,r11 */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xD33F\n"  /* mov.l @(0xFC,PC),r3  {[0x0603DCD4] = 0x060358EC} */
    ".word 0x4001\n"  /* shlr r0 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD23D\n"  /* mov.l @(0xF4,PC),r2  {[0x0603DCD8] = 0x40F00000} */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0xD23D\n"  /* mov.l @(0xF4,PC),r2  {[0x0603DCDC] = 0x060359E4} */
    ".word 0x7310\n"  /* add #16,r3 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD33C\n"  /* mov.l @(0xF0,PC),r3  {[0x0603DCE0] = 0x060357B8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2B02\n"  /* mov.l r0,@r11 */
    ".word 0xD53B\n"  /* mov.l @(0xEC,PC),r5  {[0x0603DCE4] = 0x060A53B0} */
    ".word 0xD93B\n"  /* mov.l @(0xEC,PC),r9  {[0x0603DCE8] = 0x060635B0} */
    ".word 0x6C53\n"  /* mov r5,r12 */
    ".word 0x6091\n"  /* mov.w @r9,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x4001\n"  /* shlr r0 */
    ".word 0xD333\n"  /* mov.l @(0xCC,PC),r3  {[0x0603DCD4] = 0x060358EC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD232\n"  /* mov.l @(0xC8,PC),r2  {[0x0603DCD8] = 0x40F00000} */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0xD231\n"  /* mov.l @(0xC4,PC),r2  {[0x0603DCDC] = 0x060359E4} */
    ".word 0x7310\n"  /* add #16,r3 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD330\n"  /* mov.l @(0xC0,PC),r3  {[0x0603DCE0] = 0x060357B8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2C02\n"  /* mov.l r0,@r12 */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x1531\n"  /* mov.l r3,@(0x4,r5) */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x0603DCEC] = 0x060A4C5C} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x0603DCF0] = 0x060635B2} */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xD82E\n"  /* mov.l @(0xB8,PC),r8  {[0x0603DCF4] = 0x0603C08C} */
    ".word 0xDE2E\n"  /* mov.l @(0xB8,PC),r14  {[0x0603DCF8] = 0x060A3E68} */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x1F22\n"  /* mov.l r2,@(0x8,r15) */
    ".word 0xBF21\n"  /* bsr 0x0603DA88 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x3308\n"  /* sub r0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xBECB\n"  /* bsr 0x0603D9EC */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x640B\n"  /* neg r0,r4 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x65C2\n"  /* mov.l @r12,r5 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xBEC3\n"  /* bsr 0x0603D9EC */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x65B2\n"  /* mov.l @r11,r5 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xBF09\n"  /* bsr 0x0603DA88 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x65C2\n"  /* mov.l @r12,r5 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x3208\n"  /* sub r0,r2 */
    ".word 0x1E21\n"  /* mov.l r2,@(0x4,r14) */
    ".word 0x1ED2\n"  /* mov.l r13,@(0x8,r14) */
    ".word 0xBEB2\n"  /* bsr 0x0603D9EC */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x1E03\n"  /* mov.l r0,@(0xC,r14) */
    ".word 0xBEFC\n"  /* bsr 0x0603DA88 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x1E04\n"  /* mov.l r0,@(0x10,r14) */
    ".word 0xBEF9\n"  /* bsr 0x0603DA88 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x1E05\n"  /* mov.l r0,@(0x14,r14) */
    ".word 0xBEA8\n"  /* bsr 0x0603D9EC */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x1E06\n"  /* mov.l r0,@(0x18,r14) */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0603DCFC] = 0x00010000} */
    ".word 0x1E47\n"  /* mov.l r4,@(0x1C,r14) */
    ".word 0x1ED8\n"  /* mov.l r13,@(0x20,r14) */
    ".word 0x1ED9\n"  /* mov.l r13,@(0x24,r14) */
    ".word 0x1EDA\n"  /* mov.l r13,@(0x28,r14) */
    ".word 0x1E4B\n"  /* mov.l r4,@(0x2C,r14) */
    ".word 0x1EDC\n"  /* mov.l r13,@(0x30,r14) */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x0603DCD0] = 0x060635AE} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x4201\n"  /* shlr r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xA023\n"  /* bra 0x0603DD00 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E38\n"  /* sub r3,r14 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C70\n"  /* .word 0x4C70 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C60\n"  /* .word 0x4C60 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C68\n"  /* .word 0x4C68 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x53A8\n"  /* mov.l @(0x20,r10),r3 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35AE\n"  /* .word 0x35AE */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x58EC\n"  /* mov.l @(0x30,r14),r8 */
    ".word 0x40F0\n"  /* .word 0x40F0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x59E4\n"  /* mov.l @(0x10,r14),r9 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x57B8\n"  /* mov.l @(0x20,r11),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x53B0\n"  /* mov.l @(0x0,r11),r3 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35B0\n"  /* cmp/eq r11,r5 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C5C\n"  /* .word 0x4C5C */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35B2\n"  /* cmp/hs r11,r5 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC08C\n"  /* mov.b r0,@(0x8C,GBR) */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E68\n"  /* sub r6,r14 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x0E25\n"  /* mov.w r2,@(r0,r14) */
    ".word 0x6391\n"  /* mov.w @r9,r3 */
    ".word 0xE036\n"  /* mov #54,r0 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0x633F\n"  /* exts.w r3,r3 */
    ".word 0x0E35\n"  /* mov.w r3,@(r0,r14) */
    ".word 0x936B\n"  /* mov.w @(0xD6,PC),r3 */
    ".word 0xE038\n"  /* mov #56,r0 */
    ".word 0x0E35\n"  /* mov.w r3,@(r0,r14) */
    ".word 0xE03C\n"  /* mov #60,r0 */
    ".word 0xD334\n"  /* mov.l @(0xD0,PC),r3  {[0x0603DDEC] = 0x060635AE} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0x0E35\n"  /* mov.w r3,@(r0,r14) */
    ".word 0x6391\n"  /* mov.w @r9,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4301\n"  /* shlr r3 */
    ".word 0xE03E\n"  /* mov #62,r0 */
    ".word 0x0E35\n"  /* mov.w r3,@(r0,r14) */
    ".word 0x63DF\n"  /* exts.w r13,r3 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x0E35\n"  /* mov.w r3,@(r0,r14) */
    ".word 0xE044\n"  /* mov #68,r0 */
    ".word 0x0ED6\n"  /* mov.l r13,@(r0,r14) */
    ".word 0xE048\n"  /* mov #72,r0 */
    ".word 0x0ED6\n"  /* mov.l r13,@(r0,r14) */
    ".word 0xE04C\n"  /* mov #76,r0 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0xE050\n"  /* mov #80,r0 */
    ".word 0x0E46\n"  /* mov.l r4,@(r0,r14) */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B3A\n"  /* bf 0x0603DDC0 */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x0603DDF0] = 0x060A3EE8} */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0x7580\n"  /* add #-128,r5 */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0x5351\n"  /* mov.l @(0x4,r5),r3 */
    ".word 0x1431\n"  /* mov.l r3,@(0x4,r4) */
    ".word 0x5252\n"  /* mov.l @(0x8,r5),r2 */
    ".word 0x1422\n"  /* mov.l r2,@(0x8,r4) */
    ".word 0x5353\n"  /* mov.l @(0xC,r5),r3 */
    ".word 0x1433\n"  /* mov.l r3,@(0xC,r4) */
    ".word 0x5254\n"  /* mov.l @(0x10,r5),r2 */
    ".word 0x1424\n"  /* mov.l r2,@(0x10,r4) */
    ".word 0x5355\n"  /* mov.l @(0x14,r5),r3 */
    ".word 0x1435\n"  /* mov.l r3,@(0x14,r4) */
    ".word 0x5256\n"  /* mov.l @(0x18,r5),r2 */
    ".word 0x1426\n"  /* mov.l r2,@(0x18,r4) */
    ".word 0x5357\n"  /* mov.l @(0x1C,r5),r3 */
    ".word 0x1437\n"  /* mov.l r3,@(0x1C,r4) */
    ".word 0x5258\n"  /* mov.l @(0x20,r5),r2 */
    ".word 0x1428\n"  /* mov.l r2,@(0x20,r4) */
    ".word 0x5359\n"  /* mov.l @(0x24,r5),r3 */
    ".word 0x1439\n"  /* mov.l r3,@(0x24,r4) */
    ".word 0x525A\n"  /* mov.l @(0x28,r5),r2 */
    ".word 0x142A\n"  /* mov.l r2,@(0x28,r4) */
    ".word 0x535B\n"  /* mov.l @(0x2C,r5),r3 */
    ".word 0x143B\n"  /* mov.l r3,@(0x2C,r4) */
    ".word 0x525C\n"  /* mov.l @(0x30,r5),r2 */
    ".word 0x142C\n"  /* mov.l r2,@(0x30,r4) */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x0435\n"  /* mov.w r3,@(r0,r4) */
    ".word 0xE036\n"  /* mov #54,r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x0435\n"  /* mov.w r3,@(r0,r4) */
    ".word 0xE038\n"  /* mov #56,r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x0435\n"  /* mov.w r3,@(r0,r4) */
    ".word 0xE03C\n"  /* mov #60,r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x0435\n"  /* mov.w r3,@(r0,r4) */
    ".word 0xE03E\n"  /* mov #62,r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x0435\n"  /* mov.w r3,@(r0,r4) */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x035D\n"  /* mov.w @(r0,r5),r3 */
    ".word 0x0435\n"  /* mov.w r3,@(r0,r4) */
    ".word 0xE044\n"  /* mov #68,r0 */
    ".word 0x035E\n"  /* mov.l @(r0,r5),r3 */
    ".word 0x0436\n"  /* mov.l r3,@(r0,r4) */
    ".word 0xE048\n"  /* mov #72,r0 */
    ".word 0x035E\n"  /* mov.l @(r0,r5),r3 */
    ".word 0x0436\n"  /* mov.l r3,@(r0,r4) */
    ".word 0xE04C\n"  /* mov #76,r0 */
    ".word 0x035E\n"  /* mov.l @(r0,r5),r3 */
    ".word 0x0436\n"  /* mov.l r3,@(r0,r4) */
    ".word 0xE050\n"  /* mov #80,r0 */
    ".word 0x035E\n"  /* mov.l @(r0,r5),r3 */
    ".word 0x0436\n"  /* mov.l r3,@(r0,r4) */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0603DDF4] = 0x0007FF80} */
    ".word 0x2439\n"  /* and r3,r4 */
    ".word 0x4401\n"  /* shlr r4 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0xC93E\n"  /* and #0x3E,r0 */
    ".word 0x4009\n"  /* shlr2 r0 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0603DDF8] = 0x060A3E44} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xE000\n"  /* mov #0,r0 */
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
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35AE\n"  /* .word 0x35AE */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3EE8\n"  /* sub r14,r14 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0xFF80\n"  /* .word 0xFF80 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E44\n"  /* .word 0x3E44 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603E050, \"ax\"\n"

    ".global _FUN_0603E050\n"
    ".type _FUN_0603E050, @function\n"
    "_FUN_0603E050:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x7FC8\n"  /* add #-56,r15 */
    ".word 0x9824\n"  /* mov.w @(0x48,PC),r8 */
    ".word 0xD913\n"  /* mov.l @(0x4C,PC),r9  {[0x0603E0B4] = 0x00040000} */
    ".word 0xDC13\n"  /* mov.l @(0x4C,PC),r12  {[0x0603E0B8] = 0x00008000} */
    ".word 0xDD14\n"  /* mov.l @(0x50,PC),r13  {[0x0603E0BC] = 0x0603C0A0} */
    ".word 0x1F42\n"  /* mov.l r4,@(0x8,r15) */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x0603E0C0] = 0x060A3E38} */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0603E0C4] = 0x060635A8} */
    ".word 0xA017\n"  /* bra 0x0603E0A4 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x0603E0C8] = 0x0000FF00} */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0xA009\n"  /* bra 0x0603E09C */
    ".word 0xCB03\n"  /* or #0x03,r0 */
    ".word 0xEE01\n"  /* mov #1,r14 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0xC9FF\n"  /* and #0xFF,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x930E\n"  /* mov.w @(0x1C,PC),r3 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0xA016\n"  /* bra 0x0603E0CC */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0xA281\n"  /* bra 0x0603E5A6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89E6\n"  /* bt 0x0603E076 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89EE\n"  /* bt 0x0603E08A */
    ".word 0xAFF8\n"  /* bra 0x0603E0A0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0x0300\n"  /* .word 0x0300 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC0A0\n"  /* mov.b r0,@(0xA0,GBR) */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E38\n"  /* sub r3,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35A8\n"  /* sub r10,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0xBC8E\n"  /* bsr 0x0603D9EC */
    ".word 0x54F2\n"  /* mov.l @(0x8,r15),r4 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0xBCD9\n"  /* bsr 0x0603DA88 */
    ".word 0x54F2\n"  /* mov.l @(0x8,r15),r4 */
    ".word 0x6AEE\n"  /* exts.b r14,r10 */
    ".word 0x1F02\n"  /* mov.l r0,@(0x8,r15) */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x6AAE\n"  /* exts.b r10,r10 */
    ".word 0xD22F\n"  /* mov.l @(0xBC,PC),r2  {[0x0603E1A8] = 0x060A53B8} */
    ".word 0x3A2C\n"  /* add r2,r10 */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x1F3C\n"  /* mov.l r3,@(0x30,r15) */
    ".word 0x6132\n"  /* mov.l @r3,r1 */
    ".word 0x1F13\n"  /* mov.l r1,@(0xC,r15) */
    ".word 0x61A3\n"  /* mov r10,r1 */
    ".word 0x7108\n"  /* add #8,r1 */
    ".word 0x1F1B\n"  /* mov.l r1,@(0x2C,r15) */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0x1F3D\n"  /* mov.l r3,@(0x34,r15) */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x7310\n"  /* add #16,r3 */
    ".word 0x1F3A\n"  /* mov.l r3,@(0x28,r15) */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x1F29\n"  /* mov.l r2,@(0x24,r15) */
    ".word 0x62A3\n"  /* mov r10,r2 */
    ".word 0x7214\n"  /* add #20,r2 */
    ".word 0x1F27\n"  /* mov.l r2,@(0x1C,r15) */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x1F18\n"  /* mov.l r1,@(0x20,r15) */
    ".word 0x61A3\n"  /* mov r10,r1 */
    ".word 0x711C\n"  /* add #28,r1 */
    ".word 0x1F15\n"  /* mov.l r1,@(0x14,r15) */
    ".word 0x6312\n"  /* mov.l @r1,r3 */
    ".word 0x1F36\n"  /* mov.l r3,@(0x18,r15) */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x7320\n"  /* add #32,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x1F24\n"  /* mov.l r2,@(0x10,r15) */
    ".word 0xDB20\n"  /* mov.l @(0x80,PC),r11  {[0x0603E1AC] = 0x0603C08C} */
    ".word 0x52FC\n"  /* mov.l @(0x30,r15),r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F4\n"  /* mov.l @(0x10,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FF\n"  /* mov.l @(0x3C,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x53FB\n"  /* mov.l @(0x2C,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F4\n"  /* mov.l @(0x10,r15),r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F4\n"  /* mov.l @(0x10,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FF\n"  /* mov.l @(0x3C,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x53FA\n"  /* mov.l @(0x28,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FA\n"  /* mov.l @(0x28,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FA\n"  /* mov.l @(0x28,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x53F7\n"  /* mov.l @(0x1C,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FA\n"  /* mov.l @(0x28,r15),r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F4\n"  /* mov.l @(0x10,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FA\n"  /* mov.l @(0x28,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F7\n"  /* mov.l @(0x1C,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0xA004\n"  /* bra 0x0603E1B0 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x53B8\n"  /* mov.l @(0x20,r11),r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC08C\n"  /* mov.b r0,@(0x8C,GBR) */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x0009\n"  /* nop */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F7\n"  /* mov.l @(0x1C,r15),r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F4\n"  /* mov.l @(0x10,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x64ED\n"  /* extu.w r14,r4 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0xD336\n"  /* mov.l @(0xD8,PC),r3  {[0x0603E2BC] = 0x060A3E68} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x1427\n"  /* mov.l r2,@(0x1C,r4) */
    ".word 0x53FC\n"  /* mov.l @(0x30,r15),r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x1428\n"  /* mov.l r2,@(0x20,r4) */
    ".word 0x53FB\n"  /* mov.l @(0x2C,r15),r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x1429\n"  /* mov.l r2,@(0x24,r4) */
    ".word 0x53FA\n"  /* mov.l @(0x28,r15),r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x142B\n"  /* mov.l r2,@(0x2C,r4) */
    ".word 0x53F7\n"  /* mov.l @(0x1C,r15),r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x142C\n"  /* mov.l r2,@(0x30,r4) */
    ".word 0x57A6\n"  /* mov.l @(0x18,r10),r7 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x064D\n"  /* mov.w @(r0,r4),r6 */
    ".word 0xE03C\n"  /* mov #60,r0 */
    ".word 0x034D\n"  /* mov.w @(r0,r4),r3 */
    ".word 0x6B63\n"  /* mov r6,r11 */
    ".word 0x3B38\n"  /* sub r3,r11 */
    ".word 0x07B7\n"  /* mul.l r11,r7 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0xE036\n"  /* mov #54,r0 */
    ".word 0x0B1A\n"  /* sts macl,r11 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x024D\n"  /* mov.w @(r0,r4),r2 */
    ".word 0xE03E\n"  /* mov #62,r0 */
    ".word 0x014D\n"  /* mov.w @(r0,r4),r1 */
    ".word 0xE038\n"  /* mov #56,r0 */
    ".word 0x3218\n"  /* sub r1,r2 */
    ".word 0x0327\n"  /* mul.l r2,r3 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x3B3C\n"  /* add r3,r11 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x1F32\n"  /* mov.l r3,@(0x8,r15) */
    ".word 0x034D\n"  /* mov.w @(r0,r4),r3 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x054D\n"  /* mov.w @(r0,r4),r5 */
    ".word 0x51F2\n"  /* mov.l @(0x8,r15),r1 */
    ".word 0x3358\n"  /* sub r5,r3 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x0137\n"  /* mul.l r3,r1 */
    ".word 0x600F\n"  /* exts.w r0,r0 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0603E2C0] = 0x060358EC} */
    ".word 0x3B1C\n"  /* add r1,r11 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0603E2C4] = 0x40F00000} */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x0603E2C8] = 0x060359E4} */
    ".word 0x7310\n"  /* add #16,r3 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0603E2CC] = 0x060357B8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3B0C\n"  /* add r0,r11 */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0x0677\n"  /* mul.l r7,r6 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x061A\n"  /* sts macl,r6 */
    ".word 0x1F33\n"  /* mov.l r3,@(0xC,r15) */
    ".word 0x666B\n"  /* neg r6,r6 */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x0603E2D0] = 0x060A4C78} */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x3B1C\n"  /* add r1,r11 */
    ".word 0x51F2\n"  /* mov.l @(0x8,r15),r1 */
    ".word 0x0217\n"  /* mul.l r1,r2 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x3628\n"  /* sub r2,r6 */
    ".word 0x1F62\n"  /* mov.l r6,@(0x8,r15) */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x0603E2D4] = 0x060A4C70} */
    ".word 0x022E\n"  /* mov.l @(r0,r2),r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B01\n"  /* bf 0x0603E296 */
    ".word 0xA0AC\n"  /* bra 0x0603E3EE */
    ".word 0x0009\n"  /* nop */
    ".word 0x6AED\n"  /* extu.w r14,r10 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4A00\n"  /* shll r10 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x0603E2BC] = 0x060A3E68} */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x52A1\n"  /* mov.l @(0x4,r10),r2 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x0603E2D8] = 0x012C0000} */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0xE054\n"  /* mov #84,r0 */
    ".word 0x0A26\n"  /* mov.l r2,@(r0,r10) */
    ".word 0x64ED\n"  /* extu.w r14,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0603E2D4] = 0x060A4C70} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xA010\n"  /* bra 0x0603E2DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E68\n"  /* sub r6,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x58EC\n"  /* mov.l @(0x30,r14),r8 */
    ".word 0x40F0\n"  /* .word 0x40F0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x59E4\n"  /* mov.l @(0x10,r14),r9 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x57B8\n"  /* mov.l @(0x20,r11),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C78\n"  /* .word 0x4C78 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C70\n"  /* .word 0x4C70 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1F41\n"  /* mov.l r4,@(0x4,r15) */
    ".word 0xBBD3\n"  /* bsr 0x0603DA88 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xE158\n"  /* mov #88,r1 */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x54F1\n"  /* mov.l @(0x4,r15),r4 */
    ".word 0xBB7F\n"  /* bsr 0x0603D9EC */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xE15C\n"  /* mov #92,r1 */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0xD231\n"  /* mov.l @(0xC4,PC),r2  {[0x0603E3C0] = 0x060A4C38} */
    ".word 0x915C\n"  /* mov.w @(0xB8,PC),r1 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0x61EE\n"  /* exts.b r14,r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x1F33\n"  /* mov.l r3,@(0xC,r15) */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x611E\n"  /* exts.b r1,r1 */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x0603E3C4] = 0x060A53B8} */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x711C\n"  /* add #28,r1 */
    ".word 0x1F14\n"  /* mov.l r1,@(0x10,r15) */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0xD027\n"  /* mov.l @(0x9C,PC),r0  {[0x0603E3C8] = 0x060A3E68} */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x1F35\n"  /* mov.l r3,@(0x14,r15) */
    ".word 0x9242\n"  /* mov.w @(0x84,PC),r2 */
    ".word 0x2E2F\n"  /* muls.w r2,r14 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xD024\n"  /* mov.l @(0x90,PC),r0  {[0x0603E3CC] = 0x060A3F68} */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0xA051\n"  /* bra 0x0603E3E2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0xE036\n"  /* mov #54,r0 */
    ".word 0x61A3\n"  /* mov r10,r1 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x033D\n"  /* mov.w @(r0,r3),r3 */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x9334\n"  /* mov.w @(0x68,PC),r3 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x0217\n"  /* mul.l r1,r2 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x2F12\n"  /* mov.l r1,@r15 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0603E3D0] = 0x06034FFC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6083\n"  /* mov r8,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8936\n"  /* bt 0x0603E3D4 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x3097\n"  /* cmp/gt r9,r0 */
    ".word 0x8905\n"  /* bt 0x0603E37E */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8905\n"  /* bt 0x0603E38A */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0xA029\n"  /* bra 0x0603E3DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x9307\n"  /* mov.w @(0xE,PC),r3 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xA015\n"  /* bra 0x0603E3E0 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x0333\n"  /* .word 0x0333 */
    ".word 0x0668\n"  /* .word 0x0668 */
    ".word 0xFED4\n"  /* .word 0xFED4 */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C38\n"  /* .word 0x4C38 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x53B8\n"  /* mov.l @(0x20,r11),r3 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E68\n"  /* sub r6,r14 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3F68\n"  /* sub r6,r15 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4FFC\n"  /* .word 0x4FFC */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0x2021\n"  /* mov.w r2,@r0 */
    ".word 0x7A01\n"  /* add #1,r10 */
    ".word 0x53F3\n"  /* mov.l @(0xC,r15),r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3A32\n"  /* cmp/hs r3,r10 */
    ".word 0x8BAA\n"  /* bf 0x0603E340 */
    ".word 0xA0D6\n"  /* bra 0x0603E59A */
    ".word 0x0009\n"  /* nop */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x0603E448] = 0x060A4C4C} */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x045E\n"  /* mov.l @(r0,r5),r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x88FF\n"  /* cmp/eq #-1,r0 */
    ".word 0x8931\n"  /* bt 0x0603E460 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x892F\n"  /* bt 0x0603E460 */
    ".word 0x64ED\n"  /* extu.w r14,r4 */
    ".word 0x60ED\n"  /* extu.w r14,r0 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0603E44C] = 0x060A3E68} */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x005E\n"  /* mov.l @(r0,r5),r0 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0603E450] = 0x060358EC} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x3307\n"  /* cmp/gt r0,r3 */
    ".word 0x303E\n"  /* .word 0x303E */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0603E454] = 0x40F00000} */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0603E458] = 0x060359E4} */
    ".word 0x7210\n"  /* add #16,r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0603E45C] = 0x060357B8} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0xE154\n"  /* mov #84,r1 */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0xA017\n"  /* bra 0x0603E474 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C4C\n"  /* .word 0x4C4C */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E68\n"  /* sub r6,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x58EC\n"  /* mov.l @(0x30,r14),r8 */
    ".word 0x40F0\n"  /* .word 0x40F0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x59E4\n"  /* mov.l @(0x10,r14),r9 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x57B8\n"  /* mov.l @(0x20,r11),r7 */
    ".word 0x64ED\n"  /* extu.w r14,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0xD335\n"  /* mov.l @(0xD4,PC),r3  {[0x0603E540] = 0x060A3E68} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0xE054\n"  /* mov #84,r0 */
    ".word 0x0426\n"  /* mov.l r2,@(r0,r4) */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0xD232\n"  /* mov.l @(0xC8,PC),r2  {[0x0603E540] = 0x060A3E68} */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0xE258\n"  /* mov #88,r2 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xBAFD\n"  /* bsr 0x0603DA88 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2302\n"  /* mov.l r0,@r3 */
    ".word 0xE35C\n"  /* mov #92,r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xBAA7\n"  /* bsr 0x0603D9EC */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0xD226\n"  /* mov.l @(0x98,PC),r2  {[0x0603E544] = 0x060A4C38} */
    ".word 0xD127\n"  /* mov.l @(0x9C,PC),r1  {[0x0603E548] = 0x060635B0} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6111\n"  /* mov.w @r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0x61EE\n"  /* exts.b r14,r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x1F34\n"  /* mov.l r3,@(0x10,r15) */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x611E\n"  /* exts.b r1,r1 */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x0603E54C] = 0x060A53B8} */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x711C\n"  /* add #28,r1 */
    ".word 0x1F13\n"  /* mov.l r1,@(0xC,r15) */
    ".word 0x63ED\n"  /* extu.w r14,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0603E540] = 0x060A3E68} */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x1F35\n"  /* mov.l r3,@(0x14,r15) */
    ".word 0x9229\n"  /* mov.w @(0x52,PC),r2 */
    ".word 0x2E2F\n"  /* muls.w r2,r14 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x0603E550] = 0x060A3F68} */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0xA04E\n"  /* bra 0x0603E592 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0xE036\n"  /* mov #54,r0 */
    ".word 0x61A3\n"  /* mov r10,r1 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x033D\n"  /* mov.w @(r0,r3),r3 */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x0317\n"  /* mul.l r1,r3 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x2F12\n"  /* mov.l r1,@r15 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0603E554] = 0x06034FFC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6083\n"  /* mov r8,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8935\n"  /* bt 0x0603E584 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x3097\n"  /* cmp/gt r9,r0 */
    ".word 0x8905\n"  /* bt 0x0603E530 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8913\n"  /* bt 0x0603E558 */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0xA028\n"  /* bra 0x0603E58C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0668\n"  /* .word 0x0668 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E68\n"  /* sub r6,r14 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C38\n"  /* .word 0x4C38 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35B0\n"  /* cmp/eq r11,r5 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x53B8\n"  /* mov.l @(0x20,r11),r3 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3F68\n"  /* sub r6,r15 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4FFC\n"  /* .word 0x4FFC */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4D0B\n"  /* jsr @r13 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x9351\n"  /* mov.w @(0xA2,PC),r3 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0xA006\n"  /* bra 0x0603E590 */
    ".word 0x2201\n"  /* mov.w r0,@r2 */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0x2021\n"  /* mov.w r2,@r0 */
    ".word 0x7A01\n"  /* add #1,r10 */
    ".word 0x53F4\n"  /* mov.l @(0x10,r15),r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3A32\n"  /* cmp/hs r3,r10 */
    ".word 0x8BAD\n"  /* bf 0x0603E4F6 */
    ".word 0x6EED\n"  /* extu.w r14,r14 */
    ".word 0x4E00\n"  /* shll r14 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0603E624] = 0x060A4C40} */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x2E21\n"  /* mov.w r2,@r14 */
    ".word 0x7F38\n"  /* add #56,r15 */
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
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603E5BC, \"ax\"\n"

    ".global _FUN_0603E5BC\n"
    ".type _FUN_0603E5BC, @function\n"
    "_FUN_0603E5BC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x7FCC\n"  /* add #-52,r15 */
    ".word 0xD815\n"  /* mov.l @(0x54,PC),r8  {[0x0603E628] = 0x00040000} */
    ".word 0x9924\n"  /* mov.w @(0x48,PC),r9 */
    ".word 0x6C93\n"  /* mov r9,r12 */
    ".word 0x7C01\n"  /* add #1,r12 */
    ".word 0xDE14\n"  /* mov.l @(0x50,PC),r14  {[0x0603E62C] = 0x0603C0A0} */
    ".word 0x1F42\n"  /* mov.l r4,@(0x8,r15) */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x0603E630] = 0x060A3E38} */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x0603E634] = 0x060635A8} */
    ".word 0xA017\n"  /* bra 0x0603E612 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x0603E638] = 0x0000FF00} */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0xA009\n"  /* bra 0x0603E60A */
    ".word 0xCB03\n"  /* or #0x03,r0 */
    ".word 0xED01\n"  /* mov #1,r13 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0xC9FF\n"  /* and #0xFF,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x930E\n"  /* mov.w @(0x1C,PC),r3 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0xA017\n"  /* bra 0x0603E63C */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0xA252\n"  /* bra 0x0603EAB6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89E6\n"  /* bt 0x0603E5E4 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89EE\n"  /* bt 0x0603E5F8 */
    ".word 0xAFF8\n"  /* bra 0x0603E60E */
    ".word 0x0009\n"  /* nop */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0x0300\n"  /* .word 0x0300 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C40\n"  /* .word 0x4C40 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC0A0\n"  /* mov.b r0,@(0xA0,GBR) */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E38\n"  /* sub r3,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35A8\n"  /* sub r10,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0xB9D6\n"  /* bsr 0x0603D9EC */
    ".word 0x54F2\n"  /* mov.l @(0x8,r15),r4 */
    ".word 0x2F02\n"  /* mov.l r0,@r15 */
    ".word 0xBA21\n"  /* bsr 0x0603DA88 */
    ".word 0x54F2\n"  /* mov.l @(0x8,r15),r4 */
    ".word 0x6ADE\n"  /* exts.b r13,r10 */
    ".word 0x1F02\n"  /* mov.l r0,@(0x8,r15) */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x6AAE\n"  /* exts.b r10,r10 */
    ".word 0xD230\n"  /* mov.l @(0xC0,PC),r2  {[0x0603E71C] = 0x060A53B8} */
    ".word 0x3A2C\n"  /* add r2,r10 */
    ".word 0x63A2\n"  /* mov.l @r10,r3 */
    ".word 0x1F3A\n"  /* mov.l r3,@(0x28,r15) */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x1F36\n"  /* mov.l r3,@(0x18,r15) */
    ".word 0x6132\n"  /* mov.l @r3,r1 */
    ".word 0x1F14\n"  /* mov.l r1,@(0x10,r15) */
    ".word 0x61A3\n"  /* mov r10,r1 */
    ".word 0x710C\n"  /* add #12,r1 */
    ".word 0x1F18\n"  /* mov.l r1,@(0x20,r15) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x1F23\n"  /* mov.l r2,@(0xC,r15) */
    ".word 0x62A3\n"  /* mov r10,r2 */
    ".word 0x7214\n"  /* add #20,r2 */
    ".word 0x1F27\n"  /* mov.l r2,@(0x1C,r15) */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x1F3B\n"  /* mov.l r3,@(0x2C,r15) */
    ".word 0x63A3\n"  /* mov r10,r3 */
    ".word 0x7318\n"  /* add #24,r3 */
    ".word 0x1F35\n"  /* mov.l r3,@(0x14,r15) */
    ".word 0x6132\n"  /* mov.l @r3,r1 */
    ".word 0x1F1C\n"  /* mov.l r1,@(0x30,r15) */
    ".word 0x61A3\n"  /* mov r10,r1 */
    ".word 0x7120\n"  /* add #32,r1 */
    ".word 0x1F11\n"  /* mov.l r1,@(0x4,r15) */
    ".word 0x6212\n"  /* mov.l @r1,r2 */
    ".word 0x1F29\n"  /* mov.l r2,@(0x24,r15) */
    ".word 0xDB23\n"  /* mov.l @(0x8C,PC),r11  {[0x0603E720] = 0x0603C08C} */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FA\n"  /* mov.l @(0x28,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F5\n"  /* mov.l @(0x14,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x3308\n"  /* sub r0,r3 */
    ".word 0x2A32\n"  /* mov.l r3,@r10 */
    ".word 0x52F6\n"  /* mov.l @(0x18,r15),r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FB\n"  /* mov.l @(0x2C,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F4\n"  /* mov.l @(0x10,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F6\n"  /* mov.l @(0x18,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x53F8\n"  /* mov.l @(0x20,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F4\n"  /* mov.l @(0x10,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FD\n"  /* mov.l @(0x34,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x3308\n"  /* sub r0,r3 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x53F7\n"  /* mov.l @(0x1C,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54F4\n"  /* mov.l @(0x10,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F4\n"  /* mov.l @(0x10,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FD\n"  /* mov.l @(0x34,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FD\n"  /* mov.l @(0x34,r15),r4 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F2\n"  /* mov.l @(0x8,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FB\n"  /* mov.l @(0x2C,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x3308\n"  /* sub r0,r3 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0xA005\n"  /* bra 0x0603E724 */
    ".word 0x54FD\n"  /* mov.l @(0x34,r15),r4 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x53B8\n"  /* mov.l @(0x20,r11),r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC08C\n"  /* mov.b r0,@(0x8C,GBR) */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F4\n"  /* mov.l @(0x10,r15),r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x54FB\n"  /* mov.l @(0x2C,r15),r4 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x64DD\n"  /* extu.w r13,r4 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x2202\n"  /* mov.l r0,@r2 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0xD33D\n"  /* mov.l @(0xF4,PC),r3  {[0x0603E838] = 0x060A3E68} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x1427\n"  /* mov.l r2,@(0x1C,r4) */
    ".word 0x53F6\n"  /* mov.l @(0x18,r15),r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x1429\n"  /* mov.l r2,@(0x24,r4) */
    ".word 0x53F8\n"  /* mov.l @(0x20,r15),r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x142A\n"  /* mov.l r2,@(0x28,r4) */
    ".word 0x53A4\n"  /* mov.l @(0x10,r10),r3 */
    ".word 0x143B\n"  /* mov.l r3,@(0x2C,r4) */
    ".word 0x52F7\n"  /* mov.l @(0x1C,r15),r2 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x143C\n"  /* mov.l r3,@(0x30,r4) */
    ".word 0x5BF5\n"  /* mov.l @(0x14,r15),r11 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x034D\n"  /* mov.w @(r0,r4),r3 */
    ".word 0xE03C\n"  /* mov #60,r0 */
    ".word 0x024D\n"  /* mov.w @(r0,r4),r2 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x6BB2\n"  /* mov.l @r11,r11 */
    ".word 0x0B37\n"  /* mul.l r3,r11 */
    ".word 0x0B1A\n"  /* sts macl,r11 */
    ".word 0x53A7\n"  /* mov.l @(0x1C,r10),r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0xE036\n"  /* mov #54,r0 */
    ".word 0x034D\n"  /* mov.w @(r0,r4),r3 */
    ".word 0x1F32\n"  /* mov.l r3,@(0x8,r15) */
    ".word 0xE03E\n"  /* mov #62,r0 */
    ".word 0x024D\n"  /* mov.w @(r0,r4),r2 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x0237\n"  /* mul.l r3,r2 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x3B2C\n"  /* add r2,r11 */
    ".word 0x56F1\n"  /* mov.l @(0x4,r15),r6 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0xE038\n"  /* mov #56,r0 */
    ".word 0x074D\n"  /* mov.w @(r0,r4),r7 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x034D\n"  /* mov.w @(r0,r4),r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x81F6\n"  /* mov.w r0,@(0xC,r15) */
    ".word 0x85F6\n"  /* mov.w @(0xC,r15),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x6273\n"  /* mov r7,r2 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x0627\n"  /* mul.l r2,r6 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x3B3C\n"  /* add r3,r11 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x85FA\n"  /* mov.w @(0x14,r15),r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD223\n"  /* mov.l @(0x8C,PC),r2  {[0x0603E83C] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0603E840] = 0x40F00000} */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0603E844] = 0x060359E4} */
    ".word 0x7210\n"  /* add #16,r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD220\n"  /* mov.l @(0x80,PC),r2  {[0x0603E848] = 0x060357B8} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x3B0C\n"  /* add r0,r11 */
    ".word 0x65DD\n"  /* extu.w r13,r5 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0603E84C] = 0x060A4C78} */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x335C\n"  /* add r5,r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x3B2C\n"  /* add r2,r11 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x0327\n"  /* mul.l r2,r3 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x633B\n"  /* neg r3,r3 */
    ".word 0x0767\n"  /* mul.l r6,r7 */
    ".word 0x071A\n"  /* sts macl,r7 */
    ".word 0x3378\n"  /* sub r7,r3 */
    ".word 0x1F32\n"  /* mov.l r3,@(0x8,r15) */
    ".word 0xD118\n"  /* mov.l @(0x60,PC),r1  {[0x0603E850] = 0x060A4C70} */
    ".word 0x351C\n"  /* add r1,r5 */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x0603E7FA */
    ".word 0xA0BE\n"  /* bra 0x0603E976 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6ADD\n"  /* extu.w r13,r10 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0603E838] = 0x060A3E68} */
    ".word 0xE054\n"  /* mov #84,r0 */
    ".word 0x64DD\n"  /* extu.w r13,r4 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4A00\n"  /* shll r10 */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0603E854] = 0x012C0000} */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x0A26\n"  /* mov.l r2,@(r0,r10) */
    ".word 0x1F41\n"  /* mov.l r4,@(0x4,r15) */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0603E850] = 0x060A4C70} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x0603E858] = 0x005A0000} */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xB930\n"  /* bsr 0x0603DA88 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE158\n"  /* mov #88,r1 */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xA013\n"  /* bra 0x0603E85C */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E68\n"  /* sub r6,r14 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x58EC\n"  /* mov.l @(0x30,r14),r8 */
    ".word 0x40F0\n"  /* .word 0x40F0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x59E4\n"  /* mov.l @(0x10,r14),r9 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x57B8\n"  /* mov.l @(0x20,r11),r7 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C78\n"  /* .word 0x4C78 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C70\n"  /* .word 0x4C70 */
    ".word 0x012C\n"  /* mov.b @(r0,r2),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x005A\n"  /* .word 0x005A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD339\n"  /* mov.l @(0xE4,PC),r3  {[0x0603E944] = 0x005A0000} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xB8C4\n"  /* bsr 0x0603D9EC */
    ".word 0x0009\n"  /* nop */
    ".word 0xE15C\n"  /* mov #92,r1 */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0xD236\n"  /* mov.l @(0xD8,PC),r2  {[0x0603E948] = 0x060A4C38} */
    ".word 0x9163\n"  /* mov.w @(0xC6,PC),r1 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x61DE\n"  /* exts.b r13,r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x1F35\n"  /* mov.l r3,@(0x14,r15) */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x611E\n"  /* exts.b r1,r1 */
    ".word 0xD02D\n"  /* mov.l @(0xB4,PC),r0  {[0x0603E94C] = 0x060A53B8} */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x7118\n"  /* add #24,r1 */
    ".word 0x1F14\n"  /* mov.l r1,@(0x10,r15) */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0xD02B\n"  /* mov.l @(0xAC,PC),r0  {[0x0603E950] = 0x060A3E68} */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x1F33\n"  /* mov.l r3,@(0xC,r15) */
    ".word 0x9249\n"  /* mov.w @(0x92,PC),r2 */
    ".word 0x2D2F\n"  /* muls.w r2,r13 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xD029\n"  /* mov.l @(0xA4,PC),r0  {[0x0603E954] = 0x060A3F68} */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0xA05A\n"  /* bra 0x0603E96A */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x61A3\n"  /* mov r10,r1 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x53F3\n"  /* mov.l @(0xC,r15),r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x033D\n"  /* mov.w @(r0,r3),r3 */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x933B\n"  /* mov.w @(0x76,PC),r3 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x0217\n"  /* mul.l r1,r2 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x2F12\n"  /* mov.l r1,@r15 */
    ".word 0x9035\n"  /* mov.w @(0x6A,PC),r0 */
    ".word 0xD220\n"  /* mov.l @(0x80,PC),r2  {[0x0603E958] = 0x06034FFC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893E\n"  /* bt 0x0603E95C */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x3087\n"  /* cmp/gt r8,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xCA01\n"  /* xor #0x01,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x203B\n"  /* or r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8905\n"  /* bt 0x0603E90E */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0xA02B\n"  /* bra 0x0603E964 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2099\n"  /* and r9,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0xA017\n"  /* bra 0x0603E968 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0333\n"  /* .word 0x0333 */
    ".word 0x0668\n"  /* .word 0x0668 */
    ".word 0xFED4\n"  /* .word 0xFED4 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x005A\n"  /* .word 0x005A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C38\n"  /* .word 0x4C38 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x53B8\n"  /* mov.l @(0x20,r11),r3 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E68\n"  /* sub r6,r14 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3F68\n"  /* sub r6,r15 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4FFC\n"  /* .word 0x4FFC */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0x2021\n"  /* mov.w r2,@r0 */
    ".word 0x7A01\n"  /* add #1,r10 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3A32\n"  /* cmp/hs r3,r10 */
    ".word 0x8BA1\n"  /* bf 0x0603E8B6 */
    ".word 0xA09A\n"  /* bra 0x0603EAAA */
    ".word 0x0009\n"  /* nop */
    ".word 0x6ADD\n"  /* extu.w r13,r10 */
    ".word 0xD334\n"  /* mov.l @(0xD0,PC),r3  {[0x0603EA4C] = 0x060A3E68} */
    ".word 0xE054\n"  /* mov #84,r0 */
    ".word 0xD434\n"  /* mov.l @(0xD0,PC),r4  {[0x0603EA50] = 0x005A0000} */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4A08\n"  /* shll2 r10 */
    ".word 0x4A00\n"  /* shll r10 */
    ".word 0x3A3C\n"  /* add r3,r10 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0xB87D\n"  /* bsr 0x0603DA88 */
    ".word 0x0A26\n"  /* mov.l r2,@(r0,r10) */
    ".word 0xE158\n"  /* mov #88,r1 */
    ".word 0xD42F\n"  /* mov.l @(0xBC,PC),r4  {[0x0603EA50] = 0x005A0000} */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0xB82A\n"  /* bsr 0x0603D9EC */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0xE15C\n"  /* mov #92,r1 */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x31AC\n"  /* add r10,r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0xEA00\n"  /* mov #0,r10 */
    ".word 0xD22B\n"  /* mov.l @(0xAC,PC),r2  {[0x0603EA54] = 0x060A4C38} */
    ".word 0xD12C\n"  /* mov.l @(0xB0,PC),r1  {[0x0603EA58] = 0x060635AE} */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6111\n"  /* mov.w @r1,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x61DE\n"  /* exts.b r13,r1 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x1F35\n"  /* mov.l r3,@(0x14,r15) */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x611E\n"  /* exts.b r1,r1 */
    ".word 0xD024\n"  /* mov.l @(0x90,PC),r0  {[0x0603EA5C] = 0x060A53B8} */
    ".word 0x310C\n"  /* add r0,r1 */
    ".word 0x7118\n"  /* add #24,r1 */
    ".word 0x1F14\n"  /* mov.l r1,@(0x10,r15) */
    ".word 0x63DD\n"  /* extu.w r13,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x0603EA4C] = 0x060A3E68} */
    ".word 0x330C\n"  /* add r0,r3 */
    ".word 0x1F33\n"  /* mov.l r3,@(0xC,r15) */
    ".word 0x9230\n"  /* mov.w @(0x60,PC),r2 */
    ".word 0x2D2F\n"  /* muls.w r2,r13 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0xD01D\n"  /* mov.l @(0x74,PC),r0  {[0x0603EA60] = 0x060A3F68} */
    ".word 0x320C\n"  /* add r0,r2 */
    ".word 0xA058\n"  /* bra 0x0603EAA2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x61A3\n"  /* mov r10,r1 */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x53F3\n"  /* mov.l @(0xC,r15),r3 */
    ".word 0x033D\n"  /* mov.w @(r0,r3),r3 */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x0317\n"  /* mul.l r1,r3 */
    ".word 0x011A\n"  /* sts macl,r1 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0x2F12\n"  /* mov.l r1,@r15 */
    ".word 0x901D\n"  /* mov.w @(0x3A,PC),r0 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0603EA64] = 0x06034FFC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893E\n"  /* bt 0x0603EA94 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x3087\n"  /* cmp/gt r8,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xCA01\n"  /* xor #0x01,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x203B\n"  /* or r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8916\n"  /* bt 0x0603EA68 */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0xA02B\n"  /* bra 0x0603EA9C */
    ".word 0x0009\n"  /* nop */
    ".word 0x0668\n"  /* .word 0x0668 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E68\n"  /* sub r6,r14 */
    ".word 0x005A\n"  /* .word 0x005A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4C38\n"  /* .word 0x4C38 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35AE\n"  /* .word 0x35AE */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x53B8\n"  /* mov.l @(0x20,r11),r3 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3F68\n"  /* sub r6,r15 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4FFC\n"  /* .word 0x4FFC */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2099\n"  /* and r9,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0xA006\n"  /* bra 0x0603EAA0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60A3\n"  /* mov r10,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0x2021\n"  /* mov.w r2,@r0 */
    ".word 0x7A01\n"  /* add #1,r10 */
    ".word 0x53F5\n"  /* mov.l @(0x14,r15),r3 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3A32\n"  /* cmp/hs r3,r10 */
    ".word 0x8BA3\n"  /* bf 0x0603E9F2 */
    ".word 0x6DDD\n"  /* extu.w r13,r13 */
    ".word 0x4D00\n"  /* shll r13 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0603EB00] = 0x060A4C40} */
    ".word 0x3D3C\n"  /* add r3,r13 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x2D21\n"  /* mov.w r2,@r13 */
    ".word 0x7F34\n"  /* add #52,r15 */
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
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603F238, \"ax\"\n"

    ".global _FUN_0603F238\n"
    ".type _FUN_0603F238, @function\n"
    "_FUN_0603F238:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x6A43\n"  /* mov r4,r10 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603F244, \"ax\"\n"

    ".global _FUN_0603F244\n"
    ".type _FUN_0603F244, @function\n"
    "_FUN_0603F244:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xDB1E\n"  /* mov.l @(0x78,PC),r11  {[0x0603F2C4] = 0x06041698} */
    ".word 0xDC1F\n"  /* mov.l @(0x7C,PC),r12  {[0x0603F2C8] = 0x06041470} */
    ".word 0xDD1F\n"  /* mov.l @(0x7C,PC),r13  {[0x0603F2CC] = 0x060A4D14} */
    ".word 0x9038\n"  /* mov.w @(0x70,PC),r0 */
    ".word 0x65D2\n"  /* mov.l @r13,r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x88FB\n"  /* cmp/eq #-5,r0 */
    ".word 0x8F02\n"  /* bf/s 0x0603F260 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0xA029\n"  /* bra 0x0603F2B2 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x0603F2D0] = 0x00008000} */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0603F2D4] = 0x06041884} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA00C\n"  /* bra 0x0603F284 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x0009\n"  /* nop */
    ".word 0x88F4\n"  /* cmp/eq #-12,r0 */
    ".word 0x8B01\n"  /* bf 0x0603F278 */
    ".word 0xA01D\n"  /* bra 0x0603F2B2 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x65D2\n"  /* mov.l @r13,r5 */
    ".word 0x9022\n"  /* mov.w @(0x44,PC),r0 */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x2EE8\n"  /* tst r14,r14 */
    ".word 0x8BF1\n"  /* bf 0x0603F26C */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x0603F2D8] = 0x0604188C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x0603F296 */
    ".word 0xA00E\n"  /* bra 0x0603F2B2 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0603F2DC] = 0x06036A98} */
    ".word 0x7608\n"  /* add #8,r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8901\n"  /* bt 0x0603F2AE */
    ".word 0xA002\n"  /* bra 0x0603F2B2 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x7002\n"  /* add #2,r0 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06041698 */
    ".word 0x1698\n"  /* mov.l r9,@(0x20,r6) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06041470 */
    ".word 0x1470\n"  /* mov.l r7,@(0x0,r4) */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x1884\n"  /* mov.l r8,@(0x10,r8) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_0604188C */
    ".word 0x188C\n"  /* mov.l r8,@(0x30,r8) */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06036A98 */
    ".word 0x6A98\n"  /* swap.b r9,r10 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603F2EC, \"ax\"\n"

    ".global _FUN_0603F2EC\n"
    ".type _FUN_0603F2EC, @function\n"
    "_FUN_0603F2EC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FC8\n"  /* add #-56,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xB071\n"  /* bsr 0x0603F3DA */
    ".word 0x7424\n"  /* add #36,r4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x3D47\n"  /* cmp/gt r4,r13 */
    ".word 0x8F16\n"  /* bf/s 0x0603F32C */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0xB13C\n"  /* bsr 0x0603F582 */
    ".word 0x7424\n"  /* add #36,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x6320\n"  /* mov.b @r2,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B01\n"  /* bf 0x0603F31A */
    ".word 0xA009\n"  /* bra 0x0603F32C */
    ".word 0x0009\n"  /* nop */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0xB295\n"  /* bsr 0x0603F84C */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7E0C\n"  /* add #12,r14 */
    ".word 0x7DFF\n"  /* add #-1,r13 */
    ".word 0x4D15\n"  /* cmp/pl r13 */
    ".word 0x8DEA\n"  /* bt/s 0x0603F300 */
    ".word 0x7C01\n"  /* add #1,r12 */
    ".word 0x7EF4\n"  /* add #-12,r14 */
    ".word 0x84EB\n"  /* mov.b @(0xB,r14),r0 */
    ".word 0xCB80\n"  /* or #0x80,r0 */
    ".word 0x80EB\n"  /* mov.b r0,@(0xB,r14) */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x7F38\n"  /* add #56,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603F354, \"ax\"\n"

    ".global _FUN_0603F354\n"
    ".type _FUN_0603F354, @function\n"
    "_FUN_0603F354:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FC8\n"  /* add #-56,r15 */
    ".word 0xDA09\n"  /* mov.l @(0x24,PC),r10  {[0x0603F380] = 0x06036DDC} */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xB03C\n"  /* bsr 0x0603F3DA */
    ".word 0x7424\n"  /* add #36,r4 */
    ".word 0xA02B\n"  /* bra 0x0603F3BC */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0xB109\n"  /* bsr 0x0603F582 */
    ".word 0x7424\n"  /* add #36,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x6320\n"  /* mov.b @r2,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B03\n"  /* bf 0x0603F384 */
    ".word 0xA020\n"  /* bra 0x0603F3C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06036DDC */
    ".word 0x6DDC\n"  /* extu.b r13,r13 */
    ".word 0x3DC7\n"  /* cmp/gt r12,r13 */
    ".word 0x8B0B\n"  /* bf 0x0603F3A0 */
    ".word 0xE60C\n"  /* mov #12,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x0603F430] = 0x06036D94} */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x7510\n"  /* add #16,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x74F4\n"  /* add #-12,r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x0603F3A0 */
    ".word 0xA00B\n"  /* bra 0x0603F3B6 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0xB252\n"  /* bsr 0x0603F84C */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE60C\n"  /* mov #12,r6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x7510\n"  /* add #16,r5 */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0x740C\n"  /* add #12,r4 */
    ".word 0x7E18\n"  /* add #24,r14 */
    ".word 0x7D01\n"  /* add #1,r13 */
    ".word 0x7BFF\n"  /* add #-1,r11 */
    ".word 0x4B15\n"  /* cmp/pl r11 */
    ".word 0x89D2\n"  /* bt 0x0603F366 */
    ".word 0x7EE8\n"  /* add #-24,r14 */
    ".word 0x84EB\n"  /* mov.b @(0xB,r14),r0 */
    ".word 0xCB80\n"  /* or #0x80,r0 */
    ".word 0x80EB\n"  /* mov.b r0,@(0xB,r14) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x7F38\n"  /* add #56,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x2452\n"  /* mov.l r5,@r4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0603F434] = 0x060A4D14} */
    ".word 0x9224\n"  /* mov.w @(0x48,PC),r2 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x1421\n"  /* mov.l r2,@(0x4,r4) */
    ".word 0xE3FF\n"  /* mov #-1,r3 */
    ".word 0x1432\n"  /* mov.l r3,@(0x8,r4) */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0x5324\n"  /* mov.l @(0x10,r2),r3 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x1434\n"  /* mov.l r3,@(0x10,r4) */
    ".word 0x000B\n"  /* rts */
    ".word 0x1423\n"  /* mov.l r2,@(0xC,r4) */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603F538, \"ax\"\n"

    ".global _FUN_0603F538\n"
    ".type _FUN_0603F538, @function\n"
    "_FUN_0603F538:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0xBF59\n"  /* bsr 0x0603F3F6 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x84F4\n"  /* mov.b @(0x4,r15),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x644C\n"  /* extu.b r4,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B14\n"  /* bf 0x0603F578 */
    ".word 0x53E3\n"  /* mov.l @(0xC,r14),r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x1E33\n"  /* mov.l r3,@(0xC,r14) */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x53E4\n"  /* mov.l @(0x10,r14),r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x890D\n"  /* bt 0x0603F578 */
    ".word 0x972C\n"  /* mov.w @(0x58,PC),r7 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0603F5BC] = 0x0603B21C} */
    ".word 0x56E1\n"  /* mov.l @(0x4,r14),r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0x1E22\n"  /* mov.l r2,@(0x8,r14) */
    ".word 0xBF41\n"  /* bsr 0x0603F3F6 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x65F0\n"  /* mov.b @r15,r5 */
    ".word 0x645C\n"  /* extu.b r5,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603F948, \"ax\"\n"

    ".global _FUN_0603F948\n"
    ".type _FUN_0603F948, @function\n"
    "_FUN_0603F948:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x2ED2\n"  /* mov.l r13,@r14 */
    ".word 0x1ED1\n"  /* mov.l r13,@(0x4,r14) */
    ".word 0x1ED2\n"  /* mov.l r13,@(0x8,r14) */
    ".word 0x1ED3\n"  /* mov.l r13,@(0xC,r14) */
    ".word 0x1E34\n"  /* mov.l r3,@(0x10,r14) */
    ".word 0x1ED5\n"  /* mov.l r13,@(0x14,r14) */
    ".word 0x1ED6\n"  /* mov.l r13,@(0x18,r14) */
    ".word 0xB00A\n"  /* bsr 0x0603F970 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x145C\n"  /* mov.l r5,@(0x30,r4) */
    ".word 0x0ED4\n"  /* mov.b r13,@(r0,r14) */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603F974, \"ax\"\n"

    ".global _FUN_0603F974\n"
    ".type _FUN_0603F974, @function\n"
    "_FUN_0603F974:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x034C\n"  /* mov.b @(r0,r4),r3 */
    ".word 0xE035\n"  /* mov #53,r0 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x4E11\n"  /* cmp/pz r14 */
    ".word 0x8F0E\n"  /* bf/s 0x0603F9A4 */
    ".word 0x04E4\n"  /* mov.b r14,@(r0,r4) */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x3E27\n"  /* cmp/gt r2,r14 */
    ".word 0x890A\n"  /* bt 0x0603F9A4 */
    ".word 0x66EE\n"  /* exts.b r14,r6 */
    ".word 0xD208\n"  /* mov.l @(0x20,PC),r2  {[0x0603F9B4] = 0x0606364C} */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x666E\n"  /* exts.b r6,r6 */
    ".word 0x362C\n"  /* add r2,r6 */
    ".word 0xBFC4\n"  /* bsr 0x0603F92C */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0x145C\n"  /* mov.l r5,@(0x30,r4) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x364C\n"  /* add r4,r6 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603F9BC, \"ax\"\n"

    ".global _FUN_0603F9BC\n"
    ".type _FUN_0603F9BC, @function\n"
    "_FUN_0603F9BC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x1F51\n"  /* mov.l r5,@(0x4,r15) */
    ".word 0xE5FF\n"  /* mov #-1,r5 */
    ".word 0x2F62\n"  /* mov.l r6,@r15 */
    ".word 0xB028\n"  /* bsr 0x0603FA1A */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x1E32\n"  /* mov.l r3,@(0x8,r14) */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0xE134\n"  /* mov #52,r1 */
    ".word 0x1455\n"  /* mov.l r5,@(0x14,r4) */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0x1436\n"  /* mov.l r3,@(0x18,r4) */
    ".word 0x004C\n"  /* mov.b @(r0,r4),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xC980\n"  /* and #0x80,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x5045\n"  /* mov.l @(0x14,r4),r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x5046\n"  /* mov.l @(0x18,r4),r0 */
    ".word 0x5044\n"  /* mov.l @(0x10,r4),r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x1454\n"  /* mov.l r5,@(0x10,r4) */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0xE134\n"  /* mov #52,r1 */
    ".word 0x004C\n"  /* mov.b @(r0,r4),r0 */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0xCB80\n"  /* or #0x80,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x9325\n"  /* mov.w @(0x4A,PC),r3 */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0424\n"  /* mov.b r2,@(r0,r4) */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603FAE4, \"ax\"\n"

    ".global _FUN_0603FAE4\n"
    ".type _FUN_0603FAE4, @function\n"
    "_FUN_0603FAE4:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x9D1B\n"  /* mov.w @(0x36,PC),r13 */
    ".word 0x6AE2\n"  /* mov.l @r14,r10 */
    ".word 0x53E5\n"  /* mov.l @(0x14,r14),r3 */
    ".word 0x33B7\n"  /* cmp/gt r11,r3 */
    ".word 0x8D03\n"  /* bt/s 0x0603FAFA */
    ".word 0x59E2\n"  /* mov.l @(0x8,r14),r9 */
    ".word 0x28C2\n"  /* mov.l r12,@r8 */
    ".word 0xA0A9\n"  /* bra 0x0603FC4C */
    ".word 0xE005\n"  /* mov #5,r0 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x03EC\n"  /* mov.b @(r0,r14),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x23D9\n"  /* and r13,r3 */
    ".word 0x33D0\n"  /* cmp/eq r13,r3 */
    ".word 0x8906\n"  /* bt 0x0603FB14 */
    ".word 0x28C2\n"  /* mov.l r12,@r8 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x9309\n"  /* mov.w @(0x12,PC),r3 */
    ".word 0xA09C\n"  /* bra 0x0603FC4C */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x9303\n"  /* mov.w @(0x6,PC),r3 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xA083\n"  /* bra 0x0603FC28 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0xFF7F\n"  /* .word 0xFF7F */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF91C\n"  /* .word 0xF91C */
    ".word 0x6693\n"  /* mov r9,r6 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0xB096\n"  /* bsr 0x0603FC60 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x50E1\n"  /* mov.l @(0x4,r14),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x0603FB3E */
    ".word 0xA081\n"  /* bra 0x0603FC40 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x20D9\n"  /* and r13,r0 */
    ".word 0xCB01\n"  /* or #0x01,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xE134\n"  /* mov #52,r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0x6693\n"  /* mov r9,r6 */
    ".word 0x65A3\n"  /* mov r10,r5 */
    ".word 0xB0C6\n"  /* bsr 0x0603FCE4 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x50E3\n"  /* mov.l @(0xC,r14),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x0603FB62 */
    ".word 0xA06F\n"  /* bra 0x0603FC40 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x20D9\n"  /* and r13,r0 */
    ".word 0xCB02\n"  /* or #0x02,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xE134\n"  /* mov #52,r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0x2FE2\n"  /* mov.l r14,@r15 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x5339\n"  /* mov.l @(0x24,r3),r3 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x5448\n"  /* mov.l @(0x20,r4),r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B01\n"  /* bf 0x0603FB8A */
    ".word 0xA05B\n"  /* bra 0x0603FC40 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB207\n"  /* bsr 0x0603FF9C */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x20D9\n"  /* and r13,r0 */
    ".word 0xCB03\n"  /* or #0x03,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xE134\n"  /* mov #52,r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0x2FE2\n"  /* mov.l r14,@r15 */
    ".word 0x63E3\n"  /* mov r14,r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x533B\n"  /* mov.l @(0x2C,r3),r3 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x5448\n"  /* mov.l @(0x20,r4),r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x4415\n"  /* cmp/pl r4 */
    ".word 0x8B01\n"  /* bf 0x0603FBB6 */
    ".word 0xA045\n"  /* bra 0x0603FC40 */
    ".word 0x0009\n"  /* nop */
    ".word 0xEC01\n"  /* mov #1,r12 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x20D9\n"  /* and r13,r0 */
    ".word 0xCB04\n"  /* or #0x04,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xE134\n"  /* mov #52,r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0x53E1\n"  /* mov.l @(0x4,r14),r3 */
    ".word 0x52E7\n"  /* mov.l @(0x1C,r14),r2 */
    ".word 0x5332\n"  /* mov.l @(0x8,r3),r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B0A\n"  /* bf 0x0603FBEA */
    ".word 0xE6FF\n"  /* mov #-1,r6 */
    ".word 0x55E1\n"  /* mov.l @(0x4,r14),r5 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0603FC24] = 0x0603F91C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x52E1\n"  /* mov.l @(0x4,r14),r2 */
    ".word 0x5323\n"  /* mov.l @(0xC,r2),r3 */
    ".word 0x52E6\n"  /* mov.l @(0x18,r14),r2 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x1E26\n"  /* mov.l r2,@(0x18,r14) */
    ".word 0x1EB1\n"  /* mov.l r11,@(0x4,r14) */
    ".word 0xE6FF\n"  /* mov #-1,r6 */
    ".word 0x55E3\n"  /* mov.l @(0xC,r14),r5 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0603FC24] = 0x0603F91C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0x1EB3\n"  /* mov.l r11,@(0xC,r14) */
    ".word 0x52E6\n"  /* mov.l @(0x18,r14),r2 */
    ".word 0x53E5\n"  /* mov.l @(0x14,r14),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B09\n"  /* bf 0x0603FC12 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x20D9\n"  /* and r13,r0 */
    ".word 0xCB05\n"  /* or #0x05,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0xE134\n"  /* mov #52,r1 */
    ".word 0x31EC\n"  /* add r14,r1 */
    ".word 0xA006\n"  /* bra 0x0603FC1E */
    ".word 0x2100\n"  /* mov.b r0,@r1 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x02EC\n"  /* mov.b @(r0,r14),r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22D9\n"  /* and r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x0E24\n"  /* mov.b r2,@(r0,r14) */
    ".word 0xA00F\n"  /* bra 0x0603FC40 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xF91C\n"  /* .word 0xF91C */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B01\n"  /* bf 0x0603FC30 */
    ".word 0xAF7E\n"  /* bra 0x0603FB2C */
    ".word 0x0009\n"  /* nop */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x898D\n"  /* bt 0x0603FB50 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x899D\n"  /* bt 0x0603FB74 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x89B1\n"  /* bt 0x0603FBA0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x89C4\n"  /* bt 0x0603FBCA */
    ".word 0x28C2\n"  /* mov.l r12,@r8 */
    ".word 0xE034\n"  /* mov #52,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x9335\n"  /* mov.w @(0x6A,PC),r3 */
    ".word 0x2039\n"  /* and r3,r0 */
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
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603FE44, \"ax\"\n"

    ".global _FUN_0603FE44\n"
    ".type _FUN_0603FE44, @function\n"
    "_FUN_0603FE44:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xBF77\n"  /* bsr 0x0603FD40 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x000B\n"  /* rts */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0xE001\n"  /* mov #1,r0 */
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603FE62, \"ax\"\n"

    ".global _FUN_0603FE62\n"
    ".type _FUN_0603FE62, @function\n"
    "_FUN_0603FE62:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xBF68\n"  /* bsr 0x0603FD40 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x000B\n"  /* rts */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0xE001\n"  /* mov #1,r0 */
);
__asm__(



    ".balign 2\n"
    ".global _scu_dma_runtime\n"
    ".type _scu_dma_runtime, @function\n"








    ".section .text.FUN_0603FE80, \"ax\"\n"

    ".global _FUN_0603FE80\n"
    "_scu_dma_runtime:\n"
    "_FUN_0603FE80:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0x9D28\n"  /* mov.w @(0x50,PC),r13 */
    ".word 0xDE16\n"  /* mov.l @(0x58,PC),r14  {[0x0603FEE4] = 0x25FE00A4} */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0x1F62\n"  /* mov.l r6,@(0x8,r15) */
    ".word 0x1F71\n"  /* mov.l r7,@(0x4,r15) */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0603FEE8] = 0x06000348} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x1F33\n"  /* mov.l r3,@(0xC,r15) */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x0603FEA2 */
    ".word 0xA043\n"  /* bra 0x0603FF28 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0603FEEC] = 0x10041004} */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x0603FEF0] = 0x25FE00B4} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0603FEF4] = 0x06000340} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE4FF\n"  /* mov #-1,r4 */
    ".word 0x9215\n"  /* mov.w @(0x2A,PC),r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x0603FEF8] = 0x25FE0000} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x53F8\n"  /* mov.l @(0x20,r15),r3 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x50F7\n"  /* mov.l @(0x1C,r15),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x0603FED0 */
    ".word 0xA001\n"  /* bra 0x0603FED2 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x9406\n"  /* mov.w @(0xC,PC),r4 */
    ".word 0x50F2\n"  /* mov.l @(0x8,r15),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B11\n"  /* bf 0x0603FEFC */
    ".word 0xA011\n"  /* bra 0x0603FEFE */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0xF7FF\n"  /* .word 0xF7FF */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x25FE\n"  /* mulu.w r15,r5 */
    ".word 0x00A4\n"  /* mov.b r10,@(r0,r0) */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0348\n"  /* .word 0x0348 */
    ".word 0x1004\n"  /* mov.l r0,@(0x10,r0) */
    ".word 0x1004\n"  /* mov.l r0,@(0x10,r0) */
    ".word 0x25FE\n"  /* mulu.w r15,r5 */
    ".word 0x00B4\n"  /* mov.b r11,@(r0,r0) */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0340\n"  /* .word 0x0340 */
    ".word 0x25FE\n"  /* mulu.w r15,r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE502\n"  /* mov #2,r5 */
    ".word 0x245B\n"  /* or r5,r4 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0603FF4C] = 0x25FE000C} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xE207\n"  /* mov #7,r2 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x921E\n"  /* mov.w @(0x3C,PC),r2 */
    ".word 0x73FC\n"  /* add #-4,r3 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x22D9\n"  /* and r13,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x89FB\n"  /* bt 0x0603FF10 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0603FF50] = 0x06000340} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x54F3\n"  /* mov.l @(0xC,r15),r4 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".size _scu_dma_runtime, .-_scu_dma_runtime\n"
);
__asm__(



    ".balign 2\n"










    ".section .text.FUN_0603FF3A, \"ax\"\n"

    ".global _FUN_0603FF3A\n"
    ".type _FUN_0603FF3A, @function\n"
    "_FUN_0603FF3A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x6D73\n"  /* mov r7,r13 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8F07\n"  /* bf/s 0x0603FF54 */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0xA01D\n"  /* bra 0x0603FF84 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0101\n"  /* .word 0x0101 */
    ".word 0x25FE\n"  /* mulu.w r15,r5 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0340\n"  /* .word 0x0340 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x57F2\n"  /* mov.l @(0x8,r15),r7 */
    ".word 0x55F3\n"  /* mov.l @(0xC,r15),r5 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4509\n"  /* shlr2 r5 */
    ".word 0x3352\n"  /* cmp/hs r5,r3 */
    ".word 0x8D07\n"  /* bt/s 0x0603FF74 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x3E6C\n"  /* add r6,r14 */
    ".word 0x3452\n"  /* cmp/hs r5,r4 */
    ".word 0x8FF9\n"  /* bf/s 0x0603FF66 */
    ".word 0x3D7C\n"  /* add r7,r13 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x50F3\n"  /* mov.l @(0xC,r15),r0 */
    ".word 0xC903\n"  /* and #0x03,r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA031\n"  /* bra 0x0603FFE6 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x000B\n"  /* rts */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x5009\n"  /* mov.l @(0x24,r0),r0 */
    ".word 0x5448\n"  /* mov.l @(0x20,r4),r4 */
    ".word 0x402B\n"  /* jmp @r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
);

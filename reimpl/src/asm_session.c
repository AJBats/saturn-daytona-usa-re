__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040010, \"ax\"\n"

    ".global _FUN_06040010\n"
    ".type _FUN_06040010, @function\n"
    "_FUN_06040010:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDE23\n"  /* mov.l @(0x8C,PC),r14  {[0x060400A4] = 0x060A4D14} */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x9040\n"  /* mov.w @(0x80,PC),r0 */
    ".word 0x013E\n"  /* mov.l @(r0,r3),r1 */
    ".word 0x2129\n"  /* and r2,r1 */
    ".word 0x0316\n"  /* mov.l r1,@(r0,r3) */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x933C\n"  /* mov.w @(0x78,PC),r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x060400A8] = 0x06040C98} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B06\n"  /* bf 0x06040042 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x9032\n"  /* mov.w @(0x64,PC),r0 */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0xCB01\n"  /* or #0x01,r0 */
    ".word 0x912F\n"  /* mov.w @(0x5E,PC),r1 */
    ".word 0x313C\n"  /* add r3,r1 */
    ".word 0x2102\n"  /* mov.l r0,@r1 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D02\n"  /* bt/s 0x0604004E */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0xA001\n"  /* bra 0x06040050 */
    ".word 0xE217\n"  /* mov #23,r2 */
    ".word 0xE2FF\n"  /* mov #-1,r2 */
    ".word 0x9027\n"  /* mov.w @(0x4E,PC),r0 */
    ".word 0x0326\n"  /* mov.l r2,@(r0,r3) */
    ".word 0xA019\n"  /* bra 0x0604008A */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE0E9\n"  /* mov #-23,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE0FE\n"  /* mov #-2,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE0FD\n"  /* mov #-3,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x88F1\n"  /* cmp/eq #-15,r0 */
    ".word 0x89F3\n"  /* bt 0x06040076 */
    ".word 0x88F2\n"  /* cmp/eq #-14,r0 */
    ".word 0x89EC\n"  /* bt 0x0604006C */
    ".word 0x88F3\n"  /* cmp/eq #-13,r0 */
    ".word 0x89E5\n"  /* bt 0x06040062 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89DE\n"  /* bt 0x06040058 */
    ".word 0xAFF1\n"  /* bra 0x06040080 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00C4\n"  /* mov.b r12,@(r0,r0) */
    ".word 0x00D0\n"  /* .word 0x00D0 */
    ".word 0x00C8\n"  /* .word 0x00C8 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06040C98 */
    ".word 0x0C98\n"  /* .word 0x0C98 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".global _FUN_060400b4\n"
    "_FUN_060400b4:\n"
    ".word 0xE304\n"  /* mov #4,r3 */
    ".word 0x2349\n"  /* and r4,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8902\n"  /* bt 0x060400C2 */
    ".word 0x9422\n"  /* mov.w @(0x44,PC),r4 */
    ".word 0xA008\n"  /* bra 0x060400D2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x951F\n"  /* mov.w @(0x3E,PC),r5 */
    ".word 0x2429\n"  /* and r2,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8901\n"  /* bt 0x060400D0 */
    ".word 0xA001\n"  /* bra 0x060400D2 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6043\n"  /* mov r4,r0 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060401FC, \"ax\"\n"

    ".global _FUN_060401FC\n"
    ".type _FUN_060401FC, @function\n"
    "_FUN_060401FC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x1E58\n"  /* mov.l r5,@(0x20,r14) */
    ".word 0xD50E\n"  /* mov.l @(0x38,PC),r5  {[0x0604023C] = 0x7FFFFFFF} */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06040240] = 0x060408B0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E6\n"  /* mov.l @(0x18,r14),r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8900\n"  /* bt 0x06040212 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x53E6\n"  /* mov.l @(0x18,r14),r3 */
    ".word 0x5234\n"  /* mov.l @(0x10,r3),r2 */
    ".word 0x3428\n"  /* sub r2,r4 */
    ".word 0x1E49\n"  /* mov.l r4,@(0x24,r14) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8914\n"  /* bt 0x06040250 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0xD206\n"  /* mov.l @(0x18,PC),r2  {[0x06040244] = 0x40000000} */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x890D\n"  /* bt 0x0604024C */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0xD205\n"  /* mov.l @(0x14,PC),r2  {[0x06040248] = 0x3FFFFFFF} */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0xA00A\n"  /* bra 0x06040250 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_060408B0 */
    ".word 0x08B0\n"  /* .word 0x08B0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x3FFF\n"  /* .word 0x3FFF */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x2522\n"  /* mov.l r2,@r5 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8901\n"  /* bt 0x06040258 */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x2632\n"  /* mov.l r3,@r6 */
    ".word 0x50F2\n"  /* mov.l @(0x8,r15),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8904\n"  /* bt 0x06040268 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0xE01C\n"  /* mov #28,r0 */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8901\n"  /* bt 0x06040270 */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x2732\n"  /* mov.l r3,@r7 */
    ".word 0x60F2\n"  /* mov.l @r15,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8902\n"  /* bt 0x0604027C */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x5244\n"  /* mov.l @(0x10,r4),r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x50F3\n"  /* mov.l @(0xC,r15),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8904\n"  /* bt 0x0604028C */
    ".word 0x53F3\n"  /* mov.l @(0xC,r15),r3 */
    ".word 0xE01D\n"  /* mov #29,r0 */
    ".word 0x024C\n"  /* mov.b @(r0,r4),r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x2118\n"  /* tst r1,r1 */
    ".word 0x8913\n"  /* bt 0x060402B8 */
    ".word 0xE01D\n"  /* mov #29,r0 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0x054C\n"  /* mov.b @(r0,r4),r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x2359\n"  /* and r5,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8908\n"  /* bt 0x060402B0 */
    ".word 0xA000\n"  /* bra 0x060402A2 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0x2259\n"  /* and r5,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8902\n"  /* bt 0x060402B0 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xA004\n"  /* bra 0x060402B8 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x5243\n"  /* mov.l @(0xC,r4),r2 */
    ".word 0x5345\n"  /* mov.l @(0x14,r4),r3 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060402BC, \"ax\"\n"

    ".global _FUN_060402BC\n"
    ".type _FUN_060402BC, @function\n"
    "_FUN_060402BC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FE4\n"  /* add #-28,r15 */
    ".word 0xDA06\n"  /* mov.l @(0x18,PC),r10  {[0x060402EC] = 0x06040FEA} */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0xDD06\n"  /* mov.l @(0x18,PC),r13  {[0x060402F0] = 0x060A4D14} */
    ".word 0x5CE6\n"  /* mov.l @(0x18,r14),r12 */
    ".word 0x5BE8\n"  /* mov.l @(0x20,r14),r11 */
    ".word 0x53E9\n"  /* mov.l @(0x24,r14),r3 */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0x3B38\n"  /* sub r3,r11 */
    ".word 0xB16A\n"  /* bsr 0x060405B8 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xA015\n"  /* bra 0x06040312 */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0xA01F\n"  /* bra 0x0604032A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0FEA\n"  /* .word 0x0FEA */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06040344] = 0x06041648} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B15\n"  /* bf 0x0604032A */
    ".word 0xA110\n"  /* bra 0x06040522 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xA10E\n"  /* bra 0x06040522 */
    ".word 0xE003\n"  /* mov #3,r0 */
    ".word 0xA10C\n"  /* bra 0x06040522 */
    ".word 0xE004\n"  /* mov #4,r0 */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0x54CA\n"  /* mov.l @(0x28,r12),r4 */
    ".word 0xA108\n"  /* bra 0x06040522 */
    ".word 0xE006\n"  /* mov #6,r0 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89EE\n"  /* bt 0x060402F4 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8907\n"  /* bt 0x0604032A */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89E4\n"  /* bt 0x060402E8 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x89EF\n"  /* bt 0x06040302 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x89EF\n"  /* bt 0x06040306 */
    ".word 0xAFF0\n"  /* bra 0x0604030A */
    ".word 0x0009\n"  /* nop */
    ".word 0x54E8\n"  /* mov.l @(0x20,r14),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B04\n"  /* bf 0x0604033A */
    ".word 0x53E9\n"  /* mov.l @(0x24,r14),r3 */
    ".word 0x3430\n"  /* cmp/eq r3,r4 */
    ".word 0x8B01\n"  /* bf 0x0604033A */
    ".word 0xA0F4\n"  /* bra 0x06040522 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0x54EA\n"  /* mov.l @(0x28,r14),r4 */
    ".word 0x3B43\n"  /* cmp/ge r4,r11 */
    ".word 0x8903\n"  /* bt 0x06040348 */
    ".word 0xA003\n"  /* bra 0x0604034A */
    ".word 0x0009\n"  /* nop */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06041648 */
    ".word 0x1648\n"  /* mov.l r4,@(0x20,r6) */
    ".word 0x6B43\n"  /* mov r4,r11 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x060403D8] = 0x06041014} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54CA\n"  /* mov.l @(0x28,r12),r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x06040358 */
    ".word 0xA0BC\n"  /* bra 0x060404D0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xD520\n"  /* mov.l @(0x80,PC),r5  {[0x060403DC] = 0x7FFFFFFF} */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x060403E0] = 0x060408B0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E6\n"  /* mov.l @(0x18,r14),r4 */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0x4911\n"  /* cmp/pz r9 */
    ".word 0x8900\n"  /* bt 0x0604036A */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x060403E4] = 0x060409DE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0xB1D6\n"  /* bsr 0x06040722 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x58E1\n"  /* mov.l @(0x4,r14),r8 */
    ".word 0x4915\n"  /* cmp/pl r9 */
    ".word 0x8F0B\n"  /* bf/s 0x06040394 */
    ".word 0x380C\n"  /* add r0,r8 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x060403E8] = 0x060A4D14} */
    ".word 0x9029\n"  /* mov.w @(0x52,PC),r0 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x023E\n"  /* mov.l @(r0,r3),r2 */
    ".word 0x3823\n"  /* cmp/ge r2,r8 */
    ".word 0x8904\n"  /* bt 0x06040394 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x9023\n"  /* mov.w @(0x46,PC),r0 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x3388\n"  /* sub r8,r3 */
    ".word 0x3938\n"  /* sub r3,r9 */
    ".word 0x39B3\n"  /* cmp/ge r11,r9 */
    ".word 0x8B0A\n"  /* bf 0x060403AE */
    ".word 0x52E9\n"  /* mov.l @(0x24,r14),r2 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x1E29\n"  /* mov.l r2,@(0x24,r14) */
    ".word 0x53E8\n"  /* mov.l @(0x20,r14),r3 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B01\n"  /* bf 0x060403AA */
    ".word 0xA0BC\n"  /* bra 0x06040522 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0xA0BA\n"  /* bra 0x06040522 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x3B98\n"  /* sub r9,r11 */
    ".word 0x4B15\n"  /* cmp/pl r11 */
    ".word 0x8908\n"  /* bt 0x060403C6 */
    ".word 0x53E8\n"  /* mov.l @(0x20,r14),r3 */
    ".word 0x52E9\n"  /* mov.l @(0x24,r14),r2 */
    ".word 0x3328\n"  /* sub r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B01\n"  /* bf 0x060403C2 */
    ".word 0xA0B0\n"  /* bra 0x06040522 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0xA0AE\n"  /* bra 0x06040522 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x060403EC] = 0x06040FB8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6903\n"  /* mov r0,r9 */
    ".word 0x4911\n"  /* cmp/pz r9 */
    ".word 0x890E\n"  /* bt 0x060403F0 */
    ".word 0xA0A6\n"  /* bra 0x06040522 */
    ".word 0xE006\n"  /* mov #6,r0 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x1014\n"  /* mov.l r1,@(0x10,r0) */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_060408B0 */
    ".word 0x08B0\n"  /* .word 0x08B0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x09DE\n"  /* mov.l @(r0,r13),r9 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0FB8\n"  /* .word 0x0FB8 */
    ".word 0x1C9A\n"  /* mov.l r9,@(0x28,r12) */
    ".word 0xD333\n"  /* mov.l @(0xCC,PC),r3  {[0x060404C0] = 0x060409DE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x350C\n"  /* add r0,r5 */
    ".word 0xB191\n"  /* bsr 0x06040722 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x52E1\n"  /* mov.l @(0x4,r14),r2 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x302C\n"  /* add r2,r0 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x1E02\n"  /* mov.l r0,@(0x8,r14) */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x1281\n"  /* mov.l r8,@(0x4,r2) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x1342\n"  /* mov.l r4,@(0x8,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x51E2\n"  /* mov.l @(0x8,r14),r1 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x5331\n"  /* mov.l @(0x4,r3),r3 */
    ".word 0x3138\n"  /* sub r3,r1 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x1213\n"  /* mov.l r1,@(0xC,r2) */
    ".word 0x6533\n"  /* mov r3,r5 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x0234\n"  /* mov.b r3,@(r0,r2) */
    ".word 0xB0BF\n"  /* bsr 0x060405B8 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x64D2\n"  /* mov.l @r13,r4 */
    ".word 0x903C\n"  /* mov.w @(0x78,PC),r0 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x5231\n"  /* mov.l @(0x4,r3),r2 */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8918\n"  /* bt 0x0604047C */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x9035\n"  /* mov.w @(0x6A,PC),r0 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x033E\n"  /* mov.l @(r0,r3),r3 */
    ".word 0x5221\n"  /* mov.l @(0x4,r2),r2 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8910\n"  /* bt 0x0604047C */
    ".word 0x52E2\n"  /* mov.l @(0x8,r14),r2 */
    ".word 0x3423\n"  /* cmp/ge r2,r4 */
    ".word 0x890D\n"  /* bt 0x0604047C */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x53E2\n"  /* mov.l @(0x8,r14),r3 */
    ".word 0x902A\n"  /* mov.w @(0x54,PC),r0 */
    ".word 0x022E\n"  /* mov.l @(r0,r2),r2 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8907\n"  /* bt 0x0604047C */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x5131\n"  /* mov.l @(0x4,r3),r1 */
    ".word 0x9021\n"  /* mov.w @(0x42,PC),r0 */
    ".word 0x0216\n"  /* mov.l r1,@(r0,r2) */
    ".word 0xA053\n"  /* bra 0x06040522 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x060404C4] = 0x06041128} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54C5\n"  /* mov.l @(0x14,r12),r4 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x060404C8] = 0x0604188C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x06040492 */
    ".word 0xA048\n"  /* bra 0x06040522 */
    ".word 0xE006\n"  /* mov #6,r0 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x060404CC] = 0x06041180} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x52E9\n"  /* mov.l @(0x24,r14),r2 */
    ".word 0x32BC\n"  /* add r11,r2 */
    ".word 0x1E29\n"  /* mov.l r2,@(0x24,r14) */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x5121\n"  /* mov.l @(0x4,r2),r1 */
    ".word 0x9006\n"  /* mov.w @(0xC,PC),r0 */
    ".word 0x0316\n"  /* mov.l r1,@(r0,r3) */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x52E2\n"  /* mov.l @(0x8,r14),r2 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x0326\n"  /* mov.l r2,@(r0,r3) */
    ".word 0xA034\n"  /* bra 0x06040522 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x09DE\n"  /* mov.l @(r0,r13),r9 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06041128 */
    ".word 0x1128\n"  /* mov.l r2,@(0x20,r1) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_0604188C */
    ".word 0x188C\n"  /* mov.l r8,@(0x30,r8) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06041180 */
    ".word 0x1180\n"  /* mov.l r8,@(0x0,r1) */
    ".word 0x53E2\n"  /* mov.l @(0x8,r14),r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8911\n"  /* bt 0x060404FC */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0x54CA\n"  /* mov.l @(0x28,r12),r4 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x902A\n"  /* mov.w @(0x54,PC),r0 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8907\n"  /* bt 0x060404F8 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x9023\n"  /* mov.w @(0x46,PC),r0 */
    ".word 0x013E\n"  /* mov.l @(r0,r3),r1 */
    ".word 0x70FC\n"  /* add #-4,r0 */
    ".word 0x0216\n"  /* mov.l r1,@(r0,r2) */
    ".word 0xA015\n"  /* bra 0x06040522 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0xA013\n"  /* bra 0x06040522 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x901A\n"  /* mov.w @(0x34,PC),r0 */
    ".word 0x033E\n"  /* mov.l @(r0,r3),r3 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x53E8\n"  /* mov.l @(0x20,r14),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B03\n"  /* bf 0x06040514 */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0x54CA\n"  /* mov.l @(0x28,r12),r4 */
    ".word 0xA007\n"  /* bra 0x06040522 */
    ".word 0xE002\n"  /* mov #2,r0 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x8B03\n"  /* bf 0x06040520 */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0x54CA\n"  /* mov.l @(0x28,r12),r4 */
    ".word 0xA001\n"  /* bra 0x06040522 */
    ".word 0xE006\n"  /* mov #6,r0 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F1C\n"  /* add #28,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0x00AC\n"  /* mov.b @(r0,r10),r0 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_0604053A, \"ax\"\n"

    ".global _FUN_0604053A\n"
    ".type _FUN_0604053A, @function\n"
    "_FUN_0604053A:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xDE19\n"  /* mov.l @(0x64,PC),r14  {[0x060405A8] = 0x060A4D14} */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8D11\n"  /* bt/s 0x0604056C */
    ".word 0x5D46\n"  /* mov.l @(0x18,r4),r13 */
    ".word 0xE100\n"  /* mov #0,r1 */
    ".word 0x902A\n"  /* mov.w @(0x54,PC),r0 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x0216\n"  /* mov.l r1,@(r0,r2) */
    ".word 0x6213\n"  /* mov r1,r2 */
    ".word 0x70FC\n"  /* add #-4,r0 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x0316\n"  /* mov.l r1,@(r0,r3) */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x55DA\n"  /* mov.l @(0x28,r13),r5 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x060405AC] = 0x0604134E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x060405B0] = 0x06041014} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54DA\n"  /* mov.l @(0x28,r13),r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8911\n"  /* bt 0x0604059A */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x060405B4] = 0x06040FEA} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54DA\n"  /* mov.l @(0x28,r13),r4 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xB01B\n"  /* bsr 0x060405B8 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x900E\n"  /* mov.w @(0x1C,PC),r0 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8905\n"  /* bt 0x0604059A */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x9007\n"  /* mov.w @(0xE,PC),r0 */
    ".word 0x013E\n"  /* mov.l @(r0,r3),r1 */
    ".word 0x70FC\n"  /* add #-4,r0 */
    ".word 0x0216\n"  /* mov.l r1,@(r0,r2) */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x4D14\n"  /* .word 0x4D14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_0604134E */
    ".word 0x134E\n"  /* mov.l r4,@(0x38,r3) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x1014\n"  /* mov.l r1,@(0x10,r0) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0FEA\n"  /* .word 0x0FEA */
);
/* FUN_06040668: moved to session_check.c */
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060406B4, \"ax\"\n"

    ".global _FUN_060406B4\n"
    ".type _FUN_060406B4, @function\n"
    "_FUN_060406B4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x6D43\n"  /* mov r4,r13 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060406BC, \"ax\"\n"

    ".global _FUN_060406BC\n"
    ".type _FUN_060406BC, @function\n"
    "_FUN_060406BC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xBFD1\n"  /* bsr 0x06040666 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x060406CC */
    ".word 0xA025\n"  /* bra 0x06040716 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xD305\n"  /* mov.l @(0x14,PC),r3  {[0x060406E4] = 0x06040FB8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x4E11\n"  /* cmp/pz r14 */
    ".word 0x8907\n"  /* bt 0x060406E8 */
    ".word 0xA01D\n"  /* bra 0x06040716 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x09DE\n"  /* mov.l @(r0,r13),r9 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_060409E6 */
    ".word 0x09E6\n"  /* mov.l r14,@(r0,r9) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0FB8\n"  /* .word 0x0FB8 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x6833\n"  /* mov r3,r8 */
    ".word 0x7804\n"  /* add #4,r8 */
    ".word 0xB012\n"  /* bsr 0x06040722 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x52D1\n"  /* mov.l @(0x4,r13),r2 */
    ".word 0x302C\n"  /* add r2,r0 */
    ".word 0x2802\n"  /* mov.l r0,@r8 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0604076C] = 0x0604134E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06040770] = 0x06040FEA} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".global _FUN_06040722\n"
    "_FUN_06040722:\n"
    ".word 0xE01E\n"  /* mov #30,r0 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040724, \"ax\"\n"

    ".global _FUN_06040724\n"
    ".type _FUN_06040724, @function\n"
    "_FUN_06040724:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x034C\n"  /* mov.b @(r0,r4),r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B04\n"  /* bf 0x0604073A */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xE01E\n"  /* mov #30,r0 */
    ".word 0x6153\n"  /* mov r5,r1 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06040774] = 0x06034FFC} */
    ".word 0x064C\n"  /* mov.b @(r0,r4),r6 */
    ".word 0x666C\n"  /* extu.b r6,r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0xE21F\n"  /* mov #31,r2 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x6153\n"  /* mov r5,r1 */
    ".word 0x324C\n"  /* add r4,r2 */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x0037\n"  /* mul.l r3,r0 */
    ".word 0xD207\n"  /* mov.l @(0x1C,PC),r2  {[0x06040778] = 0x06036BE4} */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_0604134E */
    ".word 0x134E\n"  /* mov.l r4,@(0x38,r3) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0FEA\n"  /* .word 0x0FEA */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x4FFC\n"  /* .word 0x4FFC */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x6BE4\n"  /* mov.b @r14+,r11 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_0604087C, \"ax\"\n"

    ".global _FUN_0604087C\n"
    ".type _FUN_0604087C, @function\n"
    "_FUN_0604087C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x060408A8] = 0x06040F16} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x5441\n"  /* mov.l @(0x4,r4),r4 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x5445\n"  /* mov.l @(0x14,r4),r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x060408AC] = 0x06040EBA} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x5049\n"  /* mov.l @(0x24,r4),r0 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x000B\n"  /* rts */
    ".word 0x1459\n"  /* mov.l r5,@(0x24,r4) */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_060414D0 */
    ".word 0x14D0\n"  /* mov.l r13,@(0x0,r4) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_0604188C */
    ".word 0x188C\n"  /* mov.l r8,@(0x30,r8) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06040F16 */
    ".word 0x0F16\n"  /* mov.l r1,@(r0,r15) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0EBA\n"  /* .word 0x0EBA */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_0604097C, \"ax\"\n"

    ".global _FUN_0604097C\n"
    ".type _FUN_0604097C, @function\n"
    "_FUN_0604097C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040980, \"ax\"\n"

    ".global _FUN_06040980\n"
    ".type _FUN_06040980, @function\n"
    "_FUN_06040980:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x61E3\n"  /* mov r14,r1 */
    ".word 0x1E58\n"  /* mov.l r5,@(0x20,r14) */
    ".word 0x7118\n"  /* add #24,r1 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x060409B4] = 0x06035228} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE006\n"  /* mov #6,r0 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x060409B8] = 0x06041034} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54E5\n"  /* mov.l @(0x14,r14),r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8D03\n"  /* bt/s 0x060409A8 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x060409BC] = 0x0604188C} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06041648 */
    ".word 0x1648\n"  /* mov.l r4,@(0x20,r6) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5228\n"  /* mov.l @(0x20,r2),r2 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06041034 */
    ".word 0x1034\n"  /* mov.l r3,@(0x10,r0) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_0604188C */
    ".word 0x188C\n"  /* mov.l r8,@(0x30,r8) */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE500\n"  /* mov #0,r5 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060409C8, \"ax\"\n"

    ".global _FUN_060409C8\n"
    ".type _FUN_060409C8, @function\n"
    "_FUN_060409C8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0xD615\n"  /* mov.l @(0x54,PC),r6  {[0x06040A24] = 0x0000FFFF} */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06040A28] = 0x060412B2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x5441\n"  /* mov.l @(0x4,r4),r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06040A2C] = 0x0604188C} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x5042\n"  /* mov.l @(0x8,r4),r0 */
    ".word 0x5344\n"  /* mov.l @(0x10,r4),r3 */
    ".word 0x000B\n"  /* rts */
    ".word 0x303C\n"  /* add r3,r0 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040AF8, \"ax\"\n"

    ".global _FUN_06040AF8\n"
    ".type _FUN_06040AF8, @function\n"
    "_FUN_06040AF8:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xB018\n"  /* bsr 0x06040B32 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x6E03\n"  /* mov r0,r14 */
    ".word 0x2EE8\n"  /* tst r14,r14 */
    ".word 0x8B04\n"  /* bf 0x06040B12 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xB07C\n"  /* bsr 0x06040C10 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B04\n"  /* bf 0x06040B28 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE010\n"  /* mov #16,r0 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040B34, \"ax\"\n"

    ".global _FUN_06040B34\n"
    ".type _FUN_06040B34, @function\n"
    "_FUN_06040B34:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FE8\n"  /* add #-24,r15 */
    ".word 0x1F55\n"  /* mov.l r5,@(0x14,r15) */
    ".word 0xD303\n"  /* mov.l @(0xC,PC),r3  {[0x06040B50] = 0x0606367C} */
    ".word 0x023C\n"  /* mov.b @(r0,r3),r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8D04\n"  /* bt/s 0x06040B54 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".word 0xA051\n"  /* bra 0x06040BF2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x367C\n"  /* add r7,r6 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x67F3\n"  /* mov r15,r7 */
    ".word 0x56F6\n"  /* mov.l @(0x18,r15),r6 */
    ".word 0x55D4\n"  /* mov.l @(0x10,r13),r5 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x06040BFC] = 0x060411A0} */
    ".word 0x7704\n"  /* add #4,r7 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x54D1\n"  /* mov.l @(0x4,r13),r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D02\n"  /* bt/s 0x06040B72 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xA040\n"  /* bra 0x06040BF2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x06040C00] = 0x0604188C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x06040B80 */
    ".word 0xA039\n"  /* bra 0x06040BF2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8901\n"  /* bt 0x06040B8A */
    ".word 0xA034\n"  /* bra 0x06040BF2 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x65E3\n"  /* mov r14,r5 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040B8E, \"ax\"\n"

    ".global _FUN_06040B8E\n"
    ".type _FUN_06040B8E, @function\n"
    "_FUN_06040B8E:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040B90, \"ax\"\n"

    ".global _FUN_06040B90\n"
    ".type _FUN_06040B90, @function\n"
    "_FUN_06040B90:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0x7210\n"  /* add #16,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x731C\n"  /* add #28,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x67F3\n"  /* mov r15,r7 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06040C04] = 0x06040220} */
    ".word 0x771C\n"  /* add #28,r7 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D2\n"  /* mov.l @r13,r4 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x53F4\n"  /* mov.l @(0x10,r15),r3 */
    ".word 0x5542\n"  /* mov.l @(0x8,r4),r5 */
    ".word 0x5244\n"  /* mov.l @(0x10,r4),r2 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x3533\n"  /* cmp/ge r3,r5 */
    ".word 0x8B0B\n"  /* bf 0x06040BD4 */
    ".word 0x50F2\n"  /* mov.l @(0x8,r15),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8908\n"  /* bt 0x06040BD4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B05\n"  /* bf 0x06040BD4 */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x3238\n"  /* sub r3,r2 */
    ".word 0x51F1\n"  /* mov.l @(0x4,r15),r1 */
    ".word 0x3128\n"  /* sub r2,r1 */
    ".word 0x1F11\n"  /* mov.l r1,@(0x4,r15) */
    ".word 0xDD0C\n"  /* mov.l @(0x30,PC),r13  {[0x06040C08] = 0x0606367C} */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06040C0C] = 0x06035C48} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2D02\n"  /* mov.l r0,@r13 */
    ".word 0x1DE1\n"  /* mov.l r14,@(0x4,r13) */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x1D22\n"  /* mov.l r2,@(0x8,r13) */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x1D33\n"  /* mov.l r3,@(0xC,r13) */
    ".word 0x63D3\n"  /* mov r13,r3 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x0324\n"  /* mov.b r2,@(r0,r3) */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x7F18\n"  /* add #24,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_060411A0 */
    ".word 0x11A0\n"  /* mov.l r10,@(0x0,r1) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_0604188C */
    ".word 0x188C\n"  /* mov.l r8,@(0x30,r8) */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x0220\n"  /* .word 0x0220 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x367C\n"  /* add r7,r6 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C48\n"  /* mov.l @(0x20,r4),r12 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040C5C, \"ax\"\n"

    ".global _FUN_06040C5C\n"
    ".type _FUN_06040C5C, @function\n"
    "_FUN_06040C5C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E63\n"  /* mov r6,r14 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040C60, \"ax\"\n"

    ".global _FUN_06040C60\n"
    ".type _FUN_06040C60, @function\n"
    "_FUN_06040C60:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0x1F51\n"  /* mov.l r5,@(0x4,r15) */
    ".word 0x1F42\n"  /* mov.l r4,@(0x8,r15) */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06040C90] = 0x06041258} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x88FF\n"  /* cmp/eq #-1,r0 */
    ".word 0x8B01\n"  /* bf 0x06040C78 */
    ".word 0x5EF1\n"  /* mov.l @(0x4,r15),r14 */
    ".word 0x5EE3\n"  /* mov.l @(0xC,r14),r14 */
    ".word 0xE601\n"  /* mov #1,r6 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0xBEB3\n"  /* bsr 0x060409E6 */
    ".word 0x54F2\n"  /* mov.l @(0x8,r15),r4 */
    ".word 0xD204\n"  /* mov.l @(0x10,PC),r2  {[0x06040C94] = 0x0606367C} */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xE010\n"  /* mov #16,r0 */
    ".word 0x0234\n"  /* mov.b r3,@(r0,r2) */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6)  -> FUN_06041258 */
    ".word 0x1258\n"  /* mov.l r5,@(0x20,r2) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x367C\n"  /* add r7,r6 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06040F1C, \"ax\"\n"

    ".global _FUN_06040F1C\n"
    ".type _FUN_06040F1C, @function\n"
    "_FUN_06040F1C:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDD07\n"  /* mov.l @(0x1C,PC),r13  {[0x06040F3C] = 0x060A5400} */
    ".word 0x4E11\n"  /* cmp/pz r14 */
    ".word 0x8B02\n"  /* bf 0x06040F2A */
    ".word 0xE218\n"  /* mov #24,r2 */
    ".word 0x3E23\n"  /* cmp/ge r2,r14 */
    ".word 0x8B01\n"  /* bf 0x06040F2E */
    ".word 0xA026\n"  /* bra 0x06040F7A */
    ".word 0xE0FA\n"  /* mov #-6,r0 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x00EC\n"  /* mov.b @(r0,r14),r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8904\n"  /* bt 0x06040F40 */
    ".word 0xA020\n"  /* bra 0x06040F7A */
    ".word 0xE0F9\n"  /* mov #-7,r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x5400\n"  /* mov.l @(0x0,r0),r4 */
    ".word 0xD619\n"  /* mov.l @(0x64,PC),r6  {[0x06040FA8] = 0x0000FFFF} */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0xB1B5\n"  /* bsr 0x060412B2 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xD418\n"  /* mov.l @(0x60,PC),r4  {[0x06040FAC] = 0x00008000} */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x124F\n"  /* mov.l r4,@(0x3C,r2) */
    ".word 0xB3A3\n"  /* bsr 0x06041698 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8F02\n"  /* bf/s 0x06040F5C */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0xA00F\n"  /* bra 0x06040F7A */
    ".word 0xE0F4\n"  /* mov #-12,r0 */
    ".word 0xB1D8\n"  /* bsr 0x06041310 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B01\n"  /* bf 0x06040F68 */
    ".word 0xA002\n"  /* bra 0x06040F6C */
    ".word 0x0009\n"  /* nop */
    ".word 0xAFF1\n"  /* bra 0x06040F4E */
    ".word 0x0009\n"  /* nop */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6543\n"  /* mov r4,r5 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x124F\n"  /* mov.l r4,@(0x3C,r2) */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x0E54\n"  /* mov.b r5,@(r0,r14) */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060410CA, \"ax\"\n"

    ".global _FUN_060410CA\n"
    ".type _FUN_060410CA, @function\n"
    "_FUN_060410CA:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FEC\n"  /* add #-20,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x1F61\n"  /* mov.l r6,@(0x4,r15) */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x06041100] = 0x060363BC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8903\n"  /* bt 0x060410E6 */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0xE0F6\n"  /* mov #-10,r0 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06041104] = 0x06036308} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8909\n"  /* bt 0x06041108 */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0xE0F6\n"  /* mov #-10,r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5228\n"  /* mov.l @(0x20,r2),r2 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_060363BC */
    ".word 0x63BC\n"  /* extu.b r11,r3 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06036308 */
    ".word 0x6308\n"  /* swap.b r0,r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06041178] = 0x060349B6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x0604117C] = 0x060A5400} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x7308\n"  /* add #8,r3 */
    ".word 0x6130\n"  /* mov.b @r3,r1 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06041382, \"ax\"\n"

    ".global _FUN_06041382\n"
    ".type _FUN_06041382, @function\n"
    "_FUN_06041382:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xDE1A\n"  /* mov.l @(0x68,PC),r14  {[0x060413F4] = 0x060A5400} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7318\n"  /* add #24,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8904\n"  /* bt 0x060413A2 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x335C\n"  /* add r5,r3 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B04\n"  /* bf 0x060413AC */
    ".word 0xE0F9\n"  /* mov #-7,r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x901E\n"  /* mov.w @(0x3C,PC),r0 */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8904\n"  /* bt 0x060413C0 */
    ".word 0xE0FF\n"  /* mov #-1,r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x9013\n"  /* mov.w @(0x26,PC),r0 */
    ".word 0x0326\n"  /* mov.l r2,@(r0,r3) */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x0366\n"  /* mov.l r6,@(r0,r3) */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x0376\n"  /* mov.l r7,@(r0,r3) */
    ".word 0xB582\n"  /* bsr 0x06041EE8 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0348\n"  /* .word 0x0348 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06034DEA */
    ".word 0x4DEA\n"  /* .word 0x4DEA */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x5400\n"  /* mov.l @(0x0,r0),r4 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0604144C] = 0x060A5400} */
    ".word 0x9026\n"  /* mov.w @(0x4C,PC),r0 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x003E\n"  /* mov.l @(r0,r3),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x06041408 */
    ".word 0x000B\n"  /* rts */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_0604140E, \"ax\"\n"

    ".global _FUN_0604140E\n"
    ".type _FUN_0604140E, @function\n"
    "_FUN_0604140E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8B02\n"  /* bf 0x0604141C */
    ".word 0xE218\n"  /* mov #24,r2 */
    ".word 0x3423\n"  /* cmp/ge r2,r4 */
    ".word 0x8B03\n"  /* bf 0x06041424 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0xE0FA\n"  /* mov #-6,r0 */
    ".word 0xD009\n"  /* mov.l @(0x24,PC),r0  {[0x0604144C] = 0x060A5400} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x034C\n"  /* mov.b @(r0,r4),r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B03\n"  /* bf 0x06041436 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0xE0F9\n"  /* mov #-7,r0 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06041450] = 0x0603667E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8908\n"  /* bt 0x06041454 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0xE0F6\n"  /* mov #-10,r0 */
    ".word 0x0348\n"  /* .word 0x0348 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x5400\n"  /* mov.l @(0x0,r0),r4 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603667E */
    ".word 0x667E\n"  /* exts.b r7,r6 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x060414C8] = 0x060349B6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x060414CC] = 0x060A5400} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x6130\n"  /* mov.b @r3,r1 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060416A8, \"ax\"\n"

    ".global _FUN_060416A8\n"
    ".type _FUN_060416A8, @function\n"
    "_FUN_060416A8:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE900\n"  /* mov #0,r9 */
    ".word 0x7FEC\n"  /* add #-20,r15 */
    ".word 0xDD20\n"  /* mov.l @(0x80,PC),r13  {[0x06041730] = 0x060A5400} */
    ".word 0x2F92\n"  /* mov.l r9,@r15 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x503F\n"  /* mov.l @(0x3C,r3),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D0A\n"  /* bt/s 0x060416D0 */
    ".word 0x6C93\n"  /* mov r9,r12 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x523F\n"  /* mov.l @(0x3C,r3),r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x132F\n"  /* mov.l r2,@(0x3C,r3) */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x8903\n"  /* bt 0x060416D0 */
    ".word 0xB629\n"  /* bsr 0x0604231E */
    ".word 0x0009\n"  /* nop */
    ".word 0xA063\n"  /* bra 0x06041796 */
    ".word 0xE003\n"  /* mov #3,r0 */
    ".word 0x922B\n"  /* mov.w @(0x56,PC),r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06041734] = 0x06035C4E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x53F1\n"  /* mov.l @(0x4,r15),r3 */
    ".word 0x654F\n"  /* exts.w r4,r5 */
    ".word 0x2539\n"  /* and r3,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8901\n"  /* bt 0x060416E8 */
    ".word 0xA001\n"  /* bra 0x060416EA */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B2B\n"  /* bf 0x06041748 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x06041738] = 0x0000FBFF} */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x0604173C] = 0x06035C54} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06041740] = 0x06034984} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06041744] = 0x06035168} */
    ".word 0x61D2\n"  /* mov.l @r13,r1 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x7140\n"  /* add #64,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0xE04C\n"  /* mov #76,r0 */
    ".word 0x002E\n"  /* mov.l @(r0,r2),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8925\n"  /* bt 0x06041764 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0xE04C\n"  /* mov #76,r0 */
    ".word 0x6433\n"  /* mov r3,r4 */
    ".word 0x023E\n"  /* mov.l @(r0,r3),r2 */
    ".word 0xE050\n"  /* mov #80,r0 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0xA01D\n"  /* bra 0x06041764 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0400\n"  /* .word 0x0400 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_060349B6 */
    ".word 0x49B6\n"  /* .word 0x49B6 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x5400\n"  /* mov.l @(0x0,r0),r4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C4E\n"  /* mov.l @(0x38,r4),r12 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFBFF\n"  /* .word 0xFBFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06035C54 */
    ".word 0x5C54\n"  /* mov.l @(0x10,r5),r12 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06034984 */
    ".word 0x4984\n"  /* .word 0x4984 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x060417E4] = 0x060349C4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B06\n"  /* bf 0x06041764 */
    ".word 0x61D2\n"  /* mov.l @r13,r1 */
    ".word 0x62F3\n"  /* mov r15,r2 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x060417E8] = 0x06035168} */
    ".word 0x7140\n"  /* add #64,r1 */
    ".word 0x7208\n"  /* add #8,r2 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0xA010\n"  /* bra 0x06041788 */
    ".word 0x6E93\n"  /* mov r9,r14 */
    ".word 0xB01E\n"  /* bsr 0x060417A8 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x06041774 */
    ".word 0xA009\n"  /* bra 0x06041786 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0xB056\n"  /* bsr 0x06041826 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x3C0C\n"  /* add r0,r12 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x32A7\n"  /* cmp/gt r10,r2 */
    ".word 0x8B01\n"  /* bf 0x06041786 */
    ".word 0xA008\n"  /* bra 0x06041796 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x7E01\n"  /* add #1,r14 */
    ".word 0x3EB3\n"  /* cmp/ge r11,r14 */
    ".word 0x8BED\n"  /* bf 0x06041768 */
    ".word 0x4C15\n"  /* cmp/pl r12 */
    ".word 0x8B01\n"  /* bf 0x06041794 */
    ".word 0xA001\n"  /* bra 0x06041796 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F14\n"  /* add #20,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".global _FUN_060417a8\n"
    "_FUN_060417a8:\n"
    ".word 0xD510\n"  /* mov.l @(0x40,PC),r5  {[0x060417EC] = 0x060A5400} */
    ".word 0xA025\n"  /* bra 0x060417F8 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0xA020\n"  /* bra 0x060417F4 */
    ".word 0xE058\n"  /* mov #88,r0 */
    ".word 0x9010\n"  /* mov.w @(0x20,PC),r0 */
    ".word 0xA01D\n"  /* bra 0x060417F4 */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x900E\n"  /* mov.w @(0x1C,PC),r0 */
    ".word 0xA01A\n"  /* bra 0x060417F4 */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x900C\n"  /* mov.w @(0x18,PC),r0 */
    ".word 0xA017\n"  /* bra 0x060417F4 */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x900A\n"  /* mov.w @(0x14,PC),r0 */
    ".word 0xA014\n"  /* bra 0x060417F4 */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x9008\n"  /* mov.w @(0x10,PC),r0 */
    ".word 0xA011\n"  /* bra 0x060417F4 */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x9006\n"  /* mov.w @(0xC,PC),r0 */
    ".word 0xA00E\n"  /* bra 0x060417F4 */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x0304\n"  /* mov.b r0,@(r0,r3) */
    ".word 0x030C\n"  /* mov.b @(r0,r0),r3 */
    ".word 0x0328\n"  /* .word 0x0328 */
    ".word 0x0338\n"  /* .word 0x0338 */
    ".word 0x0348\n"  /* .word 0x0348 */
    ".word 0x01E0\n"  /* .word 0x01E0 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_060349C4 */
    ".word 0x49C4\n"  /* .word 0x49C4 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x5400\n"  /* mov.l @(0x0,r0),r4 */
    ".word 0x6452\n"  /* mov.l @r5,r4 */
    ".word 0x9034\n"  /* mov.w @(0x68,PC),r0 */
    ".word 0xA010\n"  /* bra 0x06041818 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89D8\n"  /* bt 0x060417AE */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89D9\n"  /* bt 0x060417B4 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89DA\n"  /* bt 0x060417BA */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x89DB\n"  /* bt 0x060417C0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x89DC\n"  /* bt 0x060417C6 */
    ".word 0x8805\n"  /* cmp/eq #5,r0 */
    ".word 0x89DD\n"  /* bt 0x060417CC */
    ".word 0x8806\n"  /* cmp/eq #6,r0 */
    ".word 0x89DE\n"  /* bt 0x060417D2 */
    ".word 0x8807\n"  /* cmp/eq #7,r0 */
    ".word 0x89EB\n"  /* bt 0x060417F0 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B01\n"  /* bf 0x06041820 */
    ".word 0xA001\n"  /* bra 0x06041822 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06041D74, \"ax\"\n"

    ".global _FUN_06041D74\n"
    ".type _FUN_06041D74, @function\n"
    "_FUN_06041D74:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF0\n"  /* add #-16,r15 */
    ".word 0xDE1E\n"  /* mov.l @(0x78,PC),r14  {[0x06041DF4] = 0x060A5400} */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x9034\n"  /* mov.w @(0x68,PC),r0 */
    ".word 0x023E\n"  /* mov.l @(r0,r3),r2 */
    ".word 0x3240\n"  /* cmp/eq r4,r2 */
    ".word 0x8F41\n"  /* bf/s 0x06041E0C */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x902F\n"  /* mov.w @(0x5E,PC),r0 */
    ".word 0x002E\n"  /* mov.l @(r0,r2),r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B24\n"  /* bf 0x06041DDE */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x902B\n"  /* mov.w @(0x56,PC),r0 */
    ".word 0x023E\n"  /* mov.l @(r0,r3),r2 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06041DF8] = 0x0000FFFF} */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B1E\n"  /* bf 0x06041DDE */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x9026\n"  /* mov.w @(0x4C,PC),r0 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06041DFC] = 0x060364D4} */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8901\n"  /* bt 0x06041DB6 */
    ".word 0xA093\n"  /* bra 0x06041EDC */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06041E00] = 0x060349B6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x6130\n"  /* mov.b @r3,r1 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x6232\n"  /* mov.l @r3,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0xE204\n"  /* mov #4,r2 */
    ".word 0x9009\n"  /* mov.w @(0x12,PC),r0 */
    ".word 0x0326\n"  /* mov.l r2,@(r0,r3) */
    ".word 0xA017\n"  /* bra 0x06041E0C */
    ".word 0x0009\n"  /* nop */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0x9006\n"  /* mov.w @(0xC,PC),r0 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8B0D\n"  /* bf 0x06041E04 */
    ".word 0xA010\n"  /* bra 0x06041E0C */
    ".word 0x6CD3\n"  /* mov r13,r12 */
    ".word 0x0338\n"  /* .word 0x0338 */
    ".word 0x0340\n"  /* .word 0x0340 */
    ".word 0x0344\n"  /* mov.b r4,@(r0,r3) */
    ".word 0x033C\n"  /* mov.b @(r0,r3),r3 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x5400\n"  /* mov.l @(0x0,r0),r4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_060364D4 */
    ".word 0x64D4\n"  /* mov.b @r13+,r4 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_060349B6 */
    ".word 0x49B6\n"  /* .word 0x49B6 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x9054\n"  /* mov.w @(0xA8,PC),r0 */
    ".word 0x0236\n"  /* mov.l r3,@(r0,r2) */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x9151\n"  /* mov.w @(0xA2,PC),r1 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B1F\n"  /* bf 0x06041E56 */
    ".word 0x66E2\n"  /* mov.l @r14,r6 */
    ".word 0x904D\n"  /* mov.w @(0x9A,PC),r0 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xD327\n"  /* mov.l @(0x9C,PC),r3  {[0x06041EBC] = 0x0603683C} */
    ".word 0x066E\n"  /* mov.l @(r0,r6),r6 */
    ".word 0x70FC\n"  /* add #-4,r0 */
    ".word 0x055E\n"  /* mov.l @(r0,r5),r5 */
    ".word 0x70FC\n"  /* add #-4,r0 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x044E\n"  /* mov.l @(r0,r4),r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x6322\n"  /* mov.l @r2,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8F0E\n"  /* bf/s 0x06041E56 */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x9039\n"  /* mov.w @(0x72,PC),r0 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x0326\n"  /* mov.l r2,@(r0,r3) */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06041EC0] = 0x060349B6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7404\n"  /* add #4,r4 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0x7304\n"  /* add #4,r3 */
    ".word 0x6130\n"  /* mov.b @r3,r1 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x912C\n"  /* mov.w @(0x58,PC),r1 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8B0F\n"  /* bf 0x06041E80 */
    ".word 0x922A\n"  /* mov.w @(0x54,PC),r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06041EC4] = 0x06035C4E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6503\n"  /* mov r0,r5 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x645F\n"  /* exts.w r5,r4 */
    ".word 0x2439\n"  /* and r3,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8901\n"  /* bt 0x06041E78 */
    ".word 0xA001\n"  /* bra 0x06041E7A */
    ".word 0xE401\n"  /* mov #1,r4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8900\n"  /* bt 0x06041E80 */
    ".word 0x6CD3\n"  /* mov r13,r12 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x9117\n"  /* mov.w @(0x2E,PC),r1 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8B0F\n"  /* bf 0x06041EAA */
    ".word 0xE240\n"  /* mov #64,r2 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06041EC4] = 0x06035C4E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x654F\n"  /* exts.w r4,r5 */
    ".word 0x2539\n"  /* and r3,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8901\n"  /* bt 0x06041EA2 */
    ".word 0xA001\n"  /* bra 0x06041EA4 */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x2558\n"  /* tst r5,r5 */
    ".word 0x8900\n"  /* bt 0x06041EAA */
    ".word 0x6CD3\n"  /* mov r13,r12 */
    ".word 0x60C3\n"  /* mov r12,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B0B\n"  /* bf 0x06041EC8 */
    ".word 0xA014\n"  /* bra 0x06041EDC */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x0338\n"  /* .word 0x0338 */
    ".word 0x0344\n"  /* mov.b r4,@(r0,r3) */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603683C */
    ".word 0x683C\n"  /* extu.b r3,r8 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_060349B6 */
    ".word 0x49B6\n"  /* .word 0x49B6 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C4E\n"  /* mov.l @(0x38,r4),r12 */
    ".word 0xD433\n"  /* mov.l @(0xCC,PC),r4  {[0x06041F98] = 0x0000FFF7} */
    ".word 0xD334\n"  /* mov.l @(0xD0,PC),r3  {[0x06041F9C] = 0x06035C54} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x905D\n"  /* mov.w @(0xBA,PC),r0 */
    ".word 0x02D6\n"  /* mov.l r13,@(r0,r2) */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x13DD\n"  /* mov.l r13,@(0x34,r3) */
    ".word 0x60D3\n"  /* mov r13,r0 */
    ".word 0x7F10\n"  /* add #16,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060422F0, \"ax\"\n"

    ".global _FUN_060422F0\n"
    ".type _FUN_060422F0, @function\n"
    "_FUN_060422F0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06042310] = 0x06035C4E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x604F\n"  /* exts.w r4,r0 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8906\n"  /* bt 0x06042314 */
    ".word 0xA006\n"  /* bra 0x06042316 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x01E4\n"  /* mov.b r14,@(r0,r1) */
    ".word 0x01DC\n"  /* mov.b @(r0,r13),r1 */
    ".word 0x01E0\n"  /* .word 0x01E0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5C4E\n"  /* mov.l @(0x38,r4),r12 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xE717\n"  /* mov #23,r7 */
    ".word 0xD51E\n"  /* mov.l @(0x78,PC),r5  {[0x0604239C] = 0x060A5400} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0x624E\n"  /* exts.b r4,r2 */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x0644\n"  /* mov.b r4,@(r0,r6) */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x7318\n"  /* add #24,r3 */
    ".word 0x336C\n"  /* add r6,r3 */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x7601\n"  /* add #1,r6 */
    ".word 0x3673\n"  /* cmp/ge r7,r6 */
    ".word 0x8BF4\n"  /* bf 0x06042326 */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0x124C\n"  /* mov.l r4,@(0x30,r2) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x134D\n"  /* mov.l r4,@(0x34,r3) */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0xE3FF\n"  /* mov #-1,r3 */
    ".word 0x123E\n"  /* mov.l r3,@(0x38,r2) */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0x124F\n"  /* mov.l r4,@(0x3C,r2) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0xE04C\n"  /* mov #76,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0xE050\n"  /* mov #80,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0xE054\n"  /* mov #84,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0xE058\n"  /* mov #88,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x9016\n"  /* mov.w @(0x2C,PC),r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x7008\n"  /* add #8,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x701C\n"  /* add #28,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x7010\n"  /* add #16,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x7010\n"  /* add #16,r0 */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x7018\n"  /* add #24,r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x9005\n"  /* mov.w @(0xA,PC),r0 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x0304\n"  /* mov.b r0,@(r0,r3) */
    ".word 0x01DC\n"  /* mov.b @(r0,r13),r1 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x5400\n"  /* mov.l @(0x0,r0),r4 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_060423A0, \"ax\"\n"

    ".global _FUN_060423A0\n"
    ".type _FUN_060423A0, @function\n"
    "_FUN_060423A0:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x060423F8] = 0x060349B6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0x63F3\n"  /* mov r15,r3 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x060423FC] = 0x060A5400} */
    ".word 0x6130\n"  /* mov.b @r3,r1 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0xD60F\n"  /* mov.l @(0x3C,PC),r6  {[0x060423FC] = 0x060A5400} */
    ".word 0xE04C\n"  /* mov #76,r0 */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x0346\n"  /* mov.l r4,@(r0,r3) */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0xE050\n"  /* mov #80,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0356\n"  /* mov.l r5,@(r0,r3) */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06042418, \"ax\"\n"

    ".global _FUN_06042418\n"
    ".type _FUN_06042418, @function\n"
    "_FUN_06042418:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8D02\n"  /* bt/s 0x06042426 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xEE01\n"  /* mov #1,r14 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0604244C] = 0x00B40000} */
    ".word 0x3423\n"  /* cmp/ge r2,r4 */
    ".word 0x8B01\n"  /* bf 0x06042430 */
    ".word 0xA005\n"  /* bra 0x0604243A */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x06042450] = 0x005A0000} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8B01\n"  /* bf 0x0604243A */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06042454] = 0x060424A2} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2EE8\n"  /* tst r14,r14 */
    ".word 0x8900\n"  /* bt 0x06042446 */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00B4\n"  /* mov.b r11,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x005A\n"  /* .word 0x005A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x24A2\n"  /* mov.l r10,@r4 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06042458, \"ax\"\n"

    ".global _FUN_06042458\n"
    ".type _FUN_06042458, @function\n"
    "_FUN_06042458:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4411\n"  /* cmp/pz r4 */
    ".word 0x8900\n"  /* bt 0x06042462 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x06042490] = 0x00B40000} */
    ".word 0x3423\n"  /* cmp/ge r2,r4 */
    ".word 0x8F02\n"  /* bf/s 0x0604246E */
    ".word 0xEE01\n"  /* mov #1,r14 */
    ".word 0xA008\n"  /* bra 0x0604247E */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x06042494] = 0x005A0000} */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8B03\n"  /* bf 0x0604247C */
    ".word 0xD206\n"  /* mov.l @(0x18,PC),r2  {[0x06042490] = 0x00B40000} */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0xA001\n"  /* bra 0x0604247E */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06042498] = 0x0604249C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x2EE8\n"  /* tst r14,r14 */
    ".word 0x8900\n"  /* bt 0x0604248A */
    ".word 0x600B\n"  /* neg r0,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00B4\n"  /* mov.b r11,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x005A\n"  /* .word 0x005A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x249C\n"  /* .word 0x249C */
    ".global _FUN_0604249c\n"
    "_FUN_0604249c:\n"
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x060424C4] = 0x005A0000} */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".global _FUN_060424a2\n"
    "_FUN_060424a2:\n"
    ".word 0xC709\n"  /* mova @(0x24,PC),r0  {0x060424C8} */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x6149\n"  /* swap.w r4,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x4108\n"  /* shll2 r1 */
    ".word 0x021D\n"  /* mov.w @(r0,r1),r2 */
    ".word 0x7002\n"  /* add #2,r0 */
    ".word 0x224E\n"  /* mulu.w r4,r2 */
    ".word 0x001D\n"  /* mov.w @(r0,r1),r0 */
    ".word 0x021A\n"  /* sts macl,r2 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x431A\n"  /* .word 0x431A */
    ".word 0x6229\n"  /* swap.w r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x000B\n"  /* rts */
    ".word 0x302C\n"  /* add r2,r0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x005A\n"  /* .word 0x005A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0477\n"  /* mul.l r7,r4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0478\n"  /* .word 0x0478 */
    ".word 0x0477\n"  /* mul.l r7,r4 */
    ".word 0x0476\n"  /* mov.l r7,@(r0,r4) */
    ".word 0x08EF\n"  /* mac.l @r14+,@r8+ */
    ".word 0x0476\n"  /* mov.l r7,@(r0,r4) */
    ".word 0x0D65\n"  /* mov.w r6,@(r0,r13) */
    ".word 0x0474\n"  /* mov.b r7,@(r0,r4) */
    ".word 0x11DB\n"  /* mov.l r13,@(0x2C,r1) */
    ".word 0x0473\n"  /* .word 0x0473 */
    ".word 0x164F\n"  /* mov.l r4,@(0x3C,r6) */
    ".word 0x0470\n"  /* .word 0x0470 */
    ".word 0x1AC2\n"  /* mov.l r12,@(0x8,r10) */
    ".word 0x046E\n"  /* mov.l @(r0,r6),r4 */
    ".word 0x1F32\n"  /* mov.l r3,@(0x8,r15) */
    ".word 0x046C\n"  /* mov.b @(r0,r6),r4 */
    ".word 0x23A0\n"  /* mov.b r10,@r3 */
    ".word 0x0468\n"  /* .word 0x0468 */
    ".word 0x280C\n"  /* .word 0x280C */
    ".word 0x0464\n"  /* mov.b r6,@(r0,r4) */
    ".word 0x2C74\n"  /* mov.b r7,@-r12 */
    ".word 0x0461\n"  /* .word 0x0461 */
    ".word 0x30D8\n"  /* sub r13,r0 */
    ".word 0x045D\n"  /* mov.w @(r0,r5),r4 */
    ".word 0x3539\n"  /* .word 0x3539 */
    ".word 0x0458\n"  /* .word 0x0458 */
    ".word 0x3996\n"  /* cmp/hi r9,r9 */
    ".word 0x0453\n"  /* .word 0x0453 */
    ".word 0x3DEE\n"  /* .word 0x3DEE */
    ".word 0x044F\n"  /* mac.l @r4+,@r4+ */
    ".word 0x4241\n"  /* .word 0x4241 */
    ".word 0x0448\n"  /* .word 0x0448 */
    ".word 0x4690\n"  /* .word 0x4690 */
    ".word 0x0443\n"  /* .word 0x0443 */
    ".word 0x4AD8\n"  /* .word 0x4AD8 */
    ".word 0x043D\n"  /* mov.w @(r0,r3),r4 */
    ".word 0x4F1B\n"  /* .word 0x4F1B */
    ".word 0x0436\n"  /* mov.l r3,@(r0,r4) */
    ".word 0x5358\n"  /* mov.l @(0x20,r5),r3 */
    ".word 0x0430\n"  /* .word 0x0430 */
    ".word 0x578E\n"  /* mov.l @(0x38,r8),r7 */
    ".word 0x0428\n"  /* .word 0x0428 */
    ".word 0x5BBE\n"  /* mov.l @(0x38,r11),r11 */
    ".word 0x0420\n"  /* .word 0x0420 */
    ".word 0x5FE6\n"  /* mov.l @(0x18,r14),r15 */
    ".word 0x0419\n"  /* .word 0x0419 */
    ".word 0x6406\n"  /* mov.l @r0+,r4 */
    ".word 0x0411\n"  /* .word 0x0411 */
    ".word 0x681F\n"  /* exts.w r1,r8 */
    ".word 0x0409\n"  /* .word 0x0409 */
    ".word 0x6C30\n"  /* mov.b @r3,r12 */
    ".word 0x03FF\n"  /* mac.l @r15+,@r3+ */
    ".word 0x7039\n"  /* add #57,r0 */
    ".word 0x03F7\n"  /* mul.l r15,r3 */
    ".word 0x7438\n"  /* add #56,r4 */
    ".word 0x03ED\n"  /* mov.w @(r0,r14),r3 */
    ".word 0x782F\n"  /* add #47,r8 */
    ".word 0x03E3\n"  /* .word 0x03E3 */
    ".word 0x7C1C\n"  /* add #28,r12 */
    ".word 0x03DA\n"  /* .word 0x03DA */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0x03CF\n"  /* mac.l @r12+,@r3+ */
    ".word 0x83D9\n"  /* .word 0x83D9 */
    ".word 0x03C5\n"  /* mov.w r12,@(r0,r3) */
    ".word 0x87A8\n"  /* .word 0x87A8 */
    ".word 0x03BA\n"  /* .word 0x03BA */
    ".word 0x8B6D\n"  /* bf 0x0604262C */
    ".word 0x03AE\n"  /* mov.l @(r0,r10),r3 */
    ".word 0x8F27\n"  /* bf/s 0x060425A4 */
    ".word 0x03A4\n"  /* mov.b r10,@(r0,r3) */
    ".word 0x92D5\n"  /* mov.w @(0x1AA,PC),r2 */
    ".word 0x0397\n"  /* mul.l r9,r3 */
    ".word 0x9679\n"  /* mov.w @(0xF2,PC),r6 */
    ".word 0x038B\n"  /* .word 0x038B */
    ".word 0x9A10\n"  /* mov.w @(0x20,PC),r10 */
    ".word 0x0380\n"  /* .word 0x0380 */
    ".word 0x9D9B\n"  /* mov.w @(0x136,PC),r13 */
    ".word 0x0372\n"  /* .word 0x0372 */
    ".word 0xA11B\n"  /* bra 0x060427A0 */
    ".word 0x0366\n"  /* mov.l r6,@(r0,r3) */
    ".word 0xA48D\n"  /* bra 0x06042E88 */
    ".word 0x0359\n"  /* .word 0x0359 */
    ".word 0xA7F3\n"  /* bra 0x06043558 */
    ".word 0x034B\n"  /* .word 0x034B */
    ".word 0xAB4C\n"  /* bra 0x06041C0E */
    ".word 0x033E\n"  /* mov.l @(r0,r3),r3 */
    ".word 0xAE97\n"  /* bra 0x060422A8 */
    ".word 0x032F\n"  /* mac.l @r2+,@r3+ */
    ".word 0xB1D5\n"  /* bsr 0x06042928 */
    ".word 0x0322\n"  /* stc vbr,r3 */
    ".word 0xB504\n"  /* bsr 0x06042F8A */
    ".word 0x0313\n"  /* .word 0x0313 */
    ".word 0xB826\n"  /* bsr 0x060415D2 */
    ".word 0x0305\n"  /* mov.w r0,@(r0,r3) */
    ".word 0xBB39\n"  /* bsr 0x06041BFC */
    ".word 0x02F6\n"  /* mov.l r15,@(r0,r2) */
    ".word 0xBE3E\n"  /* bsr 0x0604220A */
    ".word 0x02E7\n"  /* mul.l r14,r2 */
    ".word 0xC134\n"  /* mov.w r0,@(0x68,GBR) */
    ".word 0x02D8\n"  /* .word 0x02D8 */
    ".word 0xC41B\n"  /* mov.b @(0x1B,GBR),r0 */
    ".word 0x02C8\n"  /* .word 0x02C8 */
    ".word 0xC6F3\n"  /* mov.l @(0x3CC,GBR),r0 */
    ".word 0x02B8\n"  /* .word 0x02B8 */
    ".word 0xC9BB\n"  /* and #0xBB,r0 */
    ".word 0x02A8\n"  /* .word 0x02A8 */
    ".word 0xCC73\n"  /* .word 0xCC73 */
    ".word 0x0298\n"  /* .word 0x0298 */
    ".word 0xCF1B\n"  /* .word 0xCF1B */
    ".word 0x0288\n"  /* .word 0x0288 */
    ".word 0xD1B3\n"  /* mov.l @(0x2CC,PC),r1  {[0x06042874] = 0x0000F737} */
    ".word 0x0278\n"  /* .word 0x0278 */
    ".word 0xD43B\n"  /* mov.l @(0xEC,PC),r4  {[0x06042698] = 0x8902A003} */
    ".word 0x0266\n"  /* mov.l r6,@(r0,r2) */
    ".word 0xD6B3\n"  /* mov.l @(0x2CC,PC),r6  {[0x0604287C] = 0x00010000} */
    ".word 0x0256\n"  /* mov.l r5,@(r0,r2) */
    ".word 0xD919\n"  /* mov.l @(0x64,PC),r9  {[0x06042618] = 0x006EFE98} */
    ".word 0x0244\n"  /* mov.b r4,@(r0,r2) */
    ".word 0xDB6F\n"  /* mov.l @(0x1BC,PC),r11  {[0x06042774] = 0x0000366A} */
    ".word 0x0234\n"  /* mov.b r3,@(r0,r2) */
    ".word 0xDDB3\n"  /* mov.l @(0x2CC,PC),r13  {[0x06042888] = 0x001B2545} */
    ".word 0x0221\n"  /* .word 0x0221 */
    ".word 0xDFE7\n"  /* mov.l @(0x39C,PC),r15  {[0x0604295C] = 0x00034556} */
    ".word 0x0211\n"  /* .word 0x0211 */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x01FE\n"  /* mov.l @(r0,r15),r1 */
    ".word 0xE419\n"  /* mov #25,r4 */
    ".word 0x01EC\n"  /* mov.b @(r0,r14),r1 */
    ".word 0xE617\n"  /* mov #23,r6 */
    ".word 0x01DB\n"  /* .word 0x01DB */
    ".word 0xE803\n"  /* mov #3,r8 */
    ".word 0x01C8\n"  /* .word 0x01C8 */
    ".word 0xE9DE\n"  /* mov #-34,r9 */
    ".word 0x01B5\n"  /* mov.w r11,@(r0,r1) */
    ".word 0xEBA6\n"  /* mov #-90,r11 */
    ".word 0x01A4\n"  /* mov.b r10,@(r0,r1) */
    ".word 0xED5B\n"  /* mov #91,r13 */
    ".word 0x0190\n"  /* .word 0x0190 */
    ".word 0xEEFF\n"  /* mov #-1,r14 */
    ".word 0x017E\n"  /* mov.l @(r0,r7),r1 */
    ".word 0xF08F\n"  /* .word 0xF08F */
    ".word 0x016B\n"  /* .word 0x016B */
    ".word 0xF20D\n"  /* .word 0xF20D */
    ".word 0x0158\n"  /* .word 0x0158 */
    ".word 0xF378\n"  /* .word 0xF378 */
    ".word 0x0145\n"  /* mov.w r4,@(r0,r1) */
    ".word 0xF4D0\n"  /* .word 0xF4D0 */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0xF615\n"  /* .word 0xF615 */
    ".word 0x011F\n"  /* mac.l @r1+,@r1+ */
    ".word 0xF746\n"  /* .word 0xF746 */
    ".word 0x010B\n"  /* .word 0x010B */
    ".word 0xF865\n"  /* .word 0xF865 */
    ".word 0x00F7\n"  /* mul.l r15,r0 */
    ".word 0xF970\n"  /* .word 0xF970 */
    ".word 0x00E4\n"  /* mov.b r14,@(r0,r0) */
    ".word 0xFA67\n"  /* .word 0xFA67 */
    ".word 0x00D1\n"  /* .word 0x00D1 */
    ".word 0xFB4B\n"  /* .word 0xFB4B */
    ".word 0x00BD\n"  /* mov.w @(r0,r11),r0 */
    ".word 0xFC1C\n"  /* .word 0xFC1C */
    ".word 0x00A9\n"  /* .word 0x00A9 */
    ".word 0xFCD9\n"  /* .word 0xFCD9 */
    ".word 0x0095\n"  /* mov.w r9,@(r0,r0) */
    ".word 0xFD82\n"  /* .word 0xFD82 */
    ".word 0x0081\n"  /* .word 0x0081 */
    ".word 0xFE17\n"  /* .word 0xFE17 */
    ".word 0x006E\n"  /* mov.l @(r0,r6),r0 */
    ".word 0xFE98\n"  /* .word 0xFE98 */
    ".word 0x005A\n"  /* .word 0x005A */
    ".word 0xFF06\n"  /* .word 0xFF06 */
    ".word 0x0046\n"  /* mov.l r4,@(r0,r0) */
    ".word 0xFF60\n"  /* .word 0xFF60 */
    ".word 0x0032\n"  /* .word 0x0032 */
    ".word 0xFFA6\n"  /* .word 0xFFA6 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0xFFD8\n"  /* .word 0xFFD8 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0xFFF6\n"  /* .word 0xFFF6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06042634, \"ax\"\n"

    ".global _FUN_06042634\n"
    ".type _FUN_06042634, @function\n"
    "_FUN_06042634:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x4F02\n"  /* sts.l mach,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x6A53\n"  /* mov r5,r10 */
);
__asm__(



    ".balign 2\n"






    ".section .text.FUN_06042646, \"ax\"\n"

    ".global _FUN_06042646\n"
    ".type _FUN_06042646, @function\n"
    "_FUN_06042646:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDB2D\n"  /* mov.l @(0xB4,PC),r11  {[0x06042700] = 0x06042714} */
    ".word 0x4A11\n"  /* cmp/pz r10 */
    ".word 0x8D01\n"  /* bt/s 0x06042652 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x65AB\n"  /* neg r10,r5 */
    ".word 0x4C11\n"  /* cmp/pz r12 */
    ".word 0x8900\n"  /* bt 0x06042658 */
    ".word 0x64CB\n"  /* neg r12,r4 */
    ".word 0xE241\n"  /* mov #65,r2 */
    ".word 0x3523\n"  /* cmp/ge r2,r5 */
    ".word 0x8902\n"  /* bt 0x06042664 */
    ".word 0xDD29\n"  /* mov.l @(0xA4,PC),r13  {[0x06042704] = 0x7FFF0000} */
    ".word 0xA008\n"  /* bra 0x06042674 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD025\n"  /* mov.l @(0x94,PC),r0  {[0x060426FC] = 0xFFFFFF00} */
    ".word 0x6249\n"  /* swap.w r4,r2 */
    ".word 0x2052\n"  /* mov.l r5,@r0 */
    ".word 0x622F\n"  /* exts.w r2,r2 */
    ".word 0x1024\n"  /* mov.l r2,@(0x10,r0) */
    ".word 0x4428\n"  /* shll16 r4 */
    ".word 0x1045\n"  /* mov.l r4,@(0x14,r0) */
    ".word 0x5D05\n"  /* mov.l @(0x14,r0),r13 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xE55A\n"  /* mov #90,r5 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x3E5C\n"  /* add r5,r14 */
    ".word 0x4E21\n"  /* shar r14 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x02BE\n"  /* mov.l @(r0,r11),r2 */
    ".word 0x32D7\n"  /* cmp/gt r13,r2 */
    ".word 0x8909\n"  /* bt 0x0604269E */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7401\n"  /* add #1,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x03BE\n"  /* mov.l @(r0,r11),r3 */
    ".word 0x3D33\n"  /* cmp/ge r3,r13 */
    ".word 0x8902\n"  /* bt 0x060426A0 */
    ".word 0xA003\n"  /* bra 0x060426A4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x3453\n"  /* cmp/ge r5,r4 */
    ".word 0x8BE9\n"  /* bf 0x06042678 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x03BE\n"  /* mov.l @(r0,r11),r3 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x7004\n"  /* add #4,r0 */
    ".word 0x05BE\n"  /* mov.l @(r0,r11),r5 */
    ".word 0x354D\n"  /* dmuls.l r4,r5 */
    ".word 0x030A\n"  /* sts mach,r3 */
    ".word 0x041A\n"  /* sts macl,r4 */
    ".word 0x243D\n"  /* .word 0x243D */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x06042708] = 0x00010000} */
    ".word 0x3427\n"  /* cmp/gt r2,r4 */
    ".word 0x8B00\n"  /* bf 0x060426C4 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x06042708] = 0x00010000} */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x4028\n"  /* shll16 r0 */
    ".word 0x4C11\n"  /* cmp/pz r12 */
    ".word 0x8D01\n"  /* bt/s 0x060426D0 */
    ".word 0x340C\n"  /* add r0,r4 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x4A11\n"  /* cmp/pz r10 */
    ".word 0x8907\n"  /* bt 0x060426E4 */
    ".word 0x4C11\n"  /* cmp/pz r12 */
    ".word 0x8B02\n"  /* bf 0x060426DE */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x0604270C] = 0x00B40000} */
    ".word 0xA001\n"  /* bra 0x060426E0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x06042710] = 0xFF4C0000} */
    ".word 0x3248\n"  /* sub r4,r2 */
    ".word 0x6423\n"  /* mov r2,r4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F06\n"  /* lds.l @r15+,mach */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x2714\n"  /* mov.b r1,@-r7 */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B4\n"  /* mov.b r11,@(r0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFF4C\n"  /* .word 0xFF4C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0039\n"  /* .word 0x0039 */
    ".word 0x4A3A\n"  /* .word 0x4A3A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0477\n"  /* mul.l r7,r4 */
    ".word 0x0039\n"  /* .word 0x0039 */
    ".word 0x414B\n"  /* .word 0x414B */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x08F0\n"  /* .word 0x08F0 */
    ".word 0x0039\n"  /* .word 0x0039 */
    ".word 0x2F70\n"  /* mov.b r7,@r15 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0D6A\n"  /* .word 0x0D6A */
    ".word 0x0039\n"  /* .word 0x0039 */
    ".word 0x14AD\n"  /* mov.l r10,@(0x34,r4) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x11E6\n"  /* mov.l r14,@(0x18,r1) */
    ".word 0x0038\n"  /* ldtlb */
    ".word 0xF10C\n"  /* .word 0xF10C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1665\n"  /* mov.l r6,@(0x14,r6) */
    ".word 0x0038\n"  /* ldtlb */
    ".word 0xC498\n"  /* mov.b @(0x98,GBR),r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1AE8\n"  /* mov.l r14,@(0x20,r10) */
    ".word 0x0038\n"  /* ldtlb */
    ".word 0x8F5F\n"  /* bf/s 0x0604280C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1F6E\n"  /* mov.l r6,@(0x38,r15) */
    ".word 0x0038\n"  /* ldtlb */
    ".word 0x5170\n"  /* mov.l @(0x0,r7),r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x23FA\n"  /* xor r15,r3 */
    ".word 0x0038\n"  /* ldtlb */
    ".word 0x0AE0\n"  /* .word 0x0AE0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x288B\n"  /* or r8,r8 */
    ".word 0x0037\n"  /* mul.l r3,r0 */
    ".word 0xBBC4\n"  /* bsr 0x06041EEE */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x2D23\n"  /* .word 0x2D23 */
    ".word 0x0037\n"  /* mul.l r3,r0 */
    ".word 0x6435\n"  /* mov.w @r3+,r4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x31C2\n"  /* cmp/hs r12,r1 */
    ".word 0x0037\n"  /* mul.l r3,r0 */
    ".word 0x044F\n"  /* mac.l @r4+,@r4+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x366A\n"  /* .word 0x366A */
    ".word 0x0036\n"  /* mov.l r3,@(r0,r0) */
    ".word 0x9C2F\n"  /* mov.w @(0x5E,PC),r12 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x3B1A\n"  /* .word 0x3B1A */
    ".word 0x0036\n"  /* mov.l r3,@(r0,r0) */
    ".word 0x2BF6\n"  /* mov.l r15,@-r11 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x3FD3\n"  /* cmp/ge r13,r15 */
    ".word 0x0035\n"  /* mov.w r3,@(r0,r0) */
    ".word 0xB3C7\n"  /* bsr 0x06042F1C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4498\n"  /* .word 0x4498 */
    ".word 0x0035\n"  /* mov.w r3,@(r0,r0) */
    ".word 0x33C7\n"  /* cmp/gt r12,r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4968\n"  /* .word 0x4968 */
    ".word 0x0034\n"  /* mov.b r3,@(r0,r0) */
    ".word 0xAC1E\n"  /* bra 0x06041FDA */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4E44\n"  /* .word 0x4E44 */
    ".word 0x0034\n"  /* mov.b r3,@(r0,r0) */
    ".word 0x1CF7\n"  /* mov.l r15,@(0x1C,r12) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x532D\n"  /* mov.l @(0x34,r2),r3 */
    ".word 0x0033\n"  /* .word 0x0033 */
    ".word 0x867E\n"  /* .word 0x867E */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x5825\n"  /* mov.l @(0x14,r2),r8 */
    ".word 0x0032\n"  /* .word 0x0032 */
    ".word 0xE8E2\n"  /* mov #-30,r8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x5D2D\n"  /* mov.l @(0x34,r2),r13 */
    ".word 0x0032\n"  /* .word 0x0032 */
    ".word 0x4454\n"  /* .word 0x4454 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x6244\n"  /* mov.b @r4+,r2 */
    ".word 0x0031\n"  /* .word 0x0031 */
    ".word 0x9908\n"  /* mov.w @(0x10,PC),r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x676E\n"  /* exts.b r6,r7 */
    ".word 0x0030\n"  /* .word 0x0030 */
    ".word 0xE733\n"  /* mov #51,r7 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x6CAA\n"  /* .word 0x6CAA */
    ".word 0x0030\n"  /* .word 0x0030 */
    ".word 0x2F0C\n"  /* .word 0x2F0C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x71FA\n"  /* add #-6,r1 */
    ".word 0x002F\n"  /* mac.l @r2+,@r0+ */
    ".word 0x70CD\n"  /* add #-51,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x775F\n"  /* add #95,r7 */
    ".word 0x002E\n"  /* mov.l @(r0,r2),r0 */
    ".word 0xACB2\n"  /* bra 0x0604214A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x7CDC\n"  /* add #-36,r12 */
    ".word 0x002D\n"  /* mov.w @(r0,r2),r0 */
    ".word 0xE2F7\n"  /* mov #-9,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8270\n"  /* .word 0x8270 */
    ".word 0x002D\n"  /* mov.w @(r0,r2),r0 */
    ".word 0x13DB\n"  /* mov.l r13,@(0x2C,r3) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x881E\n"  /* cmp/eq #30,r0 */
    ".word 0x002C\n"  /* mov.b @(r0,r2),r0 */
    ".word 0x3F9F\n"  /* .word 0x3F9F */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8DE7\n"  /* bt/s 0x060427D0 */
    ".word 0x002B\n"  /* rte */
    ".word 0x6686\n"  /* mov.l @r8+,r6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x93CD\n"  /* mov.w @(0x19A,PC),r3 */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x88D2\n"  /* cmp/eq #-46,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x99D2\n"  /* mov.w @(0x1A4,PC),r9 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xA6C9\n"  /* bra 0x060435A8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x9FF7\n"  /* mov.w @(0x1EE,PC),r15 */
    ".word 0x0028\n"  /* clrmac */
    ".word 0xC0B2\n"  /* mov.b r0,@(0xB2,GBR) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xA63F\n"  /* bra 0x060434A0 */
    ".word 0x0027\n"  /* mul.l r2,r0 */
    ".word 0xD6D3\n"  /* mov.l @(0x34C,PC),r6  {[0x06042B70] = 0x263B5249} */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xACAC\n"  /* bra 0x06042182 */
    ".word 0x0026\n"  /* mov.l r2,@(r0,r0) */
    ".word 0xE978\n"  /* mov #120,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xB340\n"  /* bsr 0x06042EB2 */
    ".word 0x0025\n"  /* mov.w r2,@(r0,r0) */
    ".word 0xF8E8\n"  /* .word 0xF8E8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xB9FE\n"  /* bsr 0x06041C36 */
    ".word 0x0025\n"  /* mov.w r2,@(r0,r0) */
    ".word 0x056F\n"  /* mac.l @r6+,@r5+ */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC0E8\n"  /* mov.b r0,@(0xE8,GBR) */
    ".word 0x0024\n"  /* mov.b r2,@(r0,r0) */
    ".word 0x0F5A\n"  /* .word 0x0F5A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xC802\n"  /* tst #0x02,r0 */
    ".word 0x0023\n"  /* .word 0x0023 */
    ".word 0x16F5\n"  /* mov.l r15,@(0x14,r6) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xCF4E\n"  /* .word 0xCF4E */
    ".word 0x0022\n"  /* stc vbr,r0 */
    ".word 0x1C8D\n"  /* mov.l r8,@(0x34,r12) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xD6CF\n"  /* mov.l @(0x33C,PC),r6  {[0x06042B94] = 0x622C2520} */
    ".word 0x0021\n"  /* .word 0x0021 */
    ".word 0x2071\n"  /* mov.w r7,@r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xDE89\n"  /* mov.l @(0x224,PC),r14  {[0x06042A84] = 0x25F00000} */
    ".word 0x0020\n"  /* .word 0x0020 */
    ".word 0x22EE\n"  /* mulu.w r14,r2 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xE680\n"  /* mov #-128,r6 */
    ".word 0x001F\n"  /* mac.l @r1+,@r0+ */
    ".word 0x2455\n"  /* mov.w r5,@-r4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xEEB9\n"  /* mov #-71,r14 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0x24F5\n"  /* mov.w r15,@-r4 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF737\n"  /* .word 0xF737 */
    ".word 0x001D\n"  /* mov.w @(r0,r1),r0 */
    ".word 0x251D\n"  /* .word 0x251D */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0x251D\n"  /* .word 0x251D */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0918\n"  /* .word 0x0918 */
    ".word 0x001B\n"  /* sleep */
    ".word 0x2545\n"  /* mov.w r4,@-r5 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x1286\n"  /* mov.l r8,@(0x18,r2) */
    ".word 0x001A\n"  /* sts macl,r0 */
    ".word 0x25E5\n"  /* mov.w r14,@-r5 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x1C51\n"  /* mov.l r5,@(0x4,r12) */
    ".word 0x0019\n"  /* div0u */
    ".word 0x274C\n"  /* .word 0x274C */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x267E\n"  /* mulu.w r7,r6 */
    ".word 0x0018\n"  /* sett */
    ".word 0x29C9\n"  /* and r12,r9 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x3116\n"  /* cmp/hi r1,r1 */
    ".word 0x0017\n"  /* mul.l r1,r0 */
    ".word 0x2DAD\n"  /* .word 0x2DAD */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x3C22\n"  /* cmp/hs r2,r12 */
    ".word 0x0016\n"  /* mov.l r1,@(r0,r0) */
    ".word 0x3345\n"  /* dmulu.l r4,r3 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x47AA\n"  /* .word 0x47AA */
    ".word 0x0015\n"  /* mov.w r1,@(r0,r0) */
    ".word 0x3AE0\n"  /* cmp/eq r14,r10 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x53B9\n"  /* mov.l @(0x24,r11),r3 */
    ".word 0x0014\n"  /* mov.b r1,@(r0,r0) */
    ".word 0x44CB\n"  /* .word 0x44CB */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x605A\n"  /* .word 0x605A */
    ".word 0x0013\n"  /* .word 0x0013 */
    ".word 0x5152\n"  /* mov.l @(0x8,r5),r1 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x6D9B\n"  /* neg r9,r13 */
    ".word 0x0012\n"  /* stc gbr,r0 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x7B89\n"  /* add #-119,r11 */
    ".word 0x0011\n"  /* .word 0x0011 */
    ".word 0x7366\n"  /* add #102,r3 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x8A34\n"  /* .word 0x8A34 */
    ".word 0x0010\n"  /* .word 0x0010 */
    ".word 0x8988\n"  /* bt 0x060427F6 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x99AF\n"  /* mov.w @(0x15E,PC),r9 */
    ".word 0x000F\n"  /* mac.l @r0+,@r0+ */
    ".word 0xA371\n"  /* bra 0x06042FD0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xAA0E\n"  /* bra 0x06041D0E */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0xC168\n"  /* mov.w r0,@(0xD0,GBR) */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xBB67\n"  /* bsr 0x06041FC8 */
    ".word 0x000D\n"  /* mov.w @(r0,r0),r0 */
    ".word 0xE3B4\n"  /* mov #-76,r3 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xCDD6\n"  /* .word 0xCDD6 */
    ".word 0x000D\n"  /* mov.w @(r0,r0),r0 */
    ".word 0x0A9B\n"  /* .word 0x0A9B */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xE177\n"  /* mov #119,r1 */
    ".word 0x000C\n"  /* mov.b @(r0,r0),r0 */
    ".word 0x365F\n"  /* .word 0x365F */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xF66D\n"  /* .word 0xF66D */
    ".word 0x000B\n"  /* rts */
    ".word 0x6743\n"  /* mov r4,r7 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x0CE0\n"  /* .word 0x0CE0 */
    ".word 0x000A\n"  /* sts mach,r0 */
    ".word 0x9D88\n"  /* mov.w @(0x110,PC),r13 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x24FE\n"  /* mulu.w r15,r4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD96D\n"  /* mov.l @(0x1B4,PC),r9  {[0x06042AD8] = 0x53492369} */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x3EFC\n"  /* add r15,r14 */
    ".word 0x0009\n"  /* nop */
    ".word 0x1B2E\n"  /* mov.l r2,@(0x38,r11) */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x5B19\n"  /* mov.l @(0x24,r1),r11 */
    ".word 0x0008\n"  /* clrt */
    ".word 0x6307\n"  /* not r0,r3 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x799F\n"  /* add #-97,r9 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0xB132\n"  /* bsr 0x06042BA2 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x9AE7\n"  /* mov.w @(0x1CE,PC),r10 */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x05E6\n"  /* mov.l r14,@(r0,r5) */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0xBF5A\n"  /* bsr 0x060427FE */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0x6158\n"  /* swap.b r5,r1 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0xE77A\n"  /* mov #122,r7 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0xC3BC\n"  /* trapa #0xBC */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x13E3\n"  /* mov.l r14,@(0xC,r3) */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x2D43\n"  /* .word 0x2D43 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x4556\n"  /* .word 0x4556 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x9E1C\n"  /* mov.w @(0x38,PC),r14 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x7CC7\n"  /* add #-57,r12 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x1673\n"  /* mov.l r7,@(0xC,r6) */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0xBB67\n"  /* bsr 0x06042040 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x9673\n"  /* mov.w @(0xE6,PC),r6 */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x02C2\n"  /* .word 0x02C2 */
    ".word 0x0003\n"  /* .word 0x0003 */
    ".word 0x1E44\n"  /* mov.l r4,@(0x10,r14) */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0x54DB\n"  /* mov.l @(0x2C,r13),r4 */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0xAE0B\n"  /* bra 0x0604259C */
    ".word 0x0004\n"  /* mov.b r0,@(r0,r0) */
    ".word 0xB462\n"  /* bsr 0x0604324E */
    ".word 0x0002\n"  /* stc sr,r0 */
    ".word 0x45EB\n"  /* .word 0x45EB */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0x2501\n"  /* mov.w r0,@r5 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0xE605\n"  /* mov #5,r6 */
    ".word 0x0005\n"  /* mov.w r0,@(r0,r0) */
    ".word 0xABD9\n"  /* bra 0x0604214C */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x8E76\n"  /* .word 0x8E76 */
    ".word 0x0006\n"  /* mov.l r0,@(r0,r0) */
    ".word 0x5052\n"  /* mov.l @(0x8,r5),r0 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x3F5A\n"  /* .word 0x3F5A */
    ".word 0x0007\n"  /* mul.l r0,r0 */
    ".word 0x1D88\n"  /* mov.l r8,@(0x20,r13) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF8CA\n"  /* .word 0xF8CA */
    ".word 0x0008\n"  /* clrt */
    ".word 0x24F3\n"  /* .word 0x24F3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xBADB\n"  /* bsr 0x06041F6C */
    ".word 0x0009\n"  /* nop */
    ".word 0x83AD\n"  /* .word 0x83AD */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x85A2\n"  /* mov.w @(0x4,r10),r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6E17\n"  /* not r1,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x592D\n"  /* mov.l @(0x34,r2),r9 */
    ".word 0x000E\n"  /* mov.l @(r0,r0),r0 */
    ".word 0x4CF8\n"  /* .word 0x4CF8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x358D\n"  /* dmuls.l r8,r5 */
    ".word 0x0013\n"  /* .word 0x0013 */
    ".word 0x14C5\n"  /* mov.l r12,@(0x14,r4) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x1ACA\n"  /* mov.l r12,@(0x28,r10) */
    ".word 0x001C\n"  /* mov.b @(r0,r1),r0 */
    ".word 0xA2E1\n"  /* bra 0x06042F9C */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x08EF\n"  /* mac.l @r14+,@r8+ */
    ".word 0x0039\n"  /* .word 0x0039 */
    ".word 0x4A3A\n"  /* .word 0x4A3A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0105\n"  /* mov.w r0,@(r0,r1) */
    ".word 0x7FFF\n"  /* add #-1,r15 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0000\n"  /* .word 0x0000 */
);

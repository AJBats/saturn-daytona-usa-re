__asm__(
    ".balign 4\n"
    ".global _vdp2_data_transfer_course0\n"
    ".type _vdp2_data_transfer_course0, @function\n"










    ".section .text.FUN_06003466, \"ax\"\n"

    ".global _FUN_06003466\n"
    "_vdp2_data_transfer_course0:\n"
    "_FUN_06003466:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x060034B0] = 0x25F00800} */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x060034B4] = 0x25F00200} */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x060034B8] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0xDE11\n"  /* mov.l @(0x44,PC),r14  {[0x060034BC] = 0x06028654} */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x060034C0] = 0x25E34000} */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x060034C4] = 0x25E4363C} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x060034C8] = 0x060612AC} */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x060034CC] = 0x25E40000} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD510\n"  /* mov.l @(0x40,PC),r5  {[0x060034C8] = 0x060612AC} */
    ".word 0x9208\n"  /* mov.w @(0x10,PC),r2 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x060034D0] = 0x25E407F0} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0900\n"  /* .word 0x0900 */
    ".word 0x0490\n"  /* .word 0x0490 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3255\n"  /* dmulu.l r5,r2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3798\n"  /* sub r9,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3790\n"  /* cmp/eq r9,r7 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x25E3\n"  /* .word 0x25E3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12AC\n"  /* mov.l r10,@(0x30,r2) */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0x07F0\n"  /* .word 0x07F0 */
    ".size _vdp2_data_transfer_course0, .-_vdp2_data_transfer_course0\n"
);
__asm__(



    ".balign 2\n"
    ".global _vdp2_data_transfer_course1\n"
    ".type _vdp2_data_transfer_course1, @function\n"










    ".section .text.FUN_060034D4, \"ax\"\n"

    ".global _FUN_060034D4\n"
    ".global _FUN_060034d4\n"
    "_vdp2_data_transfer_course1:\n"
    "_FUN_060034D4:\n"
    "_FUN_060034d4:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x9630\n"  /* mov.w @(0x60,PC),r6 */
    ".word 0xD51A\n"  /* mov.l @(0x68,PC),r5  {[0x06003544] = 0x25F00860} */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x06003548] = 0x25F00200} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0600354C] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDE1A\n"  /* mov.l @(0x68,PC),r14  {[0x06003550] = 0x06028654} */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x06003554] = 0x25E34000} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x06003558] = 0x25E497E4} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0600355C] = 0x060612AC} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x06003560] = 0x25E4108C} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD519\n"  /* mov.l @(0x64,PC),r5  {[0x0600355C] = 0x060612AC} */
    ".word 0x9221\n"  /* mov.w @(0x42,PC),r2 */
    ".word 0xD41A\n"  /* mov.l @(0x68,PC),r4  {[0x06003564] = 0x25E41A24} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _vdp2_data_transfer_course1, .-_vdp2_data_transfer_course1\n"
);
__asm__(



    ".balign 2\n"
    ".global _vdp2_data_transfer_course2\n"
    ".type _vdp2_data_transfer_course2, @function\n"










    ".section .text.FUN_06003508, \"ax\"\n"

    ".global _FUN_06003508\n"
    "_vdp2_data_transfer_course2:\n"
    "_FUN_06003508:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x9618\n"  /* mov.w @(0x30,PC),r6 */
    ".word 0xD516\n"  /* mov.l @(0x58,PC),r5  {[0x06003568] = 0x25F00940} */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x06003548] = 0x25F00200} */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0600354C] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDE0D\n"  /* mov.l @(0x34,PC),r14  {[0x06003550] = 0x06028654} */
    ".word 0xD50E\n"  /* mov.l @(0x38,PC),r5  {[0x06003554] = 0x25E34000} */
    ".word 0xD413\n"  /* mov.l @(0x4C,PC),r4  {[0x0600356C] = 0x25E4EFEC} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD50E\n"  /* mov.l @(0x38,PC),r5  {[0x0600355C] = 0x060612AC} */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x06003570] = 0x25E42300} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x0600355C] = 0x060612AC} */
    ".word 0x9207\n"  /* mov.w @(0xE,PC),r2 */
    ".word 0xD411\n"  /* mov.l @(0x44,PC),r4  {[0x06003574] = 0x25E42C78} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00E0\n"  /* .word 0x00E0 */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x0100\n"  /* .word 0x0100 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0860\n"  /* .word 0x0860 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x25E3\n"  /* .word 0x25E3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0x97E4\n"  /* mov.w @(0x1C8,PC),r7 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x12AC\n"  /* mov.l r10,@(0x30,r2) */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0x108C\n"  /* mov.l r8,@(0x30,r0) */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0x1A24\n"  /* mov.l r2,@(0x10,r10) */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0940\n"  /* .word 0x0940 */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0xEFEC\n"  /* mov #-20,r15 */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0x2300\n"  /* mov.b r0,@r3 */
    ".word 0x25E4\n"  /* mov.b r14,@-r5 */
    ".word 0x2C78\n"  /* tst r7,r12 */
    ".size _vdp2_data_transfer_course2, .-_vdp2_data_transfer_course2\n"
);
__asm__(



    ".balign 2\n"
    ".global _obj_position_update\n"
    ".type _obj_position_update, @function\n"










    ".section .text.FUN_06004F28, \"ax\"\n"

    ".global _FUN_06004F28\n"
    ".global _FUN_06004f28\n"
    "_obj_position_update:\n"
    "_FUN_06004F28:\n"
    "_FUN_06004f28:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0xDA2B\n"  /* mov.l @(0xAC,PC),r10  {[0x06004FDC] = 0x06063750} */
    ".word 0xDB2B\n"  /* mov.l @(0xAC,PC),r11  {[0x06004FE0] = 0x06059F1C} */
    ".word 0xDC2C\n"  /* mov.l @(0xB0,PC),r12  {[0x06004FE4] = 0x06059F18} */
    ".word 0xDE2C\n"  /* mov.l @(0xB0,PC),r14  {[0x06004FE8] = 0x06059F10} */
    ".word 0x1F41\n"  /* mov.l r4,@(0x4,r15) */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8D1F\n"  /* bt/s 0x06004F7E */
    ".word 0x6D63\n"  /* mov r6,r13 */
    ".word 0x54F1\n"  /* mov.l @(0x4,r15),r4 */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x232E\n"  /* mulu.w r2,r3 */
    ".word 0x031A\n"  /* sts macl,r3 */
    ".word 0x7302\n"  /* add #2,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x663D\n"  /* extu.w r3,r6 */
    ".word 0x81F4\n"  /* mov.w r0,@(0x8,r15) */
    ".word 0xD824\n"  /* mov.l @(0x90,PC),r8  {[0x06004FEC] = 0x06063D90} */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0xD224\n"  /* mov.l @(0x90,PC),r2  {[0x06004FF0] = 0x0602761E} */
    ".word 0x6882\n"  /* mov.l @r8,r8 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x6483\n"  /* mov r8,r4 */
    ".word 0x85F4\n"  /* mov.w @(0x8,r15),r0 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06004FEC] = 0x06063D90} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x06004FEC] = 0x06063D90} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD51F\n"  /* mov.l @(0x7C,PC),r5  {[0x06004FF4] = 0x06063D94} */
    ".word 0x6152\n"  /* mov.l @r5,r1 */
    ".word 0x314C\n"  /* add r4,r1 */
    ".word 0xA001\n"  /* bra 0x06004F80 */
    ".word 0x2512\n"  /* mov.l r1,@r5 */
    ".word 0x58F1\n"  /* mov.l @(0x4,r15),r8 */
    ".word 0x2DD8\n"  /* tst r13,r13 */
    ".word 0x8964\n"  /* bt 0x0600504E */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0x2399\n"  /* and r9,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8F39\n"  /* bf/s 0x06005000 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x2949\n"  /* and r4,r9 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x33AC\n"  /* add r10,r3 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x8D0B\n"  /* bt/s 0x06004FB6 */
    ".word 0x1321\n"  /* mov.l r2,@(0x4,r3) */
    ".word 0x65C2\n"  /* mov.l @r12,r5 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06004FF8] = 0x25E00000} */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06004FFC] = 0x06028654} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xA00D\n"  /* bra 0x06004FD0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x66F2\n"  /* mov.l @r15,r6 */
    ".word 0x64C2\n"  /* mov.l @r12,r4 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06004FF8] = 0x25E00000} */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06004FF0] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0xA044\n"  /* bra 0x06005064 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F1C\n"  /* mov.w @(0x38,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F18\n"  /* mov.w @(0x30,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F10\n"  /* mov.w @(0x20,PC),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D90\n"  /* cmp/eq r9,r13 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D94\n"  /* .word 0x3D94 */
    ".word 0x25E0\n"  /* mov.b r14,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x2949\n"  /* and r4,r9 */
    ".word 0x63B2\n"  /* mov.l @r11,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x32AC\n"  /* add r10,r2 */
    ".word 0x2998\n"  /* tst r9,r9 */
    ".word 0x8D0B\n"  /* bt/s 0x06005028 */
    ".word 0x1231\n"  /* mov.l r3,@(0x4,r2) */
    ".word 0x65B2\n"  /* mov.l @r11,r5 */
    ".word 0xD330\n"  /* mov.l @(0xC0,PC),r3  {[0x060050D8] = 0x25E20000} */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4508\n"  /* shll2 r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0xD32F\n"  /* mov.l @(0xBC,PC),r3  {[0x060050DC] = 0x06028654} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xA00D\n"  /* bra 0x06005042 */
    ".word 0x0009\n"  /* nop */
    ".word 0x66F2\n"  /* mov.l @r15,r6 */
    ".word 0x64B2\n"  /* mov.l @r11,r4 */
    ".word 0xD32A\n"  /* mov.l @(0xA8,PC),r3  {[0x060050D8] = 0x25E20000} */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x060050E0] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x63B2\n"  /* mov.l @r11,r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0xA00B\n"  /* bra 0x06005064 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x32AC\n"  /* add r10,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x33AC\n"  /* add r10,r3 */
    ".word 0x5131\n"  /* mov.l @(0x4,r3),r1 */
    ".word 0x1211\n"  /* mov.l r1,@(0x4,r2) */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x33AC\n"  /* add r10,r3 */
    ".word 0x2382\n"  /* mov.l r8,@r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0x7F0C\n"  /* add #12,r15 */
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
    ".word 0xE304\n"  /* mov #4,r3 */
    ".size _obj_position_update, .-_obj_position_update\n"
);
__asm__(



    ".balign 2\n"
    ".global _obj_coord_setter\n"
    ".type _obj_coord_setter, @function\n"










    ".section .text.FUN_0600508C, \"ax\"\n"

    ".global _FUN_0600508C\n"
    ".global _FUN_0600508c\n"
    "_obj_coord_setter:\n"
    "_FUN_0600508C:\n"
    "_FUN_0600508c:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2639\n"  /* and r3,r6 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0x2668\n"  /* tst r6,r6 */
    ".word 0x8D24\n"  /* bt/s 0x060050EC */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0xDB0E\n"  /* mov.l @(0x38,PC),r11  {[0x060050E4] = 0x06063D90} */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6341\n"  /* mov.w @r4,r3 */
    ".word 0x6EB2\n"  /* mov.l @r11,r14 */
    ".word 0x6C03\n"  /* mov r0,r12 */
    ".word 0x2C3E\n"  /* mulu.w r3,r12 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x060050E0] = 0x0602761E} */
    ".word 0x0C1A\n"  /* sts macl,r12 */
    ".word 0x7C02\n"  /* add #2,r12 */
    ".word 0x4C00\n"  /* shll r12 */
    ".word 0x6CCD\n"  /* extu.w r12,r12 */
    ".word 0x66CD\n"  /* extu.w r12,r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x65CD\n"  /* extu.w r12,r5 */
    ".word 0x62B2\n"  /* mov.l @r11,r2 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x2B22\n"  /* mov.l r2,@r11 */
    ".word 0xD406\n"  /* mov.l @(0x18,PC),r4  {[0x060050E8] = 0x06063D94} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x335C\n"  /* add r5,r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xA00B\n"  /* bra 0x060050EE */
    ".word 0x0009\n"  /* nop */
    ".word 0x25E2\n"  /* mov.l r14,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D90\n"  /* cmp/eq r9,r13 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D94\n"  /* .word 0x3D94 */
    ".word 0x6ED3\n"  /* mov r13,r14 */
    ".word 0xD51B\n"  /* mov.l @(0x6C,PC),r5  {[0x0600515C] = 0x06063750} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x06005160] = 0x06059F10} */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x325C\n"  /* add r5,r2 */
    ".word 0x1231\n"  /* mov.l r3,@(0x4,r2) */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x335C\n"  /* add r5,r3 */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".size _obj_coord_setter, .-_obj_coord_setter\n"
);
__asm__(



    ".balign 2\n"
    ".global _hw_render_dispatcher\n"
    ".type _hw_render_dispatcher, @function\n"










    ".section .text.FUN_06005120, \"ax\"\n"

    ".global _FUN_06005120\n"
    "_hw_render_dispatcher:\n"
    "_FUN_06005120:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2379\n"  /* and r7,r3 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x2F42\n"  /* mov.l r4,@r15 */
    ".word 0x1F61\n"  /* mov.l r6,@(0x4,r15) */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8B02\n"  /* bf 0x06005134 */
    ".word 0xDE0D\n"  /* mov.l @(0x34,PC),r14  {[0x06005164] = 0x25E00000} */
    ".word 0xA001\n"  /* bra 0x06005136 */
    ".word 0x0009\n"  /* nop */
    ".word 0xDE0C\n"  /* mov.l @(0x30,PC),r14  {[0x06005168] = 0x25E20000} */
    ".word 0xE208\n"  /* mov #8,r2 */
    ".word 0x2729\n"  /* and r2,r7 */
    ".word 0x2778\n"  /* tst r7,r7 */
    ".word 0x8D06\n"  /* bt/s 0x0600514C */
    ".word 0x3E5C\n"  /* add r5,r14 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x0600516C] = 0x06028654} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x56F1\n"  /* mov.l @(0x4,r15),r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0xD306\n"  /* mov.l @(0x18,PC),r3  {[0x06005170] = 0x06027630} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F10\n"  /* mov.w @(0x20,PC),r15 */
    ".word 0x25E0\n"  /* mov.b r14,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x25E2\n"  /* mov.l r14,@r5 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7630\n"  /* add #48,r6 */
    ".word 0xD52A\n"  /* mov.l @(0xA8,PC),r5  {[0x06005220] = 0x06063D98} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x2541\n"  /* mov.w r4,@r5 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8152\n"  /* mov.w r0,@(0x4,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8153\n"  /* mov.w r0,@(0x6,r5) */
    ".word 0x7508\n"  /* add #8,r5 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x2541\n"  /* mov.w r4,@r5 */
    ".word 0x8151\n"  /* mov.w r0,@(0x2,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x8152\n"  /* mov.w r0,@(0x4,r5) */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8153\n"  /* mov.w r0,@(0x6,r5) */
    ".size _hw_render_dispatcher, .-_hw_render_dispatcher\n"
);
__asm__(



    ".balign 2\n"
    ".global _obj_state_writer\n"
    ".type _obj_state_writer, @function\n"










    ".section .text.FUN_06005494, \"ax\"\n"

    ".global _FUN_06005494\n"
    "_obj_state_writer:\n"
    "_FUN_06005494:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06005504] = 0x06078663} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D05\n"  /* bt/s 0x060054B0 */
    ".word 0x6D53\n"  /* mov r5,r13 */
    ".word 0xD618\n"  /* mov.l @(0x60,PC),r6  {[0x06005508] = 0x00010000} */
    ".word 0xD418\n"  /* mov.l @(0x60,PC),r4  {[0x0600550C] = 0xFFFF0000} */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06005510] = 0x06026E60} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x54D2\n"  /* mov.l @(0x8,r13),r4 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06005514] = 0x06026F2A} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x64D2\n"  /* mov.l @r13,r4 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06005518] = 0x06026E94} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x54D1\n"  /* mov.l @(0x4,r13),r4 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x0600551C] = 0x06026EDE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0x56E2\n"  /* mov.l @(0x8,r14),r6 */
    ".word 0x55E1\n"  /* mov.l @(0x4,r14),r5 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06005520] = 0x06026E2E} */
    ".word 0x666B\n"  /* neg r6,r6 */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x644B\n"  /* neg r4,r4 */
    ".word 0xD112\n"  /* mov.l @(0x48,PC),r1  {[0x06005524] = 0x06063DF8} */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06005528] = 0x06035168} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE00C\n"  /* mov #12,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0600552C] = 0x06063E04} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06005530] = 0x06063E08} */
    ".word 0x2341\n"  /* mov.w r4,@r3 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06005534] = 0x06063F08} */
    ".word 0x2342\n"  /* mov.l r4,@r3 */
    ".word 0x6133\n"  /* mov r3,r1 */
    ".word 0x6112\n"  /* mov.l @r1,r1 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06005538] = 0x06063F04} */
    ".word 0x000B\n"  /* rts */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8663\n"  /* .word 0x8663 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E60\n"  /* mov.b @r6,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026F2A */
    ".word 0x6F2A\n"  /* .word 0x6F2A */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026E94 */
    ".word 0x6E94\n"  /* mov.b @r9+,r14 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026EDE */
    ".word 0x6EDE\n"  /* exts.b r13,r14 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6E2E\n"  /* exts.b r2,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3DF8\n"  /* sub r15,r13 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5168\n"  /* mov.l @(0x20,r6),r1 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E04\n"  /* .word 0x3E04 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E08\n"  /* sub r0,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F08\n"  /* sub r0,r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F04\n"  /* .word 0x3F04 */
    ".size _obj_state_writer, .-_obj_state_writer\n"
);
__asm__(



    ".balign 2\n"
    ".global _vdp_mode_setup_disp\n"
    ".type _vdp_mode_setup_disp, @function\n"










    ".section .text.FUN_0600579C, \"ax\"\n"

    ".global _FUN_0600579C\n"
    ".global _FUN_0600579c\n"
    "_vdp_mode_setup_disp:\n"
    "_FUN_0600579C:\n"
    "_FUN_0600579c:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x66E3\n"  /* mov r14,r6 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD82D\n"  /* mov.l @(0xB4,PC),r8  {[0x06005858] = 0x06085FF4} */
    ".word 0xD92D\n"  /* mov.l @(0xB4,PC),r9  {[0x0600585C] = 0x06063750} */
    ".word 0x9A52\n"  /* mov.w @(0xA4,PC),r10 */
    ".word 0xDD2D\n"  /* mov.l @(0xB4,PC),r13  {[0x06005860] = 0x0606129C} */
    ".word 0x6793\n"  /* mov r9,r7 */
    ".word 0x7720\n"  /* add #32,r7 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x06005864] = 0x06028400} */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x6080\n"  /* mov.b @r8,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891F\n"  /* bt 0x06005802 */
    ".word 0x6CE3\n"  /* mov r14,r12 */
    ".word 0x9744\n"  /* mov.w @(0x88,PC),r7 */
    ".word 0x65D2\n"  /* mov.l @r13,r5 */
    ".word 0x357C\n"  /* add r7,r5 */
    ".word 0x7518\n"  /* add #24,r5 */
    ".word 0x66D2\n"  /* mov.l @r13,r6 */
    ".word 0x36CC\n"  /* add r12,r6 */
    ".word 0x7618\n"  /* add #24,r6 */
    ".word 0x64B3\n"  /* mov r11,r4 */
    ".word 0x6155\n"  /* mov.w @r5+,r1 */
    ".word 0x74FD\n"  /* add #-3,r4 */
    ".word 0x2611\n"  /* mov.w r1,@r6 */
    ".word 0x7602\n"  /* add #2,r6 */
    ".word 0x6155\n"  /* mov.w @r5+,r1 */
    ".word 0x2611\n"  /* mov.w r1,@r6 */
    ".word 0x7602\n"  /* add #2,r6 */
    ".word 0x6155\n"  /* mov.w @r5+,r1 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x7602\n"  /* add #2,r6 */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8FF3\n"  /* bf/s 0x060057D4 */
    ".word 0x2311\n"  /* mov.w r1,@r3 */
    ".word 0x37EC\n"  /* add r14,r7 */
    ".word 0x37A3\n"  /* cmp/ge r10,r7 */
    ".word 0x8FE8\n"  /* bf/s 0x060057C6 */
    ".word 0x3CEC\n"  /* add r14,r12 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0x952B\n"  /* mov.w @(0x56,PC),r5 */
    ".word 0xD71B\n"  /* mov.l @(0x6C,PC),r7  {[0x06005868] = 0x0605ACDF} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0600586C] = 0x060284AE} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x6080\n"  /* mov.b @r8,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x0600580C */
    ".word 0xA001\n"  /* bra 0x0600580E */
    ".word 0xEC05\n"  /* mov #5,r12 */
    ".word 0xEC07\n"  /* mov #7,r12 */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x06005870] = 0x0607EAB8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8B0E\n"  /* bf 0x06005834 */
    ".word 0x6793\n"  /* mov r9,r7 */
    ".word 0x66C3\n"  /* mov r12,r6 */
    ".word 0x7728\n"  /* add #40,r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06005864] = 0x06028400} */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x7619\n"  /* add #25,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xDC0F\n"  /* mov.l @(0x3C,PC),r12  {[0x06005874] = 0x06063F28} */
    ".word 0xE30A\n"  /* mov #10,r3 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x3232\n"  /* cmp/hs r3,r2 */
    ".word 0x891E\n"  /* bt 0x0600587C */
    ".word 0x67C2\n"  /* mov.l @r12,r7 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x9507\n"  /* mov.w @(0xE,PC),r5 */
    ".word 0xD30C\n"  /* mov.l @(0x30,PC),r3  {[0x06005878] = 0x06028430} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xA01D\n"  /* bra 0x06005888 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0480\n"  /* .word 0x0480 */
    ".word 0x0180\n"  /* .word 0x0180 */
    ".word 0x0318\n"  /* .word 0x0318 */
    ".word 0x0110\n"  /* .word 0x0110 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3750\n"  /* cmp/eq r5,r7 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x129C\n"  /* mov.l r9,@(0x30,r2) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xACDF\n"  /* bra 0x0600522C */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAB8\n"  /* mov #-72,r10 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F28\n"  /* sub r2,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8430\n"  /* mov.b @(0x0,r3),r0 */
    ".word 0x67C2\n"  /* mov.l @r12,r7 */
    ".word 0xE60C\n"  /* mov #12,r6 */
    ".word 0x9544\n"  /* mov.w @(0x88,PC),r5 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x06005914] = 0x06028430} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD023\n"  /* mov.l @(0x8C,PC),r0  {[0x06005918] = 0x0607EAE0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B06\n"  /* bf 0x0600589E */
    ".word 0xE630\n"  /* mov #48,r6 */
    ".word 0x953C\n"  /* mov.w @(0x78,PC),r5 */
    ".word 0xD721\n"  /* mov.l @(0x84,PC),r7  {[0x0600591C] = 0x0607EA98} */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06005914] = 0x06028430} */
    ".word 0x6772\n"  /* mov.l @r7,r7 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD020\n"  /* mov.l @(0x80,PC),r0  {[0x06005920] = 0x06078644} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B1F\n"  /* bf 0x060058E6 */
    ".word 0x6080\n"  /* mov.b @r8,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x060058B0 */
    ".word 0xA001\n"  /* bra 0x060058B2 */
    ".word 0xEC04\n"  /* mov #4,r12 */
    ".word 0xEC06\n"  /* mov #6,r12 */
    ".word 0x6793\n"  /* mov r9,r7 */
    ".word 0x66C3\n"  /* mov r12,r6 */
    ".word 0x7730\n"  /* add #48,r7 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x9326\n"  /* mov.w @(0x4C,PC),r3 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x7616\n"  /* add #22,r6 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06005924] = 0x06028400} */
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
    ".size _vdp_mode_setup_disp, .-_vdp_mode_setup_disp\n"
);

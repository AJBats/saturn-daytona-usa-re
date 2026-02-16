/* FUN_060088CC: moved to state_init_handlers.c */
/* FUN_06008938: moved to state_init_handlers.c */
/* FUN_0600893C: moved to state_init_handlers.c */
/* FUN_06008A18: moved to state_init_handlers.c */
/* FUN_06008B04: moved to state_init_handlers.c */
/* FUN_06008B34: moved to state_init_handlers.c */
/* FUN_06008B78: moved to state_init_handlers.c */
/* FUN_06008B9C: moved to state_init_handlers.c */
/* FUN_06008BD8: moved to state_init_handlers.c */
/* FUN_06008BFC: moved to state_init_handlers.c */
/* FUN_06008C14: moved to state_init_handlers.c */
/* FUN_06008C76: moved to state_init_handlers.c */
/* FUN_06008CCC: moved to state_init_handlers.c */
/* FUN_06008CD0: moved to state_init_handlers.c */
/* FUN_06008D74: moved to state_init_handlers.c */
/* FUN_06008E00: moved to state_init_handlers.c */
/* FUN_06008E48: moved to state_init_handlers.c */
/* state_14-17: translated in race_state_handlers.c */
__asm__(



    ".balign 2\n"
    ".global _state_28_abort_processing\n"
    ".type _state_28_abort_processing, @function\n"









    ".section .text.FUN_06009508, \"ax\"\n"

    ".global _FUN_06009508\n"
    "_state_28_abort_processing:\n"
    "_FUN_06009508:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD423\n"  /* mov.l @(0x8C,PC),r4  {[0x06009598] = 0x0607EBF4} */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8908\n"  /* bt 0x06009524 */
    ".word 0xE3FE\n"  /* mov #-2,r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0xE314\n"  /* mov #20,r3 */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x0600959C] = 0x0605AD10} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xA008\n"  /* bra 0x06009534 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD01E\n"  /* mov.l @(0x78,PC),r0  {[0x060095A0] = 0x0607EAD0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B03\n"  /* bf 0x06009534 */
    ".word 0xD41D\n"  /* mov.l @(0x74,PC),r4  {[0x060095A4] = 0x0607EBD0} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xE21D\n"  /* mov #29,r2 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0600959C] = 0x0605AD10} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x060095A8] = 0x0600DFD0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x060095AC] = 0x0600BB94} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD61A\n"  /* mov.l @(0x68,PC),r6  {[0x060095B0] = 0x06063E24} */
    ".word 0xD51A\n"  /* mov.l @(0x68,PC),r5  {[0x060095B4] = 0x06063EEC} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x060095B8] = 0x06063EF8} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x060095BC] = 0x060053AC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x060095C0] = 0x0600C218} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x060095C4] = 0x060078DC} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".size _state_28_abort_processing, .-_state_28_abort_processing\n"
);
__asm__(
    ".balign 4\n"
    ".global _state_29_post_race_menu\n"
    ".type _state_29_post_race_menu, @function\n"









    ".section .text.FUN_0600955E, \"ax\"\n"

    ".global _FUN_0600955E\n"
    "_state_29_post_race_menu:\n"
    "_FUN_0600955E:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xDE0D\n"  /* mov.l @(0x34,PC),r14  {[0x0600959C] = 0x0605AD10} */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x060095C8] = 0x06063D9A} */
    ".word 0x6231\n"  /* mov.w @r3,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x9313\n"  /* mov.w @(0x26,PC),r3 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8904\n"  /* bt 0x0600957E */
    ".word 0xE31D\n"  /* mov #29,r3 */
    ".word 0xD215\n"  /* mov.l @(0x54,PC),r2  {[0x060095CC] = 0x0607EACC} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xE312\n"  /* mov #18,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0xD406\n"  /* mov.l @(0x18,PC),r4  {[0x06009598] = 0x0607EBF4} */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8924\n"  /* bt 0x060095D0 */
    ".word 0xE3FE\n"  /* mov #-2,r3 */
    ".word 0x6242\n"  /* mov.l @r4,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2422\n"  /* mov.l r2,@r4 */
    ".word 0xE314\n"  /* mov #20,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0xA025\n"  /* bra 0x060095E0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x06008FC2 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD0\n"  /* mov #-48,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBD0\n"  /* mov #-48,r11 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600DFD0 */
    ".word 0xDFD0\n"  /* mov.l @(0x340,PC),r15  {[0x060098EC] = 0x060283E0} */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600BB94 */
    ".word 0xBB94\n"  /* bsr 0x06008CDA */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E24\n"  /* .word 0x3E24 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EF8\n"  /* sub r15,r14 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060053AC */
    ".word 0x53AC\n"  /* mov.l @(0x30,r10),r3 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600C218 */
    ".word 0xC218\n"  /* mov.l r0,@(0x60,GBR) */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060078DC */
    ".word 0x78DC\n"  /* add #-36,r8 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D9A\n"  /* .word 0x3D9A */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEACC\n"  /* mov #-52,r10 */
    ".word 0xD02C\n"  /* mov.l @(0xB0,PC),r0  {[0x06009684] = 0x0607EAD0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B03\n"  /* bf 0x060095E0 */
    ".word 0xD42B\n"  /* mov.l @(0xAC,PC),r4  {[0x06009688] = 0x0607EBD0} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD02A\n"  /* mov.l @(0xA8,PC),r0  {[0x0600968C] = 0x0605AB18} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8902\n"  /* bt 0x060095EE */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x06009690] = 0x060268B0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x06009694] = 0x0600E060} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x06009698] = 0x0600BB94} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD628\n"  /* mov.l @(0xA0,PC),r6  {[0x0600969C] = 0x06063E24} */
    ".word 0xD528\n"  /* mov.l @(0xA0,PC),r5  {[0x060096A0] = 0x06063EEC} */
    ".word 0xD429\n"  /* mov.l @(0xA4,PC),r4  {[0x060096A4] = 0x06063EF8} */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x060096A8] = 0x060053AC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x060096AC] = 0x0600C218} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD028\n"  /* mov.l @(0xA0,PC),r0  {[0x060096B0] = 0x0607ED8C} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8902\n"  /* bt 0x0600961C */
    ".word 0xD327\n"  /* mov.l @(0x9C,PC),r3  {[0x060096B4] = 0x060033E6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x060096B8] = 0x06086030} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8905\n"  /* bt 0x06009632 */
    ".word 0xD725\n"  /* mov.l @(0x94,PC),r7  {[0x060096BC] = 0x0605A1C8} */
    ".word 0xD625\n"  /* mov.l @(0x94,PC),r6  {[0x060096C0] = 0x0000F000} */
    ".word 0x9527\n"  /* mov.w @(0x4E,PC),r5 */
    ".word 0xD325\n"  /* mov.l @(0x94,PC),r3  {[0x060096C4] = 0x060283E0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD225\n"  /* mov.l @(0x94,PC),r2  {[0x060096C8] = 0x0607E944} */
    ".word 0x9023\n"  /* mov.w @(0x46,PC),r0 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B01\n"  /* bf 0x06009642 */
    ".word 0xB521\n"  /* bsr 0x0600A084 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x060096CC] = 0x060078DC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD01F\n"  /* mov.l @(0x7C,PC),r0  {[0x060096C8] = 0x0607E944} */
    ".word 0x9119\n"  /* mov.w @(0x32,PC),r1 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x001E\n"  /* mov.l @(r0,r1),r0 */
    ".word 0xC8CC\n"  /* tst #0xCC,r0 */
    ".word 0x8B09\n"  /* bf 0x06009668 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x060096D0] = 0x06063798} */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6733\n"  /* mov r3,r7 */
    ".word 0x6533\n"  /* mov r3,r5 */
    ".word 0x9611\n"  /* mov.w @(0x22,PC),r6 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x060096D4] = 0x06028400} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x060096D8] = 0x0605A1C4} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x06009674 */
    ".word 0xE311\n"  /* mov #17,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0082\n"  /* .word 0x0082 */
    ".word 0x00BC\n"  /* mov.b @(r0,r11),r0 */
    ".word 0x0214\n"  /* mov.b r1,@(r0,r2) */
    ".word 0x0900\n"  /* .word 0x0900 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD0\n"  /* mov #-48,r10 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBD0\n"  /* mov #-48,r11 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAB18\n"  /* bra 0x06008CC2 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_060268B0 */
    ".word 0x68B0\n"  /* mov.b @r11,r8 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600E060 */
    ".word 0xE060\n"  /* mov #96,r0 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600BB94 */
    ".word 0xBB94\n"  /* bsr 0x06008DC6 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E24\n"  /* .word 0x3E24 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EF8\n"  /* sub r15,r14 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060053AC */
    ".word 0x53AC\n"  /* mov.l @(0x30,r10),r3 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600C218 */
    ".word 0xC218\n"  /* mov.l r0,@(0x60,GBR) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED8C\n"  /* mov #-116,r13 */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x33E6\n"  /* cmp/hi r14,r3 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6030\n"  /* mov.b @r3,r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1C8\n"  /* bra 0x06009A52 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x83E0\n"  /* .word 0x83E0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060078DC */
    ".word 0x78DC\n"  /* add #-36,r8 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3798\n"  /* sub r9,r7 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1C4\n"  /* bra 0x06009A66 */
    ".size _state_29_post_race_menu, .-_state_29_post_race_menu\n"
);
__asm__(



    ".balign 2\n"
    ".global _state_18_time_extension_setup\n"
    ".type _state_18_time_extension_setup, @function\n"









    ".section .text.FUN_060096DC, \"ax\"\n"

    ".global _FUN_060096DC\n"
    "_state_18_time_extension_setup:\n"
    "_FUN_060096DC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xB48B\n"  /* bsr 0x06009FFC */
    ".word 0x0009\n"  /* nop */
    ".word 0xE213\n"  /* mov #19,r2 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06009750] = 0x0605AD10} */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD419\n"  /* mov.l @(0x64,PC),r4  {[0x06009754] = 0x06078654} */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06009758] = 0x06078652} */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x62EC\n"  /* extu.b r14,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0600975C] = 0x06078650} */
    ".word 0x22E1\n"  /* mov.w r14,@r2 */
    ".word 0xD718\n"  /* mov.l @(0x60,PC),r7  {[0x06009760] = 0x060446CC} */
    ".word 0x9622\n"  /* mov.w @(0x44,PC),r6 */
    ".word 0x9522\n"  /* mov.w @(0x44,PC),r5 */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x06009764] = 0x060284AE} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x06009768] = 0x0605AC9C} */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6733\n"  /* mov r3,r7 */
    ".word 0xD616\n"  /* mov.l @(0x58,PC),r6  {[0x0600976C] = 0x0000F000} */
    ".word 0x951B\n"  /* mov.w @(0x36,PC),r5 */
    ".word 0x772E\n"  /* add #46,r7 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06009770] = 0x060283E0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x67F2\n"  /* mov.l @r15,r7 */
    ".word 0xD613\n"  /* mov.l @(0x4C,PC),r6  {[0x0600976C] = 0x0000F000} */
    ".word 0x9515\n"  /* mov.w @(0x2A,PC),r5 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06009770] = 0x060283E0} */
    ".word 0x772F\n"  /* add #47,r7 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x06009774] = 0x0605B6D8} */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06009778] = 0x06026CE0} */
    ".word 0x6042\n"  /* mov.l @r4,r0 */
    ".word 0xCB04\n"  /* or #0x04,r0 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2402\n"  /* mov.l r0,@r4 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x0600977C] = 0x06059F44} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x06009780] = 0xAE0004FF} */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06009784] = 0x0601D5F4} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x051C\n"  /* mov.b @(r0,r1),r5 */
    ".word 0x061C\n"  /* mov.b @(r0,r1),r6 */
    ".word 0x049C\n"  /* mov.b @(r0,r9),r4 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x06009176 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8652\n"  /* .word 0x8652 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8650\n"  /* .word 0x8650 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x46CC\n"  /* .word 0x46CC */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAC9C\n"  /* bra 0x060090A6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x83E0\n"  /* .word 0x83E0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0600A52A */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0xAE00\n"  /* bra 0x06009384 */
    ".word 0x04FF\n"  /* mac.l @r15+,@r4+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06009B58] = 0x6040CB02} */
    ".size _state_18_time_extension_setup, .-_state_18_time_extension_setup\n"
);
__asm__(



    ".balign 2\n"
    ".global _state_19_time_extension\n"
    ".type _state_19_time_extension, @function\n"









    ".section .text.FUN_06009788, \"ax\"\n"

    ".global _FUN_06009788\n"
    "_state_19_time_extension:\n"
    "_FUN_06009788:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD812\n"  /* mov.l @(0x48,PC),r8  {[0x060097E4] = 0x0000F000} */
    ".word 0xDA12\n"  /* mov.l @(0x48,PC),r10  {[0x060097E8] = 0x0605B6D8} */
    ".word 0xDB13\n"  /* mov.l @(0x4C,PC),r11  {[0x060097EC] = 0x0607ED8C} */
    ".word 0xDC13\n"  /* mov.l @(0x4C,PC),r12  {[0x060097F0] = 0x06078649} */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x060097F4] = 0x06063D98} */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x2F31\n"  /* mov.w r3,@r15 */
    ".word 0x6341\n"  /* mov.w @r4,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x81F2\n"  /* mov.w r0,@(0x4,r15) */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x060097F8] = 0x0605AB18} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8902\n"  /* bt 0x060097BE */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x060097FC] = 0x060268B0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xD010\n"  /* mov.l @(0x40,PC),r0  {[0x06009800] = 0x0607864A} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x893B\n"  /* bt 0x0600983E */
    ".word 0x63F1\n"  /* mov.w @r15,r3 */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x06009804] = 0x00008000} */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x891A\n"  /* bt 0x06009808 */
    ".word 0xE263\n"  /* mov #99,r2 */
    ".word 0x63C0\n"  /* mov.b @r12,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8923\n"  /* bt 0x06009824 */
    ".word 0x62C0\n"  /* mov.b @r12,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0xA020\n"  /* bra 0x06009824 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xF000\n"  /* .word 0xF000 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0600A59E */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xED8C\n"  /* mov #-116,r13 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8649\n"  /* .word 0x8649 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAB18\n"  /* bra 0x06008E2E */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_060268B0 */
    ".word 0x68B0\n"  /* mov.b @r11,r8 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x864A\n"  /* .word 0x864A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x62F1\n"  /* mov.w @r15,r2 */
    ".word 0x9363\n"  /* mov.w @(0xC6,PC),r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8907\n"  /* bt 0x06009824 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x63C0\n"  /* mov.b @r12,r3 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B02\n"  /* bf 0x06009824 */
    ".word 0x62C0\n"  /* mov.b @r12,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0x67C0\n"  /* mov.b @r12,r7 */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x9555\n"  /* mov.w @(0xAA,PC),r5 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x060098E4] = 0x0602834A} */
    ".word 0x677C\n"  /* extu.b r7,r7 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x9550\n"  /* mov.w @(0xA0,PC),r5 */
    ".word 0xD72C\n"  /* mov.l @(0xB0,PC),r7  {[0x060098E8] = 0x060446E0} */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x060098EC] = 0x060283E0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x994C\n"  /* mov.w @(0x98,PC),r9 */
    ".word 0x9D4C\n"  /* mov.w @(0x98,PC),r13 */
    ".word 0xDE2B\n"  /* mov.l @(0xAC,PC),r14  {[0x060098F0] = 0x060284AE} */
    ".word 0x62F1\n"  /* mov.w @r15,r2 */
    ".word 0x934A\n"  /* mov.w @(0x94,PC),r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8967\n"  /* bt 0x06009920 */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x060098F4] = 0x06078650} */
    ".word 0x6331\n"  /* mov.w @r3,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B61\n"  /* bf 0x06009920 */
    ".word 0xD026\n"  /* mov.l @(0x98,PC),r0  {[0x060098F8] = 0x0607864A} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x895D\n"  /* bt 0x06009920 */
    ".word 0xD525\n"  /* mov.l @(0x94,PC),r5  {[0x060098FC] = 0xAE0004FF} */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x06009900] = 0x0601D5F4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0xD225\n"  /* mov.l @(0x94,PC),r2  {[0x06009904] = 0x0605AC9C} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x9534\n"  /* mov.w @(0x68,PC),r5 */
    ".word 0x773B\n"  /* add #59,r7 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x67F2\n"  /* mov.l @r15,r7 */
    ".word 0x7728\n"  /* add #40,r7 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x952A\n"  /* mov.w @(0x54,PC),r5 */
    ".word 0x67F2\n"  /* mov.l @r15,r7 */
    ".word 0x772E\n"  /* add #46,r7 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x06009908] = 0x0607EACC} */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0600990C] = 0x0605AD10} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x06009910] = 0x06078652} */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x06009914] = 0x06078654} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x060098F8] = 0x0607864A} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x060098B0 */
    ".word 0xA0A2\n"  /* bra 0x060099F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xE60F\n"  /* mov #15,r6 */
    ".word 0xD210\n"  /* mov.l @(0x40,PC),r2  {[0x060098F8] = 0x0607864A} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x65C0\n"  /* mov.b @r12,r5 */
    ".word 0x655C\n"  /* extu.b r5,r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06009918] = 0x06018DDC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0xD715\n"  /* mov.l @(0x54,PC),r7  {[0x0600991C] = 0x060446EC} */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x9506\n"  /* mov.w @(0xC,PC),r5 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x060098EC] = 0x060283E0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xA090\n"  /* bra 0x060099F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0CCC\n"  /* mov.b @(r0,r12),r12 */
    ".word 0x0CB8\n"  /* .word 0x0CB8 */
    ".word 0x0694\n"  /* mov.b r9,@(r0,r6) */
    ".word 0x0090\n"  /* .word 0x0090 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0x0526\n"  /* mov.l r2,@(r0,r5) */
    ".word 0x079C\n"  /* mov.b @(r0,r9),r7 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602834A */
    ".word 0x834A\n"  /* .word 0x834A */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x46E0\n"  /* .word 0x46E0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x83E0\n"  /* .word 0x83E0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x84AE\n"  /* mov.b @(0xE,r10),r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8650\n"  /* .word 0x8650 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x864A\n"  /* .word 0x864A */
    ".word 0xAE00\n"  /* bra 0x06009500 */
    ".word 0x04FF\n"  /* mac.l @r15+,@r4+ */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_0601D5F4 */
    ".word 0xD5F4\n"  /* mov.l @(0x3D0,PC),r5  {[0x06009CD4] = 0x0600BB94} */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAC9C\n"  /* bra 0x06009242 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEACC\n"  /* mov #-52,r10 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x06009332 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8652\n"  /* .word 0x8652 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06018DDC */
    ".word 0x8DDC\n"  /* bt/s 0x060098D6 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x46EC\n"  /* .word 0x46EC */
    ".word 0xE470\n"  /* mov #112,r4 */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2249\n"  /* and r4,r2 */
    ".word 0x3240\n"  /* cmp/eq r4,r2 */
    ".word 0x8B21\n"  /* bf 0x06009972 */
    ".word 0xB443\n"  /* bsr 0x0600A1B8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD221\n"  /* mov.l @(0x84,PC),r2  {[0x060099B8] = 0x80000000} */
    ".word 0x63A2\n"  /* mov.l @r10,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2A32\n"  /* mov.l r3,@r10 */
    ".word 0x60B1\n"  /* mov.w @r11,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890F\n"  /* bt 0x06009962 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x060099BC] = 0x0607EBF4} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0xE218\n"  /* mov #24,r2 */
    ".word 0x2B31\n"  /* mov.w r3,@r11 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x060099C0] = 0x0605AD10} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x060099C4] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x060099C8] = 0x06059F44} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xA049\n"  /* bra 0x060099F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x060099CC] = 0x0605AD08} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xE20E\n"  /* mov #14,r2 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x060099C0] = 0x0605AD10} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xA041\n"  /* bra 0x060099F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x060099D0] = 0x06078650} */
    ".word 0x6041\n"  /* mov.w @r4,r0 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x2401\n"  /* mov.w r0,@r4 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xC810\n"  /* tst #0x10,r0 */
    ".word 0x890D\n"  /* bt 0x0600999C */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x060099D4] = 0x0605ACC4} */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x6733\n"  /* mov r3,r7 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x67F2\n"  /* mov.l @r15,r7 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x950F\n"  /* mov.w @(0x1E,PC),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xA02C\n"  /* bra 0x060099F4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60B1\n"  /* mov.w @r11,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891D\n"  /* bt 0x060099E0 */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0xD70B\n"  /* mov.l @(0x2C,PC),r7  {[0x060099D8] = 0x060446FC} */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD70B\n"  /* mov.l @(0x2C,PC),r7  {[0x060099DC] = 0x06044718} */
    ".word 0xA01C\n"  /* bra 0x060099EC */
    ".word 0x0009\n"  /* nop */
    ".word 0x0794\n"  /* mov.b r9,@(r0,r7) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x060093E6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD08\n"  /* bra 0x060093E2 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8650\n"  /* .word 0x8650 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xACC4\n"  /* bra 0x06009362 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x46FC\n"  /* .word 0x46FC */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x4718\n"  /* shll8 r7 */
    ".word 0xD717\n"  /* mov.l @(0x5C,PC),r7  {[0x06009A40] = 0x060446FC} */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x6593\n"  /* mov r9,r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD716\n"  /* mov.l @(0x58,PC),r7  {[0x06009A44] = 0x0604472C} */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x9525\n"  /* mov.w @(0x4A,PC),r5 */
    ".word 0x4E0B\n"  /* jsr @r14 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x60B1\n"  /* mov.w @r11,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8902\n"  /* bt 0x06009A02 */
    ".word 0xD312\n"  /* mov.l @(0x48,PC),r3  {[0x06009A48] = 0x060033E6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD012\n"  /* mov.l @(0x48,PC),r0  {[0x06009A4C] = 0x06086030} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8905\n"  /* bt 0x06009A18 */
    ".word 0x6683\n"  /* mov r8,r6 */
    ".word 0x9516\n"  /* mov.w @(0x2C,PC),r5 */
    ".word 0xD70F\n"  /* mov.l @(0x3C,PC),r7  {[0x06009A50] = 0x0605A1C8} */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x06009A54] = 0x060283E0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x60A2\n"  /* mov.l @r10,r0 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x06009A58] = 0x06026CE0} */
    ".word 0xCB04\n"  /* or #0x04,r0 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2A02\n"  /* mov.l r0,@r10 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06009A5C] = 0x06059F44} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
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
    ".word 0x079C\n"  /* mov.b @(r0,r9),r7 */
    ".word 0x0082\n"  /* .word 0x0082 */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x46FC\n"  /* .word 0x46FC */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x472C\n"  /* .word 0x472C */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x33E6\n"  /* cmp/hi r14,r3 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6030\n"  /* mov.b @r3,r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1C8\n"  /* bra 0x06009DE6 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x83E0\n"  /* .word 0x83E0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".size _state_19_time_extension, .-_state_19_time_extension\n"
);
__asm__(



    ".balign 2\n"
    ".global _state_20_race_completion\n"
    ".type _state_20_race_completion, @function\n"









    ".section .text.FUN_06009A60, \"ax\"\n"

    ".global _FUN_06009A60\n"
    "_state_20_race_completion:\n"
    "_FUN_06009A60:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0xEB01\n"  /* mov #1,r11 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0xEA04\n"  /* mov #4,r10 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0xD926\n"  /* mov.l @(0x98,PC),r9  {[0x06009B14] = 0x06078637} */
    ".word 0xDC27\n"  /* mov.l @(0x9C,PC),r12  {[0x06009B18] = 0x0607E944} */
    ".word 0xDE27\n"  /* mov.l @(0x9C,PC),r14  {[0x06009B1C] = 0x0605AB17} */
    ".word 0xD328\n"  /* mov.l @(0xA0,PC),r3  {[0x06009B20] = 0x06014A04} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x68C2\n"  /* mov.l @r12,r8 */
    ".word 0xD327\n"  /* mov.l @(0x9C,PC),r3  {[0x06009B24] = 0x060210F6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB2B7\n"  /* bsr 0x06009FFC */
    ".word 0x0009\n"  /* nop */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0xD525\n"  /* mov.l @(0x94,PC),r5  {[0x06009B28] = 0x06078648} */
    ".word 0x6550\n"  /* mov.b @r5,r5 */
    ".word 0x750A\n"  /* add #10,r5 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x06009B2C] = 0x06018DDC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6453\n"  /* mov r5,r4 */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x9036\n"  /* mov.w @(0x6C,PC),r0 */
    ".word 0x032E\n"  /* mov.l @(r0,r2),r3 */
    ".word 0x701C\n"  /* add #28,r0 */
    ".word 0x2930\n"  /* mov.b r3,@r9 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0xD121\n"  /* mov.l @(0x84,PC),r1  {[0x06009B30] = 0x06078638} */
    ".word 0x023E\n"  /* mov.l @(r0,r3),r2 */
    ".word 0x2122\n"  /* mov.l r2,@r1 */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x06009B34] = 0x060786A4} */
    ".word 0xD221\n"  /* mov.l @(0x84,PC),r2  {[0x06009B38] = 0x0607863C} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD020\n"  /* mov.l @(0x80,PC),r0  {[0x06009B3C] = 0x06083255} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890F\n"  /* bt 0x06009AE0 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD31F\n"  /* mov.l @(0x7C,PC),r3  {[0x06009B40] = 0x0605AD00} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B0A\n"  /* bf 0x06009AE0 */
    ".word 0x6290\n"  /* mov.b @r9,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B07\n"  /* bf 0x06009AE0 */
    ".word 0xD01C\n"  /* mov.l @(0x70,PC),r0  {[0x06009B44] = 0x0607EAE0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B03\n"  /* bf 0x06009AE0 */
    ".word 0x60E0\n"  /* mov.b @r14,r0 */
    ".word 0xCB08\n"  /* or #0x08,r0 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0x2E00\n"  /* mov.b r0,@r14 */
    ".word 0xD019\n"  /* mov.l @(0x64,PC),r0  {[0x06009B48] = 0x06085FF4} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8960\n"  /* bt 0x06009BAA */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06009B4C] = 0x0605AD04} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B5B\n"  /* bf 0x06009BAA */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x06009B44] = 0x0607EAE0} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B57\n"  /* bf 0x06009BAA */
    ".word 0x6390\n"  /* mov.b @r9,r3 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x893A\n"  /* bt 0x06009B78 */
    ".word 0xD413\n"  /* mov.l @(0x4C,PC),r4  {[0x06009B50] = 0x0605AB16} */
    ".word 0xD013\n"  /* mov.l @(0x4C,PC),r0  {[0x06009B54] = 0x0607EAD8} */
    ".word 0xA031\n"  /* bra 0x06009B6C */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0xA02B\n"  /* bra 0x06009B66 */
    ".word 0x22BB\n"  /* or r11,r2 */
    ".word 0x0224\n"  /* mov.b r2,@(r0,r2) */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8637\n"  /* .word 0x8637 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAB17\n"  /* bra 0x06009150 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014A04 */
    ".word 0x4A04\n"  /* rotl r10 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_060210F6 */
    ".word 0x10F6\n"  /* mov.l r15,@(0x18,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8648\n"  /* .word 0x8648 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06018DDC */
    ".word 0x8DDC\n"  /* bt/s 0x06009AEA */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8638\n"  /* .word 0x8638 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86A4\n"  /* .word 0x86A4 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x863C\n"  /* .word 0x863C */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3255\n"  /* dmulu.l r5,r2 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD00\n"  /* bra 0x06009546 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAE0\n"  /* mov #-32,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD04\n"  /* bra 0x0600955A */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAB16\n"  /* bra 0x06009182 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x6040\n"  /* mov.b @r4,r0 */
    ".word 0xCB02\n"  /* or #0x02,r0 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0xA00B\n"  /* bra 0x06009B78 */
    ".word 0x2400\n"  /* mov.b r0,@r4 */
    ".word 0x6240\n"  /* mov.b @r4,r2 */
    ".word 0x22AB\n"  /* or r10,r2 */
    ".word 0x622E\n"  /* exts.b r2,r2 */
    ".word 0xA006\n"  /* bra 0x06009B78 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89CC\n"  /* bt 0x06009B0A */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89F1\n"  /* bt 0x06009B58 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89F4\n"  /* bt 0x06009B62 */
    ".word 0x6290\n"  /* mov.b @r9,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B15\n"  /* bf 0x06009BAA */
    ".word 0xD02A\n"  /* mov.l @(0xA8,PC),r0  {[0x06009C28] = 0x0607EAD8} */
    ".word 0xA00D\n"  /* bra 0x06009B9E */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0xA007\n"  /* bra 0x06009B98 */
    ".word 0x22BB\n"  /* or r11,r2 */
    ".word 0x60E0\n"  /* mov.b @r14,r0 */
    ".word 0xCB02\n"  /* or #0x02,r0 */
    ".word 0x600E\n"  /* exts.b r0,r0 */
    ".word 0xA00B\n"  /* bra 0x06009BAA */
    ".word 0x2E00\n"  /* mov.b r0,@r14 */
    ".word 0x62E0\n"  /* mov.b @r14,r2 */
    ".word 0x22AB\n"  /* or r10,r2 */
    ".word 0x622E\n"  /* exts.b r2,r2 */
    ".word 0xA006\n"  /* bra 0x06009BAA */
    ".word 0x2E20\n"  /* mov.b r2,@r14 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89F0\n"  /* bt 0x06009B84 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89F1\n"  /* bt 0x06009B8A */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89F4\n"  /* bt 0x06009B94 */
    ".word 0xB305\n"  /* bsr 0x0600A1B8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6083\n"  /* mov r8,r0 */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x06009C2C] = 0x06083261} */
    ".word 0x8403\n"  /* mov.b @(0x3,r0),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x8B1E\n"  /* bf 0x06009BF6 */
    ".word 0xD01B\n"  /* mov.l @(0x6C,PC),r0  {[0x06009C28] = 0x0607EAD8} */
    ".word 0xA014\n"  /* bra 0x06009BE6 */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x5286\n"  /* mov.l @(0x18,r8),r2 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06009C30] = 0xFFB80000} */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8B01\n"  /* bf 0x06009BCA */
    ".word 0xA007\n"  /* bra 0x06009BD8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x62DE\n"  /* exts.b r13,r2 */
    ".word 0xA015\n"  /* bra 0x06009BFA */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0x5284\n"  /* mov.l @(0x10,r8),r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06009C34] = 0xFEC60000} */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8901\n"  /* bt 0x06009BDC */
    ".word 0xA00F\n"  /* bra 0x06009BFA */
    ".word 0x24B0\n"  /* mov.b r11,@r4 */
    ".word 0x62DE\n"  /* exts.b r13,r2 */
    ".word 0xA00C\n"  /* bra 0x06009BFA */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0xA009\n"  /* bra 0x06009BF8 */
    ".word 0x62DE\n"  /* exts.b r13,r2 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89E9\n"  /* bt 0x06009BBE */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89F0\n"  /* bt 0x06009BD0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89F7\n"  /* bt 0x06009BE2 */
    ".word 0xA002\n"  /* bra 0x06009BFA */
    ".word 0x0009\n"  /* nop */
    ".word 0xE202\n"  /* mov #2,r2 */
    ".word 0x2420\n"  /* mov.b r2,@r4 */
    ".word 0xE040\n"  /* mov #64,r0 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x03D6\n"  /* mov.l r13,@(r0,r3) */
    ".word 0xE315\n"  /* mov #21,r3 */
    ".word 0xD20D\n"  /* mov.l @(0x34,PC),r2  {[0x06009C38] = 0x0605AD10} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xE356\n"  /* mov #86,r3 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x06009C3C] = 0x0607EBCC} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x06009C40] = 0x06078654} */
    ".word 0x22A0\n"  /* mov.b r10,@r2 */
    ".word 0xD20C\n"  /* mov.l @(0x30,PC),r2  {[0x06009C44] = 0x0605A016} */
    ".word 0x22A1\n"  /* mov.w r10,@r2 */
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
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3261\n"  /* .word 0x3261 */
    ".word 0xFFB8\n"  /* .word 0xFFB8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFEC6\n"  /* .word 0xFEC6 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x0600965E */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBCC\n"  /* mov #-52,r11 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA016\n"  /* bra 0x06009C76 */
    ".size _state_20_race_completion, .-_state_20_race_completion\n"
);
/* FUN_06009C48: moved to state_init_handlers.c */
__asm__(



    ".balign 2\n"
    ".global _state_24_post_race_init\n"
    ".type _state_24_post_race_init, @function\n"









    ".section .text.FUN_06009CFC, \"ax\"\n"

    ".global _FUN_06009CFC\n"
    "_state_24_post_race_init:\n"
    "_FUN_06009CFC:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0xD21E\n"  /* mov.l @(0x78,PC),r2  {[0x06009D7C] = 0x0605A016} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06009D80] = 0x06014A74} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x06009D84] = 0x06019058} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB252\n"  /* bsr 0x0600A1B8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE219\n"  /* mov #25,r2 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x06009D88] = 0x0605AD10} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0xE206\n"  /* mov #6,r2 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06009D8C] = 0x06078654} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06009D90] = 0x060032D4} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06009D94] = 0x060210F6} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x06009D98] = 0x0607E944} */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x1232\n"  /* mov.l r3,@(0x8,r2) */
    ".word 0xD419\n"  /* mov.l @(0x64,PC),r4  {[0x06009D9C] = 0x0605B6D8} */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x06009DA0] = 0x40000000} */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x232B\n"  /* or r2,r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06009DA4] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x06009DA8] = 0x06059F44} */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".size _state_24_post_race_init, .-_state_24_post_race_init\n"
);
__asm__(
    ".balign 4\n"
    ".global _state_25_post_race_display\n"
    ".type _state_25_post_race_display, @function\n"









    ".section .text.FUN_06009D4E, \"ax\"\n"

    ".global _FUN_06009D4E\n"
    "_state_25_post_race_display:\n"
    "_FUN_06009D4E:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06009DAC] = 0x06014D2C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD216\n"  /* mov.l @(0x58,PC),r2  {[0x06009DB0] = 0x06085F8A} */
    ".word 0x6220\n"  /* mov.b @r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B0B\n"  /* bf 0x06009D76 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06009DB4] = 0x0600BB94} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD614\n"  /* mov.l @(0x50,PC),r6  {[0x06009DB8] = 0x06063E24} */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x06009DBC] = 0x06063EEC} */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x06009DC0] = 0x06063EF8} */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06009DC4] = 0x060053AC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6662\n"  /* mov.l @r6,r6 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06009DC8] = 0x0600BFFC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06009DCC] = 0x060078DC} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA016\n"  /* bra 0x06009DAE */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014A74 */
    ".word 0x4A74\n"  /* .word 0x4A74 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06019058 */
    ".word 0x9058\n"  /* mov.w @(0xB0,PC),r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xAD10\n"  /* bra 0x060097AE */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060032D4 */
    ".word 0x32D4\n"  /* .word 0x32D4 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_060210F6 */
    ".word 0x10F6\n"  /* mov.l r15,@(0x18,r0) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0600AB52 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0x0601\n"  /* .word 0x0601  -> FUN_06014D2C */
    ".word 0x4D2C\n"  /* .word 0x4D2C */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5F8A\n"  /* mov.l @(0x28,r8),r15 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600BB94 */
    ".word 0xBB94\n"  /* bsr 0x060094E2 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E24\n"  /* .word 0x3E24 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EF8\n"  /* sub r15,r14 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060053AC */
    ".word 0x53AC\n"  /* mov.l @(0x30,r10),r3 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_0600BFFC */
    ".word 0xBFFC\n"  /* bsr 0x06009DC6 */
    ".word 0x0600\n"  /* .word 0x0600  -> FUN_060078DC */
    ".word 0x78DC\n"  /* add #-36,r8 */
    ".size _state_25_post_race_display, .-_state_25_post_race_display\n"
);
/* FUN_06009DD0: moved to state_init_handlers.c */
/* FUN_06009E60: moved to state_init_handlers.c */
/* FUN_06009F10: moved to state_init_handlers.c */

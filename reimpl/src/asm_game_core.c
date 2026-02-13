__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _smpc_intback_trigger\n"
    ".type _smpc_intback_trigger, @function\n"
    ".global _FUN_060389A6\n"
    "_smpc_intback_trigger:\n"
    "_FUN_060389A6:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE18\n"  /* mov.l @(0x60,PC),r14  {[0x06038A0C] = 0x060635AC} */
    ".word 0x60E1\n"  /* mov.w @r14,r0 */
    ".word 0xA03B\n"  /* bra 0x06038A28 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xBF85\n"  /* bsr 0x060388C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA018\n"  /* bra 0x060389EA */
    ".word 0x0009\n"  /* nop */
    ".word 0xD615\n"  /* mov.l @(0x54,PC),r6  {[0x06038A10] = 0x060635A0} */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x06038A14] = 0x060A3D74} */
    ".word 0xD416\n"  /* mov.l @(0x58,PC),r4  {[0x06038A18] = 0x060A3D70} */
    ".word 0x6661\n"  /* mov.w @r6,r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x666D\n"  /* extu.w r6,r6 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0xB03A\n"  /* bsr 0x06038A48 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xD611\n"  /* mov.l @(0x44,PC),r6  {[0x06038A1C] = 0x060635A2} */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x06038A20] = 0x060A3D7C} */
    ".word 0xD412\n"  /* mov.l @(0x48,PC),r4  {[0x06038A24] = 0x060A3D78} */
    ".word 0x6661\n"  /* mov.w @r6,r6 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x666D\n"  /* extu.w r6,r6 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0xB031\n"  /* bsr 0x06038A48 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0xBF6B\n"  /* bsr 0x060388C0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xA029\n"  /* bra 0x06038A42 */
    ".word 0x2E21\n"  /* mov.w r2,@r14 */
    ".word 0x00B0\n"  /* .word 0x00B0 */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D84\n"  /* .word 0x3D84 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D88\n"  /* sub r8,r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3DB0\n"  /* cmp/eq r11,r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3DF8\n"  /* sub r15,r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E38\n"  /* sub r3,r14 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3E48\n"  /* sub r4,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35AC\n"  /* add r10,r5 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35A0\n"  /* cmp/eq r10,r5 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D74\n"  /* .word 0x3D74 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D70\n"  /* cmp/eq r7,r13 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35A2\n"  /* cmp/hs r10,r5 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D7C\n"  /* add r7,r13 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D78\n"  /* sub r7,r13 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89C2\n"  /* bt 0x060389B2 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89C4\n"  /* bt 0x060389BA */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8906\n"  /* bt 0x06038A42 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x8904\n"  /* bt 0x06038A42 */
    ".word 0x8805\n"  /* cmp/eq #5,r0 */
    ".word 0x8902\n"  /* bt 0x06038A42 */
    ".word 0x8806\n"  /* cmp/eq #6,r0 */
    ".word 0x8900\n"  /* bt 0x06038A42 */
    ".word 0x8807\n"  /* cmp/eq #7,r0 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA040\n"  /* bra 0x06038AC8 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4601\n"  /* shlr r6 */
    ".word 0xE700\n"  /* mov #0,r7 */
    ".word 0x6373\n"  /* mov r7,r3 */
    ".word 0x3362\n"  /* cmp/hs r6,r3 */
    ".word 0x8906\n"  /* bt 0x06038A60 */
    ".word 0x7701\n"  /* add #1,r7 */
    ".word 0x6351\n"  /* mov.w @r5,r3 */
    ".word 0x2431\n"  /* mov.w r3,@r4 */
    ".word 0x7402\n"  /* add #2,r4 */
    ".word 0x3762\n"  /* cmp/hs r6,r7 */
    ".word 0x8FF9\n"  /* bf/s 0x06038A52 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x9619\n"  /* mov.w @(0x32,PC),r6 */
    ".word 0xD50E\n"  /* mov.l @(0x38,PC),r5  {[0x06038AA0] = 0x060A3D88} */
    ".word 0xA01C\n"  /* bra 0x06038AA4 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x8557\n"  /* mov.w @(0xE,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0xA00E\n"  /* bra 0x06038A92 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x8557\n"  /* mov.w @(0xE,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x930D\n"  /* mov.w @(0x1A,PC),r3 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0xA006\n"  /* bra 0x06038A92 */
    ".word 0x0009\n"  /* nop */
    ".word 0x8557\n"  /* mov.w @(0xE,r5),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2269\n"  /* and r6,r2 */
    ".word 0x9306\n"  /* mov.w @(0xC,PC),r3 */
    ".word 0x223B\n"  /* or r3,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0xA00B\n"  /* bra 0x06038AB0 */
    ".word 0x8157\n"  /* mov.w r0,@(0xE,r5) */
    ".word 0x0FFF\n"  /* mac.l @r15+,@r15+ */
    ".word 0x1000\n"  /* mov.l r0,@(0x0,r0) */
    ".word 0x2000\n"  /* mov.b r0,@r0 */
    ".word 0x060A\n"  /* sts mach,r6 */
    ".word 0x3D88\n"  /* sub r8,r13 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89E1\n"  /* bt 0x06038A6C */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89E4\n"  /* bt 0x06038A76 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89EA\n"  /* bt 0x06038A86 */
    ".word 0xD404\n"  /* mov.l @(0x10,PC),r4  {[0x06038AC4] = 0x060635AC} */
    ".word 0x6241\n"  /* mov.w @r4,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B01\n"  /* bf 0x06038ABE */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2431\n"  /* mov.w r3,@r4 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x35AC\n"  /* add r10,r5 */
    ".size _smpc_intback_trigger, .-_smpc_intback_trigger\n"
);
extern void FUN_06020c3c(void);
extern void FUN_06020c3c(void);
void FUN_06020C3C(void) { FUN_06020c3c(); }
/* cd_status_read / FUN_06018EAC: moved to cd_command.c */
/* FUN_06009FFC: moved to batch_state_machine.c as sound_channels_reset */
__asm__(
    ".balign 4\n"
    ".global _cd_frame_sync_advance\n"
    ".type _cd_frame_sync_advance, @function\n"
    ".global _FUN_06012B58\n"
    "_cd_frame_sync_advance:\n"
    "_FUN_06012B58:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDA16\n"  /* mov.l @(0x58,PC),r10  {[0x06012BC0] = 0x0603AC1C} */
    ".word 0xEC01\n"  /* mov #1,r12 */
    ".word 0xEE05\n"  /* mov #5,r14 */
    ".word 0xE4FF\n"  /* mov #-1,r4 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06012BC4] = 0x06084360} */
    ".word 0x23C2\n"  /* mov.l r12,@r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x06012BC8] = 0x0608436C} */
    ".word 0x1232\n"  /* mov.l r3,@(0x8,r2) */
    ".word 0xE350\n"  /* mov #80,r3 */
    ".word 0x1231\n"  /* mov.l r3,@(0x4,r2) */
    ".word 0xDB14\n"  /* mov.l @(0x50,PC),r11  {[0x06012BCC] = 0x06083274} */
    ".word 0xA005\n"  /* bra 0x06012B8A */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0xD610\n"  /* mov.l @(0x40,PC),r6  {[0x06012BC4] = 0x06084360} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x4A0B\n"  /* jsr @r10 */
    ".word 0xE405\n"  /* mov #5,r4 */
    ".word 0x6403\n"  /* mov r0,r4 */
    ".word 0x7D01\n"  /* add #1,r13 */
    ".word 0x3DE3\n"  /* cmp/ge r14,r13 */
    ".word 0x8BF7\n"  /* bf 0x06012B80 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0xDD0F\n"  /* mov.l @(0x3C,PC),r13  {[0x06012BD0] = 0x06084AEC} */
    ".word 0x3437\n"  /* cmp/gt r3,r4 */
    ".word 0x8901\n"  /* bt 0x06012B9C */
    ".word 0xA00A\n"  /* bra 0x06012BB0 */
    ".word 0x2DC0\n"  /* mov.b r12,@r13 */
    ".word 0xD40D\n"  /* mov.l @(0x34,PC),r4  {[0x06012BD4] = 0x060448C8} */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06012BD8] = 0x0603AE08} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4011\n"  /* cmp/pz r0 */
    ".word 0x8901\n"  /* bt 0x06012BAC */
    ".word 0xA002\n"  /* bra 0x06012BB0 */
    ".word 0x2DC0\n"  /* mov.b r12,@r13 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2D20\n"  /* mov.b r2,@r13 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603AC1C */
    ".word 0xAC1C\n"  /* bra 0x060123FE */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4360\n"  /* .word 0x4360 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x436C\n"  /* .word 0x436C */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x3274\n"  /* .word 0x3274 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x4AEC\n"  /* .word 0x4AEC */
    ".word 0x0604\n"  /* mov.b r0,@(r0,r6) */
    ".word 0x48C8\n"  /* .word 0x48C8 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603AE08 */
    ".word 0xAE08\n"  /* bra 0x060127EE */
    ".size _cd_frame_sync_advance, .-_cd_frame_sync_advance\n"
);
/* FUN_0600A1B8: moved to game_state_utils.c */
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_060072E6\n"
    ".type _FUN_060072E6, @function\n"
    "_FUN_060072E6:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x2F76\n"  /* mov.l r7,@-r15 */
    ".word 0x2F66\n"  /* mov.l r6,@-r15 */
    ".word 0x2F56\n"  /* mov.l r5,@-r15 */
    ".word 0x2F46\n"  /* mov.l r4,@-r15 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x2F16\n"  /* mov.l r1,@-r15 */
    ".word 0x2F06\n"  /* mov.l r0,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F02\n"  /* sts.l mach,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06007364] = 0x06000344} */
    ".word 0x9526\n"  /* mov.w @(0x4C,PC),r5 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE4FF\n"  /* mov #-1,r4 */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x06007368] = 0x06059F40} */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06007368] = 0x06059F40} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x7201\n"  /* add #1,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x951E\n"  /* mov.w @(0x3C,PC),r5 */
    ".word 0x6450\n"  /* mov.b @r5,r4 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0xC987\n"  /* and #0x87,r0 */
    ".word 0x2500\n"  /* mov.b r0,@r5 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06007364] = 0x06000344} */
    ".word 0x9419\n"  /* mov.w @(0x32,PC),r4 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F06\n"  /* lds.l @r15+,mach */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x60F6\n"  /* mov.l @r15+,r0 */
    ".word 0x61F6\n"  /* mov.l @r15+,r1 */
    ".word 0x62F6\n"  /* mov.l @r15+,r2 */
    ".word 0x63F6\n"  /* mov.l @r15+,r3 */
    ".word 0x64F6\n"  /* mov.l @r15+,r4 */
    ".word 0x65F6\n"  /* mov.l @r15+,r5 */
    ".word 0x66F6\n"  /* mov.l @r15+,r6 */
    ".word 0x67F6\n"  /* mov.l @r15+,r7 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x6FF6\n"  /* mov.l @r15+,r15 */
    ".word 0x002B\n"  /* rte */
    ".word 0x0009\n"  /* nop */
    ".word 0x0083\n"  /* .word 0x0083 */
    ".word 0xFE11\n"  /* .word 0xFE11 */
    ".word 0xFF7C\n"  /* .word 0xFF7C */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0600\n"  /* .word 0x0600 */
    ".word 0x0344\n"  /* mov.b r4,@(r0,r3) */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F40\n"  /* mov.w @(0x80,PC),r15 */
    ".size _FUN_060072E6, .-_FUN_060072E6\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06007370\n"
    ".type _FUN_06007370, @function\n"
    "_FUN_06007370:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE2B\n"  /* mov.l @(0xAC,PC),r14  {[0x06007420] = 0x06063F5C} */
    ".word 0xD22B\n"  /* mov.l @(0xAC,PC),r2  {[0x06007424] = 0x0606A4F4} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0x934B\n"  /* mov.w @(0x96,PC),r3 */
    ".word 0xD22B\n"  /* mov.l @(0xAC,PC),r2  {[0x06007428] = 0x0606A4EC} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD32B\n"  /* mov.l @(0xAC,PC),r3  {[0x0600742C] = 0x06039250} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0xE502\n"  /* mov #2,r5 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x06007430] = 0x0603931C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x9240\n"  /* mov.w @(0x80,PC),r2 */
    ".word 0x6563\n"  /* mov r6,r5 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x973E\n"  /* mov.w @(0x7C,PC),r7 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x06007434] = 0x060393FC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x6463\n"  /* mov r6,r4 */
    ".word 0xD426\n"  /* mov.l @(0x98,PC),r4  {[0x06007438] = 0x0000FFFF} */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x0600743C] = 0x06038E54} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".word 0xD326\n"  /* mov.l @(0x98,PC),r3  {[0x06007440] = 0x06012E00} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x9634\n"  /* mov.w @(0x68,PC),r6 */
    ".word 0xD525\n"  /* mov.l @(0x94,PC),r5  {[0x06007444] = 0x002A0000} */
    ".word 0xD425\n"  /* mov.l @(0x94,PC),r4  {[0x06007448] = 0x06059FFC} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0600744C] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD023\n"  /* mov.l @(0x8C,PC),r0  {[0x06007450] = 0x0607EAB8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x890B\n"  /* bt 0x060073E2 */
    ".word 0x9626\n"  /* mov.w @(0x4C,PC),r6 */
    ".word 0xD521\n"  /* mov.l @(0x84,PC),r5  {[0x06007454] = 0x06059F78} */
    ".word 0xD41E\n"  /* mov.l @(0x78,PC),r4  {[0x06007448] = 0x06059FFC} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x9223\n"  /* mov.w @(0x46,PC),r2 */
    ".word 0x6442\n"  /* mov.l @r4,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0600744C] = 0x0602761E} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0xE660\n"  /* mov #96,r6 */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x06007458] = 0x0605A018} */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0600745C] = 0x0602766C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x06007460] = 0x0605A008} */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06007464] = 0x00008000} */
    ".word 0x7260\n"  /* add #96,r2 */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06007468] = 0x0602382C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD51A\n"  /* mov.l @(0x68,PC),r5  {[0x0600746C] = 0x0606B178} */
    ".word 0xD41B\n"  /* mov.l @(0x6C,PC),r4  {[0x06007470] = 0x002A3457} */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x06007474] = 0x06028654} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x06007478] = 0x06026CE0} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x2468\n"  /* tst r6,r4 */
    ".word 0x00DF\n"  /* mac.l @r13+,@r0+ */
    ".word 0x015F\n"  /* mac.l @r5+,@r1+ */
    ".word 0x03C0\n"  /* .word 0x03C0 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0x0300\n"  /* .word 0x0300 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F5C\n"  /* add r5,r15 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F4\n"  /* bra 0x06007E12 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4EC\n"  /* bra 0x06007E06 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06039250 */
    ".word 0x9250\n"  /* mov.w @(0xA0,PC),r2 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603931C */
    ".word 0x931C\n"  /* mov.w @(0x38,PC),r3 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x93FC\n"  /* mov.w @(0x1F8,PC),r3 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06038E54 */
    ".word 0x8E54\n"  /* .word 0x8E54 */
    ".word 0x0601\n"  /* .word 0x0601 */
    ".word 0x2E00\n"  /* mov.b r0,@r14 */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9FFC\n"  /* mov.w @(0x1F8,PC),r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAB8\n"  /* mov #-72,r10 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F78\n"  /* mov.w @(0xF0,PC),r15 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA018\n"  /* bra 0x0600748E */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x766C\n"  /* add #108,r6 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA008\n"  /* bra 0x06007476 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_0602382C */
    ".word 0x382C\n"  /* add r2,r8 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xB178\n"  /* bsr 0x06007762 */
    ".word 0x002A\n"  /* sts pr,r0 */
    ".word 0x3457\n"  /* cmp/gt r5,r4 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06028654 */
    ".word 0x8654\n"  /* .word 0x8654 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".size _FUN_06007370, .-_FUN_06007370\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0600747C\n"
    ".type _FUN_0600747C, @function\n"
    "_FUN_0600747C:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x4F12\n"  /* sts.l macl,@-r15 */
    ".word 0x7FF4\n"  /* add #-12,r15 */
    ".word 0x2F72\n"  /* mov.l r7,@r15 */
    ".word 0x675D\n"  /* extu.w r5,r7 */
    ".word 0x6073\n"  /* mov r7,r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0xC93F\n"  /* and #0x3F,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x81F2\n"  /* mov.w r0,@(0x4,r15) */
    ".word 0x933F\n"  /* mov.w @(0x7E,PC),r3 */
    ".word 0x2739\n"  /* and r3,r7 */
    ".word 0x677D\n"  /* extu.w r7,r7 */
    ".word 0x6073\n"  /* mov r7,r0 */
    ".word 0x81F4\n"  /* mov.w r0,@(0x8,r15) */
    ".word 0xD71E\n"  /* mov.l @(0x78,PC),r7  {[0x06007528] = 0x0606A4F4} */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0xD31E\n"  /* mov.l @(0x78,PC),r3  {[0x0600752C] = 0x060684EC} */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x6272\n"  /* mov.l @r7,r2 */
    ".word 0x2421\n"  /* mov.w r2,@r4 */
    ".word 0x6053\n"  /* mov r5,r0 */
    ".word 0xD41C\n"  /* mov.l @(0x70,PC),r4  {[0x06007530] = 0x06063F64} */
    ".word 0xDE1D\n"  /* mov.l @(0x74,PC),r14  {[0x06007534] = 0x0606A4EC} */
    ".word 0x6372\n"  /* mov.l @r7,r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x6372\n"  /* mov.l @r7,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x8132\n"  /* mov.w r0,@(0x4,r3) */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x6372\n"  /* mov.l @r7,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x6372\n"  /* mov.l @r7,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2732\n"  /* mov.l r3,@r7 */
    ".word 0x85F2\n"  /* mov.w @(0x4,r15),r0 */
    ".word 0x6D03\n"  /* mov r0,r13 */
    ".word 0x85F4\n"  /* mov.w @(0x8,r15),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x2D3E\n"  /* mulu.w r3,r13 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x0D1A\n"  /* sts macl,r13 */
    ".word 0x33D7\n"  /* cmp/gt r13,r3 */
    ".word 0x3D3E\n"  /* .word 0x3D3E */
    ".word 0x4D21\n"  /* shar r13 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x06007538] = 0x06063F5C} */
    ".word 0xD20E\n"  /* mov.l @(0x38,PC),r2  {[0x0600753C] = 0x0602761E} */
    ".word 0x66D3\n"  /* mov r13,r6 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x4608\n"  /* shll2 r6 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x33DC\n"  /* add r13,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x7F0C\n"  /* add #12,r15 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F4\n"  /* bra 0x06007F16 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x84EC\n"  /* mov.b @(0xC,r14),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F64\n"  /* .word 0x3F64 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4EC\n"  /* bra 0x06007F12 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F5C\n"  /* add r5,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x761E\n"  /* add #30,r6 */
    ".global _FUN_06007540\n"
    "_FUN_06007540:\n"
    ".word 0x7FFC\n"  /* add #-4,r15 */
    ".word 0x605D\n"  /* extu.w r5,r0 */
    ".word 0xD72C\n"  /* mov.l @(0xB0,PC),r7  {[0x060075F8] = 0x060684EC} */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x037D\n"  /* mov.w @(r0,r7),r3 */
    ".word 0x604D\n"  /* extu.w r4,r0 */
    ".word 0x2F31\n"  /* mov.w r3,@r15 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xD52A\n"  /* mov.l @(0xA8,PC),r5  {[0x060075FC] = 0x0606A4F4} */
    ".word 0x6252\n"  /* mov.l @r5,r2 */
    ".word 0x0725\n"  /* mov.w r2,@(r0,r7) */
    ".word 0xD42A\n"  /* mov.l @(0xA8,PC),r4  {[0x06007600] = 0x06063F64} */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x67F1\n"  /* mov.w @r15,r7 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x677D\n"  /* extu.w r7,r7 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4708\n"  /* shll2 r7 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x4700\n"  /* shll r7 */
    ".word 0x374C\n"  /* add r4,r7 */
    ".word 0x6272\n"  /* mov.l @r7,r2 */
    ".word 0x2322\n"  /* mov.l r2,@r3 */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x8572\n"  /* mov.w @(0x4,r7),r0 */
    ".word 0x8132\n"  /* mov.w r0,@(0x4,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x6063\n"  /* mov r6,r0 */
    ".word 0x334C\n"  /* add r4,r3 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x6352\n"  /* mov.l @r5,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2532\n"  /* mov.l r3,@r5 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F04\n"  /* add #4,r15 */
    ".global _FUN_06007590\n"
    "_FUN_06007590:\n"
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD71B\n"  /* mov.l @(0x6C,PC),r7  {[0x06007600] = 0x06063F64} */
    ".word 0xD619\n"  /* mov.l @(0x64,PC),r6  {[0x060075FC] = 0x0606A4F4} */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0xD217\n"  /* mov.l @(0x5C,PC),r2  {[0x060075F8] = 0x060684EC} */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x6131\n"  /* mov.w @r3,r1 */
    ".word 0x2F11\n"  /* mov.w r1,@r15 */
    ".word 0x6341\n"  /* mov.w @r4,r3 */
    ".word 0x6162\n"  /* mov.l @r6,r1 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x323C\n"  /* add r3,r2 */
    ".word 0x2211\n"  /* mov.w r1,@r2 */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x62F1\n"  /* mov.w @r15,r2 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x337C\n"  /* add r7,r3 */
    ".word 0x4200\n"  /* shll r2 */
    ".word 0x327C\n"  /* add r7,r2 */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x6122\n"  /* mov.l @r2,r1 */
    ".word 0x2312\n"  /* mov.l r1,@r3 */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x337C\n"  /* add r7,r3 */
    ".word 0x8522\n"  /* mov.w @(0x4,r2),r0 */
    ".word 0xE20C\n"  /* mov #12,r2 */
    ".word 0x6103\n"  /* mov r0,r1 */
    ".word 0x8132\n"  /* mov.w r0,@(0x4,r3) */
    ".word 0x8541\n"  /* mov.w @(0x2,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3327\n"  /* cmp/gt r2,r3 */
    ".word 0x8B0E\n"  /* bf 0x06007604 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6103\n"  /* mov r0,r1 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0x625D\n"  /* extu.w r5,r2 */
    ".word 0x4208\n"  /* shll2 r2 */
    ".word 0x312C\n"  /* add r2,r1 */
    ".word 0xA009\n"  /* bra 0x06007608 */
    ".word 0x611D\n"  /* extu.w r1,r1 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x84EC\n"  /* mov.b @(0xC,r14),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F4\n"  /* bra 0x06007FEA */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F64\n"  /* .word 0x3F64 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6103\n"  /* mov r0,r1 */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x6013\n"  /* mov r1,r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x337C\n"  /* add r7,r3 */
    ".word 0x8133\n"  /* mov.w r0,@(0x6,r3) */
    ".word 0x6362\n"  /* mov.l @r6,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2632\n"  /* mov.l r3,@r6 */
    ".word 0x000B\n"  /* rts */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x6643\n"  /* mov r4,r6 */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0600764C] = 0x060684EC} */
    ".word 0x655D\n"  /* extu.w r5,r5 */
    ".word 0xD20A\n"  /* mov.l @(0x28,PC),r2  {[0x06007650] = 0x06063F64} */
    ".word 0x4600\n"  /* shll r6 */
    ".word 0x363C\n"  /* add r3,r6 */
    ".word 0x6661\n"  /* mov.w @r6,r6 */
    ".word 0xD309\n"  /* mov.l @(0x24,PC),r3  {[0x06007654] = 0x0000FF00} */
    ".word 0x646D\n"  /* extu.w r6,r4 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x342C\n"  /* add r2,r4 */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x2239\n"  /* and r3,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x8542\n"  /* mov.w @(0x4,r4),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x235B\n"  /* or r5,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x8142\n"  /* mov.w r0,@(0x4,r4) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x84EC\n"  /* mov.b @(0xC,r14),r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3F64\n"  /* .word 0x3F64 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFF00\n"  /* .word 0xFF00 */
    ".size _FUN_0600747C, .-_FUN_0600747C\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06007CEC\n"
    ".type _FUN_06007CEC, @function\n"
    "_FUN_06007CEC:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD829\n"  /* mov.l @(0xA4,PC),r8  {[0x06007DA4] = 0x060281B8} */
    ".word 0xD92A\n"  /* mov.l @(0xA8,PC),r9  {[0x06007DA8] = 0x0606A4F8} */
    ".word 0xDA2A\n"  /* mov.l @(0xA8,PC),r10  {[0x06007DAC] = 0x00008000} */
    ".word 0xDD2B\n"  /* mov.l @(0xAC,PC),r13  {[0x06007DB0] = 0x0608AC20} */
    ".word 0xDE2B\n"  /* mov.l @(0xAC,PC),r14  {[0x06007DB4] = 0x06078624} */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x06007DB8] = 0x0603C000} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA02F\n"  /* bra 0x06007D6E */
    ".word 0xEB00\n"  /* mov #0,r11 */
    ".word 0x60B3\n"  /* mov r11,r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0C9D\n"  /* mov.w @(r0,r9),r12 */
    ".word 0x6CCD\n"  /* extu.w r12,r12 */
    ".word 0x60CD\n"  /* extu.w r12,r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x30DC\n"  /* add r13,r0 */
    ".word 0x8503\n"  /* mov.w @(0x6,r0),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8809\n"  /* cmp/eq #9,r0 */
    ".word 0x8B0D\n"  /* bf 0x06007D4E */
    ".word 0x66A3\n"  /* mov r10,r6 */
    ".word 0x64CD\n"  /* extu.w r12,r4 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0xA00C\n"  /* bra 0x06007D66 */
    ".word 0x0009\n"  /* nop */
    ".word 0x64CD\n"  /* extu.w r12,r4 */
    ".word 0x65E2\n"  /* mov.l @r14,r5 */
    ".word 0x6343\n"  /* mov r4,r3 */
    ".word 0x4408\n"  /* shll2 r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4400\n"  /* shll r4 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x343C\n"  /* add r3,r4 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x06007DBC] = 0x060280F8} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x34DC\n"  /* add r13,r4 */
    ".word 0x7B01\n"  /* add #1,r11 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x7220\n"  /* add #32,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06007DC0] = 0x06078620} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x3B32\n"  /* cmp/hs r3,r11 */
    ".word 0x8BCC\n"  /* bf 0x06007D10 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x06007DC4] = 0x0000FFFF} */
    ".word 0xD213\n"  /* mov.l @(0x4C,PC),r2  {[0x06007DC8] = 0x21800000} */
    ".word 0x2231\n"  /* mov.w r3,@r2 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_06007CEC, .-_FUN_06007CEC\n"
);
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_06007D8E\n"
    ".type _FUN_06007D8E, @function\n"
    "_FUN_06007D8E:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xEC01\n"  /* mov #1,r12 */
    ".word 0x9D02\n"  /* mov.w @(0x4,PC),r13 */
    ".word 0x9E02\n"  /* mov.w @(0x4,PC),r14 */
    ".word 0xA018\n"  /* bra 0x06007DCE */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xFE11\n"  /* .word 0xFE11 */
    ".word 0x0080\n"  /* .word 0x0080 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x81B8\n"  /* mov.w r0,@(0x10,r11) */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0xA4F8\n"  /* bra 0x0600879E */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0xAC20\n"  /* bra 0x060075F6 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8624\n"  /* .word 0x8624 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x80F8\n"  /* mov.b r0,@(0x8,r15) */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8620\n"  /* .word 0x8620 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x2180\n"  /* mov.b r8,@r1 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x64C3\n"  /* mov r12,r4 */
    ".word 0x62D0\n"  /* mov.b @r13,r2 */
    ".word 0x622C\n"  /* extu.b r2,r2 */
    ".word 0x22E9\n"  /* and r14,r2 */
    ".word 0x32E0\n"  /* cmp/eq r14,r2 */
    ".word 0x8BF9\n"  /* bf 0x06007DCC */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0xC90F\n"  /* and #0x0F,r0 */
    ".word 0x2D00\n"  /* mov.b r0,@r13 */
    ".word 0xD508\n"  /* mov.l @(0x20,PC),r5  {[0x06007E00] = 0x0605A1C0} */
    ".word 0x2448\n"  /* tst r4,r4 */
    ".word 0x8904\n"  /* bt 0x06007DEE */
    ".word 0x6351\n"  /* mov.w @r5,r3 */
    ".word 0x73F6\n"  /* add #-10,r3 */
    ".word 0x2531\n"  /* mov.w r3,@r5 */
    ".word 0xA003\n"  /* bra 0x06007DF4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6251\n"  /* mov.w @r5,r2 */
    ".word 0x720A\n"  /* add #10,r2 */
    ".word 0x2521\n"  /* mov.w r2,@r5 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xD302\n"  /* mov.l @(0x8,PC),r3  {[0x06007E04] = 0x0603C000} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xA1C0\n"  /* bra 0x06008186 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0xC000\n"  /* mov.b r0,@(0x0,GBR) */
    ".size _FUN_06007D8E, .-_FUN_06007D8E\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_06007E08\n"
    ".type _FUN_06007E08, @function\n"
    "_FUN_06007E08:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x7FDC\n"  /* add #-36,r15 */
    ".word 0x9760\n"  /* mov.w @(0xC0,PC),r7 */
    ".word 0x66F3\n"  /* mov r15,r6 */
    ".word 0x761C\n"  /* add #28,r6 */
    ".word 0xEE00\n"  /* mov #0,r14 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x3307\n"  /* cmp/gt r0,r3 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x303E\n"  /* .word 0x303E */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0625\n"  /* mov.w r2,@(r0,r6) */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0x9354\n"  /* mov.w @(0xA8,PC),r3 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x0D4E\n"  /* mov.l @(r0,r4),r13 */
    ".word 0x3D37\n"  /* cmp/gt r3,r13 */
    ".word 0x8B14\n"  /* bf 0x06007E66 */
    ".word 0x9350\n"  /* mov.w @(0xA0,PC),r3 */
    ".word 0x3D33\n"  /* cmp/ge r3,r13 */
    ".word 0x8911\n"  /* bt 0x06007E66 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xE381\n"  /* mov #-127,r3 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x0D4E\n"  /* mov.l @(r0,r4),r13 */
    ".word 0x3D37\n"  /* cmp/gt r3,r13 */
    ".word 0x8B0A\n"  /* bf 0x06007E66 */
    ".word 0xE351\n"  /* mov #81,r3 */
    ".word 0x3D33\n"  /* cmp/ge r3,r13 */
    ".word 0x8907\n"  /* bt 0x06007E66 */
    ".word 0x60E3\n"  /* mov r14,r0 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x3307\n"  /* cmp/gt r0,r3 */
    ".word 0x303E\n"  /* .word 0x303E */
    ".word 0x4021\n"  /* shar r0 */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0x0625\n"  /* mov.w r2,@(r0,r6) */
    ".word 0x7E02\n"  /* add #2,r14 */
    ".word 0xE308\n"  /* mov #8,r3 */
    ".word 0x3E33\n"  /* cmp/ge r3,r14 */
    ".word 0x8BD8\n"  /* bf 0x06007E20 */
    ".word 0x6051\n"  /* mov.w @r5,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8916\n"  /* bt 0x06007EA4 */
    ".word 0x8561\n"  /* mov.w @(0x2,r6),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x8563\n"  /* mov.w @(0x6,r6),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3320\n"  /* cmp/eq r2,r3 */
    ".word 0x8B5D\n"  /* bf 0x06007F42 */
    ".word 0x5243\n"  /* mov.l @(0xC,r4),r2 */
    ".word 0x5347\n"  /* mov.l @(0x1C,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8903\n"  /* bt 0x06007E96 */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8161\n"  /* mov.w r0,@(0x2,r6) */
    ".word 0xA005\n"  /* bra 0x06007EA0 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8161\n"  /* mov.w r0,@(0x2,r6) */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xA04F\n"  /* bra 0x06007F42 */
    ".word 0x8163\n"  /* mov.w r0,@(0x6,r6) */
    ".word 0x8551\n"  /* mov.w @(0x2,r5),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x891A\n"  /* bt 0x06007EE2 */
    ".word 0x8562\n"  /* mov.w @(0x4,r6),r0 */
    ".word 0x6261\n"  /* mov.w @r6,r2 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3320\n"  /* cmp/eq r2,r3 */
    ".word 0x8B43\n"  /* bf 0x06007F42 */
    ".word 0x5245\n"  /* mov.l @(0x14,r4),r2 */
    ".word 0x5341\n"  /* mov.l @(0x4,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8905\n"  /* bt 0x06007ECE */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8162\n"  /* mov.w r0,@(0x4,r6) */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2631\n"  /* mov.w r3,@r6 */
    ".word 0xA005\n"  /* bra 0x06007ED8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8162\n"  /* mov.w r0,@(0x4,r6) */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2631\n"  /* mov.w r3,@r6 */
    ".word 0xA033\n"  /* bra 0x06007F42 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFE6B\n"  /* .word 0xFE6B */
    ".word 0xFF58\n"  /* .word 0xFF58 */
    ".word 0x00A8\n"  /* .word 0x00A8 */
    ".word 0x8552\n"  /* mov.w @(0x4,r5),r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8916\n"  /* bt 0x06007F18 */
    ".word 0x8563\n"  /* mov.w @(0x6,r6),r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x8561\n"  /* mov.w @(0x2,r6),r0 */
    ".word 0x6203\n"  /* mov r0,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x3320\n"  /* cmp/eq r2,r3 */
    ".word 0x8B23\n"  /* bf 0x06007F42 */
    ".word 0x5247\n"  /* mov.l @(0x1C,r4),r2 */
    ".word 0x5343\n"  /* mov.l @(0xC,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8903\n"  /* bt 0x06007F0A */
    ".word 0xE001\n"  /* mov #1,r0 */
    ".word 0x8163\n"  /* mov.w r0,@(0x6,r6) */
    ".word 0xA005\n"  /* bra 0x06007F14 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0x8163\n"  /* mov.w r0,@(0x6,r6) */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0xA015\n"  /* bra 0x06007F42 */
    ".word 0x8161\n"  /* mov.w r0,@(0x2,r6) */
    ".word 0x6261\n"  /* mov.w @r6,r2 */
    ".word 0x8562\n"  /* mov.w @(0x4,r6),r0 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x3230\n"  /* cmp/eq r3,r2 */
    ".word 0x8B0D\n"  /* bf 0x06007F42 */
    ".word 0x5241\n"  /* mov.l @(0x4,r4),r2 */
    ".word 0x5345\n"  /* mov.l @(0x14,r4),r3 */
    ".word 0x3233\n"  /* cmp/ge r3,r2 */
    ".word 0x8904\n"  /* bt 0x06007F38 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2631\n"  /* mov.w r3,@r6 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xA004\n"  /* bra 0x06007F40 */
    ".word 0x6023\n"  /* mov r2,r0 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2621\n"  /* mov.w r2,@r6 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x6033\n"  /* mov r3,r0 */
    ".word 0x8162\n"  /* mov.w r0,@(0x4,r6) */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x7302\n"  /* add #2,r3 */
    ".word 0x1F32\n"  /* mov.l r3,@(0x8,r15) */
    ".word 0x6B43\n"  /* mov r4,r11 */
    ".word 0x7B08\n"  /* add #8,r11 */
    ".word 0x6C43\n"  /* mov r4,r12 */
    ".word 0x7C04\n"  /* add #4,r12 */
    ".word 0x6A43\n"  /* mov r4,r10 */
    ".word 0x7A0C\n"  /* add #12,r10 */
    ".word 0x6263\n"  /* mov r6,r2 */
    ".word 0x7206\n"  /* add #6,r2 */
    ".word 0x1F23\n"  /* mov.l r2,@(0xC,r15) */
    ".word 0x6E43\n"  /* mov r4,r14 */
    ".word 0x7E18\n"  /* add #24,r14 */
    ".word 0x6D43\n"  /* mov r4,r13 */
    ".word 0x7D1C\n"  /* add #28,r13 */
    ".word 0x6353\n"  /* mov r5,r3 */
    ".word 0x7302\n"  /* add #2,r3 */
    ".word 0x1F36\n"  /* mov.l r3,@(0x18,r15) */
    ".word 0x6163\n"  /* mov r6,r1 */
    ".word 0x7104\n"  /* add #4,r1 */
    ".word 0x1F14\n"  /* mov.l r1,@(0x10,r15) */
    ".word 0x6843\n"  /* mov r4,r8 */
    ".word 0x7810\n"  /* add #16,r8 */
    ".word 0x6943\n"  /* mov r4,r9 */
    ".word 0x7914\n"  /* add #20,r9 */
    ".word 0x6363\n"  /* mov r6,r3 */
    ".word 0x1F31\n"  /* mov.l r3,@(0x4,r15) */
    ".word 0x6253\n"  /* mov r5,r2 */
    ".word 0x7204\n"  /* add #4,r2 */
    ".word 0x1F25\n"  /* mov.l r2,@(0x14,r15) */
    ".word 0x6051\n"  /* mov.w @r5,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8948\n"  /* bt 0x0600801A */
    ".word 0x53F2\n"  /* mov.l @(0x8,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8913\n"  /* bt 0x06007FBA */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x61B2\n"  /* mov.l @r11,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x61A2\n"  /* mov.l @r10,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0xA017\n"  /* bra 0x06007FE8 */
    ".word 0x0009\n"  /* nop */
    ".word 0x52F3\n"  /* mov.l @(0xC,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8911\n"  /* bt 0x06007FE8 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2432\n"  /* mov.l r3,@r4 */
    ".word 0x63C2\n"  /* mov.l @r12,r3 */
    ".word 0x61D2\n"  /* mov.l @r13,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0x6342\n"  /* mov.l @r4,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3373\n"  /* cmp/ge r7,r3 */
    ".word 0x8901\n"  /* bt 0x06007FF4 */
    ".word 0xA0F4\n"  /* bra 0x060081DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x932E\n"  /* mov.w @(0x5C,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B01\n"  /* bf 0x06008000 */
    ".word 0xA0EE\n"  /* bra 0x060081DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x62C2\n"  /* mov.l @r12,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3373\n"  /* cmp/ge r7,r3 */
    ".word 0x8F06\n"  /* bf/s 0x06008016 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9324\n"  /* mov.w @(0x48,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8901\n"  /* bt 0x06008016 */
    ".word 0xA0E5\n"  /* bra 0x060081E0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA0E1\n"  /* bra 0x060081DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x52F6\n"  /* mov.l @(0x18,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x894A\n"  /* bt 0x060080BA */
    ".word 0x53F4\n"  /* mov.l @(0x10,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8915\n"  /* bt 0x0600805A */
    ".word 0x63B2\n"  /* mov.l @r11,r3 */
    ".word 0x6182\n"  /* mov.l @r8,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0x63A2\n"  /* mov.l @r10,r3 */
    ".word 0x6192\n"  /* mov.l @r9,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2A32\n"  /* mov.l r3,@r10 */
    ".word 0xA019\n"  /* bra 0x06008088 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8911\n"  /* bt 0x06008088 */
    ".word 0x63B2\n"  /* mov.l @r11,r3 */
    ".word 0x6142\n"  /* mov.l @r4,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2B32\n"  /* mov.l r3,@r11 */
    ".word 0x63A2\n"  /* mov.l @r10,r3 */
    ".word 0x61C2\n"  /* mov.l @r12,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2A32\n"  /* mov.l r3,@r10 */
    ".word 0x63B2\n"  /* mov.l @r11,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3373\n"  /* cmp/ge r7,r3 */
    ".word 0x8901\n"  /* bt 0x06008094 */
    ".word 0xA0A4\n"  /* bra 0x060081DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x932E\n"  /* mov.w @(0x5C,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8B01\n"  /* bf 0x060080A0 */
    ".word 0xA09E\n"  /* bra 0x060081DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3373\n"  /* cmp/ge r7,r3 */
    ".word 0x8F06\n"  /* bf/s 0x060080B6 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9324\n"  /* mov.w @(0x48,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8901\n"  /* bt 0x060080B6 */
    ".word 0xA095\n"  /* bra 0x060081E0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA091\n"  /* bra 0x060081DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x52F5\n"  /* mov.l @(0x14,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8946\n"  /* bt 0x06008152 */
    ".word 0x53F3\n"  /* mov.l @(0xC,r15),r3 */
    ".word 0x6031\n"  /* mov.w @r3,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8915\n"  /* bt 0x060080FA */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x61E2\n"  /* mov.l @r14,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2832\n"  /* mov.l r3,@r8 */
    ".word 0x6392\n"  /* mov.l @r9,r3 */
    ".word 0x61D2\n"  /* mov.l @r13,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0xA019\n"  /* bra 0x06008128 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0x52F2\n"  /* mov.l @(0x8,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8911\n"  /* bt 0x06008128 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x61B2\n"  /* mov.l @r11,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2832\n"  /* mov.l r3,@r8 */
    ".word 0x6392\n"  /* mov.l @r9,r3 */
    ".word 0x61A2\n"  /* mov.l @r10,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2932\n"  /* mov.l r3,@r9 */
    ".word 0x6382\n"  /* mov.l @r8,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3373\n"  /* cmp/ge r7,r3 */
    ".word 0x8B55\n"  /* bf 0x060081DC */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9351\n"  /* mov.w @(0xA2,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8951\n"  /* bt 0x060081DC */
    ".word 0x6292\n"  /* mov.l @r9,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3373\n"  /* cmp/ge r7,r3 */
    ".word 0x8F06\n"  /* bf/s 0x0600814E */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9349\n"  /* mov.w @(0x92,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8901\n"  /* bt 0x0600814E */
    ".word 0xA049\n"  /* bra 0x060081E0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA045\n"  /* bra 0x060081DC */
    ".word 0x0009\n"  /* nop */
    ".word 0x52F1\n"  /* mov.l @(0x4,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8913\n"  /* bt 0x06008184 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6142\n"  /* mov.l @r4,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x61C2\n"  /* mov.l @r12,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0xA017\n"  /* bra 0x060081B2 */
    ".word 0x0009\n"  /* nop */
    ".word 0x52F4\n"  /* mov.l @(0x10,r15),r2 */
    ".word 0x6021\n"  /* mov.w @r2,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8911\n"  /* bt 0x060081B2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x6182\n"  /* mov.l @r8,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0x63D2\n"  /* mov.l @r13,r3 */
    ".word 0x6192\n"  /* mov.l @r9,r1 */
    ".word 0x6233\n"  /* mov r3,r2 */
    ".word 0x4300\n"  /* shll r3 */
    ".word 0x332C\n"  /* add r2,r3 */
    ".word 0x331C\n"  /* add r1,r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x4321\n"  /* shar r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3373\n"  /* cmp/ge r7,r3 */
    ".word 0x8B10\n"  /* bf 0x060081DC */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x930C\n"  /* mov.w @(0x18,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x890C\n"  /* bt 0x060081DC */
    ".word 0x62D2\n"  /* mov.l @r13,r2 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x3373\n"  /* cmp/ge r7,r3 */
    ".word 0x8F08\n"  /* bf/s 0x060081DC */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x62F2\n"  /* mov.l @r15,r2 */
    ".word 0x9304\n"  /* mov.w @(0x8,PC),r3 */
    ".word 0x3237\n"  /* cmp/gt r3,r2 */
    ".word 0x8903\n"  /* bt 0x060081DC */
    ".word 0xA004\n"  /* bra 0x060081E0 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0195\n"  /* mov.w r9,@(r0,r1) */
    ".word 0x0131\n"  /* .word 0x0131 */
    ".word 0xAED0\n"  /* bra 0x06007F80 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F24\n"  /* add #36,r15 */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".size _FUN_06007E08, .-_FUN_06007E08\n"
);

/* FUN_060033E6: moved to render_setup.c */
extern void FUN_060053ac(int, int, int);
extern void FUN_060053ac(int, int, int);
void FUN_060053AC(int r4, int r5, int r6) { FUN_060053ac(r4, r5, r6); }
__asm__(
    ".balign 4\n"
    ".global _FUN_060055BC\n"
    ".type _FUN_060055BC, @function\n"
    ".global _perspective_project\n"
    "_FUN_060055BC:\n"
    "_perspective_project:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FCC\n"  /* add #-52,r15 */
    ".word 0xD932\n"  /* mov.l @(0xC8,PC),r9  {[0x06005698] = 0x06063EEC} */
    ".word 0xDA32\n"  /* mov.l @(0xC8,PC),r10  {[0x0600569C] = 0x06063E08} */
    ".word 0xDD33\n"  /* mov.l @(0xCC,PC),r13  {[0x060056A0] = 0x06063E04} */
    ".word 0x63A1\n"  /* mov.w @r10,r3 */
    ".word 0x6DD2\n"  /* mov.l @r13,r13 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x6ED3\n"  /* mov r13,r14 */
    ".word 0x7E20\n"  /* add #32,r14 */
    ".word 0x62E1\n"  /* mov.w @r14,r2 */
    ".word 0x3323\n"  /* cmp/ge r2,r3 */
    ".word 0x8B0C\n"  /* bf 0x060055FE */
    ".word 0x60E1\n"  /* mov.w @r14,r0 */
    ".word 0x88FF\n"  /* cmp/eq #-1,r0 */
    ".word 0x8B00\n"  /* bf 0x060055EC */
    ".word 0x5EE1\n"  /* mov.l @(0x4,r14),r14 */
    ".word 0x6DE3\n"  /* mov r14,r13 */
    ".word 0xD32C\n"  /* mov.l @(0xB0,PC),r3  {[0x060056A0] = 0x06063E04} */
    ".word 0x23D2\n"  /* mov.l r13,@r3 */
    ".word 0x62D1\n"  /* mov.w @r13,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8F02\n"  /* bf/s 0x060055FE */
    ".word 0x7E20\n"  /* add #32,r14 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2A31\n"  /* mov.w r3,@r10 */
    ".word 0x65E1\n"  /* mov.w @r14,r5 */
    ".word 0x63D1\n"  /* mov.w @r13,r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x3538\n"  /* sub r3,r5 */
    ".word 0x64A1\n"  /* mov.w @r10,r4 */
    ".word 0xD226\n"  /* mov.l @(0x98,PC),r2  {[0x060056A4] = 0x0602755C} */
    ".word 0x4528\n"  /* shll16 r5 */
    ".word 0x644D\n"  /* extu.w r4,r4 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x4428\n"  /* shll16 r4 */
    ".word 0x6C03\n"  /* mov r0,r12 */
    ".word 0xE500\n"  /* mov #0,r5 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xBF8F\n"  /* bsr 0x0600553C */
    ".word 0x7402\n"  /* add #2,r4 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0xD821\n"  /* mov.l @(0x84,PC),r8  {[0x060056A8] = 0x06026FFC} */
    ".word 0x7528\n"  /* add #40,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0xBF84\n"  /* bsr 0x0600553C */
    ".word 0x7402\n"  /* add #2,r4 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x751C\n"  /* add #28,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x7408\n"  /* add #8,r4 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0xDB1A\n"  /* mov.l @(0x68,PC),r11  {[0x060056AC] = 0x06027552} */
    ".word 0x52FA\n"  /* mov.l @(0x28,r15),r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x54F7\n"  /* mov.l @(0x1C,r15),r4 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x1F04\n"  /* mov.l r0,@(0x10,r15) */
    ".word 0x53FB\n"  /* mov.l @(0x2C,r15),r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x54F8\n"  /* mov.l @(0x20,r15),r4 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x1F05\n"  /* mov.l r0,@(0x14,r15) */
    ".word 0x53FC\n"  /* mov.l @(0x30,r15),r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x54F9\n"  /* mov.l @(0x24,r15),r4 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x65E3\n"  /* mov r14,r5 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x7502\n"  /* add #2,r5 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x1F06\n"  /* mov.l r0,@(0x18,r15) */
    ".word 0xBF5D\n"  /* bsr 0x0600553C */
    ".word 0x7403\n"  /* add #3,r4 */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64D3\n"  /* mov r13,r4 */
    ".word 0x7528\n"  /* add #40,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x7414\n"  /* add #20,r4 */
    ".word 0x65D3\n"  /* mov r13,r5 */
    ".word 0x7503\n"  /* add #3,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xA00D\n"  /* bra 0x060056B0 */
    ".word 0x7403\n"  /* add #3,r4 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E08\n"  /* sub r0,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3E04\n"  /* .word 0x3E04 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x755C\n"  /* add #92,r5 */
    ".word 0x0602\n"  /* stc sr,r6  -> FUN_06026FFC */
    ".word 0x6FFC\n"  /* extu.b r15,r15 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x7552\n"  /* add #82,r5 */
    ".word 0xBF44\n"  /* bsr 0x0600553C */
    ".word 0x0009\n"  /* nop */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x751C\n"  /* add #28,r5 */
    ".word 0x480B\n"  /* jsr @r8 */
    ".word 0x7414\n"  /* add #20,r4 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x52FA\n"  /* mov.l @(0x28,r15),r2 */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6323\n"  /* mov r2,r3 */
    ".word 0x54F7\n"  /* mov.l @(0x1C,r15),r4 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x1F01\n"  /* mov.l r0,@(0x4,r15) */
    ".word 0x53FB\n"  /* mov.l @(0x2C,r15),r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x54F8\n"  /* mov.l @(0x20,r15),r4 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x65C3\n"  /* mov r12,r5 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x1F02\n"  /* mov.l r0,@(0x8,r15) */
    ".word 0x53FC\n"  /* mov.l @(0x30,r15),r3 */
    ".word 0x2F32\n"  /* mov.l r3,@r15 */
    ".word 0x54F9\n"  /* mov.l @(0x24,r15),r4 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0x3438\n"  /* sub r3,r4 */
    ".word 0x63F2\n"  /* mov.l @r15,r3 */
    ".word 0x303C\n"  /* add r3,r0 */
    ".word 0x1F03\n"  /* mov.l r0,@(0xC,r15) */
    ".word 0x63A1\n"  /* mov.w @r10,r3 */
    ".word 0x7301\n"  /* add #1,r3 */
    ".word 0x2A31\n"  /* mov.w r3,@r10 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x06005764] = 0x06026E0C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x65F3\n"  /* mov r15,r5 */
    ".word 0x64F3\n"  /* mov r15,r4 */
    ".word 0xD618\n"  /* mov.l @(0x60,PC),r6  {[0x06005768] = 0x06063EEC} */
    ".word 0x7504\n"  /* add #4,r5 */
    ".word 0xBDC3\n"  /* bsr 0x06005294 */
    ".word 0x7410\n"  /* add #16,r4 */
    ".word 0xD017\n"  /* mov.l @(0x5C,PC),r0  {[0x0600576C] = 0x06078663} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8906\n"  /* bt 0x06005724 */
    ".word 0x5E91\n"  /* mov.l @(0x4,r9),r14 */
    ".word 0x4E18\n"  /* shll8 r14 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x06005770] = 0x01A00000} */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0xA006\n"  /* bra 0x06005730 */
    ".word 0x0009\n"  /* nop */
    ".word 0x5E91\n"  /* mov.l @(0x4,r9),r14 */
    ".word 0x4E18\n"  /* shll8 r14 */
    ".word 0x4E08\n"  /* shll2 r14 */
    ".word 0x6EEB\n"  /* neg r14,r14 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06005774] = 0xFFA00000} */
    ".word 0x3E3C\n"  /* add r3,r14 */
    ".word 0xD311\n"  /* mov.l @(0x44,PC),r3  {[0x06005778] = 0x0603850C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0xE404\n"  /* mov #4,r4 */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x6592\n"  /* mov.l @r9,r5 */
    ".word 0xD310\n"  /* mov.l @(0x40,PC),r3  {[0x0600577C] = 0x003A0000} */
    ".word 0x4518\n"  /* shll8 r5 */
    ".word 0x4500\n"  /* shll r5 */
    ".word 0x655B\n"  /* neg r5,r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06005780] = 0x0603853C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x06005784] = 0x06038520} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0x7F34\n"  /* add #52,r15 */
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
    ".word 0x6E0C\n"  /* extu.b r0,r14 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3EEC\n"  /* add r14,r14 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8663\n"  /* .word 0x8663 */
    ".word 0x01A0\n"  /* .word 0x01A0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0xFFA0\n"  /* .word 0xFFA0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x850C\n"  /* mov.w @(0x18,r0),r0 */
    ".word 0x003A\n"  /* .word 0x003A */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_0603853C */
    ".word 0x853C\n"  /* mov.w @(0x18,r3),r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x8520\n"  /* mov.w @(0x0,r2),r0 */
    ".size _FUN_060055BC, .-_FUN_060055BC\n"
);
extern void FUN_060078dc(void);
extern void FUN_060078dc(void);
void FUN_060078DC(void) { FUN_060078dc(); }
/* FUN_0600A084: moved to render_setup.c */
/* FUN_0600A0C0: moved to vdp_state_init.c */
/* FUN_0600A33C: moved to game_state_utils.c */
/* FUN_0600A914: moved to collision.c */
extern void FUN_0600bb94(void);
extern void FUN_0600bb94(void);
void FUN_0600BB94(void) { FUN_0600bb94(); }
extern void FUN_0600bffc(void);
extern void FUN_0600bffc(void);
void FUN_0600BFFC(void) { FUN_0600bffc(); }
/* FUN_0600C302: moved to car_iteration.c */
/* FUN_0600DE54: moved to car_iteration.c */
/* FUN_0600DE70: moved to car_iteration.c */
/* FUN_0600EB14: moved to race_init.c */
extern void FUN_06010a5c(int);
extern void FUN_06010a5c(int);
void FUN_06010A5C(int arg) { FUN_06010a5c(arg); }
extern void FUN_060120c8(void);
extern void FUN_060120c8(void);
void FUN_060120C8(void) { FUN_060120c8(); }
extern void FUN_060121a8(void);
extern void FUN_060121a8(void);
void FUN_060121A8(void) { FUN_060121a8(); }
extern void FUN_06018a3c(void);
extern void FUN_06018a3c(void);
void FUN_06018A3C(void) { FUN_06018a3c(); }
/* FUN_06018E70: moved to cd_command.c */
/* FUN_060192CA: moved to batch_subsystem_18.c as sound_channels_stop */
__asm__(
    ".balign 4\n"
    ".global _FUN_0601D5F4\n"
    ".type _FUN_0601D5F4, @function\n"
    ".global _sound_cmd_dispatch\n"
    "_FUN_0601D5F4:\n"
    "_sound_cmd_dispatch:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD01D\n"  /* mov.l @(0x74,PC),r0  {[0x0601D670] = 0x06086050} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8F55\n"  /* bf/s 0x0601D6AC */
    ".word 0x6E53\n"  /* mov r5,r14 */
    ".word 0xD51C\n"  /* mov.l @(0x70,PC),r5  {[0x0601D674] = 0xA0000000} */
    ".word 0xA044\n"  /* bra 0x0601D690 */
    ".word 0x6043\n"  /* mov r4,r0 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x2259\n"  /* and r5,r2 */
    ".word 0x3250\n"  /* cmp/eq r5,r2 */
    ".word 0x8B4D\n"  /* bf 0x0601D6AC */
    ".word 0xB2B8\n"  /* bsr 0x0601DB84 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601D678] = 0x25A02C20} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601D67C] = 0x0608604C} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xA046\n"  /* bra 0x0601D6AC */
    ".word 0x0009\n"  /* nop */
    ".word 0x4E18\n"  /* shll8 r14 */
    ".word 0xD417\n"  /* mov.l @(0x5C,PC),r4  {[0x0601D680] = 0xA07000FF} */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA054\n"  /* bra 0x0601D6D4 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4E18\n"  /* shll8 r14 */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x0601D684] = 0xA17000FF} */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA060\n"  /* bra 0x0601D6F8 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4E18\n"  /* shll8 r14 */
    ".word 0xD413\n"  /* mov.l @(0x4C,PC),r4  {[0x0601D688] = 0xA27000FF} */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA074\n"  /* bra 0x0601D72C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x64E3\n"  /* mov r14,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA096\n"  /* bra 0x0601D778 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4E18\n"  /* shll8 r14 */
    ".word 0xD40F\n"  /* mov.l @(0x3C,PC),r4  {[0x0601D68C] = 0xA37000FF} */
    ".word 0x34EC\n"  /* add r14,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0xA0A2\n"  /* bra 0x0601D79C */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x62E3\n"  /* mov r14,r2 */
    ".word 0x2259\n"  /* and r5,r2 */
    ".word 0x3250\n"  /* cmp/eq r5,r2 */
    ".word 0x8B25\n"  /* bf 0x0601D6AC */
    ".word 0xB290\n"  /* bsr 0x0601DB84 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0601D678] = 0x25A02C20} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xD304\n"  /* mov.l @(0x10,PC),r3  {[0x0601D67C] = 0x0608604C} */
    ".word 0x23E2\n"  /* mov.l r14,@r3 */
    ".word 0xA01E\n"  /* bra 0x0601D6AC */
    ".word 0x0009\n"  /* nop */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0xA000\n"  /* bra 0x0601D678 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x604C\n"  /* extu.b r4,r0 */
    ".word 0xA070\n"  /* bra 0x0601D764 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xA170\n"  /* bra 0x0601D968 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xA270\n"  /* bra 0x0601DB6C */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0xA370\n"  /* bra 0x0601DD70 */
    ".word 0x00FF\n"  /* mac.l @r15+,@r0+ */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x89B9\n"  /* bt 0x0601D608 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89C3\n"  /* bt 0x0601D620 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89C7\n"  /* bt 0x0601D62C */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x89CB\n"  /* bt 0x0601D638 */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x89CF\n"  /* bt 0x0601D644 */
    ".word 0x8805\n"  /* cmp/eq #5,r0 */
    ".word 0x89D1\n"  /* bt 0x0601D64C */
    ".word 0x880F\n"  /* cmp/eq #15,r0 */
    ".word 0x89D5\n"  /* bt 0x0601D658 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601D5F4, .-_FUN_0601D5F4\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601D9B0\n"
    ".type _FUN_0601D9B0, @function\n"
    "_FUN_0601D9B0:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0xEC28\n"  /* mov #40,r12 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xDE21\n"  /* mov.l @(0x84,PC),r14  {[0x0601DA44] = 0x06086054} */
    ".word 0xD022\n"  /* mov.l @(0x88,PC),r0  {[0x0601DA48] = 0x06085FF4} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8D02\n"  /* bt/s 0x0601D9CC */
    ".word 0xED00\n"  /* mov #0,r13 */
    ".word 0xA0C5\n"  /* bra 0x0601DB56 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD21F\n"  /* mov.l @(0x7C,PC),r2  {[0x0601DA4C] = 0x06086056} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x8B01\n"  /* bf 0x0601D9DA */
    ".word 0xA0A3\n"  /* bra 0x0601DB20 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD01D\n"  /* mov.l @(0x74,PC),r0  {[0x0601DA50] = 0x0608605A} */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B01\n"  /* bf 0x0601D9E8 */
    ".word 0xA09C\n"  /* bra 0x0601DB20 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD018\n"  /* mov.l @(0x60,PC),r0  {[0x0601DA4C] = 0x06086056} */
    ".word 0xD318\n"  /* mov.l @(0x60,PC),r3  {[0x0601DA4C] = 0x06086056} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8901\n"  /* bt 0x0601D9FE */
    ".word 0xA091\n"  /* bra 0x0601DB20 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD515\n"  /* mov.l @(0x54,PC),r5  {[0x0601DA54] = 0x0607EAD8} */
    ".word 0xD415\n"  /* mov.l @(0x54,PC),r4  {[0x0601DA58] = 0x06086058} */
    ".word 0xDB16\n"  /* mov.l @(0x58,PC),r11  {[0x0601DA5C] = 0xAE112BFF} */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8F55\n"  /* bf/s 0x0601DAB6 */
    ".word 0xE664\n"  /* mov #100,r6 */
    ".word 0x6041\n"  /* mov.w @r4,r0 */
    ".word 0xA044\n"  /* bra 0x0601DA9A */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0xD30E\n"  /* mov.l @(0x38,PC),r3  {[0x0601DA4C] = 0x06086056} */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xD512\n"  /* mov.l @(0x48,PC),r5  {[0x0601DA60] = 0xAE1129FF} */
    ".word 0xBDEC\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA005\n"  /* bra 0x0601DA2A */
    ".word 0x0009\n"  /* nop */
    ".word 0xD30A\n"  /* mov.l @(0x28,PC),r3  {[0x0601DA4C] = 0x06086056} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xBDE5\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA022\n"  /* bra 0x0601DA72 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD307\n"  /* mov.l @(0x1C,PC),r3  {[0x0601DA4C] = 0x06086056} */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x0601DA64] = 0xAE112AFF} */
    ".word 0xBDDE\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA02A\n"  /* bra 0x0601DA90 */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0x04B0\n"  /* .word 0x04B0 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0xAE11\n"  /* bra 0x0601D666 */
    ".word 0x27FF\n"  /* muls.w r15,r7 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6054\n"  /* mov.b @r5+,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x5FF4\n"  /* mov.l @(0x10,r15),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6056\n"  /* mov.l @r5+,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x605A\n"  /* .word 0x605A */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6058\n"  /* swap.b r5,r0 */
    ".word 0xAE11\n"  /* bra 0x0601D682 */
    ".word 0x2BFF\n"  /* muls.w r15,r11 */
    ".word 0xAE11\n"  /* bra 0x0601D686 */
    ".word 0x29FF\n"  /* muls.w r15,r9 */
    ".word 0xAE11\n"  /* bra 0x0601D68A */
    ".word 0x2AFF\n"  /* muls.w r15,r10 */
    ".word 0xD33E\n"  /* mov.l @(0xF8,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xBDC1\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA00D\n"  /* bra 0x0601DA90 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0xD33B\n"  /* mov.l @(0xEC,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xD53B\n"  /* mov.l @(0xEC,PC),r5  {[0x0601DB68] = 0xAE112CFF} */
    ".word 0xBDBA\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA006\n"  /* bra 0x0601DA90 */
    ".word 0xE214\n"  /* mov #20,r2 */
    ".word 0xD337\n"  /* mov.l @(0xDC,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xBDB3\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0xA046\n"  /* bra 0x0601DB20 */
    ".word 0x2E21\n"  /* mov.w r2,@r14 */
    ".word 0x666D\n"  /* extu.w r6,r6 */
    ".word 0xA043\n"  /* bra 0x0601DB20 */
    ".word 0x2E61\n"  /* mov.w r6,@r14 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89B9\n"  /* bt 0x0601DA12 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x89BE\n"  /* bt 0x0601DA20 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x89C3\n"  /* bt 0x0601DA2E */
    ".word 0x8804\n"  /* cmp/eq #4,r0 */
    ".word 0x89DE\n"  /* bt 0x0601DA68 */
    ".word 0x8805\n"  /* cmp/eq #5,r0 */
    ".word 0x89E3\n"  /* bt 0x0601DA76 */
    ".word 0x8806\n"  /* cmp/eq #6,r0 */
    ".word 0x89E8\n"  /* bt 0x0601DA84 */
    ".word 0xAFEF\n"  /* bra 0x0601DA94 */
    ".word 0x0009\n"  /* nop */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B23\n"  /* bf 0x0601DB04 */
    ".word 0x6041\n"  /* mov.w @r4,r0 */
    ".word 0xA019\n"  /* bra 0x0601DAF4 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0xD327\n"  /* mov.l @(0x9C,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xBD94\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA00C\n"  /* bra 0x0601DAE8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD324\n"  /* mov.l @(0x90,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x65B3\n"  /* mov r11,r5 */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xBD8D\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0xA005\n"  /* bra 0x0601DAE8 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD321\n"  /* mov.l @(0x84,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xD522\n"  /* mov.l @(0x88,PC),r5  {[0x0601DB6C] = 0xAE112DFF} */
    ".word 0xBD86\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0xA019\n"  /* bra 0x0601DB20 */
    ".word 0x2E21\n"  /* mov.w r2,@r14 */
    ".word 0x666D\n"  /* extu.w r6,r6 */
    ".word 0xA016\n"  /* bra 0x0601DB20 */
    ".word 0x2E61\n"  /* mov.w r6,@r14 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x89E4\n"  /* bt 0x0601DAC2 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x89E9\n"  /* bt 0x0601DAD0 */
    ".word 0x8806\n"  /* cmp/eq #6,r0 */
    ".word 0x89EE\n"  /* bt 0x0601DADE */
    ".word 0xAFF5\n"  /* bra 0x0601DAEE */
    ".word 0x0009\n"  /* nop */
    ".word 0x6052\n"  /* mov.l @r5,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B0A\n"  /* bf 0x0601DB20 */
    ".word 0x6041\n"  /* mov.w @r4,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8808\n"  /* cmp/eq #8,r0 */
    ".word 0x8B06\n"  /* bf 0x0601DB20 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0xD516\n"  /* mov.l @(0x58,PC),r5  {[0x0601DB70] = 0xAE112FFF} */
    ".word 0xBD6C\n"  /* bsr 0x0601D5F4 */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x62CD\n"  /* extu.w r12,r2 */
    ".word 0x2E21\n"  /* mov.w r2,@r14 */
    ".word 0xD414\n"  /* mov.l @(0x50,PC),r4  {[0x0601DB74] = 0x0608605A} */
    ".word 0x6040\n"  /* mov.b @r4,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B15\n"  /* bf 0x0601DB56 */
    ".word 0xD00E\n"  /* mov.l @(0x38,PC),r0  {[0x0601DB64] = 0x06086056} */
    ".word 0xD30D\n"  /* mov.l @(0x34,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x6001\n"  /* mov.w @r0,r0 */
    ".word 0x70FF\n"  /* add #-1,r0 */
    ".word 0x2301\n"  /* mov.w r0,@r3 */
    ".word 0x7001\n"  /* add #1,r0 */
    ".word 0x600D\n"  /* extu.w r0,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B0C\n"  /* bf 0x0601DB56 */
    ".word 0x63DC\n"  /* extu.b r13,r3 */
    ".word 0x2430\n"  /* mov.b r3,@r4 */
    ".word 0xD308\n"  /* mov.l @(0x20,PC),r3  {[0x0601DB64] = 0x06086056} */
    ".word 0x23D1\n"  /* mov.w r13,@r3 */
    ".word 0x2EC1\n"  /* mov.w r12,@r14 */
    ".word 0xD50C\n"  /* mov.l @(0x30,PC),r5  {[0x0601DB78] = 0xAE1120FF} */
    ".word 0xE400\n"  /* mov #0,r4 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xAD4F\n"  /* bra 0x0601D5F4 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6056\n"  /* mov.l @r5+,r0 */
    ".word 0xAE11\n"  /* bra 0x0601D78E */
    ".word 0x2CFF\n"  /* muls.w r15,r12 */
    ".word 0xAE11\n"  /* bra 0x0601D792 */
    ".word 0x2DFF\n"  /* muls.w r15,r13 */
    ".word 0xAE11\n"  /* bra 0x0601D796 */
    ".word 0x2FFF\n"  /* muls.w r15,r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x605A\n"  /* .word 0x605A */
    ".word 0xAE11\n"  /* bra 0x0601D79E */
    ".word 0x20FF\n"  /* muls.w r15,r0 */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".global _FUN_0601db84\n"
    "_FUN_0601db84:\n"
    ".word 0xD706\n"  /* mov.l @(0x18,PC),r7  {[0x0601DBA0] = 0x06086050} */
    ".word 0xD607\n"  /* mov.l @(0x1C,PC),r6  {[0x0601DBA4] = 0x25A02C20} */
    ".word 0xE501\n"  /* mov #1,r5 */
    ".word 0xD407\n"  /* mov.l @(0x1C,PC),r4  {[0x0601DBA8] = 0x000186A0} */
    ".word 0x4410\n"  /* dt r4 */
    ".word 0x8B01\n"  /* bf 0x0601DB94 */
    ".word 0xA003\n"  /* bra 0x0601DB9A */
    ".word 0x2752\n"  /* mov.l r5,@r7 */
    ".word 0x6062\n"  /* mov.l @r6,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8BF8\n"  /* bf 0x0601DB8C */
    ".word 0x000B\n"  /* rts */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6050\n"  /* mov.b @r5,r0 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2C20\n"  /* mov.b r2,@r12 */
    ".word 0x0001\n"  /* .word 0x0001 */
    ".word 0x86A0\n"  /* .word 0x86A0 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0xD201\n"  /* mov.l @(0x4,PC),r2  {[0x0601DBB4] = 0x25A02D97} */
    ".word 0x000B\n"  /* rts */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x25A0\n"  /* mov.b r10,@r5 */
    ".word 0x2D97\n"  /* .word 0x2D97 */
    ".size _FUN_0601D9B0, .-_FUN_0601D9B0\n"
);
__asm__(
    ".balign 4\n"
    ".global _FUN_0601DBB8\n"
    ".type _FUN_0601DBB8, @function\n"
    ".global _replay_camera_controller\n"
    "_FUN_0601DBB8:\n"
    "_replay_camera_controller:\n"
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
    ".word 0xD810\n"  /* mov.l @(0x40,PC),r8  {[0x0601DC10] = 0x06078900} */
    ".word 0xD911\n"  /* mov.l @(0x44,PC),r9  {[0x0601DC14] = 0x00009000} */
    ".word 0xDA11\n"  /* mov.l @(0x44,PC),r10  {[0x0601DC18] = 0x0608706C} */
    ".word 0xDB12\n"  /* mov.l @(0x48,PC),r11  {[0x0601DC1C] = 0x06028400} */
    ".word 0xDC12\n"  /* mov.l @(0x48,PC),r12  {[0x0601DC20] = 0x06087074} */
    ".word 0xDD13\n"  /* mov.l @(0x4C,PC),r13  {[0x0601DC24] = 0x06087068} */
    ".word 0xDE13\n"  /* mov.l @(0x4C,PC),r14  {[0x0601DC28] = 0x06087070} */
    ".word 0xD014\n"  /* mov.l @(0x50,PC),r0  {[0x0601DC2C] = 0x060786AC} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x890A\n"  /* bt 0x0601DBF8 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA0FF\n"  /* bra 0x0601DDF6 */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xD30B\n"  /* mov.l @(0x2C,PC),r3  {[0x0601DC30] = 0x0607EBF4} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8914\n"  /* bt 0x0601DC34 */
    ".word 0xA026\n"  /* bra 0x0601DC5A */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x8900\n"  /* bt 0x0601DC16 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x9000\n"  /* mov.w @(0x0,PC),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x706C\n"  /* add #108,r0 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8400\n"  /* mov.b @(0x0,r0),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7074\n"  /* add #116,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7068\n"  /* add #104,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x7070\n"  /* add #112,r0 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86AC\n"  /* .word 0x86AC */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEBF4\n"  /* mov #-12,r11 */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0xD33F\n"  /* mov.l @(0xFC,PC),r3  {[0x0601DD3C] = 0x0607EABC} */
    ".word 0x6332\n"  /* mov.l @r3,r3 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0x6303\n"  /* mov r0,r3 */
    ".word 0x6083\n"  /* mov r8,r0 */
    ".word 0x8403\n"  /* mov.b @(0x3,r0),r0 */
    ".word 0xC808\n"  /* tst #0x08,r0 */
    ".word 0x0229\n"  /* .word 0x0229 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x622B\n"  /* neg r2,r2 */
    ".word 0x2228\n"  /* tst r2,r2 */
    ".word 0x0029\n"  /* .word 0x0029 */
    ".word 0x2039\n"  /* and r3,r0 */
    ".word 0xC801\n"  /* tst #0x01,r0 */
    ".word 0x8932\n"  /* bt 0x0601DCC0 */
    ".word 0xE301\n"  /* mov #1,r3 */
    ".word 0x2D30\n"  /* mov.b r3,@r13 */
    ".word 0x9267\n"  /* mov.w @(0xCE,PC),r2 */
    ".word 0xD337\n"  /* mov.l @(0xDC,PC),r3  {[0x0601DD40] = 0x0608706A} */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0xD337\n"  /* mov.l @(0xDC,PC),r3  {[0x0601DD44] = 0x0605DFED} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0xE303\n"  /* mov #3,r3 */
    ".word 0xD236\n"  /* mov.l @(0xD8,PC),r2  {[0x0601DD48] = 0x060786A0} */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x2E22\n"  /* mov.l r2,@r14 */
    ".word 0xD436\n"  /* mov.l @(0xD8,PC),r4  {[0x0601DD4C] = 0x0605DDB4} */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0xD036\n"  /* mov.l @(0xD8,PC),r0  {[0x0601DD50] = 0x0607EAD8} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B02\n"  /* bf 0x0601DC84 */
    ".word 0xD435\n"  /* mov.l @(0xD4,PC),r4  {[0x0601DD54] = 0x0605DDD4} */
    ".word 0xE306\n"  /* mov #6,r3 */
    ".word 0x2C32\n"  /* mov.l r3,@r12 */
    ".word 0x9055\n"  /* mov.w @(0xAA,PC),r0 */
    ".word 0xD334\n"  /* mov.l @(0xD0,PC),r3  {[0x0601DD58] = 0x060350B0} */
    ".word 0x018E\n"  /* mov.l @(r0,r8),r1 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0xE309\n"  /* mov #9,r3 */
    ".word 0x024E\n"  /* mov.l @(r0,r4),r2 */
    ".word 0x2A22\n"  /* mov.l r2,@r10 */
    ".word 0xD230\n"  /* mov.l @(0xC0,PC),r2  {[0x0601DD5C] = 0x0608707C} */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x62A2\n"  /* mov.l @r10,r2 */
    ".word 0x3322\n"  /* cmp/hs r2,r3 */
    ".word 0x890D\n"  /* bt 0x0601DCC0 */
    ".word 0xE20A\n"  /* mov #10,r2 */
    ".word 0xD32D\n"  /* mov.l @(0xB4,PC),r3  {[0x0601DD5C] = 0x0608707C} */
    ".word 0x2320\n"  /* mov.b r2,@r3 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x2A22\n"  /* mov.l r2,@r10 */
    ".word 0x9040\n"  /* mov.w @(0x80,PC),r0 */
    ".word 0xD329\n"  /* mov.l @(0xA4,PC),r3  {[0x0601DD58] = 0x060350B0} */
    ".word 0x018E\n"  /* mov.l @(r0,r8),r1 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0x4008\n"  /* shll2 r0 */
    ".word 0x62E2\n"  /* mov.l @r14,r2 */
    ".word 0x0426\n"  /* mov.l r2,@(r0,r4) */
    ".word 0x60D0\n"  /* mov.b @r13,r0 */
    ".word 0x600C\n"  /* extu.b r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B01\n"  /* bf 0x0601DCCC */
    ".word 0xA08A\n"  /* bra 0x0601DDE0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31D\n"  /* mov.l @(0x74,PC),r3  {[0x0601DD44] = 0x0605DFED} */
    ".word 0xD21D\n"  /* mov.l @(0x74,PC),r2  {[0x0601DD44] = 0x0605DFED} */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x7330\n"  /* add #48,r3 */
    ".word 0x2230\n"  /* mov.b r3,@r2 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x912C\n"  /* mov.w @(0x58,PC),r1 */
    ".word 0x3313\n"  /* cmp/ge r1,r3 */
    ".word 0x8969\n"  /* bt 0x0601DDB2 */
    ".word 0xD220\n"  /* mov.l @(0x80,PC),r2  {[0x0601DD60] = 0x060639F8} */
    ".word 0x1F21\n"  /* mov.l r2,@(0x4,r15) */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0x9627\n"  /* mov.w @(0x4E,PC),r6 */
    ".word 0x9024\n"  /* mov.w @(0x48,PC),r0 */
    ".word 0xD31B\n"  /* mov.l @(0x6C,PC),r3  {[0x0601DD58] = 0x060350B0} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x018E\n"  /* mov.l @(r0,r8),r1 */
    ".word 0x379C\n"  /* add r9,r7 */
    ".word 0x71FF\n"  /* add #-1,r1 */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x60C2\n"  /* mov.l @r12,r0 */
    ".word 0xE50E\n"  /* mov #14,r5 */
    ".word 0xD31A\n"  /* mov.l @(0x68,PC),r3  {[0x0601DD64] = 0x0605E008} */
    ".word 0x0057\n"  /* mul.l r5,r0 */
    ".word 0x051A\n"  /* sts macl,r5 */
    ".word 0x353C\n"  /* add r3,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xD218\n"  /* mov.l @(0x60,PC),r2  {[0x0601DD68] = 0x060639E0} */
    ".word 0x2F22\n"  /* mov.l r2,@r15 */
    ".word 0x6723\n"  /* mov r2,r7 */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0601DD5C] = 0x0608707C} */
    ".word 0x9614\n"  /* mov.w @(0x28,PC),r6 */
    ".word 0xD517\n"  /* mov.l @(0x5C,PC),r5  {[0x0601DD6C] = 0x060639D8} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x6330\n"  /* mov.b @r3,r3 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x633C\n"  /* extu.b r3,r3 */
    ".word 0x4318\n"  /* shll8 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x4308\n"  /* shll2 r3 */
    ".word 0x373C\n"  /* add r3,r7 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x67F2\n"  /* mov.l @r15,r7 */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x379C\n"  /* add r9,r7 */
    ".word 0x9606\n"  /* mov.w @(0xC,PC),r6 */
    ".word 0xA020\n"  /* bra 0x0601DD70 */
    ".word 0x0009\n"  /* nop */
    ".word 0x00A0\n"  /* .word 0x00A0 */
    ".word 0x0230\n"  /* .word 0x0230 */
    ".word 0x00C0\n"  /* .word 0x00C0 */
    ".word 0x07C8\n"  /* .word 0x07C8 */
    ".word 0x0842\n"  /* .word 0x0842 */
    ".word 0x0942\n"  /* .word 0x0942 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEABC\n"  /* mov #-68,r10 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x706A\n"  /* add #106,r0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDFED\n"  /* mov.l @(0x3B4,PC),r15  {[0x0601E0FC] = 0x060283E0} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0x86A0\n"  /* .word 0x86A0 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDDB4\n"  /* mov.l @(0x2D0,PC),r13  {[0x0601E020] = 0x000902A8} */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xEAD8\n"  /* mov #-40,r10 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xDDD4\n"  /* mov.l @(0x350,PC),r13  {[0x0601E0A8] = 0x4E0BE408} */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x50B0\n"  /* mov.l @(0x0,r11),r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x707C\n"  /* add #124,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x39F8\n"  /* sub r15,r9 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xE008\n"  /* mov #8,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x39E0\n"  /* cmp/eq r14,r9 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x39D8\n"  /* sub r13,r9 */
    ".word 0x65F2\n"  /* mov.l @r15,r5 */
    ".word 0x6552\n"  /* mov.l @r5,r5 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xB278\n"  /* bsr 0x0601E26C */
    ".word 0x64A2\n"  /* mov.l @r10,r4 */
    ".word 0x57F1\n"  /* mov.l @(0x4,r15),r7 */
    ".word 0x9651\n"  /* mov.w @(0xA2,PC),r6 */
    ".word 0xD52B\n"  /* mov.l @(0xAC,PC),r5  {[0x0601DE30] = 0x0605DFF4} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x379C\n"  /* add r9,r7 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0xD229\n"  /* mov.l @(0xA4,PC),r2  {[0x0601DE34] = 0x000927BF} */
    ".word 0x3322\n"  /* cmp/hs r2,r3 */
    ".word 0x8B04\n"  /* bf 0x0601DD9C */
    ".word 0xD428\n"  /* mov.l @(0xA0,PC),r4  {[0x0601DE34] = 0x000927BF} */
    ".word 0xB26A\n"  /* bsr 0x0601E26C */
    ".word 0x0009\n"  /* nop */
    ".word 0xA002\n"  /* bra 0x0601DDA0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB266\n"  /* bsr 0x0601E26C */
    ".word 0x64E2\n"  /* mov.l @r14,r4 */
    ".word 0xD725\n"  /* mov.l @(0x94,PC),r7  {[0x0601DE38] = 0x060639F8} */
    ".word 0x9640\n"  /* mov.w @(0x80,PC),r6 */
    ".word 0xD522\n"  /* mov.l @(0x88,PC),r5  {[0x0601DE30] = 0x0605DFF4} */
    ".word 0x5771\n"  /* mov.l @(0x4,r7),r7 */
    ".word 0x379C\n"  /* add r9,r7 */
    ".word 0x4B0B\n"  /* jsr @r11 */
    ".word 0xE408\n"  /* mov #8,r4 */
    ".word 0xA002\n"  /* bra 0x0601DDB6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xB020\n"  /* bsr 0x0601DDF6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD221\n"  /* mov.l @(0x84,PC),r2  {[0x0601DE3C] = 0x0608706A} */
    ".word 0xD320\n"  /* mov.l @(0x80,PC),r3  {[0x0601DE3C] = 0x0608706A} */
    ".word 0x6221\n"  /* mov.w @r2,r2 */
    ".word 0x72FF\n"  /* add #-1,r2 */
    ".word 0x2321\n"  /* mov.w r2,@r3 */
    ".word 0x622D\n"  /* extu.w r2,r2 */
    ".word 0x4215\n"  /* cmp/pl r2 */
    ".word 0x890C\n"  /* bt 0x0601DDE0 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2D30\n"  /* mov.b r3,@r13 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0x4F16\n"  /* lds.l @r15+,macl */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0xA00B\n"  /* bra 0x0601DDF6 */
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
    ".size _FUN_0601DBB8, .-_FUN_0601DBB8\n"
);
extern void FUN_0601de50(void);
extern void FUN_0601de50(void);
void FUN_0601DE50(void) { FUN_0601de50(); }
extern void FUN_0601e100(void);
extern void FUN_0601e100(void);
void FUN_0601E100(void) { FUN_0601e100(); }
extern void FUN_0601f784(void);
extern void FUN_0601f784(void);
void FUN_0601F784(void) { FUN_0601f784(); }
extern void FUN_060268b0(int);
extern void FUN_060268b0(int);
void FUN_060268B0(int arg) { FUN_060268b0(arg); }
/* FUN_06026CE0: moved to render_setup.c */
void FUN_060283E0(int r4, int r5, int r6, int r7) { (void)r4; (void)r5; (void)r6; (void)r7; }
extern void FUN_0602eff0(void);
extern void FUN_0602eff0(void);
void FUN_0602EFF0(void) { FUN_0602eff0(); }
extern void FUN_0602f0e8(void);
extern void FUN_0602f0e8(void);
void FUN_0602F0E8(void) { FUN_0602f0e8(); }
extern void FUN_0602f7ea(void);
extern void FUN_0602f7ea(void);
void FUN_0602F7EA(void) { FUN_0602f7ea(); }
void FUN_060302C6(void) { }
extern void FUN_060321c0(void);
extern void FUN_060321c0(void);
void FUN_060321C0(void) { FUN_060321c0(); }
extern void FUN_06033aac(void);
extern void FUN_06033aac(void);
void FUN_06033AAC(void) { FUN_06033aac(); }
extern void FUN_06033bc8(void);
extern void FUN_06033bc8(void);
void FUN_06033BC8(void) { FUN_06033bc8(); }
__asm__(
    ".balign 4\n"
    ".global _FUN_06034900\n"
    ".type _FUN_06034900, @function\n"
    "_FUN_06034900:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0xD106\n"  /* mov.l @(0x18,PC),r1  {[0x06034928] = 0x0607E944} */
    ".word 0x6E12\n"  /* mov.l @r1,r14 */
    ".word 0xD006\n"  /* mov.l @(0x18,PC),r0  {[0x0603492C] = 0x000000B8} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x882C\n"  /* cmp/eq #44,r0 */
    ".word 0x890C\n"  /* bt 0x06034934 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06034930] = 0x000001BC} */
    ".word 0x00EE\n"  /* mov.l @(r0,r14),r0 */
    ".word 0x8828\n"  /* cmp/eq #40,r0 */
    ".word 0x8908\n"  /* bt 0x06034934 */
    ".word 0xA00E\n"  /* bra 0x06034942 */
    ".word 0x0009\n"  /* nop */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0607\n"  /* mul.l r0,r6 */
    ".word 0xE944\n"  /* mov #68,r9 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x00B8\n"  /* .word 0x00B8 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x01BC\n"  /* mov.b @(r0,r11),r1 */
    ".word 0xD410\n"  /* mov.l @(0x40,PC),r4  {[0x06034978] = 0x00000000} */
    ".word 0xD511\n"  /* mov.l @(0x44,PC),r5  {[0x0603497C] = 0xAE1128FF} */
    ".word 0xD011\n"  /* mov.l @(0x44,PC),r0  {[0x06034980] = 0x0601D5F4} */
    ".size _FUN_06034900, .-_FUN_06034900\n"
);

void FUN_060284AE(int r4, int r5, int r6, int r7) { (void)r4; (void)r5; (void)r6; (void)r7; }
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0602834A\n"
    ".type _FUN_0602834A, @function\n"
    "_FUN_0602834A:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD005\n"  /* mov.l @(0x14,PC),r0  {[0x06028364] = 0x06028614} */
    ".word 0x024E\n"  /* mov.l @(r0,r4),r2 */
    ".word 0x6222\n"  /* mov.l @r2,r2 */
    ".word 0x352C\n"  /* add r2,r5 */
    ".word 0xBFB4\n"  /* bsr 0x060282C0 */
    ".word 0x6473\n"  /* mov r7,r4 */
    ".word 0x6103\n"  /* mov r0,r1 */
    ".word 0xE706\n"  /* mov #6,r7 */
    ".word 0x7108\n"  /* add #8,r1 */
    ".word 0xA01B\n"  /* bra 0x06028398 */
    ".word 0xE000\n"  /* mov #0,r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x8614\n"  /* .word 0x8614 */
    ".size _FUN_0602834A, .-_FUN_0602834A\n"
);
extern void FUN_06018ddc(int);
extern void FUN_06018ddc(int);
void FUN_06018DDC(int arg) { FUN_06018ddc(arg); }
extern void FUN_06014a04(void);
extern void FUN_06014a04(void);
void FUN_06014A04(void) { FUN_06014a04(); }
/* FUN_0600DF66: moved to car_iteration.c */
extern void FUN_0601df88(void);
extern void FUN_0601df88(void);
void FUN_0601DF88(void) { FUN_0601df88(); }
/* FUN_0602853E: moved to batch_vdp_cmd_28.c as vdp_display_list_fill */
__asm__(
    ".balign 4\n"
    ".global _FUN_06014884\n"
    ".type _FUN_06014884, @function\n"
    "_FUN_06014884:\n"
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0x2F52\n"  /* mov.l r5,@r15 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x060148E4] = 0x0603850C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x1F61\n"  /* mov.l r6,@(0x4,r15) */
    ".word 0xE600\n"  /* mov #0,r6 */
    ".word 0x55F1\n"  /* mov.l @(0x4,r15),r5 */
    ".word 0xD316\n"  /* mov.l @(0x58,PC),r3  {[0x060148F0] = 0x0603853C} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x64F2\n"  /* mov.l @r15,r4 */
    ".word 0x7F08\n"  /* add #8,r15 */
    ".word 0xD313\n"  /* mov.l @(0x4C,PC),r3  {[0x060148EC] = 0x06038520} */
    ".word 0x432B\n"  /* jmp @r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".size _FUN_06014884, .-_FUN_06014884\n"
);
/* FUN_060032D4: moved to vdp_sprite_init.c */
extern void FUN_0600a294(void);
extern void FUN_0600a294(void);
void FUN_0600A294(void) { FUN_0600a294(); }
/* FUN_0601FD74: moved to mode_dispatch.c */
/* FUN_0600DE40: moved to car_iteration.c */
extern void FUN_06033ea8(void);
extern void FUN_06033ea8(void);
void FUN_06033EA8(void) { FUN_06033ea8(); }
extern void FUN_06014a74(void);
extern void FUN_06014a74(void);
void FUN_06014A74(void) { FUN_06014a74(); }
extern void FUN_06014d2c(void);
extern void FUN_06014d2c(void);
void FUN_06014D2C(void) { FUN_06014d2c(); }
extern void FUN_060190b8(void);
extern void FUN_060190b8(void);
void FUN_060190B8(void) { FUN_060190b8(); }
/* FUN_06012F80: moved to batch_subsystem_12.c as scene_objects_init */
extern void FUN_0601389e(void);
extern void FUN_0601389e(void);
void FUN_0601389E(void) { FUN_0601389e(); }
/* FUN_0600DFD0: moved to visual_physics_update.c */
extern void FUN_0600c218(void);
extern void FUN_0600c218(void);
void FUN_0600C218(void) { FUN_0600c218(); }
/* FUN_0600E060: moved to visual_physics_update.c */
/* FUN_0601F8C0: moved to mode_transition.c */
/* FUN_0601F900: moved to mode_transition.c */
/* FUN_060149E0: moved to render_setup.c */

extern void FUN_0601c978(void);
extern void FUN_0601c978(void);
void FUN_0601C978(void) { FUN_0601c978(); }
__asm__(
    ".balign 4\n"
    ".short 0x0009\n"  /* alignment padding */
    ".global _FUN_0601CAEE\n"
    ".type _FUN_0601CAEE, @function\n"
    "_FUN_0601CAEE:\n"
    ".word 0x2FE6\n"  /* mov.l r14,@-r15 */
    ".word 0x2FD6\n"  /* mov.l r13,@-r15 */
    ".word 0x2FC6\n"  /* mov.l r12,@-r15 */
    ".word 0x2FB6\n"  /* mov.l r11,@-r15 */
    ".word 0x2FA6\n"  /* mov.l r10,@-r15 */
    ".word 0x2F96\n"  /* mov.l r9,@-r15 */
    ".word 0x2F86\n"  /* mov.l r8,@-r15 */
    ".word 0x4F22\n"  /* sts.l pr,@-r15 */
    ".word 0xD81A\n"  /* mov.l @(0x68,PC),r8  {[0x0601CB68] = 0x06086020} */
    ".word 0xD91A\n"  /* mov.l @(0x68,PC),r9  {[0x0601CB6C] = 0x25F00200} */
    ".word 0xDA1B\n"  /* mov.l @(0x6C,PC),r10  {[0x0601CB70] = 0x25F00400} */
    ".word 0xDC1B\n"  /* mov.l @(0x6C,PC),r12  {[0x0601CB74] = 0x0602766C} */
    ".word 0xDD1C\n"  /* mov.l @(0x70,PC),r13  {[0x0601CB78] = 0x06086024} */
    ".word 0xDE1C\n"  /* mov.l @(0x70,PC),r14  {[0x0601CB7C] = 0x0608601C} */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x73FF\n"  /* add #-1,r3 */
    ".word 0x2E32\n"  /* mov.l r3,@r14 */
    ".word 0xD21B\n"  /* mov.l @(0x6C,PC),r2  {[0x0601CB80] = 0x06063D98} */
    ".word 0x6321\n"  /* mov.w @r2,r3 */
    ".word 0x9218\n"  /* mov.w @(0x30,PC),r2 */
    ".word 0x633D\n"  /* extu.w r3,r3 */
    ".word 0x2329\n"  /* and r2,r3 */
    ".word 0x2338\n"  /* tst r3,r3 */
    ".word 0x8D4B\n"  /* bt/s 0x0601CBB6 */
    ".word 0xEB00\n"  /* mov #0,r11 */
    ".word 0xD015\n"  /* mov.l @(0x54,PC),r0  {[0x0601CB78] = 0x06086024} */
    ".word 0x6002\n"  /* mov.l @r0,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8B46\n"  /* bf 0x0601CBB6 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD315\n"  /* mov.l @(0x54,PC),r3  {[0x0601CB84] = 0x060358EC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD214\n"  /* mov.l @(0x50,PC),r2  {[0x0601CB88] = 0x40680000} */
    ".word 0xD314\n"  /* mov.l @(0x50,PC),r3  {[0x0601CB8C] = 0x06035844} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8926\n"  /* bt 0x0601CB90 */
    ".word 0xE201\n"  /* mov #1,r2 */
    ".word 0xA037\n"  /* bra 0x0601CBB6 */
    ".word 0x2D22\n"  /* mov.l r2,@r13 */
    ".word 0x0800\n"  /* .word 0x0800 */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6028\n"  /* swap.b r2,r0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0FFE\n"  /* mov.l @(r0,r15),r15 */
    ".word 0x0603\n"  /* .word 0x0603  -> FUN_06036E90 */
    ".word 0x6E90\n"  /* mov.b @r9,r14 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0xB6D8\n"  /* bsr 0x0601D90E */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x6CE0\n"  /* mov.b @r14,r12 */
    ".word 0x0605\n"  /* mov.w r0,@(r0,r6) */
    ".word 0x9F44\n"  /* mov.w @(0x88,PC),r15 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6020\n"  /* mov.b @r2,r0 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0200\n"  /* .word 0x0200 */
    ".word 0x25F0\n"  /* mov.b r15,@r5 */
    ".word 0x0400\n"  /* .word 0x0400 */
    ".word 0x0602\n"  /* stc sr,r6 */
    ".word 0x766C\n"  /* add #108,r6 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x6024\n"  /* mov.b @r2+,r0 */
    ".word 0x0608\n"  /* .word 0x0608 */
    ".word 0x601C\n"  /* extu.b r1,r0 */
    ".word 0x0606\n"  /* mov.l r0,@(r0,r6) */
    ".word 0x3D98\n"  /* sub r9,r13 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x58EC\n"  /* mov.l @(0x30,r14),r8 */
    ".word 0x4068\n"  /* .word 0x4068 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5844\n"  /* mov.l @(0x10,r4),r8 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD267\n"  /* mov.l @(0x19C,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD366\n"  /* mov.l @(0x198,PC),r3  {[0x0601CD38] = 0x40568000} */
    ".word 0xD266\n"  /* mov.l @(0x198,PC),r2  {[0x0601CD3C] = 0x06035844} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8903\n"  /* bt 0x0601CBB2 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0x2D32\n"  /* mov.l r3,@r13 */
    ".word 0xA002\n"  /* bra 0x0601CBB6 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE203\n"  /* mov #3,r2 */
    ".word 0x2D22\n"  /* mov.l r2,@r13 */
    ".word 0xB2B9\n"  /* bsr 0x0601D12C */
    ".word 0x0009\n"  /* nop */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x2008\n"  /* tst r0,r0 */
    ".word 0x8901\n"  /* bt 0x0601CBC4 */
    ".word 0xA0CA\n"  /* bra 0x0601CD58 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD35A\n"  /* mov.l @(0x168,PC),r3  {[0x0601CD34] = 0x060358EC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD25B\n"  /* mov.l @(0x16C,PC),r2  {[0x0601CD40] = 0x40726000} */
    ".word 0xD359\n"  /* mov.l @(0x164,PC),r3  {[0x0601CD3C] = 0x06035844} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8901\n"  /* bt 0x0601CBE2 */
    ".word 0xA0E1\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD253\n"  /* mov.l @(0x14C,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD354\n"  /* mov.l @(0x150,PC),r3  {[0x0601CD44] = 0x406D4000} */
    ".word 0xD252\n"  /* mov.l @(0x148,PC),r2  {[0x0601CD3C] = 0x06035844} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8903\n"  /* bt 0x0601CC04 */
    ".word 0xB0E0\n"  /* bsr 0x0601CDC0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA0D0\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD24A\n"  /* mov.l @(0x128,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD34C\n"  /* mov.l @(0x130,PC),r3  {[0x0601CD44] = 0x406D4000} */
    ".word 0xD24C\n"  /* mov.l @(0x130,PC),r2  {[0x0601CD48] = 0x06035B34} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B00\n"  /* bf 0x0601CC20 */
    ".word 0x28B2\n"  /* mov.l r11,@r8 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD343\n"  /* mov.l @(0x10C,PC),r3  {[0x0601CD34] = 0x060358EC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD247\n"  /* mov.l @(0x11C,PC),r2  {[0x0601CD4C] = 0x40680000} */
    ".word 0xD342\n"  /* mov.l @(0x108,PC),r3  {[0x0601CD3C] = 0x06035844} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8903\n"  /* bt 0x0601CC42 */
    ".word 0xB15F\n"  /* bsr 0x0601CEFC */
    ".word 0x0009\n"  /* nop */
    ".word 0xA0B1\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD23B\n"  /* mov.l @(0xEC,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD33E\n"  /* mov.l @(0xF8,PC),r3  {[0x0601CD4C] = 0x40680000} */
    ".word 0xD23D\n"  /* mov.l @(0xF4,PC),r2  {[0x0601CD48] = 0x06035B34} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B03\n"  /* bf 0x0601CC64 */
    ".word 0xB1DA\n"  /* bsr 0x0601D014 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA0A0\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD232\n"  /* mov.l @(0xC8,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD337\n"  /* mov.l @(0xDC,PC),r3  {[0x0601CD50] = 0x40608000} */
    ".word 0xD231\n"  /* mov.l @(0xC4,PC),r2  {[0x0601CD3C] = 0x06035844} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8903\n"  /* bt 0x0601CC86 */
    ".word 0xB09F\n"  /* bsr 0x0601CDC0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA08F\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD22A\n"  /* mov.l @(0xA8,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD32E\n"  /* mov.l @(0xB8,PC),r3  {[0x0601CD50] = 0x40608000} */
    ".word 0xD22C\n"  /* mov.l @(0xB0,PC),r2  {[0x0601CD48] = 0x06035B34} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B00\n"  /* bf 0x0601CCA2 */
    ".word 0x28B2\n"  /* mov.l r11,@r8 */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD323\n"  /* mov.l @(0x8C,PC),r3  {[0x0601CD34] = 0x060358EC} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE200\n"  /* mov #0,r2 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0xD221\n"  /* mov.l @(0x84,PC),r2  {[0x0601CD38] = 0x40568000} */
    ".word 0xD322\n"  /* mov.l @(0x88,PC),r3  {[0x0601CD3C] = 0x06035844} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x2F26\n"  /* mov.l r2,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8903\n"  /* bt 0x0601CCC4 */
    ".word 0xB11E\n"  /* bsr 0x0601CEFC */
    ".word 0x0009\n"  /* nop */
    ".word 0xA070\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD21A\n"  /* mov.l @(0x68,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD319\n"  /* mov.l @(0x64,PC),r3  {[0x0601CD38] = 0x40568000} */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0601CD48] = 0x06035B34} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B03\n"  /* bf 0x0601CCE6 */
    ".word 0xB1C9\n"  /* bsr 0x0601D074 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA05F\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD212\n"  /* mov.l @(0x48,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD317\n"  /* mov.l @(0x5C,PC),r3  {[0x0601CD54] = 0x403E0000} */
    ".word 0xD211\n"  /* mov.l @(0x44,PC),r2  {[0x0601CD3C] = 0x06035844} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8903\n"  /* bt 0x0601CD08 */
    ".word 0xB05E\n"  /* bsr 0x0601CDC0 */
    ".word 0x0009\n"  /* nop */
    ".word 0xA04E\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0x60E2\n"  /* mov.l @r14,r0 */
    ".word 0x7FF8\n"  /* add #-8,r15 */
    ".word 0xD209\n"  /* mov.l @(0x24,PC),r2  {[0x0601CD34] = 0x060358EC} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2FF6\n"  /* mov.l r15,@-r15 */
    ".word 0xE300\n"  /* mov #0,r3 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0xD30F\n"  /* mov.l @(0x3C,PC),r3  {[0x0601CD54] = 0x403E0000} */
    ".word 0xD20B\n"  /* mov.l @(0x2C,PC),r2  {[0x0601CD48] = 0x06035B34} */
    ".word 0x420B\n"  /* jsr @r2 */
    ".word 0x2F36\n"  /* mov.l r3,@-r15 */
    ".word 0x8800\n"  /* cmp/eq #0,r0 */
    ".word 0x8B00\n"  /* bf 0x0601CD24 */
    ".word 0x28B2\n"  /* mov.l r11,@r8 */
    ".word 0x63E2\n"  /* mov.l @r14,r3 */
    ".word 0x4315\n"  /* cmp/pl r3 */
    ".word 0x8B39\n"  /* bf 0x0601CD9E */
    ".word 0xB0E7\n"  /* bsr 0x0601CEFC */
    ".word 0x0009\n"  /* nop */
    ".word 0xA039\n"  /* bra 0x0601CDA4 */
    ".word 0x0009\n"  /* nop */
    ".word 0xFFFF\n"  /* .word 0xFFFF */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x58EC\n"  /* mov.l @(0x30,r14),r8 */
    ".word 0x4056\n"  /* .word 0x4056 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5844\n"  /* mov.l @(0x10,r4),r8 */
    ".word 0x4072\n"  /* .word 0x4072 */
    ".word 0x6000\n"  /* mov.b @r0,r0 */
    ".word 0x406D\n"  /* .word 0x406D */
    ".word 0x4000\n"  /* shll r0 */
    ".word 0x0603\n"  /* .word 0x0603 */
    ".word 0x5B34\n"  /* mov.l @(0x10,r3),r11 */
    ".word 0x4068\n"  /* .word 0x4068 */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x4060\n"  /* .word 0x4060 */
    ".word 0x8000\n"  /* mov.b r0,@(0x0,r0) */
    ".word 0x403E\n"  /* .word 0x403E */
    ".word 0x0000\n"  /* .word 0x0000 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x8801\n"  /* cmp/eq #1,r0 */
    ".word 0x8B07\n"  /* bf 0x0601CD6E */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD526\n"  /* mov.l @(0x98,PC),r5  {[0x0601CDFC] = 0x0604880C} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD525\n"  /* mov.l @(0x94,PC),r5  {[0x0601CE00] = 0x0604882C} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x8802\n"  /* cmp/eq #2,r0 */
    ".word 0x8B09\n"  /* bf 0x0601CD88 */
    ".word 0xB14E\n"  /* bsr 0x0601D014 */
    ".word 0x0009\n"  /* nop */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD522\n"  /* mov.l @(0x88,PC),r5  {[0x0601CE04] = 0x0604884C} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD521\n"  /* mov.l @(0x84,PC),r5  {[0x0601CE08] = 0x0604886C} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0x60D2\n"  /* mov.l @r13,r0 */
    ".word 0x8803\n"  /* cmp/eq #3,r0 */
    ".word 0x8B07\n"  /* bf 0x0601CD9E */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD51E\n"  /* mov.l @(0x78,PC),r5  {[0x0601CE0C] = 0x0605D17C} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x6493\n"  /* mov r9,r4 */
    ".word 0xE620\n"  /* mov #32,r6 */
    ".word 0xD51D\n"  /* mov.l @(0x74,PC),r5  {[0x0601CE10] = 0x0605D19C} */
    ".word 0x4C0B\n"  /* jsr @r12 */
    ".word 0x64A3\n"  /* mov r10,r4 */
    ".word 0xE302\n"  /* mov #2,r3 */
    ".word 0xD21C\n"  /* mov.l @(0x70,PC),r2  {[0x0601CE14] = 0x0605AD10} */
    ".word 0x2232\n"  /* mov.l r3,@r2 */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601CE18] = 0x06026CE0} */
    ".word 0x430B\n"  /* jsr @r3 */
    ".word 0x0009\n"  /* nop */
    ".word 0xD31C\n"  /* mov.l @(0x70,PC),r3  {[0x0601CE1C] = 0x06059F44} */
    ".word 0x23B2\n"  /* mov.l r11,@r3 */
    ".word 0x4F26\n"  /* lds.l @r15+,pr */
    ".word 0x68F6\n"  /* mov.l @r15+,r8 */
    ".word 0x69F6\n"  /* mov.l @r15+,r9 */
    ".word 0x6AF6\n"  /* mov.l @r15+,r10 */
    ".word 0x6BF6\n"  /* mov.l @r15+,r11 */
    ".word 0x6CF6\n"  /* mov.l @r15+,r12 */
    ".word 0x6DF6\n"  /* mov.l @r15+,r13 */
    ".word 0x000B\n"  /* rts */
    ".word 0x6EF6\n"  /* mov.l @r15+,r14 */
    ".size _FUN_0601CAEE, .-_FUN_0601CAEE\n"
);
/* FUN_0600A140: moved to vdp1_clear.c */
extern void FUN_0600330a(void);
extern void FUN_0600330a(void);
void FUN_0600330A(void) { FUN_0600330a(); }
extern void FUN_0601ae80(void);
extern void FUN_0601ae80(void);
void FUN_0601AE80(void) { FUN_0601ae80(); }
extern void FUN_0600a1f6(void);
extern void FUN_0600a1f6(void);
void FUN_0600A1F6(void) { FUN_0600a1f6(); }
extern void FUN_0600338c(int, int);
extern void FUN_0600338c(int, int);
void FUN_0600338C(int r4, int r5) { FUN_0600338c(r4, r5); }
/* FUN_0601AEB6: moved to mode_dispatch.c */
extern void FUN_0601d2dc(void);
extern void FUN_0601d2dc(void);
void FUN_0601D2DC(void) { FUN_0601d2dc(); }
/* FUN_0601B074: moved to display_region_init.c */
/* FUN_06018FF8: moved to sound_init.c */
extern void FUN_0601d3c0(void);
extern void FUN_0601d3c0(void);
void FUN_0601D3C0(void) { FUN_0601d3c0(); }
extern void FUN_060193f4(void);
extern void FUN_060193f4(void);
void FUN_060193F4(void) { FUN_060193f4(); }
extern void FUN_060196a4(void);
extern void FUN_060196a4(void);
void FUN_060196A4(void) { FUN_060196a4(); }
extern void FUN_0601950c(void);
extern void FUN_0601950c(void);
void FUN_0601950C(void) { FUN_0601950c(); }
/* FUN_060198E0: moved to subsystem_setup.c */
extern void FUN_06019a48(void);
extern void FUN_06019a48(void);
void FUN_06019A48(void) { FUN_06019a48(); }
extern void FUN_0601b160(void);
extern void FUN_0601b160(void);
void FUN_0601B160(void) { FUN_0601b160(); }
extern int FUN_0601b418(void);
extern int FUN_0601b418(void);
int FUN_0601B418(void) { return FUN_0601b418(); }
extern void FUN_06018fa4(void);
extern void FUN_06018fa4(void);
void FUN_06018FA4(void) { FUN_06018fa4(); }
extern void FUN_0600ec78(void);
extern void FUN_0600ec78(void);
void FUN_0600EC78(void) { FUN_0600ec78(); }
extern void FUN_0600f424(void);
extern void FUN_0600f424(void);
void FUN_0600F424(void) { FUN_0600f424(); }

/* Physics helper stubs -- called by player_physics.c hand translations */
/* FUN_06008640: moved to force_system.c */
/* FUN_0600CD40: moved to lap_counting.c */
/* FUN_0600CA96: moved to course_correction.c */
/* FUN_0600CC38: moved to course_correction.c */
/* FUN_0600C8CC: moved to physics_helpers.c */
/* FUN_0600CF58: moved to collision_response.c */
/* FUN_0600C928: moved to physics_helpers.c */
/* FUN_0600C7D4: moved to physics_helpers.c */
/* FUN_06027358: moved to trig_tables.c */
extern void FUN_06027ede(int, int, int);
extern void FUN_06027ede(int, int, int);
void FUN_06027EDE(int r4, int r5, int r6) { FUN_06027ede(r4, r5, r6); }
/* FUN_06034F78: moved to bitfield_utils.c */
void frame_end_display_commit(void) __attribute__((alias("FUN_060078DC")));
void multi_mode_camera(void) __attribute__((alias("FUN_0600BB94")));
void hud_racing_state_init(void) __attribute__((alias("FUN_0600BFFC")));
void rendering_pass1_camera(void) __attribute__((alias("FUN_0602EFF0")));
void perspective_projection_3d(void) __attribute__((alias("FUN_0602F0E8")));
void sprite_transform(void) __attribute__((alias("FUN_0602F7EA")));
void engine_sound_generator(void) __attribute__((alias("FUN_060302C6")));

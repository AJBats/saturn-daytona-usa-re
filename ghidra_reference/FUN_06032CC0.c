/* FUN_06032CC0  0x06032CC0 */


undefined4 FUN_06032cc0(void)

{
  code *in_r0;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *unaff_r13;
  int unaff_r14;
  
  (*in_r0)();
  (*(code *)PTR_FUN_06032d34)((int)*(short *)(unaff_r14 + DAT_06032d88));
  puVar1 = (undefined4 *)(DAT_06032d8c + unaff_r14);
  *puVar1 = *unaff_r13;
  puVar1[1] = unaff_r13[1];
  puVar1[2] = unaff_r13[2];
  puVar1[3] = unaff_r13[3];
  puVar1[4] = unaff_r13[4];
  puVar1[5] = unaff_r13[5];
  puVar1[6] = unaff_r13[6];
  puVar1[7] = unaff_r13[7];
  puVar1[8] = unaff_r13[8];
  puVar1[9] = unaff_r13[9];
  puVar1[10] = unaff_r13[10];
  puVar1[0xb] = unaff_r13[0xb];
  uVar2 = (*(code *)PTR_FUN_06032d6c)();
  return uVar2;
}


/* FUN_0601E770  0x0601E770 */


undefined4 FUN_0601e770(void)

{
  undefined *puVar1;
  ushort in_r0;
  int iVar2;
  undefined4 uVar3;
  int unaff_r12;
  uint unaff_r14;
  
  puVar1 = PTR_SMPC_SF_0601e7fc;
  iVar2 = (*(code *)PTR_FUN_0601e800)();
  if (0xb < iVar2) {
    *(undefined1 *)(unaff_r12 + 0xb) = 0;
  }
  do {
  } while (((byte)*puVar1 & unaff_r14) == unaff_r14);
  *puVar1 = (char)unaff_r14;
  *PTR_SMPC_COMREG_0601e804 = 0x1a;
  do {
  } while (((byte)*puVar1 & unaff_r14) != 0);
  uVar3 = (**(code **)(*(int *)PTR_PTR_0601e808 + 0x14))
                    (*(undefined2 *)(PTR_DAT_0601e80c + (uint)in_r0 * 0x20 + 0x1c));
  do {
  } while (((byte)*puVar1 & unaff_r14) == unaff_r14);
  *puVar1 = (char)unaff_r14;
  *PTR_SMPC_COMREG_0601e804 = 0x19;
  do {
  } while (((byte)*puVar1 & unaff_r14) != 0);
  return uVar3;
}


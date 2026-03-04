/* FUN_0602E7D4  0x0602E7D4 */


void FUN_0602e7d4(void)

{
  code *in_r0;
  short sVar1;
  uint uVar2;
  uint uVar3;
  int unaff_r8;
  int unaff_r9;
  
  sVar1 = (*in_r0)();
  uVar3 = (uint)DAT_0602e80a;
  uVar2 = *(int *)(unaff_r9 + 0x28) - ((uint)(ushort)-sVar1 | uVar3 << 1);
  if ((int)uVar2 < 1) {
    uVar2 = -uVar2;
  }
  if (*PTR_DAT_0602e810 == '\0') {
    if ((uVar2 & 0xffff) < uVar3) {
LAB_0602e864:
      if (DAT_0602e87c <= unaff_r8) {
        (*(code *)PTR_FUN_0602e8a8)(DAT_0602e8a0,DAT_0602e8a4);
        FUN_0602e78c();
        return;
      }
      (*(code *)PTR_FUN_0602e888)(DAT_0602e880,DAT_0602e884);
      FUN_0602e78c();
      return;
    }
  }
  else if (uVar3 <= (uVar2 & 0xffff)) goto LAB_0602e864;
  if (DAT_0602e834 <= unaff_r8) {
    (*(code *)PTR_FUN_0602e860)(DAT_0602e858,DAT_0602e85c);
    FUN_0602e78c();
    return;
  }
  (*(code *)PTR_FUN_0602e840)(DAT_0602e838,DAT_0602e83c);
  FUN_0602e78c();
  return;
}


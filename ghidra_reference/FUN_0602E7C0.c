/* FUN_0602E7C0  0x0602E7C0 */


void FUN_0602e7c0(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int unaff_r8;
  int unaff_r9;
  int unaff_r10;
  undefined4 in_pr;
  
  sVar1 = (*(code *)PTR_FUN_0602e80c)
                    (*(int *)(unaff_r10 + 0x10) - *(int *)(unaff_r9 + 0x10),
                     *(int *)(unaff_r10 + 0x18) - *(int *)(unaff_r9 + 0x18));
  uVar3 = (uint)DAT_0602e80a;
  uVar4 = (uint)(ushort)-sVar1 | uVar3 << 1;
  uVar2 = *(int *)(unaff_r9 + 0x28) - uVar4;
  if ((int)uVar2 < 1) {
    uVar2 = -uVar2;
  }
  iVar5 = (int)(char)*PTR_DAT_0602e810;
  if (iVar5 == 0) {
    if ((uVar2 & 0xffff) < uVar3) {
LAB_0602e864:
      if (DAT_0602e87c <= unaff_r8) {
        (*(code *)PTR_FUN_0602e8a8)(DAT_0602e8a0,DAT_0602e8a4,uVar4,iVar5,in_pr);
        FUN_0602e78c();
        return;
      }
      (*(code *)PTR_FUN_0602e888)(DAT_0602e880,DAT_0602e884,uVar4,iVar5,in_pr);
      FUN_0602e78c();
      return;
    }
  }
  else if (uVar3 <= (uVar2 & 0xffff)) goto LAB_0602e864;
  if (DAT_0602e834 <= unaff_r8) {
    (*(code *)PTR_FUN_0602e860)(DAT_0602e858,DAT_0602e85c,uVar4,iVar5,in_pr);
    FUN_0602e78c();
    return;
  }
  (*(code *)PTR_FUN_0602e840)(DAT_0602e838,DAT_0602e83c,uVar4,iVar5,in_pr);
  FUN_0602e78c();
  return;
}


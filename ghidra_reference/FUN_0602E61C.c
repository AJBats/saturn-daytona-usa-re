/* FUN_0602E61C  0x0602E61C */


int FUN_0602e61c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)PTR_DAT_0602e638;
  iVar5 = *(int *)(iVar4 + DAT_0602e640);
  if (*(int *)PTR_DAT_0602e644 == iVar5) {
    iVar4 = FUN_0602e78c();
    return iVar4;
  }
  if (*(int *)PTR_DAT_0602e654 != iVar5) {
    iVar4 = FUN_0602e6e8();
    return iVar4;
  }
  iVar2 = *(int *)(iVar4 + DAT_0602e6b4);
  iVar1 = *(int *)(iVar5 + DAT_0602e6b4);
  iVar5 = *(int *)(iVar5 + DAT_0602e6b0) - *(int *)(iVar4 + DAT_0602e6b0);
  iVar5 = (*(code *)PTR_FUN_0602e6b8)(iVar5,iVar5,iVar2);
  iVar1 = iVar1 - iVar2;
  iVar1 = (*(code *)PTR_FUN_0602e6b8)(iVar1,iVar1);
  uVar3 = iVar5 + iVar1;
  if ((int)uVar3 < 0) {
    iVar5 = (*(code *)PTR_FUN_0602e6bc)(uVar3 >> 2);
    iVar5 = iVar5 << 1;
  }
  else {
    iVar5 = (*(code *)PTR_FUN_0602e6e0)(uVar3);
  }
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  if (iVar5 < (int)PTR_DAT_0602e6e4) {
    iVar4 = FUN_0602e7c0();
    return iVar4;
  }
  *(undefined4 *)PTR_DAT_0602e7b4 = *(undefined4 *)(iVar4 + DAT_0602e7b0);
  iVar5 = DAT_0602e7b8;
  *(undefined4 *)PTR_DAT_0602e7bc = *(undefined4 *)(iVar4 + DAT_0602e7b8);
  return iVar5;
}


/* FUN_0602E6E8  0x0602E6E8 */


int FUN_0602e6e8(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_r9;
  int iVar4;
  
  iVar4 = *(int *)(unaff_r9 + DAT_0602e74c);
  if (iVar4 == *(int *)PTR_DAT_0602e748) {
    iVar2 = *(int *)(unaff_r9 + DAT_0602e758);
    iVar1 = *(int *)(iVar4 + DAT_0602e758);
    iVar4 = *(int *)(iVar4 + DAT_0602e754) - *(int *)(unaff_r9 + DAT_0602e754);
    iVar4 = (*(code *)PTR_FUN_0602e75c)(iVar4,iVar4,iVar2);
    iVar1 = iVar1 - iVar2;
    iVar1 = (*(code *)PTR_FUN_0602e75c)(iVar1,iVar1);
    uVar3 = iVar4 + iVar1;
    if ((int)uVar3 < 0) {
      iVar4 = (*(code *)PTR_FUN_0602e760)(uVar3 >> 2);
      iVar4 = iVar4 << 1;
    }
    else {
      iVar4 = (*(code *)PTR_FUN_0602e784)(uVar3);
    }
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if (iVar4 < (int)PTR_DAT_0602e788) {
      iVar4 = FUN_0602e7c0();
      return iVar4;
    }
  }
  *(undefined4 *)PTR_DAT_0602e7b4 = *(undefined4 *)(unaff_r9 + DAT_0602e7b0);
  iVar4 = DAT_0602e7b8;
  *(undefined4 *)PTR_DAT_0602e7bc = *(undefined4 *)(unaff_r9 + DAT_0602e7b8);
  return iVar4;
}


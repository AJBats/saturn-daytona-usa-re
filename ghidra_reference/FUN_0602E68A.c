/* FUN_0602E68A  0x0602E68A */


int FUN_0602e68a(void)

{
  int iVar1;
  int in_r7;
  uint uVar2;
  int unaff_r9;
  code *unaff_r13;
  
  iVar1 = (*unaff_r13)();
  uVar2 = in_r7 + iVar1;
  if ((int)uVar2 < 0) {
    iVar1 = (*(code *)PTR_FUN_0602e6bc)(uVar2 >> 2);
    iVar1 = iVar1 << 1;
  }
  else {
    iVar1 = (*(code *)PTR_FUN_0602e6e0)(uVar2);
  }
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < (int)PTR_DAT_0602e6e4) {
    iVar1 = FUN_0602e7c0();
    return iVar1;
  }
  *(undefined4 *)PTR_DAT_0602e7b4 = *(undefined4 *)(unaff_r9 + DAT_0602e7b0);
  iVar1 = DAT_0602e7b8;
  *(undefined4 *)PTR_DAT_0602e7bc = *(undefined4 *)(unaff_r9 + DAT_0602e7b8);
  return iVar1;
}


/* FUN_0602E768  0x0602E768 */


int FUN_0602e768(void)

{
  int iVar1;
  int unaff_r9;
  code *unaff_r13;
  
  iVar1 = (*unaff_r13)();
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < (int)PTR_DAT_0602e788) {
    iVar1 = FUN_0602e7c0();
    return iVar1;
  }
  *(undefined4 *)PTR_DAT_0602e7b4 = *(undefined4 *)(unaff_r9 + DAT_0602e7b0);
  iVar1 = DAT_0602e7b8;
  *(undefined4 *)PTR_DAT_0602e7bc = *(undefined4 *)(unaff_r9 + DAT_0602e7b8);
  return iVar1;
}


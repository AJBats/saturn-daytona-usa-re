/* FUN_06033E40  0x06033E40 */


int FUN_06033e40(void)

{
  int iVar1;
  
  FUN_06033f54();
  FUN_06033f54(0x2c);
  iVar1 = *(int *)PTR_DAT_06033e68 + 1;
  if (DAT_06033e88 <= *(int *)PTR_DAT_06033e68 + 1) {
    iVar1 = DAT_06033e88;
  }
  *(int *)PTR_DAT_06033e68 = iVar1;
  return iVar1;
}


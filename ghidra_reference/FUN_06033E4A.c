/* FUN_06033E4A  0x06033E4A */


int FUN_06033e4a(void)

{
  int iVar1;
  
  FUN_06033f54();
  iVar1 = *(int *)PTR_DAT_06033e68 + 1;
  if (DAT_06033e88 <= *(int *)PTR_DAT_06033e68 + 1) {
    iVar1 = DAT_06033e88;
  }
  *(int *)PTR_DAT_06033e68 = iVar1;
  return iVar1;
}


/* FUN_06033E0E  0x06033E0E */


int FUN_06033e0e(void)

{
  int iVar1;
  
  FUN_06033f54();
  FUN_06033f54(0x27);
  FUN_06033f54(0x28);
  FUN_06033f54(0x29);
  FUN_06033f54(0x2a);
  FUN_06033f54(0x2b);
  FUN_06033f54(0x2c);
  iVar1 = *(int *)PTR_DAT_06033e68 + 1;
  if (DAT_06033e88 <= *(int *)PTR_DAT_06033e68 + 1) {
    iVar1 = DAT_06033e88;
  }
  *(int *)PTR_DAT_06033e68 = iVar1;
  return iVar1;
}


/* FUN_06008BFC  0x06008BFC */


int FUN_06008bfc(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_06008c4c)();
  if (iVar1 != 0) {
    *(undefined4 *)PTR_DAT_06008c38 = 6;
  }
  return iVar1;
}


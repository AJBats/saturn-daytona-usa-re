/* FUN_06008C76  0x06008C76 */


uint FUN_06008c76(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (*(code *)PTR_FUN_06008cbc)();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (uint)(byte)*PTR_DAT_06008cb4;
    if (uVar2 == 0) {
      *(undefined4 *)PTR_DAT_06008cc0 = 4;
      (*(code *)PTR_FUN_06008cc4)();
      uVar2 = (*(code *)PTR_FUN_06008cc8)();
    }
    else {
      *(undefined4 *)PTR_DAT_06008cc0 = 6;
    }
    *PTR_DAT_06008cb4 = 0;
  }
  return uVar2;
}


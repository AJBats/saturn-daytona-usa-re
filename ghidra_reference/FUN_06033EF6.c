/* FUN_06033EF6  0x06033EF6 */


int FUN_06033ef6(void)

{
  code *in_r0;
  int iVar1;
  int iVar2;
  
  (*in_r0)();
  iVar1 = (int)(char)*PTR_DAT_06033f34;
  iVar2 = DAT_06033f4c;
  if ((char)*PTR_DAT_06033f34 == 2) {
    do {
      FUN_06033f54();
      iVar2 = iVar2 + 1;
      iVar1 = DAT_06033f50;
    } while (iVar2 < DAT_06033f50);
  }
  return iVar1;
}


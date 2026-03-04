/* FUN_06033EDE  0x06033EDE */


int FUN_06033ede(void)

{
  code *in_r0;
  int iVar1;
  int iVar2;
  
  (*in_r0)();
  (*(code *)PTR_FUN_06033f3c)(DAT_06033f44);
  (*(code *)PTR_FUN_06033f3c)(DAT_06033f48);
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


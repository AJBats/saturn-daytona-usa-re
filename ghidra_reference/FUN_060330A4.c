/* FUN_060330A4  0x060330A4 */


int FUN_060330a4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = FUN_0603316c();
  iVar3 = DAT_06033150;
  iVar2 = DAT_0603314c;
  iVar1 = DAT_06033148;
  iVar8 = *(int *)(DAT_06033148 + iVar4);
  iVar9 = *(int *)(DAT_0603314c + iVar4);
  iVar4 = iVar4 + DAT_06033150;
  iVar5 = **(int **)PTR_PTR_06033154 + -1;
  do {
    iVar6 = iVar8 - *(int *)(iVar1 + iVar4);
    iVar7 = iVar9 - *(int *)(iVar2 + iVar4);
    iVar6 = iVar6 + (iVar6 >> 1);
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (iVar6 <= (int)PTR_DAT_06033158) {
      iVar6 = iVar7;
      if (iVar7 < 0) {
        iVar6 = -iVar7;
      }
      if (iVar6 <= (int)PTR_DAT_0603315c) {
        FUN_0603316c(iVar7);
        FUN_06033188();
        FUN_0603320c(PTR_DAT_06033168);
      }
    }
    iVar4 = iVar4 + iVar3;
    iVar5 = iVar5 + -1;
  } while (0 < iVar5);
  return iVar4;
}


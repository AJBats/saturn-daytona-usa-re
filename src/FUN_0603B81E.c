extern int DAT_0603b83a;

extern int DAT_0603b88c;

extern int DAT_0603b88e;

extern int PTR_DAT_0603b83c;

extern int PTR_DAT_0603b83c;

int FUN_0603b81e()
{

  int iVar1;

  int iVar2;

  iVar2 = 0;

  for (iVar1 = *(int *)0x060A4D14 + (int)DAT_0603b83a;

      (iVar2 < **(int **)0x060A4D14 && (*(int *)(iVar1 + PTR_DAT_0603b83c) != 0));

      iVar1 = iVar1 + DAT_0603b88c) {

    iVar2 = iVar2 + 1;

  }

  if (iVar2 == **(int **)0x060A4D14) {

    iVar1 = 0;

  }

  else {

    *(int *)(iVar1 + DAT_0603b88e) = 1;

  }

  return iVar1;

}

extern int DAT_0600d996;

extern int DAT_0600d998;

extern int DAT_0600d99a;

extern int PTR_DAT_0600d99c;

extern int PTR_DAT_0600d99c;

extern void FUN_0600dcc8();

void FUN_0600d92c()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar4 = *(int *)0x0607E940;

  if (*(int *)0x06063F28 - 1U < *(unsigned int *)(iVar4 + DAT_0600d996)) {

    *(int *)0x0607EBF4 = 3;

    *(int *)(iVar4 + DAT_0600d998) = *(int *)(iVar4 + DAT_0600d998) + 1;

  }

  *(int *)0x0607EAC0 = 0x28;

  FUN_0600dcc8();

  iVar1 = (int)DAT_0600d99a;

  iVar3 = *(int *)0x060786B0;

  iVar2 = *(int *)(iVar4 + iVar1);

  *(int *)(iVar4 + iVar1) = *(int *)0x060786B0;

  iVar3 = iVar3 - iVar2;

  *(int *)0x060786A4 = *(int *)(iVar4 + iVar1);

  *(int *)(iVar4 + iVar1 + -0xc) = iVar3;

  *(int *)(0x0607EBF8 + (*(int *)(iVar4 + iVar1 + -0x10) + -1) * 4) = iVar3;

  iVar1 = *(int *)(iVar4 + iVar1 + 0x14);

  if ((iVar3 < iVar1) || (iVar1 == 0)) {

    *(int *)(iVar4 + PTR_DAT_0600d99c) = iVar3;

  }

  return;

}

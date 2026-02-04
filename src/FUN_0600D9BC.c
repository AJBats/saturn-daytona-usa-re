extern int DAT_0600da50;

extern int PTR_DAT_0600da54;

extern int PTR_DAT_0600da54;

extern int FUN_0600dd88();

void FUN_0600d9bc(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned int uVar4;

  int iVar5;

  int iVar6;

  puVar1 = 0x06063F1C;

  iVar6 = *(int *)0x0607E940;

  if (((param_1 == 0) && (*(int *)0x06063F18 == *(int *)0x06063F1C)) &&

     (*(int *)(iVar6 + DAT_0600da50) != *(int *)0x06063F20)) {

    iVar3 = 0x228;

    *(int *)0x06063F20 = *(int *)(iVar6 + iVar3);

    puVar2 = 0x06063F24;

    iVar5 = *(int *)0x06063F24;

    *(int *)0x06063F24 = iVar5 + 1;

    *(int *)(iVar6 + iVar3 + -0xc) = iVar5 + 1;

    if (*(unsigned int *)puVar2 < *(unsigned int *)0x06063F28) {

      *(int *)puVar1 = 0;

    }

  }

  uVar4 = (*(int(*)())0x06035280)();

  if ((*(unsigned int *)puVar1 & uVar4) == 0) {

    *(unsigned int *)puVar1 = *(unsigned int *)puVar1 | uVar4;

    (*(int(*)())0x06034F78)();

    *(int *)(iVar6 + PTR_DAT_0600da54) = *(int *)(iVar6 + PTR_DAT_0600da54) + 1;

    if (((*(int *)0x0607EAD8 != 0) && (param_1 != 0)) && ((*(unsigned char *)(iVar6 + 3) & 8) == 0)) {

      FUN_0600dd88();

      return;

    }

  }

  return;

}

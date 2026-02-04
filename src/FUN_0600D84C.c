extern int DAT_0600d894;

extern int DAT_0600d896;

int FUN_0600d84c()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar2 = *(int *)0x0607E940;

  iVar3 = *(int *)(iVar2 + DAT_0600d894);

  iVar1 = DAT_0600d894 + -4;

  iVar4 = iVar3 - *(int *)(iVar2 + iVar1);

  if ((iVar4 < 1) || (0xf < iVar4)) {

    iVar4 = (int)(*(int *)0x0607EA9C + (unsigned int)(*(int *)0x0607EA9C < 0)) >> 1;

    if ((iVar3 == iVar4) || (iVar3 == iVar4 + 2)) {

      iVar1 = 0x1e8;

      *(int *)(iVar2 + iVar1) = iVar3;

      iVar1 = iVar1 + 0x40;

      *(int *)0x06063F20 = *(int *)(iVar2 + iVar1);

    }

  }

  else {

    iVar1 = 0x1e8;

    *(int *)(iVar2 + iVar1) = iVar3;

  }

  return iVar1;

}

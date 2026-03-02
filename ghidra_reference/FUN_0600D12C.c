extern int DAT_0600d192;

extern int DAT_0600d1fa;

extern int DAT_0600d1fc;

extern int DAT_0600d1fe;

extern int DAT_0600d200;

extern int DAT_0600d202;

extern int DAT_0600d204;

extern int DAT_0600d206;

extern int PTR_DAT_0600d194;

extern int PTR_DAT_0600d194;

extern int PTR_DAT_0600d208;

extern int PTR_DAT_0600d208;

int FUN_0600d12c()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  iVar2 = *(int *)0x0607E940;

  iVar1 = *(int *)(iVar2 + DAT_0600d192);

  iVar5 = *(int *)(iVar2 + PTR_DAT_0600d194);

  if (iVar5 == 0) {

    iVar2 = ((*(int *)(iVar1 + 0x10) - *(int *)(iVar2 + 0x10)) + *(int *)(iVar1 + 0x18)) -

            *(int *)(iVar2 + 0x18);

  }

  else {

    if (((*(int *)(iVar5 + 0x10) - *(int *)(iVar2 + 0x10)) + *(int *)(iVar5 + 0x18)) -

        *(int *)(iVar2 + 0x18) < (int)0x00080000) goto LAB_0600d1a4;

    iVar2 = ((*(int *)(iVar1 + 0x10) - *(int *)(iVar2 + 0x10)) + *(int *)(iVar1 + 0x18)) -

            *(int *)(iVar2 + 0x18);

  }

  iVar5 = iVar1;

  if ((int)0x000F0000 <= iVar2) {

    return (int)PTR_DAT_0600d194;

  }

LAB_0600d1a4:

  iVar1 = (int)DAT_0600d1fa;

  iVar3 = *(int *)0x0607E940;

  iVar2 = *(int *)(iVar5 + iVar1);

  iVar4 = iVar2 - *(int *)(iVar3 + iVar1);

  if ((DAT_0600d1fc <= iVar4) && (iVar4 <= DAT_0600d1fe)) {

    iVar1 = 0x300;

    if (DAT_0600d200 < iVar2) {

      iVar1 = -iVar1;

    }

    iVar2 = iVar2 + iVar1;

    if (iVar2 < 0) {

      *(int *)(iVar3 + DAT_0600d202) = 0;

    }

    else if (DAT_0600d204 < iVar2) {

      *(int *)(iVar3 + DAT_0600d202) = 0x800;

    }

    else {

      *(int *)(iVar3 + DAT_0600d202) = iVar2;

    }

    iVar1 = (int)PTR_DAT_0600d208;

    *(int *)(iVar3 + iVar1) = 0x100;

    iVar1 = iVar1 + 0x30;

    *(int *)(iVar3 + iVar1) = iVar5;

  }

  return iVar1;

}

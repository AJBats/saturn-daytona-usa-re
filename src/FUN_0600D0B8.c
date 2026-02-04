extern int DAT_0600d112;

extern int DAT_0600d114;

extern int DAT_0600d116;

extern int DAT_0600d118;

extern int DAT_0600d11a;

extern int PTR_DAT_0600d11c;

extern int PTR_DAT_0600d11c;

void FUN_0600d0b8()
{

  int iVar1;

  unsigned int *puVar2;

  int iVar3;

  iVar3 = (int)DAT_0600d112;

  puVar2 = *(unsigned int **)0x0607E940;

  iVar1 = *(int *)0x0607E944;

  if ((*puVar2 & (unsigned int)0x00C00000) != 0) {

    if (*(int *)(iVar1 + DAT_0600d114) < *(int *)((int)puVar2 + (int)DAT_0600d114)) {

      iVar1 = *(int *)(iVar1 + DAT_0600d114) + iVar3;

    }

    else {

      iVar1 = *(int *)(iVar1 + DAT_0600d114) + (int)DAT_0600d116;

    }

    if (iVar1 < 0) {

      *(int *)((int)puVar2 + (int)DAT_0600d118) = 0;

    }

    else if (DAT_0600d11a < iVar1) {

      *(int *)((int)puVar2 + (int)DAT_0600d118) = (int)DAT_0600d11a;

    }

    else {

      *(int *)((int)puVar2 + (int)DAT_0600d118) = iVar1;

    }

    *(int *)((int)puVar2 + (int)PTR_DAT_0600d11c) = iVar3;

  }

  return;

}

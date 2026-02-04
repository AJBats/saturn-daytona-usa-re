extern int DAT_0600d404;

extern int DAT_0600d406;

void FUN_0600d37c()
{

  int iVar1;

  int *piVar2;

  unsigned int uVar3;

  int iVar4;

  int iVar5;

  iVar5 = 0;

  iVar1 = *(int *)(*(int *)0x0607E94C + (int)DAT_0600d404);

  piVar2 = (int *)0x0607E94C;

  for (uVar3 = *(unsigned int *)0x0607EA98; 1 < uVar3; uVar3 = uVar3 - 1) {

    iVar4 = *(int *)(piVar2[1] + (int)DAT_0600d404);

    if (iVar1 < iVar4) {

      iVar4 = *piVar2;

      *piVar2 = piVar2[1];

      piVar2[1] = iVar4;

      iVar4 = iVar1;

    }

    iVar1 = *piVar2;

    piVar2 = piVar2 + 1;

    *(int *)(iVar1 + DAT_0600d406) = iVar5;

    iVar5 = iVar5 + 1;

    iVar1 = iVar4;

  }

  *(int *)(*piVar2 + (int)DAT_0600d406) = iVar5;

  return;

}

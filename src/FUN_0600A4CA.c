int FUN_0600a4ca(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  char *puVar4;

  int uVar5;

  puVar2 = 0x060634DC;

  puVar4 = 0x06089E44;

  puVar1 = 0x06031A28;

  iVar3 = *(int *)0x0607EAD8;

  if (iVar3 == 0) {

    iVar3 = param_1 * 4;

    (*0x06031D8C)

              (*(int *)(0x06063488 + iVar3),*(int *)(0x060634F8 + iVar3));

    uVar5 = *(int *)(puVar2 + iVar3);

    iVar3 = (int)*(short *)(puVar4 + 0x54);

    puVar4 = 0x06063434;

  }

  else if (iVar3 == 1) {

    iVar3 = param_1 * 4;

    (*0x06031D8C)

              (*(int *)(0x060634A4 + iVar3),*(int *)(0x060634F8 + iVar3));

    uVar5 = *(int *)(puVar2 + iVar3);

    iVar3 = (int)*(short *)(puVar4 + 0x54);

    puVar4 = 0x06063450;

  }

  else {

    if (iVar3 != 2) {

      return iVar3;

    }

    iVar3 = param_1 * 4;

    (*0x06031D8C)

              (*(int *)(0x060634C0 + iVar3),*(int *)(0x060634F8 + iVar3));

    uVar5 = *(int *)(puVar2 + iVar3);

    iVar3 = (int)*(short *)(puVar4 + 0x54);

    puVar4 = 0x0606346C;

  }

  iVar3 = (*puVar1)(*(int *)(puVar4 + param_1 * 4),iVar3,uVar5);

  return iVar3;

}

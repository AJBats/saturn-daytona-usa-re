extern int DAT_060112e2;

extern int DAT_060112e4;

extern int DAT_060112e6;

void FUN_060111e2()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  puVar3 = 0x06063828;

  puVar2 = 0x06028400;

  puVar1 = 0x06078644;

  iVar5 = 3;

  if ((*0x0607887F == '\v') && ((*(unsigned int *)0x0607EBC8 & 1) == 0)) {

    iVar5 = 4;

  }

  if (*(int *)0x0607EAB8 == 0) {

    iVar5 = iVar5 * 0x1000;

    (*0x06028400)

              (4,0x0605A7FC,(int)DAT_060112e2,*(int *)(0x06063828 + 4) + iVar5);

    (*puVar2)(4,*(int *)

                         (0x0605ABBC +

                         (unsigned int)(*(int *)puVar1 != 0) * 4 + *(int *)0x06078868 * 8),

                      (int)DAT_060112e4,*(int *)(puVar3 + 4) + iVar5);

    iVar4 = (int)DAT_060112e6;

    iVar5 = *(int *)(puVar3 + 4) + iVar5;

    puVar3 = 0x0605A9B8;

    if (*(int *)puVar1 != 0) {

      puVar3 = 0x0605A9B0;

    }

  }

  else {

    iVar5 = (iVar5 + 2) * 0x1000;

    (*0x06028400)

              (4,0x0605A8B6,(int)DAT_060112e2,*(int *)(0x06063828 + 4) + iVar5);

    (*puVar2)(4,*(int *)

                         (0x0605ABBC +

                         (unsigned int)(*(int *)puVar1 != 0) * 4 + *(int *)0x06078868 * 8),

                      (int)DAT_060112e4,*(int *)(puVar3 + 4) + iVar5);

    iVar4 = (int)DAT_060112e6;

    iVar5 = *(int *)(puVar3 + 4) + iVar5;

    puVar3 = 0x0605A9B8;

    if (*(int *)puVar1 != 0) {

      puVar3 = 0x0605A9B0;

    }

  }

  (*puVar2)(4,puVar3,iVar4,iVar5);

  return;

}

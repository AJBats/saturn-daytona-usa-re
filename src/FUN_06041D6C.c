extern int DAT_06041dec;

extern int DAT_06041dee;

extern int DAT_06041df0;

extern int DAT_06041df2;

extern int DAT_06041eb4;

extern int DAT_06041eb6;

extern int DAT_06041f90;

extern int PTR_DAT_06041eb8;

extern int PTR_DAT_06041eb8;

int FUN_06041d6c(param_1)
    int *param_1;
{

  int bVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  char local_1c [16];

  puVar2 = 0x060A5400;

  bVar1 = 1;

  if (*(int *)(*(int *)0x060A5400 + (int)DAT_06041dec) == 1) {

    if ((*(int *)(*(int *)0x060A5400 + (int)DAT_06041dee) == 0) &&

       (*(char **)(*(int *)0x060A5400 + (int)DAT_06041df0) == 0x0000FFFF)) {

      iVar3 = (*(void(*)())0x060364D4)(0,*(int *)(*(int *)0x060A5400 + (int)DAT_06041df2));

      if (iVar3 != 0) {

        return 1;

      }

      (*(void(*)())0x060349B6)(local_1c);

      *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar2 + (int)DAT_06041dec) = 4;

    }

    else if (*(int *)(*(int *)0x060A5400 + (int)DAT_06041df0) == 0) {

      bVar1 = 0;

    }

    else {

      *(int *)(*(int *)0x060A5400 + (int)DAT_06041eb4) = 2;

    }

  }

  if (*(int *)((int)DAT_06041eb4 + *(int *)puVar2) == 2) {

    iVar3 = (int)DAT_06041eb6;

    iVar3 = (*(void(*)())0x0603683C)(*(int *)(*(int *)puVar2 + iVar3 + -8),

                       *(int *)(*(int *)puVar2 + iVar3 + -4),

                       *(int *)(*(int *)puVar2 + iVar3));

    *param_1 = *param_1 + 1;

    if (iVar3 == 0) {

      *(int *)(*(int *)puVar2 + (int)DAT_06041eb4) = 3;

      (*(void(*)())0x060349B6)(local_1c);

      *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    }

  }

  uVar5 = PTR_DAT_06041eb8;

  if ((*(int *)((int)DAT_06041eb4 + *(int *)puVar2) == 3) &&

     (uVar4 = (*(void(*)())0x06035C4E)(), (uVar4 & uVar5) != 0)) {

    bVar1 = 0;

  }

  if ((*(int *)((int)DAT_06041eb4 + *(int *)puVar2) == 4) &&

     (uVar5 = (*(void(*)())0x06035C4E)(), (uVar5 & 0x40) != 0)) {

    bVar1 = 0;

  }

  if (!bVar1) {

    (*(void(*)())0x06035C54)(0x0000FFF7);

    *(int *)(*(int *)puVar2 + (int)DAT_06041f90) = 0;

    *(int *)(*(int *)puVar2 + 0x34) = 0;

  }

  return bVar1;

}

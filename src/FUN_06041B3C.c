extern int DAT_06041bc8;

extern int DAT_06041bca;

extern int DAT_06041bcc;

extern int DAT_06041bce;

extern int DAT_06041bd0;

extern int DAT_06041bd2;

extern int DAT_06041ca8;

extern int DAT_06041caa;

extern int PTR_DAT_06041cac;

extern int PTR_DAT_06041cac;

int FUN_06041b3c(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int uVar3;

  int iVar4;

  int local_28;

  int iStack_24;

  char local_20 [16];

  puVar2 = 0x060A5400;

  puVar1 = 0x060349B6;

  if (*(int *)((int)DAT_06041bc8 + *(int *)0x060A5400) == 1) {

    (*(void(*)())0x06036572)(*(int *)(*(int *)0x060A5400 + (int)DAT_06041bca),&local_28);

    (*(void(*)())puVar1)(local_20);

    *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

    *param_1 = *param_1 + 1;

    iVar4 = local_28 - *(int *)(*(int *)puVar2 + (int)DAT_06041bcc);

    local_28 = *(int *)(*(int *)puVar2 + (int)DAT_06041bce);

    if (iVar4 < local_28) {

      local_28 = iVar4;

    }

    **(int **)(*(int *)puVar2 + (int)DAT_06041bd0) = local_28;

    if (local_28 < 1) {

      iVar4 = (int)DAT_06041bc8;

      *(int *)(*(int *)puVar2 + iVar4) = 0;

      if (*(int *)(*(int *)puVar2 + iVar4 + 0x18) != 0) {

        **(int **)(*(int *)puVar2 + (int)DAT_06041bd2) = 0;

      }

      return 0;

    }

    if (*(int *)(*(int *)puVar2 + (int)DAT_06041ca8) == 0) {

      *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 0;

      return 0;

    }

    *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 2;

  }

  if (*(int *)((int)DAT_06041caa + *(int *)puVar2) == 2) {

    if (*(int *)(*(int *)puVar2 + 0x34) == 1) {

      return 2;

    }

    *(int *)(*(int *)puVar2 + 0x34) = 1;

    iVar4 = (int)PTR_DAT_06041cac;

    iVar4 = (*(void(*)())0x060365C4)(*(int *)(*(int *)puVar2 + iVar4 + -0x10),

                       *(int *)(*(int *)puVar2 + iVar4 + -0xc),

                       **(int **)(*(int *)puVar2 + iVar4));

    if (iVar4 != 0) {

      return 2;

    }

    (*(void(*)())puVar1)(local_20);

    *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 3;

  }

  if (*(int *)((int)DAT_06041caa + *(int *)puVar2) == 3) {

    iVar4 = (*(void(*)())0x0603660E)(&iStack_24);

    if (iVar4 == 0) {

      (*(void(*)())puVar1)(local_20);

      *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

      *param_1 = *param_1 + 1;

      iVar4 = (int)DAT_06041caa;

      *(int *)(*(int *)puVar2 + iVar4) = 0;

      **(int **)(*(int *)puVar2 + iVar4 + 0x18) = iStack_24 << 1;

      *(int *)(*(int *)puVar2 + 0x34) = 0;

      uVar3 = 0;

    }

    else {

      uVar3 = 1;

    }

  }

  else {

    uVar3 = 1;

  }

  return uVar3;

}

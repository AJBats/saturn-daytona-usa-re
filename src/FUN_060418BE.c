int FUN_060418be(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  char *pcVar5;

  int iVar6;

  char local_2c [16];

  puVar2 = 0x060349B6;

  puVar1 = 0x060A5400;

  for (iVar6 = 0; iVar6 < *(int *)(*(int *)puVar1 + 0x54); iVar6 = iVar6 + 1) {

    if (*(int *)(*(int *)puVar1 + 0x58) == 1) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + iVar6 * 0x10);

      iVar3 = (*(void(*)())0x06036380)((int)*pcVar5,(int)pcVar5[1]);

      if (iVar3 != 0) break;

      (*(void(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar1 + 0x58) = 2;

    }

    if (*(int *)(*(int *)puVar1 + 0x58) == 2) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + iVar6 * 0x10);

      iVar3 = (*(void(*)())0x060362A8)((int)*pcVar5,pcVar5 + 2);

      if (iVar3 != 0) break;

      (*(void(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      if (*(int *)(iVar6 * 0x10 + *(int *)puVar1 + 0x68) == 0) {

        *(int *)(*(int *)puVar1 + 0x58) = 1;

      }

      else {

        *(int *)(*(int *)puVar1 + 0x58) = 3;

      }

    }

    if (*(int *)(*(int *)puVar1 + 0x58) == 3) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + iVar6 * 0x10);

      iVar3 = (*(void(*)())0x060361FC)((int)*pcVar5,*(int *)(pcVar5 + 8),*(int *)(pcVar5 + 0xc));

      if (iVar3 != 0) break;

      (*(void(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar1 + 0x58) = 1;

    }

  }

  if (iVar6 < *(int *)(*(int *)puVar1 + 0x54)) {

    iVar3 = 0;

    for (; iVar6 < *(int *)(*(int *)puVar1 + 0x54); iVar6 = iVar6 + 1) {

      (*(void(*)())0x06035168)(iVar3,*(int *)puVar1 + 0x5c);

      iVar3 = iVar3 + 1;

    }

    *(int *)(*(int *)puVar1 + 0x54) = iVar3;

  }

  else {

    *(int *)(*(int *)puVar1 + 0x54) = 0;

  }

  uVar4 = (*(void(*)())0x06035C4E)();

  if (((uVar4 & 0x40) != 0) && (*(int *)(*(int *)puVar1 + 0x54) == 0)) {

    *(int *)(*(int *)puVar1 + 0x58) = 0;

  }

  return *(int *)(*(int *)puVar1 + 0x54);

}

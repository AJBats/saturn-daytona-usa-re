extern int DAT_06040d2c;

extern int DAT_06040dc0;

extern int DAT_06040dc2;

extern int DAT_06040e72;

extern int PTR_DAT_06040dc4;

extern int PTR_DAT_06040dc4;

int FUN_06040c98(param_1, param_2)
    int param_1;
    int param_2;
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned char bVar8;

  int iVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  int iVar9;

  int iVar10;

  int iVar11;

  unsigned char local_30 [4];

  unsigned char local_2c [16];

  puVar4 = 0x0604231E;

  puVar3 = 0x060A5400;

  puVar2 = 0x06034984;

  iVar11 = (int)DAT_06040d2c;

  *(int *)0x060A5400 = param_1;

  (*(void(*)())puVar4)();

  if (param_2 == 0) {

    *(char *)(*(int *)puVar3 + 0x17) = 0;

    *(char *)(*(int *)puVar3 + 0x2f) = 0;

  }

  else {

    *(char *)(*(int *)puVar3 + 0x17) = 1;

    *(char *)(*(int *)puVar3 + 0x2f) = 1;

  }

  (*(void(*)())puVar2)(local_2c);

  bVar8 = local_2c[0] & 0xf;

  if (bVar8 == 6) {

    return 0xfffffff3;

  }

  if (bVar8 == 7) {

    return 0xfffffff2;

  }

  if ((bVar8 != 9) && (bVar8 != 10)) {

    iVar5 = (*(void(*)())0x06034B9A)(iVar11,0x0000FFFF,iVar11,iVar11);

    if (iVar5 != 0) {

      return 0xfffffffe;

    }

    iVar5 = 0;

    bVar1 = 0;

    while (uVar7 = DAT_06040dc0, !bVar1) {

      uVar6 = (*(void(*)())0x06035C4E)();

      if ((uVar6 & uVar7) != 0) {

        (*(void(*)())0x06035C54)(0x0000FBFF);

        iVar5 = iVar5 + 1;

        if (DAT_06040dc2 < iVar5) {

          return 0xfffffffe;

        }

        (*(void(*)())puVar2)(local_2c);

        bVar8 = local_2c[0] & 0xf;

        if ((bVar8 == 1) || (bVar8 == 2)) {

          bVar1 = 1;

        }

        else if ((bVar8 == 9) || (bVar8 == 10)) {

          return 0xfffffff6;

        }

      }

    }

    iVar9 = (int)PTR_DAT_06040dc4;

    iVar10 = *(int *)0x060A4D14;

    iVar5 = (*(void(*)())0x06034AEE)(iVar10 + iVar9);

    if (iVar5 != 0) {

      return 0xfffffffe;

    }

    (*(void(*)())0x06034B54)(0,local_30);

    (*(void(*)())0x06034B54)(local_30[0],local_30);

    if ((*(unsigned int *)(iVar10 + iVar9 + (local_30[0] - 1) * 4) & 0x40000000) == 0) {

      return 0xfffffff1;

    }

    (*(void(*)())0x060364D4)((int)DAT_06040e72,iVar11);

    *(char **)(*(int *)puVar3 + 0x3c) = 0x00008000;

    do {

      uVar7 = (*(void(*)())0x06035C4E)();

      if ((uVar7 & 0x40) != 0) {

        *(int *)(*(int *)puVar3 + 0x3c) = 0;

        (*(void(*)())puVar2)(*(int *)puVar3 + 0x40);

        return 0;

      }

      iVar11 = *(int *)(*(int *)puVar3 + 0x3c) + -1;

      *(int *)(*(int *)puVar3 + 0x3c) = iVar11;

    } while (iVar11 != 0);

    return 0xfffffffe;

  }

  return 0xfffffff6;

}

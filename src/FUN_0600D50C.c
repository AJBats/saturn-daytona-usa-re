extern int DAT_0600d5d6;

extern int DAT_0600d6ba;

extern int DAT_0600d76a;

extern int PTR_DAT_0600d770;

extern int PTR_DAT_0600d770;

void FUN_0600d50c()
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char *puVar4;

  unsigned int uVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int local_30;

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  puVar1 = 0x0607EA98;

  puVar4 = 0x0607E944;

  *(int *)0x0607EBDC = 0;

  iStack_28 = 0;

  iVar8 = 0;

  piVar6 = (int *)0x0607E94C;

  for (uVar5 = 0; uVar5 < *(unsigned int *)puVar1; uVar5 = uVar5 + 1) {

    iVar3 = *piVar6;

    piVar6 = piVar6 + 1;

    *(int *)(iVar3 + DAT_0600d5d6) = 0;

    (*(void(*)())0x06034F78)();

    (*(void(*)())0x06034F78)();

    (*(void(*)())0x06034F78)();

    (*(void(*)())0x06034F78)();

    (*(void(*)())0x06034F78)();

  }

  iVar3 = *(int *)puVar4;

  if ((*(unsigned int *)0x0607EBC4 & 0x10060000) == 0) {

    (*(void(*)())0x06027358)(*(int *)0x06063EF0,&local_30,&iStack_2c);

    local_30 = (*(void(*)())0x06027552)(-local_30,0x00070000);

    iStack_2c = (*(void(*)())0x06027552)(iStack_2c,0x00070000);

    local_30 = local_30 + *(int *)0x06063DF8;

    iStack_2c = iStack_2c + *(int *)(0x06063DF8 + 8);

  }

  else {

    (*(void(*)())0x06027358)(*(int *)(*(int *)puVar4 + 0x20),&local_30,&iStack_2c);

    local_30 = (*(void(*)())0x06027552)(-local_30,0x00050000);

    iStack_2c = (*(void(*)())0x06027552)(iStack_2c,0x00050000);

    local_30 = local_30 + *(int *)(*(int *)puVar4 + 0x10);

    iStack_2c = iStack_2c + *(int *)(*(int *)puVar4 + 0x18);

  }

  iVar9 = iVar3;

  for (uVar5 = *(unsigned int *)puVar1; 1 < uVar5; uVar5 = uVar5 - 1) {

    iVar2 = (int)DAT_0600d6ba;

    iVar3 = *(int *)(iVar3 + iVar2);

    iVar9 = *(int *)(iVar9 + iVar2 + 4);

    *(unsigned int *)(iVar3 + iVar2 + -0x20) = uVar5;

    *(unsigned int *)(iVar9 + iVar2 + -0x20) = uVar5;

    iVar2 = local_30 - *(int *)(iVar3 + 0x10);

    if (iVar2 < 0) {

      iVar2 = *(int *)(iVar3 + 0x10) - local_30;

    }

    iStack_24 = *(int *)(iVar3 + 0x18);

    iVar7 = iStack_2c - iStack_24;

    if (iVar7 < 0) {

      iVar7 = iStack_24 - iStack_2c;

    }

    iVar2 = iVar2 + iVar7;

    if ((iVar2 < (int)0x000C0000) && (iStack_28 < 3)) {

      (*(void(*)())0x06034F78)();

      iStack_28 = iStack_28 + 1;

    }

    else if ((iVar2 < (int)0x00230000) && (iVar8 < 7)) {

      (*(void(*)())0x06034F78)();

      iVar8 = iVar8 + 1;

    }

    else if (iVar2 < (int)0x00780000) {

      (*(void(*)())0x06034F78)();

    }

  }

  (*(void(*)())0x06034F78)();

  iVar8 = *(int *)(*(int *)puVar4 + (int)DAT_0600d76a);

  puVar4 = 0x06078B68;

  for (uVar5 = 1; uVar5 < *(unsigned int *)puVar1; uVar5 = uVar5 + 1) {

    iVar3 = *(int *)(puVar4 + DAT_0600d76a) - iVar8;

    (*(void(*)())0x06034F78)();

    (*(void(*)())0x06034F78)();

    if ((iVar3 < 3) && (0 < iVar3)) {

      (*(void(*)())0x06034F78)();

    }

    if ((iVar3 < 1) && (-2 < iVar3)) {

      (*(void(*)())0x06034F78)();

    }

    puVar4 = puVar4 + PTR_DAT_0600d770;

  }

  return;

}

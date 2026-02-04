extern int DAT_0600e522;

extern int DAT_0600e69c;

extern int DAT_0600e69e;

extern int FUN_0600ea18();

void FUN_0600e4f2()
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  char *puVar6;

  puVar2 = 0x060786BC;

  *(short *)0x06063F44 = *(short *)0x06063D9E;

  puVar6 = *(char **)0x0607E944;

  *(char **)0x0607E940 = puVar6;

  bVar1 = puVar6 != 0x06078900;

  *(char **)0x0607E948 = 0x06078900 + DAT_0600e522;

  (*(int(*)())0x060081F4)();

  (*(int(*)())0x060085B8)();

  (*(int(*)())0x06030A06)();

  (*(int(*)())0x06030EE0)();

  if ((*(int *)puVar2 < 1) || (*(int *)0x06078635 != '\0')) {

    (*(int(*)())0x0602ECF2)();

    uVar4 = (*(int(*)())0x06006838)(*(int *)(puVar6 + 0x10),*(int *)(puVar6 + 0x18));

    *(int *)0x060786B8 = uVar4;

    (*(int(*)())0x06005ECC)();

    puVar3 = 0x06027CA4;

    (*(int(*)())0x06027CA4)(0x06063EB0,0);

    (*(int(*)())puVar3)(0x06063E9C,1);

    (*(int(*)())puVar3)(0x06063ED8,2);

    (*(int(*)())puVar3)(0x06063EC4,3);

  }

  else {

    *(int *)puVar2 = *(int *)puVar2 + -1;

    *(int *)(puVar6 + 0x10) = *(int *)(puVar6 + 0x10) + *(int *)0x060786C0;

    *(int *)(puVar6 + 0x18) = *(int *)(puVar6 + 0x18) + *(int *)0x060786C4;

    iVar5 = *(int *)(puVar6 + 0x20) + (int)*(short *)0x060786C8;

    *(int *)(puVar6 + 0x20) = iVar5;

    *(int *)(puVar6 + 0x30) = iVar5;

    *(int *)(puVar6 + 0x28) = iVar5;

    *(int *)0x06063EF0 = iVar5;

    uVar4 = (*(int(*)())0x06006838)(*(int *)(puVar6 + 0x10),*(int *)(puVar6 + 0x18));

    *(int *)0x060786B8 = uVar4;

    (*(int(*)())0x06005ECC)();

  }

  *(int *)(puVar6 + DAT_0600e69c) = *(int *)(puVar6 + 0x20);

  if (!bVar1) {

    (*(int(*)())0x0600DB64)();

  }

  (*(int(*)())0x0600DA7C)();

  (*(int(*)())0x0600CE66)();

  (*(int(*)())0x0603053C)(0);

  (*(int(*)())0x0600D780)(bVar1);

  puVar3 = 0x0600C994;

  iVar5 = 0x228;

  *(int *)(puVar6 + iVar5 + -0x34) =

       *(int *)(puVar6 + iVar5) * *(int *)0x0607EA9C + *(int *)(puVar6 + iVar5 + -0x3c);

  (*(int(*)())puVar3)();

  if ((*(int *)puVar2 < 1) && (*(int *)0x06078635 == '\0')) {

    FUN_0600ea18(puVar6);

  }

  if ((*(int *)0x06078635 == '\0') && (*(int *)0x06083255 == '\0')) {

    (*(int(*)())0x0602D9F0)();

    return;

  }

  return;

}

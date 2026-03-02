extern int DAT_0600c616;

extern int DAT_0600c6f6;

extern int DAT_0600c6f8;

extern int DAT_0600c6fa;

extern int DAT_0600c6fc;

extern int DAT_0600c6fe;

extern int DAT_0600c700;

extern int DAT_0600c702;

extern int PTR_DAT_0600c618;

extern int PTR_DAT_0600c618;

extern int FUN_0600c7d4();
extern int FUN_0600c8cc();
extern int FUN_0600c928();
extern int FUN_0600ca96();
extern int FUN_0600cc38();
extern int FUN_0600cd40();
extern int FUN_0600cf58();

void FUN_0600c5d6()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  char auStack_1c [8];

  puVar3 = 0x06078680;

  puVar2 = 0x0607EBDC;

  puVar1 = 0x06027552;

  iVar7 = *(int *)0x0607E940;

  iVar4 = FUN_0600cd40();

  iVar6 = iVar4 + 0x18;

  if (((*(short *)0x06087804 == 2) || (0 < *(int *)(iVar7 + DAT_0600c616))) ||

     (0 < *(int *)(iVar7 + PTR_DAT_0600c618))) {

    FUN_0600ca96(puVar3);

  }

  else if ((((*(unsigned char *)(*(int *)0x0607E944 + 3) & 8) == 0) &&

           (*(int *)(iVar7 + DAT_0600c6f6) < 1)) && ((*(unsigned char *)(iVar7 + DAT_0600c6f8) & 0x20) == 0))

  {

    if ((*(int *)puVar2 < 0xb) && (*(int *)(iVar7 + DAT_0600c6fa) < 0x66)) {

      FUN_0600cf58(iVar6);

    }

    if (*(int *)(iVar7 + DAT_0600c6fa) < 1) {

      FUN_0600cc38(iVar6,puVar3);

    }

    else {

      *(int *)(iVar7 + DAT_0600c6fa) = *(int *)(iVar7 + DAT_0600c6fa) + -2;

      FUN_0600ca96(puVar3);

      *(int *)puVar2 = *(int *)puVar2 + 1;

    }

  }

  else {

    FUN_0600cc38(iVar6,puVar3);

  }

  if (*(short *)0x06087804 == 3) {

    uVar5 = (*(int(*)())puVar1)(*(int *)(iVar4 + 0x20),*(int *)(iVar7 + DAT_0600c6fc));

    *(int *)(DAT_0600c6fe + iVar7) = uVar5;

  }

  FUN_0600c8cc(iVar7,puVar3);

  if ((**(unsigned int **)0x0607E940 & (unsigned int)0x00E00000) == 0) {

    *(int *)(iVar7 + 0x20) = (int)*(short *)(puVar3 + 0xe);

    (*(int(*)())0x06027358)(-*(int *)(iVar7 + 0x28),DAT_0600c702 + iVar7,DAT_0600c700 + iVar7);

    iVar4 = (*(int(*)())puVar1)(*(int *)(iVar7 + 0xc),*(int *)(iVar7 + DAT_0600c702));

    *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + iVar4;

    iVar4 = (*(int(*)())puVar1)(*(int *)(iVar7 + 0xc),*(int *)(iVar7 + DAT_0600c700));

    *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + iVar4;

    *(int *)(iVar7 + 0x14) = 0;

  }

  else {

    FUN_0600c928(iVar7);

    FUN_0600c7d4(iVar7,puVar3);

    uVar5 = (*(int(*)())0x06006838)(*(int *)(iVar7 + 0x10),*(int *)(iVar7 + 0x18))

    ;

    (*(int(*)())0x06027EDE)(uVar5,iVar7 + 0x10,auStack_1c);

  }

  return;

}

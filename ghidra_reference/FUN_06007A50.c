extern int DAT_06007a92;

extern int DAT_06007a94;

extern int DAT_06007a96;

void FUN_06007a50()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  short sVar7;

  int uVar5;

  int iVar6;

  int iVar8;

  short sVar9;

  int local_24;

  int auStack_20 [2];

  puVar1 = 0x06027552;

  iVar8 = (int)DAT_06007a92;

  if (*(int *)(*(int *)0x0607E944 + (int)DAT_06007a94) <= iVar8) {

    iVar8 = *(int *)(*(int *)0x0607E944 + (int)DAT_06007a94);

  }

  iVar8 = (*(int(*)())0x06027552)(iVar8,0x0000D1B7);

  if (*(int *)0x06085FF4 == '\0') {

    sVar9 = 0x34;

  }

  else {

    sVar9 = 0x24;

  }

  (*(int(*)())0x06027358)(DAT_06007a96 + iVar8,&local_24,auStack_20);

  puVar3 = 0x06078604;

  puVar2 = 0x0602754C;

  iVar8 = (*(int(*)())puVar1)(0x00970000,local_24);

  sVar7 = (*(int(*)())puVar2)(-iVar8);

  *(short *)(puVar3 + 8) = sVar7 + 8;

  uVar5 = (*(int(*)())puVar1)(0x00970000,auStack_20[0]);

  sVar7 = (*(int(*)())puVar2)(uVar5);

  *(short *)(puVar3 + 10) = sVar7 + sVar9;

  puVar4 = 0x00900000;

  iVar8 = (*(int(*)())puVar1)(0x00020000,auStack_20[0]);

  iVar6 = (*(int(*)())puVar1)(puVar4,local_24);

  sVar7 = (*(int(*)())puVar2)(iVar8 - iVar6);

  *(short *)(puVar3 + 0xc) = sVar7 + 8;

  iVar8 = (*(int(*)())puVar1)(0x00020000,local_24);

  iVar6 = (*(int(*)())puVar1)(puVar4,auStack_20[0]);

  sVar7 = (*(int(*)())puVar2)(iVar8 + iVar6);

  *(short *)(puVar3 + 0xe) = sVar7 + sVar9;

  iVar8 = (*(int(*)())puVar1)(0x00890000,local_24);

  sVar7 = (*(int(*)())puVar2)(-iVar8);

  *(short *)(puVar3 + 0x10) = sVar7 + 8;

  uVar5 = (*(int(*)())puVar1)(0x00890000,auStack_20[0]);

  sVar7 = (*(int(*)())puVar2)(uVar5);

  *(short *)(puVar3 + 0x12) = sVar7 + sVar9;

  iVar8 = (*(int(*)())puVar1)(0xFFFE0000,auStack_20[0]);

  iVar6 = (*(int(*)())puVar1)(puVar4,local_24);

  sVar7 = (*(int(*)())puVar2)(iVar8 - iVar6);

  *(short *)(puVar3 + 0x14) = sVar7 + 8;

  iVar8 = (*(int(*)())puVar1)(0xFFFE0000,local_24);

  iVar6 = (*(int(*)())puVar1)(puVar4,auStack_20[0]);

  sVar7 = (*(int(*)())puVar2)(iVar8 + iVar6);

  *(short *)(puVar3 + 0x16) = sVar7 + sVar9;

  *(short *)(puVar3 + 6) = (short)0x0000A3FF;

  puVar1 = 0x060785FC;

  (*(int(*)())0x060280C4)(puVar3,*(int *)0x060785FC);

  *(int *)0x0605A008 = *(int *)0x0605A008 + 1;

  *(int *)puVar1 = *(int *)puVar1 + 0x20;

  return;

}

extern int FUN_06033504();

int FUN_06033470()
{

  short sVar1;

  short sVar2;

  char *puVar3;

  short sVar5;

  int uVar4;

  short *psVar6;

  short sVar7;

  puVar3 = 0x06062970;

  psVar6 = (short *)(0x060338C4 + **(int **)0x06033874 * 8);

  sVar1 = *psVar6;

  sVar2 = psVar6[1];

  *(int *)0x06062970 = 0;

  puVar3[4] = 1;

  puVar3[5] = (char)(**(unsigned int **)0x0603387C >> 6);

  *(short *)(puVar3 + 6) = 0xe;

  sVar5 = sVar1;

  sVar7 = psVar6[2] + sVar1;

  if ('\0' < **(char **)0x06033884) {

    sVar5 = psVar6[2] + sVar1;

    sVar7 = sVar1;

  }

  *(short *)(puVar3 + 8) = sVar5;

  *(short *)(puVar3 + 0x14) = sVar5;

  *(short *)(puVar3 + 0xc) = sVar7;

  *(short *)(puVar3 + 0x10) = sVar7;

  *(short *)(puVar3 + 10) = sVar2;

  *(short *)(puVar3 + 0xe) = sVar2;

  sVar1 = psVar6[3];

  *(short *)(puVar3 + 0x12) = sVar1 + sVar2;

  *(short *)(puVar3 + 0x16) = sVar1 + sVar2;

  (*(void(*)())0x060280F8)(puVar3,*(int *)0x060785FC);

  uVar4 = FUN_06033504();

  return uVar4;

}

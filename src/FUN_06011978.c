void FUN_06011978(param_1, param_2, param_3, param_4)
    int *param_1;
    int param_2;
    int param_3;
    short param_4;
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  short uVar5;

  short *puVar6;

  puVar4 = 0x0605AAA0;

  puVar3 = 0x060786CC;

  puVar2 = 0x0602754C;

  puVar6 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  uVar5 = (*(int(*)())0x0602754C)(*param_1 + param_2);

  *puVar6 = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[1] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 10) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[2] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0xc) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[3] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0xe) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[4] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x10) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[5] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x12) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[6] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x14) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[7] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x16) = uVar5;

  *(short *)(puVar3 + (short)(*(short *)puVar4 * 0x18) + 6) = param_4;

  puVar3[(short)(*(short *)puVar4 * 0x18) + 4] = 0;

  puVar3[(short)(*(short *)puVar4 * 0x18) + 5] = 1;

  *(short *)puVar4 = *(short *)puVar4 + 1;

  return;

}

void FUN_060116a8(int param_1,int param_2,short param_3,int param_4)
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  int uVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  short *psVar11;

  int uStack_2c;

  int uStack_28;

  short sStack_24;

  sStack_24 = param_3;

  (*(int(*)())0x06027358)((int)param_3,&uStack_2c,&uStack_28);

  puVar4 = 0x06027552;

  puVar3 = 0x0602754C;

  puVar2 = 0x0605AAA0;

  puVar1 = 0x060786CC;

  psVar11 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  iVar5 = (*(int(*)())0x06027552)(0xFFC80000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar8 = (*(int(*)())puVar3)(uVar7);

  sVar9 = (*(int(*)())puVar3)(param_1);

  *psVar11 = sVar9 + sVar8;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xc) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xe) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x12) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x14) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x16) = sVar10 + sVar9;

  *(short *)(puVar1 + (short)(*(short *)puVar2 * 0x18) + 6) = param_5;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 4] = 0;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 5] = 1;

  *(short *)puVar2 = *(short *)puVar2 + 1;

  return;

}

void FUN_06011af4(int param_1,int param_2,int param_3,int param_4,short param_5,
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

  int uStack_38;

  int uStack_34;

  int uStack_30;

  int uStack_2c;

  int iStack_28;

  int iStack_24;

  uStack_30 = param_2;

  uStack_2c = param_1;

  (*0x06027358)((int)param_5,&uStack_38,&uStack_34);

  puVar4 = 0x06027552;

  puVar3 = 0x0602754C;

  puVar2 = 0x0605AAA0;

  puVar1 = 0x060786CC;

  iStack_24 = -param_3;

  psVar11 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  iVar5 = (*0x06027552)(iStack_24,uStack_34);

  iVar6 = (*puVar4)(param_4,uStack_38);

  uVar7 = (*puVar4)(iVar5 - iVar6,param_6);

  sVar8 = (*puVar3)(uVar7);

  sVar9 = (*puVar3)(uStack_2c);

  *psVar11 = sVar9 - sVar8;

  sVar8 = *(short *)puVar2;

  iVar5 = (*puVar4)(iStack_24,uStack_38);

  iVar6 = (*puVar4)(param_4,uStack_34);

  uVar7 = (*puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*puVar3)(uVar7);

  sVar10 = (*puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*puVar4)(param_3,uStack_34);

  iVar6 = (*puVar4)(param_4,uStack_38);

  uVar7 = (*puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*puVar3)(uVar7);

  sVar10 = (*puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xc) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*puVar4)(param_3,uStack_38);

  iVar6 = (*puVar4)(param_4,uStack_34);

  uVar7 = (*puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*puVar3)(uVar7);

  sVar10 = (*puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xe) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*puVar4)(param_3,uStack_34);

  iStack_28 = -param_4;

  iVar6 = (*puVar4)(iStack_28,uStack_38);

  uVar7 = (*puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*puVar3)(uVar7);

  sVar10 = (*puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x10) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*puVar4)(param_3,uStack_38);

  iVar6 = (*puVar4)(iStack_28,uStack_34);

  uVar7 = (*puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*puVar3)(uVar7);

  sVar10 = (*puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x12) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*puVar4)(iStack_24,uStack_34);

  iVar6 = (*puVar4)(iStack_28,uStack_38);

  uVar7 = (*puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*puVar3)(uVar7);

  sVar10 = (*puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x14) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*puVar4)(iStack_24,uStack_38);

  iVar6 = (*puVar4)(iStack_28,uStack_34);

  uVar7 = (*puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*puVar3)(uVar7);

  sVar10 = (*puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x16) = sVar10 + sVar9;

  *(short *)(puVar1 + (short)(*(short *)puVar2 * 0x18) + 6) = param_7;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 4] = 0;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 5] = 0;

  *(short *)puVar2 = *(short *)puVar2 + 1;

  return;

}

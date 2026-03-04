/* FUN_060116BC  0x060116BC */


void FUN_060116bc(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  short in_r0;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short *psVar11;
  undefined2 in_stack_0000001e;
  undefined4 uStack_10;
  undefined4 auStack_c [3];
  
  (*(code *)PTR_FUN_060117dc)((int)in_r0,&uStack_10,auStack_c);
  puVar4 = PTR_FUN_060117ec;
  puVar3 = PTR_FUN_060117e8;
  puVar2 = PTR_DAT_060117e4;
  puVar1 = PTR_DAT_060117e0;
  psVar11 = (short *)(PTR_DAT_060117e0 + (short)(*(short *)PTR_DAT_060117e4 * 0x18) + 8);
  iVar5 = (*(code *)PTR_FUN_060117ec)(DAT_060117f0,auStack_c[0]);
  iVar6 = (*(code *)puVar4)(PTR_DAT_060117f4,uStack_10);
  uVar7 = (*(code *)puVar4)(iVar5 - iVar6);
  sVar8 = (*(code *)puVar3)(uVar7);
  sVar9 = (*(code *)puVar3)(param_1);
  *psVar11 = sVar9 + sVar8;
  sVar8 = *(short *)puVar2;
  iVar5 = (*(code *)puVar4)(DAT_060117f0,uStack_10);
  iVar6 = (*(code *)puVar4)(PTR_DAT_060117f4,auStack_c[0]);
  uVar7 = (*(code *)puVar4)(iVar5 + iVar6);
  sVar9 = (*(code *)puVar3)(uVar7);
  sVar10 = (*(code *)puVar3)();
  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 10) = sVar10 + sVar9;
  sVar8 = *(short *)puVar2;
  iVar5 = (*(code *)puVar4)(PTR_DAT_060117f8,auStack_c[0]);
  iVar6 = (*(code *)puVar4)(PTR_DAT_060117f4,uStack_10);
  uVar7 = (*(code *)puVar4)(iVar5 - iVar6);
  sVar9 = (*(code *)puVar3)(uVar7);
  sVar10 = (*(code *)puVar3)(param_1);
  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xc) = sVar10 + sVar9;
  sVar8 = *(short *)puVar2;
  iVar5 = (*(code *)puVar4)(PTR_DAT_060117f8,uStack_10);
  iVar6 = (*(code *)puVar4)(PTR_DAT_060117f4,auStack_c[0]);
  uVar7 = (*(code *)puVar4)(iVar5 + iVar6);
  sVar9 = (*(code *)puVar3)(uVar7);
  sVar10 = (*(code *)puVar3)();
  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xe) = sVar10 + sVar9;
  sVar8 = *(short *)puVar2;
  iVar5 = (*(code *)puVar4)(PTR_DAT_0601196c,auStack_c[0]);
  iVar6 = (*(code *)puVar4)(DAT_06011970,uStack_10);
  uVar7 = (*(code *)puVar4)(iVar5 - iVar6);
  sVar9 = (*(code *)puVar3)(uVar7);
  sVar10 = (*(code *)puVar3)(param_1);
  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x10) = sVar10 + sVar9;
  sVar8 = *(short *)puVar2;
  iVar5 = (*(code *)puVar4)(PTR_DAT_0601196c,uStack_10);
  iVar6 = (*(code *)puVar4)(DAT_06011970,auStack_c[0]);
  uVar7 = (*(code *)puVar4)(iVar5 + iVar6);
  sVar9 = (*(code *)puVar3)(uVar7);
  sVar10 = (*(code *)puVar3)();
  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x12) = sVar10 + sVar9;
  sVar8 = *(short *)puVar2;
  iVar5 = (*(code *)puVar4)(DAT_06011974,auStack_c[0]);
  iVar6 = (*(code *)puVar4)(DAT_06011970,uStack_10);
  uVar7 = (*(code *)puVar4)(iVar5 - iVar6);
  sVar9 = (*(code *)puVar3)(uVar7);
  sVar10 = (*(code *)puVar3)(param_1);
  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x14) = sVar10 + sVar9;
  sVar8 = *(short *)puVar2;
  iVar5 = (*(code *)puVar4)(DAT_06011974,uStack_10);
  iVar6 = (*(code *)puVar4)(DAT_06011970,auStack_c[0]);
  uVar7 = (*(code *)puVar4)(iVar5 + iVar6);
  sVar9 = (*(code *)puVar3)(uVar7);
  sVar10 = (*(code *)puVar3)();
  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x16) = sVar10 + sVar9;
  *(undefined2 *)(puVar1 + (short)(*(short *)puVar2 * 0x18) + 6) = in_stack_0000001e;
  puVar1[(short)(*(short *)puVar2 * 0x18) + 4] = 0;
  puVar1[(short)(*(short *)puVar2 * 0x18) + 5] = 1;
  *(short *)puVar2 = *(short *)puVar2 + 1;
  return;
}


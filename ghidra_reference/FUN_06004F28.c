/* FUN_06004F28  0x06004F28 */


void FUN_06004f28(short *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int in_r3;
  ushort uVar5;
  short *psVar6;
  uint unaff_r9;
  
  puVar4 = PTR_DAT_06004fe8;
  puVar3 = PTR_DAT_06004fe4;
  puVar2 = PTR_DAT_06004fe0;
  puVar1 = PTR_DAT_06004fdc;
  if (in_r3 != 0) {
    uVar5 = (param_1[1] * *param_1 + 2) * 2;
    psVar6 = *(short **)PTR_DAT_06004fec;
    (*(code *)PTR_FUN_06004ff0)(psVar6,param_1,uVar5);
    *(uint *)PTR_DAT_06004fec = *(int *)PTR_DAT_06004fec + (uint)uVar5;
    *(uint *)PTR_DAT_06004ff4 = *(int *)PTR_DAT_06004ff4 + (uint)uVar5;
    param_1 = psVar6;
  }
  if (param_3 == 0) {
    *(undefined4 *)(puVar1 + *(int *)puVar4 * 8 + 4) =
         *(undefined4 *)(puVar1 + (*(int *)puVar4 + -1) * 8 + 4);
  }
  else if ((unaff_r9 & 3) == 0) {
    *(undefined4 *)(puVar1 + *(int *)puVar4 * 8 + 4) = *(undefined4 *)puVar3;
    if ((unaff_r9 & 8) == 0) {
      (*(code *)PTR_FUN_06004ff0)(PTR_DAT_06004ff8 + *(int *)puVar3 * 0x20,param_3,param_4 << 5);
    }
    else {
      (*(code *)PTR_FUN_06004ffc)(param_3,PTR_DAT_06004ff8 + *(int *)puVar3 * 0x20);
    }
    *(int *)puVar3 = *(int *)puVar3 + param_4;
  }
  else {
    *(undefined4 *)(puVar1 + *(int *)puVar4 * 8 + 4) = *(undefined4 *)puVar2;
    if ((unaff_r9 & 8) == 0) {
      (*(code *)PTR_FUN_060050e0)(PTR_DAT_060050d8 + *(int *)puVar2 * 0x20,param_3,param_4 << 5);
    }
    else {
      (*(code *)PTR_FUN_060050dc)(param_3,PTR_DAT_060050d8 + *(int *)puVar2 * 0x20);
    }
    *(int *)puVar2 = *(int *)puVar2 + param_4;
  }
  *(short **)(puVar1 + *(int *)puVar4 * 8) = param_1;
  *(int *)puVar4 = *(int *)puVar4 + 1;
  return;
}


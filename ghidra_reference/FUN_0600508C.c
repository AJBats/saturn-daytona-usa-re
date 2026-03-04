/* FUN_0600508C  0x0600508C */


void FUN_0600508c(ushort *param_1,undefined4 param_2,uint param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint in_r3;
  uint uVar3;
  ushort *puVar4;
  
  puVar1 = PTR_DAT_060050e4;
  if ((param_3 & in_r3) != 0) {
    puVar4 = *(ushort **)PTR_DAT_060050e4;
    uVar3 = ((uint)param_1[1] * (uint)*param_1 + 2) * 2 & 0xffff;
    (*(code *)PTR_FUN_060050e0)(puVar4,param_1,uVar3);
    *(uint *)puVar1 = *(int *)puVar1 + uVar3;
    *(uint *)PTR_DAT_060050e8 = *(int *)PTR_DAT_060050e8 + uVar3;
    param_1 = puVar4;
  }
  puVar2 = PTR_DAT_06005160;
  puVar1 = PTR_DAT_0600515c;
  *(undefined4 *)(PTR_DAT_0600515c + *(int *)PTR_DAT_06005160 * 8 + 4) = param_2;
  *(ushort **)(puVar1 + *(int *)puVar2 * 8) = param_1;
  *(int *)puVar2 = *(int *)puVar2 + 1;
  return;
}


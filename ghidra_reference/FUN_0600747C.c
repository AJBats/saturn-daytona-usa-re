/* FUN_0600747C  0x0600747C */


void FUN_0600747c(uint param_1,ushort param_2,undefined2 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  ushort uVar4;
  int iVar5;
  
  puVar1 = PTR_DAT_06007528;
  uVar4 = param_2 & DAT_06007526;
  *(short *)(PTR_DAT_0600752c + (param_1 & 0xffff) * 2) = (short)*(undefined4 *)PTR_DAT_06007528;
  puVar3 = PTR_DAT_06007534;
  puVar2 = PTR_DAT_06007530;
  *(undefined4 *)(PTR_DAT_06007530 + *(int *)puVar1 * 8) = *(undefined4 *)PTR_DAT_06007534;
  *(ushort *)(puVar2 + *(int *)puVar1 * 8 + 4) = param_2;
  *(undefined2 *)(puVar2 + *(int *)puVar1 * 8 + 6) = param_3;
  *(int *)puVar1 = *(int *)puVar1 + 1;
  iVar5 = (int)((uint)(param_2 >> 8 & 0x3f) * (uint)uVar4) >> 1;
  (*(code *)PTR_FUN_0600753c)(*(int *)puVar3 * 8 + *(int *)PTR_DAT_06007538,param_4,iVar5 << 3);
  *(int *)puVar3 = *(int *)puVar3 + iVar5;
  return;
}


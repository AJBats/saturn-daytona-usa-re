/* FUN_0600D41C  0x0600D41C */


void FUN_0600d41c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)PTR_DAT_0600d4ac;
  for (uVar3 = 1;
      (uVar4 = uVar3, puVar5 = (undefined4 *)PTR_DAT_0600d4ac,
      puVar1 = (undefined4 *)PTR_DAT_0600d4b0,
      *(uint *)(*(int *)(PTR_DAT_0600d4ac + uVar3 * 4) + (int)DAT_0600d4a6) <
      *(uint *)PTR_DAT_0600d4a8 && (uVar3 < 3)); uVar3 = uVar3 + 1) {
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar1 + 1;
  }
  for (uVar4 = *(int *)PTR_DAT_0600d4b4 - uVar3; puVar1 = (undefined4 *)PTR_DAT_0600d4b0, 1 < uVar4;
      uVar4 = uVar4 - 1) {
    uVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar6 = uVar2;
    puVar6 = puVar6 + 1;
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *puVar1;
    puVar6 = puVar6 + 1;
    puVar1 = puVar1 + 1;
  }
  FUN_0600d496();
  return;
}


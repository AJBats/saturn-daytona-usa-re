/* FUN_0601AC88  0x0601AC88 */


uint FUN_0601ac88(void)

{
  undefined *puVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 unaff_r10;
  int iVar5;
  undefined1 *puVar6;
  byte bVar7;
  
  puVar1 = PTR_DAT_0601acf4;
  iVar4 = *(int *)(PTR_PTR_0601acf0 +
                  (*(int *)PTR_DAT_0601ace8 * 6 + *(int *)PTR_DAT_0601acec * 2) * 4);
  iVar5 = *(int *)(PTR_PTR_0601acfc + *(int *)PTR_DAT_0601ace8 * 8);
  uVar2 = (uint)PTR_DAT_0601ace4._0_2_;
  bVar7 = 0x13;
  if ((*(uint *)PTR_DAT_0601acf4 < *(uint *)(iVar4 + uVar2)) &&
     (uVar2 = 0, *(int *)PTR_DAT_0601ad00 != 0)) {
    do {
      if (*(uint *)((bVar7 - 1) * 0xc + iVar4 + 4) <= *(uint *)puVar1) break;
      (*(code *)PTR_FUN_0601ad94)();
      bVar7 = bVar7 - 1;
    } while (bVar7 != 0);
    puVar6 = (undefined1 *)((uint)bVar7 * 0xc + iVar4);
    *(undefined4 *)(puVar6 + 4) = *(undefined4 *)puVar1;
    uVar3 = FUN_0601ae2c();
    puVar6[8] = uVar3;
    puVar6[9] = *PTR_DAT_0601ad98;
    uVar2 = *(uint *)PTR_DAT_0601ad9c & 0xff;
    puVar6[10] = (char)*(uint *)PTR_DAT_0601ad9c;
    *puVar6 = (char)unaff_r10;
    *(undefined1 **)PTR_DAT_0601ada0 = puVar6;
    *PTR_DAT_0601ada4 = bVar7;
  }
  else {
    *(undefined4 *)PTR_DAT_0601ada0 = unaff_r10;
  }
  puVar1 = PTR_DAT_0601ada8;
  if ((*(int *)PTR_DAT_0601adac < *(int *)(iVar5 + 4)) && (0 < *(int *)PTR_DAT_0601adac)) {
    *(undefined4 *)(iVar5 + 4) = *(undefined4 *)PTR_DAT_0601adac;
    *(int *)puVar1 = iVar5;
  }
  else {
    *(undefined4 *)PTR_DAT_0601ada8 = unaff_r10;
  }
  return uVar2;
}


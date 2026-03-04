/* FUN_060209AC  0x060209AC */


void FUN_060209ac(undefined1 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  
  puVar3 = PTR_DAT_06020a1c;
  puVar2 = PTR_DAT_06020a18;
  puVar1 = PTR_DAT_06020a14;
  iVar11 = (int)DAT_06020a0e;
  if (*PTR_DAT_06020a14 == '\0') {
    (*(code *)PTR_FUN_06020a24)(0,DAT_06020a20);
    *puVar1 = 1;
  }
  puVar8 = PTR_VDP2_LSTA1U_06020a2c;
  *(undefined4 *)PTR_VDP2_LSTA1U_06020a2c = DAT_06020a28;
  *(undefined2 *)(puVar8 + -10) = PTR_DAT_06020a10._0_2_;
  *(short *)puVar2 = *(short *)puVar2 + 1;
  uVar7 = 0;
  puVar8 = PTR_DAT_06020a30;
  do {
    piVar10 = (int *)(puVar8 + (uVar7 & 0xffff) * 4);
    iVar5 = (*(code *)PTR_FUN_06020a34)();
    puVar6 = DAT_06020b04;
    if (iVar5 != 0) {
      puVar6 = puVar3;
    }
    uVar7 = uVar7 + 1;
    *piVar10 = (int)puVar6 * (uint)*(ushort *)puVar2;
    puVar4 = PTR_FUN_06020b1c;
    puVar6 = PTR_DAT_06020b18;
  } while ((int)(uVar7 & 0xffff) < iVar11);
  if (*(ushort *)puVar2 < 10) {
    return;
  }
  if (((*PTR_DAT_06020b0c == '\0' && *(int *)PTR_DAT_06020b08 == 4) & *PTR_DAT_06020b10 &
      *PTR_DAT_06020b14) != 0) {
    iVar11 = (int)DAT_06020af4;
    (*(code *)PTR_FUN_06020b1c)
              (8,*(undefined4 *)(PTR_DAT_06020b18 + DAT_06020af6),(int)DAT_06020af8,
               *(int *)((int)(PTR_DAT_06020b18 + DAT_06020af6) + 4) + iVar11);
    puVar9 = (undefined4 *)(puVar6 + DAT_06020afa);
    (*(code *)puVar4)(8,*puVar9,(int)DAT_06020afc,puVar9[1] + iVar11);
    puVar9 = (undefined4 *)(puVar6 + DAT_06020afe);
    (*(code *)puVar4)(8,*puVar9,(int)DAT_06020b00,puVar9[1] + iVar11);
  }
  FUN_06020946();
  *puVar1 = 0;
  FUN_06020dee(param_1);
  return;
}


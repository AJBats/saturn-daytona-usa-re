/* FUN_060115F0  0x060115F0 */


void FUN_060115f0(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  undefined *puVar6;
  int *piVar7;
  int iVar8;
  
  puVar2 = PTR_DAT_06011660;
  puVar1 = PTR_DAT_0601165c;
  iVar8 = (int)DAT_06011658;
  FUN_0601164a();
  *(short *)puVar1 = *(short *)puVar1 + 1;
  uVar5 = 0;
  puVar6 = PTR_DAT_06011664;
  do {
    piVar7 = (int *)(puVar6 + (uVar5 & 0xffff) * 4);
    iVar3 = (*(code *)PTR_FUN_06011668)();
    puVar4 = DAT_0601166c;
    if (iVar3 != 0) {
      puVar4 = puVar2;
    }
    uVar5 = uVar5 + 1;
    *piVar7 = (int)puVar4 * (uint)*(ushort *)puVar1;
  } while ((int)(uVar5 & 0xffff) < iVar8);
  return;
}


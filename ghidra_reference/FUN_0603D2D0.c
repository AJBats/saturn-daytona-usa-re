/* FUN_0603D2D0  0x0603D2D0 */


void FUN_0603d2d0(void)

{
  ushort uVar1;
  ushort *puVar2;
  undefined *puVar3;
  ushort uVar4;
  
  puVar2 = (ushort *)PTR_DAT_0603d39c;
  puVar3 = PTR_DAT_0603d394;
  (*(code *)PTR_FUN_0603d3a0)(PTR_DAT_0603d39c,PTR_DAT_0603d398);
  uVar4 = (ushort)puVar3;
  *puVar2 = *puVar2 & uVar4;
  puVar3 = PTR_DAT_0603d3a4;
  (*(code *)PTR_FUN_0603d3a0)();
  uVar1 = (ushort)puVar3;
  *puVar2 = *puVar2 & uVar1;
  (*(code *)PTR_FUN_0603d3a0)();
  puVar2[1] = puVar2[1] & uVar4;
  (*(code *)PTR_FUN_0603d3a0)();
  puVar2[1] = puVar2[1] & uVar1;
  (*(code *)PTR_FUN_0603d3a0)();
  puVar2[2] = puVar2[2] & uVar4;
  (*(code *)PTR_FUN_0603d3a0)();
  puVar2[2] = puVar2[2] & uVar1;
  (*(code *)PTR_FUN_0603d3a0)();
  puVar2[3] = puVar2[3] & uVar4;
  (*(code *)PTR_FUN_0603d3a0)();
  puVar2[3] = puVar2[3] & uVar1;
  (*(code *)PTR_FUN_0603d3a0)();
  return;
}


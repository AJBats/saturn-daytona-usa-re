/* FUN_0603D518  0x0603D518 */


void FUN_0603d518(void)

{
  ushort uVar1;
  ushort *puVar2;
  undefined *puVar3;
  ushort uVar4;
  
  puVar2 = (ushort *)PTR_DAT_0603d5c8;
  puVar3 = PTR_DAT_0603d5c0;
  (*(code *)PTR_FUN_0603d5cc)(PTR_DAT_0603d5c8,PTR_DAT_0603d5c4);
  uVar4 = (ushort)puVar3;
  *puVar2 = *puVar2 & uVar4;
  uVar1 = DAT_0603d5be;
  (*(code *)PTR_FUN_0603d5cc)();
  *puVar2 = *puVar2 & uVar1;
  (*(code *)PTR_FUN_0603d5cc)();
  puVar2[1] = puVar2[1] & uVar4;
  (*(code *)PTR_FUN_0603d5cc)();
  puVar2[1] = puVar2[1] & uVar1;
  (*(code *)PTR_FUN_0603d5cc)();
  puVar2[2] = 0;
  (*(code *)PTR_FUN_0603d5cc)();
  puVar2[3] = puVar2[3] & uVar4;
  (*(code *)PTR_FUN_0603d5cc)();
  puVar2[3] = puVar2[3] & uVar1;
  (*(code *)PTR_FUN_0603d5cc)();
  return;
}


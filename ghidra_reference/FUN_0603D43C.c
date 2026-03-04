/* FUN_0603D43C  0x0603D43C */


void FUN_0603d43c(void)

{
  ushort uVar1;
  ushort *puVar2;
  undefined *puVar3;
  ushort uVar4;
  
  puVar2 = (ushort *)PTR_DAT_0603d50c;
  puVar3 = PTR_DAT_0603d504;
  (*(code *)PTR_FUN_0603d510)(PTR_DAT_0603d50c,PTR_DAT_0603d508);
  uVar4 = (ushort)puVar3;
  *puVar2 = *puVar2 & uVar4;
  uVar1 = DAT_0603d500;
  (*(code *)PTR_FUN_0603d510)();
  *puVar2 = *puVar2 & uVar1;
  (*(code *)PTR_FUN_0603d510)();
  puVar2[1] = puVar2[1] & uVar4;
  (*(code *)PTR_FUN_0603d510)();
  puVar2[1] = puVar2[1] & uVar1;
  (*(code *)PTR_FUN_0603d510)();
  puVar2[2] = puVar2[2] & uVar4;
  (*(code *)PTR_FUN_0603d510)();
  puVar2[2] = puVar2[2] & uVar1;
  (*(code *)PTR_FUN_0603d510)();
  puVar2[3] = puVar2[3] & uVar4;
  (*(code *)PTR_FUN_0603d510)();
  puVar2[2] = puVar2[2] & uVar1;
  (*(code *)PTR_FUN_0603d510)();
  return;
}


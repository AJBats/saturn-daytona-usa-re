/* FUN_06020B58  0x06020B58 */


void FUN_06020b58(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  *(uint *)PTR_DAT_06020c00 = *(uint *)PTR_DAT_06020c00 | 1;
  FUN_06020b20();
  (*(code *)PTR_FUN_06020c04)(0xc);
  puVar1 = PTR_DAT_06020c08;
  *(uint *)PTR_DAT_06020c08 = *(uint *)PTR_DAT_06020c08 | (uint)PTR_DAT_06020c0c;
  *(undefined2 *)PTR_DAT_06020c10 = 2;
  puVar3 = PTR_FUN_06020c18;
  puVar2 = PTR_DAT_06020c14;
  *(undefined4 *)PTR_DAT_06020c14 = 0;
  (*(code *)puVar3)();
  *(uint *)puVar1 = *(uint *)puVar1 | (uint)PTR_DAT_06020c0c;
  *(undefined2 *)PTR_DAT_06020c10 = 4;
  *(undefined4 *)puVar2 = 0;
  (*(code *)puVar3)();
  *DAT_06020c1c = 3;
  *PTR_DAT_06020c20 = 1;
  *(undefined4 *)PTR_DAT_06020c24 = 0;
  FUN_06020dd0();
  *(undefined1 *)(*(int *)PTR_DAT_06020c28 + 0x10) = 0;
  *(undefined4 *)puVar2 = 0;
  (*(code *)puVar3)();
  *(undefined4 *)puVar2 = 0;
  (*(code *)puVar3)();
  return;
}


/* FUN_0601A2BC  0x0601A2BC */


void FUN_0601a2bc(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_0601a324;
  *(uint *)PTR_DAT_0601a31c = *(uint *)PTR_DAT_0601a31c | DAT_0601a320;
  (*(code *)puVar1)();
  (*(code *)PTR_FUN_0601a324)();
  puVar1 = PTR_FUN_0601a328;
  (*(code *)PTR_FUN_0601a328)(4);
  (*(code *)puVar1)(8);
  (*(code *)puVar1)(0xc);
  (*(code *)PTR_FUN_0601a32c)();
  (*(code *)PTR_FUN_0601a338)(PTR_DAT_0601a334,PTR_DAT_0601a330,0,8);
  (*(code *)PTR_FUN_0601a338)(PTR_DAT_0601a33c,PTR_DAT_0601a330,0,9);
  *PTR_DAT_0601a340 = *PTR_DAT_0601a340 + '\x01';
  return;
}


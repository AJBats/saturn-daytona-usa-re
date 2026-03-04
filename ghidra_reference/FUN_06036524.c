/* FUN_06036524  0x06036524 */


undefined4 FUN_06036524(void)

{
  undefined4 uVar1;
  uint *unaff_r12;
  uint *unaff_r13;
  uint *unaff_r14;
  undefined1 auStack_14 [2];
  ushort uStack_12;
  byte bStack_10;
  ushort uStack_e;
  undefined1 local_c [12];
  
  (*(code *)PTR_FUN_060365bc)(local_c);
  local_c[0] = 0x50;
  uVar1 = (*(code *)PTR_FUN_060365c0)(0,local_c,auStack_14);
  *unaff_r14 = (uint)uStack_12;
  *unaff_r12 = (uint)bStack_10;
  *unaff_r13 = (uint)uStack_e;
  return uVar1;
}


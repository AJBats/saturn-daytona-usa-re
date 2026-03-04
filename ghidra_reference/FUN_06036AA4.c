/* FUN_06036AA4  0x06036AA4 */


undefined4 FUN_06036aa4(void)

{
  undefined4 uVar1;
  uint *unaff_r12;
  uint *unaff_r13;
  uint *unaff_r14;
  undefined1 auStack_14 [2];
  ushort uStack_12;
  uint uStack_10;
  undefined1 local_c [12];
  
  (*(code *)PTR_FUN_06036b38)(local_c);
  local_c[0] = 0x72;
  uVar1 = (*(code *)PTR_FUN_06036b3c)(0,local_c,auStack_14);
  *unaff_r13 = (uint)uStack_12;
  *unaff_r12 = uStack_10 >> 0x18;
  *unaff_r14 = uStack_10 & DAT_06036b40;
  return uVar1;
}


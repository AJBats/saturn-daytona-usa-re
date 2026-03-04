/* FUN_06036754  0x06036754 */


undefined4 FUN_06036754(uint *param_1)

{
  undefined4 uVar1;
  uint *unaff_r13;
  uint *unaff_r14;
  undefined1 auStack_14 [2];
  ushort uStack_12;
  uint uStack_10;
  undefined1 local_c [12];
  
  (*(code *)PTR_FUN_060367a0)(local_c);
  local_c[0] = 0x56;
  uVar1 = FUN_06036650(local_c,auStack_14);
  *unaff_r13 = (uint)uStack_12;
  *param_1 = uStack_10 >> 0x18;
  *unaff_r14 = uStack_10 & DAT_060367a8;
  return uVar1;
}


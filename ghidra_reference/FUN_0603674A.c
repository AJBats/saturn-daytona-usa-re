/* FUN_0603674A  0x0603674A */


undefined4 FUN_0603674a(uint *param_1,uint *param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_20 [2];
  ushort uStack_1e;
  uint uStack_1c;
  undefined1 auStack_18 [12];
  
  (*(code *)PTR_FUN_060367a0)(auStack_18);
  auStack_18[0] = 0x56;
  uVar1 = FUN_06036650(auStack_18,auStack_20);
  *param_2 = (uint)uStack_1e;
  *param_1 = uStack_1c >> 0x18;
  *param_3 = uStack_1c & DAT_060367a8;
  return uVar1;
}


/* FUN_06036248  0x06036248 */


undefined4 FUN_06036248(undefined1 param_1)

{
  undefined4 uVar1;
  uint *unaff_r13;
  uint *unaff_r14;
  uint local_14;
  uint uStack_10;
  undefined1 local_c [4];
  undefined1 uStack_8;
  
  (*(code *)PTR_FUN_06036298)(local_c);
  local_c[0] = 0x41;
  uStack_8 = param_1;
  uVar1 = (*(code *)PTR_FUN_060362a0)(0,local_c,&local_14);
  *unaff_r13 = local_14 & DAT_060362a4;
  *unaff_r14 = uStack_10 & DAT_060362a4;
  return uVar1;
}


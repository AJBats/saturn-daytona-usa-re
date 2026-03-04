/* FUN_06036688  0x06036688 */


undefined4 FUN_06036688(undefined1 param_1)

{
  undefined4 uVar1;
  uint *unaff_r14;
  uint local_14;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 local_c [4];
  undefined1 uStack_8;
  
  (*(code *)PTR_FUN_060366fc)(local_c);
  local_c[0] = 0x54;
  uStack_8 = param_1;
  uVar1 = (*(code *)PTR_FUN_060366f8)(0,local_c,&local_14);
  *unaff_r14 = local_14 & DAT_06036700;
  *(undefined1 *)(unaff_r14 + 1) = uStack_10;
  *(undefined1 *)((int)unaff_r14 + 5) = uStack_f;
  *(undefined1 *)((int)unaff_r14 + 6) = uStack_e;
  *(undefined1 *)((int)unaff_r14 + 7) = uStack_d;
  return uVar1;
}


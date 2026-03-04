/* FUN_06034CCC  0x06034CCC */


undefined4 FUN_06034ccc(void)

{
  undefined4 uVar1;
  uint *unaff_r14;
  uint local_14 [2];
  undefined1 local_c [12];
  
  (*(code *)PTR_FUN_06034d10)(local_c);
  local_c[0] = 6;
  uVar1 = (*(code *)PTR_FUN_06034d14)(0,local_c,local_14);
  *unaff_r14 = local_14[0] & DAT_06034d18;
  return uVar1;
}


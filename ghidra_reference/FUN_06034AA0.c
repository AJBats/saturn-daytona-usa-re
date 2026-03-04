/* FUN_06034AA0  0x06034AA0 */


undefined4 FUN_06034aa0(void)

{
  undefined4 uVar1;
  undefined1 *unaff_r14;
  undefined1 auStack_14 [2];
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 local_c [12];
  
  (*(code *)PTR_FUN_06034b44)(local_c);
  local_c[0] = 1;
  uVar1 = (*(code *)PTR_FUN_06034b48)(0,local_c,auStack_14);
  *unaff_r14 = uStack_12;
  unaff_r14[1] = uStack_11;
  unaff_r14[2] = uStack_f;
  unaff_r14[3] = uStack_e;
  unaff_r14[4] = uStack_d;
  return uVar1;
}


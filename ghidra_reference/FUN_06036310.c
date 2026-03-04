/* FUN_06036310  0x06036310 */


undefined4 FUN_06036310(void)

{
  undefined4 uVar1;
  undefined1 *unaff_r14;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 local_c [12];
  
  (*(code *)PTR_FUN_06036374)(local_c);
  local_c[0] = 0x43;
  uVar1 = (*(code *)PTR_FUN_0603637c)(0,local_c,&uStack_14);
  unaff_r14[1] = uStack_13;
  unaff_r14[2] = uStack_12;
  unaff_r14[4] = uStack_11;
  *unaff_r14 = uStack_f;
  unaff_r14[3] = uStack_e;
  unaff_r14[5] = uStack_d;
  return uVar1;
}


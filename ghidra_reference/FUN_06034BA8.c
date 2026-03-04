/* FUN_06034BA8  0x06034BA8 */


int FUN_06034ba8(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  uint unaff_r14;
  undefined1 local_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  
  (*(code *)PTR_FUN_06034bf8)(&local_c);
  local_c = 4;
  uStack_b = (undefined1)unaff_r14;
  uStack_a = param_2;
  if (((int)DAT_06034bf4 & unaff_r14) == 1) {
    for (iVar1 = (int)DAT_06034bf6; 0 < iVar1; iVar1 = iVar1 + -1) {
    }
    (*(code *)PTR_FUN_06034c7c)(0x41);
    iVar1 = (*(code *)PTR_FUN_06034c80)(0x40,&local_c);
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_06034c84)();
    }
  }
  else {
    iVar1 = (*(code *)PTR_FUN_06034c80)(0,&local_c);
  }
  return iVar1;
}


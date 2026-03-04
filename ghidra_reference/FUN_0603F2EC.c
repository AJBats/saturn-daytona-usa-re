/* FUN_0603F2EC  0x0603F2EC */


int FUN_0603f2ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int unaff_r13;
  int unaff_r14;
  char local_38 [32];
  undefined1 auStack_18 [24];
  
  FUN_0603f3da(auStack_18);
  iVar1 = 0;
  while ((0 < unaff_r13 &&
         (FUN_0603f582(auStack_18,local_38,param_3,param_4,param_1), local_38[0] != '\0'))) {
    FUN_0603f84c(unaff_r14,local_38);
    unaff_r14 = unaff_r14 + 0xc;
    unaff_r13 = unaff_r13 + -1;
    iVar1 = iVar1 + 1;
  }
  *(byte *)(unaff_r14 + -1) = *(byte *)(unaff_r14 + -1) | 0x80;
  return iVar1;
}


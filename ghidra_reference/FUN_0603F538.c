/* FUN_0603F538  0x0603F538 */


char FUN_0603f538(undefined4 *param_1)

{
  int iVar1;
  char local_c [4];
  char acStack_8 [8];
  
  FUN_0603f3f6(param_1,acStack_8);
  if ((acStack_8[0] == '\0') &&
     (iVar1 = param_1[3], param_1[3] = iVar1 + 1, iVar1 + 1 != param_1[4])) {
    (*(code *)PTR_FUN_0603f5bc)(*param_1,1,param_1[1],(int)DAT_0603f5b8);
    param_1[2] = 0;
    FUN_0603f3f6(param_1,local_c,1);
    acStack_8[0] = local_c[0];
  }
  return acStack_8[0];
}


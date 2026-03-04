/* FUN_0603B168  0x0603B168 */


undefined4
FUN_0603b168(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4,uint *param_5)

{
  undefined4 uVar1;
  int iStack_18;
  int iStack_14;
  int *piStack_10;
  undefined4 *puStack_c;
  undefined4 uStack_8;
  
  piStack_10 = param_4;
  puStack_c = param_1;
  uStack_8 = param_3;
  FUN_0603be9c(*param_1,param_2,0,0,&iStack_18,&iStack_14,param_3,param_5);
  *param_5 = *param_5 & 0x9f;
  *piStack_10 = (iStack_18 + -1) * 0x800 + iStack_14;
  uVar1 = FUN_0603b93c(0);
  return uVar1;
}


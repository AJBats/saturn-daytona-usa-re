/* FUN_0603B118  0x0603B118 */


void FUN_0603b118(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uStack_1c;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  undefined4 *puStack_10;
  undefined4 uStack_c;
  
  puStack_18 = param_2;
  uStack_14 = param_3;
  puStack_10 = param_1;
  uStack_c = param_4;
  FUN_0603be9c(*param_1,0,0,param_2,param_3,param_4,0,&uStack_1c);
  if (((uStack_1c & 8) != 0) && ((uStack_1c & 4) != 0)) {
    *puStack_18 = 0;
  }
  FUN_0603b93c(0);
  return;
}


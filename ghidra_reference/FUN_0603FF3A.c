/* FUN_0603FF3A  0x0603FF3A */


void FUN_0603ff3a(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 *param_4,int param_5
                 ,uint param_6)

{
  uint uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return;
  }
  uVar1 = 0;
  if (param_6 >> 2 != 0) {
    do {
      uVar1 = uVar1 + 1;
      *param_2 = *param_4;
      param_2 = param_2 + param_3;
      param_4 = param_4 + param_5;
    } while (uVar1 < param_6 >> 2);
  }
  FUN_0603ffe6(param_6 & 3,param_2,param_4);
  return;
}


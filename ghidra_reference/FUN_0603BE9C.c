/* FUN_0603BE9C  0x0603BE9C */


void FUN_0603be9c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,int *param_6,uint *param_7,uint *param_8)

{
  if ((*(byte *)((int)param_1 + 0x1d) & 0x60) == 0) {
    (*(code *)PTR_FUN_0603bf18)();
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *param_1;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = param_1[1];
    }
    if (param_7 != (uint *)0x0) {
      *param_7 = (uint)*(byte *)(param_1 + 7);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = param_1[3];
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = param_1[4];
    }
    if (param_8 != (uint *)0x0) {
      *param_8 = (uint)*(byte *)((int)param_1 + 0x1d);
    }
    if (param_6 != (int *)0x0) {
      *param_6 = param_1[3] - param_1[5];
    }
  }
  return;
}


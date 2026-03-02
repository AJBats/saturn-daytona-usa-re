extern int DAT_0604089c;

int * FUN_0604077C(param_1, param_2, param_3, param_4, param_5)
    int *param_1;
    int param_2;
    int param_3;
    char param_4;
    int param_5;
{

  int iVar1;

  int local_1c;

  int uStack_18;

  char local_14;

  char uStack_13;

  char uStack_12;

  char uStack_11;

  char uStack_10;

  char uStack_f;

  *param_1 = param_2;

  param_1[2] = 0;

  *(char *)(param_1 + 6) = param_4;

  param_1[3] = param_3;

  param_1[4] = 0;

  param_1[8] = 1;

  *(char *)((int)param_1 + 0x19) = 0;

  *(char *)((int)param_1 + 0x1a) = 0;

  *(char *)((int)param_1 + 0x1b) = 0;

  param_1[9] = (unsigned int)param_5;

  local_14 = *(char *)(param_1 + 6);

  uStack_13 = *(char *)((int)param_1 + 0x19);

  uStack_12 = 0;

  uStack_11 = 0;

  uStack_10 = 0;

  uStack_f = 0;

  (*(int(*)())0x06035228)();

  param_1[10] = 0xffffffff;

  iVar1 = (*(int(*)())0x06040EEC)(&uStack_18);

  if (iVar1 == 0) {

    param_1[1] = uStack_18;

    iVar1 = (*(int(*)())0x06040E88)(&local_1c);

    if (iVar1 == 0) {

      param_1[5] = local_1c;

      iVar1 = (*(int(*)())0x06041034)(local_1c,param_1[8],&local_14,0,0);

      if (iVar1 == 0) {

        iVar1 = (*(int(*)())0x060414D0)(local_1c,uStack_18,(int)DAT_0604089c);

        if (iVar1 == 0) {

          iVar1 = (*(int(*)())0x0604188C)();

          if (iVar1 != 0) {

            param_1 = (int *)0x0;

          }

        }

        else {

          param_1 = (int *)0x0;

        }

      }

      else {

        param_1 = (int *)0x0;

      }

    }

    else {

      (*(int(*)())0x06040F16)(uStack_18);

      param_1 = (int *)0x0;

    }

  }

  else {

    param_1 = (int *)0x0;

  }

  return param_1;

}

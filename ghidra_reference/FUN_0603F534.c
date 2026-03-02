extern int DAT_0603f5b8;

extern int FUN_0603f3f6();

char FUN_0603f534(param_1)
    int *param_1;
{

  int iVar1;

  char local_10 [4];

  char acStack_c [8];

  FUN_0603f3f6(param_1,acStack_c,1);

  if ((acStack_c[0] == '\0') &&

     (iVar1 = param_1[3], param_1[3] = iVar1 + 1, iVar1 + 1 != param_1[4])) {

    (*(int(*)())0x0603B21C)(*param_1,1,param_1[1],0x800);

    param_1[2] = 0;

    FUN_0603f3f6(param_1,local_10,1);

    acStack_c[0] = local_10[0];

  }

  return acStack_c[0];

}

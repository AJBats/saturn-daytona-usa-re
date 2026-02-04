extern int FUN_0603f2e0();
extern int FUN_0603f342();

int FUN_0603f0fc(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  puVar1 = 0x0603B424;

  if (param_1 != 0) {

    (*(void(*)())0x0603B31C)(param_1,param_3);

    do {

      iVar2 = (*(void(*)())puVar1)(param_1);

    } while (iVar2 != 0);

  }

  if (*param_2 == 0) {

    uVar3 = FUN_0603f2e0(param_1,param_2[2],param_2[1]);

  }

  else {

    uVar3 = FUN_0603f342(param_1,param_2[2],param_2[1]);

  }

  return uVar3;

}

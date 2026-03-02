extern int DAT_0603ac9e;

extern int FUN_0603adac();
extern int FUN_0603b74c();
extern int FUN_0603b93c();

int FUN_0603ac1c(param_1, param_2, param_3)
    int param_1;
    unsigned int param_2;
    int *param_3;
{

  int iVar1;

  if ((param_1 < 1) || (0x18 < param_1)) {

    iVar1 = -5;

  }

  else if ((param_2 & 3) == 0) {

    if ((param_3 == (int *)0x0) ||

       ((((*param_3 == 0 || (*param_3 == 1)) && (1 < param_3[1])) && (param_3[2] != 0)))) {

      *(unsigned int *)0x060A4D14 = param_2;

      FUN_0603b74c();

      iVar1 = (*(int(*)())0x0604000C)(param_3 == (int *)0x0);

      if (iVar1 != 0) {

        iVar1 = FUN_0603b93c();

        return iVar1;

      }

      if ((*(unsigned int *)((int)DAT_0603ac9e + *(int *)0x060A4D14) & 1) == 0) {

        iVar1 = FUN_0603b93c(0xfffffffe);

        return iVar1;

      }

      if (param_3 == (int *)0x0) {

        iVar1 = (*(int(*)())0x0603F22C)();

        if (iVar1 < 0) {

          iVar1 = FUN_0603b93c(0xfffffff9);

          return iVar1;

        }

      }

      else {

        iVar1 = (*(int(*)())0x0603BC12)(param_3);

        if (iVar1 < 1) {

          iVar1 = FUN_0603b93c(0xffffffff);

          return iVar1;

        }

      }

      FUN_0603adac(param_3);

      FUN_0603b93c(0);

    }

    else {

      iVar1 = -4;

    }

  }

  else {

    iVar1 = -0x15;

  }

  return iVar1;

}

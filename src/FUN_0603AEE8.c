extern int DAT_0603af70;

extern int DAT_0603af72;

extern int PTR_DAT_0603af74;

extern int PTR_DAT_0603af74;

extern int FUN_0603b81e();
extern int FUN_0603b93c();
extern int FUN_0603ba2c();

int FUN_0603aee8(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  puVar1 = 0x060A4D14;

  if ((*(int *)(*(int *)0x060A4D14 + (int)DAT_0603af70) == 0) ||

     ((-1 < param_1 && (param_1 < *(int *)(*(int *)0x060A4D14 + (int)DAT_0603af72))))) {

    iVar2 = FUN_0603b81e();

    if (iVar2 == 0) {

      FUN_0603b93c(0xffffffed);

      iVar2 = 0;

    }

    else {

      if (*(int *)(*(int *)puVar1 + (int)DAT_0603af70) == 0) {

        uVar3 = 0;

      }

      else if (*(int *)(*(int *)puVar1 + (int)PTR_DAT_0603af74) == 0) {

        uVar3 = (*(void(*)())0x0603F1E0)(param_1,*(int *)(*(int *)puVar1 + (int)DAT_0603af70));

      }

      else {

        uVar3 = (*(void(*)())0x0603F1F0)(param_1,*(int *)(*(int *)puVar1 + (int)DAT_0603af70));

      }

      iVar2 = FUN_0603ba2c(iVar2,uVar3,param_1);

      if (iVar2 == 0) {

        FUN_0603b93c(0xfffffff6);

      }

      else {

        FUN_0603b93c(0);

      }

    }

  }

  else {

    FUN_0603b93c(0xfffffff6);

    iVar2 = 0;

  }

  return iVar2;

}

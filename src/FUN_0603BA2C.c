extern int DAT_0603bae6;

extern void FUN_0603bc86();

int FUN_0603ba2c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  int uVar1;

  int iVar2;

  int uVar3;

  int uVar4;

  uVar1 = (*0x0603F93C)(param_1 + 0x40);

  if (param_1 == 0) {

    param_1 = 0;

  }

  else {

    iVar2 = FUN_0603bc86(param_1,param_1,param_3,param_2);

    if (iVar2 == 0) {

      param_1 = 0;

    }

    else {

      uVar3 = (*0x0603EF34)(DAT_0603bae6 + param_1,0,0xffffffff);

      uVar4 = (*0x0603F8B8)

                        (param_1 + 0x90,uVar3,0x0603EF64,0x0603EFD4,0x0603EFE6,

                         0x0603F036,0x0603F070);

      (*0x0603F9B8)(uVar1,iVar2,uVar4);

      *(int *)(param_1 + 4) = uVar3;

      *(char *)(param_1 + 0x11) = 0;

      *(char *)(param_1 + 0x12) = 0;

      *(int *)(param_1 + 8) = uVar1;

    }

  }

  return param_1;

}

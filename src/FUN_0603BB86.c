extern int DAT_0603bbb4;

extern int DAT_0603bbb6;

extern int DAT_0603bc50;

extern int DAT_0603bc52;

extern int DAT_0603bc54;

extern int FUN_0603bac6();

int FUN_0603bb86(param_1)
    int *param_1;
{

  char *puVar1;

  int uVar2;

  int iVar3;

  puVar1 = 0x060A4D14;

  if ((*(unsigned int *)((int)DAT_0603bbb4 + *(int *)0x060A4D14) & 1) == 0) {

    uVar2 = 0;

  }

  else {

    iVar3 = FUN_0603bac6(*(int *)0x060A4D14 + (int)DAT_0603bbb6);

    if (iVar3 == 0) {

      uVar2 = 0;

    }

    else {

      iVar3 = (int)DAT_0603bc50 + *(int *)puVar1 + (int)DAT_0603bc52;

      (*(void(*)())0x060360FC)(param_1,iVar3 + 6,4);

      *param_1 = *param_1 + (int)DAT_0603bc54;

      (*(void(*)())0x060360FC)(param_1 + 1,iVar3 + 0xe,4);

      if (param_1[1] == 0) {

        uVar2 = 0;

      }

      else {

        *(char *)((int)param_1 + 10) = 0;

        *(char *)((int)param_1 + 0xb) = 0;

        *(char *)(param_1 + 2) = 0;

        *(char *)((int)param_1 + 9) = 0;

        uVar2 = 1;

      }

    }

  }

  return uVar2;

}

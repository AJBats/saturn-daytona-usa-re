extern int DAT_0603be0e;

extern int PTR_DAT_0603bd64;

extern int PTR_DAT_0603bd64;

int FUN_0603bd1c(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x060A4D14;

  if ((*(int **)(*(int *)0x060A4D14 + 0xa8) == (int *)0x0

      ) || (*(int **)(*(int *)0x060A4D14 + 0xa8) == param_1)) {

    iVar2 = (*(int(*)())(*(int *)((unsigned int)*(unsigned char *)(param_1 + 4) << 4 + *(int *)0x060A4D14 + 4)))(*param_1);

    if (iVar2 == 0) {

      *(int **)(*(int *)puVar1 + 0xa8) = param_1;

    }

    else if ((iVar2 == 2) && (*(int **)(*(int *)puVar1 + 0xa8) == param_1)) {

      *(int *)(*(int *)puVar1 + 0xa8) = 0;

    }

  }

  else {

    iVar2 = 5;

  }

  return iVar2;

}

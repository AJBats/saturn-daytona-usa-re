void FUN_0603853c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  short uVar6;

  puVar4 = 0x060A3EE8;

  puVar3 = 0x060A3E68;

  puVar2 = 0x060A3DF8;

  puVar1 = 0x060A4C78;

  iVar5 = *(int *)0x060635A8;

  if (iVar5 == 1) {

    *(int *)(0x060A3E68 + 0x44) = param_1;

    *(int *)(puVar3 + 0x48) = param_2;

    if ((*(int *)0x060A4C44 == 0) ||

       ((*(int *)0x060A4C4C != 0 && (*(int *)0x060A4C70 != 0)))) {

      *(int *)puVar1 = 0;

    }

    else {

      *(int *)puVar1 = param_3;

    }

    if (*(int *)puVar1 != 0) {

      (*0x0603DDFC)(0,0);

      return;

    }

  }

  else if (iVar5 == 2) {

    *(int *)(0x060A3EE8 + 0x44) = param_1;

    *(int *)(puVar4 + 0x48) = param_2;

    if ((*(int *)0x060A4C48 == 0) ||

       ((*(int *)0x060A4C50 != 0 && (*(int *)0x060A4C74 != 0)))) {

      *(int *)(puVar1 + 4) = 0;

    }

    else {

      *(int *)(puVar1 + 4) = param_3;

    }

    if (*(int *)(puVar1 + 4) != 0) {

      (*0x0603DDFC)(0,0);

      return;

    }

  }

  else if (iVar5 == 4) {

    *(int *)0x060A3DF8 = param_1;

    *(int *)(puVar2 + 4) = param_2;

  }

  else if (iVar5 == 8) {

    *(int *)(0x060A3DF8 + 0x10) = param_1;

    *(int *)(puVar2 + 0x14) = param_2;

  }

  else {

    uVar6 = (short)((unsigned int)param_1 >> 0x10);

    if (iVar5 == 0x10) {

      *(short *)(0x060A3DF8 + 0x20) = uVar6;

      iVar5 = 0x22;

    }

    else {

      if (iVar5 != 0x20) {

        return;

      }

      *(short *)(0x060A3DF8 + 0x24) = uVar6;

      iVar5 = 0x26;

    }

    *(short *)(puVar2 + iVar5) = (short)((unsigned int)param_2 >> 0x10);

  }

  return;

}

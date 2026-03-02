int FUN_06038642(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  short sVar6;

  short sVar7;

  puVar4 = 0x060A3EE8;

  puVar3 = 0x060A3E68;

  puVar2 = 0x060A3DF8;

  puVar1 = 0x060A4C78;

  iVar5 = *(int *)0x060635A8;

  if (iVar5 == 1) {

    *(int *)(0x060A3E68 + 0x44) = *(int *)(0x060A3E68 + 0x44) + param_1;

    *(int *)(puVar3 + 0x48) = *(int *)(puVar3 + 0x48) + param_2;

    if ((*(int *)0x060A4C44 == 0) ||

       ((*(int *)0x060A4C4C != 0 && (*(int *)0x060A4C70 != 0)))) {

      *(int *)puVar1 = 0;

    }

    else {

      *(int *)puVar1 = *(int *)puVar1 + param_3;

    }

    iVar5 = 0;

    if (*(int *)puVar1 != 0) {

      iVar5 = (*(int(*)())0x0603DDFC)(0,0);

      return iVar5;

    }

  }

  else if (iVar5 == 2) {

    *(int *)(0x060A3EE8 + 0x44) = *(int *)(0x060A3EE8 + 0x44) + param_1;

    *(int *)(puVar4 + 0x48) = *(int *)(puVar4 + 0x48) + param_2;

    if ((*(int *)0x060A4C48 == 0) ||

       ((*(int *)0x060A4C50 != 0 && (*(int *)0x060A4C74 != 0)))) {

      *(int *)(puVar1 + 4) = 0;

    }

    else {

      *(int *)(puVar1 + 4) = *(int *)(puVar1 + 4) + param_3;

    }

    iVar5 = 0;

    if (*(int *)(puVar1 + 4) != 0) {

      iVar5 = (*(int(*)())0x0603DDFC)(0,0);

      return iVar5;

    }

  }

  else if (iVar5 == 4) {

    *(int *)0x060A3DF8 = *(int *)0x060A3DF8 + param_1;

    *(int *)(puVar2 + 4) = *(int *)(puVar2 + 4) + param_2;

  }

  else if (iVar5 == 8) {

    *(int *)(0x060A3DF8 + 0x10) = *(int *)(0x060A3DF8 + 0x10) + param_1;

    *(int *)(puVar2 + 0x14) = *(int *)(puVar2 + 0x14) + param_2;

  }

  else {

    sVar6 = (short)((unsigned int)param_1 >> 0x10);

    sVar7 = (short)((unsigned int)param_2 >> 0x10);

    if (iVar5 == 0x10) {

      *(short *)(0x060A3DF8 + 0x20) = *(short *)(0x060A3DF8 + 0x20) + sVar6;

      *(short *)(puVar2 + 0x22) = *(short *)(puVar2 + 0x22) + sVar7;

      iVar5 = 0x22;

    }

    else if (iVar5 == 0x20) {

      *(short *)(0x060A3DF8 + 0x24) = *(short *)(0x060A3DF8 + 0x24) + sVar6;

      *(short *)(puVar2 + 0x26) = *(short *)(puVar2 + 0x26) + sVar7;

      iVar5 = 0x26;

    }

  }

  return iVar5;

}

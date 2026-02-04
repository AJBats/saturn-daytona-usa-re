int FUN_060409e6(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  int local_1c;

  int iStack_18;

  puVar1 = 0x0604188C;

  if (param_2 < 0) {

    param_2 = 0;

  }

  if (param_3 == 1) {

    iVar2 = *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) + param_2;

    local_1c = param_2;

  }

  else {

    if (*(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) == param_2) {

      return param_2;

    }

    iVar2 = (*(void(*)())0x060411A0)(*(int *)(param_1 + 4),0,0x0000FFFF,&local_1c,0)

    ;

    if (iVar2 != 0) {

      return -1;

    }

    iVar2 = (*(void(*)())puVar1)();

    if (iVar2 != 0) {

      return -1;

    }

    iVar2 = param_2;

    if (local_1c < 0) {

      local_1c = 0;

    }

  }

  if (*(int *)(param_1 + 0x24) == 0) {

    if ((*(int *)(param_1 + 8) <= iVar2) &&

       (iVar2 < *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8))) {

      local_1c = iVar2 - *(int *)(param_1 + 8);

    }

    if (0 < local_1c) {

      (*(void(*)())0x060412B2)(*(int *)(param_1 + 4),0,local_1c);

      iVar3 = (*(void(*)())puVar1)();

      if (iVar3 != 0) {

        return -1;

      }

    }

    *(int *)(param_1 + 8) = iVar2;

    *(int *)(param_1 + 0x10) = 0;

  }

  else if (*(int *)(param_1 + 0x24) == 1) {

    if ((iVar2 < *(int *)(param_1 + 8)) ||

       (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 8) + 1 < iVar2)) {

      iStack_18 = param_1;

      (*(void(*)())0x060412B2)(*(int *)(param_1 + 4),0,0x0000FFFF);

      iVar3 = (*(void(*)())puVar1)();

      if (iVar3 == 0) {

        return -1;

      }

      *(int *)(param_1 + 8) = iVar2;

    }

    *(int *)(param_1 + 0x10) = iVar2 - *(int *)(param_1 + 8);

  }

  return *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10);

}

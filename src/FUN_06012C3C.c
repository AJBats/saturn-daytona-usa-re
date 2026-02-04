extern void FUN_06012bdc();

void FUN_06012c3c(param_1, param_2)
    int param_1;
    int param_2;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  int local_2c;

  puVar4 = 0x0600026C;

  puVar3 = 0x0603AE08;

  puVar2 = 0x06084AEC;

  puVar1 = 0x0603B1B6;

  iVar6 = 0;

  while (*puVar2 != '\0') {

    FUN_06012bdc();

  }

  do {

    iVar5 = (*puVar3)(param_1);

    iVar6 = iVar6 + 1;

    if (4 < iVar6) {

      (**(void **)puVar4)();

    }

  } while (iVar5 < 0);

  local_2c = 0;

  do {

    iVar6 = (*puVar1)(iVar5,0,param_2,0xffffffff);

    local_2c = local_2c + 1;

    if (4 < local_2c) {

      (**(void **)puVar4)();

    }

  } while (iVar6 < 0);

  return;

}

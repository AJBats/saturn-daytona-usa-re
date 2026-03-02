extern int DAT_060401e8;

extern int FUN_060400b4();

unsigned int * FUN_060400d6(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int param_3;
{

  int iVar1;

  unsigned int uVar2;

  unsigned int local_20;

  int uStack_1c;

  char uStack_18;

  char uStack_17;

  char uStack_16;

  char uStack_15;

  if (param_2 == (unsigned int *)0x0) {

    *param_1 = 0x40000000 | param_3;

    iVar1 = (*(int(*)())0x060415C8)(param_3,&local_20);

    if (iVar1 != 0) {

      return (unsigned int *)0x0;

    }

    param_1[1] = local_20;

    uVar2 = FUN_060400b4(uStack_15);

    param_1[3] = uVar2;

    uVar2 = (*(int(*)())0x06035F44)();

    param_1[4] = uVar2;

    (*(int(*)())0x06036BE4)(uStack_1c);

    uVar2 = (*(int(*)())0x06036BE4)();

    param_1[5] = uVar2;

    *(char *)(param_1 + 7) = uStack_16;

    *(char *)((int)param_1 + 0x1d) = uStack_15;

    *(char *)((int)param_1 + 0x1e) = uStack_18;

    *(char *)((int)param_1 + 0x1f) = uStack_17;

  }

  else {

    *param_1 = param_3;

    param_1[1] = *param_2;

    uVar2 = FUN_060400b4(*(char *)((int)param_2 + 0xb));

    param_1[3] = uVar2;

    param_1[4] = (int)DAT_060401e8 + param_2[1] >> 0xb;

    (*(int(*)())0x06036BE4)();

    uVar2 = (*(int(*)())0x06036BE4)();

    param_1[5] = uVar2;

    *(char *)(param_1 + 7) = *(char *)((int)param_2 + 10);

    *(char *)((int)param_1 + 0x1d) = *(char *)((int)param_2 + 0xb);

    *(char *)((int)param_1 + 0x1e) = *(char *)(param_2 + 2);

    *(char *)((int)param_1 + 0x1f) = *(char *)((int)param_2 + 9);

  }

  param_1[6] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[10] = 0x7FFFFFFF;

  return param_1;

}

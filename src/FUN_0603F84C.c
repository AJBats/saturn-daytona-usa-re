extern int DAT_0603f8ac;

extern int DAT_0603f8ae;

extern int PTR_DAT_0603f8b0;

extern int PTR_DAT_0603f8b0;

void FUN_0603f84c(param_1, param_2)
    int *param_1;
    int param_2;
{

  char cVar1;

  char cVar2;

  char cVar3;

  char cVar4;

  unsigned int uVar5;

  *param_1 = *(int *)(param_2 + 4);

  param_1[1] = *(int *)(param_2 + 8);

  *(char *)((int)param_1 + 10) = *(char *)(param_2 + 0x1d);

  uVar5 = (unsigned int)*(unsigned short *)(param_2 + 0xc);

  if (((unsigned int)0x00008000 & uVar5) == 0) {

    cVar4 = '\0';

  }

  else {

    cVar4 = '\x10';

  }

  if (((int)DAT_0603f8ac & uVar5) == 0) {

    cVar1 = '\0';

  }

  else {

    cVar1 = '\b';

  }

  if (((int)DAT_0603f8ae & uVar5) == 0) {

    cVar2 = '\0';

  }

  else {

    cVar2 = '\x04';

  }

  if (((int)PTR_DAT_0603f8b0 & uVar5) == 0) {

    cVar3 = '\0';

  }

  else {

    cVar3 = '\x02';

  }

  *(char *)((int)param_1 + 0xb) = cVar4 + cVar1 + cVar2 + cVar3;

  *(char *)(param_1 + 2) = *(char *)(param_2 + 0xe);

  *(char *)((int)param_1 + 9) = *(char *)(param_2 + 0xf);

  return;

}

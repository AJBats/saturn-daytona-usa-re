extern int DAT_06034bf4;

extern int DAT_06034bf6;

int FUN_06034b9a(param_1, param_2, param_3, param_4)
    unsigned int param_1;
    short param_2;
    char param_3;
    char param_4;
{

  int iVar1;

  char local_1c;

  char uStack_1b;

  short uStack_1a;

  char uStack_16;

  char uStack_15;

  (*(int(*)())0x06035E90)(&local_1c);

  local_1c = 4;

  uStack_1b = (char)param_1;

  uStack_1a = param_2;

  uStack_16 = param_3;

  uStack_15 = param_4;

  if ((0x81 & param_1) == 1) {

    for (iVar1 = (int)DAT_06034bf6; 0 < iVar1; iVar1 = iVar1 + -1) {

    }

    (*(int(*)())0x06035C92)(0x41);

    iVar1 = (*(int(*)())0x06035EC8)(0x40,&local_1c);

    if (iVar1 == 0) {

      (*(int(*)())0x06035C80)();

    }

  }

  else {

    iVar1 = (*(int(*)())0x06035EC8)(0,&local_1c);

  }

  return iVar1;

}

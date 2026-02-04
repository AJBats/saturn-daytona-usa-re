extern int DAT_06008718;

extern int DAT_0600871a;

extern int DAT_0600871c;

extern int DAT_0600871e;

extern int FUN_06008730();

void FUN_060086c0(param_1)
    int *param_1;
{

  int iVar1;

  int *piVar2;

  char cVar3;

  cVar3 = '\x01';

  piVar2 = (int *)0x0607E940;

  (*(int(*)())0x06034F78)();

  (*(int(*)())0x06034F78)();

  *(int *)(*piVar2 + 0x1b8) = *param_1;

  iVar1 = param_1[1];

  *(int *)(*piVar2 + (int)DAT_0600871a) = iVar1;

  iVar1 = iVar1 + -0x28;

  *(int *)(*piVar2 + (int)DAT_0600871c) = iVar1;

  *(int *)(*piVar2 + 0x208) = iVar1;

  *(int *)0x0607EBEC = *(int *)0x0607EBEC + cVar3;

  FUN_06008730();

  return;

}

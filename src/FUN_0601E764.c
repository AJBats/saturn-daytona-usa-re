int FUN_0601e764(param_1, param_2, param_3)
    unsigned short param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  puVar1 = 0x20100063;

  iVar2 = (*0x06035C1C)(param_2);

  if (0xb < iVar2) {

    *(char *)(param_2 + 0xb) = 0;

  }

  do {

  } while ((*puVar1 & 1) == 1);

  *puVar1 = 1;

  *0x2010001F = 0x1a;

  do {

  } while ((*puVar1 & 1) != 0);

  uVar3 = (**(void **)(*(int *)0x06000354 + 0x14))

                    (*(short *)(0x06087094 + (unsigned int)param_1 * 0x20 + 0x1c),param_2,param_3

                    );

  do {

  } while ((*puVar1 & 1) == 1);

  *puVar1 = 1;

  *0x2010001F = 0x19;

  do {

  } while ((*puVar1 & 1) != 0);

  return uVar3;

}

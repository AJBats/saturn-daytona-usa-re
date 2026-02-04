extern int FUN_0601f4b4();

int FUN_0601e810(param_1, param_2, param_3)
    unsigned short param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int uVar6;

  puVar3 = 0x20100063;

  puVar2 = 0x060877D8;

  puVar1 = 0x0605E06C;

  iVar5 = (*(int(*)())0x06035C1C)(param_2);

  if (0xb < iVar5) {

    *(char *)(param_2 + 0xb) = 0;

  }

  iVar5 = (*(int(*)())0x06035C1C)(puVar1 + (unsigned int)(unsigned char)*puVar2 * 0xb);

  if (10 < iVar5) {

    puVar1[(unsigned int)(unsigned char)*puVar2 * 0xb + 10] = 0;

  }

  FUN_0601f4b4(0x060877E8);

  puVar4 = 0x060877B4;

  (*(int(*)())0x06035C08)(0x060877B4,param_2);

  (*(int(*)())0x06035C08)(puVar4 + 0xc,puVar1 + (unsigned int)(unsigned char)*puVar2 * 0xb);

  puVar4[0x17] = 0;

  uVar6 = (*(int(*)())(*(int *)(*(int *)0x06000354 + 0x28)))(0x060877E8);

  *(int *)(puVar4 + 0x18) = uVar6;

  *(int *)(puVar4 + 0x1c) = *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)*((int)(int)puVar2 << 2));

  do {

  } while ((*puVar3 & 1) == 1);

  *puVar3 = 1;

  *(int *)0x2010001F = 0x1a;

  do {

  } while ((*puVar3 & 1) != 0);

  uVar6 = (*(int(*)())(*(int *)(*(int *)0x06000354 + 0x10)))(*(short *)(0x06087094 + (unsigned int)(param_1 << 5) + 0x1c),

                     0x060877B4,param_3,0);

  do {

  } while ((*puVar3 & 1) == 1);

  *puVar3 = 1;

  *(int *)0x2010001F = 0x19;

  do {

  } while ((*puVar3 & 1) != 0);

  return uVar6;

}

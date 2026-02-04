extern int DAT_060078ca;

void FUN_06007790(param_1, param_2, param_3)
    unsigned short *param_1;
    short param_2;
    int param_3;
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar5;

  unsigned short uVar6;

  puVar4 = 0x0606A4F4;

  puVar3 = 0x0606A4EC;

  puVar2 = 0x06063F64;

  if (*param_1 == 10) {

    *(int *)0x06063F60 = *(int *)(0x0606A4EC << 3) + *(int *)0x06063F5C;

  }

  uVar1 = param_1[1];

  *(short *)(0x060684EC + (unsigned int)*((int)(int)param_1 << 1)) = (short)*(int *)puVar4;

  *(int *)(puVar2 + *(int *)((int)(int)puVar4 << 3)) = *(int *)puVar3;

  uVar5 = *param_1;

  if (((uVar5 == 0xd) || (uVar5 == 0xe)) || (uVar5 == 0xf)) {

    uVar6 = uVar1 & DAT_060078ca;

    uVar5 = (*(int(*)())0x06034FE0)();

    *(unsigned short *)(puVar2 + *(int *)((int)(int)puVar4 << 3) + 4) = uVar5 | uVar6;

    *(int *)0x0606A4F0 = *(int *)puVar3;

  }

  else {

    *(unsigned short *)(puVar2 + *(int *)((int)(int)puVar4 << 3) + 4) = uVar1;

  }

  *(unsigned short *)(puVar2 + *(int *)((int)(int)puVar4 << 3) + 6) = param_1[2] + (param_2 << 2);

  (*(int(*)())0x06028654)(*(int *)(param_1 + 4) + param_3,*(int *)((int)(int)puVar3 << 3) + *(int *)0x06063F5C);

  *(int *)puVar4 = *(int *)puVar4 + 1;

  *(int *)puVar3 = *(int *)puVar3 + ((int)((unsigned int)(uVar1 >> 8 & 0x3f) * (unsigned int)(uVar1 & 0xff)) >> 1);

  return;

}

extern int DAT_060076e2;

extern int DAT_0600777e;

void FUN_06007658(param_1, param_2, param_3, param_4)
    unsigned short param_1;
    unsigned short param_2;
    short param_3;
    int param_4;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  unsigned short uVar6;

  puVar3 = 0x0606A4F4;

  puVar2 = 0x0606A4EC;

  puVar1 = 0x06063F64;

  if (param_1 == 10) {

    *(int *)0x06063F60 = *(int *)(0x0606A4EC << 3) + *(int *)0x06063F5C;

  }

  uVar5 = DAT_060076e2;

  uVar4 = param_2 & DAT_060076e2;

  *(short *)(0x060684EC + (unsigned int)(param_1 << 1)) = (short)*(int *)puVar3;

  *(int *)(puVar1 + *(int *)((int)(int)puVar3 << 3)) = *(int *)puVar2;

  if (((param_1 == 0xd) || (param_1 == 0xe)) || (param_1 == 0xf)) {

    uVar6 = DAT_0600777e & param_2;

    uVar5 = (*(int(*)())0x06034FE0)(param_2,param_2 & uVar5);

    *(unsigned short *)(puVar1 + *(int *)((int)(int)puVar3 << 3) + 4) = uVar5 | uVar6;

    *(int *)0x0606A4F0 = *(int *)puVar2;

  }

  else {

    *(unsigned short *)(puVar1 + *(int *)((int)(int)puVar3 << 3) + 4) = param_2;

  }

  *(short *)(puVar1 + *(int *)((int)(int)puVar3 << 3) + 6) = param_3;

  (*(int(*)())0x06028654)(param_4,*(int *)((int)(int)puVar2 << 3) + *(int *)0x06063F5C);

  *(int *)puVar3 = *(int *)puVar3 + 1;

  *(int *)puVar2 = *(int *)puVar2 + ((int)((unsigned int)(param_2 >> 8 & 0x3f) * (unsigned int)uVar4) >> 1);

  return;

}

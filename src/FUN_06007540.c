void FUN_06007540(param_1, param_2, param_3)
    unsigned int param_1;
    unsigned int param_2;
    short param_3;
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  int *puVar4;

  puVar2 = 0x0606A4F4;

  uVar1 = *(unsigned short *)(0x060684EC + (param_2 & 0xffff) << 1);

  *(short *)(0x060684EC + (param_1 & 0xffff) << 1) = (short)*(int *)0x0606A4F4;

  puVar3 = 0x06063F64;

  puVar4 = (int *)(0x06063F64 + (unsigned int)(uVar1 << 3));

  *(int *)(0x06063F64 + *(int *)((int)(int)puVar2 << 3)) = *puVar4;

  *(short *)(puVar3 + *(int *)((int)(int)puVar2 << 3) + 4) = *(short *)(puVar4 + 1);

  *(short *)(puVar3 + *(int *)((int)(int)puVar2 << 3) + 6) = param_3;

  *(int *)puVar2 = *(int *)puVar2 + 1;

  return;

}

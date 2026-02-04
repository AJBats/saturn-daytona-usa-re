void FUN_06007590(param_1, param_2)
    unsigned short *param_1;
    short param_2;
{

  char *puVar1;

  char *puVar2;

  unsigned short uVar3;

  puVar2 = 0x06063F64;

  puVar1 = 0x0606A4F4;

  uVar3 = *(unsigned short *)(0x060684EC + (unsigned int)param_1[1] * 2);

  *(short *)(0x060684EC + (unsigned int)*param_1 * 2) = (short)*(int *)0x0606A4F4;

  *(int *)(puVar2 + *(int *)puVar1 * 8) = *(int *)(puVar2 + (unsigned int)uVar3 * 8);

  *(short *)(puVar2 + *(int *)puVar1 * 8 + 4) =

       *(short *)((int)(puVar2 + (unsigned int)uVar3 * 8) + 4);

  if (param_1[1] < 0xd) {

    uVar3 = param_1[2];

  }

  else {

    uVar3 = param_1[2] + param_2 * 4;

  }

  *(unsigned short *)(puVar2 + *(int *)puVar1 * 8 + 6) = uVar3;

  *(int *)puVar1 = *(int *)puVar1 + 1;

  return;

}

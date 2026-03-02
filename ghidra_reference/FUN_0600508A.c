void FUN_0600508a(param_1, param_2, param_3)
    unsigned short *param_1;
    int param_2;
    unsigned int param_3;
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  unsigned short *puVar4;

  puVar1 = 0x06063D90;

  if ((param_3 & 4) != 0) {

    puVar4 = *(unsigned short **)0x06063D90;

    uVar3 = ((unsigned int)param_1[1] * (unsigned int)*param_1 + 2) << 1 & 0xffff;

    (*(int(*)())0x0602761E)(puVar4,param_1,uVar3);

    *(unsigned int *)puVar1 = *(int *)puVar1 + uVar3;

    *(unsigned int *)0x06063D94 = *(int *)0x06063D94 + uVar3;

    param_1 = puVar4;

  }

  puVar2 = 0x06059F10;

  puVar1 = 0x06063750;

  *(int *)(0x06063750 + *(int *)(0x06059F10 << 3) + 4) = param_2;

  *(unsigned short **)(puVar1 + *(int *)((int)(int)puVar2 << 3)) = param_1;

  *(int *)puVar2 = *(int *)puVar2 + 1;

  return;

}

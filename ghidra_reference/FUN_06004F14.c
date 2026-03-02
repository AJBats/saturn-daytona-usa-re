void FUN_06004f14(param_1, param_2, param_3, param_4)
    short *param_1;
    unsigned int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar5;

  short *psVar6;

  puVar4 = 0x06059F10;

  puVar3 = 0x06059F18;

  puVar2 = 0x06059F1C;

  puVar1 = 0x06063750;

  if ((param_2 & 4) != 0) {

    uVar5 = (param_1[1] * *param_1 + 2) << 1;

    psVar6 = *(short **)0x06063D90;

    (*(int(*)())0x0602761E)(psVar6,param_1,uVar5);

    *(unsigned int *)0x06063D90 = *(int *)0x06063D90 + (unsigned int)uVar5;

    *(unsigned int *)0x06063D94 = *(int *)0x06063D94 + (unsigned int)uVar5;

    param_1 = psVar6;

  }

  if (param_3 == 0) {

    *(int *)(puVar1 + (*(int *)puVar4 << 3) + 4) =

         *(int *)(puVar1 + ((*(int *)puVar4 + -1) << 3) + 4);

  }

  else if ((param_2 & 3) == 0) {

    *(int *)(puVar1 + *(int *)((int)(int)puVar4 << 3) + 4) = *(int *)puVar3;

    if ((param_2 & 8) == 0) {

      (*(int(*)())0x0602761E)(0x25E00000 + *(int *)((int)(int)puVar3 << 5),param_3,param_4 << 5);

    }

    else {

      (*(int(*)())0x06028654)(param_3,0x25E00000 + *(int *)((int)(int)puVar3 << 5));

    }

    *(int *)puVar3 = *(int *)puVar3 + param_4;

  }

  else {

    *(int *)(puVar1 + *(int *)((int)(int)puVar4 << 3) + 4) = *(int *)puVar2;

    if ((param_2 & 8) == 0) {

      (*(int(*)())0x0602761E)(0x25E20000 + *(int *)((int)(int)puVar2 << 5),param_3,param_4 << 5);

    }

    else {

      (*(int(*)())0x06028654)(param_3,0x25E20000 + *(int *)((int)(int)puVar2 << 5));

    }

    *(int *)puVar2 = *(int *)puVar2 + param_4;

  }

  *(short **)(puVar1 + *(int *)((int)(int)puVar4 << 3)) = param_1;

  *(int *)puVar4 = *(int *)puVar4 + 1;

  return;

}

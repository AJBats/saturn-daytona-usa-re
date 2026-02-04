extern int DAT_060203be;

extern void FUN_06020414();

int FUN_06020366(param_1)
    unsigned int param_1;
{

  unsigned short uVar1;

  char *puVar2;

  int uVar3;

  unsigned char *pbVar4;

  unsigned char *pbVar5;

  puVar2 = 0x0604BD72;

  uVar1 = DAT_060203be;

  pbVar4 = *(unsigned char **)(0x0605F458 + (param_1 & 0xff) * 4);

  uVar3 = FUN_06020414(**(short **)(0x0605F478 + (unsigned int)pbVar4[2] * 4),*pbVar4,pbVar4[1],

                       *(short **)(0x0605F478 + (unsigned int)pbVar4[2] * 4) + 2);

  while (pbVar5 = pbVar4 + 3, *pbVar5 != uVar1) {

    uVar3 = FUN_06020414(*(short *)(puVar2 + (unsigned int)pbVar4[5] * 0x2a),*pbVar5,pbVar4[4],

                         (short *)((int)(puVar2 + (unsigned int)pbVar4[5] * 0x2a) + 4));

    pbVar4 = pbVar5;

  }

  return uVar3;

}

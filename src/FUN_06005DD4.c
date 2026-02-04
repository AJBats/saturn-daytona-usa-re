extern int DAT_06005eae;

extern int DAT_06005eb0;

extern int DAT_06005eb2;

extern int DAT_06005eb4;

char * FUN_06005dd4(param_1)
    int param_1;
{

  char *puVar1;

  int *puVar2;

  int uVar3;

  unsigned int uVar4;

  char cVar5;

  int *puVar6;

  int *puVar7;

  unsigned int *puVar8;

  int *puVar9;

  puVar1 = 0x06063E14;

  puVar9 = (int *)(int)DAT_06005eae;

  puVar7 = puVar9 + 1;

  puVar6 = (int *)(int)DAT_06005eb0;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = param_1;

  puVar1[8] = 0;

  puVar8 = (unsigned int *)(int)DAT_06005eb2;

  uVar4 = *puVar8;

  puVar2 = (int *)(int)DAT_06005eb4;

  uVar3 = *puVar2;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[7] = (char)uVar4 + '\x01';

  uVar4 = *puVar8;

  uVar3 = *puVar2;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[6] = (char)uVar4 + '\x01';

  uVar4 = *puVar8;

  uVar3 = *puVar2;

  *puVar6 = 6;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[5] = 0xd;

  puVar1[4] = (char)uVar4 + '\x01';

  uVar4 = *puVar8;

  uVar3 = *puVar2;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[3] = (char)uVar4 + '\x01';

  uVar4 = *puVar8;

  uVar3 = *puVar2;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[2] = 0xc;

  puVar1[1] = (char)uVar4 + '\x01';

  if ((*puVar8 & 0xff) == 0) {

    cVar5 = '\v';

  }

  else {

    cVar5 = (char)*puVar8 + '\x01';

  }

  *puVar1 = cVar5;

  return puVar1;

}

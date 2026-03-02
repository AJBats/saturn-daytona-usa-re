void FUN_06017784(param_1, param_2, param_3, param_4)
    unsigned short *param_1;
    short param_2;
    unsigned short param_3;
    int param_4;
{

  unsigned short uVar1;

  unsigned short uVar2;

  char *puVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  puVar3 = 0x06085640;

  uVar1 = *param_1;

  uVar2 = param_1[1];

  uVar5 = param_4 + 2;

  for (uVar6 = 0; uVar6 < uVar2; uVar6 = uVar6 + 1) {

    uVar7 = 0;

    if (uVar1 != 0) {

      do {

        uVar4 = (unsigned int)uVar7;

        uVar7 = uVar7 + 1;

        *(unsigned short *)(puVar3 + (((uVar5 & 0xff) << 1) + (int)(short)((param_3 & 0xff) * 0x36))) =

             param_1[(unsigned int)uVar6 * (unsigned int)uVar1 + uVar4 + 2] + param_2;

        param_3 = param_3 + 1;

      } while (uVar7 < uVar1);

    }

    param_3 = param_3 - uVar1;

    uVar5 = uVar5 + 1;

  }

  return;

}

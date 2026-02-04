extern int DAT_06014818;

unsigned int FUN_0601476c(param_1)
    unsigned int *param_1;
{

  char *puVar1;

  unsigned char *pbVar2;

  unsigned char *pbVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  char cVar8;

  pbVar3 = 0x0605B3C4;

  puVar1 = 0x06084B14;

  uVar6 = (unsigned int)DAT_06014818;

  uVar7 = 1;

  uVar5 = 0;

  *(short *)0x06084FB8 = 0;

  *(unsigned int *)0x0607EBCC = uVar6 - 0x4b;

  do {

    cVar8 = *puVar1 == *pbVar3;

    pbVar2 = pbVar3 + 2;

    if (puVar1[1] == pbVar3[1]) {

      cVar8 = cVar8 + '\x01';

    }

    pbVar3 = pbVar3 + 3;

    if (puVar1[2] == *pbVar2) {

      cVar8 = cVar8 + '\x01';

    }

    if (cVar8 == '\x03') {

      *(int *)0x0607EBCC = *(int *)(0x0605B164 + uVar5 * 4);

      if (uVar5 < 2) {

        if (0x2a < uVar5) {

          uVar5 = 0x2b;

        }

        puVar4 = 0x0605B4A8 +

                 (short)(((short)uVar5 * 4 + ((unsigned short)*(int *)0x0607EBC8 & 3)) * 3);

        *puVar1 = *puVar4;

        puVar1[1] = puVar4[1];

        pbVar3 = puVar4 + 3;

        puVar1[2] = puVar4[2];

        uVar7 = uVar6 & 0xff;

      }

      else {

        uVar7 = 0;

        *(short *)0x06084FB8 = 1;

      }

    }

    uVar5 = uVar5 + 1;

    if (*pbVar3 == uVar6) {

      uVar7 = 0;

    }

  } while (uVar7 == 1);

  *param_1 = uVar5;

  return uVar7;

}

extern int DAT_0603815a;

extern int DAT_060382f4;

unsigned int FUN_06038120(param_1)
    unsigned char *param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  unsigned int *puVar5;

  unsigned short uVar6;

  unsigned int *puVar7;

  unsigned short uVar8;

  unsigned short uVar9;

  int iVar10;

  puVar2 = 0x060A2470;

  puVar1 = 0x060A3C70;

  iVar10 = 0x200;

  uVar4 = (*(int *)0x060635A8 == 4 ^ 1) & -((*(int *)0x060635A8 == 8) - 1);

  if (uVar4 == 0) {

    uVar6 = param_1[3] & 1 | (param_1[2] & 1) << 1 | (param_1[1] & 1) << 2 | (*param_1 & 1) << 3 |

            (param_1[4] & 3) << 4;

    puVar5 = (unsigned int *)(0x060A3DF8 + 0x2c);

    puVar7 = (unsigned int *)(0x060A3DF8 + 0x30);

    if (*(int *)0x060635A8 == 8) {

      uVar6 = uVar6 << 8 & (unsigned short)0x0000FF00;

      puVar7 = (unsigned int *)(0x060A3DF8 + 0x34);

    }

    *(unsigned short *)(0x060A3DF8 + 0x2a) = uVar6;

    puVar3 = 0x060A3D70;

    *(int *)0x060A3D70 = *(int *)(param_1 + 8);

    *(char **)(puVar3 + 4) = puVar2;

    puVar3 = 0x060A3D78;

    *(int *)0x060A3D78 = *(int *)(param_1 + 0xc);

    *(char **)(puVar3 + 4) = puVar1;

    puVar3 = 0x0007FFFF;

    *puVar7 = *(unsigned int *)(param_1 + 8) >> 1 & (unsigned int)0x0007FFFF;

    *puVar5 = *(unsigned int *)(param_1 + 0xc) >> 1 & (unsigned int)puVar3;

    uVar6 = (unsigned short)(param_1[4] == 0);

    if (param_1[4] == 1) {

      uVar6 = 2;

    }

    if (param_1[4] == 2) {

      uVar6 = 4;

    }

    if (param_1[4] == 3) {

      uVar6 = 8;

    }

    uVar8 = 0;

    uVar9 = 0;

    do {

      if (param_1[2] != 0) {

        uVar4 = (unsigned int)uVar8;

        uVar8 = uVar8 + 1;

        *(int *)(puVar2 + (uVar4 << 2)) = *(int *)(param_1 + (short)(uVar9 * 0xc) + 0x10)

        ;

      }

      if (param_1[1] != 0) {

        uVar4 = (unsigned int)uVar8;

        uVar8 = uVar8 + 1;

        *(int *)(puVar2 + (uVar4 << 2)) = *(int *)(param_1 + (short)(uVar9 * 0xc) + 0x14)

        ;

      }

      if (*param_1 != 0) {

        uVar4 = (unsigned int)uVar8;

        uVar8 = uVar8 + 1;

        *(int *)(puVar2 + (uVar4 << 2)) = *(int *)(param_1 + (short)(uVar9 * 0xc) + 0x18)

        ;

      }

      uVar9 = uVar9 + uVar6;

    } while ((int)(unsigned int)uVar9 < iVar10);

    *(unsigned short *)0x060635A0 = uVar8;

    uVar9 = 0;

    uVar6 = 0;

    do {

      uVar4 = 0;

      if (param_1[3] != 0) {

        uVar4 = (unsigned int)(uVar9 << 2);

        uVar9 = uVar9 + 1;

        *(int *)(puVar1 + uVar4) =

             *(int *)(param_1 + (unsigned int)(uVar6 << 2) + (int)DAT_060382f4);

      }

      uVar6 = uVar6 + 1;

    } while (uVar6 < 0x40);

    *(unsigned short *)0x060635A2 = uVar9;

    *(short *)0x060635AC = 2;

  }

  return uVar4;

}

extern int DAT_06031750;

extern int DAT_0603178c;

extern int DAT_060317c6;

extern int DAT_060318e4;

extern int DAT_06031918;

extern int DAT_0603196c;

int FUN_060316c4(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    int param_3;
{

  long long lVar1;

  int in_r0;

  short sVar4;

  int iVar2;

  int iVar3;

  unsigned int uVar5;

  unsigned int uVar6;

  int extraout_r3;

  int extraout_r3_00;

  int extraout_r3_01;

  int extraout_r3_02;

  unsigned int uVar7;

  int iVar8;

  char *puVar9;

  if ((int)param_2[3] < (int)param_1[3]) {

    sVar4 = (*0x0602744C)(param_2[4] - param_1[4],param_2[6] - param_1[6]);

    iVar8 = (int)-sVar4;

    uVar5 = param_1[8] - iVar8 & 0xffff;

    if (DAT_06031750 <= uVar5) {

      uVar5 = uVar5 - DAT_06031750;

    }

    uVar7 = param_2[8] - iVar8 & 0xffff;

    if (DAT_06031750 <= uVar7) {

      uVar7 = uVar7 - DAT_06031750;

    }

    uVar5 = (*(int *)(0x0605BCC8 + (uVar5 >> 9) * 4) - param_3) +

            *(int *)(0x0605BCC8 + (uVar7 >> 9) * 4);

    if (0 < (int)uVar5) {

      uVar7 = param_1[10] - param_2[10] & 0xffff;

      if (((int)DAT_0603178c < (int)uVar7) && ((int)uVar7 < DAT_0603178c * 3)) {

        if ((int)0x0001638E < (int)(param_1[3] + param_2[3])) {

          *param_2 = *param_2 | 0x08000000;

        }

      }

      else {

        if ((int)0x0001638E < (int)(param_1[3] - param_2[3])) {

          *param_2 = *param_2 | 0x08000000;

        }

        uVar7 = param_1[10] - iVar8 & 0xffff;

        if (((int)uVar7 <= (int)DAT_060317c6) || (DAT_060317c6 * 3 <= (int)uVar7)) {

          param_2[8] = param_1[8];

          iVar2 = (*0x06027344)(uVar7);

          lVar1 = (long long)(int)(param_1[3] - param_2[3]) * (long long)iVar2;

          uVar7 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

          param_2[3] = param_2[3] + uVar7;

          param_1[3] = param_1[3] - uVar7;

        }

      }

      uVar5 = uVar5 >> 1;

      uVar7 = param_2[4];

      uVar6 = param_2[6];

      param_2[0xe] = uVar7;

      param_2[0xf] = uVar6;

      iVar2 = (*0x06027344)(-iVar8);

      iVar3 = (*0x06027348)(-iVar8);

      param_2[4] = uVar7 + ((int)((unsigned long long)((long long)extraout_r3 * (long long)iVar3) >> 0x20) <<

                            0x10 | (unsigned int)((long long)extraout_r3 * (long long)iVar3) >> 0x10);

      lVar1 = (long long)(int)uVar5 * (long long)iVar2;

      param_2[6] = uVar6 + ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

      puVar9 = 0x00008000 + iVar8;

      uVar7 = param_1[4];

      uVar6 = param_1[6];

      param_1[0xe] = uVar7;

      param_1[0xf] = uVar6;

      iVar8 = (*0x06027344)(-(int)puVar9);

      in_r0 = (*0x06027348)(-(int)puVar9);

      param_1[4] = uVar7 + ((int)((unsigned long long)((long long)extraout_r3_00 * (long long)in_r0) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_00 * (long long)in_r0) >> 0x10);

      lVar1 = (long long)(int)uVar5 * (long long)iVar8;

      param_1[6] = uVar6 + ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

    }

  }

  else {

    sVar4 = (*0x0602744C)(param_1[4] - param_2[4],param_1[6] - param_2[6]);

    iVar8 = (int)-sVar4;

    uVar7 = (unsigned int)DAT_060318e4;

    uVar5 = param_1[8] - iVar8 & 0xffff;

    if (uVar7 <= uVar5) {

      uVar5 = uVar5 - uVar7;

    }

    uVar6 = param_2[8] - iVar8 & 0xffff;

    if (uVar7 <= uVar6) {

      uVar6 = uVar6 - uVar7;

    }

    uVar5 = (*(int *)(0x0605BCC8 + (uVar5 >> 9) * 4) - param_3) +

            *(int *)(0x0605BCC8 + (uVar6 >> 9) * 4);

    if (0 < (int)uVar5) {

      uVar7 = param_1[10] - param_2[10] & 0xffff;

      if (((int)DAT_06031918 < (int)uVar7) && ((int)uVar7 < DAT_06031918 * 3)) {

        if ((int)0x0001638E < (int)(param_1[3] + param_2[3])) {

          uVar7 = *param_1 | 0x08000000;

          *param_2 = *param_2 | 0x08000000;

          *param_1 = uVar7;

        }

      }

      else {

        if ((int)0x0001638E < (int)(param_2[3] - param_1[3])) {

          uVar7 = *param_1 | 0x08000000;

          *param_2 = *param_2 | 0x08000000;

          *param_1 = uVar7;

        }

        uVar7 = param_2[10] - iVar8 & 0xffff;

        if (((int)uVar7 <= (int)DAT_0603196c) || (DAT_0603196c * 3 <= (int)uVar7)) {

          uVar6 = param_2[8];

          param_1[8] = uVar6;

          param_1[10] = uVar6;

          iVar2 = (*0x06027344)(uVar7);

          lVar1 = (long long)(int)(param_2[3] - param_1[3]) * (long long)iVar2;

          uVar7 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

          param_1[3] = param_1[3] + uVar7;

          param_2[3] = param_2[3] - uVar7;

        }

      }

      uVar5 = uVar5 >> 1;

      uVar7 = param_1[4];

      uVar6 = param_1[6];

      param_1[0xe] = uVar7;

      param_1[0xf] = uVar6;

      iVar2 = (*0x06027344)(-iVar8);

      iVar3 = (*0x06027348)(-iVar8);

      param_1[4] = uVar7 + ((int)((unsigned long long)((long long)extraout_r3_01 * (long long)iVar3) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_01 * (long long)iVar3) >> 0x10);

      lVar1 = (long long)(int)uVar5 * (long long)iVar2;

      param_1[6] = uVar6 + ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

      puVar9 = 0x00008000 + iVar8;

      uVar7 = param_2[4];

      uVar6 = param_2[6];

      param_2[0xe] = uVar7;

      param_2[0xf] = uVar6;

      iVar8 = (*0x06027344)(-(int)puVar9);

      in_r0 = (*0x06027348)(-(int)puVar9);

      param_2[4] = uVar7 + ((int)((unsigned long long)((long long)extraout_r3_02 * (long long)in_r0) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_02 * (long long)in_r0) >> 0x10);

      lVar1 = (long long)(int)uVar5 * (long long)iVar8;

      param_2[6] = uVar6 + ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

    }

  }

  return in_r0;

}

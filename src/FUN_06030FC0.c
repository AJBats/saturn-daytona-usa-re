extern int DAT_060310b8;

extern int DAT_0603112e;

extern int DAT_06031130;

extern int DAT_06031132;

extern int DAT_06031188;

extern int DAT_0603118a;

extern int DAT_060311b6;

extern int DAT_06031208;

extern int DAT_0603120a;

extern int DAT_0603129c;

extern int DAT_0603129e;

extern int PTR_DAT_06031234;

extern int PTR_DAT_06031234;

extern int PTR_DAT_060312a0;

extern int PTR_DAT_060312a0;

extern int FUN_06031340();
extern int FUN_0603136e();

int FUN_06030fc0(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    char *param_3;
{

  int bVar1;

  long long lVar2;

  int in_r0;

  int iVar3;

  short sVar5;

  int iVar4;

  unsigned int uVar6;

  int extraout_r1;

  int iVar7;

  int extraout_r2;

  char *extraout_r2_00;

  int extraout_r3;

  int extraout_r3_00;

  unsigned int uVar8;

  char *pcVar9;

  int iVar10;

  unsigned int uVar11;

  char *puVar12;

  int in_pr;

  long long uVar13;

  if ((int)param_2[3] < (int)param_1[3]) {

    sVar5 = (*(void(*)())0x0602744C)(param_2[4] - param_1[4],param_2[6] - param_1[6]);

    iVar3 = (int)-sVar5;

    sVar5 = (*(void(*)())0x0602744C)(param_2[0xe] - param_1[0xe],param_2[0xf] - param_1[0xf],param_1[0xe],

                       param_1[0xf],in_pr,in_r0);

    uVar8 = (unsigned int)DAT_060310b8;

    uVar6 = param_1[0xc] - ((unsigned int)(unsigned short)-sVar5 | uVar8 << 1);

    if ((int)uVar6 < 1) {

      uVar6 = -uVar6;

    }

    uVar6 = (unsigned int)((uVar6 & 0xffff) < uVar8);

    FUN_06031340();

    iVar7 = extraout_r1;

    if (extraout_r1 >= (int)uVar8) {

      iVar7 = extraout_r1 - uVar8;

    }

    uVar11 = (unsigned int)(extraout_r1 < (int)uVar8);

    bVar1 = uVar11 != uVar6;

    uVar13 = (*(void(*)())0x06027348)(iVar7);

    iVar7 = (int)uVar13;

    uVar6 = extraout_r2 - iVar3 & 0xffff;

    if ((int)uVar8 <= (int)uVar6) {

      uVar6 = uVar6 - uVar8;

    }

    uVar8 = (unsigned int)((unsigned long long)uVar13 >> 0x29);

    iVar10 = 0;

    if ((10 < uVar8) && (uVar8 < 0x37)) {

      iVar10 = 1;

    }

    if (((bVar1) && (uVar11 = (unsigned int)(uVar11 == 0), iVar10 != 0)) ||

       (param_3 = (char *)

                  ((*(int *)(0x0605BCC8 + uVar8 * 4) - (int)param_3) +

                  *(int *)(0x0605BCC8 + (uVar6 >> 9) * 4)), 0 < (int)param_3)) {

      uVar6 = param_1[10] - param_2[10] & 0xffff;

      if (((int)DAT_0603112e < (int)uVar6) && ((int)uVar6 < DAT_0603112e * 3)) {

        if ((int)0x00042AAA < (int)(param_1[3] + param_2[3])) {

          *param_2 = *param_2 | 0x08000000;

          (*(void(*)())0x06008460)();

          *(int *)((int)param_1 + (int)DAT_06031130) = (int)DAT_06031132;

        }

      }

      else {

        puVar12 = 0x00042AAA;

        if ((int)0x00042AAA < (int)(param_1[3] - param_2[3])) {

          *param_2 = *param_2 | 0x08000000;

          (*(void(*)())0x06008460)();

          *(int *)((int)param_1 + (int)DAT_06031188) = (int)DAT_0603118a;

          puVar12 = extraout_r2_00;

        }

        if ((iVar10 == 0) && ((int)((unsigned int)puVar12 >> 1) <= (int)(param_1[3] - param_2[3]))) {

          puVar12 = 0x20000000;

          if (uVar11 != 0) {

            puVar12 = (char *)((unsigned int)0x20000000 >> 1);

          }

          *param_1 = *param_1 | (unsigned int)puVar12;

        }

        else {

          uVar6 = param_1[10] - iVar3 & 0xffff;

          if (((int)uVar6 <= (int)DAT_060311b6) || (DAT_060311b6 * 3 <= (int)uVar6)) {

            if (iVar10 != 0) {

              param_2[0xc] = param_1[0xc];

              *(int *)((int)DAT_06031208 + (int)param_2) = 8;

            }

            iVar4 = (*(void(*)())0x06027344)(uVar6);

            lVar2 = (long long)(int)(param_1[3] - param_2[3] >> 2) * (long long)iVar4;

            iVar4 = (int)((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) >> 1;

            *(unsigned int *)((int)DAT_0603120a + (int)param_2) = param_2[3] + iVar4;

            param_1[3] = param_1[3] - iVar4;

          }

        }

      }

      if (iVar10 == 0) {

        if (*(int *)0x0602FD9A == '\0') {

          *(int *)0x0602FD9A = 3;

        }

      }

      else {

        if (uVar11 == 0) {

          uVar6 = 0x80;

          pcVar9 = 0x0602FD98 + 1;

          if (*(short *)0x06031A24 != 0) {

            uVar6 = (unsigned int)PTR_DAT_06031234;

          }

        }

        else {

          uVar6 = 0x40;

          pcVar9 = 0x0602FD98;

          if (*(short *)0x06031A24 != 0) {

            uVar6 = (unsigned int)DAT_0603129c;

          }

        }

        *param_1 = *param_1 | uVar6;

        if (*pcVar9 == '\0') {

          *pcVar9 = '\x03';

        }

        iVar3 = (int)DAT_0603129e;

        if (uVar11 == 0) {

          iVar3 = iVar3 * 3;

        }

        iVar3 = (param_1[0xc] & 0xffff) + iVar3;

        param_3 = (char *)

                  ((int)((unsigned long long)((long long)(int)param_3 * (long long)iVar7) >> 0x20) << 0x10 |

                  (unsigned int)((long long)(int)param_3 * (long long)iVar7) >> 0x10);

        if (bVar1) {

          param_3 = param_3 + (int)0x0000D999;

        }

      }

      if (*(short *)((int)PTR_DAT_060312a0 + (int)param_1) < 8) {

        if (*(short *)((int)PTR_DAT_060312a0 + (int)param_1) < 6) {

          puVar12 = (char *)((unsigned int)param_3 >> 2) + ((unsigned int)param_3 >> 1);

          param_3 = (char *)((unsigned int)param_3 >> 2);

        }

        else {

          puVar12 = param_3;

          param_3 = (char *)0x0;

        }

      }

      else {

        puVar12 = (char *)0x0;

      }

      uVar6 = param_2[4];

      uVar8 = param_2[6];

      param_2[0xe] = uVar6;

      param_2[0xf] = uVar8;

      iVar7 = (*(void(*)())0x06027344)(-iVar3);

      iVar10 = (*(void(*)())0x06027348)(-iVar3);

      param_2[4] = uVar6 + ((int)((unsigned long long)((long long)extraout_r3 * (long long)iVar10) >> 0x20) <<

                            0x10 | (unsigned int)((long long)extraout_r3 * (long long)iVar10) >> 0x10);

      param_2[6] = uVar8 + ((int)((unsigned long long)((long long)(int)puVar12 * (long long)iVar7) >> 0x20) <<

                            0x10 | (unsigned int)((long long)(int)puVar12 * (long long)iVar7) >> 0x10);

      puVar12 = 0x00008000 + iVar3;

      uVar6 = param_1[4];

      uVar8 = param_1[6];

      param_1[0xe] = uVar6;

      param_1[0xf] = uVar8;

      iVar3 = (*(void(*)())0x06027344)(-(int)puVar12);

      iVar7 = (*(void(*)())0x06027348)(-(int)puVar12);

      param_1[4] = uVar6 + ((int)((unsigned long long)((long long)extraout_r3_00 * (long long)iVar7) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_00 * (long long)iVar7) >> 0x10);

      param_1[6] = uVar8 + ((int)((unsigned long long)((long long)(int)param_3 * (long long)iVar3) >> 0x20) <<

                            0x10 | (unsigned int)((long long)(int)param_3 * (long long)iVar3) >> 0x10);

    }

    return iVar7;

  }

  iVar3 = FUN_0603136e(param_1,param_2,param_2[4],param_2[6]);

  return iVar3;

}

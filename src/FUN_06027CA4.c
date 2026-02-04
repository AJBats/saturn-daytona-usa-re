extern int DAT_06027d26;

extern int DAT_06027de2;

extern int DAT_06027e18;

extern int DAT_06027e98;

extern int DAT_06027e9a;

extern int PTR_DAT_06027da0;

extern int PTR_DAT_06027da0;

void FUN_06027ca4(param_1, param_2)
    unsigned int *param_1;
    int param_2;
{

  short sVar1;

  unsigned int *puVar2;

  short uVar3;

  unsigned int *puVar4;

  short *psVar5;

  unsigned int uVar6;

  int iVar7;

  unsigned int uVar8;

  int iVar9;

  char *puVar10;

  puVar4 = (unsigned int *)(((unsigned int)(0x04000000 + *param_1) >> 0x15) +

                   (0x03FFFFFF - param_1[2] >> 0x15) * 0x40);

  if (*(int *)0x0607EAD8 == 2) {

    iVar9 = 0;

    psVar5 = (short *)0x06061270;

    while( true ) {

      sVar1 = *psVar5;

      psVar5 = psVar5 + 1;

      if ((unsigned int *)(int)sVar1 == (unsigned int *)0x0) break;

      if (puVar4 == (unsigned int *)(int)sVar1) {

        if (*(int *)(*(int *)0x0607E940 + (int)DAT_06027d26) < 0x47) {

          sVar1 = *(short *)(0x06061240 + iVar9 * 2);

          iVar9 = (int)*(short *)((int)(0x06061240 + iVar9 * 2) + 2);

          *(short *)0x06063F50 = sVar1;

          puVar10 = (char *)(int)sVar1;

          goto LAB_06027d36;

        }

        break;

      }

      iVar9 = iVar9 + 2;

    }

    iVar9 = 0;

    puVar10 = 0x0607EAD8;

LAB_06027d36:

    if (iVar9 != 0) goto LAB_06027d50;

  }

  puVar10 = (char *)(unsigned int)*(unsigned short *)(0x060C2000 + (int)puVar4 * 4);

  iVar9 = (int)(short)*(unsigned short *)((int)(0x060C2000 + (int)puVar4 * 4) + 2);

LAB_06027d50:

  do {

    if (iVar9 < 1) {

      uVar6 = 0;

      uVar8 = 0;

LAB_06027e6a:

      *(short *)(param_1 + 3) = (short)uVar6;

      if (uVar8 == 0) {

        iVar9 = *(int *)0x0607E940;

      }

      else {

        sVar1 = *(short *)(puVar4 + 0xc);

        param_1[4] = (int)sVar1;

        uVar3 = (*0x0602ECCC)();

        *(short *)((int)param_1 + 0xe) = uVar3;

        iVar9 = *(int *)0x0607E940;

        if (param_2 < 1) {

          *(int *)(DAT_06027e9a + iVar9) = (int)sVar1;

        }

      }

      *(unsigned int *)((unsigned int)*(unsigned short *)(0x0606128A + param_2 * 2) + iVar9) = uVar6;

      return;

    }

    puVar2 = (unsigned int *)(0x060A6000 + *(short *)(puVar10 + (int)0x060BF000) * 0x34);

    uVar6 = *puVar2;

    iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[4]) >> 0x20) << 0x10

            | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[4]) >> 0x10) + puVar2[5];

    if ((uVar6 & 0x1000000) == 0) {

      iVar7 = iVar7 + param_1[2];

    }

    if (((int)PTR_DAT_06027da0 & uVar6) == 0) {

      if (iVar7 < 0) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

LAB_06027db6:

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[6]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[6]) >> 0x10) +

              puVar2[7];

      if ((uVar6 & 0x2000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      puVar4 = param_1;

      if (((int)DAT_06027de2 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[8]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[8]) >> 0x10) +

              puVar2[9];

      if ((uVar6 & 0x4000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      if (((int)DAT_06027e18 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[10]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[10]) >> 0x10) +

              puVar2[0xb];

      if ((uVar6 & 0x8000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      if ((0x00000800 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      puVar4 = (unsigned int *)(0x060A6000 + *(short *)(puVar10 + (int)0x060BF000) * 0x34);

      uVar8 = (unsigned int)DAT_06027e98;

      uVar6 = *puVar4 & uVar8;

      goto LAB_06027e6a;

    }

    if (iVar7 < 1) goto LAB_06027db6;

    puVar10 = puVar10 + 2;

    iVar9 = iVar9 + -1;

  } while( true );

}

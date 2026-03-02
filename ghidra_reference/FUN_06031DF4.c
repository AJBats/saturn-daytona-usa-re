extern int DAT_06031e30;

extern int DAT_06031eee;

extern int DAT_06031fc4;

extern int DAT_06032048;

extern int DAT_0603204a;

extern int PTR_DAT_06031ea8;

extern int PTR_DAT_06031ea8;

extern int PTR_DAT_06031f30;

extern int PTR_DAT_06031f30;

extern int PTR_DAT_06031f74;

extern int PTR_DAT_06031f74;

extern int PTR_DAT_0603204c;

extern int PTR_DAT_0603204c;

extern int FUN_060320e6();

unsigned int FUN_06031df4(param_1, param_2, param_3)
    int param_1;
    char param_2;
    int param_3;
{

  unsigned int uVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  int iVar5;

  int iVar6;

  unsigned int uVar7;

  int extraout_r3;

  int extraout_r3_00;

  int extraout_r3_01;

  int iVar8;

  unsigned int uVar9;

  int iVar10;

  char *puVar11;

  int *puVar12;

  int *puVar13;

  int iVar14;

  int iVar15;

  unsigned int *puVar16;

  int *piVar17;

  int iVar18;

  unsigned int *puVar19;

  unsigned int *puVar21;

  unsigned int *puVar22;

  int iVar23;

  int iVar24;

  unsigned int in_sr;

  unsigned int uVar25;

  unsigned int uVar26;

  unsigned int uVar27;

  unsigned int uVar28;

  unsigned int uVar29;

  unsigned int *puVar20;

  puVar3 = 0x06032108;

  puVar2 = 0x06032128;

  puVar19 = (unsigned int *)(param_1 + param_3 * 0x18);

  do {

    puVar20 = puVar19 + -6;

    uVar4 = (unsigned int)(short)*(unsigned short *)(puVar19 + -2);

    puVar22 = (unsigned int *)-256;

    puVar16 = (unsigned int *)(0x060961A8 + (unsigned int)*(unsigned short *)(puVar19 + -2) * 0xc);

    uVar7 = puVar16[2];

    uVar26 = in_sr & 0xfffffffe;

    uVar25 = uVar26 | 0 < (int)uVar7;

    if (((unsigned char)uVar25 & 1) == 1) {

      puVar22[4] = 0xa0;

      *puVar22 = uVar7;

      puVar22[5] = 0;

      *(unsigned int *)puVar2 = uVar7;

      puVar11 = 0x06032138;

      if ((puVar19[-3] & 0x80000) == 0) {

        puVar21 = *(unsigned int **)0x0608A52C;

        uVar4 = *puVar21;

        uVar25 = *puVar20;

        uVar7 = uVar4 ^ uVar25;

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar1 = (uVar25 & 0xffff) * (uVar4 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar4 & 0xffff);

        iVar5 = 0;

        uVar9 = iVar6 + (uVar25 & 0xffff) * (uVar4 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar27 = uVar1 + (uVar9 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar27 < uVar1) + (uVar9 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar4 >> 0x10);

        if ((int)-(unsigned int)((int)uVar7 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar27 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar27 = ~uVar27 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar27 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar27 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        uVar7 = puVar21[1];

        uVar4 = puVar19[-5];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar29 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar29 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar29) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;

        }

        uVar7 = puVar21[2];

        uVar4 = puVar19[-4];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        uVar7 = puVar21[3];

        uVar4 = *puVar20;

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        *(unsigned int *)0x06032138 = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar7 = puVar21[4];

        uVar25 = puVar19[-5];

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar29 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar4 = uVar25 + (uVar29 < uVar28) + (uVar4 & 0xffff);

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar4 = uVar25 + (uVar29 < uVar28) + uVar4;

        }

        uVar7 = puVar21[5];

        uVar25 = puVar19[-4];

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar28 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar29 + uVar28;

          uVar4 = uVar25 + (uVar28 < uVar29) + (uVar4 & 0xffff);

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        else {

          uVar28 = uVar29 + uVar28;

          uVar4 = uVar25 + (uVar28 < uVar29) + uVar4;

        }

        uVar7 = puVar21[6];

        uVar25 = *puVar20;

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar29 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        *(unsigned int *)(puVar11 + 4) = uVar4 << 0x10 | uVar28 >> 0x10;

        uVar7 = puVar21[7];

        uVar4 = puVar19[-5];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar29 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar29) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar29 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar29) + uVar25;

        }

        uVar7 = puVar21[8];

        uVar4 = puVar19[-4];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        *(unsigned int *)(puVar11 + 8) = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar4 = *(unsigned int *)puVar11;

        uVar25 = *puVar16;

        uVar7 = uVar4 ^ uVar25;

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar1 = (uVar25 & 0xffff) * (uVar4 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar4 & 0xffff);

        iVar5 = 0;

        uVar9 = iVar6 + (uVar25 & 0xffff) * (uVar4 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar27 = uVar1 + (uVar9 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar27 < uVar1) + (uVar9 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar4 >> 0x10);

        if ((int)-(unsigned int)((int)uVar7 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar27 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar27 = ~uVar27 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar27 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar27 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        uVar7 = *(unsigned int *)(puVar11 + 4);

        uVar4 = puVar16[1];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar29 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar29 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar29) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;

        }

        uVar7 = *(unsigned int *)(puVar11 + 8);

        uVar4 = puVar16[2];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        uVar4 = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar26 = uVar26 | 0 < (int)uVar4;

        uVar25 = uVar26;

        if (((unsigned char)uVar26 & 1) != 1) goto LAB_060320be;

      }

      uVar4 = puVar16[1];

      uVar25 = *puVar16;

      uVar9 = puVar22[7];

      piVar17 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)((int)puVar19 + -6) * 0xc);

      uVar7 = piVar17[2];

      puVar22[4] = 0xa0;

      *puVar22 = uVar7;

      puVar22[5] = 0;

      *(int *)puVar3 = (int)((unsigned long long)((long long)(int)uVar9 * (long long)(int)uVar25) >> 0x20);

      *(int *)(puVar3 + 4) =

           (int)((unsigned long long)((long long)(int)uVar9 * (long long)(int)-uVar4) >> 0x20);

      puVar11 = puVar3;

      uVar4 = FUN_060320e6();

      uVar25 = uVar26 & 0xfffffffe | (unsigned int)(0 < extraout_r3);

      if (((unsigned char)uVar25 & 1) == 1) {

        *(int *)(puVar2 + 4) = extraout_r3;

        puVar12 = (int *)(puVar11 + 8);

        iVar6 = piVar17[1];

        iVar5 = *piVar17;

        uVar4 = puVar22[7];

        piVar17 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)(puVar19 + -1) * 0xc);

        uVar26 = piVar17[2];

        puVar22[4] = 0xa0;

        *puVar22 = uVar26;

        puVar22[5] = 0;

        *puVar12 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)iVar5) >> 0x20);

        *(int *)(puVar11 + 0xc) =

             (int)((unsigned long long)((long long)(int)uVar4 * (long long)-iVar6) >> 0x20);

        uVar4 = FUN_060320e6();

        uVar25 = uVar25 & 0xfffffffe | (unsigned int)(0 < extraout_r3_00);

        if (((unsigned char)uVar25 & 1) == 1) {

          *(int *)(puVar2 + 8) = extraout_r3_00;

          puVar13 = puVar12 + 2;

          iVar6 = piVar17[1];

          iVar5 = *piVar17;

          uVar4 = puVar22[7];

          piVar17 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)((int)puVar19 + -2) * 0xc);

          uVar26 = piVar17[2];

          puVar22[4] = 0xa0;

          *puVar22 = uVar26;

          puVar22[5] = 0;

          *puVar13 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)iVar5) >> 0x20);

          puVar12[3] = (int)((unsigned long long)((long long)(int)uVar4 * (long long)-iVar6) >> 0x20);

          uVar4 = FUN_060320e6();

          uVar25 = uVar25 & 0xfffffffe | (unsigned int)(0 < extraout_r3_01);

          if (((unsigned char)uVar25 & 1) == 1) {

            *(int *)(puVar2 + 0xc) = extraout_r3_01;

            iVar5 = piVar17[1];

            uVar26 = puVar22[7];

            puVar13[2] = (int)((unsigned long long)((long long)(int)uVar26 * (long long)*piVar17) >> 0x20);

            puVar13[3] = (int)((unsigned long long)((long long)(int)uVar26 * (long long)-iVar5) >> 0x20);

            FUN_060320e6();

            puVar11 = 0x0608AC20;

            iVar5 = *(int *)0x060620D4;

            iVar23 = -176;

            uVar4 = *(unsigned int *)puVar3;

            iVar6 = *(int *)(puVar3 + 8);

            iVar10 = *(int *)(puVar3 + 0x10);

            iVar15 = *(int *)(puVar3 + 0x18);

            uVar25 = uVar25 & 0xfffffffe;

            if ((((iVar23 <= (int)uVar4) || (iVar23 <= iVar6)) || (iVar23 <= iVar10)) ||

               (iVar23 <= iVar15)) {

              iVar23 = 0xb0;

              uVar26 = uVar25 | (int)uVar4 < iVar23;

              if (((((unsigned char)uVar26 & 1) == 1) ||

                  (uVar26 = uVar25 | iVar6 < iVar23, ((unsigned char)uVar26 & 1) == 1)) ||

                 ((uVar26 = uVar25 | iVar10 < iVar23, ((unsigned char)uVar26 & 1) == 1 ||

                  (uVar26 = uVar25 | iVar15 < iVar23, uVar25 = uVar26, ((unsigned char)uVar26 & 1) != 1)))) {

                iVar24 = -127;

                iVar23 = *(int *)(puVar3 + 4);

                iVar8 = *(int *)(puVar3 + 0xc);

                iVar14 = *(int *)(puVar3 + 0x14);

                iVar18 = *(int *)(puVar3 + 0x1c);

                uVar25 = uVar26 & 0xfffffffe;

                if (((iVar24 <= iVar23) || (iVar24 <= iVar8)) ||

                   ((iVar24 <= iVar14 ||

                    (uVar25 = uVar25 | iVar18 < iVar24, ((unsigned char)uVar25 & 1) != 1)))) {

                  iVar24 = 0x51;

                  if ((((iVar23 < iVar24) || (iVar8 < iVar24)) || (iVar14 < iVar24)) ||

                     (uVar25 = uVar25 & 0xfffffffe, iVar18 < iVar24)) {

                    *(short *)(0x0608AC20 + iVar5 * 0x18 + 0x16) = (short)iVar18;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x14) = (short)iVar15;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x12) = (short)iVar14;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x10) = (short)iVar10;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0xe) = (short)iVar8;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0xc) = (short)iVar6;

                    *(short *)(puVar11 + iVar5 * 0x18 + 10) = (short)iVar23;

                    *(short *)(puVar11 + iVar5 * 0x18 + 8) = (short)uVar4;

                    *(short *)(puVar11 + iVar5 * 0x18 + 6) =

                         *(short *)((int)puVar19 + -10);

                    puVar11[iVar5 * 0x18 + 4] =

                         (unsigned char)((unsigned int)(int)*(short *)(puVar19 + -3) >> 4) & 0xf;

                    puVar11[iVar5 * 0x18 + 5] = param_2;

                    uVar25 = (*(int(*)())(*(int *)(0x06032144 +

                                         ((int)*(short *)(puVar19 + -3) & 7U) << 2)))(*(int *)(puVar2 + 4),*(int *)(puVar2 + 8),

                                        *(int *)(puVar2 + 0xc));

                    return uVar25;

                  }

                }

              }

            }

          }

        }

      }

    }

LAB_060320be:

    param_3 = param_3 + -1;

    in_sr = uVar25 & 0xfffffffe | (unsigned int)(param_3 == 0);

    puVar19 = puVar20;

    if (((unsigned char)in_sr & 1) == 1) {

      return uVar4;

    }

  } while( 1 );

}

extern int DAT_06029c2e;

extern int DAT_06029ea4;

extern int DAT_06029ea6;

extern int DAT_06029ed4;

extern int DAT_06029ee2;

extern int DAT_06029f2a;

extern int DAT_06029f2c;

extern int DAT_06029f2e;

extern int DAT_06029f30;

extern int DAT_06029f3e;

extern int DAT_06029f4c;

extern int DAT_06029f94;

extern int DAT_06029f96;

extern int DAT_06029f98;

extern int DAT_06029f9a;

extern int DAT_06029fa8;

extern int DAT_06029fb6;

extern int DAT_06029ffe;

extern int DAT_0602a000;

extern int DAT_0602a002;

extern int DAT_0602a004;

extern int DAT_0602a012;

extern int DAT_0602a020;

extern int DAT_0602a050;

extern int PTR_DAT_06029ea8;

extern int PTR_DAT_06029ea8;

unsigned int FUN_06029bf4(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    char param_3;
    int param_4;
{

  unsigned int uVar1;

  unsigned int uVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  int iVar8;

  int iVar9;

  int *puVar10;

  int uVar11;

  int iVar12;

  unsigned int *puVar13;

  unsigned int *puVar14;

  unsigned int *puVar15;

  unsigned int *puVar16;

  int iVar17;

  unsigned int in_sr;

  unsigned int uVar18;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  iVar17 = *(int *)0x06063F08;

  puVar15 = (unsigned int *)(param_1 + param_4 * 0x18);

  do {

    puVar3 = 0x0608A70C;

    puVar16 = puVar15 + -6;

    uVar19 = in_sr & 0xfffffffe;

    uVar18 = uVar19 | *(short *)0x0605BE36 == 0;

    if ((((unsigned char)uVar18 & 1) == 1) ||

       (uVar7 = (unsigned int)*(short *)((int)puVar15 + -10), uVar18 = uVar19, (int)DAT_06029c2e != uVar7))

    {

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)(puVar15 + -2) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar7 = *puVar14;

      uVar19 = *puVar13;

      uVar20 = uVar7 ^ uVar19;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar2 = (uVar19 & 0xffff) * (uVar7 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar7 & 0xffff);

      iVar8 = 0;

      uVar1 = iVar9 + (uVar19 & 0xffff) * (uVar7 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar2 + uVar1 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar2) + (uVar1 >> 0x10) + (uVar19 >> 0x10) * (uVar7 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar20 = puVar14[1];

      uVar7 = puVar13[1];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar26 = uVar21 + uVar26;

        uVar19 = uVar7 + (uVar26 < uVar21) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar26 = uVar21 + uVar26;

        uVar19 = uVar7 + (uVar26 < uVar21) + uVar19;

      }

      uVar20 = puVar14[2];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar26 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar23 = uVar26 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar26) + uVar19;

      }

      uVar20 = puVar14[3];

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[4];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + uVar7;

      }

      *(unsigned int *)0x0608A70C = (uVar19 << 0x10 | uVar23 >> 0x10) + puVar14[9];

      uVar20 = puVar14[5];

      uVar19 = puVar13[2];

      uVar1 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar21 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + uVar2 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar19 + (uVar23 < uVar22) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar19 + (uVar23 < uVar22) + uVar7;

      }

      uVar20 = puVar14[6];

      uVar19 = *puVar13;

      uVar1 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar21 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + uVar2 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar26 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar1 = puVar14[7];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + uVar19;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar7 << 0x10 | uVar23 >> 0x10) + puVar14[10];

      uVar20 = puVar14[8];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar22) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar22) + uVar19;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar19 << 0x10 | uVar23 >> 0x10) + puVar14[0xb];

      puVar4 = 0x0608A704;

      uVar19 = uVar18 & 0xfffffffe;

      *(unsigned short *)0x0608A704 = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = 0x0608A73C;

      if ((puVar15[-3] & 0x80000) == 0) {

        puVar13 = *(unsigned int **)0x06089EDC;

        uVar20 = *puVar13;

        uVar7 = *puVar16;

        uVar1 = uVar20 ^ uVar7;

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

        iVar8 = 0;

        uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar23 = uVar21 + uVar2 * 0x10000;

        uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

                (uVar7 >> 0x10) * (uVar20 >> 0x10);

        if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar23 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar23 = ~uVar23 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar23 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar23 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        uVar1 = puVar13[1];

        uVar20 = puVar15[-5];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar26 + uVar21 * 0x10000;

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

        }

        uVar1 = puVar13[2];

        uVar20 = puVar15[-4];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + uVar21 * 0x10000;

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        uVar1 = puVar13[3];

        uVar20 = *puVar16;

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + uVar21 * 0x10000;

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        *(unsigned int *)0x0608A73C = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar1 = puVar13[4];

        uVar7 = puVar15[-5];

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + uVar21 * 0x10000;

        uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar26 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar20 = uVar7 + (uVar26 < uVar24) + (uVar20 & 0xffff);

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar20 = uVar7 + (uVar26 < uVar24) + uVar20;

        }

        uVar1 = puVar13[5];

        uVar7 = puVar15[-4];

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + uVar21 * 0x10000;

        uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar24 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar26 + uVar24;

          uVar20 = uVar7 + (uVar24 < uVar26) + (uVar20 & 0xffff);

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        else {

          uVar24 = uVar26 + uVar24;

          uVar20 = uVar7 + (uVar24 < uVar26) + uVar20;

        }

        uVar1 = puVar13[6];

        uVar7 = *puVar16;

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + uVar21 * 0x10000;

        uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar26 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        *(unsigned int *)(puVar3 + 4) = uVar20 << 0x10 | uVar24 >> 0x10;

        uVar1 = puVar13[7];

        uVar20 = puVar15[-5];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + uVar21 * 0x10000;

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar26 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar26) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar26 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar26) + uVar7;

        }

        uVar1 = puVar13[8];

        uVar20 = puVar15[-4];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + uVar21 * 0x10000;

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        *(unsigned int *)(puVar3 + 8) = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar20 = *(unsigned int *)puVar3;

        uVar7 = *(unsigned int *)0x0608A70C;

        uVar1 = uVar20 ^ uVar7;

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

        iVar8 = 0;

        uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar23 = uVar21 + uVar2 * 0x10000;

        uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

                (uVar7 >> 0x10) * (uVar20 >> 0x10);

        if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar23 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar23 = ~uVar23 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar23 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar23 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        uVar1 = *(unsigned int *)(puVar3 + 4);

        uVar20 = *(unsigned int *)(0x0608A70C + 4);

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar26 + uVar21 * 0x10000;

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

        }

        uVar1 = *(unsigned int *)(puVar3 + 8);

        uVar20 = *(unsigned int *)(0x0608A70C + 8);

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + uVar21 * 0x10000;

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        uVar7 = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar19 = uVar19 | 0 < (int)uVar7;

        if (((unsigned char)uVar19 & 1) != 1) goto LAB_0602a1b6;

      }

      puVar3 = 0x0608A718;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)((int)puVar15 + -6) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar7 = *puVar14;

      uVar18 = *puVar13;

      uVar20 = uVar7 ^ uVar18;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar2 = (uVar18 & 0xffff) * (uVar7 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar7 & 0xffff);

      iVar8 = 0;

      uVar1 = iVar9 + (uVar18 & 0xffff) * (uVar7 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar2 + uVar1 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar21 < uVar2) + (uVar1 >> 0x10) + (uVar18 >> 0x10) * (uVar7 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar21 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar20 = puVar14[1];

      uVar7 = puVar13[1];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar21 + uVar26;

        uVar18 = uVar7 + (uVar26 < uVar21) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar26 = uVar21 + uVar26;

        uVar18 = uVar7 + (uVar26 < uVar21) + uVar18;

      }

      uVar20 = puVar14[2];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar26 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar26) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar26 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar26) + uVar18;

      }

      uVar20 = puVar14[3];

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[4];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + uVar7;

      }

      *(unsigned int *)0x0608A718 = (uVar18 << 0x10 | uVar23 >> 0x10) + puVar14[9];

      uVar20 = puVar14[5];

      uVar18 = puVar13[2];

      uVar1 = uVar20 ^ uVar18;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar21 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + uVar2 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

               (uVar18 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar23 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar18 + (uVar23 < uVar22) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar18 + (uVar23 < uVar22) + uVar7;

      }

      uVar20 = puVar14[6];

      uVar18 = *puVar13;

      uVar1 = uVar20 ^ uVar18;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar21 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + uVar2 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) +

               (uVar18 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar26 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar1 = puVar14[7];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar18 = uVar20 + (uVar22 < uVar26) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar18 = uVar20 + (uVar22 < uVar26) + uVar18;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar7 << 0x10 | uVar23 >> 0x10) + puVar14[10];

      uVar20 = puVar14[8];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar22) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar22) + uVar18;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar18 << 0x10 | uVar23 >> 0x10) + puVar14[0xb];

      uVar18 = uVar19 & 0xfffffffe;

      *(unsigned short *)(puVar4 + 2) = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = 0x0608A724;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)(puVar15 + -1) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar20 = *puVar14;

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[1];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar26 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

      }

      uVar1 = puVar14[2];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

      }

      uVar1 = puVar14[3];

      uVar20 = *puVar13;

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar2 = puVar14[4];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + uVar23 * 0x10000;

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + uVar20;

      }

      *(unsigned int *)0x0608A724 = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[9];

      uVar1 = puVar14[5];

      uVar7 = puVar13[2];

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + uVar21 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + uVar20;

      }

      uVar1 = puVar14[6];

      uVar7 = *puVar13;

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + uVar21 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar24 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar2 = puVar14[7];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + uVar23 * 0x10000;

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + uVar7;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar20 << 0x10 | uVar26 >> 0x10) + puVar14[10];

      uVar1 = puVar14[8];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + uVar7;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[0xb];

      *(unsigned short *)(puVar4 + 4) = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = 0x0608A730;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)((int)puVar15 + -2) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar20 = *puVar14;

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + uVar2 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[1];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar26 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

      }

      uVar1 = puVar14[2];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

      }

      uVar1 = puVar14[3];

      uVar20 = *puVar13;

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar2 = puVar14[4];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + uVar23 * 0x10000;

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + uVar20;

      }

      *(unsigned int *)0x0608A730 = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[9];

      uVar1 = puVar14[5];

      uVar7 = puVar13[2];

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + uVar21 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + uVar20;

      }

      uVar1 = puVar14[6];

      uVar7 = *puVar13;

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + uVar21 * 0x10000;

      uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar24 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar2 = puVar14[7];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + uVar23 * 0x10000;

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + uVar7;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar20 << 0x10 | uVar26 >> 0x10) + puVar14[10];

      uVar1 = puVar14[8];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + uVar21 * 0x10000;

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + uVar7;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[0xb];

      iVar8 = *(int *)(puVar3 + 8);

      *(unsigned short *)(puVar4 + 6) = (unsigned short)(iVar8 <= iVar17);

      iVar8 = (unsigned int)(iVar8 <= iVar17) + (int)*(short *)(puVar4 + 4) +

              (int)*(short *)(puVar4 + 2) + (int)*(short *)puVar4;

      uVar19 = uVar18 | iVar8 == 0;

      if (((unsigned char)uVar19 & 1) != 1) {

        if (iVar8 == 4) {

          uVar7 = 4;

          uVar19 = uVar18;

          goto LAB_0602a1b6;

        }

        (*(void(*)())(*(int *)(0x0602A1E0 + iVar8 * 4)))(0x0608A70C,0x0608A704,puVar14 + 9,puVar14 + 0xc);

        uVar19 = uVar18;

      }

      puVar5 = 0x0608A76C;

      puVar4 = 0x0608AC20;

      puVar3 = 0x0608A70C;

      iVar8 = *(int *)0x060620D0;

      puVar10 = (int *)(int)DAT_06029ea4;

      uVar11 = *(int *)(0x0608A70C + 8);

      puVar10[4] = (int)DAT_06029ea6;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 4);

      iVar9 = puVar10[7];

      *(int *)puVar5 = (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)puVar3) >> 0x20);

      *(int *)(puVar5 + 4) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      puVar6 = 0x0608A6FC;

      iVar9 = *(int *)puVar5;

      iVar12 = *(int *)(puVar5 + 4);

      *(short *)0x0608A6FC = 0;

      uVar19 = uVar19 & 0xfffffffe;

      if (PTR_DAT_06029ea8 < iVar9) {

        *(short *)puVar6 = 1;

      }

      else if (iVar9 < DAT_06029ed4) {

        *(short *)puVar6 = 1;

      }

      else if (DAT_06029ee2 < iVar12) {

        *(short *)puVar6 = 1;

      }

      else if (iVar12 < DAT_06029f2a) {

        *(short *)puVar6 = 1;

      }

      puVar10 = (int *)(int)DAT_06029f2c;

      uVar11 = *(int *)(puVar3 + 0x14);

      puVar10[4] = (int)DAT_06029f2e;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x10);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 8) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0xc)) >> 0x20);

      *(int *)(puVar5 + 0xc) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 8);

      iVar12 = *(int *)(puVar5 + 0xc);

      *(short *)(puVar6 + 2) = 0;

      if (DAT_06029f30 < iVar9) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (iVar9 < DAT_06029f3e) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (DAT_06029f4c < iVar12) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (iVar12 < DAT_06029f94) {

        *(short *)(puVar6 + 2) = 1;

      }

      puVar10 = (int *)(int)DAT_06029f96;

      uVar11 = *(int *)(puVar3 + 0x20);

      puVar10[4] = (int)DAT_06029f98;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x1c);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 0x10) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0x18)) >> 0x20);

      *(int *)(puVar5 + 0x14) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 0x10);

      iVar12 = *(int *)(puVar5 + 0x14);

      *(short *)(puVar6 + 4) = 0;

      if (DAT_06029f9a < iVar9) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (iVar9 < DAT_06029fa8) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (DAT_06029fb6 < iVar12) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (iVar12 < DAT_06029ffe) {

        *(short *)(puVar6 + 4) = 1;

      }

      puVar10 = (int *)(int)DAT_0602a000;

      uVar11 = *(int *)(puVar3 + 0x2c);

      puVar10[4] = (int)DAT_0602a002;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x28);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 0x18) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0x24)) >> 0x20);

      *(int *)(puVar5 + 0x1c) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 0x18);

      iVar12 = *(int *)(puVar5 + 0x1c);

      *(short *)(puVar6 + 6) = 0;

      if (DAT_0602a004 < iVar9) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (iVar9 < DAT_0602a012) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (DAT_0602a020 < iVar12) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (iVar12 < DAT_0602a050) {

        *(short *)(puVar6 + 6) = 1;

      }

      if (((((int)0xFFFFFF50 <= *(int *)puVar5) ||

           ((int)0xFFFFFF50 <= *(int *)(puVar5 + 8))) ||

          ((int)0xFFFFFF50 <= *(int *)(puVar5 + 0x10))) ||

         (uVar7 = *(unsigned int *)(puVar5 + 0x18), (int)0xFFFFFF50 <= (int)uVar7)) {

        uVar18 = uVar19 | *(int *)puVar5 < 0x000000B0;

        if (((((unsigned char)uVar18 & 1) != 1) &&

            (uVar18 = uVar19 | *(int *)(puVar5 + 8) < 0x000000B0, ((unsigned char)uVar18 & 1) != 1)) &&

           (uVar18 = uVar19 | *(int *)(puVar5 + 0x10) < 0x000000B0, ((unsigned char)uVar18 & 1) != 1)) {

          uVar7 = *(unsigned int *)(puVar5 + 0x18);

          uVar18 = uVar19 | (int)uVar7 < 0x000000B0;

          uVar19 = uVar18;

          if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602a1b6;

        }

        uVar18 = uVar18 & 0xfffffffe;

        if ((((int)0xFFFFFF81 <= *(int *)(puVar5 + 4)) ||

            ((int)0xFFFFFF81 <= *(int *)(puVar5 + 0xc))) ||

           (((int)0xFFFFFF81 <= *(int *)(puVar5 + 0x14) ||

            (uVar7 = *(unsigned int *)(puVar5 + 0x1c), uVar19 = uVar18, (int)0xFFFFFF81 <= (int)uVar7)

            ))) {

          uVar19 = uVar18 | *(int *)(puVar5 + 4) < 0x00000051;

          if (((((unsigned char)uVar19 & 1) != 1) &&

              (uVar19 = uVar18 | *(int *)(puVar5 + 0xc) < 0x00000051, ((unsigned char)uVar19 & 1) != 1)) &&

             (uVar19 = uVar18 | *(int *)(puVar5 + 0x14) < 0x00000051, ((unsigned char)uVar19 & 1) != 1)) {

            uVar7 = *(unsigned int *)(puVar5 + 0x1c);

            uVar19 = uVar18 | (int)uVar7 < 0x00000051;

            if (((unsigned char)uVar19 & 1) != 1) goto LAB_0602a1b6;

          }

          iVar9 = (int)*(short *)(puVar6 + 6) +

                  (int)*(short *)puVar6 + (int)*(short *)(puVar6 + 2) + (int)*(short *)(puVar6 + 4);

          if (iVar9 != 4) {

            if (iVar9 != 0) {

              (*(void(*)())(*(int *)(0x0602A1F0 + iVar9 * 4)))(puVar5,puVar6);

            }

            *(short *)(puVar4 + iVar8 * 0x18 + 8) = (short)*(int *)puVar5;

            *(short *)(puVar4 + iVar8 * 0x18 + 10) = (short)*(int *)(puVar5 + 4);

            *(short *)(puVar4 + iVar8 * 0x18 + 0xc) = (short)*(int *)(puVar5 + 8);

            *(short *)(puVar4 + iVar8 * 0x18 + 0xe) = (short)*(int *)(puVar5 + 0xc);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x10) = (short)*(int *)(puVar5 + 0x10);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x12) = (short)*(int *)(puVar5 + 0x14);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x14) = (short)*(int *)(puVar5 + 0x18);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x16) = (short)*(int *)(puVar5 + 0x1c);

            *(short *)(puVar4 + iVar8 * 0x18 + 6) = *(short *)((int)puVar15 + -10);

            puVar4[iVar8 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar15 + -3) >> 4) & 0xf;

            puVar4[iVar8 * 0x18 + 5] = param_3;

            uVar19 = (**(void **)(0x0602A200 + ((int)*(short *)(puVar15 + -3) & 7U) * 4))

                               (*(int *)(0x0608A70C + 0x14),

                                *(int *)(0x0608A70C + 0x20),

                                *(int *)(0x0608A70C + 0x2c));

            return uVar19;

          }

          uVar7 = 4;

          uVar19 = uVar19 & 0xfffffffe;

        }

      }

    }

LAB_0602a1b6:

    param_4 = param_4 + -1;

    in_sr = uVar19 & 0xfffffffe | (unsigned int)(param_4 == 0);

    puVar15 = puVar16;

    if (((unsigned char)in_sr & 1) == 1) {

      return uVar7;

    }

  } while( 1 );

}

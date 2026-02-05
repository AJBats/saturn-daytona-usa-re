extern int DAT_0602b64c;

extern int DAT_0602b64e;

extern int DAT_0602b67c;

extern int DAT_0602b68a;

extern int DAT_0602b6d2;

extern int DAT_0602b6d4;

extern int DAT_0602b6d6;

extern int DAT_0602b6d8;

extern int DAT_0602b6e6;

extern int DAT_0602b6f4;

extern int DAT_0602b73c;

extern int DAT_0602b73e;

extern int DAT_0602b740;

extern int DAT_0602b742;

extern int DAT_0602b750;

extern int DAT_0602b75e;

extern int DAT_0602b7a6;

extern int DAT_0602b7a8;

extern int DAT_0602b7aa;

extern int DAT_0602b7ac;

extern int DAT_0602b7ba;

extern int DAT_0602b7c8;

extern int DAT_0602b7f8;

extern int PTR_DAT_0602b650;

extern int PTR_DAT_0602b650;

unsigned int FUN_0602b5d2(param_1, param_2, param_3, param_4, param_5)
    int param_1;
    int param_2;
    unsigned int *param_3;
    unsigned int *param_4;
    int param_5;
{

  short sVar1;

  short sVar2;

  unsigned char bVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  int in_r0;

  int iVar10;

  int iVar11;

  unsigned int uVar12;

  int *puVar13;

  int uVar14;

  int in_r3;

  int iVar15;

  short *psVar16;

  unsigned int *puVar17;

  unsigned int *puVar18;

  unsigned int *unaff_r8;

  int unaff_r10;

  char unaff_r13;

  int unaff_r14;

  unsigned int uVar19;

  unsigned int in_sr;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  unsigned int uVar27;

  do {

    iVar10 = in_r0 + in_r3;

    uVar12 = in_sr & 0xfffffffe;

    uVar20 = uVar12 | iVar10 == 0;

    if (((unsigned char)uVar20 & 1) == 1) {

LAB_0602b600:

      puVar8 = 0x06094A90;

      puVar7 = 0x0608AC20;

      puVar6 = 0x06094A30;

      iVar10 = *(int *)0x060620D0;

      puVar13 = (int *)-256;

      uVar14 = *(int *)(0x06094A30 + 8);

      puVar13[4] = 0xa0;

      *puVar13 = uVar14;

      puVar13[5] = 0;

      iVar15 = *(int *)(puVar6 + 4);

      iVar11 = puVar13[7];

      *(int *)puVar8 = (int)((unsigned long long)((long long)iVar11 * (long long)*(int *)puVar6) >> 0x20);

      *(int *)(puVar8 + 4) = (int)((unsigned long long)((long long)iVar11 * (long long)-iVar15) >> 0x20);

      puVar9 = 0x06094A20;

      iVar11 = *(int *)puVar8;

      iVar15 = *(int *)(puVar8 + 4);

      *(short *)0x06094A20 = 0;

      uVar12 = uVar20 & 0xfffffffe;

      if (PTR_DAT_0602b650 < iVar11) {

        *(short *)puVar9 = 1;

      }

      else if (iVar11 < DAT_0602b67c) {

        *(short *)puVar9 = 1;

      }

      else if (DAT_0602b68a < iVar15) {

        *(short *)puVar9 = 1;

      }

      else if (iVar15 < DAT_0602b6d2) {

        *(short *)puVar9 = 1;

      }

      puVar13 = (int *)-256;

      uVar14 = *(int *)(puVar6 + 0x14);

      puVar13[4] = 0xa0;

      *puVar13 = uVar14;

      puVar13[5] = 0;

      iVar15 = *(int *)(puVar6 + 0x10);

      iVar11 = puVar13[7];

      *(int *)(puVar8 + 8) =

           (int)((unsigned long long)((long long)iVar11 * (long long)*(int *)(puVar6 + 0xc)) >> 0x20);

      *(int *)(puVar8 + 0xc) = (int)((unsigned long long)((long long)iVar11 * (long long)-iVar15) >> 0x20);

      iVar11 = *(int *)(puVar8 + 8);

      iVar15 = *(int *)(puVar8 + 0xc);

      *(short *)(puVar9 + 2) = 0;

      if (DAT_0602b6d8 < iVar11) {

        *(short *)(puVar9 + 2) = 1;

      }

      else if (iVar11 < DAT_0602b6e6) {

        *(short *)(puVar9 + 2) = 1;

      }

      else if (DAT_0602b6f4 < iVar15) {

        *(short *)(puVar9 + 2) = 1;

      }

      else if (iVar15 < DAT_0602b73c) {

        *(short *)(puVar9 + 2) = 1;

      }

      puVar13 = (int *)-256;

      uVar14 = *(int *)(puVar6 + 0x20);

      puVar13[4] = 0xa0;

      *puVar13 = uVar14;

      puVar13[5] = 0;

      iVar15 = *(int *)(puVar6 + 0x1c);

      iVar11 = puVar13[7];

      *(int *)(puVar8 + 0x10) =

           (int)((unsigned long long)((long long)iVar11 * (long long)*(int *)(puVar6 + 0x18)) >> 0x20);

      *(int *)(puVar8 + 0x14) = (int)((unsigned long long)((long long)iVar11 * (long long)-iVar15) >> 0x20);

      iVar11 = *(int *)(puVar8 + 0x10);

      iVar15 = *(int *)(puVar8 + 0x14);

      *(short *)(puVar9 + 4) = 0;

      if (DAT_0602b742 < iVar11) {

        *(short *)(puVar9 + 4) = 1;

      }

      else if (iVar11 < DAT_0602b750) {

        *(short *)(puVar9 + 4) = 1;

      }

      else if (DAT_0602b75e < iVar15) {

        *(short *)(puVar9 + 4) = 1;

      }

      else if (iVar15 < DAT_0602b7a6) {

        *(short *)(puVar9 + 4) = 1;

      }

      puVar13 = (int *)-256;

      uVar14 = *(int *)(puVar6 + 0x2c);

      puVar13[4] = 0xa0;

      *puVar13 = uVar14;

      puVar13[5] = 0;

      iVar15 = *(int *)(puVar6 + 0x28);

      iVar11 = puVar13[7];

      *(int *)(puVar8 + 0x18) =

           (int)((unsigned long long)((long long)iVar11 * (long long)*(int *)(puVar6 + 0x24)) >> 0x20);

      *(int *)(puVar8 + 0x1c) = (int)((unsigned long long)((long long)iVar11 * (long long)-iVar15) >> 0x20);

      iVar11 = *(int *)(puVar8 + 0x18);

      iVar15 = *(int *)(puVar8 + 0x1c);

      *(short *)(puVar9 + 6) = 0;

      if (DAT_0602b7ac < iVar11) {

        *(short *)(puVar9 + 6) = 1;

      }

      else if (iVar11 < DAT_0602b7ba) {

        *(short *)(puVar9 + 6) = 1;

      }

      else if (DAT_0602b7c8 < iVar15) {

        *(short *)(puVar9 + 6) = 1;

      }

      else if (iVar15 < DAT_0602b7f8) {

        *(short *)(puVar9 + 6) = 1;

      }

      if (((((int)0xFFFFFF50 <= *(int *)puVar8) ||

           ((int)0xFFFFFF50 <= *(int *)(puVar8 + 8))) ||

          ((int)0xFFFFFF50 <= *(int *)(puVar8 + 0x10))) ||

         (uVar20 = *(unsigned int *)(puVar8 + 0x18), (int)0xFFFFFF50 <= (int)uVar20)) {

        uVar19 = uVar12 | *(int *)puVar8 < 0x000000B0;

        if (((((unsigned char)uVar19 & 1) != 1) &&

            (uVar19 = uVar12 | *(int *)(puVar8 + 8) < 0x000000B0, ((unsigned char)uVar19 & 1) != 1)) &&

           (uVar19 = uVar12 | *(int *)(puVar8 + 0x10) < 0x000000B0, ((unsigned char)uVar19 & 1) != 1)) {

          uVar20 = *(unsigned int *)(puVar8 + 0x18);

          uVar19 = uVar12 | (int)uVar20 < 0x000000B0;

          uVar12 = uVar19;

          if (((unsigned char)uVar19 & 1) != 1) goto LAB_0602b972;

        }

        uVar12 = uVar19 & 0xfffffffe;

        if ((((int)0xFFFFFF81 <= *(int *)(puVar8 + 4)) ||

            ((int)0xFFFFFF81 <= *(int *)(puVar8 + 0xc))) ||

           (((int)0xFFFFFF81 <= *(int *)(puVar8 + 0x14) ||

            (uVar20 = *(unsigned int *)(puVar8 + 0x1c), (int)0xFFFFFF81 <= (int)uVar20)))) {

          uVar19 = uVar12 | *(int *)(puVar8 + 4) < 0x00000051;

          if (((((unsigned char)uVar19 & 1) != 1) &&

              (uVar19 = uVar12 | *(int *)(puVar8 + 0xc) < 0x00000051, ((unsigned char)uVar19 & 1) != 1)) &&

             (uVar19 = uVar12 | *(int *)(puVar8 + 0x14) < 0x00000051, ((unsigned char)uVar19 & 1) != 1)) {

            uVar20 = *(unsigned int *)(puVar8 + 0x1c);

            uVar19 = uVar12 | (int)uVar20 < 0x00000051;

            uVar12 = uVar19;

            if (((unsigned char)uVar19 & 1) != 1) goto LAB_0602b972;

          }

          iVar11 = (int)*(short *)(puVar9 + 6) +

                   (int)*(short *)puVar9 + (int)*(short *)(puVar9 + 2) + (int)*(short *)(puVar9 + 4)

          ;

          if (iVar11 != 4) {

            if (iVar11 != 0) {

              (*(int(*)())(*(int *)(0x0602B9BC + (iVar11 << 2))))(puVar8,puVar9);

            }

            *(short *)(puVar7 + iVar10 * 0x18 + 8) = (short)*(int *)puVar8;

            *(short *)(puVar7 + iVar10 * 0x18 + 10) = (short)*(int *)(puVar8 + 4);

            *(short *)(puVar7 + iVar10 * 0x18 + 0xc) = (short)*(int *)(puVar8 + 8);

            *(short *)(puVar7 + iVar10 * 0x18 + 0xe) = (short)*(int *)(puVar8 + 0xc);

            *(short *)(puVar7 + iVar10 * 0x18 + 0x10) = (short)*(int *)(puVar8 + 0x10);

            *(short *)(puVar7 + iVar10 * 0x18 + 0x12) = (short)*(int *)(puVar8 + 0x14);

            *(short *)(puVar7 + iVar10 * 0x18 + 0x14) = (short)*(int *)(puVar8 + 0x18);

            *(short *)(puVar7 + iVar10 * 0x18 + 0x16) = (short)*(int *)(puVar8 + 0x1c);

            *(short *)(puVar7 + iVar10 * 0x18 + 6) = *(short *)((int)unaff_r8 + 0xe);

            puVar7[iVar10 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(unaff_r8 + 3) >> 4) & 0xf;

            puVar7[iVar10 * 0x18 + 5] = unaff_r13;

            uVar12 = (*(int(*)())(*(int *)(0x0602B9CC + ((int)*(short *)(unaff_r8 + 3) & 7U) << 2)))(*(int *)(0x06094A30 + 0x14),

                                *(int *)(0x06094A30 + 0x20),

                                *(int *)(0x06094A30 + 0x2c));

            return uVar12;

          }

          uVar20 = 4;

          uVar12 = uVar19 & 0xfffffffe;

        }

      }

    }

    else {

      if (iVar10 != 4) {

        (*(int(*)())(*(int *)(0x0602B9AC + (iVar10 << 2))))(0x06094A30,0x06094A28,param_3,param_4);

        uVar20 = uVar12;

        goto LAB_0602b600;

      }

      uVar20 = 4;

    }

LAB_0602b972:

    do {

      puVar18 = unaff_r8;

      puVar6 = 0x06094AB0;

      param_5 = param_5 + -1;

      uVar19 = uVar12 & 0xfffffffe;

      if (param_5 == 0) {

        return uVar20;

      }

      unaff_r8 = puVar18 + -6;

      psVar16 = (short *)((unsigned int)*(unsigned short *)(puVar18 + -2) * 6 + unaff_r14);

      sVar1 = psVar16[1];

      sVar2 = psVar16[2];

      *(int *)0x06094AB0 = (int)*psVar16 << 0xb;

      *(int *)(puVar6 + 4) = (int)sVar1 << 0xb;

      *(int *)(puVar6 + 8) = (int)sVar2 << 0xb;

      puVar7 = 0x06094A30;

      puVar17 = *(unsigned int **)0x06089EDC;

      uVar21 = *puVar17;

      uVar20 = *(unsigned int *)puVar6;

      uVar5 = uVar21 ^ uVar20;

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

      iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

      iVar10 = 0;

      uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar24 + (uVar4 << 16);

      uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

               (uVar20 >> 0x10) * (uVar21 >> 0x10);

      if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar27 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar5 = puVar17[1];

      uVar21 = *(unsigned int *)(puVar6 + 4);

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar25 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar23 = uVar25 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar23 < uVar25) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar23 = uVar27 + uVar23;

        uVar20 = uVar21 + (uVar23 < uVar27) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar23 = uVar27 + uVar23;

        uVar20 = uVar21 + (uVar23 < uVar27) + uVar20;

      }

      uVar5 = puVar17[2];

      uVar21 = *(unsigned int *)(puVar6 + 8);

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar27 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar27 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar25 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar25 = uVar23 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar23) + (uVar20 & 0xffff);

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

        uVar25 = uVar23 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar23) + uVar20;

      }

      uVar5 = puVar17[3];

      uVar21 = *(unsigned int *)puVar6;

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar27 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar23 = uVar27 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar23 < uVar27) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      uVar4 = puVar17[4];

      uVar5 = *(unsigned int *)(puVar6 + 4);

      uVar24 = uVar4 ^ uVar5;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar26 = (uVar5 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar5 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar27 = iVar11 + (uVar5 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar22 = uVar26 + (uVar27 << 16);

      uVar5 = iVar10 + (unsigned int)(uVar22 < uVar26) + (uVar27 >> 0x10) +

              (uVar5 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar24 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar22 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar22 = uVar23 + uVar22;

        uVar21 = uVar5 + (uVar22 < uVar23) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar22 = uVar23 + uVar22;

        uVar21 = uVar5 + (uVar22 < uVar23) + uVar21;

      }

      *(unsigned int *)0x06094A30 = (uVar20 << 0x10 | uVar25 >> 0x10) + puVar17[9];

      uVar5 = puVar17[5];

      uVar20 = *(unsigned int *)(puVar6 + 8);

      uVar4 = uVar5 ^ uVar20;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar27 = (uVar20 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar20 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar20 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar27 + (uVar24 << 16);

      uVar20 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar24 >> 0x10) +

               (uVar20 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar25 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar25 = uVar22 + uVar25;

        uVar21 = uVar20 + (uVar25 < uVar22) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar25 = uVar22 + uVar25;

        uVar21 = uVar20 + (uVar25 < uVar22) + uVar21;

      }

      uVar5 = puVar17[6];

      uVar20 = *(unsigned int *)puVar6;

      uVar4 = uVar5 ^ uVar20;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar27 = (uVar20 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar20 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar20 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar23 = uVar27 + (uVar24 << 16);

      uVar20 = iVar10 + (unsigned int)(uVar23 < uVar27) + (uVar24 >> 0x10) +

               (uVar20 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar23 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar4 = puVar17[7];

      uVar5 = *(unsigned int *)(puVar6 + 4);

      uVar24 = uVar4 ^ uVar5;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar26 = (uVar5 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar5 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar27 = iVar11 + (uVar5 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar22 = uVar26 + (uVar27 << 16);

      uVar5 = iVar10 + (unsigned int)(uVar22 < uVar26) + (uVar27 >> 0x10) +

              (uVar5 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar24 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar22 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar22 = uVar23 + uVar22;

        uVar20 = uVar5 + (uVar22 < uVar23) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar22 = uVar23 + uVar22;

        uVar20 = uVar5 + (uVar22 < uVar23) + uVar20;

      }

      *(unsigned int *)(puVar7 + 4) = (uVar21 << 0x10 | uVar25 >> 0x10) + puVar17[10];

      uVar5 = puVar17[8];

      uVar21 = *(unsigned int *)(puVar6 + 8);

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar27 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar27 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar25 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar25 = uVar22 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar22) + (uVar20 & 0xffff);

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

        uVar25 = uVar22 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar22) + uVar20;

      }

      *(unsigned int *)(puVar7 + 8) = (uVar20 << 0x10 | uVar25 >> 0x10) + puVar17[0xb];

      puVar6 = 0x06094A28;

      *(unsigned short *)0x06094A28 = (unsigned short)(*(int *)(puVar7 + 8) <= unaff_r10);

      puVar7 = 0x06094A60;

      if ((puVar18[-3] & 0x80000) != 0) break;

      puVar17 = *(unsigned int **)0x06089EDC;

      uVar21 = *puVar17;

      uVar20 = *unaff_r8;

      uVar5 = uVar21 ^ uVar20;

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

      iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

      iVar10 = 0;

      uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar24 + (uVar4 << 16);

      uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

               (uVar20 >> 0x10) * (uVar21 >> 0x10);

      if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar27 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar5 = puVar17[1];

      uVar21 = puVar18[-5];

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar25 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar23 = uVar25 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar23 < uVar25) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar23 = uVar27 + uVar23;

        uVar20 = uVar21 + (uVar23 < uVar27) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar23 = uVar27 + uVar23;

        uVar20 = uVar21 + (uVar23 < uVar27) + uVar20;

      }

      uVar5 = puVar17[2];

      uVar21 = puVar18[-4];

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar27 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar27 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar25 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar25 = uVar23 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar23) + (uVar20 & 0xffff);

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

        uVar25 = uVar23 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar23) + uVar20;

      }

      uVar5 = puVar17[3];

      uVar21 = *unaff_r8;

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar27 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar23 = uVar27 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar23 < uVar27) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      *(unsigned int *)0x06094A60 = uVar20 << 0x10 | uVar25 >> 0x10;

      uVar5 = puVar17[4];

      uVar20 = puVar18[-5];

      uVar4 = uVar5 ^ uVar20;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar27 = (uVar20 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar20 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar20 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar27 + (uVar24 << 16);

      uVar20 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar24 >> 0x10) +

               (uVar20 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar25 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar25 = uVar23 + uVar25;

        uVar21 = uVar20 + (uVar25 < uVar23) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar25 = uVar23 + uVar25;

        uVar21 = uVar20 + (uVar25 < uVar23) + uVar21;

      }

      uVar5 = puVar17[5];

      uVar20 = puVar18[-4];

      uVar4 = uVar5 ^ uVar20;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar27 = (uVar20 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar20 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar20 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar23 = uVar27 + (uVar24 << 16);

      uVar20 = iVar10 + (unsigned int)(uVar23 < uVar27) + (uVar24 >> 0x10) +

               (uVar20 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar23 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar23 = uVar25 + uVar23;

        uVar21 = uVar20 + (uVar23 < uVar25) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar23 = uVar25 + uVar23;

        uVar21 = uVar20 + (uVar23 < uVar25) + uVar21;

      }

      uVar5 = puVar17[6];

      uVar20 = *unaff_r8;

      uVar4 = uVar5 ^ uVar20;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar27 = (uVar20 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar20 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar20 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar27 + (uVar24 << 16);

      uVar20 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar24 >> 0x10) +

               (uVar20 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar25 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

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

      *(unsigned int *)(puVar7 + 4) = uVar21 << 0x10 | uVar23 >> 0x10;

      uVar5 = puVar17[7];

      uVar21 = puVar18[-5];

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar27 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar23 = uVar27 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar23 < uVar27) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar23 = uVar25 + uVar23;

        uVar20 = uVar21 + (uVar23 < uVar25) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar23 = uVar25 + uVar23;

        uVar20 = uVar21 + (uVar23 < uVar25) + uVar20;

      }

      uVar5 = puVar17[8];

      uVar21 = puVar18[-4];

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar27 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar27 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar25 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar25 = uVar23 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar23) + (uVar20 & 0xffff);

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

        uVar25 = uVar23 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar23) + uVar20;

      }

      *(unsigned int *)(puVar7 + 8) = uVar20 << 0x10 | uVar25 >> 0x10;

      uVar21 = *(unsigned int *)puVar7;

      uVar20 = *(unsigned int *)0x06094A30;

      uVar5 = uVar21 ^ uVar20;

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

      iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

      iVar10 = 0;

      uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar24 + (uVar4 << 16);

      uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

               (uVar20 >> 0x10) * (uVar21 >> 0x10);

      if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar27 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar5 = *(unsigned int *)(puVar7 + 4);

      uVar21 = *(unsigned int *)(0x06094A30 + 4);

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar25 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar23 = uVar25 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar23 < uVar25) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar23 = uVar27 + uVar23;

        uVar20 = uVar21 + (uVar23 < uVar27) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar23 = uVar27 + uVar23;

        uVar20 = uVar21 + (uVar23 < uVar27) + uVar20;

      }

      uVar5 = *(unsigned int *)(puVar7 + 8);

      uVar21 = *(unsigned int *)(0x06094A30 + 8);

      uVar4 = uVar5 ^ uVar21;

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar27 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

      iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar27 + (uVar24 << 16);

      uVar21 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar24 >> 0x10) +

               (uVar21 >> 0x10) * (uVar5 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar25 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar12 >> 1) & 1) == 1) {

        uVar25 = uVar23 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar23) + (uVar20 & 0xffff);

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

        uVar25 = uVar23 + uVar25;

        uVar20 = uVar21 + (uVar25 < uVar23) + uVar20;

      }

      uVar20 = uVar20 << 0x10 | uVar25 >> 0x10;

      uVar19 = uVar19 | 0 < (int)uVar20;

      uVar12 = uVar19;

    } while (((unsigned char)uVar19 & 1) != 1);

    puVar7 = 0x06094AB0;

    psVar16 = (short *)((unsigned int)*(unsigned short *)((int)puVar18 + -6) * 6 + unaff_r14);

    sVar1 = psVar16[1];

    sVar2 = psVar16[2];

    *(int *)0x06094AB0 = (int)*psVar16 << 0xb;

    *(int *)(puVar7 + 4) = (int)sVar1 << 0xb;

    *(int *)(puVar7 + 8) = (int)sVar2 << 0xb;

    puVar8 = 0x06094A30;

    puVar17 = *(unsigned int **)0x06089EDC;

    uVar20 = *puVar17;

    uVar12 = *(unsigned int *)puVar7;

    uVar21 = uVar20 ^ uVar12;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar4 = (uVar12 & 0xffff) * (uVar20 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar20 & 0xffff);

    iVar10 = 0;

    uVar5 = iVar11 + (uVar12 & 0xffff) * (uVar20 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar24 = uVar4 + (uVar5 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar24 < uVar4) + (uVar5 >> 0x10) + (uVar12 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar24 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar21 = puVar17[1];

    uVar20 = *(unsigned int *)(puVar7 + 4);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar27 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar27 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar20 + (uVar25 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar20 + (uVar25 < uVar24) + uVar12;

    }

    uVar21 = puVar17[2];

    uVar20 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar27 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar25 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar27 = uVar25 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar25) + uVar12;

    }

    uVar21 = puVar17[3];

    uVar20 = *(unsigned int *)puVar7;

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

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

    uVar5 = puVar17[4];

    uVar21 = *(unsigned int *)(puVar7 + 4);

    uVar4 = uVar5 ^ uVar21;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar23 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

    iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

    iVar10 = 0;

    uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar26 = uVar23 + (uVar24 << 16);

    uVar21 = iVar10 + (unsigned int)(uVar26 < uVar23) + (uVar24 >> 0x10) +

             (uVar21 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar26 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar20 = uVar21 + (uVar26 < uVar25) + (uVar20 & 0xffff);

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

      uVar20 = uVar21 + (uVar26 < uVar25) + uVar20;

    }

    *(unsigned int *)(0x06094A30 + 0xc) = (uVar12 << 0x10 | uVar27 >> 0x10) + puVar17[9];

    uVar21 = puVar17[5];

    uVar12 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar12;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar24 = (uVar12 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar12 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar12 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar27 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar26 + uVar27;

      uVar20 = uVar12 + (uVar27 < uVar26) + (uVar20 & 0xffff);

      if ((int)uVar20 < -0x8000) {

        uVar20 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar20) {

        uVar20 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar20 = uVar20 & 0xffff;

    }

    else {

      uVar27 = uVar26 + uVar27;

      uVar20 = uVar12 + (uVar27 < uVar26) + uVar20;

    }

    uVar21 = puVar17[6];

    uVar12 = *(unsigned int *)puVar7;

    uVar5 = uVar21 ^ uVar12;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar24 = (uVar12 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar12 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + (uVar4 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar4 >> 0x10) +

             (uVar12 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar25 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar5 = puVar17[7];

    uVar21 = *(unsigned int *)(puVar7 + 4);

    uVar4 = uVar5 ^ uVar21;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar23 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

    iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

    iVar10 = 0;

    uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar26 = uVar23 + (uVar24 << 16);

    uVar21 = iVar10 + (unsigned int)(uVar26 < uVar23) + (uVar24 >> 0x10) +

             (uVar21 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar26 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar21 + (uVar26 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar21 + (uVar26 < uVar25) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x10) = (uVar20 << 0x10 | uVar27 >> 0x10) + puVar17[10];

    uVar21 = puVar17[8];

    uVar20 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar27 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar26 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar26) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar27 = uVar26 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar26) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x14) = (uVar12 << 0x10 | uVar27 >> 0x10) + puVar17[0xb];

    *(unsigned short *)(puVar6 + 2) = (unsigned short)(*(int *)(puVar8 + 0x14) <= unaff_r10);

    puVar7 = 0x06094AB0;

    psVar16 = (short *)((unsigned int)*(unsigned short *)(puVar18 + -1) * 6 + unaff_r14);

    sVar1 = psVar16[1];

    sVar2 = psVar16[2];

    *(int *)0x06094AB0 = (int)*psVar16 << 0xb;

    *(int *)(puVar7 + 4) = (int)sVar1 << 0xb;

    *(int *)0x06094AE0 = (int)sVar1 << 0xb;

    *(int *)(puVar7 + 8) = (int)sVar2 << 0xb;

    puVar8 = 0x06094A30;

    puVar17 = *(unsigned int **)0x06089EDC;

    uVar20 = *puVar17;

    uVar12 = *(unsigned int *)puVar7;

    uVar21 = uVar20 ^ uVar12;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar4 = (uVar12 & 0xffff) * (uVar20 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar20 & 0xffff);

    iVar10 = 0;

    uVar5 = iVar11 + (uVar12 & 0xffff) * (uVar20 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar24 = uVar4 + (uVar5 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar24 < uVar4) + (uVar5 >> 0x10) + (uVar12 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar24 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar21 = puVar17[1];

    uVar20 = *(unsigned int *)(puVar7 + 4);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar27 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar27 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar20 + (uVar25 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar20 + (uVar25 < uVar24) + uVar12;

    }

    uVar21 = puVar17[2];

    uVar20 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar27 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar25 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar27 = uVar25 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar25) + uVar12;

    }

    uVar21 = puVar17[3];

    uVar20 = *(unsigned int *)puVar7;

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

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

    uVar5 = puVar17[4];

    uVar21 = *(unsigned int *)(puVar7 + 4);

    uVar4 = uVar5 ^ uVar21;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar23 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

    iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

    iVar10 = 0;

    uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar26 = uVar23 + (uVar24 << 16);

    uVar21 = iVar10 + (unsigned int)(uVar26 < uVar23) + (uVar24 >> 0x10) +

             (uVar21 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar26 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar20 = uVar21 + (uVar26 < uVar25) + (uVar20 & 0xffff);

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

      uVar20 = uVar21 + (uVar26 < uVar25) + uVar20;

    }

    *(unsigned int *)(0x06094A30 + 0x18) = (uVar12 << 0x10 | uVar27 >> 0x10) + puVar17[9];

    uVar21 = puVar17[5];

    uVar12 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar12;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar24 = (uVar12 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar12 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar12 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar27 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar26 + uVar27;

      uVar20 = uVar12 + (uVar27 < uVar26) + (uVar20 & 0xffff);

      if ((int)uVar20 < -0x8000) {

        uVar20 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar20) {

        uVar20 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar20 = uVar20 & 0xffff;

    }

    else {

      uVar27 = uVar26 + uVar27;

      uVar20 = uVar12 + (uVar27 < uVar26) + uVar20;

    }

    uVar21 = puVar17[6];

    uVar12 = *(unsigned int *)puVar7;

    uVar5 = uVar21 ^ uVar12;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar24 = (uVar12 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar12 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + (uVar4 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar4 >> 0x10) +

             (uVar12 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar25 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar5 = puVar17[7];

    uVar21 = *(unsigned int *)(puVar7 + 4);

    uVar4 = uVar5 ^ uVar21;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar23 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

    iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

    iVar10 = 0;

    uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar26 = uVar23 + (uVar24 << 16);

    uVar21 = iVar10 + (unsigned int)(uVar26 < uVar23) + (uVar24 >> 0x10) +

             (uVar21 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar26 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar21 + (uVar26 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar21 + (uVar26 < uVar25) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x1c) = (uVar20 << 0x10 | uVar27 >> 0x10) + puVar17[10];

    uVar21 = puVar17[8];

    uVar20 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar27 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar26 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar26) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar27 = uVar26 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar26) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x20) = (uVar12 << 0x10 | uVar27 >> 0x10) + puVar17[0xb];

    *(unsigned short *)(puVar6 + 4) = (unsigned short)(*(int *)(puVar8 + 0x20) <= unaff_r10);

    puVar7 = 0x06094AB0;

    psVar16 = (short *)((unsigned int)*(unsigned short *)((int)puVar18 + -2) * 6 + unaff_r14);

    sVar1 = psVar16[1];

    sVar2 = psVar16[2];

    *(int *)0x06094AB0 = (int)*psVar16 << 0xb;

    *(int *)(puVar7 + 4) = (int)sVar1 << 0xb;

    *(int *)(puVar7 + 8) = (int)sVar2 << 0xb;

    puVar8 = 0x06094A30;

    puVar18 = *(unsigned int **)0x06089EDC;

    uVar20 = *puVar18;

    uVar12 = *(unsigned int *)puVar7;

    uVar21 = uVar20 ^ uVar12;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar4 = (uVar12 & 0xffff) * (uVar20 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar20 & 0xffff);

    iVar10 = 0;

    uVar5 = iVar11 + (uVar12 & 0xffff) * (uVar20 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar24 = uVar4 + (uVar5 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar24 < uVar4) + (uVar5 >> 0x10) + (uVar12 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar24 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar21 = puVar18[1];

    uVar20 = *(unsigned int *)(puVar7 + 4);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar27 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar27 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar25 < uVar27) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar20 + (uVar25 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar20 + (uVar25 < uVar24) + uVar12;

    }

    uVar21 = puVar18[2];

    uVar20 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar27 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar25 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar27 = uVar25 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar25) + uVar12;

    }

    uVar21 = puVar18[3];

    uVar20 = *(unsigned int *)puVar7;

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

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

    uVar5 = puVar18[4];

    uVar21 = *(unsigned int *)(puVar7 + 4);

    uVar4 = uVar5 ^ uVar21;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar23 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

    iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

    iVar10 = 0;

    uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar26 = uVar23 + (uVar24 << 16);

    uVar21 = iVar10 + (unsigned int)(uVar26 < uVar23) + (uVar24 >> 0x10) +

             (uVar21 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar26 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar20 = uVar21 + (uVar26 < uVar25) + (uVar20 & 0xffff);

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

      uVar20 = uVar21 + (uVar26 < uVar25) + uVar20;

    }

    *(unsigned int *)(0x06094A30 + 0x24) = (uVar12 << 0x10 | uVar27 >> 0x10) + puVar18[9];

    uVar21 = puVar18[5];

    uVar12 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar12;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar24 = (uVar12 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar12 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar12 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar27 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar26 + uVar27;

      uVar20 = uVar12 + (uVar27 < uVar26) + (uVar20 & 0xffff);

      if ((int)uVar20 < -0x8000) {

        uVar20 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar20) {

        uVar20 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar20 = uVar20 & 0xffff;

    }

    else {

      uVar27 = uVar26 + uVar27;

      uVar20 = uVar12 + (uVar27 < uVar26) + uVar20;

    }

    uVar21 = puVar18[6];

    uVar12 = *(unsigned int *)puVar7;

    uVar5 = uVar21 ^ uVar12;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar24 = (uVar12 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar12 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar12 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + (uVar4 << 16);

    uVar12 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar4 >> 0x10) +

             (uVar12 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar25 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar5 = puVar18[7];

    uVar21 = *(unsigned int *)(puVar7 + 4);

    uVar4 = uVar5 ^ uVar21;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar23 = (uVar21 & 0xffff) * (uVar5 & 0xffff);

    iVar11 = (uVar21 >> 0x10) * (uVar5 & 0xffff);

    iVar10 = 0;

    uVar24 = iVar11 + (uVar21 & 0xffff) * (uVar5 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar26 = uVar23 + (uVar24 << 16);

    uVar21 = iVar10 + (unsigned int)(uVar26 < uVar23) + (uVar24 >> 0x10) +

             (uVar21 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar26 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar21 + (uVar26 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar21 + (uVar26 < uVar25) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x28) = (uVar20 << 0x10 | uVar27 >> 0x10) + puVar18[10];

    uVar21 = puVar18[8];

    param_3 = puVar18 + 9;

    uVar20 = *(unsigned int *)(puVar7 + 8);

    uVar5 = uVar21 ^ uVar20;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar20 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar4 = iVar11 + (uVar20 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar27 = uVar24 + (uVar4 << 16);

    uVar20 = iVar10 + (unsigned int)(uVar27 < uVar24) + (uVar4 >> 0x10) +

             (uVar20 >> 0x10) * (uVar21 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar27 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar27 = ~uVar27 + 1;

      }

    }

    if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

      uVar27 = uVar26 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar26) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar27 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar27 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar27 = uVar26 + uVar27;

      uVar12 = uVar20 + (uVar27 < uVar26) + uVar12;

    }

    param_4 = puVar18 + 0xc;

    *(unsigned int *)(puVar8 + 0x2c) = (uVar12 << 0x10 | uVar27 >> 0x10) + puVar18[0xb];

    in_sr = uVar19 & 0xfffffffe | (unsigned int)(*(int *)(puVar8 + 0x2c) <= unaff_r10);

    bVar3 = (unsigned char)in_sr & 1;

    *(unsigned short *)(puVar6 + 6) = (unsigned short)bVar3;

    in_r3 = (int)*(short *)(puVar6 + 2) + (int)*(short *)puVar6;

    in_r0 = (unsigned int)bVar3 + (int)*(short *)(puVar6 + 4);

  } while( 1 );

}

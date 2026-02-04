extern int DAT_0602bb26;

extern int DAT_0602bbba;

extern int DAT_0602bbbc;

extern int DAT_0602bbbe;

extern int DAT_0602bd90;

extern int DAT_0602bd94;

extern int DAT_0602bd98;

extern void FUN_0602bc7a();
extern void FUN_0602bcfc();
extern void FUN_0602bd3c();

unsigned int FUN_0602b9e0(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    char param_3;
    int param_4;
{

  unsigned int uVar1;

  unsigned int uVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned int extraout_r1;

  unsigned int extraout_r2;

  unsigned int extraout_r3;

  unsigned int extraout_r3_00;

  unsigned int extraout_r3_01;

  unsigned int extraout_r3_02;

  unsigned int extraout_r3_03;

  int iVar6;

  int iVar7;

  int iVar8;

  unsigned int *puVar9;

  int iVar10;

  unsigned int *puVar11;

  int iVar12;

  int iVar13;

  unsigned int *puVar14;

  unsigned int *puVar15;

  int *puVar16;

  int iVar17;

  int iVar18;

  unsigned int in_sr;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  iVar7 = 0x40;

  puVar16 = (int *)0x06094AE4;

  do {

    *puVar16 = 0xffffffff;

    iVar7 = iVar7 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar16 = puVar16 + 4;

  } while (iVar7 != 0);

  puVar14 = (unsigned int *)(param_1 + param_4 * 0x18);

  do {

    puVar3 = 0x0602BD6C;

    puVar15 = puVar14 + -6;

    puVar11 = *(unsigned int **)0x0608A52C;

    puVar9 = (unsigned int *)0x0602BD8C;

    FUN_0602bc7a(*(short *)(puVar14 + -2));

    *puVar9 = extraout_r1;

    puVar9[1] = extraout_r2;

    puVar9[2] = extraout_r3;

    *(unsigned int *)0x0602BDB4 = extraout_r2;

    puVar4 = 0x0602BD9C;

    uVar19 = in_sr & 0xfffffffe;

    if ((puVar14[-3] & 0x80000) == 0) {

      uVar21 = *puVar11;

      uVar5 = *puVar15;

      uVar20 = uVar21 ^ uVar5;

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar2 = (uVar5 & 0xffff) * (uVar21 & 0xffff);

      iVar8 = (uVar5 >> 0x10) * (uVar21 & 0xffff);

      iVar7 = 0;

      uVar1 = iVar8 + (uVar5 & 0xffff) * (uVar21 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar22 = uVar2 + uVar1 * 0x10000;

      uVar5 = iVar7 + (unsigned int)(uVar22 < uVar2) + (uVar1 >> 0x10) + (uVar5 >> 0x10) * (uVar21 >> 0x10);

      if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar22 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      uVar20 = puVar11[1];

      uVar21 = puVar14[-5];

      uVar1 = uVar20 ^ uVar21;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar24 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar24 + uVar2 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar23 < uVar24) + (uVar2 >> 0x10) +

               (uVar21 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar5 = uVar21 + (uVar23 < uVar22) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar5 = uVar21 + (uVar23 < uVar22) + uVar5;

      }

      uVar20 = puVar11[2];

      uVar21 = puVar14[-4];

      uVar1 = uVar20 ^ uVar21;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar22 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) +

               (uVar21 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar24 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar5 = uVar21 + (uVar24 < uVar23) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar5 = uVar21 + (uVar24 < uVar23) + uVar5;

      }

      uVar20 = puVar11[3];

      uVar21 = *puVar15;

      uVar1 = uVar20 ^ uVar21;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar22 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar22 + uVar2 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar23 < uVar22) + (uVar2 >> 0x10) +

               (uVar21 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

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

      *(unsigned int *)0x0602BD9C = uVar5 << 0x10 | uVar24 >> 0x10;

      uVar20 = puVar11[4];

      uVar5 = puVar14[-5];

      uVar1 = uVar20 ^ uVar5;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar22 = (uVar5 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar5 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar5 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar5 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) + (uVar5 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar24 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar21 = uVar5 + (uVar24 < uVar23) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar21 = uVar5 + (uVar24 < uVar23) + uVar21;

      }

      uVar20 = puVar11[5];

      uVar5 = puVar14[-4];

      uVar1 = uVar20 ^ uVar5;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar22 = (uVar5 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar5 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar5 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar22 + uVar2 * 0x10000;

      uVar5 = iVar7 + (unsigned int)(uVar23 < uVar22) + (uVar2 >> 0x10) + (uVar5 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar23 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar23 = uVar24 + uVar23;

        uVar21 = uVar5 + (uVar23 < uVar24) + (uVar21 & 0xffff);

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

        uVar23 = uVar24 + uVar23;

        uVar21 = uVar5 + (uVar23 < uVar24) + uVar21;

      }

      uVar20 = puVar11[6];

      uVar5 = *puVar15;

      uVar1 = uVar20 ^ uVar5;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar22 = (uVar5 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar5 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar5 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar5 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) + (uVar5 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar24 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      *(unsigned int *)(puVar4 + 4) = uVar21 << 0x10 | uVar23 >> 0x10;

      uVar20 = puVar11[7];

      uVar21 = puVar14[-5];

      uVar1 = uVar20 ^ uVar21;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar22 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar22 + uVar2 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar23 < uVar22) + (uVar2 >> 0x10) +

               (uVar21 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar23 = uVar24 + uVar23;

        uVar5 = uVar21 + (uVar23 < uVar24) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar23 = uVar24 + uVar23;

        uVar5 = uVar21 + (uVar23 < uVar24) + uVar5;

      }

      uVar20 = puVar11[8];

      uVar21 = puVar14[-4];

      uVar1 = uVar20 ^ uVar21;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar22 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) +

               (uVar21 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar24 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar5 = uVar21 + (uVar24 < uVar23) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar5 = uVar21 + (uVar24 < uVar23) + uVar5;

      }

      *(unsigned int *)(puVar4 + 8) = uVar5 << 0x10 | uVar24 >> 0x10;

      uVar21 = *(unsigned int *)puVar4;

      uVar5 = *puVar9;

      uVar20 = uVar21 ^ uVar5;

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar2 = (uVar5 & 0xffff) * (uVar21 & 0xffff);

      iVar8 = (uVar5 >> 0x10) * (uVar21 & 0xffff);

      iVar7 = 0;

      uVar1 = iVar8 + (uVar5 & 0xffff) * (uVar21 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar22 = uVar2 + uVar1 * 0x10000;

      uVar5 = iVar7 + (unsigned int)(uVar22 < uVar2) + (uVar1 >> 0x10) + (uVar5 >> 0x10) * (uVar21 >> 0x10);

      if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar22 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      uVar20 = *(unsigned int *)(puVar4 + 4);

      uVar21 = puVar9[1];

      uVar1 = uVar20 ^ uVar21;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar24 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar24 + uVar2 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar23 < uVar24) + (uVar2 >> 0x10) +

               (uVar21 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar5 = uVar21 + (uVar23 < uVar22) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar5 = uVar21 + (uVar23 < uVar22) + uVar5;

      }

      uVar20 = *(unsigned int *)(puVar4 + 8);

      uVar21 = puVar9[2];

      uVar1 = uVar20 ^ uVar21;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar22 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

      iVar7 = 0;

      uVar2 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) +

               (uVar21 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar24 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar5 = uVar21 + (uVar24 < uVar23) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar5 = uVar21 + (uVar24 < uVar23) + uVar5;

      }

      uVar5 = uVar5 << 0x10 | uVar24 >> 0x10;

      uVar19 = uVar19 | 0 < (int)uVar5;

      if (((unsigned char)uVar19 & 1) == 1) goto LAB_0602baa4;

    }

    else {

LAB_0602baa4:

      FUN_0602bd3c((int)*(short *)(puVar14 + -2));

      *puVar9 = extraout_r3_00;

      puVar9 = puVar9 + 1;

      FUN_0602bcfc();

      FUN_0602bd3c((int)*(short *)((int)puVar14 + -6));

      FUN_0602bc7a();

      *puVar9 = extraout_r3_01;

      puVar9 = puVar9 + 1;

      FUN_0602bcfc();

      FUN_0602bd3c((int)*(short *)(puVar14 + -1));

      FUN_0602bc7a();

      *puVar9 = extraout_r3_02;

      puVar9 = puVar9 + 1;

      FUN_0602bcfc();

      FUN_0602bd3c((int)*(short *)((int)puVar14 + -2));

      FUN_0602bc7a();

      *puVar9 = extraout_r3_03;

      FUN_0602bcfc();

      puVar4 = 0x0608AC20;

      uVar21 = *(unsigned int *)0x060620D4 & 0xffff;

      iVar17 = (int)DAT_0602bb26;

      uVar5 = *(unsigned int *)(puVar3 + -0x20);

      iVar7 = *(int *)(puVar3 + -0x18);

      iVar8 = *(int *)(puVar3 + -0x10);

      iVar12 = *(int *)(puVar3 + -8);

      uVar19 = uVar19 & 0xfffffffe;

      if ((((iVar17 <= (int)uVar5) || (iVar17 <= iVar7)) || (iVar17 <= iVar8)) || (iVar17 <= iVar12)

         ) {

        iVar17 = (int)DAT_0602bbba;

        uVar20 = uVar19 | (int)uVar5 < iVar17;

        if (((((unsigned char)uVar20 & 1) == 1) ||

            (uVar20 = uVar19 | iVar7 < iVar17, ((unsigned char)uVar20 & 1) == 1)) ||

           ((uVar20 = uVar19 | iVar8 < iVar17, ((unsigned char)uVar20 & 1) == 1 ||

            (uVar19 = uVar19 | iVar12 < iVar17, uVar20 = uVar19, ((unsigned char)uVar19 & 1) != 1)))) {

          iVar18 = (int)DAT_0602bbbc;

          iVar17 = *(int *)(puVar3 + -0x1c);

          iVar6 = *(int *)(puVar3 + -0x14);

          iVar10 = *(int *)(puVar3 + -0xc);

          iVar13 = *(int *)(puVar3 + -4);

          uVar19 = uVar20 & 0xfffffffe;

          if (((iVar18 <= iVar17) || (iVar18 <= iVar6)) ||

             ((iVar18 <= iVar10 || (uVar19 = uVar19 | iVar13 < iVar18, ((unsigned char)uVar19 & 1) != 1)))) {

            iVar18 = (int)DAT_0602bbbe;

            uVar19 = uVar19 & 0xfffffffe;

            if ((((iVar17 < iVar18) || (iVar6 < iVar18)) || (iVar10 < iVar18)) || (iVar13 < iVar18))

            {

              *(short *)(0x0608AC20 + uVar21 * 0x18 + 0x16) = (short)iVar13;

              *(short *)(puVar4 + uVar21 * 0x18 + 0x14) = (short)iVar12;

              *(short *)(puVar4 + uVar21 * 0x18 + 0x12) = (short)iVar10;

              *(short *)(puVar4 + uVar21 * 0x18 + 0x10) = (short)iVar8;

              *(short *)(puVar4 + uVar21 * 0x18 + 0xe) = (short)iVar6;

              *(short *)(puVar4 + uVar21 * 0x18 + 0xc) = (short)iVar7;

              *(short *)(puVar4 + uVar21 * 0x18 + 10) = (short)iVar17;

              *(short *)(puVar4 + uVar21 * 0x18 + 8) = (short)uVar5;

              *(short *)(puVar4 + uVar21 * 0x18 + 6) = *(short *)((int)puVar14 + -10);

              puVar4[uVar21 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar14 + -3) >> 4) & 0xf;

              puVar4[uVar21 * 0x18 + 5] = param_3;

              uVar19 = (**(void **)(0x0602BDB8 + ((int)*(short *)(puVar14 + -3) & 7U) * 4))

                                 (DAT_0602bd90,DAT_0602bd94,DAT_0602bd98);

              return uVar19;

            }

          }

        }

      }

    }

    param_4 = param_4 + -1;

    in_sr = uVar19 & 0xfffffffe | (unsigned int)(param_4 == 0);

    puVar14 = puVar15;

    if (((unsigned char)in_sr & 1) == 1) {

      return uVar5;

    }

  } while( true );

}

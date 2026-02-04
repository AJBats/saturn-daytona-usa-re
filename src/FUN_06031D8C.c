void FUN_06031d8c(param_1, param_2)
    unsigned int *param_1;
    int param_2;
{

  unsigned int uVar1;

  int iVar2;

  int iVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  int *piVar6;

  unsigned int *puVar7;

  unsigned int in_sr;

  unsigned int uVar8;

  unsigned int uVar9;

  unsigned int uVar10;

  unsigned int uVar11;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  unsigned int uVar18;

  puVar7 = (unsigned int *)*0x06089EDC;

  piVar6 = (int *)0x06094FA8;

  do {

    uVar9 = *puVar7;

    uVar8 = *param_1;

    uVar10 = uVar9 ^ uVar8;

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar8 < 0) {

      uVar8 = -uVar8;

    }

    uVar4 = (uVar8 & 0xffff) * (uVar9 & 0xffff);

    iVar3 = (uVar8 >> 0x10) * (uVar9 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar3 + (uVar8 & 0xffff) * (uVar9 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar11 = uVar4 + uVar1 * 0x10000;

    uVar8 = iVar2 + (unsigned int)(uVar11 < uVar4) + (uVar1 >> 0x10) + (uVar8 >> 0x10) * (uVar9 >> 0x10);

    if ((int)-(unsigned int)((int)uVar10 < 0) < 0) {

      uVar8 = ~uVar8;

      if (uVar11 == 0) {

        uVar8 = uVar8 + 1;

      }

      else {

        uVar11 = ~uVar11 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar8 < -0x8000) {

        uVar8 = 0xffff8000;

        uVar11 = 0;

      }

      if (0x7fff < (int)uVar8) {

        uVar8 = 0x7fff;

        uVar11 = 0xffffffff;

      }

      uVar8 = uVar8 & 0xffff;

    }

    uVar10 = puVar7[1];

    uVar9 = param_1[1];

    uVar1 = uVar10 ^ uVar9;

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar5 = (uVar9 & 0xffff) * (uVar10 & 0xffff);

    iVar3 = (uVar9 >> 0x10) * (uVar10 & 0xffff);

    iVar2 = 0;

    uVar4 = iVar3 + (uVar9 & 0xffff) * (uVar10 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar5 + uVar4 * 0x10000;

    uVar9 = iVar2 + (unsigned int)(uVar13 < uVar5) + (uVar4 >> 0x10) + (uVar9 >> 0x10) * (uVar10 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar13 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar13 = uVar11 + uVar13;

      uVar8 = uVar9 + (uVar13 < uVar11) + (uVar8 & 0xffff);

      if ((int)uVar8 < -0x8000) {

        uVar8 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar8) {

        uVar8 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar8 = uVar8 & 0xffff;

    }

    else {

      uVar13 = uVar11 + uVar13;

      uVar8 = uVar9 + (uVar13 < uVar11) + uVar8;

    }

    uVar4 = puVar7[9];

    uVar10 = puVar7[2];

    uVar9 = param_1[2];

    uVar1 = uVar10 ^ uVar9;

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar5 = (uVar9 & 0xffff) * (uVar10 & 0xffff);

    iVar3 = (uVar9 >> 0x10) * (uVar10 & 0xffff);

    iVar2 = 0;

    uVar11 = iVar3 + (uVar9 & 0xffff) * (uVar10 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar12 = uVar5 + uVar11 * 0x10000;

    uVar9 = iVar2 + (unsigned int)(uVar12 < uVar5) + (uVar11 >> 0x10) + (uVar9 >> 0x10) * (uVar10 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar12 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar12 = ~uVar12 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar12 = uVar13 + uVar12;

      uVar8 = uVar9 + (uVar12 < uVar13) + (uVar8 & 0xffff);

      if ((int)uVar8 < -0x8000) {

        uVar8 = 0xffff8000;

        uVar12 = 0;

      }

      if (0x7fff < (int)uVar8) {

        uVar8 = 0x7fff;

        uVar12 = 0xffffffff;

      }

      uVar8 = uVar8 & 0xffff;

    }

    else {

      uVar12 = uVar13 + uVar12;

      uVar8 = uVar9 + (uVar12 < uVar13) + uVar8;

    }

    uVar10 = puVar7[3];

    uVar9 = *param_1;

    uVar1 = uVar10 ^ uVar9;

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar5 = (uVar9 & 0xffff) * (uVar10 & 0xffff);

    iVar3 = (uVar9 >> 0x10) * (uVar10 & 0xffff);

    iVar2 = 0;

    uVar11 = iVar3 + (uVar9 & 0xffff) * (uVar10 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar5 + uVar11 * 0x10000;

    uVar9 = iVar2 + (unsigned int)(uVar13 < uVar5) + (uVar11 >> 0x10) + (uVar9 >> 0x10) * (uVar10 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar13 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar1 = puVar7[4];

    uVar10 = param_1[1];

    uVar11 = uVar1 ^ uVar10;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar15 = (uVar10 & 0xffff) * (uVar1 & 0xffff);

    iVar3 = (uVar10 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar5 = iVar3 + (uVar10 & 0xffff) * (uVar1 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar15 + uVar5 * 0x10000;

    uVar10 = iVar2 + (unsigned int)(uVar14 < uVar15) + (uVar5 >> 0x10) + (uVar10 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar11 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar14 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar14 = uVar13 + uVar14;

      uVar9 = uVar10 + (uVar14 < uVar13) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar14 = uVar13 + uVar14;

      uVar9 = uVar10 + (uVar14 < uVar13) + uVar9;

    }

    uVar1 = puVar7[5];

    uVar10 = param_1[2];

    uVar11 = uVar1 ^ uVar10;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar13 = (uVar10 & 0xffff) * (uVar1 & 0xffff);

    iVar3 = (uVar10 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar5 = iVar3 + (uVar10 & 0xffff) * (uVar1 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar13 + uVar5 * 0x10000;

    uVar10 = iVar2 + (unsigned int)(uVar15 < uVar13) + (uVar5 >> 0x10) + (uVar10 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar11 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar15 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar9 = uVar10 + (uVar15 < uVar14) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar9 = uVar10 + (uVar15 < uVar14) + uVar9;

    }

    uVar5 = puVar7[10];

    uVar1 = puVar7[6];

    uVar10 = *param_1;

    uVar11 = uVar1 ^ uVar10;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar14 = (uVar10 & 0xffff) * (uVar1 & 0xffff);

    iVar3 = (uVar10 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar13 = iVar3 + (uVar10 & 0xffff) * (uVar1 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + uVar13 * 0x10000;

    uVar10 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar13 >> 0x10) + (uVar10 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar11 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar16 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    uVar11 = puVar7[7];

    uVar1 = param_1[1];

    uVar13 = uVar11 ^ uVar1;

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    uVar18 = (uVar1 & 0xffff) * (uVar11 & 0xffff);

    iVar3 = (uVar1 >> 0x10) * (uVar11 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar3 + (uVar1 & 0xffff) * (uVar11 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar18 + uVar14 * 0x10000;

    uVar1 = iVar2 + (unsigned int)(uVar17 < uVar18) + (uVar14 >> 0x10) + (uVar1 >> 0x10) * (uVar11 >> 0x10);

    if ((int)-(unsigned int)((int)uVar13 < 0) < 0) {

      uVar1 = ~uVar1;

      if (uVar17 == 0) {

        uVar1 = uVar1 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar10 = uVar1 + (uVar17 < uVar16) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar10 = uVar1 + (uVar17 < uVar16) + uVar10;

    }

    param_2 = param_2 + -1;

    uVar11 = puVar7[8];

    uVar1 = param_1[2];

    param_1 = param_1 + 3;

    uVar13 = uVar11 ^ uVar1;

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    uVar16 = (uVar1 & 0xffff) * (uVar11 & 0xffff);

    iVar3 = (uVar1 >> 0x10) * (uVar11 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar3 + (uVar1 & 0xffff) * (uVar11 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar18 = uVar16 + uVar14 * 0x10000;

    uVar1 = iVar2 + (unsigned int)(uVar18 < uVar16) + (uVar14 >> 0x10) + (uVar1 >> 0x10) * (uVar11 >> 0x10);

    if ((int)-(unsigned int)((int)uVar13 < 0) < 0) {

      uVar1 = ~uVar1;

      if (uVar18 == 0) {

        uVar1 = uVar1 + 1;

      }

      else {

        uVar18 = ~uVar18 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar18 = uVar17 + uVar18;

      uVar10 = uVar1 + (uVar18 < uVar17) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar18 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar18 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar18 = uVar17 + uVar18;

      uVar10 = uVar1 + (uVar18 < uVar17) + uVar10;

    }

    piVar6[2] = (uVar10 << 0x10 | uVar18 >> 0x10) + puVar7[0xb];

    *piVar6 = (uVar8 << 0x10 | uVar12 >> 0x10) + uVar4;

    piVar6[1] = (uVar9 << 0x10 | uVar15 >> 0x10) + uVar5;

    piVar6 = piVar6 + 3;

    in_sr = in_sr & 0xfffffffe;

  } while (param_2 != 0);

  return;

}

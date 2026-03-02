void FUN_06026f72(param_1)
    unsigned int *param_1;
{

  int iVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int *puVar4;

  unsigned int uVar5;

  int iVar6;

  unsigned int uVar7;

  int iVar8;

  unsigned int uVar9;

  unsigned int *puVar10;

  unsigned int uVar11;

  unsigned int *puVar12;

  unsigned int *puVar13;

  unsigned int uVar14;

  unsigned int *puVar15;

  unsigned int *puVar16;

  unsigned int in_sr;

  unsigned int uVar17;

  unsigned int uVar18;

  unsigned int uVar19;

  iVar8 = 3;

  puVar4 = *(unsigned int **)0x06089EDC;

  puVar15 = (unsigned int *)0x0608A4F0;

  do {

    puVar12 = puVar4;

    iVar6 = 3;

    do {

      uVar11 = in_sr;

      puVar10 = param_1;

      uVar7 = *puVar12;

      uVar5 = *puVar10;

      uVar9 = uVar7 ^ uVar5;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar2 = (uVar5 & 0xffff) * (uVar7 & 0xffff);

      iVar3 = (uVar5 >> 0x10) * (uVar7 & 0xffff);

      iVar1 = 0;

      uVar14 = iVar3 + (uVar5 & 0xffff) * (uVar7 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar17 = uVar2 + (uVar14 << 16);

      uVar5 = iVar1 + (unsigned int)(uVar17 < uVar2) + (uVar14 >> 0x10) + (uVar5 >> 0x10) * (uVar7 >> 0x10);

      if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar17 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar17 = ~uVar17 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar17 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar17 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      uVar9 = puVar12[1];

      uVar7 = puVar10[3];

      uVar14 = uVar9 ^ uVar7;

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar19 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

      iVar3 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

      iVar1 = 0;

      uVar2 = iVar3 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar18 = uVar19 + (uVar2 << 16);

      uVar7 = iVar1 + (unsigned int)(uVar18 < uVar19) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

      if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar18 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar18 = ~uVar18 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar18 = uVar17 + uVar18;

        uVar5 = uVar7 + (uVar18 < uVar17) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar18 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar18 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar18 = uVar17 + uVar18;

        uVar5 = uVar7 + (uVar18 < uVar17) + uVar5;

      }

      iVar6 = iVar6 + -1;

      in_sr = uVar11 & 0xfffffffe;

      uVar9 = puVar12[2];

      uVar7 = puVar10[6];

      uVar14 = uVar9 ^ uVar7;

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar17 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

      iVar3 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

      iVar1 = 0;

      uVar2 = iVar3 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar19 = uVar17 + (uVar2 << 16);

      uVar7 = iVar1 + (unsigned int)(uVar19 < uVar17) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

      if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar19 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar19 = ~uVar19 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar19 = uVar18 + uVar19;

        uVar5 = uVar7 + (uVar19 < uVar18) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar19 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar19 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar19 = uVar18 + uVar19;

        uVar5 = uVar7 + (uVar19 < uVar18) + uVar5;

      }

      *puVar15 = uVar5 << 0x10 | uVar19 >> 0x10;

      puVar15 = puVar15 + 1;

      param_1 = puVar10 + 1;

    } while (iVar6 != 0);

    param_1 = puVar10 + -2;

    iVar8 = iVar8 + -1;

    puVar4 = puVar12 + 3;

  } while (iVar8 != 0);

  puVar13 = puVar12 + -6;

  iVar8 = 3;

  do {

    puVar16 = puVar4;

    puVar12 = puVar15;

    uVar7 = *puVar13;

    uVar5 = puVar10[7];

    uVar9 = uVar7 ^ uVar5;

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar2 = (uVar5 & 0xffff) * (uVar7 & 0xffff);

    iVar1 = (uVar5 >> 0x10) * (uVar7 & 0xffff);

    iVar6 = 0;

    uVar14 = iVar1 + (uVar5 & 0xffff) * (uVar7 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar17 = uVar2 + (uVar14 << 16);

    uVar5 = iVar6 + (unsigned int)(uVar17 < uVar2) + (uVar14 >> 0x10) + (uVar5 >> 0x10) * (uVar7 >> 0x10);

    if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar17 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    uVar9 = puVar13[1];

    uVar7 = puVar10[8];

    uVar14 = uVar9 ^ uVar7;

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    uVar19 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

    iVar1 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

    iVar6 = 0;

    uVar2 = iVar1 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar18 = uVar19 + (uVar2 << 16);

    uVar7 = iVar6 + (unsigned int)(uVar18 < uVar19) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

    if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

      uVar7 = ~uVar7;

      if (uVar18 == 0) {

        uVar7 = uVar7 + 1;

      }

      else {

        uVar18 = ~uVar18 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      uVar18 = uVar17 + uVar18;

      uVar5 = uVar7 + (uVar18 < uVar17) + (uVar5 & 0xffff);

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar18 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar18 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    else {

      uVar18 = uVar17 + uVar18;

      uVar5 = uVar7 + (uVar18 < uVar17) + uVar5;

    }

    iVar8 = iVar8 + -1;

    uVar9 = puVar13[2];

    puVar13 = puVar13 + 3;

    uVar7 = puVar10[9];

    uVar14 = uVar9 ^ uVar7;

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    uVar17 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

    iVar1 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

    iVar6 = 0;

    uVar2 = iVar1 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar19 = uVar17 + (uVar2 << 16);

    uVar7 = iVar6 + (unsigned int)(uVar19 < uVar17) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

    if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

      uVar7 = ~uVar7;

      if (uVar19 == 0) {

        uVar7 = uVar7 + 1;

      }

      else {

        uVar19 = ~uVar19 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      uVar19 = uVar18 + uVar19;

      uVar5 = uVar7 + (uVar19 < uVar18) + (uVar5 & 0xffff);

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar19 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar19 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    else {

      uVar19 = uVar18 + uVar19;

      uVar5 = uVar7 + (uVar19 < uVar18) + uVar5;

    }

    *puVar12 = (uVar5 << 0x10 | uVar19 >> 0x10) + *puVar16;

    puVar15 = puVar12 + 1;

    puVar4 = puVar16 + 1;

  } while (iVar8 != 0);

  uVar5 = puVar12[-10];

  uVar7 = puVar12[-9];

  uVar9 = puVar12[-8];

  uVar11 = puVar12[-7];

  uVar14 = puVar12[-6];

  puVar16[-0xb] = puVar12[-0xb];

  puVar16[-10] = uVar5;

  puVar16[-9] = uVar7;

  puVar16[-8] = uVar9;

  puVar16[-7] = uVar11;

  puVar16[-6] = uVar14;

  uVar5 = puVar12[-4];

  uVar7 = puVar12[-3];

  uVar9 = puVar12[-2];

  uVar11 = puVar12[-1];

  uVar14 = *puVar12;

  puVar16[-5] = puVar12[-5];

  puVar16[-4] = uVar5;

  puVar16[-3] = uVar7;

  puVar16[-2] = uVar9;

  puVar16[-1] = uVar11;

  *puVar16 = uVar14;

  return;

}

void FUN_06026ffc(param_1, param_2)
    unsigned int *param_1;
    int *param_2;
{

  unsigned int uVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  int *piVar6;

  unsigned int uVar7;

  int iVar8;

  int iVar9;

  unsigned int *puVar10;

  unsigned int *puVar11;

  int *piVar12;

  unsigned int in_sr;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  puVar10 = *(unsigned int **)0x06089EDC;

  puVar11 = puVar10 + 9;

  iVar9 = 3;

  piVar6 = (int *)0x0608A520;

  do {

    piVar12 = piVar6;

    uVar4 = *puVar10;

    uVar13 = *param_1;

    uVar5 = uVar4 ^ uVar13;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar7 = (uVar13 & 0xffff) * (uVar4 & 0xffff);

    iVar3 = (uVar13 >> 0x10) * (uVar4 & 0xffff);

    iVar8 = 0;

    uVar1 = iVar3 + (uVar13 & 0xffff) * (uVar4 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar14 = uVar7 + (uVar1 << 16);

    uVar13 = iVar8 + (unsigned int)(uVar14 < uVar7) + (uVar1 >> 0x10) + (uVar13 >> 0x10) * (uVar4 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar14 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar5 = puVar10[1];

    uVar4 = param_1[1];

    uVar1 = uVar5 ^ uVar4;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    uVar2 = (uVar4 & 0xffff) * (uVar5 & 0xffff);

    iVar3 = (uVar4 >> 0x10) * (uVar5 & 0xffff);

    iVar8 = 0;

    uVar7 = iVar3 + (uVar4 & 0xffff) * (uVar5 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar15 = uVar2 + (uVar7 << 16);

    uVar4 = iVar8 + (unsigned int)(uVar15 < uVar2) + (uVar7 >> 0x10) + (uVar4 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar4 = ~uVar4;

      if (uVar15 == 0) {

        uVar4 = uVar4 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar13 = uVar4 + (uVar15 < uVar14) + (uVar13 & 0xffff);

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar13 = uVar4 + (uVar15 < uVar14) + uVar13;

    }

    uVar7 = *puVar11;

    puVar11 = puVar11 + 1;

    uVar5 = puVar10[2];

    puVar10 = puVar10 + 3;

    uVar4 = param_1[2];

    uVar1 = uVar5 ^ uVar4;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    uVar2 = (uVar4 & 0xffff) * (uVar5 & 0xffff);

    iVar3 = (uVar4 >> 0x10) * (uVar5 & 0xffff);

    iVar8 = 0;

    uVar14 = iVar3 + (uVar4 & 0xffff) * (uVar5 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar16 = uVar2 + (uVar14 << 16);

    uVar4 = iVar8 + (unsigned int)(uVar16 < uVar2) + (uVar14 >> 0x10) + (uVar4 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar4 = ~uVar4;

      if (uVar16 == 0) {

        uVar4 = uVar4 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar16 = uVar15 + uVar16;

      uVar13 = uVar4 + (uVar16 < uVar15) + (uVar13 & 0xffff);

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    else {

      uVar16 = uVar15 + uVar16;

      uVar13 = uVar4 + (uVar16 < uVar15) + uVar13;

    }

    iVar9 = iVar9 + -1;

    in_sr = in_sr & 0xfffffffe;

    *piVar12 = (uVar13 << 0x10 | uVar16 >> 0x10) + uVar7;

    piVar6 = piVar12 + 1;

  } while (iVar9 != 0);

  iVar9 = piVar12[-1];

  iVar8 = *piVar12;

  *param_2 = piVar12[-2];

  param_2[1] = iVar9;

  param_2[2] = iVar8;

  return;

}

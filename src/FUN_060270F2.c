char * FUN_060270f2(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  char *puVar7;

  char *puVar8;

  int iVar9;

  unsigned int *puVar10;

  unsigned int *puVar11;

  unsigned int in_sr;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  puVar8 = 0x0608A6B0;

  puVar7 = 0x0608A52C;

  *(int *)0x0608A6B0 = param_1;

  *(int *)(puVar8 + 4) = param_2;

  *(int *)(puVar8 + 8) = param_3;

  puVar10 = *(unsigned int **)puVar7;

  iVar9 = 3;

  puVar11 = puVar10 + 9;

  do {

    uVar5 = *(unsigned int *)puVar8;

    uVar12 = *puVar10;

    uVar6 = uVar5 ^ uVar12;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar5 & 0xffff);

    iVar4 = (uVar12 >> 0x10) * (uVar5 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar4 + (uVar12 & 0xffff) * (uVar5 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar3 + uVar1 * 0x10000;

    uVar12 = iVar2 + (unsigned int)(uVar13 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar13 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = *(unsigned int *)(puVar8 + 4);

    uVar5 = puVar10[1];

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar15 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar15 + uVar3 * 0x10000;

    uVar5 = iVar2 + (unsigned int)(uVar14 < uVar15) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar14 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + uVar12;

    }

    uVar6 = *(unsigned int *)(puVar8 + 8);

    uVar5 = puVar10[2];

    puVar10 = puVar10 + 3;

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar13 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar13 + uVar3 * 0x10000;

    uVar5 = iVar2 + (unsigned int)(uVar15 < uVar13) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar15 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + uVar12;

    }

    iVar9 = iVar9 + -1;

    in_sr = in_sr & 0xfffffffe;

    *puVar11 = (uVar12 << 0x10 | uVar15 >> 0x10) + *puVar11;

    puVar11 = puVar11 + 1;

  } while (iVar9 != 0);

  return puVar8;

}

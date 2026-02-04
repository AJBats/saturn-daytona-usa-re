extern void FUN_06027358();

unsigned int FUN_060271a2()
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  int iVar8;

  unsigned int *puVar9;

  int *piVar10;

  unsigned int *puVar11;

  unsigned int in_sr;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  piVar10 = (int *)(0x0608A6B0 + 4);

  puVar11 = (unsigned int *)0x0608A6B0;

  FUN_06027358();

  puVar11[2] = -*piVar10;

  puVar7 = 0x0608A52C;

  puVar11[3] = *puVar11;

  puVar9 = *(unsigned int **)puVar7;

  iVar8 = 3;

  do {

    uVar13 = *puVar9;

    uVar12 = *puVar11;

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + uVar1 * 0x10000;

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

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

    uVar6 = puVar9[2];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + uVar3 * 0x10000;

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

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

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + uVar3 * 0x10000;

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

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

    uVar1 = puVar9[2];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + uVar14 * 0x10000;

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[2] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

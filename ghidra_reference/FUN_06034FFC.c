int FUN_06034ffc()
{

  int bVar1;

  unsigned int uVar2;

  char cVar3;

  int bVar4;

  int bVar5;

  unsigned int uVar6;

  int in_r0;

  int in_r1;

  unsigned int uVar7;

  unsigned int uVar8;

  unsigned int uVar9;

  unsigned int uVar11;

  unsigned int uVar12;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  unsigned int uVar18;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  unsigned int uVar27;

  unsigned int uVar28;

  unsigned int uVar29;

  unsigned int uVar30;

  unsigned int uVar31;

  unsigned int uVar32;

  unsigned int uVar33;

  unsigned int uVar34;

  unsigned int uVar35;

  unsigned int uVar36;

  unsigned int uVar37;

  unsigned int uVar38;

  unsigned int uVar39;

  unsigned int uVar40;

  unsigned int uVar41;

  unsigned int uVar42;

  unsigned int uVar10;

  unsigned int uVar13;

  if (in_r0 != 0) {

    uVar6 = -(unsigned int)(in_r1 < 0);

    uVar7 = in_r1 - (unsigned int)(uVar6 != 0);

    bVar1 = in_r0 < 0;

    uVar2 = (unsigned int)bVar1 << 9;

    uVar12 = (uVar7 << 1);

    uVar7 = (unsigned int)(in_r1 < 0) * -2 | (unsigned int)((uVar7 & 0x80000000) != 0);

    bVar4 = (int)uVar6 < 0 == bVar1;

    bVar5 = bVar1 == ((uVar6 & 0x80000000) != 0);

    uVar8 = (unsigned int)bVar4 * (uVar7 - in_r0) + (unsigned int)!bVar4 * (uVar7 + in_r0);

    cVar3 = bVar4 * (uVar7 < uVar8) + !bVar4 * (uVar8 < uVar7);

    uVar7 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar13 = uVar2 | uVar7;

    uVar9 = (uVar8 << 1) | (unsigned int)((uVar12 & 0x80000000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar8 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar9 - in_r0) + (unsigned int)!bVar4 * (uVar9 + in_r0);

    cVar3 = bVar4 * (uVar9 < uVar10) + !bVar4 * (uVar10 < uVar9);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar14 = uVar2 | uVar7 & 0xfffffeff | uVar13;

    uVar9 = uVar2 | uVar7 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40000000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar15 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20000000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar16 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10000000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar17 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x8000000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar18 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x4000000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar19 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x2000000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar20 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x1000000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar21 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x800000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar22 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x400000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar23 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x200000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar24 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x100000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar25 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x80000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar26 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar27 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar28 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar29 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x8000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar30 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x4000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar31 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x2000) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar32 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x1000) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar33 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x800) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar34 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x400) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar35 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x200) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar36 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x100) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar37 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x80) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar38 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar39 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar40 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar41 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 8) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar42 = uVar9 | uVar8 & 0xfffffeff | uVar13;

    uVar9 = uVar9 | uVar8 & 0xfffffefe;

    uVar8 = uVar9 | uVar13;

    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 4) != 0);

    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);

    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);

    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    uVar11 = uVar9 | uVar13 & 0xfffffeff | uVar8;

    uVar9 = uVar9 | uVar13 & 0xfffffefe;

    uVar13 = uVar9 | uVar8;

    uVar12 = (uVar10 << 1) | (unsigned int)((uVar12 & 2) != 0);

    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);

    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar4 * (uVar12 - in_r0) + (unsigned int)!bVar4 * (uVar12 + in_r0);

    cVar3 = bVar4 * (uVar12 < uVar13) + !bVar4 * (uVar13 < uVar12);

    uVar13 = uVar9 | uVar8 & 0xfffffeff |

             (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;

    return ((((((((((((((((((((((((((((((((unsigned int)(((unsigned char)((uVar2 | uVar7) >> 8) & 1) ==

                                                ((unsigned char)((uVar2 | uVar7) >> 9) & 1)) << 1 |

                                         (unsigned int)(((unsigned char)(uVar14 >> 8) & 1) ==

                                               ((unsigned char)(uVar14 >> 9) & 1))) << 1 |

                                        (unsigned int)(((unsigned char)(uVar15 >> 8) & 1) ==

                                              ((unsigned char)(uVar15 >> 9) & 1))) << 1 |

                                       (unsigned int)(((unsigned char)(uVar16 >> 8) & 1) == ((unsigned char)(uVar16 >> 9) & 1)

                                             )) << 1 |

                                      (unsigned int)(((unsigned char)(uVar17 >> 8) & 1) == ((unsigned char)(uVar17 >> 9) & 1))

                                      ) << 1 | (unsigned int)(((unsigned char)(uVar18 >> 8) & 1) ==

                                                     ((unsigned char)(uVar18 >> 9) & 1))) << 1 |

                                    (unsigned int)(((unsigned char)(uVar19 >> 8) & 1) == ((unsigned char)(uVar19 >> 9) & 1)))

                                    << 1 | (unsigned int)(((unsigned char)(uVar20 >> 8) & 1) ==

                                                 ((unsigned char)(uVar20 >> 9) & 1))) << 1 |

                                  (unsigned int)(((unsigned char)(uVar21 >> 8) & 1) == ((unsigned char)(uVar21 >> 9) & 1))) <<

                                  1 | (unsigned int)(((unsigned char)(uVar22 >> 8) & 1) == ((unsigned char)(uVar22 >> 9) & 1))

                                 ) << 1 | (unsigned int)(((unsigned char)(uVar23 >> 8) & 1) ==

                                                ((unsigned char)(uVar23 >> 9) & 1))) << 1 |

                               (unsigned int)(((unsigned char)(uVar24 >> 8) & 1) == ((unsigned char)(uVar24 >> 9) & 1))) << 1

                              | (unsigned int)(((unsigned char)(uVar25 >> 8) & 1) == ((unsigned char)(uVar25 >> 9) & 1))) << 1

                             | (unsigned int)(((unsigned char)(uVar26 >> 8) & 1) == ((unsigned char)(uVar26 >> 9) & 1))) << 1

                            | (unsigned int)(((unsigned char)(uVar27 >> 8) & 1) == ((unsigned char)(uVar27 >> 9) & 1))) << 1 |

                           (unsigned int)(((unsigned char)(uVar28 >> 8) & 1) == ((unsigned char)(uVar28 >> 9) & 1))) << 1 |

                          (unsigned int)(((unsigned char)(uVar29 >> 8) & 1) == ((unsigned char)(uVar29 >> 9) & 1))) << 1 |

                         (unsigned int)(((unsigned char)(uVar30 >> 8) & 1) == ((unsigned char)(uVar30 >> 9) & 1))) << 1 |

                        (unsigned int)(((unsigned char)(uVar31 >> 8) & 1) == ((unsigned char)(uVar31 >> 9) & 1))) << 1 |

                       (unsigned int)(((unsigned char)(uVar32 >> 8) & 1) == ((unsigned char)(uVar32 >> 9) & 1))) << 1 |

                      (unsigned int)(((unsigned char)(uVar33 >> 8) & 1) == ((unsigned char)(uVar33 >> 9) & 1))) << 1 |

                     (unsigned int)(((unsigned char)(uVar34 >> 8) & 1) == ((unsigned char)(uVar34 >> 9) & 1))) << 1 |

                    (unsigned int)(((unsigned char)(uVar35 >> 8) & 1) == ((unsigned char)(uVar35 >> 9) & 1))) << 1 |

                   (unsigned int)(((unsigned char)(uVar36 >> 8) & 1) == ((unsigned char)(uVar36 >> 9) & 1))) << 1 |

                  (unsigned int)(((unsigned char)(uVar37 >> 8) & 1) == ((unsigned char)(uVar37 >> 9) & 1))) << 1 |

                 (unsigned int)(((unsigned char)(uVar38 >> 8) & 1) == ((unsigned char)(uVar38 >> 9) & 1))) << 1 |

                (unsigned int)(((unsigned char)(uVar39 >> 8) & 1) == ((unsigned char)(uVar39 >> 9) & 1))) << 1 |

               (unsigned int)(((unsigned char)(uVar40 >> 8) & 1) == ((unsigned char)(uVar40 >> 9) & 1))) << 1 |

              (unsigned int)(((unsigned char)(uVar41 >> 8) & 1) == ((unsigned char)(uVar41 >> 9) & 1))) << 1 |

             (unsigned int)(((unsigned char)(uVar42 >> 8) & 1) == ((unsigned char)(uVar42 >> 9) & 1))) << 1 |

            (unsigned int)(((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1))) << 1 |

           (unsigned int)(((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1))) +

           (unsigned int)(bVar1 != (int)uVar6 < 0);

  }

  *(int *)0x060A246C = 0x0000044E;

  return 0;

}

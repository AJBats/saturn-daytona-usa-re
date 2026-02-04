long long FUN_06036be4()
{

  int bVar1;

  int bVar2;

  unsigned int uVar3;

  char cVar4;

  int bVar5;

  int bVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  char *puVar9;

  int in_r0;

  int in_r1;

  unsigned int uVar10;

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

  unsigned int uVar43;

  unsigned int uVar44;

  unsigned int uVar13;

  puVar9 = 0x060A246C;

  if (in_r0 != 0) {

    bVar1 = in_r1 < 0;

    uVar8 = -(unsigned int)bVar1;

    uVar10 = in_r1 - (unsigned int)(uVar8 != 0);

    bVar2 = in_r0 < 0;

    uVar3 = (unsigned int)bVar2 << 9;

    uVar7 = uVar10 * 2;

    uVar10 = (unsigned int)bVar1 * -2 | (unsigned int)((uVar10 & 0x80000000) != 0);

    bVar5 = (int)uVar8 < 0 == bVar2;

    bVar6 = bVar2 == ((uVar8 & 0x80000000) != 0);

    uVar11 = (unsigned int)bVar5 * (uVar10 - in_r0) + (unsigned int)!bVar5 * (uVar10 + in_r0);

    cVar4 = bVar5 * (uVar10 < uVar11) + !bVar5 * (uVar11 < uVar10);

    uVar10 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar15 = uVar3 | uVar10;

    uVar12 = uVar11 * 2 | (unsigned int)((uVar7 & 0x80000000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar12 - in_r0) + (unsigned int)!bVar5 * (uVar12 + in_r0);

    cVar4 = bVar5 * (uVar12 < uVar13) + !bVar5 * (uVar13 < uVar12);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar16 = uVar3 | uVar10 & 0xfffffeff | uVar15;

    uVar12 = uVar3 | uVar10 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x40000000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar17 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x20000000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar18 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x10000000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar19 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x8000000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar20 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x4000000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar21 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x2000000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar22 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x1000000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar23 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x800000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar24 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x400000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar25 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x200000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar26 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x100000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar27 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x80000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar28 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x40000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar29 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x20000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar30 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x10000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar31 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x8000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar32 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x4000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar33 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x2000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar34 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x1000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar35 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x800) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar36 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x400) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar37 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x200) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar38 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x100) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar39 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x80) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar40 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x40) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar41 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x20) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar42 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 0x10) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar43 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 8) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar44 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = uVar13 * 2 | (unsigned int)((uVar7 & 4) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar14 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar11 = uVar12 | uVar15 & 0xfffffefe | uVar11;

    uVar15 = uVar13 * 2 | (unsigned int)((uVar7 & 2) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    uVar15 = (unsigned int)bVar5 * (uVar15 - in_r0) + (unsigned int)!bVar5 * (uVar15 + in_r0);

    if ((int)uVar15 < 0 != bVar1) {

      uVar11 = ((int)uVar15 >> 1) << 1 | (unsigned int)((uVar15 & 1) == 1);

      bVar5 = (int)uVar15 < 0 == in_r0 < 0;

      uVar15 = (unsigned int)bVar5 * (uVar11 - in_r0) + (unsigned int)!bVar5 * (uVar11 + in_r0);

    }

    return CONCAT44((((((((((((((((((((((((((((((((unsigned int)(bVar2 != (int)uVar8 < 0) << 1 |

                                                 (unsigned int)(((unsigned char)((uVar3 | uVar10) >> 8) & 1) ==

                                                       ((unsigned char)((uVar3 | uVar10) >> 9) & 1))) << 1 |

                                                (unsigned int)(((unsigned char)(uVar16 >> 8) & 1) ==

                                                      ((unsigned char)(uVar16 >> 9) & 1))) << 1 |

                                               (unsigned int)(((unsigned char)(uVar17 >> 8) & 1) ==

                                                     ((unsigned char)(uVar17 >> 9) & 1))) << 1 |

                                              (unsigned int)(((unsigned char)(uVar18 >> 8) & 1) ==

                                                    ((unsigned char)(uVar18 >> 9) & 1))) << 1 |

                                             (unsigned int)(((unsigned char)(uVar19 >> 8) & 1) ==

                                                   ((unsigned char)(uVar19 >> 9) & 1))) << 1 |

                                            (unsigned int)(((unsigned char)(uVar20 >> 8) & 1) ==

                                                  ((unsigned char)(uVar20 >> 9) & 1))) << 1 |

                                           (unsigned int)(((unsigned char)(uVar21 >> 8) & 1) ==

                                                 ((unsigned char)(uVar21 >> 9) & 1))) << 1 |

                                          (unsigned int)(((unsigned char)(uVar22 >> 8) & 1) ==

                                                ((unsigned char)(uVar22 >> 9) & 1))) << 1 |

                                         (unsigned int)(((unsigned char)(uVar23 >> 8) & 1) ==

                                               ((unsigned char)(uVar23 >> 9) & 1))) << 1 |

                                        (unsigned int)(((unsigned char)(uVar24 >> 8) & 1) ==

                                              ((unsigned char)(uVar24 >> 9) & 1))) << 1 |

                                       (unsigned int)(((unsigned char)(uVar25 >> 8) & 1) == ((unsigned char)(uVar25 >> 9) & 1)

                                             )) << 1 |

                                      (unsigned int)(((unsigned char)(uVar26 >> 8) & 1) == ((unsigned char)(uVar26 >> 9) & 1))

                                      ) << 1 | (unsigned int)(((unsigned char)(uVar27 >> 8) & 1) ==

                                                     ((unsigned char)(uVar27 >> 9) & 1))) << 1 |

                                    (unsigned int)(((unsigned char)(uVar28 >> 8) & 1) == ((unsigned char)(uVar28 >> 9) & 1)))

                                    << 1 | (unsigned int)(((unsigned char)(uVar29 >> 8) & 1) ==

                                                 ((unsigned char)(uVar29 >> 9) & 1))) << 1 |

                                  (unsigned int)(((unsigned char)(uVar30 >> 8) & 1) == ((unsigned char)(uVar30 >> 9) & 1))) <<

                                  1 | (unsigned int)(((unsigned char)(uVar31 >> 8) & 1) == ((unsigned char)(uVar31 >> 9) & 1))

                                 ) << 1 | (unsigned int)(((unsigned char)(uVar32 >> 8) & 1) ==

                                                ((unsigned char)(uVar32 >> 9) & 1))) << 1 |

                               (unsigned int)(((unsigned char)(uVar33 >> 8) & 1) == ((unsigned char)(uVar33 >> 9) & 1))) << 1

                              | (unsigned int)(((unsigned char)(uVar34 >> 8) & 1) == ((unsigned char)(uVar34 >> 9) & 1))) << 1

                             | (unsigned int)(((unsigned char)(uVar35 >> 8) & 1) == ((unsigned char)(uVar35 >> 9) & 1))) << 1

                            | (unsigned int)(((unsigned char)(uVar36 >> 8) & 1) == ((unsigned char)(uVar36 >> 9) & 1))) << 1 |

                           (unsigned int)(((unsigned char)(uVar37 >> 8) & 1) == ((unsigned char)(uVar37 >> 9) & 1))) << 1 |

                          (unsigned int)(((unsigned char)(uVar38 >> 8) & 1) == ((unsigned char)(uVar38 >> 9) & 1))) << 1 |

                         (unsigned int)(((unsigned char)(uVar39 >> 8) & 1) == ((unsigned char)(uVar39 >> 9) & 1))) << 1 |

                        (unsigned int)(((unsigned char)(uVar40 >> 8) & 1) == ((unsigned char)(uVar40 >> 9) & 1))) << 1 |

                       (unsigned int)(((unsigned char)(uVar41 >> 8) & 1) == ((unsigned char)(uVar41 >> 9) & 1))) << 1 |

                      (unsigned int)(((unsigned char)(uVar42 >> 8) & 1) == ((unsigned char)(uVar42 >> 9) & 1))) << 1 |

                     (unsigned int)(((unsigned char)(uVar43 >> 8) & 1) == ((unsigned char)(uVar43 >> 9) & 1))) << 1 |

                    (unsigned int)(((unsigned char)(uVar44 >> 8) & 1) == ((unsigned char)(uVar44 >> 9) & 1))) << 1 |

                    (unsigned int)(((unsigned char)(uVar14 >> 8) & 1) == ((unsigned char)(uVar14 >> 9) & 1)),uVar15 + bVar1);

  }

  *(int *)0x060A246C = 0x0000044E;

  return ZEXT48(puVar9) << 0x20;

}

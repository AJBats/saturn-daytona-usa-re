extern int DAT_06021520;

extern int DAT_06021522;

extern int DAT_06021524;

extern int DAT_06021526;

extern int DAT_060218de;

extern int DAT_060218e0;

extern int DAT_060218e2;

extern int DAT_06021c2e;

extern int DAT_06021c32;

extern int DAT_06021e98;

extern int DAT_06021e9a;

extern int DAT_06021fe0;

extern int DAT_06022114;

extern int DAT_06022116;

extern int DAT_06022118;

extern int PTR_DAT_06021528;

extern int PTR_DAT_06021528;

void FUN_06021450()
{

  short uVar1;

  short uVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  int **ppuVar11;

  unsigned int uVar12;

  short uVar14;

  int uVar13;

  int *puVar15;

  int *piVar16;

  int extraout_r3;

  int extraout_r3_00;

  int extraout_r3_01;

  int *puVar17;

  int extraout_r3_02;

  int extraout_r3_03;

  int extraout_r3_04;

  int extraout_r3_05;

  int *extraout_r3_06;

  int *extraout_r3_07;

  int *extraout_r3_08;

  int *extraout_r3_09;

  int *extraout_r3_10;

  int *extraout_r3_11;

  int *extraout_r3_12;

  unsigned int uVar18;

  short uVar19;

  unsigned int uVar20;

  int iVar21;

  unsigned int *puVar22;

  char *puVar23;

  int iVar24;

  int *piVar25;

  int *piVar26;

  int *piVar27;

  int *piVar28;

  int *piVar33;

  int *local_34;

  unsigned int *puStack_30;

  unsigned int uStack_2c;

  int *puStack_28;

  int *puStack_24;

  int *piVar29;

  int *piVar30;

  int *piVar31;

  int *piVar32;

  int *piVar34;

  int *piVar35;

  puVar10 = 0x00200000;

  puVar9 = 0x00200000;

  puVar8 = 0x00200000;

  puVar7 = 0x06089D98;

  puVar23 = 0x060896B8;

  puVar6 = 0x060895A0;

  puVar5 = 0x06089744;

  puVar4 = 0x0608962C;

  puVar3 = 0x060897D0;

  uVar2 = DAT_06021522;

  uVar1 = DAT_06021520;

  iVar24 = 0x140;

  uVar18 = 0;

  if (*(int *)0x0607EAD8 == 0) {

    *(char **)0x06089D98 = 0x00200000 + (int)0x00037F08;

    *(int *)(puVar7 + 0x1c) = 0xc;

    *(char **)(puVar7 + 0x38) = puVar8 + (int)0x00037F98;

    *(int *)(puVar7 + 0x54) = 9;

    *(char **)(puVar7 + 0x70) = 0x00010000;

    *(int *)(puVar7 + DAT_06021526) = 10;

    uStack_2c = 0;

    puStack_28 = (int *)0x060507A4;

    local_34 = (int *)puVar3;

    puStack_24 = (int *)(puVar3 + PTR_DAT_06021528);

    do {

      puStack_30 = puStack_28;

      *local_34 = *puStack_28;

      local_34[1] = puStack_28[1];

      local_34[2] = -puStack_28[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      puVar15 = local_34;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)((int)puVar15 + 0x16) = uVar14;

      *(unsigned int *)(puVar23 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar4 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar5 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar6 + uStack_2c) = uVar18;

      uStack_2c = uStack_2c + 4;

      puStack_28 = puStack_28 + 4;

      local_34 = local_34 + 6;

    } while (local_34 < puStack_24);

  }

  else if (*(int *)0x0607EAD8 == 1) {

    *(char **)(0x06089D98 + 4) = 0x00200000 + (int)0x00089364;

    *(int *)(puVar7 + 0x20) = 0x12;

    *(char **)(puVar7 + 0x3c) = puVar9 + (int)0x0008943C;

    *(int *)(puVar7 + 0x58) = 0xb;

    *(char **)(puVar7 + 0x74) = 0x00010000;

    *(char **)(puVar7 + 8) = puVar9 + (int)0x00089124;

    *(int *)(puVar7 + 0x24) = 0x1c;

    *(char **)(puVar7 + 0x40) = puVar9 + (int)0x00089274;

    *(int *)(puVar7 + 0x5c) = 10;

    *(char **)(puVar7 + 0x78) = 0x0000CCCC;

    *(char **)(puVar7 + 0xc) = puVar9 + (int)0x00089544;

    *(int *)(puVar7 + 0x28) = 0x34;

    *(char **)(puVar7 + 0x44) = puVar9 + (int)0x000897B4;

    *(int *)(puVar7 + 0x60) = 0x1c;

    *(char **)(puVar7 + 0x7c) = 0x0000F333;

    *(int *)(puVar7 + 0x8c) = 0xf;

    uVar20 = 0;

    do {

      puVar17 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puVar15 = (int *)(0x06050844 + (char)((char)uVar20 * '\f'));

      *puVar17 = *puVar15;

      puVar17[1] = puVar15[1];

      puVar17[2] = -puVar15[2];

      puVar17[3] = 0;

      puVar17[4] = 0;

      *(short *)(puVar17 + 5) = 0;

      *(short *)((int)puVar17 + 0x16) = 0;

      iVar21 = (uVar20 << 2);

      uVar20 = uVar20 + 1;

      *(int *)(puVar23 + iVar21) = 0;

      *(int *)(puVar4 + iVar21) = 0;

      *(int *)(puVar5 + iVar21) = 0;

      *(int *)(puVar6 + iVar21) = 1;

    } while (uVar20 < 4);

    uStack_2c = 0;

    for (; uVar20 < 0xc; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050874 + ((uStack_2c & 0xff) * 0x14 & 0xff));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3 + 0x14) = uVar14;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_00 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 2;

      uStack_2c = uStack_2c + 1;

    }

    uStack_2c = uVar18;

    for (; uVar20 < 0xf; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050914 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_01 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 3;

      uStack_2c = uStack_2c + 1;

    }

  }

  else {

    *(char **)0x06089D98 = 0x00200000 + (int)0x000BE1F8;

    *(int *)(puVar7 + 0x1c) = 0xc;

    *(char **)(puVar7 + 0x38) = puVar10 + (int)0x000BE288;

    *(int *)(puVar7 + 0x54) = 9;

    *(char **)(puVar7 + 0x70) = 0x00010000;

    *(char **)(puVar7 + 8) = puVar10 + (int)0x000BE360;

    *(int *)(puVar7 + 0x24) = 0x1c;

    *(char **)(puVar7 + 0x40) = puVar10 + (int)0x000BE4B0;

    *(int *)(puVar7 + 0x5c) = 10;

    *(char **)(puVar7 + 0x78) = 0x0000CCCC;

    *(char **)(puVar7 + 0x10) = puVar10 + (int)0x000BDBF8;

    *(int *)(puVar7 + 0x2c) = 0x20;

    *(char **)(puVar7 + 0x48) = puVar10 + (int)0x000BDD78;

    *(int *)(puVar7 + 100) = 0xe;

    *(char **)(puVar7 + DAT_060218de) = 0x0000F333;

    *(char **)(puVar7 + 0x14) = puVar10 + (int)0x000BDEC8;

    *(int *)(puVar7 + 0x30) = 0xe;

    *(char **)(puVar7 + 0x4c) = puVar10 + (int)0x000BDF70;

    *(int *)(puVar7 + 0x68) = 10;

    *(char **)(puVar7 + DAT_060218e0) = 0x0000CCCC;

    *(char **)(puVar7 + 0x18) = puVar10 + (int)0x000BE060;

    *(int *)(puVar7 + 0x34) = 0xe;

    *(char **)(puVar7 + 0x50) = puVar10 + (int)0x000BE108;

    *(int *)(puVar7 + 0x6c) = 10;

    iVar21 = 0x88;

    *(char **)(puVar7 + iVar21) = 0x0000CCCC;

    *(int *)(puVar7 + iVar21 + 4) = 0x23;

    uVar20 = 0;

    do {

      puVar17 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puVar15 = (int *)(0x06050AE4 + (char)((char)uVar20 * '\f'));

      *puVar17 = *puVar15;

      puVar17[1] = puVar15[1];

      puVar17[2] = -puVar15[2];

      puVar17[3] = 0;

      puVar17[4] = 0;

      *(short *)(puVar17 + 5) = 0;

      *(short *)((int)puVar17 + 0x16) = 0;

      iVar21 = (uVar20 << 2);

      uVar20 = uVar20 + 1;

      *(int *)(puVar23 + iVar21) = 0;

      *(int *)(puVar4 + iVar21) = 0;

      *(int *)(puVar5 + iVar21) = 0;

      *(int *)(puVar6 + iVar21) = 0;

    } while (uVar20 < 9);

    uStack_2c = 0;

    for (; uVar12 = uVar18, uVar20 < 0x15; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050974 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_02 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 2;

      uStack_2c = uStack_2c + 1;

    }

    for (; uStack_2c = uVar12, uVar12 = uVar18, uVar20 < 0x18; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050944 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_03 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 4;

      uVar12 = uStack_2c + 1;

    }

    for (; uStack_2c = uVar12, uVar20 < 0x1d; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050A34 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_04 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 5;

      uVar12 = uStack_2c + 1;

    }

    uStack_2c = uVar18;

    for (; uVar20 < 0x23; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050A84 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_05 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 6;

      uStack_2c = uStack_2c + 1;

    }

  }

  puVar23 = 0x06089B18;

  *(unsigned int *)0x06089B18 = uVar18;

  *(short *)(puVar23 + 4) = DAT_06021c2e;

  *(short *)(puVar23 + 6) = 0x40008000;

  *(unsigned int *)(puVar23 + 8) = uVar18;

  uVar19 = (short)uVar18;

  *(short *)(puVar23 + 0xc) = uVar19;

  uVar14 = DAT_06021c32;

  *(short *)(puVar23 + 0xe) = DAT_06021c32;

  *(unsigned int *)(puVar23 + 0x10) = uVar18;

  *(short *)(puVar23 + 0x14) = uVar19;

  *(short *)(puVar23 + 0x16) = uVar14;

  puStack_30 = (unsigned int *)(puVar23 + 0x18);

  *(unsigned int *)(puVar23 + 0x18) = uVar18;

  *(short *)(puVar23 + 0x1c) = uVar19;

  *(short *)(puVar23 + 0x1e) = uVar14;

  uVar20 = 4;

  local_34 = (int *)0x06089B18;

  ppuVar11 = &local_34;

  do {

    piVar25 = (int *)ppuVar11;

    piVar25[1] = (uVar20 << 3) + *piVar25;

    piVar25[-9] = (int)(piVar25 + -9);

    (*(int(*)())0x06035BC8)();

    piVar25[-10] = 0x33333333;

    piVar25[-0xb] = 0x4054D333;

    piVar25[-0xc] = (int)(piVar25 + -7);

    (*(int(*)())0x060359E4)();

    piVar25[-0x13] = (int)(piVar25 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x16] = (int)(piVar25 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x17] = (int)(piVar25 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar25[-0x18] = 0x9999999A;

    piVar25[-0x19] = 0x40139999;

    piVar25[-0x1a] = (int)(piVar25 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar25[-0x1b] = (int)(piVar25 + -0x16);

    (*(int(*)())0x06035460)();

    piVar25[-0x1c] = 0;

    piVar25[-0x1d] = 0x40680000;

    piVar25[-0x1e] = (int)(piVar25 + -0x19);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    iVar21 = uVar20 + 1;

    *extraout_r3_06 = uVar13;

    *(short *)(piVar25[-0x1d] + 4) = uVar1;

    *(short *)(piVar25[-0x1d] + 6) = uVar2;

    piVar25[-0x1d] = (iVar21 << 3) + piVar25[-0x1e];

    piVar25[-0x27] = (int)(piVar25 + -0x27);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x28] = 0x33333333;

    piVar25[-0x29] = 0x4054D333;

    piVar25[-0x2a] = (int)(piVar25 + -0x25);

    (*(int(*)())0x060359E4)();

    piVar25[-0x31] = (int)(piVar25 + -0x31);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x34] = (int)(piVar25 + -0x34);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x35] = (int)(piVar25 + -0x30);

    (*(int(*)())0x060359E4)();

    piVar25[-0x36] = 0x9999999A;

    piVar25[-0x37] = 0x40139999;

    piVar25[-0x38] = (int)(piVar25 + -0x33);

    (*(int(*)())0x060359E4)();

    piVar25[-0x39] = (int)(piVar25 + -0x34);

    (*(int(*)())0x06035460)();

    piVar25[-0x3a] = 0;

    piVar25[-0x3b] = 0x40680000;

    piVar25[-0x3c] = (int)(piVar25 + -0x37);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    iVar21 = iVar21 + 1;

    *extraout_r3_07 = uVar13;

    *(short *)(piVar25[-0x3b] + 4) = uVar1;

    *(short *)(piVar25[-0x3b] + 6) = uVar2;

    piVar25[-0x3b] = (iVar21 << 3) + piVar25[-0x3c];

    piVar25[-0x45] = (int)(piVar25 + -0x45);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x46] = 0x33333333;

    piVar25[-0x47] = 0x4054D333;

    piVar25[-0x48] = (int)(piVar25 + -0x43);

    (*(int(*)())0x060359E4)();

    piVar25[-0x4f] = (int)(piVar25 + -0x4f);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x52] = (int)(piVar25 + -0x52);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x53] = (int)(piVar25 + -0x4e);

    (*(int(*)())0x060359E4)();

    piVar25[-0x54] = 0x9999999A;

    piVar25[-0x55] = 0x40139999;

    piVar25[-0x56] = (int)(piVar25 + -0x51);

    (*(int(*)())0x060359E4)();

    piVar25[-0x57] = (int)(piVar25 + -0x52);

    (*(int(*)())0x06035460)();

    piVar25[-0x58] = 0;

    piVar25[-0x59] = 0x40680000;

    piVar26 = piVar25 + -0x5a;

    piVar25[-0x5a] = (int)(piVar25 + -0x55);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_08 = uVar13;

    uVar20 = iVar21 + 1;

    *(short *)(piVar25[-0x59] + 4) = uVar1;

    *(short *)(piVar25[-0x59] + 6) = uVar2;

    ppuVar11 = (int **)(piVar25 + -0x5a);

  } while (uVar20 < 0x16);

  piVar25[-0x5a] = iVar21 + -0x15;

  piVar25[-0x58] = iVar21 + -0x15;

  piVar25[-0x59] = piVar25[-0x5a];

  piVar25[-0x56] = (int)0x06089B18;

  piVar31 = piVar25 + -0x5a;

  for (; uVar20 < 0x28; uVar20 = uVar20 + 1) {

    *(unsigned int *)((int)piVar31 + 0xc) = (uVar20 << 3) + *(int *)((int)piVar31 + 0x10);

    *(char **)((int)piVar31 + -0x24) = (char *)((int)piVar31 + -0x24);

    (*(int(*)())0x06035BC8)();

    *(int *)((int)piVar31 + -0x28) = 0x33333333;

    *(int *)((int)piVar31 + -0x2c) = 0x4054D333;

    *(char **)((int)piVar31 + -0x30) = (char *)((int)piVar31 + -0x1c);

    (*(int(*)())0x060359E4)();

    *(char **)((int)piVar31 + -0x4c) = (char *)((int)piVar31 + -0x4c);

    (*(int(*)())0x06035BC8)();

    *(char **)((int)piVar31 + -0x58) = (char *)((int)piVar31 + -0x58);

    (*(int(*)())0x06035BC8)();

    *(char **)((int)piVar31 + -0x5c) = (char *)((int)piVar31 + -0x48);

    (*(int(*)())0x060359E4)();

    *(int *)((int)piVar31 + -0x60) = 0x9999999A;

    *(int *)((int)piVar31 + -100) = 0x40139999;

    *(char **)((int)piVar31 + -0x68) = (char *)((int)piVar31 + -0x54);

    (*(int(*)())0x060359E4)();

    *(char **)((int)piVar31 + -0x6c) = (char *)((int)piVar31 + -0x58);

    (*(int(*)())0x06035460)();

    *(int *)((int)piVar31 + -0x70) = 0;

    *(int *)((int)piVar31 + -0x74) = 0x40580000;

    piVar26 = (int *)((int)piVar31 + -0x78);

    *(char **)((int)piVar31 + -0x78) = (char *)((int)piVar31 + -100);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_09 = uVar13;

    *(short *)(*(int *)((int)piVar31 + -0x6c) + 4) = DAT_06021e98;

    *(short *)(*(int *)((int)piVar31 + -0x6c) + 6) = DAT_06021e9a;

    *(int *)((int)piVar31 + -0x70) = *(int *)((int)piVar31 + -0x70) + 1;

    *(int *)((int)piVar31 + -0x74) = *(int *)((int)piVar31 + -0x74) + 1;

    *(int *)((int)piVar31 + -0x78) = *(int *)((int)piVar31 + -0x78) + 1;

    piVar31 = (int *)((int)piVar31 + -0x78);

  }

  *(char **)((int)piVar26 + 4) = 0x06089B18;

  uVar20 = uVar18;

  do {

    *piVar26 = (uVar20 << 3) + piVar26[1] + iVar24;

    piVar26[-9] = (int)(piVar26 + -9);

    (*(int(*)())0x06035BC8)();

    piVar26[-10] = 0x9999999A;

    piVar26[-0xb] = 0x404FD999;

    piVar26[-0xc] = (int)(piVar26 + -7);

    (*(int(*)())0x060359E4)();

    piVar26[-0x13] = (int)(piVar26 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x16] = (int)(piVar26 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x17] = (int)(piVar26 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar26[-0x18] = 0x9999999A;

    piVar26[-0x19] = 0x40139999;

    piVar26[-0x1a] = (int)(piVar26 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar26[-0x1b] = (int)(piVar26 + -0x16);

    (*(int(*)())0x06035460)();

    piVar26[-0x1c] = 0;

    piVar26[-0x1d] = 0x40700000;

    piVar26[-0x1e] = (int)(piVar26 + -0x19);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_10 = uVar13;

    iVar21 = uVar20 + 1;

    *(short *)(piVar26[-0x1e] + 4) = DAT_06021fe0;

    *(short *)(piVar26[-0x1e] + 6) = (short)uVar18;

    piVar26[-0x1e] = (iVar21 << 3) + piVar26[-0x1d] + iVar24;

    piVar26[-0x27] = (int)(piVar26 + -0x27);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x28] = 0x9999999A;

    piVar26[-0x29] = 0x404FD999;

    piVar26[-0x2a] = (int)(piVar26 + -0x25);

    (*(int(*)())0x060359E4)();

    piVar26[-0x31] = (int)(piVar26 + -0x31);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x34] = (int)(piVar26 + -0x34);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x35] = (int)(piVar26 + -0x30);

    (*(int(*)())0x060359E4)();

    piVar26[-0x36] = 0x9999999A;

    piVar26[-0x37] = 0x40139999;

    piVar26[-0x38] = (int)(piVar26 + -0x33);

    (*(int(*)())0x060359E4)();

    piVar26[-0x39] = (int)(piVar26 + -0x34);

    (*(int(*)())0x06035460)();

    piVar26[-0x3a] = 0;

    piVar27 = piVar26 + -0x3b;

    piVar26[-0x3b] = 0x40700000;

    piVar16 = piVar26 + -0x37;

    piVar28 = piVar26 + -0x3c;

    piVar29 = piVar26 + -0x3c;

    piVar30 = piVar26 + -0x3c;

    piVar31 = piVar26 + -0x3c;

    piVar32 = piVar26 + -0x3c;

    piVar26 = piVar26 + -0x3c;

    *piVar28 = (int)piVar16;

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_11 = uVar13;

    uVar20 = iVar21 + 1;

    *(short *)(*piVar29 + 4) = DAT_06022114;

    *(short *)(*piVar30 + 6) = (short)uVar18;

  } while (uVar20 < 0xe);

  *piVar27 = (int)0x06089B18;

  for (; uVar20 < 0x1c; uVar20 = uVar20 + 1) {

    *piVar31 = (uVar20 << 3) + piVar31[1] + iVar24;

    piVar31[-9] = (int)(piVar31 + -9);

    (*(int(*)())0x06035BC8)();

    piVar31[-10] = 0x9999999A;

    piVar31[-0xb] = 0x404FD999;

    piVar31[-0xc] = (int)(piVar31 + -7);

    (*(int(*)())0x060359E4)();

    piVar31[-0x13] = (int)(piVar31 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar31[-0x16] = (int)(piVar31 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar31[-0x17] = (int)(piVar31 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar31[-0x18] = 0x9999999A;

    piVar31[-0x19] = 0x40139999;

    piVar31[-0x1a] = (int)(piVar31 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar31[-0x1b] = (int)(piVar31 + -0x16);

    (*(int(*)())0x06035460)();

    piVar31[-0x1c] = 0;

    piVar31[-0x1d] = 0x40600000;

    piVar26 = piVar31 + -0x19;

    piVar33 = piVar31 + -0x1e;

    piVar34 = piVar31 + -0x1e;

    piVar35 = piVar31 + -0x1e;

    piVar32 = piVar31 + -0x1e;

    piVar31 = piVar31 + -0x1e;

    *piVar33 = (int)piVar26;

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_12 = uVar13;

    *(short *)(*piVar34 + 4) = (short)uVar18;

    *(short *)(*piVar35 + 6) = (short)uVar18;

  }

  *piVar32 = (int)0x06089B18;

  puVar22 = (unsigned int *)(0x06089B18 + iVar24 + (uVar20 << 3));

  piVar32[1] = (int)(0x06089B18 + DAT_06022116);

  if (puVar22 < 0x06089B18 + DAT_06022116) {

    do {

      *piVar32 = (int)puVar22;

      *puVar22 = uVar18;

      puVar22 = puVar22 + 2;

      *(short *)(*piVar32 + 4) = DAT_06022118;

      *(short *)(*piVar32 + 6) = (short)uVar18;

    } while (puVar22 < (unsigned int *)piVar32[1]);

  }

  return;

}

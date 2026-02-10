extern int DAT_06036832;
extern int DAT_06036a0e;
extern int DAT_06036fba;
extern int DAT_06036fbc;
extern int DAT_06036fbe;
extern int DAT_06036fc0;
extern int DAT_06036fc2;
extern int DAT_06037078;
extern int DAT_0603707a;
extern int DAT_0603707c;
extern int DAT_0603707e;
extern int DAT_06037154;
extern int DAT_06037156;
extern int DAT_0603728e;
extern int DAT_06037362;
extern int DAT_0603743a;
extern int DAT_06037532;
extern int DAT_06037534;
extern int DAT_06037536;
extern int DAT_060376a4;
extern int DAT_060376a6;
extern int DAT_060376a8;
extern int DAT_060378f8;
extern int DAT_060378fa;
extern int DAT_060378fc;
extern int DAT_060378fe;
extern int DAT_06037b10;
extern int DAT_06037c8e;
extern int DAT_06037c90;
extern int DAT_06037c92;
extern int DAT_06037c94;
extern int DAT_06037c96;
extern int FUN_06036650();
extern int PTR_DAT_060368d0;
extern int PTR_DAT_06036a8c;
extern int PTR_DAT_06036fc4;
extern int PTR_DAT_06037158;
extern int PTR_DAT_06037364;
extern int PTR_DAT_0603743c;
extern int PTR_DAT_06037900;
extern int PTR_DAT_06037c98;

void FUN_06036068()
{

  int in_r1 = 0;

  (*(int(*)())(0x06036086 + *(char *)(0x0603603C + in_r1)))();

  return;

}

char * FUN_060360fc(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    unsigned int param_3;
{

  char uVar1;

  unsigned int uVar2;

  char *puVar3;

  if (param_1 != param_2) {

    if (param_1 < param_2) {

      uVar2 = 0;

      puVar3 = param_1;

      if (param_3 != 0) {

        do {

          uVar1 = *param_2;

          param_2 = param_2 + 1;

          uVar2 = uVar2 + 1;

          *puVar3 = uVar1;

          puVar3 = puVar3 + 1;

        } while (uVar2 < param_3);

      }

    }

    else {

      puVar3 = param_1 + param_3;

      param_2 = param_2 + param_3;

      uVar2 = 0;

      if (param_3 != 0) {

        do {

          param_2 = param_2 + -1;

          uVar2 = uVar2 + 1;

          puVar3 = puVar3 + -1;

          *puVar3 = *param_2;

        } while (uVar2 < param_3);

      }

    }

  }

  return param_1;

}

void FUN_06036144(param_1)
    char param_1;
{

  char local_10 [4];

  char uStack_c;

  (*(int(*)())0x06035E90)(local_10);

  local_10[0] = 0x30;

  uStack_c = param_1;

  (*(int(*)())0x06035EC8)(0x40,local_10);

  return;

}

void FUN_060361fc(param_1, param_2, param_3)
    char param_1;
    int param_2;
    int param_3;
{
  int _local_18;
  int _uStack_14;

  char local_18;

  int uStack_17;

  char uStack_14;

  int uStack_13;

  (*(int(*)())0x06035E90)(&local_18);

  _local_18 = ((0x40) << 24 | (param_2) & 0xFFFFFF);

  _uStack_14 = ((param_1) << 24 | (param_3) & 0xFFFFFF);

  (*(int(*)())0x06035EC8)(0x40,&local_18);

  return;

}

void FUN_060362a8(param_1, param_2)
    char param_1;
    char *param_2;
{

  char local_14;

  char uStack_13;

  char uStack_12;

  char uStack_11;

  char uStack_10;

  char uStack_f;

  char uStack_e;

  char uStack_d;

  (*(int(*)())0x06035E90)(&local_14);

  local_14 = 0x42;

  uStack_13 = param_2[1];

  uStack_12 = param_2[2];

  uStack_11 = param_2[4];

  uStack_f = *param_2;

  uStack_e = param_2[3];

  uStack_d = param_2[5];

  uStack_10 = param_1;

  (*(int(*)())0x06035EC8)(0x40,&local_14);

  return;

}

void FUN_06036380(param_1, param_2)
    char param_1;
    char param_2;
{

  char local_14;

  char uStack_13;

  char uStack_10;

  (*(int(*)())0x06035E90)(&local_14);

  local_14 = 0x44;

  uStack_13 = param_2;

  uStack_10 = param_1;

  (*(int(*)())0x06035EC8)(0x40,&local_14);

  return;

}

int FUN_060363bc(param_1, param_2)
    char param_1;
    unsigned int *param_2;
{

  int uVar1;

  char uStack_1c;

  unsigned char bStack_1b;

  char local_14 [4];

  char uStack_10;

  (*(int(*)())0x06035E90)(local_14);

  local_14[0] = 0x45;

  uStack_10 = param_1;

  uVar1 = (*(int(*)())0x06035EA2)(0,local_14,&uStack_1c);

  *param_2 = (unsigned int)bStack_1b;

  return uVar1;

}

void FUN_06036414(param_1, param_2, param_3, param_4)
    char param_1;
    char param_2;
    char param_3;
    char param_4;
{

  char local_1c;

  char uStack_1b;

  char uStack_1a;

  char uStack_19;

  char uStack_18;

  (*(int(*)())0x06035E90)(&local_1c);

  local_1c = 0x46;

  uStack_1b = param_2;

  uStack_1a = param_3;

  uStack_19 = param_4;

  uStack_18 = param_1;

  (*(int(*)())0x06035EC8)(0x40,&local_1c);

  return;

}

void FUN_060364d4(param_1, param_2)
    char param_1;
    char param_2;
{

  char local_14;

  char uStack_13;

  char uStack_10;

  (*(int(*)())0x06035E90)(&local_14);

  local_14 = 0x48;

  uStack_13 = param_1;

  uStack_10 = param_2;

  (*(int(*)())0x06035EC8)(0x40,&local_14);

  return;

}

int FUN_06036518(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int *param_3;
{

  int uVar1;

  char auStack_20 [2];

  unsigned short uStack_1e;

  unsigned char bStack_1c;

  unsigned short uStack_1a;

  char local_18 [12];

  (*(int(*)())0x06035E90)(local_18);

  local_18[0] = 0x50;

  uVar1 = (*(int(*)())0x06035EA2)(0,local_18,auStack_20);

  *param_3 = (unsigned int)uStack_1e;

  *param_2 = (unsigned int)bStack_1c;

  *param_1 = (unsigned int)uStack_1a;

  return uVar1;

}

int FUN_06036572(param_1, param_2)
    char param_1;
    unsigned int *param_2;
{

  int uVar1;

  char auStack_1c [6];

  unsigned short uStack_16;

  char local_14 [4];

  char uStack_10;

  (*(int(*)())0x06035E90)(local_14);

  local_14[0] = 0x51;

  uStack_10 = param_1;

  uVar1 = (*(int(*)())0x06035EA2)(0,local_14,auStack_1c);

  *param_2 = (unsigned int)uStack_16;

  return uVar1;

}

void FUN_060365c4(param_1, param_2, param_3)
    char param_1;
    short param_2;
    short param_3;
{

  char local_18 [2];

  short uStack_16;

  char uStack_14;

  short uStack_12;

  (*(int(*)())0x06035E90)(local_18);

  local_18[0] = 0x52;

  uStack_16 = param_2;

  uStack_14 = param_1;

  uStack_12 = param_3;

  (*(int(*)())0x06035EC8)(0x40,local_18);

  return;

}

int FUN_0603660e(param_1)
    unsigned int *param_1;
{

  int uVar1;

  unsigned int local_18 [2];

  char local_10 [12];

  (*(int(*)())0x06035E90)(local_10);

  local_10[0] = 0x53;

  uVar1 = FUN_06036650(local_10,local_18);

  *param_1 = local_18[0] & 0x00FFFFFF;

  return uVar1;

}

int FUN_06036650(param_1, param_2)
    int param_1;
    int param_2;
{

  unsigned int uVar1;

  int uVar2;

  uVar1 = (*(int(*)())0x06035C4E)();

  if ((uVar1 & 0x40) == 0) {

    uVar2 = 0xffffffff;

  }

  else {

    uVar2 = (*(int(*)())0x06035EA2)(0,param_1,param_2);

  }

  return uVar2;

}

void FUN_060367e8(param_1, param_2, param_3)
    char param_1;
    short param_2;
    short param_3;
{

  char local_18 [2];

  short uStack_16;

  char uStack_14;

  short uStack_12;

  (*(int(*)())0x06035E90)(local_18);

  local_18[0] = 0x61;

  uStack_16 = param_2;

  uStack_14 = param_1;

  uStack_12 = param_3;

  (*(int(*)())0x06035EC8)(0x80,local_18);

  return;

}

void FUN_0603683c(param_1, param_2, param_3)
    char param_1;
    short param_2;
    short param_3;
{

  char local_18 [2];

  short uStack_16;

  char uStack_14;

  short uStack_12;

  (*(int(*)())0x06035E90)(local_18);

  local_18[0] = 0x62;

  uStack_16 = param_2;

  uStack_14 = param_1;

  uStack_12 = param_3;

  (*(int(*)())0x06035EC8)(0x80,local_18);

  return;

}

void FUN_0603697c(param_1, param_2, param_3, param_4)
    char param_1;
    short param_2;
    short param_3;
    char param_4;
{

  char local_1c;

  char uStack_1b;

  short uStack_1a;

  char uStack_18;

  short uStack_16;

  (*(int(*)())0x06035E90)(&local_1c);

  local_1c = 0x66;

  uStack_1b = param_4;

  uStack_1a = param_2;

  uStack_18 = param_1;

  uStack_16 = param_3;

  (*(int(*)())0x06035EC8)(0x100,&local_1c);

  return;

}

void FUN_06036a1c(param_1, param_2)
    char param_1;
    int param_2;
{
  int _uStack_10;

  char local_14 [4];

  char uStack_10;

  int uStack_f;

  (*(int(*)())0x06035E90)(local_14);

  local_14[0] = 0x70;

  _uStack_10 = ((param_1) << 24 | (param_2) & 0xFFFFFF);

  (*(int(*)())0x06035EC8)(0x200,local_14);

  return;

}

int FUN_06036a98(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int *param_3;
{

  int uVar1;

  char auStack_20 [2];

  unsigned short uStack_1e;

  unsigned int uStack_1c;

  char local_18 [12];

  (*(int(*)())0x06035E90)(local_18);

  local_18[0] = 0x72;

  uVar1 = (*(int(*)())0x06035EA2)(0,local_18,auStack_20);

  *param_2 = (unsigned int)uStack_1e;

  *param_3 = uStack_1c >> 0x18;

  *param_1 = uStack_1c & 0x00FFFFFF;

  return uVar1;

}

int FUN_06036af2(param_1, param_2)
    unsigned int param_1;
    int param_2;
{

  int iVar1;

  unsigned int local_1c [2];

  char local_14 [4];

  unsigned int uStack_10;

  (*(int(*)())0x06035E90)(local_14);

  local_14[0] = 0x73;

  uStack_10 = (unsigned int)param_1;

  iVar1 = (*(int(*)())0x06035EA2)(0,local_14,local_1c);

  if (iVar1 == 0) {

    iVar1 = (*(int(*)())0x06035CBC)(local_1c[0] & 0x00FFFFFF,param_2);

  }

  return iVar1;

}

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

  int in_r0 = 0;

  int in_r1 = 0;

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

    uVar7 = (uVar10 << 1);

    uVar10 = (unsigned int)bVar1 * -2 | (unsigned int)((uVar10 & 0x80000000) != 0);

    bVar5 = (int)uVar8 < 0 == bVar2;

    bVar6 = bVar2 == ((uVar8 & 0x80000000) != 0);

    uVar11 = (unsigned int)bVar5 * (uVar10 - in_r0) + (unsigned int)!bVar5 * (uVar10 + in_r0);

    cVar4 = bVar5 * (uVar10 < uVar11) + !bVar5 * (uVar11 < uVar10);

    uVar10 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar15 = uVar3 | uVar10;

    uVar12 = (uVar11 << 1) | (unsigned int)((uVar7 & 0x80000000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar12 - in_r0) + (unsigned int)!bVar5 * (uVar12 + in_r0);

    cVar4 = bVar5 * (uVar12 < uVar13) + !bVar5 * (uVar13 < uVar12);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar16 = uVar3 | uVar10 & 0xfffffeff | uVar15;

    uVar12 = uVar3 | uVar10 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x40000000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar17 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x20000000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar18 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x10000000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar19 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x8000000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar20 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x4000000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar21 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x2000000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar22 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x1000000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar23 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x800000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar24 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x400000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar25 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x200000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar26 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x100000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar27 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x80000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar28 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x40000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar29 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x20000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar30 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x10000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar31 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x8000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar32 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x4000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar33 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x2000) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar34 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x1000) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar35 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x800) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar36 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x400) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar37 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x200) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar38 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x100) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar39 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x80) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar40 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x40) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar41 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x20) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar42 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 0x10) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar43 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar12 = uVar12 | uVar15 & 0xfffffefe;

    uVar15 = uVar12 | uVar11;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 8) != 0);

    bVar5 = ((unsigned char)(uVar15 >> 8) & 1) == ((unsigned char)(uVar15 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar15 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar15 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar44 = uVar12 | uVar11 & 0xfffffeff | uVar15;

    uVar12 = uVar12 | uVar11 & 0xfffffefe;

    uVar11 = uVar12 | uVar15;

    uVar14 = (uVar13 << 1) | (unsigned int)((uVar7 & 4) != 0);

    bVar5 = ((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1);

    bVar6 = (int)((unsigned char)(uVar11 >> 9) & 1) == ((uVar13 & 0x80000000) != 0);

    uVar13 = (unsigned int)bVar5 * (uVar14 - in_r0) + (unsigned int)!bVar5 * (uVar14 + in_r0);

    cVar4 = bVar5 * (uVar14 < uVar13) + !bVar5 * (uVar13 < uVar14);

    uVar11 = (unsigned int)(unsigned char)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;

    uVar14 = uVar12 | uVar15 & 0xfffffeff | uVar11;

    uVar11 = uVar12 | uVar15 & 0xfffffefe | uVar11;

    uVar15 = (uVar13 << 1) | (unsigned int)((uVar7 & 2) != 0);

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

void FUN_06036cb0()
{

  char cVar1;

  char *in_r0;

  int *in_r1;

  int *puVar2;

  int *puVar3;

  int uVar4;

  int uVar5;

  uVar4 = *in_r1;

  puVar2 = in_r1 + 1;

  do {

    uVar5 = *puVar2;

    puVar3 = puVar2 + 1;

    if ((((char)uVar4 == '\0' || (char)((unsigned int)uVar4 >> 8) == '\0') ||

        (char)((unsigned int)uVar4 >> 0x10) == '\0') || (char)((unsigned int)uVar4 >> 0x18) == '\0') {

LAB_06036ce8:

      cVar1 = *(char *)(puVar3 + -2);

      *in_r0 = cVar1;

      if (cVar1 != '\0') {

        cVar1 = *(char *)((int)puVar3 + -7);

        in_r0[1] = cVar1;

        if (cVar1 != '\0') {

          cVar1 = *(char *)((int)puVar3 + -6);

          in_r0[2] = cVar1;

          if (cVar1 != '\0') {

            in_r0[3] = *(char *)((int)puVar3 + -5);

          }

        }

      }

      return;

    }

    *(int *)in_r0 = uVar4;

    uVar4 = *puVar3;

    puVar3 = puVar2 + 2;

    if ((((char)uVar5 == '\0' || (char)((unsigned int)uVar5 >> 8) == '\0') ||

        (char)((unsigned int)uVar5 >> 0x10) == '\0') || (char)((unsigned int)uVar5 >> 0x18) == '\0') {

      in_r0 = in_r0 + 4;

      goto LAB_06036ce8;

    }

    *(int *)(in_r0 + 4) = uVar5;

    uVar5 = *puVar3;

    puVar3 = puVar2 + 3;

    if ((((char)uVar4 == '\0' || (char)((unsigned int)uVar4 >> 8) == '\0') ||

        (char)((unsigned int)uVar4 >> 0x10) == '\0') || (char)((unsigned int)uVar4 >> 0x18) == '\0') {

      in_r0 = in_r0 + 8;

      goto LAB_06036ce8;

    }

    *(int *)(in_r0 + 8) = uVar4;

    uVar4 = *puVar3;

    puVar3 = puVar2 + 4;

    if ((((char)uVar5 == '\0' || (char)((unsigned int)uVar5 >> 8) == '\0') ||

        (char)((unsigned int)uVar5 >> 0x10) == '\0') || (char)((unsigned int)uVar5 >> 0x18) == '\0') {

      in_r0 = in_r0 + 0xc;

      goto LAB_06036ce8;

    }

    *(int *)(in_r0 + 0xc) = uVar5;

    in_r0 = in_r0 + 0x10;

    puVar2 = puVar3;

  } while( 1 );

}

int FUN_06036d14()
{

  char cVar1;

  char cVar2;

  char *in_r0;

  char *in_r1;

  int iVar3;

  int iVar4;

  if (((unsigned int)in_r1 & 3) == 0 && ((unsigned int)in_r0 & 3) == 0) {

    iVar3 = (*(int(*)())0x06036E1C)();

    return iVar3;

  }

  cVar1 = *in_r0;

  cVar2 = *in_r1;

  while( 1 ) {

    iVar4 = (int)cVar2;

    iVar3 = (int)cVar1;

    if ((iVar3 == 0) || (iVar4 != iVar3)) break;

    iVar3 = (int)in_r0[1];

    iVar4 = (int)in_r1[1];

    if ((iVar3 == 0) || (iVar4 != iVar3)) break;

    iVar3 = (int)in_r0[2];

    iVar4 = (int)in_r1[2];

    if ((iVar3 == 0) || (iVar4 != iVar3)) break;

    iVar3 = (int)in_r0[3];

    in_r0 = in_r0 + 4;

    iVar4 = (int)in_r1[3];

    in_r1 = in_r1 + 4;

    if ((iVar3 == 0) || (iVar4 != iVar3)) break;

    cVar1 = *in_r0;

    cVar2 = *in_r1;

  }

  return iVar3 - iVar4;

}

int FUN_06036d94(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    unsigned int param_3;
{

  char cVar1;

  char *pcVar2;

  unsigned int uVar3;

  if (param_3 == 0) {

    return 0;

  }

  uVar3 = 0;

  pcVar2 = param_1;

  if (param_3 != 0) {

    do {

      param_1 = pcVar2 + 1;

      cVar1 = *param_2;

      param_2 = param_2 + 1;

      if ((*pcVar2 != cVar1) || (*pcVar2 == '\0')) break;

      uVar3 = uVar3 + 1;

      pcVar2 = param_1;

    } while (uVar3 < param_3);

  }

  return (unsigned int)(unsigned char)param_1[-1] - (unsigned int)(unsigned char)param_2[-1];

}

char * FUN_06036ddc(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    unsigned int param_3;
{

  unsigned int uVar1;

  char *pcVar2;

  

  uVar1 = 0;

  pcVar2 = param_1;

  for (; (uVar1 < param_3 && (*param_2 != '\0')); param_2 = param_2 + 1) {

    *pcVar2 = *param_2;

    uVar1 = uVar1 + 1;

    pcVar2 = pcVar2 + 1;

  }

  for (; uVar1 < param_3; uVar1 = uVar1 + 1) {

    *pcVar2 = '\0';

    pcVar2 = pcVar2 + 1;

  }

  return param_1;

}

long long FUN_06036e1c()
{

  int *in_r0;

  int *piVar1;

  int *in_r1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  iVar4 = *in_r0;

  iVar5 = *in_r1;

  while( 1 ) {

    piVar2 = in_r1 + 1;

    piVar1 = in_r0 + 1;

    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||

        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;

    piVar3 = piVar2;

    if (iVar5 != iVar4) goto LAB_06036e82;

    iVar5 = *piVar2;

    piVar2 = in_r1 + 2;

    iVar4 = *piVar1;

    piVar1 = in_r0 + 2;

    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||

        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;

    piVar3 = piVar2;

    if (iVar5 != iVar4) goto LAB_06036e82;

    iVar5 = *piVar2;

    piVar2 = in_r1 + 3;

    iVar4 = *piVar1;

    piVar1 = in_r0 + 3;

    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||

        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;

    piVar3 = piVar2;

    if (iVar5 != iVar4) goto LAB_06036e82;

    iVar5 = *piVar2;

    piVar2 = in_r1 + 4;

    iVar4 = *piVar1;

    piVar1 = in_r0 + 4;

    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||

        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;

    piVar3 = piVar2;

    if (iVar5 != iVar4) goto LAB_06036e82;

    iVar4 = *piVar1;

    iVar5 = *piVar2;

    in_r0 = piVar1;

    in_r1 = piVar2;

  }

  iVar4 = (int)*(char *)(piVar1 + -1);

  iVar5 = (int)*(char *)(piVar2 + -1);

  piVar3 = (int *)((int)piVar2 + -3);

  if ((iVar5 != 0) && (iVar5 == iVar4)) {

    iVar4 = (int)*(char *)((int)piVar1 + -3);

    iVar5 = (int)*(char *)piVar3;

    piVar3 = (int *)((int)piVar2 + -2);

    if ((iVar5 != 0) && (iVar5 == iVar4)) {

      iVar4 = (int)*(char *)((int)piVar1 + -2);

      iVar5 = (int)*(char *)piVar3;

      piVar3 = (int *)((int)piVar2 + -1);

      if ((iVar5 != 0) && (iVar5 == iVar4)) {

        iVar4 = (int)*(char *)((int)piVar1 + -1);

        iVar5 = (int)*(char *)piVar3;

        piVar3 = piVar2;

      }

    }

  }

LAB_06036e82:

  return CONCAT44(piVar3,iVar4 - iVar5);

}

void FUN_06036e90(param_1, param_2, param_3)
    unsigned int param_1;
    unsigned short param_2;
    int param_3;
{

  char *puVar1;

  puVar1 = 0x060A3DF8;

  if ((param_2 == 1) || (param_2 == *(unsigned short *)0x060635B0)) {

    param_1 = param_1 & (unsigned int)0x0007FFFF;

    *(unsigned int *)(0x060A3DF8 + 0x3c) = param_1;

    (*(int(*)())0x06038A48)(param_1 | (unsigned int)0x25E00000,param_3,(unsigned int)param_2 << 1);

    *(unsigned int *)(puVar1 + 0x3c) = *(unsigned int *)(puVar1 + 0x3c) >> 1;

    if (param_2 != 1) {

      *(unsigned int *)(puVar1 + 0x3c) = *(unsigned int *)(puVar1 + 0x3c) | 0x80000000;

    }

    if (*(short *)0x060635AC == 0) {

      *(short *)0x060635AC = 1;

    }

  }

  return;

}

void FUN_06036f0c(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar5;

  int iVar6;

  puVar4 = 0x060A3D88;

  puVar3 = 0x060635B0;

  puVar2 = 0x060635AE;

  uVar1 = DAT_06036fba;

  iVar6 = *(int *)0x06000324;

  *(unsigned short *)0x060A3D88 = *(unsigned short *)0x060A3D88 & (unsigned short)0x0000FFCF;

  if (param_2 == '\0') {

    *(short *)puVar3 = DAT_06036fbc;

  }

  else {

    if (param_2 == '\x01') {

      *(short *)puVar3 = DAT_06036fbe;

      uVar5 = *(unsigned short *)puVar4 | 0x10;

    }

    else {

      if (param_2 != '\x02') goto LAB_06036f58;

      *(short *)puVar3 = DAT_06036fc0;

      uVar5 = *(unsigned short *)puVar4 | 0x20;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_06036f58:

  *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF3F;

  if (param_1 != '\0') {

    if (param_1 == '\x02') {

      uVar5 = *(unsigned short *)puVar4 | 0x80;

    }

    else {

      if (param_1 != '\x03') goto LAB_06036f86;

      *(short *)puVar3 = *(short *)puVar3 + *(short *)puVar3;

      uVar5 = *(unsigned short *)puVar4 | 0xc0;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_06036f86:

  *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFF0;

  if (param_3 == '\0') {

    if (iVar6 != 0) {

      (*(int(*)())(*(int *)0x06000320))(0);

    }

    *(short *)puVar2 = DAT_06036fc2;

  }

  else {

    if (param_3 == '\x01') {

      if (iVar6 != 1) {

        (*(int(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = PTR_DAT_06036fc4;

      uVar5 = *(unsigned short *)puVar4 | 1;

    }

    else if (param_3 == '\x02') {

      if (iVar6 != 0) {

        (*(int(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_06037078;

      uVar5 = *(unsigned short *)puVar4 | 2;

    }

    else if (param_3 == '\x03') {

      if (iVar6 != 1) {

        (*(int(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707a;

      uVar5 = *(unsigned short *)puVar4 | 3;

    }

    else if (param_3 == '\x04') {

      if (iVar6 != 0) {

        (*(int(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_0603707c;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 4;

    }

    else if (param_3 == '\x05') {

      if (iVar6 != 1) {

        (*(int(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707e;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 5;

    }

    else if (param_3 == '\x06') {

      if (iVar6 != 0) {

        (*(int(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_06037078;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 6;

    }

    else {

      if (param_3 != '\a') goto LAB_060370a0;

      if (iVar6 != 1) {

        (*(int(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707a;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 7;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_060370a0:

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return;

}

unsigned int FUN_060370e4(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned short uVar7;

  int iVar8;

  int *piVar9;

  unsigned char bVar10;

  puVar5 = 0x060A4C4C;

  puVar4 = 0x060A3E38;

  puVar3 = 0x060A3D88;

  puVar2 = 0x060A4C44;

  puVar1 = 0x0000FF00;

  *(int *)0x060A4C44 = 0;

  *(int *)(puVar2 + 4) = 0;

  *(int *)puVar5 = *param_1;

  *(int *)(puVar5 + 4) = param_1[1];

  *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & DAT_06037154;

  if (*(char *)(param_1 + 2) == '\x01') {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) | DAT_06037156;

  }

  else {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FEFF;

  }

  *(unsigned short *)(puVar3 + 0xe) = uVar7;

  if (*(char *)((int)param_1 + 9) == '\x01') {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) | PTR_DAT_06037158;

  }

  else {

    uVar7 = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FDFF;

  }

  *(unsigned short *)(puVar3 + 0xe) = uVar7;

  iVar8 = 0;

  bVar10 = 0;

  uVar7 = (unsigned short)puVar1;

  if (*(unsigned char *)((int)param_1 + 10) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFFC | (unsigned short)*(unsigned char *)((int)param_1 + 10)

    ;

    if (*(char *)((int)param_1 + 10) == '\x01') {

      bVar10 = *(int *)puVar5 == 0;

      if (!(int)bVar10) {

        *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFFC;

      }

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

      *(char **)puVar2 = 0x25E00000 + *(int *)puVar5;

      iVar8 = 1;

    }

  }

  else if (*(char *)((int)param_1 + 10) == '\x04') {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(char **)(puVar2 + 4) = 0x25E00000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)((int)param_1 + 0xb) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3 |

         (unsigned short)*(unsigned char *)((int)param_1 + 0xb) << 2;

    if (*(char *)((int)param_1 + 0xb) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 2;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 1;

        *(char **)puVar2 = 0x25E20000 + *(int *)puVar5;

        iVar8 = 1;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFF3;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_0603728e;

        *(char **)(puVar2 + 4) = 0x25E20000 + *(int *)(puVar5 + 4);

        iVar8 = iVar8 + 1;

      }

    }

  }

  else if (*(char *)((int)param_1 + 0xb) == '\x04') {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_06037362;

    *(char **)(puVar2 + 4) = 0x25E20000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)(param_1 + 3) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF | (unsigned short)*(unsigned char *)(param_1 + 3) << 4;

    if (*(char *)(param_1 + 3) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 3;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 2;

        *(char **)puVar2 = 0x25E40000 + *(int *)puVar5;

        iVar8 = 1;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FFCF;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | PTR_DAT_06037364;

        iVar8 = iVar8 + 1;

        *(char **)(puVar2 + 4) = 0x25E40000 + *(int *)(puVar5 + 4);

      }

    }

  }

  else if ((*(char *)(param_1 + 3) == '\x04') && (*(int *)0x060A4C50 != 0)) {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_0603743a;

    *(char **)(puVar2 + 4) = 0x25E40000 + *(int *)(puVar5 + 4);

  }

  if (*(unsigned char *)((int)param_1 + 0xd) < 4) {

    *(unsigned short *)(puVar3 + 0xe) =

         *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F |

         (unsigned short)*(unsigned char *)((int)param_1 + 0xd) << 6;

    if (*(char *)((int)param_1 + 0xd) == '\x01') {

      if (iVar8 == 0) {

        if (*(int *)puVar5 == 0) {

          bVar10 = 4;

        }

        else {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | 3;

        *(char **)puVar2 = 0x25E60000 + *(int *)puVar5;

      }

      else {

        if (*(int *)(puVar5 + 4) != 0) {

          *(unsigned short *)(puVar3 + 0xe) = *(unsigned short *)(puVar3 + 0xe) & (unsigned short)0x0000FF3F;

        }

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

        *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | PTR_DAT_0603743c;

        *(char **)(puVar2 + 4) = 0x25E60000 + *(int *)(puVar5 + 4);

      }

    }

  }

  else if ((*(char *)((int)param_1 + 0xd) == '\x04') && (*(int *)0x060A4C50 != 0)) {

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

    *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | DAT_06037532;

    *(char **)(puVar2 + 4) = 0x25E60000 + *(int *)(puVar5 + 4);

  }

  uVar6 = *(unsigned int *)(puVar2 + 4);

  if (uVar6 == 0) {

    if (((*(char *)((int)param_1 + 0xe) == '\x01') && (*(int *)0x060A4C44 == 0)) &&

       (iVar8 = (*(int(*)())0x0603C156)(), iVar8 == 1)) {

      uVar6 = (int)*(short *)(puVar3 + 0xe) | (unsigned int)0x00008000;

      *(short *)(puVar3 + 0xe) = (short)uVar6;

      *(char **)puVar2 = 0x25F00800;

    }

    else if ((*(int *)puVar2 == 0) || (*(int *)0x060A4C59 == '\0')) {

      uVar6 = *(unsigned int *)puVar2;

      if (uVar6 == 0) {

        if ((*(int *)puVar5 != 0) && (*(int *)0x060A4C58 != '\0')) {

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar7;

          piVar9 = (int *)puVar5;

          uVar7 = (*(int(*)())0x06034FFC)();

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) | uVar7;

          *(char **)puVar2 = 0x25E00000 + *piVar9;

        }

        uVar6 = *(unsigned int *)(puVar5 + 4);

        if ((uVar6 != 0) && (*(int *)0x060A4C59 != '\0')) {

          piVar9 = (int *)(puVar5 + 4);

          *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff;

          uVar6 = (*(int(*)())0x06034FFC)();

          uVar6 = (int)*(short *)(puVar4 + 6) | (uVar6 & 0xffff) << 8;

          *(short *)(puVar4 + 6) = (short)uVar6;

          *(char **)(puVar2 + 4) = 0x25E00000 + *piVar9;

        }

      }

    }

    else {

      if (*(int *)(puVar5 + 4) == 0) {

        *(int *)(puVar5 + 4) = *(int *)puVar5 + 0x400;

      }

      if (*(int *)puVar5 == 0) {

        *(int *)puVar5 = 0xffffffff;

      }

      *(int *)(puVar2 + 4) = *(int *)(puVar5 + 4) + *(int *)puVar2;

      *(unsigned short *)(puVar4 + 6) =

           DAT_06037536 & *(unsigned short *)(puVar4 + 6) | *(unsigned short *)(puVar4 + 6) << 8;

      uVar6 = (unsigned int)bVar10;

      if (uVar6 == 1) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFFC;

      }

      else if (uVar6 == 2) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFF3;

      }

      else if (uVar6 == 3) {

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FFCF;

      }

      else {

        if (uVar6 != 4) {

          return uVar6;

        }

        uVar6 = (int)*(short *)(puVar3 + 0xe) & (unsigned int)0x0000FF3F;

      }

      *(short *)(puVar3 + 0xe) = (short)uVar6;

    }

  }

  return uVar6;

}

int FUN_06037618(param_1)
    char *param_1;
{

  unsigned int uVar1;

  unsigned char bVar2;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  bVar2 = 0;

  param_1[6] = 0;

  param_1[8] = 0;

  param_1[7] = 0;

  *(short *)(param_1 + 10) = 0;

  do {

    uVar1 = (unsigned int)bVar2;

    bVar2 = bVar2 + 1;

    *(int *)(param_1 + (uVar1 << 2) + 0xc) = 0;

  } while (bVar2 < 0x10);

  return 0;

}

void FUN_06037660(param_1, param_2)
    unsigned short *param_1;
    unsigned char *param_2;
{

  unsigned char bVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  unsigned short *extraout_r3;

  unsigned short uVar8;

  unsigned short uVar11;

  char *puVar9;

  unsigned short *puVar10;

  char *puVar12;

  unsigned short local_38;

  char *puStack_2c;

  puVar12 = 0x060A3D88;

  puVar4 = 0x060A3DB0;

  uVar3 = DAT_060376a6;

  uVar2 = DAT_060376a4;

  puStack_2c = (char *)0x0;

  local_38 = (unsigned short)param_2[8];

  uVar11 = local_38 << 0xe & DAT_060376a8;

  puVar9 = (char *)(unsigned int)uVar11;

  uVar5 = (unsigned int)param_1 & 0xffff;

  uVar6 = (unsigned short)0x00008000;

  uVar7 = (unsigned short)0x0000BFFF;

  if (uVar5 == 1) {

    bVar1 = *param_2;

    *(unsigned short *)(0x060A3D88 + 0x20) =

         *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFEF;

    *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 4;

    uVar8 = (unsigned short)param_2[1] << 8 & DAT_06037c8e;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FEFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar8;

    *(short *)(puVar4 + 0x10) = *(short *)(param_2 + 10);

    bVar1 = param_2[2];

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) & uVar2;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) | (unsigned short)bVar1 << 0xf & uVar6;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) & uVar7;

    *(unsigned short *)(puVar4 + 0x10) = *(unsigned short *)(puVar4 + 0x10) | uVar11;

    uVar6 = (unsigned short)param_2[3] << 8 & DAT_06037c90;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FCFF;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | uVar6;

    uVar6 = (unsigned short)param_2[7] << 10 & DAT_06037c92;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000F3FF;

    *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | uVar6;

    uVar6 = (unsigned short)param_2[4] << 10 & DAT_06037c94;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FBFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    uVar6 = (unsigned short)param_2[5] << 0xc & DAT_06037c96;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x00008FFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    uVar6 = (unsigned short)param_2[6] << 9 & PTR_DAT_06037c98;

    param_1 = (unsigned short *)(unsigned int)uVar6;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FDFF;

    *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | uVar6;

    puVar12 = (void *)0x00000008;

    if ((*(int *)0x060A4C58 == '\x01') && (*(int *)0x060A4C59 == '\x01')) {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FFF0;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x28;

      puStack_2c = puVar4 + 0x38;

    }

    else if (*(int *)0x060A4C58 == '\x01') {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FFF0;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x28;

    }

    else if (*(int *)0x060A4C59 == '\x01') {

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FF0F;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x38;

    }

  }

  else if (uVar5 == 2) {

    if ((*(int *)0x060A4C58 == '\x01') && (*(int *)0x060A4C59 == '\x02')) {

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFDF;

      if (*param_2 != 0) {

        *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | 0x20;

      }

      bVar1 = param_2[1];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFE;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | bVar1 & 1;

      *(short *)(puVar4 + 8) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar2;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar7;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFFC;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | bVar1 & 3;

      bVar1 = param_2[5];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF8F;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 7) << 4;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFD;

      *(unsigned short *)(puVar4 + 0x16) = *(unsigned short *)(puVar4 + 0x16) & (unsigned short)0x0000FF0F;

      param_1 = (unsigned short *)(puVar4 + 0x16);

      puVar9 = puVar4 + 0x38;

      puVar12 = (void *)0x00000008;

    }

  }

  else {

    if (uVar5 == 4) {

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFFE;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | bVar1 & 1;

      bVar1 = param_2[1];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFE;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | bVar1 & 1;

      *(short *)(puVar4 + 8) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar2;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) & uVar7;

      *(unsigned short *)(puVar4 + 8) = *(unsigned short *)(puVar4 + 8) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFFC;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | bVar1 & 3;

      bVar1 = param_2[4];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFF3;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 3) << 2;

      bVar1 = param_2[5];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF8F;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 7) << 4;

      bVar1 = param_2[6];

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFFD;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | (bVar1 & 1) << 1;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000FFF0;

      puVar9 = puVar4 + 0x18;

    }

    else if (uVar5 == 8) {

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FDFD;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | DAT_060378f8;

      uVar8 = (unsigned short)param_2[1] << 8 & DAT_060378fa;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FEFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar8;

      *(short *)(puVar4 + 10) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) & uVar2;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) & uVar7;

      *(unsigned short *)(puVar4 + 10) = *(unsigned short *)(puVar4 + 10) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFF3;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 2;

      uVar6 = (unsigned short)param_2[4] << 10 & DAT_060378fc;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000F3FF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      uVar6 = (unsigned short)param_2[5] << 0xc & DAT_060378fe;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000CFFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      uVar6 = (unsigned short)param_2[6] << 9 & PTR_DAT_06037900;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FDFF;

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 | uVar6;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000FF0F;

      puVar9 = puVar4 + 0x1c;

    }

    else if (uVar5 == 0x10) {

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFFB;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 2;

      bVar1 = param_2[1];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFFE;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | bVar1 & 1;

      *(short *)(puVar4 + 0xc) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) & uVar2;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) & uVar7;

      *(unsigned short *)(puVar4 + 0xc) = *(unsigned short *)(puVar4 + 0xc) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FFCF;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 4;

      bVar1 = param_2[5];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFFD;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 1;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & (unsigned short)0x0000F0FF;

      puVar9 = puVar4 + 0x20;

    }

    else {

      if (uVar5 != 0x20) goto LAB_06037e88;

      bVar1 = *param_2;

      *(unsigned short *)(0x060A3D88 + 0x20) =

           *(unsigned short *)(0x060A3D88 + 0x20) & (unsigned short)0x0000FFF7;

      *(unsigned short *)(puVar12 + 0x20) = *(unsigned short *)(puVar12 + 0x20) | (bVar1 & 1) << 3;

      bVar1 = param_2[1];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFEF;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 4;

      *(short *)(puVar4 + 0xe) = *(short *)(param_2 + 10);

      bVar1 = param_2[2];

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) & uVar2;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) | (unsigned short)bVar1 << 0xf & uVar6;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) & uVar7;

      *(unsigned short *)(puVar4 + 0xe) = *(unsigned short *)(puVar4 + 0xe) | uVar11;

      bVar1 = param_2[3];

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) & (unsigned short)0x0000FF3F;

      *(unsigned short *)(puVar4 + 0x12) = *(unsigned short *)(puVar4 + 0x12) | (bVar1 & 3) << 6;

      bVar1 = param_2[5];

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & (unsigned short)0x0000FFDF;

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) | (bVar1 & 1) << 5;

      *(unsigned short *)(puVar4 + 0x14) = *(unsigned short *)(puVar4 + 0x14) & DAT_06037b10;

      puVar9 = puVar4 + 0x24;

    }

    param_1 = (unsigned short *)(puVar4 + 0x14);

    puVar12 = (void *)0x00000002;

  }

LAB_06037e88:

  if (param_2[6] == 1) {

    uVar6 = (*(int(*)())0x06035280)();

  }

  else {

    (*(int(*)())0x06035F44)();

    uVar6 = (*(int(*)())0x06035280)();

  }

  *param_1 = *param_1 | uVar6;

  uVar6 = 0;

  if (((unsigned int)puVar12 & 0xffff) != 0) {

    do {

      uVar7 = (*(int(*)())0x06035F44)();

      *extraout_r3 = uVar7 & 0x3f;

      uVar7 = (*(int(*)())0x06035F44)();

      *(unsigned short *)(puVar9 + (unsigned int)(uVar6 << 1)) =

           *(unsigned short *)(puVar9 + (unsigned int)(uVar6 << 1)) | (uVar7 & 0x3f) << 8 & uVar3;

      uVar6 = uVar6 + 1;

    } while ((unsigned int)uVar6 < ((unsigned int)puVar12 & 0xffff));

  }

  if (puStack_2c != (char *)0x0) {

    *param_1 = *param_1 & 0xf;

    *param_1 = *param_1 | *param_1 << 4;

    uVar5 = 0;

    if (((unsigned int)puVar12 & 0xffff) != 0) {

      do {

        puVar10 = (unsigned short *)(puStack_2c + ((uVar5 & 0xffff) << 1));

        uVar6 = (*(int(*)())0x06035F44)();

        *puVar10 = uVar6 & 0x3f;

        uVar6 = (*(int(*)())0x06035F44)();

        uVar5 = uVar5 + 1;

        *puVar10 = *puVar10 | (uVar6 & 0x3f) << 8 & uVar3;

      } while ((uVar5 & 0xffff) < ((unsigned int)puVar12 & 0xffff));

    }

  }

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return;

}

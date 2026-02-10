extern int DAT_060100f6;
extern int DAT_060100f8;
extern int DAT_060101b2;
extern int DAT_0601038c;
extern int DAT_0601038e;
extern int DAT_0601043e;
extern int DAT_0601064a;
extern int DAT_06010736;
extern int DAT_0601096e;
extern int DAT_06010a2a;
extern int DAT_06010c4c;
extern int DAT_06010c4e;
extern int DAT_0601112c;
extern int DAT_0601112e;
extern int DAT_06011206;
extern int DAT_06011208;
extern int DAT_0601120a;
extern int DAT_060112e2;
extern int DAT_060112e4;
extern int DAT_060112e6;
extern int DAT_060113b2;
extern int DAT_060113b4;
extern int DAT_060113b6;
extern int DAT_06011462;
extern int DAT_06011464;
extern int DAT_06011466;
extern int DAT_060115c6;
extern int DAT_06011fd4;
extern int DAT_06011fd6;
extern int DAT_06011fd8;
extern int DAT_06011fda;
extern void FUN_06010d94();
extern void FUN_060111e2();
extern void FUN_06011310();
extern void FUN_060116a8(int,int,short,int,short);
extern int FUN_06011978();
extern void FUN_06011e7c();
extern int PTR_DAT_06010274;
extern int PTR_DAT_06010278;
extern int PTR_DAT_0601030c;
extern int PTR_DAT_06010440;
extern int PTR_DAT_06010508;
extern int PTR_DAT_06010870;
extern int PTR_DAT_06010970;
extern int PTR_DAT_06010ac8;
extern int PTR_DAT_06010c50;
extern int PTR_DAT_06011130;
extern int PTR_DAT_0601120c;
extern int PTR_DAT_06011f04;
extern short DAT_06011efe;
extern short DAT_06011f00;
extern short DAT_06011f02;

int FUN_060100a4(param_1)
    unsigned char param_1;
{

  short sVar1;

  unsigned short uVar2;

  char *puVar3;

  int iVar4;

  char *puVar5;

  int iVar6;

  char *puVar7;

  int iVar8;

  puVar7 = (char *)0x00010000;

  sVar1 = (unsigned short)param_1 + DAT_060100f6;

  iVar6 = (int)DAT_060100f8;

  iVar4 = *(int *)(0x060447C8 + (unsigned int)(param_1 << 4));

  puVar5 = *(char **)((int)(0x060447C8 + (unsigned int)(param_1 << 4)) + 4);

  if ((unsigned int)param_1 == *(unsigned int *)0x0607EAD8) {

    puVar3 = 0x0605D0BC + (unsigned int)(param_1 << 5);

  }

  else {

    puVar3 = 0x0605D0BC + (param_1 + 3) << 5;

  }

  (*(int(*)())0x0602766C)(*(int *)(0x06078888 + (unsigned int)(param_1 << 2)),puVar3,0x20);

  if (4 < (unsigned char)*(int *)0x0607887F) {

    if ((unsigned int)param_1 == *(unsigned int *)0x0607EAD8) {

      if (*(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) < 0x1e) {

        uVar2 = *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) + 1;

        *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) = uVar2;

      }

      else {

        *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) = 0x20;

        uVar2 = 0x20;

      }

      iVar4 = iVar4 + *(int *)(0x060447F8 + (char)(param_1 * '\f')) * (unsigned int)uVar2;

      puVar5 = puVar5 + *(int *)((int)(0x060447F8 + (char)(param_1 * '\f')) + 4) * (unsigned int)uVar2

      ;

      iVar8 = (unsigned int)uVar2 * (int)DAT_060101b2;

    }

    else {

      if (0x1d < *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1))) {

        return (unsigned int)(param_1 << 1);

      }

      uVar2 = *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) + 1;

      *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) = uVar2;

      iVar8 = (unsigned int)uVar2 * 0x72b;

    }

    iVar6 = iVar6 + (unsigned int)uVar2 * -0x800;

    puVar7 = puVar7 + -iVar8;

  }

  if (0xb < (unsigned char)*(int *)0x0607887F) {

    puVar5 = (short *)0x00960000;

  }

  iVar4 = (*(int(*)())0x06011AF4)(iVar4,puVar5,

                     (*(unsigned int *)(0x06044844 + *(int *)(0x0605AA98 << 2)) >> 1) << 0x10,

                     0x00200000,iVar6,puVar7,(int)sVar1);

  return iVar4;

}

void FUN_06010238()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  puVar3 = (int *)0x0000FFFF;

  puVar2 = (char *)0x0607EADC;

  uVar1 = *(unsigned short *)0x06063D9C;

  *(int *)0x0607EADC = 0;

  uVar4 = ((unsigned int)uVar1 ^ (unsigned int)puVar3) & 0xff;

  if (0x72b < (int)uVar4) {

    *(int *)puVar2 = *(int *)puVar2 + 1;

  }

  if (0xc0 < (int)uVar4) {

    *(int *)puVar2 = *(int *)puVar2 + 1;

  }

  *(int *)0x0607887E = (char)*(int *)puVar2;

  *(int *)0x0607EAD8 = *(int *)puVar2;

  return;

}

void FUN_060102ea(param_1)
    unsigned short param_1;
{

  char *puVar1;

  char *puVar2;

  puVar1 = (char *)0x0607EBCC;

  *(int *)0x0607EBCC = *(int *)0x0607EBCC + -1;

  if ((param_1 & PTR_DAT_0601030c) == 0) {

    if ((*(int *)puVar1 < 1) || ((param_1 & DAT_0601038c) != 0)) {

      (*(int(*)())0x0601D5F4)(0,*(int *)(0x0604481C + *(int *)(0x0607EADC << 2)));

      *(int *)puVar1 = 0;

      *(int *)0x0607887F = 2;

      *(int *)0x06078648 = (char)*(int *)0x0607EAD8;

      puVar2 = (char *)0x0605AB18;

      *(int *)0x0605AB18 = 0;

      if ((*(int *)0x06085FF4 == '\0') &&

         ((*(int *)0x0605AD00 == 0 && ((*(unsigned short *)0x06063D98 & DAT_0601038e) != 0)))) {

        *puVar2 = 1;

      }

    }

  }

  else {

    *(int *)0x0605AD10 = 6;

  }

  return;

}

void FUN_060103b8(param_1)
    unsigned int param_1;
{

  char *puVar1;

  char *puVar2;

  int *puVar3;

  int iVar4;

  puVar1 = (char *)0x0607EADC;

  if (((param_1 & 0xffff & (unsigned int)0x00008000) != 0) && (*(int *)0x0607EADC < 1)) {

    *(int *)0x0607EADC = *(int *)0x0607EADC + 1;

  }

  if (((param_1 & 0xffff & (int)DAT_0601043e) != 0) && (0 < *(int *)0x0607EADC)) {

    *(int *)puVar1 = *(int *)puVar1 + -1;

  }

  puVar2 = (char *)0x0607EAB8;

  *(int *)0x0607EAB8 = *(int *)puVar1;

  *(int *)0x06078868 = *(int *)puVar1;

  puVar1 = (char *)0x0602766C;

  iVar4 = 0xc0;

  if (*(int *)puVar2 == 0) {

    (*(int(*)())0x0602766C)(*(int *)0x06078884,*(int *)0x0605D05C,iVar4);

    puVar3 = (int *)0x0605D088;

  }

  else {

    (*(int(*)())0x0602766C)(*(int *)0x06078884,*(int *)0x0605D084,iVar4);

    puVar3 = (int *)0x0605D060;

  }

  (*(int(*)())puVar1)(*(int *)0x06078880,*puVar3,iVar4);

  return;

}

void FUN_06010470()
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  int *puVar4;

  int iVar5;

  puVar1 = (char *)0x0607EADC;

  iVar5 = 0xc0;

  uVar3 = (unsigned int)*(unsigned short *)0x06063D9C ^ (unsigned int)0x0000FFFF;

  *(int *)0x0607EADC = 0;

  if (iVar5 < (int)(uVar3 & 0xff)) {

    *(int *)puVar1 = *(int *)puVar1 + 1;

  }

  puVar2 = (char *)0x0607EAB8;

  *(int *)0x0607EAB8 = *(int *)puVar1;

  *(int *)0x06078868 = *(int *)puVar1;

  puVar1 = (char *)0x0602766C;

  if (*(int *)puVar2 == 0) {

    (*(int(*)())0x0602766C)(*(int *)0x06078884,*(int *)0x0605D05C,iVar5);

    puVar4 = (int *)0x0605D088;

  }

  else {

    (*(int(*)())0x0602766C)(*(int *)0x06078884,*(int *)0x0605D084,iVar5);

    puVar4 = (int *)0x0605D060;

  }

  (*(int(*)())puVar1)(*(int *)0x06078880,*puVar4,iVar5);

  return;

}

unsigned int FUN_060104e0(param_1)
    unsigned int param_1;
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  int iVar7;

  unsigned int uVar8;

  int iVar9;

  int *puVar10;

  int uVar11;

  puVar5 = (short *)0x060788A8;

  puVar4 = (char *)0x06078868;

  puVar3 = (int *)0x0607EAB8;

  puVar2 = (char *)0x0607EADC;

  cVar1 = *(int *)0x0605AB16;

  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {

LAB_06010504:

    iVar9 = 5;

  }

  else {

    if (cVar1 != '\x03') {

      if (cVar1 == '\x04') goto LAB_06010504;

      if ((cVar1 != '\x05') && (cVar1 != '\x06')) {

        if (cVar1 == '\a') {

          iVar9 = 9;

        }

        else {

          iVar9 = 3;

        }

        goto LAB_06010570;

      }

    }

    iVar9 = 7;

  }

LAB_06010570:

  if (*(int *)0x0605AB17 == '\a') {

    iVar9 = 0xb;

  }

  uVar6 = (unsigned int)(char)*(int *)0x0605AB17;

  if (uVar6 == 0xf) {

    iVar9 = 0xd;

  }

  if ((param_1 & 0xffff & (unsigned int)0x00008000) == 0) {

    if ((param_1 & 0xffff & (int)DAT_0601064a) != 0) {

      *(char **)0x0607889C = 0x00010000;

      iVar7 = *(int *)puVar2;

      *(int *)puVar2 = iVar7 + -1;

      if (iVar7 + -1 < 0) {

        *(int *)puVar2 = iVar9;

      }

      uVar11 = 0xFFF40000;

      uVar6 = (unsigned int)(unsigned char)*puVar5;

      if (uVar6 == 0) {

        *puVar5 = 1;

        *(int *)0x06078898 = uVar11;

        *(int *)0x060788A4 = *(int *)puVar2;

      }

      else {

        *puVar5 = 0;

        *(int *)0x06078894 = uVar11;

        *(int *)0x060788A0 = *(int *)puVar2;

      }

    }

  }

  else {

    *(int *)0x0607889C = 0xFFFF0000;

    iVar7 = *(int *)puVar2;

    *(int *)puVar2 = iVar7 + 1;

    if (iVar9 < iVar7 + 1) {

      *(int *)puVar2 = 0;

    }

    if (*puVar5 == '\0') {

      *puVar5 = 1;

      (*(int(*)())0x060359E4)();

      uVar6 = (*(int(*)())0x060357B8)();

      *(unsigned int *)0x06078898 = uVar6;

      *(int *)0x060788A4 = *(int *)puVar2;

    }

    else {

      *puVar5 = 0;

      (*(int(*)())0x060359E4)();

      uVar6 = (*(int(*)())0x060357B8)();

      *(unsigned int *)0x06078894 = uVar6;

      *(int *)0x060788A0 = *(int *)puVar2;

    }

  }

  uVar8 = *(unsigned int *)puVar2;

  *(unsigned int *)puVar4 = uVar8;

  *(unsigned int *)puVar3 = uVar8 & 1;

  if (*(unsigned int *)puVar4 < 10) {

    if (*puVar5 == '\0') {

      uVar11 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      puVar10 = (int *)0x06078884;

    }

    else {

      uVar11 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      puVar10 = (int *)0x06078880;

    }

    uVar6 = (*(int(*)())0x0602766C)(*puVar10,uVar11,0xc0);

  }

  if ((param_1 & 0xffff & (unsigned int)0x0000C000) != 0) {

    if (*(unsigned int *)puVar4 < 0xc) {

      iVar9 = *(int *)puVar4;

    }

    else {

      iVar9 = *(int *)puVar4 + -2;

    }

    uVar6 = (*(int(*)())0x0602761E)(0x25F00000 + (*(int *)((int)(int)puVar3 << 1) + 0x23) << 5,

                       0x0605CA9C + (iVar9 << 6),0x40);

    return uVar6;

  }

  return uVar6;

}

unsigned int FUN_06010760()
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  unsigned int uVar9;

  int iVar10;

  int iVar11;

  int uVar12;

  puVar5 = (short *)0x0607EADC;

  puVar4 = (char *)0x06078868;

  puVar3 = (int *)0x060788A8;

  puVar2 = (char *)0x0602761E;

  cVar1 = *(int *)0x0605AB16;

  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {

LAB_06010782:

    iVar11 = 5;

  }

  else {

    if (cVar1 != '\x03') {

      if (cVar1 == '\x04') goto LAB_06010782;

      if ((cVar1 != '\x05') && (cVar1 != '\x06')) {

        if (cVar1 == '\a') {

          iVar11 = 9;

        }

        else {

          iVar11 = 3;

        }

        goto LAB_060107c8;

      }

    }

    iVar11 = 7;

  }

LAB_060107c8:

  if (*(int *)0x0605AB17 == '\a') {

    iVar11 = 0xb;

  }

  if (*(int *)0x0605AB17 == '\x0f') {

    iVar11 = 0xd;

  }

  uVar7 = ((unsigned int)*(unsigned short *)0x06063D9C ^ (unsigned int)0x0000FFFF) & 0xff;

  uVar8 = uVar7;

  if (0x90 < (int)uVar7) {

    *(int *)0x0607889C = 0xFFFF0000;

    *(int *)0x0605AA9C = 0x1e;

    iVar10 = *(int *)puVar5;

    *(int *)puVar5 = iVar10 + 1;

    if (iVar11 < iVar10 + 1) {

      *(int *)puVar5 = 0;

    }

    puVar6 = (char *)0x000C0000;

    uVar8 = (unsigned int)(unsigned char)*puVar3;

    if (uVar8 == 0) {

      *puVar3 = 1;

      *(char **)0x06078898 = puVar6;

      *(int *)0x060788A4 = *(int *)puVar5;

    }

    else {

      *puVar3 = 0;

      *(char **)0x06078894 = puVar6;

      *(int *)0x060788A0 = *(int *)puVar5;

    }

  }

  if (uVar7 < 0x70) {

    *(char **)0x0607889C = 0x00010000;

    *(int *)0x0605AA9C = 0x1e;

    iVar10 = *(int *)puVar5;

    *(int *)puVar5 = iVar10 + -1;

    if (iVar10 + -1 < 0) {

      *(int *)puVar5 = iVar11;

    }

    uVar12 = 0xFFF40000;

    uVar8 = (unsigned int)(unsigned char)*puVar3;

    if (uVar8 == 0) {

      *puVar3 = 1;

      *(int *)0x06078898 = uVar12;

      *(int *)0x060788A4 = *(int *)puVar5;

    }

    else {

      *puVar3 = 0;

      *(int *)0x06078894 = uVar12;

      *(int *)0x060788A0 = *(int *)puVar5;

    }

  }

  uVar9 = *(unsigned int *)puVar5;

  *(unsigned int *)puVar4 = uVar9;

  *(unsigned int *)0x0607EAB8 = uVar9 & 1;

  if (*(unsigned int *)puVar4 < 10) {

    if (*puVar3 == '\0') {

      uVar12 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      iVar11 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + 0x40;

    }

    else {

      uVar12 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      iVar11 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + DAT_0601096e + 0x40;

    }

    uVar8 = (*(int(*)())puVar2)(iVar11,uVar12,0xc0);

  }

  if ((uVar7 < 0x70) || (0x90 < (int)uVar7)) {

    if (*(unsigned int *)puVar4 < 0xc) {

      iVar11 = *(int *)puVar4;

    }

    else {

      iVar11 = *(int *)puVar4 + -2;

    }

    uVar8 = (*(int(*)())puVar2)(0x25F00000 + (*(int *)(0x0607EAB8 << 1) + 0x23) << 5,

                              0x0605CA9C + (iVar11 << 6),0x40);

  }

  return uVar8;

}

void FUN_06010994()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  puVar3 = (int *)0x0602761E;

  puVar2 = (char *)0x06063F5C;

  puVar1 = (char *)0x06059FFC;

  if (*(int *)0x06083255 == '\0') {

    iVar6 = 0xc0;

    uVar5 = *(int *)(0x0605D05C + *(int *)(0x06078868 << 2));

    iVar4 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + 0x40;

  }

  else {

    iVar6 = 0x20;

    uVar5 = *(int *)(0x0605D0AC + *(int *)(0x0607EAB8 << 2));

    iVar4 = ((unsigned int)(unsigned char)((int *)0x060448B5)[*(int *)0x0607EAD8] +

            (unsigned int)*(unsigned short *)0x0607886C) << 5 + *(int *)(0x06059FFC << 3) +

            *(int *)0x06063F5C;

  }

  (*(int(*)())0x0602761E)(iVar4,uVar5,iVar6);

  (*(int(*)())puVar3)(*(int *)((int)(int)puVar1 << 3) + *(int *)puVar2 + DAT_06010a2a + 0x40,

                    *(int *)(0x0605D05C + (unsigned int)(unsigned char)*(int *)(0x0607ED91 << 2)));

  return;

}

void FUN_06010a5c(param_1)
    int param_1;
{

  (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + PTR_DAT_06010ac8 + 0x40

             ,*(int *)(0x0605D05C + (param_1 << 2)));

  return;

}

int FUN_06010b54()
{

  int uVar1;

  if (*(int *)0x0607EAE0 == 0) {

    uVar1 = (*(int(*)())0x0601D5F4)(0,*(int *)(0x0604483C + *(int *)(0x0607EAB8 << 2)));

  }

  else {

    uVar1 = 0xAB110BFF;

    if (*(int *)0x06078644 == 1) {

      uVar1 = 0xAB110AFF;

    }

    uVar1 = (*(int(*)())0x0601D5F4)(0,uVar1);

  }

  return uVar1;

}

int FUN_06010bc4()
{

  unsigned short uVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int uVar7;

  unsigned char *pbVar8;

  puVar6 = (char *)0x06078878;

  puVar5 = (short *)0x0608A52C;

  puVar4 = (char *)0x06078898;

  puVar3 = (int *)0x06078894;

  sVar2 = PTR_DAT_06010c50;

  uVar1 = DAT_06010c4e;

  pbVar8 = (unsigned char *)-495;

  if (*(int *)0x06085FF4 == '\0') {

    *(int *)0x060788A0 = 1;

    *(short *)puVar6 = *(short *)puVar6 + sVar2;

    FUN_06011310();

    puVar3 = (int *)0x060270D0;

    *(int *)puVar5 = *(int *)puVar5 + 0x30;

    (*(int(*)())puVar3)();

    *(int *)0x0607884C = 1;

    *(char **)0x06078850 = 0x00038000;

    *(int *)0x06078854 = 0xFFFF0000;

    *(char **)0x06078858 = 0x0006B333;

    *(char **)0x06063574 = 0x06010F04;

    *(short *)0x21000000 = (short)0x0000FFFF;

    FUN_06010d94(0,0xFFFC8000,0xFFFF0000,0x0006B333);

    puVar3 = (int *)0x0603C000;

    do {

    } while ((*pbVar8 & uVar1) != uVar1);

    *pbVar8 = *pbVar8 & 0xf;

    uVar7 = (*(int(*)())puVar3)();

  }

  else {

    *(short *)0x06078878 = *(short *)0x06078878 + PTR_DAT_06010c50;

    puVar6 = (char *)0x0607889C;

    *(int *)puVar3 = *(int *)puVar3 + *(int *)0x0607889C;

    *(int *)puVar4 = *(int *)puVar4 + *(int *)puVar6;

    if (*(int *)puVar6 < 0) {

      if (*(int *)0x060788A8 == '\0') {

        if (*(int *)puVar3 < 1) {

          *(int *)puVar3 = 0;

          *(int *)puVar6 = 0;

        }

      }

      else if ((*(int *)0x060788A8 == '\x01') && (*(int *)puVar4 < 1)) {

        *(int *)puVar4 = 0;

        *(int *)puVar6 = 0;

      }

    }

    else if (*(int *)0x060788A8 == '\0') {

      if (-1 < *(int *)puVar3) {

        *(int *)puVar3 = 0;

        *(int *)puVar6 = 0;

      }

    }

    else if ((*(int *)0x060788A8 == '\x01') && (-1 < *(int *)puVar4)) {

      *(int *)puVar4 = 0;

      *(int *)puVar6 = 0;

    }

    FUN_060111e2();

    puVar6 = (char *)0x060270D0;

    *(int *)puVar5 = *(int *)puVar5 + 0x30;

    (*(int(*)())puVar6)();

    *(int *)0x0607884C = 1;

    *(int *)0x06078850 = *(int *)puVar4;

    *(int *)0x06078854 = 0xFFFF3334;

    *(char **)0x06078858 = 0x00063333;

    *(char **)0x06063574 = 0x06010F04;

    *(short *)0x21000000 = (short)0x0000FFFF;

    FUN_06010d94(0,*(int *)puVar3,0xFFFF3334,0x00063333);

    puVar3 = (int *)0x0603C000;

    do {

    } while ((*pbVar8 & uVar1) != uVar1);

    *pbVar8 = *pbVar8 & 0xf;

    uVar7 = (*(int(*)())puVar3)();

  }

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  return uVar7;

}

void FUN_06010d94(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  short *psVar8;

  puVar2 = (char *)0x06026E0C;

  puVar1 = (char *)0x06089EDC;

  if (*(unsigned int *)0x060788A0 < 10) {

    *(int *)0x06089EDC = *(int *)0x06089EDC + 0x30;

    (*(int(*)())puVar2)();

    puVar2 = (char *)0x06026E2E;

    (*(int(*)())0x06026E2E)(param_2,param_3,param_4);

    (*(int(*)())0x06026EDE)((int)*(short *)0x06078878);

    puVar3 = (int *)0x0606212C;

    (*(int(*)())0x06031D8C)(*(int *)0x0606212C,*(int *)0x060621D8);

    puVar6 = (char *)0x06062180;

    puVar5 = (short *)0x06031A28;

    puVar4 = (char *)0x060620D8;

    psVar8 = (short *)(0x06089E44 + (param_1 << 1));

    (*(int(*)())0x06031A28)(*(int *)0x060620D8,(int)*psVar8,*(int *)0x06062180);

    (*(int(*)())0x06026DBC)();

    (*(int(*)())puVar2)(*(int *)0x06044640,*(int *)0x06044644,

                      -*(int *)0x06044648);

    (*(int(*)())0x06031D8C)(*(int *)(puVar3 + 4),*(int *)0x060621DC);

    (*(int(*)())puVar5)(*(int *)(puVar4 + 4),(int)*psVar8,*(int *)(puVar6 + 4));

    puVar7 = (char *)0x06026DBC;

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

    (*(int(*)())puVar7)();

    (*(int(*)())puVar2)(*(int *)0x0604464C,*(int *)0x06044650,

                      -*(int *)0x06044654);

    (*(int(*)())0x06031D8C)(*(int *)(puVar3 + 8),*(int *)0x060621E0);

    (*(int(*)())puVar5)(*(int *)(puVar4 + 8),(int)*psVar8,*(int *)(puVar6 + 8));

    puVar7 = (char *)0x06026DBC;

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

    (*(int(*)())puVar7)();

    (*(int(*)())puVar2)(*(int *)0x06044670,*(int *)0x06044674,

                      -*(int *)0x06044678);

    (*(int(*)())0x06031D8C)(*(int *)(puVar3 + 0xc),*(int *)0x060621E4);

    (*(int(*)())puVar5)(*(int *)(puVar4 + 0xc),(int)*psVar8,*(int *)(puVar6 + 0xc));

    *(int *)puVar1 = *(int *)puVar1 + -0x60;

  }

  return;

}

void FUN_06011094()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int local_30;

  int iStack_2c;

  int iStack_28;

  puVar3 = (int *)0x0605AC70;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x0607EADC;

  if (*(int *)0x0607887F == '\x03') {

    if ((*(unsigned int *)0x0607EBC8 & 1) == 0) {

      iStack_28 = 4;

    }

    else {

      iStack_28 = 3;

    }

  }

  else if ((*(unsigned int *)0x0607EBC8 & 3) < 2) {

    iStack_28 = 3;

  }

  else {

    iStack_28 = 4;

  }

  iVar8 = *(int *)(0x06063750 + DAT_0601112c);

  iVar7 = *(int *)(0x06063750 + DAT_0601112c + 0x10);

  local_30 = iStack_28;

  if (*(int *)0x0607EADC != 0) {

    local_30 = 3;

  }

  (*(int(*)())0x06028400)(4,*(int *)(0x0605AC70 + *(int *)(0x06078644 << 2)),0x282,

             (local_30 << 12) + iVar8);

  puVar5 = (short *)0x0605AB98;

  puVar4 = (char *)0x0605AD00;

  (*(int(*)())puVar2)(8,*(int *)(0x0605AB98 + *(int *)(0x0605AD00 << 2)),

                    (int)PTR_DAT_06011130,(local_30 << 12) + iVar7);

  iStack_2c = iStack_28;

  if (*(int *)puVar1 != 1) {

    iStack_2c = 3;

  }

  iVar6 = (iStack_2c + 2) << 12;

  (*(int(*)())puVar2)(4,*(int *)(puVar3 + *(int *)(0x06078644 << 2) + 0xc),(int)DAT_06011206

                    ,iVar6 + iVar8);

  (*(int(*)())puVar2)(8,*(int *)(puVar5 + *(int *)((int)(int)puVar4 << 2) + 0xc),0x4a8,

                    iVar6 + iVar7);

  if (*(int *)puVar1 != 2) {

    iStack_28 = 3;

  }

  iVar6 = (iStack_28 + 4) << 12;

  (*(int(*)())puVar2)(4,*(int *)(puVar3 + *(int *)(0x06078644 << 2) + 0x18),

                    0x2ba,iVar6 + iVar8);

  (*(int(*)())puVar2)(8,*(int *)(puVar5 + *(int *)((int)(int)puVar4 << 2) + 0x18),

                    (int)PTR_DAT_0601120c,iVar6 + iVar7);

  return;

}

void FUN_060111e2()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  puVar3 = (int *)0x06063828;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06078644;

  iVar5 = 3;

  if ((*(int *)0x0607887F == '\v') && ((*(unsigned int *)0x0607EBC8 & 1) == 0)) {

    iVar5 = 4;

  }

  if (*(int *)0x0607EAB8 == 0) {

    iVar5 = (iVar5 << 12);

    (*(int(*)())0x06028400)(4,0x0605A7FC,0x2a0,*(int *)(0x06063828 + 4) + iVar5);

    (*(int(*)())puVar2)(4,*(int *)

                         (0x0605ABBC +

                         (unsigned int)(*(int *)puVar1 != 0) << 2 + *(int *)(0x06078868 << 3)),

                      0x530,*(int *)(puVar3 + 4) + iVar5);

    iVar4 = (int)DAT_060112e6;

    iVar5 = *(int *)(puVar3 + 4) + iVar5;

    puVar3 = (int *)0x0605A9B8;

    if (*(int *)puVar1 != 0) {

      puVar3 = (int *)0x0605A9B0;

    }

  }

  else {

    iVar5 = (iVar5 + 2) << 12;

    (*(int(*)())0x06028400)(4,0x0605A8B6,0x2a0,*(int *)(0x06063828 + 4) + iVar5);

    (*(int(*)())puVar2)(4,*(int *)

                         (0x0605ABBC +

                         (unsigned int)(*(int *)puVar1 != 0) << 2 + *(int *)(0x06078868 << 3)),

                      0x530,*(int *)(puVar3 + 4) + iVar5);

    iVar4 = (int)DAT_060112e6;

    iVar5 = *(int *)(puVar3 + 4) + iVar5;

    puVar3 = (int *)0x0605A9B8;

    if (*(int *)puVar1 != 0) {

      puVar3 = (int *)0x0605A9B0;

    }

  }

  (*(int(*)())puVar2)(4,puVar3,iVar4,iVar5);

  return;

}

void FUN_06011310()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int local_20;

  puVar2 = (char *)0x06063828;

  puVar1 = (char *)0x06028400;

  if (*(int *)0x0607887F == '\v') {

    if ((*(unsigned int *)0x0607EBC8 & 1) == 0) {

      iVar5 = 4;

    }

    else {

      iVar5 = 3;

    }

  }

  else if ((*(unsigned int *)0x0607EBC8 & 3) < 2) {

    iVar5 = 3;

  }

  else {

    iVar5 = 4;

  }

  local_20 = iVar5;

  if (*(int *)0x0607EADC != 0) {

    local_20 = 3;

  }

  local_20 = (local_20 << 12);

  (*(int(*)())0x06028400)(4,0x0605A7FC,0x288,*(int *)(0x06063828 + 4) + local_20);

  puVar3 = (int *)0x06078644;

  puVar4 = (char *)0x0605A9B8;

  if (*(int *)0x06078644 != 0) {

    puVar4 = (char *)0x0605A9B0;

  }

  (*(int(*)())puVar1)(4,puVar4,(int)DAT_060113b4,*(int *)(puVar2 + 4) + local_20);

  puVar4 = (char *)0x0605A978;

  if (*(int *)puVar3 != 0) {

    puVar4 = (char *)0x0605A998;

  }

  (*(int(*)())puVar1)(4,puVar4,0x518,*(int *)(puVar2 + 4) + local_20);

  local_20 = iVar5;

  if (*(int *)0x0607EADC != 1) {

    local_20 = 3;

  }

  iVar5 = (local_20 + 2) << 12;

  (*(int(*)())puVar1)(4,0x0605A8B6,(int)DAT_06011462,*(int *)(puVar2 + 4) + iVar5);

  puVar4 = (char *)0x0605A9B8;

  if (*(int *)puVar3 != 0) {

    puVar4 = (char *)0x0605A9B0;

  }

  (*(int(*)())puVar1)(4,puVar4,0x54a,*(int *)(puVar2 + 4) + iVar5);

  puVar4 = (char *)0x0605A980;

  if (*(int *)puVar3 != 0) {

    puVar4 = (char *)0x0605A9A0;

  }

  (*(int(*)())puVar1)(4,puVar4,(int)DAT_06011466,*(int *)(puVar2 + 4) + iVar5);

  return;

}

unsigned int FUN_060114ac(param_1)
    unsigned int param_1;
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  int *puVar4;

  short *psVar5;

  puVar1 = (char *)0x06078860;

  iVar3 = *(int *)(0x060447A8 + *(int *)(0x0607EADC << 2) + (param_1 & 0xffff) << 4) -

          *(int *)0x06078860;

  *(int *)0x06078860 = *(int *)0x06078860 + ((int)(iVar3 + (unsigned int)(iVar3 < 0)) >> 1);

  if (((*(int *)0x0607887F == '\x03') || (*(int *)0x0607887F == '\v')) &&

     ((*(unsigned int *)0x0607EBC8 & 1) != 0)) {

    return *(unsigned int *)0x0607EBC8;

  }

  psVar5 = (short *)(0x060447A4 + (param_1 & 0xffff) << 1);

  puVar4 = (int *)(0x060447A8 + (param_1 & 0xffff) << 4 + 0xc);

  FUN_060116a8(*(int *)puVar1,*puVar4,(int)DAT_060115c6,0x00010000,(int)*psVar5);

  FUN_06011978(0x06044764,*(int *)puVar1,*puVar4,(int)*psVar5);

  uVar2 = FUN_06011978(0x06044784,*(int *)puVar1,*puVar4,(int)*psVar5);

  return uVar2;

}

void FUN_0601155e(param_1)
    unsigned short param_1;
{

  char *puVar1;

  unsigned short uVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  short *puVar5;

  int iVar6;

  puVar1 = (char *)0x0605AAA6;

  uVar2 = 0;

  iVar6 = *(int *)0x06063788;

  do {

    uVar3 = (unsigned int)uVar2;

    uVar4 = (unsigned int)uVar2;

    uVar2 = uVar2 + 1;

    puVar5 = (short *)(uVar4 * 0x58 + (unsigned int)(param_1 << 1) + iVar6 + 4);

    *(short *)(puVar1 + (uVar3 << 2)) = *puVar5;

    *(short *)((int)(puVar1 + (uVar3 << 2)) + 2) = puVar5[1];

  } while (uVar2 < 0x1c);

  (*(int(*)())0x06028400)(8,0x0605AAA2,(param_1 & 0x3f) << 1,

             0x0000F000 + *(int *)(0x06063788 + 4));

  return;

}

void FUN_060116a8(int param_1,int param_2,short param_3,int param_4,short param_5)
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  int uVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  short *psVar11;

  int uStack_2c;

  int uStack_28;

  short sStack_24;

  sStack_24 = param_3;

  (*(int(*)())0x06027358)((int)param_3,&uStack_2c,&uStack_28);

  puVar4 = (char *)0x06027552;

  puVar3 = (char *)0x0602754C;

  puVar2 = (char *)0x0605AAA0;

  puVar1 = (char *)0x060786CC;

  psVar11 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  iVar5 = (*(int(*)())0x06027552)(0xFFC80000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar8 = (*(int(*)())puVar3)(uVar7);

  sVar9 = (*(int(*)())puVar3)(param_1);

  *psVar11 = sVar9 + sVar8;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xc) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xe) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x12) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x14) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x16) = sVar10 + sVar9;

  *(short *)(puVar1 + (short)(*(short *)puVar2 * 0x18) + 6) = param_5;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 4] = 0;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 5] = 1;

  *(short *)puVar2 = *(short *)puVar2 + 1;

  return;

}

int FUN_06011978(param_1, param_2, param_3, param_4)
    int *param_1;
    int param_2;
    int param_3;
    short param_4;
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  short uVar5;

  short *puVar6;

  puVar4 = (char *)0x0605AAA0;

  puVar3 = (int *)0x060786CC;

  puVar2 = (char *)0x0602754C;

  puVar6 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  uVar5 = (*(int(*)())0x0602754C)(*param_1 + param_2);

  *puVar6 = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[1] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 10) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[2] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0xc) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[3] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0xe) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[4] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x10) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[5] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x12) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[6] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x14) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[7] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x16) = uVar5;

  *(short *)(puVar3 + (short)(*(short *)puVar4 * 0x18) + 6) = param_4;

  puVar3[(short)(*(short *)puVar4 * 0x18) + 4] = 0;

  puVar3[(short)(*(short *)puVar4 * 0x18) + 5] = 1;

  *(short *)puVar4 = *(short *)puVar4 + 1;

  return 0;

}

void FUN_06011af4(int param_1,int param_2,int param_3,int param_4,short param_5,short param_6,short param_7)
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  int uVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  short *psVar11;

  int uStack_38;

  int uStack_34;

  int uStack_30;

  int uStack_2c;

  int iStack_28;

  int iStack_24;

  uStack_30 = param_2;

  uStack_2c = param_1;

  (*(int(*)())0x06027358)((int)param_5,&uStack_38,&uStack_34);

  puVar4 = (char *)0x06027552;

  puVar3 = (int *)0x0602754C;

  puVar2 = (char *)0x0605AAA0;

  puVar1 = (char *)0x060786CC;

  iStack_24 = -param_3;

  psVar11 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  iVar5 = (*(int(*)())0x06027552)(iStack_24,uStack_34);

  iVar6 = (*(int(*)())puVar4)(param_4,uStack_38);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_6);

  sVar8 = (*(int(*)())puVar3)(uVar7);

  sVar9 = (*(int(*)())puVar3)(uStack_2c);

  *psVar11 = sVar9 - sVar8;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(iStack_24,uStack_38);

  iVar6 = (*(int(*)())puVar4)(param_4,uStack_34);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(param_3,uStack_34);

  iVar6 = (*(int(*)())puVar4)(param_4,uStack_38);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xc) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(param_3,uStack_38);

  iVar6 = (*(int(*)())puVar4)(param_4,uStack_34);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xe) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(param_3,uStack_34);

  iStack_28 = -param_4;

  iVar6 = (*(int(*)())puVar4)(iStack_28,uStack_38);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x10) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(param_3,uStack_38);

  iVar6 = (*(int(*)())puVar4)(iStack_28,uStack_34);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x12) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(iStack_24,uStack_34);

  iVar6 = (*(int(*)())puVar4)(iStack_28,uStack_38);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x14) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(iStack_24,uStack_38);

  iVar6 = (*(int(*)())puVar4)(iStack_28,uStack_34);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x16) = sVar10 + sVar9;

  *(short *)(puVar1 + (short)(*(short *)puVar2 * 0x18) + 6) = param_7;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 4] = 0;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 5] = 0;

  *(short *)puVar2 = *(short *)puVar2 + 1;

  return;

}

void FUN_06011dc0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar5;

  puVar4 = (char *)0x060785FC;

  puVar3 = (int *)0x060786CC;

  puVar2 = (char *)0x0605A008;

  puVar1 = (char *)0x0605AAA0;

  for (uVar5 = 0; uVar5 < *(unsigned short *)puVar1; uVar5 = uVar5 + 1) {

    if (puVar3[(short)(uVar5 * 0x18) + 5] == '\0') {

      (*(int(*)())0x060280F8)(puVar3 + (short)(uVar5 * 0x18),*(int *)puVar4);

    }

    else {

      (*(int(*)())0x060280C4)(puVar3 + (short)(uVar5 * 0x18),*(int *)puVar4);

      (puVar3 + (short)(uVar5 * 0x18))[5] = 0;

    }

    *(int *)puVar2 = *(int *)puVar2 + 1;

    *(int *)puVar4 = *(int *)puVar4 + 0x20;

  }

  *(short *)puVar1 = 0;

  return;

}

void FUN_06011e7c()
{
  register int func asm("r3") = 0x06028400;
  register int off asm("r2");

  off = (int)DAT_06011efe;

  (*(int(*)())func)(0xc,*(int *)0x060638B0,(int)DAT_06011f00,
                   *(int *)0x060638B4 + off);

  (*(int(*)())func)(0xc,*(int *)0x060638A0,(int)DAT_06011f02,
                   *(int *)0x060638A4 + off);
}

void FUN_06011eb4()
{

  if (*(int *)0x06085FF4 != '\0') {

    FUN_06011e7c();

    return;

  }

  if (*(int *)0x0607EADC != 0) {

    (*(int(*)())0x06028400)(0xc,*(int *)0x060638B0,0x420,

               *(int *)(0x060638B0 + 4) + (int)DAT_06011efe);

    return;

  }

  (*(int(*)())0x06028400)(0xc,*(int *)0x060638A0,0x420,

             *(int *)(0x060638A0 + 4) + (int)DAT_06011efe);

  return;

}

void FUN_06011f1c(param_1)
    unsigned short *param_1;
{

  unsigned short uVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  short sVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uVar3 = DAT_06011fd6;

  uVar2 = DAT_06011fd4;

  iVar7 = -2048;

  sVar4 = 0;

  do {

    uVar1 = *param_1;

    *param_1 = 0;

    iVar5 = ((int)(short)uVar1 & 0x1fU) - 2;

    if (iVar5 < 1) {

      iVar5 = 0;

    }

    iVar6 = (short)(uVar1 & uVar2) + -0x40;

    *param_1 = *param_1 | (unsigned short)iVar5;

    if (iVar6 < 1) {

      iVar6 = 0;

    }

    *param_1 = *param_1 | (unsigned short)iVar6;

    iVar5 = (short)(uVar1 & uVar3) + iVar7;

    if (iVar5 < 1) {

      iVar5 = 0;

    }

    sVar4 = sVar4 + 1;

    *param_1 = *param_1 | (unsigned short)iVar5;

    param_1 = param_1 + 1;

  } while (sVar4 < 0x10);

  return;

}

void FUN_06011f92(param_1, param_2)
    unsigned short *param_1;
    unsigned short *param_2;
{

  unsigned short uVar1;

  unsigned short uVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  unsigned int uVar6;

  int iVar7;

  short sVar8;

  uVar2 = DAT_06011fd6;

  iVar7 = 0x400;

  uVar6 = iVar7 - 0x20;

  sVar8 = 0;

  do {

    uVar1 = *param_1;

    uVar5 = *param_2;

    *param_1 = 0;

    iVar3 = ((int)(short)uVar1 & 0x1fU) + 1;

    if (iVar3 < (short)uVar5) {

      uVar4 = (unsigned short)iVar3;

    }

    else {

      uVar4 = uVar5 & 0x1f;

    }

    *param_1 = *param_1 | uVar4;

    iVar3 = ((int)(short)uVar1 & uVar6) + 0x20;

    if ((((short)uVar5 <= iVar3 ^ 1) & uVar6) == 0) {

      uVar4 = uVar5 & (unsigned short)uVar6;

    }

    else {

      uVar4 = (unsigned short)iVar3;

    }

    iVar3 = (short)(uVar1 & uVar2) + iVar7;

    *param_1 = *param_1 | uVar4;

    if ((((short)uVar5 <= iVar3 ^ 1) & uVar2) == 0) {

      uVar5 = uVar5 & uVar2;

    }

    else {

      uVar5 = (unsigned short)iVar3;

    }

    sVar8 = sVar8 + 1;

    *param_1 = *param_1 | uVar5;

    param_1 = param_1 + 1;

    param_2 = param_2 + 1;

  } while (sVar8 < 0x10);

  return;

}

#include "game.h"

extern int DAT_06018212;
extern int DAT_06018214;
extern int DAT_06018216;
extern int DAT_06018218;
extern int DAT_0601821a;
extern int DAT_060182f2;
extern int DAT_060183ec;
extern int DAT_060183ee;
extern int DAT_060183f0;
extern int DAT_060183f2;
extern int DAT_06018504;
extern int DAT_06018506;
extern int DAT_060185a0;
extern int DAT_060185a2;
extern int DAT_06018660;
extern int DAT_06018662;
extern int DAT_06018b8e;
extern int DAT_06018cc6;
extern int DAT_060193c4;
extern int DAT_060193c6;
extern int DAT_060195ac;
extern int DAT_060195ae;
extern int DAT_06019694;
extern int DAT_06019696;
extern int DAT_06019762;
extern int DAT_06019864;
extern int DAT_06019b22;
extern int DAT_06019bfc;
extern void FUN_06018320();
extern void FUN_060185d8();
extern void FUN_060192e8();
extern void FUN_06019324();
extern void FUN_0601938c();
extern void FUN_06019928();
extern int FUN_06019bc8();
extern int FUN_06019db8();
extern int FUN_06019fb2();
extern int FUN_0601a65e();
extern int FUN_0601a80c();
extern int cd_register_double_read();
extern int FUN_06034DEA();
extern int PTR_DAT_060185a4;
extern int PTR_DAT_06018664;
extern int PTR_DAT_060195b0;
extern int PTR_DAT_06019764;
extern int PTR_DAT_06019a24;
extern int PTR_DAT_06019b24;
extern short PTR_DAT_060182f4;

void FUN_06018166()
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  puVar4 = (char *)0x060684EC;

  puVar3 = (char *)0x06063F64;

  puVar2 = (char *)0x0605BE2C;

  iVar8 = (int)DAT_06018212;

  iVar5 = CAR_PTR_TARGET;

  *(short *)0x0605BE2C = *(short *)0x0605BE2C + 1;

  bVar1 = *(unsigned int *)(iVar5 + DAT_06018214) < *(int *)0x06063F28 - 1U;

  if (bVar1) {

    uVar6 = *(int *)0x06089E28;

  }

  else {

    uVar6 = *(int *)0x06089E2C;

  }

  iVar5 = (int)DAT_06018216;

  if (*(short *)puVar2 < 6) {

    iVar7 = 0x90;

    *(int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar4 + iVar8) << 3)) =

         *(int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar4 + iVar8) << 3)) + iVar7;

    *(int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar4 + iVar5) << 3)) =

         *(int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar4 + iVar5) << 3)) + iVar7;

  }

  else {

    *(int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar4 + iVar8) << 3)) = uVar6;

    *(int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar4 + iVar5) << 3)) =

         *(int *)0x06089E30;

    *(short *)puVar2 = 0;

  }

  if (bVar1) {

    *(short *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar4 + iVar8) << 3) + 6) = DAT_060182f2;

  }

  else {

    *(short *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar4 + iVar8) << 3) + 6) = DAT_0601821a;

  }

  if ((GAME_STATE_BIT & (unsigned int)0x00800000) != 0) {

    FUN_060185d8();

    return;

  }

  FUN_06018320();

  return;

}

unsigned int track_calculation()
{
  unsigned int uVar3;
  unsigned short *puVar4;
  unsigned int uVar5;

  uVar3 = (unsigned int)*(unsigned short *)0x0605BE1C;
  uVar5 = (unsigned int)*(unsigned short *)0x06063D9A;

  if ((uVar3 == 0) && (uVar5 != 0)) {
    puVar4 = (unsigned short *)0x0605BE1E;

    uVar3 = (*(int(*)())0x06035280)();

    if ((uVar3 & uVar5) == 0) {
      *puVar4 = 0;
      uVar3 = 0;
    }
    else {
      *puVar4 = *puVar4 + 1;
      uVar3 = (unsigned int)*puVar4;

      if (uVar3 == 7) {
        int idx;
        *puVar4 = 0;
        *(short *)0x0605BE1C = 1;

        idx = (unsigned int)*(unsigned short *)0x06069BB6 << 3;
        *(int *)(0x06063F64 + idx) = *(int *)0x06089E3C;
        uVar3 = (unsigned int)PTR_DAT_060182f4;
        *(short *)(0x06063F64 + idx + 6) = PTR_DAT_060182f4;
      }
    }
  }

  return uVar3;
}

void FUN_06018320()
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  unsigned short uVar9;

  unsigned short uVar10;

  int iVar11;

  puVar8 = (char *)0x0605BE33;

  puVar7 = (char *)0x0605BE34;

  puVar6 = (char *)0x06085FC0;

  puVar5 = (char *)0x0605BE32;

  puVar4 = (char *)0x00008000;

  puVar3 = (char *)0x0607E940;

  puVar2 = (char *)0x0605BE35;

  *(int *)0x0605BE34 = *(int *)0x0605BE33;

  if (((int)DAT_060183ee <= *(int *)(*(int *)puVar3 + (int)DAT_060183ec)) &&

     (*(int *)(*(int *)puVar3 + (int)DAT_060183ec) <= (int)DAT_060183f0)) {

    *puVar8 = 1;

    uVar9 = *(unsigned short *)0x06063D98 & 0x40;

    uVar10 = (*(unsigned short *)0x0605BE30 ^ uVar9) & uVar9;

    *(unsigned short *)0x0605BE30 = uVar9;

    if (*(int *)0x0605DE3C == '\0') {

      if ((((*(unsigned char *)(*(int *)puVar3 + 3) & 8) == 0 & (*puVar8 ^ *puVar7)) != 0) &&

         ((*(unsigned int *)0x0605A010 & 0x3f) == 0)) {

        *puVar2 = 1;

      }

    }

    else {

      *puVar2 = 1;

    }

    puVar7 = (char *)0x00010000;

    if (*(int *)0x06085FF4 == '\0') {

      if ((*(int *)(*(int *)puVar3 + 8) == 0) && (uVar10 != 0)) {

        iVar11 = (int)DAT_060183f2;

        if (*puVar5 == '\0') {

          *(int *)puVar6 = 0;

          iVar11 = *(int *)(puVar6 + 4) + iVar11;

          *(int *)(puVar6 + 4) = iVar11;

          if ((int)puVar7 <= iVar11) {

            *(char **)puVar6 = puVar4;

            *(char **)(puVar6 + 4) = puVar4;

            *puVar5 = *puVar5 + '\x01';

          }

        }

        else if (*puVar5 == '\x01') {

          *(char **)puVar6 = puVar4;

          iVar11 = *(int *)(puVar6 + 4) + iVar11;

          *(int *)(puVar6 + 4) = iVar11;

          if ((int)0x00018000 <= iVar11) {

            *(int *)puVar6 = 0;

            *(int *)(puVar6 + 4) = 0;

            *puVar5 = *puVar5 + '\x01';

          }

        }

        else {

          *(int *)puVar6 = 0;

          *(int *)(puVar6 + 4) = 0;

        }

      }

    }

    else {

      cVar1 = *puVar5;

      if (cVar1 == '\0') {

        *(int *)puVar6 = 0;

        *(int *)(puVar6 + 4) = 0;

        if ((*(int *)(*(int *)puVar3 + 8) == 0) && (uVar10 != 0)) {

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else if (cVar1 == '\x01') {

        iVar11 = *(int *)(puVar6 + 4) + 0x100;

        *(int *)(puVar6 + 4) = iVar11;

        if ((int)puVar7 <= iVar11) {

          *(char **)(puVar6 + 4) = puVar7;

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else if (cVar1 == '\x02') {

        iVar11 = *(int *)puVar6 + 0x200;

        *(int *)puVar6 = iVar11;

        if ((int)puVar4 <= iVar11) {

          *(char **)puVar6 = puVar4;

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else if (cVar1 == '\x03') {

        iVar11 = *(int *)(puVar6 + 4) + 0x100;

        *(int *)(puVar6 + 4) = iVar11;

        if ((int)0x00020000 <= iVar11) {

          *(char **)(puVar6 + 4) = 0x00020000;

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else if (cVar1 == '\x04') {

        iVar11 = *(int *)puVar6 + 0x200;

        *(int *)puVar6 = iVar11;

        if ((int)puVar7 <= iVar11) {

          *(int *)puVar6 = 0;

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else {

        *(int *)puVar6 = 0;

        *(int *)(puVar6 + 4) = 0;

      }

    }

    if (*puVar2 != '\0') {

      *(char **)puVar6 = puVar4;

      *(char **)(puVar6 + 4) = puVar4;

    }

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)0x06048140,*(int *)(0x06048140 + 4),

               *(int *)(0x06048140 + 8));

    (*(int(*)())0x06026EDE)(*(int *)(puVar6 + 4) + (int)DAT_060185a0);

    (*(int(*)())0x06026E94)(*(int *)puVar6);

    puVar2 = (char *)0x00200000;

    (*(int(*)())0x06031D8C)(0x00200000 + (int)0x000BABE0,0x178);

    (*(int(*)())0x06031A28)(puVar2 + (int)0x000BBD80,(int)*(short *)0x06089E98,

               (int)PTR_DAT_060185a4);

    (*(int(*)())0x06026DF8)();

    return;

  }

  *(int *)puVar6 = 0;

  *(int *)(puVar6 + 4) = 0;

  *puVar8 = 0;

  *puVar2 = 0;

  *puVar5 = 0;

  return;

}

void FUN_060185d8()
{

  char *puVar1;

  if (*(int *)0x06083254 == '\x03') {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)0x06048140,*(int *)(0x06048140 + 4),

               *(int *)(0x06048140 + 8));

    (*(int(*)())0x06026EDE)((int)DAT_06018660);

    puVar1 = (char *)0x00200000;

    (*(int(*)())0x06031D8C)(0x00200000 + (int)0x000BABE0,0x178);

    (*(int(*)())0x06031A28)(puVar1 + (int)0x000BBD80,(int)*(short *)0x06089E98,

               (int)PTR_DAT_06018664);

    (*(int(*)())0x06026DF8)();

    return;

  }

  return;

}

int FUN_06018634()
{

  short *puVar1;

  char *puVar2;

  int iVar3;

  puVar2 = (char *)0x0605BE36;

  puVar1 = (char *)0x0605BE38;

  iVar3 = CAR_COUNT;

  if (iVar3 == 0) {

    *(short *)0x0605BE24 = 0;

    *(short *)0x0605BE22 = 0;

    *(short *)0x0605BE20 = 0;

    *(short *)0x0605BE2A = 0;

    *(short *)0x0605BE26 = 0;

    *(short *)0x0605BE28 = 0;

    *(short *)0x0605BE36 = 0;

    *(short *)0x0605BE38 = 0;

    return 0;

  }

  if (iVar3 == 1) {

    *(short *)0x0605BE1C = 0;

    *(short *)0x0605BE1E = 0;

    iVar3 = 0;

    *(short *)puVar2 = 0;

  }

  else {

    if (iVar3 != 2) {

      return iVar3;

    }

    *(short *)0x0605BE36 = 0;

    iVar3 = 2;

  }

  *puVar1 = 0;

  return iVar3;

}

void FUN_06018a3c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int uVar6;

  int local_30;

  char uStack_2c;

  char uStack_2b;

  int uStack_28;

  char uStack_24;

  char uStack_23;

  char uStack_20;

  puVar1 = (char *)0x0607EAD8;

  if (*(int *)0x06078868 < 10) {

    *(int *)0x0607867C = 0;

    *(int *)0x06083255 = 0;

  }

  else {

    if (*(int *)0x06078868 < 0xc) {

      *(int *)0x0607867C = 0;

    }

    else {

      *(int *)0x0607867C = 1;

    }

    *(int *)0x06083255 = 1;

  }

  if (*(int *)0x0605AD08 == 0) {

    (*(int(*)())0x0600736C)();

    (*(int(*)())0x06012DB4)(*(int *)puVar1);

    (*(int(*)())(*(int *)(0x0605D1BC + *(int *)((int)(int)puVar1 << 2))))();

    (*(int(*)())0x06012D7C)(*(int *)puVar1);

    if (*(int *)0x06078635 == '\0') {

      (*(int(*)())0x06012E7C)();

    }

    if (*(short *)0x0607ED8C == 0) {

      (*(int(*)())0x06018FF8)();

    }

  }

  if (*(short *)0x0607ED8C != 0) {

    (*(int(*)())0x06018FF8)();

  }

  if ((GAME_STATE_BIT & (int)DAT_06018b8e) == 0) {

    uVar6 = 0;

    iVar5 = 3;

  }

  else {

    if (*(int *)0x0605AB18 == '\0') {

      if (COURSE_SELECT == 2) {

        (*(int(*)())0x06018E1E)((unsigned char)*(int *)0x06078648 + 6);

        local_30 = 2;

        uStack_2c = 6;

        uStack_2b = 1;

        uStack_28 = 2;

        uStack_24 = 9;

        uStack_23 = 99;

        uStack_20 = 0x8f;

        (*(int(*)())0x06034D1C)(&local_30);

      }

      else {

        (*(int(*)())0x06018DDC)((unsigned char)*(int *)0x06078648 + 6,(unsigned char)*(int *)0x06078648 + 6,0xf);

      }

      goto LAB_06018bd8;

    }

    uVar6 = 0xf;

    iVar5 = (int)(char)((int *)0x0605D23C)[(unsigned char)*(int *)0x06078648];

  }

  (*(int(*)())0x06018DDC)(iVar5,iVar5,uVar6);

LAB_06018bd8:

  *(int *)0x0607EBE4 = 0;

  iVar4 = *(int *)((int)(int)puVar1 << 1);

  *(unsigned int *)0x0607EA9C = (unsigned int)*(unsigned short *)(0x0604806C + iVar4);

  *(char **)0x0607EB84 = 0x060D5840;

  *(char **)0x0607EB88 = 0x060C6000;

  *(char **)0x06063F3C = 0x0604800C + *(int *)((int)(int)puVar1 << 3);

  iVar5 = (*(int(*)())0x06035280)();

  *(int *)0x06063F18 = iVar5 + -1;

  *(int *)0x060786AC = 0;

  *(int *)0x06063F1C = 1;

  *(int *)0x06063F20 = 0;

  *(int *)0x06063F24 = 0;

  *(int *)0x06086034 = 0;

  puVar2 = (char *)0x06063F28;

  iVar5 = (int)(char)((char)COURSE_SELECT * '\x06');

  *(unsigned int *)0x06063F28 = (unsigned int)*(unsigned short *)(0x0604805A + iVar4 + iVar5);

  *(unsigned int *)0x0607EA98 = (unsigned int)*(unsigned short *)(0x06048072 + iVar4);

  *(unsigned int *)0x0607EAA0 = (unsigned int)*(unsigned short *)(0x06048024 + iVar4);

  puVar3 = (char *)0x0607EAAC;

  *(unsigned int *)0x0607EAAC = (unsigned int)*(unsigned short *)(0x0604802A + iVar4 + iVar5);

  *(unsigned int *)puVar3 =

       *(int *)puVar3 +

       (unsigned int)*(unsigned short *)

              (0x0604803C + iVar4 + (char)((char)*(int *)0x0605AD0C * '\x06')) *

       *(int *)puVar2;

  (*(int(*)())0x0602761E)(0x25C00220 + *(int *)(0x06059FFC << 3),0x0605CDDC,0xa0);

  (*(int(*)())0x060149E0)();

  (*(int(*)())0x060148FC)();

  (*(int(*)())0x06026CE0)();

  VBLANK_OUT_COUNTER = 0;

  (*(int(*)())0x0600A026)();

  *(int *)0x0605AD08 = 0;

  *(char **)0x0607E944 = 0x06078900;

  (*(int(*)())0x06010994)();

  (*(int(*)())0x060038D4)();

  (*(int(*)())0x060039C8)();

  (*(int(*)())(*(int *)(0x0605D1CC + *(int *)((int)(int)puVar1 << 2))))();

  (*(int(*)())0x060032D4)();

  (*(int(*)())0x06003430)();

  (*(int(*)())0x06014994)();

  (*(int(*)())0x06021128)();

  return;

}

int FUN_06018ddc(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  int uVar1;

  int local_18;

  char uStack_14;

  char uStack_13;

  int uStack_10;

  char uStack_c;

  char uStack_b;

  char uStack_8;

  local_18 = 2;

  uStack_13 = 1;

  uStack_10 = 2;

  uStack_b = 99;

  uStack_14 = param_1;

  uStack_c = param_2;

  uStack_8 = param_3;

  uVar1 = (*(int(*)())0x06034D1C)(&local_18);

  return uVar1;

}

int FUN_06018e1e(param_1)
    char param_1;
{

  int uVar1;

  int local_c;

  char uStack_8;

  char uStack_7;

  local_c = 2;

  uStack_7 = 1;

  uStack_8 = param_1;

  uVar1 = (*(int(*)())0x06034DEA)(&local_c);

  return uVar1;

}

int
FUN_06018e70()
{
    int buf[2];
    buf[0] = 3;
    return FUN_06034DEA(buf);
}

int
FUN_06018eac()
{
    char buf[16];
    cd_register_double_read(buf);
    return buf[0] & 0x1f;
}

void FUN_06018fa4()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x06012EDC)();

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  return;

}

void FUN_06018ff8()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x06012EBC)();

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0600FF);

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  return;

}

void FUN_06019058()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x06012F10)();

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0600FF);

  return;

}

void FUN_060190b8()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x06012F20)();

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  return;

}

void FUN_060190f4()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x06012F50)();

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  return;

}

void FUN_0601914c()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x06012F58)();

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  return;

}

void FUN_06019188()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x06012F60)();

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  return;

}

void FUN_060191e0()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x0602760C)(0x25A03000,0x00200000,0x0006D000);

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  return;

}

void FUN_06019248()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  SOUND_TIMEOUT_FLAG = 0;

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  (*(int(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (SOUND_TIMEOUT_FLAG == 0) {

    (*(int(*)())0x0602760C)(0x25A03000,0x0026D000,0x0006D000);

    *(short *)0x25A02DBE = 0;

  }

  (*(int(*)())puVar1)(0xf,0xAE0001FF);

  return;

}

void FUN_060192b4()
{

  char *puVar1;

  char *puVar2;

  

  puVar1 = (char *)0x0007FFFF;

  puVar2 = (char *)0x25A00000;

  do {

    puVar1 = puVar1 + -1;

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  } while (puVar1 != (char *)0x0);

  return;

}

/* sound_channels_off -- Mute sound channels 1, 3, 2 via sound_cmd_dispatch.
 * Called during sound system shutdown/reset. */
extern void sound_cmd_dispatch(int channel, int command);

void FUN_060192ca(void)
{
    sound_cmd_dispatch(1, 0);
    sound_cmd_dispatch(3, 0);
    sound_cmd_dispatch(2, 0);
}

/* sound_mailbox_timeout -- Busy-wait ~100k iterations then set timeout flag.
 * Called when SCSP sound mailbox doesn't respond in time. */
void FUN_060192e8(void)
{
    register unsigned int cnt asm("r1") = 100000;
    do {
        cnt--;
    } while (cnt != 0);
    SOUND_TIMEOUT_FLAG = 1;
}

void FUN_06019324()
{

  char *puVar1;

  puVar1 = (char *)0x06038BD4;

  (*(int(*)())0x06038BD4)(0x100,1);

  (*(int(*)())puVar1)(4);

  (*(int(*)())puVar1)(8,5);

  (*(int(*)())puVar1)(0x10,6);

  (*(int(*)())puVar1)(0x20,7);

  (*(int(*)())puVar1)(1,0);

  INPUT_STATE = INPUT_STATE | 0x40000000;

  return;

}

/* sound_vdp2_scroll_setup -- DMA-copy 5 scroll plane data blocks to VDP2 VRAM.
 * Loads sound system visualization data (waveform/spectrum display).
 *   0x25F00540: color data (0x20 bytes)
 *   0x25F00000: pattern names (0x20 bytes)
 *   0x25F00600: cell data (0x20 bytes)
 *   0x25F00620: animation cells (0xE0 bytes)
 *   0x25F00780: palette data (0x80 bytes) */
void FUN_0601938c(void)
{
    register int dma_copy asm("r3") = 0x0602761E;
    (*(int(*)())dma_copy)(0x25F00540, 0x0605CE9C, 0x20);
    (*(int(*)())dma_copy)(0x25F00000, 0x0605CD9C, 0x20);
    (*(int(*)())dma_copy)(0x25F00600, 0x0605CF9C, 0x20);
    (*(int(*)())dma_copy)(0x25F00620, 0x0605CEBC, 0xE0);
    (*(int(*)())dma_copy)(0x25F00780, 0x06049DC4, 0x80);
}

void FUN_060193f4()
{

  char *puVar1;

  char *puVar2;

  *(int *)0x06085FF0 = 0;

  *(int *)0x0605D245 = 0;

  *(int *)0x06085FF1 = 1;

  *(int *)0x06085FF2 = 0;

  *(int *)0x06085FF3 = 0;

  *(int *)0x06085FF5 = 0;

  (*(int(*)())0x0601D5F4)(0xf,0xAE0003FF);

  puVar2 = (char *)0x06026CE0;

  puVar1 = (char *)0x0605B6D8;

  INPUT_STATE = INPUT_STATE | 0x80000000;

  (*(int(*)())puVar2)();

  (*(int(*)())0x06026CE0)();

  FUN_0601938c();

  (*(int(*)())0x0601A73E)();

  (*(int(*)())0x0600511E)(0x25E76174,0x00014000,0,9);

  (*(int(*)())0x0600511E)(0x25E761FC,0x00017700,0,8);

  puVar2 = (char *)0x06014884;

  (*(int(*)())0x06014884)(8,0);

  (*(int(*)())puVar2)(0x10,0);

  (*(int(*)())puVar2)(0x20,0);

  (*(int(*)())0x0602853E)(4);

  (*(int(*)())0x0602853E)(0xc);

  puVar2 = (char *)0x06028560;

  *(unsigned int *)puVar1 = *(unsigned int *)puVar1 | 4;

  (*(int(*)())puVar2)();

  (*(int(*)())0x06028400)(4,*(int *)0x06063AF8,0,0x0000A000 + *(int *)(0x06063AF8 + 4),

             0x06063AF8);

  FUN_06019324();

  return;

}

unsigned int FUN_0601950c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  int *puVar8;

  char cVar9;

  puVar5 = (char *)0x06049AEC;

  puVar4 = (char *)0x0605D244;

  puVar3 = (char *)0x06063750;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06049AF4;

  if (*(int *)0x06085FF1 != '\0') {

    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_060195ac),0x14,

               *(int *)((int)(0x06063750 + DAT_060195ac) + 4) + (int)DAT_060195ae);

    cVar9 = '\0';

    do {

      if (cVar9 != *puVar4) {

        puVar8 = (int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar1 + (cVar9 << 1)) << 3));

        (*(int(*)())puVar2)(0xc,*puVar8,

                          ((unsigned int)(unsigned char)(puVar5 + (cVar9 << 1))[1] * 0x40 +

                          (unsigned int)(unsigned char)puVar5[(cVar9 << 1)]) << 1,puVar8[1] + (int)PTR_DAT_060195b0

                         );

      }

      cVar9 = cVar9 + '\x01';

      *(int *)0x06085FF1 = 0;

    } while (cVar9 < '\x04');

  }

  puVar6 = (char *)0x0605D242;

  uVar7 = (unsigned int)(unsigned char)*(int *)0x06085FF5;

  if (uVar7 == 0) {

    if ((unsigned char)*(int *)0x0605D242 < 0x10) {

      puVar8 = (int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar1 + (char)(*puVar4 << 1)) << 3));

      uVar7 = (*(int(*)())puVar2)(0xc,*puVar8,

                                ((unsigned int)(unsigned char)(puVar5 + (char)(*puVar4 << 1))[1] * 0x40 +

                                (unsigned int)(unsigned char)puVar5[(char)(*puVar4 << 1)]) << 1,

                                puVar8[1] + (int)DAT_06019694);

    }

    else {

      (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)(puVar5 + (char)(*puVar4 << 1))[1] * 0x40 +

                     (unsigned int)(unsigned char)puVar5[(char)(*puVar4 << 1)]) << 1,0x90,

                 *(int *)0x0605D4EC);

      uVar7 = (*(int(*)())0x060284AE)(0xc,(((unsigned char)(puVar5 + (char)(*puVar4 << 1))[1] + 2) << 6 +

                             (unsigned int)(unsigned char)puVar5[(char)(*puVar4 << 1)]) << 1,0x90,

                         *(int *)0x0605D4EC);

      if (0x1e < (unsigned char)*puVar6) {

        *puVar6 = 0;

      }

    }

  }

  return uVar7;

}

void FUN_060196a4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  puVar3 = (char *)0x0605D244;

  puVar2 = (char *)0x0605D242;

  puVar1 = (char *)0x06085FF1;

  (*(int(*)())0x06026110)();

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019762) != 0) {

    (*(int(*)())0x06028400)(0xc,*(int *)

                    (0x06063750 + (unsigned int)*(unsigned short *)(0x06049AF4 + (char)(*puVar3 << 1)) << 3)

               ,((unsigned int)(unsigned char)((char *)(0x06049AEC + (char)(*puVar3 << 1)))[1] * 0x40 +

                (unsigned int)(unsigned char)((int *)0x06049AEC)[(char)(*puVar3 << 1)]) << 1,

               *(int *)((int)(0x06063750 +

                             (unsigned int)*(unsigned short *)(0x06049AF4 + (char)(*puVar3 << 1)) << 3) + 4) +

               (int)(short)PTR_DAT_06019764);

    if ('\x01' < (char)*puVar3) {

      *puVar3 = 0;

    }

    VBLANK_OUT_COUNTER = 0;

    *puVar2 = 0;

    GAME_STATE = 4;

    *puVar1 = 1;

    *(int *)0x06085FF5 = 1;

    return;

  }

  if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06019764) == 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019864) != 0) {

      *puVar1 = 1;

      *puVar2 = 5;

      *puVar3 = *puVar3 + -1;

      if ((char)*puVar3 < '\0') {

        *puVar3 = 3;

      }

    }

  }

  else {

    *puVar1 = 1;

    *puVar2 = 5;

    *puVar3 = *puVar3 + '\x01';

    if ('\x03' < (char)*puVar3) {

      *puVar3 = 0;

    }

  }

  *(int *)0x0605D243 = *(int *)0x0605D243 + '\x01';

  *puVar2 = *puVar2 + '\x01';

  (*(int(*)())(*(int *)((char)(*puVar3 << 2) + 0x0605D250)))();

  return;

}

/* subsystem_setup_init -- Initialize sound/display subsystem for game mode.
 * Configures VDP sprite slot (0xC), resets VDP sprite system,
 * sets sound subsystem flags (active=1, channel=1, volume=0xFF),
 * then runs subsystem data init, display setup, and cursor init. */
void FUN_060198e0(void)
{
    (*(int(*)())0x0602853E)(0xC);    /* VDP sprite slot config */
    (*(int(*)())0x06028560)();       /* VDP sprite system reset */
    *(int *)0x06085FF1 = 1;          /* sound subsystem active */
    *(int *)0x06085FF6 = 1;          /* sound channel active */
    *(int *)0x06085FF7 = 0xFF;       /* volume = max */
    FUN_06019928();                  /* subsystem data init */
    FUN_0601a80c();                  /* display setup */
    (*(int(*)())0x0601A940)();       /* cursor/selection init */
}

void FUN_06019928()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = (char *)0x060284AE;

  puVar2 = (char *)0x06049AFC;

  puVar1 = (char *)0x0605D294;

  iVar5 = 0x90;

  if (*(int *)0x06085FF1 == '\x01') {

    INPUT_STATE = INPUT_STATE | 4;

    bVar6 = 0;

    do {

      (*(int(*)())puVar3)(8,((unsigned int)(unsigned char)(puVar2 + (unsigned int)(bVar6 << 1))[1] * 0x40 +

                          (unsigned int)(unsigned char)puVar2[(unsigned int)(bVar6 << 1)]) << 1,iVar5,

                        *(int *)(puVar1 + (unsigned int)(bVar6 << 2)));

      puVar4 = (char *)0x06085FF0;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 8);

    (*(int(*)())puVar3)(0xc,((unsigned int)(unsigned char)(puVar2 + (char)*(int *)(0x06085FF0 << 1))[1] * 0x40 +

                          (unsigned int)(unsigned char)puVar2[(char)*(int *)(0x06085FF0 << 1)]) << 1,iVar5,

                      *(int *)(puVar1 + (char)*(int *)(0x06085FF0 << 2)));

    (*(int(*)())puVar3)(0xc,((unsigned int)(unsigned char)puVar2[(char)(*puVar4 << 1) + 1] * 0x40 + 1) << 1,iVar5,

                      0x06049E44);

    if (*puVar4 != '\x06') {

      (*(int(*)())puVar3)(0xc,((unsigned int)(unsigned char)puVar2[0xd] * 0x40 + (unsigned int)(unsigned char)puVar2[0xc] + 0xd) << 1,

                        iVar5,*(int *)0x0605D4F0,puVar2);

    }

    FUN_06019bc8();

    FUN_06019db8();

    FUN_06019fb2();

    FUN_0601a65e();

    *(int *)0x06085FF1 = 0;

  }

  return;

}

void FUN_06019a48()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  puVar2 = (char *)0x06085FF0;

  puVar1 = (char *)0x06085FF1;

  if (*(int *)0x06085FF3 == '\0') {

    iVar3 = 0x90;

    if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & iVar3 + 0x70U) == 0) {

      if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06019b24) == 0) {

        if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019bfc) != 0) {

          (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +

                         (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,iVar3,

                     *(int *)0x0605D4F0);

          *puVar2 = *puVar2 + -1;

          if ((char)*puVar2 < '\0') {

            *puVar2 = 7;

          }

          *puVar1 = 1;

        }

      }

      else {

        (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +

                       (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,iVar3,

                   *(int *)0x0605D4F0);

        *puVar2 = *puVar2 + '\x01';

        if ('\a' < (char)*puVar2) {

          *puVar2 = 0;

        }

        *puVar1 = 1;

      }

    }

    else {

      (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +

                     (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,iVar3,

                 *(int *)0x0605D4F0);

      if (*puVar2 == '\a') {

        GAME_STATE = 7;

      }

      else {

        *puVar2 = 7;

        *puVar1 = 1;

        VBLANK_OUT_COUNTER = 0;

        (*(int(*)())0x06026CE0)();

      }

    }

  }

  *(int *)0x0605D243 = *(int *)0x0605D243 + '\x01';

  *(int *)0x0605D242 = *(int *)0x0605D242 + '\x01';

  (*(int(*)())(*(int *)(0x0605D260 + (char)(*puVar2 << 2))))();

  return;

}

int FUN_06019bc8()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = (char *)0x06028400;

  puVar2 = (char *)0x06049B12;

  puVar1 = (char *)0x0605D242;

  if (*(int *)0x06085FF0 == '\0') {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == COURSE_SELECT) {

        if ((unsigned char)*puVar1 < 8) {

          iVar5 = 6;

        }

        else {

          iVar5 = 7;

          if (0x10 < (unsigned char)*puVar1) {

            *puVar1 = 0;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      uVar4 = (*(int(*)())puVar3)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B0C + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B0C)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 3);

  }

  else {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == COURSE_SELECT) {

        iVar5 = 6;

      }

      else {

        iVar5 = 5;

      }

      uVar4 = (*(int(*)())puVar3)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B0C + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B0C)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 3);

  }

  return uVar4;

}

int FUN_06019db8()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = (char *)0x0605D242;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06049B2C;

  if (*(int *)0x06085FF0 == '\x01') {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD0C) {

        if ((unsigned char)*puVar3 < 8) {

          iVar5 = 6;

        }

        else {

          iVar5 = 7;

          if (0x10 < (unsigned char)*puVar3) {

            *puVar3 = 0;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B18 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B18)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  else {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD0C) {

        iVar5 = 6;

      }

      else {

        iVar5 = 5;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B18 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B18)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  return uVar4;

}

int FUN_06019fb2()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = (char *)0x0605D242;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06049B2C;

  if (*(int *)0x06085FF0 == '\x02') {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD04) {

        if ((unsigned char)*puVar3 < 8) {

          iVar5 = 6;

        }

        else {

          iVar5 = 7;

          if (0x10 < (unsigned char)*puVar3) {

            *puVar3 = 0;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B22 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B22)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  else {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD04) {

        iVar5 = 6;

      }

      else {

        iVar5 = 5;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B22 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B22)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  return uVar4;

}

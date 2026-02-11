#include "game.h"

extern int DAT_0601e162;
extern int DAT_0601e164;
extern int DAT_0601e166;
extern int DAT_0601e238;
extern int DAT_0601e23a;
extern int DAT_0601e23c;
extern int DAT_0601e23e;
extern int DAT_0601e240;
extern int DAT_0601e242;
extern int DAT_0601e244;
extern int DAT_0601e246;
extern int DAT_0601e248;
extern int DAT_0601e24a;
extern int DAT_0601e24c;
extern int DAT_0601e24e;
extern int DAT_0601e444;
extern int DAT_0601efda;
extern int DAT_0601f5c6;
extern int DAT_0601f6ba;
extern int DAT_0601f804;
extern int DAT_0601f806;
extern int DAT_0601f962;
extern int DAT_0601f964;
extern int DAT_0601fa26;
extern int DAT_0601fac4;
extern int DAT_0601fac6;
extern int DAT_0601fac8;
extern int DAT_0601faca;
extern int DAT_0601facc;
extern int DAT_0601face;
extern int DAT_0601fba6;
extern int DAT_0601fba8;
extern int DAT_0601fbaa;
extern int DAT_0601fbac;
extern int DAT_0601fbae;
extern int DAT_0601fbb0;
extern int DAT_0601fbb2;
extern int DAT_0601fbb4;
extern int DAT_0601fbb6;
extern int DAT_0601fbb8;
extern int DAT_0601fbba;
extern int DAT_0601fbbc;
extern int DAT_0601fbbe;
extern int DAT_0601fbc0;
extern int DAT_0601fbc2;
extern int DAT_0601fbc4;
extern int DAT_0601fbc6;
extern int DAT_0601fbc8;
extern int DAT_0601fc8e;
extern int DAT_0601fc90;
extern int DAT_0601fc92;
extern int DAT_0601fc94;
extern int DAT_0601fc96;
extern int DAT_0601fc98;
extern int DAT_0601fc9a;
extern int DAT_0601fc9c;
extern int DAT_0601fc9e;
extern int DAT_0601fca0;
extern int DAT_0601fca2;
extern int DAT_0601fca4;
extern int DAT_0601fca6;
extern int DAT_0601fca8;
extern int DAT_0601fe96;
extern int DAT_0601ff8a;
extern int DAT_0601ff8c;
extern int DAT_0601ff8e;
extern int DAT_0601ff90;
extern int DAT_0601ff92;
extern void FUN_0601e26c();
extern void FUN_0601e2b4();
extern void FUN_0601e37c();
extern int FUN_0601e488(unsigned short slot);
extern unsigned int FUN_0601e4d4();
extern int FUN_0601e6a4();
extern int FUN_0601e764();
extern int FUN_0601e810();
extern unsigned int FUN_0601eb70();
extern char * FUN_0601ebda();
extern char * FUN_0601efc4();
extern int FUN_0601f40c();
extern void FUN_0601f4b4();
extern int FUN_0601f5e0();
extern void FUN_0601f87a();
extern void FUN_0601f9cc();
extern void FUN_0601fd20();
extern void FUN_0601fec0();
extern int vdp1_texture_palette_init();
extern int PTR_DAT_0601e168;
extern int PTR_DAT_0601ebf0;
extern int PTR_DAT_0601f808;
extern int PTR_DAT_0601fa28;
extern int PTR_DAT_0601fd48;

void FUN_0601e0de()
{

  return;

}

void FUN_0601e100()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  puVar4 = (char *)0x00008000;

  puVar2 = (char *)0x06028400;

  puVar3 = (char *)0x06063750;

  if (DEMO_MODE_FLAG == 0) {

    (*(int(*)())0x0602761E)(0x25F00100,0x0604892C,0x20);

    (*(int(*)())puVar2)(8,*(int *)(puVar3 + 0x10),(int)DAT_0601e162,

                      puVar4 + *(int *)(puVar3 + 0x14));

    puVar4 = puVar4 + *(int *)((int)(puVar3 + DAT_0601e164) + 4);

    puVar3 = *(char **)(puVar3 + DAT_0601e164);

    sVar1 = DAT_0601e166;

  }

  else {

    (*(int(*)())0x0602761E)(0x25F00100,0x0605DFCC,0x20);

    sVar1 = DAT_0601e238;

    if (*(int *)0x06078644 == 1) {

      sVar1 = PTR_DAT_0601e168;

    }

    (*(int(*)())puVar2)(8,*(int *)(puVar3 + sVar1),(int)DAT_0601e23a,

                      puVar4 + *(int *)((int)(puVar3 + sVar1) + 4));

    puVar4 = (char *)0x00009000;

    (*(int(*)())puVar2)(8,*(int *)(puVar3 + DAT_0601e23c),0x3c2,

                      0x00009000 + *(int *)((int)(puVar3 + DAT_0601e23c) + 4));

    (*(int(*)())puVar2)(8,*(int *)(puVar3 + DAT_0601e240),0x4c2,

                      puVar4 + *(int *)((int)(puVar3 + DAT_0601e240) + 4));

    (*(int(*)())puVar2)(8,*(int *)(puVar3 + DAT_0601e244),0x5c2,

                      puVar4 + *(int *)((int)(puVar3 + DAT_0601e244) + 4));

    (*(int(*)())0x0601AB8C)();

    FUN_0601e26c(*(int *)0x06086008);

    sVar1 = DAT_0601e248;

    (*(int(*)())puVar2)(8,0x0605DFF4,(int)DAT_0601e24a,

                      puVar4 + *(int *)(puVar3 + DAT_0601e248 + 4));

    FUN_0601e26c(*(int *)0x06086004);

    (*(int(*)())puVar2)(8,0x0605DFF4,(int)DAT_0601e24c,puVar4 + *(int *)(puVar3 + sVar1 + 4));

    FUN_0601e26c(0);

    puVar4 = puVar4 + *(int *)(puVar3 + sVar1 + 4);

    puVar3 = (char *)0x0605DFF4;

    sVar1 = DAT_0601e24e;

  }

  (*(int(*)())puVar2)(8,puVar3,(int)sVar1,puVar4);

  *(int *)0x06087068 = 0;

  *(int *)0x0605DFF0 = 0;

  return;

}

void FUN_0601e26c()
{

  char *puVar1;

  char *puVar2;

  int uVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  unsigned char bVar6;

  puVar2 = (char *)0x06087064;

  puVar1 = (char *)0x0605DFF4;

  uVar3 = (*(int(*)())0x06005DD4)();

  *(int *)puVar2 = uVar3;

  bVar6 = 0;

  do {

    uVar5 = (unsigned int)bVar6;

    uVar4 = (unsigned int)bVar6;

    bVar6 = bVar6 + 1;

    *(unsigned short *)(puVar1 + (uVar5 << 1) + 4) = (unsigned short)*(unsigned char *)(*(int *)puVar2 + uVar4);

  } while (bVar6 < 8);

  return;

}

void FUN_0601e2b4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  puVar4 = (char *)0x20100063;

  puVar3 = (char *)0x0605E068;

  puVar2 = (char *)0x0604A5C0;

  puVar1 = (char *)0x060877D8;

  if (*(int *)0x06087080 == '\0') {

    for (uVar5 = 0; uVar5 < *(unsigned int *)(puVar2 + (unsigned int)(unsigned char)(*puVar1 << 2)); uVar5 = uVar5 + 1) {

      *(char *)(*(int *)puVar3 + uVar5) = 0;

    }

  }

  do {

  } while ((*puVar4 & 1) == 1);

  *puVar4 = 1;

  SMPC_COMREG = 0x1a;

  do {

  } while ((*puVar4 & 1) != 0);

  (*(int(*)())(*(int *)0x06000358))(*(int *)0x0605E060,*(int *)0x0605E064,0x06087086);

  FUN_0601e37c();

  do {

  } while ((*puVar4 & 1) == 1);

  *puVar4 = 1;

  SMPC_COMREG = 0x19;

  do {

  } while ((*puVar4 & 1) != 0);

  return;

}

void FUN_0601e37c()
{

  short uVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned int uVar5;

  puVar2 = (char *)0x06087094;

  uVar1 = DAT_0601e444;

  uVar5 = 0;

  uVar4 = 0;

  do {

    if (2 < uVar4) {

      *(short *)0x06087084 = (short)uVar5;

      return;

    }

    if (*(short *)(0x06087086 + (unsigned int)(uVar4 << 2)) != 0) {

      *(unsigned short *)(puVar2 + (((uVar5 & 0xffff) << 5) + 0x1c)) = uVar4;

      iVar3 = FUN_0601e488(uVar5);

      if (iVar3 != 0) {

        if (iVar3 == 1) goto LAB_0601e46a;

        if (iVar3 == 2) {

          iVar3 = FUN_0601e6a4(*(short *)(puVar2 + (((uVar5 & 0xffff) << 5) + 0x1c)));

          if (iVar3 == 0) {

            puVar2[(uVar5 & 0xffff) << 5 + 0x1f] = 1;

          }

          else {

            puVar2[(uVar5 & 0xffff) << 5 + 0x1f] = (char)uVar1;

          }

        }

      }

      if (*(unsigned int *)(puVar2 + (((uVar5 & 0xffff) << 5) + 0xc)) <

          *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)*(int *)(0x060877D8 << 2)) + 0x20U) {

        puVar2[(uVar5 & 0xffff) << 5 + 0x1e] = 0;

      }

      else {

        puVar2[(uVar5 & 0xffff) << 5 + 0x1e] = 1;

      }

      uVar5 = uVar5 + 1;

    }

LAB_0601e46a:

    uVar4 = uVar4 + 1;

  } while( 1 );

}

/* sound_slot_play -- Start sound playback for a slot.
 * Computes slot descriptor at 0x06087094 + (slot * 32),
 * calls BIOS sound open then play via vtable at 0x06000354. */
int FUN_0601e488(unsigned short slot)
{
    char *desc = (char *)(0x06087094 + (unsigned int)(slot << 5));
    short sound_id = *(short *)(desc + 0x1C);

    /* BIOS sound open (vtable[1]) */
    (*(int(*)())(*(int *)(*(int *)0x06000354 + 4)))(sound_id, 0);
    /* BIOS sound play (vtable[3]) */
    (*(int(*)())(*(int *)(*(int *)0x06000354 + 0xC)))(sound_id,
        *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)*(int *)(0x060877D8 << 2)), desc);

    return 0;
}

unsigned int FUN_0601e4d4()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned int uVar4;

  char *pcVar5;

  int iVar6;

  unsigned char *pbVar7;

  char local_28 [4];

  char local_24 [8];

  puVar1 = (char *)0x2010001F;

  pbVar7 = 0x2010001F + 0x44;

  pcVar5 = local_28;

  local_28[0] = '\0';

  local_24[0] = '\0';

  local_28[1] = 0;

  local_24[1] = 0;

  local_28[2] = 0;

  local_24[2] = 0;

  for (iVar6 = 0; puVar2 = 0x06087094, iVar6 < (int)(unsigned int)*(unsigned short *)0x06087084;

      iVar6 = iVar6 + 1) {

    do {

    } while ((*pbVar7 & 1) == 1);

    *pbVar7 = 1;

    *puVar1 = (char *)0x1a;

    do {

    } while ((*pbVar7 & 1) != 0);

    (*(int(*)())(*(int *)(*(int *)0x06000354 + 4)))(*(short *)(puVar2 + (iVar6 << 5) + 0x1c),0);

    iVar3 = FUN_0601e764((int)*(short *)(puVar2 + (iVar6 << 5) + 0x1c),

                         0x0604A57C + (unsigned int)(unsigned char)*(int *)0x060877D8 * 0xc,

                         *(int *)0x0605E098);

    do {

    } while ((*pbVar7 & 1) == 1);

    *pbVar7 = 1;

    *puVar1 = (char *)0x19;

    do {

    } while ((*pbVar7 & 1) != 0);

    if (iVar3 == 0) {

      local_24[iVar6] = '\x01';

    }

    if (puVar2[(iVar6 << 5) + 0x1e] != '\0') {

      local_28[iVar6] = '\x01';

    }

  }

  uVar4 = 0;

  do {

    if (local_24[uVar4] != '\0') {

      return uVar4 & 0xff;

    }

    uVar4 = uVar4 + 1;

  } while ((int)uVar4 < 3);

  uVar4 = 3;

  while( 1 ) {

    if (local_28 + 3 <= pcVar5) {

      return 8;

    }

    if (*pcVar5 != '\0') break;

    pcVar5 = pcVar5 + 1;

    uVar4 = uVar4 + 1;

  }

  return uVar4 & 0xff;

}

int FUN_0601e6a4(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  puVar1 = (char *)0x06000354;

  iVar3 = 0;

  do {

    iVar2 = (*(int(*)())(*(int *)(*(int *)puVar1 + 8)))(param_1);

    if (iVar2 == 0) {

      return 0;

    }

    iVar3 = iVar3 + 1;

  } while (iVar3 < 10);

  return iVar2;

}

int FUN_0601e764(param_1, param_2, param_3)
    unsigned short param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  puVar1 = (char *)0x20100063;

  iVar2 = (*(int(*)())0x06035C1C)(param_2);

  if (0xb < iVar2) {

    *(char *)(param_2 + 0xb) = 0;

  }

  do {

  } while ((*puVar1 & 1) == 1);

  *puVar1 = 1;

  SMPC_COMREG = 0x1a;

  do {

  } while ((*puVar1 & 1) != 0);

  uVar3 = (*(int(*)())(*(int *)(*(int *)0x06000354 + 0x14)))(*(short *)(0x06087094 + (unsigned int)(param_1 << 5) + 0x1c),param_2,param_3

                    );

  do {

  } while ((*puVar1 & 1) == 1);

  *puVar1 = 1;

  SMPC_COMREG = 0x19;

  do {

  } while ((*puVar1 & 1) != 0);

  return uVar3;

}

int FUN_0601e810(param_1, param_2, param_3)
    unsigned short param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int uVar6;

  puVar3 = (char *)0x20100063;

  puVar2 = (char *)0x060877D8;

  puVar1 = (char *)0x0605E06C;

  iVar5 = (*(int(*)())0x06035C1C)(param_2);

  if (0xb < iVar5) {

    *(char *)(param_2 + 0xb) = 0;

  }

  iVar5 = (*(int(*)())0x06035C1C)(puVar1 + (unsigned int)(unsigned char)*puVar2 * 0xb);

  if (10 < iVar5) {

    puVar1[(unsigned int)(unsigned char)*puVar2 * 0xb + 10] = 0;

  }

  FUN_0601f4b4(0x060877E8);

  puVar4 = (char *)0x060877B4;

  (*(int(*)())0x06035C08)(0x060877B4,param_2);

  (*(int(*)())0x06035C08)(puVar4 + 0xc,puVar1 + (unsigned int)(unsigned char)*puVar2 * 0xb);

  puVar4[0x17] = 0;

  uVar6 = (*(int(*)())(*(int *)(*(int *)0x06000354 + 0x28)))(0x060877E8);

  *(int *)(puVar4 + 0x18) = uVar6;

  *(int *)(puVar4 + 0x1c) = *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)(*puVar2 << 2));

  do {

  } while ((*puVar3 & 1) == 1);

  *puVar3 = 1;

  SMPC_COMREG = 0x1a;

  do {

  } while ((*puVar3 & 1) != 0);

  uVar6 = (*(int(*)())(*(int *)(*(int *)0x06000354 + 0x10)))(*(short *)(0x06087094 + (unsigned int)(param_1 << 5) + 0x1c),

                     0x060877B4,param_3,0);

  do {

  } while ((*puVar3 & 1) == 1);

  *puVar3 = 1;

  SMPC_COMREG = 0x19;

  do {

  } while ((*puVar3 & 1) != 0);

  return uVar6;

}

int FUN_0601e958()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = (char *)0x0605E05C;

  puVar2 = (char *)0x0601F8BC;

  puVar1 = (char *)0x0605E098;

  iVar5 = (int)(char)*(int *)0x0605E05D;

  if (iVar5 == 0) {

    FUN_0601e2b4();

    puVar4 = (char *)0x060877D8;

    bVar6 = FUN_0601e4d4(0x0604A57C + (unsigned int)(unsigned char)*(int *)0x060877D8 * 0xc);

    if (bVar6 < 7) {

      ((int *)0x060877DD)[(unsigned char)*puVar4] = 1;

      if (2 < bVar6) {

        ((int *)0x060877D9)[(unsigned char)*puVar4] = bVar6 - 3;

        FUN_0601eb70();

        iVar5 = FUN_0601f40c();

        return iVar5;

      }

      ((int *)0x060877D9)[(unsigned char)*puVar4] = bVar6;

      iVar5 = FUN_0601e764(((int *)0x060877D9)[(unsigned char)*puVar4],

                           0x0604A57C + (unsigned int)(unsigned char)*puVar4 * 0xc,

                           *(int *)puVar1);

      if (iVar5 == 0) {

        iVar5 = 0;

        if (*(int *)0x06087080 == '\0') {

          iVar5 = 0;

          while (*(char *)(*(int *)puVar1 + iVar5) == ((int *)0x0604A5AC)[iVar5]) {

            iVar5 = iVar5 + 1;

            if (0xf < iVar5) {

              iVar5 = FUN_0601ebda();

              return iVar5;

            }

          }

          *puVar3 = 8;

          iVar5 = (*(int(*)())puVar2)();

        }

      }

      else {

        *puVar3 = 8;

        iVar5 = (*(int(*)())puVar2)();

      }

    }

    else {

      FUN_0601eb70();

      ((int *)0x060877DD)[(unsigned char)*puVar4] = 0;

      *puVar3 = 4;

      iVar5 = (*(int(*)())puVar2)();

    }

  }

  else {

    *(int *)0x0605E05C = 0;

  }

  return iVar5;

}

int FUN_0601eaa0()
{

  char *puVar1;

  unsigned char bVar2;

  int uVar3;

  puVar1 = (char *)0x060877D8;

  uVar3 = 0;

  bVar2 = FUN_0601e4d4(0x0604A57C + (unsigned int)(unsigned char)*(int *)0x060877D8 * 0xc);

  if (bVar2 < 7) {

    ((int *)0x060877DD)[(unsigned char)*puVar1] = 1;

    if (bVar2 < 3) {

      ((int *)0x060877D9)[(unsigned char)*puVar1] = bVar2;

      uVar3 = 1;

    }

    else {

      ((int *)0x060877D9)[(unsigned char)*puVar1] = bVar2 - 3;

    }

  }

  else {

    ((int *)0x060877DD)[(unsigned char)*puVar1] = 0;

  }

  return uVar3;

}

void FUN_0601eb1c()
{

  if (((int *)0x060877DD)[(unsigned char)*(int *)0x060877D8] != '\0') {

    FUN_0601e810(((int *)0x060877D9)[(unsigned char)*(int *)0x060877D8],

                 0x0604A57C + (unsigned int)(unsigned char)*(int *)0x060877D8 * 0xc,

                 *(int *)0x0605E098);

  }

  return;

}

unsigned int FUN_0601eb70()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  int iVar8;

  puVar5 = (char *)0x0605E09C;

  puVar4 = (char *)0x0604A5AC;

  puVar3 = (char *)0x0605E098;

  puVar2 = (char *)0x060877D8;

  puVar1 = (char *)0x0604A5C0;

  uVar6 = (unsigned int)(unsigned char)*(int *)0x06087080;

  if (uVar6 == 0) {

    for (uVar7 = 0; uVar6 = (unsigned int)(unsigned char)(*puVar2 << 2), uVar7 < *(unsigned int *)(puVar1 + uVar6);

        uVar7 = uVar7 + 1) {

      *(char *)(*(int *)puVar3 + uVar7) = 0;

    }

    iVar8 = 0;

    do {

      *(char *)(*(int *)puVar5 + iVar8) = puVar4[iVar8];

      *(char *)(*(int *)puVar5 + iVar8 + 1) = puVar4[iVar8 + 1];

      iVar8 = iVar8 + 2;

    } while (iVar8 < 0x10);

  }

  return uVar6;

}

char * FUN_0601ebda()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  char *puVar6;

  int *puVar7;

  char *puVar8;

  int *puVar9;

  char *puVar10;

  iVar5 = 0xf0;

  puVar2 = (char *)(unsigned int)(unsigned char)*(int *)0x06087080;

  if (puVar2 == (char *)0x0) {

    puVar3 = (char *)(*(int *)0x0605E098 + 0x10);

    puVar9 = (int *)(0x0605DD6C + 0x48);

    puVar7 = (int *)0x0605DD6C;

    do {

      puVar10 = (char *)*puVar7;

      puVar2 = puVar10;

      do {

        *puVar2 = *puVar3;

        puVar2[1] = puVar3[1];

        puVar2[2] = puVar3[2];

        puVar2[3] = puVar3[3];

        puVar2[4] = puVar3[4];

        puVar2[5] = puVar3[5];

        puVar2[6] = puVar3[6];

        puVar2[7] = puVar3[7];

        puVar2[8] = puVar3[8];

        puVar6 = puVar2 + 0xc;

        puVar2[9] = puVar3[9];

        puVar4 = puVar3 + 0xb;

        puVar2[10] = puVar3[10];

        puVar3 = puVar3 + 0xc;

        puVar2[0xb] = *puVar4;

        puVar2 = puVar6;

      } while (puVar6 < puVar10 + iVar5);

      puVar7 = puVar7 + 2;

    } while (puVar7 < puVar9);

    puVar9 = (int *)(0x0605DE24 + 0x18);

    puVar7 = (int *)0x0605DE24;

    do {

      puVar2 = (char *)*puVar7;

      puVar7 = puVar7 + 1;

      *puVar2 = *puVar3;

      puVar2[1] = puVar3[1];

      puVar2[2] = puVar3[2];

      puVar2[3] = puVar3[3];

      puVar2[4] = puVar3[4];

      puVar2[5] = puVar3[5];

      puVar10 = puVar3 + 7;

      puVar2[6] = puVar3[6];

      puVar3 = puVar3 + 8;

      puVar2[7] = *puVar10;

    } while (puVar7 < puVar9);

    puVar10 = 0x0605DDB4 + 0x20;

    puVar8 = (char *)0x0605DDB4;

    do {

      *puVar8 = *puVar3;

      puVar8[1] = puVar3[1];

      puVar8[2] = puVar3[2];

      puVar8[3] = puVar3[3];

      puVar6 = puVar8 + 8;

      puVar8[4] = puVar3[4];

      puVar8[5] = puVar3[5];

      puVar4 = puVar3 + 7;

      puVar8[6] = puVar3[6];

      puVar3 = puVar3 + 8;

      puVar8[7] = *puVar4;

      puVar8 = puVar6;

    } while (puVar6 < puVar10);

    puVar10 = 0x0605DDD4 + 0x20;

    puVar8 = (char *)0x0605DDD4;

    do {

      *puVar8 = *puVar3;

      puVar8[1] = puVar3[1];

      puVar8[2] = puVar3[2];

      puVar8[3] = puVar3[3];

      puVar6 = puVar8 + 8;

      puVar8[4] = puVar3[4];

      puVar8[5] = puVar3[5];

      puVar4 = puVar3 + 7;

      puVar8[6] = puVar3[6];

      puVar3 = puVar3 + 8;

      puVar8[7] = *puVar4;

      puVar8 = puVar6;

    } while (puVar6 < puVar10);

    puVar10 = 0x0605DE40 + 0x24;

    puVar8 = (char *)0x0605DE40;

    do {

      puVar4 = puVar3;

      *puVar8 = *puVar4;

      puVar8[1] = puVar4[1];

      puVar8[2] = puVar4[2];

      puVar8[3] = puVar4[3];

      puVar8[4] = puVar4[4];

      puVar8[5] = puVar4[5];

      puVar8[6] = puVar4[6];

      puVar8[7] = puVar4[7];

      puVar8[8] = puVar4[8];

      puVar8[9] = puVar4[9];

      puVar6 = puVar8 + 0xc;

      puVar8[10] = puVar4[10];

      puVar8[0xb] = puVar4[0xb];

      puVar1 = (char *)0x0605AD00;

      puVar3 = puVar4 + 0xc;

      puVar8 = puVar6;

    } while (puVar6 < puVar10);

    COURSE_SELECT = puVar4[0xc];

    puVar1[1] = puVar4[0xd];

    puVar1[2] = puVar4[0xe];

    puVar1[3] = puVar4[0xf];

    puVar8 = (char *)0x0605AD04;

    *(int *)0x0605AD04 = puVar4[0x10];

    puVar8[1] = puVar4[0x11];

    puVar8[2] = puVar4[0x12];

    puVar8[3] = puVar4[0x13];

    puVar8 = (char *)0x0605AD0C;

    *(int *)0x0605AD0C = puVar4[0x14];

    puVar8[1] = puVar4[0x15];

    puVar8[2] = puVar4[0x16];

    puVar8[3] = puVar4[0x17];

    *(int *)0x0605AB16 = puVar4[0x18];

    *(int *)0x0605AB17 = puVar4[0x19];

    *(int *)0x0605D240 = puVar4[0x1a];

    *(int *)0x0605D241 = puVar4[0x1b];

    puVar8 = (char *)0x06060D44;

    *(int *)0x06060D44 = puVar4[0x1c];

    puVar8[1] = puVar4[0x1d];

    puVar8 = (char *)0x06060D46;

    *(int *)0x06060D46 = puVar4[0x1e];

    puVar8[1] = puVar4[0x1f];

    puVar8 = (char *)0x06060D40;

    *(int *)0x06060D40 = puVar4[0x20];

    puVar8[1] = puVar4[0x21];

    puVar8 = (char *)0x06060D42;

    *(int *)0x06060D42 = puVar4[0x22];

    puVar8[1] = puVar4[0x23];

    puVar8 = (char *)0x06060D48;

    *(int *)0x06060D48 = puVar4[0x24];

    puVar8[1] = puVar4[0x25];

    puVar8 = (char *)0x06060D4A;

    *(int *)0x06060D4A = puVar4[0x26];

    puVar8[1] = puVar4[0x27];

    puVar8 = (char *)0x06060D4C;

    *(int *)0x06060D4C = puVar4[0x28];

    puVar8[1] = puVar4[0x29];

    puVar8 = (char *)0x06060D4E;

    *(int *)0x06060D4E = puVar4[0x2a];

    puVar8[1] = puVar4[0x2b];

    puVar8 = (char *)0x06060D54;

    *(int *)0x06060D54 = puVar4[0x2c];

    puVar8[1] = puVar4[0x2d];

    puVar8[2] = puVar4[0x2e];

    puVar8[3] = puVar4[0x2f];

    puVar8 = (char *)0x06060D58;

    *(int *)0x06060D58 = puVar4[0x30];

    puVar8[1] = puVar4[0x31];

    puVar8[2] = puVar4[0x32];

    puVar8[3] = puVar4[0x33];

    puVar8 = (char *)0x06060D50;

    *(int *)0x06060D50 = puVar4[0x34];

    puVar8[1] = puVar4[0x35];

    puVar8[2] = puVar4[0x36];

    puVar8[3] = puVar4[0x37];

    puVar8 = (char *)0x06060D60;

    *(int *)0x06060D60 = puVar4[0x38];

    puVar8[1] = puVar4[0x39];

    puVar8 = (char *)0x06060D62;

    *(int *)0x06060D62 = puVar4[0x3a];

    puVar8[1] = puVar4[0x3b];

    puVar3 = 0x06060D5C + 1;

    *(int *)0x06060D5C = puVar4[0x3c];

    *puVar3 = puVar4[0x3d];

    puVar8 = (char *)0x06060D5E;

    *(int *)0x06060D5E = puVar4[0x3e];

    puVar8[1] = puVar4[0x3f];

    puVar8 = (char *)0x06060D64;

    *(int *)0x06060D64 = puVar4[0x40];

    puVar8[1] = puVar4[0x41];

    puVar8 = (char *)0x06060D66;

    *(int *)0x06060D66 = puVar4[0x42];

    puVar8[1] = puVar4[0x43];

    puVar8 = (char *)0x06060D68;

    *(int *)0x06060D68 = puVar4[0x44];

    puVar8[1] = puVar4[0x45];

    puVar8 = (char *)0x06060D6A;

    *(int *)0x06060D6A = puVar4[0x46];

    puVar8[1] = puVar4[0x47];

    puVar8 = (char *)0x06060D70;

    *(int *)0x06060D70 = puVar4[0x48];

    puVar8[1] = puVar4[0x49];

    puVar8[2] = puVar4[0x4a];

    puVar8[3] = puVar4[0x4b];

    puVar8 = (char *)0x06060D74;

    *(int *)0x06060D74 = puVar4[0x4c];

    puVar8[1] = puVar4[0x4d];

    puVar8[2] = puVar4[0x4e];

    puVar8[3] = puVar4[0x4f];

    puVar8 = (char *)0x06060D6C;

    *(int *)0x06060D6C = puVar4[0x50];

    puVar8[1] = puVar4[0x51];

    puVar8[2] = puVar4[0x52];

    puVar8[3] = puVar4[0x53];

  }

  return puVar2;

}

char * FUN_0601efc4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  char *puVar5;

  int *puVar6;

  char *puVar7;

  char *puVar8;

  int *puVar9;

  char *puVar10;

  iVar4 = 0xf0;

  puVar2 = (char *)(unsigned int)(unsigned char)*(int *)0x06087080;

  if (puVar2 == (char *)0x0) {

    puVar3 = (char *)(*(int *)0x0605E098 + 0x10);

    puVar9 = (int *)(0x0605DD6C + 0x48);

    puVar6 = (int *)0x0605DD6C;

    do {

      puVar10 = (char *)*puVar6;

      puVar2 = puVar10;

      do {

        *puVar3 = *puVar2;

        puVar3[1] = puVar2[1];

        puVar3[2] = puVar2[2];

        puVar3[3] = puVar2[3];

        puVar3[4] = puVar2[4];

        puVar3[5] = puVar2[5];

        puVar3[6] = puVar2[6];

        puVar3[7] = puVar2[7];

        puVar5 = puVar2 + 0xc;

        puVar3[8] = puVar2[8];

        puVar3[9] = puVar2[9];

        puVar3[10] = puVar2[10];

        puVar3[0xb] = puVar2[0xb];

        puVar3 = puVar3 + 0xc;

        puVar2 = puVar5;

      } while (puVar5 < puVar10 + iVar4);

      puVar6 = puVar6 + 2;

    } while (puVar6 < puVar9);

    puVar9 = (int *)(0x0605DE24 + 0x18);

    puVar6 = (int *)0x0605DE24;

    do {

      puVar2 = (char *)*puVar6;

      puVar6 = puVar6 + 1;

      *puVar3 = *puVar2;

      puVar3[1] = puVar2[1];

      puVar3[2] = puVar2[2];

      puVar3[3] = puVar2[3];

      puVar3[4] = puVar2[4];

      puVar3[5] = puVar2[5];

      puVar3[6] = puVar2[6];

      puVar3[7] = puVar2[7];

      puVar3 = puVar3 + 8;

    } while (puVar6 < puVar9);

    puVar10 = 0x0605DDB4 + 0x20;

    puVar7 = (int *)0x0605DDB4;

    do {

      *puVar3 = *puVar7;

      puVar3[1] = puVar7[1];

      puVar3[2] = puVar7[2];

      puVar3[3] = puVar7[3];

      puVar5 = puVar7 + 8;

      puVar3[4] = puVar7[4];

      puVar3[5] = puVar7[5];

      puVar3[6] = puVar7[6];

      puVar3[7] = puVar7[7];

      puVar3 = puVar3 + 8;

      puVar7 = puVar5;

    } while (puVar5 < puVar10);

    puVar10 = 0x0605DDD4 + 0x20;

    puVar7 = (int *)0x0605DDD4;

    do {

      *puVar3 = *puVar7;

      puVar3[1] = puVar7[1];

      puVar3[2] = puVar7[2];

      puVar3[3] = puVar7[3];

      puVar5 = puVar7 + 8;

      puVar3[4] = puVar7[4];

      puVar3[5] = puVar7[5];

      puVar3[6] = puVar7[6];

      puVar3[7] = puVar7[7];

      puVar3 = puVar3 + 8;

      puVar7 = puVar5;

    } while (puVar5 < puVar10);

    puVar10 = 0x0605DE40 + 0x24;

    puVar7 = (int *)0x0605DE40;

    do {

      puVar5 = puVar3;

      *puVar5 = *puVar7;

      puVar5[1] = puVar7[1];

      puVar5[2] = puVar7[2];

      puVar5[3] = puVar7[3];

      puVar5[4] = puVar7[4];

      puVar5[5] = puVar7[5];

      puVar5[6] = puVar7[6];

      puVar5[7] = puVar7[7];

      puVar5[8] = puVar7[8];

      puVar5[9] = puVar7[9];

      puVar8 = puVar7 + 0xc;

      puVar5[10] = puVar7[10];

      puVar5[0xb] = puVar7[0xb];

      puVar1 = (char *)0x0605AD00;

      puVar3 = puVar5 + 0xc;

      puVar7 = puVar8;

    } while (puVar8 < puVar10);

    puVar3 = 0x0605AD00 + 1;

    puVar5[0xc] = COURSE_SELECT;

    puVar5[0xd] = *puVar3;

    puVar5[0xe] = puVar1[2];

    puVar5[0xf] = puVar1[3];

    puVar7 = (int *)0x0605AD04;

    puVar3 = 0x0605AD04 + 1;

    puVar5[0x10] = *(int *)0x0605AD04;

    puVar5[0x11] = *puVar3;

    puVar5[0x12] = puVar7[2];

    puVar5[0x13] = puVar7[3];

    puVar7 = (int *)0x0605AD0C;

    puVar3 = 0x0605AD0C + 1;

    puVar5[0x14] = *(int *)0x0605AD0C;

    puVar5[0x15] = *puVar3;

    puVar5[0x16] = puVar7[2];

    puVar5[0x17] = puVar7[3];

    puVar5[0x18] = *(int *)0x0605AB16;

    puVar5[0x19] = *(int *)0x0605AB17;

    puVar5[0x1a] = *(int *)0x0605D240;

    puVar5[0x1b] = *(int *)0x0605D241;

    puVar3 = 0x06060D44 + 1;

    puVar5[0x1c] = *(int *)0x06060D44;

    puVar5[0x1d] = *puVar3;

    puVar3 = 0x06060D46 + 1;

    puVar5[0x1e] = *(int *)0x06060D46;

    puVar5[0x1f] = *puVar3;

    puVar3 = 0x06060D40 + 1;

    puVar5[0x20] = *(int *)0x06060D40;

    puVar5[0x21] = *puVar3;

    puVar3 = 0x06060D42 + 1;

    puVar5[0x22] = *(int *)0x06060D42;

    puVar5[0x23] = *puVar3;

    puVar3 = 0x06060D48 + 1;

    puVar5[0x24] = *(int *)0x06060D48;

    puVar5[0x25] = *puVar3;

    puVar3 = 0x06060D4A + 1;

    puVar5[0x26] = *(int *)0x06060D4A;

    puVar5[0x27] = *puVar3;

    puVar3 = 0x06060D4C + 1;

    puVar5[0x28] = *(int *)0x06060D4C;

    puVar5[0x29] = *puVar3;

    puVar3 = 0x06060D4E + 1;

    puVar5[0x2a] = *(int *)0x06060D4E;

    puVar5[0x2b] = *puVar3;

    puVar7 = (int *)0x06060D54;

    puVar3 = 0x06060D54 + 1;

    puVar5[0x2c] = *(int *)0x06060D54;

    puVar5[0x2d] = *puVar3;

    puVar5[0x2e] = puVar7[2];

    puVar5[0x2f] = puVar7[3];

    puVar7 = (int *)0x06060D58;

    puVar3 = 0x06060D58 + 1;

    puVar5[0x30] = *(int *)0x06060D58;

    puVar5[0x31] = *puVar3;

    puVar5[0x32] = puVar7[2];

    puVar5[0x33] = puVar7[3];

    puVar7 = (int *)0x06060D50;

    puVar3 = 0x06060D50 + 1;

    puVar5[0x34] = *(int *)0x06060D50;

    puVar5[0x35] = *puVar3;

    puVar5[0x36] = puVar7[2];

    puVar5[0x37] = puVar7[3];

    puVar3 = 0x06060D60 + 1;

    puVar5[0x38] = *(int *)0x06060D60;

    puVar5[0x39] = *puVar3;

    puVar3 = 0x06060D62 + 1;

    puVar5[0x3a] = *(int *)0x06060D62;

    puVar5[0x3b] = *puVar3;

    puVar3 = 0x06060D5C + 1;

    puVar5[0x3c] = *(int *)0x06060D5C;

    puVar5[0x3d] = *puVar3;

    puVar3 = 0x06060D5E + 1;

    puVar5[0x3e] = *(int *)0x06060D5E;

    puVar5[0x3f] = *puVar3;

    puVar3 = 0x06060D64 + 1;

    puVar5[0x40] = *(int *)0x06060D64;

    puVar5[0x41] = *puVar3;

    puVar3 = 0x06060D66 + 1;

    puVar5[0x42] = *(int *)0x06060D66;

    puVar5[0x43] = *puVar3;

    puVar3 = 0x06060D68 + 1;

    puVar5[0x44] = *(int *)0x06060D68;

    puVar5[0x45] = *puVar3;

    puVar3 = 0x06060D6A + 1;

    puVar5[0x46] = *(int *)0x06060D6A;

    puVar5[0x47] = *puVar3;

    puVar7 = (int *)0x06060D70;

    puVar3 = 0x06060D70 + 1;

    puVar5[0x48] = *(int *)0x06060D70;

    puVar5[0x49] = *puVar3;

    puVar5[0x4a] = puVar7[2];

    puVar5[0x4b] = puVar7[3];

    puVar7 = (int *)0x06060D74;

    puVar3 = 0x06060D74 + 1;

    puVar5[0x4c] = *(int *)0x06060D74;

    puVar5[0x4d] = *puVar3;

    puVar5[0x4e] = puVar7[2];

    puVar5[0x4f] = puVar7[3];

    puVar7 = (int *)0x06060D6C;

    puVar3 = 0x06060D6C + 1;

    puVar5[0x50] = *(int *)0x06060D6C;

    puVar5[0x51] = *puVar3;

    puVar5[0x52] = puVar7[2];

    puVar5[0x53] = puVar7[3];

  }

  return puVar2;

}

int FUN_0601f40c()
{

  char *puVar1;

  int iVar2;

  puVar1 = (char *)0x060877D8;

  if (((int *)0x060877DD)[(unsigned char)*(int *)0x060877D8] != '\0') {

    FUN_0601efc4();

    iVar2 = FUN_0601e810(((int *)0x060877D9)[(unsigned char)*puVar1],

                         0x0604A57C + (unsigned int)(unsigned char)*puVar1 * 0xc,

                         *(int *)0x0605E098);

    if (iVar2 != 0) {

      *(int *)0x0605E05C = 0xc;

      (*(int(*)())0x0601F8BC)();

      return 0;

    }

  }

  return 0;

}

void FUN_0601f4b4(param_1)
    char *param_1;
{

  unsigned char bVar1;

  unsigned char bVar2;

  unsigned char bVar3;

  unsigned char bVar4;

  int iVar5;

  iVar5 = *(int *)0x060A4C98;

  *(int *)0x060877E4 = iVar5;

  bVar1 = *(unsigned char *)(iVar5 + 1);

  bVar2 = *(unsigned char *)(iVar5 + 2);

  bVar3 = *(unsigned char *)(iVar5 + 3);

  bVar4 = *(unsigned char *)(iVar5 + 4);

  *param_1 = (char)DAT_0601f5c6 +

             (char)((int)(unsigned int)*(unsigned char *)(iVar5 + 5) >> 4) * '\n' + (*(unsigned char *)(iVar5 + 5) & 0xf) +

             (char)((int)(unsigned int)*(unsigned char *)(iVar5 + 6) >> 4) * (char)0x03E8F844 +

             (*(unsigned char *)(iVar5 + 6) & 0xf) * 'd';

  param_1[1] = bVar4 & 0xf;

  param_1[5] = (char)((int)(unsigned int)bVar4 >> 4);

  param_1[2] = (bVar3 & 0xf) + (char)((int)(unsigned int)bVar3 >> 4) * '\n';

  param_1[3] = (bVar2 & 0xf) + (char)((int)(unsigned int)bVar2 >> 4) * '\n';

  param_1[4] = (bVar1 & 0xf) + (char)((int)(unsigned int)bVar1 >> 4) * '\n';

  return;

}

int FUN_0601f5e0()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  puVar1 = (char *)0x0607ED90;

  uVar6 = (unsigned int)DAT_0601f6ba;

  FUN_0601f87a(0);

  (*(int(*)())0x0601E2B4)();

  (*(int(*)())0x0601EB70)();

  (*(int(*)())0x0601F40C)();

  puVar2 = (char *)0x060877F0;

  if (*(int *)0x06078635 == '\0') {

    iVar3 = 0;

  }

  else {

    *(int *)0x060877F0 = puVar1[4];

    puVar2[1] = puVar1[5];

    puVar2[2] = puVar1[6];

    puVar2[3] = puVar1[7];

    if ((*(unsigned int *)0x060786A4 < *(unsigned int *)0x060877F0) ||

       (iVar3 = *(int *)0x060877F0, iVar3 == 0)) {

      *(int *)0x0605E0A1 = 1;

      *(int *)0x0605E0A0 = (char)CAR_COUNT;

      puVar2 = (char *)0x060786A4;

      puVar4 = 0x060786A4 + 1;

      puVar1[4] = *(int *)0x060786A4;

      puVar1[5] = *puVar4;

      puVar1[6] = puVar2[2];

      puVar1[7] = puVar2[3];

      for (uVar5 = *(unsigned int *)0x0607ED88; uVar5 < uVar6; uVar5 = uVar5 + 2) {

        puVar1[uVar5] = 0x40;

        puVar1[uVar5 + 1] = 0x80;

      }

      FUN_0601f87a(CAR_COUNT + 1U & 0xff);

      puVar2 = (char *)0x060877D8;

      puVar1 = (char *)0x0605E06C;

      puVar4 = (char *)0x0;

      if (*(int *)0x06085FFC != 0) {

        puVar4 = *(char **)0x06085FFC;

      }

      if (*(int *)0x06086000 != 0) {

        puVar4 = *(char **)0x06086000;

      }

      if (puVar4 == (char *)0x0) {

        ((int *)0x0605E06C)[(char)(*(int *)0x060877D8 * '\v') + 7] = 0x44;

        puVar1[(char)(*puVar2 * '\v') + 8] = 0x41;

        puVar1[(char)(*puVar2 * '\v') + 9] = 0x59;

      }

      else {

        ((int *)0x0605E06C)[(char)(*(int *)0x060877D8 * '\v') + 7] = *puVar4;

        puVar1[(char)(*puVar2 * '\v') + 8] = puVar4[1];

        puVar1[(char)(*puVar2 * '\v') + 9] = puVar4[2];

      }

      (*(int(*)())0x0601E2B4)();

      iVar3 = (*(int(*)())0x0601EB1C)();

      return iVar3;

    }

  }

  return iVar3;

}

unsigned int FUN_0601f784()
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  puVar2 = (char *)0x0607EAD8;

  puVar1 = (char *)0x0607ED90;

  uVar5 = (unsigned int)DAT_0601f804;

  uVar3 = 0;

  if (*(int *)0x06078635 != '\0') {

    FUN_0601f87a(CAR_COUNT + 1U & 0xff);

    (*(int(*)())0x0601E2B4)();

    uVar3 = (*(int(*)())0x0601EAA0)();

    uVar3 = uVar3 & 0xff;

    if ((uVar3 == 0) &&

       ((*(int *)0x0605E0A1 == '\0' || ((unsigned int)(unsigned char)*(int *)0x0605E0A0 != CAR_COUNT)))

       ) {

      if (*(int *)puVar2 == 0) {

        uVar3 = (*(int(*)())0x06027630)(puVar1,0x002F8000,(int)DAT_0601f806);

      }

      else if (*(int *)puVar2 == 1) {

        uVar3 = (*(int(*)())0x06027630)(puVar1,0x002F8000,(int)PTR_DAT_0601f808);

      }

      else {

        uVar3 = *(unsigned int *)puVar2;

        if (uVar3 == 2) {

          uVar3 = (*(int(*)())0x06027630)(puVar1,0x002F8000,uVar5);

        }

      }

    }

    for (uVar4 = *(unsigned int *)(0x0604A5C0 + (unsigned int)(unsigned char)*(int *)(0x060877D8 << 2)); uVar4 < uVar5;

        uVar4 = uVar4 + 2) {

      uVar3 = uVar4 + 1;

      puVar1[uVar4] = 0x40;

      puVar1[uVar3] = 0x80;

    }

    *(int *)0x0605E0A1 = 0;

  }

  return uVar3;

}

void FUN_0601f87a(param_1)
    unsigned char param_1;
{
  char *puVar1;

  *(unsigned char *)0x060877D8 = param_1;

  puVar1 = (char *)0x06087080;

  if (param_1 == '\0') {

    *(char **)0x0605E098 = 0x060A0FA8;

    *puVar1 = 0;

  }

  else {

    *(char **)0x0605E098 = 0x0607ED90;

    *puVar1 = 1;

  }

  return;

}

void FUN_0601f8bc()
{

  return;

}

/* mode_transition_check -- Check if mode transition is complete.
 * Clears transition flag, runs transition step (FUN_0601f5e0).
 * If flag still clear after step, transition still in progress (return 1).
 * Otherwise, finalize: init render, apply transition, commit. Return 0. */
int FUN_0601f8c0(void)
{
    *(int *)0x0605E05C = 0;
    FUN_0601f5e0();

    if (*(int *)0x0605E05C == '\0') {
        return 1;  /* transition still in progress */
    }

    (*(int(*)())0x060149E0)();  /* render init */
    FUN_0601f9cc();             /* apply transition */
    (*(int(*)())0x060149CC)();  /* commit */
    return 0;                   /* transition complete */
}

int FUN_0601f900()
{

  short local_8 [4];

  if ((*(unsigned short *)0x06063D9A & DAT_0601f962) != 0) {

    local_8[0] = DAT_0601f964;

    (*(int(*)())0x06036E90)(0x25E7FFFE,1,local_8);

    return 1;

  }

  FUN_0601fd20();

  return 0;

}

void FUN_0601f9cc()
{

  short sVar1;

  char cVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  int uVar8;

  int uVar9;

  int iVar10;

  int *puVar11;

  int iVar12;

  int *local_28;

  short auStack_24 [4];

  auStack_24[0] = DAT_0601fa26;

  (*(int(*)())0x0602853E)(0xc);

  (*(int(*)())0x06028560)();

  puVar4 = (char *)0x06028400;

  puVar3 = (char *)0x06063750;

  if (*(int *)0x06078644 == 1) {

    (*(int(*)())0x0600511E)(0x25E72194,0x00017700,0,8);

    (*(int(*)())0x0602761E)(0x25F00600,0x0604894C,0x20);

    cVar2 = *(int *)0x0605E05C;

    if (cVar2 == '\x04') {

      local_28 = (int *)(puVar3 + PTR_DAT_0601fa28);

      uVar8 = local_28[1];

      iVar7 = 0;

    }

    else {

      if (cVar2 != '\b') {

        if (cVar2 == '\f') {

          (*(int(*)())puVar4)(0xc,*(int *)(puVar3 + DAT_0601fac8),0x400,

                            *(int *)((int)(puVar3 + DAT_0601fac8) + 4));

        }

        goto LAB_0601fcd4;

      }

      local_28 = (int *)(puVar3 + DAT_0601fac4);

      uVar8 = local_28[1];

      iVar7 = 0x380;

    }

    (*(int(*)())puVar4)(0xc,*local_28,iVar7,uVar8);

  }

  else {

    (*(int(*)())0x0602761E)(0x25F00600,0x0605CD9C,0x20);

    puVar6 = (int *)0x0605E0A4;

    puVar5 = (char *)0x060284AE;

    iVar7 = 0x590;

    iVar10 = iVar7 + 8;

    iVar12 = 0x90;

    cVar2 = *(int *)0x0605E05C;

    if (cVar2 == '\x04') {

      (*(int(*)())0x060284AE)(0xc,0x80,iVar12,*(int *)0x0605E0A4);

      (*(int(*)())puVar4)(0xc,*(int *)(puVar3 + iVar10),0x98,

                        *(int *)((int)(puVar3 + iVar10) + 4));

      (*(int(*)())puVar5)(0xc,0x180,iVar12,*(int *)(puVar6 + 4));

      (*(int(*)())puVar5)(0xc,0x280,iVar12,*(int *)(puVar6 + 8));

      puVar11 = (int *)(puVar3 + iVar7);

      (*(int(*)())puVar4)(0xc,*puVar11,(int)DAT_0601fbae,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x400,iVar12,*(int *)(puVar6 + 0xc));

      (*(int(*)())puVar5)(0xc,0x500,iVar12,*(int *)(puVar6 + 0x10));

      (*(int(*)())puVar4)(0xc,*puVar11,(int)DAT_0601fbb4,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x600,iVar12,*(int *)(puVar6 + 0x14));

      (*(int(*)())puVar5)(0xc,0x700,iVar12,*(int *)(puVar6 + 0x18));

      (*(int(*)())puVar4)(0xc,*puVar11,0x730,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x800,iVar12,*(int *)(puVar6 + 0x1c));

      (*(int(*)())puVar5)(0xc,0x900,iVar12,*(int *)(puVar6 + 0x20));

      (*(int(*)())puVar5)(0xc,0xa00,iVar12,*(int *)(puVar6 + 0x24));

      (*(int(*)())puVar5)(0xc,0xb00,iVar12,*(int *)(puVar6 + 0x28));

      (*(int(*)())puVar4)(0xc,*puVar11,(int)DAT_0601fbc4,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0xc80,iVar12,*(int *)0x0605E0E4);

      uVar9 = puVar11[1];

      uVar8 = *puVar11;

      sVar1 = DAT_0601fbc8;

    }

    else {

      if (cVar2 != '\b') {

        if (cVar2 == '\f') {

          (*(int(*)())0x060284AE)(0xc,0x480,iVar12,*(int *)0x0605E0DC);

          (*(int(*)())puVar4)(0xc,*(int *)(puVar3 + iVar10),0x498,

                            *(int *)((int)(puVar3 + iVar10) + 4));

          (*(int(*)())puVar5)(0xc,0x600,iVar12,*(int *)0x0605E0E0);

          puVar11 = (int *)(puVar3 + iVar7);

          (*(int(*)())puVar4)(0xc,*puVar11,0x620,puVar11[1]);

          (*(int(*)())puVar5)(0xc,0x800,iVar12,*(int *)0x0605E0E4);

          (*(int(*)())puVar4)(0xc,*puVar11,0x852,puVar11[1]);

        }

        goto LAB_0601fcd4;

      }

      (*(int(*)())0x060284AE)(0xc,0x380,iVar12,*(int *)0x0605E0D0);

      (*(int(*)())puVar4)(0xc,*(int *)(puVar3 + iVar10),0x398,

                        *(int *)((int)(puVar3 + iVar10) + 4));

      (*(int(*)())puVar5)(0xc,0x500,iVar12,*(int *)0x0605E0D4);

      puVar11 = (int *)(puVar3 + iVar7);

      (*(int(*)())puVar4)(0xc,*puVar11,(int)DAT_0601fc94,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x680,iVar12,*(int *)0x0605E0D8);

      (*(int(*)())puVar4)(0xc,*puVar11,0x6b2,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x880,iVar12,*(int *)0x0605E0E4);

      uVar9 = puVar11[1];

      uVar8 = *puVar11;

      sVar1 = DAT_0601fc9c;

    }

    (*(int(*)())puVar4)(0xc,uVar8,(int)sVar1,uVar9);

  }

LAB_0601fcd4:

  puVar3 = (char *)0x06038BD4;

  (*(int(*)())0x06038BD4)(0x100,0);

  (*(int(*)())puVar3)(4,0);

  (*(int(*)())puVar3)(8,0);

  (*(int(*)())puVar3)(0x10,0);

  (*(int(*)())puVar3)(0x20,7);

  (*(int(*)())puVar3)(1,0);

  (*(int(*)())0x06036E90)(0x25E7FFFE,1,auStack_24);

  (*(int(*)())puVar3)(0x20,7);

  return;

}

/* mode_transition_vdp_reset -- Reset VDP state for mode transition.
 * Forces right-direction input, reinits VDP1 textures/palette,
 * clears render state and command buffer. */
void FUN_0601fd20(void)
{
    INPUT_STATE |= 4;
    vdp1_texture_palette_init();
    *(int *)0x060620D0 = 0;
    *(int *)0x0605A000 = 0;
    *(int *)0x0605A004 = 0;
    VDP1_CMD_BASE_PTR = 0;
    VBLANK_OUT_COUNTER = 0;
}

/* mode_dispatch_cd -- Read CD status, then dispatch via mode handler vtable.
 * Vtable index stored at 0x06087804. */
int FUN_0601fd74(void)
{
    int auStack_14[5];
    (*(int(*)())0x06035168)();  /* cd_get_status */
    return (*(int(*)())auStack_14[*(int *)0x06087804])();
}

void FUN_0601fe20()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  unsigned int uVar7;

  puVar3 = (char *)0x0607EA98;

  puVar2 = (char *)0x06078900;

  puVar1 = (char *)0x0607E940;

  iVar4 = 0x268;

  piVar6 = *(int **)0x060877F4;

  *(int *)0x060877FC = piVar6[1];

  *(int *)puVar3 = *piVar6 + -1;

  (*(int(*)())0x060054EA)(piVar6[2]);

  iVar5 = piVar6[3];

  *(short *)0x06087800 = 0;

  *(short *)0x06087802 = 0;

  for (uVar7 = 0; uVar7 <= *(unsigned int *)puVar3; uVar7 = uVar7 + 1) {

    *(char **)puVar1 = puVar2 + uVar7 * iVar4;

    FUN_0601fec0(iVar5);

    iVar5 = iVar5 + 8;

  }

  (*(int(*)())0x0600D280)();

  *(short *)0x06087804 = 2;

  return;

}

void FUN_0601fec0(param_1)
    unsigned short *param_1;
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  int iVar5;

  int iVar6;

  puVar2 = (char *)0x06078680;

  iVar3 = (int)DAT_0601ff8a;

  iVar6 = CAR_PTR_CURRENT;

  iVar5 = (int)(unsigned int)*param_1 >> 1;

  *(int *)(iVar6 + iVar3) = iVar5;

  *(int *)(iVar6 + iVar3 + 4) = iVar5;

  *(int *)(iVar6 + iVar3 + -4) = iVar5;

  *(int *)(iVar6 + iVar3 + -8) = iVar5;

  uVar1 = param_1[1];

  *(unsigned int *)(iVar6 + 8) = (unsigned int)uVar1;

  uVar4 = (*(int(*)())0x06027552)(0x35a,(unsigned int)uVar1 << 0x10);

  *(int *)(iVar6 + 0xc) = uVar4;

  *(int *)(iVar6 + DAT_0601ff8e) = uVar4;

  uVar1 = param_1[2];

  iVar3 = (int)DAT_0601ff90;

  *(unsigned int *)(iVar6 + iVar3) = (unsigned int)uVar1;

  *(unsigned int *)(iVar6 + iVar3 + -4) = (unsigned int)uVar1;

  (*(int(*)())0x0600CB90)(puVar2,*param_1);

  *(int *)(iVar6 + 0x10) = *(int *)puVar2;

  *(int *)(iVar6 + 0x14) = *(int *)(puVar2 + 4);

  *(int *)(iVar6 + 0x18) = *(int *)(puVar2 + 8);

  *(int *)(iVar6 + 0x1c) = (int)*(short *)(puVar2 + 0xc);

  *(int *)(iVar6 + 0x20) = (int)*(short *)(puVar2 + 0xe);

  *(int *)(iVar6 + 0x24) = (int)*(short *)(puVar2 + 0x10);

  *(int *)(iVar6 + 0x30) = *(int *)(iVar6 + 0x20);

  *(int *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x20);

  iVar3 = 0x1b0;

  *(int *)(iVar6 + iVar3) = *(int *)(iVar6 + 0x20);

  *(int *)(iVar6 + iVar3 + -0xc) = *(int *)(iVar6 + 0x1c);

  *(int *)(iVar6 + iVar3 + -8) = *(int *)(iVar6 + 0x20);

  *(int *)(iVar6 + iVar3 + -4) = *(int *)(iVar6 + 0x24);

  iVar3 = iVar3 + 0x3c;

  *(int *)(iVar6 + iVar3) = *(int *)(iVar6 + iVar3) + 1;

  if (*(int *)0x0607EA9C < *(int *)(iVar6 + iVar3)) {

    *(int *)(iVar6 + DAT_0601ff8a) = *(int *)(iVar6 + DAT_0601ff8a) - *(int *)0x0607EA9C;

  }

  *(int *)(iVar6 + DAT_0601ff8a + -8) = *(int *)(iVar6 + DAT_0601ff8a);

  return;

}

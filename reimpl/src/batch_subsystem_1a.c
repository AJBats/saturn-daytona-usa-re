#include "game.h"

extern int DAT_0601a6dc;
extern int DAT_0601a6de;
extern int DAT_0601a6e0;
extern int DAT_0601a6e2;
extern int DAT_0601a756;
extern int DAT_0601a758;
extern int DAT_0601a75a;
extern int DAT_0601a872;
extern int DAT_0601a926;
extern int DAT_0601a928;
extern int DAT_0601a92a;
extern int DAT_0601a9a4;
extern int DAT_0601aa3a;
extern int DAT_0601aac2;
extern int DAT_0601ae3e;
extern int DAT_0601b0c6;
extern int DAT_0601b246;
extern int DAT_0601b248;
extern int DAT_0601b24a;
extern int DAT_0601b24c;
extern int DAT_0601b24e;
extern int DAT_0601b250;
extern int DAT_0601b252;
extern int DAT_0601b254;
extern int DAT_0601b256;
extern int DAT_0601b258;
extern int DAT_0601b25a;
extern int DAT_0601b25c;
extern int DAT_0601b25e;
extern int DAT_0601b260;
extern int DAT_0601b262;
extern int DAT_0601b38a;
extern int DAT_0601b38c;
extern int DAT_0601b38e;
extern int DAT_0601b390;
extern int DAT_0601b392;
extern int DAT_0601b45a;
extern int DAT_0601b76c;
extern int DAT_0601b76e;
extern int DAT_0601b87e;
extern int DAT_0601b946;
extern int DAT_0601bb3a;
extern int DAT_0601bb3c;
extern int DAT_0601bb3e;
extern int DAT_0601bb40;
extern int DAT_0601bb42;
extern int DAT_0601bb44;
extern int DAT_0601bb46;
extern int DAT_0601bb48;
extern int DAT_0601bb4a;
extern int DAT_0601bbc0;
extern int DAT_0601bbc2;
extern int DAT_0601bcba;
extern char * FUN_0601adb0();
extern unsigned int FUN_0601ae2c();
extern int FUN_0601bbcc();
extern int PTR_DAT_0601a4a8;
extern int PTR_DAT_0601a608;
extern int PTR_DAT_0601a75c;
extern int PTR_DAT_0601ace4;
extern int PTR_DAT_0601b0c8;
extern int PTR_DAT_0601b264;
extern int PTR_DAT_0601b394;

void FUN_0601a3f4(param_1, param_2)
    unsigned short param_1;
    unsigned int param_2;
{

  unsigned char bVar1;

  char *puVar2;

  char *puVar3;

  unsigned char *pbVar4;

  char *puVar5;

  int iVar6;

  unsigned char bVar7;

  puVar3 = (char *)0x06049E54;

  puVar2 = (char *)0x060283E0;

  puVar5 = (int *)0x06049B36;

  if ((param_2 & 0xffff) == 0xa8) {

    bVar1 = ((int *)0x06049CD4)[param_1];

    if ((param_1 == 1) || (param_1 == 4)) {

      iVar6 = 2;

    }

    else {

      iVar6 = 3;

    }

    pbVar4 = 0x06049CCC + param_1;

    for (bVar7 = 0; bVar7 < *pbVar4; bVar7 = bVar7 + 1) {

      (*(int(*)())puVar2)(iVar6 << 2,

                        ((unsigned int)(unsigned char)((char *)(0x06049C28 + ((unsigned int)bVar1 + (unsigned int)bVar7) << 1))[1] * 0x40

                        + (unsigned int)(unsigned char)((int *)0x06049C28)[((unsigned int)bVar1 + (unsigned int)bVar7) << 1]) << 1,0,

                        puVar3);

    }

    pbVar4 = 0x06059084 + (unsigned int)(param_1 << 1);

    puVar5 = (int *)0x06049E58;

  }

  else {

    bVar1 = ((int *)0x06049C1E)[param_1];

    if ((param_1 == 5) || (param_1 == 8)) {

      iVar6 = 2;

    }

    else {

      iVar6 = 3;

    }

    pbVar4 = 0x06049C14 + param_1;

    for (bVar7 = 0; bVar7 < *pbVar4; bVar7 = bVar7 + 1) {

      (*(int(*)())puVar2)(iVar6 << 2,

                        ((unsigned int)(unsigned char)(puVar5 + (((unsigned int)bVar1 + (unsigned int)bVar7) << 1))[1] * 0x40 +

                        (unsigned int)(unsigned char)puVar5[((unsigned int)bVar1 + (unsigned int)bVar7) << 1]) << 1,0,puVar3);

    }

    pbVar4 = 0x06059060 + (unsigned int)(param_1 << 1);

    puVar5 = (int *)0x06049E58;

  }

  (*(int(*)())0x060284AE)(iVar6 << 2,((unsigned int)pbVar4[1] * 0x40 + (unsigned int)*pbVar4) << 1,0x60,puVar5);

  return;

}

/* get_sound_bank_index -- Return sound bank index based on game mode.
 * Mode 0x10 (16 = VS mode) uses bank 0xA8, all others use 0xA9. */
int FUN_0601a5f8(void)
{
    if (*(int *)0x06063D9E == 0x10) {
        return 0xA8;
    }
    return 0xA9;
}

void FUN_0601a65e()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int *local_18;

  if (*(int *)0x06085FF0 == '\x03') {

    iVar3 = 3;

    if ((unsigned char)*(int *)0x0605D242 < 8) {

      iVar4 = 6;

    }

    else {

      iVar4 = 7;

      if (0x10 < (unsigned char)*(int *)0x0605D242) {

        *(int *)0x0605D242 = 0;

      }

    }

  }

  else {

    iVar4 = 6;

    iVar3 = 5;

  }

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06063750;

  if (*(int *)0x0605D241 == '\0') {

    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_0601a6de),(int)DAT_0601a6e0,

               (iVar4 << 12) + *(int *)((int)(0x06063750 + DAT_0601a6de) + 4));

    local_18 = (int *)(puVar1 + DAT_0601a6e2);

    iVar3 = (iVar3 << 12) + local_18[1];

  }

  else {

    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_0601a756),(int)DAT_0601a758,

               (iVar3 << 12) + *(int *)((int)(0x06063750 + DAT_0601a756) + 4));

    local_18 = (int *)(puVar1 + DAT_0601a75a);

    iVar3 = (iVar4 << 12) + local_18[1];

  }

  (*(int(*)())puVar2)(0xc,*local_18,(int)PTR_DAT_0601a75c,iVar3);

  return;

}

void FUN_0601a73e()
{

  if (*(int *)0x0605D241 == '\0') {

    (*(int(*)())0x0601D5F4)(0xf,0xAE0006FF);

    return;

  }

  (*(int(*)())0x0601D5F4)(0xf,0xAE0007FF);

  return;

}

void FUN_0601a80c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int in_r7 = 0;

  puVar3 = (char *)0x0605D243;

  puVar2 = (char *)0x0605D248;

  puVar1 = (char *)0x06063D98;

  if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) == 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601a872) == 0) {

      if (((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) == 0) {

        if (((*(unsigned short *)0x06063D98 & DAT_0601a872) != 0) && (*(int *)0x0605D243 == '\x14')) {

          *(int *)0x0605D248 = *(int *)0x0605D248 + -1;

          *puVar3 = 0;

        }

      }

      else if (*(int *)0x0605D243 == '\x14') {

        *(int *)0x0605D248 = *(int *)0x0605D248 + 1;

        *puVar3 = 0;

      }

    }

    else {

      *(int *)0x0605D248 = *(int *)0x0605D248 + -1;

      *puVar3 = 0;

    }

  }

  else {

    *(int *)0x0605D248 = *(int *)0x0605D248 + 1;

    *puVar3 = 0;

  }

  if ((*(unsigned short *)(puVar1 + 2) & 0xf8) != 0) {

    *(int *)puVar2 = 0;

  }

  if (0x14 < *(int *)puVar2) {

    *(int *)puVar2 = 0;

  }

  if (*(int *)puVar2 < 0) {

    *(int *)puVar2 = (char *)0x14;

  }

  if ((*(unsigned short *)(puVar1 + 2) & DAT_0601a926) != 0) {

    iVar4 = *(int *)puVar2 + 2;

    (*(int(*)())0x06018DDC)(iVar4,iVar4,0,in_r7,iVar4);

  }

  puVar1 = (char *)0x060283E0;

  (*(int(*)())0x060283E0)(0xc,(int)DAT_0601a928,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a92a,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a928,0x0000E000,

                    *(int *)(0x0605D2B4 + *(int *)((int)(int)puVar2 << 3)));

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a92a,0x0000E000,

                    *(int *)(0x0605D2B4 + (*(int *)((int)(int)puVar2 << 1) + 1) << 2));

  return;

}

void FUN_0601a940()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  puVar3 = (char *)0x0605D243;

  puVar2 = (char *)0x0605D24C;

  puVar1 = (char *)0x06063D98;

  if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) == 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601a9a4) == 0) {

      if (((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) == 0) {

        if (((*(unsigned short *)0x06063D98 & DAT_0601a9a4) != 0) && (*(int *)0x0605D243 == '\x14')) {

          *(int *)0x0605D24C = *(int *)0x0605D24C + -1;

          *puVar3 = 0;

        }

      }

      else if (*(int *)0x0605D243 == '\x14') {

        *(int *)0x0605D24C = *(int *)0x0605D24C + '\x01';

        *puVar3 = 0;

      }

    }

    else {

      *(int *)0x0605D24C = *(int *)0x0605D24C + -1;

      *puVar3 = 0;

    }

  }

  else {

    *(int *)0x0605D24C = *(int *)0x0605D24C + '\x01';

    *puVar3 = 0;

  }

  if ('1' < (char)*puVar2) {

    *puVar2 = 0;

  }

  if ((char)*puVar2 < '\0') {

    *puVar2 = (char *)0x31;

  }

  if ((*(unsigned short *)(puVar1 + 2) & 0xf8) != 0) {

    *puVar2 = 0;

  }

  if ((*(unsigned short *)(puVar1 + 2) & DAT_0601aa3a) != 0) {

    if (*(int *)0x06085FF6 != '\0') {

      (*(int(*)())0x06012EC4)();

      (*(int(*)())0x06012F00)();

      *(int *)0x06085FF6 = 0;

    }

    puVar1 = (char *)0x06085FF7;

    if ((char)*puVar2 < '$') {

      if (*(int *)0x06085FF7 != '\0') {

        (*(int(*)())0x060191E0)();

        *puVar1 = 0;

      }

    }

    else if (*(int *)0x06085FF7 != '\x01') {

      (*(int(*)())0x06019248)();

      *puVar1 = 1;

    }

    (*(int(*)())0x0601D5F4)(0,0xAE0001FF);

    (*(int(*)())0x0601D5F4)(0,*(int *)(0x06049CFC + (char)(*puVar2 << 2)));

  }

  puVar1 = (char *)0x060283E0;

  (*(int(*)())0x060283E0)(0xc,(int)DAT_0601aac2,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)0x091CFFFF,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)0x091CFFFF,0x0000E000,

                    *(int *)(0x0605D35C + (char)(*puVar2 << 3)));

  (*(int(*)())puVar1)(0xc,(int)DAT_0601aac2,0x0000E000,

                    *(int *)(0x0605D35C + (char)(*puVar2 << 3) + 4));

  return;

}

void FUN_0601ab8c()
{

  char *puVar1;

  

  puVar1 = (char *)0x0607EAD8;

  *(int *)0x06086004 =

       *(int *)

        (0x0605DE40 +

        (COURSE_SELECT << 2) + (int)(char)((char)CAR_COUNT * '\f'));

  *(int *)0x06086008 =

       *(int *)

        (*(int *)(0x0605DE24 + ((*(int *)(int)puVar1 << 1) + DEMO_MODE_FLAG) << 2) + 4);

  return;

}

int FUN_0601abc6()
{

  int iVar1;

  *(int *)0x06085FF8 = 0;

  *(int *)0x06085FF9 = 0;

  *(int *)0x06085FFC = 0;

  *(int *)0x06086000 = 0;

  FUN_0601adb0();

  if ((*(int *)0x06078638 <

       *(int *)(*(int *)(0x0605DE24 + *(int *)(0x0607EAD8 << 3)) + 4)) &&

     (0 < *(int *)0x06078638)) {

    *(int *)0x06085FF9 = 1;

  }

  if (*(int *)0x0607EBF4 == 0) {

    return 0;

  }

  iVar1 = 0xe8;

  if (*(unsigned int *)0x060786A4 <

      *(unsigned int *)(*(int *)(0x0605DD6C +

                        (CAR_COUNT * 6 + *(int *)(0x0605AD00 << 1)) << 2) + iVar1))

  {

    *(int *)0x06085FF8 = 1;

  }

  return iVar1;

}

unsigned int FUN_0601ac7c()
{

  char *puVar1;

  unsigned int uVar2;

  char uVar3;

  int iVar4;

  int iVar5;

  char *puVar6;

  unsigned char bVar7;

  puVar1 = (char *)0x060786A4;

  iVar4 = *(int *)(0x0605DD6C +

                  (CAR_COUNT * 6 + *(int *)(0x0605AD00 << 1)) << 2);

  iVar5 = *(int *)(0x0605DE24 + *(int *)(0x0607EAD8 << 3));

  uVar2 = (unsigned int)PTR_DAT_0601ace4;

  bVar7 = 0x13;

  if ((*(unsigned int *)0x060786A4 < *(unsigned int *)(iVar4 + uVar2)) &&

     (uVar2 = 0, *(int *)0x0607EBF4 != 0)) {

    do {

      if (*(unsigned int *)((bVar7 - 1) * 0xc + iVar4 + 4) <= *(unsigned int *)puVar1) break;

      (*(int(*)())0x06035168)();

      bVar7 = bVar7 - 1;

    } while (bVar7 != 0);

    puVar6 = (char *)((unsigned int)bVar7 * 0xc + iVar4);

    *(int *)(puVar6 + 4) = *(int *)puVar1;

    uVar3 = FUN_0601ae2c();

    puVar6[8] = uVar3;

    puVar6[9] = *(int *)0x0605DE3C;

    uVar2 = DEMO_MODE_FLAG & 0xff;

    puVar6[10] = (char)DEMO_MODE_FLAG;

    *puVar6 = 0;

    *(char **)0x06085FFC = puVar6;

    *(int *)0x06086012 = bVar7;

  }

  else {

    *(int *)0x06085FFC = 0;

  }

  puVar1 = (char *)0x06086000;

  if ((*(int *)0x06078638 < *(int *)(iVar5 + 4)) && (0 < *(int *)0x06078638)) {

    *(int *)(iVar5 + 4) = *(int *)0x06078638;

    *(int *)puVar1 = iVar5;

  }

  else {

    *(int *)0x06086000 = 0;

  }

  return uVar2;

}

char * FUN_0601adb0()
{

  char *puVar1;

  char *puVar2;

  puVar1 = (char *)0x0607EAD8;

  puVar2 = (char *)0x0;

  if (DEMO_MODE_FLAG != 0) {

    if ((*(int *)0x06078638 <

         *(int *)(*(int *)(0x0605DE24 +

                          (*(int *)(0x0607EAD8 << 1) + DEMO_MODE_FLAG) << 2) + 4)) &&

       (0 < *(int *)0x06078638)) {

      *(int *)

       (*(int *)(0x0605DE24 + (*(int *)(0x0607EAD8 << 1) + DEMO_MODE_FLAG) << 2) +

       4) = *(int *)(0x06078900 + DAT_0601ae3e);

    }

    puVar2 = 0x0605DE40 + (char)((char)*(int *)puVar1 * '\f');

    if ((*(unsigned int *)0x060786A4 < *(unsigned int *)(puVar2 + *(int *)(0x0605AD00 << 2))) &&

       (puVar2 = (char *)0x0, *(int *)0x0607EBF4 != 0)) {

      puVar2 = 0x0605DE40 + (char)((char)*(int *)puVar1 * '\f');

      *(int *)(puVar2 + *(int *)(0x0605AD00 << 2)) = *(int *)0x060786A4;

    }

  }

  return puVar2;

}

unsigned int FUN_0601ae2c()
{

  unsigned int uVar1;

  if (*(int *)0x06083255 == '\0') {

    uVar1 = *(unsigned int *)0x06078868;

  }

  else {

    uVar1 = (*(unsigned int *)0x0607EAB8 & 0xff) + 10;

  }

  uVar1 = uVar1 & 0xff;

  if (*(int *)0x06078663 != '\0') {

    uVar1 = uVar1 + 0xc;

  }

  return uVar1;

}

/* display_mode_init -- Initialize display subsystem state and load VDP2 scroll data.
 * Resets mode counters, then DMA-copies 3 scroll plane data blocks to VRAM:
 *   VDP2 color RAM (0x25F006C0), scroll plane A (0x25F00180), pattern (0x25F00000). */
void FUN_0601ae80(void)
{
    register int dma_func asm("r3") = 0x0602761E;

    *(int *)0x06086010 = 0;
    *(int *)0x0608600F = 0x28;
    *(int *)0x06086011 = 0;

    (*(int(*)())dma_func)(0x25F006C0, 0x0604866C, 0x60);      /* color RAM */
    (*(int(*)())dma_func)(0x25F00180, 0x060485CC, 0x20);       /* scroll plane A */
    (*(void(*)())0x0602766C)(0x25F00000, 0x0604996C, 0x180);   /* pattern data */
}

/* display_mode_dispatch -- Call handler from display mode vtable.
 * Reads mode index from 0x06086011, looks up function pointer in
 * table at 0x0605DEC8, and calls it. */
void FUN_0601aeb6(void)
{
    (*(int(*)())(*(int *)(0x0605DEC8 + (unsigned int)(unsigned char)*(int *)(0x06086011 << 2))))();
}

/* display_region_setup -- Configure display region (320x224 @ offset 48,48).
 * Calls VDP2 display region function with standard NTSC parameters:
 *   x=0, y=0x30, w=0x30, h=0, x2=0x160, y2=0x100, w2=0x160, h2=0x100 */
int FUN_0601b074(void)
{
    return (*(int(*)())0x06039100)(0, 0x30, 0x30, 0, 0x160, 0x100, 0x160, 0x100);
}

void FUN_0601b09a(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  FUN_0601bbcc(*(int *)

                (0x0605DD6C + (param_1 * 6 + (param_2 << 1) + (unsigned int)(unsigned char)*(int *)0x0605D4F7) << 2)

               ,(int)param_3,6);

  return;

}

void FUN_0601b0d8()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned short uVar5;

  unsigned int uVar6;

  puVar3 = (char *)0x060284AE;

  puVar2 = (char *)0x0604A4B8;

  puVar1 = (char *)0x0604A490;

  uVar5 = 0;

  uVar6 = 0;

  do {

    iVar4 = ((uVar6 & 0xffff) + 6) << 6;

    (*(int(*)())puVar3)(8,(iVar4 + 2) << 1,0x60,puVar1);

    (*(int(*)())puVar3)(8,(((uVar6 & 0xffff) + 7) << 6 + 0x21) << 1,0x60,puVar2);

    (*(int(*)())puVar3)(0xc,(iVar4 + 0x25) << 1,0x60,puVar2);

    uVar5 = uVar5 + 1;

    uVar6 = uVar6 + 3;

  } while (uVar5 < 5);

  return;

}

void FUN_0601b160()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  *(int *)0x0606A4F4 = 0;

  *(int *)0x0606A4EC = (int)DAT_0601b246;

  (*(int(*)())0x06039250)(0x06063F5C);

  (*(int(*)())0x060393FC)(0,0,0,(int)DAT_0601b24a,(int)DAT_0601b248);

  VDP1_CMD_BASE_PTR = 0;

  **(short **)0x06063F5C = (short)0x00008000;

  (*(int(*)())0x06012E00)();

  puVar1 = (char *)0x002A0000;

  (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)0x06063F5C,0x002A0000,

             0x640);

  puVar2 = (char *)0x06007658;

  iVar8 = 0x101;

  iVar10 = 0xb40;

  iVar4 = 0x4b46;

  (*(int(*)())0x06007658)(iVar8,iVar10,0x78);

  iVar9 = (int)DAT_0601b254;

  iVar5 = (int)DAT_0601b256;

  (*(int(*)())puVar2)(iVar9,iVar10,0x7c);

  iVar7 = 0x103;

  iVar6 = (int)DAT_0601b25a;

  (*(int(*)())puVar2)(iVar7,iVar10,0x80);

  puVar3 = (char *)0x06007540;

  (*(int(*)())0x06007540)((int)DAT_0601b260,iVar8,(int)DAT_0601b25e);

  (*(int(*)())puVar3)(DAT_0601b262 + 0x7d,iVar9);

  (*(int(*)())puVar3)(PTR_DAT_0601b264 + 0x7a,iVar7);

  (*(int(*)())puVar2)(iVar8,iVar10,0x78,puVar1 + iVar4);

  (*(int(*)())puVar2)(iVar9,iVar10,0x7c,puVar1 + iVar5);

  (*(int(*)())puVar2)(iVar7,iVar10,0x80,puVar1 + iVar6);

  (*(int(*)())puVar3)((int)DAT_0601b260,iVar8,(int)DAT_0601b25e);

  (*(int(*)())puVar3)(DAT_0601b262 + 0x7d,iVar9);

  (*(int(*)())puVar3)(DAT_0601b38a + 0x7a,iVar7);

  (*(int(*)())puVar2)(iVar8,iVar10,0x78,puVar1 + iVar4);

  (*(int(*)())puVar2)(iVar9,iVar10,0x7c,puVar1 + iVar5);

  (*(int(*)())puVar2)(iVar7,iVar10,(int)DAT_0601b38c,puVar1 + iVar6);

  (*(int(*)())puVar3)((int)DAT_0601b390,iVar8,(int)DAT_0601b38e);

  (*(int(*)())puVar3)(DAT_0601b392 + 0x7d,iVar9);

  (*(int(*)())puVar3)(DAT_0601b38a + 0x7a,iVar7);

  *(short *)0x0605AAA0 = 0;

  puVar2 = (char *)0x06026CE0;

  puVar1 = (char *)0x0605B6D8;

  INPUT_STATE = INPUT_STATE | 0x80000000;

  (*(int(*)())puVar2)();

  (*(int(*)())0x06026CE0)();

  (*(int(*)())0x0602766C)(0x25F00540,0x0604842C,0x40);

  (*(int(*)())0x0602766C)(0x25F001A0,0x060487EC,0x20);

  (*(int(*)())0x0600511E)(0x25E6F9C4,0x00017700,0,9);

  puVar2 = (char *)0x06094FA8;

  (*(int(*)())0x06028654)(0x25E75DDC);

  (*(int(*)())0x06028400)(4,puVar2,0,0x0000B000);

  (*(int(*)())0x06014884)(0x10,0,0);

  (*(int(*)())0x06014884)(0x20,0,0);

  puVar2 = (char *)0x06038BD4;

  (*(int(*)())0x06038BD4)((int)PTR_DAT_0601b394,7);

  (*(int(*)())puVar2)(4,0);

  (*(int(*)())puVar2)(8,1);

  (*(int(*)())puVar2)(0x10,6);

  (*(int(*)())puVar2)(0x20,5);

  (*(int(*)())puVar2)(1,0);

  (*(int(*)())0x0602853E)(0xc);

  (*(int(*)())0x06028560)();

  *(unsigned int *)puVar1 = *(unsigned int *)puVar1 | 0x40000000;

  *(int *)0x0608600D = 0;

  *(int *)0x0608600C = 0;

  *(int *)0x0608600E = 0;

  (*(int(*)())0x06018DDC)(4,4,0xf);

  return;

}

int FUN_0601b418()
{

  (*(int(*)())(*(int *)(0x0605DEB4 + (unsigned int)(unsigned char)*(int *)(0x0608600D << 2))))();

  (*(int(*)())0x06011AF4)(0x01000000,0x01000000,0x00200000,0x00200000,0x00008000,

             0x00010000,0x101);

  (*(int(*)())0x060078DC)();

  *(short *)0x0605D4F8 = *(short *)0x0605D4F8 + 1;

  return (int)(char)*(int *)0x0608600C;

}

void FUN_0601b6dc()
{

  char cVar1;

  char *puVar2;

  int iVar3;

  unsigned char bVar4;

  unsigned char local_28 [4];

  unsigned char local_24 [8];

  puVar2 = (char *)0x0608600E;

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06035228)();

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b76c) == 0) {

    if (((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b76e) != 0) &&

       (cVar1 = *puVar2, *puVar2 = cVar1 + '\x01', '\x02' < (char)(cVar1 + '\x01'))) {

      *puVar2 = 0;

    }

  }

  else {

    cVar1 = *puVar2;

    *puVar2 = cVar1 + -1;

    if ((char)(cVar1 + -1) < '\0') {

      *puVar2 = 2;

    }

  }

  bVar4 = 0;

  do {

    if ((int)(char)*puVar2 == (unsigned int)bVar4) {

      if ((*(unsigned short *)0x0605D4F8 & 4) == 0) {

        iVar3 = 2;

      }

      else {

        iVar3 = 1;

      }

    }

    else {

      iVar3 = 2;

    }

    (*(int(*)())0x06028400)(8,*(int *)(0x06063750 + (bVar4 + 0x36) << 3),

               ((unsigned int)local_28[bVar4] * 0x40 + (unsigned int)local_24[bVar4]) << 1,

               (iVar3 << 12) + *(int *)((int)(0x06063750 + (bVar4 + 0x36) << 3) + 4));

    bVar4 = bVar4 + 1;

  } while (bVar4 < 3);

  return;

}

void FUN_0601b7f4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char cVar4;

  int *puVar5;

  char *puVar6;

  int iVar7;

  unsigned char bVar8;

  char auStack_38 [4];

  unsigned char local_34 [4];

  int local_30 [3];

  unsigned char local_24;

  unsigned char local_23;

  puVar1 = (char *)0x06063750;

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06035168)();

  (*(int(*)())0x06035228)();

  puVar6 = auStack_38;

  (*(int(*)())0x06035228)();

  puVar2 = (char *)0x0608600E;

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b87e) == 0) {

    if ((((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) != 0) &&

       (cVar4 = ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] + '\x01',

       ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] = cVar4, (char)puVar6[(char)*puVar2] <= cVar4)) {

      ((int *)0x0605D4F4)[(char)*puVar2] = 0;

    }

  }

  else {

    cVar4 = ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] + -1;

    ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] = cVar4;

    if (cVar4 < '\0') {

      ((int *)0x0605D4F4)[(char)*puVar2] = puVar6[(char)*puVar2] + -1;

    }

  }

  puVar2 = (char *)0x0605D4F4;

  bVar8 = 0;

  do {

    if ((int)(char)*puVar2 == (unsigned int)bVar8) {

      iVar7 = 1;

    }

    else {

      iVar7 = 4;

    }

    (*(int(*)())0x06011AF4)(local_30[bVar8],0xFFD40000,0x002F0000,0x001C0000,0x00008000,

               0x00010000,(unsigned int)bVar8 + iVar7 + 0x100);

    if ((int)(char)*puVar2 == (unsigned int)bVar8) {

      if (((*(unsigned short *)0x0605D4F8 & 8) == 0) && (*(int *)0x0608600E == '\0')) {

        iVar7 = 4;

      }

      else {

        iVar7 = 3;

      }

    }

    else {

      iVar7 = 4;

    }

    puVar5 = (int *)(puVar1 + ((bVar8 + 0x30) << 3));

    (*(int(*)())0x06028400)(8,*puVar5,((unsigned int)local_34[bVar8] + (unsigned int)(local_24 << 6)) << 1,

               (iVar7 << 12) + puVar5[1]);

    puVar3 = (char *)0x0605D4F5;

    bVar8 = bVar8 + 1;

  } while (bVar8 < 3);

  bVar8 = 0;

  do {

    if ((int)(char)*puVar3 == (unsigned int)bVar8) {

      if (((*(unsigned short *)0x0605D4F8 & 8) == 0) && (*(int *)0x0608600E == '\x01')) {

        iVar7 = 4;

      }

      else {

        iVar7 = 3;

      }

    }

    else {

      iVar7 = 4;

    }

    puVar5 = (int *)(puVar1 + ((bVar8 + 0x33) << 3));

    (*(int(*)())0x06028400)(8,*puVar5,((unsigned int)local_34[bVar8] + (unsigned int)(local_23 << 6)) << 1,

               (iVar7 << 12) + puVar5[1]);

    bVar8 = bVar8 + 1;

  } while (bVar8 < 3);

  return;

}

void FUN_0601ba50(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  char *pcVar6;

  char auStack_1c [8];

  puVar2 = (char *)0x0605D4F7;

  puVar1 = (char *)0x060284AE;

  (*(int(*)())0x06035228)();

  puVar4 = (char *)0x06063750;

  puVar3 = (char *)0x06028400;

  (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_0601bb3a),0x290,

             0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601bb3a) + 4));

  (*(int(*)())puVar3)(0xc,*(int *)(puVar4 + DAT_0601bb3e),(int)DAT_0601bb40,

                    0x0000A000 + *(int *)((int)(puVar4 + DAT_0601bb3e) + 4));

  (*(int(*)())puVar3)(0xc,*(int *)(puVar4 + ((param_1 + 0x30) << 3)),0x390,

                    0x00009000 + *(int *)((int)(puVar4 + ((param_1 + 0x30) << 3)) + 4));

  (*(int(*)())puVar3)(0xc,*(int *)(puVar4 + ((param_2 + 0x33) << 3)),(int)DAT_0601bb44,

                    0x00009000 + *(int *)((int)(puVar4 + ((param_2 + 0x33) << 3)) + 4));

  FUN_0601bbcc(*(int *)

                (0x0605DD6C + (param_1 * 6 + (param_2 << 1) + (unsigned int)(unsigned char)*puVar2) << 2),

               (int)param_3,10);

  (*(int(*)())puVar3)(0xc,*(int *)(puVar4 + DAT_0601bb46),(int)DAT_0601bb4a,

                    *(int *)((int)(puVar4 + DAT_0601bb46) + 4) + (int)DAT_0601bb48);

  pcVar6 = *(char **)(0x0605DE24 + ((param_1 << 1) + (unsigned int)(unsigned char)*puVar2) << 2);

  (*(int(*)())puVar1)(8,(int)DAT_0601bbc0,0x60,auStack_1c);

  if (*pcVar6 != '\0') {

    (*(int(*)())puVar1)(8,(int)DAT_0601bbc0,0x60,pcVar6);

  }

  uVar5 = (*(int(*)())0x06005DD4)(*(int *)

                      (*(int *)(0x0605DE24 + ((param_1 << 1) + (unsigned int)(unsigned char)*puVar2) << 2) + 4));

  (*(int(*)())puVar1)(8,0xcb2,0x78,uVar5);

  return;

}

int FUN_0601bbcc(param_1, param_2, param_3)
    int param_1;
    char param_2;
    unsigned int param_3;
{

  char cVar1;

  int bVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int iVar8;

  int uVar9;

  int *puVar10;

  int iVar11;

  char *pcVar12;

  unsigned char bVar13;

  unsigned int uVar14;

  unsigned int local_44;

  char auStack_24 [8];

  puVar4 = (char *)0x060284AE;

  puVar3 = (char *)0x06028400;

  iVar11 = (int)DAT_0601bcba;

  iVar8 = (*(int(*)())0x06035228)();

  puVar7 = (char *)0x06063920;

  puVar6 = (char *)0x06063D08;

  puVar5 = (int *)0x06063918;

  for (uVar14 = (unsigned int)param_2; (int)(uVar14 & 0xffff) < param_2 + 5; uVar14 = uVar14 + 1) {

    local_44 = (param_3 & 0xffff) << 6;

    (*(int(*)())puVar4)(8,(local_44 + 2) << 1,0x60,

                      *(int *)(0x0605DE64 + (uVar14 & 0xffff) << 2));

    pcVar12 = (char *)((uVar14 & 0xffff) * 0xc + param_1);

    (*(int(*)())puVar4)(8,(local_44 + 9) << 1,0x60,auStack_24);

    if (*pcVar12 != '\0') {

      (*(int(*)())puVar4)(8,((param_3 & 0xffff) << 6 + 9) << 1,0x60,pcVar12);

    }

    iVar8 = (uVar14 & 0xffff) * 0xc + param_1;

    uVar9 = (*(int(*)())0x06005DD4)(*(int *)(iVar8 + 4));

    (*(int(*)())puVar4)(8,((param_3 & 0xffff) << 6 + 0x10) << 1,0x78,uVar9);

    bVar13 = *(unsigned char *)(iVar8 + 8);

    bVar2 = 0xb < bVar13;

    if (bVar2) {

      bVar13 = bVar13 - 0xc;

    }

    if (9 < bVar13) {

      local_44 = 0x2000000;

    }

    iVar8 = (param_3 & 0xffff) << 6;

    (*(int(*)())puVar3)(8,*(int *)

                         (0x06063750 + ((local_44 >> 0x18) + (unsigned int)bVar2 + 0x3c) << 3),

                      (iVar8 + 0x21) << 1,

                      (unsigned int)(bVar13 << 12) +

                      *(int *)((int)(0x06063750 +

                                    ((local_44 >> 0x18) + (unsigned int)bVar2 + 0x3c) << 3) + 4));

    (*(int(*)())puVar4)(0xc,(iVar8 + 0x25) << 1,0x60,0x0604A4B8);

    if (*(char *)((uVar14 & 0xffff) * 0xc + param_1 + 10) != '\0') {

      if (*(int *)0x06078644 == 1) {

        iVar8 = *(int *)(puVar5 + 4);

        puVar10 = (int *)puVar5;

      }

      else {

        iVar8 = *(int *)(puVar6 + 4);

        puVar10 = (int *)puVar6;

      }

      (*(int(*)())puVar3)(0xc,*puVar10,((param_3 & 0xffff) << 6 + 0x25) << 1,iVar8 + iVar11);

    }

    cVar1 = *(char *)((uVar14 & 0xffff) * 0xc + param_1 + 9);

    iVar8 = (int)cVar1;

    if (cVar1 != '\0') {

      iVar8 = (*(int(*)())puVar3)(0xc,*(int *)puVar7,((param_3 & 0xffff) << 6 + 0x28) << 1,

                                0x00008000 + *(int *)(puVar7 + 4));

    }

    param_3 = param_3 + 3;

  }

  return iVar8;

}

void FUN_0601bdec()
{
  register int base asm("r2") = CAR_PTR_TARGET;
  unsigned int *puVar2 = (unsigned int *)0x06059F38;
  unsigned int *puVar4 = (unsigned int *)0x06059F3C;
  int *piVar5 = (int *)0x06086018;
  int iVar1, diff;

  iVar1 = (*(int(*)())0x06034FE0)();
  *puVar4 = *puVar4 + iVar1 + 1;

  diff = *piVar5 - *(int *)(base + 0x20);
  if (diff >= 1) {
    *puVar2 = *puVar2 + 2;
  } else if (diff < 0) {
    *puVar2 = *puVar2 - 2;
  }

  if (*puVar4 > 0x50) {
    *puVar4 = *puVar4 - 0x50;
  }

  if (*puVar2 > 0xa0) {
    *puVar2 = 0;
  }

  *piVar5 = *(int *)(base + 0x20);
}

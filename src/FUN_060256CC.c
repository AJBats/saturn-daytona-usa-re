extern int DAT_06025746;

extern int DAT_0602596a;

extern int DAT_06025a80;

extern int PTR_DAT_06025748;

extern int PTR_DAT_06025748;

extern int PTR_DAT_06025bb8;

extern int PTR_DAT_06025bb8;

extern int FUN_06025224();
extern int FUN_060262c0();

void FUN_060256cc()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  unsigned short uVar7;

  unsigned int uVar8;

  unsigned short uVar9;

  int iVar10;

  int *piVar11;

  puVar5 = 0x06089ED0;

  puVar4 = 0x06089ECC;

  puVar3 = 0x06060F2C;

  puVar2 = 0x06063750;

  uVar1 = DAT_06025746;

  if (*(int *)0x06061199 == '\0') {

    iVar6 = (*(int(*)())0x06035C2C)();

    if (iVar6 < 6) {

      uVar8 = 0;

      do {

        (*(int(*)())0x0601A3F4)(uVar8,uVar1);

        uVar8 = uVar8 + 1;

      } while ((uVar8 & 0xffff) < 10);

    }

    else {

      uVar8 = 0;

      do {

        (*(int(*)())0x0601A3F4)(uVar8,uVar1);

        iVar6 = (uVar8 & 0xffff) << 3;

        if ((unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) == (int)PTR_DAT_06025748) {

          uVar7 = 9;

        }

        else {

          uVar7 = 8;

        }

        piVar11 = (int *)(0x06058FBC + iVar6);

        iVar10 = (uVar8 & 0xffff) << 1;

        (*(int(*)())0x06028400)(piVar11[1] << 2,*(int *)(puVar2 + (*piVar11 << 3)),

                   ((unsigned int)(unsigned char)((char *)(0x0605904C + iVar10))[1] * 0x40 +

                   (unsigned int)(unsigned char)((int *)0x0605904C)[iVar10]) << 1,

                   0x00008000 + *(int *)((int)(puVar2 + (*piVar11 << 3)) + 4));

        (*(int(*)())0x06028400)(piVar11[1] << 2,

                   *(int *)(puVar2 + ((unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) << 3)),

                   ((unsigned int)(unsigned char)((char *)(0x06059060 + iVar10))[1] * 0x40 +

                   (unsigned int)(unsigned char)((int *)0x06059060)[iVar10]) << 1,

                   (unsigned int)(uVar7 << 12) +

                   *(int *)((int)(puVar2 + ((unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) << 3)) + 4));

        uVar8 = uVar8 + 1;

      } while ((uVar8 & 0xffff) < 10);

    }

    if ((*(unsigned short *)0x06063D9A != 0) &&

       (((unsigned int)0x0000C000 & (unsigned int)*(unsigned short *)0x06063D9A) == 0)) {

      *(int *)0x06061199 = 1;

    }

  }

  if (*(int *)0x06061199 != '\0') {

    uVar7 = *(unsigned short *)0x06063D9A;

    if (uVar7 != 0) {

      if (((unsigned int)uVar7 & (unsigned int)0x0000C000) == 0) {

        if ((uVar7 & DAT_06025a80) != 0) {

          *(int *)0x06061198 = 5;

          *(short *)0x06089EDA = 0x12;

          *(int *)0x06061199 = 0;

          FUN_06025224(4);

          return;

        }

        uVar9 = 0;

        do {

          if ((*(unsigned short *)(0x06059094 + (unsigned int)(uVar9 << 1)) & uVar7) != 0) break;

          uVar9 = uVar9 + 1;

        } while (uVar9 < 10);

        *(unsigned int *)puVar4 = (unsigned int)uVar9;

        FUN_060262c0((unsigned int)uVar9);

        uVar8 = 0;

        do {

          if (*(short *)(0x060610BC + ((uVar8 & 0xff) * 0xc & 0xff) + 8) ==

              *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 6)) break;

          uVar8 = uVar8 + 1;

        } while ((uVar8 & 0xffff) < 0xe);

        *(unsigned int *)puVar5 = uVar8 & 0xffff;

      }

      else if (((unsigned int)uVar7 & (unsigned int)0x00008000) == 0) {

        if ((uVar7 & DAT_0602596a) != 0) {

          iVar6 = *(int *)puVar5;

          *(int *)puVar5 = iVar6 + -1;

          if (iVar6 + -1 < 0) {

            *(int *)puVar5 = 0xe;

          }

          if ((*(short *)0x06089ED4 == 1) && (*(int *)0x06089ED0 == 0xd)) {

            *(int *)puVar5 = 9;

          }

          if ((*(short *)0x06089ED4 == 2) && (*(int *)0x06089ED0 == 9)) {

            *(int *)puVar5 = 7;

          }

          if ((*(short *)0x06089ED6 == 1) && (*(int *)0x06089ED0 == 7)) {

            *(int *)puVar5 = 3;

          }

          if ((*(short *)0x06089ED6 == 2) && (*(int *)0x06089ED0 == 3)) {

            *(int *)puVar5 = 1;

          }

        }

      }

      else {

        iVar6 = *(int *)puVar5;

        *(int *)puVar5 = iVar6 + 1;

        if (0xe < iVar6 + 1) {

          *(int *)puVar5 = 0;

        }

        if ((*(short *)0x06089ED6 == 1) && (*(int *)0x06089ED0 == 4)) {

          *(int *)puVar5 = 8;

        }

        if ((*(short *)0x06089ED6 == 2) && (*(int *)0x06089ED0 == 2)) {

          *(int *)puVar5 = 4;

        }

        if ((*(short *)0x06089ED4 == 1) && (*(int *)0x06089ED0 == 10)) {

          *(int *)puVar5 = 0xe;

        }

        if ((*(short *)0x06089ED4 == 2) && (*(int *)0x06089ED0 == 8)) {

          *(int *)puVar5 = 10;

        }

      }

      *(int *)(puVar3 + *(int *)((int)(int)puVar4 << 3)) =

           *(int *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 4);

      *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 4) =

           *(short *)(0x06059094 + *(int *)((int)(int)puVar4 << 1));

      *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 6) =

           *(short *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8);

      FUN_06025224(4);

    }

    if (-1 < *(int *)puVar4) {

      iVar6 = (*(int(*)())0x06035C2C)();

      if (5 < iVar6) {

        if ((unsigned int)*(unsigned short *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8) ==

            (int)PTR_DAT_06025bb8) {

          uVar7 = 9;

        }

        else {

          uVar7 = 8;

        }

        (*(int(*)())0x06028400)(*(int *)((int)(0x06058FBC + *(int *)((int)(int)puVar4 << 3)) + 4) << 2,

                   *(int *)(puVar2 + (*(int *)(0x06058FBC + *(int *)((int)(int)puVar4 << 3)) << 3)),

                   ((unsigned int)(unsigned char)((char *)(0x0605904C + *(int *)((int)(int)puVar4 << 1)))[1] * 0x40 +

                   (unsigned int)(unsigned char)((int *)0x0605904C)[*(int *)((int)(int)puVar4 << 1)]) << 1,

                   0x00008000 +

                   *(int *)((int)(puVar2 + (*(int *)(0x06058FBC + *(int *)((int)(int)puVar4 << 3)) << 3)) + 4)

                  );

        (*(int(*)())0x06028400)(*(int *)(0x06058FBC + *(int *)((int)(int)puVar4 << 3) + 4) << 2,

                   *(int *)

                    (puVar2 + ((unsigned int)*(unsigned short *)

                                     (0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8

                                     ) << 3)),

                   ((unsigned int)(unsigned char)((char *)(0x06059060 + *(int *)((int)(int)puVar4 << 1)))[1] * 0x40 +

                   (unsigned int)(unsigned char)((int *)0x06059060)[*(int *)((int)(int)puVar4 << 1)]) << 1,

                   (unsigned int)(uVar7 << 12) +

                   *(int *)((int)(puVar2 + ((unsigned int)*(unsigned short *)

                                                  (0x060610BC +

                                                  ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8) << 3))

                           + 4));

        return;

      }

      (*(int(*)())0x0601A3F4)(*(unsigned int *)puVar4 & 0xffff,uVar1);

      return;

    }

  }

  return;

}

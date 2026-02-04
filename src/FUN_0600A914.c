extern int DAT_0600a99a;

extern int DAT_0600aa7e;

extern int PTR_DAT_0600a99c;

extern int PTR_DAT_0600a99c;

extern int PTR_DAT_0600aa80;

extern int PTR_DAT_0600aa80;

int FUN_0600a914()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  unsigned int uVar8;

  unsigned int uVar9;

  int iVar10;

  int iVar11;

  unsigned int *puVar12;

  puVar3 = 0x06078900;

  puVar2 = 0x0607EA98;

  puVar1 = 0x0004B333;

  iVar11 = (int)DAT_0600a99a;

  iVar5 = *(int *)0x0607EAE0;

  if (iVar5 == 0) {

    for (uVar8 = 1; puVar4 = 0x0607E940, uVar8 < *(int *)puVar2 - 1U; uVar8 = uVar8 + 1) {

      puVar12 = (unsigned int *)(puVar3 + uVar8 * iVar11);

      *(unsigned int **)0x0607E940 = puVar12;

      uVar9 = uVar8;

      if ((*puVar12 & (unsigned int)0x00E00000) != 0) {

        while (uVar9 = uVar9 + 1, uVar9 < *(unsigned int *)puVar2) {

          iVar6 = uVar9 * iVar11;

          iVar5 = (int)PTR_DAT_0600a99c;

          iVar10 = *(int *)((int)puVar12 + iVar5) - *(int *)(puVar3 + iVar5 + iVar6);

          if ((iVar10 < 0x15) && (-0x15 < iVar10)) {

            iVar10 = *(int *)(puVar3 + iVar6 + 0x10) - puVar12[4];

            iVar7 = *(int *)(puVar3 + iVar6 + 0x18) - puVar12[6];

            if (iVar10 < 0) {

              iVar10 = -iVar10;

            }

            if (iVar7 < 0) {

              iVar7 = -iVar7;

            }

            if (iVar7 < iVar10) {

              iVar7 = iVar7 >> 2;

            }

            else {

              iVar10 = iVar10 >> 2;

            }

            if ((iVar10 + iVar7 < (int)puVar1) &&

               (iVar5 = (int)DAT_0600aa7e, *(int *)(puVar3 + iVar5 + iVar6) < (int)0x00010000)

               ) {

              iVar5 = (*(void(*)())0x060316C4)(puVar12);

            }

          }

        }

      }

    }

    *(char **)0x0607E940 = puVar3;

    iVar10 = *(int *)puVar4;

    for (uVar8 = 1; uVar8 < *(unsigned int *)puVar2; uVar8 = uVar8 + 1) {

      puVar12 = (unsigned int *)(puVar3 + uVar8 * iVar11);

      if ((*puVar12 & (unsigned int)0x00E00000) != 0) {

        iVar5 = (int)PTR_DAT_0600aa80;

        iVar6 = *(int *)(iVar10 + iVar5) - *(int *)((int)puVar12 + iVar5);

        if ((iVar6 < 0x15) && (-0x15 < iVar6)) {

          iVar6 = puVar12[4] - *(int *)(iVar10 + 0x10);

          iVar7 = puVar12[6] - *(int *)(iVar10 + 0x18);

          if (iVar6 < 0) {

            iVar6 = -iVar6;

          }

          if (iVar7 < 0) {

            iVar7 = -iVar7;

          }

          if (iVar7 < iVar6) {

            iVar7 = iVar7 >> 2;

          }

          else {

            iVar6 = iVar6 >> 2;

          }

          if ((iVar6 + iVar7 < (int)puVar1) &&

             (iVar5 = (int)DAT_0600aa7e, *(int *)((int)puVar12 + iVar5) < (int)0x00010000)) {

            iVar5 = (*(void(*)())0x06030FC0)(iVar10,puVar12);

          }

        }

      }

    }

  }

  return iVar5;

}

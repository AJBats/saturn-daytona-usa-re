extern int DAT_0603056a;

extern int DAT_06030588;

extern int DAT_060305ae;

extern int DAT_060305b0;

extern int DAT_06030602;

extern int DAT_06030604;

extern int DAT_0603063a;

extern int DAT_06030680;

extern int DAT_060306c8;

extern int DAT_06030714;

extern int DAT_06030716;

extern int PTR_DAT_0603056c;

extern int PTR_DAT_0603056c;

extern int PTR_DAT_06030598;

extern int PTR_DAT_06030598;

extern int FUN_06030a9c();
extern int FUN_06030b68();

void FUN_0603053c(param_1)
    short param_1;
{

  char *puVar1;

  unsigned int *puVar2;

  int iVar3;

  unsigned int uVar4;

  short sVar6;

  int iVar5;

  unsigned int uVar7;

  char *puVar8;

  unsigned char bVar9;

  int uVar10;

  int iVar11;

  *(short *)0x06030FBE = param_1;

  iVar11 = *(int *)0x0607E940;

  puVar2 = (unsigned int *)(DAT_0603056a + iVar11);

  uVar4 = puVar2[2];

  if ((((int)PTR_DAT_0603056c & (*puVar2 | puVar2[1] | uVar4 | puVar2[3])) != 0) &&

     (uVar7 = puVar2[3] & uVar4 & puVar2[1] & *puVar2, ((int)DAT_06030588 & uVar7) == 0)) {

    if (((int)PTR_DAT_06030598 & uVar7) != 0) {

      FUN_06030a9c(0,uVar4,*(int *)(0x06063EC4 + 0x10));

      return;

    }

    if (((int)DAT_060305ae & uVar7) == 0) {

      uVar4 = (unsigned int)DAT_06030602;

      bVar9 = (uVar4 & *puVar2) != 0;

      if ((uVar4 & puVar2[1]) != 0) {

        bVar9 = bVar9 + 2;

      }

      if ((uVar4 & puVar2[2]) != 0) {

        bVar9 = bVar9 + 4;

      }

      if ((uVar4 & puVar2[3]) != 0) {

        bVar9 = bVar9 + 8;

      }

      *(int *)(DAT_06030604 + iVar11) = 8;

      puVar1 = 0x06063E9C;

      puVar8 = 0x06063EC4;

      if (bVar9 == 3) {

        iVar3 = (int)DAT_06030680;

        uVar4 = (*(int *)(iVar11 + 0x30) + 0x8000) - (*(int *)(0x06063E9C + 0x10) + iVar3);

        sVar6 = (short)*(int *)(0x06063E9C + 0x10);

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((iVar3 <= (int)(uVar4 & 0xffff)) && ((int)(uVar4 & 0xffff) <= iVar3 * 3)) {

          sVar6 = sVar6 + DAT_06030680 * 2;

        }

        *(short *)0x06030FBC = sVar6 + DAT_06030680;

        FUN_06030b68(0,*(int *)(puVar1 + 0x10));

        return;

      }

      if (bVar9 == 0xc) {

        iVar3 = (int)DAT_0603063a;

        uVar4 = *(int *)(iVar11 + 0x30) - (*(int *)(0x06063EC4 + 0x10) + iVar3);

        sVar6 = (short)*(int *)(0x06063EC4 + 0x10);

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((iVar3 <= (int)(uVar4 & 0xffff)) && ((int)(uVar4 & 0xffff) <= iVar3 * 3)) {

          sVar6 = sVar6 + DAT_0603063a * 2;

        }

        *(short *)0x06030FBC = sVar6 + DAT_0603063a;

        FUN_06030b68(2,*(int *)(puVar8 + 0x10));

        return;

      }

      if (((bVar9 & 5) != 5) && (((bVar9 & 5) == 0 || ((bVar9 & 10) != 0)))) {

        uVar10 = 1;

        puVar8 = 0x06063EB0;

        if ((bVar9 & 2) == 0) {

          uVar10 = 3;

          puVar8 = 0x06063ED8;

        }

        iVar3 = (int)DAT_060306c8;

        iVar5 = *(int *)(puVar8 + 0x10);

        uVar4 = *(int *)(iVar11 + 0x30) - iVar5;

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((iVar3 <= (int)(uVar4 & 0xffff)) && ((int)(uVar4 & 0xffff) <= iVar3 * 3)) {

          iVar5 = iVar5 + iVar3 * 2;

        }

        *(short *)0x06030FBC = (short)iVar5 + DAT_060306c8;

        FUN_06030b68(uVar10,*(int *)(puVar8 + 0x10));

        return;

      }

      uVar10 = 0;

      puVar8 = 0x06063E9C;

      if ((bVar9 & 1) == 0) {

        uVar10 = 2;

        puVar8 = 0x06063EC4;

      }

      iVar3 = (int)DAT_06030714;

      iVar5 = *(int *)(puVar8 + 0x10);

      uVar4 = *(int *)(iVar11 + 0x30) - iVar5;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((iVar3 <= (int)(uVar4 & 0xffff)) && ((int)(uVar4 & 0xffff) <= iVar3 * 3)) {

        iVar5 = iVar5 + iVar3 * 2;

      }

      *(short *)0x06030FBC = (short)iVar5 + DAT_06030716;

      FUN_06030b68(uVar10,*(int *)(puVar8 + 0x10));

      return;

    }

    *(short *)(iVar11 + DAT_060305b0) = 0xf;

  }

  return;

}

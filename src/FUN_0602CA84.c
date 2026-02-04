extern int DAT_0602cb04;

extern int DAT_0602cb06;

extern int DAT_0602cb08;

extern int DAT_0602cb0a;

extern int DAT_0602cb0c;

extern int DAT_0602cb0e;

extern int DAT_0602cb72;

extern int DAT_0602cb74;

extern int DAT_0602cb76;

extern int DAT_0602cb78;

extern int DAT_0602cb7a;

extern int DAT_0602cc9c;

extern int DAT_0602cc9e;

extern int DAT_0602cca0;

extern int DAT_0602cca2;

extern int DAT_0602cca4;

extern int DAT_0602cca6;

extern int DAT_0602cca8;

extern int DAT_0602ccaa;

extern int DAT_0602ccac;

extern int DAT_0602ccae;

extern int DAT_0602ccb0;

extern int DAT_0602ccb2;

extern int DAT_0602ccb4;

extern int DAT_0602ccb6;

extern int DAT_0602ccb8;

extern int DAT_0602ccba;

extern int PTR_DAT_0602cb10;

extern int PTR_DAT_0602cb10;

extern void FUN_0602ccd0();

void FUN_0602ca84()
{

  long long lVar1;

  long long lVar2;

  int bVar3;

  int in_r0;

  char *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  unsigned int uVar8;

  unsigned int uVar9;

  int iVar10;

  int iVar11;

  unsigned int uVar12;

  int iVar13;

  lVar1 = (long long)-*(int *)(DAT_0602cb06 + in_r0) * (long long)(int)0x03700000;

  uVar9 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  lVar1 = (long long)-*(int *)(DAT_0602cb06 + in_r0) * (long long)(int)0x02D00000;

  uVar12 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  lVar1 = (long long)-*(int *)(DAT_0602cb04 + in_r0) * (long long)*(int *)(DAT_0602cb08 + in_r0);

  uVar8 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  lVar1 = (long long)-*(int *)(DAT_0602cb04 + in_r0) * (long long)*(int *)(DAT_0602cb0a + in_r0);

  if (-1 < (int)(uVar8 ^ uVar9)) {

    uVar9 = -uVar9;

  }

  iVar10 = uVar9 + uVar8;

  uVar8 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  if (-1 < (int)(uVar8 ^ uVar12)) {

    uVar12 = -uVar12;

  }

  iVar13 = uVar12 + uVar8;

  *(int *)(DAT_0602cb0c + in_r0) = iVar13;

  iVar5 = *(int *)(DAT_0602cb0e + in_r0);

  iVar7 = *(int *)(PTR_DAT_0602cb10 + in_r0);

  iVar6 = iVar5 - iVar7;

  if (iVar6 < 0) {

    iVar6 = -iVar6;

  }

  iVar11 = iVar10;

  if (iVar10 < 0) {

    iVar11 = -iVar10;

  }

  if (iVar6 < iVar11) {

    iVar11 = iVar11 + (iVar6 >> 2);

  }

  else {

    iVar11 = (iVar11 >> 2) + iVar6;

  }

  puVar4 = 0x00010000;

  if (*(int *)(DAT_0602cb72 + in_r0) <= iVar11) {

    puVar4 = (char *)

             (*0x0602755C)(*(int *)(DAT_0602cb72 + in_r0),iVar11,iVar11,iVar13,iVar10)

    ;

  }

  *(char **)(DAT_0602cb74 + in_r0) = puVar4;

  iVar10 = *(int *)(DAT_0602cb76 + in_r0) + iVar7;

  iVar5 = -iVar10 - iVar5;

  iVar6 = *(int *)(DAT_0602cb78 + in_r0) - *(int *)(DAT_0602cb7a + in_r0);

  bVar3 = false;

  if (iVar13 < 0) {

    iVar13 = -iVar13;

  }

  iVar7 = iVar6 - iVar7;

  if (iVar7 < 0) {

    iVar7 = -iVar7;

    if (iVar7 < iVar13) {

      iVar7 = (iVar7 >> 2) + iVar13;

    }

    else {

      iVar7 = iVar7 + (iVar13 >> 2);

    }

  }

  else if (iVar7 < iVar13) {

    iVar7 = (iVar7 >> 2) + iVar13;

  }

  else {

    bVar3 = true;

    iVar7 = iVar7 + (iVar13 >> 2);

  }

  iVar13 = 0x10000;

  if (*(int *)(DAT_0602cc9c + in_r0) < iVar7) {

    iVar13 = (*0x0602755C)(*(int *)(DAT_0602cc9c + in_r0),iVar7);

  }

  *(int *)(DAT_0602cc9e + in_r0) = iVar13;

  if (((bVar3) && (iVar13 <= (int)0x0000CCCC)) && (*(int *)(DAT_0602cca0 + in_r0) < 1)) {

    FUN_0602ccd0();

  }

  *(int *)(DAT_0602cca4 + in_r0) = -*(int *)(DAT_0602cca2 + in_r0) >> 3;

  if (*(short *)(DAT_0602cca6 + in_r0) != 0) {

    iVar7 = (int)DAT_0602ccaa;

    iVar13 = *(int *)(iVar7 + in_r0);

    *(int *)(DAT_0602cca8 + in_r0) = *(int *)(DAT_0602cca8 + in_r0) + (-iVar13 >> 2);

    *(int *)(iVar7 + in_r0) = (-iVar13 >> 2) + iVar13;

    iVar7 = (int)DAT_0602ccae;

    *(int *)(DAT_0602ccac + in_r0) = 0;

    *(int *)(iVar7 + in_r0) = 0;

  }

  if (*(short *)(DAT_0602ccb0 + in_r0) != 0) {

    iVar7 = (int)DAT_0602cca8;

    iVar13 = (int)DAT_0602ccaa;

    *(int *)(DAT_0602cca4 + in_r0) = 0;

    *(int *)(iVar7 + in_r0) = 0;

    *(int *)(iVar13 + in_r0) = 0;

    iVar7 = (int)DAT_0602ccae;

    *(int *)(DAT_0602ccac + in_r0) = 0;

    *(int *)(iVar7 + in_r0) = 0;

    *(int *)(DAT_0602ccb2 + in_r0) = 0xFFFF0000;

  }

  iVar13 = func_0x0602ccec();

  iVar7 = 0x00000140;

  if ((*(short *)(DAT_0602ccb8 + iVar13) != 4) && (*(short *)(DAT_0602ccb8 + iVar13) != 5)) {

    iVar7 = 0x00000100;

  }

  lVar1 = (long long)iVar5 * (long long)*(int *)(DAT_0602ccb4 + iVar13);

  lVar2 = (long long)*(int *)(DAT_0602cc9e + iVar13) * (long long)(-iVar10 - iVar6);

  lVar1 = (long long)iVar7 *

          (long long)

          (int)((((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) +

                ((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10)) -

               *(int *)(DAT_0602ccb6 + iVar13));

  *(int *)(DAT_0602ccba + iVar13) =

       (int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) >> 8;

  return;

}

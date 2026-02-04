extern int DAT_0602c71a;

extern int DAT_0602c71c;

extern int DAT_0602c71e;

extern int DAT_0602c720;

extern int DAT_0602c722;

extern int DAT_0602c724;

extern int DAT_0602c726;

extern int DAT_0602c728;

extern int DAT_0602c72a;

extern int DAT_0602c7f8;

extern int DAT_0602c7fa;

extern void FUN_0602c7fc();

void FUN_0602c690()
{

  long long lVar1;

  long long lVar2;

  long long lVar3;

  long long lVar4;

  int in_r0;

  int iVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  int iVar8;

  unsigned int uVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  char *puVar15;

  char *puVar16;

  char *puVar17;

  uVar6 = *(unsigned int *)(DAT_0602c71c + in_r0) | *(unsigned int *)(DAT_0602c71a + in_r0);

  iVar5 = FUN_0602c7fc();

  uVar7 = *(unsigned int *)(DAT_0602c720 + iVar5) | *(unsigned int *)(DAT_0602c71e + iVar5);

  iVar5 = FUN_0602c7fc();

  iVar10 = *(int *)(DAT_0602c722 + iVar5);

  iVar12 = *(int *)(DAT_0602c724 + iVar5);

  uVar14 = *(unsigned int *)(DAT_0602c726 + iVar5);

  if ((int)(uVar14 ^ -iVar10) < 0) {

    uVar14 = 0;

  }

  lVar1 = (long long)(int)0x03700000 * (long long)*(int *)(DAT_0602c728 + iVar5);

  lVar2 = (long long)(int)0x02D00000 * (long long)*(int *)(DAT_0602c728 + iVar5);

  iVar8 = *(int *)(iVar5 + 0x1c);

  uVar13 = (int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10;

  if (iVar8 < 0) {

    iVar8 = 0;

  }

  iVar11 = 0x00000645;

  iVar8 = (*0x06027348)(iVar8 >> 1);

  uVar9 = (int)((unsigned long long)((long long)iVar11 * (long long)iVar8) >> 0x20) << 0x10 |

          (unsigned int)((long long)iVar11 * (long long)iVar8) >> 0x10;

  lVar2 = (long long)(int)(*(int *)(DAT_0602c72a + iVar5) + uVar9) * (long long)(int)0x251B1285;

  lVar3 = (long long)(int)(uVar9 * 2 + *(int *)(DAT_0602c72a + iVar5)) *

          (long long)(int)0x251B1285;

  lVar4 = (long long)-iVar10 * (long long)(int)uVar14;

  lVar1 = (long long)

          (int)((((int)((unsigned long long)lVar4 >> 0x20) << 0x10 | (unsigned int)lVar4 >> 0x10) +

                ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10)) -

               ((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10)) *

          (long long)(int)uVar6;

  lVar1 = (long long)(int)0x00028000 *

          (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  puVar15 = (char *)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  lVar1 = (long long)(int)uVar14 * (long long)-iVar12;

  lVar1 = (long long)(int)uVar7 *

          (long long)

          (int)(((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) + uVar13 +

               ((int)((unsigned long long)lVar3 >> 0x20) << 0x10 | (unsigned int)lVar3 >> 0x10));

  lVar1 = (long long)(int)0x00028000 *

          (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  puVar17 = (char *)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  puVar16 = 0x01600000;

  if (((int)0x01600000 < (int)puVar15) &&

     (puVar16 = puVar15, (int)0x0C080000 < (int)puVar15)) {

    puVar16 = 0x0C080000;

  }

  puVar15 = 0x01200000;

  if (((int)0x01200000 < (int)puVar17) &&

     (puVar15 = puVar17, (int)0x09D80000 < (int)puVar17)) {

    puVar15 = 0x09D80000;

  }

  iVar12 = (int)DAT_0602c7fa;

  iVar10 = *(int *)(DAT_0602c7f8 + iVar5);

  iVar8 = *(int *)(iVar12 + iVar5);

  *(int *)(DAT_0602c7f8 + iVar5) = iVar10 + ((int)puVar16 - iVar10 >> 2);

  *(int *)(iVar12 + iVar5) = iVar8 + ((int)puVar15 - iVar8 >> 2);

  return;

}

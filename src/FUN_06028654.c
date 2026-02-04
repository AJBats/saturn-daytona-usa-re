extern int DAT_06028708;

extern int PTR_DAT_060286ac;

extern int PTR_DAT_060286ac;

long long FUN_06028654(param_1, param_2)
    unsigned char *param_1;
    unsigned char *param_2;
{

  unsigned char bVar1;

  unsigned char bVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int in_r0;

  int in_r1;

  int iVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  int iVar9;

  unsigned int uVar10;

  uVar5 = 0x00000FFF;

  puVar4 = 0x0000FF00;

  puVar3 = 0x0602872C;

  uVar7 = 0;

  uVar8 = 0;

  while( true ) {

    while( true ) {

      uVar8 = uVar8 >> 1;

      if ((uVar8 & (int)PTR_DAT_060286ac) == 0) {

        bVar1 = *param_1;

        param_1 = param_1 + 1;

        uVar8 = (unsigned int)bVar1 | (unsigned int)puVar4;

      }

      if ((uVar8 & 1) == 0) break;

      bVar1 = *param_1;

      param_1 = param_1 + 1;

      *param_2 = bVar1;

      param_2 = param_2 + 1;

      puVar3[uVar7] = bVar1;

      uVar7 = uVar7 + 1 & uVar5;

    }

    bVar1 = *param_1;

    bVar2 = param_1[1];

    param_1 = param_1 + 2;

    if (bVar2 == 0 && bVar1 == 0) break;

    uVar10 = (unsigned int)DAT_06028708;

    iVar9 = ((bVar2 | uVar10) << 8 | (unsigned int)bVar1) + uVar7;

    iVar6 = 0;

    do {

      bVar1 = puVar3[iVar9 + iVar6 & uVar5];

      *param_2 = bVar1;

      param_2 = param_2 + 1;

      puVar3[uVar7] = bVar1;

      uVar7 = uVar7 + 1 & uVar5;

      iVar6 = iVar6 + 1;

    } while (iVar6 < ((int)(bVar2 & uVar10) >> 4) + 3);

  }

  return CONCAT44(in_r1,in_r0);

}

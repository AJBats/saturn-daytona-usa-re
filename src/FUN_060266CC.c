extern int DAT_06026728;

extern int DAT_0602672a;

extern int DAT_0602672c;

extern int DAT_0602672e;

extern int DAT_06026848;

extern int DAT_0602684a;

extern int DAT_060268a6;

extern int PTR_DAT_0602684c;

extern int PTR_DAT_0602684c;

int FUN_060266cc()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  puVar4 = 0x06089EDA;

  puVar3 = 0x060284AE;

  puVar2 = 0x06059128;

  iVar9 = (int)DAT_06026728;

  iVar7 = (int)DAT_0602672a;

  (*(void(*)())0x060284AE)(8,iVar7,iVar9,0x0605912C);

  iVar8 = (int)DAT_0602672c;

  (*(void(*)())puVar3)(8,iVar8,iVar9,0x06059134);

  puVar5 = 0x06061198;

  uVar1 = *(unsigned short *)0x06063D9A;

  if (uVar1 != 0) {

    if ((uVar1 & DAT_0602672e) != 0) {

      *(unsigned short *)0x06089ED8 = (unsigned short)(*(short *)puVar4 == 0x12);

      *puVar5 = 6;

      (*(void(*)())puVar3)(8,((unsigned int)*(unsigned short *)puVar4 * 0x40 + 0x11) * 2,iVar9,puVar2);

      (*(void(*)())puVar3)(8,iVar7,iVar9,0x0605913C);

      uVar6 = (*(void(*)())puVar3)(8,iVar8,iVar9,0x06059144);

      return uVar6;

    }

    if ((unsigned int)uVar1 == (int)DAT_06026848) {

      *(short *)0x06089ED8 = 0;

      *puVar5 = 6;

      (*(void(*)())puVar3)(8,((unsigned int)*(unsigned short *)puVar4 * 0x40 + 0x11) * 2,iVar9,puVar2);

      (*(void(*)())puVar3)(8,iVar7,iVar9,0x0605913C);

      uVar6 = (*(void(*)())puVar3)(8,iVar8,iVar9,0x06059144);

      return uVar6;

    }

    if ((unsigned int)uVar1 == (int)DAT_0602684a) {

      (*(void(*)())puVar3)(8,((unsigned int)*(unsigned short *)puVar4 * 0x40 + 0x11) * 2,iVar9,puVar2);

      *(short *)puVar4 = *(short *)puVar4 + -2;

    }

    if ((unsigned int)uVar1 == (int)PTR_DAT_0602684c) {

      (*(void(*)())puVar3)(8,((unsigned int)*(unsigned short *)puVar4 * 0x40 + 0x11) * 2,iVar9,puVar2);

      *(short *)puVar4 = *(short *)puVar4 + 2;

    }

    if (0x14 < *(unsigned short *)puVar4) {

      *(short *)puVar4 = 0x12;

    }

    if (*(unsigned short *)puVar4 < 0x12) {

      *(short *)puVar4 = 0x14;

    }

  }

  if ((*(unsigned short *)0x06089EC6 & 4) != 0) {

    uVar6 = (*(void(*)())puVar3)(8,((unsigned int)*(unsigned short *)puVar4 * 0x40 + 0x11) * 2,iVar9,puVar2);

    return uVar6;

  }

  uVar6 = (*(void(*)())0x06028400)(8,*(int *)0x06063B88,((unsigned int)*(unsigned short *)puVar4 * 0x40 + 0x11) * 2,

                     *(int *)(0x06063B88 + 4) + (int)DAT_060268a6);

  return uVar6;

}

extern int DAT_060212d4;

extern int DAT_060212d6;

extern int DAT_060212d8;

extern int DAT_060212da;

extern int DAT_06021414;

extern int DAT_06021416;

extern int DAT_06021418;

extern int DAT_0602141a;

extern int PTR_DAT_060211d8;

extern int PTR_DAT_060211d8;

extern int PTR_DAT_060212dc;

extern int PTR_DAT_060212dc;

unsigned int FUN_06021178()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int uVar9;

  puVar1 = 0x0608959C;

  iVar6 = *(int *)(*(int *)0x0607E940 + 0x10);

  iVar8 = *(int *)(*(int *)0x0607E940 + 0x18);

  if (((((int)0x00760000 < iVar6) && (iVar6 < (int)0x014B0000)) &&

      (iVar8 < (int)0x00D00000)) && (0xFF3B0000 < iVar8)) {

    if (((0x57 < *(int *)(*(int *)0x0607E940 + (int)PTR_DAT_060211d8)) &&

        (*(int *)(*(int *)0x0607E940 + (int)PTR_DAT_060211d8) < 0x7a)) &&

       ((*(unsigned short *)0x0608959C & 1) == 0)) {

      *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C | 1;

      *(unsigned short *)puVar1 = *(unsigned short *)puVar1 | 2;

    }

  }

  else if ((((iVar6 < 0xFE9A0000) && (iVar8 < 0xFDCD0000)) ||

           ((iVar6 < 0xFE950000 && (iVar8 < 0xFDD30000)))) ||

          ((iVar6 < 0xFE8F0000 && (iVar8 < 0xFDD80000)))) {

    if ((*(unsigned short *)0x0608959C & 1) == 0) {

      *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C | 1;

      *(unsigned short *)puVar1 = *(unsigned short *)puVar1 | 2;

    }

  }

  else if ((*(unsigned short *)0x0608959C & 1) != 0) {

    *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C & 0xfffe;

    *(unsigned short *)puVar1 = *(unsigned short *)puVar1 | 2;

  }

  puVar4 = 0x0602766C;

  puVar3 = 0x06059FFC;

  puVar2 = 0x06063F5C;

  uVar5 = (unsigned int)(*(unsigned short *)puVar1 >> 1);

  if ((*(unsigned short *)puVar1 >> 1 & 1) != 0) {

    iVar6 = (int)DAT_060212d4;

    if ((*(unsigned short *)puVar1 & 1) == 0) {

      (*0x060039C8)();

      (*puVar4)(*(int *)puVar3 * 8 + *(int *)puVar2,0x0604D408,(int)DAT_06021414);

      (*puVar4)(*(int *)puVar3 * 8 + *(int *)puVar2 + (int)DAT_06021418,0x0604D808,

                        (int)DAT_06021416);

      if (*0x06083255 == '\0') {

        (*puVar4)(*(int *)puVar3 * 8 + *(int *)puVar2 + 0x40,

                          *(int *)(0x0605D05C + *(int *)0x06078868 * 4),iVar6);

        uVar9 = *(int *)(0x0605D05C + (unsigned int)(unsigned char)*0x0607ED91 * 4);

        iVar8 = (int)DAT_0602141a;

        iVar7 = *(int *)puVar3 * 8 + *(int *)puVar2;

      }

      else {

        iVar6 = 0x20;

        uVar9 = *(int *)(0x0605D0AC + *(int *)0x0607EAB8 * 4);

        iVar7 = ((unsigned int)(unsigned char)0x060448B5[*(int *)0x0607EAD8] +

                (unsigned int)*(unsigned short *)0x0607886C) * 0x20 + *(int *)puVar3 * 8;

        iVar8 = *(int *)puVar2;

      }

      uVar5 = (*puVar4)(iVar7 + iVar8,uVar9,iVar6);

    }

    else {

      (*0x060039F2)();

      (*puVar4)(*(int *)puVar3 * 8 + *(int *)puVar2,0x0604D608,(int)DAT_060212d6);

      (*puVar4)(*(int *)puVar3 * 8 + *(int *)puVar2 + (int)DAT_060212da,0x0604EFC8,

                        (int)DAT_060212d8);

      if (*0x06083255 == '\0') {

        (*puVar4)(*(int *)puVar3 * 8 + *(int *)puVar2 + 0x40,

                          *(int *)(0x0605D084 + *(int *)0x06078868 * 4),iVar6);

        uVar9 = *(int *)(0x0605D084 + (unsigned int)(unsigned char)*0x0607ED91 * 4);

        iVar8 = (int)PTR_DAT_060212dc;

        iVar7 = *(int *)puVar3 * 8 + *(int *)puVar2;

      }

      else {

        iVar6 = 0x20;

        uVar9 = *(int *)(0x0605D0B4 + *(int *)0x0607EAB8 * 4);

        iVar7 = ((unsigned int)(unsigned char)0x060448B5[*(int *)0x0607EAD8] +

                (unsigned int)*(unsigned short *)0x0607886C) * 0x20 + *(int *)puVar3 * 8;

        iVar8 = *(int *)puVar2;

      }

      uVar5 = (*puVar4)(iVar7 + iVar8,uVar9,iVar6);

    }

    *(unsigned short *)puVar1 = *(unsigned short *)puVar1 & 0xfffd;

  }

  return uVar5;

}

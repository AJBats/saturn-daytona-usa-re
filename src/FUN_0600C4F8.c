extern int DAT_0600c590;

extern int DAT_0600c592;

extern int DAT_0600c594;

extern int DAT_0600c596;

extern int DAT_0600c598;

extern int DAT_0600c59a;

extern int PTR_DAT_0600c59c;

extern int PTR_DAT_0600c59c;

void FUN_0600c4f8()
{

  char *puVar1;

  short extraout_var;

  int uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  puVar1 = 0x06027552;

  iVar6 = *(int *)0x0607E940;

  if (0 < *(short *)(iVar6 + DAT_0600c590)) {

    *(short *)(iVar6 + DAT_0600c590) = *(short *)(iVar6 + DAT_0600c590) + -1;

  }

  if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00008000) == 0) {

    iVar5 = (int)DAT_0600c592;

    if ((*(int *)(iVar6 + DAT_0600c594) < 1) && (*(int *)(iVar6 + DAT_0600c596) == 0)) {

      iVar3 = *(int *)(iVar6 + 8) * 4;

      uVar2 = (*puVar1)(0xFEC00000 +

                                (*(int *)(0x060477EC + iVar3) -

                                *(int *)(0x060454CC + iVar3)),1);

      iVar3 = (*puVar1)(uVar2,*(int *)(iVar6 + DAT_0600c59a));

      iVar4 = *(int *)(iVar6 + PTR_DAT_0600c59c) - *(int *)(iVar6 + 0xc);

      if (iVar4 < iVar5) {

        *(int *)(iVar6 + DAT_0600c598) = iVar5;

      }

      else if (iVar3 >> 1 < iVar4) {

        *(int *)(iVar6 + DAT_0600c598) = iVar3 >> 1;

      }

      else {

        *(int *)(iVar6 + DAT_0600c598) = iVar4;

      }

    }

    else {

      *(int *)(iVar6 + DAT_0600c598) = iVar5;

    }

    iVar5 = *(int *)(iVar6 + 0xc) + *(int *)(iVar6 + DAT_0600c598);

    if (iVar5 < 1) {

      *(int *)(iVar6 + 0xc) = 0;

    }

    else {

      *(int *)(iVar6 + 0xc) = iVar5;

    }

    (*puVar1)(*(int *)(iVar6 + 0xc),0x00480000);

    *(int *)(iVar6 + 8) = (int)extraout_var;

  }

  return;

}

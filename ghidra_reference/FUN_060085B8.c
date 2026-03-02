extern int DAT_06008624;

extern int DAT_06008626;

extern int DAT_06008628;

extern int DAT_0600862a;

extern int FUN_06008730();

int FUN_060085b8()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x0607E940;

  iVar2 = 0;

  if (*(int *)(*(int *)0x0607E940 + (int)DAT_06008624) != 0) {

    *(int *)0x0607EBD4 = 0x46;

    if ((*(int *)((int)DAT_06008626 + *(int *)puVar1) == 1) &&

       (((int)*(char *)(*(int *)puVar1 + 0x160) & 0x80U) != 0)) {

      *(int *)(*(int *)puVar1 + 0x28) = *(int *)(*(int *)puVar1 + 0x30);

      *(int *)(*(int *)puVar1 + DAT_0600862a + -8) =

           *(int *)(*(int *)puVar1 + (int)DAT_0600862a);

    }

    FUN_06008730();

    iVar2 = (int)DAT_06008624;

    if (*(int *)(*(int *)puVar1 + iVar2) < 2) {

      if (*(char **)0x0607EBC4 == 0x00200000) {

        *(int *)0x06078654 = 4;

      }

      else {

        *(int *)0x06078654 = 1;

      }

    }

  }

  return iVar2;

}

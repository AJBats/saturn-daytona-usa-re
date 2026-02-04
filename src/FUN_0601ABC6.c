extern int PTR_DAT_0601ace4;

extern int PTR_DAT_0601ace4;

extern int FUN_0601adb0();

int FUN_0601abc6()
{

  int iVar1;

  *(int *)0x06085FF8 = 0;

  *(int *)0x06085FF9 = 0;

  *(int *)0x06085FFC = 0;

  *(int *)0x06086000 = 0;

  FUN_0601adb0();

  if ((*(int *)0x06078638 <

       *(int *)(*(int *)(0x0605DE24 + *(int *)0x0607EAD8 * 8) + 4)) &&

     (0 < *(int *)0x06078638)) {

    *(int *)0x06085FF9 = 1;

  }

  if (*(int *)0x0607EBF4 == 0) {

    return 0;

  }

  iVar1 = (int)PTR_DAT_0601ace4;

  if (*(unsigned int *)0x060786A4 <

      *(unsigned int *)(*(int *)(0x0605DD6C +

                        (*(int *)0x0607EAD8 * 6 + *(int *)0x0605AD00 * 2) * 4) + iVar1))

  {

    *(int *)0x06085FF8 = 1;

  }

  return iVar1;

}

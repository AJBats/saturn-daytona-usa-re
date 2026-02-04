extern int DAT_0602f4aa;

extern int PTR_DAT_0602f4ac;

extern int PTR_DAT_0602f4ac;

void FUN_0602f474()
{

  int iVar1;

  int iVar2;

  int unaff_r14;

  iVar2 = 0;

  iVar1 = (int)*(short *)(DAT_0602f4aa + unaff_r14);

  if (iVar1 != 0) {

    iVar1 = iVar1 + -1;

    *(short *)(DAT_0602f4aa + unaff_r14) = (short)iVar1;

    if (iVar1 != 0) {

      if (iVar1 != 1) {

        iVar2 = (iVar1 != 2) + 1;

      }

      iVar2 = iVar2 + 1;

    }

    iVar2 = iVar2 + 1;

  }

  *(int *)(PTR_DAT_0602f4ac + unaff_r14) =

       *(int *)(0x060477D8 + iVar2 * 4);

  return;

}

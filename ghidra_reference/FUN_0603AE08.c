extern int DAT_0603ae60;

extern int DAT_0603ae62;

extern int PTR_DAT_0603ae64;

extern int PTR_DAT_0603ae64;

extern int FUN_0603b93c();

int FUN_0603ae08(param_1)
    int param_1;
{

  int iVar1;

  if ((*(int *)(*(int *)0x060A4D14 + 0xa0) != 0) &&

     (*(int *)(0x98 + *(int *)0x060A4D14) == 1)) {

    iVar1 = (*(int(*)())0x0603F148)(*(int *)(*(int *)0x060A4D14 + 0xa0),param_1,

                       *(int *)(*(int *)0x060A4D14 + (int)PTR_DAT_0603ae64));

    if (iVar1 < 0) {

      iVar1 = FUN_0603b93c(0xfffffff7);

      return iVar1;

    }

    FUN_0603b93c(0);

    return iVar1;

  }

  iVar1 = FUN_0603b93c(0xfffffff8);

  return iVar1;

}

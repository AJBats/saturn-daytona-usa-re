extern int DAT_0603adda;

extern int PTR_DAT_0603addc;

extern int PTR_DAT_0603addc;

extern void FUN_0603b7c0();
extern void FUN_0603b93c();

void FUN_0603adac(param_1)
    int param_1;
{

  int uVar1;

  int iVar2;

  iVar2 = *(int *)0x060A4D14 + (int)DAT_0603adda;

  if (param_1 == 0) {

    if (*(int *)(*(int *)0x060A4D14 + (int)PTR_DAT_0603addc) != 0) {

      FUN_0603b93c(0xfffffff9);

      return;

    }

    *(int *)(iVar2 + 8) = 0;

    *(int *)(iVar2 + 0xc) = 0;

    *(int *)(iVar2 + 4) = 0;

  }

  else {

    (*0x06035168)();

    uVar1 = FUN_0603b7c0();

    *(int *)(iVar2 + 0xc) = uVar1;

  }

  FUN_0603b93c(0);

  return;

}

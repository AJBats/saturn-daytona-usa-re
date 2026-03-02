extern int FUN_060330a0();
extern int FUN_06033330();

int FUN_0603307c()
{

  int iVar1;

  

  iVar1 = **(int **)0x06033864;

  if (iVar1 < 1) {

    FUN_06033330();

    iVar1 = FUN_060330a0();

  }

  return iVar1;

}

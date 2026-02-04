extern int FUN_0603b878();
extern int FUN_0603b8b4();
extern int FUN_0603b8f4();
extern int FUN_0603b93c();

void FUN_0603af94(param_1)
    int param_1;
{

  int iVar1;

  iVar1 = FUN_0603b878();

  if (iVar1 == 0) {

    FUN_0603b93c(0xfffffff5);

    return;

  }

  FUN_0603b8b4(param_1);

  FUN_0603b8f4(param_1);

  (*(int(*)())0x0603BF22)(iVar1,param_1);

  FUN_0603b93c(0);

  return;

}

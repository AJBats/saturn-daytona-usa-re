extern int FUN_0603f3da();
extern int FUN_0603f582();
extern int FUN_0603f84c();

int FUN_0603f2e0(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  char local_44 [32];

  char auStack_24 [24];

  FUN_0603f3da(auStack_24,param_1,param_3,param_4,param_1);

  iVar1 = 0;

  while ((0 < param_3 && (FUN_0603f582(auStack_24,local_44), local_44[0] != '\0'))) {

    FUN_0603f84c(param_2,local_44);

    param_2 = param_2 + 0xc;

    param_3 = param_3 + -1;

    iVar1 = iVar1 + 1;

  }

  *(unsigned char *)(param_2 + -1) = *(unsigned char *)(param_2 + -1) | 0x80;

  return iVar1;

}

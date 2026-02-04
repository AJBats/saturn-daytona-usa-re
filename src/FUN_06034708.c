extern void FUN_06034754();
extern void FUN_060347a8();
extern void FUN_06034848();

int FUN_06034708(param_1)
    int param_1;
{

  int uVar1;

  *(int *)(param_1 + 0x00000010) = *(int *)(param_1 + 0x0000000C);

  FUN_06034754();

  FUN_060347a8();

  uVar1 = FUN_06034848();

  return uVar1;

}

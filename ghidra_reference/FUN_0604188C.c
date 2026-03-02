extern int FUN_06041698();

int FUN_0604188c()
{

  int iVar1;

  

  *(char **)(*(int *)0x060A5400 + 0x3c) = 0x00008000;

  do {

    iVar1 = FUN_06041698();

  } while (iVar1 == 1);

  *(int *)(*(int *)0x060A5400 + 0x3c) = 0;

  return iVar1;

}

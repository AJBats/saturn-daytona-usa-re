void FUN_06026ce0()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  puVar2 = 0x0605A010;

  puVar1 = 0x060635C4;

  iVar3 = 0;

  *(int *)0x060635C4 = 1;

  do {

    iVar3 = iVar3 + 1;

  } while (*(int *)puVar1 == 1);

  *(int *)puVar2 = iVar3;

  return;

}

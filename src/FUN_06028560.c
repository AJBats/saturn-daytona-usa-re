int * FUN_06028560()
{

  char *puVar1;

  int *puVar2;

  int iVar3;



  puVar1 = 0x00200020;

  iVar3 = 0x0380;

  puVar2 = (int *)0x060612C4;

  do {

    *puVar2 = puVar1;

    iVar3 = iVar3 + -1;

    puVar2 = puVar2 + 1;

  } while (iVar3 != 0);

  return puVar2;

}

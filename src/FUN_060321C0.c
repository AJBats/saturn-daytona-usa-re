extern int FUN_06032d90();
extern int FUN_06032e18();

char * FUN_060321c0()
{

  char uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  iVar5 = 0;

  do {

    iVar6 = *(int *)(0x060623B0 + (iVar5 << 2));

    *(char *)(iVar6 + 0x000002DC) = (char)iVar5;

    FUN_06032d90();

    *(short *)(iVar6 + 0x0000000E) = (short)0x00000004;

    FUN_06032e18(0x00000000);

    puVar4 = *(char **)(0x06062464 + (iVar5 << 2));

    puVar3 = (char *)(0x000002DE + iVar6);

    iVar6 = 0x0000000D;

    do {

      uVar1 = *puVar4;

      puVar4 = puVar4 + 1;

      *puVar3 = uVar1;

      puVar3 = puVar3 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

    iVar5 = iVar5 + 1;

  } while (iVar5 <= 0x00000005);

  *(int *)0x06082A20 = 0;

  *(int *)0x06082A24 = 0;

  puVar2 = 0x06082A25;

  *(int *)0x06082A25 = 0;

  return puVar2;

}

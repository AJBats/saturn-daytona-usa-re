extern void FUN_06033278();

long long FUN_0603320c()
{

  int in_r0;

  unsigned int uVar1;

  int extraout_r1;

  char *pcVar2;

  char *extraout_r3;

  char *puVar3;

  int iVar4;

  int iVar5;

  pcVar2 = 0x0603390C + in_r0 * 0x18;

  iVar4 = 6;

  puVar3 = (char *)(in_r0 * 8);

  do {

    iVar5 = 4;

    do {

      uVar1 = FUN_06033278(puVar3,(unsigned int)(int)*pcVar2 >> 4);

      FUN_06033278(0x00010000,uVar1 & 0xf);

      iVar5 = iVar5 + -1;

      pcVar2 = extraout_r3;

      puVar3 = 0x00010000;

    } while (0 < iVar5);

    iVar4 = iVar4 + -1;

  } while (0 < iVar4);

  return CONCAT44(0x00010000 + 0xFFF80000 + extraout_r1,0x00010000);

}

extern void FUN_0603a7b0();
extern void FUN_0603ab46();


void FUN_0603a766()
{

  short uVar1;

  char *puVar2;

  char *puVar3;



  puVar3 = 0x060A4CB4;

  puVar2 = 0x060A4CAC;

  uVar1 = 0x00FF;

  while (*(int *)puVar3 < (int)(unsigned int)*(unsigned short *)puVar2) {

    FUN_0603ab46((char)uVar1);

    FUN_0603a7b0();

    *(int *)puVar3 = *(int *)puVar3 + 1;

  }

  return;

}

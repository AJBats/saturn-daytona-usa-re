extern int DAT_0601fe96;

extern void FUN_0601fec0();

void FUN_0601fe20()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  unsigned int uVar7;

  puVar3 = 0x0607EA98;

  puVar2 = 0x06078900;

  puVar1 = 0x0607E940;

  iVar4 = (int)DAT_0601fe96;

  piVar6 = *(int **)0x060877F4;

  *(int *)0x060877FC = piVar6[1];

  *(int *)puVar3 = *piVar6 + -1;

  (*0x060054EA)(piVar6[2]);

  iVar5 = piVar6[3];

  *(short *)0x06087800 = 0;

  *(short *)0x06087802 = 0;

  for (uVar7 = 0; uVar7 <= *(unsigned int *)puVar3; uVar7 = uVar7 + 1) {

    *(char **)puVar1 = puVar2 + uVar7 * iVar4;

    FUN_0601fec0(iVar5);

    iVar5 = iVar5 + 8;

  }

  (*0x0600D280)();

  *(short *)0x06087804 = 2;

  return;

}

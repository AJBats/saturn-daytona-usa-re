extern int DAT_0600dd62;

int FUN_0600dcc8()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  iVar5 = *(int *)0x0607E940;

  piVar6 = (int *)(*(int *)0x0607EA9C * 0x18 + *(int *)(iVar5 + DAT_0600dd62));

  iVar3 = *piVar6;

  iVar7 = iVar3 - *(int *)(iVar5 + 0x10);

  if (iVar7 < 0) {

    iVar7 = *(int *)(iVar5 + 0x10) - iVar3;

  }

  iVar4 = piVar6[1];

  iVar3 = iVar4 - *(int *)(iVar5 + 0x18);

  if (iVar3 < 0) {

    iVar3 = *(int *)(iVar5 + 0x18) - iVar4;

  }

  piVar6 = (int *)0x0607869C;

  iVar3 = (*(int(*)())0x06034FE0)(iVar5,iVar7 + iVar3);

  *piVar6 = iVar3;

  puVar1 = 0x060786B0;

  *(int *)0x060786B0 = *(int *)0x0607EBD0 * 5 - iVar3;

  puVar2 = 0x0605A21C;

  iVar3 = *(int *)0x0607EAD8;

  if (iVar3 != 0) {

    *(int *)0x060786A0 = *(int *)puVar1 - *(int *)0x0605A21C;

    *(int *)puVar2 = *(int *)puVar1;

  }

  return iVar3;

}

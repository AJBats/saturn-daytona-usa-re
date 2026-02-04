extern int DAT_0600de1e;

void FUN_0600dd88(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  iVar6 = *(int *)0x0607E940;

  piVar5 = (int *)(*(int *)(iVar6 + DAT_0600de1e) +

                  *(int *)((param_1 + -1) << 2 + *(int *)(*(int *)0x06063F3C + 4)) * 0x18);

  iVar7 = *piVar5;

  iVar3 = iVar7 - *(int *)(iVar6 + 0x10);

  if (iVar3 < 0) {

    iVar3 = *(int *)(iVar6 + 0x10) - iVar7;

  }

  iVar4 = piVar5[1];

  iVar7 = iVar4 - *(int *)(iVar6 + 0x18);

  if (iVar7 < 0) {

    iVar7 = *(int *)(iVar6 + 0x18) - iVar4;

  }

  piVar5 = (int *)0x0607869C;

  iVar3 = (*(int(*)())0x06034FE0)(iVar3 + iVar7);

  *piVar5 = iVar3;

  puVar1 = 0x060786B0;

  iVar3 = *(int *)0x0607EBD0 * 5 - iVar3;

  *(int *)0x060786B0 = iVar3;

  puVar2 = 0x0605A21C;

  *(int *)0x060786A0 = iVar3 - *(int *)0x0605A21C;

  *(int *)puVar2 = *(int *)puVar1;

  return;

}

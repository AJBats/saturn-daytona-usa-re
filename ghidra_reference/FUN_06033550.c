extern int FUN_060335f4();

int FUN_06033550()
{

  int in_r0;

  int iVar1;

  int iVar2;

  int iVar3;

  int in_r1;

  int iVar4;

  int extraout_r2;

  int extraout_r2_00;

  int extraout_r3;

  int in_r7;

  long long uVar5;

  *(int *)(in_r1 + -4) =

       *(int *)(0x06033630 + *(int *)(0x0607EAD8 << 2)) -

       (*(int *)(0x00000020 + in_r0) + *(int *)(0x000001D8 + in_r0) +

       *(int *)(0x000001CC + in_r0));

  iVar1 = FUN_060335f4();

  iVar1 = (*(int(*)())0x06027552)(*(int *)(0x00000010 + iVar1));

  iVar2 = (*(int(*)())0x06027552)(extraout_r3,in_r7);

  iVar3 = (*(int(*)())0x06027552)(extraout_r2);

  uVar5 = (*(int(*)())0x06027552)(extraout_r2_00,in_r7);

  iVar4 = (int)((unsigned long long)uVar5 >> 0x20);

  *(int *)(iVar4 + -4) = iVar1 - (int)uVar5;

  *(int *)(iVar4 + -8) = iVar2 + iVar3;

  return in_r0;

}

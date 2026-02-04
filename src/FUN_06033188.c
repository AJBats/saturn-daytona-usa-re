long long FUN_06033188(param_1, param_2, param_3)
    int param_1;
    int param_2;
    unsigned int param_3;
{

  int in_r0;

  int extraout_r2;

  int extraout_r2_00;

  int iVar1;

  long long uVar2;

  (*0x06027358)(param_3 & (unsigned int)0x0000FFFF,0x0606318C,0x06063190);

  (*0x06027552)(extraout_r2);

  uVar2 = (*0x06027552)(extraout_r2_00);

  iVar1 = (int)uVar2;

  uVar2 = (*0x06027552)((int)((unsigned long long)uVar2 >> 0x20));

  (*0x06027552)((int)((unsigned long long)uVar2 >> 0x20));

  return CONCAT44((int)uVar2 - iVar1,in_r0);

}

extern int DAT_0600c8b6;

extern int DAT_0600c8b8;

extern int DAT_0600c8ba;

extern int DAT_0600c8bc;

extern int DAT_0600c8be;

extern int DAT_0600c8c0;

extern int DAT_0600c8c2;

void FUN_0600c7d4(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  short sVar2;

  *(int *)(param_1 + DAT_0600c8b6) = *(int *)(param_1 + 0x20);

  sVar2 = (short)*(int *)(param_1 + 0x28) - (short)*(int *)(param_1 + 0x20);

  if ((int)DAT_0600c8b8 < *(int *)(param_1 + 8)) {

    sVar2 = sVar2 >> 3;

  }

  else if ((int)DAT_0600c8ba < *(int *)(param_1 + 8)) {

    sVar2 = sVar2 >> 2;

  }

  else if ((int)DAT_0600c8bc < *(int *)(param_1 + 8)) {

    sVar2 = sVar2 >> 1;

  }

  sVar2 = (short)*(int *)(param_1 + 0x20) + sVar2;

  *(int *)(param_1 + 0x20) = (int)sVar2;

  *(int *)(param_1 + 0x30) =

       (int)(short)((sVar2 - (short)*(int *)(param_1 + DAT_0600c8be)) -

                   *(short *)(param_2 + 0x12));

  *(int *)(param_1 + 0x1c) =

       (int)(short)(*(short *)(param_2 + 0xc) + (short)*(int *)(param_1 + 0x1c)) >> 1;

  *(int *)(param_1 + 0x24) =

       (int)(short)(*(short *)(param_2 + 0x10) + (short)*(int *)(param_1 + 0x24)) >> 1;

  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x10);

  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x18);

  *(int *)(param_1 + 0x20) =

       (int)(short)((short)*(int *)(param_1 + 0x20) +

                   (short)(-(int)*(short *)(param_2 + 0x12) >> 2));

  (*(void(*)())0x06027358)(-*(int *)(param_1 + 0x28),DAT_0600c8c2 + param_1,DAT_0600c8c0 + param_1);

  iVar1 = (*(void(*)())0x06027552)(*(int *)(param_1 + 0xc),*(int *)(param_1 + DAT_0600c8c2));

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar1;

  iVar1 = (*(void(*)())0x06027552)(*(int *)(param_1 + 0xc),*(int *)(param_1 + DAT_0600c8c0));

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar1;

  return;

}

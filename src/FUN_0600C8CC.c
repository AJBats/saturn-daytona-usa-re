extern int DAT_0600c962;

extern int DAT_0600c964;

int FUN_0600c8cc(param_1, param_2)
    int param_1;
    int *param_2;
{

  int iVar1;

  short sVar2;

  iVar1 = (*(int(*)())0x0602744C)(*param_2 - *(int *)(param_1 + 0x10),param_2[2] - *(int *)(param_1 + 0x18));

  sVar2 = (short)-iVar1 - (short)*(int *)(param_1 + 0x28);

  if (DAT_0600c962 < sVar2) {

    *(int *)(param_1 + 0x28) = (int)(short)((short)*(int *)(param_1 + 0x28) + DAT_0600c962);

  }

  else if (sVar2 < DAT_0600c964) {

    *(int *)(param_1 + 0x28) =

         (int)(short)((short)*(int *)(param_1 + 0x28) + (short)0x0000FA00);

  }

  else {

    *(int *)(param_1 + 0x28) = -iVar1;

  }

  return iVar1;

}

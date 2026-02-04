void FUN_0600c928(param_1)
    int param_1;
{

  int iVar1;

  unsigned int uVar2;

  unsigned int uVar3;



  uVar3 = 0x2000;

  uVar2 = (int)((*(unsigned int *)(param_1 + 0xc) >> 9 & 0xffff) * 0xffff) >> 8 & 0xffff;

  if ((int)uVar2 < (int)uVar3) {

    uVar3 = uVar2;

  }

  iVar1 = *(int *)(param_1 + 0x48) - uVar3;

  *(int *)(param_1 + 0x48) = iVar1;

  *(int *)(param_1 + 0x50) = iVar1;

  return;

}

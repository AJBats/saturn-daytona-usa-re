int FUN_0600c970(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;



  iVar1 = 0x01EC;

  iVar2 = *(int *)(param_1 + iVar1);

  if ((0x44 < iVar2) && (iVar2 < 99)) {

    *(int *)(param_1 + 0xc) =

         *(int *)(param_1 + 0xc) + (int)*(short *)(0x0605A1E0 + ((iVar2 + -0x45) << 1));

  }

  return iVar1;

}

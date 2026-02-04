extern int FUN_06035f16();

int FUN_06035ec8(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  char auStack_10 [12];

  iVar1 = (*(void(*)())0x06035D22)(param_1,param_2,auStack_10);

  if (iVar1 != 0) {

    return iVar1;

  }

  FUN_06035f16(auStack_10,0x06063594);

  return 0;

}

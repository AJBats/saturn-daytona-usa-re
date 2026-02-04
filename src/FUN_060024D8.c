extern int DAT_06002554;

extern int PTR_DAT_06002558;


int FUN_060024d8(param_1)
    short param_1;
{

  int iVar1;

  

  iVar1 = *(int *)PTR_DAT_06002558 + (int)DAT_06002554;

  *(short *)(iVar1 + 0x14) = param_1;

  *(short *)(iVar1 + 0x16) = param_1;

  *(short *)(iVar1 + 0x18) = param_1;

  return (int)param_1;

}

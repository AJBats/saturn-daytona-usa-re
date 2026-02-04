extern int DAT_06002554;

extern int DAT_06002556;

extern int FUN_060023e6();
extern int FUN_060024d8();

int FUN_06002510(param_1)
    short param_1;
{

  int uVar1;

  short local_8;

  for (local_8 = DAT_06002554; (int)(unsigned int)local_8 < (int)DAT_06002556; local_8 = local_8 + param_1)

  {

    FUN_060024d8((int)(short)local_8);

    FUN_060023e6();

  }

  FUN_060024d8((int)DAT_06002556);

  uVar1 = FUN_060023e6();

  return uVar1;

}

extern void FUN_0603f92c();

char FUN_0603f970(param_1, param_2)
    int param_1;
    int param_2;
{

  char uVar1;

  uVar1 = *(char *)(param_1 + 0x35);

  *(char *)(param_1 + 0x35) = (char)param_2;

  if ((-1 < param_2) && (param_2 < 4)) {

    FUN_0603f92c(param_1,0,0x0606364C + (char)((char)param_2 * '\f'));

  }

  return uVar1;

}

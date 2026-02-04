extern void FUN_060172e4();
extern void FUN_06017330();

void FUN_060172bc()
{

  unsigned char bVar1;

  bVar1 = 0;

  do {

    FUN_060172e4(bVar1);

    FUN_06017330(bVar1);

    bVar1 = bVar1 + 1;

  } while (bVar1 < 0x12);

  return;

}

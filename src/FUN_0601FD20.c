extern void FUN_06026CE0();

void FUN_0601FD20()
{

  *(int *)0x0605B6D8 = *(int *)0x0605B6D8 | 4;

  FUN_06026CE0();

  *(int *)0x060620D0 = 0;
  *(int *)0x0605A000 = 0;
  *(int *)0x0605A004 = 0;
  *(int *)0x0605A008 = 0;
  *(int *)0x06059F44 = 0;

  return;

}

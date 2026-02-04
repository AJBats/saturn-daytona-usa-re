extern int DAT_0600a10e;

extern int DAT_0600a110;

extern int DAT_0600a112;

void FUN_0600a0c0()
{

  (*0x06038BD4)((int)DAT_0600a10e,0);

  (*0x06026CE0)();

  *(int *)0x06059F44 = 0;

  (*0x06039250)(0x06063F5C);

  (*0x060393FC)(0,0,0,(int)DAT_0600a112,(int)DAT_0600a110);

  *(int *)0x0605A008 = 0;

  **(short **)0x06063F5C = (short)0x00008000;

  (*0x06026CE0)();

  *(int *)0x06059F44 = 0;

  return;

}

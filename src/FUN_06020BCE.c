void FUN_06020bce()
{

  (*0x0603850C)(8);

  (*0x06038794)(0x00010000);

  (*0x06038520)();

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | (unsigned int)0x04000000;

  *(short *)0x0608780C = 2;

  *(int *)0x0605A00C = 0;

  (*0x06026CE0)();

  return;

}

extern int FUN_060337fc();

void FUN_06033520()
{

  char *puVar1;

  int uVar2;

  short in_r2;

  puVar1 = 0x06062970;

  *(short *)(0x06062970 + 6) = in_r2;

  uVar2 = 0x00000000;

  *(int *)puVar1 = 0x00000000;

  puVar1[4] = (char)uVar2 + '\x01';

  puVar1[5] = (char)(*(unsigned int *)0x0605B734 >> 6);

  FUN_060337fc(puVar1 + 0x16);

  return;

}

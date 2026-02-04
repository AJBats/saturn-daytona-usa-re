extern int DAT_0600bfe2;

extern int DAT_0600bfe4;

extern int DAT_0600bfe6;

void FUN_0600bf70()
{

  short sVar1;

  sVar1 = (short)((int)(short)*(int *)(*(int *)0x0607E944 + 0x1c) * (int)DAT_0600bfe2

                 >> 10) + (short)*(int *)0x06063E34;

  if (*(int *)0x06063E1C == *(int *)0x06063E20) {

    *(int *)0x06063EEC =

         (int)(short)*(int *)0x06063EEC * 0x320 +

         (int)sVar1 * 0xe0 >> 10;

  }

  else {

    *(int *)0x06063EEC = (int)sVar1;

  }

  return;

}

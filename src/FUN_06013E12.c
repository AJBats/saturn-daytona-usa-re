void FUN_06013e12()
{

  unsigned short uVar1;

  uVar1 = (unsigned short)*(int *)0x0607EBC8 & 0x1f;

  if (0x10 < uVar1) {

    (*(int(*)())0x06026EDE)((int)(short)(uVar1 << 0xc));

    return;

  }

  return;

}

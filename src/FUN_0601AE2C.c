unsigned int FUN_0601ae2c()
{

  unsigned int uVar1;

  if (*(int *)0x06083255 == '\0') {

    uVar1 = *(unsigned int *)0x06078868;

  }

  else {

    uVar1 = (*(unsigned int *)0x0607EAB8 & 0xff) + 10;

  }

  uVar1 = uVar1 & 0xff;

  if (*(int *)0x06078663 != '\0') {

    uVar1 = uVar1 + 0xc;

  }

  return uVar1;

}

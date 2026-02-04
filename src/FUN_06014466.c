unsigned int FUN_06014466()
{

  char *puVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  puVar1 = 0x06084B08;

  uVar2 = (int)(((unsigned int)*(unsigned short *)(0x06063D98 + 4) ^ (unsigned int)0x0000FFFF) & 0xff) >> 3;

  uVar3 = uVar2;

  if (0x1c < uVar2) {

    uVar3 = 0x1c;

  }

  *(int *)0x06084B0C = *(int *)0x06084B08;

  *(unsigned int *)puVar1 = uVar3;

  if (2 < *(unsigned int *)0x06084B18) {

    if (uVar3 < 0xf) {

      *(int *)puVar1 = 0x1b;

    }

    else {

      *(int *)puVar1 = 0x1c;

    }

  }

  if (*(int *)puVar1 != *(int *)0x06084B0C) {

    uVar2 = (*(void(*)())0x0601D5F4)(0,0xAB111DFF);

  }

  *(unsigned int *)0x06084B20 =

       (unsigned int)(unsigned char)0x0605AD2C[*(int *)puVar1];

  return uVar2;

}

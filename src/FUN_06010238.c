extern int PTR_DAT_06010274;

extern int PTR_DAT_06010278;

extern int PTR_DAT_06010278;

void FUN_06010238()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  puVar3 = 0x0000FFFF;

  puVar2 = 0x0607EADC;

  uVar1 = *(unsigned short *)0x06063D9C;

  *(int *)0x0607EADC = 0;

  uVar4 = ((unsigned int)uVar1 ^ (unsigned int)puVar3) & 0xff;

  if (0x72b < (int)uVar4) {

    *(int *)puVar2 = *(int *)puVar2 + 1;

  }

  if (0xc0 < (int)uVar4) {

    *(int *)puVar2 = *(int *)puVar2 + 1;

  }

  *(int *)0x0607887E = (char)*(int *)puVar2;

  *(int *)0x0607EAD8 = *(int *)puVar2;

  return;

}

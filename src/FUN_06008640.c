extern int DAT_060086a6;

extern int FUN_060086c0();
extern int FUN_06008730();

int FUN_06008640()
{

  char *puVar1;

  int uVar2;

  puVar1 = 0x0607E940;

  if ((**(unsigned char **)0x0607E940 & 8) == 0) {

    if (*(int *)(*(int *)0x0607E940 + (int)0x01BC00D4) != 0) {

      uVar2 = FUN_06008730();

      return uVar2;

    }

    return 0;

  }

  **(unsigned char **)0x0607E940 = **(unsigned char **)0x0607E940 & 0xf7;

  if (*(int *)(*(int *)puVar1 + (int)0x01BC00D4) != 0) {

    uVar2 = FUN_06008730();

    return uVar2;

  }

  *(short *)(*(int *)puVar1 + (int)DAT_060086a6) = 0x14;

  if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00800000) != 0) {

    uVar2 = FUN_060086c0(*(int *)0x060453C4);

    return uVar2;

  }

  uVar2 = FUN_060086c0(*(int *)(0x060453B4 + (*(unsigned int *)0x0607EBD0 & 1) << 3));

  return uVar2;

}

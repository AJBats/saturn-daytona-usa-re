extern int FUN_060086c0();
extern int FUN_06008730();

int FUN_06008640()
{
  char *puVar1;

  puVar1 = 0x0607E940;

  if ((**(unsigned char **)0x0607E940 & 8) == 0) {
    if (*(int *)(*(int *)0x0607E940 + 0x01BC) != 0) {
      return FUN_06008730();
    }
    return 0;
  }

  **(unsigned char **)0x0607E940 = **(unsigned char **)0x0607E940 & 0xf7;

  if (*(int *)(*(int *)puVar1 + 0x01BC) != 0) {
    return FUN_06008730();
  }

  *(short *)(*(int *)puVar1 + 0x00D4) = 0x14;

  if ((*(unsigned int *)0x0607EBC4 & 0x00800000) != 0) {
    return FUN_060086c0(*(int *)0x060453C4);
  }

  return FUN_060086c0(*(int *)(0x060453B4 + ((*(unsigned int *)0x0607EBD0 & 1) << 3)));
}

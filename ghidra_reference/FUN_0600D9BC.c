void FUN_0600d9bc(param_1)
    int param_1;
{
  register int *puVar1 asm("r14") = (int *)0x06063F1C;
  register int base asm("r5") = *(int *)0x0607E940;
  unsigned int uVar4;
  int offset;
  int iVar5;

  if (param_1 == 0) {
    if (*(int *)0x06063F18 == *puVar1) {
      offset = 0x228;
      if (*(int *)(base + offset) != *(int *)0x06063F20) {
        *(int *)0x06063F20 = *(int *)(base + offset);
        iVar5 = *(int *)0x06063F24;
        *(int *)0x06063F24 = iVar5 + 1;
        *(int *)(base + offset + -0xc) = iVar5 + 1;
        if ((unsigned int)*(int *)0x06063F24 < *(unsigned int *)0x06063F28) {
          *puVar1 = 0;
        }
      }
    }
  }

  uVar4 = (*(int(*)())0x06035280)();
  if (((unsigned int)*puVar1 & uVar4) == 0) {
    *puVar1 = *puVar1 | uVar4;
    (*(int(*)())0x06034F78)();
    *(int *)(base + 0x230) = *(int *)(base + 0x230) + 1;
    if (*(int *)0x0607EAD8 != 0) {
      if (param_1 != 0) {
        if ((*(unsigned char *)(base + 3) & 8) == 0) {
          (*(void(*)())0x0600dd88)();
          return;
        }
      }
    }
  }
}

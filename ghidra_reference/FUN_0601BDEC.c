void FUN_0601bdec()
{
  register int base asm("r2") = *(int *)0x0607E944;
  unsigned int *puVar2 = (unsigned int *)0x06059F38;
  unsigned int *puVar4 = (unsigned int *)0x06059F3C;
  int *piVar5 = (int *)0x06086018;
  int iVar1, diff;

  iVar1 = (*(int(*)())0x06034FE0)();
  *puVar4 = *puVar4 + iVar1 + 1;

  diff = *piVar5 - *(int *)(base + 0x20);
  if (diff >= 1) {
    *puVar2 = *puVar2 + 2;
  } else if (diff < 0) {
    *puVar2 = *puVar2 - 2;
  }

  if (*puVar4 > 0x50) {
    *puVar4 = *puVar4 - 0x50;
  }

  if (*puVar2 > 0xa0) {
    *puVar2 = 0;
  }

  *piVar5 = *(int *)(base + 0x20);
}

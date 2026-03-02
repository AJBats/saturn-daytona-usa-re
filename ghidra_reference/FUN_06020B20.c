extern short PTR_DAT_06020b48;

int FUN_06020b20()
{
  register int base asm("r2") = 0x25E5F800;
  register int zero asm("r0") = 0;
  register int idx asm("r3");
  unsigned short uVar4;

  *(int *)0x25F800A4 = 0x12F2FC00;
  *(short *)0x25F8009A = PTR_DAT_06020b48;

  uVar4 = 0;
  do {
    idx = (unsigned short)uVar4 << 2;
    uVar4 = uVar4 + 1;
    *(int *)(base + idx) = zero;
  } while ((unsigned short)uVar4 < 0x100);

  return idx;
}

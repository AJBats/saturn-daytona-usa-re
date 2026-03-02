extern int DAT_0600ce8e;
extern int DAT_0600cf3a;
extern int FUN_0600cd40();
extern int FUN_0600cdd0();

void FUN_0600ce66()
{
  register int base asm("r2") = *(int *)0x0607E940;

  *(int *)(base + DAT_0600ce8e + 4) = *(int *)(base + DAT_0600ce8e);

  if ((*(unsigned char *)(base + 3) & 8) == 0) {
    FUN_0600cd40();
  } else {
    FUN_0600cdd0();
  }

  *(unsigned int *)(base + DAT_0600cf3a + 0x68) =
       (unsigned int)*(unsigned short *)((*(int *)(base + DAT_0600cf3a) << 2) + *(int *)0x0607EB84);
}

extern int DAT_0600e9e8;
extern int DAT_0600e9ea;
extern int PTR_DAT_0600e9ec;
extern int FUN_0600e906();

void FUN_0600e99c()
{
  register int base asm("r2") = *(int *)0x0607E944;
  int result;

  FUN_0600e906();

  if (*(int *)0x0607EAD8 == 0) {
    result = (*(int(*)())0x06027552)(*(int *)(base + 0xc), 0x066505B3);
    *(int *)(base + DAT_0600e9e8) = result;
    *(int *)(base + DAT_0600e9ea) = result;
  }

  if (*(int *)(base + PTR_DAT_0600e9ec) == 0) {
    *(int *)0x0607EAD0 = 0;
    *(int *)(base + 0x228) = 0;
    *(int *)(base + 0x21C) = 0;
  }
}

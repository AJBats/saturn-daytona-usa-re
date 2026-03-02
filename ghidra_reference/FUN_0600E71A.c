extern short DAT_0600e79c;
extern short DAT_0600e79e;

void FUN_0600e71a()
{
  register int base asm("r14") = *(int *)0x0607E940;
  int tmp;

  (*(void(*)())0x06008318)();
  (*(void(*)())0x06008640)();
  (*(void(*)())0x0600D266)();
  (*(void(*)())0x0600C4F8)();
  (*(void(*)())0x0600C5D6)();

  tmp = *(int *)(base + DAT_0600e79c);
  if (tmp > 0) {
    tmp = tmp - 1;
    *(int *)(base + DAT_0600e79c) = tmp;
    if (tmp == 0) {
      int idx = *(int *)(base + DAT_0600e79e);
      int tbl = *(int *)(base + DAT_0600e79e + -4);
      *(int *)(base + 0x1F8) = (int)*(short *)(idx * 0x18 + tbl + 0x14);
      *(int *)(base + 0x204) = 0x400;
    }
  }

  (*(void(*)())0x0600CEBA)();

  *(int *)(base + 0x1F4) = *(int *)(base + 0x228) * *(int *)0x0607EA9C + *(int *)(base + 0x1EC);
}

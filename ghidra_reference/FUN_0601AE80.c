void FUN_0601ae80()
{
  register int func asm("r3") = 0x0602761E;

  *(int *)0x06086010 = 0;
  *(int *)0x0608600F = 0x28;
  *(int *)0x06086011 = 0;

  (*(int(*)())func)(0x25F006C0, 0x0604866C, 0x60);
  (*(int(*)())func)(0x25F00180, 0x060485CC, 0x20);
  (*(void(*)())0x0602766C)(0x25F00000, 0x0604996C, 0x180);
}

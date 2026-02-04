extern int DAT_06014a4e;

void FUN_06014a04()
{

  int in_r7;

  (*0x0602761E)

            (0x25C00000 + (int)DAT_06014a4e + *(int *)0x06059FFC * 8,0x06044B64,

             0x20,in_r7,0x25C00000);

  (*0x060172BC)();

  *(unsigned int *)0x0607EBF4 = *(unsigned int *)0x0607EBF4 | 1;

  *(short *)0x06085F90 = 0;

  *(short *)0x06085F94 = 1;

  return;

}

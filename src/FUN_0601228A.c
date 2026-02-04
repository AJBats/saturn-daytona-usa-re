extern void FUN_060122f4();
extern void FUN_0601250c();
extern void FUN_060125d0();
extern void FUN_06012710();

void FUN_0601228a()
{

  if (0x6d < *(int *)0x0607EBCC) {

    FUN_060122f4();

    FUN_0601250c();

    FUN_06012710();

    return;

  }

  if (99 < *(int *)0x0607EBCC) {

    *(short *)0x060788B2 = 0;

    FUN_0601250c();

    FUN_06012710();

    return;

  }

  if (0x27 < *(int *)0x0607EBCC) {

    *(short *)0x060788B2 = 0;

    FUN_060125d0();

    FUN_06012710();

    return;

  }

  *(int *)0x0607EBCC = 1;

  *(int *)0x0605AD10 = 0x10;

  *0x06078636 = 1;

  return;

}

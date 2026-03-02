extern short DAT_060123de;
extern short DAT_060123e0;
extern short DAT_060123e2;

void FUN_06012344()
{
  register int (*func)() asm("r3") = (int(*)())0x06027552;
  int iVar1;
  int iVar2;
  int *p;
  int iVar4;
  int tmp;

  tmp = *(int *)0x060788AC;
  iVar4 = ((int)(tmp + (unsigned int)(tmp < 0)) >> 1) << 0x10;

  iVar1 = (*func)(iVar4, (int)DAT_060123de);
  iVar2 = (*func)(iVar4, (int)DAT_060123e0);
  iVar4 = (*func)(iVar4, (int)DAT_060123e2);

  p = (int *)0x060788C0;
  p[0] = p[0] + iVar1 * -2;
  p[1] = p[1] + iVar2;
  p[2] = p[2] + iVar4;

  p = (int *)0x060788CC;
  p[0] = p[0] - iVar2;
  p[1] = p[1] - iVar1;
  p[2] = p[2] - iVar1;

  p = (int *)0x060788D8;
  p[0] = p[0] + (iVar1 << 1);
  iVar1 = (*(int(*)())0x06034FE0)();
  p[1] = p[1] - iVar1;
  p[2] = p[2] - iVar4;

  p = (int *)0x060788E4;
  p[0] = p[0] + iVar2;
  p[1] = p[1] + iVar2;
  p[2] = p[2] + iVar4;
}

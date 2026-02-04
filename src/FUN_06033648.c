extern int FUN_06033550();
extern int FUN_060336c8();
extern int FUN_060336f2();

int FUN_06033648()
{

  int in_r0;

  int iVar1;

  int extraout_r2;

  short sVar2;

  unsigned int uVar3;

  int iVar4;

  unsigned int in_sr;

  long long uVar5;

  FUN_060336f2();

  if ((in_sr & 1) == 0) {

    if (0 < *(int *)0x0607EAE0) {

      return in_r0;

    }

    iVar4 = **(int **)0x0603386C + -1;

  }

  else {

    iVar4 = 1;

  }

  uVar3 = (unsigned int)(*(int *)(0x00000224 + in_r0) == 0);

  uVar5 = FUN_060336c8();

  iVar1 = (int)uVar5;

  do {

    iVar1 = iVar1 + 0x00000268;

    if (*(unsigned int *)(extraout_r2 + iVar1) == uVar3) break;

    iVar4 = iVar4 + -1;

  } while (0 < iVar4);

  sVar2 = 6;

  if (((char)*0x06078635 < '\x01') && ((int)uVar3 < 2)) {

    sVar2 = (short)uVar3 * 4 + 6;

  }

  *(short *)((int)((unsigned long long)uVar5 >> 0x20) + -2) = sVar2;

  FUN_06033550();

  return in_r0;

}

extern short DAT_0600d404;
extern short DAT_0600d406;

void FUN_0600d37c()
{
  register int *piVar2 asm("r4") = (int *)0x0607E94C;
  register unsigned int uVar3 asm("r5") = *(unsigned int *)0x0607EA98;
  register int iVar5 asm("r12") = 0;
  int iVar1, iVar4;

  iVar1 = *(int *)(*piVar2 + (int)DAT_0600d404);

  while (uVar3 > 1) {
    iVar4 = *(int *)(piVar2[1] + (int)DAT_0600d404);
    if (iVar1 < iVar4) {
      int tmp = *piVar2;
      *piVar2 = piVar2[1];
      piVar2[1] = tmp;
    } else {
      iVar4 = iVar1;
    }
    iVar1 = *piVar2++;
    *(int *)(iVar1 + DAT_0600d406) = iVar5++;
    iVar1 = iVar4;
    uVar3--;
  }

  *(int *)(*piVar2 + (int)DAT_0600d406) = iVar5;
}

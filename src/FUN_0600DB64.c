extern int DAT_0600dbda;

unsigned int FUN_0600db64()
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  iVar3 = *(int *)0x0607E940;

  if (((int)*(char *)(iVar3 + 2) & 4U) != 0) {

    *(unsigned char *)(iVar3 + 2) = *(unsigned char *)(iVar3 + 2) & 0xfb;

    *(int *)(iVar3 + DAT_0600dbda) = *(int *)(iVar3 + DAT_0600dbda) + 1;

    *(int *)0x0607EABC = 0x28;

    puVar1 = 0x0601D7D0;

    *(int *)0x0607EAAC = *(int *)0x0607EAAC + *(int *)0x0607EAA0;

    uVar2 = (*puVar1)();

    return uVar2;

  }

  return (int)*(char *)(iVar3 + 2);

}

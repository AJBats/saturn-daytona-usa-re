extern int DAT_0600ce8e;

extern int DAT_0600cf3a;

extern int FUN_0600cd40();
extern int FUN_0600cdd0();

void FUN_0600ce66()
{

  int iVar1;

  iVar1 = *(int *)0x0607E940;

  *(int *)(iVar1 + DAT_0600ce8e + 4) = *(int *)(iVar1 + DAT_0600ce8e);

  if ((*(unsigned char *)(iVar1 + 3) & 8) == 0) {

    FUN_0600cd40();

  }

  else {

    FUN_0600cdd0();

  }

  *(unsigned int *)(iVar1 + DAT_0600cf3a + 0x68) =

       (unsigned int)*(unsigned short *)(*(int *)(iVar1 + DAT_0600cf3a) * 4 + *(int *)0x0607EB84);

  return;

}

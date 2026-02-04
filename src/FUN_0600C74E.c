extern int DAT_0600c7be;

extern int DAT_0600c7c0;

extern void FUN_0600c7d4();
extern void FUN_0600c8cc();
extern void FUN_0600c928();
extern void FUN_0600c970();
extern void FUN_0600ca96();
extern void FUN_0600cd40();

void FUN_0600c74e()
{

  char *puVar1;

  int uVar2;

  int iVar3;

  char auStack_10 [8];

  puVar1 = 0x06078680;

  iVar3 = *(int *)0x0607E940;

  FUN_0600cd40();

  FUN_0600ca96(puVar1);

  if ((*(int *)(iVar3 + DAT_0600c7be) < 0x2e) || (0x3b < *(int *)(iVar3 + DAT_0600c7be))) {

    FUN_0600c8cc(iVar3,puVar1);

  }

  else {

    *(int *)(iVar3 + 0x28) = (int)DAT_0600c7c0;

  }

  *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x28);

  if (*(int *)(iVar3 + 4) == 0) {

    FUN_0600c970(iVar3);

  }

  FUN_0600c928(iVar3);

  FUN_0600c7d4(iVar3,puVar1);

  uVar2 = (*0x06006838)(*(int *)(iVar3 + 0x10),*(int *)(iVar3 + 0x18));

  (*0x06027EDE)(uVar2,iVar3 + 0x10,auStack_10);

  return;

}

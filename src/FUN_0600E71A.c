extern int DAT_0600e79c;

extern int DAT_0600e79e;

extern int DAT_0600e7a0;

extern int DAT_0600e7a2;

extern int PTR_DAT_0600e7a4;

extern int PTR_DAT_0600e7a4;

void FUN_0600e71a()
{

  int iVar1;

  int iVar2;

  iVar2 = *(int *)0x0607E940;

  (*0x06008318)();

  (*0x06008640)();

  (*0x0600D266)();

  (*0x0600C4F8)();

  (*0x0600C5D6)();

  if ((0 < *(int *)(iVar2 + DAT_0600e79c)) &&

     (iVar1 = *(int *)(iVar2 + DAT_0600e79c) + -1, *(int *)(iVar2 + DAT_0600e79c) = iVar1,

     iVar1 == 0)) {

    iVar1 = (int)DAT_0600e7a0;

    *(int *)(iVar2 + iVar1) =

         (int)*(short *)(*(int *)(iVar2 + DAT_0600e79e) * 0x18 + *(int *)(iVar2 + DAT_0600e79e + -4)

                        + 0x14);

    *(int *)(iVar2 + iVar1 + 0xc) = (int)DAT_0600e7a2;

  }

  (*0x0600CEBA)();

  iVar1 = (int)PTR_DAT_0600e7a4;

  *(int *)(iVar2 + iVar1 + -0x34) =

       *(int *)(iVar2 + iVar1) * *(int *)0x0607EA9C + *(int *)(iVar2 + iVar1 + -0x3c);

  return;

}
